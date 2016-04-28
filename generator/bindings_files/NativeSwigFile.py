#!/usr/bin/env python
#
# @file    NativeSwigFile.py
# @brief   class for generating swig files
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


class NativeSwigFile():
    """Class for SWIG files"""

    def __init__(self, name, package, elements, plugins, is_header):

        self.package = package.lower()
        self.cap_package = self.package.upper()
        self.up_package = strFunctions.upper_first(self.package)
        self.is_header = is_header

        if is_header:
            self.fileout = BaseCppFile.BaseCppFile(name, 'h', None)
            self.fileout.brief_description = 'SWIG header file'
        else:
            self.fileout = BaseCppFile.BaseCppFile(name, 'i', None)
            self.fileout.brief_description = 'SWIG local file'

        self.elements = elements
        self.plugins = plugins

        self.language = global_variables.language
        self.cap_language = global_variables.language.upper()
        self.base = global_variables.std_base

        self.ext_dir = '{0}/packages/{1}/extension/'.format(self.language,
                                                          self.package)
        self.common_dir = '{0}/packages/{1}/common/'.format(self.language,
                                                          self.package)
        self.base_dir = '{0}/packages/{1}/{0}/'.format(self.language,
                                                       self.package)

    ########################################################################

    def write_swig_header_code(self):
        self.fileout.skip_line(2)
        self.fileout.write_line('#ifdef USE_{0}'.format(self.cap_package))
        self.fileout.skip_line()
        self.write_includes('#')
        self.fileout.skip_line()
        self.fileout.write_line('#endif // USE_{0}'.format(self.cap_package))
        self.fileout.skip_line()

    def write_swig_interface_code(self):
        self.fileout.skip_line(2)
        self.fileout.write_line('#ifdef USE_{0}'.format(self.cap_package))
        self.fileout.skip_line()
        self.write_remove_objects()
        self.fileout.skip_line()
        self.fileout.write_line('%template ({0}PkgNamespaces) {1}Extension'
                                'Namespaces<{0}'
                                'Extension>;'.format(self.up_package,
                                                     self.cap_language))
        self.fileout.skip_line()
        self.write_includes('%')
        self.fileout.skip_line()
        self.fileout.write_line('#endif /* USE_{0} */'.format(self.cap_package))
        self.fileout.skip_line()

    #########################################################################

    def write_swig_library_header_code(self):
        self.fileout.skip_line(2)
        self.fileout.write_line('#include <{0}/common/lib{0}-version.h>'
                                ''.format(self.language.lower()))
        self.fileout.write_line('#include <{0}/common/{1}OperationReturnValues'
                                '.h>'.format(self.language.lower(),
                                             global_variables.prefix))
        self.fileout.skip_line()
        self.fileout.write_line('#include <{0}/{1}Types.h>'
                                ''.format(self.language.lower(),
                                          global_variables.prefix))
        self.fileout.skip_line()
        self.fileout.write_line('#include \"ListWrapper.h\"')
        self.fileout.skip_line()
        self.fileout.write_line('#include <sbml/math/MathML.h>')
        self.fileout.write_line('#include <sbml/math/ASTNode.h>')
        self.fileout.skip_line()
        self.fileout.write_line('#include <sbml/xml/XMLAttributes.h>')
        self.fileout.write_line('#include <sbml/xml/XMLConstructorException.h>')
        self.fileout.write_line('#include <sbml/xml/XMLNamespaces.h>')
        self.fileout.write_line('#include <sbml/xml/XMLToken.h>')
        self.fileout.write_line('#include <sbml/xml/XMLNode.h>')
        self.fileout.write_line('#include <sbml/xml/XMLTriple.h>')
        self.fileout.write_line('#include <sbml/xml/XMLOutputStream.h>')
        self.fileout.write_line('#include <sbml/xml/XMLInputStream.h>')
        self.fileout.write_line('#include <sbml/xml/XMLError.h>')
        self.fileout.write_line('#include <sbml/xml/XMLErrorLog.h>')
        self.fileout.skip_line()


    def write_swig_library_interface_code(self):
        self.fileout.skip_line(2)
    ########################################################################
    # Function used
    
    def write_includes(self, sep):
        self.write_include_line(sep, '{0}Extension'.format(self.up_package),
                                self.ext_dir)
        for plugin in self.plugins:
            name = '{0}{1}Plugin'.format(self.up_package, plugin['sbase'])
            self.write_include_line(sep, name, self.ext_dir)
        if sep == '#':
            self.write_include_line(sep, '{0}Extension'
                                         'Types'.format(self.up_package),
                                    self.common_dir)
        for element in self.elements:
            name = element['name']
            self.write_include_line(sep, name, self.base_dir)
        for element in self.elements:
            if element['hasListOf']:
                name = strFunctions.list_of_name(element['name'])
                self.write_include_line(sep, name, self.base_dir)
                
    def write_remove_objects(self):
        for element in self.elements:
            if element['hasListOf']:
                self.fileout.write_line('%newobject '
                                        'remove{0};'.format(element['name']))

    def write_include_line(self, sep, ctype, my_dir):
        self.fileout.write_line_verbatim('{0}include <{1}{2}.h>'.format(sep,
                                                                     my_dir,
                                                                     ctype))

    ########################################################################

    # Write file

    def write_file(self):
        if global_variables.is_package:
            self.fileout.write_file()
            if self.is_header:
                self.write_swig_header_code()
            else:
                self.write_swig_interface_code()
        else:
            self.write_library_file()

    def close_file(self):
        if self.fileout:
            self.fileout.close_file()

    def write_library_file(self):
        self.fileout.write_file()
        if self.is_header:
            self.write_swig_library_header_code()
        else:
            self.write_swig_library_interface_code()


    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
