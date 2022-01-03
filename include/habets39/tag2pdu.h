/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HABETS39_TAG2PDU_H
#define INCLUDED_HABETS39_TAG2PDU_H

#include <gnuradio/block.h>
#include <habets39/api.h>

namespace gr {
namespace habets39 {

/*!
 * \brief <+description of block+>
 * \ingroup habets39
 *
 */
class HABETS39_API tag2pdu : virtual public gr::block
{
public:
    typedef std::shared_ptr<tag2pdu> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of habets39::tag2pdu.
     *
     * To avoid accidental use of raw pointers, habets39::tag2pdu's
     * constructor is in a private implementation
     * class. habets39::tag2pdu::make is the public interface for
     * creating new instances.
     */
    static sptr
    make(const std::string& tag_start, const std::string& tag_end, int min_size);
};

} // namespace habets39
} // namespace gr

#endif /* INCLUDED_HABETS39_TAG2PDU_H */
