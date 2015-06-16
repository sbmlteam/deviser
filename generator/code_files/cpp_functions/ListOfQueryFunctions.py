#!/usr/bin/env python
#
# @file    ListOfQueryFunctions.py
# @brief   class to create functions to query a ListOf element
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


class ListOfQueryFunctions():
    """Class for all functions for ListOf classes"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object):
        self.language = language
        self.is_cpp_api = is_cpp_api
        self.is_list_of = is_list_of
        self.class_object = class_object
        if is_list_of:
            self.child_name = class_object['lo_child']
            self.class_name = class_object['name']
        else:
            self.child_name = strFunctions.upper_first(class_object['element'])
            self.class_name = class_object['parent']['name']
        if is_cpp_api:
            self.object_name = self.class_name
            self.object_child_name = self.child_name
        else:
            if is_list_of:
                self.object_name = 'ListOf_t'
            else:
                self.object_name = self.class_name + '_t'
            self.object_child_name = self.child_name + '_t'
        self.concretes = []
        if 'concretes' in class_object:
            self.concretes = class_object['concretes']

        self.used_sidrefs = []

        # useful variables
        if not self.is_cpp_api and self.is_list_of:
            self.struct_name = self.object_child_name
        else:
            self.struct_name = self.object_name
        self.plural = strFunctions.plural(self.child_name)
        self.indef_name = strFunctions.get_indefinite(self.object_child_name)
        self.abbrev_parent = strFunctions.abbrev_name(self.object_name)
        self.abbrev_child = strFunctions.abbrev_name(self.child_name)
    ########################################################################

    # Functions for writing get element functions

    # function to write get by index from a listOf
    def write_get_element_by_index(self, is_const):
        # c api does not need a non constant version
        if not self.is_cpp_api and not is_const:
            return

        # useful variables
        virtual = True if self.is_list_of else False
        # create comment parts
        title_line = 'Get {} {} from the {}.'.format(self.indef_name,
                                                     self.object_child_name,
                                                     self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param n, an unsigned int representing the index '
                      'of the {} to retrieve.'.format(self.object_child_name))
        return_lines = ['@return the nth {} in this {}.'.format(
            self.object_child_name, self.object_name)]
        additional = []
        if self.is_cpp_api:
            additional = ['@see size()'] if self.is_list_of \
                else ['@see getNum{}'.format(self.plural)]

        # create the function declaration
        arguments = []
        if self.is_cpp_api:
            function = 'get' if self.is_list_of else 'get{}'\
                .format(self.object_child_name)
        else:
            function = '{}_get{}'.format(self.class_name, self.child_name)
            arguments.append('{}* {}'.format(self.object_name,
                                             self.abbrev_parent))
        arguments.append('unsigned int n')
        if is_const:
            return_type = 'const {}*'.format(self.object_child_name)
        else:
            return_type = '{}*'.format(self.object_child_name)

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
                     'object_name': self.struct_name})

    # function to write get by id from a listOf
    def write_get_element_by_id(self, is_const):
        # c api does not need a non constant version
        if not self.is_cpp_api and not is_const:
            return

        # useful variables
        virtual = True if self.is_list_of else False

        # create comment
        title_line = 'Get {} {} from the {} based on its identifier.'\
            .format(self.indef_name, self.object_child_name, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param sid a string representing the identifier '
                      'of the {} to retrieve.'.format(self.object_child_name))
        return_lines = ['@return the {0} in this {1} based on the '
                        'identifier or NULL if no such {0} exists.'
                        .format(self.object_child_name, self.object_name)]
        additional = []
        if self.is_cpp_api:
            additional = ['@see size()'] if self.is_list_of \
                else ['@see getNum{}'.format(self.plural)]

        # create function declaration
        if self.is_cpp_api:
            function = 'get' if self.is_list_of \
                else 'get{}'.format(self.object_child_name)
            arguments = ['const std::string& sid']
        else:
            function = '{}_getById'.format(self.class_name) if self.is_list_of \
                else '{}_get{}ById'.format(self.class_name, self.child_name)
            arguments = ['{}* {}'.format(self.object_name, self.abbrev_parent),
                         'const char *sid']
        if is_const:
            return_type = 'const {}*'.format(self.object_child_name)
        else:
            return_type = '{}*'.format(self.object_child_name)

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
                     'object_name': self.struct_name})

    # function to write get by sidref from a listOf
    def write_get_element_by_sidref(self, sid_ref, const):
        # c api does not need a non constant version
        if not self.is_cpp_api and not const:
            return

        # useful variables
        element = sid_ref['element']
        att_name = sid_ref['name']
        match = [element, const]
        if match in self.used_sidrefs:
            return
        else:
            self.used_sidrefs.append(match)

        # create comment
        title_line = 'Get {} {} from the {} based on the {} to which ' \
                     'it refers.'.format(self.indef_name,
                                         self.object_child_name,
                                         self.object_name,
                                         element)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param sid a string representing the {} attribute '
                      'of the {} object to '
                      'retrieve.'.format(att_name, self.object_child_name))
        return_lines = ['@return the first {0} in this {1} based on the '
                        'given {2} attribute or NULL if no such {0} exists.'
                        .format(self.object_child_name, self.object_name,
                                att_name)]
        additional = []

        # create function declaration
        if self.is_cpp_api:
            if self.is_list_of:
                function = 'getBy{}'.format(element)
            else:
                function = 'get{}By{}'.format(self.object_child_name, element)
            arguments = ['const std::string& sid']
        else:
            function = '{}_get{}By{}'.format(self.class_name,
                                             self.child_name, element)
            arguments = ['{}* {}'.format(self.object_name, self.abbrev_parent),
                         'const char *sid']
        if const:
            return_type = 'const {}*'.format(self.object_child_name)
        else:
            return_type = '{}*'.format(self.object_child_name)

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

    ########################################################################

    # Functions for writing remove element functions

    # function to write remove by index from a listOf
    def write_remove_element_by_index(self):
        # useful variables
        virtual = True if self.is_list_of else False

        # create comment parts
        title_line = 'Removes the nth {} from this {} and returns a ' \
                     'pointer to it.'.format(self.object_child_name,
                                             self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param n, an unsigned int representing the index of '
                      'the {} to remove.'.format(self.object_child_name))
        return_lines = ['@return a pointer to the nth {} in this {}.'.format(
            self.object_child_name, self.object_name)]
        additional = []
        if self.is_cpp_api:
            additional = ['@see size()'] if self.is_list_of \
                else ['@see getNum{}'.format(self.plural)]
            additional.append(' ')
            additional.append('@note the caller owns the returned object and '
                              'is responsible for deleting it.')
        # create the function declaration
        arguments = []
        if self.is_cpp_api:
            function = 'remove' if self.is_list_of \
                else 'remove{}'.format(self.object_child_name)
        else:
            if self.is_list_of:
                function = '{}_remove'.format(self.class_name)
            else:
                function = '{}_remove{}'.format(self.class_name,
                                                self.child_name)

            arguments.append('{}* {}'.format(self.object_name,
                                             self.abbrev_parent))
        arguments.append('unsigned int n')
        return_type = '{}*'.format(self.object_child_name)

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
                     'object_name': self.struct_name})

    # function to write remove by id from a listOf
    def write_remove_element_by_id(self):
        # useful variables
        virtual = True if self.is_list_of else False

        # create comment parts
        title_line = 'Removes the {} from this {} based on its identifier and ' \
                     'returns a pointer to it.'.format(self.object_child_name,
                                                       self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'
                          .format(self.abbrev_parent, self.object_name))
        params.append('@param sid, a string representing the identifier of '
                      'the {} to remove.'.format(self.object_child_name))
        return_lines = ['@return the {0} in this {1} based on the identifier '
                        'or NULL if no such {0} '
                        'exists.'.format(self.object_child_name,
                                         self.object_name)]
        additional = []
        if self.is_cpp_api:
            additional.append('@note the caller owns the returned object and '
                              'is responsible for deleting it.')
        # create the function declaration
        arguments = []
        if self.is_cpp_api:
            function = 'remove' if self.is_list_of \
                else 'remove{}'.format(self.object_child_name)
            arguments = ['const std::string& sid']
        else:
            if self.is_list_of:
                function = '{}_removeById'.format(self.class_name)
            else:
                function = '{}_remove{}ById'.format(self.class_name,
                                                    self.child_name)
            arguments.append('{}* {}'.format(self.object_name,
                                             self.abbrev_parent))
            arguments.append('const char* sid')
        return_type = '{}*'.format(self.object_child_name)

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
                     'object_name': self.struct_name})

    ########################################################################

    # Functions for writing add and create element functions

    # function to write add element
    def write_add_element_function(self):
        # create comment parts
        title_line = 'Adds a copy of the given {} to this {}.'.format(
            self.object_child_name, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to which the {} '
                          'should be added.'.format(self.abbrev_parent,
                                                    self.object_name,
                                                    self.object_child_name))
        params.append('@param {}, the {} object to '
                      'add.'.format(self.abbrev_child, self.object_child_name))
        return_lines = ['@copydetails doc_returns_success_code',
                        '@li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, '
                        'OperationReturnValues_t}',
                        '@li @sbmlconstant{LIBSBML_OPERATION_FAILED,'
                        ' OperationReturnValues_t}']
        additional = []
        if self.is_cpp_api:
            additional.append('@copydetails doc_note_object_is_copied')
            additional.append(' ')
            additional.append('@see create{}()'.format(self.object_child_name))
        # create the function declaration
        arguments = []
        if self.is_cpp_api:
            function = 'add{}'.format(self.object_child_name)
        else:
            function = '{}_add{}'.format(self.class_name, self.child_name)
            arguments.append('{}* {}'.format(self.object_name,
                                             self.abbrev_parent))
        arguments.append('const {}* {}'.format(self.object_child_name,
                                               self.abbrev_child))
        return_type = 'int'

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

    # function to write create element
    def write_create_element_function(self, index=0):
        if len(self.concretes) == 0 and index == 0:
            child = self.object_child_name
        else:
            if index == 0:
                return
            else:
                i = index - 1
            child = self.concretes[i]['element']
        # create comment parts
        title_line = 'Creates a new {0} object, adds it to this {1} object ' \
                     'and returns the {0} object ' \
                     'created.'.format(child, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure '
                          'to which the {} should be '
                          'added.'.format(self.abbrev_parent, self.object_name,
                                          self.object_child_name))
        return_lines = ['@return a new {} object '
                        'instance.'.format(child)]
        additional = []
        if self.is_cpp_api:
            additional.append('@see add{0}(const {0}* {1})'
                              .format(self.object_child_name,
                                      self.abbrev_child))
        # create the function declaration
        arguments = []
        if self.is_cpp_api:
            function = 'create{}'.format(child)
        else:
            function = '{}_create{}'.format(self.class_name, self.child_name)
            arguments.append('{}* {}'.format(self.object_name,
                                             self.abbrev_parent))
        return_type = '{}*'.format(child)

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

    # Functions for writing get num element functions

    # function to write get num
    def write_get_num_element_function(self):
        # create comment parts
        title_line = 'Get the number of {} objects in ' \
                     'this {}.'.format(self.object_child_name, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to query.'
                          .format(self.abbrev_parent, self.object_name))
        return_lines = ['@return the number of {} objects in '
                        'this {}.'.format(self.object_child_name,
                                          self.object_name)]
        additional = []

        # create the function declaration
        arguments = []
        if self.is_cpp_api:
            function = 'getNum{}'.format(self.plural)
        else:
            function = '{}_getNum{}'.format(self.class_name, self.plural)
            arguments.append('{}* {}'.format(self.object_name,
                                             self.abbrev_parent))
        return_type = 'unsigned int'

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

    # Functions for writing getListOf

    # function to write get num
    def write_get_list_of_function(self, is_const=False):
        if not self.is_cpp_api and not is_const:
            return

        loname = strFunctions.list_of_name(self.child_name)
        # create comment parts
        params = []
        if self.is_cpp_api:
            title_line = 'Returns the {} from this {}.'.format(loname,
                                                               self.object_name)
            return_lines = ['@return the {} '
                            'from this {}.'.format(loname, self.object_name)]
        else:
            title_line = 'Returns a ListOf_t* containing {} objects ' \
                         'from this {}.'.format(self.object_child_name,
                                                self.object_name)
            params.append('@param {} the {} structure whose \"{}\" is sought.'
                          .format(self.abbrev_parent, self.object_name, loname))
            return_lines = ['@return the \"{}\" from this {} as a '
                            'ListOf_t *.'.format(loname, self.object_name)]
        additional = []

        # create the function declaration
        if self.is_cpp_api:
            function = 'get{}'.format(loname)
            arguments = []
            if is_const:
                return_type = 'const {}*'.format(loname)
            else:
                return_type = '{}*'.format(loname)
        else:
            function = '{}_get{}'.format(self.class_name, loname)
            arguments = ['const {}* {}'.format(self.object_name,
                                               self.abbrev_parent)]
            return_type = 'ListOf_t*'

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
                     'object_name': self.struct_name})
