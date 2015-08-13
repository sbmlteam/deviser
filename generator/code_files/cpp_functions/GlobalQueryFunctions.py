#!/usr/bin/env python
#
# @file    GlobalQueryFunctions.py
# @brief   class to create general functions
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


class GlobalQueryFunctions():
    """Class for general functions"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object):
        self.language = language
        self.package = class_object['package']
        self.class_name = class_object['name']
        self.is_cpp_api = is_cpp_api
        self.is_list_of = is_list_of
        self.is_plugin = False
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']
        self.is_header = class_object['is_header']
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

        self.child_lo_elements = class_object['child_lo_elements']
        self.child_elements = class_object['child_elements']
        self.base_class = class_object['baseClass']
        self.std_base = class_object['std_base']

        self.has_only_math = class_object['has_only_math']
        self.num_children = class_object['num_children']
        self.num_non_std_children = class_object['num_non_std_children']

        # useful variables
        if not self.is_cpp_api and self.is_list_of:
            self.struct_name = self.object_child_name
        else:
            self.struct_name = self.object_name
        self.abbrev_parent = strFunctions.abbrev_name(self.object_name)
        if self.is_cpp_api is False:
            self.true = '@c 1'
            self.false = '@c 0'
        else:
            self.true = '@c true'
            self.false = '@c false'

    ########################################################################

    # Function for writing function to retrieve elements

    # function to write get by sid
    def write_get_by_sid(self):
        # only write for elements with  base derived children in cpp
        if not self.is_cpp_api or self.num_children == 0:
                return
        elif self.num_children == self.num_non_std_children:
            return

        # create comment parts
        title_line = 'Returns the first child element that has the given ' \
                     '@p id in the model-wide SId namespace, or @c NULL if ' \
                     'no such object is found.'
        params = ['@param id a string representing the id attribute '
                  'of the object to retrieve.']
        return_lines = ['@return  a pointer to the {} element with the '
                        'given @p id.'.format(self.std_base)]
        additional = []

        # create the function declaration
        function = 'getElementBySId'
        return_type = '{}*'.format(self.std_base)
        arguments = ['const std::string& id']

        code = []
        if not self.is_header:
            implementation = ['id.empty()', 'return NULL']
            code = [self.create_code_block('if', implementation),
                    self.create_code_block('line',
                                           ['{}* obj = '
                                            'NULL'.format(self.std_base)])]

            if_block = ['obj != NULL', 'return obj']
            if_code = self.create_code_block('if', if_block)
            for i in range(0, len(self.child_elements)):
                name = self.child_elements[i]['memberName']
                middle_if = self.create_code_block('if',
                                                   ['{}->getId() == '
                                                    'id'.format(name),
                                                    'return {}'.format(name)])
                code.append(self.create_code_block('if',
                                                   ['{} != NULL'.format(name),
                                                    middle_if,
                                                    'obj = {}->getElementBy'
                                                    'SId(id)'.format(name),
                                                    if_code]))

            for i in range(0, len(self.child_lo_elements)):
                line = [' obj = {}.getElementBySId('
                        'id)'.format(self.child_lo_elements[i]['memberName'])]
                code.append(self.create_code_block('line', line))
                code.append(if_code)

            if self.is_list_of:
                code.append(self.create_code_block('line',
                                                   ['return ListOf::'
                                                    'getElementBySId(id)']))
            else:
                code.append(self.create_code_block('line', ['return obj']))

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

    # function to write get by metaid
    def write_get_by_metaid(self):
        # only write for elements with  base derived children in cpp
        if not self.is_cpp_api or self.num_children == 0:
                return
        elif self.num_children == self.num_non_std_children:
            return

        # create comment parts
        title_line = 'Returns the first child element that has the given ' \
                     '@p metaid, or @c NULL if ' \
                     'no such object is found.'
        params = ['@param metaid a string representing the metaid attribute '
                  'of the object to retrieve.']
        return_lines = ['@return  a pointer to the {} element with the '
                        'given @p metaid.'.format(self.std_base)]
        additional = []

        # create the function declaration
        function = 'getElementByMetaId'
        return_type = '{}*'.format(self.std_base)
        arguments = ['const std::string& metaid']

        code = []
        if not self.is_header:
            code = [self.create_code_block('if',
                                           ['metaid.empty()', 'return NULL']),
                    self.create_code_block('line', ['{}* obj = NUL'
                                                    'L'.format(self.std_base)])]
            if_block = ['obj != NULL', 'return obj']
            if_code = self.create_code_block('if', if_block)
            for i in range(0, len(self.child_elements)):
                name = self.child_elements[i]['memberName']
                middle_if = self.create_code_block('if',
                                                   ['{}->getMetaId() == '
                                                    'metaid'.format(name),
                                                    'return {}'.format(name)])
                code.append(self.create_code_block('if',
                                                   ['{} != NULL'.format(name),
                                                    middle_if,
                                                    'obj = {}->getElementBy'
                                                    'MetaId'
                                                    '(metaid)'.format(name),
                                                    if_code]))

            num_lo = len(self.child_lo_elements)
            name = []
            for i in range(0, num_lo):
                name.append(self.child_lo_elements[i]['memberName'])
                first_if = ['{}.getMetaId() == metaid'.format(name[i]),
                            'return &{}'.format(name[i])]
                code.append(self.create_code_block('if', first_if))
            if_block = ['obj != NULL', 'return obj']
            if_code = self.create_code_block('if', if_block)
            for i in range(0, num_lo):
                line = 'obj = {}.getElementByMetaId' \
                       '(metaid)'.format(name[i])
                code.append(self.create_code_block('line', [line]))
                code.append(if_code)
            if self.is_list_of:
                code.append(self.create_code_block('line',
                                                   ['return ListOf::getElement'
                                                    'ByMetaId(metaid)']))
            else:
                code.append(self.create_code_block('line', ['return obj']))

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

    # function to write get all elements
    def write_get_all_elements(self):
        # only write for elements with  base derived children in cpp
        if not self.is_cpp_api or self.num_children == 0:
                return
        elif self.num_children == self.num_non_std_children:
            return

        # create comment parts
        title_line = 'Returns a List of all child {} objects, including ' \
                     'those nested to an arbitrary depth.'.format(self.std_base)
        params = ['filter, an ElementFilter that may impose restrictions on '
                  'the objects to be retrieved.']
        return_lines = ['@return  a List* pointer of pointers to all '
                        '{} child objects with any restriction '
                        'imposed.'.format(self.std_base)]
        additional = []

        # create the function declaration
        function = 'getAllElements'
        return_type = 'List*'
        if self.is_header:
            arguments = ['ElementFilter * filter = NULL']
        else:
            arguments = ['ElementFilter* filter']

        code = []
        if not self.is_header:
            sublist = 'NULL'
            if self.is_list_of:
                sublist = 'ListOf::getAllElements(filter)'
            implementation = ['List* ret = new List()',
                              'List* sublist = {}'.format(sublist)]
            code = [self.create_code_block('line', implementation)]
            implementation = []
            for i in range(0, len(self.child_elements)):
                name = self.child_elements[i]['memberName']
                implementation.append('ADD_FILTERED_POINTER(ret, sublist, {}, '
                                      'filter)'.format(name))
            code.append(self.create_code_block('line', implementation))
            implementation = []
            for i in range(0, len(self.child_lo_elements)):
                name = self.child_lo_elements[i]['memberName']
                implementation.append('ADD_FILTERED_LIST(ret, sublist, {}, '
                                      'filter)'.format(name))
            code.append(self.create_code_block('line', implementation))
            if not self.is_plugin:
                code.append(self.create_code_block('line',
                                                   ['ADD_FILTERED_FROM_PLUGIN'
                                                    '(ret, sublist, filter)']))
            code.append(self.create_code_block('line', ['return ret']))

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

    # Function for writing code for comp flattening

    # function to write appendFrom
    def write_append_from(self):
        # only write for elements with  base derived children in cpp
        if not self.is_cpp_api or self.num_children == 0:
                return

        # create comment parts
        title_line = 'Append items from model (used in comp flattening)'
        params = ['@param model a pointer to a model object']
        return_lines = ['']
        additional = []

        # create the function declaration
        function = 'appendFrom'
        return_type = 'int'
        arguments = ['const Model* model']

        code = []
        if not self.is_header:
            code = [self.create_code_block('line',
                                           ['int ret = LIBSBML_'
                                            'OPERATION_SUCCESS']),
                    self.create_code_block('if',
                                           ['model == NULL',
                                            'return LIBSBML_'
                                            'INVALID_OBJECT']),
                    self.create_code_block('line',
                                           ['const {0}* plug = static_cast'
                                            '<const {0}*>(model->getPlugin'
                                            '(getPrefix()'
                                            '))'.format(self.class_name)]),
                    self.create_code_block('if',
                                           ['plug == NULL', 'return ret']),
                    self.create_code_block('line',
                                           ['Model* parent = static_cast'
                                            '<Model*>(getParentSBML'
                                            'Object())']),
                    self.create_code_block('if',
                                           ['parent == NULL',
                                            'return LIBSBML_INVALID_'
                                            'OBJECT'])]
            # implementation =[]
            # for i in range(0, len(self.child_elements)):
            #     name = self.child_elements[i]['memberName']
            #     implementation.append('ADD_FILTERED_POINTER(ret, sublist, {},'
            #                           'filter)'.format(name))
            # code.append(self.create_code_block('line', implementation))
            for i in range(0, len(self.child_lo_elements)):
                name = self.child_lo_elements[i]['memberName']
                loname = strFunctions.\
                    upper_first(self.child_lo_elements[i]['name'])
                code.append(self.create_code_block('line',
                                                   ['ret = {}.appendFrom(plug->'
                                                    'get{}())'.format(name,
                                                                      loname)]))
                code.append(self.create_code_block('if',
                                                   ['ret != LIBSBML_OPERATION'
                                                    '_SUCCESS', 'return ret']))
            code.append(self.create_code_block('line', ['return ret']))

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

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
