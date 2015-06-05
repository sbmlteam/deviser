#!/usr/bin/env python
#
# @file    CppHeaderFile.py
# @brief   class for generating cpp header files
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
from util import strFunctions
from util import query


class CppHeaderFile(BaseCppFile.BaseCppFile):
    """Class for all Cpp Header files"""

    def __init__(self, class_object):
        # members from object
        self.name = class_object['name']
        self.package = class_object['package']
        self.child_elements = []
        self.has_list_of = class_object['hasListOf']
        self.attributes_on_list_of = ''  # class_object['loattrib']
        self.typecode = class_object['typecode']

        # check case of things where we assume upper/lower
        if self.package[0].islower():
            self.package = strFunctions.upper_first(class_object['package'])

        # derived members
        self.list_of_name = strFunctions.list_of_name(self.name)

        # derived members for description
        if class_object['hasListOf'] is True:
            self.brief_description = 'Definitions of {0} and {1}.' \
                .format(self.name, self.list_of_name)
        else:
            self.brief_description = 'Definition of {0}.'.format(self.name)

        BaseCppFile.BaseCppFile.__init__(self, self.name, 'h',
                                         class_object['attribs'])

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
        if self.has_list_of:
            self.write_line('#include <{0}/ListOf.h>'.format(self.language))
        if self.package:
            self.write_line(
                '#include <{0}/packages/{1}/extension/{2}Extension.h>'
                .format(self.language, self.package.lower(), self.package))

        # additional includes for child elements
        for i in range(0, len(self.child_elements)):
            child = self.child_elements[i]['capAttName']
            self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'
                            .format(self.language, self.package.lower(),
                                    child))

        for i in range(0, len(self.child_lo_elements)):
            child = self.child_lo_elements[i]['capAttName']
            self.write_line('#include <{0}/packages/{1}/{0}/{2}.h>'
                            .format(self.language, self.package.lower(),
                                    child))

    ########################################################################

    # Functions for writing the class
    def write_class(self, base_class, class_name, attributes):
        if base_class == 'ListOf':
            self.is_list_of = True
            class_attributes = attributes
            has_children = 0
        else:
            class_attributes = query.seperate_attributes(attributes)
            has_children = \
                (len(self.child_elements) + len(self.child_lo_elements)) > 0
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
        self.write_constructors(class_name)
        self.write_attribute_functions(class_name, class_attributes)
        if base_class != 'ListOf':
            self.write_child_element_functions(class_name)
        if base_class == 'ListOf':
            self.write_listof_functions(class_name)
        else:
            self.write_child_lo_element_functions(class_name)
        self.write_general_functions(class_name, attributes)
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
        self.is_list_of = False
        self.is_cpp_api = False
        class_attributes = query.seperate_attributes(self.attributes)
        self.write_constructors(self.name)
        self.write_attribute_functions(self.name, class_attributes)
        self.write_child_element_functions(self.name)
        self.write_child_lo_element_functions(self.name)
        self.write_general_functions(self.name, self.attributes)
        self.is_list_of = True
        self.write_listof_functions(self.name)

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

    # Functions for writing constructors

    # function to write the constructors
    def write_constructors(self, class_name):
        self.write_level_version_constructor(class_name)
        self.write_namespace_constructor(class_name)
        self.write_copy_constructor(class_name)
        self.write_assignment_operator(class_name)
        self.write_clone(class_name)
        self.write_destructor(class_name)

    # function to write level version constructor
    def write_level_version_constructor(self, class_name):
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
        else:
            object_name = class_name

        # create doc string header
        title_line = 'Creates a new {0} using the given SBML @p level' \
            .format(object_name)
        if self.package:
            title_line += ', @ p version and package version values.'
        else:
            title_line += ' and @ p version values.'

        params = ['@param level an unsigned int, the SBML Level to '
                  'assign to this {0}'.format(object_name),
                  '@param version an unsigned int, the SBML Version to '
                  'assign to this {0}'.format(object_name)]
        if self.package:
            params.append('@param pkgVersion an unsigned int, the SBML {0} '
                          'Version to assign to this {1}'
                          .format(self.package, object_name))

        return_lines = ['@throws SBMLConstructorException',
                        'Thrown if the given @p level and @p version '
                        'combination, or this kind of SBML object, are '
                        'either invalid or mismatched with respect to the '
                        'parent SBMLDocument object.',
                        '@copydetails doc_note_setting_lv']
        self.write_comment_header(title_line, params, return_lines,
                                  object_name)

        # create the function declaration
        if self.is_cpp_api:
            function = class_name
            return_type = ''
        else:
            function = '{}_create'.format(class_name)
            return_type = '{0} *'.format(object_name)

        if self.package:
            arguments = [
                'unsigned int level = '
                '{}Extension::getDefaultLevel()'.format(self.package),
                'unsigned int version = '
                '{}Extension::getDefaultVersion()'.format(self.package),
                'unsigned int pkgVersion = '
                '{}Extension::getDefaultPackageVersion()'.format(self.package)]
        else:
            arguments = ['unsigned int level',
                         'unsigned int version']

        self.write_function_header(function,
                                   arguments, return_type)
        self.skip_line(2)

    # function to write namespace constructor
    def write_namespace_constructor(self, class_name):
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
        else:
            object_name = class_name

        # create doc string header
        title_line = 'Creates a new {0} using the given'.format(object_name)
        if self.package:
            title_line = title_line + ' {0}PkgNamespaces object.' \
                .format(self.package)
        else:
            title_line = title_line + ' {0}Namespaces object @p {1}ns.' \
                .format(self.language.upper(), self.language)

        params = []
        if self.package:
            params.append('@param {0}ns the {1}PkgNamespaces object'
                          .format(self.package.lower(), self.package))
        else:
            params.append('@param {0}ns the {1}Namespaces object'
                          .format(self.language, self.language.upper()))

        return_lines = ['@throws SBMLConstructorException',
                        'Thrown if the given @p level and @p version '
                        'combination, or this kind of SBML object, are '
                        'either invalid or mismatched with respect to the '
                        'parent SBMLDocument object.',
                        '@copydetails doc_note_setting_lv']

        self.write_comment_header(title_line, params, return_lines,
                                  object_name)

        # create the function declaration
        if self.is_cpp_api:
            function = class_name
            return_type = ''
        else:
            function = '{0}_createWithNS'.format(class_name)
            return_type = '{0} *'.format(object_name)

        arguments = []
        if self.package:
            if self.is_cpp_api:
                arguments.append('{0}PkgNamespaces *{1}ns'
                                 .format(self.package, self.package.lower()))
            else:
                arguments.append('{0}PkgNamespaces_t *{1}ns'
                                 .format(self.package, self.package.lower()))

        else:
            if self.is_cpp_api:
                arguments.append('{0}Namespaces *{1}ns'
                                 .format(self.language.upper(), self.language))
            else:
                arguments.append('{0}Namespaces_t *{1}ns'
                                 .format(self.language.upper(), self.language))

        self.write_function_header(function,
                                   arguments, return_type)
        self.skip_line(2)

    # function to write copy constructor
    def write_copy_constructor(self, class_name):
        # do not write for C API
        if self.is_cpp_api is False:
            return
        self.open_comment()
        self.write_comment_line('Copy constructor for {0}.'.format(class_name))
        self.write_blank_comment_line()
        self.write_comment_line('@param orig; the {0} instance to copy.'
                                .format(class_name))
        self.close_comment()
        self.write_line('{0}(const {0}& orig);'.format(class_name))
        self.skip_line(2)

    # function to write assignment operator
    def write_assignment_operator(self, class_name):
        # do not write for C API
        if self.is_cpp_api is False:
            return
        self.open_comment()
        self.write_comment_line('Assignment operator for {0}.'
                                .format(class_name))
        self.write_blank_comment_line()
        self.write_comment_line('@param rhs; the {0} object whose values are '
                                'to be used as the basis of the assignment'
                                .format(class_name))
        self.close_comment()
        self.write_line('{0}& operator=(const {0}& rhs);'.format(class_name))
        self.skip_line(2)

    # function to write clone
    def write_clone(self, class_name):
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
        else:
            object_name = class_name
        self.open_comment()
        self.write_comment_line('Creates and returns a deep copy of '
                                'this {0} object.'.format(object_name))
        if not self.is_cpp_api:
            self.write_blank_comment_line()
            self.write_comment_line('@param {0} the {1} structure'
                                    .format(abbrev_object, object_name))
        self.write_blank_comment_line()
        self.write_comment_line('@return a (deep) copy of this {0} object.'
                                .format(object_name))
        self.close_comment()
        if self.is_cpp_api:
            self.write_line('virtual {0}* clone () const;'.format(class_name))
        else:
            self.write_extern_decl()
            self.write_line('{0} *'.format(object_name))
            self.write_line('{0}_clone(const {1} * {2});'
                            .format(class_name, object_name, abbrev_object))

        self.skip_line(2)

    # function to write destructor
    def write_destructor(self, class_name):
        abbrev_object = ''
        if self.is_cpp_api is False:
            object_name = class_name + '_t'
            abbrev_object = strFunctions.abbrev_name(class_name)
        else:
            object_name = class_name
        self.open_comment()
        if self.is_cpp_api:
            self.write_comment_line('Destructor for {0}.'.format(class_name))
        else:
            self.write_comment_line('Frees this {0} object.'
                                    .format(object_name))
            self.write_blank_comment_line()
            self.write_comment_line('@param {0} the {1} structure'
                                    .format(abbrev_object, object_name))
        self.close_comment()
        if self.is_cpp_api:
            self.write_line('virtual ~{0}();'.format(class_name))
        else:
            self.write_extern_decl()
            self.write_line('void')
            self.write_line('{0}_free({1} * {2});'
                            .format(class_name, object_name, abbrev_object))
        self.skip_line(2)

    ########################################################################

    # Functions for writing the attribute manipulation functions
    # these are for attributes and elements that occur as a single child

    # function to write the get/set/isSet/unset functions for attributes
    def write_attribute_functions(self, class_name, class_attributes):
        num_attributes = len(class_attributes)
        for i in range(0, num_attributes):
            self.write_get_function(class_name, class_attributes[i], True)
        for i in range(0, num_attributes):
            self.write_is_set_function(class_name, class_attributes[i], True)
        for i in range(0, num_attributes):
            self.write_set_function(class_name, class_attributes[i], True)
        for i in range(0, num_attributes):
            self.write_unset_function(class_name, class_attributes[i], True)

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
        if attribute['isEnum'] is True:
            self.write_get_string_for_enum_function(class_name, attribute)

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
    def write_general_functions(self, class_name, attributes):
        has_children = query.has_children(attributes)

        if self.is_cpp_api:
            if query.has_sid_ref(attributes):
                self.write_rename_sidrefs_function(class_name)
            self.write_get_element_name(class_name)
            self.write_get_typecode(class_name)
            if not self.is_list_of:
                self.write_has_reqd_attributes(class_name, attributes)
                if has_children:
                    self.write_has_reqd_elements(class_name, attributes)
                self.write_write_elements(class_name)
                self.write_accept_function(class_name)
                self.write_set_document(class_name)
                if has_children:
                    self.write_connect_to_child(class_name)
                self.write_enable_pkg_internal(class_name)
        else:
            self.write_has_reqd_attributes(class_name, attributes)
            if has_children:
                self.write_has_reqd_elements(class_name, attributes)

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
        if self.is_list_of:
            title_line = 'Returns the libSBML type code for the SBML objects ' \
                         'contained in this {} object.'.format(class_name)
        else:
            title_line = 'Returns the libSBML typcode of this {} object' \
                .format(class_name)
        params = ['@copydetails doc_what_are_typecodes']
        return_lines = []
        if self.is_list_of:
            return_lines.append('@return the SBML typecode for the '
                                'objects contained in this list:')
        else:
            return_lines.append('@return the SBML type code for this object:')
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
        if self.is_list_of:
            function = 'getItemTypeCode'
        else:
            function = 'getTypeCode'
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
        if not self.is_list_of:
            if (len(self.child_elements) + len(self.child_lo_elements)) > 0:
                self.write_create_object()
            self.write_add_expected_attributes()
            self.write_read_attributes()
            self.write_write_attributes()
        else:
            self.write_create_object()
            self.write_create_write_xmlns()

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

    ########################################################################

    # Functions for writing functions for the main ListOf class

    def write_listof_functions(self, class_name):
        self.write_get_element_functions(class_name, [])
        self.write_remove_element_functions(class_name, [])
        if self.is_cpp_api:
            self.write_add_element_function(class_name, [])
            self.write_get_num_elements_function(class_name, [])
            self.write_create_element_function(class_name, [])
            num_attributes = len(self.attributes)
            for i in range(0, num_attributes):
                attribute = self.attributes[i]
                if attribute['type'] == 'SIdRef':
                    self.write_get_by_sidref_functions(class_name,
                                                       attribute, [])

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
                self.write_create_element_function(class_name, element)
                self.write_remove_element_functions(class_name, element)
            else:
                self.write_add_element_function(class_name, element)
                self.write_create_element_function(class_name, element)
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
            virtual = False
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
        object_name = ob_parent if ob_parent != 'ListOf_t' else class_name + '_t'
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
        virtual = False
        constant = True
        self.write_function_header(function, arguments,
                                   return_type, constant, virtual)
        self.skip_line(2)

    def write_get_by_id_functions(self, struct):
        # these may not used in all cases but declared to keep PEP8 happy
        cap_name = struct['cap_name']
        plural = struct['plural']
        name = struct['name']
        ob_name = struct['ob_name']
        parent = struct['parent']
        ob_parent = struct['ob_parent']
        indef_name = struct['indef']
        class_name = struct['class_name']
        abbrev_parent = strFunctions.abbrev_name(parent)
        additional = []
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
            virtual = False
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
            object_name = ob_parent if ob_parent != 'ListOf_t' else class_name + '_t'
        params.append('@param sid a string representing the identifier '
                      'of the {} to retrieve.'.format(ob_name))
        return_lines = ['@return the {0} in this {1} based on the '
                        'identifier or NULL if no such {0} exists.'
                        .format(ob_name, ob_parent)]
        additional = []
        self.write_comment_header(title_line, params, return_lines, object_name, additional)

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
        virtual = False
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
        indef_name = struct['indef']
        class_name = struct['class_name']
        abbrev_parent = strFunctions.abbrev_name(parent)


        # by index
        # create doc string header
        title_line = 'Removes the nth {} from this {} and returns a ' \
                     'pointer to it.'.format(ob_name, ob_parent)
        params = []
        additional = []
        object_name = ob_parent if ob_parent != 'ListOf_t' else class_name + '_t'
        if not self.is_cpp_api:
            params.append('@param {}, the {} structure to search.'.format(abbrev_parent, ob_parent))

        params.append('@param n an unsigned int representing the index of the {} to remove.'.format(ob_name))
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
        virtual = False
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
            params.append('@param {}, the {} structure to search.'.format(abbrev_parent, ob_parent))
        params.append('@param sid a string representing the identifier '
                      'of the {} to remove.'.format(ob_name))
        return_lines = ['@return the {0} in this {1} based on the '
                        'identifier or NULL if no such {0} exists.'
                        .format(ob_name, ob_parent)]
        additional = []
        self.write_comment_header(title_line, params, return_lines, object_name, additional)
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
        virtual = False
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
        params.append('@param {}; the {} object to add.'.format(abbrev, ob_name))
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
        abbrev = strFunctions.abbrev_name(ob_name)
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
        arguments= []
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
    def write_create_element_function(self, class_name, attribute):
        # attribute will be empty when working from a ListOf parent
        if not self.is_list_of:
            name = attribute['element']
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
        if self.is_cpp_api:
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
        if self.has_list_of:
            self.write_class('ListOf', self.list_of_name,
                             self.attributes_on_list_of)
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
