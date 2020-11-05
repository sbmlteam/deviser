#!/usr/bin/env python
#
# @file    ParseXML.py
# @brief   function to take the output from Deviser Edit and create
#             the expected dictionaries
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
#
# A note on XML terminology
# =========================
# XML Node example from https://www.w3schools.com/xml/xml_attributes.asp:
#
# <person gender="female">
#   <firstname>Anna</firstname>
#   <lastname>Smith</lastname>
# </person>
#
# <person> is an element.
# Here, gender is an attribute (aka "attribute node").
# <firstname> is an element (aka "element node")
#
# Helpful info on https://www.w3schools.com/xml/dom_nodes.asp: (q.v. for examples)
#
# According to the XML DOM, *everything* in an XML document is a node:
# The entire document is a document node
# Every XML element is an element node
# The text in the XML elements are text nodes
# Every attribute is an attribute node
# Comments are comment nodes
#
# A common error in DOM processing is to expect an element node to contain text.
# However, the text of an element node is stored in a text node.
# In this example: <year>2005</year>, the element node <year> holds a text node with the value "2005".
# "2005" is not the value of the <year> element!

from xml.dom.minidom import *
import os.path
from util import query

from util import strFunctions
from util import global_variables


class ParseXML():
    """Class for all Cpp Header files"""

    def __init__(self, filename):
        '''
        ParseXML constructor. Check XML file exists and parse it.
        Initialise instance variables.

        :param filename: The (path to the) XML file to parse
        '''
        if not os.path.isfile(filename):
            global_variables.code_returned = \
                global_variables.return_codes['failed to read file']
            print('{0} not found'.format(filename))

        if global_variables.code_returned == \
                global_variables.return_codes['success']:
            self.dom = parse(filename)  # A Document Object Model (i.e. a Document) instance.

        self.temp_dir = os.path.dirname(filename)
        self.abs_dir = os.path.abspath(filename)

        self.concrete_dict = dict({})
        self.package_name = ''
        self.elements = []
        self.sbml_elements = []
        self.num_versions = 1
        self.plugins = []

    #####################################################################

    # Functions for converting values

    @staticmethod
    def to_bool(v):
        '''
        Get **boolean** value of a node's value string

        :param v: the string value
        :returns: True if v exists and v.lower() has the value
                  "yes", "true", or "1".
                  Else False.

        i.e.
        In  : [to_bool(x) for x in ['false', 'true', '0', '1', None, 'yes', 'no', 'Yes']]
        Out : [False, True, False, True, False, True, False, True]
        '''
        if v is None:
            return False
        return v.lower() in ("yes", "true", "1")


    @staticmethod
    def to_int(v):
        '''
        Convert a value string to an int

        :param v: the string value to convert to an int, e.g. "2.6"
        :return: returns an int (0 if v is None), e.g. 2

        Just using int(v) doesn't work.

        TODO: Is float(v) ever likely to not be an int?
        If so, do we want to always round it down as is done here?
        '''
        if v is None:
            return 0
        return int(float(v))

    #####################################################################

    # Functions for retrieving values

    @staticmethod
    def get_value(node, name):
        '''
        Extract a value from an attribute node
        e.g. Given the node <person gender="female">,
        the attribute node is "gender" and its value is "female"

        :param node: the node, e.g. <person> in this example
        :param name: the name of the attribute node whose value we want, e.g. "gender"
        :return: returns the value (e.g. "female" in this example)
        '''
        temp = node.getAttributeNode(name)
        if temp is None:
            return None
        return temp.nodeValue

    @staticmethod
    def get_enum_value(node, name, classname, typename, invalid=False):
        '''
        Get the name value of an enumValue node such as
        <enumValue name="SPATIAL_COMPRESSIONKIND_DEFLATED" value="deflated"/>

        :param node: the <enumValue> node
        :param name: the node's name attribute (e.g. the string "name")
        :param classname: class name of parent <enum> node (e.g. "BOUNDARY")
        :param typename: type name of parent <enum> node (e.g. "KIND")
        :param invalid: Set this to True if you want to get the invalid form of the name attribute.
        :return: returns the value of the name attribute (e.g. "SPATIAL_COMPRESSIONKIND_DEFLATED",
                 or like "SPATIAL_BOUNDARYKIND_INVALID" if `invalid` is `True`)
        '''
        temp = node.getAttributeNode(name)  # Get node's "name" attribute node
        if temp is None:
            return None
        else:
            tempname = temp.nodeValue.upper()  # e.g. "SPATIAL_COMPRESSIONKIND_DEFLATED"
        parts = tempname.split('_')  # TODO what if tempname is "" or None?
        if not invalid:
            if len(parts) > 2:
                return tempname
            else:
                # we don't have a classic X_Y_Z name which we want
                if tempname.startswith(classname + '_' + typename):
                    return tempname
                elif tempname.startswith(typename):
                    return classname + '_' + tempname
                else:
                    return classname + '_' + typename + '_' + tempname
        else:
            if len(parts) > 2:
                return '{0}_{1}_INVALID'.format(parts[0], parts[1])
            else:
                return classname + '_' +  tempname + '_INVALID'

    @staticmethod
    def get_bool_value(self, node, name):
        '''
        Get the boolean value True or False from a node like
        <attribute name="sampledVolume" required="false" type="lo_element"
         element="SampledVolume" abstract="false"/>

        :node: the node
        :name: the name of the attribute desired, e.g. "abstract" or "required"
        :return: returns True or False depending on desired attribute's value.
        '''
        temp = node.getAttributeNode(name)
        if temp is None:
            return False
        # temp.nodeValue is a string like "true"
        # We want the boolean value (e.g. True) rather than the string (e.g. "true")
        return self.to_bool(temp.nodeValue)

    @staticmethod
    def get_int_value(self, node, name):
        temp = node.getAttributeNode(name)
        if temp is None:
            return 0
        return self.to_int(temp.nodeValue)

    @staticmethod
    def get_type_value(self, node):
        temp = node.getAttributeNode('type')
        if temp is None:
            return None
        return self.standardize_types(temp.nodeValue)

    @staticmethod
    def get_element_value(self, node):
        element = ''
        temp = self.get_value(node, 'element')
        if temp is not None:
            element = strFunctions.standard_element_name(temp)
        return element

    @staticmethod
    def get_element_name_value(self, node, name):
        xml_element_name = ''
        temp = self.get_value(node, name)
        # we expect this to be camel case starting with lower
        if temp is not None:
            xml_element_name = strFunctions.lower_first(temp)
        return xml_element_name

    @staticmethod
    def get_element_class_name(self, node):
        '''
        Get the name of the class from an <element> node

        :param node: the <element> node
        :return: returns the name, if present, ensuring it starts in upper-case.
                 Else returns `None`.

        e.g. Given a node like:
        <element name="Geometry" typeCode="SBML_SPATIAL_GEOMETRY" ...>
        get the value of the `name` attribute ("Geometry" in this example).
        '''
        class_name = None
        temp = self.get_value(node, 'name')
        # Expect CamelCase with upper first
        if temp is not None:
            class_name = strFunctions.upper_first(temp)
        return class_name

    @staticmethod
    def get_enum_name(self, node):
        '''
        Gets the name attribute of an <enum> node
        such as <enum name="BoundaryKind">

        :param node: the <enum> node
        :return: returns the name (e.g. "BoundaryKind") or
                 an empty string if no name value held.
        '''
        enum_name = ''
        temp = self.get_value(node, 'name')
        # Expect CamelCase with upper first
        if temp is not None:
            last = len(temp)
            # strip _t if it is there; since we add it later  TODO why? and where?
            if temp.endswith('_t'):
                last -= 2
            enum_name = strFunctions.upper_first(temp[0:last])
        return enum_name

    @staticmethod
    def get_mapping(self, node):
        '''
        Used to get information from a <mapping> node
        e.g.
        <mapping name="DimensionDescription" package="numl"/>

        :param node: the <mapping> node to interrogate
        :return: returns [name, package] tuple
        '''
        name = ''
        package = ''  # TODO Maybe better as None?

        # Example values for `name`:
        # "Transition", "QualitativeSpecies"
        temp = self.get_value(node, 'name')
        # expect CamelCase with upper first
        if temp is not None:
            name = strFunctions.upper_first(temp)

        # Example for `package`: "qual"
        temp = self.get_value(node, 'package')
        # Expect lower-case first letter:
        if temp is not None:
            package = strFunctions.lower_first(temp)

        return [name, package]


    @staticmethod
    def get_loclass_name_value(self, node, name):
        xml_loclass_name = ''
        temp = self.get_value(node, name)
        # we expect this to be camelCase starting with lower
        if temp is not None:
            xml_loclass_name = strFunctions.upper_first(temp)  # See issue 16
        return xml_loclass_name

    @staticmethod
    def get_add_code_value(self, node, name):
        '''
        Gets the value of a filename; the file contains code.

        :param node: element node to process
        :param name: the name of the attribute whose value we want.
                     Example name = "additionalDecls"
        :return: the filename (e.g. "spatial_geometry.h.txt")
        '''
        add_code = self.get_value(node, name)
        if add_code is not None:
            # Do we have the full path or not?
            if not os.path.exists(add_code):
                temp = self.temp_dir + '//' + add_code
                if os.path.exists(temp):
                    add_code = os.path.abspath(temp)
                else:
                    return None
        return add_code

    @staticmethod
    def get_lo_min_children(self, node):
        name = 'minNumListOfChildren'
        temp = node.getAttributeNode(name)
        if temp is None:
            return 1
        return self.to_int(temp.nodeValue)

    @staticmethod
    def get_typecode(self, node):
        name = 'typeCode'
        temp = node.getAttributeNode(name)
        if temp is None:
            return None
        temptype = temp.nodeValue
        if not global_variables.is_package:
            if temptype.endswith('DOCUMENT'):
                vars = temptype.split('_')
                typecode = vars[0] + '_DOCUMENT'
            elif temptype.startswith('SBML_'):
                typecode = temptype[5:]
            else:
                typecode = temptype
        else:
            typecode = temptype
        return typecode

    def analyse_enumname(self, enum_name):
        """
        Pulls out classname and typename "parts" of the name of an <enum> node,
        depending on whether an upper-case letter is found in the name or not.

        TODO: why?

        :param enum_name: The name of the <enum> node. e.g. "BoundaryKind"
        :return: returns tuple with classname and typename "parts" of name,
                 e.g. cname="BOUNDARY" and tname="KIND".
                 But if enum_name is all lower-case (after first character),
                 return it in upper case as the value for cname,
                 and set tname to "" (empty string).
        """
        break_found = False
        for i in range(1, len(enum_name)):
            if enum_name[i].isupper():
                break_found = True
                break
        if break_found:
            cname = enum_name[0:i].upper()
            tname = enum_name[i:].upper()
        else:
            cname = enum_name.upper()
            tname = ''
        return [cname, tname]
  #####################################################################

    # Functions for looking up elements

    @staticmethod
    def find_element(elements, name):
        if elements is None or name is None:
            return None
        else:
            return query.get_matching_element('name', name, elements)
        # for element in elements:
        #     if element['name'] == name:
        #         return element
        # return None

    @staticmethod
    def find_lo_element(elements, name):
        if elements is None or name is None:
            return None
        for element in elements:
            if 'isListOf' in element and element['isListOf'] is True:
                name_to_match = strFunctions.list_of_name(element['name'])
                if 'listOfClassName' in element:
                    if element['listOfClassName'] != '':
                        name_to_match = element['listOfClassName']
                    else:
                        element['listOfClassName'] = name_to_match
                if name_to_match.lower() == name.lower():
                    return element
        return None

    #####################################################################

    # Functions for standardizing types/name etc

    def standardize_types(self, attrib_type):
        name = attrib_type.lower()
        if self.matches_unsigned_int(name):
            return 'uint'
        else:
            mytypes = dict({'boolean': 'bool', 'bool': 'bool',
                'integer': 'int', 'int': 'int', 'sidref': 'SIdRef',
                'unitsidref': 'UnitSIdRef', 'sid': 'SId', 'unitsid': 'UnitSId',
                'idref': 'IDREF', 'id': 'ID',
                'uint': 'uint', 'string': 'string', 'double': 'double',
                'enum': 'enum', 'element': 'element', 'lo_element': 'lo_element',
            })
            if name in mytypes:
                return mytypes[name]
            else:
                return attrib_type


    @staticmethod
    def matches_unsigned_int(name):
        if name == 'unsigned integer':
            return True
        elif name == 'unsigned int':
            return True
        elif name == 'positive integer':
            return True
        elif name == 'positive int':
            return True
        elif name == 'non-negative integer':
            return True
        elif name == 'non-negative int':
            return True
        else:
            return False

    #####################################################################

    # Functions for returning different parts

    @staticmethod
    def get_concrete_list(self, node):
        concrete_list = []
        for concrete in node.getElementsByTagName('concrete'):
            concrete_list.append(
                dict(
                    {'name': self.get_value(concrete, "name"),
                     'element': self.get_value(concrete, "element")}
                ))
        return concrete_list

    @staticmethod
    def get_attribute_description(self, node, version_count):
        """
        Extract information from an <attribute> node.

        :param node: the <attribute> node to query
        :param version_count: number of <pkgVersion> nodes
        :return: dictionary of info about the node

        Example of an <attribute> node:
        <attribute name="sampledVolume" required="false" type="lo_element"
         element="SampledVolume" abstract="false"/>
        """
        version_info = []
        for i in range(0, self.num_versions):
            version_info.append(False)
        version_info[version_count] = True

        attr_name = self.get_value(node, 'name')
        if not attr_name:
            self.report_error(global_variables
                              .return_codes['missing required information'],
                              'An attribute must have a Name')

        required = self.get_bool_value(self, node, 'required')

        attr_type = self.get_type_value(self, node)
        if not attr_type:
            self.report_error(global_variables
                              .return_codes['missing required information'],
                              'An attribute must have a Type')
        attr_abstract = self.get_bool_value(self, node, 'abstract')
        attr_element = self.get_element_value(self, node)

        # If the type is lo_element we actually want the name to be
        # just that of the element.
        if attr_type == 'lo_element':
            if attr_name.startswith('listOf') or attr_name.startswith('ListOf'):
                attr_name = strFunctions.lower_first(attr_element)
            elif attr_name.endswith('s'):
                plural = strFunctions.plural(strFunctions.lower_first(attr_element))
                if plural == attr_name:
                    attr_name = strFunctions.lower_first(attr_element)

        # xml name defaults to name
        attr_xml_name = self.get_value(node, 'xmlName')
        if not attr_xml_name:
            attr_xml_name = attr_name

        attribute_dict = dict({'type': attr_type,
                               'reqd': required,
                               'name': attr_name,
                               'element': attr_element,
                               'abstract': attr_abstract,
                               'xml_name': attr_xml_name,
                               'num_versions': self.num_versions,
                               'version': version_count,
                               'version_info': version_info
                               })
        if attr_abstract and attr_element  in self.concrete_dict:
            attribute_dict['concrete'] = self.concrete_dict[attr_element]

        return attribute_dict

    @staticmethod
    def get_element_description(self, node, version_count):
        '''


        :param node: the <element> node
        :param version_count: the number of package versions
           (Strictly, the number of <pkgVersion> nodes in the
           XML file we parse.)
        :return:
        '''

        # Example <element> node:
        #
        # <element name="DynElement" typeCode="SBML_DYN_DYNELEMENT"
        # hasListOf="true" hasChildren="false" hasMath="false"
        # childrenOverwriteElementName="false" minNumListOfChildren="0"
        # maxNumListOfChildren="0" abstract="false">
        #
        element_name = self.get_element_class_name(self, node)
        if not element_name:
            self.report_error(global_variables
                              .return_codes['missing required information'],
                              'A Class must have a Name')
        element = None
        # check whether we have an element with this
        # name in a different version
        if version_count > 0:
            element = query.get_matching_element('name', element_name,
                                                 self.sbml_elements)
            # for existing in self.sbml_elements:
            #     if existing['name'] == element_name:
            #         element = existing

        if element:
            for attr in node.getElementsByTagName('attribute'):
                element['attribs'].append(
                    self.get_attribute_description(self, attr, version_count))

            for attr in node.getElementsByTagName('listOfAttribute'):
                element['lo_attribs'].append(
                    self.get_attribute_description(self, attr, version_count))
            element['num_versions'] = self.num_versions
            element['version'] = version_count

            return None

        else:
            base_class = self.get_value(node, 'baseClass')
            if not base_class:
                base_class = 'SBase'
            type_code = self.get_typecode(self, node)
            if not type_code:
                self.report_error(global_variables
                                  .return_codes['missing required information'],
                                  'A Class must have a TypeCode')
            has_math = self.get_bool_value(self, node, 'hasMath')
            has_children = self.get_bool_value(self, node, 'hasChildren')
            has_list_of = self.get_bool_value(self, node, 'hasListOf')
            children_overwrite = self.get_bool_value(self, node, 'childrenOverwriteElementName')
            abstract = self.get_bool_value(self, node, 'abstract')
            xml_element_name = \
                self.get_element_name_value(self, node, 'elementName')
            xml_lo_element_name = \
                self.get_element_name_value(self, node, 'listOfName')
            lo_class_name = \
                self.get_loclass_name_value(self, node, 'listOfClassName')
            min_lo_children = self.get_lo_min_children(self, node)
            add_decls = self.get_add_code_value(self, node, 'additionalDecls')
            add_defs = self.get_add_code_value(self, node, 'additionalDefs')

            attributes = []
            for attr in node.getElementsByTagName('attribute'):
                attributes.append(self.get_attribute_description(self, attr,
                                                                 version_count))

            lo_attributes = []
            for attr in node.getElementsByTagName('listOfAttribute'):
                lo_attributes.append(
                    self.get_attribute_description(self, attr, version_count))

            # construct element
            element = dict({'name': element_name,
                            'package': self.package_name,
                            'typecode': type_code,
                            'hasListOf': has_list_of,
                            'attribs': attributes,
                            'lo_attribs': lo_attributes,
                            'hasChildren': has_children,
                            'hasMath': has_math,
                            'baseClass': base_class,
                            'abstract': abstract,
                            'elementName': xml_element_name,
                            'lo_elementName': xml_lo_element_name,
                            'lo_class_name': lo_class_name,
                            'min_lo_children': min_lo_children,
                            'num_versions': self.num_versions,
                            'version': version_count,
                            'childrenOverwriteElementName': children_overwrite
                            })
            if add_decls is not None:
                element['addDecls'] = add_decls

            if add_defs is not None:
                element['addDefs'] = add_defs

            if abstract:
                element['concrete'] = self.concrete_dict[element_name]

            return element

    @staticmethod
    def get_plugin_description(self, node, version_count):
        ext_point = self.get_value(node, 'extensionPoint')
        plugin = None
        # check whether we have an element with this
        # name in a different version
        if version_count > 0:
            plugin = query.get_matching_element('sbase', ext_point,
                                                self.plugins)
        if plugin:
            for reference in node.getElementsByTagName('reference'):
                temp = self.find_element(self.elements,
                                         self.get_value(reference, 'name'))
                if temp is not None and temp not in plugin['extension']:
                    plugin['extension'].append(temp)

            # look for references to ListOf elements
            for reference in node.getElementsByTagName('reference'):
                temp = self.find_lo_element(self.elements,
                                            self.get_value(reference, 'name'))
                if temp is not None and temp not in plugin['lo_extension']:
                    plugin['lo_extension'].append(temp)

            for attr in node.getElementsByTagName('attribute'):
                plugin['attribs'].append(
                    self.get_attribute_description(self, attr, version_count))
            plugin['num_versions'] = self.num_versions
            plugin['version'] = version_count

            return None

        else:
            plug_elements = []
            plug_lo_elements = []
            ext_point = self.get_value(node, 'extensionPoint')
            add_decls = self.get_add_code_value(self, node, 'additionalDecls')
            add_defs = self.get_add_code_value(self, node, 'additionalDefs')

            # read references to elements
            for reference in node.getElementsByTagName('reference'):
                temp = self.find_element(self.elements,
                                         self.get_value(reference, 'name'))
                if temp is not None:
                    plug_elements.append(temp)

            # look for references to ListOf elements
            for reference in node.getElementsByTagName('reference'):
                temp = self.find_lo_element(self.elements,
                                            self.get_value(reference, 'name'))
                if temp is not None:
                    plug_lo_elements.append(temp)

            attributes = []

            # read additional attributes
            for attr in node.getElementsByTagName('attribute'):
                attributes.append(self.get_attribute_description(self, attr,
                                                                 version_count))
            plugin_dict = dict({'sbase': ext_point,
                                'extension': plug_elements,
                                'attribs': attributes,
                                'lo_extension': plug_lo_elements})

            if add_decls is not None:
                if os.path.exists(self.temp_dir + '/' + add_decls):
                    add_decls += self.temp_dir + '/'
                plugin_dict['addDecls'] = add_decls

            if add_defs is not None:
                if os.path.exists(self.temp_dir + '/' + add_defs):
                    add_defs += self.temp_dir + '/'
                plugin_dict['addDefs'] = add_defs

            return plugin_dict

    def get_elements_for_version(self, pkg_node):
        '''
        Iterate over <element> nodes nested within a <pkgVersion> node.
        Extract information from these. Use it to update the ParseXML
        object's `concrete_dict` dictionary and `sbml_elements`
        list (of dictionaries).

        :param pkg_node: The <pkgVersion> node

        '''

        # version_count = self.get_int_value(self, pkg_node, 'version_count')

        # read concrete versions of abstract classes and fill dictionary
        for node in pkg_node.getElementsByTagName('element'):
            # Example <element> node:
            #
            # <element name="DynElement" typeCode="SBML_DYN_DYNELEMENT"
            #    hasListOf="true" hasChildren="false" hasMath="false"
            #    childrenOverwriteElementName="false" minNumListOfChildren="0"
            #    maxNumListOfChildren="0" abstract="false">
            #
            element_name = self.get_value(node, 'name')
            is_abstract = self.get_bool_value(self, node, 'abstract')
            if is_abstract:
                concretes = self.get_concrete_list(self, node)
                if len(concretes) == 0:
                    self.report_error(global_variables
                                      .return_codes['missing required information'],
                                      'The abstract class {0} lists no instantiations'.format(element_name))
                self.concrete_dict[element_name] = concretes

        # read element
        for node in pkg_node.getElementsByTagName('element'):
            element = self.get_element_description(self, node, self.version_count)
            if element:
                self.elements.append(dict({'name': element['name'],
                                           'typecode': element['typecode'],
                                           'isListOf': element['hasListOf'],
                                           'listOfName': element['elementName'],
                                           'listOfClassName':
                                               element['lo_class_name'],
                                           'xml_name': element['elementName'],
                                           'min_lo_children':
                                               element['min_lo_children']}))
                self.sbml_elements.append(element)

    def get_plugins_for_version(self, pkg_node):
