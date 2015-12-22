#!/usr/bin/env python
#
# @file    BaseFile.py
# @brief   base class for all files to be generated
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

from util import global_variables, strFunctions


class BaseFile:
    """Common base class for all files"""

    def __init__(self, name, extension):
        self.name = name
        self.extension = extension

        # derived members for file
        self.filename = name + '.' + extension
        if name != '':
            self.file_out = open(self.filename, 'w')

        # derived members for comments
        self.comment_start = '/**'
        self.comment = ' *'
        self.comment_end = '*/'

        # derived members for description
        if not hasattr(self, 'brief_description'):
            self.brief_description = "Base file"
        elif len(self.brief_description) == 0:
            self.brief_description = 'Base file'

            # derived members for spacing
        self.line_length = 79
        self.num_tabs = 0

        # populate useful variables
        if self.extension == 'h':
            self.is_header = True
        else:
            self.is_header = False

        # members that might get overridden if creating another library
        self.language = global_variables.language
        self.library_name = global_variables.library_name
        self.cap_language = self.language.upper()

        self.open_br = '{'
        self.close_br = '}'

        # members used here that will only cone from some
        # instantiations of this base class
        # but it needs to know that it can resolve them
        self.class_name = ''
        self.package = ''
        self.class_object = []

    ########################################################################

    # FUNCTIONS FOR WRITING LINES/COMMENTS

    # based on the number of tabs and the length of line specified

    # function to create lines of size specified
    def create_lines(self, line, tabsize, is_comment=False):
        max_length = self.line_length - tabsize
        if max_length <= 0:
            # we must have a line where the tabsize is so long
            # multi did this with ListOfSpeciesTypeComponentMapsInProduct
            max_length = self.line_length - 4
        if is_comment:
            max_length -= 3

        lines = []
        if len(line) == 0:
            return lines
        words = line.split()
        num_words = len(words)
        if num_words == 0:
            lines.append(line)
        elif num_words == 1:
            lines.append(line)
        else:
            self.parse_lines(lines, words, max_length)
        return lines

    @staticmethod
    def parse_lines(lines, words, max_length):
        num_words = len(words)
        in_quotes = False
        quotes_closed = True
        reopen_quotes = False
        i = 1
        temp = words[0]
        if temp.startswith('\"'):
            in_quotes = True
        newline = words[0]
        while i < num_words:
            if len(newline) < max_length:
                if not in_quotes:
                    if words[i].startswith('\"'):
                        in_quotes = True
                        quotes_closed = False
                    # check we dont also end
                    if words[i].endswith('\"'):
                        in_quotes = False
                        quotes_closed = True
                else:
                    if words[i].endswith('\"'):
                        in_quotes = False
                if len(temp) > 0:
                    temp = temp + ' ' + words[i]
                else:
                    if reopen_quotes:
                        temp = '\"' + words[i]
                        reopen_quotes = False
                    else:
                        temp = words[i]
                i += 1
                if len(temp) <= max_length:
                    if temp.endswith('\"'):
                        quotes_closed = True
                    newline = temp
                else:
                    if len(newline) == 0:
                        if in_quotes or not quotes_closed:
                            temp += ' \"'
                            quotes_closed = True
                        if in_quotes and not quotes_closed:
                            reopen_quotes = True
                        lines.append(temp)
                        temp = ''
                    else:
                        if in_quotes:
                            if words[i-1].startswith('\"'):
                                # do not add the quotes as we are throwing
                                # the word away
                                in_quotes = False
                                quotes_closed = True
                            else:
                                newline += ' \"'
                                quotes_closed = True
                                reopen_quotes = True
                        elif not quotes_closed:
                            newline += ' \"'
                            quotes_closed = True
                            reopen_quotes = True
                        lines.append(newline)
                        newline = ''
                        temp = ''
                        i -= 1
            else:
                if in_quotes or not quotes_closed:
                    newline += ' \"'
                    quotes_closed = True
                    reopen_quotes = True
                lines.append(newline)
                newline = ''
                temp = ''
        if len(newline) > 0:
            lines.append(newline)

    # write line without worrying about size
    def write_line_verbatim(self, line):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}\n'.format(tabs, line))

    # write line without worrying about size
    def copy_line_verbatim(self, line):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}'.format(tabs, line))

    # functions for writing lines indenting each new line
    def write_line(self, line, space=0):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        for i in range(0, space):
            tabs += ' '
        lines = self.create_lines(line, len(tabs))
        for i in range(0, len(lines)):
            self.file_out.write('{0}{1}\n'.format(tabs, lines[i]))
            tabs += '  '

    # functions for writing lines without indenting each new line
    def write_line_no_indent(self, line):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        lines = self.create_lines(line, len(tabs))
        for i in range(0, len(lines)):
            self.file_out.write('{0}{1}\n'.format(tabs, lines[i]))

    # function to write a line preserving with indenting
    def write_spaced_line(self, line):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}\n'.format(tabs, line))

    # function for blankLines
    def skip_line(self, num=1):
        for i in range(0, num):
            self.file_out.write('\n')

    # functions for writing comments
    def write_comment_line(self, line):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        lines = self.create_lines(line, len(tabs), True)
        for i in range(0, len(lines)):
            self.file_out.write('{0}{1} {2}\n'
                                .format(tabs, self.comment, lines[i]))

    def write_blank_comment_line(self):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}\n'.format(tabs, self.comment))

    def open_comment(self):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}\n'.format(tabs, self.comment_start))

    def close_comment(self):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0} {1}\n'.format(tabs, self.comment_end))

    def write_doxygen_start(self):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('\n{0}{1} @cond doxygen{2}Internal {3}\n\n'
                            .format(tabs, self.comment_start,
                                    self.library_name,
                                    self.comment_end))

    def write_doxygen_end(self):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('\n{0}{1} @endcond {2}\n\n'
                            .format(tabs, self.comment_start,
                                    self.comment_end))

    # function for the library extern declaration
    def write_extern_decl(self):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}_EXTERN\n'
                            .format(tabs, self.library_name.upper()))

    ########################################################################

    # Function to copy from another file verbatim
    def copy_additional_file(self, filename):
        in_file = open(filename, 'r')
        for line in in_file:
            self.file_out.write('{0}'.format(line))
        in_file.close()

    ########################################################################

    # Functions to alter the number of tabs being used in writing lines

    def up_indent(self, num=1):
        self.num_tabs += num

    def down_indent(self, num=1):
        self.num_tabs -= num
        # just checking
        if self.num_tabs < 0:
            self.num_tabs = 0

    ########################################################################

    # File access functions

    def close_file(self):
        self.file_out.close()

    ########################################################################

    # Default write file with standard header and licence

    def write_file(self):
        self.add_file_header()

    def write_libsbml_licence(self):
        self.write_blank_comment_line()
        self.write_comment_line('<!-----------------------------------------'
                                '---------------------------------')
        self.write_comment_line('This file is part of libSBML.  Please visit '
                                'http://sbml.org for more information about '
                                'SBML, and the latest version of libSBML.')
        self.write_blank_comment_line()
        self.write_comment_line('Copyright (C) 2013-2015 jointly by the '
                                'following organizations:')
        self.write_comment_line('    1. California Institute of Technology, '
                                'Pasadena, CA, USA')
        self.write_comment_line('    2. EMBL European Bioinformatics '
                                'Institute (EMBL-EBI), Hinxton, UK')
        self.write_comment_line('    3. University of Heidelberg, Heidelberg, '
                                'Germany')
        self.write_blank_comment_line()
        self.write_comment_line('Copyright (C) 2009-2013 jointly by the '
                                'following organizations:')
        self.write_comment_line('    1. California Institute of Technology, '
                                'Pasadena, CA, USA')
        self.write_comment_line('    2. EMBL European Bioinformatics '
                                'Institute (EMBL-EBI), Hinxton, UK')
        self.write_blank_comment_line()
        self.write_comment_line('Copyright (C) 2006-2008 by the California '
                                'Institute of Technology,')
        self.write_comment_line('    Pasadena, CA, USA ')
        self.write_blank_comment_line()
        self.write_comment_line('Copyright (C) 2002-2005 jointly by the '
                                'following organizations:')
        self.write_comment_line('    1. California Institute of Technology, '
                                'Pasadena, CA, USA')
        self.write_comment_line('    2. Japan Science and Technology Agency, '
                                'Japan')
        self.write_blank_comment_line()
        self.write_comment_line('This library is free software; you can '
                                'redistribute it and/or modify it under the '
                                'terms of the GNU Lesser General Public '
                                'License as published by the Free Software '
                                'Foundation.  A copy of the license agreement'
                                ' is provided in the file named "LICENSE.txt"'
                                ' included with this software distribution '
                                'and also available online as http://sbml.org'
                                '/software/libsbml/license.html')
        self.write_comment_line('--------------------------------------------'
                                '---------------------------- -->')

    def add_file_header(self):
        self.open_comment()
        self.write_comment_line('@file   {0}'.format(self.filename))
        self.write_comment_line('@brief  {0}'.format(self.brief_description))
        if global_variables.is_package:
            self.write_comment_line('@author SBMLTeam')
        else:
            self.write_comment_line('@author DEVISER')
        if self.library_name == 'Libsbml':
            self.write_libsbml_licence()
        if self.is_header and not self.is_excluded(self.name):
            if self.name.endswith('Extension'):
                self.write_class_comments(True, False, False)
            elif self.name.endswith('Plugin'):
                self.write_class_comments(False, True, False)
            elif self.name.endswith('Validator'):
                self.write_class_comments(False, False, True)
            else:
                self.write_class_comments(False, False, False)

        self.close_comment()

    def write_class_comments(self, extension, plugin, validator):
        fullname = global_variables.package_full_name
        up_package = strFunctions.upper_first(self.package)
        validator_class_comment = 'The {0} class extends the ' \
                                  'Validator class from core libSBML to ' \
                                  'apply validation to the constructs ' \
                                  'introduced by the SBML Level&nbsp;3 ' \
                                  '{1} package. This class then acts as a ' \
                                  'base class for any validators that ' \
                                  'apply rules to the &ldquo;{2}&rdquo; ' \
                                  'package specification constructs or to ' \
                                  'entire models that use the &ldquo;{2}' \
                                  '&rdquo; package, and may therefore be ' \
                                  'subject to other global restrictions ' \
                                  'introduced.'.format(self.name,
                                                       fullname,
                                                       self.package.lower())
        self.write_blank_comment_line()
        self.write_comment_line('@class {0}'.format(self.class_name))
        if extension:
            self.write_comment_line('@sbmlbrief{0}{1}{2} Base extension class'
                                    '.'.format(self.open_br,
                                               self.package.lower(),
                                               self.close_br))
            self.write_blank_comment_line()
            self.write_comment_line('@class {0}PkgNamespaces'
                                    ''.format(up_package))
            self.write_comment_line('@sbmlbrief{0}{1}{2} SBMLNamespaces '
                                    'extension.'
                                    ''.format(self.open_br,
                                              self.package.lower(),
                                              self.close_br))
        elif plugin:
            self.write_comment_line('@sbmlbrief{0}{1}{2} Extension of '
                                    '{3}.'.format(self.open_br,
                                                  self.package.lower(),
                                                  self.close_br,
                                                  self.class_object['sbase']))
        elif validator:
            self.write_comment_line('@sbmlbrief{0}{1}{2} Entry point for '
                                    '&ldquo;{1}&rdquo package validation'
                                    '.'.format(self.open_br,
                                               self.package.lower(),
                                               self.close_br))
            self.write_blank_comment_line()
            self.write_comment_line('@htmlinclude not-sbml-warning.html')
            self.write_blank_comment_line()
            self.write_comment_line('@copydetails doc_common_intro_'
                                    'package_validators')
            self.write_blank_comment_line()
            self.write_comment_line('{0}'.format(validator_class_comment))
            self.write_blank_comment_line()
            self.write_comment_line('@copydetails doc_section_package_'
                                    'validators_general_info')
        else:
            self.write_comment_line('@sbmlbrief{0}{1}{2} TODO:'
                                    '{3}'.format(self.open_br,
                                                self.package.lower(),
                                                self.close_br,
                                                self.brief_description))

    @staticmethod
    def is_excluded(filename):
        excluded = False
        excluded_files = ['Types', 'fwd', 'Error', 'ErrorTable',
                          'ConsistencyValidator', 'package', 'register']
        i = 0
        while not excluded and i < len(excluded_files):
            if filename.endswith(excluded_files[i]):
                excluded = True
            i += 1
        return excluded
