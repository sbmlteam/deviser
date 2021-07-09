#!/usr/bin/env python
#
# @file    BaseXMLFile.py
# @brief   base class for all XML test files to be generated
# @author  Frank Bergmann
# @author  Sarah Keating
# @author  Matthew S. Gillman
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

"""
Warning The xml.dom.minidom module is not secure against maliciously
constructed data. If you need to parse untrusted or unauthenticated
data see XML vulnerabilities
(https://docs.python.org/3/library/xml.html#xml-vulnerabilities).
"""

from xml.dom.minidom import getDOMImplementation

from . import BaseFile
from ..util import strFunctions, query


class BaseXMLFile(BaseFile.BaseFile):
    """Common base class for all interface files"""

    def __init__(self, name, package, reqd, ext='xml'):
        """
        Constructor

        :param name: first part of file (before . and extension)
             which we will write to.
        :param package:
        :param reqd:
        :param ext: file extension (without dot, e.g. "xml").
        """
        BaseFile.BaseFile.__init__(self, name, ext)

        self.pkg = package
        self.corens = 'http://www.sbml.org/sbml/level3/version1/core'
        self.pkgns = 'http://www.sbml.org/sbml/level3/version1/{0}/version1'.\
            format(self.pkg)
        self.reqd = reqd

        self.rngns = 'http://relaxng.org/ns/structure/1.0'
        self.xmlschema = 'http://www.w3.org/2001/XMLSchema-datatypes'

        self.comment_start = '<!--'
        self.comment_end = '-->'

        self.start_id = [dict({'name': 'id',
                              'number': 1})]

        self.impl = getDOMImplementation()

        self.doc = None
        self.model_element = None

    #########################################################################

    def write_xml(self, tree, error_code=None, plugin_no=-1):
        """
        Main writing function

        :param tree: tree structure, obtained from a call to
            create_object_tree() in query.py
        :param error_code:
        :param plugin_no:
        :return: nothing
        """
        # Create a Document Object Model document object
        # (the root of the DOM):
        self.create_document(error_code)
        num_plugins = len(tree)
        model_index = self.get_model_index(tree, num_plugins)
        if model_index == num_plugins:
            # need to sort this
            raise Exception("We have hit somewhere I don't think we should be")
        else:
            element = self.create_top_object(tree[model_index])
            self.doc.documentElement.appendChild(element)

        for i in range(0, num_plugins):
            if i == model_index:
                continue
            elif plugin_no > -1 and i != plugin_no:
                continue
            element = self.create_listof_object(tree[i])
            if element:
                self.doc.documentElement.childNodes[0].appendChild(element)
        str_xml = self.doc.toprettyxml(indent='    ', encoding='UTF-8')
        lines = str_xml.decode('utf-8').split('\n')
        for line in lines:
            self.write_line_verbatim(line)

    ########################################################################
    # create elements of the document

    def create_rng_document(self):
        """
        ?? RNG = Random Number Generator ??
        """
        self.doc = self.impl.createDocument(self.rngns, 'grammar', None)
        top_element = self.doc.documentElement
        top_element.setAttributeNS(self.rngns, 'xmlns', self.rngns)
        top_element.setAttributeNS(self.rngns, 'ns', self.pkgns)
        top_element.setAttributeNS(self.rngns,
                                   'datatypeLibrary', self.xmlschema)

    def create_document(self, error_code=None):
        """
        Create the XML document tree. Set the namespace values.

        :param error_code:
        """
        self.doc = self.impl.createDocument(self.corens, 'sbml', None)
        top_element = self.doc.documentElement
        # Add some attribute values to the XML element:
        attributes = {
            'xmlns': [self.corens, self.corens],
            'level': ['3', self.corens],
            'version': ['1', self.corens]
        }
        if error_code and (error_code == 'incorrect_ns'):
            attributes.update(
                {'xmlns:{0}'.format(self.pkg): ['http://incorrect',
                                                self.pkgns]})
        else:
            attributes.update(
                {'xmlns:{0}'.format(self.pkg): [self.pkgns, self.pkgns]})
        if error_code:
            if error_code == 'incorrect_value_reqd':
                reqd = 'true'
                if self.reqd == 'true':
                    reqd = 'false'
                attributes.update(
                    {'{0}:required'.format(self.pkg): [reqd, self.pkgns]})
            elif error_code == 'incorrect_type_reqd':
                attributes.update(
                    {'{0}:required'.format(self.pkg): ['-3.4', self.pkgns]})
            elif error_code != 'missing_reqd':
                attributes.update(
                    {'{0}:required'.format(self.pkg): [self.reqd, self.pkgns]})
        else:
            attributes.update(
                {'{0}:required'.format(self.pkg): [self.reqd, self.pkgns]})

        # These need to be in alphabetical order as python up to 3.7 sorts xml
        sorted_att = sorted(attributes)

        for name in sorted_att:
            top_element.setAttributeNS(attributes[name][1],
                                       name, attributes[name][0])

    def create_top_object(self, tree):
        """

        :param tree:
        :return:
        """
        # name = strFunctions.lower_first(tree['base'])  # TODO unused
        if tree['ext'] == 'core':
            element = self.create_object(tree)
        return element

    def create_listof_object(self, tree):
        """

        :param tree:
        :return:
        """
        name = strFunctions.lower_list_of_name_no_prefix(tree['base'])
        if name in ['listOfReactions', 'listOfSimpleSpeciesReferences',
                    'listOfSpeciesReferences', 'listOfInSpeciesTypeBonds',
                    'listOfOutwardBindingSites']:
            return None
        lo_element = self.doc.createElement('{0}'.format(name))
        element = self.create_object(tree)
        lo_element.appendChild(element)
        return lo_element

    def create_object(self, parent):
        """

        :param parent:
        :return:
        """
        if 'base' in parent:
            name = strFunctions.lower_first(parent['base'])
        elif 'name' in parent:
            name = strFunctions.lower_first(parent['name'])
        else:
            name = 'FIXME'

        ext = parent['ext'] if 'ext' in parent else self.pkg

        if name == 'math':
            return self.create_math_element()
        if ext != 'core':
            name = '{0}:{1}'.format(self.pkg, name)

        attribs = []
        if 'attribs' in parent and len(parent['attribs']) > 0:
            attrib = self.get_attributes(parent['attribs'], self.pkg)
            if attrib and len(attrib) > 0:
                attribs = attrib
        if ext == 'core':
            attrib = self.get_core_attributes(name)
            if attrib and len(attrib) > 0:
                if len(attribs) > 0:
                    for att in attrib:
                        attribs.append(att)
                else:
                    attribs = attrib

        return self.create_element(name, attribs, parent)

    def create_element(self, name, attribs, parent):
        """

        :param name:
        :param attribs:
        :param parent:
        :return:
        """
        children = parent['children']
        element = self.doc.createElement('{0}'.format(name))
        # need to sort attributes alphabetically because python up to 3.7
        # does this but later dont and we want to do comparisons
        self.sort_and_write_attributes(attribs, element)
        for i in range(0, len(children)):
            subelement = self.create_object(children[i])
            element.appendChild(subelement)
        return element

    def sort_and_write_attributes(self, attribs, element):
        att_dict = {}
        for att in attribs:
            att_dict[att['name']] = att['value']
        sorted_att = sorted(att_dict)

        for att in sorted_att:
            element.setAttribute('{0}'.format(att), att_dict[att])

    def create_math_element(self):
        """

        :return:
        """
        element = self.doc.createElement('{0}'.format('math'))
        element.setAttribute('xmlns', 'http://www.w3.org/1998/Math/MathML')
        return element

    ######################################################################

    # functions to make nice sets of attributes

    def get_sensible_value(self, attribute):
        """

        :param attribute:
        :return:
        """
        # value = ''  # TODO Unused
        att_type = attribute['type']
        if att_type == 'boolean' or att_type == 'bool':
            value = 'false'
        elif query.is_number(att_type):
            value = '0'
        elif att_type == 'SId':
            value = self.get_id(attribute)
        elif att_type == 'SIdRef':
            value = self.get_id_ref(attribute)
        elif att_type == 'enum':
            value = query.get_first_enum_value(attribute)
        elif att_type == 'SBO':
            value = 'SBO:0000001'
        elif att_type == 'UnitSId':
            value = 'dimensionless'
        elif att_type == 'UnitSIdRef':
            value = 'dimensionless'
        else:
            value = 'someString'
        return value

    def get_attributes(self, attributes, pkg):
        """

        :param attributes:
        :param pkg:
        :return:
        """
        attrib_list = []
        for attrib in attributes:
            att_type = attrib['type']
            if query.is_element(att_type):
                continue
            elif att_type == 'array' or att_type == 'vector':
                continue
            if 'ext' in attrib:
                pkg = attrib['ext']
            if pkg == 'core':
                name = attrib['xml_name']
            else:
                name = '{0}:{1}'.format(pkg, attrib['xml_name'])
            value = self.get_sensible_value(attrib)
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
        return attrib_list

    def add_new_dictionary_to_list(self, attrib_list, name, type,
                                   get_sensible_value=True, other_value=None):
        """
        Create a new attribute dictionary and add it to attrib_list.

        :param attrib_list: list of dictionaries, which we add to
        :param name: attribute name, e.g. 'id', 'constant'. TODO correct?
        :param type: attribute type, e.g. 'SId', 'boolean'
        :param get_sensible_value: get the value from get_sensible_value()
               function call.
        :param other_value: the value if get_sensible_value is `False`.
        """
        if get_sensible_value and other_value is not None:
            raise ValueError("You cannot have both get_sensible_value=True"
                             "and other_value not None")

        attrib = dict()
        attrib['type'] = type
        if get_sensible_value:
            value = self.get_sensible_value(attrib)
        else:
            value = other_value
        attrib_dict = dict({'name': name, 'value': value})
        attrib_list.append(attrib_dict)

    def get_core_attributes(self, object):
        """
        Create a list of attribute dictionaries, based on value of `object`.

        :param object: name of the object, e.g. 'compartment', parameter',
               or 'species'.
        :return: the new list
        """
        attrib_list = []
        if object == 'compartment':

            self.add_new_dictionary_to_list(attrib_list, 'id', 'SId',
                                            get_sensible_value=False,
                                            other_value='compartment')

            self.add_new_dictionary_to_list(attrib_list, 'constant',
                                            'boolean')

        elif object == 'parameter':

            self.add_new_dictionary_to_list(attrib_list, 'id', 'SId')

            self.add_new_dictionary_to_list(attrib_list, 'constant',
                                            'boolean')
        elif object == 'species':

            self.add_new_dictionary_to_list(attrib_list, 'id', 'SId')

            self.add_new_dictionary_to_list(attrib_list, 'constant',
                                            'boolean')

            self.add_new_dictionary_to_list(attrib_list, 'boundaryCondition',
                                            'boolean')

            self.add_new_dictionary_to_list(attrib_list,
                                            'hasOnlySubstanceUnits',
                                            'boolean')

            self.add_new_dictionary_to_list(attrib_list, 'compartment', 'SId',
                                            get_sensible_value=False,
                                            other_value='compartment')

        return attrib_list

