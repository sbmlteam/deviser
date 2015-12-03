#!/usr/bin/env python
#
# @file    ExtensionHeaderFile.py
# @brief   class for generating header file for the given class
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
from . cpp_functions import *
from util import query, strFunctions


class ExtensionHeaderFile(BaseCppFile.BaseCppFile):
    """Class for all Extension Header files"""

    def __init__(self, package, filetype=''):

        self.up_package = strFunctions.upper_first(package['name'])
        if filetype == '':
            self.name = '{0}Extension'.format(self.up_package)
            self.class_name = self.name
        elif filetype == 'types':
            self.name = '{0}ExtensionTypes'.format(self.up_package)
        elif filetype == 'fwd':
            self.name = '{0}fwd'.format(package['name'])

        self.brief_description = \
            'Definition of {0}.'.format(self.name)

        BaseCppFile.BaseCppFile.__init__(self, self.name, 'h',
                                         None)

        # members from object
        self.package = package['name']
        self.cap_package = package['name'].upper()
        self.baseClass = '{0}Extension'.format(self.cap_language)
        self.class_name = self.name

        self.elements = package['elements']
        self.number = package['number']
        self.enums = package['enums']
        self.offset = package['offset']
        self.plugins = package['plugins']
        self.num_versions = 1
        if 'num_versions' in package:
            self.num_versions = package['num_versions']

        # create a class object so we can just reuse code
        self.class_object['package'] = self.package
        self.class_object['name'] = self.name
        self.class_object['concretes'] = []
        self.class_object['baseClass'] = self.baseClass
        self.class_object['attribs'] = []
        self.class_object['has_children'] = False
        self.class_object['child_elements'] = []
        self.class_object['overwrites_children'] = False
        self.class_object['name'] = self.name
    ########################################################################

    # Functions for writing the class
    def write_class(self, base_class, class_name):
        self.write_line('class {0}_EXTERN {1} : public {2}'
                        .format(self.library_name.upper(),
                                class_name, base_class))
        self.write_line('{')
        self.write_line('public:')
        self.skip_line()
        self.up_indent()
        self.write_attribute_functions()
        self.write_constructors()
        self.write_virtual_functions()
        self.write_init_function()
        self.down_indent()
        self.write_line('};\n')

    ########################################################################
    # Functions for writing specific includes and forward declarations

    def write_common_includes(self):
        self.write_line_verbatim('#include <{0}/common'
                                 '/extern.h>'.format(self.language))
        self.write_line_verbatim('#include <{0}/{1}'
                                 'TypeCodes.h>'.format(self.language,
                                                       self.cap_language))

    def write_general_includes(self):
        lang = self.language
        up_lang = self.cap_language
        self.write_line_verbatim('#include <{0}/extension/'
                                 '{1}Extension.h>'.format(lang, up_lang))
        self.write_line_verbatim('#include <{0}/extension/{1}'
                                 'ExtensionNamespaces.h>'.format(lang, up_lang))
        self.write_line_verbatim('#include <{0}/extension/{1}'
                                 'ExtensionRegister.h>'.format(lang, up_lang))
        self.skip_line()
        self.write_line('#ifndef {0}_CREATE_NS'.format(self.cap_package))
        self.write_line('#define {0}_CREATE_NS(variable, {1}'
                        'ns)\\'.format(self.cap_package, self.language))
        self.write_line('  EXTENSION_CREATE_NS({0}PkgNamespaces, variable, '
                        '{1}ns);'.format(self.up_package, self.language))
        self.write_line('#endif')
        self.skip_line()
        if self.num_versions > 1:
            self.write_line('#ifndef {0}_CREATE_NS_WITH_'
                            'VERSION'.format(self.cap_package))
            self.write_line('#define {0}_CREATE_NS_WITH_'
                            'VERSION(variable, {1}'
                            'ns, version)\\'.format(self.cap_package,
                                                    self.language))
            self.write_line('  EXTENSION_CREATE_NS_WITH_VERSION('
                            '{0}PkgNamespaces, variable, '
                            '{1}ns, version);'.format(self.up_package,
                                                     self.language))
            self.write_line('#endif')
            self.skip_line()
        self.write_line_verbatim('#include <vector>')

    ########################################################################

    # function to write the constructors
    def write_constructors(self):
        constructor = Constructors.Constructors(self.language,
                                                self.is_cpp_api,
                                                self.class_object)
        code = constructor.write_constructor()
        self.write_function_declaration(code)

        code = constructor.write_copy_constructor()
        self.write_function_declaration(code)

        code = constructor.write_assignment_operator()
        self.write_function_declaration(code)

        code = constructor.write_clone()
        self.write_function_declaration(code)

        code = constructor.write_destructor()
        self.write_function_declaration(code)

    ########################################################################

    # function to write the static get functions
    def write_attribute_functions(self):
        self.class_object['class_attributes'] \
            = query.get_static_extension_attribs(self.num_versions)
        attrib_functions = SetGetFunctions.SetGetFunctions(self.language,
                                                           self.is_cpp_api,
                                                           self.is_list_of,
                                                           self.class_object)
        num_attributes = len(self.class_object['class_attributes'])
        for i in range(0, num_attributes):
            code = attrib_functions.write_static_extension_get(i)
            self.write_function_declaration(code)

    ########################################################################

    # Functions for writing virtual functions

    def write_virtual_functions(self):
        ext_functions = ExtensionFunctions.ExtensionFunctions(self.language,
                                                              self.package,
                                                              self.elements,
                                                              self.offset)

        code = ext_functions.write_get_name()
        self.write_function_declaration(code)

        code = ext_functions.write_get_uri()
        self.write_function_declaration(code)

        code = ext_functions.write_get_other('Level')
        self.write_function_declaration(code)

        code = ext_functions.write_get_other('Version')
        self.write_function_declaration(code)

        code = ext_functions.write_get_other('PackageVersion')
        self.write_function_declaration(code)

        code = ext_functions.write_get_namespaces()
        self.write_function_declaration(code)

        code = ext_functions.write_get_string_typecode()
        self.write_function_declaration(code)

        code = ext_functions.write_get_error_table()
        self.write_function_declaration(code, True)

        code = ext_functions.write_get_error_table_index()
        self.write_function_declaration(code, True)

        code = ext_functions.write_get_error_offset()
        self.write_function_declaration(code, True)

        if self.num_versions > 1:
            code = ext_functions.write_has_multiple_versions()
            self.write_function_declaration(code, True)

    ########################################################################

    # write the init function
    def write_init_function(self):
        init_functions = \
            ExtensionInitFunctions.ExtensionInitFunctions(self.language,
                                                          self.package,
                                                          self.std_base,
                                                          [], [])
        code = init_functions.write_init_function()
        self.write_function_declaration(code, True)

    ########################################################################

    # write the instantiation
    def write_extension_instance(self):
        up_package = strFunctions.upper_first(self.package)
        self.open_comment()
        self.write_blank_comment_line()
        self.write_comment_line('Required typedef definitions')
        self.write_blank_comment_line()
        self.write_comment_line('{0}PkgNamespace is derived from {1}Namespaces '
                                'class and used when creating an object of {2} '
                                'derived classes defined in the {3} '
                                'package'.format(up_package,
                                                 self.cap_language,
                                                 self.std_base, self.package))
        self.write_blank_comment_line()
        self.write_comment_line('{0}ExtensionNamespaces<{1}Extension> must be '
                                'instantiated in {1}Extension.cpp for '
                                'DLL'.format(self.cap_language, up_package))
        self.write_blank_comment_line()
        self.close_comment()
        self.write_line('typedef {0}ExtensionNamespaces<{1}Extension> '
                        '{1}PkgNamespaces;'.format(self.cap_language,
                                                   up_package))

    ########################################################################

    # write the type defs

    def write_type_defs(self):
        # write the enum for typecodes
        self.write_type_code_enum_header(self.package)
        values = query.get_typecode_enum(self.elements)
        name = '{0}{1}TypeCode_t'.format(self.cap_language, self.up_package)
        self.write_enum(name, self.number, values[0], values[1], values[2]+5)
        self.skip_line(2)

        num_enums = len(self.enums)
        if num_enums == 0:
            return
        init_functions = \
            ExtensionInitFunctions.ExtensionInitFunctions(self.language,
                                                          self.package,
                                                          self.std_base,
                                                          self.enums,
                                                          [])
