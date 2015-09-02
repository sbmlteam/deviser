#!/usr/bin/env python
#
# @file    ValidationFiles.py
# @brief   class for generating cpp files
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

import CppHeaderFile
from base_files import BaseCppFile, BaseTexFile
from util import strFunctions, global_variables
from validation import ValidationRulesForPlugin, ValidationRulesForClass


class ValidationFiles():
    """Class for all Cpp files"""

    def __init__(self, lib_object, language='sbml', verbose=False):
        # members from object
        self.lib_object = lib_object
        self.language = language
        self.cap_language = language.upper()

        self.package = lib_object['name']
        self.up_package = strFunctions.upper_first(self.package)

        self.offset = lib_object['offset']
        self.sbml_classes = lib_object['sbmlElements']
        self.enums = lib_object['enums']
        self.plugins = lib_object['plugins']
        self.fullname = lib_object['fullname']
        self.level = lib_object['sbml_level']
        self.version = lib_object['sbml_version']
        self.pkg_version = lib_object['pkg_version']
        self.pkg_ref = 'SBML Level~{} Package specification for {}, ' \
                       'Version~{}'.format(self.level,
                                           self.fullname, self.pkg_version)

        self.error_file = None
        self.class_rules = []
        self.create_rule_structure()

        self.verbose = verbose

    def write_files(self):
        self.write_error_header()
#        self.write_code(self.lib_object)

    def write_error_header(self):
        class_desc = self.create_description()
        self.error_file = CppHeaderFile.CppHeaderFile(class_desc, False)
        if self.verbose:
            print('Writing file {}'.format(self.error_file.filename))
        self.write_error_file()
        self.error_file.close_file()

    # def write_code(self, class_desc):
    #     fileout = CppCodeFile.CppCodeFile(class_desc)
    #     if self.verbose:
    #         print('Writing file {}'.format(fileout.filename))
    #     fileout.write_file()
    #     fileout.close_file()

    def create_description(self):
        descrip = ({})
        descrip['name'] = '{}{}Error'.format(self.up_package, self.cap_language)
        descrip['attribs'] = []
        return descrip

    def create_rule_structure(self):
        tex_file = BaseTexFile.BaseTexFile('', '', self.lib_object)
        tex_file.sort_class_names(self.sbml_classes)
        tex_file.sort_attribute_names(self.sbml_classes)
        tex_file.sort_enum_names(self.enums)
        number = self.offset + 20200
        for i in range(0, len(self.plugins)):
            rules = ValidationRulesForPlugin.ValidationRulesForPlugin(
                self.plugins[i], self.fullname, number,
                self.package, self.pkg_ref)
            rules.determine_rules()
            self.class_rules += rules.rules
            number += 100
        for i in range(0, len(self.sbml_classes)):
            # hack for render
            if self.sbml_classes[i]['name'] == 'RelAbsVector':
                continue
            rules = ValidationRulesForClass\
                .ValidationRulesForClass(self.sbml_classes[i],
                                         self.fullname, number, self.package,
                                         self.pkg_ref)
            rules.determine_rules()
            self.class_rules += rules.rules
            number += 100
        self.populate_error_list()

    def populate_error_list(self):
        for rule in self.class_rules:
            global_variables.error_list.append(rule['typecode'])

    #########################################################################

    # Functions to write the error enumeration file

    def write_error_file(self):
        BaseCppFile.BaseCppFile.write_file(self.error_file)
        self.error_file.write_defn_begin()
        self.error_file.write_cppns_begin()
        self.error_file.write_cdecl_begin()
        self.error_file.write_line('typedef enum')
        self.error_file.write_line('{')
        self.write_general_errors()
        for rule in self.class_rules:
            self.write_rule(rule['typecode'], rule['number'])
        self.error_file.file_out.write('} ')
        self.error_file.file_out.write('{}{}'
                                       'ErrorCode_t'
                                       ';\n'.format(self.up_package,
                                                    self.cap_language))
        self.error_file.write_cdecl_end()
        self.error_file.write_cppns_end()
        self.error_file.write_defn_end()

    def write_general_errors(self):
        error = '{}Unknown'.format(self.up_package)
        number = self.offset + 10100
        self.error_file.file_out.write('  {:{width}}'.format(error, width=60))
        self.error_file.file_out.write('= {}\n'.format(number))
        error = '{}NSUndeclared'.format(self.up_package)
        number = self.offset + 10101
        self.write_rule(error, number)
        error = '{}ElementNotInNs'.format(self.up_package)
        number = self.offset + 10102
        self.write_rule(error, number)
        error = '{}DuplicateComponentId'.format(self.up_package)
        number = self.offset + 10301
        self.write_rule(error, number)
        error = '{}AttributeRequiredMissing'.format(self.up_package)
        number = self.offset + 20101
        self.write_rule(error, number)
        error = '{}AttributeRequiredMustBeBoolean'.format(self.up_package)
        number = self.offset + 20102
        self.write_rule(error, number)

    def write_rule(self, tc, number):
        self.error_file.file_out.write(', {:{width}}'.format(tc, width=60))
        self.error_file.file_out.write('= {}\n'.format(number))
