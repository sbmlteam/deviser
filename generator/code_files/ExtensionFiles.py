#!/usr/bin/env python
#
# @file    ExtensionFiles.py
# @brief   class for generating the plugin files
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

from . import ExtensionCodeFile
from . import ExtensionHeaderFile
from . import CppCodeFile
from . import CppHeaderFile
from util import strFunctions, global_variables


class ExtensionFiles():
    """Class for all Extension files"""

    def __init__(self, package, filetype='', verbose=False):
        # # members from object
        self.package = package
        self.verbose = verbose
        self.file_type = filetype
        self.language = global_variables.language

    def write_files(self):
        self.write_header()
        if self.file_type == '' or self.file_type == 'enums':
            self.write_code()

    def write_plugin_files(self, num):
        class_descrip = self.create_class_description(num)
        self.write_plugin_header(class_descrip)
        self.write_plugin_code(class_descrip)
        self.remove_class_description(num)

    def write_header(self):
        types_fileout = ExtensionHeaderFile.ExtensionHeaderFile(self.package,
                                                                self.file_type)
        if self.verbose:
            print('Writing file {0}'.format(types_fileout.filename))
        if self.file_type == '':
            types_fileout.write_file()
        elif self.file_type == 'types':
            types_fileout.write_types_file()
        elif self.file_type == 'fwd':
            types_fileout.write_fwd_file()
        elif self.file_type == 'enums':
            types_fileout.write_ext_enum_header()
        types_fileout.close_file()

    def write_plugin_header(self, class_descrip):
        fileout = CppHeaderFile.CppHeaderFile(class_descrip)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.write_file()
        fileout.close_file()

    def write_plugin_code(self, class_descrip):
        fileout = CppCodeFile.CppCodeFile(class_descrip)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.write_file()
        fileout.close_file()

    def write_code(self):
        fileout = ExtensionCodeFile.ExtensionCodeFile(self.package, self.file_type)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        if self.file_type == '':
            fileout.write_file()
        elif self.file_type == 'enums':
            fileout.write_ext_enum_code()
        fileout.close_file()

    def create_class_description(self, num):
        if num >= len(self.package['plugins']):
            class_object = self.create_document_plugin_desc()
        else:
            class_object = self.package['plugins'][num]
            up_package = strFunctions.upper_first(self.package['name'])
            class_object['name'] = '{0}{1}Plugin'.format(up_package,
                                                         class_object['sbase'])
            class_object['is_plugin'] = True
            class_object['is_list_of'] = False
            class_object['hasListOf'] = False
            class_object['package'] = self.package['name']
            class_object['typecode'] = ''
            class_object['baseClass'] = 'SBasePlugin'
            class_object['sid_refs'] = []
            class_object['unit_sid_refs'] = []
            class_object['hasMath'] = False
            for i in range(0, len(class_object['extension'])):
                class_object['attribs'].append(self.get_attrib_descrip
                                               (class_object['extension'][i]))

            for elem in class_object['lo_extension']:
                class_object['attribs'].append(self.get_attrib_descrip(elem))

        return class_object

    def remove_class_description(self, num):
        if num >= len(self.package['plugins']):
            class_object = self.create_document_plugin_desc()
        else:
            class_object = self.package['plugins'][num]
            class_object['attribs'] = []

        return class_object

    def get_existing_doc_plugin(self):
        existing_plugin = None
        for plugin in self.package['plugins']:
            if plugin['sbase'] == 'SBMLDocument':
                existing_plugin = plugin
                break
        return existing_plugin

    def create_document_plugin_desc(self):
        up_package = strFunctions.upper_first(self.package['name'])
        existing_doc_plugin = self.get_existing_doc_plugin()
        attribs = []
        extension = []
        lo_extension = []
        root = []
        if existing_doc_plugin:
            attribs = existing_doc_plugin['attribs']
            extension = existing_doc_plugin['extension']
            lo_extension = existing_doc_plugin['lo_extension']
            root = existing_doc_plugin['root']
        up_language = self.language.upper()
        doc_plug = dict({'attribs': attribs,
                         'extension': extension,
                         'lo_extension': lo_extension,
                         'root': root,
                         'sbase': '{0}Document'.format(up_language),
                         'name': '{0}{1}DocumentPlugin'.format(up_package,
                                                               up_language),
                         'is_plugin': True,
                         'is_list_of': False,
                         'hasListOf': False,
                         'package': self.package['name'],
                         'typecode': '',
                         'baseClass': '{0}DocumentPlugin'.format(up_language),
                         'sid_refs': [],
                         'unit_sid_refs': [],
                         'hasMath': False,
                         'is_doc_plugin': True,
                         'reqd': self.package['required']})
        for i in range(0, len(doc_plug['extension'])):
            doc_plug['attribs'].append(self.get_attrib_descrip
                                           (doc_plug['extension'][i]))

        for elem in doc_plug['lo_extension']:
            doc_plug['attribs'].append(self.get_attrib_descrip(elem))
        return doc_plug

    @staticmethod
    def get_attrib_descrip(element):
        if element['isListOf']:
            attr_name = strFunctions.list_of_name(element['name'])
            attr_type = 'lo_element'
            attr_element = element['name']
        else:
            attr_name = element['name']
            attr_type = 'element'
            attr_element = element['name']
        attribute_dict = dict({'type': attr_type,
                               'reqd': False,
                               'name': attr_name,
                               'element': attr_element,
                               'abstract': False,
                               'num_versions': 1,
                               'version': 1,
                               'version_info': [True],
                               'parent': element,
                               'root': element['root']
                               })
        return attribute_dict
