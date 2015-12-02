#!/usr/bin/env python
#
# @file    DowncastPackagesFile.py
# @brief   class for generating downcast packages file
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


class DowncastPackagesFile():
    """Class for downcast Packages files"""

    def __init__(self, name, package, binding, elements, plugins=None,
                 local=False):

        if not plugins:
            plugins = []
        self.binding = binding
        self.package = package.lower()
        self.cap_package = self.package.upper()
        self.up_package = strFunctions.upper_first(self.package)
        self.local = local

        if self.local and len(name) > 0:
            self.fileout = BaseCppFile.BaseCppFile(name, 'i', None)
            self.fileout.brief_description = 'Casting to most specific ' \
                                             'packages object for ' \
                                             '{0}'.format(binding)
        elif binding == 'csharp' or binding == 'java':
            self.fileout = BaseCppFile.BaseCppFile(name, 'i', None)
            self.fileout.brief_description = 'Casting to most specific ' \
                                             'packages object for ' \
                                             '{0}'.format(binding)
        else:
            self.fileout = BaseCppFile.BaseCppFile(name, 'cpp', None)
            self.fileout.brief_description = 'Casting to most specific ' \
                                             'packages object for ' \
                                             '{0}'.format(binding)

        self.elements = elements
        self.plugins = plugins

        self.language = global_variables.language
        self.cap_language = global_variables.language.upper()
        self.base = global_variables.std_base

    ########################################################################

    # Write binding specific code

    # write the local-downcast-packages-{}.cpp for
    # javascript, perl,python,r,ruby
    def write_binding_specific_cpp_code(self):
        self.fileout.skip_line(2)
        self.fileout.write_line('#ifdef USE_{0}'.format(self.cap_package))
        line = 'else if (pkgName == \"{0}\")'.format(self.package)
        self.fileout.write_line(line)
        self.fileout.write_line('{')
        self.fileout.up_indent()
        self.fileout.write_line('switch ( sb->getTypeCode() )')
        self.fileout.write_line('{')
        self.fileout.up_indent()
        self.fileout.write_line('case {0}_LIST_OF:'.format(self.cap_language))
        self.fileout.up_indent()
        self.fileout.write_line('name = sb->getElementName();')
        code = self.create_list_of_block()
        self.fileout.write_implementation_block(code['code_type'], code['code'])
        self.fileout.skip_line()
        self.fileout.write_line('return SWIGTYPE_p_ListOf;')
        self.fileout.skip_line()
        self.fileout.down_indent()
        self.write_element_types()
        self.fileout.write_line('default:')
        self.fileout.up_indent()
        self.fileout.write_line('return SWIGTYPE_p_{0};'.format(self.base))
        self.fileout.down_indent()
        self.fileout.write_line('}')
        self.fileout.down_indent()
        self.fileout.write_line('}')
        self.fileout.skip_line()
        self.fileout.write_line('#endif // USE_{0}'.format(self.cap_package))
        self.fileout.skip_line()

    # write the local-packages-{}.i for csharp/java
    def write_binding_specific_i_code(self):
        self.fileout.skip_line(2)
        self.fileout.write_line('#ifdef USE_{0}'.format(self.cap_package))

        if self.binding == 'csharp':
            code = 'cscode'
            public = 'public override'
            args = 'IntPtr cPtr, bool owner'
            equals = '.Equals(IntPtr.Zero)'
        else:
            code = 'javacode'
            public = 'public'
            args = 'long cPtr, boolean owner'
            equals = ' == 0'

        self.fileout.write_line('%typemap({0}) {1}'
                                'Extension'.format(code, self.up_package))
        self.fileout.write_line('%{')
        self.fileout.up_indent()
        self.write_plugin_downcast(public, args, equals)
        self.fileout.skip_line()
        self.write_element_downcast(public, args, equals)
        self.fileout.down_indent()
        self.fileout.skip_line()
        self.fileout.write_line('%}')
        self.fileout.skip_line()
        self.write_covariant_clone()
        self.fileout.skip_line()
        self.write_covariant_list_of()
        self.fileout.skip_line()
        self.write_exception_list()
        self.fileout.skip_line()
        self.write_base_classes_cast()
        self.fileout.skip_line()
        self.fileout.write_line('#endif // USE_{0}'.format(self.cap_package))
        self.fileout.skip_line()

    # write the local-{}.i for
    # javascript, perl,python,r,ruby
    def write_local_file(self):
        self.fileout.skip_line(2)
        self.fileout.write_line('#ifdef USE_{0}'.format(self.cap_package))
        self.fileout.skip_line()
        self.write_exception_list()
        self.fileout.skip_line()
        self.write_base_classes_cast()
        self.fileout.skip_line()
        self.fileout.write_line('#endif // USE_{0}'.format(self.cap_package))
        self.fileout.skip_line()

    #########################################################################

    # Function used by write_binding_specific_i_code

    def write_plugin_downcast(self, public, args, equals):
        self.fileout.write_line('{0} {1}Plugin Downcast{1}'
                                'Plugin({2})'.format(public, self.base, args))
        self.fileout.write_line('{')
        self.fileout.up_indent()
        self.fileout.write_line('if (cPtr{0}) return null;'.format(equals))
        self.fileout.skip_line()
        self.fileout.write_line('{0}Plugin sbp = new {0}Plugin'
                                '(cPtr, false);'.format(self.base))
        self.fileout.write_line('{0} sb = sbp.getParent{1}'
                                'Object();'.format(self.base,
                                                   self.cap_language))
        self.fileout.skip_line()
        self.fileout.write_line('switch ( sb.getTypeCode() )')
        self.fileout.write_line('{')
        self.fileout.up_indent()
        for plugin in self.plugins:
            cap_base = plugin['sbase'].upper()
            up_base = strFunctions.upper_first(plugin['sbase'])
            self.fileout.write_line('case (int) lib{0}.{1}_'
                                    '{2}:'.format(self.language,
                                                 self.cap_language, cap_base))
            self.fileout.up_indent()
            self.fileout.write_line(' return new {0}{1}Plugin'
                                    '(cPtr, owner);'.format(self.up_package,
                                                            up_base))
            self.fileout.down_indent()
            self.fileout.skip_line()
        self.fileout.write_line('default:')
        self.fileout.up_indent()
        self.fileout.write_line('return new {0}Plugin(cPtr, '
                                'owner);'.format(self.base))
        self.fileout.down_indent()
        self.fileout.down_indent()
        self.fileout.write_line('}')
        self.fileout.down_indent()
        self.fileout.write_line('}')

    def write_element_downcast(self, public, args, equals):
        string = 'string' if self.binding == 'csharp' else 'String'
        self.fileout.write_line('{0} {1} Downcast{1}({2})'.format(public,
                                                                  self.base,
                                                                  args))
        self.fileout.write_line('{')
        self.fileout.up_indent()
        self.fileout.write_line('if (cPtr{0}) return null;'.format(equals))
        self.fileout.skip_line()
        self.fileout.write_line('{0} sb = new {0}(cPtr, '
                                'false);'.format(self.base))
        self.fileout.write_line('switch ( sb.getTypeCode() )')
        self.fileout.write_line('{')
        self.fileout.up_indent()
        self.fileout.write_line('case (int) lib{0}.{1}_'
                                'LIST_OF:'.format(self.language,
                                                  self.cap_language))
        self.fileout.up_indent()
        self.fileout.write_line('{0} name = sb.getElementName();'.format(string))
        code = self.create_list_of_block(self.binding)
        self.fileout.write_implementation_block(code['code_type'], code['code'])
        self.fileout.skip_line()
        self.fileout.write_line('return new ListOf(cPtr, owner);')
        self.fileout.skip_line()
        self.fileout.down_indent()
        for element in self.elements:
            self.fileout.write_line('case (int) lib{0}.'
                                    '{1}:'.format(self.language,
                                                 element['typecode']))
            self.fileout.up_indent()
            self.fileout.write_line(' return new {0}(cPtr, '
                                    'owner);'.format(element['name']))
            self.fileout.down_indent()
            self.fileout.skip_line()
        self.fileout.write_line('default:')
        self.fileout.up_indent()
        self.fileout.write_line('return new {0}(cPtr, owner);'.format(self.base))
        self.fileout.down_indent()
        self.fileout.down_indent()
        self.fileout.write_line('}')
        self.fileout.down_indent()
        self.fileout.write_line('}')

    def write_covariant_clone(self):
        rtype = 'COVARIANT_RTYPE_CLONE'
        self.write_specific_line(rtype, '{0}Extension'.format(self.up_package))
        for element in self.elements:
            self.write_specific_line(rtype, element['name'])
        for element in self.elements:
            if element['hasListOf']:
                name = strFunctions.list_of_name(element['name'])
                self.write_specific_line(rtype, name)

    def write_exception_list(self):
        rtype = '{0}CONSTRUCTOR_EXCEPTION'.format(self.cap_language)
        self.write_specific_line(rtype, '{0}Pkg'
                                        'Namespaces'.format(self.up_package))
        for element in self.elements:
            self.write_specific_line(rtype, element['name'])
        for element in self.elements:
            if element['hasListOf']:
                name = strFunctions.list_of_name(element['name'])
                self.write_specific_line(rtype, name)

    def write_covariant_list_of(self):
        rtype = 'COVARIANT_RTYPE_LISTOF_GET_REMOVE'
        for element in self.elements:
            if element['hasListOf']:
                self.write_specific_line(rtype, element['name'])

    def write_specific_line(self, rtype, ctype):
        self.fileout.write_line('{0}({1})'.format(rtype, ctype))

    def write_base_classes_cast(self):
        if self.local:
            my_map = 'out'
            call = ''
        elif self.binding == 'csharp':
            my_map = '\"csout\"'
            call = '$imcall'
        else:
            my_map = '\"javaout\"'
            call = '$jnicall'
        for element in self.elements:
            if element['abstract']:
                name = element['name']
                self.write_cast(name, call, my_map)

    def write_cast(self, name, call, my_map):
        if self.local:
            self.fileout.write_line('/**')
            self.fileout.write_line_verbatim(' * Convert {0} objects into the '
                                             'most specific object '
                                             'possible.'.format(name))
            self.fileout.write_line(' */')
        else:
            self.fileout.write_line('//')
            self.fileout.write_line('// Convert {0} objects into the most '
                                    'specific '
                                    'object possible.'.format(name))
            self.fileout.write_line('//')
        self.fileout.write_line('%typemap({0}) {1}*'.format(my_map, name))
        self.fileout.write_line('{')
        self.fileout.up_indent()
        if self.local:
            self.fileout.write_line('$result = SWIG_NewPointerObj($1, '
                                    'GetDowncastSwigTypeForPackage($1, '
                                    '\"{0}\"), $owner | '
                                    '%newpointer_flags);'.format(self.package))
        else:
            self.fileout.write_line('return ({0}) lib{1}.Downcast{2}({3}, '
                                    '$owner);'.format(name, self.language,
                                                      self.base, call))
        self.fileout.down_indent()
        self.fileout.write_line('}')
        self.fileout.skip_line()

    ########################################################################

    def write_element_types(self):
        for element in self.elements:
            self.fileout.write_line('case {0}:'.format(element['typecode']))
            self.fileout.up_indent()
            self.fileout.write_line('return SWIGTYPE_p_'
                                    '{0};'.format(element['name']))
            self.fileout.down_indent()
            self.fileout.skip_line()

    def create_list_of_block(self, b_type=''):
        line = []
        count = 0
        for element in self.elements:
            if element['hasListOf']:
                count += 1
                up_loname = strFunctions.list_of_name(element['name'])
                loname = strFunctions.lower_first(up_loname)
                if len(line) > 0:
                    line.append('else if')
                if b_type == 'java':
                    line.append('name.equals(\"{0}\")'.format(loname))
                else:
                    line.append('name == \"{0}\"'.format(loname))
                if b_type == 'java' or b_type == 'csharp':
                    line.append('return new {0}(cPtr, owner)'.format(up_loname))
                else:
                    line.append('return SWIGTYPE_p_{0}'.format(up_loname))
        if count == 0:
            code = self.create_code_block('blank', [])
        elif count == 1:
            code = self.create_code_block('if', line)
        else:
            code = self.create_code_block('else_if', line)
        return code

    ########################################################################

    # Write file

    def write_file(self):
        self.fileout.write_file()
        if self.local:
            self.write_local_file()
        elif self.binding == 'csharp' or self.binding == 'java':
            self.write_binding_specific_i_code()
        else:
            self.write_binding_specific_cpp_code()

    def close_file(self):
        if self.fileout:
            self.fileout.close_file()

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
