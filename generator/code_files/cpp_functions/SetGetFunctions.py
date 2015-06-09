#!/usr/bin/env python
#
# @file    SetGetFunctions.py
# @brief   class to create functions to get/set attributes/elements
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


class SetGetFunctions():
    """Class for all functions for set/get/isset/unset"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object):
        self.language = language
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
        self.child_lo_elements = class_object['child_lo_elements']
        self.child_elements = class_object['child_elements']
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
        else:
            if index < len(self.child_elements):
                attribute = self.child_elements[index]
            else:
                return

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
                     'object_name': self.struct_name})

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
            function = 'get{0}'.format(attribute['capAttName'])
            return_type = 'const std::string&'
        else:
            function = '{0}_get{1}'.format(self.class_name,
                                           attribute['capAttName'])
            return_type = 'const char *'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(self.object_name, self.abbrev_parent))

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
                     'object_name': self.struct_name})

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
                     'object_name': self.struct_name})

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
        if is_attribute:
            ob_type = 'attribute'
        else:
            ob_type = 'element'

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
                      .format(attribute['name'], attribute['attTypeCode'],
                              ob_type))

        return_lines.append("@copydetails doc_returns_success_code")
        return_lines.append('@li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, '
                            'OperationReturnValues_t}')

        return_lines.append('@li @sbmlconstant '
                            '{LIBSBML_INVALID_ATTRIBUTE_VALUE,'
                            ' OperationReturnValues_t}')

        # create the function declaration
        if self.is_cpp_api:
            function = 'set{0}'.format(attribute['capAttName'])
            return_type = 'int'
        else:
            function = '{0}_set{1}'.format(self.class_name, attribute['capAttName'])
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
                     'object_name': self.struct_name})

    # function to write set functions
    def write_set_string_for_enum(self, is_attribute, index):
        if is_attribute and index < len(self.attributes):
            attribute = self.attributes[index]
        else:
            return
        if not attribute['isEnum']:
            return
        if self.is_cpp_api is False:
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
        return_lines.append('@li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, '
                            'OperationReturnValues_t}')
        return_lines.append('@li @sbmlconstant '
                            '{LIBSBML_INVALID_ATTRIBUTE_VALUE,'
                            ' OperationReturnValues_t}')

        # create the function declaration
        if self.is_cpp_api:
            function = 'set{0}'.format(attribute['capAttName'])
            return_type = 'int'
        else:
            function = '{0}_set{1}'.format(self.class_name, attribute['capAttName'])
            return_type = 'int'

        arguments = []
        if self.is_cpp_api:
            arguments.append('{0} {1}'.format('const std::string&',
                                              attribute['name']))
        else:
            arguments.append('{0} * {1}'
                             .format(self.object_name, self.abbrev_parent))
            arguments.append('const char * {}'.format(attribute['name']))

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
                     'object_name': self.struct_name})

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
        return_lines.append('@li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, '
                            'OperationReturnValues_t}')
        return_lines.append('@li @sbmlconstant{LIBSBML_OPERATION_FAILED,'
                            ' OperationReturnValues_t}')

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
                     'object_name': self.struct_name})

    ########################################################################

    # Functions for writing create for a child element

    # function to write set functions
    def write_create(self, is_attribute, index):
        if is_attribute:
            return
        else:
            if index < len(self.child_elements):
                attribute = self.child_elements[index]
            else:
                return
        # not if element is Math
        if attribute['attTypeCode'] == 'ASTNode*':
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
                     'object_name': self.struct_name})

