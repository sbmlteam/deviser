#!/usr/bin/env python
#
# @file    BaseXMLFile.py
# @brief   base class for all XML test files to be generated
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
#
# ------------------------------------------------------------------------ -->


from . import BaseFile
from xml.dom.minidom import *
from util import strFunctions, query


class BaseXMLFile(BaseFile.BaseFile):
    """Common base class for all interface files"""

    def __init__(self, name, package, reqd, ext='xml'):
        BaseFile.BaseFile.__init__(self, name, ext)

        self.pkg = package
        self.corens = 'http://www.sbml.org/sbml/level3/version1/core'
        self.pkgns = 'http://www.sbml.org/sbml/level3/version1/{0}/version1' \
                     ''.format(self.pkg)
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
    # main writing function

    def write_xml(self, tree, error_code=None, plugin_no=-1):
        self.create_document(error_code)
        num_plugins = len(tree)
        model_index = self.get_model_index(tree, num_plugins)
        if model_index == num_plugins:
            # need to sort this
            print('we have hit somewhere I dont think we should be')
        else:
            element = self.create_top_object(tree[model_index])
            self.doc.documentElement.appendChild(element)

        for i in range(0, num_plugins):
            if i == model_index:
                continue;
            elif plugin_no > -1 and i != plugin_no:
                continue;
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
        self.doc = self.impl.createDocument(self.rngns, 'grammar', None)
        top_element = self.doc.documentElement
        top_element.setAttributeNS(self.rngns, 'xmlns', self.rngns)
        top_element.setAttributeNS(self.rngns, 'ns', self.pkgns)
        top_element.setAttributeNS(self.rngns, 'datatypeLibrary', self.xmlschema)


    def create_document(self, error_code=None):
        self.doc = self.impl.createDocument(self.corens, 'sbml', None)
        top_element = self.doc.documentElement
        top_element.setAttributeNS(self.corens, 'xmlns', self.corens)
        top_element.setAttributeNS(self.corens, 'level', '3')
        top_element.setAttributeNS(self.corens, 'version', '1')
        if error_code:
            if error_code == 'incorrect_ns':
                top_element.setAttributeNS(self.pkgns, 'xmlns:{0}'.format(self.pkg),
                                           'http://incorrect')
            elif error_code != 'missing_ns':
                top_element.setAttributeNS(self.pkgns, 'xmlns:{0}'.format(self.pkg),
                                           self.pkgns)
        else:
            top_element.setAttributeNS(self.pkgns, 'xmlns:{0}'.format(self.pkg),
                                       self.pkgns)
        if error_code:
            if error_code == 'incorrect_value_reqd':
                reqd = 'true'
                if self.reqd == 'true':
                    reqd = 'false'
                top_element.setAttributeNS(self.pkgns,
                                           '{0}:required'.format(self.pkg),
                                           reqd)
            elif error_code == 'incorrect_type_reqd':
                top_element.setAttributeNS(self.pkgns,
                                           '{0}:required'.format(self.pkg),
                                           '-3.4')
            elif error_code != 'missing_reqd':
                top_element.setAttributeNS(self.pkgns,
                                           '{0}:required'.format(self.pkg),
                                           self.reqd)
        else:
            top_element.setAttributeNS(self.pkgns,
                                       '{0}:required'.format(self.pkg),
                                       self.reqd)



    def create_top_object(self, tree):
        name = strFunctions.lower_first(tree['base'])
        if tree['ext'] == 'core':
            element = self.create_object(tree)
        return element


    def create_listof_object(self, tree):
        name = strFunctions.lower_list_of_name_no_prefix(tree['base'])
        if name == 'listOfReactions' or name == 'listOfSimpleSpeciesReferences' or name == 'listOfSpeciesReferences'\
                or name == 'listOfInSpeciesTypeBonds' or name == 'listOfOutwardBindingSites':
            return None
        lo_element = self.doc.createElement('{0}'.format(name))
        element = self.create_object(tree)
        lo_element.appendChild(element)
        return lo_element


    def create_object(self, parent):
        if 'base' in parent:
            name = strFunctions.lower_first(parent['base'])
        elif 'name' in parent:
            name = strFunctions.lower_first(parent['name'])
        else:
            name = 'FIXME'

        if 'ext' in parent:
            ext = parent['ext']
        else:
            ext = self.pkg

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
        children = parent['children']
        element = self.doc.createElement('{0}'.format(name))
        for i in range (0, len(attribs)):
            element.setAttribute('{0}'.format(attribs[i]['name']), attribs[i]['value'])
        for i in range(0, len(children)):
            subelement = self.create_object(children[i])
            element.appendChild(subelement)
        return element

    def create_math_element(self):
        element = self.doc.createElement('{0}'.format('math'))
        element.setAttribute('xmlns', 'http://www.w3.org/1998/Math/MathML')
        return element

    ######################################################################

    # functions to make nice sets of attributes

    def get_sensible_value(self, attribute):
        value = ''
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

    def get_core_attributes(self, object):
        attrib_list = []
        attrib = dict()
        if object == 'compartment':
            name = 'id'
            attrib['type'] = 'SId'
            value = 'compartment'
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
            name = 'constant'
            attrib['type'] = 'boolean'
            value = self.get_sensible_value(attrib)
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
        elif object == 'parameter':
            name = 'id'
            attrib['type'] = 'SId'
            value = self.get_sensible_value(attrib)
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
            name = 'constant'
            attrib['type'] = 'boolean'
            value = self.get_sensible_value(attrib)
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
        elif object == 'species':
            name = 'id'
            attrib['type'] = 'SId'
            value = self.get_sensible_value(attrib)
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
            name = 'constant'
            attrib['type'] = 'boolean'
            value = self.get_sensible_value(attrib)
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
            name = 'boundaryCondition'
            attrib['type'] = 'boolean'
            value = self.get_sensible_value(attrib)
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
            name = 'hasOnlySubstanceUnits'
            attrib['type'] = 'boolean'
            value = self.get_sensible_value(attrib)
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
            name = 'compartment'
            attrib['type'] = 'SId'
            value = 'compartment'
            attrib_dict = dict({'name': name, 'value': value})
            attrib_list.append(attrib_dict)
        return attrib_list

##################################################################################

# helper functions

    def get_id(self, attrib, use_name=None):
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
        for i in range(0,len(self.start_id)):
            if self.start_id[i]['name'] == name:
                return[True, i]
        return [False, -1]


    def get_model_index(self, tree, num):
        for i in range(0, num):
            if tree[i]['base'] == 'Model' and tree[i]['ext'] == 'core':
                return i
        return num
