#!/usr/bin/env python
#
# @file    ConcreteClassFunctions.py
# @brief   class to create functions for concrete classes
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


class ConcreteClassFunctions():
    """Class for all protected functions"""

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

        self.concretes = class_object['concretes']

        # useful variables
        if not self.is_cpp_api and self.is_list_of:
            self.struct_name = self.object_child_name
        else:
            self.struct_name = self.object_name
        self.plural = strFunctions.plural(self.child_name)
        self.indef_name = strFunctions.get_indefinite(self.object_child_name)
        self.abbrev_parent = strFunctions.abbrev_name(self.object_name)
        self.abbrev_child = strFunctions.abbrev_name(self.child_name)
        if self.is_cpp_api is False:
            self.true = '@c 1'
            self.false = '@c 0'
        else:
            self.true = '@c true'
            self.false = '@c false'

    ########################################################################

    # Function for writing isFoo functions

    def write_is_foo(self, index):
        # not applicable to list_of
        if self.is_list_of:
            return
        if self.is_cpp_api:
            name = 'abstract \"{}\"'.format(self.object_name)
            conc_type = self.concretes[index]['element']
            conc_name = self.concretes[index]['element']
        else:
            name = '{}'.format(self.object_name)
            conc_type = self.concretes[index]['element'] + '_t'
            conc_name = self.concretes[index]['element']

        # create comment parts
        title_line = 'Predicate returning {} if this {} is of type {}'\
            .format(self.true, name, conc_type)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(self.abbrev_parent, self.object_name))
        return_lines = ['@return {} if this {} is of type {}, {} '
                        'otherwise'.format(self.true, name, conc_type,
                                           self.false)]
        additional = []

        # create the function declaration
        if self.is_cpp_api:
            function = 'is{}'.format(conc_name)
            return_type = 'bool'
            arguments = []
        else:
            function = '{}_is{}'.format(self.class_name, conc_name)
            return_type = 'int'
            arguments = ['const {0} * '
                         '{1}'.format(self.object_name, self.abbrev_parent)]
        if self.is_cpp_api:
            line = ['return dynamic_cast<const {}*>(this) != '
                    'NULL'.format(conc_name)]
        else:
            line = ['return ({0} != NULL) ? static_cast<int>({0}'
                    '->is{1}()) : 0'.format(self.abbrev_parent, conc_name)]
        code = [self.create_code_block('line', line)]

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

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