##############################################################################

# helper functions

    def get_id(self, attrib, use_name=None):
        """

        :param attrib:
        :param use_name:
        :return:
        """
        if 'parent' in attrib:
            name = strFunctions.lower_first(attrib['parent']['name'])
        elif use_name:
            name = use_name
        else:
            name = 'id'
        [found, index] = self.match_id_name(name)
        if not found:
            number = 1
            self.start_id.append(dict({'name': name, 'number': number}))
        else:
            number = self.start_id[index]['number'] + 1
            self.start_id[index]['number'] = number
        value = '{0}_{1}'.format(name, number)
        return value

    def get_id_ref(self, attrib):
        """

        :param attrib: dictionary structure representing an <attribute> node??
        :return:
        """
        name = attrib['name']
        [found, index] = self.match_id_name(name)
        if found:
            number = self.start_id[index]['number']
        elif 'element' in attrib and len(attrib['element']) > 0:
            name = strFunctions.lower_first(attrib['element'])
            [found, index] = self.match_id_name(name)
            if found:
                number = self.start_id[index]['number']
            else:
                number = 1
        else:
            number = 1
        value = '{0}_{1}'.format(name, number)
        return value

    def match_id_name(self, name):
        """

        :param name:
        :return: tuple with .....
        """
        for i in range(0, len(self.start_id)):
            if self.start_id[i]['name'] == name:
                return[True, i]
        return [False, -1]

    def get_model_index(self, tree, num):
        """

        :param tree:
        :param num:
        :return:
        """
        for i in range(0, num):
            if tree[i]['base'] == 'Model' and tree[i]['ext'] == 'core':
                return i
        return num
