/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HABETS39_HDLC_UNSTUFF_IMPL_H
#define INCLUDED_HABETS39_HDLC_UNSTUFF_IMPL_H

#include <habets39/hdlc_unstuff.h>

namespace gr {
namespace habets39 {

class hdlc_unstuff_impl : public hdlc_unstuff
{
private:
    pmt::pmt_t d_in;
    pmt::pmt_t d_out;
    void handle(const pmt::pmt_t& msg);

public:
    hdlc_unstuff_impl();
    ~hdlc_unstuff_impl();
};

} // namespace habets39
} // namespace gr

#endif /* INCLUDED_HABETS39_HDLC_UNSTUFF_IMPL_H */
