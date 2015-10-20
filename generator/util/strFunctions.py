#!/usr/bin/env python
#
# @file    strFunctions.py
# @brief   functions atht adjust strings in some way
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

import re
import global_variables


def upper_first(word):
    if len(word) == 0:
        return word
    returned_word = word[0].upper() + word[1:len(word)]
    return returned_word


def lower_first(word):
    # hack for spatial CSGFoo classes
    if word.startswith('CSG'):
        returned_word = 'csg' + word[3:len(word)]
    else:
        returned_word = word[0].lower() + word[1:len(word)]
    return returned_word


def get_indent(element):
    s1 = '{0}('.format(element)
    return len(s1)


def abbrev_name(element):
    abbrev = ''
    for i in range(0, len(element)):
        if element[i].isupper():
            abbrev = abbrev + element[i]
    return abbrev.lower()


def list_of_name(name):
    prefix = ''
    if not global_variables.is_package:
        prefix = global_variables.prefix
    return prefix + 'ListOf' + plural_no_prefix(name)


def cap_list_of_name(name):
    name = upper_first(name)
    return list_of_name(name)


def plural_no_prefix(name):
    if global_variables.is_package:
        return plural(name)
    else:
        new_name = remove_prefix(name)
        return plural(new_name)


def plural(name):
    if name.endswith('s'):
        returned_word = name
    elif name.endswith('nformation'):
        returned_word = name
    elif name.endswith('x'):
        returned_word = name[0:len(name)-1] + 'es'
    else:
        returned_word = name + 's'
    return returned_word


def remove_prefix(name):
    prefix_to_remove = ''
    if global_variables.prefix == 'SBML':
        # we might want to remove the name of the package
        if global_variables.is_package \
                and global_variables.package_prefix != '':
            prefix_to_remove = global_variables.package_prefix
    else:
        prefix_to_remove = global_variables.prefix
    length = len(prefix_to_remove)
    if length == 0:
        return name
    if name.startswith(prefix_to_remove):
        newname = name[length:]
    else:
        newname = name
    return newname


def get_indefinite(name):
    if name.startswith('a') or name.startswith('A') \
            or name.startswith('e') or name.startswith('E') \
            or name.startswith('i') or name.startswith('I') \
            or name.startswith('o') or name.startswith('O') \
            or name.startswith('u') or name.startswith('U'):
        return 'an'
    else:
        return 'a'


def standard_element_name(name):
    if name.endswith('*'):
        length = len(name)
        name = name[0:length-1]
    return upper_first(name)


def wrap_token(name, pkg=''):
    """ returns the name wrapped as a token
       e.g. \token{'id'} or \token{'comp:\-id'} """
    if pkg == '':
        return '\\token{' + name + '}'
    else:
        return '\\token{' + pkg + ':\\-' + name + '}'


def wrap_type(name, element, hack=False):
    if name == 'array':
        return 'consisting of an array of \\primtype{' + element + '}'
    elif name == 'enum':
        element_name = texify(element)
        return 'of type \\primtype{' + element_name + '}'
    elif name == 'element':
        if hack:
            return 'of type \\' + element
        else:
            return wrap_token(element)
    elif name == 'lo_element':
        return wrap_token(element)
    elif name == 'inline_lo_element':
        return 'TO DO: add type'
    else:
        return 'of type \\primtype{' + name + '}'


def wrap_section(name, add_class=True):
    if add_class:
        return '\\sec{' + make_class(name) + '}'
    else:
        return '\\sec{' + name + '}'


def make_class(name):
    return name.lower() + '-class'


def wrap_enum(name):
    return '\\primtype{' + lower_first(name) + '}'


def get_element_name(attribute):
    if 'type' in attribute:
        if attribute['type'] == 'lo_element':
            return '\{}'.format(cap_list_of_name(attribute['texname']))
        elif attribute['type'] == 'inline_lo_element':
            return '\{}'.format(cap_list_of_name(attribute['texname']))
        elif attribute['type'] == 'element':
            if attribute['element'] == 'ASTNode*':
                return 'MathML math'
            else:
                return attribute['element']
        else:
            return 'FIX_ME'
    elif 'isListOf' in attribute:
        if attribute['isListOf']:
            return '\{}'.format(cap_list_of_name(attribute['name']))
        else:
            return '\{}'.format(upper_first(attribute['name']))
    else:
        return 'FIX ME'


def replace_digits(name):
    name = re.sub('0', 'Zero', name)
    name = re.sub('1', 'One', name)
    name = re.sub('2', 'Two', name)
    name = re.sub('3', 'Three', name)
    name = re.sub('4', 'Four', name)
    name = re.sub('5', 'Five', name)
    name = re.sub('6', 'Six', name)
    name = re.sub('7', 'Seven', name)
    name = re.sub('8', 'Eight', name)
    name = re.sub('9', 'Nine', name)
    return name


def replace_underscore(name):
    name = re.sub('_', '\_', name)
    return name


def remove_spaces(name):
    newname = ''
    for i in range(0, len(name)):
        if name[i] != ' ':
            newname += name[i]
    return newname


def texify(name):
    name = replace_digits(name)
    name = replace_underscore(name)
    name = remove_spaces(name)
    return name


def compare_no_case(name, reference):
    caseless_name = name.lower()
    caseless_ref = reference.lower()
    if caseless_name == caseless_ref:
        return True
    else:
        return False


def get_class_from_plugin(plugin, package):
    num = len(package)
    length = len(plugin)
    name = plugin[num:length-6]
    return name