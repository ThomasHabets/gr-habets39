/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HABETS39_PDU_FILE_WRITER_IMPL_H
#define INCLUDED_HABETS39_PDU_FILE_WRITER_IMPL_H

#include <habets39/pdu_file_writer.h>

namespace gr {
namespace habets39 {

class pdu_file_writer_impl : public pdu_file_writer
{
private:
    std::string d_output_dir;
    pmt::pmt_t d_in;
    uint64_t d_n = 0;
    void handle(const pmt::pmt_t&);

public:
    pdu_file_writer_impl(const std::string& output_dir);
    ~pdu_file_writer_impl();
};

} // namespace habets39
} // namespace gr

#endif /* INCLUDED_HABETS39_PDU_FILE_WRITER_IMPL_H */
