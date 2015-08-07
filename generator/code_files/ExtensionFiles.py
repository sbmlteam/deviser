#!/usr/bin/env python
#
# @file    ExtensionFiles.py
# @brief   class for generating the extension files
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2014 by the California Institute of Technology
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

import ExtensionCodeFile
import ExtensionHeaderFile


class ExtensionFiles():
    """Class for all Extension files"""

    def __init__(self, package, verbose=False):
        # # members from object
        self.package = package
        self.verbose = verbose

    def write_files(self):
        self.write_header()
        self.write_code()

    def write_header(self):
        fileout = ExtensionHeaderFile.ExtensionHeaderFile(self.package)
        if not self.verbose:
            print('Writing file {}'.format(fileout.name))
        fileout.write_file()
        fileout.close_file()

    def write_code(self):
        fileout = ExtensionCodeFile.ExtensionCodeFile(self.package)
        if self.verbose:
            print('Writing file {}'.format(fileout.name))
        fileout.write_file()
        fileout.close_file()

    def test_func(self):
        self.write_files()
 #       if self.class_object['hasListOf']:
 #           lo_working_class = self.create_list_of_description()
#            self.write_header(lo_working_class)
 #           self.write_code(lo_working_class)
