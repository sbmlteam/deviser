#!/usr/bin/env python
#
# @file    CppHeaderFile.py
# @brief   class for generating header file for the given class
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
from util import strFunctions
from util import query


class CppHeaderFile(BaseCppFile.BaseCppFile):
    """Class for all Cpp Header files"""

    def __init__(self, class_object):

        self.brief_description = \
            'Definition of {}.'.format(class_object['name'])
        BaseCppFile.BaseCppFile.__init__(self, class_object['name'], 'h',
                                         class_object['attribs'])

        # members from object
        self.class_object = class_object
        self.is_list_of = class_object['is_list_of']
        self.name = class_object['name']
        self.class_name = class_object['name']
        self.package = class_object['package']
        self.typecode = class_object['typecode']
        if class_object['is_list_of']:
            self.list_of_name = class_object['list_of_name']
            self.list_of_child = class_object['lo_child']
        else:
            self.list_of_name = ''
            self.list_of_child = ''
        self.baseClass = class_object['baseClass']
        self.sid_refs = class_object['sid_refs']

        # check case of things where we assume upper/lower
        if self.package[0].islower():
            self.package = strFunctions.upper_first(class_object['package'])

        self.hasMath = class_object['hasMath']
        self.class_attributes = query.seperate_attributes(self.attributes)

        self.class_object['class_attributes'] = self.class_attributes
        self.class_object['child_lo_elements'] = self.child_lo_elements
        self.class_object['child_elements'] = self.child_elements
    ########################################################################

    # Functions for writing specific includes

    def write_common_includes(self):
        self.write_line('#include <{0}/common/extern.h>'.format(self.language))
        self.write_line('#include <{0}/common/{0}fwd.h>'.format(self.language))
        if self.package:
            self.write_line('#include <{0}/packages/{1}/common/{1}fwd.h>'.
                            format(self.language, self.package.lower()))

    def write_general_includes(self):
        self.write_line('#include <string>')
        self.skip_line(2)
        self.write_line('#include <{0}/{1}.h>'.
                        format(self.language, self.baseClass))
        if self.package:
            self.write_line(
                '#include <{0}/packages/{1}/extension/{2}Extension.h>'
                .format(self.language, self.package.lower(), self.package))

        # additional includes for child elements
        for i in range(0, len(self.child_elements)):
            child = self.child_elements[i]['element']
            if child != 'ASTNode':
                self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'
                                .format(self.language, self.package.lower(),
                                        child))

        for i in range(0, len(self.child_lo_elements)):
            child = self.child_lo_elements[i]['capAttName']
            self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'
                            .format(self.language, self.package.lower(),
                                    child))

        if self.is_list_of:
            child = self.list_of_child
            self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'
                            .format(self.language, self.package.lower(),
                                    child))
    ########################################################################

    # Functions for writing the class
    def write_class(self, base_class, class_name, attributes):
        class_attributes = query.seperate_attributes(attributes)
        has_children = query.has_children(attributes)
        self.write_line('class {0}_EXTERN {1} : public {2}'
                        .format(self.library_name.upper(),
                                class_name, base_class))
        self.write_line('{')
        if len(attributes) > 0:
            self.write_line('protected:')
            self.up_indent()
            self.write_doxygen_start()
            self.write_data_members(attributes)
            self.write_doxygen_end()
            self.down_indent()
        else:
            self.skip_line()
        self.write_line('public:')
        self.skip_line()
        self.up_indent()
        self.write_constructors()
        self.write_attribute_functions()
        if base_class != 'ListOf':
            self.write_child_element_functions(class_name)
        if base_class == 'ListOf':
            self.write_listof_functions()
        else:
            self.write_child_lo_element_functions(class_name)
        self.write_general_functions()
        if has_children:
            self.write_functions_to_retrieve(class_name)
        self.down_indent()
        self.write_line('protected:')
        self.skip_line()
        self.up_indent()
        self.write_protected_functions()
        self.down_indent()
        self.write_line('};\n')

    def write_c_header(self):
        self.is_cpp_api = False
        if not self.is_list_of:
            class_attributes = query.seperate_attributes(self.attributes)
            self.write_constructors()
            self.write_attribute_functions()
            self.write_child_element_functions(self.name)
            self.write_child_lo_element_functions(self.name)
            self.write_general_functions()
        else:
            self.write_listof_functions()

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

    ########################################################################

    # function to write the constructors
    def write_constructors(self):
        constructor = Constructors.Constructors(self.language,
                                                self.is_cpp_api,
                                                self.class_object)

        code = constructor.write_level_version_constructor()
        self.write_function_declaration(code)

        code = constructor.write_namespace_constructor()
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
            self.write_function_declaration(code)

            code = attrib_functions.write_get_string_for_enum(True, i)
            self.write_function_declaration(code)

#            self.write_get_function(class_name, class_attributes[i], True)
        for i in range(0, num_attributes):
            code = attrib_functions.write_is_set(True, i)
            self.write_function_declaration(code)

#            self.write_is_set_function(class_name, class_attributes[i], True)
        for i in range(0, num_attributes):
            code = attrib_functions.write_set(True, i)
            self.write_function_declaration(code)

            code = attrib_functions.write_set_string_for_enum(True, i)
            self.write_function_declaration(code)
#            self.write_set_function(class_name, class_attributes[i], True)
        for i in range(0, num_attributes):
            code = attrib_functions.write_unset(True, i)
            self.write_function_declaration(code)
