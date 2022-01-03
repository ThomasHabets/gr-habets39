/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HABETS39_PDU_PACK_IMPL_H
#define INCLUDED_HABETS39_PDU_PACK_IMPL_H

#include <habets39/pdu_pack.h>

namespace gr {
namespace habets39 {

class pdu_pack_impl : public pdu_pack
{
private:
    bool d_strict;
    pmt::pmt_t d_in;
    pmt::pmt_t d_out;

public:
    pdu_pack_impl(bool strict);
    ~pdu_pack_impl();

    void handle(const pmt::pmt_t& msg);
};

} // namespace habets39
} // namespace gr

#endif /* INCLUDED_HABETS39_PDU_PACK_IMPL_H */
