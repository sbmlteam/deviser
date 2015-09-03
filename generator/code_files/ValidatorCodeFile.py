#!/usr/bin/env python
#
# @file    ValidatorCodeFile.py
# @brief   class for generating code file for the given class
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


class ValidatorCodeFile(BaseCppFile.BaseCppFile):
    """Class for all Validator Header files"""

    def __init__(self, language, package, filetype='', valid_type=''):
        self.up_package = strFunctions.upper_first(package)
        self.valid_type = strFunctions.upper_first(valid_type)

        if filetype == 'constraints':
            self.name = '{}{}ConsistencyConstraints'.format(self.up_package,
                                                            self.valid_type)
        elif filetype == 'consistency':
            self.name = '{}{}ConsistencyValidator'.format(self.up_package,
                                                          self.valid_type)
            self.baseClass = '{}Validator'.format(self.up_package)
        elif filetype == 'declared':
            self.name = '{}{}ConsistencyConstraints' \
                        'Declared'.format(self.up_package,
                                          self.valid_type)

        self.brief_description = \
            'Definition of {}.'.format(self.name)

        if filetype == 'declared':
            BaseCppFile.BaseCppFile.__init__(self, self.name, 'cxx', None)
        else:
            BaseCppFile.BaseCppFile.__init__(self, self.name, 'cpp', None)

        self.language = language
        self.package = package

    ########################################################################

    # Functions for writing the class
    def write_class(self):
        self.write_init_function()

    ########################################################################
    # Functions for writing specific includes

    def write_general_includes(self):
        self.write_line_verbatim('#include <{}/packages/{}/validator/{}'
                                 '.h>'.format(self.language, self.package,
                                              self.name))
        self.skip_line()
        self.open_comment()
        self.write_comment_line('Compile {}Consistency'
                                'Constraints'.format(self.valid_type))
        self.close_comment()
        self.write_line_verbatim('#include \"constraints/{}{}Consistency'
                                 'Constraints.cpp\"'.format(self.up_package,
                                                            self.valid_type))

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
        self.write_line('{}{}ConsistencyValidator::'
                        'init()'.format(self.up_package, self.valid_type))
        self.write_line('{')
        self.write_line_verbatim('#define  AddingConstraintsToValidator 1')
        self.write_line_verbatim('#include \"constraints/{}{}Consistency'
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
        self.write_line_verbatim('#include <{}/validator/VConstraint'
                                 '.h>'.format(self.language))
        self.skip_line()
        self.write_line_verbatim('#include <{}/packages/{}/validator/{}{}Error'
                                 '.h>'.format(self.language, self.package,
                                              self.up_package,
                                              self.cap_language))
        self.skip_line()
        self.write_line_verbatim('#endif /* AddingConstraintsToValidator')
        self.skip_line()
        self.write_line_verbatim('#include <{}/validator/ConstraintMacros'
                                 '.h>'.format(self.language))
        self.skip_line()
        self.write_line_verbatim('using namespace std;')
        self.skip_line()
        self.open_comment()
        self.write_comment_line('PUT CONSTRAINTS HERE')
        self.close_comment()
        self.skip_line()
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
