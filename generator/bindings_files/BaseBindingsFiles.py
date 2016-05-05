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

from base_files import BaseInterfaceFile, BaseFile
from code_files import CppHeaderFile
from code_files import CppCodeFile
from util import strFunctions, global_variables


class BaseBindingsFiles():
    """Class for all Base files"""

    def __init__(self, elements, verbose=False):
        # members from object

        self.elements = elements

        self.verbose = verbose

    def write_files(self):
        self.write_all_files('OStream')
        self.write_header('ListWrapper')
        self.write_interface('std_set')
        self.write_header('lib')
        self.write_interface('lib')
        self.write_interface('ASTNodes')

    def write_all_files(self, name):
        self.write_header(name)
        self.write_code(name)

    def write_header(self, name, common=False):
        base_descrip = self.create_base_description(name, common)
        fileout = CppHeaderFile.CppHeaderFile(base_descrip, False)
        filein = '{0}.h'.format(name)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.add_file_header()
        fileout.skip_line(2)
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def write_interface(self, name, common=False):
        if name == 'lib':
            filename = global_variables.library_name.lower()
        else:
            filename = name
        fileout = BaseInterfaceFile.BaseInterfaceFile(filename)
        filein = '{0}.i'.format(name)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.add_file_header()
        fileout.skip_line(2)
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def write_code(self, name, common=False):
        base_descrip = self.create_base_description(name, common)
        fileout = CppCodeFile.CppCodeFile(base_descrip, False)
        filein = '{0}.cpp'.format(name)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.add_file_header()
        fileout.skip_line(2)
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def create_base_description(self, name, common=False):
        if name == 'lib':
            filename = global_variables.library_name.lower()
            descr = dict({'name': '{}'.format(filename),
                          'attribs': None})
        else:
            descr = dict({'name': name, 'attribs': None})
        return descr

    def copy_file_contents(self, fileout, infilename):
        filename = '{0}{1}templates{1}{2}'.format(os.path.dirname(__file__),
                                                  os.sep, infilename)
        infile = open(filename, 'r')
        lines = infile.readlines()
        infile.close()
        num_lines = len(lines)
        i = 0
        while i < num_lines:
            line = lines[i]
            if line.startswith('<verbatim>'):
                i = self.print_block(fileout, lines, i)
            elif line.startswith('<sbml>'):
                i = self.print_sbml_block(fileout, lines, i)
            elif line.startswith('<insert_class_includes/>'):
                self.print_includes(fileout)
                i += 1
            else:
                line = self.adjust_line(line)
                fileout.copy_line_verbatim(line)
                i += 1

    @staticmethod
    def adjust_line(line):
        line = re.sub('SBase', global_variables.std_base, line)
        line = re.sub('LIBSBML', global_variables.library_name.upper(), line)
        line = re.sub('LibSBML', 'Lib{0}'.format(global_variables.language.upper()), line)
        line = re.sub('libSBML', 'lib{0}'.format(global_variables.language.upper()), line)
        line = re.sub('CAT_SBML',
                      'CAT_{0}'.format(global_variables.language.upper()), line)
        line = re.sub('SBML_',
                      '{0}_'.format(global_variables.language.upper()), line)
        line = re.sub('readSBML', 'read{0}ML'.format(global_variables.prefix), line)
        line = re.sub('writeSBML', 'write{0}ML'.format(global_variables.prefix), line)
        line = re.sub('sbml', global_variables.language, line)
        line = re.sub('SBMLSBML', '{0}{1}'.format(strFunctions.upper_first(global_variables.language), global_variables.prefix), line)
        line = re.sub('SBML', global_variables.prefix, line)
        line = re.sub('ListOf', '{0}ListOf'.format(global_variables.prefix), line)
        line = re.sub('SPEC_NAMESPACE', '\"{0}\"'.format(global_variables.namespaces[0]['namespace']), line)
        line = re.sub('LANGUAGE', '{0}'.format(global_variables.language.lower()), line)
        return line

    @staticmethod
    def print_block(fileout, lines, i):
        i += 1
        line = lines[i]
        while not line.startswith('</verbatim>'):
            fileout.copy_line_verbatim(line)
            i += 1
            line = lines[i]
        i += 1
        return i

    @staticmethod
    def print_sbml_block(fileout, lines, i):
        i += 1
        line = lines[i]
        while not line.startswith('</sbml>'):
            line = re.sub('LIBREPLACE', global_variables.library_name.upper(), line)
            fileout.copy_line_verbatim(line)
            i += 1
            line = lines[i]
        i += 1
        return i


    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code

    def write_cmake_file(self):
        fileout = BaseFile.BaseFile('CMakeLists', 'txt')
        filein = 'CMakeLists.txt'
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def print_includes(self, fileout):
        for element in self.elements:
            if not element['name'].endswith('Document'):
                name = strFunctions.prefix_name(element['name'])
                fileout.copy_line_verbatim('%include <{0}/{1}.h>\n'
                                           ''.format(global_variables.language,
                                                     name))

