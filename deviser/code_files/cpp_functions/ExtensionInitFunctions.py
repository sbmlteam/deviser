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

from ...util import strFunctions, query


class ExtensionInitFunctions():
    """Class for extension functions"""

    def __init__(self, language, package, base, enums, plugins, lv_info):
        self.language = language
        self.package = package
        self.std_base = base

        self.enums = enums
        self.plugins = plugins

        self.lv_info = lv_info
        self.num_versions = len(lv_info)

        self.open_br = '{'
        self.close_br = '}'

        # derived members
        self.up_package = strFunctions.upper_first(self.package)
        self.cap_language = language.upper()
        self.struct_name = '{0}Extension'.format(self.up_package)

    ########################################################################

    # Function to initialise

    # function to write init
    def write_init_function(self, static=True):
        # create comment parts
        title_line = 'Initializes {0} extension by creating an object of this ' \
                     'class with the required {1}Plugin derived objects and ' \
                     'registering the object to the {2}ExtensionRegistry ' \
                     'class'.format(self.package, self.std_base,
                                    self.cap_language)
        params = []
        return_lines = ['This function is automatically invoked when creating'
                        'the following global object in {0}Extension.'
                        'cpp'.format(self.up_package)]
        additional = ['static {0}ExtensionRegister<{1}Extension> {2}'
                      'ExtensionRegistry;'.format(self.cap_language,
                                                  self.up_package,
                                                  self.package)]

        # create the function declaration
        arguments = []
        function = 'init'
        return_type = 'static void' if static else 'void'

        # create the function implementation
        code = [self.create_code_block('if', ['{0}ExtensionRegistry::'
                                              'getInstance().isRegistered'
                                              '(getPackageName'
                                              '())'.format(self.cap_language),
                                              'return']),
                self.create_code_block('line', ['{0}Extension {1}Extension'
                                                ''.format(self.up_package,
                                                          self.package)]),
                self.create_code_block('blank', []),
                self.create_code_block('line', ['std::vector<std::string> packageURIs'])]
        for i in range(0, self.num_versions):
            level_val = self.lv_info[i]['core_level']
            version = self.lv_info[i]['core_version']
            pkg_version = self.lv_info[i]['pkg_version']
            code .append(self.create_code_block('line', ['packageURIs.push_back(getXmlnsL{0}V{1}V{2}())'
                                                         ''.format(level_val, version, pkg_version)]))
        implementation = ['{0}ExtensionPoint {1}docExtPoint(\"core\", '
                          '{2}_DOCUMENT)'.format(self.std_base,
                                                 self.language,
                                                 self.cap_language)]
        for i in range(0, len(self.plugins)):
            name = self.plugins[i]['sbase']
            tc = query.get_typecode_format(name, self.language)
            if name == self.std_base:
                implementation.append('{0}ExtensionPoint {1}ExtPoint(\"all\", '
                                      'SBML_GENERIC_SBASE)'.format(self.std_base, name.lower(),
                                                    tc))
            else:
                implementation.append('{0}ExtensionPoint {1}ExtPoint(\"core\", '
                                      '{2})'.format(self.std_base, name.lower(),
                                                    tc))
        code.append(self.create_code_block('line', implementation))
        implementation = ['{0}PluginCreator<{1}{2}DocumentPlugin, '
                          '{1}Extension> {3}docPluginCreator({3}docExtPoint, '
                          'packageURIs)'.format(self.std_base, self.up_package,
                                                self.cap_language,
                                                self.language)]
        for i in range(0, len(self.plugins)):
            name = self.plugins[i]['sbase']
            implementation.append('{0}PluginCreator<{1}{2}Plugin, '
                                  '{1}Extension> {3}PluginCreator({3}ExtPoint, '
                                  'packageURIs)'.format(self.std_base,
                                                        self.up_package,
                                                        name, name.lower()))
        code.append(self.create_code_block('line', implementation))
        implementation = ['{0}Extension.add{1}PluginCreator('
                          '&{2}docPluginCreator)'.format(self.package,
                                                         self.std_base,
                                                         self.language)]
        for i in range(0, len(self.plugins)):
            name = self.plugins[i]['sbase']
            implementation.append('{0}Extension.add{1}PluginCreator('
                                  '&{2}PluginCreator)'.format(self.package,
                                                              self.std_base,
                                                              name.lower()))
        code.append(self.create_code_block('line', implementation))
        code.append(self.create_code_block('line',
                                           ['{0}ExtensionRegistry::'
                                            'getInstance().addExtension(&{1}'
                                            'Extension'
                                            ')'.format(self.cap_language,
                                                       self.package)]))
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

    def get_class_name(self, value):
        # value will be CLASS_ENUMTYPE_VALUE
        parts = value.split('_')
        classname = strFunctions.upper_first(parts[0].lower())
        return classname

    def write_enum_to_string_function(self, index, values=None, str_name=''):
        enum = self.enums[index]
        name = enum['name']
        abbrev_name = strFunctions.abbrev_name(name)
        classname = self.get_class_name(enum['values'][0]['name'])
        # create comment parts
        title_line = 'Returns the string version of the provided #{0}_t enumeration.'.format(name)
        params = ['@param {0} the #{1}_t enumeration value to convert.'.format(abbrev_name, name)]
        return_lines = ['@return A string corresponding to the given type:']
        for enumVal in enum['values']:
            return_lines.append('\"{0}\",'.format(enumVal['value']))
        return_lines.append('or @c NULL if the value is @sbmlconstant{0}{1}, {2}_t{3} or '
                            'another invalid enumeration value.'.format(self.open_br, values[-1], name, self.close_br))
        additional = ['@copydetails doc_returned_unowned_char', ' ', '@if conly', '@memberof {0}_t'.format(classname), '@endif']

        # create the function declaration
        arguments = ['{0}_t {1}'.format(name, abbrev_name)]
        function = '{0}_toString'.format(name)
        return_type = 'const char*'

        # create the function implementation
        if values:
            implementation = ['int min = {0}'.format(values[0]),
                              'int max = {0}'.format(values[-1])]
            code = [dict({'code_type': 'line', 'code': implementation}),
                    self.create_code_block('if', [
                        '{0} < min || {0} > max'.format(abbrev_name),
                        'return \"(Unknown {0} value)\"'.format(name)]),
                    self.create_code_block('line', [
                        'return {0}[{1} - min]'.format(str_name, abbrev_name)])]
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
        classname = self.get_class_name(enum['values'][0]['name'])
        # create comment parts
        title_line = 'Returns the #{2}_t enumeration corresponding to the given string or @sbmlconstant{0}{1}, {2}_t{3} ' \
                     'if there is no such match.'.format(self.open_br, values[-1], name, self.close_br)
        params = ['@param code the string to convert to a #{0}_t.'.format(name)]
        return_lines = ['@return the corresponding #{2}_t or @sbmlconstant{0}{1}, {2}_t{3} '
                        'if no match is found.'.format(self.open_br, values[-1], name, self.close_br)]
        additional = ['@note The matching is case-sensitive: \"{4}\" will return @sbmlconstant{0}{1}, {2}_t{3}, '
                      'but \"{5}\" will return @sbmlconstant{0}{6}, {2}_t{3}.'.format(self.open_br,
                                                                                     enum['values'][0]['name'], name,
                                                                                     self.close_br,
                                                                                     enum['values'][0]['value'],
                                                                                     strFunctions.upper_first(enum['values'][0]['value']),
                                                                                     values[-1]),
                      ' ', '@if conly', '@memberof {0}_t'.format(classname), '@endif']

        # create the function declaration
        arguments = ['const char* code']
        function = '{0}_fromString'.format(name)
        return_type = '{0}_t'.format(name)

        # create the function implementation
        if values:
            implementation = ['static int size = sizeof({0})/sizeof'
                              '({0}[0])'.format(str_name),
                              'std::string type(code)']
            code = [dict({'code_type': 'line', 'code': implementation})]
            if_code = self.create_code_block('if', ['type == {0}'
                                                    '[i]'.format(str_name),
                                                    'return ({0}_t)'
                                                    '(i)'.format(name)])
            code.append(self.create_code_block('for', ['int i = 0; i < size; '
                                                       'i++', if_code]))
            code.append(self.create_code_block
                        ('line', ['return {0}'.format(values[-1])]))
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
        classname = self.get_class_name(enum['values'][0]['name'])
        abbrev_name = strFunctions.abbrev_name(name)
        # create comment parts
        title_line = 'Predicate returning @c 1 (true) or @c 0 (false) depending on whether the given #{0}_t is valid.'.format(name)
        params = ['@param {0} the #{1}_t enumeration to query.'.format(abbrev_name, name)]
        return_lines = ['@return @c 1 (true) if the #{0}_t is'.format(name)]
        num_vals = len(values)
        last = num_vals-1 if num_vals > 0 else 0
        penultimate = last-1 if last > 0 else 0
        next_pen = penultimate-1 if penultimate > 0 else 0
        for i in range(0, num_vals-1):
            if i == penultimate:
                return_lines.append('@sbmlconstant{0}{1}, {2}_t{3};'.format(self.open_br, values[i], name, self.close_br))
            elif i == next_pen:
                return_lines.append('@sbmlconstant{0}{1}, {2}_t{3}, or'.format(self.open_br, values[i], name, self.close_br))
            else:
                return_lines.append('@sbmlconstant{0}{1}, {2}_t{3},'.format(self.open_br, values[i], name, self.close_br))
        return_lines.append('@c 0 (false) otherwise (including @sbmlconstant{0}{1}, {2}_t{3}).'.format(self.open_br, values[-1], name, self.close_br))

        additional = ['@if conly', '@memberof {0}_t'.format(classname), '@endif']

        # create the function declaration
        arguments = ['{0}_t {1}'.format(name, abbrev_name)]
        function = '{0}_isValid'.format(name)
        return_type = 'int'

        # create the function implementation
        if values:
            implementation = ['int min = {0}'.format(values[0]),
                              'int max = {0}'.format(values[-1])]
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

    def write_is_valid_enum_string_function(self, index, values=None):
        enum = self.enums[index]
        name = enum['name']
        classname = self.get_class_name(enum['values'][0]['name'])
        # create comment parts
        title_line = 'Predicate returning @c 1 (true) or @c 0 (false) depending on whether the given string is a valid #{0}_t.'.format(name)
        params = ['@param code the string to query.']
        return_lines = ['@return @c 1 (true) if the string is']
        num_vals = len(enum['values'])
        last = num_vals-1 if num_vals > 0 else 0
        penultimate = last-1 if last > 0 else 0
        for i in range(0, num_vals):
            if i == last:
                return_lines.append('\"{0}\";'.format(enum['values'][i]['value']))
            elif i == penultimate:
                return_lines.append('\"{0}\", or'.format(enum['values'][i]['value']))
            else:
                return_lines.append('\"{0}\",'.format(enum['values'][i]['value']))
        return_lines.append('@c 0 (false) otherwise.')
        additional = ['@note The matching is case-sensitive: \"{0}\" will return @c 1 (true), '
                      'but \"{1}\" will return @c 0 (false).'.format(enum['values'][0]['value'],
                                                                     strFunctions.upper_first(enum['values'][0]['value'])),
                      ' ', '@if conly', '@memberof {0}_t'.format(classname), '@endif']

        # create the function declaration
        arguments = ['const char* code']
        function = '{0}_isValidString'.format(name)
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
