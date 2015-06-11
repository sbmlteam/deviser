#!/usr/bin/env python
#
# @file    query.py
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

import strFunctions


# return True is any of the attributes are of type SIdRef
def has_sid_ref(attributes):
    if any(attribute['type'] == 'SIdRef' for attribute in attributes):
        return True
    return False


# return a set of attributes that are of type SIdRef
def get_sid_refs(attributes):
    sid_refs = []
    for i in range(0, len(attributes)):
        if strFunctions.compare_no_case(attributes[i]['type'], 'SIdRef'):
            sid_refs.append(attributes[i])
    return sid_refs


# return a set of attributes that are SIdRefs for the given class
def get_sid_refs_for_class(working_class):
    sid_refs = []
    child_element = get_class(working_class['element'],
                              working_class['root'])
    if child_element is not None:
        sid_refs = get_sid_refs(child_element['attribs'])
    return sid_refs


# return True is any of the attributes refer to elements
def has_children(attributes):
    if any(attribute['type'] == 'element' for attribute in attributes):
        return True
    elif any(attribute['type'] == 'lo_element' for attribute in attributes):
        return True
    return False


# return True is any of the attributes refer to elements but not math
def has_children_not_math(attributes):
    for i in range(0, len(attributes)):
        if attributes[i]['type'] == 'lo_element':
            return True
        elif attributes[i]['type'] == 'element' \
                and attributes[i]['name'] != 'math':
            return True
    return False


# return the class with the matching name from the root object
def get_class(name, root_object):
    if root_object is None:
        return None
    elif root_object['sbmlElements'] is None:
        return None
    else:
        for i in range(0, len(root_object['sbmlElements'])):
            if name == root_object['sbmlElements'][i]['name']:
                return root_object['sbmlElements'][i]


# return a list of the actual concrete classes
def get_concretes(root_object, concrete_list):
    concretes = []
    for c in concrete_list:
        add_concrete_to_list(root_object, c, concretes)
    return concretes


# add the non-abstract class to the list
def add_concrete_to_list(root, concrete, mylist):
    current = get_class(concrete['element'], root)
    if current is not None:
        if current['abstract'] is False:
            mylist.append(concrete)
        else:
            for c in current['concrete']:
                if c != concrete:
                    add_concrete_to_list(root, c, mylist)


# return a set of attributes with any elements/lo_elements removed
def seperate_attributes(full_attributes):
    attributes = []
    for i in range(0, len(full_attributes)):
        att_type = full_attributes[i]['attType']
        if att_type != 'element' and att_type != 'lo_element':
            attributes.append(full_attributes[i])
    return attributes
