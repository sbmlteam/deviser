#!/usr/bin/env python
#
# @file    BaseClassFiles.py
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

from . import CppHeaderFile
from . import CppCodeFile
from . import ValidationFiles
from util import strFunctions, global_variables, query
from base_files import BaseFile, BaseCMakeFile, BaseTemplateFile


class BaseClassFiles(BaseTemplateFile.BaseTemplateFile):
    """Class for all Base files"""

    def __init__(self, name, elements, verbose=False):
        # members from object
        # self.class_prefix = strFunctions.upper_first(name)
        BaseTemplateFile.BaseTemplateFile.__init__(self, name, 'code_files')

        self.elements = elements

        self.verbose = verbose

    def write_files(self):
        self.write_all_files('SBase')
        self.write_all_files('ListOf')
        self.write_all_files('ConstructorException')
        self.write_all_files('Reader')
        self.write_all_files('Writer')
        self.write_all_files('ErrorLog')
        self.write_all_files('Namespaces')
        self.write_all_files('Error')
        self.write_all_files('Visitor')
        self.write_all_files('TypeCodes')
        self.write_header('Types')
        self.write_header('ErrorTable')

    def write_common_files(self):
        self.write_header('common', True)
        self.write_header('extern', True)
        self.write_header('lib-config', True)
        self.write_code('lib-version', True)
        self.write_cmake('lib-version.h')
        self.write_cmake('lib-config-common.h')
        self.write_cmake('lib-namespace.h')
        self.write_all_files('OperationReturnValues')

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

    def write_cmake(self, name):
        if name.startswith('lib'):
            if global_variables.library_name.lower().startswith('lib'):
                out_name = '{0}-{1}'.format(global_variables.library_name.lower(), name[4:])
            else:
                out_name = 'lib{0}-{1}'.format(global_variables.library_name.lower(), name[4:])
        else:
            out_name = name
