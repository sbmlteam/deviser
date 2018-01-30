#!/usr/bin/env python
#
# @file    ListOfQueryFunctions.py
# @brief   class to create functions to query a ListOf element
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

from util import strFunctions, query, global_variables


class ListOfQueryFunctions():
    """Class for all functions for ListOf classes"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object):
        self.language = language
        self.cap_language = language.upper()
        self.is_cpp_api = is_cpp_api
        self.is_list_of = is_list_of
        self.is_plugin = False
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']
        self.class_object = class_object
        self.package = class_object['package']
        if is_list_of:
            self.child_name = class_object['lo_child']
            self.class_name = class_object['name']
        elif self.is_plugin:
            self.child_name = strFunctions.upper_first(class_object['element'])
            self.class_name = class_object['plugin']
        else:
            self.child_name = strFunctions.upper_first(class_object['element'])
            self.class_name = class_object['parent']['name']
        if is_cpp_api:
            self.object_name = self.class_name
            self.object_child_name = self.child_name
        else:
            if is_list_of:
                if global_variables.is_package:
                    self.object_name = 'ListOf_t'
                else:
                    self.object_name = strFunctions.prefix_name('ListOf_t')
            else:
                self.object_name = self.class_name + '_t'
            self.object_child_name = self.child_name + '_t'
        self.lo_name = ''
        if 'attType' in class_object and (class_object['attType'] == 'lo_element' or class_object['attType'] == 'inline_lo_element'):
            self.lo_name = class_object['attTypeCode']

        self.used_child_name = self.child_name
        if 'used_child_name' in class_object and class_object['used_child_name'] != '':
            self.used_child_name = strFunctions.upper_first(class_object['used_child_name'])
        self.std_base = class_object['std_base']
        self.concretes = []
        if 'concretes' in class_object and len(class_object['concretes']) > 0:
            self.concretes = class_object['concretes']
        elif 'concrete' in class_object:
            self.concretes = query.get_concretes(class_object['root'],
                                                 class_object['concrete'])

        self.document = False
        if 'document' in class_object:
            self.document = class_object['document']

        self.has_id = True
        if not self.is_list_of:
            self.has_id = query.has_attribute(
                query.get_class(self.child_name, self.class_object['root']),
                'id')

        self.used_sidrefs = []
        self.used_eq_names = []

        # useful variables
        if not self.is_cpp_api and self.is_list_of:
            self.struct_name = self.class_name + '_t'
        else:
            self.struct_name = self.object_name
        self.plural = strFunctions.plural(strFunctions.upper_first(self.used_child_name))
        self.indef_name = strFunctions.get_indefinite(self.object_child_name)
        self.abbrev_parent = strFunctions.abbrev_name(self.object_name)
        self.abbrev_child = strFunctions.abbrev_name(self.child_name)
        self.ideq = 'IdEq'
        if not global_variables.is_package:
            self.ideq = strFunctions.prefix_name('IdEq')


        # status
        if self.is_cpp_api:
            if self.is_list_of:
                self.status = 'cpp_list'
            elif self.is_plugin:
                self.status = 'plugin'
            else:
                self.status = 'cpp_not_list'
        else:
            if self.is_list_of:
                self.status = 'c_list'
            else:
                self.status = 'c_not_list'
        self.is_header = class_object['is_header']
        self.open_br = '{'
        self.close_br = '}'

    ########################################################################

    # Functions for writing get element functions

    # function to write get by index from a listOf
    def write_get_element_by_index(self, is_const):
        # c api does not need a constant version
        if not self.is_cpp_api and is_const:
            return

        if self.is_list_of:
            return_string = 'in this {0}'.format(self.object_name)
        else:
            return_string = 'in the {0} within this ' \
                            '{1}'.format(self.lo_name,
                                         self.class_name)

        # useful variables
        virtual = True if self.is_list_of else False
        # create comment parts
        title_line = 'Get {0} {1} from the {2}.'.format(self.indef_name,
                                                        self.object_child_name,
                                                        self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param n an unsigned int representing the index '
                      'of the {0} to retrieve.'.format(self.object_child_name))
        return_lines = ['@return the nth {0} {1}.'.format(
            self.object_child_name, return_string)]
        additional = []
        additional.append('@copydetails doc_returned_unowned_pointer')
        if self.is_cpp_api:
            self.add_other_referenced_functions(additional, 'getindex', self.used_child_name, self.object_child_name)

        # create the function declaration
        arguments = []
        used_c_name = strFunctions.remove_prefix(self.used_child_name)
        if self.is_cpp_api:
            function = 'get' if self.is_list_of else 'get{0}'\
                .format(strFunctions.remove_prefix(self.used_child_name))
        else:
            function = '{0}_get{1}'.format(self.class_name, used_c_name)
            arguments.append('{0}* {1}'.format(self.object_name,
                                               self.abbrev_parent))
        arguments.append('unsigned int n')
        if is_const:
            return_type = 'const {0}*'.format(self.object_child_name)
        else:
            return_type = '{0}*'.format(self.object_child_name)
        # if appropriate write the code
        code = []
        if not self.is_header:
            if self.status == 'cpp_list':
                list_type = 'ListOf'
                if not global_variables.is_package:
                    list_type = strFunctions.prefix_name('ListOf')
                const = 'const ' if is_const else ''
                implementation = ['return static_cast<{0}{1}*>({2}::'
                                  'get(n))'.format(const, self.child_name, list_type)]
                code = [self.create_code_block('line', implementation)]
            elif self.status == 'cpp_not_list':
                if not self.document:
                    implementation = ['return {0}.get'
                                      '(n)'.format(self.class_object['memberName'])]
                else:
                    if not is_const:
                        implementation = ['return const_cast<{1}Error*>({0}.getError'
                                          '(n))'.format(self.class_object['memberName'],
                                                        global_variables.prefix)]
                    else:
                        implementation = ['return {0}.getError'
                                          '(n)'.format(self.class_object['memberName'])]

                code = [self.create_code_block('line', implementation)]
            elif self.status == 'plugin':
                const = 'const ' if is_const else ''
                name = self.class_object['memberName']
                implementation = ['return static_cast<{0} {1}*>({2}.get'
                                  '(n))'.format(const, self.child_name, name)]
                code = [self.create_code_block('line', implementation)]
            elif self.status == 'c_list':
                line = ['{0} == NULL'.format(self.abbrev_parent), 'return NULL']
                code = [self.create_code_block('if', line)]
                line = ['return static_cast <{0}*>({1})->get'
                        '(n)'.format(self.class_name, self.abbrev_parent)]
                code.append(self.create_code_block('line', line))
            else:
                line = ['return ({0} != NULL) ? {0}->get{1}(n) : '
                        'NULL'.format(self.abbrev_parent, used_c_name)]
                code = [self.create_code_block('line', line)]
        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': is_const,
                     'virtual': virtual,
                     'object_name': self.struct_name,
                     'implementation': code})

    def add_other_referenced_functions(self, additional, this_func, object, child_object = ''):
        if child_object == '':
            child_object = object
        additional.append(' ')
        if self.is_cpp_api:
            if this_func != 'add':
                additional.append('@see add{0}(const {1}* object)'.format(object, child_object))
            if this_func != 'create':
                additional.append('@see create{0}()'.format(object))
            if this_func != 'getid':
                additional.append('@see get(const std::string& sid)') if self.is_list_of else \
                    additional.append('@see get{0}(const std::string& sid)'.format(object))
            if this_func != 'getindex':
                additional.append('@see get(unsigned int n)') if self.is_list_of else \
                    additional.append('@see get{0}(unsigned int n)'.format(object))
            if this_func != 'getnum':
                additional.append('@see getNum{0}()'.format(strFunctions.remove_prefix(self.plural)))
                # additional.append('@see size()') if self.is_list_of \
                #     else additional.append('@see getNum{0}()'.format(strFunctions.remove_prefix(self.plural)))
            if this_func != 'removeid':
                additional.append('@see remove(const std::string& sid)') if self.is_list_of else \
                    additional.append('@see remove{0}(const std::string& sid)'.format(object))
            if this_func != 'removeindex':
                additional.append('@see remove(unsigned int n)') if self.is_list_of else \
                    additional.append('@see remove{0}(unsigned int n)'.format(object))
        else:
            lenobject = len(object)
            objectname = object # object[0:lenobject-2]
            if this_func != 'add':
                additional.append('@see {0}_add{1}()'.format(self.class_name, objectname))
            if this_func != 'create':
                additional.append('@see {0}_create{1}()'.format(self.class_name, objectname))
            if this_func != 'getid':
                additional.append('@see {0}_getById()'.format(self.class_name)) if self.is_list_of else \
                    additional.append('@see {0}_get{1}ById()'.format(self.class_name, objectname))
            if this_func != 'getindex':
                additional.append('@see {0}_get()'.format(self.class_name)) if self.is_list_of else \
                    additional.append('@see {0}_get{1}()'.format(self.class_name, objectname))
            if this_func != 'getnum':
                additional.append('@see {1}_getNum{0}()'.format(strFunctions.remove_prefix(self.plural), self.class_name, objectname))
                # additional.append('@see size()') if self.is_list_of \
                #     else additional.append('@see getNum{0}()'.format(strFunctions.remove_prefix(self.plural)))
            if this_func != 'removeid':
                additional.append('@see {0}_removeById()'.format(self.class_name)) if self.is_list_of else \
                    additional.append('@see {0}_remove{1}ById()'.format(self.class_name, objectname))
            if this_func != 'removeindex':
                additional.append('@see {0}_remove()'.format(self.class_name)) if self.is_list_of else \
                    additional.append('@see {0}_remove{1}()'.format(self.class_name, objectname))


    # function to write get by id from a listOf
    def write_get_element_by_id(self, is_const):
        # c api does not need a constant version
        if not self.is_cpp_api and is_const:
            return
        elif not self.has_id:
            return

        # useful variables
        virtual = True if self.is_list_of else False
        used_c_name = strFunctions.remove_prefix(self.child_name)
        used_cpp_name = strFunctions.remove_prefix(self.used_child_name)

        if self.is_list_of:
            return_string = 'in this {0}'.format(self.object_name)
        else:
            return_string = 'in the {0} within this ' \
                            '{1}'.format(self.lo_name,
                                         self.class_name)
        # create comment
        title_line = 'Get {0} {1} from the {2} based on its identifier.'\
            .format(self.indef_name, self.object_child_name, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param sid a string representing the identifier '
                      'of the {0} to retrieve.'.format(self.object_child_name))
        return_lines = ['@return the {0} {1} with the given @p sid'
                        ' or @c NULL if no such {0} exists.'
                        .format(self.object_child_name, return_string)]
        additional = []
        additional.append('@copydetails doc_returned_unowned_pointer')
        if self.is_cpp_api:
            self.add_other_referenced_functions(additional, 'getid', self.used_child_name, self.object_child_name)

        # create function declaration
        if self.is_cpp_api:
            function = 'get' if self.is_list_of \
                else 'get{0}'.format(used_cpp_name)
            arguments = ['const std::string& sid']
        else:
            function = '{0}_getById'.format(self.class_name) if self.is_list_of \
                else '{0}_get{1}ById'.format(self.class_name, used_c_name)
            arguments = ['{0}* {1}'.format(self.object_name,
                                           self.abbrev_parent),
                         'const char *sid']
        if is_const:
            return_type = 'const {0}*'.format(self.object_child_name)
        else:
            return_type = '{0}*'.format(self.object_child_name)
        # if appropriate write the code
        code = []
        if not self.is_header:
            if self.status == 'cpp_list':
                code = self.cpp_list_write_get_element_by_id(is_const)
            elif self.status == 'cpp_not_list':
                code = self.cpp_not_list_write_get_element_by_id()
            elif self.status == 'plugin':
                const = 'const ' if is_const else ''
                name = self.class_object['memberName']
                implementation = ['return static_cast<{0} {1}*>({2}.get'
                                  '(sid))'.format(const, self.child_name, name)]
                code = [self.create_code_block('line', implementation)]
            elif self.status == 'c_list':
                code = self.c_list_write_get_element_by_id()
            else:
                code = self.c_not_list_write_get_element_by_id(used_c_name)
        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': is_const,
                     'virtual': virtual,
                     'object_name': self.struct_name,
                     'implementation': code})

    def cpp_list_write_get_element_by_id(self, const):
        if const:
            implementation = ['vector<{0}*>::const_iterator '
                              'result'.format(self.std_base),
                              'result = find_if(mItems.begin(), mItems.end(), '
                              '{1}<{0}>(sid))'.format(self.object_child_name,
                                                      self.ideq),
                              'return (result == mItems.end()) ? 0 : '
                              'static_cast  <const {0}*> '
                              '(*result)'.format(self.object_child_name)]
        else:
            implementation = ['return const_cast<{0}*>(static_cast<const {1}&>'
                              '(*this).get(sid))'.format(self.object_child_name,
                                                         self.object_name)]
        code = [self.create_code_block('line', implementation)]
        return code

    def cpp_not_list_write_get_element_by_id(self):
        implementation = ['return {0}.'
                          'get(sid)'.format(self.class_object['memberName'])]
        code = [self.create_code_block('line', implementation)]
        return code

    def c_list_write_get_element_by_id(self):
        code = []
        line = ['{0} == NULL'.format(self.abbrev_parent), 'return NULL']
        code.append(self.create_code_block('if', line))
        implementation = ['return (sid != NULL) ? static_cast <{0}*>({1})'
                          '->get(sid) : NULL'.format(self.class_name,
                                                     self.abbrev_parent)]
        code.append(self.create_code_block('line', implementation))
        return code

    def c_not_list_write_get_element_by_id(self, name):
        implementation = ['return ({0} != NULL && '
                          'sid != NULL) ? {0}->get{1}'
                          '(sid) : NULL'.format(self.abbrev_parent,
                                                name)]
        code = [self.create_code_block('line', implementation)]
        return code

    # function to write get by sidref from a listOf
    def write_get_element_by_sidref(self, sid_ref, const):
        # c api does not need a constant version
        if not self.is_cpp_api and const:
            return

        # useful variables
        element = strFunctions.upper_first(sid_ref['name'])
        elemType = sid_ref['element'] if 'element' in sid_ref else 'element'
        att_name = sid_ref['name']
        match = [element, const]
        if match in self.used_sidrefs:
            return
        else:
            self.used_sidrefs.append(match)

        # create comment
        if elemType == 'SBase':
            title_line = 'Get {0} {1} from the {2} based on the element to which ' \
                         'it refers.'.format(self.indef_name,
                                             self.object_child_name,
                                             self.object_name,
                                             element)
        else:
            title_line = 'Get {0} {1} from the {2} based on the {3} to which ' \
                         'it refers.'.format(self.indef_name,
                                             self.object_child_name,
                                             self.object_name,
                                             element)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param sid a string representing the \"{0}\" attribute '
                      'of the {1} object to '
                      'retrieve.'.format(att_name, self.object_child_name))
        return_lines = ['@return the first {0} in this {1} based on the '
                        'given {2} attribute or NULL if no such {0} exists.'
                        .format(self.object_child_name, self.object_name,
                                att_name)]
        additional = ['@copydetails doc_returned_unowned_pointer']

        # create function declaration
        used_c_name = strFunctions.remove_prefix(self.child_name)
        used_cpp_name = strFunctions.remove_prefix(self.object_child_name)
        if self.is_cpp_api:
            if self.is_list_of:
                function = 'getBy{0}'.format(element)
            else:
                function = 'get{0}By{1}'.format(used_cpp_name, element)
            arguments = ['const std::string& sid']
        else:
            function = '{0}_get{1}By{2}'.format(self.class_name,
                                                used_c_name, element)
            arguments = ['{0}* {1}'.format(self.object_name,
                                           self.abbrev_parent),
                         'const char *sid']
        if const:
            return_type = 'const {0}*'.format(self.object_child_name)
        else:
            return_type = '{0}*'.format(self.object_child_name)
        up_name = strFunctions.abbrev_name(element).upper()
        if const and self.is_cpp_api and self.is_list_of:
            implementation = ['vector<{0}*>::const_iterator '
                              'result'.format(self.std_base),
                              'result = find_if(mItems.begin(), mItems.end(), '
                              '{1}{0}(sid))'.format(up_name, self.ideq),
                              'return (result == mItems.end()) ? 0 : '
                              'static_cast  <const {0}*> '
                              '(*result)'.format(self.object_child_name)]
        elif self.is_cpp_api and not self.is_list_of:
            implementation = ['return {0}.getBy{1}'
                              '(sid)'.format(self.class_object['memberName'],
                                             element)]
        elif not const and self.is_cpp_api and self.is_list_of:
            implementation = ['return const_cast<{0}*>(static_cast<const {1}'
                              '&>(*this).getBy{2}(sid))'.format(self.child_name,
                                                                self.class_name,
                                                                element)]
        else:
            implementation = ['return ({0} != NULL && '
                              'sid != NULL) ? {0}->get{1}By{2}'
                              '(sid) : NULL'.format(self.abbrev_parent,
                                                    used_c_name,
                                                    element)]
        code = [self.create_code_block('line', implementation)]
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

    # function to write lookup by sidref from a listOf
    def write_lookup(self, sid_ref):
        # c api does not need it
        if not self.is_cpp_api:
            return

        # useful variables
        if 'capAttName' in sid_ref:
            element = sid_ref['capAttName']
        else:
            element = sid_ref['element']
        eq_name = '{1}{0}'.format(strFunctions.abbrev_name(element).upper(),
                                  self.ideq)
        match = [element]
        if match in self.used_sidrefs:
            return
        else:
            self.used_sidrefs.append(match)
        if eq_name in self.used_eq_names:
            eq_name += '_A'
        self.used_eq_names.append(eq_name)
        open_b = '{'
        close_b = '}'
        # create comment
        title_line = 'Used by {0}::get() to lookup {1} {2} ' \
                     'based on its {3}.'.format(self.class_name,
                                                self.indef_name,
                                                self.child_name, element)
        params = []
        return_lines = []
        additional = []

        # create function declaration
        function = 'struct {0} : public std::unary_function' \
                   '<{1}*, bool>'.format(eq_name, self.std_base)
        arguments = []
        return_type = ''
        code = ['const string& id;', ' ',
                '{0} (const string& id) : id(id) {1}  '
                '{2}'.format(eq_name, open_b, close_b),
                'bool operator() ({0}* sb)'.format(self.std_base), '{',
                '        return (static_cast<{0}*>(sb)'
                '->get{1}() == id);'.format(self.child_name, element), '}']
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

    # Functions for writing remove element functions

    # function to write remove by index from a listOf
    def write_remove_element_by_index(self):
        # useful variables
        virtual = True if self.is_list_of else False

        # create comment parts
        title_line = 'Removes the nth {0} from this {1} and returns a ' \
                     'pointer to it.'.format(self.object_child_name,
                                             self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param n an unsigned int representing the index of '
                      'the {0} to remove.'.format(self.object_child_name))
        return_lines = ['@return a pointer to the nth {0} in this {1}.'.format(
            self.object_child_name, self.object_name)]
        additional = []
        additional.append('@copydetails doc_returned_owned_pointer')
        if self.is_cpp_api:
            self.add_other_referenced_functions(additional, 'removeindex', self.used_child_name, self.object_child_name)
        # create the function declaration
        arguments = []
        used_c_name = strFunctions.remove_prefix(self.used_child_name)
        used_cpp_name = strFunctions.remove_prefix(self.used_child_name)
        if self.is_cpp_api:
            function = 'remove' if self.is_list_of \
                else 'remove{0}'.format(used_cpp_name)
        else:
            if self.is_list_of:
                function = '{0}_remove'.format(self.class_name)
            else:
                function = '{0}_remove{1}'.format(self.class_name,
                                                  used_c_name)

            arguments.append('{0}* {1}'.format(self.object_name,
                                               self.abbrev_parent))
        arguments.append('unsigned int n')
        return_type = '{0}*'.format(self.object_child_name)

        code = []
        if not self.is_header:
            if self.status == 'cpp_list':
                list_type = 'ListOf'
                if not global_variables.is_package:
                    list_type = strFunctions.prefix_name('ListOf')
                implementation = ['return static_cast<{0}*>({1}::'
                                  'remove(n))'.format(self.object_child_name,
                                                      list_type)]
                code = [self.create_code_block('line', implementation)]
            elif self.status == 'cpp_not_list':
                member = self.class_object['memberName']
                implementation = ['return {0}.remove(n)'.format(member)]
                code = [self.create_code_block('line', implementation)]
            elif self.status == 'plugin':
                name = self.class_object['memberName']
                implementation = ['return static_cast<{0}*>({1}.remove'
                                  '(n))'.format(self.child_name, name)]
                code = [self.create_code_block('line', implementation)]
            elif self.status == 'c_list':
                line = ['{0} == NULL'.format(self.abbrev_parent), 'return NULL']
                code = [self.create_code_block('if', line)]
                line = ['return static_cast <{0}*>({1})->remove'
                        '(n)'.format(self.class_name, self.abbrev_parent)]
                code.append(self.create_code_block('line', line))
            else:
                line = ['return ({0} != NULL) ? '
                        '{0}->remove{1}(n) : '
                        'NULL'.format(self.abbrev_parent, used_c_name)]
                code = [self.create_code_block('line', line)]
        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': virtual,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write remove by id from a listOf
    def write_remove_element_by_id(self):
        if not self.is_list_of:
            child = query.get_class(self.child_name,
                                    self.class_object['root'])
            has_id = False
            if child:
                has_id = query.has_attribute(child, 'id')
            if not has_id:
                return
        # useful variables
        virtual = True if self.is_list_of else False

        # create comment parts
        title_line = 'Removes the {0} from this {1} based on its identifier and ' \
                     'returns a pointer to it.'.format(self.object_child_name,
                                                       self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param sid a string representing the identifier of '
                      'the {0} to remove.'.format(self.object_child_name))
        return_lines = ['@return the {0} in this {1} based on the identifier '
                        'or NULL if no such {0} '
                        'exists.'.format(self.object_child_name,
                                         self.object_name)]
        additional = []
        additional.append('@copydetails doc_returned_owned_pointer')
        if self.is_cpp_api:
            self.add_other_referenced_functions(additional, 'removeid', self.object_child_name)
        # create the function declaration
        arguments = []
        used_c_name = strFunctions.remove_prefix(self.child_name)
        used_cpp_name = strFunctions.remove_prefix(self.object_child_name)
        if self.is_cpp_api:
            function = 'remove' if self.is_list_of \
                else 'remove{0}'.format(used_cpp_name)
            arguments = ['const std::string& sid']
        else:
            if self.is_list_of:
                function = '{0}_removeById'.format(self.class_name)
            else:
                function = '{0}_remove{1}ById'.format(self.class_name,
                                                      used_c_name)
            arguments.append('{0}* {1}'.format(self.object_name,
                                               self.abbrev_parent))
            arguments.append('const char* sid')
        return_type = '{0}*'.format(self.object_child_name)

        code = []
        if not self.is_header:
            if self.status == 'cpp_list':
               implementation = ['{0}* item = NULL'.format(self.std_base),
                                  'vector<{0}*>::iterator '
                                  'result'.format(self.std_base)]
               code = [self.create_code_block('line', implementation),
                       self.create_code_block('line',
                                              ['result = find_if('
                                               'mItems.begin(), '
                                               'mItems.end(), {1}<{0}>(sid)'
                                                ')'.format(self.
                                                           object_child_name,
                                                           self.ideq)])]
               implementation = ['result != mItems.end()', 'item = *result',
                                  'mItems.erase(result)']
               code.append(self.create_code_block('if', implementation))
               code.append(
                    self.create_code_block(
                        'line',
                        ['return static_cast <{0}*> '
                         '(item)'.format(self.object_child_name)]))
            elif self.status == 'cpp_not_list':
                member = self.class_object['memberName']
                implementation = ['return {0}.remove(sid)'.format(member)]
                code = [self.create_code_block('line', implementation)]
            elif self.status == 'plugin':
                name = self.class_object['memberName']
                implementation = ['return static_cast<{0}*>({1}.remove'
                                  '(sid))'.format(self.child_name, name)]
                code = [self.create_code_block('line', implementation)]
            elif self.status == 'c_list':
                line = ['{0} == NULL'.format(self.abbrev_parent), 'return NULL']
                code = [self.create_code_block('if', line)]
                line = ['return (sid != NULL) ? static_cast <{0}*>({1})->remove'
                        '(sid) : NULL'.format(self.class_name,
                                              self.abbrev_parent)]
                code.append(self.create_code_block('line', line))
            else:
                line = ['return ({0} != NULL && sid != NULL) ? '
                        '{0}->remove{1}(sid) : '
                        'NULL'.format(self.abbrev_parent, used_c_name)]
                code = [self.create_code_block('line', line)]

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': virtual,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing add and create element functions

    # function to write add element
    def write_add_element_function(self):
        # create comment parts
        title_line = 'Adds a copy of the given {0} to this {1}.'.format(
            self.object_child_name, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure to which the {2} '
                          'should be added.'.format(self.abbrev_parent,
                                                    self.object_name,
                                                    self.object_child_name))
        params.append('@param {0} the {1} object to '
                      'add.'.format(self.abbrev_child, self.object_child_name))
        success = global_variables.ret_success
        failed = global_variables.ret_failed
        return_lines = ['@copydetails doc_returns_success_code',
                        '@li @{0}constant{1}{2}, '
                        'OperationReturnValues_t{3}'.format(self.language,
                                                            self.open_br,
                                                            success,
                                                            self.close_br),
                        '@li @{0}constant{1}{2},'
                        ' OperationReturnValues_t{3}'.format(self.language,
                                                             self.open_br,
                                                             failed,
                                                             self.close_br),
                        '@li @{0}constant{1}{2},'
                        ' OperationReturnValues_t{3}'.format(self.language,
                                                             self.open_br,
                                                             global_variables.ret_invalid_obj,
                                                             self.close_br),
                        '@li @{0}constant{1}{2},'
                        ' OperationReturnValues_t{3}'.format(self.language,
                                                             self.open_br,
                                                             global_variables.ret_level_mis,
                                                             self.close_br),
                        '@li @{0}constant{1}{2},'
                        ' OperationReturnValues_t{3}'.format(self.language,
                                                             self.open_br,
                                                             global_variables.ret_vers_mis,
                                                             self.close_br),
                        '@li @{0}constant{1}{2},'
                        ' OperationReturnValues_t{3}'.format(self.language,
                                                             self.open_br,
                                                             global_variables.ret_pkgv_mis,
                                                             self.close_br),
                        '@li @{0}constant{1}{2},'
                        ' OperationReturnValues_t{3}'.format(self.language,
                                                             self.open_br,
                                                             global_variables.ret_dup_id,
                                                             self.close_br)]
        additional = []
        if self.is_cpp_api:
            additional.append('@copydetails doc_note_object_is_copied')
            self.add_other_referenced_functions(additional, 'add', self.used_child_name, self.object_child_name)
        # create the function declaration
        arguments = []
        used_c_name = strFunctions.remove_prefix(self.used_child_name)
        used_cpp_name = strFunctions.remove_prefix(self.used_child_name)
        if self.is_cpp_api:
            function = 'add{0}'.format(used_cpp_name)
        else:
            function = '{0}_add{1}'.format(self.class_name, used_c_name)
            arguments.append('{0}* {1}'.format(self.object_name,
                                               self.abbrev_parent))
        arguments.append('const {0}* {1}'.format(self.object_child_name,
                                                 self.abbrev_child))
        return_type = 'int'
        member = ''
        if not self.is_list_of:
            member = self.class_object['memberName']
            else_lines = ['return {0}.append({1})'.format(member, self.abbrev_child)]
        else:
            else_lines = ['return append({0})'.format(self.abbrev_child)]
        this_object = query.get_class(self.object_child_name,
                                      self.class_object['root'])
        if self.is_cpp_api:
            implementation = ['{0} == NULL'.format(self.abbrev_child),
                              'return {0}'.format(global_variables.ret_failed),
                              'else if',
                              '{0}->hasRequiredAttributes() == '
                              'false'.format(self.abbrev_child),
                              'return '
                              '{0}'.format(global_variables.ret_invalid_obj)]
            if this_object and 'hasChildren' in this_object \
                    and this_object['hasChildren']:
                ret = global_variables.ret_invalid_obj
                implementation += ['else if',
                                   '{0}->hasRequiredElements() == '
                                   'false'.format(self.abbrev_child),
                                   'return {0}'.format(ret)]
            implementation += ['else if',
                               'getLevel() != {0}->'
                               'getLevel()'.format(self.abbrev_child),
                               'return '
                               '{0}'.format(global_variables.ret_level_mis),
                               'else if',
                               'getVersion() != {0}->'
                               'getVersion()'.format(self.abbrev_child),
                               'return '
                               '{0}'.format(global_variables.ret_vers_mis),
                               'else if']
            if self.is_plugin:
                ret = global_variables.ret_pkgv_mis
                implementation.append('getPackageVersion() != {0}->getPackage'
                                      'Version()'.format(self.abbrev_child))
                implementation.append('return {0}'.format(ret))
            else:
                implementation.append('matchesRequired{0}NamespacesForAddition'
                                      '(static_cast<const {1}*>({2})) == '
                                      'false'.format(global_variables.prefix,
                                                     self.std_base,
                                                     self.abbrev_child))
                implementation.append('return '
                                      '{0}'.format(global_variables.ret_ns_mis))
            if not self.is_list_of and self.has_id:
                implementation.append('else if')
                implementation.append('{0}->isSetId() '
                                      '&& ({1}.get({0}->getId())) '
                                      '!= NULL'.format(self.abbrev_child,
                                                       member))
                implementation.append('return '
                                      '{0}'.format(global_variables.ret_dup_id))
            implementation.append('else')
            implementation.append(self.create_code_block('line', else_lines))
            code = [self.create_code_block('else_if', implementation)]
        else:
            implementation = ['return ({0} != NULL) ? {0}->add{1}({2}) : '
                              '{3}'.format(self.abbrev_parent,
                                           used_c_name,
                                           self.abbrev_child,
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

    # function to write create element
    def write_create_element_function(self, index=0):
        is_concrete = False
        if len(self.concretes) == 0 and index == 0:
            child = self.object_child_name
            abbrev_child = self.abbrev_child
            child_name = self.child_name
        else:
            if index == 0:
                return
            else:
                i = index - 1
            child_name = self.concretes[i]['element']
            child = child_name
            if not self.is_cpp_api:
                child += '_t'
            is_concrete = True
            abbrev_child = strFunctions.abbrev_name(child)
        # create comment parts
        title_line = 'Creates a new {0} object, adds it to this {1} object ' \
                     'and returns the {0} object ' \
                     'created.'.format(child, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure '
                          'to which the {2} should be '
                          'added.'.format(self.abbrev_parent, self.object_name,
                                          child))
        return_lines = ['@return a new {0} object '
                        'instance.'.format(child)]
        additional = []
        additional.append('@copydetails doc_returned_unowned_pointer')
        if self.is_cpp_api:
            self.add_other_referenced_functions(additional, 'create', self.used_child_name, self.object_child_name)
        # create the function declaration
        arguments = []

        remove_prefix = False
        prefix_to_remove = ''
        # hack for render
        if self.package == 'Render' or self.package == 'render':
            remove_prefix = True
            prefix_to_remove = strFunctions.upper_first(self.package)
        used_c_name = strFunctions.remove_prefix(child_name, False, remove_prefix, prefix_to_remove)
        if self.is_cpp_api:
            function = 'create{0}'.format(strFunctions.remove_prefix(child, False, remove_prefix, prefix_to_remove))
        else:
            function = '{0}_create{1}'.format(self.class_name, used_c_name)
            arguments.append('{0}* {1}'.format(self.object_name,
                                               self.abbrev_parent))
        return_type = '{0}*'.format(child)

        if self.is_cpp_api and not is_concrete:
            pack_up = self.package.upper()
            pack_low = self.package.lower()
            implementation = ['{0}* {1} = NULL'.format(self.child_name,
                                                       self.abbrev_child)]
            code = [self.create_code_block('line', implementation)]

            if self.class_object['num_versions'] > 1:
                line = '{0}_CREATE_NS_WITH_VERSION({1}ns, get{2}Namespaces(), ' \
                       'getPackageVersion())'.format(pack_up, pack_low,
                                                     global_variables.prefix)
            else:
                line = '{0}_CREATE_NS({1}ns, ' \
                       'get{2}Namespaces())'.format(pack_up, pack_low,
                                                    global_variables.prefix)
            if global_variables.is_package:
                implementation = [line,
                                  '{0} = new {1}({2}ns)'.format(self.abbrev_child,
                                                                self.child_name,
                                                                pack_low),
                                  'delete {0}ns'.format(pack_low),
                                  'catch', '...', '']
            else:
                implementation = ['{0} = new {1}(get{2}Namespaces())'
                                  ''.format(self.abbrev_child,
                                            self.child_name,
                                            global_variables.prefix),
                                  'catch', '...', '']
            code.append(self.create_code_block('try', implementation))
            implementation = ['{0} != NULL'.format(self.abbrev_child)]
            if self.is_list_of:
                implementation.append('appendAndOwn'
                                      '({0})'.format(self.abbrev_child))
            else:
                member = self.class_object['memberName']
                implementation.append('{0}.appendAndOwn'
                                      '({1})'.format(member, self.abbrev_child))
            code.append(self.create_code_block('if', implementation))
            implementation = ['return {0}'.format(self.abbrev_child)]
            code.append(self.create_code_block('line', implementation))
        elif self.is_cpp_api and is_concrete:
            pack_up = self.package.upper()
            pack_low = self.package.lower()
            implementation = ['{0}* {1} = NULL'.format(child,
                                                       abbrev_child)]
            code = [self.create_code_block('line', implementation)]
            if self.class_object['num_versions'] > 1:
                line = '{0}_CREATE_NS_WITH_VERSION({1}ns, get{2}Namespaces(), ' \
                       'getPackageVersion())'.format(pack_up, pack_low,
                                                     global_variables.prefix)
            else:
                line = '{0}_CREATE_NS({1}ns, ' \
                       'get{2}Namespaces())'.format(pack_up, pack_low,
                                                    global_variables.prefix)
            if global_variables.is_package:
                implementation = [line,
                                  '{0} = new {1}({2}ns)'.format(abbrev_child,
                                                                child,
                                                                pack_low),
                                  'delete {0}ns'.format(pack_low),
                                  'catch', '...', '']
            else:
                implementation = ['{0} = new {1}(get{2}Namespaces())'
                                  ''.format(abbrev_child,
                                            child,
                                            global_variables.prefix),
                                  'catch', '...', '']
            code.append(self.create_code_block('try', implementation))
            implementation = ['{0} != NULL'.format(abbrev_child)]
            if self.is_list_of:
                implementation.append('appendAndOwn'
                                      '({0})'.format(abbrev_child))
            else:
                member = self.class_object['memberName']
                implementation.append('{0}.appendAndOwn'
                                      '({1})'.format(member, abbrev_child))
            code.append(self.create_code_block('if', implementation))
            implementation = ['return {0}'.format(abbrev_child)]
            code.append(self.create_code_block('line', implementation))
        else:
            implementation = ['return ({0} != NULL) ? {0}->create{1}() : '
                              'NULL'.format(self.abbrev_parent,
                                            used_c_name)]
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

    # Functions for writing get num element functions

    # function to write get num
    def write_get_num_element_function(self, parameter=None):
        # create comment parts
        if parameter:
            title_line = 'Get the number of {0} objects in ' \
                         'this {1} with the given {2}' \
                         '.'.format(self.object_child_name,
                                    self.object_name,
                                    parameter['name'])
        else:
            title_line = 'Get the number of {0} objects in ' \
                         'this {1}.'.format(self.object_child_name,
                                            self.object_name)
        params = []
        if parameter:
            params.append('@param {0} the {0} of the {1} to return.'
                          ''.format(parameter['name'], self.object_child_name))
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure to query.'
                          .format(self.abbrev_parent, self.object_name))
        return_lines = ['@return the number of {0} objects in '
                        'this {1}.'.format(self.object_child_name,
                                           self.object_name)]
        additional = []
        if self.is_cpp_api:
            self.add_other_referenced_functions(additional, 'getnum', self.used_child_name, self.object_child_name)

        # create the function declaration
        arguments = []
        if parameter:
            arguments.append('{0} {1}'.format(parameter['type'], parameter['name']))
        used_c_name = strFunctions.remove_prefix(self.plural)
        if self.is_cpp_api:
            function = 'getNum{0}'.format(used_c_name)
        else:
            function = '{0}_getNum{1}'.format(self.class_name, used_c_name)
            arguments.append('{0}* {1}'.format(self.object_name,
                                               self.abbrev_parent))
        return_type = 'unsigned int'

        if self.is_cpp_api and self.is_list_of:
            implementation = ['return size()']
        elif self.is_cpp_api and not self.is_list_of:
            if not self.document:
                implementation = ['return {0}.'
                                  'size()'.format(self.class_object['memberName'])]
            elif parameter:
                implementation = ['return getErrorLog()->'
                                  'getNumFailsWith{0}({1})'
                                  ''.format(strFunctions.upper_first(parameter['name']),
                                            parameter['name'])]
            else:
                implementation = ['return {0}.'
                                  'getNumErrors()'.format(self.class_object['memberName'])]

        else:
            implementation = ['return ({0} != NULL) ? {0}->getNum{1}() : '
                              '{2}_INT_MAX'.format(self.abbrev_parent,
                                                   used_c_name,
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
                     'constant': True,
                     'virtual': False,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing getListOf

    # function to write get num
    def write_get_list_of_function(self, is_const=False):
        if not self.is_cpp_api and not is_const:
            return

        loname = self.lo_name # strFunctions.list_of_name(self.child_name)
        # create comment parts
        params = []
        if self.is_cpp_api:
            title_line = 'Returns the {0} from this {1}.' \
                         ''.format(loname, self.object_name)
            return_lines = ['@return the {0} '
                            'from this {1}.'.format(loname, self.object_name)]
        else:
            title_line = 'Returns a ListOf_t * containing {0} objects ' \
                         'from this {1}.'.format(self.object_child_name,
                                                 self.object_name)
            params.append('@param {0} the {1} structure whose {2} is sought'
                          '.'.format(self.abbrev_parent, self.object_name,
                                     loname))
            return_lines = ['@return the {0} from this {1} as a '
                            'ListOf_t *.'.format(loname, self.object_name)]
        additional = ['@copydetails doc_returned_unowned_pointer']
        self.add_other_referenced_functions(additional, '', strFunctions.upper_first(self.used_child_name), self.object_child_name)


        # create the function declaration
        name_used = strFunctions.cap_list_of_name(self.used_child_name) # strFunctions.remove_prefix(loname)
        if self.is_cpp_api:
            function = 'get{0}'.format(name_used)
            arguments = []
            if is_const:
                return_type = 'const {0}*'.format(loname)
            else:
                return_type = '{0}*'.format(loname)
        else:
            function = '{0}_get{1}'.format(self.class_name, name_used)
            arguments = ['{0}* {1}'.format(self.object_name,
                                           self.abbrev_parent)]
            if global_variables.is_package:
                return_type = 'ListOf_t*'
            else:
                return_type = '{0}ListOf_t*'.format(global_variables.prefix)
        if self.is_cpp_api:
            implementation = ['return '
                              '&{0}'.format(self.class_object['memberName'])]
            code = [self.create_code_block('line', implementation)]
        else:
            implementation = ['return ({0} != NULL) ? {0}->get{1}() : '
                              'NULL'.format(self.abbrev_parent, name_used)]
            code = [self.create_code_block('line', implementation)]
        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': is_const,
                     'virtual': False,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # HELPER FUNCTIONS

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
