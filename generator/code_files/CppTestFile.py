#!/usr/bin/env python
#
# @file    CppTestFile.py
# @brief   class for generating example code file for the given package
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

from ..base_files import BaseCppFile
from . cpp_functions import *
from ..util import query, strFunctions, global_variables


class CppTestFile(BaseCppFile.BaseCppFile):
    """Class for all Cpp test files"""

    def __init__(self, pkg_object):
        self.name = 'test'
        self.brief_description = \
            'Implementation  of the example code for the {0} package' \
            '.'.format(pkg_object['name'])
        BaseCppFile.BaseCppFile.__init__(self, self.name, 'cpp',
                                         None)
        self.elements = pkg_object['baseElements']
        self.object_tree = query.create_object_tree(pkg_object)
        self.tests = []

    ########################################################################
    # Write parts of the file
    def write_includes(self):
        self.skip_line()
        self.write_line_verbatim('#include <iostream>')
        self.skip_line()
        self.write_line_verbatim('#include \"sbml/SBMLTypes.h\"')
        self.write_line_verbatim('#include \"sbml/packages/{0}/common/'
                                 '{1}Extension'
                                 'Types.h\"'.format(self.package,
                                                    self.package_up))

    def write_function(self, class_object):
        attrib_functions = GenericAttributeFunctions.GenericAttributeFunctions(self.language,
                                                                               self.is_cpp_api,
                                                                               self.is_list_of,
                                                                               class_object,
                                                                               writing_test = True)
        expand_attributes = self.expand_attributes(class_object['attribs'])
        attributes = query.sort_attributes(expand_attributes)
        bool_atts = attributes['bool_atts']
        int_atts = attributes['int_atts']
        double_atts = attributes['double_atts']
        uint_atts = attributes['uint_atts']
        string_atts = attributes['string_atts']

        if len(bool_atts) > 0:
            code = attrib_functions.write_test(bool_atts, 'bool')
            self.write_function_implementation(code, exclude=False, test=True)

        if len(int_atts) > 0:
            code = attrib_functions.write_test(int_atts, 'int')
            self.write_function_implementation(code, exclude=False, test=True)

        if len(double_atts) > 0:
            code = attrib_functions.write_test(double_atts, 'double')
            self.write_function_implementation(code, exclude=False, test=True)

        if len(uint_atts) > 0:
            code = attrib_functions.write_test(uint_atts, 'unsigned int')
            self.write_function_implementation(code, exclude=False, test=True)

        if len(string_atts) > 0:
            code = attrib_functions.write_test(string_atts, 'std::string')
            self.write_function_implementation(code, exclude=False, test=True)

        for t in attrib_functions.tests:
            self.tests.append(t)

    ########################################################################

    # Write file

    def write_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        for element in self.elements:
            self.write_function(element)
        self.skip_line(2)
        for t in self.tests:
            self.write_line('tcase_add_test(tcase, {0});'.format(t))