#            self.write_unset_function(class_name, class_attributes[i], True)

    # function to write the get/set/isSet/unset functions for single
    # child elements
    def write_child_element_functions(self, class_name):
        num_elements = len(self.child_elements)
        for i in range(0, num_elements):
            self.write_get_function(class_name, self.child_elements[i], False)
        for i in range(0, num_elements):
            self.write_is_set_function(class_name, self.child_elements[i],
                                       False)
        for i in range(0, num_elements):
            self.write_set_function(class_name, self.child_elements[i], False)
        for i in range(0, num_elements):
            self.write_create_element_function(class_name,
                                               self.child_elements[i], True)
        for i in range(0, num_elements):
            self.write_unset_function(class_name, self.child_elements[i], False)

    # function to write get function
    def write_get_function(self, class_name, attribute, is_attribute):
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
        else:
            object_name = class_name

        # create doc string header
        params = []
        return_lines = []
        title_line = 'Returns the value of the \"{0}\" {1} of this {2}.' \
            .format(attribute['name'],
                    ('attribute' if is_attribute else 'element'),
                    (class_name if self.is_cpp_api else object_name))

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure whose {2} is sought.'
                          .format(abbrev_object, object_name,
                                  attribute['name']))

        if self.is_cpp_api:
            return_lines.append('@return the value of the \"{0}\" {1} of '
                                'this {2} as a {3}.'
                                .format(attribute['name'],
                                        ('attribute' if is_attribute
                                         else 'element'),
                                        class_name,
                                        (attribute['attType']
                                         if (is_attribute
                                             and attribute['isEnum'] is False)
                                         else attribute['attTypeCode'])))
        else:
            return_lines.append('@return the value of the \"{0}\" {1} of '
                                'this {2} as a {3} {4}.'
                                .format(attribute['name'],
                                        ('attribute' if is_attribute
                                         else 'element'),
                                        object_name,
                                        ('pointer to a'
                                         if (is_attribute and
                                             attribute['attType'] == 'string')
                                         else ''),
                                        (attribute['attType']
                                         if (is_attribute
                                             and attribute['isEnum'] is False)
                                         else attribute['attTypeCode'])))
        self.write_comment_header(title_line, params, return_lines,
                                  object_name)

        # create the function declaration
        if self.is_cpp_api:
            function = 'get{0}'.format(attribute['capAttName'])
            if attribute['attType'] == 'string' \
                    or attribute['attType'] == 'element':
                return_type = 'const ' + attribute['attTypeCode']
            else:
                return_type = attribute['attTypeCode']
        else:
            function = '{0}_get{1}'.format(class_name, attribute['capAttName'])
            if attribute['attType'] == 'element':
                return_type = 'const {0}'.format(attribute['CType'])
            else:
                return_type = '{0}'.format(attribute['CType'])

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(object_name, abbrev_object))

        virtual = False
        constant = True
        self.write_function_header(function, arguments, return_type,
                                   constant, virtual)
        self.skip_line(2)
        # for an enum write a string version
        if attribute['isEnum'] is True:
            self.write_get_string_for_enum_function(class_name, attribute)
        # for a child element write a non const version
        if not is_attribute and self.is_cpp_api:
            if attribute['attType'] == 'element':
                self.write_comment_header(title_line, params,
                                          return_lines, object_name)
                return_type = attribute['attTypeCode']
                constant = False
                self.write_function_header(function, arguments, return_type,
                                           constant, virtual)
                self.skip_line(2)

    # function to write get function string version for enums
    def write_get_string_for_enum_function(self, class_name, attribute):
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
        else:
            object_name = class_name

        # create doc string header
        params = []
        return_lines = []
        title_line = 'Returns the value of the \"{0}\" attribute of this {1}.' \
            .format(attribute['name'],
                    (class_name if self.is_cpp_api else object_name))

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure whose {2} is sought.'
                          .format(abbrev_object, object_name,
                                  attribute['name']))

        if self.is_cpp_api:
            return_lines.append('@return the value of the \"{0}\" attribute '
                                'of this {1} as a string.'
                                .format(attribute['name'], class_name))
        else:
            return_lines.append('@return the value of the \"{0}\" attribute '
                                'of this {1} as a const char *.'
                                .format(attribute['name'], object_name))
        self.write_comment_header(title_line, params, return_lines,
                                  object_name)

        # create the function declaration
        if self.is_cpp_api:
            function = 'get{0}'.format(attribute['capAttName'])
            return_type = 'const std::string&'
        else:
            function = '{0}_get{1}'.format(class_name, attribute['capAttName'])
            return_type = 'const char *'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(object_name, abbrev_object))

        virtual = False
        constant = True
        self.write_function_header(function, arguments, return_type,
                                   constant, virtual)
        self.skip_line(2)

    # function to write is set function
    def write_is_set_function(self, class_name, attribute, is_attribute):
        if is_attribute:
            ob_type = 'attribute'
        else:
            ob_type = 'element'
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
            true = '@c 1'
            false = '@c 0'
        else:
            object_name = class_name
            true = '@c true'
            false = '@c false'

        # create doc string header
        params = []
        return_lines = []
        title_line = 'Predicate returning {} or {} depending on whether ' \
                     'this {}\'s \"{}\" {} has been set.' \
            .format(true, false, object_name, attribute['name'], ob_type)
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(abbrev_object, object_name))

        return_lines.append('@return {0} if this {1}\'s \"{2}\" {3} has been '
                            'set, otherwise {4} is returned.'
                            .format(true, object_name, attribute['name'],
                                    ob_type, false))
        self.write_comment_header(title_line, params, return_lines,
                                  object_name)

        # create the function declaration
        if self.is_cpp_api:
            function = 'isSet{0}'.format(attribute['capAttName'])
            return_type = 'bool'
        else:
            function = '{0}_isSet{1}'.format(class_name,
                                             attribute['capAttName'])
            return_type = 'int'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(object_name, abbrev_object))

        virtual = False
        constant = True
        self.write_function_header(function, arguments, return_type,
                                   constant, virtual)
        self.skip_line(2)

    # function to write set function
    def write_set_function(self, class_name, attribute, is_attribute):
        if is_attribute:
            ob_type = 'attribute'
        else:
            ob_type = 'element'
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
        else:
            object_name = class_name
        # create doc string header
        params = []
        return_lines = []
        title_line = 'Sets the value of the \"{0}\" {1} of this {2}.' \
            .format(attribute['name'], ob_type, object_name)

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(abbrev_object, object_name))
        params.append('@param {0} {1} value of the \"{0}\" {2} to be set.'
                      .format(attribute['name'], attribute['attTypeCode'],
                              ob_type))

        return_lines.append("@copydetails doc_returns_success_code")
        return_lines.append('@li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, '
                            'OperationReturnValues_t}')

        return_lines.append('@li @sbmlconstant '
                            '{LIBSBML_INVALID_ATTRIBUTE_VALUE,'
                            ' OperationReturnValues_t}')
        self.write_comment_header(title_line, params, return_lines,
                                  object_name)

        # create the function declaration
        if self.is_cpp_api:
            function = 'set{0}'.format(attribute['capAttName'])
            return_type = 'int'
        else:
            function = '{0}_set{1}'.format(class_name, attribute['capAttName'])
            return_type = 'int'

        arguments = []
        if self.is_cpp_api:
            arguments.append('{0} {1}'
                             .format(('const ' + attribute['attTypeCode']
                                      if (attribute['attType'] == 'string' or
                                          attribute['attType'] == 'enum' or
                                          attribute['attType'] == 'element')
                                      else attribute['attTypeCode']),
                                     attribute['name']))
        else:
            arguments.append('{0} * {1}'
                             .format(object_name, abbrev_object))
            if attribute['attType'] == 'element':
                arguments.append('const {0} {1}'
                                 .format(attribute['CType'],
                                         attribute['name']))
            else:
                arguments.append('{0} {1}'
                                 .format(attribute['CType'],
                                         attribute['name']))

        virtual = False
        constant = False
        self.write_function_header(function, arguments, return_type,
                                   constant, virtual)
        self.skip_line(2)

        if attribute['isEnum'] is True:
            self.write_set_for_enums_function(class_name, attribute)

    # function to write set function with string version for enums
    def write_set_for_enums_function(self, class_name, attribute):
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
            att_type = 'const char *'
        else:
            object_name = class_name
            att_type = 'std::string&'
        # create doc string header
        params = []
        return_lines = []
        title_line = 'Sets the value of the \"{0}\" attribute of this {1}.' \
            .format(attribute['name'], object_name)

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(abbrev_object, object_name))
        params.append('@param {0} {1} of the \"{0}\" attribute to be set.'
                      .format(attribute['name'], att_type))

        return_lines.append("@copydetails doc_returns_success_code")
        return_lines.append('@li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, '
                            'OperationReturnValues_t}')

        return_lines.append('@li @sbmlconstant '
                            '{LIBSBML_INVALID_ATTRIBUTE_VALUE,'
                            ' OperationReturnValues_t}')
        self.write_comment_header(title_line, params, return_lines,
                                  object_name)

        # create the function declaration
        if self.is_cpp_api:
            function = 'set{0}'.format(attribute['capAttName'])
            return_type = 'int'
        else:
            function = '{0}_set{1}'.format(class_name, attribute['capAttName'])
            return_type = 'int'

        arguments = []
        if self.is_cpp_api:
            arguments.append('{0} {1}'.format('const std::string&',
                                              attribute['name']))
        else:
            arguments.append('{0} * {1}'
                             .format(object_name, abbrev_object))
            arguments.append('const char * {}'.format(attribute['name']))

        virtual = False
        constant = False
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line(2)

    # function to write unset function
    def write_unset_function(self, class_name, attribute, is_attribute):
        if is_attribute:
            ob_type = 'attribute'
        else:
            ob_type = 'element'
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
        else:
            object_name = class_name
        # create doc string header
        params = []
        return_lines = []
        title_line = 'Unsets the value of the \"{0}\" {1} of this {2}.' \
            .format(attribute['name'], ob_type, object_name)

        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(abbrev_object, object_name))

        return_lines.append('@copydetails doc_returns_success_code')
        return_lines.append('@li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, '
                            'OperationReturnValues_t}')

        return_lines.append('@li @sbmlconstant{LIBSBML_OPERATION_FAILED,'
                            ' OperationReturnValues_t}')
        self.write_comment_header(title_line, params, return_lines,
                                  object_name)

        # create the function declaration
        if self.is_cpp_api:
            function = 'unset{0}'.format(attribute['capAttName'])
            return_type = 'int'
        else:
            function = '{0}_unset{1}'.format(class_name,
                                             attribute['capAttName'])
            return_type = 'int'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('{0} * {1}'
                             .format(object_name, abbrev_object))

        virtual = False
        constant = False
        self.write_function_header(function, arguments, return_type,
                                   constant, virtual)
        self.skip_line(2)

    ########################################################################

    # Functions for writing general functions

    # main general function writing function
    def write_general_functions(self):
        gen_functions = GeneralFunctions.GeneralFunctions(self.language,
                                                          self.is_cpp_api,
                                                          self.is_list_of,
                                                          self.class_object)
        code = gen_functions.write_rename_sidrefs()
        self.write_function_declaration(code)

        code = gen_functions.write_get_element_name()
        self.write_function_declaration(code)

        code = gen_functions.write_get_typecode()
        self.write_function_declaration(code)

        code = gen_functions.write_get_item_typecode()
        self.write_function_declaration(code)

        code = gen_functions.write_has_required_attributes()
        self.write_function_declaration(code)

        code = gen_functions.write_has_required_elements()
        self.write_function_declaration(code)

        code = gen_functions.write_write_elements()
        self.write_function_declaration(code, exclude=True)

        code = gen_functions.write_accept()
        self.write_function_declaration(code, exclude=True)

        code = gen_functions.write_set_document()
        self.write_function_declaration(code, exclude=True)

        code = gen_functions.write_connect_to_child()
        self.write_function_declaration(code, exclude=True)

        code = gen_functions.write_enable_package()
        self.write_function_declaration(code, exclude=True)


