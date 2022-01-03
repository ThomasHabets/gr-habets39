/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "tag2pdu_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace habets39 {

using input_type = uint8_t;

tag2pdu::sptr tag2pdu::make(const std::string& tag_start, const std::string& tag_end)
{
    return gnuradio::make_block_sptr<tag2pdu_impl>(tag_start, tag_end);
}


/*
 * The private constructor
 */
tag2pdu_impl::tag2pdu_impl(const std::string& tag_start, const std::string& tag_end)
    : gr::block("tag2pdu",
                gr::io_signature::make(1, 1, sizeof(input_type)),
                gr::io_signature::make(0, 0, 0)),
      d_port(pmt::intern("pdus")),
      d_tag_start(tag_start),
      d_tag_end(tag_end)
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

    consume(0, insize);
    return 0;
}

} /* namespace habets39 */
} /* namespace gr */
