#!/usr/bin/env python
#
# @file    BaseFile.py
# @brief   base class for all files to be generated
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

from ..util import global_variables as gv, strFunctions as SF


class BaseFile:
    """Common base class for all files"""

    def __init__(self, name, extension):
        """
        Constructor

        :param name: name of file (before dot and extension)
        :param extension: file extension (without dot, e.g. "xml").
        """
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
        self.language = gv.language
        self.library_name = gv.library_name
        self.cap_language = self.language.upper()

        self.open_br = '{'
        self.close_br = '}'

        # members used here that will only come from some
        # instantiations of this base class
        # but it needs to know that it can resolve them
        self.class_name = ''
        self.package = ''
        self.class_object = dict()
        self.has_enum = False

    ########################################################################

    # FUNCTIONS FOR WRITING LINES/COMMENTS

    # based on the number of tabs and the length of line specified

    def create_lines(self, line, tabsize, is_comment=False):
        """
        Function to create lines of size specified.

        :param line: the input line which we wish to split into shorter lines
        :param tabsize: number of space characters equivalent to a tab. (??)
        :param is_comment: set to `True` if input line is a comment
        :return: the set of lines produced
        """
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
        if num_words < 2:
            lines.append(line)
        else:
            self.parse_lines(lines, words, max_length)
        return lines

    @staticmethod
    def parse_lines(lines, words, max_length):
        """
        TODO this is a horrendous-looking function and
        we really need some decent test code for it.
        And more explanatory comments!

        :param lines:
        :param words:
        :param max_length:
        :return: nothing
        """
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
                    # check we don't also end
                    end_found = False
                    if words[i].endswith('\"'):
                        in_quotes = False
                        quotes_closed = True
                    else:
                        for c in range(1, len(words[i])):
                            if words[i][c] == '\"':
                                end_found = True
                    if end_found and in_quotes and not quotes_closed:
                        in_quotes = False
                        quotes_closed = True
                else:
                    if words[i].endswith('\"'):
                        in_quotes = False
                    elif words[i].endswith('\",') and not quotes_closed:
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
                    elif temp.endswith('\",'):
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
                    elif len(words[i - 1]) > (max_length - 5):
                        newline = temp
                        lines.append(newline)
                        newline = ''
                        temp = ''
                    else:
                        rollback = True
                        if in_quotes:
                            if words[i - 1] == '",':
                                # special case for validation rule messages
                                rollback = False
                                newline = temp
                            elif words[i - 1].startswith('\"'):
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
                        # don't break between @c and true etc
                        # remove @c and go back a word
                        if words[i - 2] == '@c':
                            templine = words[0]
                            for j in range(1, i - 2):
                                templine = templine + ' ' + words[j]
                            newline = templine
                            i -= 1
                        lines.append(newline)
                        newline = ''
                        temp = ''
                        if rollback:
                            i -= 1
                            rollback = False
            else:
                # don't break between @c and true etc
                # remove @c and go back a word
                if words[i - 1] == '@c':
                    lenline = len(newline)
                    newline = newline[0:lenline - 3]
                    i -= 1
                if in_quotes or not quotes_closed:
                    newline += ' \"'
                    quotes_closed = True
                    reopen_quotes = True
                lines.append(newline)
                newline = ''
                temp = ''
        if len(newline) > 0:
            lines.append(newline)

    def get_my_tabs(self):
        """
        Utility function for nice formatting.
        """
        tabs = ''
        for _ in range(0, int(self.num_tabs)):
            tabs += '  '
        return tabs

    def write_line_verbatim(self, line, skip_newline=False):
        """
        Write line without worrying about size. Finish with newline
        character.

        :param line: the line to write.
        """
        tabs = self.get_my_tabs()
        end = "\n"
        if skip_newline:
            end = ""
        self.file_out.write('{0}{1}{2}'.format(tabs, line, end))

    def copy_line_verbatim(self, line):
        """
        Write line without worrying about size
        """
        self.write_line_verbatim(line, True)

    def write_line(self, line, space=0, indent=True):
        """
        Functions for writing lines, indenting each new line

        :param line: the single input line
        :param space: number of spaces (of extra indentation)
        :param indent: set to `False` to stop indentation.
        """
        tabs = self.get_my_tabs()
        if indent:
            for _ in range(0, space):
                tabs += ' '
        lines = self.create_lines(line, len(tabs))
        for i in range(0, len(lines)):
            self.file_out.write('{0}{1}\n'.format(tabs, lines[i]))
            if indent:
                tabs += '  '

    def write_line_no_indent(self, line):
        """
        Functions for writing line without indenting each new line
        """
        self.write_line(line, indent=False)

    def write_spaced_line(self, line):
        """
        Function to write a single line, preserving the indenting
        i.e. we do not add extra indenting

        :param line: the line to write.
        """
        self.file_out.write('{0}{1}\n'.format(self.get_my_tabs(), line))

    def skip_line(self, num=1):
        """
        Function for blank lines

        :param num: number of blank lines to write.
        """
        for _ in range(0, num):
            self.file_out.write('\n')

    def write_comment_line(self, line):
        """
        Write a line of text in the comment block.

        :param line: single input line we want to write as
              multiple comment lines.
        """
        tabs = self.get_my_tabs()
        lines = self.create_lines(line, len(tabs), True)
        for i in range(0, len(lines)):
            self.file_out.write('{0}{1} {2}\n'
                                .format(tabs, self.comment, lines[i]))

    def write_blank_comment_line(self):
        """
        Write a blank line in the comment block.
        """
        self.file_out.write('{0}{1}\n'.format(self.get_my_tabs(),
                                              self.comment))

    def open_comment(self):
        """
        Start a new comment block.
        """
        self.file_out.write('{0}{1}\n'.format(self.get_my_tabs(),
                                              self.comment_start))

    def close_comment(self):
        """
        Finish a comment block.
        """
        self.file_out.write('{0} {1}\n'.format(self.get_my_tabs(),
                                               self.comment_end))

    def write_doxygen_start(self):
        """
        From the Doxygen website:

        Starts a conditional section that ends with a corresponding
        @endcond command, which is typically found in another comment
        block. The main purpose of this pair of commands is to (conditionally)
        exclude part of a file from processing (by Doxygen).
        The section between @cond and @endcond can be included by adding
        its section label to the ENABLED_SECTIONS configuration option.
        """
        self.file_out.write('\n{0}{1} @cond doxygen{2}Internal {3}\n\n'
                            .format(self.get_my_tabs(), self.comment_start,
                                    self.library_name,
                                    self.comment_end))

    def write_doxygen_end(self):
        """
        End the section (conditionally) excluded by Doxygen.
        """
        self.file_out.write('\n{0}{1} @endcond {2}\n\n'
                            .format(self.get_my_tabs(), self.comment_start,
                                    self.comment_end))

    def write_extern_decl(self):
        """
        Function for the library extern declaration
        """
        self.file_out.write('{0}{1}_EXTERN\n'
                            .format(self.get_my_tabs(),
                                    self.library_name.upper()))

    ########################################################################

    def copy_additional_file(self, filename):
        """
        Function to copy from another file verbatim

        :param filename: the file we wish to copy.
        """
        in_file = open(filename, 'r')
        for line in in_file:
            self.file_out.write('{0}'.format(line))
        in_file.close()

    ########################################################################

    # Functions to alter the number of tabs being used in writing lines

    def up_indent(self, num=1):
        """
        Increase the number of tabs to use.

        :param num: number of tabs to add
        """
        self.num_tabs += num

    def down_indent(self, num=1):
        """
        Decrease the number of tabs to use.

        :param num: number of tabs to drop.
        """
        self.num_tabs -= num
        # just checking
        if self.num_tabs < 0:
            self.num_tabs = 0

    ########################################################################

    # File access functions

    def close_file(self):
        """
        Close file for writing.
        """
        self.file_out.close()

    ########################################################################

    # Default write file with standard header and licence

    def write_file(self):
        self.add_file_header()

    def write_licence(self):
        """
        Write the licence texts to the file.
        """
        self.write_blank_comment_line()
        self.write_comment_line('<!-----------------------------------------'
                                '---------------------------------')
        # copyright can be any of the following:
        # libsbml copyright
        # libsbml copyright plus custom copyright
        # custom copyright
        if gv.library_name == 'Libsbml':
            # we are writing code for libsbml include the copyright
            self.write_libsbml_copyright()
            if gv.custom_copyright \
                    and len(gv.custom_copyright) > 0:
                # we have a custom copyright as well
                # add it
                self.write_blank_comment_line()
                self.write_custom_copyright()
        else:
            # we are writing code for something else
            if not gv.custom_copyright or len(gv.custom_copyright) == 0:
                # no copyright given so write the libsbml one
                self.write_libsbml_copyright()
            else:
                self.write_custom_copyright()

        self.write_gpl_licence()
        self.write_comment_line('--------------------------------------------'
                                '---------------------------- -->')

    def write_gpl_licence(self):
        """
        Write the GPL licence to the file.
        """
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

    def write_custom_copyright(self):
        """
        Write a custom copyright text, stored in another file,
        to the output file.
        """
        filename = gv.custom_copyright
        in_file = open(filename, 'r')
        for line in in_file:
            self.write_comment_line('{0}'.format(line))
        in_file.close()

    def write_libsbml_copyright(self):
        """
        Write libSBML copyright statement to file.
        """
        self.write_comment_line('This file is part of libSBML.  Please visit '
                                'http://sbml.org for more information about '
                                'SBML, and the latest version of libSBML.')
        self.write_blank_comment_line()
        self.write_comment_line('Copyright (C) 2019 jointly by the '
                                'following organizations:')
        self.write_comment_line('    1. California Institute of Technology, '
                                'Pasadena, CA, USA')
        self.write_comment_line('    2. University of Heidelberg, Heidelberg,'
                                ' Germany')
        self.write_blank_comment_line()
        self.write_comment_line('Copyright (C) 2013-2018 jointly by the '
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

    def add_file_header(self):
        """
        Write the file 'header' - useful comments, etc.
        """
        self.open_comment()
        self.write_comment_line('@file   {0}'.format(self.filename))
        self.write_comment_line('@brief  {0}'.format(self.brief_description))
        if gv.is_package:
            self.write_comment_line('@author SBMLTeam')
        else:
            self.write_comment_line('@author DEVISER')
        if self.extension != 'xml' and self.extension != 'rng':
            self.write_licence()
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
        if self.is_header and not self.is_list_of and self.has_enum:
            self.skip_line()
            self.write_enum_block()

    def write_enum_block(self):
        """
        Write out a big comment block, explaining what the different enums
        are used for.
        """
        self.open_comment()
        self.write_comment_line('<!-- ~ ~ ~ ~ ~ Start of common documentation'
                                ' strings ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~')
        self.write_comment_line('The following text is used as common'
                                ' documentation blocks copied multiple')
        self.write_comment_line('times elsewhere in this file. The use of'
                                ' @class is a hack needed because')
        self.write_comment_line('Doxygen\'s @copydetails command has limited'
                                ' functionality.  Symbols')
        self.write_comment_line('beginning with "doc_" are marked as ignored'
                                ' in our Doxygen configuration.')
        self.write_comment_line('~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~'
                                ' ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  -->')
        self.write_blank_comment_line()
        for enum in self.enums:
            self.write_blank_comment_line()
            self.write_comment_line('@class doc_{0}_{1}'.
                                    format(self.class_name.lower(),
                                           enum['name']))
            self.write_blank_comment_line()
            self.write_comment_line('@par')
            self.write_comment_line('The attribute "{0}" on a {1} object is '
                                    'used to  TODO:add explanation'.
                                    format(enum['name'], self.class_name))
            self.write_blank_comment_line()
            self.write_comment_line('In the SBML')
            self.write_comment_line('Level&nbsp;3 Version&nbsp;1 {0}'
                                    ' specification, the following are the'.
                                    format(self.package))
            self.write_comment_line('allowable values for "{0}":'.
                                    format(enum['name']))
            self.write_comment_line('<ul>')
            # dont write the invalid block
            for i in range(0, len(enum['values']) - 1):
                value = enum['values'][i]
                self.file_out.write(' * <li> @c "{0}", '
                                    'TODO:add description\n'.
                                    format(value['value']))
                self.write_blank_comment_line()
            self.write_comment_line('</ul>')

        self.close_comment()

    def write_class_comments(self, extension, plugin, validator):
        """
        Write a comment block about the C++ class.

        :param extension: `True` if this is an extension
        :param plugin: `True` if this is a plugin
        :param validator: `True` if a validator

        Only one of these three cases may be `True`.
        All may be `False`.
        """
        # Sanity check:
        options = [extension, plugin, validator]
        if sum(options) > 1:
            # raise an error and...Not sure what Deviser usually does
            mystr = "Error in write_class_comments - too many true values: "
            for opt in options:
                if opt:
                    mystr += "{0} ".format(opt)
            raise ValueError(mystr)

        fullname = gv.package_full_name
        up_package = SF.upper_first(self.package)
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
        self.write_comment_line('@class {0}'.format(self.name))
        if extension:
            self.write_comment_line('@sbmlbrief{0}{1}{2} Base extension'
                                    ' class for the package'
                                    '.'.format(self.open_br,
                                               self.package.lower(),
                                               self.close_br))
            self.write_blank_comment_line()
            self.write_comment_line('@htmlinclude not-sbml-warning.html')
            self.write_blank_comment_line()
            self.write_comment_line('This is the {0} package extension of the'
                                    ' SBMLExtension class that is used to '
                                    'facilitate libSBML plug-ins in the '
                                    'implementation of an SBMLLevel&nbsp;3 '
                                    'package.'.
                                    format(SF.upper_first(self.package)))
            self.write_blank_comment_line()
            self.write_comment_line('@class {0}PkgNamespaces'
                                    ''.format(up_package))
            self.write_comment_line('@sbmlbrief{0}{1}{2} SBMLNamespaces '
                                    'extension.'
                                    ''.format(self.open_br,
                                              self.package.lower(),
                                              self.close_br))
            self.write_blank_comment_line()
            self.write_comment_line('@htmlinclude not-sbml-warning.html')
        elif plugin:
            self.write_comment_line('@sbmlbrief{0}{1}{2} Extension of '
                                    '{3}.'.format(self.open_br,
                                                  self.package.lower(),
                                                  self.close_br,
                                                  self.class_object['sbase']))
        elif validator:
            self.write_comment_line('@sbmlbrief{0}{1}{2} Entry point for '
                                    '&ldquo;{1}&rdquo; package validation'
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
        """
        Is this file to be excluded? (?? from having a comment block written?)

        :param filename: the file in question
        :return: `True` if file may be excluded, `False` otherwise.
        """
        excluded = False
        excluded_files = ['Types', 'fwd', 'Error', 'ErrorTable',
                          'ConsistencyValidator', 'package', 'register']
        i = 0
        while not excluded and i < len(excluded_files):
            if filename.endswith(excluded_files[i]):
                excluded = True
            i += 1
        if not excluded:
            if filename == gv.library_name.lower():
                excluded = True
        return excluded
