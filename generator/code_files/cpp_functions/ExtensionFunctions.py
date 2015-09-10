#!/usr/bin/env python
#
# @file    ExtensionFunctions.py
# @brief   class to create functions specific to the extension class
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

from util import strFunctions, global_variables


class ExtensionFunctions():
    """Class for extension functions"""

    def __init__(self, language, package, elements, offset):
        self.language = language
        self.package = package
        self.elements = elements
        self.offset = offset

        # derived members
        self.up_package = strFunctions.upper_first(self.package)
        self.cap_language = language.upper()
        self.struct_name = '{}Extension'.format(self.up_package)

    ########################################################################

    # Functions to get name of package

    # function to write getName
    def write_get_name(self):
        # create comment parts
        title_line = 'Returns the name of this ' \
                     'package (\"{}\").'.format(self.package)
        params = []
        return_lines = ['@return a string representing the name of '
                        'this package (\"{}\").'.format(self.package)]
        additional = []

        # create the function declaration
        arguments = []
        function = 'getName'
        return_type = 'const std::string&'

        # create the function implementation
        implementation = ['return getPackageName()']
        code = [dict({'code_type': 'line', 'code': implementation})]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions to get uri of package

    # function to write getName
    def write_get_uri(self):
        # create comment parts
        title_line = 'Returns the namespace URI corresponding to the ' \
                     'given {} Level, Version and ' \
                     'PackageVersion'.format(self.cap_language)
        params = ['@param {}Level, the level of {}'.format(self.language,
                                                           self.cap_language),
                  '@param {}Version the version of '
                  '{}'.format(self.language, self.cap_language),
                  '@param pkgVersion the version of this package']
        return_lines = ['@return a string representing the name of '
                        'this package (\"{}\").'.format(self.package)]
        additional = []

        # create the function declaration
        level = '{}Level'.format(self.language)
        vers = '{}Version'.format(self.language)
        arguments = ['unsigned int {}'.format(level),
                     'unsigned int {}'.format(vers),
                     'unsigned int pkgVersion']
        function = 'getURI'
        return_type = 'const std::string&'

        # create the function implementation
        bottom_if = self.create_code_block('if', ['pkgVersion == 1',
                                                  'return getXmlnsL3V1V1()'])
        middle_if = self.create_code_block('if', ['{} == 1'.format(vers),
                                                  bottom_if])
        code = [self.create_code_block('if', ['{} == 3'.format(level),
                                              middle_if])]
        implementation = ['static std::string empty = \"\"', 'return empty']
        code.append(self.create_code_block('line', implementation))
        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions to get other info of package

    # function to write getLevel/Version/PackageVersion
    def write_get_other(self, other):
        # create comment parts
        title_line = 'Returns the {} {} for the given URI  of this ' \
                     'package.'.format(self.cap_language, other)
        params = ['@param uri the string of the URI that represents one '
                  'of the versions of the \"{}\" package'.format(self.package)]
        return_lines = ['@return the {} {} with the given URI of this '
                        'package, or @c 0 if the given URI is '
                        'invalid.'.format(self.cap_language, other)]
        additional = []

        # create the function declaration
        arguments = ['const std::string& uri']
        function = 'get{}'.format(other)
        return_type = 'unsigned int'

        # create the function implementation
        if other == 'Level':
            value = 3
        else:
            value = 1
        implementation = ['uri == getXmlnsL3V1V1()', 'return {}'.format(value)]
        code = [dict({'code_type': 'if', 'code': implementation}),
                self.create_code_block('line', ['return 0'])]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write getExtension namespaces
    def write_get_namespaces(self):
        # create comment parts
        title_line = 'Returns a  {}PkgNamespaces ' \
                     'object.'.format(self.up_package)
        params = ['@param uri the string of the URI that represents one '
                  'of the versions of the \"{}\" package'.format(self.package)]
        return_lines = ['@return {}PkgNamespaces object corresponding to '
                        'the given URI of this '
                        'package, or @c NULL if the given URI is not '
                        'defined in the \"{}\" '
                        'package.'.format(self.up_package, self.package)]
        additional = []

        # create the function declaration
        arguments = ['const std::string& uri']
        function = 'get{}ExtensionNamespaces'.format(self.cap_language)
        return_type = '{}Namespaces*'.format(global_variables.prefix)

        # create the function implementation
        code = [dict({'code_type': 'line',
                      'code': ['{}PkgNamespaces* pkgns = '
                               'NULL'.format(self.up_package)]}),
                self.create_code_block('if', ['uri == getXmlnsL3V1V1()',
                                              'pkgns = new {}PkgNamespaces'
                                              '(3, 1, 1)'
                                              ''.format(self.up_package)]),
                self.create_code_block('line', ['return pkgns'])]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write getExtension namespaces
    @property
    def write_get_string_typecode(self):
        # create comment parts
        title_line = 'Returns the given {}{}TypeCode_t(int) ' \
                     'as a string.'.format(self.cap_language, self.up_package)
        params = ['@param typeCode a TypeCode from the \"{}\" '
                  'package.'.format(self.package)]
        return_lines = ['@return the typecode as a string.']
        additional = []

        # create the function declaration
        arguments = ['int typeCode']
        function = 'getStringFromTypeCode'
        return_type = 'const char*'

        # create the function implementation
        n = len(self.elements)
        implementation = ['int min = {}'.format(self.elements[0]['typecode']),
                          'int max = {}'.format(self.elements[n-1]['typecode'])]
        code = [dict({'code_type': 'line', 'code': implementation}),
                self.create_code_block('if', ['typeCode < min || '
                                              'typeCode > max',
                                              'return \"(Unknown '
                                              '{} {} Type)\"'
                                              ''.format(self.cap_language,
                                                        self.up_package)]),
                self.create_code_block('line',
                                       ['return {}_{}_TYPECODE_STRINGS'
                                        '[typeCode - min'
                                        ']'.format(self.cap_language,
                                                   self.package.upper())])]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions to get error info

    # function to getError table
    def write_get_error_table(self):
        # create comment parts
        title_line = 'Returns the entry in the error table at this index.'
        params = ['@param index an unsigned integer representing the '
                  'index of the error.']
        return_lines = ['@return packageErrorTableEntry object in the '
                        '{}{}ErrorTable.'.format(self.up_package,
                                                 self.cap_language)]
        additional = []

        # create the function declaration
        arguments = ['unsigned int index']
        function = 'getErrorTable'
        return_type = 'packageErrorTableEntry'

        # create the function implementation
        implementation = ['return {}ErrorTable[index]'.format(self.package)]
        code = [dict({'code_type': 'line', 'code': implementation})]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to getError table
    def write_get_error_table_index(self):
        # create comment parts
        title_line = 'Return the index in the error table with the ' \
                     'given errorId.'
        params = ['@param errorId an unsigned integer representing the '
                  'errorId of the error.']
        return_lines = ['@return unsigned int representing the index in the '
                        '{}{}ErrorTable corresponding to the errorId '
                        'given.'.format(self.up_package, self.cap_language)]
        additional = []

        # create the function declaration
        arguments = ['unsigned int errorId']
        function = 'getErrorTableIndex'
        return_type = 'unsigned int'

        # create the function implementation
        implementation = ['unsigned int tableSize = sizeof({0}ErrorTable)/'
                          'sizeof({0}ErrorTable[0])'.format(self.package),
                          'unsigned int index = 0']
        code = [dict({'code_type': 'line', 'code': implementation})]
        if_code = self.create_code_block('if', ['errorId == {}ErrorTable[i]'
                                                '.code'.format(self.package),
                                                'index = i', 'break'])
        code.append(self.create_code_block('for', ['unsigned int i = 0; '
                                                   'i < tableSize; i++',
                                                   if_code]))
        code.append(self.create_code_block('line', ['return index']))

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to getError table
    def write_get_error_offset(self):
        # create comment parts
        title_line = 'Returns the offset for the errorId range for ' \
                     'the \"{}\" package.'.format(self.package)
        params = []
        return_lines = ['@return unsigned int representing the offset '
                        'for errors in the '
                        '{}{}ErrorTable.'.format(self.up_package,
                                                 self.cap_language)]
        additional = []

        # create the function declaration
        arguments = ['']
        function = 'getErrorIdOffset'
        return_type = 'unsigned int'

        # create the function implementation
        implementation = ['return {}'.format(self.offset)]
        code = [dict({'code_type': 'line', 'code': implementation})]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # HELPER FUNCTIONS

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
