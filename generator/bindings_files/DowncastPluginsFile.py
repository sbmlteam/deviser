#!/usr/bin/env python
#
# @file    DowncastPluginsFile.py
# @brief   class for generating downcast plugins file
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

from base_files import BaseCppFile
from util import strFunctions, global_variables


class DowncastPluginsFile():
    """Class for downcast Packages files"""

    def __init__(self, name, package, binding, plugins):

        self.binding = binding
        self.package = package.lower()
        self.cap_package = self.package.upper()
        self.up_package = strFunctions.upper_first(self.package)

        if binding == 'csharp' or binding == 'java':
            self.fileout = None
        else:
            self.fileout = BaseCppFile.BaseCppFile(name, 'cpp', None)
            self.fileout.brief_description = 'Casting to most specific ' \
                                             'plugins object for ' \
                                             '{0}'.format(binding)

        self.cap_language = global_variables.language.upper()
        self.plugins = plugins
        self.base = global_variables.std_base

    ########################################################################

    # Write binding specific code

    def write_binding_specific_cpp_code(self):
        self.fileout.skip_line(2)
        self.fileout.write_line('#ifdef USE_{0}'.format(self.cap_package))
        line = 'if (pkgName == \"{0}\")'.format(self.package)
        self.fileout.write_line(line)
        self.fileout.write_line('{')
        self.fileout.up_indent()
        code = self.create_if_block()
        self.fileout.write_implementation_block(code['code_type'], code['code'])
        self.fileout.down_indent()
        self.fileout.write_line('}')
        self.fileout.skip_line()
        self.fileout.write_line('#endif // USE_{0}'.format(self.cap_package))
        self.fileout.skip_line()

    ########################################################################

    def create_if_block(self):
        line = []
        for plugin in self.plugins:
            name = plugin['sbase'].upper()
            if len(line) > 0:
                line.append('else if')
            line.append('sb->getTypeCode() == {0}_{1}'.format(self.cap_language,
                                                            name))
            line.append('return SWIGTYPE_p_{0}{1}Plugin'.format(self.up_package,
                                                              plugin['sbase']))
        if len(self.plugins) == 0:
            code = self.create_code_block('blank', [])
        elif len(self.plugins) == 1:
            code = self.create_code_block('if', line)
        else:
            code = self.create_code_block('else_if', line)
        return code

    ########################################################################

    # Write file

    def write_file(self):
        if self.fileout:
            self.fileout.write_file()
            self.write_binding_specific_cpp_code()

    def close_file(self):
        if self.fileout:
            self.fileout.close_file()

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
