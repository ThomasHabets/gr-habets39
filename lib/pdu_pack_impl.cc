/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "hdlc_unstuff_impl.h"
#include "pdu_pack_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace habets39 {

pdu_pack::sptr pdu_pack::make(bool strict)
{
    return gnuradio::make_block_sptr<pdu_pack_impl>(strict);
}

/*
 * The private constructor
 */
pdu_pack_impl::pdu_pack_impl(bool strict)
    : gr::block(
          "pdu_pack", gr::io_signature::make(0, 0, 0), gr::io_signature::make(0, 0, 0)),
      d_strict(strict),
      d_in(pmt::intern("in")),
      d_out(pmt::intern("out"))
{
    message_port_register_in(d_in);
    message_port_register_out(d_out);
    set_msg_handler(d_in, [this](const pmt::pmt_t& msg) { handle(msg); });
}

/*
 * Our virtual destructor.
 */
pdu_pack_impl::~pdu_pack_impl() {}

void pdu_pack_impl::handle(const pmt::pmt_t& msg)
{
    const auto bits = pmt_to_vector(msg);

    if (d_strict && (bits.size() % 8)) {
        std::clog << "PDU Pack got non-multiple of 8 (" << bits.size() << "\n";
        return;
    }

    // Calculate output.
    uint8_t bit_value = 1;
    uint8_t t = 0;
    std::vector<uint8_t> out;
    out.reserve(bits.size() / 8 + 1);
    for (const auto bit : bits) {
        if (bit) {
            t |= bit_value;
        }
        if (bit_value == 128) {
            bit_value = 1;
            out.push_back(t);
            t = 0;
        } else {
            bit_value <<= 1;
        }
    }

    // Send message.
    const auto v = pmt::init_u8vector(out.size(), out);
    const auto pdu = pmt::cons(pmt::PMT_NIL, v);
    message_port_pub(d_out, pdu);
}

} /* namespace habets39 */
} /* namespace gr */
