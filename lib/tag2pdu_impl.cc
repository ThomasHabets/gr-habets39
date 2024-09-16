/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "tag2pdu_impl.h"
#include <gnuradio/io_signature.h>

#include <set>

namespace gr {
namespace habets39 {

using input_type = uint8_t;

tag2pdu::sptr
tag2pdu::make(const std::string& tag_start, const std::string& tag_end, int min_size)
{
    return gnuradio::make_block_sptr<tag2pdu_impl>(tag_start, tag_end, min_size);
}


/*
 * The private constructor
 */
tag2pdu_impl::tag2pdu_impl(const std::string& tag_start,
                           const std::string& tag_end,
                           int min_size)
    : gr::block("tag2pdu",
                gr::io_signature::make(1, 1, sizeof(input_type)),
                gr::io_signature::make(0, 0, 0)),
      d_port(pmt::intern("pdus")),
      d_tag_start(pmt::intern(tag_start)),
      d_tag_end(pmt::intern(tag_end)),
      d_min_size(min_size)
{
    message_port_register_out(d_port);
}

/*
 * Our virtual destructor.
 */
tag2pdu_impl::~tag2pdu_impl() {}

int tag2pdu_impl::general_work(int noutput_items,
                               gr_vector_int& ninput_items,
                               gr_vector_const_void_star& input_items,
                               gr_vector_void_star& output_items)
{
    auto in = static_cast<const input_type*>(input_items[0]);
    auto insize = ninput_items[0];
    const auto nr = nitems_read(0);

    // Get start tag.
    std::set<int> start_tags;
    std::set<int> end_tags;
    {
        std::vector<tag_t> ts;
        get_tags_in_window(ts, 0, 0, insize);
        for (const auto& t : ts) {
            if (t.key == d_tag_start) {
                start_tags.insert(t.offset - nr);
            }
            if (t.key == d_tag_end) {
                end_tags.insert(t.offset - nr);
            }
        }
    }

    // Fast path: not currently collecting a PDU, and no start tag seen.
    if (!d_active && start_tags.empty()) {
        consume(0, insize);
        return 0;
    }

    for (int i = 0; i < insize; i++) {
        const bool st = start_tags.count(i);
        const bool et = end_tags.count(i);

        if (st) {
            d_active = true;
            d_data.clear();
        }

        if (!d_active) {
            continue;
        }

        d_data.push_back(in[i]);
        if (et && !st) {
            if (d_data.size() > d_min_size) {
                auto v = pmt::init_u8vector(d_data.size(), d_data);
                auto pdu = pmt::cons(pmt::PMT_NIL, v);
                message_port_pub(d_port, pdu);
            }
            d_active = false;
            d_data.clear();
        }
    }
    consume(0, insize);
    return 0;
}

} /* namespace habets39 */
} /* namespace gr */
