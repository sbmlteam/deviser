#!/usr/bin/env python
#
# @file    RNGSchemaFiles.py
# @brief   class for generating RNG schema files
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


from ..base_files import BaseXMLFile
from ..util import strFunctions, query


class RNGSchemaFiles(BaseXMLFile.BaseXMLFile):
    '''class to write validation rng schema files'''

    def __init__(self, lib_object, verbose=False):
        # members from object
        self.lib_object = lib_object
        self.verbose = verbose
        self.package = strFunctions.lower_first(lib_object['name'])
        self.reqd = 'false'
        if lib_object['required']:
            self.reqd = 'true'
        self.offset = lib_object['offset']
        self.sbml_classes = lib_object['baseElements']
        self.enums = lib_object['enums']
        self.plugins = lib_object['plugins']
        self.fullname = lib_object['fullname']
        self.level = lib_object['base_level']
        self.version = lib_object['base_version']
        self.pkg_version = lib_object['pkg_version']
        self.pkg_ref = 'NA'
        self.reqd_status = lib_object['required']

        self.tree = query.create_object_tree(lib_object, False)
        BaseXMLFile.BaseXMLFile.__init__(self, self.package, self.package,
                                         self.reqd_status, 'rng')

        self.class_rules = []

    ##########################################################################

    def write_file(self):
        self.create_rng_document()
        for enum in self.enums:
            element = self.write_simple_type(enum)
            self.doc.documentElement.appendChild(element)
        for new_class in self.sbml_classes:
            element = self.write_class_definition(new_class)
            self.doc.documentElement.appendChild(element)
            if new_class['hasListOf']:
                element = self.write_lo_class_definition(new_class)
                self.doc.documentElement.appendChild(element)
        for plugin in self.plugins:
            element = self.write_extended_element(plugin)
            self.doc.documentElement.appendChild(element)
        element = self.write_sbml_element()
        self.doc.documentElement.appendChild(element)
        str_xml = self.doc.toprettyxml(indent='    ', encoding='UTF-8')
        lines = str_xml.split('\n')
        for line in lines:
            self.write_line_verbatim(line)
        self.close_file()

    def write_simple_type(self, enum):
        comment = self.doc.createComment('definition of {0}'.format(enum['name']))
        self.doc.documentElement.appendChild(comment)
        element = self.doc.createElement('define')
        element.setAttribute('name', '{0}.simpleType'.format(enum['name']))
        choice = self.doc.createElement('choice')
        for entry in enum['values']:
            value = self.doc.createElement('value')
            value.setAttribute('type', 'string')
            text_value = self.doc.createTextNode('{0}'.format(entry['value']))
            value.appendChild(text_value)
            choice.appendChild(value)
        element.appendChild(choice)
        return element

    def write_class_definition(self, new_class):
        comment = self.doc.createComment('definition of {0}'.format(new_class['name']))
        self.doc.documentElement.appendChild(comment)
        element = self.doc.createElement('define')
        element.setAttribute('name', '{0}.datatype'.format(strFunctions.lower_first(new_class['name'])))
        element.setAttribute('combine', 'interleave')
        interleave = self.doc.createElement('interleave')
        base = self.get_base_class(new_class['baseClass'], False)
        interleave.appendChild(base)
        for attrib in new_class['attribs']:
            attribute = self.get_attribute(attrib)
            interleave.appendChild(attribute)
        element.appendChild(interleave)
        return element

    def write_lo_class_definition(self, new_class):
        lo_name = strFunctions.lower_first(strFunctions.cap_list_of_name(new_class['name']))
        comment = self.doc.createComment('definition of {0}'.format(lo_name))
        self.doc.documentElement.appendChild(comment)
        element = self.doc.createElement('define')
        element.setAttribute('name', '{0}.datatype'.format(lo_name))
        element.setAttribute('combine', 'interleave')
        interleave = self.doc.createElement('interleave')
        base = self.get_base_class(new_class['baseClass'], False)
        interleave.appendChild(base)
        child_elements = self.get_lo_children(strFunctions.lower_first(new_class['name']))
        for attrib in new_class['lo_attribs']:
            attribute = self.get_attribute(attrib)
            interleave.appendChild(attribute)
        interleave.appendChild(child_elements)
        element.appendChild(interleave)
        return element

    def write_extended_element(self, plugin):
        name = strFunctions.lower_first(plugin['sbase'])
        comment = self.doc.createComment('extended of {0}'.format(name))
        self.doc.documentElement.appendChild(comment)
        element = self.doc.createElement('define')
        element.setAttribute('name', '{0}.datatype'.format(name))
        element.setAttribute('combine', 'interleave')
        interleave = self.doc.createElement('interleave')
        for lo_extension in plugin['lo_extension']:
            lo_extension['reqd'] = False
            child = self.get_lo_element(lo_extension)
            interleave.appendChild(child)
        for attrib in plugin['attribs']:
            attribute = self.get_attribute(attrib)
            interleave.appendChild(attribute)
        element.appendChild(interleave)
        return element

    def write_sbml_element(self):
        comment = self.doc.createComment('the SBML element')
        self.doc.documentElement.appendChild(comment)
        element = self.doc.createElement('define')
        element.setAttribute('name', 'sbml.datatype')
        element.setAttribute('combine', 'interleave')
        reqd_value = 'false'
        if self.reqd:
            reqd_value = 'true'
        reqd = self.doc.createTextNode('{0}'.format(reqd_value))
        value = self.doc.createElement('value')
        value.setAttribute('type', 'boolean')
        value.appendChild(reqd)
        attribute = self.doc.createElement('attribute')
        attribute.setAttribute('name', 'required')
        attribute.setAttribute('ns', self.pkgns)
        attribute.appendChild(value)
        element.appendChild(attribute)
        return element


    def get_base_class(self, base, interleave=True):
        if interleave:
            element = self.doc.createElement('interleave')
            ref = self.doc.createElement('ref')
            ref.setAttribute('name', '{0}.datatype'.format(base))
            element.appendChild(ref)
        else:
            element = self.doc.createElement('ref')
            element.setAttribute('name', '{0}.datatype'.format(base))
        return element

    def get_attribute(self, attrib):
        if attrib['type'] == 'lo_element':
            lo_element = self.get_lo_element(attrib)
            return lo_element
        type_node = self.get_type_node(attrib)
        attrib_node = self.doc.createElement('attribute')
        attrib_node.setAttribute('name', '{0}'.format(attrib['name']))
        attrib_node.setAttribute('ns', self.pkgns)
        attrib_node.appendChild(type_node)
        if attrib['reqd']:
            return attrib_node
        else:
            optional = self.doc.createElement('optional')
            optional.appendChild(attrib_node)
            return optional

    def get_lo_element(self, attrib):
        lo_name = strFunctions.lower_first(strFunctions.cap_list_of_name(attrib['name']))
        attrib_node = self.doc.createElement('element')
        attrib_node.setAttribute('name', '{0}'.format(lo_name))
        ref = self.doc.createElement('ref')
        ref.setAttribute('name', '{0}.datatype'.format(lo_name))
        attrib_node.appendChild(ref)
        if attrib['reqd']:
            return attrib_node
        else:
            optional = self.doc.createElement('optional')
            optional.appendChild(attrib_node)
            return optional

    def get_lo_children(self, name):
        ref = self.doc.createElement('ref')
        ref.setAttribute('name', '{0}.datatype'.format(name))
        element = self.doc.createElement('element')
        element.setAttribute('name', name)
        element.appendChild(ref)
        one_or_more = self.doc.createElement('oneOrMore')
        one_or_more.appendChild(element)
        return one_or_more


    def get_type_node(self, attrib):
        if attrib['type'] == 'SId' or attrib['type'] == 'SIdRef':
            type_node = self.doc.createElement('ref')
            type_node.setAttribute('name', '{0}.simpleType'.format(attrib['type']))
        elif attrib['type'] == 'enum':
            type_node = self.doc.createElement('ref')
            type_node.setAttribute('name', '{0}.simpleType'.format(attrib['element']))
        else:
            type_node = self.doc.createElement('data')
            type_node.setAttribute('type', attrib['type'])
        return type_node

