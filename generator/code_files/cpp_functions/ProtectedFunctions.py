#!/usr/bin/env python
#
# @file    ProtectedFunctions.py
# @brief   class to create protected functions
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

from util import strFunctions, query, global_variables


class ProtectedFunctions():
    """Class for all protected functions"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object, lv_info=[]):
        self.language = language
        self.cap_language = language.upper()
        self.package = class_object['package']
        self.class_name = class_object['name']
        self.is_cpp_api = is_cpp_api
        self.is_list_of = is_list_of
        self.is_plugin = False
        self.base = ''
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']
            if 'sbase' in class_object:
                self.base = class_object['sbase']
        if is_list_of:
            self.child_name = class_object['lo_child']
        else:
            self.child_name = ''
        if is_cpp_api:
            self.object_name = self.class_name
            self.object_child_name = self.child_name
        else:
            if is_list_of:
                self.object_name = 'ListOf_t'
            else:
                self.object_name = self.class_name + '_t'
            self.object_child_name = self.child_name + '_t'
        self.parent_class = ''
        if not self.is_plugin:
            self.parent_class = query.get_parent_class(class_object)

        self.attributes = class_object['class_attributes']
        self.all_attributes = class_object['attribs']
        self.has_math = class_object['has_math']
        if 'is_doc_plugin' in class_object and class_object['is_doc_plugin']:
            self.std_base = global_variables.baseClass
        else:
            self.std_base = class_object['std_base']
        self.base_class = class_object['baseClass']
        self.has_std_base = class_object['has_std_base']
        self.child_base_class = ''
        if 'child_base_class' in class_object:
            self.child_base_class = class_object['child_base_class']
        self.concretes = []
        if 'concretes' in class_object:
            self.concretes = class_object['concretes']
        self.has_array = class_object['has_array']

        self.child_lo_elements = class_object['child_lo_elements']
        self.child_elements = class_object['child_elements']
        self.num_non_std_children = class_object['num_non_std_children']
        self.num_children = class_object['num_children']
        self.has_list_of = class_object['hasListOf']
        self.has_multiple_versions = False
        self.version_attributes = []
        if 'num_versions' in class_object and class_object['num_versions'] > 1:
            self.has_multiple_versions = True
            for i in range(0, class_object['num_versions']):
                self.version_attributes.append(
                    query.get_version_attributes(self.all_attributes, i))
        self.is_header = class_object['is_header']

        self.document = False
        if 'document' in class_object:
            self.document = class_object['document']

        self.lv_info = lv_info

        # useful variables
        if not self.is_cpp_api and self.is_list_of:
            self.struct_name = self.object_child_name
        else:
            self.struct_name = self.object_name
        self.plural = strFunctions.plural(self.child_name)
        self.lo_name = ''
        if 'lo_class_name' in class_object and class_object['lo_class_name'] != '':
            self.lo_name = class_object['lo_class_name'][6:]
        self.indef_name = strFunctions.get_indefinite(self.object_child_name)
        self.abbrev_parent = strFunctions.abbrev_name(self.object_name)
        self.abbrev_child = strFunctions.abbrev_name(self.child_name)
        if self.is_cpp_api is False:
            self.true = '@c 1'
            self.false = '@c 0'
        else:
            self.true = '@c true'
            self.false = '@c false'

        if global_variables.is_package:
            self.error = 'logPackageError(\"{0}\", ' \
                         ''.format(self.package.lower())
            self.error_args = 'getPackageVersion(), getLevel(), getVersion()'
            self.given_args = 'pkgVersion, level, version'
        else:
            self.error = 'logError('
            self.error_args = 'getLevel(), getVersion()'
            self.given_args = 'level, version'

    ########################################################################

    # Functions for writing createObject

    # function to write create_object
    def write_create_object(self):
        num_children = self.num_children - self.num_non_std_children
        # if not list of only write if has children other than node based
        if self.has_std_base:
            if not self.is_list_of and num_children == 0:
                return

        # create comment parts
        if self.is_list_of:
            title_line = 'Creates a new {0} in this ' \
                         '{1}'.format(self.object_child_name, self.object_name)
        else:
            title_line = 'Creates a new object from the next XMLToken ' \
                         'on the XMLInputStream'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'createObject'
        return_type = '{0}*'.format(self.std_base)
        if global_variables.is_package:
            arguments = ['XMLInputStream& stream']
            xmlns = 'XMLNamespaces'
        else:
            arguments = ['LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream']
            xmlns = 'LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces'

        # create the function implementation
        code = []
        if not self.is_header:
            ns = '{0}ns'.format(self.package.lower())
            upkg = self.package.upper()

            if self.is_list_of:
                if num_children == 0:
                    code = self.write_create_object_lo(upkg, ns)
                else:
                    code = self.write_create_object_anomalous_lo(upkg, ns)
            else:
                code = self.write_create_object_element(num_children, upkg, ns, xmlns)
                if global_variables.is_package and len(self.child_elements) != self.num_non_std_children:
                    code.append(self.create_code_block('line',
                                                       ['delete '
                                                        '{0}'.format(ns)]))
                    [other_packages, list_other_packages] = query.has_other_packages(self.child_elements)
                    for package in list_other_packages:
                        code.append(self.create_code_block('line',
                                                           ['delete '
                                                            '{0}'.format(package + 'ns')]))
                code.append(self.create_code_block('line',
                                                   ['connectToChild()']))
                code.append(self.create_code_block('line', ['return obj']))
      # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    def write_create_object_element(self, num_children, upkg, ns, xmlns):
        base_create = 'NULL'
        if not self.has_std_base:
            base_create = '{0}::createObject' \
                          '(stream)'.format(self.base_class)
        code = [self.create_code_block('line',
                                       ['{0}* obj = {1}'.format(self.std_base, base_create)])]
        self.add_ns_code(num_children, upkg, ns, xmlns, code)
        if self.is_plugin:
            class_name = strFunctions.get_class_from_plugin(
                self.class_name, self.package)
        else:
            class_name = self.class_name
        # sort error names to be used
        name_in_error = class_name
        if not self.document:
            name_in_error = strFunctions.remove_prefix(class_name)
        # hack forr render relAbsVector
        error = '{0}{1}AllowedElements'.format(self.package, name_in_error)
        error_hack = '{0}{1}AllowedAttributes'.format(self.package, name_in_error)
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}Unknown'.format(self.package)
        error_line = 'getErrorLog()->{0}{1}, ' \
                     '{2})'.format(self.error, error, self.error_args)
        error_line_hack = 'getErrorLog()->{0}{1}, {2})'.format(self.error, error_hack, self.error_args)
        if num_children == 0:
            # do nothing we are calling a base class
            implementation = []
        else:
            implementation = []
            i = 0
            children_dealt_with = 0
            else_if = False
            for i in range(0, len(self.child_elements)):
                code_added = False
                element = self.child_elements[i]
                if 'is_ml' in element and element['is_ml']:
                    continue
                if element['attTypeCode'] == 'RelAbsVector*':
                    code_added = self.get_element_implementation(element, implementation, code, ns, error_line_hack)
                else:
                    code_added = self.get_element_implementation(element, implementation, code, ns, error_line)
                children_dealt_with += 1
                if not code_added:
                    if i < num_children - 1:
                        implementation.append('else if')
                        else_if = True
                else:
                    implementation = []
            for j in range(i, i + len(self.child_lo_elements)):
                code_added = False
                element = self.child_lo_elements[j-i]
                if self.is_plugin:
                    implementation += \
                        self.get_plugin_lo_block(element, error_line)
                else:
                    if element['attTypeCode'] == 'RelAbsVector*':
                        code_added = self.get_element_implementation(element, implementation, code, ns, error_line_hack)
                    else:
                        code_added = self.get_element_implementation(element, implementation, code, ns, error_line)
                if not code_added:
                    if j < num_children - children_dealt_with - 1:
                        implementation.append('else if')
                        else_if = True
                else:
                    implementation = []
            if not self.is_plugin:
                if num_children == 1:
                    if not code_added:
                        code.append(self.create_code_block('if',
                                                           implementation))
                else:
                    if not code_added:
                        if else_if:
                            code.append(self.create_code_block('else_if',
                                                               implementation))
                        else:
                            code.append(self.create_code_block('if',
                                                               implementation))
            else:
                if num_children == 1:
                    plugin_imp = self.create_code_block('if',
                                                        implementation)
                else:
                    plugin_imp = self.create_code_block('else_if',
                                                        implementation)
                code.append(self.create_code_block('if',
                                                   ['prefix == '
                                                    'targetPrefix',
                                                    plugin_imp]))
        return code

    def get_element_implementation(self, element, implementation, code, ns, error_line):
        code_added = False
        if element['abstract'] and \
                not (element['attType'] == 'lo_element'):
            this_implement = self.get_abstract_block(element, ns, error_line)
            no_lines = len(implementation)
            if no_lines > 0:
                this_implement.append('else if')
                for i in range(0, no_lines-1):
                    this_implement.append(implementation[i])
            code.append(self.create_code_block('else_if',
                                               this_implement))
            code_added = True
        elif element['type'] == 'inline_lo_element':
            my_implement = ['obj = {0}.createObject(stream'
                              ')'.format(element['memberName'])]
            no_lines = len(implementation)
            this_implement = []
            if no_lines > 0:
                for i in range(0, no_lines-1):
                    this_implement.append(implementation[i])
                this_implement.append('else')
                this_implement.append('obj = {0}.createObject(stream'
                              ')'.format(element['memberName']))
                code.append(self.create_code_block('if_else',
                                                   this_implement))
            else:
                code.append(self.create_code_block('line', my_implement))
            code_added = True
        elif element['attType'] == 'lo_element':
            implementation += self.get_lo_block(element, error_line)
        else:
            overwrite = element['children_overwrite']
            name = element['memberName']
            loname = element['xml_name'] if overwrite \
                else strFunctions.lower_first(strFunctions.remove_prefix(element['element']))
            this_ns = ns
            if 'other_package' in element and element['other_package'] != '':
                this_ns = '{0}ns'.format(element['other_package'])
            implementation += self.get_obj_block(name, loname,
                                                 error_line,
                                                 overwrite,
                                                 element['element'],
                                                 this_ns)
        return code_added

    def add_ns_code(self, num_children, upkg, ns, xmlns, code):
        if self.is_plugin:
            lines = ['const std::string& name = '
                     'stream.peek().getName()',
                     'const {0}& xmlns = '
                     'stream.peek().getNamespaces()'.format(xmlns),
                     'const std::string& prefix '
                     '= stream.peek().getPrefix()']
        else:
            lines = ['const std::string& name '
                     '= stream.peek().getName()']
        if num_children > 0:
            code.append(self.create_code_block('line', lines))
        if self.is_plugin:
            line = ['const std::string& targetPrefix = (xmlns.hasURI'
                    '(mURI)) ? xmlns.getPrefix(mURI) : mPrefix']
            code.append(self.create_code_block('line', line))
        if global_variables.is_package and len(self.child_elements) != self.num_non_std_children:
            line = ['{0}_CREATE_NS({1}, '
                    'get{2}Namespaces'
                    '())'.format(upkg, ns, global_variables.prefix)]
            code.append(self.create_code_block('line', line))
            [other_packages, list_other_packages] = query.has_other_packages(self.child_elements)
            for package in list_other_packages:
                line = ['{0}_CREATE_NS({1}, '
                        'get{2}Namespaces'
                        '())'.format(package.upper(), package + 'ns', global_variables.prefix)]
                code.append(self.create_code_block('line', line))


    def write_create_object_lo(self, upkg, ns):
        if global_variables.is_package:
            implementation = ['const std::string& name = '
                              'stream.peek().getName()',
                              '{0}* object = NULL'.format(self.std_base),
                              '{0}_CREATE_NS({1}, '
                              'get{2}Namespaces'
                              '())'.format(upkg, ns, global_variables.prefix)]
        else:
            implementation = ['const std::string& name = '
                              'stream.peek().getName()',
                              '{0}* object = NULL'.format(self.std_base)]
        code = [dict({'code_type': 'line', 'code': implementation})]
        implementation = self.write_create_object_class(self.child_name,
                                                        ns)
        code.append(self.create_code_block('if', implementation))
        for i in range(0, len(self.concretes)):
            implementation = \
                self.write_create_object_class(
                    self.concretes[i]['element'], ns)
            code.append(self.create_code_block('if', implementation))
        if global_variables.is_package:
            code.append(self.create_code_block('line',
                                               ['delete {0}'.format(ns),
                                                'return object']))
        else:
            code.append(self.create_code_block('line',
                                               ['return object']))
        return code

    def write_create_object_anomalous_lo(self, upkg, ns):
        # the unusual case where a list of have a child element
        # is not of the same type as the list of
        if global_variables.is_package:
            implementation = ['const std::string& name = '
                              'stream.peek().getName()',
                              '{0}* object = NULL'.format(self.std_base),
                              '{0}_CREATE_NS({1}, '
                              'get{2}Namespaces'
                              '())'.format(upkg, ns, global_variables.prefix)]
        else:
            implementation = ['const std::string& name = '
                              'stream.peek().getName()',
                              '{0}* object = NULL'.format(self.std_base)]

        code = [dict({'code_type': 'line', 'code': implementation})]
        implementation = self.write_create_object_class(self.child_name,
                                                        ns)
        code.append(self.create_code_block('if', implementation))
        for i in range(0, len(self.child_elements)):
            implementation = \
                self.write_create_object_class(
                    self.child_elements[i]['element'], ns, True)
            code.append(self.create_code_block('if', implementation))
        if global_variables.is_package:
            code.append(self.create_code_block('line',
                                               ['delete {0}'.format(ns),
                                                'return object']))
        else:
            code.append(self.create_code_block('line',
                                               ['return object']))

        return code

    @staticmethod
    def write_create_object_class(name, ns, create=False):
        if global_variables.is_package:
            use_ns = ns
        else:
            use_ns = 'get{0}Namespaces()'.format(global_variables.prefix)
        xmlname = strFunctions.lower_first(name)
        if not global_variables.is_package:
            temp = strFunctions.remove_prefix(name)
            xmlname = strFunctions.lower_first(temp)

        if not create:
            implementation = ['name == '
                              '\"{0}\"'.format(xmlname),
                              'object = new {0}({1})'.format(name, use_ns),
                              'appendAndOwn(object)']
        else:
            abbrev = strFunctions.abbrev_name(name)
            implementation = ['name == '
                              '\"{0}\"'.format(xmlname),
                              '{0} new{1}({2})'.format(name, abbrev.upper(),
                                                       use_ns),
                              'set{0}(&new{1})'.format(name, abbrev.upper()),
                              'object = get{0}()'.format(name)]
        return implementation

    def get_lo_block(self, element, error_line):
        name = element['memberName']
        loname = strFunctions.lower_first(
            strFunctions.remove_prefix(element['attTypeCode']))
        nested_if = self.create_code_block('if',
                                           ['{0}.size() '
                                            '!= 0'.format(name),
                                            error_line])
        line = 'obj = &{0}'.format(name)
        implementation = ['name == \"{0}\"'.format(loname),
                          nested_if, line]
        return implementation

    def get_plugin_lo_block(self, element, error_line):
        name = element['memberName']
        implementation = self.get_lo_block(element, error_line)
        lines = ['targetPrefix.empty()',
                 '{0}.get{1}()->enableDefaultNS(mURI, '
                 'true)'.format(name, global_variables.document_class)]
        second_if = self.create_code_block('if', lines)
        implementation.append(second_if)
        return implementation

    def get_abstract_block(self, element, ns, error_line):
        name = element['memberName']
        concretes = query.get_concretes(element['root'], element['concrete'])
        num_concs = len(concretes)
        implementation = self.get_concrete_block(concretes[0], name, ns, error_line, element['capAttName'])
        for i in range(1, num_concs):
            implementation.append('else if')
            implementation += self.get_concrete_block(concretes[i], name, ns, error_line, element['capAttName'])
        return implementation

    def get_concrete_block(self, element, name, ns, error_line, membername):
        implementation = self.get_obj_block(name, element['name'], error_line, False, element['element'], ns, membername)
        return implementation

    def get_obj_block(self, name, xmlname, error_line, over_write, element, ns, concrete_name=''):
        implementation = []
        used_ns = ns
        if not global_variables.is_package:
            used_ns = 'get{0}Namespaces()'.format(global_variables.prefix)
        if len(concrete_name) > 0:
            name_to_use = concrete_name
        else:
            name_to_use = element
            elem_name = element
            if name_to_use.startswith(strFunctions.upper_first(self.package)):
                 elem_name = strFunctions.remove_prefix(element, False, True, self.package)
            elif element.lower() != xmlname.lower():
                [elem_name, unused] = strFunctions.remove_hyphens(xmlname)
            name_to_use = strFunctions.upper_first(elem_name)
        nested_if = self.create_code_block('if',
                                           ['isSet{0}()'.format(name_to_use),
                                            error_line])
        implementation.append('name == \"{0}\"'.format(xmlname))
        implementation.append(nested_if)
        implementation.append('delete {0}'.format(name))
        implementation.append('{0} = new {1}'
                              '({2})'.format(name,
                                             element, used_ns))
        if over_write:
            implementation.append('{0}->setElementName'
                                  '(name)'.format(name))
        implementation.append('obj = {0}'.format(name))
        return implementation

    ########################################################################

    # Functions for attributes/elements

    # function to write addExpectedAttributes
    def write_add_expected_attributes(self):
        if self.has_std_base and len(self.attributes) == 0:
            return
        # create comment parts
        title_line = 'Adds the expected attributes for this element'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'addExpectedAttributes'
        return_type = 'void'
        if global_variables.is_package:
            arguments = ['ExpectedAttributes& attributes']
        else:
            arguments = ['LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes& attributes']

        # create the function implementation
        if self.base_class:
            implementation = ['{0}::addExpectedAttributes'
                              '(attributes)'.format(self.base_class)]
            code = [dict({'code_type': 'line', 'code': implementation})]
        else:
            code = []
        if not self.has_multiple_versions:
            for i in range(0, len(self.attributes)):
                if self.attributes[i]['isArray']:
                    continue
                name = self.attributes[i]['xml_name']
                implementation = ['attributes.add(\"{0}\")'.format(name)]
                code.append(dict({'code_type': 'line', 'code': implementation}))
        else:
            code.append(self.create_code_block('line',
                                               ['unsigned int level = getLevel()',
                                                'unsigned int coreVersion = getVersion()',
                                                'unsigned int pkgVersion = getPackageVersion()']))
            for i in range(0, len(self.lv_info)):
                level_val = self.lv_info[i]['core_level']
                version = self.lv_info[i]['core_version']
                pkg_version = self.lv_info[i]['pkg_version']

                implementation = ['level == {0} && coreVersion == {1} && pkgVersion == {2}'.format(level_val, version, pkg_version)]
                for j in range(0, len(self.version_attributes[i])):
                    if self.version_attributes[i][j]['isArray']:
                        continue
                    name = self.version_attributes[i][j]['name']
                    # in l3v2 id and name are on SBase
                    if version < 2:
                        implementation.append('attributes.add(\"{0}\")'.format(name))
                    else:
                        if name != 'id' and name != 'name':
                            implementation.append('attributes.add(\"{0}\")'.format(name))
                code.append(self.create_code_block('if', implementation))
        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write readAttributes
    def write_read_attributes(self):
        if self.has_std_base and len(self.attributes) == 0:
            return

        # create comment
        title_line = 'Reads the expected attributes into the member ' \
                     'data variables'
        params = []
        return_lines = []
        additional = []

        # create function declaration
        function = 'readAttributes'
        return_type = 'void'
        if global_variables.is_package:
            arguments = ['const XMLAttributes& attributes',
                         'const ExpectedAttributes& expectedAttributes']
        else:
            arguments = ['const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes& attributes',
                         'const LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes& expectedAttributes']

        # create the function implementation
        implementation = ['unsigned int level = getLevel()',
                          'unsigned int version = getVersion()']
        if global_variables.is_package:
            implementation += ['unsigned int pkgVersion = getPackageVersion()']
        implementation += ['unsigned int numErrs',
                           'bool assigned = false',
                           '{0}ErrorLog* log = '
                           'getErrorLog()'.format(global_variables.prefix)]
        code = [dict({'code_type': 'line', 'code': implementation})]
        # only do this if has a list of
        if not self.is_list_of and self.has_list_of:
            line = self.get_error_from_list_of_read()
            code.append(self.create_code_block('if', line))

        if self.base_class:
            line = ['{0}::readAttributes(attributes, '
                    'expectedAttributes)'.format(self.base_class),
                    ]
            code.append(self.create_code_block('line', line))

            ifblock = ['log']
            line = ['numErrs = log->getNumErrors()']
            ifblock.append(self.create_code_block('line', line))
            line = self.get_error_from_base_class()
            ifblock.append(self.create_code_block('for', line))
            code.append(self.create_code_block('if', ifblock))

        if not self.has_multiple_versions:
            for i in range(0, len(self.attributes)):
                self.write_read_att(self.attributes, i, code)
        else:
            for i in range(0, len(self.lv_info)):
                level_val = self.lv_info[i]['core_level']
                version = self.lv_info[i]['core_version']
                pkg_version = self.lv_info[i]['pkg_version']

                implementation = ['level == {0} && version == {1} && pkgVersion == {2}'.format(level_val, version, pkg_version),
                                  'readL{0}V{1}V{2}Attributes(attributes)'.format(level_val, version, pkg_version)]
                code.append(self.create_code_block('if', implementation))

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write individual version reads
    def write_read_version_attributes(self, version):
        if not self.has_multiple_versions:
            return
        elif self.has_std_base and len(self.attributes) == 0:
            return

        # create comment
        title_line = 'Reads the expected attributes into the member ' \
                     'data variables'
        params = []
        return_lines = []
        additional = []

        # create function declaration
        level_val = self.lv_info[version]['core_level']
        version_val = self.lv_info[version]['core_version']
        pkg_version = self.lv_info[version]['pkg_version']
        is_l3v1 = False
        if (level_val == 3 and version_val == 1):
            is_l3v1 = True
        function = 'readL{0}V{1}V{2}Attributes'.format(level_val, version_val, pkg_version)
        return_type = 'void'
        if global_variables.is_package:
            arguments = ['const XMLAttributes& attributes']
        else:
            arguments = ['const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes& attributes']

        # create the function implementation
        implementation = ['unsigned int level = getLevel()',
                          'unsigned int version = getVersion()',
                          'bool assigned = false',
                          'unsigned int pkgVersion = getPackageVersion()',
                          'SBMLErrorLog* log = getErrorLog()']
        need_num_errs = False
        for i in range(0, len(self.version_attributes[version])):
            att_type = self.version_attributes[version][i]['type']
            if att_type == 'bool' or att_type == 'int' or att_type == 'uint' or att_type == 'double':
                need_num_errs = True
                break
        if need_num_errs:
            implementation.append('unsigned int numErrs')
        code = [dict({'code_type': 'line', 'code': implementation})]

        for i in range(0, len(self.version_attributes[version])):
            self.write_read_att(self.version_attributes[version], i, code, is_l3v1)

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write read other xml
    def write_read_other_xml(self):
        # only needed for cpp list of class
        has_vector = query.has_vector(self.attributes)
        if not has_vector:
            if self.is_list_of or self.num_non_std_children == 0:
                return
        else:
            for attrib in self.attributes:
                if attrib['isVector']:
                    vector_attribute = attrib
        # create comment
        title_line = 'Reads other XML such as math/notes etc.'
        params = []
        return_lines = []
        additional = []

        # create function declaration
        function = 'readOtherXML'
        return_type = 'bool'
        if global_variables.is_package:
            arguments = ['XMLInputStream& stream']
        else:
            arguments = ['LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream']

        # create the function implementation
        if has_vector:
            implementation = ['bool read = false']
        else:
            implementation = ['bool read = false',
                              'const string& name = stream.peek().getName()']
        code = [dict({'code_type': 'line', 'code': implementation})]

        if has_vector:
            for i in range(0,len(self.attributes)):
                attrib = self.attributes[i]
                if attrib['isVector']:
                    vector_attribute = attrib
                else:
                    continue;
                implementation = ['!text.fail()', '{0}.push_back(value)'.format(vector_attribute['memberName'])]
                if_block = self.create_code_block('if', implementation)
                implementation = ['stream.isGood() && stream.peek().isText()',
                                  'text << stream.next().getCharacters()']
                nested_while = self.create_code_block('while', implementation)
                implementation = ['stream.peek().getName() == \"{0}\"'
                                  ''.format(vector_attribute['name']),
                                  'stream.next()', 'stringstream text',
                                  nested_while, '{0} value'.format(vector_attribute['element']), 'text >> value',
                                  if_block, 'stream.next()', 'read = true']
                code.append(self.create_code_block('while', implementation))
                if len(self.child_elements) > 0:
                    implementation = ['const string& name = stream.peek().getName()']
                    code.append(self.create_code_block('line', implementation))


        # math is unique - assume others are XMLNode based
        if global_variables.is_package:
            token = 'XMLToken'
            node = 'XMLNode'
        else:
            token = 'LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken'
            node = 'LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode'
        for i in range(0, len(self.child_elements)):
            element = self.child_elements[i]
            if element['element'] == 'ASTNode':
                nested_if = []
                line = ['stream.get{0}Namespaces() == '
                        'NULL'.format(global_variables.prefix),
                        'stream.set{0}Namespaces(new '
                        '{0}Namespaces(getLevel(), '
                        'getVersion()))'.format(global_variables.prefix)]
                if global_variables.is_package:
                    nested_if = self.create_code_block('if', line)
                implementation = ['name == \"math\"',
                                  'const {0} elem = stream.peek()'.format(token),
                                  'const std::string prefix = '
                                  'checkMathMLNamespace(elem)']
                if len(nested_if) > 0:
                    implementation.append(nested_if)
                implementation.append('delete mMath')
                implementation.append('mMath = readMathML(stream, prefix)')
                implementation.append('read = true')
                code.append(self.create_code_block('if', implementation))
            elif 'is_ml' in element and element['is_ml']:
                member = element['memberName']
                name = element['capAttName'] if element['name'] == 'uncertML' \
                    else element['name']
                line = ['name == \"{0}\"'.format(name),
                        'const {0}& token = stream.next()'.format(token),
                        'stream.skipText()',
                        'delete {0}'.format(member),
                        '{0}* xml = new {0}(stream)'.format(node)]
                if element['element'] == 'XMLNode':
                    line.append('{0} = new {1}(*(static_cast<{2}*>(xml)))'.format(member, node, token))
                else:
                    line.append('{0} = new {1}(xml)'.format(member, element['element']))
                line.append('stream.skipPastEnd(token)')
                line.append('delete xml')
                line.append('read = true')
                code.append(self.create_code_block('if', line))
        line = ['{0}::readOtherXML(stream)'.format(self.base_class),
                'read = true']
        code.append(self.create_code_block('if', line))
        code.append(self.create_code_block('line', ['return read']))

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write writeAttributes
    def write_write_attributes(self):
        if self.has_std_base and len(self.attributes) == 0:
            return

        # create comment
        title_line = 'Writes the attributes to the stream'
        params = []
        return_lines = []
        additional = []

        # create function declaration
        function = 'writeAttributes'
        return_type = 'void'
        if global_variables.is_package:
            arguments = ['XMLOutputStream& stream']
        else:
            arguments = ['LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream']

        # create the function implementation
        if self.base_class:
            implementation = ['{0}::writeAttributes'
                              '(stream)'.format(self.base_class)]
            code = [dict({'code_type': 'line', 'code': implementation})]
        else:
            code = []

        if not self.has_multiple_versions:
            for i in range(0, len(self.attributes)):
                self.write_write_att(self.attributes, i, code)
        else:
            implementation = ['unsigned int level = getLevel()',
                              'unsigned int version = getVersion()']
            if global_variables.is_package:
                implementation += ['unsigned int pkgVersion = getPackageVersion()']
            code.append(self.create_code_block('line', implementation))
            for i in range(0, len(self.lv_info)):
                level_val = self.lv_info[i]['core_level']
                version = self.lv_info[i]['core_version']
                pkg_version = self.lv_info[i]['pkg_version']

                implementation = ['level == {0} && version == {1} && pkgVersion == {2}'.format(level_val, version, pkg_version),
                                  'writeL{0}V{1}V{2}Attributes(stream)'.format(level_val, version, pkg_version)]
                code.append(self.create_code_block('if', implementation))


        if global_variables.is_package and not self.is_plugin and \
                self.base_class:
            code.append(self.create_code_block('line',
                                               ['{0}::write'
                                                'ExtensionAttributes(stream'
                                                ')'.format(self.std_base)]))

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    # function to write individual version writeAttributes
    def write_write_version_attributes(self, version):
        if not self.has_multiple_versions:
            return
        elif self.has_std_base and len(self.attributes) == 0:
            return

        # create comment
        title_line = 'Writes the attributes to the stream'
        params = []
        return_lines = []
        additional = []

        # create function declaration
        level_val = self.lv_info[version]['core_level']
        version_val = self.lv_info[version]['core_version']
        pkg_version = self.lv_info[version]['pkg_version']
        function = 'writeL{0}V{1}V{2}Attributes'.format(level_val, version_val, pkg_version)
        return_type = 'void'
        if global_variables.is_package:
            arguments = ['XMLOutputStream& stream']
        else:
            arguments = ['LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream']

        # create the function implementation
        code = []
        for i in range(0, len(self.version_attributes[version])):
            # if we are l3v2 id and name are written by sbase
            if version_val < 2:
                self.write_write_att(self.version_attributes[version], i, code)
            else:
                att_name = self.version_attributes[version][i]['xml_name']
                if att_name != 'id' and att_name != 'name':
                    self.write_write_att(self.version_attributes[version], i, code)

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing namespaces

    # function to write writeXMLNS
    def write_write_xmlns(self):
        if not self.is_list_of:
            if not self.document:
                return

        # create comment parts
        title_line = 'Writes the namespace for the {0} package'\
            .format(self.package)
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'writeXMLNS'
        return_type = 'void'
        if global_variables.is_package:
            arguments = ['XMLOutputStream& stream']
            xmlns = 'XMLNamespaces'
        else:
            arguments = ['LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream']
            xmlns = 'LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces'

        # create the function implementation
        implementation = ['{0} xmlns'.format(xmlns),
                          'std::string prefix = getPrefix()']
        code = [dict({'code_type': 'line', 'code': implementation})]
        if global_variables.is_package:
            implementation = ['thisxmlns && thisxmlns->hasURI({0}Extension::'
                              'getXmlnsL{1}V{2}V{3}())'.format(self.package, self.lv_info[0]['core_level'], self.lv_info[0]['core_version'], self.lv_info[0]['pkg_version']),
                              'xmlns.add({0}Extension::getXmlnsL{1}V{2}V{3}(), '
                              'prefix)'.format(self.package, self.lv_info[0]['core_level'], self.lv_info[0]['core_version'], self.lv_info[0]['pkg_version'])]
        else:
            implementation = ['thisxmlns && thisxmlns->hasURI({0}_XMLNS_L1V1)'.format(global_variables.language.upper()),
                              'xmlns.add({0}_XMLNS_L1V1, '
                              'prefix)'.format(global_variables.language.upper())]

        nested_if = self.create_code_block('if', implementation)
        implementation = ['prefix.empty()',
                          'const {0}* thisxmlns = getNamespaces()'.format(xmlns),
                          nested_if]
        code.append(self.create_code_block('if', implementation))
        code.append(self.create_code_block('line', ['stream << xmlns']))

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing arrays

    # function to write write_test
    def write_set_element_text(self):
        if not self.has_array:
            return
        elif not self.is_cpp_api:
            return

        # create comment parts
        title_line = 'Writes the array data as a text element'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'setElementText'
        return_type = 'void'
        arguments = ['const std::string& text']

        # find the array attribute
        name = ''
        array_type = ''
        for attrib in self.attributes:
            if attrib['isArray']:
                name = attrib['capAttName']
                array_type = attrib['element']
        # create the function implementation
        implementation = ['stringstream strStream(text)',
                          '{0} val'.format(array_type),
                          'vector<{0}> valuesVector'.format(array_type)]
        code = [self.create_code_block('line', implementation),
                self.create_code_block('while',
                                       ['strStream >> val',
                                        'valuesVector.push_back(val)']),
                self.create_code_block('line',
                                       ['unsigned int length = (unsigned '
                                        'int)valuesVector.size()'])]
        for_loop = self.create_code_block('for',
                                          ['unsigned int i = 0; '
                                           'i < length; ++i',
                                           'data[i] = valuesVector.at(i)'])
        code.append(self.create_code_block('if',
                                           ['length > 0',
                                            '{0}* data = new {0}'
                                            '[length]'.format(array_type),
                                            for_loop,
                                            'set{0}(data, length)'.format(name),
                                            'delete[] data']))

        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    ########################################################################

    # Functions for writing isValidTypeForList

    def write_is_valid_type_for_list(self):
        if not self.is_list_of:
            return
        elif len(self.concretes) == 0:
            return

        # create comment parts
        title_line = 'checks concrete types'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'isValidTypeForList'
        return_type = 'bool'
        arguments = ['{0}* item'.format(self.child_base_class)]

        # create the function implementation
        implementation = ['unsigned int tc = item->getTypeCode()']
        code = [dict({'code_type': 'line', 'code': implementation})]
        tc = self.concretes[0]['typecode']
        implementation = 'return ((tc == {0})'.format(tc)
        for i in range(1, len(self.concretes)):
            tc = self.concretes[i]['typecode']
            implementation += ' || (tc == {0})'.format(tc)
        implementation += ')'
        code.append(self.create_code_block('line', [implementation]))
        # return the parts
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.struct_name,
                     'implementation': code})

    #####################################################################

    # HELPER FUNCTIONS

    def get_error_from_list_of_read(self):
        name_in_error = strFunctions.remove_prefix(self.class_name)
        if self.lo_name == '':
            plural = strFunctions.plural(name_in_error)
        else:
            plural = self.lo_name
        c_err = '{0}{1}LO{2}AllowedCoreAttributes'.format(self.package,
                                                          self.parent_class,
                                                          plural)
        error = '{0}{1}LO{2}AllowedAttributes'.format(self.package,
                                                      self.parent_class,
                                                      plural)
        unknown_error ='UnknownCoreAttribute'
        if not global_variables.is_package:
            unknown_error = '{0}UnknownCoreAttribute' \
                            ''.format(global_variables.prefix)
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}{1}AllowedAttributes'.format(self.package,
                                                         name_in_error)
                if error not in global_variables.error_list:
                    error = '{0}Unknown'.format(self.package)
            if c_err not in global_variables.error_list:
                c_err = '{0}Unknown'.format(self.package)
        if global_variables.is_package:
            line = ['log->getError(n)->getErrorId() == UnknownPackageAttribute',
                    'const std::string details = log->getError(n)->getMessage()',
                    'log->remove(UnknownPackageAttribute)',
                    'log->{0}{1}, {2}, details)'.format(self.error, error,
                                                        self.given_args),
                    'else if', 'log->getError(n)->getErrorId() == '
                               'UnknownCoreAttribute',
                    'const std::string details = log->getError(n)->getMessage()',
                    'log->remove(UnknownCoreAttribute)',
                    'log->{0}{1}, {2}, details)'.format(self.error, c_err,
                                                        self.given_args,
                                                        )]
            if_err = self.create_code_block('else_if', line)
        else:
            line = ['log->getError(n)->getErrorId() == {0}'.format(unknown_error),
                    'const std::string details = log->getError(n)->getMessage()',
                    'log->remove({0})'.format(unknown_error),
                    'log->{0}{1}, {2}, details)'.format(self.error, c_err,
                                                        self.given_args)]
            if_err = self.create_code_block('if', line)

        line = ['int n = numErrs-1; n >= 0; n--', if_err]
        for_loop = self.create_code_block('for', line)

        if global_variables.is_package:
            if self.lo_name == '':
                use_name = strFunctions.cap_list_of_name(self.class_name)
            else:
                use_name = strFunctions.cap_list_of_name(self.lo_name)
            line = ['log && getParent{1}Object() && static_cast<{0}*>(getParent{1}Object())->size() '
                    '< 2'.format(use_name,
                                 self.cap_language),
                    'numErrs = log->getNumErrors()', for_loop]
        else:
            line = ['log && getParent{1}Object() && static_cast<{0}*>(getParent{1}Object())->size() '
                    '< 2'.format(strFunctions.cap_list_of_name(self.class_name),
                                 global_variables.prefix),
                    'numErrs = log->getNumErrors()', for_loop]

        return line

    def get_error_from_base_class(self):
        if self.is_plugin:
            class_name = strFunctions.get_class_from_plugin(
                self.class_name, self.package)
            core_err = '{0}{1}AllowedAttributes'.format(self.package,
                                                        class_name)
        else:
            if self.is_list_of:
                class_name = '{0}LO{1}'.format(self.parent_class,
                                               self.class_name[6:])
            else:
                class_name = self.class_name
            core_err = '{0}{1}AllowedCoreAttributes'.format(self.package,
                                                            class_name)
        error = '{0}{1}AllowedAttributes'.format(self.package, class_name)
        unknown_error ='UnknownCoreAttribute'
        if not global_variables.is_package:
            unknown_error = '{0}UnknownCoreAttribute' \
                            ''.format(global_variables.prefix)
        if not global_variables.running_tests:
            if global_variables.is_package:
                if core_err not in global_variables.error_list:
                    core_err = '{0}Unknown'.format(self.package)
                if error not in global_variables.error_list:
                    error = '{0}Unknown'.format(self.package)
            else:
                if core_err not in global_variables.error_list:
                    core_err = '{0}Unknown'.format(global_variables.prefix)
                if error not in global_variables.error_list:
                    error = '{0}Unknown'.format(global_variables.prefix)

        if global_variables.is_package:
            line = ['log->getError(n)->getErrorId() == UnknownPackageAttribute',
                    'const std::string details = log->getError(n)->getMessage()',
                    'log->remove(UnknownPackageAttribute)',
                    'log->{0}{1}, {2}, details)'.format(self.error, error,
                                                        self.given_args),
                    'else if', 'log->getError(n)->getErrorId() == '
                               'UnknownCoreAttribute',
                    'const std::string details = log->getError(n)->getMessage()',
                    'log->remove(UnknownCoreAttribute)',
                    'log->{0}{1}, {2}, details)'.format(self.error, core_err,
                                                        self.given_args)]
            if self.is_plugin:
                line += ['else if', 'log->getError(n)->getErrorId() == '
                            'NotSchemaConformant',
                    'const std::string details = log->getError(n)->getMessage()',
                    'log->remove(NotSchemaConformant)',
                    'log->{0}{1}, {2}, details)'.format(self.error, error,
                                                        self.given_args)]
            if_err = self.create_code_block('else_if', line)
        else:
            line = ['log->getError(n)->getErrorId() == {0}'.format(unknown_error),
                    'const std::string details = log->getError(n)->getMessage()',
                    'log->remove({0})'.format(unknown_error),
                    'log->{0}{1}, {2}, details)'.format(self.error, error,
                                                        self.given_args)]
            if_err = self.create_code_block('if', line)


        line = ['int n = numErrs-1; n >= 0; n--', if_err]
        return line

    def write_write_att(self, attributes, index, code):
        if attributes[index]['isArray']:
            return
        elif attributes[index]['isVector']:
            return
        name = attributes[index]['xml_name']
        cap_name = attributes[index]['capAttName']
        member = attributes[index]['memberName']
        att_type = attributes[index]['attType']
        if att_type == 'enum':
            element = attributes[index]['element']
            variable = '{0}_toString({1})'.format(element, member)
        else:
            variable = member
        line = ['isSet{0}() == true'.format(cap_name),
                'stream.writeAttribute(\"{0}\", getPrefix(), '
                '{1})'.format(name, variable)]
        code.append(self.create_code_block('if', line))

    def write_read_att(self, attributes, index, code, is_l3v1=False):
        attribute = attributes[index]
        if attribute['isArray']:
            return
        if attribute['isVector']:
            return
        name = attribute['xml_name']
        att_type = attribute['type']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'

        implementation = ['', '{0} {1} (use = \"{2}\"'
                              ' )'.format(name, att_type, status),
                          '']
        code.append(self.create_code_block('comment', implementation))

        if att_type == 'SId' or att_type == 'UnitSId' or att_type == 'ID':
            self.write_sid_read(index, code, attributes, is_l3v1)
        elif att_type == 'SIdRef' or att_type == 'UnitSIdRef' or att_type == 'IDREF':
            self.write_sidref_read(index, code, attributes)
        elif att_type == 'enum':
            self.write_enum_read(index, code, attributes)
        elif att_type == 'string' or att_type == 'IDREF':
            self.write_string_read(index, code, attributes, is_l3v1)
        elif att_type == 'int' or att_type == 'uint' or att_type == 'double':
            self.write_number_read(index, code, att_type, attributes)
        elif att_type == 'bool':
            self.write_bool_read(index, code, attributes)
        else:
            line = ['assigned = attributes.readInto(\"{0}\", '
                    '{1})'.format(name, member)]
            code.append(self.create_code_block('line', line))

    def write_bool_read(self, index, code, attributes):
        attribute = attributes[index]
        name = attribute['xml_name']
        member = attribute['memberName']
        set_name = 'mIsSet{0}'.format(strFunctions.upper_first(attribute['name']))
        line = ['numErrs = log->getNumErrors()',
                '{0} = attributes.readInto(\"{1}\", '
                '{2})'.format(set_name, name, member)]
        code.append(self.create_code_block('line', line))

        # sort error names to be used
        [error_bool, error] = self.sort_error_names(strFunctions.upper_first(attribute['name']), 'Boolean')
        line = ['log->getNumErrors() == numErrs + 1 && log->contains(XMLAttributeTypeMismatch)',
                'log->remove(XMLAttributeTypeMismatch)',
                'log->{0}{1}, {2})'.format(self.error, error_bool, self.given_args)]
        if attribute['reqd']:
            line += ['else',
                     'std::string message = \"{0} attribute \'{1}\' is '
                     'missing from the <{2}> element.\"'.format(self.package,
                                                                name,
                                                                self.class_name),
                     'log->{0}{1}, {2}, message)'.format(self.error, error,
                                                         self.given_args)]
            nested_if = self.create_code_block('if_else', line)
        else:
            nested_if = self.create_code_block('if', line)

        line = ['{0} == false'.format(set_name), nested_if]
        code.append(self.create_code_block('if', line))

    def write_sid_read(self, index, code, attributes, is_l3v1=False):
        attribute = attributes[index]
        name = attribute['xml_name']
        given_name = attribute['name']
        att_type = attribute['type']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'
        class_name = strFunctions.remove_prefix(self.class_name)
        if is_l3v1 and name == 'id':
            line = ['XMLTriple triple{0}(\"{1}\", nURI, getPrefix())'.format(name.upper(), name),
                    'assigned = attributes.readInto(triple{0}, {1})'.format(name.upper(), member)]
        else:
            line = ['assigned = attributes.readInto(\"{0}\", {1})'.format(name,
                                                                          member)]
        code.append(self.create_code_block('line', line))

        check_function = 'isValidSBMLSId'.format(self.cap_language)
        if att_type == 'ID' or att_type == 'IDREF':
            check_function = 'isValidXMLID'
        if att_type == 'SId':
            if self.is_plugin:
                invalid_line = '\"The {1}:id on the <\" + getParentSBMLObject()->getElementName() + \"> is \'\" + {0} + \"\', ' \
                               'which does not conform to ' \
                               'the syntax.\"'.format(member, self.package.lower())
            else:
                invalid_line = '\"The id on the <\" + getElementName() + \"> is \'\" + {0} + \"\', ' \
                               'which does not conform to ' \
                               'the syntax.\"'.format(member)
            error = '{0}IdSyntaxRule'.format(self.package)
        else:
            invalid_line = '\"The attribute {0}=\'\" + {1} + ' \
                           '\"\' does not conform to the ' \
                           'syntax."'.format(name, member)
            # want type without ref
            if att_type == 'SIdRef':
                if 'element' not in attribute or len(attribute['element']) == 0:
                    type_wanted = 'SId'
                else:
                    type_wanted = attribute['element']
            elif att_type.endswith('Ref') or att_type.endswith('REF'):
                length = len(att_type)
                type_wanted = att_type[0:length-3]
            else:
                type_wanted = att_type
            [error, not_used] = self.sort_error_names(strFunctions.upper_first(given_name),
                                                type_wanted)
        line = ['{0}.empty() == true'.format(member)]
        if self.is_plugin:
            line.append('logEmptyString({0}, level, version, pkgVersion, '
                        '\"<{1}>\")'.format(member, self.class_name))
        else:
            line.append('logEmptyString({0}, level, version, '
                        '\"<{1}>\")'.format(member, self.class_name))
        line += ['else if',
                 'SyntaxChecker::{0}({1}) == '
                 'false'.format(check_function, member)]
        if self.is_plugin or global_variables.is_package:
            line.append('log->{0}{3}, {1}, '
                        '{2}, getLine(), getColumn())'.format(self.error, self.given_args,
                                      invalid_line, error))
        else:
            line.append('logError({1}, level, version, '
                        '{0})'.format(invalid_line, error))
        first_if = self.create_code_block('else_if', line)

        line = 'assigned == true'
        if self.is_plugin:
            class_name = strFunctions.get_class_from_plugin(
                self.class_name, self.package)
        else:
            class_name = strFunctions.remove_prefix(self.class_name)
        # sort error names to be used
        [not_used, error] = self.sort_error_names(strFunctions.upper_first(given_name), '')

        if status == 'optional':
            block = [line, first_if]
            code.append(self.create_code_block('if', block))
        else:
            extra_lines = ['std::string message = \"{0} attribute \'{1}\' '
                           'is missing from the <{2}> '
                           'element.\"'.format(self.package, name,
                                               self.class_name),
                           'log->{0}{1}, {2}, message'
                           ')'.format(self.error, error, self.given_args)]
            block = [line, first_if, 'else',
                     self.create_code_block('line', extra_lines)]
            code.append(self.create_code_block('if_else', block))

    def write_sidref_read(self, index, code, attributes):
        attribute = attributes[index]
        name = attribute['xml_name']
        given_name = attribute['name']
        att_type = attribute['type']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'
        line = ['assigned = attributes.readInto(\"{0}\", {1})'.format(name,
                                                                      member)]
        code.append(self.create_code_block('line', line))

        check_function = 'isValidSBMLSId'.format(self.cap_language)
        if att_type == 'IDREF':
            check_function = 'isValidXMLID'
        # want type without ref
        if att_type == 'SIdRef':
            if 'element' not in attribute or len(attribute['element']) == 0:
                type_wanted = 'SId'
            else:
                type_wanted = attribute['element']
        elif att_type.endswith('Ref') or att_type.endswith('REF'):
            length = len(att_type)
            type_wanted = att_type[0:length-3]
        else:
            type_wanted = att_type
        [error, not_used] = self.sort_error_names(strFunctions.upper_first(given_name),
                                            type_wanted)
        line = ['{0}.empty() == true'.format(member)]
        if self.is_plugin:
            line.append('logEmptyString({0}, level, version, pkgVersion, '
                        '\"<{1}>\")'.format(member, self.class_name))
        else:
            line.append('logEmptyString({0}, level, version, '
                        '\"<{1}>\")'.format(member, self.class_name))
        line += ['else if',
                 'SyntaxChecker::{0}({1}) == '
                 'false'.format(check_function, member)]
        msgline = ['isSetId()', 'msg += \" with id \'\" + getId() + \"\'\"']
        nested_if = self.create_code_block('if', msgline)
        if self.is_plugin:
            line.append('std::string msg = \"The {0} attribute on the <\" + getParentSBMLObject()->getElementName() + \">\"'.format(name))
        else:
            line.append('std::string msg = \"The {0} attribute on the <\" + getElementName() + \">\"'.format(name))
        line.append(nested_if)
        line.append('msg += \" is \'\" + {0} + \"\', which does not conform to the syntax.\"'.format(member))


        if self.is_plugin or global_variables.is_package:
            line.append('log->{0}{3}, {1}, '
                        '{2}, getLine(), getColumn())'.format(self.error, self.given_args,
                                      'msg', error))
        else:
            line.append('logError({1}, level, version, '
                        '{0})'.format('msg', error))
        first_if = self.create_code_block('else_if', line)

        line = 'assigned == true'
        # sort error names to be used
        [not_used, error] = self.sort_error_names(strFunctions.upper_first(given_name), '')

        if status == 'optional':
            block = [line, first_if]
            code.append(self.create_code_block('if', block))
        else:
            extra_lines = ['std::string message = \"{0} attribute \'{1}\' '
                           'is missing from the <{2}> '
                           'element.\"'.format(self.package, name,
                                               self.class_name),
                           'log->{0}{1}, {2}, message'
                           ')'.format(self.error, error, self.given_args)]
            block = [line, first_if, 'else',
                     self.create_code_block('line', extra_lines)]
            code.append(self.create_code_block('if_else', block))

    def write_string_read(self, index, code, attributes, is_l3v1=False):
        attribute = attributes[index]
        name = attribute['xml_name']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'

        if name == 'name':
            if is_l3v1:
                line = ['XMLTriple triple{0}(\"{1}\", nURI, getPrefix())'.format(name.upper(), name),
                        'assigned = attributes.readInto(triple{0}, {1})'.format(name.upper(), member)]
            elif attribute['reqd'] or not self.has_multiple_versions:
                line = ['assigned = attributes.readInto(\"{0}\", {1})'.format(name,
                                                                              member)]
            else:
                line = ['// read by SBase']
                code.append(self.create_code_block('line', line))
                return
        else:
            line = ['assigned = attributes.readInto(\"{0}\", {1})'.format(name,
                                                                          member)]
        code.append(self.create_code_block('line', line))

        line = ['{0}.empty() == true'.format(member)]
        if self.is_plugin:
            line.append('logEmptyString({0}, level, version, pkgVersion, '
                        '\"<{1}>\")'.format(member, self.class_name))
        else:
            line.append('logEmptyString({0}, level, version, '
                        '\"<{1}>\")'.format(member, self.class_name))
        first_if = self.create_code_block('if', line)
        line = 'assigned == true'
        if self.is_plugin:
            class_name = strFunctions.get_class_from_plugin(
                self.class_name, self.package)
        else:
            class_name = strFunctions.remove_prefix(self.class_name)
        # sort error names to be used
        if not global_variables.is_package:
            use_name = strFunctions.prefix_name(class_name)
        else:
            use_name = class_name
        [not_used, error] = self.sort_error_names(use_name, '')
        if status == 'optional':
            block = [line, first_if]
            code.append(self.create_code_block('if', block))
        else:
            extra_lines = ['std::string message = \"{0} attribute \'{1}\' '
                           'is missing from the <{2}> '
                           'element.\"'.format(self.package, name,
                                               self.class_name),
                           'log->{0}{1}, {2}, message'
                           ')'.format(self.error, error, self.given_args)]
            block = [line, first_if, 'else',
                     self.create_code_block('line', extra_lines)]
            code.append(self.create_code_block('if_else', block))

    def write_enum_read(self, index, code, attributes):
        attribute = attributes[index]
        name = attribute['xml_name']
        element = attribute['element']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'
        [att_name, unused] = strFunctions.remove_hyphens(attribute['name'])

        # sort error names to be used
        [error, att_error] = self.sort_error_names(strFunctions.upper_first(att_name),'{0}Enum'.format(element))
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}Unknown'.format(self.package)
            if att_error not in global_variables.error_list:
                att_error = '{0}Unknown'.format(self.package)

        line = ['std::string {0}'.format(att_name),
                'assigned = attributes.readInto(\"{0}\", '
                '{1})'.format(name, att_name)]
        code.append(self.create_code_block('line', line))

        line = ['isSetId()', 'msg += \"with id \'\" + getId() + \"\'\"']
        if_id = self.create_code_block('if', line)

        line = ['{0}_isValid({1}) == 0'.format(element, member),
                self.create_code_block('line',
                                       ['std::string msg = \"The {0} on the '
                                        '<{1}'
                                        '> \"'.format(name, self.class_name)]),
                if_id,
                self.create_code_block('line',
                                       ['msg += \"is \'\" + {0} + \"\', which '
                                        'is not a valid option.'
                                        '\"'.format(att_name)]),
                self.create_code_block('line', ['log->{0}{1}, {2}, msg)'
                                       .format(self.error, error,
                                               self.given_args)])]
        second_if = self.create_code_block('if', line)

        line = ['{0}.empty() == true'.format(att_name),
                'logEmptyString({0}, level, version, '
                '\"<{1}>\")'.format(att_name, self.class_name),
                'else',
                self.create_code_block('line',
                                       ['{0} = {1}_fromString({2}.'
                                        'c_str())'.format(member, element,
                                                          att_name)]),
                second_if]
        first_if = self.create_code_block('if_else', line)

        line = 'assigned == true'
        if status == 'optional':
            block = [line, first_if]
            code.append(self.create_code_block('if', block))
        else:
            extra_lines = ['std::string message = \"{0} attribute \'{1}\' '
                           'is missing.\"'.format(self.package, name),
                           'log->{0}{1}, {2}, message'
                           ')'.format(self.error, att_error, self.given_args)]
            block = [line, first_if, 'else',
                     self.create_code_block('line', extra_lines)]
            code.append(self.create_code_block('if_else', block))

    def write_number_read(self, index, code, att_type, attributes):
        attribute = attributes[index]
        [name, unused] = strFunctions.remove_hyphens(attribute['name'])
        up_name = strFunctions.upper_first(name)
        member = attribute['memberName']
        set_name = 'mIsSet{0}'.format(up_name)
        reqd = attribute['reqd']
        if att_type == 'int':
            num_type = 'Integer'
        elif att_type == 'uint':
            num_type = 'UnInteger'
        elif att_type == 'double':
            num_type = 'Double'
        else:
            num_type = 'FIX ME'

        # sort error names to be used
        [error, att_error] = self.sort_error_names(up_name, num_type)
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}Unknown'.format(self.package)
            if att_error not in global_variables.error_list:
                att_error = '{0}Unknown'.format(self.package)
        line = ['numErrs = log->getNumErrors()',
                '{0} = attributes.readInto(\"{1}\", {2})'.format(set_name,
                                                                 attribute['xml_name'],
                                                                 member)]
        code.append(self.create_code_block('line', line))

        line = ['log->getNumErrors() == numErrs + 1 && '
                'log->contains(XMLAttributeTypeMismatch)',
                'log->remove(XMLAttributeTypeMismatch)',
                'std::string message = \"{0} attribute \'{1}\' '
                'from the <{2}> element must be an '
                'integer.\"'.format(self.package, attribute['xml_name'], self.class_name),
                'log->{0}{1}, {2}, message)'.format(self.error, error,
                                                    self.given_args)]
        if reqd:
            if self.is_plugin:
                class_name = strFunctions.get_class_from_plugin(
                    self.class_name, self.package)
            else:
                class_name = self.class_name
            line += ['else',
                     'std::string message = \"{0} attribute \'{1}\' is missing '
                     'from the <{2}> element.\"'.format(self.package, attribute['xml_name'],
                                                        class_name),
                     'log->{0}{1}, {2}, message)'.format(self.error, att_error,
                                                         self.given_args)]

            if_error = self.create_code_block('if_else', line)
        else:
            if_error = self.create_code_block('if', line)

        line = [' {0} == false'.format(set_name),
                if_error]
        second_if = self.create_code_block('if', line)
        code.append(second_if)

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code

    def sort_error_names(self, up_name, num_type):
        if self.is_plugin:
            class_name = self.base
            error = '{0}{1}{2}MustBe{3}'.format(self.package, class_name,
                                                up_name, 'NonNegativeInteger' if num_type=='UnInteger' else num_type)
            att_error = '{0}{1}AllowedAttributes'.format(self.package,
                                                         class_name)
        else:
            class_name = strFunctions.remove_prefix(self.class_name)
            if class_name.startswith('ListOf'):
                temp = 'LO{0}'.format(class_name[6:])
                class_name = temp
            error = '{0}{1}{2}MustBe{3}'.format(self.package, class_name,
                                                up_name, 'NonNegativeInteger' if num_type=='UnInteger' else num_type)
            att_error = '{0}{1}AllowedAttributes'.format(self.package,
                                                         class_name)
        if not global_variables.running_tests and error not in global_variables.error_list:
            error = '{0}Unknown'.format(self.package)
        if not global_variables.running_tests and att_error not in global_variables.error_list:
            att_error = '{0}Unknown'.format(self.package)
        return [error, att_error]
