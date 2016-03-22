#!/usr/bin/env python
#
# @file    ExtensionFunctions.py
# @brief   class to create functions specific to the extension class
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2015 by the California Institute of Technology
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

    def __init__(self, language, package, elements, offset, num_versions=1):
        self.language = language
        self.package = package
        self.elements = elements
        self.offset = offset
        self.num_versions = num_versions

        # derived members
        self.up_package = strFunctions.upper_first(self.package)
        self.cap_language = language.upper()
        self.struct_name = '{0}Extension'.format(self.up_package)

    ########################################################################

    # Functions to get name of package

    # function to write getName
    def write_get_name(self):
        # create comment parts
        title_line = 'Returns the name of this SBML Level&nbsp;3 ' \
                     'package (\"{0}\").'.format(self.package)
        params = []
        return_lines = ['@return a string representing the name of '
                        'this package (\"{0}\").'.format(self.package)]
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
        title_line = 'Returns a string representing the {0} XML namespace of ' \
                     'this {0} Level&nbsp;3 package.'.format(self.cap_language)
        params = ['@param {0}Level, the level of {1}.'.format(self.language,
                                                             self.cap_language),
                  '@param {0}Version the version of '
                  '{1}.'.format(self.language, self.cap_language),
                  '@param pkgVersion the version of this package.']
        return_lines = ['@return a string representing the name of '
                        'this package (\"{0}\").'.format(self.package)]
        additional = ['The namespace URI constructed by this method '
                      'corresponds to the combination of the Level and '
                      'Version of SBML, and the Version of the SBML '
                      'Level&nbsp;3 package.  (At the time of this writing, '
                      'the only SBML Level that supports packages is '
                      'Level&nbsp;3, so the value of @p sbmlLevel is '
                      'necessarily always <code>3</code>.)']

        # create the function declaration
        level = '{0}Level'.format(self.language)
        vers = '{0}Version'.format(self.language)
        arguments = ['unsigned int {0}'.format(level),
                     'unsigned int {0}'.format(vers),
                     'unsigned int pkgVersion']
        function = 'getURI'
        return_type = 'const std::string&'

        # create the function implementation
        if self.num_versions == 1:
            bottom_if = self.create_code_block('if',
                                               ['pkgVersion == 1',
                                                'return getXmlnsL3V1V1()'])
        else:
            bottom_if = self.create_code_block('if_else',
                                               ['pkgVersion == 1',
                                                'return getXmlnsL3V1V1()',
                                                'else',
                                                'return getXmlnsL3V1V2()'])
        middle_if = self.create_code_block('if', ['{0} == 1'.format(vers),
                                                  bottom_if])
        code = [self.create_code_block('if', ['{0} == 3'.format(level),
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
        if other == 'Level':
            title_name = 'SBML Level'
            ret_name = 'SBML Level'
        elif other == 'Version':
            title_name = 'Version within the SBML Level'
            ret_name = 'SBML Version within the SBML Level'
        elif other == 'PackageVersion':
            title_name = 'SBML Level&nbsp;3 package version'
            ret_name = 'version of the SBML Level&nbsp;3 package'
        else:
            title_name = ''
            ret_name = ''
        # create comment parts
        title_line = 'Returns the {0} for the given URI  of this ' \
                     'package.'.format(title_name)
        params = ['@param uri the string of the URI that represents one '
                  'of the versions of the \"{0}\" package.'.format(self.package)]
        return_lines = ['@return the {0} for the given URI of this '
                        'package, or @c 0 if the given URI is '
                        'invalid.'.format(ret_name)]
        additional = []

        # create the function declaration
        arguments = ['const std::string& uri']
        function = 'get{0}'.format(other)
        return_type = 'unsigned int'

        # create the function implementation
        write_else = False
        value = 0
        if other == 'Level':
            value = 3
        elif other == 'Version':
            value = 1
        elif self.num_versions == 1:
            value = 1
        else:
            write_else = True

        if write_else:
            implementation = ['uri == getXmlnsL3V1V1()', 'return 1', 'else if',
                              'uri == getXmlnsL3V1V2()', 'return 2']
            code = [dict({'code_type': 'else_if', 'code': implementation}),
                    self.create_code_block('line', ['return 0'])]

        else:
            implementation = ['uri == getXmlnsL3V1V1()',
                              'return {0}'.format(value)]
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
        title_line = 'Returns a  {0}PkgNamespaces ' \
                     'object.'.format(self.up_package)
        params = ['@param uri the string of the URI that represents one '
                  'of the versions of the \"{0}\" package.'.format(self.package)]
        return_lines = ['@return {0}PkgNamespaces object corresponding to '
                        'the given URI of this '
                        'package, or @c NULL if the given URI is not '
                        'defined in the \"{1}\" '
                        'package.'.format(self.up_package, self.package)]
        additional = []

        # create the function declaration
        arguments = ['const std::string& uri']
        function = 'get{0}ExtensionNamespaces'.format(self.cap_language)
        return_type = '{0}Namespaces*'.format(global_variables.prefix)

        # create the function implementation
        code = [dict({'code_type': 'line',
                      'code': ['{0}PkgNamespaces* pkgns = '
                               'NULL'.format(self.up_package)]})]
        if self.num_versions == 1:
            code .append(self.create_code_block('if',
                                                ['uri == getXmlnsL3V1V1()',
                                                 'pkgns = new {0}PkgNamespaces'
                                                 '(3, 1, 1)'
                                                 ''.format(self.up_package)]))
        else:
            code .append(self.create_code_block('else_if',
                                                ['uri == getXmlnsL3V1V1()',
                                                 'pkgns = new {0}PkgNamespaces'
                                                 '(3, 1, 1)'
                                                 ''.format(self.up_package),
                                                 'else if',
                                                 'uri == getXmlnsL3V1V2()',
                                                 'pkgns = new {0}'
                                                 'PkgNamespaces(3, 1, 2)'
                                                 ''.format(self.up_package)]))

        code.append(self.create_code_block('line', ['return pkgns']))

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
    def write_get_string_typecode(self):
        # create comment parts
        title_line = 'Takes a type code of the &ldquo;{0}&rdquo; package and ' \
                     'returns a string describing the ' \
                     'code.'.format(self.package)
        params = ['@param typeCode a libSBML type code defined by the libSBML '
                  'extension implementing support for the SBML '
                  'Level&nbsp;3 &ldquo;{0}&rdquo; package.'
                  ''.format(self.package)]
        return_lines = ['@return a text string representing the type code '
                        'given by @p typeCode.  If the type code is '
                        'unrecognized for this implementation of the '
                        'libSBML &ldquo;{0}&rdquo; package, the string '
                        'returned '
                        'will be <code>"(Unknown SBML {1} Type)"'
                        '</code>.'.format(self.package, self.up_package)]
        additional = []

        # create the function declaration
        arguments = ['int typeCode']
        function = 'getStringFromTypeCode'
        return_type = 'const char*'

        # create the function implementation
        n = len(self.elements)
        implementation = ['int min = {0}'.format(self.elements[0]['typecode']),
                          'int max = {0}'
                          ''.format(self.elements[n-1]['typecode'])]
        code = [dict({'code_type': 'line', 'code': implementation}),
                self.create_code_block('if', ['typeCode < min || '
                                              'typeCode > max',
                                              'return \"(Unknown '
                                              '{0} {1} Type)\"'
                                              ''.format(self.cap_language,
                                                        self.up_package)]),
                self.create_code_block('line',
                                       ['return {0}_{1}_TYPECODE_STRINGS'
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
                        '{0}{1}ErrorTable.'.format(self.up_package,
                                                   self.cap_language)]
        additional = []

        # create the function declaration
        arguments = ['unsigned int index']
        function = 'getErrorTable'
        return_type = 'packageErrorTableEntry'

        # create the function implementation
        implementation = ['return {0}ErrorTable[index]'.format(self.package)]
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
                        '{0}{1}ErrorTable corresponding to the errorId '
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
        if_code = self.create_code_block('if', ['errorId == {0}ErrorTable[i]'
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
                     'the \"{0}\" package.'.format(self.package)
        params = []
        return_lines = ['@return unsigned int representing the offset '
                        'for errors in the '
                        '{0}{1}ErrorTable.'.format(self.up_package,
                                                   self.cap_language)]
        additional = []

        # create the function declaration
        arguments = ['']
        function = 'getErrorIdOffset'
        return_type = 'unsigned int'

        # create the function implementation
        implementation = ['return {0}'.format(self.offset)]
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

    # multiple versions
    def write_has_multiple_versions(self):
        # create comment parts
        title_line = 'Returns true if the package has multiple versions.'
        params = []
        return_lines = ['@return true if multiple versions, false otherwise.']
        additional = []

        # create the function declaration
        arguments = ['']
        function = 'hasMultipleVersions'
        return_type = 'bool'

        return_value = 'true'
        # should not get here but double check
        if self.num_versions == 1:
            return_value = 'false'

        # create the function implementation
        implementation = ['return {0}'.format(return_value)]
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
