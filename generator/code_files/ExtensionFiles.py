#!/usr/bin/env python
#
# @file    PluginFiles.py
# @brief   class for generating the plugin files
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

import ExtensionCodeFile
import ExtensionHeaderFile
import CppCodeFile
import CppHeaderFile
from util import strFunctions


class ExtensionFiles():
    """Class for all Extension files"""

    def __init__(self, package, verbose=False):
        # # members from object
        self.package = package
        self.verbose = verbose

    def write_files(self):
        self.write_header()
        self.write_code()

    def write_plugin_files(self, num):
        self.write_plugin_header(num)
        # self.write_code()

    def write_header(self):
        fileout = ExtensionHeaderFile.ExtensionHeaderFile(self.package)
        if not self.verbose:
            print('Writing file {}'.format(fileout.name))
        fileout.write_file()
        fileout.close_file()

    def write_plugin_header(self, num):
        class_descrip = self.create_class_description(num)
        fileout = CppHeaderFile.CppHeaderFile(class_descrip)
        if not self.verbose:
            print('Writing file {}'.format(fileout.name))
        fileout.write_file()
        fileout.close_file()

    def write_plugin_code(self, num):
        class_descrip = self.create_class_description(num)
        fileout = CppCodeFile.CppCodeFile(class_descrip)
        if not self.verbose:
            print('Writing file {}'.format(fileout.name))
        fileout.write_file()
        fileout.close_file()

    def write_code(self):
        fileout = ExtensionCodeFile.ExtensionCodeFile(self.package)
        if self.verbose:
            print('Writing file {}'.format(fileout.name))
        fileout.write_file()
        fileout.close_file()

    def create_class_description(self, num):
        class_object = self.package['plugins'][num]
        up_package = strFunctions.upper_first(self.package['name'])
        class_object['name'] = '{}{}Plugin'.format(up_package,
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

        for i in range(0, len(class_object['lo_extension'])):
            class_object['attribs'].append(self.get_attrib_descrip
                                           (class_object['lo_extension'][i]))

        return class_object

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

    def test_func(self, num=-1):
        if num == -1:
            self.write_files()
        else:
#            self.write_plugin_header(num)
            self.write_plugin_code(num)
 #       if self.class_object['hasListOf']:
 #           lo_working_class = self.create_list_of_description()
#            self.write_header(lo_working_class)
 #           self.write_code(lo_working_class)
