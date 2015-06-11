#!/usr/bin/env python
#
# @file    createPackageFromXml.py
# @brief   function to take the output from Deviser Edit and create
#             the expected dictionaries
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


from xml.dom.minidom import *
import os.path

from util import strFunctions


def to_bool(v):
    if v is None:
        return False
    return v.lower() in ("yes", "true", "1")


def to_int(v):
    if v is None:
        return 0
    return int(float(v))


def get_value(node, name):
    temp = node.getAttributeNode(name)
    if temp is None:
        return None
    return temp.nodeValue


def find_element(elements, name):
    if elements is None or name is None:
        return None
    for element in elements:
        if element['name'] == name:
            return element
    return None


def standardize_types(attrib_type):
    name = attrib_type.lower()
    if name == 'boolean' or name == 'bool':
        return 'bool'
    elif name == 'unsigned integer' or name == 'unsigned int':
        return 'uint'
    elif name == 'integer' or name == 'int':
        return 'int'
    elif name == 'sidref':
        return 'SIdRef'
    elif name == 'unitsidref':
        return 'UnitSIdRef'
    elif name == 'sid':
        return 'SId'
    elif name == 'unitsid':
        return 'UnitSId'
    elif name == 'uint' or name == 'string' or name == 'double' \
            or name == 'enum' or name == 'element' or name == 'lo_element':
        return name
    else:
        return attrib_type


def find_lo_element(elements, name):
    if elements is None or name is None:
        return None
    for element in elements:
        if 'isListOf' in element and element['isListOf'] is True:
            match = strFunctions.list_of_name(element['name'])
            if 'listOfClassName' in element \
                    and element['listOfClassName'] != '':
                match = element['listOfClassName']
            if match.lower() == name.lower():
                return element
    return None


