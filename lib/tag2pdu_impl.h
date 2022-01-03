/* -*- c++ -*- */
/*
 * Copyright 2022 Thomas Habets <thomas@habets.se>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_HABETS39_TAG2PDU_IMPL_H
#define INCLUDED_HABETS39_TAG2PDU_IMPL_H

#include <habets39/tag2pdu.h>

namespace gr {
namespace habets39 {

class tag2pdu_impl : public tag2pdu
{
private:
    pmt::pmt_t d_port;
    pmt::pmt_t d_tag_start;
    pmt::pmt_t d_tag_end;
    bool d_active = false;
    std::vector<uint8_t> d_data;
    int d_min_size;

public:
    tag2pdu_impl(const std::string& tag_start, const std::string& tag_end, int min_size);
    ~tag2pdu_impl();

    // Where all the action really happens

    int general_work(int noutput_items,
                     gr_vector_int& ninput_items,
                     gr_vector_const_void_star& input_items,
                     gr_vector_void_star& output_items);
};

} // namespace habets39
} // namespace gr

#endif /* INCLUDED_HABETS39_TAG2PDU_IMPL_H */
