#!/usr/bin/env python
#
# @file    BaseCMakeFiles.py
# @brief   class for generating base files for other library implementations
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

import re
import os

from base_files import BaseInterfaceFile, BaseFile, BaseCMakeFile, BaseTemplateFile
from code_files import CppHeaderFile
from code_files import CppCodeFile
from util import strFunctions, global_variables


class BaseCMakeFiles(BaseTemplateFile.BaseTemplateFile):
    """Class for all Base files"""

    def __init__(self, verbose=False):
        # members from object

        BaseTemplateFile.BaseTemplateFile.__init__(self,
                                                   global_variables.prefix,
                                                   'cmake_files')
        self.verbose = verbose

    def write_files(self):
        current_dir = os.getcwd()
        self.write_file_for_dir('top-level')
        os.chdir('src')
        src_dir = os.getcwd()
        self.write_file_for_dir('src')
        os.chdir('bindings')
        self.write_file_for_dir('bindings')
        os.chdir(src_dir)
        os.chdir('{0}'.format(global_variables.language))
        self.write_file_for_dir('code')
        os.chdir(current_dir)

    def write_file_for_dir(self, this_dir):
        fileout = BaseFile.BaseFile('CMakeLists', 'txt')
        filein = '{0}{1}CMakeLists.txt'.format(this_dir, os.sep)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def print_find_dependency_library(self, fileout):
        lines = []
        for depend in global_variables.dependency:
            lib_up = depend['library'].upper()
            lib_low = depend['library'].lower()
            m = len(lib_low)
            name = lib_low[3:m]
            lines.append('find_library({0}_LIBRARY\n'.format(lib_up))
            lines.append('     NAMES {0}-static.lib {1}-static {0}.lib {1}\n'.format(lib_low, name))
            lines.append('     PATHS ${1}{0}_DEPENDENCY_DIR{2}/lib\n'.format(global_variables.library_name.upper(), '{', '}'))
            lines.append('     /usr/local/lib\n')
            lines.append('           /usr/lib\n')
            lines.append('     DOC \"The file name of the {0} library.\"\n'.format(name))
            lines.append(')\n')
            lines.append('\n')
            lines.append('find_path({0}_INCLUDE_DIR\n'.format(lib_up))
            lines.append('    NAMES {0}/{1}Base.h\n'.format(name, depend['prefix']))
            lines.append('    PATHS\n')
            lines.append('      ${1}{0}_DEPENDENCY_DIR{2}/include\n'.format(global_variables.library_name.upper(), '{', '}'))
            lines.append('    /usr/local/include\n')
            lines.append('          /usr/include\n')
            lines.append('    DOC "The directory containing the {0} include files."\n'.format(name))
            lines.append(')\n')
            lines.append('\n')
            lines.append('set({0}_STATIC OFF CACHE BOOL "is {1} statically compiled")\n'.format(lib_up, lib_low))
            lines.append('if (WIN32 AND NOT CYGWIN)\n')
            lines.append('    if (LIBSBML_LIBRARY AND LIBSBML_LIBRARY MATCHES ".*-static*$")\n')
            lines.append('        set({0}_STATIC ON CACHE BOOL "is {1} statically compiled")\n'.format(lib_up, lib_low))
            lines.append('    else()\n')
            lines.append('        option({0}_STATIC "The {0} library was statically compiled" ON)\n'.format(lib_up))
            lines.append('    endif()\n')
            lines.append('endif()\n')
        for line in lines:
            fileout.copy_line_verbatim(line)

    def print_static_dependency_library(self, fileout):
        lines = []
        for depend in global_variables.dependency:
            lib_up = depend['library'].upper()
            lib_low = depend['library'].lower()
            m = len(lib_low)
            name = lib_low[3:m]
            lines.append('  if ({0}_STATIC)\n'.format(lib_up))
            lines.append('      add_definitions(-D{0}_STATIC)\n'.format(lib_up))
            lines.append('      set(BUILD_DEFINITIONS "${1}BUILD_DEFINITIONS{2} -D{0}_STATIC")\n'.format(lib_up, '{', '}'))
            lines.append('  else()\n')
            lines.append('      add_definitions(-D{0}_EXPORTS)\n'.format(lib_up))
            lines.append('      set(BUILD_DEFINITIONS "${1}BUILD_DEFINITIONS{2} -D{0}_EXPORTS")\n'.format(lib_up, '{', '}'))
            lines.append('  endif()\n')
        for line in lines:
            fileout.copy_line_verbatim(line)

    def print_dependency_library_config(self, fileout):
        lines = []
        for depend in global_variables.dependency:
            lib_up = depend['library'].upper()
            m = len(lib_up)
            name = lib_up[3:m]
            lines.append('   {0} library configuration:\n'.format(name))
            lines.append('     {0} library                  = ${2}{1}_LIBRARY{3}\n'.format(name, lib_up, '{', '}'))
            lines.append('     {0} include                  = -I${2}{1}_INCLUDE_DIR{3}\n'.format(name, lib_up, '{', '}'))
        for line in lines:
            fileout.copy_line_verbatim(line)

    def print_include_dependency(self, fileout):
        for depend in global_variables.dependency:
            lib_up = depend['library'].upper()
            line = 'include_directories(BEFORE ${0}{1}_INCLUDE_DIR{2})\n'.format('{', lib_up, '}')
            fileout.copy_line_verbatim(line)
