/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "hdlc_unstuff_impl.h"
#include <gnuradio/io_signature.h>
#include <cstdarg>

namespace gr {
namespace habets39 {

const std::vector<uint8_t> flag = { 0, 1, 1, 1, 1, 1, 1, 0 };

hdlc_unstuff::sptr hdlc_unstuff::make()
{
    return gnuradio::make_block_sptr<hdlc_unstuff_impl>();
}

/*
 * The private constructor
 */
hdlc_unstuff_impl::hdlc_unstuff_impl()
    : gr::block("hdlc_unstuff",
                gr::io_signature::make(0, 0, 0),
                gr::io_signature::make(0, 0, 0)),
      d_in(pmt::intern("in")),
      d_out(pmt::intern("out"))
{
    message_port_register_in(d_in);
    message_port_register_out(d_out);
    set_msg_handler(d_in, [this](const pmt::pmt_t& msg) { handle(msg); });
}

std::string xsprintf(const char* fmt, ...)
{
    va_list va;
    va_start(va, fmt);
    va_list va2;
    va_copy(va2, va);
    const auto len = vsnprintf(nullptr, 0, fmt, va2);
    char buf[len + 1] = { 0 };
    vsnprintf(buf, len + 1, fmt, va);
    va_end(va);
    return buf;
}

std::vector<uint8_t> pmt_to_vector(const pmt::pmt_t& msg)
{
    auto blob = pmt::cdr(msg);
    if (!pmt::is_blob(blob)) {
        throw std::runtime_error("HDLC unstuff: PMT must be blob");
    }
    auto len = pmt::blob_length(blob);
    auto blob_data = static_cast<const char*>(pmt::blob_data(blob));
    return std::vector<uint8_t>(blob_data, blob_data + len);
}

std::pair<std::vector<uint8_t>, bool> unstuff(const std::vector<uint8_t> in)
{
    int n = 0;
    std::vector<uint8_t> ret;
    ret.reserve(in.size());
    for (int c = 0; c < in.size(); c++) {
        if (in[c]) {
            n++;
            if (true) {
                // 6 instead of 5 because the stream may still have flags.
                if (n > 6) {
                    return { {}, false };
                }
            }
        } else {
            if (n == 5) {
                n = 0;
                continue;
            }
            n = 0;
        }
        ret.push_back(in[c]);
    }
    return { ret, true };
}

/*
 * Our virtual destructor.
 */
hdlc_unstuff_impl::~hdlc_unstuff_impl() {}

void hdlc_unstuff_impl::handle(const pmt::pmt_t& msg)
{
    const auto in = pmt_to_vector(msg);
    std::clog << "HABETS: Got PDU of size " << in.size() << "\n";
    auto outok = unstuff(in);
    if (!outok.second) {
        std::clog << "HDLC Unstuff: bad input\n";
        return;
    }
    auto& out = outok.first;

    out.resize(out.size() & ~0x7); // Chop off partial bytes.

    // Remove trailing flags.
    for (;;) {
        if (out.size() < flag.size()) {
            break;
        }
        if (!std::equal(flag.begin(), flag.end(), &out[out.size() - flag.size()])) {
            break;
        }
        out.resize(out.size() - flag.size());
    }
    if (out.empty()) {
        return;
    }
    const auto v = pmt::init_u8vector(out.size(), out);
    const auto pdu = pmt::cons(pmt::PMT_NIL, v);
    message_port_pub(d_out, pdu);
}

} /* namespace habets39 */
} /* namespace gr */
