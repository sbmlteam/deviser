#!/usr/bin/env python
#
# @file    RegisterFile.py
# @brief   class for generating cmake register file
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

from base_files import BaseCppFile
from util import strFunctions, global_variables


class RegisterFile():
    """Class for CMake package files"""

    def __init__(self, name, package, src):

        self.package = package.lower()
        self.src = src

        if src:
            extension = 'cxx'
        else:
            extension = 'h'
        self.fileout = BaseCppFile.BaseCppFile(name, extension, None)

        self.fileout.brief_description = 'CMake register file for {0} ' \
                                         'package'.format(self.package)

        self.cap_package = self.package.upper()
        self.up_package = strFunctions.upper_first(self.package)

        self.language = global_variables.language
        self.cap_language = global_variables.language.upper()

        self.open_br = '{'
        self.close_br = '}'

    ########################################################################

    # Write specific code

    def write_header_file(self):
        """
        Add code to the .h file.

        NB I think that's correct? It doesn't write another file?
        So might need renaming.

        """
        self.fileout.skip_line()
        self.fileout.write_line('#ifdef USE_{0}'.format(self.cap_package))
        self.fileout.up_indent()
        self.fileout.write_line_verbatim(('#include '
                                          '<{0}/packages/{1}/extension/'
                                          '{2}Extension.h>').
                                         format(self.language,
                                                self.package,
                                                self.up_package))
        self.fileout.down_indent()
        self.fileout.write_line('#endif')
        self.fileout.skip_line()

    def write_src_file(self):
        """
        Add lines to .cxx file.

        TODO see comment on previous function; that applies here, too.
        """
        self.fileout.skip_line()
        self.fileout.write_line('#ifdef USE_{0}'.
                                format(self.cap_package))
        self.fileout.up_indent()
        self.fileout.write_line('{0}Extension::init();'.
                                format(self.up_package))
        self.fileout.down_indent()
        self.fileout.write_line('#endif')
        self.fileout.skip_line()
    ########################################################################

    # Write file

    def write_file(self):
        """
        Write the required file.
        """
        self.fileout.write_file()
        if self.src:
            self.write_src_file()
        else:
            self.write_header_file()

    def close_file(self):
        """
        Utility wrapper function to close a file.
        """
        self.fileout.close_file()
