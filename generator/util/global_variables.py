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

global ret_success
ret_success = 'LIB{}_OPERATION_SUCCESS'.format(language.upper())

global ret_failed
ret_failed = 'LIB{}_OPERATION_FAILED'.format(language.upper())

global ret_invalid_obj
ret_invalid_obj = 'LIB{}_INVALID_OBJECT'.format(language.upper())

global ret_invalid_att
ret_invalid_att = 'LIB{}_INVALID_ATTRIBUTE_VALUE'.format(language.upper())

global ret_level_mis
ret_level_mis = 'LIB{}_LEVEL_MISMATCH'.format(language.upper())

global ret_vers_mis
ret_vers_mis = 'LIB{}_VERSION_MISMATCH'.format(language.upper())

global ret_pkgv_mis
ret_pkgv_mis = 'LIB{}_PKG_VERSION_MISMATCH'.format(language.upper())

global ret_ns_mis
ret_ns_mis = 'LIB{}_NAMESPACES_MISMATCH'.format(language.upper())

global ret_dup_id
ret_dup_id = 'LIB{}_DUPLICATE_OBJECT_ID'.format(language.upper())

global ret_att_unex
ret_att_unex = 'LIB{}_UNEXPECTED_ATTRIBUTE'.format(language.upper())


def set_language(name):
    language = name
    global ret_success
    ret_success = 'LIB{}_OPERATION_SUCCESS'.format(language.upper())

    global ret_failed
    ret_failed = 'LIB{}_OPERATION_FAILED'.format(language.upper())

    global ret_invalid_obj
    ret_invalid_obj = 'LIB{}_INVALID_OBJECT'.format(language.upper())

    global ret_invalid_att
    ret_invalid_att = 'LIB{}_INVALID_ATTRIBUTE_VALUE'.format(language.upper())

    global ret_level_mis
    ret_level_mis = 'LIB{}_LEVEL_MISMATCH'.format(language.upper())

    global ret_vers_mis
    ret_vers_mis = 'LIB{}_VERSION_MISMATCH'.format(language.upper())

    global ret_pkgv_mis
    ret_pkgv_mis = 'LIB{}_PKG_VERSION_MISMATCH'.format(language.upper())

    global ret_ns_mis
    ret_ns_mis = 'LIB{}_NAMESPACES_MISMATCH'.format(language.upper())

    global ret_dup_id
    ret_dup_id = 'LIB{}_DUPLICATE_OBJECT_ID'.format(language.upper())

    global ret_att_unex
    ret_att_unex = 'LIB{}_UNEXPECTED_ATTRIBUTE'.format(language.upper())


