#!/usr/bin/env python
#
# @file    CppCodeFile.py
# @brief   class for generating code file for the given class
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
from util import query, strFunctions, global_variables


class CppCodeFile(BaseCppFile.BaseCppFile):
    """Class for all Cpp Code files"""

    def __init__(self, class_object):

        self.brief_description = \
            'Implementation  of the {0} class.'.format(class_object['name'])
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
        if self.add_impl is not None and not self.is_list_of:
            self.copy_additional_file(self.add_impl)

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
            self.write_line('class {0};'.format(element['element']))
        self.skip_line()

    def write_general_includes(self):
        lo_name = ''
        if self.has_parent_list_of:
            if 'lo_class_name' in self.class_object:
                lo_name = self.class_object['lo_class_name']
            if len(lo_name) == 0:
                lo_name = strFunctions.list_of_name(self.class_name)
        if global_variables.is_package:
            folder = self.language if not self.is_plugin else 'extension'
            self.write_line_verbatim('#include <{0}/packages/{1}/{2}/{3}'
                                     '.h>'.format(self.language,
                                                  self.package.lower(),
                                                  folder, self.class_name))
            if self.has_parent_list_of and not self.is_list_of:
                self.write_line_verbatim('#include <{0}/packages/{1}/{0}/'
                                         '{2}'
                                         '.h>'.format(self.language,
                                                      self.package.lower(),
                                                      lo_name))
            self.write_line_verbatim('#include <{0}/packages/{1}/validator/'
                                     '{2}{3}Error'
                                     '.h>'.format(self.language,
                                                  self.package.lower(),
                                                  self.package,
                                                  self.cap_language))
        else:
            self.write_line_verbatim('#include <{0}/{1}'
                                     '.h>'.format(self.language,
                                                  self.class_name))
            if self.has_parent_list_of and not self.is_list_of:
                self.write_line_verbatim('#include <{0}/{1}'
                                         '.h>'.format(self.language,
                                                      lo_name))
            self.write_line_verbatim('#include <sbml/xml/XMLInputStream.h>')

        # determine whether we need to write other headers
        write_element_filter = False
        concrete_classes = []
        write_model = False
        write_validators = False
        write_math = False

        if len(self.child_lo_elements) > 0:
            write_element_filter = True
        else:
            for element in self.child_elements:
                if 'concrete' in element:
                    write_element_filter = True

        if self.is_plugin and not self.is_doc_plugin \
                and self.language == 'sbml':
            write_model = True

        if self.is_doc_plugin:
            write_validators = True

        if self.has_math:
            write_math = True

        for lo in self.child_lo_elements:
            if 'concrete' in lo:
                child_concretes = query.get_concretes(lo['root'],
                                                      lo['concrete'])
                for j in range(0, len(child_concretes)):
                    element = child_concretes[j]['element']
                    if element not in concrete_classes:
                        concrete_classes.append(element)

        for i in range(0, len(self.concretes)):
            element = self.concretes[i]['element']
            if element not in concrete_classes:
                concrete_classes.append(element)

        for child in self.child_elements:
            if 'concrete' in child:
                child_concretes = query.get_concretes(child['root'],
                                                      child['concrete'])
                for j in range(0, len(child_concretes)):
                    element = child_concretes[j]['element']
                    if element not in concrete_classes:
                        concrete_classes.append(element)

        if write_element_filter:
            self.write_line_verbatim('#include <{0}/util/ElementFilter.'
                                     'h>'.format(self.language))
        if write_model:
            self.write_line_verbatim('#include <{0}/Model'
                                     '.h>'.format(self.language))

        if write_validators:
            self.write_line_verbatim('#include <{0}/packages/{1}/validator/{2}'
                                     'ConsistencyValidator'
                                     '.h>'.format(self.language,
                                                  self.package.lower(),
                                                  self.package))
            self.write_line_verbatim('#include <{0}/packages/{1}/validator/{2}'
                                     'IdentifierConsistencyValidator.'
                                     'h>'.format(self.language,
                                                 self.package.lower(),
                                                 self.package))

        if write_math:
            self.write_line_verbatim('#include <{0}/math/MathML'
                                     '.h>'.format(self.language))

        if len(concrete_classes) > 0:
            self.skip_line()
        for element in concrete_classes:
            self.write_line_verbatim('#include <{0}/packages/{1}/{0}/{2}'
                                     '.h>'.format(self.language,
                                                  self.package.lower(),
                                                  element))
        self.skip_line(2)
        self.write_line('using namespace std;')
        self.skip_line()

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
        if self.is_cpp_api and not self.is_plugin:
            code = constructor.write_level_version_constructor()
            self.write_function_implementation(code)

            code = constructor.write_namespace_constructor()
            self.write_function_implementation(code)
        elif self.is_plugin:
            code = constructor.write_uri_constructor()
            self.write_function_implementation(code)
        elif self.has_std_base:
            for i in range(0, len(self.concretes)+1):
                code = constructor.write_level_version_constructor(i)
                self.write_function_implementation(code)
        else:
            code = constructor.write_level_version_constructor(-1)
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
    def write_child_element_functions(self, override=None):
        if override is None:
            if not self.has_children:
                return

            attrib_functions = SetGetFunctions.\
                SetGetFunctions(self.language, self.is_cpp_api,
                                self.is_list_of, self.class_object)

            num_elements = len(self.child_elements)
        else:
            attrib_functions = SetGetFunctions.SetGetFunctions(self.language,
                                                               self.is_cpp_api,
                                                               self.is_list_of,
                                                               override)
            num_elements = 1

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
            if override is None and code is None \
                    and 'concrete' in self.child_elements[i]:
                # need to write creates for the concrete
                member = self.child_elements[i]['memberName']
                concrete = self.child_elements[i]['concrete']
                concretes = query.get_concretes(self.class_object['root'],
                                                concrete)
                for j in range(0, len(concretes)):
                    code = attrib_functions\
                        .write_create_concrete_child(concretes[j], member)
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

        if not self.is_plugin:
            code = gen_functions.write_get_element_name()
            self.write_function_implementation(code)

        code = gen_functions.write_set_element_name()
        self.write_function_implementation(code, exclude=True)

        if not self.is_plugin:
            code = gen_functions.write_get_typecode()
            self.write_function_implementation(code)

        code = gen_functions.write_get_item_typecode()
        self.write_function_implementation(code)

        code = gen_functions.write_has_required_attributes()
        self.write_function_implementation(code)

        code = gen_functions.write_has_required_elements()
        self.write_function_implementation(code)

        code = gen_functions.write_write_elements()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_accept()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_set_document()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_write()
        self.write_function_implementation(code, exclude=True)

        code = gen_functions.write_connect_to_child()
        self.write_function_implementation(code, exclude=True)

        if self.is_plugin:
            code = gen_functions.write_connect_to_parent()
            self.write_function_implementation(code, exclude=True)

        if global_variables.is_package:
            code = gen_functions.write_enable_package()
            self.write_function_implementation(code, exclude=True)

        if self.is_doc_plugin:
            code = gen_functions.write_is_comp_flat()
            self.write_function_implementation(code, exclude=True)

            code = gen_functions.write_check_consistency()
            self.write_function_implementation(code, exclude=True)

            code = gen_functions.write_read_attributes()
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

        if self.is_plugin:
            code = gen_functions.write_append_from()
            self.write_function_implementation(code, True)

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
        if 'num_versions' in self.class_object \
                and self.class_object['num_versions'] > 1:
            for i in range(0, self.class_object['num_versions']):
                code = protect_functions.write_read_version_attributes(i+1)
                self.write_function_implementation(code, exclude)

        code = protect_functions.write_read_other_xml()
        self.write_function_implementation(code, exclude)

        code = protect_functions.write_write_attributes()
        self.write_function_implementation(code, exclude)
        if 'num_versions' in self.class_object \
                and self.class_object['num_versions'] > 1:
            for i in range(0, self.class_object['num_versions']):
                code = protect_functions.write_write_version_attributes(i+1)
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
            code = lo_functions.write_add_element_function()
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
            element['is_plugin'] = self.is_plugin
            if self.is_plugin:
                element['plugin'] = self.class_name
            if 'concrete' in element:
                element['concretes'] = query.get_concretes(
                    self.class_object['root'], element['concrete'])
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

            code = lo_functions.write_add_element_function()
            self.write_function_implementation(code)

            code = lo_functions.write_get_num_element_function()
            self.write_function_implementation(code)

            if 'concretes' in element:
                for n in range(0, len(element['concretes'])):
                        code = lo_functions.write_create_element_function(n+1)
                        self.write_function_implementation(code)
            else:
                code = lo_functions.write_create_element_function()
                self.write_function_implementation(code)

            code = lo_functions.write_remove_element_by_index()
            self.write_function_implementation(code)

            code = lo_functions.write_remove_element_by_id()
            self.write_function_implementation(code)

            # this tackles the situation where a listOfFoo class also
            # contains an element of another type
            # eg qual:ListOfFunctionTerms contains a DefaultTerm
            if not self.is_plugin:
                element_children = \
                    query.get_other_element_children(self.class_object, element)

                for j in range(0, len(element_children)):
                    child_class = self.create_lo_other_child_element_class(
                        element_children[0], self.class_name)
                    self.write_child_element_functions(child_class)
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
        if not self.is_plugin:
            self.write_c_code()
        self.write_cppns_end()
