#!/usr/bin/env python
#
# @file    CMakeFiles.py
# @brief   class for generating the cmake files
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

import os

from util import global_variables
import PackageFile
import RegisterFile


class CMakeFiles():
    """Class for all cmake files"""

    def __init__(self, pkg_object, this_dir, verbose=False):
        self.verbose = verbose
        self.this_dir = this_dir

        # # members from object
        self.package = pkg_object['name']

        self.language = global_variables.language
        self.elements = pkg_object['baseElements']
        self.plugins = pkg_object['plugins']

    #########################################################################

    def write_package_files(self):
        name = '{}-package'.format(self.package)
        ext = PackageFile.PackageFile(name, self.package, False)
        if self.verbose:
            print('Writing file {}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()
        os.chdir('src')
        ext = PackageFile.PackageFile(name, self.package, True)
        if self.verbose:
            print('Writing file {}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()
        os.chdir(self.this_dir)

    def write_register_files(self):
        name = '{}-register'.format(self.package)
        ext = RegisterFile.RegisterFile(name, self.package, False)
        if self.verbose:
            print('Writing file {}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()
        ext = RegisterFile.RegisterFile(name, self.package, True)
        if self.verbose:
            print('Writing file {}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()

    ########################################################################

    def write_files(self):
        self.write_package_files()
        os.chdir('src/{}/packages'.format(self.language))
        self.write_register_files()
        os.chdir(self.this_dir)
