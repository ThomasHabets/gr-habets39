/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HABETS39_PDU_FILE_WRITER_H
#define INCLUDED_HABETS39_PDU_FILE_WRITER_H

#include <gnuradio/block.h>
#include <habets39/api.h>

namespace gr {
namespace habets39 {

/*!
 * \brief <+description of block+>
 * \ingroup habets39
 *
 */
class HABETS39_API pdu_file_writer : virtual public gr::block
{
public:
    typedef std::shared_ptr<pdu_file_writer> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of habets39::pdu_file_writer.
     *
     * To avoid accidental use of raw pointers, habets39::pdu_file_writer's
     * constructor is in a private implementation
     * class. habets39::pdu_file_writer::make is the public interface for
     * creating new instances.
     */
    static sptr make(const std::string& output_dir);
};

} // namespace habets39
} // namespace gr

#endif /* INCLUDED_HABETS39_PDU_FILE_WRITER_H */
