/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(pdu_pack.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(61234a05062baf1fdb084fba44e12a23)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <habets39/pdu_pack.h>
// pydoc.h is automatically generated in the build directory
#include <pdu_pack_pydoc.h>

void bind_pdu_pack(py::module& m)
{

    using pdu_pack    = gr::habets39::pdu_pack;


    py::class_<pdu_pack, gr::block, gr::basic_block,
        std::shared_ptr<pdu_pack>>(m, "pdu_pack", D(pdu_pack))

        .def(py::init(&pdu_pack::make),
           D(pdu_pack,make)
        )
        



        ;




}







