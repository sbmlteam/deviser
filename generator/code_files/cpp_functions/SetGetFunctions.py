#!/usr/bin/env python
#
# @file    SetGetFunctions.py
# @brief   class to create functions to get/set attributes/elements
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

from util import strFunctions, query, global_variables


class SetGetFunctions():
    """Class for all functions for set/get/isset/unset"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object):
        self.language = language
        self.cap_language = language.upper()
        self.package = class_object['package']
        self.class_name = class_object['name']
        self.is_cpp_api = is_cpp_api
        self.is_list_of = is_list_of
        if is_list_of:
            self.child_name = class_object['lo_child']
        else:
            self.child_name = ''
        if is_cpp_api:
            self.object_name = self.class_name
            self.object_child_name = self.child_name
        else:
            if is_list_of:
                self.object_name = 'ListOf_t'
            else:
                self.object_name = self.class_name + '_t'
            self.object_child_name = self.child_name + '_t'

        self.attributes = class_object['class_attributes']
        self.child_elements = class_object['child_elements']
        if 'num_versions' in class_object and class_object['num_versions'] > 1:
            self.has_multiple_versions = True
        else:
            self.has_multiple_versions = False

        # useful variables
        if not self.is_cpp_api and self.is_list_of:
            self.struct_name = self.object_child_name
        else:
            self.struct_name = self.object_name
        if self.is_cpp_api is False:
            self.true = '@c 1'
            self.false = '@c 0'
        else:
            self.true = '@c true'
            self.false = '@c false'
        self.plural = strFunctions.plural(self.child_name)
        self.indef_name = strFunctions.get_indefinite(self.object_child_name)
        self.abbrev_parent = strFunctions.abbrev_name(self.object_name)
        self.abbrev_child = strFunctions.abbrev_name(self.child_name)
        self.is_header = True
        if 'is_header' in class_object:
            self.is_header = class_object['is_header']
        self.is_plugin = False
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']

        self.open_br = '{'
        self.close_br = '}'

        self.success = global_variables.ret_success
        self.failed = global_variables.ret_failed
        self.invalid_att = global_variables.ret_invalid_att
        self.invalid_obj = global_variables.ret_invalid_obj
    ########################################################################

    # Functions for writing get functions

    # function to write get functions
    def write_get(self, is_attribute, index, const=True):
        if not self.is_cpp_api and not const:
            return
        if is_attribute:
            if index < len(self.attributes):
                attribute = self.attributes[index]
            else:
                return
            # dont write a get for c
            if not self.is_cpp_api and attribute['isArray']:
                return
        else:
            if index < len(self.child_elements):
                attribute = self.child_elements[index]
            else:
                return
        if attribute['isArray'] and self.is_cpp_api:
            return self.write_get_array(index, const)
        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Returns the value of the \"{0}\" {1} of this {2}.' \
            .format(attribute['name'],
                    ('attribute' if is_attribute else 'element'),
                    (self.class_name if self.is_cpp_api else self.object_name))

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure whose {2} is sought.'
                          .format(self.abbrev_parent, self.object_name,
                                  attribute['name']))

        if self.is_cpp_api:
            return_lines.append('@return the value of the \"{0}\" {1} of '
                                'this {2} as a {3}.'
                                .format(attribute['name'],
                                        ('attribute' if is_attribute
                                         else 'element'),
                                        self.class_name,
                                        (attribute['attType']
                                         if (is_attribute
                                             and attribute['isEnum'] is False)
                                         else attribute['attTypeCode'])))
        else:
            return_lines.append('@return the value of the \"{0}\" {1} of '
                                'this {2} as a {3} {4}.'
                                .format(attribute['name'],
                                        ('attribute' if is_attribute
                                         else 'element'),
                                        self.object_name,
                                        ('pointer to a'
                                         if (is_attribute and
                                             attribute['attType'] == 'string')
                                         else ''),
                                        (attribute['attType']
                                         if (is_attribute
                                             and attribute['isEnum'] is False)
                                         else attribute['attTypeCode'])))

        # create the function declaration
        if self.is_cpp_api:
            function = 'get{0}'.format(attribute['capAttName'])
            if attribute['attType'] == 'string' \
                    or attribute['attType'] == 'element':
                if const:
                    return_type = 'const ' + attribute['attTypeCode']
                else:
                    return_type = attribute['attTypeCode']
            else:
                return_type = attribute['attTypeCode']
        else:
            function = '{0}_get{1}'.format(self.class_name,
                                           attribute['capAttName'])
            if attribute['attType'] == 'element':
                return_type = 'const {0}'.format(attribute['CType'])
            else:
                return_type = '{0}'.format(attribute['CType'])

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(self.object_name, self.abbrev_parent))

        # create the function implementation
        if self.is_cpp_api:
            implementation = ['return {}'.format(attribute['memberName'])]
            code = [self.create_code_block('line', implementation)]
        else:
            code = self.get_c_attribute(attribute)

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': const,
                     'virtual': False,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write get functions
    def write_get_string_for_enum(self, is_attribute, index):
        if is_attribute and index < len(self.attributes):
            attribute = self.attributes[index]
        else:
            return
        if not attribute['isEnum']:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Returns the value of the \"{0}\" attribute of this {1}.' \
            .format(attribute['name'],
                    (self.class_name if self.is_cpp_api else self.object_name))

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure whose {2} is sought.'
                          .format(self.abbrev_parent, self.object_name,
                                  attribute['name']))

        if self.is_cpp_api:
            return_lines.append('@return the value of the \"{0}\" attribute '
                                'of this {1} as a string.'
                                .format(attribute['name'], self.class_name))
        else:
            return_lines.append('@return the value of the \"{0}\" attribute '
                                'of this {1} as a const char *.'
                                .format(attribute['name'], self.object_name))

        # create the function declaration
        if self.is_cpp_api:
            function = 'get{0}AsString'.format(attribute['capAttName'])
            return_type = 'const std::string&'
        else:
            function = '{0}_get{1}AsString'.format(self.class_name,
                                                   attribute['capAttName'])
            return_type = 'const char *'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(self.object_name, self.abbrev_parent))
        if self.is_cpp_api:
            implementation = ['static const std::string code_str =  {}_'
                              'toString({})'.format(attribute['element'],
                                                    attribute['memberName']),
                              'return code_str']
        else:
            implementation = ['return {}_toString({}->get{}()'
                              ')'.format(attribute['element'],
                                         self.abbrev_parent,
                                         attribute['capAttName'])]
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
                     'virtual': False,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write get function for an array
    # specialised c++ function to use an array pointer
    # as an argument to be read into
    def write_get_array(self, index, const):
        if index < len(self.attributes):
            attribute = self.attributes[index]
        else:
            return None
        # create comment parts
        title_line = 'Returns the value of the \"{}\" attribute of this {}.' \
            .format(attribute['name'], self.class_name)
        params = ['@param outArray {} array that will be used to return the '
                  'value of the \"{}\" attribute of this '
                  '{}.'.format(attribute['attTypeCode'], attribute['name'],
                               self.class_name)]
        return_lines = []
        additional = ['@note the value of the \"{}\" attribute of this '
                      '{} is returned in the argument '
                      'array.'.format(attribute['name'], self.class_name)]

        # create the function declaration
        function = 'get{0}'.format(attribute['capAttName'])
        return_type = 'void'
        arguments = ['{} outArray'.format(attribute['attTypeCode'])]
        code = [self.create_code_block(
            'if',
            ['outArray == NULL || {} == NULL'.format(attribute['memberName']),
             'return'])]
        line = ['memcpy(outArray, {0}, sizeof({1})*{0}'
                'Length)'.format(attribute['memberName'], attribute['element'])]
        code.append(self.create_code_block('line', line))

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': const,
                     'virtual': False,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write get functions for extension
    def write_static_extension_get(self, index, const=True, static=True):
        if index < len(self.attributes):
            attribute = self.attributes[index]
        else:
            return
        name = attribute['name']
        if name == 'packageName':
            title_name = 'nickname of the {} Level&nbsp;3 package'.format(self.cap_language)
            ret_name = 'package nickname'
        elif name == 'defaultLevel':
            title_name = 'default {} Level'.format(self.cap_language)
            ret_name = '{} Level'.format(self.cap_language)
        elif name == 'defaultVersion':
            title_name = 'default {} Version'.format(self.cap_language)
            ret_name = 'Version within the default {} Level'.format(self.cap_language)
        elif name == 'defaultPackageVersion':
            title_name = 'default version of the {} Level&nbsp;3 package'.format(self.cap_language)
            ret_name = 'default version number of the {} Level&nbsp;3 package definition'.format(self.cap_language)
        elif name == 'xmlnsL3V1V1' or name == 'xmlnsL3V1V2':
            title_name = 'XML namespace URI of the {} Level&nbsp;3 package'.format(self.cap_language)
            ret_name = 'XML namespace'
        else:
            title_name = ''
            ret_name = ''

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Returns the {} implemented by this lib{} extension.' \
            .format(title_name, self.cap_language)

        return_lines.append('@return the {}, as {} {}.'
                            .format(ret_name,
                                    strFunctions.get_indefinite(attribute['attType']),
                                    attribute['attType']))
        if self.cap_language == 'SBML':
            additional.append('@copydetails doc_note_static_methods')
        # create the function declaration
        function = 'get{0}'.format(attribute['capAttName'])
        if attribute['attType'] == 'string' \
                or attribute['attType'] == 'element':
            if const:
                return_type = 'static const ' + attribute['attTypeCode']
            else:
                return_type = 'static ' + attribute['attTypeCode']
        else:
            return_type = 'static ' + attribute['attTypeCode']
        if not static:
            temp = return_type[7:]
            return_type = temp

        arguments = []

        # create the function implementation
        if attribute['attType'] == 'string':
            if attribute['name'] == 'packageName':
                name = 'pkgName'
                value = '{}'.format(self.package)
            else:
                name = 'xmlns'
                if attribute['name'].endswith('1'):
                    value = 'http://www.{0}.org/{0}/level3/version1/{1}/' \
                            'version1'.format(self.language, self.package)
                else:
                    value = 'http://www.{0}.org/{0}/level3/version1/{1}/' \
                            'version2'.format(self.language, self.package)

            implementation = ['static const std::string {} '
                              '= \"{}\"'.format(name, value),
                              'return {}'.format(name)]
        else:
            implementation = ['return {}'.format(attribute['memberName'])]
        code = [self.create_code_block('line', implementation)]

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

    # Functions for writing is set functions

    # function to write is set functions
    def write_is_set(self, is_attribute, index):
        if is_attribute:
            if index < len(self.attributes):
                attribute = self.attributes[index]
            else:
                return
        else:
            if index < len(self.child_elements):
                attribute = self.child_elements[index]
            else:
                return
        if is_attribute:
            ob_type = 'attribute'
        else:
            ob_type = 'element'

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Predicate returning {} or {} depending on whether ' \
                     'this {}\'s \"{}\" {} has been set.' \
            .format(self.true, self.false, self.object_name, attribute['name'],
                    ob_type)
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(self.abbrev_parent, self.object_name))

        return_lines.append('@return {0} if this {1}\'s \"{2}\" {3} has been '
                            'set, otherwise {4} is returned.'
                            .format(self.true, self.object_name,
                                    attribute['name'],
                                    ob_type, self.false))

        # create the function declaration
        if self.is_cpp_api:
            function = 'isSet{0}'.format(attribute['capAttName'])
            return_type = 'bool'
        else:
            function = '{0}_isSet{1}'.format(self.class_name,
                                             attribute['capAttName'])
            return_type = 'int'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(self.object_name, self.abbrev_parent))

        # create the function implementation
        if self.is_cpp_api:
            if query.is_string(attribute):
                implementation = ['return ({}.empty() == false)'.format(
                    attribute['memberName'])]
            elif attribute['attType'] == 'enum' or attribute['isArray']:
                implementation = ['return ({} != '
                                  '{})'.format(attribute['memberName'],
                                               attribute['default'])]
            elif query.has_is_set_member(attribute):
                implementation = ['return '
                                  'mIsSet{}'.format(attribute['capAttName'])]
            elif attribute['type'] == 'element':
                implementation = ['return ({} != '
                                  '{})'.format(attribute['memberName'],
                                               attribute['default'])]
            else:
                implementation = ['']
        else:
            if not self.is_list_of:
                use_name = self.abbrev_parent
            else:
                use_name = 'static_cast<const ' \
                           '{}*>({})'.format(self.class_name,
                                             self.abbrev_parent)
            implementation = ['return ({0} != NULL) ? static_cast<int>({0}->is'
                              'Set{1}()) : 0'.format(use_name,
                                                     attribute['capAttName'])]

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
                     'virtual': False,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing is set/unset functions

    # function to write set functions
    def write_set(self, is_attribute, index):
        if is_attribute:
            if index < len(self.attributes):
                attribute = self.attributes[index]
            else:
                return
        else:
            if index < len(self.child_elements):
                attribute = self.child_elements[index]
            else:
                return
        if attribute['isArray']:
            if self.is_cpp_api:
                return self.write_cpp_set_array(index)
            else:
                return self.write_c_set_array(index)
        if is_attribute:
            ob_type = 'attribute'
        else:
            ob_type = 'element'
        if self.is_cpp_api:
            att_type = attribute['attTypeCode']
        else:
            att_type = attribute['CType']

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Sets the value of the \"{0}\" {1} of this {2}.' \
            .format(attribute['name'], ob_type, self.object_name)

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param {0} {1} value of the \"{0}\" {2} to be set.'
                      .format(attribute['name'], att_type,
                              ob_type))

        return_lines.append("@copydetails doc_returns_success_code")
        return_lines.append('@li @{}constant{}{}, '
                            'OperationReturnValues_'
                            't{}'.format(self.language, self.open_br,
                                         self.success, self.close_br))

        return_lines.append('@li @{}constant '
                            '{}{},'
                            ' OperationReturnValues_'
                            't{}'.format(self.language, self.open_br,
                                         self.invalid_att, self.close_br))

        # create the function declaration
        if self.is_cpp_api:
            function = 'set{0}'.format(attribute['capAttName'])
            return_type = 'int'
        else:
            function = '{0}_set{1}'.format(self.class_name,
                                           attribute['capAttName'])
            return_type = 'int'

        arguments = []
        if self.is_cpp_api:
            arguments.append('{0} {1}'
                             .format(('const ' + attribute['attTypeCode']
                                      if (attribute['attType'] == 'string' or
                                          attribute['attType'] == 'enum' or
                                          attribute['attType'] == 'element')
                                      else attribute['attTypeCode']),
                                     attribute['name']))
        else:
            arguments.append('{0} * {1}'
                             .format(self.object_name, self.abbrev_parent))
            if attribute['attType'] == 'element':
                arguments.append('const {0} {1}'
                                 .format(attribute['CType'],
                                         attribute['name']))
            else:
                arguments.append('{0} {1}'
                                 .format(attribute['CType'],
                                         attribute['name']))

        # create the function implementation
        if self.is_cpp_api:
            code = self.set_cpp_attribute(attribute)
        else:
            if not self.is_list_of:
                use_name = self.abbrev_parent
            else:
                use_name = 'static_cast<' \
                           '{}*>({})'.format(self.class_name,
                                             self.abbrev_parent)
            implementation = ['return ({0} != NULL) ? {0}->set{1}({2}) : '
                              'LIB{3}'
                              '_INVALID_OBJECT'.format(use_name,
                                                       attribute['capAttName'],
                                                       attribute['name'],
                                                       self.cap_language)]
            code = [self.create_code_block('line', implementation)]

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

    # function to write set functions
    def write_set_string_for_enum(self, is_attribute, index):
        if is_attribute and index < len(self.attributes):
            attribute = self.attributes[index]
        else:
            return
        if not attribute['isEnum']:
            return
        if not self.is_cpp_api:
            att_type = 'const char *'
        else:
            att_type = 'std::string&'

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Sets the value of the \"{0}\" attribute of this {1}.' \
            .format(attribute['name'], self.object_name)

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param {0} {1} of the \"{0}\" attribute to be set.'
                      .format(attribute['name'], att_type))

        return_lines.append("@copydetails doc_returns_success_code")
        return_lines.append('@li @{}constant{}{}, '
                            ' OperationReturnValues_'
                            't{}'.format(self.language, self.open_br,
                                         self.success, self.close_br))
        return_lines.append('@li @{}constant '
                            '{}{},'
                            ' OperationReturnValues_'
                            't{}'.format(self.language, self.open_br,
                                         self.invalid_att, self.close_br))

        # create the function declaration
        if self.is_cpp_api:
            function = 'set{0}'.format(attribute['capAttName'])
            return_type = 'int'
        else:
            function = '{0}_set{1}AsString'.format(self.class_name,
                                                   attribute['capAttName'])
            return_type = 'int'

        arguments = []
        if self.is_cpp_api:
            arguments.append('{0} {1}'.format('const std::string&',
                                              attribute['name']))
        else:
            arguments.append('{0} * {1}'
                             .format(self.object_name, self.abbrev_parent))
            arguments.append('const char * {}'.format(attribute['name']))

        if self.is_cpp_api:
            implementation = ['{0}_isValidString({1}.c_str()) == '
                              '0'.format(attribute['element'],
                                         attribute['name']),
                              '{} = {}'.format(attribute['memberName'],
                                               attribute['default']),
                              'return {}'.format(self.invalid_att), 'else',
                              '{} = {}_fromString'
                              '({}.c_str())'.format(attribute['memberName'],
                                                    attribute['element'],
                                                    attribute['name']),
                              'return {}'.format(self.success)]
            code = [dict({'code_type': 'if_else', 'code': implementation})]
        else:
            implementation = ['return ({0} != NULL) ? {0}->set{1}({2}): '
                              '{3}'.format(self.abbrev_parent,
                                           attribute['capAttName'],
                                           attribute['name'],
                                           self.invalid_obj)]
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

    # function to write set function for an array
    # specialised c++ function to use an array pointer
    # as an argument to be read into
    def write_cpp_set_array(self, index):
        if index < len(self.attributes):
            attribute = self.attributes[index]
        else:
            return None
        # create comment parts
        title_line = 'Sets the value of the \"{}\" attribute of this {}.' \
            .format(attribute['name'], self.class_name)
        params = ['@param inArray {} array value of the \"{}\" attribute '
                  'to be set.'.format(attribute['attTypeCode'],
                                      attribute['name']),
                  '@param arrayLength int value for the length of '
                  'the \"{}\" attribute to be '
                  'set.'.format(attribute['name'])]
        return_lines = ["@copydetails doc_returns_success_code",
                        '@li @{}constant{}{}, '
                        'OperationReturnValues_t{}'.format(self.language,
                                                           self.open_br,
                                                           self.success,
                                                           self.close_br),
                        '@li @{}constant '
                        '{}{},'
                        ' OperationReturnValues_t{}'.format(self.language,
                                                            self.open_br,
                                                            self.invalid_att,
                                                            self.close_br)]

        additional = []

        # create the function declaration
        function = 'set{0}'.format(attribute['capAttName'])
        return_type = 'int'
        arguments = ['{} inArray'.format(attribute['attTypeCode']),
                     'int arrayLength']
        member = attribute['memberName']
        length = member + 'Length'
        ar_type = attribute['element']
        is_set_l = 'mIsSet' + strFunctions.upper_first(attribute['name']) \
                   + 'Length'
        code = [self.create_code_block('if',
                                       ['inArray == NULL',
                                        'return {}'.format(self.invalid_att)]),
                self.create_code_block('if',
                                       ['{} != NULL'.format(member),
                                        'delete[] {}'.format(member)])]
        implementation = ['{} = new {}[arrayLength]'.format(member, ar_type),
                          'memcpy({}, inArray, sizeof('
                          '{})*arrayLength)'.format(member, ar_type),
                          '{} = true'.format(is_set_l),
                          '{} = arrayLength'.format(length)]
        code.append(self.create_code_block('line', implementation))
        code.append(self.create_code_block(
            'line', ['return {}'.format(self.success)]))

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

    # function to write set function for an array
    # specialised c function
    def write_c_set_array(self, index):
        if index < len(self.attributes):
            attribute = self.attributes[index]
        else:
            return None
        # create comment parts
        title_line = 'Sets the value of the \"{}\" attribute of this {}.' \
            .format(attribute['name'], self.object_name)

        params = ['@param {} the {} structure.'.format(self.abbrev_parent,
                                                       self.object_name),
                  '@param {0} pointer value of the \"{0}\" '
                  'attribute to be set.'.format(attribute['name']),
                  '@param arrayLength int value for the length of '
                  'the \"{}\" attribute to be '
                  'set.'.format(attribute['name'])]

        return_lines = ["@copydetails doc_returns_success_code",
                        '@li @{}constant{}{}, '
                        'OperationReturnValues_t{}'.format(self.language,
                                                           self.open_br,
                                                           self.success,
                                                           self.close_br),
                        '@li @{}constant '
                        '{}{},'
                        ' OperationReturnValues_t{}'.format(self.language,
                                                            self.open_br,
                                                            self.invalid_att,
                                                            self.close_br)]

        additional = []

        # create the function declaration
        function = '{}_set{}'.format(self.class_name, attribute['capAttName'])
        return_type = 'int'
        arguments = ['{}* {}'.format(self.object_name, self.abbrev_parent),
                     '{} {}'.format(attribute['attTypeCode'],
                                    attribute['name']),
                     'int arrayLength']
        implementation = ['return ({0} != NULL) ? {0}->set{1}({2}, '
                          'arrayLength)'
                          ' : {3}'.format(self.abbrev_parent,
                                          attribute['capAttName'],
                                          attribute['name'],
                                          global_variables.ret_invalid_obj)]
        code = [self.create_code_block('line', implementation)]

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

    # function to write unset functions
    def write_unset(self, is_attribute, index):
        if is_attribute:
            if index < len(self.attributes):
                attribute = self.attributes[index]
            else:
                return
        else:
            if index < len(self.child_elements):
                attribute = self.child_elements[index]
            else:
                return
        if is_attribute:
            ob_type = 'attribute'
        else:
            ob_type = 'element'

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Unsets the value of the \"{0}\" {1} of this {2}.' \
            .format(attribute['name'], ob_type, self.object_name)

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(self.abbrev_parent, self.object_name))

        return_lines.append('@copydetails doc_returns_success_code')
        return_lines.append('@li @{}constant{}{}, '
                            ' OperationReturnValues_'
                            't{}'.format(self.language, self.open_br,
                                         self.success, self.close_br))
        return_lines.append('@li @{}constant{}{},'
                            ' OperationReturnValues_'
                            't{}'.format(self.language, self.open_br,
                                         self.failed, self.close_br))

        # create the function declaration
        if self.is_cpp_api:
            function = 'unset{0}'.format(attribute['capAttName'])
            return_type = 'int'
        else:
            function = '{0}_unset{1}'.format(self.class_name,
                                             attribute['capAttName'])
            return_type = 'int'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('{0} * {1}'
                             .format(self.object_name, self.abbrev_parent))

        # create the function implementation
        if self.is_cpp_api:
            code = self.unset_cpp_attribute(attribute)
        else:
            if not self.is_list_of:
                use_name = self.abbrev_parent
            else:
                use_name = 'static_cast<' \
                           '{}*>({})'.format(self.class_name,
                                             self.abbrev_parent)
            implementation = ['return ({0} != NULL) ? {0}->unset{1}() : LIB{2}'
                              '_INVALID_OBJECT'.format(use_name,
                                                       attribute['capAttName'],
                                                       self.cap_language)]
            code = [self.create_code_block('line', implementation)]
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

    # Functions for writing create for a child element

    # function to write create functions
    def write_create(self, is_attribute, index):
        if is_attribute:
            return
        else:
            if index < len(self.child_elements):
                attribute = self.child_elements[index]
            else:
                return
        # not if element is Math or is abstract
        if attribute['attTypeCode'] == 'ASTNode*':
            return
        elif 'is_ml' in attribute and attribute['is_ml']:
            return
        elif attribute['abstract']:
            return

        # useful variables
        name = strFunctions.upper_first(attribute['name'])
        if self.is_cpp_api:
            att_type = attribute['attTypeCode']
            att_name = attribute['element']
        else:
            att_type = attribute['CType']
            att_name = attribute['element'] + '_t'

        # create comment parts
        title_line = 'Creates a new {0} object, adds it to this {1} object ' \
                     'and returns the {0} object ' \
                     'created.'.format(att_name, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure '
                          'to which the {} should be '
                          'added.'.format(self.abbrev_parent, self.object_name,
                                          att_name))
        return_lines = ['@return a new {} object '
                        'instance.'.format(att_name)]
        additional = []

        # create the function declaration
        arguments = []
        if self.is_cpp_api:
            function = 'create{}'.format(name)
        else:
            function = '{}_create{}'.format(self.class_name, name)
            arguments.append('{}* {}'.format(self.object_name,
                                             self.abbrev_parent))
        return_type = '{}'.format(att_type)

        code = []
        if not self.is_header and self.is_cpp_api:
            member = attribute['memberName']
            up_pack = self.package.upper()
            low_pack = self.package.lower()
            implementation = ['{} != NULL'.format(member),
                              'delete {}'.format(member)]
            code = [self.create_code_block('if', implementation)]
            implementation = ['{}_CREATE_NS({}ns, '
                              'get{}Namespaces'
                              '())'.format(up_pack, low_pack,
                                           global_variables.prefix),
                              '{} = new {}'
                              '({}ns)'.format(member, att_name, low_pack)]
            code.append(self.create_code_block('line', implementation))
            if attribute['children_overwrite']:
                line = ['{}->setElementName(\"{}\")'.format(member,
                                                            attribute['name'])]
                code.append(self.create_code_block('line', line))
            if self.is_plugin:
                line = ['{0}->set{1}(this->get{1}'
                        '())'.format(member, global_variables.document_class)]
                code.append(self.create_code_block('line', line))
            code.append(self.create_code_block('line',
                                               ['delete {}'
                                                'ns'.format(low_pack)]))
            code.append(self.create_code_block('line', ['connectToChild()']))
            code.append((self.create_code_block('line',
                                                ['return {}'.format(member)])))
        elif not self.is_header:
            implementation = ['{} == NULL'.format(self.abbrev_parent),
                              'return NULL']
            code = [self.create_code_block('if', implementation)]
            implementation = ['return ({})({}->'
                              'create{}())'.format(att_type,
                                                   self.abbrev_parent, name)]
            code.append(self.create_code_block('line', implementation))

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

    # function to write create functions
    def write_create_concrete_child(self, attribute, member=''):
        # useful variables
        name = strFunctions.upper_first(attribute['element'])
        if self.is_cpp_api:
            att_type = attribute['element'] + '*'
            att_name = attribute['element']
        else:
            att_type = attribute['element'] + '_t*'
            att_name = attribute['element'] + '_t'

        # create comment parts
        title_line = 'Creates a new {0} object, adds it to this {1} object ' \
                     'and returns the {0} object ' \
                     'created.'.format(att_name, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure '
                          'to which the {} should be '
                          'added.'.format(self.abbrev_parent, self.object_name,
                                          att_name))
        return_lines = ['@return a new {} object '
                        'instance.'.format(att_name)]
        additional = []

        # create the function declaration
        arguments = []
        if self.is_cpp_api:
            function = 'create{}'.format(name)
        else:
            function = '{}_create{}'.format(self.class_name, name)
            arguments.append('{}* {}'.format(self.object_name,
                                             self.abbrev_parent))
        return_type = '{}'.format(att_type)

        up_pack = self.package.upper()
        low_pack = self.package.lower()
        if self.is_cpp_api:
            implementation = ['{} != NULL'.format(member),
                              'delete {}'.format(member)]
            code = [self.create_code_block('if', implementation)]
            implementation = ['{}_CREATE_NS({}ns, '
                              'get{}Namespaces'
                              '())'.format(up_pack, low_pack,
                                           global_variables.prefix),
                              '{} = new {}'
                              '({}ns)'.format(member, att_name, low_pack)]
            code.append(self.create_code_block('line', implementation))
            code.append(self.create_code_block('line',
                                               ['delete {}'
                                                'ns'.format(low_pack)]))
            code.append(self.create_code_block('line', ['connectToChild()']))
            code.append((self.create_code_block('line',
                                                ['return static_cast<{}*>'
                                                 '({})'.format(att_name,
                                                               member)])))
        else:
            implementation = ['return ({0} != NULL) ? {0}->create{1}() : '
                              'NULL'.format(self.abbrev_parent,
                                            attribute['element'])]
            code = [self.create_code_block('line', implementation)]

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

    # HELPER FUNCTIONS

    def get_c_attribute(self, attribute):
        if attribute['isArray']:
            return
        code = []
        null_line = 'NULL'
        if attribute['attType'] == 'enum':
            null_line = '{}'.format(attribute['default'])
        if not attribute['isNumber'] and attribute['attType'] != 'boolean':
            line = ['{} == NULL'.format(self.abbrev_parent),
                    'return {}'.format(null_line)]
            code = [self.create_code_block('if', line)]

        if attribute['attType'] == 'enum':
            line = ['return {}->get{}()'.format(self.abbrev_parent,
                                                attribute['capAttName'])]
        elif attribute['attType'] == 'integer' \
                or attribute['attType'] == 'unsigned integer':
            line = ['return ({0} != NULL) ? {0}->get{1}() : '
                    '{2}_INT_MAX'.format(self.abbrev_parent,
                                         attribute['capAttName'],
                                         self.cap_language)]
        elif attribute['attType'] == 'double':
            line = ['return ({0} != NULL) ? {0}->get{1}() : '
                    'util_NaN()'.format(self.abbrev_parent,
                                        attribute['capAttName'])]
        elif attribute['attType'] == 'boolean':
            line = ['return ({0} != NULL) ? static_cast<int>({0}->get{1}()) : '
                    '0'.format(self.abbrev_parent,
                               attribute['capAttName'])]
        elif attribute['type'] == 'element':
            line = ['return ({})({}->get{}())'.format(attribute['CType'],
                                                      self.abbrev_parent,
                                                      attribute['capAttName'])]
        else:
            if not self.is_list_of:
                use_name = self.abbrev_parent
            else:
                use_name = 'static_cast<const ' \
                           '{}*>({})'.format(self.class_name,
                                             self.abbrev_parent)
            line = ['return {0}->get{1}().empty() ? NULL : safe_strdup({0}'
                    '->get{1}().c_str())'.format(use_name,
                                                 attribute['capAttName'])]
        code.append(self.create_code_block('line', line))
        return code

    def set_cpp_attribute(self, attribute):
        member = attribute['memberName']
        name = attribute['name']
        if 'version_info' in attribute and False in attribute['version_info']:
            code = [self.create_code_block('line',
                                           ['unsigned int pkgVersion = '
                                            'getPackageVersion()'])]
            deal_with_versions = True
        else:
            code = []
            deal_with_versions = False

        if attribute['type'] == 'SId':
            if self.language == 'sbml':
                implementation = ['return SyntaxChecker::'
                                  'checkAndSetSId(id, mId)']
            else:
                implementation = ['{} = {}'.format(member, name),
                                  'return {}'.format(self.success)]
            code = [dict({'code_type': 'line', 'code': implementation})]
        elif attribute['type'] == 'SIdRef':
            implementation = ['!(SyntaxChecker::isValidInternalSId({})'
                              ')'.format(name),
                              'return {}'.format(self.invalid_att), 'else',
                              '{} = {}'.format(member, name),
                              'return {}'.format(self.success)]
            code = [dict({'code_type': 'if_else', 'code': implementation})]
        elif attribute['type'] == 'UnitSId' \
                or attribute['type'] == 'UnitSIdRef':
            implementation = ['!(SyntaxChecker::isValidInternalUnitSId({})'
                              ')'.format(name),
                              'return {}'.format(self.invalid_att), 'else',
                              '{} = {}'.format(member, name),
                              'return {}'.format(self.success)]
            code = [dict({'code_type': 'if_else', 'code': implementation})]
        elif attribute['type'] == 'string' or attribute['type'] == 'IDREF':
            implementation = ['{} = {}'.format(member, name),
                              'return {}'.format(self.success)]
            code = [dict({'code_type': 'line', 'code': implementation})]
        elif attribute['type'] == 'enum':
            implementation = ['{0}_isValid({1}) == '
                              '0'.format(attribute['element'], name),
                              '{} = {}'.format(member,
                                               attribute['default']),
                              'return {}'.format(self.invalid_att), 'else',
                              '{} = {}'.format(member, name),
                              'return {}'.format(self.success)]
            code = [dict({'code_type': 'if_else', 'code': implementation})]
        elif query.has_is_set_member(attribute):
            if not deal_with_versions:
                implementation = self.write_set_att_with_member(attribute, True)
                code.append(self.create_code_block('line', implementation))
            else:
                if attribute['num_versions'] == 2:
                    implementation = ['pkgVersion == 1']
                    atts = attribute['version_info'][0]
                    implementation += self.write_set_att_with_member(attribute,
                                                                     atts)
                    implementation.append('else')
                    atts = attribute['version_info'][1]
                    implementation += self.write_set_att_with_member(attribute,
                                                                     atts)
                    code.append(self.create_code_block('if_else',
                                                       implementation))
        elif attribute['type'] == 'element':
            if not self.is_plugin:
                clone = 'clone'
                nested_if = []
                implementation = ['{} == {}'.format(member, name),
                                  'return {}'.format(self.success),
                                  'else if',
                                  '{} == NULL'.format(name),
                                  'delete {}'.format(member),
                                  '{} = NULL'.format(member),
                                  'return {}'.format(self.success)]
                if attribute['element'] == 'ASTNode':
                    clone = 'deepCopy'
                    implementation.append('else if')
                    implementation.append('!({}->isWellFormedASTNode()'
                                          ')'.format(name))
                    implementation.append('return {}'.format(self.invalid_obj))
                    line = ['{} != NULL'.format(member),
                            '{}->setParent{}Object'
                            '(this)'.format(member, self.cap_language)]
                    nested_if = self.create_code_block('if', line)
                elif not attribute['is_ml']:
                    line = ['{} != NULL'.format(member)]
                    if attribute['children_overwrite']:
                        line.append('{}->setElementName'
                                    '(\"{}\")'.format(member, name))
                    line.append('{}->connectToParent(this)'.format(member))
                    nested_if = self.create_code_block('if', line)
                implementation.append('else')
                implementation.append('delete {}'.format(member))
                implementation.append('{0} = ({1} != NULL) ? {1}->{2}() '
                                      ': NULL'.format(member, name, clone))
                if len(nested_if) > 0:
                    implementation.append(nested_if)
                implementation.append('return {}'.format(self.success))
                code = [self.create_code_block('else_if', implementation)]
            else:
                implementation = ['{} == NULL'.format(name),
                                  'return {}'.format(self.failed),
                                  'else if', '{}->hasRequiredElements() '
                                             '== false'.format(name),
                                  'return {}'.format(self.invalid_obj),
                                  'else if',
                                  'getLevel() != {}->getLevel()'.format(name),
                                  'return '
                                  '{}'.format(global_variables.ret_level_mis),
                                  'else if', 'getVersion() != {}->'
                                             'getVersion()'.format(name),
                                  'return '
                                  '{}'.format(global_variables.ret_vers_mis),
                                  'else if', 'getPackageVersion() != {}->'
                                             'getPackageVersion()'.format(name),
                                  'return '
                                  '{}'.format(global_variables.ret_pkgv_mis),
                                  'else', 'delete {}'.format(member),
                                  '{} = static_cast<{}>({}->'
                                  'clone())'.format(member,
                                                    attribute['attTypeCode'],
                                                    name),
                                  'return {}'.format(self.success)]
                code = [self.create_code_block('else_if', implementation)]
        else:
            code = [dict({'code_type': 'blank', 'code': []})]
        return code

    def write_set_att_with_member(self, attribute, in_version):
        if in_version:
            implementation = ['{} = {}'.format(attribute['memberName'],
                                               attribute['name']),
                              'mIsSet{} = true'.format(attribute['capAttName']),
                              'return {}'.format(self.success)]
        else:
            implementation = ['{} = {}'.format(attribute['memberName'],
                                               attribute['name']),
                              'mIsSet{} = '
                              'false'.format(attribute['capAttName']),
                              'return {}'.format(global_variables.ret_att_unex)]
        return implementation

    def unset_cpp_attribute(self, attribute):
        if attribute['attType'] == 'string':
            implementation = ['{}.erase()'.format(attribute['memberName'])]
            implementation2 = ['{}.empty() == '
                               'true'.format(attribute['memberName']),
                               'return {}'.format(self.success), 'else',
                               'return {}'.format(self.failed)]
            code = [dict({'code_type': 'line', 'code': implementation}),
                    dict({'code_type': 'if_else', 'code': implementation2})]
        elif attribute['attType'] == 'enum':
            implementation = ['{} = {}'.format(attribute['memberName'],
                                               attribute['default']),
                              'return {}'.format(self.success)]
            code = [dict({'code_type': 'line', 'code': implementation})]
        elif query.has_is_set_member(attribute):
            implementation = ['{} = {}'.format(attribute['memberName'],
                                               attribute['default']),
                              'mIsSet{} = '
                              'false'.format(attribute['capAttName'])]
            implementation2 = ['isSet{}() == '
                               'false'.format(attribute['capAttName']),
                               'return {}'.format(self.success), 'else',
                               'return {}'.format(self.failed)]
            code = [dict({'code_type': 'line', 'code': implementation}),
                    dict({'code_type': 'if_else', 'code': implementation2})]
        elif attribute['type'] == 'element':
            implementation = ['delete {}'.format(attribute['memberName']),
                              '{} = NULL'.format(attribute['memberName']),
                              'return {}'.format(self.success)]
            code = [dict({'code_type': 'line', 'code': implementation})]
        elif attribute['isArray']:
            code = [self.create_code_block(
                'if', ['{} != NULL'.format(attribute['memberName']),
                       'delete[] {}'.format(attribute['memberName'])]),
                    self.create_code_block('line', [
                        '{} = NULL'.format(attribute['memberName'])]),
                    self.create_code_block('line', [
                        'return unset{}Length()'.format(
                            strFunctions.upper_first(attribute['name']))])]
        else:
            implementation = ['TO DO']
            code = [dict({'code_type': 'line', 'code': implementation})]
        return code

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code