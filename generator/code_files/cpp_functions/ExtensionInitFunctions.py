#!/usr/bin/env python
#
# @file    ExtensionInitFunctions.py
# @brief   class to create init and typedef functions specific to the
# extension class
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

from util import strFunctions


class ExtensionInitFunctions():
    """Class for extension functions"""

    def __init__(self, language, package, base, enums=None):
        self.language = language
        self.package = package
        self.std_base = base

        self.enums = enums

        # derived members
        self.up_package = strFunctions.upper_first(self.package)
        self.cap_language = self.language.upper()
        self.struct_name = '{}Extension'.format(self.up_package)

    ########################################################################

    # Function to initialise

    # function to write init
    def write_init_function(self):
        # create comment parts
        title_line = 'Initializes {} extension by creating an object of this ' \
                     'class with the required {}Plugin derived objects and ' \
                     'registering the object to the {}ExtensionRegistry ' \
                     'class'.format(self.package, self.std_base,
                                    self.cap_language)
        params = []
        return_lines = ['This function is automatically invoked when creating'
                        'the following global object in {}Extension.'
                        'cpp'.format(self.up_package)]
        additional = ['static {}ExtensionRegister<{}Extension> {}'
                      'ExtensionRegistry;'.format(self.cap_language,
                                                  self.up_package,
                                                  self.package)]

        # create the function declaration
        arguments = []
        function = 'init'
        return_type = 'static void'

        # create the function implementation
        implementation = ['mElementName = name']
        code = [dict({'code_type': 'line', 'code': implementation})]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for enums

    def write_enum_to_string_function(self, index):
        enum = self.enums[index]
        name = enum['name']
        abbrev_name = strFunctions.abbrev_name(name)
        # create comment parts
        title_line = ''
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        arguments = ['{}_t {}'.format(name, abbrev_name)]
        function = '{}_toString'.format(name)
        return_type = 'const char*'

        # create the function implementation
        implementation = ['mElementName = name']
        code = [dict({'code_type': 'line', 'code': implementation})]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': name,
                     'implementation': code})

    def write_enum_from_string_function(self, index):
        enum = self.enums[index]
        name = enum['name']
        # create comment parts
        title_line = ''
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        arguments = ['const char* code']
        function = '{}_fromString'.format(name)
        return_type = '{}_t'.format(name)

        # create the function implementation
        implementation = ['mElementName = name']
        code = [dict({'code_type': 'line', 'code': implementation})]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': name,
                     'implementation': code})

    def write_is_valid_enum_function(self, index):
        enum = self.enums[index]
        name = enum['name']
        abbrev_name = strFunctions.abbrev_name(name)
        # create comment parts
        title_line = ''
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        arguments = ['{}_t {}'.format(name, abbrev_name)]
        function = '{}_isValid'.format(name)
        return_type = 'int'

        # create the function implementation
        implementation = ['mElementName = name']
        code = [dict({'code_type': 'line', 'code': implementation})]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': name,
                     'implementation': code})

    def write_is_valid_enum_string_function(self, index):
        enum = self.enums[index]
        name = enum['name']
        # create comment parts
        title_line = ''
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        arguments = ['const char* code']
        function = '{}_isValidString'.format(name)
        return_type = 'int'.format(name)

        # create the function implementation
        implementation = ['mElementName = name']
        code = [dict({'code_type': 'line', 'code': implementation})]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': name,
                     'implementation': code})

    ########################################################################

    # HELPER FUNCTIONS

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
