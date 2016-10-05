#!/usr/bin/env python
#
# @file    GenericAttributeFunctions.py
# @brief   class to create generic functions to get/set attributes/elements
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


class GenericAttributeFunctions():
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

        self.document = False
        if 'document' in class_object:
            self.document = class_object['document']

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
    def write_get(self, attributes, att_type):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return
        elif attributes is None or len(attributes) == 0:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Gets the value of the "attributeName" attribute of this Compartment.' \
            .format(self.true, self.object_name)
        params.append('@param attributeName, the name of the attribute to retrieve.')
        params.append('@param value, the address of the value to record.')

        return_lines.append('@copydetails doc_returns_success_code')
        return_lines.append('@li @{0}constant{1}{2}, '
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.success, self.close_br))
        return_lines.append('@li @{0}constant{1}{2},'
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.failed, self.close_br))

        # create the function declaration
        function = 'getAttribute'
        return_type = 'int'

        arguments = ['const std::string& attributeName', '{0}& value'.format(att_type)]

        # create the function implementation
        first_line = ['int return_value = {0}::getAttribute(attributeName, value)'.format(global_variables.baseClass)]
        first_if = ['return_value == {0}'.format(global_variables.ret_success), 'return return_value']
        last_line = ['return return_value']
        first = True
        block = []
        for attrib in attributes:
            if not first:
                block.append('else if')
            else:
                first = False
            block.append('attributeName == \"{0}\"'.format(attrib['name']))
            lines = ['value = get{0}()'.format(attrib['capAttName']),
                     'return_value = {0}'.format(global_variables.ret_success)]
            block.append(self.create_code_block('line', lines))
            if len(block) > 2:
                if_block = self.create_code_block('else_if', block)
            else:
                if_block = self.create_code_block('if', block)
        code = [self.create_code_block('line', first_line),
                self.create_code_block('if', first_if),
                if_block,
                self.create_code_block('line', last_line)]

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

    # Functions for writing is set functions

    # function to write is set functions
    def write_is_set(self, attributes):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return
        elif attributes is None or len(attributes) == 0:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Predicate returning {0} if ' \
                     'this {1}\'s attribute \"attributeName\" is set.' \
            .format(self.true, self.object_name)
        params.append('@param attributeName, the name of the attribute to query.')

        return_lines.append('@return {0} if this {1}\'s attribute \"attributeName\" has been '
                            'set, otherwise {2} is returned.'
                            .format(self.true, self.object_name, self.false))

        # create the function declaration
        function = 'isSetAttribute'
        return_type = 'bool'

        arguments = ['const std::string& attributeName']

        # create the function implementation
        first_line = ['bool value = {0}::isSetAttribute(attributeName)'.format(global_variables.baseClass)]
        last_line = ['return value']
        first = True
        block = []
        for attrib in attributes:
            if not first:
                block.append('else if')
            else:
                first = False
            block.append('attributeName == \"{0}\"'.format(attrib['name']))
            block.append('value = isSet{0}()'.format(attrib['capAttName']))
            if len(block) > 2:
                if_block = self.create_code_block('else_if', block)
            else:
                if_block = self.create_code_block('if', block)
        code = [self.create_code_block('line', first_line),
                if_block,
                self.create_code_block('line', last_line)]

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

    # Functions for writing set functions

    # function to write set functions
    def write_set(self, attributes, att_type):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return
        elif attributes is None or len(attributes) == 0:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = 'Sets the value of the "attributeName" attribute of this Compartment.' \
            .format(self.true, self.object_name)
        params.append('@param attributeName, the name of the attribute to set.')
        params.append('@param value, the value of the attribute to set.')

        return_lines.append('@copydetails doc_returns_success_code')
        return_lines.append('@li @{0}constant{1}{2}, '
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.success, self.close_br))
        return_lines.append('@li @{0}constant{1}{2},'
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.failed, self.close_br))

        # create the function declaration
        function = 'setAttribute'
        return_type = 'int'

        arguments = ['const std::string& attributeName', '{0} value'.format(att_type)]

        # create the function implementation
        first_line = ['int return_value = {0}::setAttribute(attributeName, value)'.format(global_variables.baseClass)]
        last_line = ['return return_value']
        first = True
        block = []
        for attrib in attributes:
            if not first:
                block.append('else if')
            else:
                first = False
            block.append('attributeName == \"{0}\"'.format(attrib['name']))
            block.append('return_value = set{0}(value)'.format(attrib['capAttName']))
            if len(block) > 2:
                if_block = self.create_code_block('else_if', block)
            else:
                if_block = self.create_code_block('if', block)
        code = [self.create_code_block('line', first_line),
                if_block,
                self.create_code_block('line', last_line)]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing unset functions

    # function to write unset functions
    def write_unset(self, attributes):
        if not self.is_cpp_api:
            return
        elif self.is_list_of:
            return
        elif attributes is None or len(attributes) == 0:
            return

        # create comment parts
        params = []
        return_lines = []
        additional = []
        title_line = ' Unsets the value of the "attributeName" attribute of this {0}.'.format(self.object_name)
        params.append('@param attributeName, the name of the attribute to query.')

        return_lines.append('@copydetails doc_returns_success_code')
        return_lines.append('@li @{0}constant{1}{2}, '
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.success, self.close_br))
        return_lines.append('@li @{0}constant{1}{2},'
                            ' OperationReturnValues_'
                            't{3}'.format(self.language, self.open_br,
                                          self.failed, self.close_br))


        # create the function declaration
        function = 'unsetAttribute'
        return_type = 'int'

        arguments = ['const std::string& attributeName']

        # create the function implementation
        first_line = ['int value = {0}::unsetAttribute(attributeName)'.format(global_variables.baseClass)]
        last_line = ['return value']
        first = True
        block = []
        for attrib in attributes:
            if not first:
                block.append('else if')
            else:
                first = False
            block.append('attributeName == \"{0}\"'.format(attrib['name']))
            block.append('value = unset{0}()'.format(attrib['capAttName']))
            if len(block) > 2:
                if_block = self.create_code_block('else_if', block)
            else:
                if_block = self.create_code_block('if', block)
        code = [self.create_code_block('line', first_line),
                if_block,
                self.create_code_block('line', last_line)]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
