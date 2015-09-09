#!/usr/bin/env python
#
# @file    ValidatorHeaderFile.py
# @brief   class for generating header file for the given class
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

from base_files import BaseCppFile
from util import strFunctions
from cpp_functions import *


class ValidatorHeaderFile(BaseCppFile.BaseCppFile):
    """Class for all Validator Header files"""

    def __init__(self, language, package, filetype='', valid_type=''):
        self.language = language
        self.cap_language = language.upper()

        self.up_package = strFunctions.upper_first(package)
        self.valid_type = strFunctions.upper_first(valid_type)
        self.file_type = filetype
        if filetype == 'main':
            self.name = '{}Validator'.format(self.up_package)
        elif filetype == 'consistency':
            self.name = '{}{}ConsistencyValidator'.format(self.up_package,
                                                          self.valid_type)
            self.baseClass = '{}Validator'.format(self.up_package)
            if valid_type == '':
                self.category = 'LIB{}_CAT_GENERAL_' \
                                'CONSISTENCY'.format(self.cap_language)
            else:
                self.category = 'LIB{}_CAT_IDENTIFIER_' \
                                'CONSISTENCY'.format(self.cap_language)

        self.brief_description = \
            'Definition of {}.'.format(self.name)

        BaseCppFile.BaseCppFile.__init__(self, self.name, 'h',
                                         None)
        self.package = package
        if filetype == 'consistency':
            self.baseClass = '{}Validator'.format(self.up_package)

    ########################################################################

    # Functions for writing the class
    def write_class(self, base_class, class_name):
        self.write_line('class {} : public {}'
                        .format(class_name, base_class))
        self.write_line('{')
        self.write_line('public:')
        self.skip_line()
        self.up_indent()
        if self.file_type == 'consistency':
            self.write_constructors()
            self.write_init_function()
        elif self.file_type == 'main':
            self.write_validator_class()
            self.down_indent()
            self.write_line('protected:')
            self.up_indent()
            self.write_doxygen_start()
            self.write_members()
            self.write_doxygen_end()
        self.down_indent()
        self.write_line('};\n')

    ########################################################################
    # Functions for writing specific includes

    def write_general_includes(self):
        self.write_line_verbatim('#include <{}/packages/{}/validator/{}'
                                 '.h>'.format(self.language, self.package,
                                              self.baseClass))

    def write_includes(self):
        self.write_line_verbatim('#include <{}/{}Error'
                                 '.h>'.format(self.language, self.cap_language))
        self.write_line_verbatim('#include <{}/validator/Validator'
                                 '.h>'.format(self.language))
        self.write_line_verbatim('#include <{}/{}Reader'
                                 '.h>'.format(self.language, self.cap_language))

    def write_forward_decls(self):
        self.write_line_verbatim('class VConstraint;')
        self.write_line_verbatim('struct {}Validator'
                                 'Constraints;'.format(self.up_package))
        self.write_line_verbatim('class {}Document;'.format(self.cap_language))

    def write_members(self):
        self.write_line('{0}ValidatorConstraints* m{0}'
                        'Constraints;'.format(self.up_package))
        self.skip_line()
        self.write_line('friend class {}Validating'
                        'Visitor;'.format(self.up_package))
    ########################################################################

    # function to write the constructors
    def write_constructors(self):
        args = [': {}Validator( {} )'.format(self.up_package, self.category)]
        implementation = [dict({'code_type': 'blank', 'code': []})]
        destruct = 'virtual ~{}'.format(self.name)
        self.write_class_function_header(self.name, [], '', False, args)
        self.write_implementation(implementation)
        self.skip_line(2)
        self.write_class_function_header(destruct, [], '', False, [])
        self.write_implementation(implementation)
        self.skip_line(2)

    ########################################################################

    # init function
    def write_init_function(self):
        code = dict({'title_line': 'Initializes this Validator with a '
                                   'set of Constraints',
                     'params': [],
                     'return_lines': [],
                     'additional': [],
                     'function': 'init',
                     'return_type': 'void',
                     'arguments': [],
                     'constant': False,
                     'virtual': True,
                     'object_name': '',
                     'implementation': [],
                     'args_no_defaults': [],
                     'constructor_args': []})
        self.write_function_declaration(code)

    ########################################################################

    # Write the validator class

    def write_validator_class(self):
        constructor = \
            ValidatorClassFunctions.ValidatorClassFunctions(self.language,
                                                            self.name,
                                                            is_header=True)
        code = constructor.write_constructor()
        self.write_function_declaration(code)

        code = constructor.write_destructor()
        self.write_function_declaration(code)

        code = constructor.write_init_function()
        self.write_function_declaration(code)

        code = constructor.write_add_constraint_function()
        self.write_function_declaration(code)

        code = constructor.write_validate_function('doc')
        self.write_function_declaration(code)

        code = constructor.write_validate_function('file')
        self.write_function_declaration(code)

    ########################################################################

    # Functions for writing definition declaration

    def write_defn_begin(self):
        self.skip_line(2)
        self.write_line('#ifndef {0}_H__'.format(self.name))
        self.write_line('#define {0}_H__'.format(self.name))
        self.skip_line(2)

    def write_defn_end(self):
        self.skip_line(2)
        self.write_line('#endif  /*  !{0}_H__  */'.format(self.name))
        self.skip_line(2)

    ########################################################################

    # Write file

    def write_file(self):
        self.write_doxygen_start()
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_defn_begin()
        self.write_cpp_begin()
        if self.file_type == 'consistency':
            self.write_general_includes()
        self.write_cppns_begin()
        if self.file_type == 'consistency':
            self.write_class(self.baseClass, self.name)
        self.write_cppns_end()
        self.write_cpp_end()
        self.write_defn_end()
        self.write_doxygen_end()

    # Write the main validator file
    def write_main_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_defn_begin()
        self.write_cpp_begin()
        self.write_doxygen_start()
        self.write_line_verbatim('#include <list>')
        self.write_line_verbatim('#include <string>')
        self.write_doxygen_end()
        self.write_includes()
        self.write_cppns_begin()
        self.write_forward_decls()
        self.skip_line(2)
        validator = '{}Validator'.format(self.up_package)
        self.write_class('Validator', validator)
        self.write_cppns_end()
        self.write_cpp_end()
        self.write_defn_end()

    # # Write the extension types file
    # def write_fwd_file(self):
    #     BaseCppFile.BaseCppFile.write_file(self)
    #     self.write_defn_begin()
    #     self.write_class_or_struct()
    #     self.write_cppns_begin()
    #     self.write_classes()
    #     self.write_cppns_end()
    #     self.write_end_class_or_struct()
    #     self.write_defn_end()
