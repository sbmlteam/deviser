#!/usr/bin/env python
#
# @file    global_variables.py
# @brief   general functions for querying objects
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2014 by the California Institute of Technology
# (California, USA), the European Bioinformatics Institute (EMBL-EBI, UK)
# and the University of Heidelberg (Germany), with support from the National
# Institutes of Health (USA) under grant R01GM070923.  All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
# Neither the name of the California Institute of Technology (Caltech), nor
# of the European Bioinformatics Institute (EMBL-EBI), nor of the University
# of Heidelberg, nor the names of any contributors, may be used to endorse
# or promote products derived from this software without specific prior
# written permission.
# ------------------------------------------------------------------------ -->

global error_list
error_list = []

global running_tests
running_tests = False

global language
language = 'sbml'
global baseClass
baseClass = 'SBase'
global std_base
std_base = 'SBase'
global document_class
document_class = 'SBMLDocument'
global prefix
prefix = 'SBML'
global library_name
library_name = 'Libsbml'
global ignore_package
is_package = True


global ret_success
ret_success = '{}_OPERATION_SUCCESS'.format(library_name.upper())

global ret_failed
ret_failed = '{}_OPERATION_FAILED'.format(library_name.upper())

global ret_invalid_obj
ret_invalid_obj = '{}_INVALID_OBJECT'.format(library_name.upper())

global ret_invalid_att
ret_invalid_att = '{}_INVALID_ATTRIBUTE_VALUE'.format(library_name.upper())

global ret_level_mis
ret_level_mis = '{}_LEVEL_MISMATCH'.format(library_name.upper())

global ret_vers_mis
ret_vers_mis = '{}_VERSION_MISMATCH'.format(library_name.upper())

global ret_pkgv_mis
ret_pkgv_mis = '{}_PKG_VERSION_MISMATCH'.format(library_name.upper())

global ret_ns_mis
ret_ns_mis = '{}_NAMESPACES_MISMATCH'.format(library_name.upper())

global ret_dup_id
ret_dup_id = '{}_DUPLICATE_OBJECT_ID'.format(library_name.upper())

global ret_att_unex
ret_att_unex = '{}_UNEXPECTED_ATTRIBUTE'.format(library_name.upper())


def set_globals(lang, base, doc, prfix, lib, is_pack):
    global language
    language = lang

    global baseClass
    baseClass = base
    global std_base
    std_base = base
    global document_class
    document_class = doc
    global prefix
    prefix = prfix
    global library_name
    library_name = lib
    global is_package
    is_package = is_pack

    global ret_success
    ret_success = '{}_OPERATION_SUCCESS'.format(library_name.upper())

    global ret_failed
    ret_failed = '{}_OPERATION_FAILED'.format(library_name.upper())

    global ret_invalid_obj
    ret_invalid_obj = '{}_INVALID_OBJECT'.format(library_name.upper())

    global ret_invalid_att
    ret_invalid_att = '{}_INVALID_ATTRIBUTE_VALUE'.format(library_name.upper())

    global ret_level_mis
    ret_level_mis = '{}_LEVEL_MISMATCH'.format(library_name.upper())

    global ret_vers_mis
    ret_vers_mis = '{}_VERSION_MISMATCH'.format(library_name.upper())

    global ret_pkgv_mis
    ret_pkgv_mis = '{}_PKG_VERSION_MISMATCH'.format(library_name.upper())

    global ret_ns_mis
    ret_ns_mis = '{}_NAMESPACES_MISMATCH'.format(library_name.upper())

    global ret_dup_id
    ret_dup_id = '{}_DUPLICATE_OBJECT_ID'.format(library_name.upper())

    global ret_att_unex
    ret_att_unex = '{}_UNEXPECTED_ATTRIBUTE'.format(library_name.upper())