#        code = init_functions.write_init_function()
#        self.write_function_declaration(code, True)
        self.is_cpp_api = False
        for i in range(0, len(self.enums)):
            name = self.enums[i]['name'] + '_t'
            values = query.get_enum(self.enums[i])
            self.write_enum(name, 0, values[0], values[1], values[2]+5)
            self.skip_line(2)
            code = init_functions.write_enum_to_string_function(i)
            self.write_function_declaration(code)
            code = init_functions.write_enum_from_string_function(i)
            self.write_function_declaration(code)
            code = init_functions.write_is_valid_enum_function(i)
            self.write_function_declaration(code)
            code = init_functions.write_is_valid_enum_string_function(i)
            self.write_function_declaration(code)

    ########################################################################

    # Functions for writing extension types

    def write_type_includes(self):
        self.write_line_verbatim('#include <{0}/packages/{1}/common/{1}'
                                 'fwd.h>'.format(self.language, self.package))
        self.skip_line()
        self.write_line_verbatim('#include <{0}/packages/{1}/extension/{2}'
                                 'Extension.h>'.format(self.language,
                                                       self.package,
                                                       self.up_package))
        self.write_line_verbatim('#include <{0}/packages/{1}/extension/'
                                 '{2}{3}Document'
                                 'Plugin.h>'.format(self.language, self.package,
                                                    self.up_package,
                                                    self.cap_language))

        for plugin in self.plugins:
            self.write_line_verbatim('#include <{0}/packages/{1}/extension/{2}{3}'
                                     'Plugin.h>'.format(self.language,
                                                        self.package,
                                                        self.up_package,
                                                        plugin['sbase']))
        self.skip_line()

        for element in self.elements:
            self.write_line_verbatim('#include <{0}/packages/{1}/{0}/{2}.'
                                     'h>'.format(self.language, self.package,
                                                 element['name']))

    ########################################################################

    # Functions for writing teh fwd declarations file

    def write_docs_fwd(self):
        forward_dec = 'Forward declaration of all opaque C types.'
        fwd_text = 'Declaring all types up-front avoids \"redefinition ' \
                   'of type Foo\" compile errors and allows our combined ' \
                   'C/C++ headers to depend minimally upon each other.  Put ' \
                   'another way, the type definitions below serve the same ' \
                   'purpose as \"class Foo;\" forward declarations in ' \
                   'C++ code.'
        self.open_comment()
        self.write_comment_line(forward_dec)
        self.write_blank_comment_line()
        self.write_comment_line(fwd_text)
        self.close_comment()
        self.skip_line()

    def write_class_or_struct(self):
        self.write_line('#ifdef __cplusplus')
        self.write_line('#     define CLASS_OR_STRUCT class')
        self.write_line('#else')
        self.write_line('#     define CLASS_OR_STRUCT struct')
        self.write_line('#endif  /* __cplusplus */')

    def write_classes(self):
        width = query.get_max_length(self.elements, 'name')
        for element in self.elements:
            self.write_spaced_line('typedef CLASS_OR_STRUCT {0:{width}} '
                                   '{0}_t;'.format(element['name'],
                                                   width=width))

    def write_end_class_or_struct(self):
        self.write_line('#undef CLASS_OR_STRUCT')

    ########################################################################

    # Functions for writing definition declaration

    def write_defn_begin(self):
        self.skip_line(2)
        self.write_line('#ifndef {0}_H__'.format(self.name))
        self.write_line('#define {0}_H__'.format(self.name))
        self.skip_line(2)

    def write_defn_end(self):
        self.skip_line(2)
        self.write_line('#endif  /*  !{0}_H__  */'.format(self.name))
        self.skip_line(2)

    ########################################################################

    # Write file

    def write_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_defn_begin()
        self.write_common_includes()
        self.write_cpp_begin()
        self.write_general_includes()
        self.write_cppns_begin()
        self.write_class(self.baseClass, self.name)
        self.write_extension_instance()
        self.write_cppns_end()
        self.write_cpp_end()
        self.write_cppns_begin()
        self.write_type_defs()
        self.write_cppns_end()
        self.write_defn_end()

    # Write the extension types file
    def write_types_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_defn_begin()
        self.write_type_includes()
        self.write_defn_end()

    # Write the extension types file
    def write_fwd_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_defn_begin()
        self.write_docs_fwd()
        self.write_class_or_struct()
        self.write_cppns_begin()
        self.write_classes()
        self.write_cppns_end()
        self.write_end_class_or_struct()
        self.write_defn_end()