#         has_children = query.has_children(attributes)
#         has_package_children = query.has_children_not_math(attributes)
#
#         if self.is_cpp_api:
#             # if query.has_sid_ref(attributes):
#             #     self.write_rename_sidrefs_function(class_name)
#             # self.write_get_element_name(class_name)
#             # self.write_get_typecode(class_name)
#             if not self.is_list_of:
# #                self.write_has_reqd_attributes(class_name, attributes)
#                 if has_children:
#                     self.write_has_reqd_elements(class_name, attributes)
# #                self.write_write_elements(class_name)
# #                self.write_accept_function(class_name)
# #                self.write_set_document(class_name)
#                 if has_package_children:
#                     self.write_connect_to_child(class_name)
# #                self.write_enable_pkg_internal(class_name)
# #            else:
# #                self.write_get_item_typecode(class_name)
#         else:
# #            self.write_has_reqd_attributes(class_name, attributes)
#             if has_children:
#                 self.write_has_reqd_elements(class_name, attributes)
#
    def write_rename_sidrefs_function(self, class_name):
        # create doc string header
        title_line = '@copydoc doc_renamesidref_common'
        self.write_comment_header(title_line, [], [], class_name)

        # create the function declaration
        function = 'renameSIdRefs'
        return_type = 'void'
        arguments = ['const std::string& oldid', 'const std::string& newid']
        virtual = True
        constant = False
        self.write_function_header(function, arguments, return_type,
                                   constant, virtual)
        self.skip_line(2)

    def write_get_element_name(self, class_name):
        # create doc string header
        title_line = 'Returns the XML name of this {} object'.format(class_name)
        return_lines = ['@return the name of this element; that is \"'
                        '{}\".'.format(strFunctions.lower_first(class_name))]
        self.write_comment_header(title_line, [], return_lines, class_name)
        # create the function declaration
        function = 'getElementName'
        return_type = 'const std::string&'
        virtual = True
        constant = True
        self.write_function_header(function, [], return_type, constant, virtual)
        self.skip_line(2)

    def write_get_typecode(self, class_name):
        # create doc string header
        title_line = 'Returns the libSBML typcode of this {} object'\
            .format(class_name)
        params = ['@copydetails doc_what_are_typecodes']
        return_lines = ['@return the SBML type code for this object:']
        additional = []
        if self.is_list_of:
            line = '@sbmlconstant{SBML_LIST_OF, SBMLTypeCode_t}'
        else:
            line = '@sbmlconstant{' + '{}'.format(self.typecode) \
                   + ', SBML{}TypeCode_t'.format(self.package) + '}'
        additional.append(line)
        additional.append(' ')
        additional.append('@copydetails doc_warning_typecodes_not_unique')
        if not self.is_list_of:
            additional.append(' ')
            additional.append('@see getElementName()')
            additional.append('@see getPackageName()')
        self.write_comment_header(title_line, params, return_lines, class_name,
                                  additional)
        # create the function declaration
        function = 'getTypeCode'
        return_type = 'int'
        virtual = True
        constant = True
        self.write_function_header(function, [], return_type, constant, virtual)
        self.skip_line(2)

    def write_get_item_typecode(self, class_name):
        if not self.is_list_of:
            return
        # create doc string header
        title_line = 'Returns the libSBML type code for the SBML objects ' \
                     'contained in this {} object.'.format(class_name)
        params = ['@copydetails doc_what_are_typecodes']
        return_lines = ['@return the SBML typecode for the '
                        'objects contained in this list:']
        additional = []
        line = '@sbmlconstant{' + '{}'.format(self.typecode) \
               + ', SBML{}TypeCode_t'.format(self.package) + '}'
        additional.append(line)
        additional.append(' ')
        additional.append('@copydetails doc_warning_typecodes_not_unique')
        additional.append(' ')
        additional.append('@see getElementName()')
        additional.append('@see getPackageName()')
        self.write_comment_header(title_line, params, return_lines, class_name,
                                  additional)
        # create the function declaration
        function = 'getItemTypeCode'
        return_type = 'int'
        virtual = True
        constant = True
        self.write_function_header(function, [], return_type, constant, virtual)
        self.skip_line(2)

    def write_has_reqd_attributes(self, class_name, attributes):
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
            true = '@c 1'
            false = '@c 0'
        else:
            object_name = class_name
            true = '@c true'
            false = '@c false'
        # create doc string header
        title_line = 'Predicate returning {} if all the required ' \
                     'attributes for this {} object have been set.'\
            .format(true, object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(abbrev_object, object_name))

        return_lines = ['@return {0} to indicate that all the required '
                        'attributes of this {1} have been set, otherwise '
                        '{2} is returned.'.format(true, object_name, false)]
        additional = [' ', '@note The required attributes for the {} object'
                           ' are:'.format(object_name)]
        for i in range(0, len(attributes)):
            if attributes[i]['reqd']:
                att_type = attributes[i]['type']
                att_name = attributes[i]['name']
                if att_type != 'element' and att_type != 'lo_element':
                    additional.append('@li \"{}\"'.format(att_name))
        self.write_comment_header(title_line, params, return_lines, object_name,
                                  additional)
        # create the function declaration
        if self.is_cpp_api:
            function = 'hasRequiredAttributes'
            return_type = 'bool'
        else:
            function = '{0}_hasRequiredAttributes'.format(class_name)
            return_type = 'int'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(object_name, abbrev_object))
        virtual = True
        constant = True
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

    def write_has_reqd_elements(self, class_name, attributes):
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
            true = '@c 1'
            false = '@c 0'
        else:
            object_name = class_name
            true = '@c true'
            false = '@c false'
        # create doc string header
        title_line = 'Predicate returning {} if all the required ' \
                     'elements for this {} object have been set.'\
            .format(true, object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(abbrev_object, object_name))

        return_lines = ['@return {0} to indicate that all the required '
                        'elements of this {1} have been set, otherwise '
                        '{2} is returned.'.format(true, object_name, false)]
        additional = [' ', '@note The required elements for the {} object'
                           ' are:'.format(object_name)]
        for i in range(0, len(attributes)):
            if attributes[i]['reqd']:
                if attributes[i]['type'] == 'element' \
                        or attributes[i]['type'] == 'lo_element':
                    additional.append('@li \"{}\"'
                                      .format(attributes[i]['name']))
        self.write_comment_header(title_line, params, return_lines, object_name,
                                  additional)
        # create the function declaration
        if self.is_cpp_api:
            function = 'hasRequiredElements'
            return_type = 'bool'
        else:
            function = '{0}_hasRequiredElements'.format(class_name)
            return_type = 'int'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(object_name, abbrev_object))
        virtual = True
        constant = True
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

    def write_write_elements(self, class_name):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Write any contained elements'
        self.write_comment_header(title_line, [], [], class_name)

        # create the function declaration
        function = 'writeElements'
        return_type = 'void'
        arguments = ['XMLOutputStream& stream']
        virtual = True
        constant = True
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    def write_accept_function(self, class_name):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Accepts the given SBMLVisitor'
        self.write_comment_header(title_line, [], [], class_name)

        # create the function declaration
        function = 'accept'
        return_type = 'bool'
        arguments = ['SBMLVisitor& v']
        virtual = True
        constant = True
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    def write_set_document(self, class_name):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Sets the parent SBMLDocument'
        self.write_comment_header(title_line, [], [], class_name)

        # create the function declaration
        function = 'setSBMLDocument'
        return_type = 'void'
        arguments = ['SBMLDocument* d']
        virtual = True
        constant = False
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    def write_connect_to_child(self, class_name):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Connects to child elements'
        self.write_comment_header(title_line, [], [], class_name)

        # create the function declaration
        function = 'connectToChild'
        return_type = 'void'
        arguments = []
        virtual = True
        constant = False
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    def write_enable_pkg_internal(self, class_name):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Enables/disables the given package with this element'
        self.write_comment_header(title_line, [], [], class_name)

        # create the function declaration
        function = 'enablePackageInternal'
        return_type = 'void'
        arguments = ['const std::string& pkgURI',
                     'const std::string& pkgPrefix', 'bool flag']
        virtual = True
        constant = False
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    ########################################################################

    # Retrieve element functions
    def write_functions_to_retrieve(self, class_name):
        self.write_get_by_sid(class_name)
        self.write_get_by_metaid(class_name)
        self.write_get_all_elements(class_name)

    def write_get_by_sid(self, class_name):
        # create doc string header
        title_line = 'Returns the first child element that has the given ' \
                     '@p id in the model-wide SId namespace, or @c NULL if ' \
                     'no such object is found.'
        params = ['@param id a string representing the id attribute '
                  'of the object to retrieve.']
        return_lines = ['@return  a pointer to the SBase element with the '
                        'given @p id.']
        additional = []
        self.write_comment_header(title_line, params, return_lines,
                                  class_name, additional)

        # create the function declaration
        function = 'getElementBySId'
        return_type = 'SBase*'
        arguments = ['const std::string& id']
        virtual = True
        constant = False
        self.write_function_header(function, arguments, return_type,
                                   constant, virtual)
        self.skip_line(2)

    def write_get_by_metaid(self, class_name):
        # create doc string header
        title_line = 'Returns the first child element that has the given ' \
                     '@p metaid, or @c NULL if ' \
                     'no such object is found.'
        params = ['@param metaid a string representing the metaid attribute '
                  'of the object to retrieve.']
        return_lines = ['@return  a pointer to the SBase element with the '
                        'given @p metaid.']
        additional = []
        self.write_comment_header(title_line, params, return_lines,
                                  class_name, additional)

        # create the function declaration
        function = 'getElementByMetaId'
        return_type = 'SBase*'
        arguments = ['const std::string& metaid']
        virtual = True
        constant = False
        self.write_function_header(function, arguments, return_type,
                                   constant, virtual)
        self.skip_line(2)

    def write_get_all_elements(self, class_name):
        # create doc string header
        title_line = 'Returns a List of all child SBase objects, including ' \
                     'those nested to an arbitrary depth.'
        params = ['filter, an ElementFilter that may impose restrictions on '
                  'the objects to be retrieved.']
        return_lines = ['@return  a List* pointer of pointers to all '
                        'SBase child objects with any restriction imposed.']
        additional = []
        self.write_comment_header(title_line, params, return_lines,
                                  class_name, additional)

        # create the function declaration
        function = 'getAll Elements'
        return_type = 'List*'
        arguments = ['ElementFilter * filter = NULL']
        virtual = True
        constant = False
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line(2)

    ########################################################################

    # Protected functions

    def write_protected_functions(self):
        protect_functions = ProtectedFunctions.ProtectedFunctions(self.language,
                                  self.is_cpp_api, self.is_list_of, self.class_object)
        exclude = True
        code = protect_functions.write_create_object()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_add_expected_attributes()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_read_attributes()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_read_other_xml()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_write_attributes()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_write_xmlns()
        self.write_function_declaration(code, exclude)