#        out_name = 'lib{0}-{1}'.format(global_variables.language, name[4:])
        fileout = BaseCMakeFile.BaseCMakeFile(out_name)
        filein = '{0}.cmake'.format(name)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def print_includes(self, fileout):
        for element in self.elements:
            name = strFunctions.prefix_name(element['name'])
            fileout.copy_line_verbatim('#include <{0}/{1}.h>\n'
                                       ''.format(global_variables.language,
                                                 name))

    def print_typecodes(self, fileout):
        for element in self.elements:
          #  if not element['name'].endswith('Document'):
            name = element['typecode']
            fileout.copy_line_verbatim('  , {0}\n'
                                           ''.format(name))

    def print_typecode_strings(self, fileout):
        for element in self.elements:
        #   if not element['name'].endswith('Document'):
            name = strFunctions.remove_prefix(element['name'])
            fileout.copy_line_verbatim('  , \"{0}\"\n'
                                           ''.format(name))

    def print_visit_header(self, fileout):
        for element in self.elements:
            if not element['name'].endswith('Document'):
                if not 'document' in element or not element['document']:
                    name = strFunctions.prefix_name(element['name'])
                    self.write_visit_header(fileout, name)
                    fileout.skip_line(2)

    def write_visit_header(self, fileout, name):
        fileout.open_comment()
        fileout.write_comment_line('Interface method for using the '
                                   '<a target=\"_blank\" ')
        fileout.write_comment_line('href=\"http://en.wikipedia.org/wiki/'
                                   'Design_pattern_(computer_science)\"'
                                   '><i>Visitor')
        fileout.write_comment_line(self.adjust_line('Pattern</i></a> to '
                                                    'perform operations on '
                                                    'SBase objects.'))
        fileout.write_blank_comment_line()
        fileout.write_comment_line(self.adjust_line('@param x the '
                                                    'SBase object to visit.'))
        fileout.close_comment()
        fileout.write_line('virtual bool visit (const {0} &x);'.format(name))

    def print_leave_header(self, fileout):
        for element in self.elements:
            if not element['name'].endswith('Document'):
                if not 'document' in element or not element['document']:
                    name = strFunctions.prefix_name(element['name'])
                    fileout.skip_line(2)
                    self.write_leave_header(fileout, name)

    def write_leave_header(self, fileout, name):
        fileout.open_comment()
        fileout.write_comment_line('Interface method for using the '
                                   '<a target=\"_blank\" ')
        fileout.write_comment_line('href=\"http://en.wikipedia.org/wiki/'
                                   'Design_pattern_(computer_science)\"'
                                   '><i>Visitor')
        fileout.write_comment_line(self.adjust_line('Pattern</i></a> to '
                                                    'perform operations on '
                                                    'SBase objects.'))
        fileout.write_blank_comment_line()
        fileout.write_comment_line(self.adjust_line('@param x the '
                                                    'SBase object to leave.'))
        fileout.close_comment()
        fileout.write_line('virtual void leave (const {0} &x);'.format(name))

    def print_visit_code(self, fileout):
        for element in self.elements:
            if not element['name'].endswith('Document'):
                if not 'document' in element or not element['document']:
                    name = strFunctions.prefix_name(element['name'])
                    self.write_visit_code(fileout, name)

    def write_visit_code(self, fileout, name):
        code = dict({'title_line': 'Visit the {0}'.format(name),
                     'params': ['const {0}& x'.format(name)],
                     'return_lines': [],
                     'additional': [],
                     'function': 'visit',
                     'return_type': 'bool',
                     'arguments': ['const {0}& x'.format(name)],
                     'constant': False,
                     'virtual': False,
                     'object_name': '{0}Visitor'.format(global_variables.prefix),
                     'implementation': [self.create_code_block('line', [self.adjust_line('return visit(static_cast<const SBase&>(x))')])]})
        fileout.write_function_implementation(code)

    def print_leave_code(self, fileout):
        fileout.skip_line(2)
        for element in self.elements:
            if not element['name'].endswith('Document'):
                if not 'document' in element or not element['document']:
                    name = strFunctions.prefix_name(element['name'])
                    self.write_leave_code(fileout, name)

    def write_leave_code(self, fileout, name):
        code = dict({'title_line': 'Leave the {0}'.format(name),
                     'params': ['const {0}& x'.format(name)],
                     'return_lines': [],
                     'additional': [],
                     'function': 'leave',
                     'return_type': 'void',
                     'arguments': ['const {0}& x'.format(name)],
                     'constant': False,
                     'virtual': False,
                     'object_name': '{0}Visitor'.format(global_variables.prefix),
                     'implementation': [self.create_code_block('blank', [])]})
        fileout.write_function_implementation(code)

    def print_visitor_forwards(self, fileout):
        for element in self.elements:
            if not element['name'].endswith('Document'):
                name = strFunctions.prefix_name(element['name'])
                fileout.write_line('class {0};'.format(name))


    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code

    def print_error_enum(self, fileout):
        for error in global_variables.class_rules:
            name = error['typecode']
            if not name.endswith('Unknown'):
                fileout.copy_line_verbatim(', {0}      = {1}\n'
                                           ''.format(name, error['number']))

    def print_error_table(self, fileout):
        # create a dummy object so we can use the validation files code
        lib_object = dict({'name': '',
                           'offset': 0,
                           'baseElements': None,
                           'plugins': None,
                           'fullname': '',
                           'base_level': 1,
                           'base_version': 1,
                           'pkg_version': 1,
                           'required': True,
                           'enums': None})
        valid = ValidationFiles.ValidationFiles(lib_object, True)
        valid.set_error_file(fileout)
        for error in global_variables.class_rules:
            name = error['typecode']
            if not name.endswith('Unknown'):
                valid.write_table_entry(error)

    def print_document_errors(self, fileout):
        root = {'baseElements': self.elements}
        doc = query.get_class(global_variables.document_class, root)
        if not doc:
            docname = 'Document'
        else:
            docname = strFunctions.remove_prefix(doc['name'], False, False, '', True)
        libname = strFunctions.get_library_suffix(global_variables.library_name)
        if not libname.endswith('ml'):
            libname = libname + 'ml'
        fileout.copy_line_verbatim('          if ( errorId == {0}{1}Allowed'
                                   'CoreAttributes\n'.format(libname, docname))
        level = False
        version = False
        if doc and 'attribs' in doc:
            for a in doc['attribs']:
                if a['name'] == 'level':
                    level = True
                elif a['name'] == 'version':
                    version = True
        if level:
            fileout.copy_line_verbatim('            || errorId == {0}{1}'
                                       'LevelMustBeNonNegativeInteger\n'
                                       ''.format(libname, docname))
        if version:
            fileout.copy_line_verbatim('            || errorId == {0}{1}'
                                       'VersionMustBeNonNegativeInteger\n'
                                       ''.format(libname, docname))
        fileout.copy_line_verbatim('            || errorId == InvalidNamespace'
                                   'On{0})\n'.format(global_variables.prefix))


