/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HABETS39_PDU_PACK_H
#define INCLUDED_HABETS39_PDU_PACK_H

#include <gnuradio/block.h>
#include <habets39/api.h>

namespace gr {
namespace habets39 {

/*!
 * \brief <+description of block+>
 * \ingroup habets39
 *
 */
class HABETS39_API pdu_pack : virtual public gr::block
{
public:
    typedef std::shared_ptr<pdu_pack> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of habets39::pdu_pack.
     *
     * To avoid accidental use of raw pointers, habets39::pdu_pack's
     * constructor is in a private implementation
     * class. habets39::pdu_pack::make is the public interface for
     * creating new instances.
     */
    static sptr make(bool strict = false);
};

} // namespace habets39
} // namespace gr

#endif /* INCLUDED_HABETS39_PDU_PACK_H */