#        version_count = self.get_int_value(self, pkg_node, 'version_count')

        for node in pkg_node.getElementsByTagName('plugin'):
            plugin = self.get_plugin_description(self, node, self.version_count)
            if plugin:
                self.plugins.append(plugin)

    @staticmethod
    def find_child_occurences(name, elements):
        found = False
        parent = ''
        num_elements = len(elements)
        index = 0
        while not found and index < num_elements:
            elem = elements[index]
            if 'attribs' in elem:
                for attr in elem['attribs']:
                    if attr['type'] == 'lo_element' \
                            or attr['type'] == 'element':
                        if attr['element'] == name:
                            found = True
                            parent = elem['name']
            index += 1
        return [found, parent]

    def add_parent_elements(self, package):
        for elem in package['baseElements']:
            name = elem['name']
            [occurs_as_child, parent] = \
                self.find_child_occurences(name, package['baseElements'])
            if occurs_as_child:
                elem['parent'] = parent

    def get_version_information(self, node):
        level = self.get_int_value(self, node, 'level')
        version = self.get_int_value(self, node, 'version')
        namespace = self.get_value(node, 'namespace')
        return dict({'level': level,
                     'version': version,
                     'namespace': namespace})

    def get_dependency_information(self, node):
        library = self.get_value(node, 'library_name')
        prefix = self.get_value(node, 'prefix')
        return dict({'library': library,
                     'prefix': prefix})

    def read_language_element(self, node):
        """
        Interrogates a <language> node and updates global_variables

        :param node: the <language> node
        :return: returns nothing

        Example of a <language> node starting element:
        <language name="SBGN" baseClass="SbgnBase" documentClass="SbgnDocument"
         prefix="Sbgn" libraryName="libSBGN"
         annotationElementName="Extension" topLevelElementName="Extension"
         isPackage="false" uses_ASTNode="true" uses_XMLNode="true">

        The <language> node can also contain nodes of at least the following
        types: <library_version>, <language_version> and <dependencies>.
        These are also interrogated in this function.
        """
        language = self.get_value(node, 'name')
        base_class = self.get_value(node, 'baseClass')
        document_class = self.get_value(node, 'documentClass')
        prefix = self.get_value(node, 'prefix')
        library_name = self.get_value(node, 'libraryName')
        pkg_prefix = self.get_value(node, 'pkg_prefix')
        annot_element = self.get_value(node, 'annotationElementName')
        uses_ASTNode = self.get_bool_value(self, node, 'uses_ASTNode')
        uses_XMLNode = self.get_bool_value(self, node, 'uses_XMLNode')
        top_level_element = self.get_value(node, 'topLevelElementName')

        if node.getAttributeNode('isPackage'):
            is_package = self.get_bool_value(self, node, 'isPackage')
        else:
            is_package = True

        # Get the NodeList of <language_version> nodes, if any:
        versions = node.getElementsByTagName('language_versions')
        specification = []
        # A <language_versions> node can contain multiple <version> nodes.
        # If the NodeList of <language_version> nodes has at least one entry,
        # we get the first one and then iterate over the <version> node(s)
        # it has, if any:
        if versions:
            for version in versions[0].getElementsByTagName('version'):
                specification.append(self.get_version_information(version))

        # Example <dependencies> node:
        # <dependencies>
        #   <dependency library_name="libnuml" prefix="NUML"/>
        # </dependencies>
        dependencies = node.getElementsByTagName('dependencies')
        dependency = []
        if dependencies:
            for depend in dependencies[0].getElementsByTagName('dependency'):
                dependency.append(self.get_dependency_information(depend))

        # Example of a <library_version> node:
        # <library_version major="2" minor="0" revision="0"/>
        library = node.getElementsByTagName('library_version')
        if library:
            # TODO can we guarantee these 3 values are always present in
            # a <library_version> node?
            major = self.get_int_value(self, library[0], 'major')
            minor = self.get_int_value(self, library[0], 'minor')
            rev = self.get_int_value(self, library[0], 'revision')
        else:
            major = 0
            minor = 0
            rev = 0

        library_version = dict({'major': major,
                                'minor': minor,
                                'revision': rev})

        # variants = node.getElementsByTagName('libsbml_variants')
        # variant = None
        # if variants:
        #     variant = variants[0]

        # annot_element = ''
        notes_element = ''
        use_id = True
        use_name = False
        # if variant:
        #     base_node = variant.getElementsByTagName('base')
        #     annot_element = self.get_value(base_node[0], 'annotationElementName')
        #     notes_element = self.get_value(base_node[0], 'notesElementName')
        #     use_id = self.get_bool_value(self, base_node[0], 'include_id')
        #     use_name = self.get_bool_value(self, base_node[0], 'include_name')

        # some sanity checking
        if not language or language == '':
            language = 'sbml'
        # set the globals
        global_variables.set_globals(language.lower(), base_class,
                                     document_class, prefix, library_name,
                                     is_package, pkg_prefix, specification,
                                     dependency, library_version, '', annot_element,
                                     notes_element, use_id, use_name, uses_ASTNode, uses_XMLNode,
                                     top_level_element)

    #####################################################################

    @staticmethod
    def report_error(code, message):
        global_variables.code_returned = code
        print('{0}'.format(global_variables.get_return_code(code)))
        print('{0}'.format(message))
    #####################################################################

    # main parsing function

    def parse_deviser_xml(self):
        """
        Parses the filename given in __init__ (e.g. "dyn.xml") and returns a
        big dictionary with the definition contained in it.

        :return: the big `package` dictionary structure

        The dom.documentElement is the main property of the document object,
        i.e. the top-level (enclosing) node. In our case, this is the
        <package> node.

        Example of <package> node:
        <package name="dyn" fullname="Dynamic Processes" number="400"
         offset="9000000" version="1" required="true">

        Some names, e.g. "additionalDecls", can occur in more than one type of node,
        e.g. in <plugin> and <element> nodes (at least) in this case.

        """
        temp = self.get_value(self.dom.documentElement, 'name')  # e.g. "dyn"
        # we expect this to be lower case:
        self.package_name = temp.lower()
        number = self.get_int_value(self, self.dom.documentElement, 'number')
        offset = self.get_int_value(self, self.dom.documentElement, 'offset')
        fullname = self.get_value(self.dom.documentElement, 'fullname')

        # Remove trailing '.'
        if fullname.endswith('.'):
            l = len(fullname)
            fullname = fullname[0:l-1]

        required = self.get_bool_value(self, self.dom.documentElement, 
                                       'required')
        custom_copyright = self.get_add_code_value(self,
                                                   self.dom.documentElement,
                                                   'customCopyright')
        add_declarations = self.get_add_code_value(self,
                                                   self.dom.documentElement,
                                                   'additionalDecls')
        add_implementation = self.get_add_code_value(self,
                                                     self.dom.documentElement,
                                                     'additionalDefs')

        # setup global variables
        languages = self.dom.getElementsByTagName('language')
        # Example of a <language> element node:
        # <language name="SedML" baseClass="SedBase" ... >
        if len(languages) > 0: 
            # read the first element
            node = languages[0]
            self.read_language_element(node)
        else:
            # just in case we generate a new thing
            global_variables.reset()
            global_variables.set_unknown_error(self.package_name)

        global_variables.set_global_fullname(fullname)
        global_variables.set_custom_copyright(custom_copyright)
        global_variables.add_additional_implementation(add_implementation)
        global_variables.add_additional_declaration(add_declarations)

        # get package information - see issue 17
        sbml_level = 3
        sbml_version = 1
        pkg_version = 1
        self.num_versions = len(self.dom.getElementsByTagName('pkgVersion'))
        self.version_count = 0

        # Iterate over pkgVersion nodes.
        lv_info = []  # List of dictionaries, one dict per <pkgVersion> node.
        # Example <pkgVersion> node:
        # <pkgVersion level="3" version="1" pkg_version="1">
        #     <elements...>
        #     <plugins...>
        # </pkgVersion>
        for node in self.dom.getElementsByTagName('pkgVersion'):
            sbml_level = self.get_int_value(self, node, 'level')
            sbml_version = self.get_int_value(self, node, 'version')
            pkg_version = self.get_int_value(self, node, 'pkg_version')
            # <elements> and <plugins> are nodes nested within the
            # <pkgVersion> node
            self.get_elements_for_version(node)
            self.get_plugins_for_version(node)
            lv_info.append(dict({'core_level': sbml_level, 'core_version': sbml_version, 'pkg_version': pkg_version}))
            self.version_count = self.version_count + 1

        # Now iterate over <enum> nodes (if any).
        # Each one may have one or more <enumValue> nodes.
        enums = []
        names_listed = []
        for node in self.dom.getElementsByTagName('enum'):
            values = []  # List of dictionaries, each with key = enumValue node's name, value = its value
            enum_name = self.get_enum_name(self, node)  # e.g. "BoundaryKind"
            # Get classname and typename e.g. ["BOUNDARY", "KIND"]:
            [cname, tname] = self.analyse_enumname(enum_name)

            if enum_name not in names_listed:  # So we don't add two with same name (presumably an error)
                # Example enumValue element node, val:
                # <enumValue name="SPATIAL_BOUNDARYKIND_NEUMANN" value="Neumann"/>
                for val in node.getElementsByTagName('enumValue'):
                    values.append(dict({'name': self.get_enum_value(val, 'name', cname, tname),
                                        'value': self.get_value(val, 'value')}))
                    # e.g. values.append(dict('name': "SPATIAL_BOUNDARYKIND_NEUMANN", 'value': "Neumann")

                # add invalid name here
                # e.g. values.append(dict('name': 'SPATIAL_BOUNDARYKIND_INVALID',
                #                         'value': 'invalid BoundaryKind value')
                invalid_value = 'invalid {0} value'.format(enum_name)
                values.append(dict({'name': self.get_enum_value(val, 'name', cname, tname, invalid=True),
                                    'value': invalid_value}))

                enums.append(dict({'name': enum_name, 'values': values}))
                names_listed.append(enum_name)

        mappings = []
        classes_listed = []
        for node in self.dom.getElementsByTagName('mapping'):
            [cname, package] = self.get_mapping(self, node)

            if cname not in classes_listed:
                mappings.append(dict({'class': cname, 'package': package}))
                classes_listed.append(cname)


        package = dict({'name': self.package_name,
                        'elements': self.elements,
                        'plugins': self.plugins,
                        'number': number,
                        'baseElements': self.sbml_elements,
                        'enums': enums,
                        'offset': offset,
                        'fullname': fullname,
                        'base_level': sbml_level,
                        'base_version': sbml_version,
                        'pkg_version': pkg_version,
                        'required': required,
                        'num_versions': self.num_versions,
                        'lv_info': lv_info
                        })

        list_all_element = ['SBase', 'XMLNode', 'ASTNode', 'UncertMLNode']
        # link elements
        for elem in package['elements']:
            list_all_element.append(elem['name'])
            elem['root'] = package
            if 'attribs' in elem:
                for attr in elem['attribs']:
                    attr['parent'] = elem
                    attr['root'] = package
            if 'lo_attribs' in elem:
                for attr in elem['lo_attribs']:
                    attr['parent'] = elem
                    attr['root'] = package

        for elem in package['baseElements']:
            elem['root'] = package
            if 'attribs' in elem:
                for attr in elem['attribs']:
                    attr['parent'] = elem
                    attr['root'] = package
                    if attr['type'] =='lo_element':
                        if 'element' in attr and attr['element'] != '' and attr['element'] not in list_all_element:
                            self.report_error(global_variables
                                              .return_codes['unknown type used'],
                                              'Unrecognized element: {0}'.format(attr['element']))
                    if 'element' in attr and attr['element'] in classes_listed:
                        for map in mappings:
                            if map['class'] == attr['element']:
                                attr['other_package'] = map['package']

            if 'concrete' in elem:
                for attr in elem['concrete']:
                    attr['parent'] = elem
                    attr['root'] = package
            if 'lo_attribs' in elem:
                for attr in elem['lo_attribs']:
                    attr['parent'] = elem
                    attr['root'] = package


        for elem in package['plugins']:
            elem['root'] = package
            if 'attribs' in elem:
                for attr in elem['attribs']:
                    attr['parent'] = elem
                    attr['root'] = package

        self.add_parent_elements(package)

        return package
