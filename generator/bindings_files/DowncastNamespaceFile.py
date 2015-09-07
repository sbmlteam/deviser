#!/usr/bin/env python
#
# @file    DowncastNamespaceFile.py
# @brief   class for generating downcast namespace file
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

from base_files import BaseCppFile, BaseInterfaceFile
from util import strFunctions, global_variables


class DowncastNamespaceFile():
    """Class for downcast namespace files"""

    def __init__(self, name, package, binding):

        self.binding = binding
        self.package = package.lower()
        self.cap_package = self.package.upper()
        self.up_package = strFunctions.upper_first(self.package)

        if binding == 'csharp' or binding == 'java':
            self.fileout = BaseInterfaceFile.BaseInterfaceFile(name)
            self.fileout.brief_description = 'Casting to most specific ' \
                                             'namespace object for ' \
                                             '{}'.format(binding)
        else:
            self.fileout = BaseCppFile.BaseCppFile(name, 'cpp', None)
            self.fileout.brief_description = 'Casting to most specific ' \
                                             'namespace object for ' \
                                             '{}'.format(binding)

        self.cap_language = global_variables.language.upper()

    ########################################################################

    # Write binding specific code

    def write_binding_specific_i_code(self):
        self.fileout.skip_line(2)
        self.fileout.write_line('#ifdef USE_{}'.format(self.cap_package))
        self.fileout.write_line('%pragma({}) modulecode ='.format(self.binding))
        self.fileout.write_line('%{')
        self.fileout.up_indent()
        self.fileout.write_line('if (ns.hasURI({}Extension.'
                                'getXmlnsL3V1V1()))'.format(self.up_package))
        self.fileout.write_line('{')
        self.fileout.up_indent()
        self.fileout.write_line('return new {}PkgNamespaces(cPtr, '
                                'owner);'.format(self.up_package))
        self.fileout.down_indent()
        self.fileout.write_line('}')
        self.fileout.down_indent()
        self.fileout.write_line('%}')
        self.fileout.write_line('#endif /* USE_{} */'.format(self.cap_package))
        self.fileout.skip_line()

    def write_binding_specific_cpp_code(self):
        self.fileout.skip_line(2)
        self.fileout.write_line('#ifdef USE_{}'.format(self.cap_package))
        line = 'if (pkgName == \"{}\")'.format(self.package)
        self.fileout.write_line(line)
        self.fileout.write_line('{')
        self.fileout.up_indent()
        self.fileout.write_line('return SWIGTYPE_p_{}'
                                'ExtensionNamespacesT_{}'
                                'Extension_t;'.format(self.cap_language,
                                                      self.up_package))
        self.fileout.down_indent()
        self.fileout.write_line('}')
        self.fileout.write_line('#endif // USE_{}'.format(self.cap_package))
        self.fileout.skip_line()

    ########################################################################

    # Write file

    def write_file(self):
        self.fileout.write_file()
        if self.binding == 'csharp' or self.binding == 'java':
            self.write_binding_specific_i_code()
        else:
            self.write_binding_specific_cpp_code()

    def close_file(self):
        self.fileout.close_file()
