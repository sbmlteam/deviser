#!/usr/bin/env python
#
# @file    PackageFile.py
# @brief   class for generating cmake package file
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

from ..base_files import BaseCMakeFile
from ..util import strFunctions, global_variables


class PackageFile():
    """Class for CMake package files"""

    def __init__(self, name, package, src, examples=False):

        self.package = package.lower()
        self.src = src

        self.fileout = BaseCMakeFile.BaseCMakeFile(name)

        if src:
            self.fileout.brief_description = 'Src CMake file for {0} ' \
                                             'package'.format(self.package)
        else:
            if not examples:
                self.fileout.brief_description = \
                    'Top-level CMake file for {0} ' \
                    'package'.format(self.package)
            else:
                self.fileout.brief_description = \
                    'Examples CMake file for {0} ' \
                    'package'.format(self.package)

        self.cap_package = self.package.upper()
        self.up_package = strFunctions.upper_first(self.package)

        self.language = global_variables.language
        self.cap_language = global_variables.language.upper()

        self.open_br = '{'
        self.close_br = '}'

    ########################################################################

    # Write specific code

    def write_top_level_file(self):
        """
        TODO add description
        """
        fout = self.fileout

        fout.skip_line()
        fout.write_line_verbatim('option(ENABLE_{0}     \"Enable lib'
                                 '{1} support for the {1} Level 3 '
                                 '{2} (\'{3}\') package.\"'
                                 '      OFF)'.format(self.cap_package,
                                                     self.cap_language,
                                                     self.up_package,
                                                     self.package))
        fout.skip_line()
        fout.write_comment_line('provide summary status')
        fout.write_line_verbatim('list(APPEND LIB{0}_PACKAGE_SUMMARY '
                                 '\"{0} \'{1}\' package  = ${3}ENABLE'
                                 '_{2}{4}\")'.format(self.cap_language,
                                                     self.package,
                                                     self.cap_package,
                                                     self.open_br,
                                                     self.close_br))
        fout.skip_line()
        fout.write_line('if (ENABLE_{0})'.format(self.cap_package))
        fout.up_indent()
        fout.write_line('add_definitions(-DUSE_'
                        '{0})'.format(self.cap_package))
        fout.write_line_verbatim('set(LIB{0}_PACKAGE_INCLUDES ${1}'
                                 'LIB{0}_PACKAGE_INCLUDES{2} \"LIB{0}'
                                 '_HAS_PACKAGE_{3}'
                                 '\")'.format(self.cap_language,
                                              self.open_br,
                                              self.close_br,
                                              self.cap_package))
        fout.write_line_verbatim('list(APPEND SWIG_EXTRA_ARGS -DUSE'
                                 '_{0})'.format(self.cap_package))
        fout.write_line_verbatim('list(APPEND SWIG_SWIGDOCDEFINES '
                                 '--define USE_'
                                 '{0})'.format(self.cap_package))
        fout.down_indent()
        fout.write_line('endif()')
        fout.skip_line()

    def write_src_file(self):
        """
        TODO add description
        """
        fout = self.fileout

        fout.skip_line()
        fout.write_line('if (ENABLE_{0})'.format(self.cap_package))
        fout.skip_line()
        fout.write_line_verbatim('include(${0}LIB{1}_ROOT_SOURCE_DIR{2}/'
                                 '{3}-package.'
                                 'cmake)'.format(self.open_br,
                                                 self.cap_language,
                                                 self.close_br,
                                                 self.package))
        fout.skip_line()
        fout.write_comment_line('build up sources')
        fout.write_line('set({0}_SOURCES)'.format(self.cap_package))
        fout.skip_line()
        fout.write_comment_line('go through all directories')
        fout.write_line('foreach(dir common extension {0} validator '
                        'validator/constraints)'.
                        format(self.language))
        fout.up_indent()
        fout.skip_line()
        fout.write_comment_line('add to include directory')
        fout.write_line('include_directories(${0}CMAKE_CURRENT_SOURCE'
                        '_DIR{1}/{2}/packages/{3}/${0}dir'
                        '{1})'.format(self.open_br, self.close_br,
                                      self.language, self.package))
        fout.skip_line()
        fout.write_comment_line('file sources')
        fout.write_line_verbatim('file(GLOB current ${0}CMAKE_CURRENT_'
                                 'SOURCE_DIR{1}/{2}/packages/{3}/${0}'
                                 'dir{1}/*.cpp'.format(self.open_br,
                                                       self.close_br,
                                                       self.language,
                                                       self.package))
        fout.write_line_verbatim('                  ${0}CMAKE_CURRENT_'
                                 'SOURCE_DIR{1}/{2}/packages/{3}/${0}'
                                 'dir{1}/*.c'.format(self.open_br,
                                                     self.close_br,
                                                     self.language,
                                                     self.package))
        fout.write_line_verbatim('                  ${0}CMAKE_CURRENT_'
                                 'SOURCE_DIR{1}/{2}/packages/{3}/${0}'
                                 'dir{1}/*.h)'.format(self.open_br,
                                                      self.close_br,
                                                      self.language,
                                                      self.package))
        fout.skip_line()
        fout.write_comment_line('add sources')
        fout.write_line('set({0}_SOURCES ${1}{0}_SOURCES{2} ${1}'
                        'current{2})'.format(self.cap_package,
                                             self.open_br,
                                             self.close_br))
        fout.skip_line()
        fout.write_comment_line('mark headers for installation')
        fout.write_line_verbatim('file(GLOB {3}_headers ${0}CMAKE_'
                                 'CURRENT_SOURCE_DIR{1}/{2}/packages/'
                                 '{3}/${0}dir{1}/*'
                                 '.h)'.format(self.open_br,
                                              self.close_br,
                                              self.language,
                                              self.package))
        fout.skip_line()
        fout.write_line_verbatim('install(FILES ${0}{3}_headers{1} '
                                 'DESTINATION include/{2}/packages/{3}/'
                                 '${0}dir{1} )'.format(self.open_br,
                                                       self.close_br,
                                                       self.language,
                                                       self.package))
        fout.skip_line()
        fout.down_indent()
        fout.write_line('endforeach()')
        fout.skip_line()
        fout.write_comment_line('create source group for IDEs')
        fout.write_line_verbatim('source_group({0}_package FILES ${1}{2}_'
                                 'SOURCES{3})'.format(self.package,
                                                      self.open_br,
                                                      self.cap_package,
                                                      self.close_br))
        fout.skip_line()
        fout.write_comment_line('add {0} sources to {1} '
                                'sources'.format(self.package,
                                                 self.cap_language))
        fout.write_line_verbatim('SET(LIB{3}_SOURCES ${0}LIB{3}_SOURCES'
                                 '{2} ${0}{1}_SOURCES'
                                 '{2})'.format(self.open_br,
                                               self.cap_package,
                                               self.close_br,
                                               self.cap_language))
        fout.skip_line()
        fout.open_comment()
        fout.write_blank_comment_line()
        fout.write_comment_line('add test scripts')
        fout.close_comment()
        fout.write_line('if (WITH_CHECK)')
        fout.skip_line(2)
        fout.write_line('endif()')
        fout.skip_line()
        fout.write_line('endif()')
        fout.skip_line()

    def write_example_file(self):
        """
        TODO add description
        """
        fout = self.fileout

        fout.write_file()
        fout.skip_line()
        fout.write_line('if (ENABLE_{0})'.format(self.cap_package))
        fout.up_indent()
        fout.write_line('add_subdirectory(c++/{0})'.format(self.package))
        fout.down_indent()
        fout.write_line('endif()')
        fout.skip_line()

    ########################################################################

    # Write file

    def write_file(self):
        """
        TODO add description
        """
        self.fileout.write_file()
        if self.src:
            self.write_src_file()
        else:
            self.write_top_level_file()

    def close_file(self):
        """
        Utility wrapper function for closing a file.
        """
        self.fileout.close_file()
