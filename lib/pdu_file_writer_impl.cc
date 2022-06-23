/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "hdlc_unstuff_impl.h"
#include "pdu_file_writer_impl.h"
#include <gnuradio/io_signature.h>
#include <fstream>
#include <sys/stat.h>

namespace gr {
namespace habets39 {

pdu_file_writer::sptr pdu_file_writer::make(const std::string& output_dir)
{
    return gnuradio::make_block_sptr<pdu_file_writer_impl>(output_dir);
}

/*
 * The private constructor
 */
pdu_file_writer_impl::pdu_file_writer_impl(const std::string& output_dir)
    : gr::block("pdu_file_writer",
                gr::io_signature::make(0, 0, 0),
                gr::io_signature::make(0, 0, 0)),
      d_output_dir(output_dir.empty() ? "." : output_dir),
      d_in(pmt::intern("in"))
{
    struct stat st;
    if (stat(d_output_dir.c_str(), &st)) {
        throw std::runtime_error(xsprintf(
            "can't stat output dir %s: %s", d_output_dir.c_str(), strerror(errno)));
    }
    if (!S_ISDIR(st.st_mode)) {
        throw std::runtime_error(
            xsprintf("output dir %s isn't a directory", d_output_dir.c_str()));
    }
    message_port_register_in(d_in);
    set_msg_handler(d_in, [this](const pmt::pmt_t& msg) { handle(msg); });
}

/*
 * Our virtual destructor.
 */
pdu_file_writer_impl::~pdu_file_writer_impl() {}

void pdu_file_writer_impl::handle(const pmt::pmt_t& msg)
{
    const auto bytes = pmt_to_vector(msg);
    struct timeval tv;
    if (gettimeofday(&tv, nullptr)) {
    }
    const auto path =
        xsprintf("%s/%d.%06d.%d", d_output_dir.c_str(), tv.tv_sec, tv.tv_usec, d_n++);
    std::ofstream fo(path);
    if (!fo.good()) {
        throw std::runtime_error(
            xsprintf("failed to open %s: %s", path, strerror(errno)));
    }
    fo << std::string(bytes.begin(), bytes.end());
}

} /* namespace habets39 */
} /* namespace gr */
