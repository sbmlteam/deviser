#!/usr/bin/env python
#
# @file    BaseBindingsFiles.py
# @brief   class for generating base files for other library implementations
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

import re
import os

from base_files import BaseInterfaceFile, BaseFile, BaseCMakeFile, BaseTemplateFile
from code_files import CppHeaderFile
from code_files import CppCodeFile
from util import strFunctions, global_variables


class BaseBindingsFiles(BaseTemplateFile.BaseTemplateFile):
    """Class for all Base files"""

    def __init__(self, elements, binding, verbose=False):
        # members from object

        BaseTemplateFile.BaseTemplateFile.__init__(self,
                                                   global_variables.prefix,
                                                   'bindings_files')
        self.elements = elements
        self.binding = binding

        self.verbose = verbose

    def write_files(self):
        if self.binding == 'swig':
            self.write_swig_files()
        else:
            self.write_other_files()

    def write_other_files(self):
        self.write_interface('lib')
        self.write_interface('local')
        self.write_code('local')
        self.write_cmake_files()
        self.write_assembly_file()

    def write_swig_files(self):
        self.write_all_files('OStream')
        self.write_header('ListWrapper')
        self.write_interface('std_set')
        self.write_header('lib')
        self.write_interface('lib')
        self.write_interface('ASTNodes')

    def write_all_files(self, name):
        self.write_header(name)
        self.write_code(name)

    def write_header(self, name):
        base_descrip = self.create_base_description(name)
        fileout = CppHeaderFile.CppHeaderFile(base_descrip, False)
        filein = '{1}{2}{0}.h'.format(name, self.binding, os.sep)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.add_file_header()
        fileout.skip_line(2)
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def write_interface(self, name):
        if name == 'lib':
            filename = global_variables.library_name.lower()
        else:
            filename = name
        fileout = BaseInterfaceFile.BaseInterfaceFile(filename)
        filein = '{1}{2}{0}.i'.format(name, self.binding, os.sep)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.add_file_header()
        fileout.skip_line(2)
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def write_code(self, name):
        base_descrip = self.create_base_description(name)
        fileout = CppCodeFile.CppCodeFile(base_descrip, False)
        filein = '{1}{2}{0}.cpp'.format(name, self.binding, os.sep)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.add_file_header()
        fileout.skip_line(2)
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def write_cmake_files(self):
        fileout = BaseFile.BaseFile('CMakeLists', 'txt')
        filein = '{0}{1}CMakeLists.txt'.format(self.binding, os.sep)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        self.copy_file_contents(fileout, filein)
        fileout.close_file()
        if self.binding == 'csharp':
            fileout = BaseCMakeFile.BaseCMakeFile('compile-native-files')
            filein = '{0}{1}native.cmake'.format(self.binding, os.sep)
            if self.verbose:
                print('Writing file {0}'.format(fileout.filename))
            fileout.add_file_header()
            fileout.skip_line(2)
            self.copy_file_contents(fileout, filein)
            fileout.close_file()

    def write_assembly_file(self):
        if not self.binding == 'csharp':
            return
        fileout = BaseFile.BaseFile('AssemblyInfo.cs', 'in')
        filein = '{0}{1}assembly.in'.format(self.binding, os.sep)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    ###########################################################
    def print_includes(self, fileout):
        for element in self.elements:
            if not element['name'].endswith('Document'):
                name = strFunctions.prefix_name(element['name'])
                fileout.copy_line_verbatim('%include <{0}/{1}.h>\n'
                                           ''.format(global_variables.language,
                                                     name))
                if element['hasListOf']: 
                    loname = strFunctions.prefix_name(
                      strFunctions.list_of_name(element['name']))
                    fileout.copy_line_verbatim('%include <{0}/{1}.h>\n'
                                           ''.format(global_variables.language,
                                                     loname))


    def print_derived_types(self, fileout):
        libname = global_variables.library_name.lower()
        for element in self.elements:
            if not element['name'].endswith('Document'):
                name = strFunctions.prefix_name(element['name'])
                fileout.copy_line_verbatim('    case (int) {0}.{1}:'
                                           '\n'.format(libname,
                                                       element['typecode']))
                fileout.copy_line_verbatim('      return new {0}(cPtr, owner)'
                                           ';\n'.format(name))
                fileout.skip_line()

    def print_derived_listof_types(self, fileout):
        for element in self.elements:
            if not element['name'].endswith('Document') and \
                    element['hasListOf']:
                name = strFunctions.lower_list_of_name_no_prefix(
                    element['name'])
                loname = strFunctions.prefix_name(
                    strFunctions.list_of_name(element['name']))
                fileout.copy_line_verbatim('      else if (name == \"{0}\")\n'
                                           ''.format(name))
                fileout.copy_line_verbatim('      {\n')
                fileout.copy_line_verbatim('         return new {0}(cPtr, '
                                           'owner);\n'.format(loname))
                fileout.copy_line_verbatim('      }\n')

    def print_for_all_classes(self, fileout, line, classes=True, lists=True):
        l_len = len(line)
        declaration = line[0:l_len-1]
        if classes:
            for element in self.elements:
                name = strFunctions.prefix_name(element['name'])
                fileout.copy_line_verbatim('{0}({1})\n'.format(declaration,
                                                               name))
        if lists:
            for element in self.elements:
                if element['hasListOf']:
                    loname = strFunctions.prefix_name(
                        strFunctions.list_of_name(element['name']))
                    fileout.copy_line_verbatim('{0}({1})\n'.format(declaration,
                                                                   loname))

    def print_dependency_includes(self, fileout, header):
        if header.startswith('header'):
            include = '#'
        else:
            include = '%'
        lines = []
        for depend in global_variables.dependency:
            lang = depend['prefix'].lower()
            lines.append('{0}include <{1}/common/extern.h>\n'.format(include, lang))
            lines.append('{0}include <{1}/common/lib{1}-namespace.h>\n'
                         ''.format(include, lang))
            lines.append('{0}include <{1}/common/lib{1}-version.h>\n'
                         ''.format(include, lang))
            # hack for NUML
            if depend['prefix'] == 'NUML':
                lines.append('{0}include <{1}/common/'
                             'operationReturnValues.h>\n'
                             ''.format(include, lang))
            else:
                lines.append('{0}include <{1}/common/{2}'
                             'OperationReturnValues.h>\n'
                             ''.format(include, lang, depend['prefix']))
            lines.append('\n')
            lines.append('{0}include <{1}/{2}Namespaces.h>\n'
                         ''.format(include, lang, depend['prefix']))
            lines.append('{0}include <{1}/{2}TypeCodes.h>\n'
                         ''.format(include, lang, depend['prefix']))
            lines.append('{0}include <{1}/{2}Types.h>\n'
                         ''.format(include, lang, depend['prefix']))
            lines.append('{0}include <{1}/{2}Error.h>\n'
                         ''.format(include, lang, depend['prefix']))
            lines.append('{0}include <{1}/{2}ErrorLog.h>\n'
                         ''.format(include, lang, depend['prefix']))
        for line in lines:
            fileout.copy_line_verbatim(line)

    def print_dependency_library(self, fileout, include=False):
        for depend in global_variables.dependency:
            lib = depend['library'].upper()
            if include:
                fileout.copy_line_verbatim('include_directories'
                                           '(BEFORE ${1}{0}_INCLUDE_DIR{2})'
                                           '\n'.format(lib, '{', '}'))
            else:
                fileout.copy_line_verbatim('         -I${1}{0}_INCLUDE_DIR{2}/'
                                           '\n'.format(lib, '{', '}'))
