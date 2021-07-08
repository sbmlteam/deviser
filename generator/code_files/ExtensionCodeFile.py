#!/usr/bin/env python
#
# @file    ExtensionCodeFile.py
# @brief   class for generating code file for the given extension
# @author  Frank Bergmann
# @author  Sarah Keating
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
from . cpp_functions import *
from util import query, strFunctions, global_variables


class ExtensionCodeFile(BaseCppFile.BaseCppFile):
    """Class for all Cpp Code files"""

    def __init__(self, package, filetype=''):

        self.up_package = strFunctions.upper_first(package['name'])
        if filetype == '':
            self.name = '{0}Extension'.format(self.up_package)
        elif filetype == 'enums':
            if package['name'].endswith('ml') and global_variables.is_package:
                length = len(package['name'])
                self.name = '{0}Enumerations'.format(strFunctions.upper_first(package['name'][0:length-2]))
            else:
                self.name = '{0}Enumerations'.format(strFunctions.upper_first(package['name']))
        self.brief_description = \
            'Implementation  of {0}.'.format(self.name)
        BaseCppFile.BaseCppFile.__init__(self, self.name, 'cpp',
                                         None)

        # members from object
        self.package = package['name']
        self.cap_package = package['name'].upper()
        self.baseClass = '{0}Extension'.format(self.cap_language)

        self.elements = package['elements']
        self.number = package['number']
        self.enums = package['enums']
        self.plugins = package['plugins']
        self.offset = package['offset']

        self.num_versions = 1
        if 'num_versions' in package:
            self.num_versions = package['num_versions']

        self.core_level = package['base_level']
        self.core_version = package['base_version']
        self.lv_info = package['lv_info']

        # create a class object so we can just reuse code
        self.class_object['package'] = self.package
        self.class_object['name'] = self.name
        self.class_object['concretes'] = []
        self.class_object['baseClass'] = self.baseClass
        self.class_object['attribs'] = []
        self.class_object['has_children'] = False
        self.class_object['child_elements'] = []
        self.class_object['overwrites_children'] = False

    ########################################################################

    # Functions for writing the class
    def write_class(self):
        # self.write_forward_class()
        self.write_attribute_functions()
        self.write_extension_instance()
        self.write_constructors()
        self.write_virtual_functions()
        self.write_init_function()

    ########################################################################
    # Functions for writing specific includes and forward implementations

    def write_general_includes(self):

        self.write_line_verbatim('#include <{0}/extension/{1}'
                                 'ExtensionRegister.h>'
                                 ''.format(self.language,
                                           self.cap_language))
        self.write_line_verbatim('#include <{0}/extension/{1}'
                                 'ExtensionRegistry.h>'
                                 ''.format(self.language,
                                           self.cap_language))
        self.write_line_verbatim('#include <{0}/extension/{1}'
                                 'PluginCreator.h>'.format(self.language,
                                                           self.std_base))
        self.write_line_verbatim('#include <{0}/extension/{1}'
                                 'DocumentPlugin.h>'
                                 ''.format(self.language,
                                           self.cap_language))
        self.skip_line()
        self.write_line_verbatim('#include <{0}/packages/{1}/extension/{2}'
                                 'Extension.h>'.format(self.language,
                                                       self.package,
                                                       self.up_package))
        self.write_line_verbatim('#include <{0}/packages/{1}/extension/{2}'
                                 '{3}DocumentPlugin.h>'
                                 ''.format(self.language, self.package,
                                           self.up_package, self.cap_language))
        self.write_line_verbatim('#include <{0}/packages/{1}/validator/{2}'
                                 '{3}ErrorTable.h>'
                                 ''.format(self.language, self.package,
                                           self.up_package,
                                           self.cap_language))
        for i in range(0, len(self.plugins)):
            self.write_line_verbatim('#include <{0}/packages/{1}/extension/{2}'
                                     '{3}Plugin.h>'
                                     ''.format(self.language,
                                               self.package,
                                               self.up_package,
                                               self.plugins[i]['sbase']))

        self.skip_line(2)
        self.write_line('using namespace std;')
        self.skip_line()

    ########################################################################

    # function to write the constructors
    def write_constructors(self):
        constructor = Constructors.Constructors(self.language,
                                                self.is_cpp_api,
                                                self.class_object)
        code = constructor.write_constructor()
        self.write_function_implementation(code)

        code = constructor.write_copy_constructor()
        self.write_function_implementation(code)

        code = constructor.write_assignment_operator()
        self.write_function_implementation(code)

        code = constructor.write_clone()
        self.write_function_implementation(code)

        code = constructor.write_destructor()
        self.write_function_implementation(code)

    ########################################################################

    # function to write the static get functions
    def write_attribute_functions(self):
        self.class_object['class_attributes'] \
            = query.get_static_extension_attribs(self.num_versions, self.lv_info)
        attrib_functions = SetGetFunctions.SetGetFunctions(self.language,
                                                           self.is_cpp_api,
                                                           self.is_list_of,
                                                           self.class_object,
                                                           self.lv_info)
        num_attributes = len(self.class_object['class_attributes'])
        for i in range(0, num_attributes):
            code = attrib_functions.write_static_extension_get(i, True, False)
            self.write_function_implementation(code)

    ########################################################################

    # Functions for writing virtual functions

    def write_virtual_functions(self):
        ext_functions = ExtensionFunctions.ExtensionFunctions(self.language,
                                                              self.package,
                                                              self.elements,
                                                              self.offset,
                                                              self.num_versions,
                                                              self.lv_info)

        code = ext_functions.write_get_name()
        self.write_function_implementation(code)

        code = ext_functions.write_get_uri()
        self.write_function_implementation(code)

        code = ext_functions.write_get_other('Level')
        self.write_function_implementation(code)

        code = ext_functions.write_get_other('Version')
        self.write_function_implementation(code)

        code = ext_functions.write_get_other('PackageVersion')
        self.write_function_implementation(code)

        code = ext_functions.write_get_namespaces()
        self.write_function_implementation(code)

        code = ext_functions.write_get_string_typecode()
        self.write_function_implementation(code)

        code = ext_functions.write_get_error_table()
        self.write_function_implementation(code, exclude=True)

        code = ext_functions.write_get_error_table_index()
        self.write_function_implementation(code, exclude=True)

        code = ext_functions.write_get_error_offset()
        self.write_function_implementation(code, exclude=True)

        if self.num_versions > 1:
            code = ext_functions.write_has_multiple_versions()
            self.write_function_implementation(code, True)

    ########################################################################

    # write the init function
    def write_init_function(self):
        init_functions = \
            ExtensionInitFunctions.ExtensionInitFunctions(self.language,
                                                          self.package,
                                                          self.std_base,
                                                          self.enums,
                                                          self.plugins,
                                                          self.lv_info)
        code = init_functions.write_init_function(False)
        self.write_function_implementation(code, True)

    ########################################################################

    # write the instantiation
    def write_extension_instance(self):
        # this is a bit different from the header file
        up_package = strFunctions.upper_first(self.package)
        self.open_comment()
        self.write_blank_comment_line()
        self.write_comment_line('Adds this {0}Extension to the {1}'
                                'ExtensionRegistry '
                                'class'.format(up_package, self.cap_language))
        self.write_blank_comment_line()
        self.close_comment()
        self.write_line('static {0}ExtensionRegister<{1}Extension> '
                        '{2}ExtensionRegistry;'.format(self.cap_language,
                                                       up_package,
                                                       self.package))
        self.skip_line()
        self.write_line('static')
        self.write_line('const char* {0}_{1}_TYPECODE_STRINGS[] ='
                        ''.format(self.cap_language, self.cap_package))
        self.write_line('{')
        self.up_indent()
        self.write_line('  \"{0}\"'.format(self.elements[0]['name']))
        for i in range(1, len(self.elements)):
            self.write_line('  , \"{0}\"'.format(self.elements[i]['name']))
        self.down_indent()
        self.write_line('};')
        self.skip_line(2)
        self.open_comment()
        self.write_blank_comment_line()
        self.write_comment_line('Instantiate {0}ExtensionNamespaces<{1}'
                                'Extension> for DLL'.format(self.cap_language,
                                                            up_package))
        self.write_blank_comment_line()
        self.close_comment()
        self.write_line('template class LIB{0}_EXTERN {0}ExtensionNamespaces<'
                        '{1}Extension>;'.format(self.cap_language,
                                                up_package))
        self.skip_line()

    ########################################################################

    # write the type defs

    def write_type_defs(self):
        # write the enum for typecodes
        # self.write_type_code_enum_header(self.package)
        # values = query.get_typecode_enum(self.elements)
        # name = '{}{}TypeCode_t'.format(self.cap_language, self.up_package)
        # self.write_enum(name, self.number, values[0], values[1], values[2]+5)
        # self.skip_line(2)
        #
        num_enums = len(self.enums)
        if num_enums == 0:
            return
        self.write_other_enums()

    def write_other_enums(self):
        init_functions = \
            ExtensionInitFunctions.ExtensionInitFunctions(self.language,
                                                          self.package,
                                                          self.std_base,
                                                          self.enums,
                                                          [], self.lv_info)
        self.is_cpp_api = False
        for i in range(0, len(self.enums)):
            name = query.get_typecode_format(self.enums[i]['name'],
                                             self.language) + '_STRINGS'
            values = query.get_enum(self.enums[i])
            self.write_enum_strings(name, values[1])
            self.skip_line(2)
            code = init_functions.write_enum_to_string_function(i,
                                                                values[0],
                                                                name)
            self.write_function_implementation(code)
            code = init_functions.write_enum_from_string_function(i, values[0],
                                                                  name)
            self.write_function_implementation(code)
            code = init_functions.write_is_valid_enum_function(i, values[0])
            self.write_function_implementation(code)
            code = init_functions.write_is_valid_enum_string_function(i, values[0])
            self.write_function_implementation(code)

    ########################################################################

    # Write file

    def write_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_general_includes()
        self.write_cppns_begin()
        self.write_cpp_begin()
        self.write_class()
#        self.write_extension_instance()
        self.write_cpp_end()
        self.write_type_defs()
        self.write_cppns_end()

    # Write the extension types file
    def write_ext_enum_code(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_line_verbatim('#include <string>')
        self.write_line_verbatim('#include <{0}/common/{1}.h>'
                                 ''.format(self.language,
                                           self.name))
        self.write_cppns_begin()
        self.write_other_enums()
        self.write_cppns_end()