def parse_deviser_xml(filename):
    """
    Parses the given filename and returns a dictionary with
    the definition contained in it
    """

    sbml_elements = []
    elements = []
    plugins = []
    enums = []

    dom = parse(filename)

    temp = get_value(dom.documentElement, 'name')
    # we expect this to be lower case
    package_name = temp.lower()
    number = to_int(get_value(dom.documentElement, 'number'))
    offset = to_int(get_value(dom.documentElement, 'offset'))
    fullname = get_value(dom.documentElement, 'fullname')
    required = to_bool(get_value(dom.documentElement, 'required'))

    # get package information (assume we want the first only)
    sbml_level = 3
    sbml_version = 1
    pkg_version = 1
    for node in dom.getElementsByTagName('pkgVersion'):
        sbml_level = to_int(get_value(node, 'level'))
        sbml_version = to_int(get_value(node, 'version'))
        pkg_version = to_int(get_value(node, 'pkg_version'))
        break

    concrete_dict = dict({})

    # read concrete versions of abstract classes and fill dictionary
    for node in dom.getElementsByTagName('element'):
        element_name = get_value(node, 'name')
        concrete_list = []
        for concrete in node.getElementsByTagName('concrete'):
            concrete_list.append(
                dict(
                    {'name': get_value(concrete, "name"),
                     'element': get_value(concrete, "element")}
                ))
        concrete_dict[element_name] = concrete_list

    # read element
    for node in dom.getElementsByTagName('element'):

        element_name = get_value(node, 'name')
        base_class = get_value(node, 'baseClass')
        type_code = get_value(node, 'typeCode')
        has_math = to_bool(get_value(node, 'hasMath'))
        has_children = to_bool(get_value(node, 'hasChildren'))
        has_list_of = to_bool(get_value(node, 'hasListOf'))
        abstract = to_bool(get_value(node, 'abstract'))
        children_overwrite_element_name = to_bool(
            get_value(node, 'childrenOverwriteElementName'))

        temp = get_value(node, 'elementName')
        # we expect this to be camel case starting with lower
        if temp is not None:
            xml_element_name = strFunctions.lower_first(temp)
        else:
            xml_element_name = ''

        temp = get_value(node, 'listOfName')
        # we expect this to be camel case starting with lower
        if temp is not None:
            xml_lo_element_name = strFunctions.lower_first(temp)
        else:
            xml_lo_element_name = ''

        temp = get_value(node, 'listOfClassName')
        # we expect this to be camel case starting with upper
        if temp is not None:
            lo_class_name = strFunctions.upper_first(temp)
        else:
            lo_class_name = ''

        add_decls = get_value(node, 'additionalDecls')
        add_defs = get_value(node, 'additionalDefs')

        attributes = []

        # add attributes
        for attr in node.getElementsByTagName('attribute'):

            attr_name = get_value(attr, 'name')
            required = to_bool(get_value(attr, 'required'))
            attr_type = standardize_types(get_value(attr, 'type'))
            attr_abstract = to_bool(get_value(attr, 'abstract'))
            temp = get_value(attr, 'element')
            # expect this to be uppercase
            if temp is not None:
                attr_element = strFunctions.standard_element_name(temp)
            else:
                attr_element = ''

            attribute_dict = dict({'type': attr_type,
                                   'reqd': required,
                                   'name': attr_name,
                                   'element': attr_element,
                                   'abstract': attr_abstract,
                                   })
            if attr_abstract:
                attribute_dict['concrete'] = concrete_dict[attr_element]

            attributes.append(attribute_dict)

        lo_attributes = []

        # add attributes
        for attr in node.getElementsByTagName('listOfAttribute'):

            attr_name = get_value(attr, 'name')
            required = to_bool(get_value(attr, 'required'))
            attr_type = get_value(attr, 'type')
            attr_abstract = to_bool(get_value(attr, 'abstract'))
            attr_element = get_value(attr, 'element')

            attribute_dict = dict({'type': attr_type,
                                   'reqd': required,
                                   'name': attr_name,
                                   'element': attr_element,
                                   'abstract': attr_abstract})
            if attr_abstract:
                attribute_dict['concrete'] = concrete_dict[attr_element]

            lo_attributes.append(attribute_dict)

        # construct element
        element = dict({'name': element_name,
                        'package': package_name,
                        'typecode': type_code,
                        'hasListOf': has_list_of,
                        'attribs': attributes,
                        'lo_attribs': lo_attributes,
                        'hasChildren': has_children,
                        'hasMath': has_math,
                        'childrenOverwriteElementName':
                            children_overwrite_element_name,
                        'baseClass': base_class,
                        'abstract': abstract
                        })
        if xml_element_name is not None:
            element['elementName'] = xml_element_name

        if xml_lo_element_name is not None:
            element['lo_elementName'] = xml_lo_element_name

        if lo_class_name is not None:
            element['lo_class_name'] = lo_class_name

        if add_decls is not None:
            if os.path.exists(os.path.dirname(filename) + '/' + add_decls):
                add_decls += os.path.dirname(filename) + '/'
            element['addDecls'] = add_decls

        if add_defs is not None:
            if os.path.exists(os.path.dirname(filename) + '/' + add_defs):
                add_defs += os.path.dirname(filename) + '/'
            element['addDefs'] = add_defs

        if abstract:
            element['concrete'] = concrete_dict[element_name]

        elements.append(dict({'name': element_name,
                              'typecode': type_code,
                              'isListOf': has_list_of,
                              'listOfName': xml_lo_element_name
                              if xml_lo_element_name is not None else '',
                              'listOfClassName': lo_class_name
                              if lo_class_name is not None else ''}))
        sbml_elements.append(element)

    for node in dom.getElementsByTagName('plugin'):

        plug_elements = []
        plug_lo_elements = []
        ext_point = get_value(node, 'extensionPoint')
        add_decls = get_value(node, 'additionalDecls')
        add_defs = get_value(node, 'additionalDefs')

        # read references to elements
        for reference in node.getElementsByTagName('reference'):
            temp = find_element(elements, get_value(reference, 'name'))
            if temp is not None:
                plug_elements.append(temp)

        # look for references to ListOf elements
        for reference in node.getElementsByTagName('reference'):
            temp = find_lo_element(elements, get_value(reference, 'name'))
            if temp is not None:
                plug_lo_elements.append(temp)

        attributes = []

        # read additional attributes
        for attr in node.getElementsByTagName('attribute'):

            attr_name = get_value(attr, 'name')
            required = to_bool(get_value(attr, 'required'))
            attr_type = get_value(attr, 'type')

            attr_abstract = to_bool(get_value(attr, 'abstract'))
            attr_element = get_value(attr, 'element')

            attribute_dict = dict({'type': attr_type,
                                   'reqd': required,
                                   'name': attr_name,
                                   'element': attr_element,
                                   'abstract': attr_abstract
                                   })
            if attr_abstract:
                attribute_dict['concrete'] = concrete_dict[attr_element]

            attributes.append(attribute_dict)

        plugin_dict = dict({'sbase': ext_point,
                            'extension': plug_elements,
                            'attribs': attributes,
                            'lo_extension': plug_lo_elements})

        if add_decls is not None:
            if os.path.exists(os.path.dirname(filename) + '/' + add_decls):
                add_decls += os.path.dirname(filename) + '/'
            plugin_dict['addDecls'] = add_decls

        if add_defs is not None:
            if os.path.exists(os.path.dirname(filename) + '/' + add_defs):
                add_defs += os.path.dirname(filename) + '/'
            plugin_dict['addDefs'] = add_defs

        plugins.append(plugin_dict)

    for node in dom.getElementsByTagName('enum'):
        values = []
        enum_name = get_value(node, 'name')

        for val in node.getElementsByTagName('enumValue'):
            values.append(dict({'name': get_value(val, 'name'),
                                'value': get_value(val, 'value')}))

        enums.append(dict({'name': enum_name, 'values': values}))

    package = dict({'name': package_name,
                    'elements': elements,
                    'plugins': plugins,
                    'number': number,
                    'sbmlElements': sbml_elements,
                    'enums': enums,
                    'offset': offset,
                    'fullname': fullname,
                    'sbml_level': sbml_level,
                    'sbml_version': sbml_version,
                    'pkg_version': pkg_version,
                    'required': required
                    })

    # link elements
    for elem in package['elements']:
        elem['root'] = package
        if 'attribs' in elem:
            for attr in elem['attribs']:
                attr['parent'] = elem
                attr['root'] = package

    for elem in package['sbmlElements']:
        elem['root'] = package
        if 'attribs' in elem:
            for attr in elem['attribs']:
                attr['parent'] = elem
                attr['root'] = package
        if 'concrete' in elem:
            for attr in elem['concrete']:
                attr['parent'] = elem
                attr['root'] = package

    return package
