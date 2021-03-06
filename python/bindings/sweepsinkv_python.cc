/*
 * Copyright 2021 Free Software Foundation, Inc.
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
/* BINDTOOL_HEADER_FILE(sweepsinkv.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(ab9aaf54cf2c116488465d8a6ebb83d1)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <habets39/sweepsinkv.h>
// pydoc.h is automatically generated in the build directory
#include <sweepsinkv_pydoc.h>

void bind_sweepsinkv(py::module& m)
{

    using sweepsinkv    = gr::habets39::sweepsinkv;


    py::class_<sweepsinkv, gr::block, gr::basic_block,
        std::shared_ptr<sweepsinkv>>(m, "sweepsinkv", D(sweepsinkv))

        .def(py::init(&sweepsinkv::make),
           D(sweepsinkv,make)
        )
        



        ;




}








