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


# return True is any of the attributes refer to elements
def has_children(attributes):
    if any(attribute['type'] == 'element' for attribute in attributes):
        return True
    elif any(attribute['type'] == 'lo_element' for attribute in attributes):
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


# return a set of attributes with any elements/lo_elements removed
def seperate_attributes(full_attributes):
    attributes = []
    for i in range(0, len(full_attributes)):
        att_type = full_attributes[i]['attType']
        if att_type != 'element' and att_type != 'lo_element':
            attributes.append(full_attributes[i])
    return attributes

###############################################################
# function to clarify the object names for the different types

# get functions
def create_structure_for_getters(in_name, class_name, attribute, is_cpp, is_list):
    # attribute will be empty if we are using a ListOf class
    if len(attribute) == 0:
        if is_cpp:
            name = in_name
        else:
            name = in_name + '_t'
        cap_name = name
        plural = strFunctions.plural(name)
    else:
        name = attribute['element']
        cap_name = attribute['capAttName']
        plural = strFunctions.upper_first(attribute['pluralName'])
    ob_name = name
    if is_list and not is_cpp:
        parent = strFunctions.list_of_name(in_name)
        name = in_name
        ob_parent = 'ListOf_t' # strFunctions.list_of_name(in_name) + '_t'
    else:
        parent = class_name
        ob_parent = class_name
    if not is_list and not is_cpp:
        ob_parent = class_name + '_t'
        ob_name = name + '_t'

    indef = strFunctions.get_indefinite(name)
    struct = dict({'name': name,
                   'cap_name': cap_name,
                   'plural': plural,
                   'parent': parent,
                   'ob_parent': ob_parent,
                   'ob_name': ob_name,
                   'indef': indef,
                   'class_name': class_name})
    return struct

# add/getNum functions
def create_structure_for_children(in_name, class_name, attribute, is_cpp, is_list):
    if not is_list:
        name = attribute['element']
        parent = class_name
        if is_cpp:
            ob_name = attribute['element']
            ob_parent = class_name
        else:
            ob_name = attribute['element'] + '_t'
            ob_parent = class_name + '_t'
    else:
        ob_name = in_name
        name = in_name
        parent = class_name
        ob_parent = class_name
    struct = dict({'name': name,
                   'parent': parent,
                   'ob_parent': ob_parent,
                   'ob_name': ob_name,
                   'class_name': class_name})
    return struct
