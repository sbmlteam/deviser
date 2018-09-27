#!/usr/bin/env python
#
# @file    global_variables.py
# @brief   general functions for querying objects
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2018 by the California Institute of Technology
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

import os


global error_list
error_list = []
global class_rules
class_rules = []

global running_tests
running_tests = False

global figures_present
figures_present = False

global deviser_file
deviser_file = ''

global current_dir
current_dir = os.getcwd()

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
global up_full_lib
up_full_lib = 'LIBSBML'
global is_package
is_package = True
global package_prefix
package_prefix = ''
global package_full_name
package_full_name = ''
global has_level_version
has_level_version = True
global top_level_element_name
top_level_element_name = 'sbml'
global annot_element
annot_element = 'Annotation'

global return_codes
return_codes= dict({'success': 0,
                    'failed to read file': 1,
                    'missing function argument': 2,
                    'invalid function arguments': 3,
                    'parsing error': 4,
                    'unknown type used': 5,
                    'unknown error - please report': 6,
                    'missing required information': 7})

global code_returned
code_returned = return_codes['success']

global ret_success
#ret_success = '{0}_OPERATION_SUCCESS'.format(library_name.upper())

global ret_failed
#ret_failed = '{0}_OPERATION_FAILED'.format(library_name.upper())

global ret_invalid_obj
#ret_invalid_obj = '{0}_INVALID_OBJECT'.format(library_name.upper())

global ret_invalid_att
#ret_invalid_att = '{0}_INVALID_ATTRIBUTE_VALUE'.format(library_name.upper())

global ret_level_mis
#ret_level_mis = '{0}_LEVEL_MISMATCH'.format(library_name.upper())

global ret_vers_mis
#ret_vers_mis = '{0}_VERSION_MISMATCH'.format(library_name.upper())

global ret_pkgv_mis
#ret_pkgv_mis = '{0}_PKG_VERSION_MISMATCH'.format(library_name.upper())

global ret_ns_mis
#ret_ns_mis = '{0}_NAMESPACES_MISMATCH'.format(library_name.upper())

global ret_dup_id
#ret_dup_id = '{0}_DUPLICATE_OBJECT_ID'.format(library_name.upper())

global ret_att_unex
#ret_att_unex = '{0}_UNEXPECTED_ATTRIBUTE'.format(library_name.upper())

global namespaces
global dependency
global library_version

global custom_copyright
custom_copyright = ''

global add_implementation
add_implementation = []
global add_declaration
add_declaration = []

def add_additional_implementation(filename):
    if filename is not None:
        global add_implementation
        add_implementation.append(filename)

def add_additional_declaration(filename):
    if filename is not None:
        global add_declaration
        add_declaration.append(filename)

def set_custom_copyright(copyright):
    global custom_copyright
    custom_copyright = copyright

def set_global_fullname(fullname):
    global package_full_name
    package_full_name = fullname


def set_globals(lang, base, doc, prfix, lib, is_pack, pkg_prefix,
                specifications=[], depend=[], library_vers=[], copyright='', annot_elem=''):
    global language
    language = lang

    global namespaces
    global has_level_version
    namespaces = []
    if len(specifications) > 0:
        namespaces = specifications
        if not 'level' in namespaces[0] or not namespaces[0]['level']:
            has_level_version = False
    else:
        namespaces.append(dict({'namespace': 'not defined'}))

    global dependency
    dependency = []
    if len(depend) > 0:
        dependency = depend

    global library_version
    library_version = []
    if library_vers:
        library_version = library_vers

    global custom_copyright
    custom_copyright = copyright

    if base:
        global baseClass
        baseClass = base
        global std_base
        std_base = base

    if prfix:
        global prefix
        prefix = prfix

    if doc:
        global document_class
        global top_level_element_name
        document_class = doc
        # this is a bit of a hack as sedml and combine archive vary
        if doc.endswith('Document'):
            top_level_element_name = language
        else:
            top_level_element_name = doc
        if not doc.startswith(prefix):
            document_class = '{0}{1}'.format(prefix, doc)


    global package_prefix
    if pkg_prefix:
        package_prefix = pkg_prefix
    elif pkg_prefix == '':
        package_prefix = ''

    global annot_element
    if annot_elem != '':
        annot_element = annot_elem


    global library_name
    if lib:
        library_name = lib
    else:
        library_name = 'Lib' + language

    global up_full_lib
    if not library_name.upper().startswith('LIB'):
        up_full_lib = 'LIB{0}'.format(library_name.upper())
    else:
        up_full_lib = library_name.upper()

    global is_package
    is_package = is_pack

    global ret_success
    ret_success = '{0}_OPERATION_SUCCESS'.format(library_name.upper())

    global ret_failed
    ret_failed = '{0}_OPERATION_FAILED'.format(library_name.upper())

    global ret_invalid_obj
    ret_invalid_obj = '{0}_INVALID_OBJECT'.format(library_name.upper())

    global ret_invalid_att
    ret_invalid_att = '{0}_INVALID_ATTRIBUTE_VALUE'.format(library_name.upper())

    global ret_level_mis
    ret_level_mis = '{0}_LEVEL_MISMATCH'.format(library_name.upper())

    global ret_vers_mis
    ret_vers_mis = '{0}_VERSION_MISMATCH'.format(library_name.upper())

    global ret_pkgv_mis
    ret_pkgv_mis = '{0}_PKG_VERSION_MISMATCH'.format(library_name.upper())

    global ret_ns_mis
    ret_ns_mis = '{0}_NAMESPACES_MISMATCH'.format(library_name.upper())

    global ret_dup_id
    ret_dup_id = '{0}_DUPLICATE_OBJECT_ID'.format(library_name.upper())

    global ret_att_unex
    ret_att_unex = '{0}_UNEXPECTED_ATTRIBUTE'.format(library_name.upper())




def get_return_code(index):
    matched = False
    length = len(return_codes)
    values = list(return_codes.values())
    items = list(return_codes.keys())
    i = 0
    while not matched and i < length:
        if values[i] == index:
            matched = True
        else:
            i += 1
    if not matched:
        return 'not found'
    else:
        returned_word = items[i]
        length = len(returned_word)
        return returned_word[0].upper() + returned_word[1:length]


def reset():
    set_globals('sbml', 'SBase', 'SBMLDocument', 'SBML', 'Libsbml',
                True, '')
    global error_list
    error_list = []
    global class_rules
    class_rules = []
    global add_implementation
    add_implementation = []
    global add_declaration
    add_declaration = []


def populate_error_list(lib_object):
    from code_files import ValidationFiles
    ValidationFiles.ValidationFiles(lib_object)
