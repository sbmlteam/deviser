#!/usr/bin/env python
#
# @file    BaseTemplateFile.py
# @brief   base class for all files to be generated from templates
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

import os
import re

from util import global_variables, strFunctions


class BaseTemplateFile:
    """Common base class for all template files"""

    def __init__(self, name, filetype):

        self.class_prefix = strFunctions.upper_first(name)
        self.filetype = filetype



    ########################################################################

    def create_base_description(self, name, common=False):
        if common:
            if name.startswith('lib'):
                if global_variables.library_name.lower().startswith('lib'):
                    used_name = '{0}-{1}'.format(global_variables.library_name.lower(), name[4:])
                else:
                    used_name = 'lib{0}-{1}'.format(global_variables.library_name.lower(), name[4:])
            else:
                used_name = name

            descr = dict({'name': '{0}'.format(used_name),
                          'attribs': None})
        elif self.filetype == 'bindings_files':
            if name == 'lib':
                filename = global_variables.library_name.lower()
                descr = dict({'name': filename,
                              'attribs': None})
            else:
                descr = dict({'name': name, 'attribs': None})
        else:
            if name == 'SBase':
                descr = dict({'name': '{0}Base'.format(self.class_prefix),
                              'attribs': None})
            else:
                descr = dict({'name': '{0}{1}'.format(self.class_prefix, name),
                              'attribs': None})
        return descr

    def copy_file_contents(self, fileout, infilename):
        filename = '{0}{1}..{1}{3}{1}templates{1}{2}'.format(os.path.dirname(__file__),
                                                  os.sep, infilename, self.filetype)
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
            elif line.startswith('<if_'):
                i = self.print_if_block(fileout, lines, i)
            elif line.startswith('<replace_only_sbase>'):
                i = self.print_sbase_block(fileout, lines, i)
            elif line.startswith('<insert_class_includes/>'):
                self.print_includes(fileout)
                i += 1
            elif line.startswith('<insert_type_codes/>'):
                self.print_typecodes(fileout)
                i += 1
            elif line.startswith('<insert_type_strings/>'):
                self.print_typecode_strings(fileout)
                i += 1
            elif line.startswith('<add_visit_classes_header/>'):
                self.print_visit_header(fileout)
                i += 1
            elif line.startswith('<add_leave_classes_header/>'):
                self.print_leave_header(fileout)
                i += 1
            elif line.startswith('<add_visit_classes_code/>'):
                self.print_visit_code(fileout)
                i += 1
            elif line.startswith('<add_leave_classes_code/>'):
                self.print_leave_code(fileout)
                i += 1
            elif line.startswith('<add_specific_errors/>'):
                self.print_error_enum(fileout)
                i += 1
            elif line.startswith('<add_specific_error_table/>'):
                self.print_error_table(fileout)
                i += 1
            elif line.startswith('<insert_document_errors/>'):
                self.print_document_errors(fileout)
                i += 1
            elif line.startswith('<add_visitor_forwards/>'):
                self.print_visitor_forwards(fileout)
                i += 1
            elif line.startswith('<insert_class_includes/>'):
                self.print_includes(fileout)
                i += 1
            elif line.startswith('<dependencies>'):
                self.print_dependency_includes(fileout, lines[i+1])
                i += 3
            elif line.startswith('<insert_derived_types/>'):
                self.print_derived_types(fileout)
                i += 1
            elif line.startswith('<insert_derived_types/>'):
                self.print_derived_types(fileout)
                i += 1
            elif line.startswith('<insert_derived_listof_types/>'):
                self.print_derived_listof_types(fileout)
                i += 1
            elif line.startswith('<library_dependencies/>'):
                self.print_dependency_library(fileout)
                i += 1
            elif line.startswith('<include_library_dependencies/>'):
                self.print_dependency_library(fileout, True)
                i += 1
            elif line.startswith('<insert>'):
                self.print_for_all_classes(fileout, lines[i+1])
                i += 3
            elif line.startswith('<insert listonly>'):
                self.print_for_all_classes(fileout, lines[i+1], False, True)
                i += 3
            elif line.startswith('<find_library_dependencies/>'):
                self.print_find_dependency_library(fileout)
                i += 1
            elif line.startswith('<static_library_dependencies/>'):
                self.print_static_dependency_library(fileout)
                i += 1
            elif line.startswith('<library_config/>'):
                self.print_dependency_library_config(fileout)
                i += 1
            elif line.startswith('<omex_hack>'):
                i = self.print_omex_hack(fileout, lines, i)
            elif line.startswith('<include_dependency_directories/>'):
                self.print_include_dependency(fileout)
                i += 1
            elif line.startswith('<all_namespaces/>'):
                self.print_all_namespaces(fileout)
                i += 1
            elif line.startswith('<all_namespaces_static/>'):
                self.print_all_namespaces(fileout, True)
                i += 1
            else:
                line = self.adjust_line(line)
                fileout.copy_line_verbatim(line)
                i += 1

    @staticmethod
    def adjust_line(line):
        lowerlibname = global_variables.library_name.lower()
        nonlibname = lowerlibname
        if lowerlibname.startswith('lib'):
            nonlibname = lowerlibname[3:]
        line = re.sub('nonlibsbml', nonlibname, line)
        line = re.sub('SBase', global_variables.std_base, line)
        line = re.sub('LIBSBML', global_variables.library_name.upper(), line)
        line = re.sub('LibSBML', strFunctions.upper_first(global_variables.library_name), line)
        line = re.sub('libSBML', strFunctions.lower_first(global_variables.library_name), line)
        line = re.sub('libsbml', lowerlibname, line)
        if lowerlibname.startswith('lib'):
            line = re.sub('sbmlfwd', '{0}fwd'.format(lowerlibname[3:]), line)
        else:
            line = re.sub('sbmlfwd', '{0}fwd'.format(lowerlibname), line)
        doctype = '{0}_DOCUMENT'.format(global_variables.language.upper())
        # if global_variables.document_class != 'SedDocument':
        #     doctype = 'LIB_{0}_{1}'.format(strFunctions.get_library_suffix(global_variables.library_name).upper(),
        #                                    strFunctions.remove_prefix(global_variables.document_class).upper())
        line = re.sub('SBML_DOCUMENT', doctype, line)
        line = re.sub('SBMLDocument', global_variables.document_class, line)
        line = re.sub('toplevelname', strFunctions.lower_first(global_variables.top_level_element_name), line)
        line = re.sub('CAT_SBML',
                      'CAT_{0}'.format(global_variables.language.upper()), line)
        line = re.sub('SBML_Lang',
                      '{0}'.format(global_variables.language.upper()), line)
        line = re.sub('SBML_',
                      '{0}_'.format(global_variables.language.upper()), line)
        # hack for SedML
        if global_variables.prefix == 'Sed':
            line = re.sub('readSBML', 'read{0}ML'.format(global_variables.prefix), line)
            line = re.sub('writeSBML', 'write{0}ML'.format(global_variables.prefix), line)
        else:
            line = re.sub('readSBML', 'read{0}'.format(global_variables.language.upper()), line)
            line = re.sub('writeSBML', 'write{0}'.format(global_variables.language.upper()), line)
        line = re.sub('sbml', global_variables.language, line)
        line = re.sub('SBMLSBML', '{0}{1}'.format(strFunctions.upper_first(global_variables.language), global_variables.prefix), line)
        line = re.sub('SBML', global_variables.prefix, line)
        line = re.sub('ListOf', '{0}ListOf'.format(global_variables.prefix), line)
        line = re.sub('<SPEC_NAMESPACE>', '\"{0}\"'.format(global_variables.namespaces[-1]['namespace']), line)
        line = re.sub('language_', '{0}'.format(global_variables.language.lower()), line)
        line = re.sub('LANGUAGE', '{0}'.format(global_variables.language.upper()), line)
        if global_variables.namespaces is not None and len(global_variables.namespaces) > 0 and 'level' in global_variables.namespaces[-1]:
            line = re.sub('<SPEC_LEVEL>', '{0}'.format(global_variables.namespaces[-1]['level']), line)
            line = re.sub('<SPEC_VERSION>', '{0}'.format(global_variables.namespaces[-1]['version']), line)
        if global_variables.annot_element is not None:
            line = re.sub('<Annotation>', global_variables.annot_element, line)
            line = re.sub('<annotation_variable>', '\"{0}\"'.format(strFunctions.lower_first(global_variables.annot_element)), line)
        line = re.sub('<NS>', 'LIBSBML_CPP_NAMESPACE_QUALIFIER ', line)
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
        other_libs = ''
        for depend in global_variables.dependency:
            lib_up = depend['library'].upper()
            other_libs = other_libs + '${0}{1}_LIBRARY{2}'.format('{', lib_up, '}')

        while not line.startswith('</sbml>'):
            line = re.sub('LIBREPLACE', global_variables.library_name.upper(), line)
            line = re.sub('OTHER_LIBS', other_libs, line)
            fileout.copy_line_verbatim(line)
            i += 1
            line = lines[i]
        i += 1
        return i

    def print_if_block(self, fileout, lines, i):
        line = lines[i]
        length = len(line)
        block = line[4:length-2]
        end_block = '</if_{0}>'.format(block)
        writeLines = self.write_lines(block)
        i += 1
        line = lines[i]
        while not line.startswith(end_block):
            if writeLines:
                line = self.adjust_line(line)
                fileout.copy_line_verbatim(line)
            i += 1
            line = lines[i]
            if line.startswith('<else>'):
                writeLines = not writeLines
                i += 1
                line = lines[i]
        i += 1
        return i

    def write_lines(self, block):
        if block == 'package' and not global_variables.is_package:
            return False
        if block == 'has_level_version':
            if not global_variables.has_level_version:
                return False
            elif not self.doc_has_level_version():
                return False
        return True

    def doc_has_level_version(self):
        for element in self.elements:
            if element['document']:
                for attrib in element['attribs']:
                    if attrib['name'] == 'level':
                        return True
        return False

    @staticmethod
    def print_omex_hack(fileout, lines, i):
        if global_variables.language.lower() == 'omex':
            fileout.copy_line_verbatim('add_subdirectory(src)')
            i += 1
            line = lines[i]
            while not line.startswith('</omex_hack>'):
                i += 1
                line = lines[i]
            i += 1
        else:
            i += 1
            line = lines[i]
            while not line.startswith('</omex_hack>'):
                line = re.sub('sbml', global_variables.language, line)
                fileout.copy_line_verbatim(line)
                i += 1
                line = lines[i]
            i += 1
        return i

    @staticmethod
    def print_sbase_block(fileout, lines, i):
        i += 1
        line = lines[i]
        while not line.startswith('</replace_only_sbase>'):
            line = re.sub('SBase', global_variables.std_base, line)
            fileout.copy_line_verbatim(line)
            i += 1
            line = lines[i]
        i += 1
        return i

    @staticmethod
    def print_all_namespaces(fileout, static=False):
        if global_variables.namespaces is None or len(global_variables.namespaces) == 0:
            return
        indent = '  '
        if static:
            indent = 'static '
        for ns in global_variables.namespaces:
            if 'level' in ns and 'version' in ns and 'namespace' in ns:
                line = '{4}const char* const {0}_XMLNS_L{1}V{2}   = \"{3}\";\n'.format(global_variables.prefix.upper(),
                                                                                     ns['level'], ns['version'],
                                                                                     ns['namespace'], indent)
                fileout.copy_line_verbatim(line)