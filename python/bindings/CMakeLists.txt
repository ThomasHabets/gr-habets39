# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT habets39_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT habets39_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND habets39_python_files
    sweepsinkv_python.cc
    tag2pdu_python.cc
    hdlc_unstuff_python.cc
    pdu_pack_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(habets39 
   ../..
   gr::habets39
   "${habets39_python_files}")

install(TARGETS habets39_python DESTINATION ${GR_PYTHON_DIR}/habets39 COMPONENT pythonapi)
