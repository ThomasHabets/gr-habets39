/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HABETS39_HDLC_UNSTUFF_H
#define INCLUDED_HABETS39_HDLC_UNSTUFF_H

#include <gnuradio/block.h>
#include <habets39/api.h>

namespace gr {
namespace habets39 {

/*!
 * \brief <+description of block+>
 * \ingroup habets39
 *
 */
class HABETS39_API hdlc_unstuff : virtual public gr::block
{
public:
    typedef std::shared_ptr<hdlc_unstuff> sptr;

    /*!
     * \brief Return a shared_ptr to a new instance of habets39::hdlc_unstuff.
     *
     * To avoid accidental use of raw pointers, habets39::hdlc_unstuff's
     * constructor is in a private implementation
     * class. habets39::hdlc_unstuff::make is the public interface for
     * creating new instances.
     */
    static sptr make();
};

} // namespace habets39
} // namespace gr

#endif /* INCLUDED_HABETS39_HDLC_UNSTUFF_H */
