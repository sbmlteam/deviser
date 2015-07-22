#!/usr/bin/env python
#
# @file    CppCodeFile.py
# @brief   class for generating code file for the given class
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

from base_files import BaseCppFile
from cpp_functions import *
from util import query


class CppCodeFile(BaseCppFile.BaseCppFile):
    """Class for all Cpp Code files"""

    def __init__(self, class_object):

        self.brief_description = \
            'Implementation  of {}.'.format(class_object['name'])
        BaseCppFile.BaseCppFile.__init__(self, class_object['name'], 'cpp',
                                         class_object['attribs'])

        # members from object
        self.expand_class(class_object)
    ########################################################################

    # Functions for writing the class
    def write_class(self):
        # self.write_forward_class()
        self.write_constructors()
        self.write_attribute_functions()
        self.write_child_element_functions()
        self.write_listof_functions()
        self.write_child_lo_element_functions()
        self.write_concrete_functions()
        self.write_general_functions()
        self.write_functions_to_retrieve()
        self.write_protected_functions()
        if self.add_decls is not None:
            self.copy_additional_file(self.add_decls)

    def write_c_code(self):
        self.is_cpp_api = False
        if not self.is_list_of:
            self.write_constructors()
            self.write_attribute_functions()
            self.write_child_element_functions()
            self.write_child_lo_element_functions()
            self.write_concrete_functions()
            self.write_general_functions()
        else:
            self.write_attribute_functions()
            self.write_listof_functions()

    ########################################################################
    # Functions for writing specific includes and forward declarations

    def write_forward_class(self):
        if len(self.concretes) == 0:
            return
        for element in self.concretes:
            self.write_line('class {};'.format(element['element']))
        self.skip_line()

    def write_general_includes(self):
        if self.language == 'sbml':
            if self.package:
                self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'
                                .format(self.language, self.package.lower(),
                                        self.class_name))
                self.write_line('#include <{}/packages/{}/validator/'
                                '{}SBMLError.h>'
                                .format(self.language, self.package.lower(),
                                        self.package))
            else:
                self.write_line('#include <{0}/{1}.h>'.
                                format(self.language, self.class_name))
        else:
            self.write_line('#include <{0}/{1}.h>'.
                            format(self.language, self.baseClass))

        if len(self.child_lo_elements) > 0:
            self.write_line('#include <{}'
                            '/util/ElementFilter.h>'.format(self.language))

        if self.has_math:
            self.write_line('#include <{}/math/MathML.h>'.format(self.language))

        for i in range(0, len(self.concretes)):
            self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'.format(
                self.language, self.package.lower(),
                self.concretes[i]['element']
            ))

        self.skip_line(2)
        self.write_line('using namespace std;')
        self.skip_line()

        # additional includes for child elements
        # for i in range(0, len(self.child_elements)):
        #     child = self.child_elements[i]['element']
        #     if child != 'ASTNode':
        #         self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'
        #                         .format(self.language, self.package.lower(),
        #                                 child))
        #
        # for i in range(0, len(self.child_lo_elements)):
        #     child = self.child_lo_elements[i]['attTypeCode']
        #     self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'
        #                     .format(self.language, self.package.lower(),
        #                             child))
        #
        # if self.is_list_of:
        #     child = self.list_of_child
        #     self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'
        #                     .format(self.language, self.package.lower(),
        #                             child))
    ########################################################################

    # function to write the data members
    def write_data_members(self, attributes):
        for i in range(0, len(attributes)):
            if attributes[i]['attType'] != 'string':
                self.write_line('{0} {1};'.format(attributes[i]['attTypeCode'],
                                                  attributes[i]['memberName']))
            else:
                self.write_line('std::string {0};'
                                .format(attributes[i]['memberName']))
            if attributes[i]['isNumber'] is True \
                    or attributes[i]['attType'] == 'boolean':
                self.write_line('bool mIsSet{0};'
                                .format(attributes[i]['capAttName']))
        if self.overwrites_children:
            self.write_line('std::string mElementName;')

    ########################################################################

    # function to write the constructors
    def write_constructors(self):
        constructor = Constructors.Constructors(self.language,
                                                self.is_cpp_api,
                                                self.class_object)
        if self.is_cpp_api:
            code = constructor.write_level_version_constructor()
            self.write_function_implementation(code)

            code = constructor.write_namespace_constructor()
            self.write_function_implementation(code)
        else:
            for i in range(0, len(self.concretes)+1):
                code = constructor.write_level_version_constructor(i)
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

    # Functions for writing the attribute manipulation functions
    # these are for attributes and elements that occur as a single child

    # function to write the get/set/isSet/unset functions for attributes
    def write_attribute_functions(self):
        attrib_functions = SetGetFunctions.SetGetFunctions(self.language,
                                                           self.is_cpp_api,
                                                           self.is_list_of,
                                                           self.class_object)
        num_attributes = len(self.class_attributes)
        for i in range(0, num_attributes):
            code = attrib_functions.write_get(True, i)
            self.write_function_implementation(code)

            code = attrib_functions.write_get_string_for_enum(True, i)
            self.write_function_implementation(code)

        for i in range(0, num_attributes):
            code = attrib_functions.write_is_set(True, i)
            self.write_function_implementation(code)

        for i in range(0, num_attributes):
            code = attrib_functions.write_set(True, i)
            self.write_function_implementation(code)

            code = attrib_functions.write_set_string_for_enum(True, i)
            self.write_function_implementation(code)

        for i in range(0, num_attributes):
            code = attrib_functions.write_unset(True, i)
            self.write_function_implementation(code)

    # function to write the get/set/isSet/unset functions for single
    # child elements
    def write_child_element_functions(self):
        if self.is_list_of:
            return

        attrib_functions = SetGetFunctions.SetGetFunctions(self.language,
                                                           self.is_cpp_api,
                                                           self.is_list_of,
                                                           self.class_object)

        num_elements = len(self.child_elements)
        for i in range(0, num_elements):
            code = attrib_functions.write_get(False, i)
            self.write_function_implementation(code)

            code = attrib_functions.write_get(False, i, const=False)
            self.write_function_implementation(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_is_set(False, i)
            self.write_function_implementation(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_set(False, i)
            self.write_function_implementation(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_create(False, i)
            if code is None and 'concrete' in self.child_elements[i]:
                # need to write creates for the concrete
                concrete = self.child_elements[i]['concrete']
                concretes = query.get_concretes(self.class_object['root'],
                                                concrete)
                for j in range(0, len(concretes)):
                    code = attrib_functions\
                        .write_create_concrete_child(concretes[j])
                    self.write_function_implementation(code)
            else:
                self.write_function_implementation(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_unset(False, i)
            self.write_function_implementation(code)

    ########################################################################

    # Functions for writing general functions

    def write_general_functions(self):
        gen_functions = GeneralFunctions.GeneralFunctions(self.language,
                                                          self.is_cpp_api,
                                                          self.is_list_of,
                                                          self.class_object)
        code = gen_functions.write_rename_sidrefs()
        self.write_function_implementation(code)

        code = gen_functions.write_get_element_name()
        self.write_function_implementation(code)

        code = gen_functions.write_set_element_name()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_get_typecode()
        self.write_function_implementation(code)

        code = gen_functions.write_get_item_typecode()
        self.write_function_implementation(code)

        code = gen_functions.write_has_required_attributes()
        self.write_function_implementation(code)

        code = gen_functions.write_has_required_elements()
        self.write_function_implementation(code)

        code = gen_functions.write_write_elements
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_accept()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_set_document()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_write()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_connect_to_child()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_enable_package()
        self.write_function_implementation(code, exclude=True)

    ########################################################################

    # Retrieve element functions

    def write_functions_to_retrieve(self):
        if not query.has_children(self.attributes):
            return

        gen_functions = \
            GlobalQueryFunctions.GlobalQueryFunctions(self.language,
                                                      self.is_cpp_api,
                                                      self.is_list_of,
                                                      self.class_object)
        code = gen_functions.write_get_by_sid()
        self.write_function_implementation(code)

        code = gen_functions.write_get_by_metaid()
        self.write_function_implementation(code)

        code = gen_functions.write_get_all_elements()
        self.write_function_implementation(code)

    ########################################################################

    # concrete class functions

    def write_concrete_functions(self):
        conc_functions = \
            ConcreteClassFunctions.ConcreteClassFunctions(self.language,
                                                          self.is_cpp_api,
                                                          self.is_list_of,
                                                          self.class_object)
        for i in range(0, len(self.concretes)):
            code = conc_functions.write_is_foo(i)
            self.write_function_implementation(code)

    ########################################################################

    # Protected functions

    def write_protected_functions(self):
        protect_functions = \
            ProtectedFunctions.ProtectedFunctions(self.language,
                                                  self.is_cpp_api,
                                                  self.is_list_of,
                                                  self.class_object)
        exclude = True
        code = protect_functions.write_create_object()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_add_expected_attributes()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_read_attributes()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_read_other_xml()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_write_attributes()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_write_xmlns()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_is_valid_type_for_list()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_set_element_text()
        self.write_function_implementation(code, exclude)

    ########################################################################

    # Functions for writing functions for the main ListOf class

    def write_listof_functions(self):
        if not self.is_list_of:
            return

        lo_functions = ListOfQueryFunctions\
            .ListOfQueryFunctions(self.language, self.is_cpp_api,
                                  self.is_list_of,
                                  self.class_object)

        code = lo_functions.write_get_element_by_index(is_const=False)
        self.write_function_implementation(code)

        code = lo_functions.write_get_element_by_index(is_const=True)
        self.write_function_implementation(code)

        code = lo_functions.write_get_element_by_id(is_const=False)
        self.write_function_implementation(code)

        code = lo_functions.write_get_element_by_id(is_const=True)
        self.write_function_implementation(code)

        code = lo_functions.write_remove_element_by_index()
        self.write_function_implementation(code)

        code = lo_functions.write_remove_element_by_id()
        self.write_function_implementation(code)

        if self.is_cpp_api:
            code = lo_functions.write_add_element_function
            self.write_function_implementation(code)

            code = lo_functions.write_get_num_element_function()
            self.write_function_implementation(code)

            for i in range(0, len(self.concretes)+1):
                code = lo_functions.write_create_element_function(i)
                self.write_function_implementation(code)

            for i in range(0, len(self.sid_refs)):
                code = lo_functions.write_lookup(self.sid_refs[i])
                self.write_function_verbatim(code)

                code = \
                    lo_functions.write_get_element_by_sidref(self.sid_refs[i],
                                                             const=True)
                self.write_function_implementation(code)

                code = \
                    lo_functions.write_get_element_by_sidref(self.sid_refs[i],
                                                             const=False)
                self.write_function_implementation(code)

    # main function to write the functions dealing with a child listOf element
    def write_child_lo_element_functions(self):
        num_elements = len(self.child_lo_elements)
        for i in range(0, num_elements):
            element = self.child_lo_elements[i]
            element['std_base'] = self.std_base
            element['package'] = self.package
            element['is_header'] = self.is_header
            lo_functions = ListOfQueryFunctions\
                .ListOfQueryFunctions(self.language, self.is_cpp_api,
                                      self.is_list_of,
                                      element)
            code = lo_functions.write_get_list_of_function(is_const=True)
            self.write_function_implementation(code)

            code = lo_functions.write_get_list_of_function(is_const=False)
            self.write_function_implementation(code)

            code = lo_functions.write_get_element_by_index(is_const=False)
            self.write_function_implementation(code)

            code = lo_functions.write_get_element_by_index(is_const=True)
            self.write_function_implementation(code)

            code = lo_functions.write_get_element_by_id(is_const=False)
            self.write_function_implementation(code)

            code = lo_functions.write_get_element_by_id(is_const=True)
            self.write_function_implementation(code)

            sid_ref = query.get_sid_refs_for_class(element)
            for j in range(0, len(sid_ref)):
                if self.is_list_of:
                    code = lo_functions.write_lookup(sid_ref[j])
                    self.write_function_verbatim(code)

                code = \
                    lo_functions.write_get_element_by_sidref(sid_ref[j],
                                                             const=True)
                self.write_function_implementation(code)

                code = \
                    lo_functions.write_get_element_by_sidref(sid_ref[j],
                                                             const=False)
                self.write_function_implementation(code)

            code = lo_functions.write_add_element_function
            self.write_function_implementation(code)

            code = lo_functions.write_get_num_element_function()
            self.write_function_implementation(code)

            code = lo_functions.write_create_element_function()
            self.write_function_implementation(code)

            code = lo_functions.write_remove_element_by_index()
            self.write_function_implementation(code)

            code = lo_functions.write_remove_element_by_id()
            self.write_function_implementation(code)

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
        self.write_general_includes()
        self.write_cppns_begin()
        self.write_cpp_begin()
        self.write_class()
        self.write_cpp_end()
        self.write_c_code()
        self.write_cppns_end()
