#!/usr/bin/env python
#
# @file    CppExampleFile.py
# @brief   class for generating example code file for the given package
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2015 by the California Institute of Technology
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

from util import query, strFunctions, global_variables


class CppExampleFile(BaseCppFile.BaseCppFile):
    """Class for all Cpp Example files"""

    def __init__(self, pkg_object):
        self.name = '{0}_example1'.format(pkg_object['name'])
        self.brief_description = \
            'Implementation  of the example code for the {0} package' \
            '.'.format(pkg_object['name'])
        BaseCppFile.BaseCppFile.__init__(self, self.name, 'cpp',
                                         None)
        self.package = strFunctions.lower_first(pkg_object['name'])
        self.package_up = strFunctions.upper_first(pkg_object['name'])
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

    def write_function(self):
        implementation = ['i am a line']
        code = [dict({'code_type': 'line', 'code': implementation})]

        return dict({'title_line': self.name,
                     'params': ['int argc', 'char** argv'],
                     'return_lines': [],
                     'additional': [],
                     'function': 'main',
                     'return_type': 'int',
                     'arguments': ['int argc', 'char** argv'],
                     'constant': False,
                     'virtual': False,
                     'object_name': None,
                     'implementation': code})



    ########################################################################

    # Write file

    def write_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_includes()
        self.write_cppns_use()
        code = self.write_function()
        self.write_function_implementation(code)
