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

from util import strFunctions, query


class ExtensionInitFunctions():
    """Class for extension functions"""

    def __init__(self, language, package, base, enums, plugins):
        self.language = language
        self.package = package
        self.std_base = base

        self.enums = enums
        self.plugins = plugins

        # derived members
        self.up_package = strFunctions.upper_first(self.package)
        self.cap_language = language.upper()
        self.struct_name = '{}Extension'.format(self.up_package)

    ########################################################################

    # Function to initialise

    # function to write init
    def write_init_function(self, static=True):
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
        return_type = 'static void' if static else 'void'

        # create the function implementation
        code = [self.create_code_block('if', ['SBMLExtensionRegistry::'
                                              'getInstance().isRegistered'
                                              '(getPackageName())', 'return']),
                self.create_code_block('line', ['{}Extension {}Extension'
                                                ''.format(self.up_package,
                                                          self.package)]),
                self.create_code_block('blank', []),
                self.create_code_block('line', ['std::vector<std::string> '
                                                'packageURIs',
                                                'packageURIs.push_back'
                                                '(getXmlnsL3V1V1())'])]
        implementation = ['SBaseExtensionPoint sbmldocExtPoint(\"core\", '
                          'SBML_DOCUMENT)']
        for i in range(0, len(self.plugins)):
            name = self.plugins[i]['sbase']
            tc = query.get_typecode_format(name, self.language)
            implementation.append('SBaseExtensionPoint {}ExtPoint(\"core\", '
                                  '{})'.format(name.lower(), tc))
        code.append(self.create_code_block('line', implementation))
        implementation = ['SBasePluginCreator<{0}SBMLDocumentPlugin, '
                          '{0}Extension> sbmldocPluginCreator(sbmldocExtPoint, '
                          'packageURIs)'.format(self.up_package)]
        for i in range(0, len(self.plugins)):
            name = self.plugins[i]['sbase']
            implementation.append('SBasePluginCreator<{0}{1}Plugin, '
                                  '{0}Extension> {2}PluginCreator({2}ExtPoint, '
                                  'packageURIs)'.format(self.up_package,
                                                        name, name.lower()))
        code.append(self.create_code_block('line', implementation))
        implementation = ['{}Extension.addSBasePluginCreator('
                          '&sbmldocPluginCreator)'.format(self.package)]
        for i in range(0, len(self.plugins)):
            name = self.plugins[i]['sbase']
            implementation.append('{}Extension.addSBasePluginCreator('
                                  '&{}PluginCreator)'.format(self.package,
                                                             name.lower()))
        code.append(self.create_code_block('line', implementation))
        code.append(self.create_code_block('line', ['int result = '
                                                    'SBMLExtensionRegistry::'
                                                    'getInstance().addExtension'
                                                    '(&{}Extension'
                                                    ')'.format(self.package)]))
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

    def write_enum_to_string_function(self, index, values=None, str_name=''):
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
        if values:
            implementation = ['int min = {}'.format(values[0]),
                              'int max = {}'.format(values[-1])]
            code = [dict({'code_type': 'line', 'code': implementation}),
                    self.create_code_block('if', [
                        '{0} < min || {0} > max'.format(abbrev_name),
                        'return \"(Unknown {} value)\"'.format(name)]),
                    self.create_code_block('line', [
                        'return {}[{} - min]'.format(str_name, abbrev_name)])]
        else:
            code = []
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

    def write_enum_from_string_function(self, index, values=None, str_name=''):
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
        if values:
            implementation = ['static int size = sizeof({0})/sizeof'
                              '({0}[0])'.format(str_name),
                              'std::string type(code)']
            code = [dict({'code_type': 'line', 'code': implementation})]
            if_code = self.create_code_block('if', ['type == {}'
                                                    '[i]'.format(str_name),
                                                    'return ({}_t)'
                                                    '(i)'.format(name)])
            code.append(self.create_code_block('for', ['int i = 0; i < size; '
                                                       'i++', if_code]))
            code.append(self.create_code_block
                        ('line', ['return {}'.format(values[-1])]))
        else:
            code = []

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

    def write_is_valid_enum_function(self, index, values=None):
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
        if values:
            implementation = ['int min = {}'.format(values[0]),
                              'int max = {}'.format(values[-1])]
            code = [dict({'code_type': 'line', 'code': implementation}),
                    self.create_code_block
                    ('if_else',
                     ['{0} < min || {0} >= max'.format(abbrev_name),
                      'return 0', 'else', 'return 1'])]
        else:
            code = []

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
        implementation = ['return {0}_isValid({0}_'
                          'fromString(code))'.format(name)]
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
