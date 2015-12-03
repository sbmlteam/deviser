#!/usr/bin/env python
#
# @file    query.py
# @brief   general functions for querying objects
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2015 by the California Institute of Technology
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

from . import strFunctions


# return True is any of the attributes are of type SIdRef
def has_sid_ref(attributes):
    if any(attribute['type'] == 'SIdRef' for attribute in attributes):
        return True
    return False


# return a set of attributes that are of type SIdRef
def get_sid_refs(attributes, unit=False):
    sid_refs = []
    if not unit:
        match = 'SIdRef'
    else:
        match = 'UnitSIdRef'
    for i in range(0, len(attributes)):
        if strFunctions.compare_no_case(attributes[i]['type'], match):
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
    elif any(attribute['type'] == 'inline_lo_element'
             for attribute in attributes):
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
    elif root_object['baseElements'] is None:
        return None
    else:
        for i in range(0, len(root_object['baseElements'])):
            if name == root_object['baseElements'][i]['name']:
                return root_object['baseElements'][i]


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
            concrete['type_code'] = current['typecode']
            mylist.append(concrete)
        else:
            for c in current['concrete']:
                if c != concrete:
                    add_concrete_to_list(root, c, mylist)


# return a set of attributes with any elements/lo_elements removed
# populating the version information
def separate_attributes(full_attributes):
    attributes = []
    for i in range(0, len(full_attributes)):
        att_type = full_attributes[i]['attType']
        name = full_attributes[i]['name']
        if att_type != 'element' and att_type != 'lo_element':
            existing = get_matching_element('name', name, attributes)
            if existing:
                vers = full_attributes[i]['version']
                existing['version_info'][vers-1] = True
            else:
                attributes.append(full_attributes[i])
    return attributes


# return attributes for the given version only
def get_version_attributes(attributes, version):
    ver_attribs = []
    for i in range(0, len(attributes)):
        att_type = attributes[i]['attType']
        if att_type != 'element' and att_type != 'lo_element':
            if attributes[i]['version'] == version:
                ver_attribs.append(attributes[i])
    return ver_attribs


# return a set of unique attributes
#  any with multiple versions appear only once
def get_unique_attributes(full_attributes):
    attributes = []
    for i in range(0, len(full_attributes)):
        name = full_attributes[i]['name']
        existing = get_matching_element('name', name, attributes)
        if existing:
            continue
        else:
            attributes.append(full_attributes[i])
    return attributes


def get_matching_element(name, match_name, list_elements):
    element = None
    if not list_elements:
        return element
    for existing in list_elements:
        if existing[name] == match_name:
            element = existing
    return element


# return True is any of the attributes are of type array
def has_array(attributes):
    if any(attribute['type'] == 'array' for attribute in attributes):
        return True
    return False


# return True is the attribute is saved as a string
def is_string(attribute):
    if attribute['attType'] == 'string':
        return True
    return False


# return True is the attribute has an isSet member variable
def has_is_set_member(attribute):
    if attribute['isNumber'] or attribute['attType'] == 'boolean':
        return True
    return False


# return True if the element has the attribute specified
def has_attribute(element, attribute):
    if element is None:
        return False
    elif element['attribs'] is None:
        return False
    else:
        for i in range(0, len(element['attribs'])):
            if attribute == element['attribs'][i]['name']:
                return True
    return False


# works out if any classes use this element
# with a different name
def overwrites_name(root, name):
    if root is None:
        return False
    for element in root['baseElements']:
        for attrib in element['attribs']:
            if attrib['element'] == name:
                if strFunctions.compare_no_case(name, attrib['xml_name']):
                    return False
                else:
                    return True
    return False


def get_static_extension_attribs(num_versions):
    attribs = []
    att = dict({'name': 'packageName',
                'capAttName': 'PackageName',
                'attTypeCode': 'std::string&',
                'attType': 'string',
                'memberName': ''})
    attribs.append(att)
    att = dict({'name': 'defaultLevel',
                'capAttName': 'DefaultLevel',
                'attTypeCode': 'unsigned int',
                'attType': 'unsigned integer',
                'memberName': 3})
    attribs.append(att)
    att = dict({'name': 'defaultVersion',
                'capAttName': 'DefaultVersion',
                'attTypeCode': 'unsigned int',
                'attType': 'unsigned integer',
                'memberName': 1})
    attribs.append(att)
    att = dict({'name': 'defaultPackageVersion',
                'capAttName': 'DefaultPackageVersion',
                'attTypeCode': 'unsigned int',
                'attType': 'unsigned integer',
                'memberName': 1})
    attribs.append(att)
    for i in range(0, num_versions):
        name = 'xmlnsL3V1V{0}'.format(i+1)
        cap_name = strFunctions.upper_first(name)
        att = dict({'name': name,
                    'capAttName': cap_name,
                    'attTypeCode': 'std::string&',
                    'attType': 'string',
                    'memberName': 'fix this'})
        attribs.append(att)

    return attribs


# get enumeration values
def get_typecode_enum(elements):
    value = []
    strvalue = []
    max_length = 0
    for i in range(0, len(elements)):
        tc = elements[i]['typecode']
        if len(tc) > max_length:
            max_length = len(tc)
        value.append(tc)
        strvalue.append(elements[i]['name'])
    return [value, strvalue, max_length]


# get enumeration values
def get_enum(element):
    name = element['name']
    value = []
    strvalue = []
    max_length = 0
    for i in range(0, len(element['values'])):
        tc = element['values'][i]['name']
        if len(tc) > max_length:
            max_length = len(tc)
        value.append(tc)
        strvalue.append(element['values'][i]['value'])
    tc = get_prefix(name) + '_INVALID'
    if len(tc) > max_length:
        max_length = len(tc)
    value.append(tc)
    strvalue.append('invalid {0}'.format(name))
    return [value, strvalue, max_length]


def get_default_enum_value(attribute):
    prefix = ''
    name = attribute['element']
    enums = attribute['root']['enums']
    for i in range(0, len(enums)):
        if name == enums[i]['name']:
            prefix = get_prefix(name)
    default = prefix + '_INVALID'
    return default


def get_prefix(name):
    prefix = ''
    first = True
    for i in range(0, len(name)):
        char = name[i]
        if char.isupper():
            if first:
                prefix += char
                first = False
            else:
                prefix += '_{0}'.format(char)
        else:
            prefix += char.upper()
    return prefix


def get_typecode_format(name, language):
    tc = language.upper()
    for i in range(0, len(name)):
        char = name[i]
        if char.isupper():
            tc += '_'
        tc += char.upper()
    return tc


def get_max_length(elements, attribute):
    if elements is None:
        return 0
    if attribute not in elements[0]:
        return 0
    else:
        max_len = len(elements[0][attribute])
    for i in range(1, len(elements)):
        if len(elements[i][attribute]) > max_len:
            max_len = len(elements[i][attribute])
    return max_len


def get_other_element_children(this_object, element):
    other_children = []
    child = get_class(element['element'], this_object['root'])
    if child is None or 'lo_attribs' not in child:
        return other_children
    for i in range(0, len(child['lo_attribs'])):
        if child['lo_attribs'][i]['type'] == 'element':
            other_children.append(child['lo_attribs'][i]['element'])
    return other_children