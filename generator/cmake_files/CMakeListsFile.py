#!/usr/bin/env python
#
# @file    CMakeListsFile.py
# @brief   class for generating cmake lists file
# @author  Frank Bergmann
# @author  Sarah Keating
# @author  Matthew S. Gillman
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

from ..base_files import BaseTxtFile
from ..util import strFunctions, global_variables


class CMakeListsFile():
    """Class for CMake package files"""

    def __init__(self, name, package):

        self.package = package.lower()
        self.fileout = BaseTxtFile.BaseTxtFile(name)

        self.fileout.brief_description = \
            'CMake build scripts for example programs'

        self.cap_package = self.package.upper()
        self.up_package = strFunctions.upper_first(self.package)

        self.language = global_variables.language
        self.cap_language = global_variables.language.upper()

        self.open_br = '{'
        self.close_br = '}'

    ########################################################################

    # Write specific code
    def write_examples(self):
        fout = self.fileout

        fout.skip_line()
        fout.write_line('include_directories'
                        '(${0}CMAKE_CURRENT_SOURCE_DIR{1})'.
                        format(self.open_br, self.close_br))
        fout.write_line('include_directories'
                        '(BEFORE ${0}LIBSBML_ROOT_SOURCE_DIR{1}/src)'.
                        format(self.open_br, self.close_br))
        fout.write_line('include_directories'
                        '(${0}LIBSBML_ROOT_SOURCE_DIR{1}/include)'.
                        format(self.open_br, self.close_br))
        fout.write_line('include_directories'
                        '(BEFORE ${0}LIBSBML_ROOT_BINARY_DIR{1}/src)'.
                        format(self.open_br, self.close_br))
        fout.skip_line()
        fout.write_line('if (EXTRA_INCLUDE_DIRS)')
        fout.write_line('include_directories(${0}EXTRA_INCLUDE_DIRS{1})'.
                        format(self.open_br, self.close_br))
        fout.write_line('endif (EXTRA_INCLUDE_DIRS)')
        fout.skip_line()
        fout.write_line('foreach (example')
        fout.up_indent()
        fout.skip_line()
        fout.write_line('{0}_example1'.format(self.package))
        fout.skip_line()
        fout.down_indent()
        fout.write_line(')')
        fout.up_indent()
        fout.write_line_verbatim(('add_executable'
                                  '(example_{2}_cpp_${0}example{1}'
                                  ' ${0}example{1}.cpp ../util.c)')
                                 .format(self.open_br,
                                         self.close_br,
                                         self.package))
        fout.write_line_verbatim(('set_target_properties'
                                  '(example_{2}_cpp_${0}example{1} '
                                  'PROPERTIES OUTPUT_NAME '
                                  '${0}example{1})').
                                 format(self.open_br,
                                        self.close_br,
                                        self.package))
        fout.write_line_verbatim(('target_link_libraries'
                                  '(example_{2}_cpp_${0}example{1} '
                                  '${0}LIBSBML_LIBRARY{1}-static)').
                                 format(self.open_br,
                                        self.close_br,
                                        self.package))
        fout.skip_line()
        fout.write_line('if (WITH_LIBXML)')
        fout.up_indent()
        fout.write_line_verbatim(('target_link_libraries'
                                  '(example_{2}_cpp_${0}example{1}'
                                  ' ${0}LIBXML_LIBRARY{1} '
                                  '${0}EXTRA_LIBS{1})').
                                 format(self.open_br,
                                        self.close_br,
                                        self.package))
        fout.down_indent()
        fout.write_line('endif(WITH_LIBXML)')
        fout.skip_line()
        fout.write_line('if (WITH_ZLIB)')
        fout.up_indent()
        fout.write_line_verbatim(('target_link_libraries'
                                  '(example_{2}_cpp_${0}example{1}'
                                  ' ${0}LIBZ_LIBRARY{1})').
                                 format(self.open_br,
                                        self.close_br,
                                        self.package))
        fout.down_indent()
        fout.write_line('endif(WITH_ZLIB)')
        fout.skip_line()
        fout.write_line('if (WITH_BZIP2)')
        fout.up_indent()
        fout.write_line_verbatim(('target_link_libraries'
                                  '(example_{2}_cpp_${0}example{1}'
                                  ' ${0}LIBBZ_LIBRARY{1})').
                                 format(self.open_br,
                                        self.close_br,
                                        self.package))
        fout.down_indent()
        fout.write_line('endif(WITH_BZIP2)')
        fout.skip_line()
        fout.down_indent()
        fout.write_line('endforeach()')
        fout.skip_line()
        fout.write_line('# install c++ examples')
        fout.write_line_verbatim('file(GLOB cpp_samples '
                                 '\"${0}CMAKE_CURRENT_SOURCE_DIR{1}/*.c\"'.
                                 format(self.open_br, self.close_br))
        fout.write_line_verbatim('                      '
                                 '\"${0}CMAKE_CURRENT_SOURCE_DIR{1}/*.cpp\"'
                                 .format(self.open_br, self.close_br))
        fout.write_line_verbatim('                      '
                                 '\"${0}CMAKE_CURRENT_SOURCE_DIR{1}/*.h\")'.
                                 format(self.open_br, self.close_br))
        fout.write_line_verbatim(('install (FILES ${0}cpp_samples{1} '
                                  'DESTINATION '
                                  '${0}MISC_PREFIX{1}examples/c++/{2})').
                                 format(self.open_br,
                                        self.close_br,
                                        self.package))
        fout.skip_line()

    ########################################################################

    # Write file

    def write_file(self):
        self.fileout.write_file()
        self.write_examples()

    def close_file(self):
        self.fileout.close_file()
