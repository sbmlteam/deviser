"""
This is the base file for using the 'templates' in directory
code_files/templates. When writing another library (NOT a package)
for libSBML, deviser will take the 'templates' (.h and .cpp files),
replace various things and create new files based on the 'template'.
"""
#!/usr/bin/env python
#
# @file    BaseTemplateFile.py
# @brief   base class for all files to be generated from templates
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

import os
import re

from util import global_variables as gv, strFunctions as SF


class BaseTemplateFile:
    """Common base class for all template files"""

    def __init__(self, name, filetype):

        self.class_prefix = SF.upper_first(name)
        self.filetype = filetype

    ########################################################################

    def create_base_description(self, name, common=False):
        """
        Create a dictionary describing an object.

        :param name: e.g. SBase, ListOf, ConstructorException
        :param common: ???
        :return: dictionary of a name and no attributes.
        """
        if common:
            if name.startswith('lib'):
                used_name = '{0}-{1}'.format(gv.library_name.lower(), name[4:])
                if not gv.library_name.lower().startswith('lib'):
                    used_name = "lib" + used_name
            else:
                used_name = name

            descr = dict({'name': '{0}'.format(used_name),
                          'attribs': None})
        elif self.filetype == 'bindings_files':
            if name == 'lib':
                filename = gv.library_name.lower()
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
        """
        Copy certain content from a template file to an output file.

        :param fileout: object representing file we are writing to.
        :param infilename: name of the file we wish to copy.

        NB not all of the functions referred to in the while-loop
        have been implemented.
        """
        filename = '{0}{1}..{1}{3}{1}templates{1}{2}'.\
            format(os.path.dirname(__file__),
                   os.sep, infilename, self.filetype)
        infile = open(filename, 'r')
        lines = infile.readlines()
        infile.close()
        num_lines = len(lines)
        i = 0
        while i < num_lines:  # <- Assumes output file never has more lines
            line = lines[i]   # than the input file. Is that always true?
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
            elif line.startswith('<insert_other_includes/>'):
                self.print_all_other_includes(fileout)
                i += 1
            else:
                line = self.adjust_line(line)
                fileout.copy_line_verbatim(line)
                i += 1

    @staticmethod
    def adjust_line(line):
        """
        Replace certain items in a line of code.

        :param line: the line before replacement(s)
        :return: the line after replacement(s)
        """
        lowerlibname = gv.library_name.lower()
        nonlibname = lowerlibname
        if lowerlibname.startswith('lib'):
            nonlibname = lowerlibname[3:]  # Remove leading "lib"
        line = re.sub('nonlibsbml', nonlibname, line)
        line = re.sub('SBase', gv.std_base, line)
        line = re.sub('LIBSBML', gv.library_name.upper(), line)
        line = re.sub('LibSBML', SF.upper_first(gv.library_name), line)
        line = re.sub('libSBML', SF.lower_first(gv.library_name), line)
        line = re.sub('libsbml', lowerlibname, line)
        if lowerlibname.startswith('lib'):
            line = re.sub('sbmlfwd', '{0}fwd'.format(lowerlibname[3:]), line)
        else:
            line = re.sub('sbmlfwd', '{0}fwd'.format(lowerlibname), line)
        doctype = '{0}_DOCUMENT'.format(gv.language.upper())
        # if gv.document_class != 'SedDocument':
        #     doctype = 'LIB_{0}_{1}'.
        #       format(SF.get_library_suffix(gv.library_name).upper(),
        #              SF.remove_prefix(gv.document_class).upper())
        line = re.sub('SBML_DOCUMENT', doctype, line)
        line = re.sub('SBMLDocument', gv.document_class, line)
        line = re.sub('toplevelname', gv.top_level_element_name, line)
        line = re.sub('CAT_SBML',
                      'CAT_{0}'.format(gv.language.upper()), line)
        line = re.sub('SBML_Lang',
                      '{0}'.format(gv.language.upper()), line)
        line = re.sub('SBML_',
                      '{0}_'.format(gv.language.upper()), line)
        # hack for SedML
        if gv.prefix == 'Sed':
            line = re.sub('readSBML', 'read{0}ML'.format(gv.prefix), line)
            line = re.sub('writeSBML', 'write{0}ML'.format(gv.prefix), line)
        else:
            line = re.sub('readSBML', 'read{0}'.
                          format(gv.language.upper()), line)
            line = re.sub('writeSBML', 'write{0}'.
                          format(gv.language.upper()), line)
        line = re.sub('sbml', gv.language, line)
        line = re.sub('SBMLSBML', '{0}{1}'.
                      format(SF.upper_first(gv.language), gv.prefix), line)
        line = re.sub('SBML', gv.prefix, line)
        line = re.sub('ListOf', '{0}ListOf'.format(gv.prefix), line)
        line = re.sub('<SPEC_NAMESPACE>', '\"{0}\"'.
                      format(gv.namespaces[-1]['namespace']), line)
        line = re.sub('language_', '{0}'.format(gv.language.lower()), line)
        line = re.sub('LANGUAGE', '{0}'.format(gv.language.upper()), line)
        if gv.namespaces is not None and len(gv.namespaces) > 0 \
                and 'level' in gv.namespaces[-1]:
            line = re.sub('<SPEC_LEVEL>', '{0}'.
                          format(gv.namespaces[-1]['level']), line)
            line = re.sub('<SPEC_VERSION>', '{0}'.
                          format(gv.namespaces[-1]['version']), line)
        if gv.annot_element is not None:
            line = re.sub('<Annotation>', gv.annot_element, line)
            line = re.sub('<annotation_variable>', '\"{0}\"'.
                          format(SF.lower_first(gv.annot_element)), line)
        if gv.notes_element is not None:
            line = re.sub('<Notes>', gv.notes_element, line)
            line = re.sub('<notes_variable>', '\"{0}\"'.
                          format(SF.lower_first(gv.notes_element)), line)
        line = re.sub('<NS>', 'LIBSBML_CPP_NAMESPACE_QUALIFIER ', line)
        return line

    @staticmethod
    def print_block(fileout, lines, i):
        """
        Print lines in the template file, between the <verbatim> anchors,
            to the output file.

        :param fileout: object representing the file we are writing to
        :param lines: the lines we want to write out.
        :param i: total number of lines written before executing this function
        :return: total number of lines written AFTER executing this function
        """
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
        """
        Print lines in the template file, between the <sbml> anchors,
            to the output file.

        :param fileout: object representing the file we are writing to
        :param lines: the lines we want to write out.
        :param i: total number of lines written before executing this function
        :return: total number of lines written AFTER executing this function
        """
        i += 1
        line = lines[i]
        other_libs = ''
        for depend in gv.dependency:
            lib_up = depend['library'].upper()
            other_libs += '${0}{1}_LIBRARY{2}'.format('{', lib_up, '}')

        while not line.startswith('</sbml>'):
            line = re.sub('LIBREPLACE', gv.library_name.upper(), line)
            line = re.sub('OTHER_LIBS', other_libs, line)
            fileout.copy_line_verbatim(line)
            i += 1
            line = lines[i]
        i += 1
        return i

    def print_if_block(self, fileout, lines, i):
        """
        Print lines in the template file, between if_ anchors,
            to the output file.
            e.g. between line with <if_has_level_version> and
            line with </if_has_level_version>

        :param fileout: object representing the file we are writing to
        :param lines: the lines we want to write out.
        :param i: total number of lines written before executing this function
        :return: total number of lines written AFTER executing this function
        """
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
        if block == 'package' and not gv.is_package:
            return False
        if block == 'has_level_version':
            if not gv.has_level_version:
                return False
            elif not self.doc_has_level_version():
                return False
        return True

    def doc_has_level_version(self):
        for element in self.elements:
            if 'document' in element and element['document']:
                for attrib in element['attribs']:
                    if attrib['name'] == 'level':
                        return True
        return False

    @staticmethod
    def print_omex_hack(fileout, lines, i):
        """
        Print lines in the template file, between the <omex-hack> anchors,
            to the output file.

        :param fileout: object representing the file we are writing to
        :param lines: the lines we want to write out.
        :param i: total number of lines written before executing this function
        :return: total number of lines written AFTER executing this function
        """
        if gv.language.lower() == 'omex':
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
                line = re.sub('sbml', gv.language, line)
                fileout.copy_line_verbatim(line)
                i += 1
                line = lines[i]
            i += 1
        return i

    @staticmethod
    def print_sbase_block(fileout, lines, i):
        """
        Write lines from the template file between the <replace_only_sbase>
           and </replace_only_sbase> anchors. Before writing each line,
           replace any instance of 'SBase' with the value of std_base (in
           the global variables), if different.

        :param fileout: object representing the file we are writing to
        :param lines: the lines we want to write out.
        :param i: total number of lines written before executing this function
        :return: total number of lines written AFTER executing this function
        """
        i += 1
        line = lines[i]
        while not line.startswith('</replace_only_sbase>'):
            line = re.sub('SBase', gv.std_base, line)
            fileout.copy_line_verbatim(line)
            i += 1
            line = lines[i]
        i += 1
        return i

    @staticmethod
    def print_all_namespaces(fileout, static=False):
        if gv.namespaces is None or len(gv.namespaces) == 0:
            return
        indent = '  '
        if static:
            indent = 'static '
        for ns in gv.namespaces:
            if 'level' in ns and 'version' in ns and 'namespace' in ns:
                leader = gv.prefix.upper() if gv.is_package \
                    else gv.language.upper()
                line = \
                    '{4}const char* const {0}_XMLNS_L{1}V{2}   = \"{3}\";\n'.\
                    format(leader,
                           ns['level'], ns['version'],
                           ns['namespace'], indent)
                fileout.copy_line_verbatim(line)

    @staticmethod
    def print_all_other_includes(fileout):
        """
        Write any remaining #include lines to the output file.

        :param fileout: object representing the file we are writing to.
        """
        if gv.uses_ASTNode:
            line = '#include <sbml/math/FormulaFormatter.h>'
            fileout.copy_line_verbatim(line)
            fileout.copy_line_verbatim('  ')
