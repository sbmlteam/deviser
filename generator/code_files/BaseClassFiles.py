#!/usr/bin/env python
#
# @file    BaseClassFiles.py
# @brief   class for generating base files for other library implementations
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

# NB issue 45 - consider moving this file to base_files directory.

# import re
# import os

from . import CppHeaderFile
from . import CppCodeFile
from . import ValidationFiles
from ..util import strFunctions as SF, global_variables as gv, query
from ..base_files import BaseCMakeFile, BaseTemplateFile


class BaseClassFiles(BaseTemplateFile.BaseTemplateFile):
    """Class for all Base files"""

    def __init__(self, name, elements, verbose=False):
        """
        Constructor

        :param name: e.g. "Sed"
        :param elements: list of dictionaries, each storing information
               about a class.
        :param verbose: set to `True` for more output.
        """
        # members from object
        # self.class_prefix = SF.upper_first(name)
        BaseTemplateFile.BaseTemplateFile.__init__(self, name, 'code_files')

        self.elements = elements
        self.verbose = verbose

    def write_files(self):
        """
        Write all the files we require (a .h and .cpp file for each).
        """
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
        """
        Write the 'common' files.

        TODO Sarah, please explain. Thanks.
        """
        self.write_header('common', True)
        self.write_header('extern', True)
        self.write_header('lib-config', True)
        self.write_code('lib-version', True)
        self.write_cmake('lib-version.h')
        self.write_cmake('lib-config-common.h')
        self.write_cmake('lib-namespace.h')
        self.write_all_files('OperationReturnValues')

    def write_all_files(self, name):
        """
        Write both the .h file and the .cpp file

        :param name: name of the file, e.g. "Hello" will
               cause Hello.h and Hello.cpp to be written.
        """
        self.write_header(name)
        self.write_code(name)

    def write_header(self, name, common=False):
        """
        Write the header file (.h file)

        :param name: e.g. "Hello", to create file "Hello.h".
        :param common: ???
        """
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
        """
        Write the implementation (.cpp) file.

        :param name: e.g. "Hello" will create file Hello.cpp
        :param common: ???
        """
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
        """
        Copy the CMake (.cmake) file

        :param name: e.g. "Hello" will cause Hello.cmake to be written.
                A name like "libPaisley" might create libsbml-Paisley.cmake
                (depending on value of gv.library_name)
        """
        if name.startswith('lib'):
            if gv.library_name.lower().startswith('lib'):  # e.g. Libsbml
                out_name = '{0}-{1}'.format(gv.library_name.lower(), name[4:])
            else:
                out_name = 'lib{0}-{1}'.format(gv.library_name.lower(),
                                               name[4:])
        else:
            out_name = name
        # out_name = 'lib{0}-{1}'.format(gv.language, name[4:])
        fileout = BaseCMakeFile.BaseCMakeFile(out_name)
        filein = '{0}.cmake'.format(name)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        self.copy_file_contents(fileout, filein)
        fileout.close_file()

    def print_includes(self, fileout):
        """
        Write the #include lines to the output file

        :param fileout: object representing output file we are writing.
        """
        for element in self.elements:
            name = SF.prefix_name(element['name'])
            fileout.copy_line_verbatim('#include <{0}/{1}.h>\n'
                                       ''.format(gv.language,
                                                 name))

    def print_typecodes(self, fileout):
        """
        Write the typecode lines to the file.

        :param fileout: object representing output file we are writing.
               e.g. a CppHeaderFile.CppHeaderFile object
               with name 'SedTypeCodes'

        Example typecodes: 'MY_TEST_TYPE', 'MY_SECOND_TYPE'
        """
        for element in self.elements:
            # if not element['name'].endswith('Document'):
            name = element['typecode']
            fileout.copy_line_verbatim('  , {0}\n'.format(name))

    def print_typecode_strings(self, fileout):
        """
        Write out the typecode strings, for each class represented
            in self.elements
        TODO not sure what typecode strings are

        :param fileout: object representing output file we are writing.
        """
        for element in self.elements:
            # if not element['name'].endswith('Document'):
            name = SF.remove_prefix(element['name'])
            fileout.copy_line_verbatim('  , \"{0}\"\n'.format(name))

    def print_visit_header(self, fileout):
        """
        Cycle over all the class dictionaries in self.elements
        Write visitor header to file represented by fileout object

        ::param fileout: object representing output file we are writing.
        """
        for element in self.elements:
            if not element['name'].endswith('Document'):
                if 'document' not in element or not element['document']:
                    name = SF.prefix_name(element['name'])
                    self.write_visit_header(fileout, name)
                    fileout.skip_line(2)

    def write_visit_header(self, fileout, name):
        """
        Write the file header for the Visitor pattern

        ::param fileout: object representing output file we are writing.
        :param name: the name of the SBase object we are visiting
        """
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
        """
        Print the leave() header for certain classes.

        :param fileout: object representing output file we are writing.
        """
        for element in self.elements:
            if not element['name'].endswith('Document'):
                if 'document' not in element or not element['document']:
                    name = SF.prefix_name(element['name'])
                    fileout.skip_line(2)
                    self.write_leave_header(fileout, name)

    def write_leave_header(self, fileout, name):
        """
        Write the part of the header concerning the leave() method.

        :param fileout: object representing output file we are writing.
        :param name: the name of the SBase object class which leave() uses.
        """
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
        """
        Cycle through the list of dictionaries in self.elements,
            which represent classes. Write Visitor code for those
            which .... TODO Sarah please complete this sentence

        :param fileout: object representing output file we are writing.
        """
        for element in self.elements:
            if not element['name'].endswith('Document'):
                if 'document' not in element or not element['document']:
                    name = SF.prefix_name(element['name'])
                    self.write_visit_code(fileout, name)

    def write_visit_code(self, fileout, name):
        """
        Write out the visit() function implementation code.

        :param fileout: object representing output file we are writing.
        :param name: the name of the object class we are visiting.
        """
        impl = 'return visit(static_cast<const SBase&>(x))'
        code = dict({'title_line': 'Visit the {0}'.format(name),
                     'params': ['const {0}& x'.format(name)],
                     'return_lines': [],
                     'additional': [],
                     'function': 'visit',
                     'return_type': 'bool',
                     'arguments': ['const {0}& x'.format(name)],
                     'constant': False,
                     'virtual': False,
                     'object_name': '{0}Visitor'.format(gv.prefix),
                     'implementation':
                         [self.create_code_block('line',
                                                 [self.adjust_line(impl)])]})
        fileout.write_function_implementation(code)

    def print_leave_code(self, fileout):
        """
        Cycle through the list of dictionaries in self.elements,
            which represent classes. Write leave() code for those
            which .... TODO Sarah please complete this sentence

        :param fileout: object representing output file we are writing.
        """
        fileout.skip_line(2)
        for element in self.elements:
            if not element['name'].endswith('Document'):
                if 'document' not in element or not element['document']:
                    name = SF.prefix_name(element['name'])
                    self.write_leave_code(fileout, name)

    def write_leave_code(self, fileout, name):
        """
        Write function implementation for leave().
         I'm not sure how this fits in with the Visitor pattern.

        :param fileout: object representing output file we are writing.
        :param name: name of class we are leaving
        """
        code = dict({'title_line': 'Leave the {0}'.format(name),
                     'params': ['const {0}& x'.format(name)],
                     'return_lines': [],
                     'additional': [],
                     'function': 'leave',
                     'return_type': 'void',
                     'arguments': ['const {0}& x'.format(name)],
                     'constant': False,
                     'virtual': False,
                     'object_name': '{0}Visitor'.format(gv.prefix),
                     'implementation': [self.create_code_block('blank', [])]})
        fileout.write_function_implementation(code)

    def print_visitor_forwards(self, fileout):
        """
        Write forward declarations of classes we want to be able to visit.

        :param fileout: object representing output file we are writing.
        """
        for element in self.elements:
            if not element['name'].endswith('Document'):
                name = SF.prefix_name(element['name'])
                fileout.write_line('class {0};'.format(name))

    @staticmethod
    def create_code_block(code_type, lines):
        """
        Create a dictionary storing the code we want to write.

        :param code_type: e.g. 'line' or 'blank'
        :param lines: e.g. ['return visit(static_cast<const SedBase&>(x))']
            or []
        :return: dictionary containing both of the above.
        """
        code = dict({'code_type': code_type, 'code': lines})
        return code

    def print_error_enum(self, fileout):
        """
        Write out contents of an enum for typecode errors.

        :param fileout: object representing output file we are writing.
        """
        for error in gv.class_rules:
            name = error['typecode']
            if not name.endswith('Unknown'):
                fileout.copy_line_verbatim(', {0}      = {1}\n'
                                           ''.format(name, error['number']))

    def print_error_table(self, fileout):
        """
        ????

        :param fileout: object representing output file we are writing.
        """
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
        for error in gv.class_rules:
            name = error['typecode']
            if not name.endswith('Unknown'):
                valid.write_table_entry(error)

    def print_document_errors(self, fileout):
        """
        Write out the document errors to the file.
        TODO Sorry, I don't know what these are

        :param fileout: object representing output file we are writing.
        """
        root = {'baseElements': self.elements}
        doc = query.get_class(gv.document_class, root)
        if not doc:
            docname = 'Document'
        else:
            docname = SF.remove_prefix(doc['name'], remove_package=False,
                                       remove_doc_prefix=True)
        libname = SF.get_library_suffix(gv.library_name)
        if not libname.endswith('ml'):
            libname = libname + 'ml'
        fileout.copy_line_verbatim((10 * '') + 'if ( errorId == {0}{1}Allowed'
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
            fileout.copy_line_verbatim((12 * ' ') + '|| errorId == {0}{1}'
                                       'LevelMustBeNonNegativeInteger\n'
                                       ''.format(libname, docname))
        if version:
            fileout.copy_line_verbatim((12 * ' ') + '|| errorId == {0}{1}'
                                       'VersionMustBeNonNegativeInteger\n'
                                       ''.format(libname, docname))
        fileout.copy_line_verbatim('            || errorId == InvalidNamespace'
                                   'On{0})\n'.format(gv.prefix))
