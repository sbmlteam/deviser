#!/usr/bin/env python
#
# @file    ValidatorCodeFile.py
# @brief   class for generating code file for the given class
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

from .cpp_functions import *
from ..base_files import BaseCppFile
from ..util import strFunctions, global_variables


class ValidatorCodeFile(BaseCppFile.BaseCppFile):
    """Class for all Validator Header files"""

    def __init__(self, language, package, filetype='', valid_type='',
                 elements=None):
        self.up_package = strFunctions.upper_first(package)
        self.valid_type = strFunctions.upper_first(valid_type)
        self.file_type = filetype
        if filetype == 'main':
            self.name = '{0}Validator'.format(self.up_package)
        elif filetype == 'constraints':
            self.name = '{0}{1}ConsistencyConstraints'.format(self.up_package,
                                                              self.valid_type)
        elif filetype == 'consistency':
            self.name = '{0}{1}ConsistencyValidator'.format(self.up_package,
                                                            self.valid_type)
            self.baseClass = '{0}Validator'.format(self.up_package)
        elif filetype == 'declared':
            self.name = '{0}{1}ConsistencyConstraints' \
                        'Declared'.format(self.up_package,
                                          self.valid_type)

        self.brief_description = \
            'Definition of {0}.'.format(self.name)

        if filetype == 'declared':
            BaseCppFile.BaseCppFile.__init__(self, self.name, 'cxx', None)
        else:
            BaseCppFile.BaseCppFile.__init__(self, self.name, 'cpp', None)

        self.language = language
        self.package = package
        if filetype == 'consistency':
            self.baseClass = '{0}Validator'.format(self.up_package)
        self.elements = elements

    ########################################################################

    # Functions for writing the class
    def write_class(self):
        if self.file_type == 'consistency':
            self.write_init_function()
        elif self.file_type == 'main':
            self.write_validator_class()

    ########################################################################
    # Functions for writing specific includes

    def write_general_includes(self):
        self.write_line_verbatim('#include <{0}/packages/{1}/validator/{2}'
                                 '.h>'.format(self.language, self.package,
                                              self.name))
        self.skip_line()
        self.open_comment()
        self.write_comment_line('Compile {0}Consistency'
                                'Constraints'.format(self.valid_type))
        self.close_comment()
        self.write_line_verbatim('#include \"constraints/{0}{1}Consistency'
                                 'Constraints.cpp\"'.format(self.up_package,
                                                            self.valid_type))

    def write_validator_includes(self):
        self.skip_line()
        self.write_line_verbatim('#include <{0}/validator/VConstraint'
                                 '.h>'.format(self.language))
        self.skip_line()
        self.write_line_verbatim('#include <{0}/packages/{1}/common/{2}'
                                 'ExtensionTypes.h>'.format(self.language,
                                                            self.package,
                                                            self.up_package))
        self.write_line_verbatim('#include <{0}/packages/{1}/validator/{2}'
                                 '.h>'.format(self.language, self.package,
                                              self.name))

    ########################################################################

    # init function
    def write_init_function(self):
        # these dont fit the standard writing function
        # so do line by line
        self.open_comment()
        self.write_comment_line('Initializes this Validator with a '
                                'set of Constraints')
        self.close_comment()
        self.write_line('void')
        self.write_line('{0}{1}ConsistencyValidator::'
                        'init()'.format(self.up_package, self.valid_type))
        self.write_line('{')
        self.write_line_verbatim('#define  AddingConstraintsToValidator 1')
        self.write_line_verbatim('#include \"constraints/{0}{1}Consistency'
                                 'ConstraintsDeclared'
                                 '.cxx\"'.format(self.up_package,
                                                 self.valid_type))
        self.write_line('}')
        self.skip_line(2)

    ########################################################################

    # constraints file
    def write_constraint_header(self):
        self.write_line_verbatim('#ifndef AddingConstraintsToValidator')
        self.skip_line()
        self.write_line_verbatim('#include <{0}/validator/VConstraint'
                                 '.h>'.format(self.language))
        self.skip_line()
        self.write_line_verbatim('#include <{0}/packages/{1}/validator/{2}{3}'
                                 'Error'
                                 '.h>'.format(self.language, self.package,
                                              self.up_package,
                                              self.cap_language))
        self.skip_line()
        self.write_line_verbatim('#endif /* AddingConstraintsToValidator */')
        self.skip_line()
        self.write_line_verbatim('#include <{0}/validator/ConstraintMacros'
                                 '.h>'.format(self.language))
        self.skip_line()
        self.write_line_verbatim('using namespace std;')
        self.skip_line()
        self.open_comment()
        self.write_comment_line('PUT CONSTRAINTS HERE')
        self.close_comment()
        self.skip_line()
    ########################################################################

    # Write the validator class

    def write_validator_class(self):
        constructor = \
            ValidatorClassFunctions.ValidatorClassFunctions(self.language,
                                                            self.name,
                                                            False, None,
                                                            self.package)
        self.write_comments(['-------------------------------------------',
                             '{0}Validator'.format(self.up_package),
                             '-------------------------------------------'])
        self.skip_line()
        code = constructor.write_constructor()
        self.write_function_implementation(code)

        code = constructor.write_destructor()
        self.write_function_implementation(code)

        code = constructor.write_add_constraint_function()
        self.write_function_implementation(code)

        code = constructor.write_validate_function('doc')
        self.write_function_implementation(code)

        code = constructor.write_validate_function('file')
        self.write_function_implementation(code)

    ########################################################################

    # Write the validator class

    def write_generic_constraint_structure(self):
        constructor = \
            ValidatorClassFunctions.ValidatorClassFunctions(self.language,
                                                            self.name,
                                                            is_header=False)

        self.write_comments(['-------------------------------------------',
                             'Apply<T>',
                             '-------------------------------------------'])
        self.open_comment()
        self.write_comment_line('Applies a Constraint<T> to an {0} object of '
                                'type T.'.format(self.cap_language))
        self.close_comment()
        self.skip_line()
        self.write_line('template <typename T>')
        self.write_line('struct Apply : public unary_function<TConstraint<T>*, '
                        'void>')
        self.write_line('{')
        self.up_indent()

        code = constructor.write_apply_function()
        self.write_inline_function_implementation(code)

        code = constructor.write_operator_function()
        self.write_inline_function_implementation(code)
                                                  
        self.write_line('const Model& model;')
        self.write_line('const T&     object;')
        self.down_indent()
        self.write_line('};')
        self.skip_line(2)

    ########################################################################

    # Write the validator class

    def write_constraint_set_class(self):
        constructor = \
            ValidatorClassFunctions.ValidatorClassFunctions(self.language,
                                                            self.name,
                                                            is_header=False)
        self.write_comments(['-------------------------------------------',
                             'ConstraintSet<T>',
                             '-------------------------------------------'])
        self.write_line('template <typename T>')
        self.write_line('class ConstraintSet')
        self.write_line('{')
        self.write_line('public:')
        self.up_indent()
        self.skip_line()
        self.write_line('ConstraintSet() { }')
        self.write_line('~ConstraintSet() { }')
        self.skip_line(2)

        code = constructor.write_constraint_add_function()
        self.write_inline_function_implementation(code)

        code = constructor.write_apply_to_function()
        self.write_inline_function_implementation(code)

        code = constructor.write_empty_function()
        self.write_inline_function_implementation(code)

        self.down_indent()
        self.write_line('protected:')
        self.up_indent()
        self.skip_line()
        self.write_line('std::list< TConstraint<T>* > constraints;')
        self.down_indent()
        self.write_line('};')
        self.skip_line(2)

    ########################################################################

    # Write the validator class

    def write_specific_constraint_structure(self):
        name = '{0}Constraints'.format(self.name)
        constructor = \
            ValidatorClassFunctions.ValidatorClassFunctions(self.language,
                                                            name,
                                                            False,
                                                            self.elements)
        self.write_comments(['-------------------------------------------',
                             'ValidatorConstraints',
                             '-------------------------------------------'])
        self.write_line('struct {0}ValidatorConstraints'
                        ''.format(self.up_package))
        self.write_line('{')
        self.up_indent()
        self.skip_line()
        self.write_constraint_set_member(
            '{0}'.format(global_variables.document_class))
        self.write_constraint_set_member('Model')
        if self.elements:
            for element in self.elements:
                self.write_constraint_set_member(element['name'])
        self.skip_line()
        self.write_line('map<VConstraint*, bool> ptrMap;')
        self.skip_line()
        self.write_line('~{0}ValidatorConstraints();'.format(self.up_package))
        self.skip_line()
        self.write_line('void add(VConstraint* c);')
        self.skip_line()
        self.down_indent()
        self.write_line('};')
        self.skip_line(2)
        code = constructor.write_destructor(constraints=True)
        self.write_function_implementation(code)
        code = constructor.write_v_constraint_add_function()
        self.write_function_implementation(code)

    # function to write spaced sets of data
    def write_constraint_set_member(self, class_name):
        constraint = 'ConstraintSet<{0}>'.format(class_name)
        self.write_spaced_line('{0:{width}} m{1};'.format(constraint,
                                                          class_name,
                                                          width=45))
    ########################################################################

    # Write the validator class

    def write_validating_visitor_class(self):
        name = '{0}ValidatingVisitor'.format(self.up_package)
        constructor = \
            ValidatorClassFunctions.ValidatorClassFunctions(self.language,
                                                            name,
                                                            False,
                                                            self.elements,
                                                            self.package,
                                                            self.std_base)

        self.write_comments(['-------------------------------------------',
                             'ValidatingVisitor',
                             '-------------------------------------------'])
        self.skip_line()
        self.write_line('class {0}: public {1}Visitor'
                        ''.format(name, self.cap_language))
        self.write_line('{')
        self.write_line('public:')
        self.up_indent()
        self.skip_line()
        code = constructor.write_constructor('visitor')
        self.write_inline_function_implementation(code)
        self.write_line('using {0}Visitor::visit;'.format(self.cap_language))
        self.skip_line()
        for element in self.elements:
            code = constructor.write_visit_function(element['name'])
            self.write_inline_function_implementation(code)
        code = constructor.write_visit_base_function()
        self.write_inline_function_implementation(code)
        self.down_indent()
        self.write_line('protected:')
        self.up_indent()
        self.skip_line()
        self.write_line('{0}Validator& v;'.format(self.up_package))
        self.write_line('const Model& m;')
        self.down_indent()
        self.write_line('};')
        self.skip_line(2)

    ########################################################################

    # Functions for writing definition declaration

    def write_if_doxygen_begin(self):
        self.skip_line()
        self.write_line('#ifndef doxygen_ignore')
        self.skip_line()

    def write_if_doxygen_end(self):
        self.skip_line()
        self.write_line('#endif  /*  doxygen_ignore  */')
        self.skip_line()

    ########################################################################

    # Write file

    def write_file(self):
        self.write_doxygen_start()
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_if_doxygen_begin()
        self.write_general_includes()
        self.write_cppns_begin()
        self.write_class()
        self.write_cppns_end()
        self.write_if_doxygen_end()
        self.write_doxygen_end()

    # Write the constraints types file
    def write_constraints_file(self, valid_type=''):
        self.write_doxygen_start()
        BaseCppFile.BaseCppFile.write_file(self)
        if not valid_type == 'declared':
            self.write_constraint_header()
        self.write_doxygen_end()

    # Write the main validator file
    def write_main_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_validator_includes()
        self.write_doxygen_start()
        self.write_line('using namespace std;')
        self.write_doxygen_end()
        self.write_cppns_begin()
        self.write_cpp_begin()
        self.write_generic_constraint_structure()
        self.write_constraint_set_class()
        self.write_specific_constraint_structure()
        self.write_validating_visitor_class()
        self.write_validator_class()
        self.write_cpp_end()
        self.write_cppns_end()