#         if not self.is_list_of:
#             # if the only child is math we do not need this
# #            if query.has_children_not_math(self.attributes):
# #                self.write_create_object()
#             self.write_add_expected_attributes()
#             self.write_read_attributes()
#             if self.hasMath:
#                 self.write_read_other_xml()
#             self.write_write_attributes()
#         else:
#             self.write_create_object()
#             self.write_create_write_xmlns()

    def write_add_expected_attributes(self):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Adds the expected attributes for this element'
        self.write_comment_header(title_line, [], [], '')

        # create the function declaration
        function = 'addExpectedAttributes'
        return_type = 'void'
        arguments = ['ExpectedAttributes& attributes']
        virtual = True
        constant = False
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    def write_read_attributes(self):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Reads the expected attributes into the member ' \
                     'data variables'
        self.write_comment_header(title_line, [], [], '')

        # create the function declaration
        function = 'readAttributes'
        return_type = 'void'
        arguments = ['const XMLAttributes& attributes',
                     'const ExpectedAttributes& expectedAttributes']
        virtual = True
        constant = False
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    def write_write_attributes(self):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Writes the attributes to the stream'
        self.write_comment_header(title_line, [], [], '')

        # create the function declaration
        function = 'writeAttributes'
        return_type = 'void'
        arguments = ['XMLOutputStream& stream']
        virtual = True
        constant = True
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    def write_create_object(self):
        self.write_doxygen_start()
        # create doc string header
        if self.is_list_of:
            title_line = 'Creates a new {} in this {}'.format(self.name,
                                                              self.list_of_name)
        else:
            title_line = 'Creates a new object from the next XMLToken ' \
                         'on the XMLInputStream'
        self.write_comment_header(title_line, [], [], '')

        # create the function declaration
        function = 'createObject'
        return_type = 'SBase*'
        arguments = ['XMLInputStream& stream']
        virtual = True
        constant = False
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    def write_create_write_xmlns(self):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Writes the namespace for the {} package'\
            .format(self.package)
        self.write_comment_header(title_line, [], [], '')

        # create the function declaration
        function = 'writeXMLNS'
        return_type = 'void'
        arguments = ['XMLOutputStream& stream']
        virtual = True
        constant = True
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    def write_read_other_xml(self):
        self.write_doxygen_start()
        # create doc string header
        title_line = 'Reads other XML such as math/notes etc.'
        self.write_comment_header(title_line, [], [], '')

        # create the function declaration
        function = 'readOtherXML'
        return_type = 'bool'
        arguments = ['XMLInputStream& stream']
        virtual = True
        constant = False
        self.write_function_header(function,
                                   arguments, return_type, constant, virtual)
        self.skip_line()
        self.write_doxygen_end()

    ########################################################################

    # Functions for writing functions for the main ListOf class

    def write_listof_functions(self):
        lo_functions = ListOfQueryFunctions\
            .ListOfQueryFunctions(self.language, self.is_cpp_api,
                                  self.is_list_of,
                                  self.class_object)

        code = lo_functions.write_get_element_by_index(is_const=False)
        self.write_function_declaration(code)

        code = lo_functions.write_get_element_by_index(is_const=True)
        self.write_function_declaration(code)

        code = lo_functions.write_get_element_by_id(is_const=False)
        self.write_function_declaration(code)

        code = lo_functions.write_get_element_by_id(is_const=True)
        self.write_function_declaration(code)

        code = lo_functions.write_remove_element_by_index()
        self.write_function_declaration(code)

        code = lo_functions.write_remove_element_by_id()
        self.write_function_declaration(code)

        if self.is_cpp_api:
            code = lo_functions.write_add_element_function()
            self.write_function_declaration(code)

            code = lo_functions.write_get_num_element_function()
            self.write_function_declaration(code)

            code = lo_functions.write_create_element_function()
            self.write_function_declaration(code)

            for i in range(0, len(self.sid_refs)):
                code = \
                    lo_functions.write_get_element_by_sidref(self.sid_refs[i],
                                                                const = True)
                self.write_function_declaration(code)

                code = \
                    lo_functions.write_get_element_by_sidref(self.sid_refs[i],
                                                                const = False)
                self.write_function_declaration(code)
            ############

            #THIS WILL HAVE NO ATTRIBUTES
            # num_attributes = len(self.attributes)
            #
            # for i in range(0, num_attributes):
            #     attribute = self.attributes[i]
            #     if attribute['type'] == 'SIdRef':
            #         self.write_get_by_sidref_functions(class_name,
            #                                            attribute, [])

    # main function to write the functions dealing with a child listOf element
    def write_child_lo_element_functions(self, class_name):
        num_elements = len(self.child_lo_elements)
        for i in range(0, num_elements):
            element = self.child_lo_elements[i]
            # for hacking purposes
            if self.is_cpp_api:
                self.write_get_listof_functions(class_name, element)
                self.write_get_element_functions(class_name, element)
                self.write_child_get_by_sidref(class_name, element)
                self.write_add_element_function(class_name, element)
                self.write_get_num_elements_function(class_name, element)
                self.write_create_element_function(class_name, element, False)
                self.write_remove_element_functions(class_name, element)
            else:
                self.write_add_element_function(class_name, element)
                self.write_create_element_function(class_name, element, False)
                self.write_get_listof_functions(class_name, element)
                self.write_get_element_functions(class_name, element)
                self.write_get_num_elements_function(class_name, element)
                self.write_remove_element_functions(class_name, element)

    # function to work out and call get By reference
    def write_child_get_by_sidref(self, class_name, attribute):
        child_element = query.get_class(attribute['element'], attribute['root'])
        if child_element is not None:
            num_attributes = len(child_element['attribs'])
            for i in range(0, num_attributes):
                attrib = child_element['attribs'][i]
                if attrib['type'] == 'SIdRef':
                    self.write_get_by_sidref_functions(class_name, attrib,
                                                       attribute['element'])

    # function to write the getListOf functions
    def write_get_listof_functions(self, class_name, attribute):
        abbrev_object = ''
        if self.is_cpp_api:
            parent = class_name
            loname = attribute['attTypeCode']
            ob_name = attribute['element']
        else:
            parent = class_name + '_t'
            loname = attribute['attTypeCode']
            ob_name = attribute['element'] + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)

        params = []
        if self.is_cpp_api:
            title_line = 'Returns the {} from this {}.'.format(loname, parent)
            return_lines = ['@return the {} from this {}.'.format(loname,
                                                                  parent)]
        else:
            title_line = 'Returns a ListOf_t* containing {} objects ' \
                         'from this {}.'.format(ob_name, parent)
            params.append('@param {} the {} structure whose \"{}\" is sought.'
                          .format(abbrev_object, parent, loname))
            return_lines = ['@return the \"{}\" from this {} as a '
                            'ListOf_t *.'.format(loname, parent)]
        additional = []
        self.write_comment_header(title_line, params, return_lines,
                                  parent, additional)

        # create the function declaration
        if self.is_cpp_api:
            function = 'get{}'.format(loname)
            arguments = []
            return_type = 'const {}*'.format(loname)
        else:
            function = '{}_get{}'.format(class_name, loname)
            arguments = ['const {}* {}'.format(parent, abbrev_object)]
            return_type = 'ListOf_t*'
        virtual = False
        constant = True
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

        if self.is_cpp_api:
            # write non - const version
            return_type = '{}*'.format(loname)
            constant = False
            self.write_comment_header(title_line, params, return_lines,
                                      parent, additional)
            self.write_function_header(function, arguments,
                                       return_type, constant, virtual)
            self.skip_line(2)

    # function to write the getElement/get functions from ListOf
    def write_get_element_functions(self, class_name, attribute):
        struct = query.create_structure_for_getters(self.name, class_name,
                                                    attribute, self.is_cpp_api,
                                                    self.is_list_of)
        self.write_get_by_index_functions(struct)
        self.write_get_by_id_functions(struct)

    def write_get_by_index_functions(self, struct):
        cap_name = struct['cap_name']
        plural = struct['plural']
        name = struct['name']
        ob_name = struct['ob_name']
        parent = struct['parent']
        ob_parent = struct['ob_parent']
        indef_name = struct['indef']
        class_name = struct['class_name']
        abbrev_parent = strFunctions.abbrev_name(parent)

        if self.is_cpp_api:
            # non const get by index
            # create doc string header
            title_line = 'Get {} {} from the {}.'.format(indef_name, name,
                                                         parent)
            params = ['@param n an unsigned int representing '
                      'the index of the {} to retrieve.'.format(ob_name)]
            return_lines = ['@return the nth {} in this {}.'.format(name,
                                                                    parent)]
            additional = ['@see size()'] if self.is_list_of \
                else ['@see getNum{}'.format(plural)]
            self.write_comment_header(title_line, params, return_lines,
                                      class_name,
                                      additional)
            # create the function declaration
            function = 'get' if self.is_list_of else 'get{}'.format(cap_name)
            arguments = ['unsigned int n']
            return_type = '{}*'.format(name)
            virtual = True if self.is_list_of else False
            constant = False
            self.write_function_header(function, arguments,
                                       return_type, constant, virtual)
            self.skip_line(2)

        # const get by index
        title_line = 'Get {} {} from the {}.'\
            .format(indef_name, ob_name, ob_parent)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'
                          .format(abbrev_parent, ob_parent))
        params.append('@param n, an unsigned int representing the '
                      'index of the {} to retrieve.'.format(ob_name))

        return_lines = ['@return the nth {} in this {}.'.format(ob_name,
                                                                ob_parent)]
        additional = []
        object_name = ob_parent \
            if ob_parent != 'ListOf_t' else class_name + '_t'
        if self.is_cpp_api:
            additional = ['@see size()'] if self.is_list_of \
                else ['@see getNum{}'.format(plural)]
            object_name = class_name

        self.write_comment_header(title_line, params, return_lines,
                                  object_name, additional)
        # create the function declaration
        if self.is_cpp_api:
            function = 'get' if self.is_list_of else 'get{}'.format(cap_name)
            arguments = ['unsigned int n']
        else:
            function = '{}_get{}'.format(parent, name)
            arguments = ['{}* {}'.format(ob_parent, abbrev_parent),
                         'unsigned int']
        return_type = 'const {}*'.format(ob_name)
        virtual = True if self.is_list_of else False
        constant = True
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

    def write_get_by_id_functions(self, struct):
        # these may not used in all cases but declared to keep PEP8 happy
        plural = struct['plural']
        name = struct['name']
        ob_name = struct['ob_name']
        parent = struct['parent']
        ob_parent = struct['ob_parent']
        indef_name = struct['indef']
        class_name = struct['class_name']
        abbrev_parent = strFunctions.abbrev_name(parent)
        if self.is_cpp_api:
            # non const get by id
            # create doc string header
            title_line = 'Get {} {} from the {} based on its identifier.'\
                .format(indef_name, name, parent)
            params = ['@param sid a string representing the identifier '
                      'of the {} to retrieve.'.format(name)]
            return_lines = ['@return the {0} in this {1} based on the '
                            'identifier or NULL if no such {0} exists.'
                            .format(name, parent)]
            additional = ['@see size()'] if self.is_list_of \
                else ['@see getNum{}'.format(plural)]
            self.write_comment_header(title_line, params, return_lines,
                                      class_name,
                                      additional)
            # create the function declaration
            function = 'get' if self.is_list_of else 'get{}'.format(name)
            arguments = ['const std::string& sid']
            return_type = '{}*'.format(name)
            virtual = True if self.is_list_of else False
            constant = False
            self.write_function_header(function, arguments,
                                       return_type, constant, virtual)
            self.skip_line(2)

        # const get by id
        # create doc string header
        object_name = class_name
        title_line = 'Get {} {} from the {} based on its identifier.'\
            .format(indef_name, ob_name, ob_parent)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'
                          .format(abbrev_parent, ob_parent))
            object_name = ob_parent \
                if ob_parent != 'ListOf_t' else class_name + '_t'
        params.append('@param sid a string representing the identifier '
                      'of the {} to retrieve.'.format(ob_name))
        return_lines = ['@return the {0} in this {1} based on the '
                        'identifier or NULL if no such {0} exists.'
                        .format(ob_name, ob_parent)]
        additional = []
        self.write_comment_header(title_line, params, return_lines,
                                  object_name, additional)

        # create the function declaration
        if self.is_cpp_api:
            function = 'get' if self.is_list_of else 'get{}'.format(name)
            arguments = ['const std::string& sid']
            return_type = 'const {}*'.format(name)
        else:
            function = '{}_getById'.format(parent) if self.is_list_of \
                else '{}_get{}ById'.format(parent, name)
            arguments = ['{}* {}'.format(ob_parent, abbrev_parent),
                         'const char *sid']
            return_type = '{}*'.format(ob_name)
        virtual = True if self.is_list_of else False
        constant = True
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

    # function to get an element by SIdRef
    def write_get_by_sidref_functions(self, class_name, attribute,
                                      child_lo):
        if child_lo is None:
            child_lo = []
        if len(child_lo) > 0:
            ob_name = child_lo
            child = child_lo
        else:
            ob_name = self.name
            child = ''
        indef = strFunctions.get_indefinite(ob_name)
        sidref = attribute['element']
        # const get by sidref
        # create doc string header
        title_line = 'Get {} {} from the {} based on the {} to which ' \
                     'it refers.'.format(indef, ob_name, class_name, sidref)
        params = ['@param sid a string representing the {} attribute of the {} '
                  'object to retrieve.'.format(strFunctions.lower_first(sidref),
                                               ob_name)]
        return_lines = ['@return the first {0} in this {1} based on the '
                        'given {2} attribute or NULL if no such {0} exists.'
                        .format(ob_name, class_name,
                                strFunctions.lower_first(sidref))]
        additional = []
        self.write_comment_header(title_line, params, return_lines,
                                  class_name, additional)
        # create the function declaration
        function = 'get{}By{}'.format(child, sidref)
        arguments = ['const std::string& sid']
        return_type = 'const {}*'.format(ob_name)
        virtual = False
        constant = True
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)
        # non-const version
        constant = False
        self.write_comment_header(title_line, params, return_lines,
                                  class_name, additional)
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

    # function to write the getElement/get functions from ListOf
    def write_remove_element_functions(self, class_name, attribute):
        struct = query.create_structure_for_getters(self.name, class_name,
                                                    attribute, self.is_cpp_api,
                                                    self.is_list_of)
        cap_name = struct['cap_name']
        plural = struct['plural']
        name = struct['name']
        ob_name = struct['ob_name']
        parent = struct['parent']
        ob_parent = struct['ob_parent']
        class_name = struct['class_name']
        abbrev_parent = strFunctions.abbrev_name(parent)
        # by index
        # create doc string header
        title_line = 'Removes the nth {} from this {} and returns a ' \
                     'pointer to it.'.format(ob_name, ob_parent)
        params = []
        additional = []
        object_name = ob_parent \
            if ob_parent != 'ListOf_t' else class_name + '_t'
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'
                          .format(abbrev_parent, ob_parent))

        params.append('@param n an unsigned int representing the index of '
                      'the {} to remove.'.format(ob_name))
        return_lines = ['@return a pointer to the nth {} in this {}.'
                        .format(ob_name, ob_parent)]
        if self.is_cpp_api:
            additional = ['@see size()'] if self.is_list_of \
                else ['@see getNum{}'.format(plural)]
            additional.append(' ')
            additional.append('@note the caller owns the returned object and '
                              'is responsible for deleting it.')
            object_name = class_name
        self.write_comment_header(title_line, params, return_lines,
                                  object_name, additional)
        # create the function declaration
        if self.is_cpp_api:
            function = 'remove' if self.is_list_of \
                else 'remove{}'.format(cap_name)
            arguments = ['unsigned int n']
            return_type = '{}*'.format(name)
        else:
            function = '{}_remove{}'.format(parent, name)
            arguments = ['{}* {}'.format(ob_parent, abbrev_parent),
                         'unsigned int']
            return_type = '{}*'.format(ob_name)
        virtual = True if self.is_list_of else False
        constant = False
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

        # by id
        # create doc string header
        title_line = 'Removes the {} from this {} based on its identifier ' \
                     'and returns a pointer to it.'\
            .format(ob_name, ob_parent)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'
                          .format(abbrev_parent, ob_parent))
        params.append('@param sid a string representing the identifier '
                      'of the {} to remove.'.format(ob_name))
        return_lines = ['@return the {0} in this {1} based on the '
                        'identifier or NULL if no such {0} exists.'
                        .format(ob_name, ob_parent)]
        additional = []
        self.write_comment_header(title_line, params, return_lines,
                                  object_name, additional)
        # create the function declaration
        if self.is_cpp_api:
            function = 'remove' if self.is_list_of \
                else 'remove{}'.format(cap_name)
            arguments = ['const std::string& sid']
            return_type = '{}*'.format(name)
        else:
            function = '{}_remove{}ById'.format(parent, name)
            arguments = ['{}* {}'.format(ob_parent, abbrev_parent),
                         'const char* sid']
            return_type = '{}*'.format(ob_name)
        virtual = True if self.is_list_of else False
        constant = False
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

    # function to write the addElement function
    def write_add_element_function(self, class_name, attribute):
        struct = query.create_structure_for_children(self.name, class_name,
                                                     attribute, self.is_cpp_api,
                                                     self.is_list_of)
        name = struct['name']
        ob_name = struct['ob_name']
        parent = struct['parent']
        ob_parent = struct['ob_parent']
        abbrev = strFunctions.abbrev_name(ob_name)
        abbrev_parent = strFunctions.abbrev_name(parent)
        # create doc string header
        title_line = 'Adds a copy of the given {} to this {}.'\
            .format(ob_name, ob_parent)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to which the '
                          '{} should be added.'.format(abbrev_parent,
                                                       ob_parent, ob_name))
        params.append('@param {}; the {} object to add.'
                      .format(abbrev, ob_name))
        return_lines = ['@copydetails doc_returns_success_code',
                        '@li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, '
                        'OperationReturnValues_t}',
                        '@li @sbmlconstant{LIBSBML_OPERATION_FAILED,'
                        ' OperationReturnValues_t}']
        additional = []
        if self.is_cpp_api:
            additional.append('@copydetails doc_note_object_is_copied')
            additional.append(' ')
            additional.append('@see create{}()'.format(ob_name))
        self.write_comment_header(title_line, params, return_lines,
                                  ob_parent, additional)
        # create the function declaration
        if self.is_cpp_api:
            function = 'add{}'.format(name)
            arguments = ['const {}* {}'.format(ob_name, abbrev)]
        else:
            function = '{}_add{}'.format(parent, name)
            arguments = ['{}* {}'.format(ob_parent, abbrev_parent),
                         '{}* {}'.format(ob_name, abbrev)]
        return_type = 'int'
        virtual = False
        constant = False
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

    # function to write the getNumElements function
    def write_get_num_elements_function(self, class_name, attribute):
        struct = query.create_structure_for_children(self.name, class_name,
                                                     attribute, self.is_cpp_api,
                                                     self.is_list_of)
        name = struct['name']
        ob_name = struct['ob_name']
        parent = struct['parent']
        ob_parent = struct['ob_parent']
        abbrev_parent = strFunctions.abbrev_name(parent)
        # create doc string header
        title_line = 'Get the number of {} objects in this {}.'\
            .format(ob_name, ob_parent)

        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to which the '
                          '{} should be added.'.format(abbrev_parent,
                                                       ob_parent, ob_name))
        return_lines = ['@return the number of {} objects in '
                        'this {}.'.format(ob_name, ob_parent)]
        additional = []
        self.write_comment_header(title_line, params, return_lines,
                                  class_name, additional)
        # create the function declaration
        arguments = []
        if self.is_cpp_api:
            function = 'getNum{}'.format(strFunctions.plural(ob_name))
        else:
            function = '{}_getNum{}'.format(parent, strFunctions.plural(name))
            arguments.append('const {}* {}'.format(ob_parent, abbrev_parent))
        return_type = 'unsigned int'
        virtual = False
        constant = True
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

    # function to write the createElement function
    def write_create_element_function(self, class_name, attribute, is_single):
        if is_single and attribute['element'] == 'ASTNode':
            return
        # attribute will be empty when working from a ListOf parent
        if not self.is_list_of:
            name = attribute['element'] if not is_single else attribute['name']
            parent = class_name
            if self.is_cpp_api:
                ob_name = attribute['element']
                ob_parent = class_name
            else:
                ob_name = attribute['element'] + '_t'
                ob_parent = class_name + '_t'
        else:
            ob_name = self.name
            name = self.name
            parent = class_name
            ob_parent = class_name
        abbrev = strFunctions.abbrev_name(ob_name)
        abbrev_parent = strFunctions.abbrev_name(parent)
        # create doc string header
        title_line = 'Creates a new {0} object, adds it to this {1} object ' \
                     'and returns the {0} object created.'.format(ob_name,
                                                                  ob_parent)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to which the '
                          '{} should be added.'.format(abbrev_parent,
                                                       ob_parent, ob_name))
        return_lines = ['@return a new {} object instance.'. format(ob_name)]
        additional = []
        if self.is_cpp_api and not is_single:
            additional.append('@see add{0}(const {0}* {1})'.format(ob_name,
                                                                   abbrev))
        self.write_comment_header(title_line, params, return_lines,
                                  ob_parent, additional)
        # create the function declaration
        if self.is_cpp_api:
            function = 'create{}'.format(name)
        else:
            function = '{}_create{}'.format(parent, name)
        arguments = []
        if not self.is_cpp_api:
            arguments.append('{}* {}'.format(ob_parent, abbrev_parent))
        return_type = '{}*'.format(ob_name)
        virtual = False
        constant = False
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

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
        self.write_class(self.baseClass, self.name, self.attributes)
        self.write_cppns_end()
        self.write_cpp_end()
        self.write_swig_begin()
        self.write_cppns_begin()
        self.write_cdecl_begin()
        self.write_c_header()
        self.write_cdecl_end()
        self.write_cppns_end()
        self.write_swig_end()
        self.write_defn_end()
