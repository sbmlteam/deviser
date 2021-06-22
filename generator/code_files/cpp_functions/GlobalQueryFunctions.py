#!/usr/bin/env python
#
# @file    GlobalQueryFunctions.py
# @brief   class to create general functions
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

from ...util import strFunctions, global_variables, query


class GlobalQueryFunctions():
    """Class for general functions"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object):
        self.language = language
        self.cap_language = language.upper()
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

        if 'is_doc_plugin' in class_object and class_object['is_doc_plugin']:
            self.std_base = global_variables.baseClass
        else:
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
        return_lines = ['@return  a pointer to the {0} element with the '
                        'given @p id. If no such object is found, this method returns @c NULL.'.format(self.std_base)]
        additional = []

        # create the function declaration
        function = 'getElementBySId'
        return_type = '{0}*'.format(self.std_base)
        arguments = ['const std::string& id']

        code = []
        if not self.is_header:
            implementation = ['id.empty()', 'return NULL']
            code = [self.create_code_block('if', implementation),
                    self.create_code_block('line',
                                           ['{0}* obj = '
                                            'NULL'.format(self.std_base)])]

            if_block = ['obj != NULL', 'return obj']
            if_code = self.create_code_block('if', if_block)
            for i in range(0, len(self.child_elements)):
                element_type = self.child_elements[i]['element']
                if element_type == 'ASTNode' or element_type == 'XMLNode':
                    continue
                name = self.child_elements[i]['memberName']
                middle_if = self.create_code_block('if',
                                                   ['{0}->getId() == '
                                                    'id'.format(name),
                                                    'return {0}'.format(name)])
                code.append(self.create_code_block('if',
                                                   ['{0} != NULL'.format(name),
                                                    middle_if,
                                                    'obj = {0}->getElementBy'
                                                    'SId(id)'.format(name),
                                                    if_code]))

            for child in self.child_lo_elements:
                symbol ='.'
                pointer = '&'
                if 'recursive_child' in child and child['recursive_child']:
                    symbol = '->'
                    pointer = ''
                if query.has_lo_attribute(query.get_class(child['name'], child['root']), 'id'):
                    line = ['{0}{1}getId() == id'.format(child['memberName'], symbol),
                            'return {1}{0}'.format(child['memberName'], pointer)]
                    code.append(self.create_code_block('if', line))
                line = [' obj = {0}{1}getElementBySId('
                        'id)'.format(child['memberName'], symbol)]
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
        if not global_variables.is_package:
            return
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
        return_lines = ['@return  a pointer to the {0} element with the '
                        'given @p metaid. If no such object is found this method returns @c NULL.'.format(self.std_base)]
        additional = []

        # create the function declaration
        function = 'getElementByMetaId'
        return_type = '{0}*'.format(self.std_base)
        arguments = ['const std::string& metaid']

        code = []
        if not self.is_header:
            code = [self.create_code_block('if',
                                           ['metaid.empty()', 'return NULL']),
                    self.create_code_block('line', ['{0}* obj = NUL'
                                                    'L'.format(self.std_base)])]
            if_block = ['obj != NULL', 'return obj']
            if_code = self.create_code_block('if', if_block)
            for i in range(0, len(self.child_elements)):
                name = self.child_elements[i]['memberName']
                middle_if = self.create_code_block('if',
                                                   ['{0}->getMetaId() == '
                                                    'metaid'.format(name),
                                                    'return {0}'.format(name)])
                code.append(self.create_code_block('if',
                                                   ['{0} != NULL'.format(name),
                                                    middle_if,
                                                    'obj = {0}->getElementBy'
                                                    'MetaId'
                                                    '(metaid)'.format(name),
                                                    if_code]))

            num_lo = len(self.child_lo_elements)
            name = []
            for i in range(0, num_lo):
                qualifier = '.'
                pointer = '&'
                if 'recursive_child' in self.child_lo_elements[i] and self.child_lo_elements[i]['recursive_child']:
                    qualifier = '->'
                    pointer = ''
                name.append(self.child_lo_elements[i]['memberName'])
                first_if = ['{0}{1}getMetaId() == metaid'.format(name[i], qualifier),
                            'return {1}{0}'.format(name[i], pointer)]
                code.append(self.create_code_block('if', first_if))
            if_block = ['obj != NULL', 'return obj']
            if_code = self.create_code_block('if', if_block)
            for i in range(0, num_lo):
                qualifier = '.'
                if 'recursive_child' in self.child_lo_elements[i] and self.child_lo_elements[i]['recursive_child']:
                    qualifier = '->'
                line = 'obj = {0}{1}getElementByMetaId' \
                       '(metaid)'.format(name[i], qualifier)
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
        """
        This writes the 'getAllElements(ElementFilter*) function.
        The function uses macros to loop through any child elements and return
        objects to the list to be returned.
        The optional ElementFilter argument allows users to define a filter
        to allow/disallow objects from being added to the list.
        For example, this would allow users to return all elements that have a
        particular attribute set.

        For libSBML the ElementFilter is defined in sbml/util/ElementFilter.h.
        For other libraries, it is prefixed wth the library prefix e.g.
        SedElementFilter and the corresponding files will be generated
        in the relevant util folder.


        :return: dictionary of parts of function
        """
        # create appropriate names
        if self.cap_language == 'SBML':
            element_filter = 'ElementFilter'
            add_filtered = 'ADD_FILTERED'
        else:
            element_filter = '{0}ElementFilter'.\
                format(global_variables.prefix)
            add_filtered = 'ADD_{0}_FILTERED'\
                .format(global_variables.prefix.upper())

        # only write for this function for elements with base derived
        # children in cpp code
        if not self.is_cpp_api or self.num_children == 0:
            return
        elif self.num_children == self.num_non_std_children:
            return

        # create comment parts
        title_line = 'Returns a List of all child {0} objects, including ' \
                     'those nested to an arbitrary depth.'.format(self.std_base)
        params = ['@param filter an ElementFilter that may impose '
                  'restrictions on the objects to be retrieved.']
        return_lines = ['@return  a List pointer of pointers to all '
                        '{0} child objects with any restriction '
                        'imposed.'.format(self.std_base)]
        additional = []

        # create the function declaration
        function = 'getAllElements'
        return_type = 'List*'
        if self.is_header:
            arguments = ['{0} * filter = NULL'.format(element_filter)]
        else:
            arguments = ['{0}* filter'.format(element_filter)]

        code = []
        if not self.is_header:
            sublist = 'NULL'
            if self.is_list_of:
                sublist = 'ListOf::getAllElements(filter)'
            implementation = ['List* ret = new List()',
                              'List* sublist = {0}'.format(sublist)]
            code = [self.create_code_block('line', implementation)]
            implementation = []
            for child_element in self.child_elements:
                # do not write for an ASTNode
                if child_element['element'] == 'ASTNode':
                    continue
                name = child_element['memberName']
                implementation.append('{1}_POINTER(ret, sublist, {0}, '
                                      'filter)'.format(name, add_filtered))
            code.append(self.create_code_block('line', implementation))
            implementation = []
            for child_lo_element in self.child_lo_elements:
                name = child_lo_element['memberName']
                elementType = 'LIST'
                if 'recursive_child' in child_lo_element and \
                        child_lo_element['recursive_child']:
                    elementType = 'POINTER'
                implementation.append('{2}_{1}(ret, sublist, {0}, '
                                      'filter)'.format(name, elementType,
                                                       add_filtered))
            code.append(self.create_code_block('line', implementation))

            # only write get elements from plugin if this is an SBML plugin
            if self.cap_language == 'SBML' and not self.is_plugin:
                code.append(self.create_code_block('line',
                                                   ['ADD_FILTERED_FROM_PLUGIN'
                                                    '(ret, sublist, '
                                                    'filter)']))
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
        params = ['@param model a pointer to a model object.']
        return_lines = ['']
        additional = []

        # create the function declaration
        function = 'appendFrom'
        return_type = 'int'
        arguments = ['const Model* model']

        code = []
        success = '{0}'.format(global_variables.ret_success)
        invalid = '{0}'.format(global_variables.ret_invalid_obj)
        if not self.is_header:
            code = [self.create_code_block('line',
                                           ['int ret = {0}'.format(success)]),
                    self.create_code_block('if',
                                           ['model == NULL',
                                            'return {0}'.format(invalid)]),
                    self.create_code_block('line',
                                           ['const {0}* plug = static_cast'
                                            '<const {0}*>(model->getPlugin'
                                            '(getPrefix()'
                                            '))'.format(self.class_name)]),
                    self.create_code_block('if',
                                           ['plug == NULL', 'return ret']),
                    self.create_code_block('line',
                                           ['Model* parent = static_cast'
                                            '<Model*>(getParent{0}'
                                            'Object()'
                                            ')'.format(self.cap_language)]),
                    self.create_code_block('if',
                                           ['parent == NULL',
                                            'return {0}'.format(invalid)])]
            ret = global_variables.ret_success
            for i in range(0, len(self.child_lo_elements)):
                name = self.child_lo_elements[i]['memberName']
                loname = strFunctions.\
                    upper_first(self.child_lo_elements[i]['name'])
                code.append(self.create_code_block('line',
                                                   ['ret = {0}.appendFrom'
                                                    '(plug->get{1}())'
                                                    ''.format(name, loname)]))
                code.append(
                    self.create_code_block('if',
                                           ['ret != {0}'.format(ret),
                                            'return ret']))
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
