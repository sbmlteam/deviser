#!/usr/bin/env python
#
# @file    ProtectedFunctions.py
# @brief   class to create protected functions
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

from util import strFunctions, query, global_variables


class ProtectedFunctions():
    """Class for all protected functions"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object):
        self.language = language
        self.cap_language = language.upper()
        self.package = class_object['package']
        self.class_name = class_object['name']
        self.is_cpp_api = is_cpp_api
        self.is_list_of = is_list_of
        self.is_plugin = False
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']
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
            self.version_attributes.append(
                query.get_version_attributes(self.all_attributes, 1))
            for i in range(1, class_object['num_versions']):
                self.version_attributes.append(
                    query.get_version_attributes(self.all_attributes, i+1))
        self.is_header = class_object['is_header']

        self.document = False
        if 'document' in class_object:
            self.document = class_object['document']

        # useful variables
        if not self.is_cpp_api and self.is_list_of:
            self.struct_name = self.object_child_name
        else:
            self.struct_name = self.object_name
        self.plural = strFunctions.plural(self.child_name)
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
        arguments = ['XMLInputStream& stream']

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
                base_create = 'NULL'
                if not self.has_std_base:
                    base_create = '{0}::createObject' \
                                  '(stream)'.format(self.base_class)
                code = [self.create_code_block('line',
                                               ['{0}* obj = '
                                                '{1}'.format(self.std_base,
                                                             base_create)])]
                if self.is_plugin:
                    lines = ['const std::string& name = '
                             'stream.peek().getName()',
                             'const XMLNamespaces& xmlns = '
                             'stream.peek().getNamespaces()',
                             'const std::string& prefix '
                             '= stream.peek().getPrefix()']
                else:
                    lines = ['const std::string& name '
                             '= stream.peek().getName()']
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
                if self.is_plugin:
                    class_name = strFunctions.get_class_from_plugin(
                        self.class_name, self.package)
                else:
                    class_name = self.class_name
                # sort error names to be used
                error = '{0}{1}AllowedElements'.format(self.package, class_name)
                if not global_variables.running_tests:
                    if error not in global_variables.error_list:
                        error = '{0}Unknown'.format(self.package)
                error_line = 'getErrorLog()->{0}{1}, ' \
                             '{2})'.format(self.error, error, self.error_args)
                if num_children == 1:
                    element = self.find_single_element()
                    if element['abstract'] and \
                            not element['attType'] == 'lo_element':
                        implementation = self.get_abstract_block(element, ns)
                        code.append(self.create_code_block('else_if',
                                                           implementation))
                    elif element['type'] == 'inline_lo_element':
                        implementation = ['obj = {0}.createObject(stream'
                                          ')'.format(element['memberName'])]
                        code.append(self.create_code_block('line',
                                                           implementation))
                    elif element['attType'] == 'lo_element':
                        implementation = self.get_lo_block(element, error_line)
                        code.append(self.create_code_block('if',
                                                           implementation))
                    else:
                        if global_variables.is_package:
                            implementation = ['prefix == targetPrefix']
                            implementation += self.get_element_block(element,
                                                                     error_line, ns)
                            code.append(self.create_code_block('if',
                                                               implementation))
                        else:
                            implementation = self.get_element_block(element,
                                                                     error_line, ns)
                            code.append(self.create_code_block('if',
                                                               implementation))

                else:
                    implementation = []
                    i = 0
                    children_dealt_with = 0
                    for i in range(0, len(self.child_elements)):
                        element = self.child_elements[i]
                        if 'is_ml' in element and element['is_ml']:
                            continue
                        overwrite = element['children_overwrite']
                        name = element['memberName']
                        loname = element['xml_name'] if overwrite \
                            else strFunctions.lower_first(strFunctions.remove_prefix(element['element']))
                        implementation += self.get_obj_block(name, loname,
                                                             error_line,
                                                             overwrite,
                                                             element['element'],
                                                             ns)
                        children_dealt_with += 1
                        if i < num_children - 1:
                            implementation.append('else if')
                    for j in range(i, i + len(self.child_lo_elements)):
                        element = self.child_lo_elements[j-i]
                        if self.is_plugin:
                            implementation += \
                                self.get_plugin_lo_block(element, error_line)
                        else:
                            implementation += self.get_lo_block(element,
                                                                error_line)
                        if j < num_children - children_dealt_with - 1:
                            implementation.append('else if')
                    if not self.is_plugin:
                        code.append(self.create_code_block('else_if',
                                                           implementation))
                    else:
                        plugin_imp = self.create_code_block('else_if',
                                                            implementation)
                        code.append(self.create_code_block('if',
                                                           ['prefix == '
                                                            'targetPrefix',
                                                            plugin_imp]))
                if global_variables.is_package and len(self.child_elements) != self.num_non_std_children:
                    code.append(self.create_code_block('line',
                                                       ['delete '
                                                        '{0}'.format(ns)]))
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

    def get_element_block(self, element, error_line, ns):
        name = element['name']
        function = strFunctions.upper_first(element['element'])

        nested_if = self.create_code_block('if',
                                           ['isSet{0}()'.format(element['capAttName']),
                                            error_line])
        used_ns = ns
        if not global_variables.is_package:
            used_ns = 'get{0}Namespaces()'.format(global_variables.prefix)
        implementation = ['name == \"{0}\"'.format(name),
                          nested_if,
                          '{0} = new {1}({2})'.format(element['memberName'],
                                                      function, used_ns),
                          'obj = {0}'.format(element['memberName'])]
        if global_variables.is_package:
            return [self.create_code_block('if', implementation)]
        else:
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

    def get_abstract_block(self, element, ns):
        name = element['memberName']
        concretes = query.get_concretes(element['root'], element['concrete'])
        num_concs = len(concretes)
        implementation = self.get_concrete_block(concretes[0], name, ns)
        for i in range(1, num_concs):
            implementation.append('else if')
            implementation += self.get_concrete_block(concretes[i], name, ns)
        return implementation

    @staticmethod
    def get_concrete_block(element, name, ns):
        implementation = ['name == \"{0}\"'.format(element['name']),
                          '{0} = new {1}({2})'.format(name, element['element'],
                                                      ns),
                          'obj = {0}'.format(name)]
        return implementation

    def get_obj_block(self, name, loname, error_line, over_write, element, ns):
        implementation = []
        used_ns = ns
        if not global_variables.is_package:
            used_ns = 'get{0}Namespaces()'.format(global_variables.prefix)
        nested_if = self.create_code_block('if',
                                           ['{0} '
                                            '!= NULL'.format(name),
                                            error_line])
        implementation.append('name == \"{0}\"'.format(loname))
        implementation.append(nested_if)
        implementation.append('{0} = new {1}'
                              '({2})'.format(name,
                                             element, used_ns))
        if over_write:
            implementation.append('{0}->setElementName'
                                  '(name)'.format(name))
        implementation.append('obj = {0}'.format(name))
        return implementation

    def find_single_element(self):
        element = None
        for i in range(0, len(self.child_elements)):
            element = self.child_elements[i]
            if 'is_ml' in element and element['is_ml']:
                element = None
                continue
            else:
                break
        if element is None:
            element = self.child_lo_elements[0]
        return element

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
        arguments = ['ExpectedAttributes& attributes']

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
                                               ['unsigned int pkgVersion = '
                                                'getPackageVersion()']))
            implementation = ['pkgVersion == 1']
            for i in range(0, len(self.version_attributes)):
                for j in range(0, len(self.version_attributes[i])):
                    if self.version_attributes[i][j]['isArray']:
                        continue
                    name = self.version_attributes[i][j]['name']
                    implementation.append('attributes.add(\"{0}\")'
                                          ''.format(name))
                if i < len(self.version_attributes) - 1:
                    implementation.append('else')
            code.append(self.create_code_block('if_else', implementation))
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
        arguments = ['const XMLAttributes& attributes',
                     'const ExpectedAttributes& expectedAttributes']

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
                    'numErrs = log->getNumErrors()']
            code.append(self.create_code_block('line', line))

            line = self.get_error_from_base_class()
            code.append(self.create_code_block('for', line))

        if not self.has_multiple_versions:
            for i in range(0, len(self.attributes)):
                self.write_read_att(self.attributes, i, code)
        else:
            implementation = ['pkgVersion == 1', 'readV1Attributes(attributes)',
                              'else', 'readV2Attributes(attributes)']
            code.append(self.create_code_block('if_else', implementation))

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
        function = 'readV{0}Attributes'.format(version)
        return_type = 'void'
        arguments = ['const XMLAttributes& attributes']

        # create the function implementation
        implementation = ['unsigned int level = getLevel()',
                          'unsigned int version = getVersion()',
                          'bool assigned = false',
                          'unsigned int pkgVersion = getPackageVersion()',
                          'SBMLErrorLog* log = getErrorLog()',
                          'unsigned int numErrs']
        code = [dict({'code_type': 'line', 'code': implementation})]

        for i in range(0, len(self.version_attributes[version-1])):
            self.write_read_att(self.version_attributes[version-1], i, code)

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
        if self.is_list_of or self.num_non_std_children == 0:
            return
        # create comment
        title_line = 'Reads other XML such as math/notes etc.'
        params = []
        return_lines = []
        additional = []

        # create function declaration
        function = 'readOtherXML'
        return_type = 'bool'
        arguments = ['XMLInputStream& stream']

        # create the function implementation
        implementation = ['bool read = false',
                          'const string& name = stream.peek().getName()']
        code = [dict({'code_type': 'line', 'code': implementation})]

        # math is unique - assume others are XMLNode based
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
                                  'const XMLToken elem = stream.peek()',
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
                        'const XMLToken& token = stream.next()',
                        'stream.skipText()',
                        'delete {0}'.format(member),
                        'XMLNode* xml = new XMLNode(stream)']
                if element['element'] == 'XMLNode':
                    line.append('{0} = new {1}(*(static_cast<XMLToken*>(xml)))'.format(member, element['element']))
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
        arguments = ['XMLOutputStream& stream']

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
            code.append(self.create_code_block('line',
                                               ['unsigned int pkgVersion = '
                                                'getPackageVersion()']))
            implementation = ['pkgVersion == 1', 'writeV1Attributes(stream)',
                              'else', 'writeV2Attributes(stream)']
            code.append(self.create_code_block('if_else', implementation))

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
        if self.is_list_of or not self.has_multiple_versions:
            return
        elif self.has_std_base and len(self.attributes) == 0:
            return

        # create comment
        title_line = 'Writes the attributes to the stream'
        params = []
        return_lines = []
        additional = []

        # create function declaration
        function = 'writeV{0}Attributes'.format(version)
        return_type = 'void'
        arguments = ['XMLOutputStream& stream']

        # create the function implementation
        code = []
        for i in range(0, len(self.version_attributes[version-1])):
            self.write_write_att(self.version_attributes[version-1], i, code)

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
        arguments = ['XMLOutputStream& stream']

        # create the function implementation
        implementation = ['XMLNamespaces xmlns',
                          'std::string prefix = getPrefix()']
        code = [dict({'code_type': 'line', 'code': implementation})]
        if global_variables.is_package:
            implementation = ['thisxmlns && thisxmlns->hasURI({0}Extension::'
                              'getXmlnsL3V1V1())'.format(self.package),
                              'xmlns.add({0}Extension::getXmlnsL3V1V1(), '
                              'prefix)'.format(self.package)]
        else:
            implementation = ['thisxmlns && thisxmlns->hasURI({0}_XMLNS_L1V1)'.format(global_variables.language.upper()),
                              'xmlns.add({0}_XMLNS_L1V1, '
                              'prefix)'.format(global_variables.language.upper())]

        nested_if = self.create_code_block('if', implementation)
        implementation = ['prefix.empty()',
                          'const XMLNamespaces* thisxmlns = getNamespaces()',
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
        tc = self.concretes[0]['type_code']
        implementation = 'return ((tc == {0})'.format(tc)
        for i in range(1, len(self.concretes)):
            tc = self.concretes[i]['type_code']
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
        plural = strFunctions.plural(self.class_name)
        c_err = '{0}{1}LO{2}AllowedCoreAttributes'.format(self.package,
                                                          self.parent_class,
                                                          plural)
        error = '{0}{1}LO{2}AllowedAttributes'.format(self.package,
                                                      self.parent_class,
                                                      plural)
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}{1}AllowedAttributes'.format(self.package,
                                                         self.class_name)
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
                                                        self.given_args)]
            if_err = self.create_code_block('else_if', line)
        else:
            line = ['log->getError(n)->getErrorId() == UnknownCoreAttribute',
                    'const std::string details = log->getError(n)->getMessage()',
                    'log->remove(UnknownCoreAttribute)',
                    'log->{0}{1}, {2}, details)'.format(self.error, error,
                                                        self.given_args)]
            if_err = self.create_code_block('if', line)

        line = ['int n = numErrs-1; n >= 0; n--', if_err]
        for_loop = self.create_code_block('for', line)

        if global_variables.is_package:
            line = ['static_cast<{0}*>(getParent{1}Object())->size() '
                    '< 2'.format(strFunctions.cap_list_of_name(self.class_name),
                                 self.cap_language),
                    'numErrs = log->getNumErrors()', for_loop]
        else:
            line = ['static_cast<{0}*>(getParent{1}Object())->size() '
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
        if not global_variables.running_tests:
            if global_variables.is_package:
                if core_err not in global_variables.error_list:
                    core_err = '{0}Unknown'.format(self.package)
                if error not in global_variables.error_list:
                    error = '{0}Unknown'.format(self.package)
            else:
                if core_err not in global_variables.error_list:
                    core_err = '{0}UnknownError'.format(global_variables.prefix)
                if error not in global_variables.error_list:
                    error = '{0}UnknownError'.format(global_variables.prefix)

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
            if_err = self.create_code_block('else_if', line)
        else:
            line = ['log->getError(n)->getErrorId() == UnknownCoreAttribute',
                    'const std::string details = log->getError(n)->getMessage()',
                    'log->remove(UnknownCoreAttribute)',
                    'log->{0}{1}, {2}, details)'.format(self.error, error,
                                                        self.given_args)]
            if_err = self.create_code_block('if', line)


        line = ['int n = numErrs-1; n >= 0; n--', if_err]
        return line

    def write_write_att(self, attributes, index, code):
        if attributes[index]['isArray']:
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

    def write_read_att(self, attributes, index, code):
        attribute = attributes[index]
        if attribute['isArray']:
            return
        name = attribute['xml_name']
        att_type = attribute['type']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'

        implementation = ['', '{0} {1} (use = \"{2}\"'
                              ' )'.format(name, att_type, status),
                          '']
        code.append(self.create_code_block('comment', implementation))

        if att_type == 'SId' or att_type == 'SIdRef' \
                or att_type == 'UnitSId' or att_type == 'UnitSIdRef'\
                or att_type == 'ID' or att_type == 'IDREF':
            self.write_sid_read(index, code, attributes)
        elif att_type == 'enum':
            self.write_enum_read(index, code, attributes)
        elif att_type == 'string' or att_type == 'IDREF':
            self.write_string_read(index, code, attributes)
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
        line = ['{0} = attributes.readInto(\"{1}\", '
                '{2})'.format(set_name, name, member)]
        code.append(self.create_code_block('line', line))

        # sort error names to be used
        error = '{0}{1}AllowedAttributes'.format(self.package, self.class_name)
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}Unknown'.format(self.package)
        if attribute['reqd']:
            line = ['!{0}'.format(set_name),
                    'std::string message = \"{0} attribute \'{1}\' is '
                    'missing from the <{2}> element.\"'.format(self.package,
                                                               name,
                                                               self.class_name),
                    'log->{0}{1}, {2}, message)'.format(self.error, error,
                                                        self.given_args)]
            code.append(self.create_code_block('if', line))

    def write_sid_read(self, index, code, attributes):
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
        if att_type == 'ID' or att_type == 'IDREF':
            check_function = 'isValidXMLID'
        if att_type == 'SId':
            invalid_line = '\"The id \'\" + {0} + \"\' does not conform to ' \
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
            error = '{0}{1}{2}MustBe{3}'.format(self.package, self.class_name,
                                                strFunctions.upper_first(given_name),
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
        if self.is_plugin:
            line.append('log->{0}{3}, {1}, '
                        '{2})'.format(self.error, self.given_args,
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
            class_name = self.class_name
        # sort error names to be used
        error = '{0}{1}AllowedAttributes'.format(self.package, class_name)
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}Unknown'.format(self.package)

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

    def write_string_read(self, index, code, attributes):
        attribute = attributes[index]
        name = attribute['xml_name']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'

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
            class_name = self.class_name
        # sort error names to be used
        error = '{0}{1}AllowedAttributes'.format(self.package, class_name)
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}Unknown'.format(self.package)
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

        # sort error names to be used
        error = '{0}{1}{2}MustBe{3}Enum'.format(self.package, self.class_name,
                                                strFunctions.upper_first(name),
                                                element)
        att_error = '{0}{1}AllowedAttributes'.format(self.package,
                                                     self.class_name)
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}Unknown'.format(self.package)
            if att_error not in global_variables.error_list:
                att_error = '{0}Unknown'.format(self.package)

        line = ['std::string {0}'.format(name.lower()),
                'assigned = attributes.readInto(\"{0}\", '
                '{1})'.format(name, name.lower())]
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
                                        '\"'.format(name.lower())]),
                self.create_code_block('line', ['log->{0}{1}, {2}, msg)'
                                       .format(self.error, error,
                                               self.given_args)])]
        second_if = self.create_code_block('if', line)

        line = ['{0}.empty() == true'.format(name.lower()),
                'logEmptyString({0}, level, version, '
                '\"<{1}>\")'.format(name.lower(), self.class_name),
                'else',
                self.create_code_block('line',
                                       ['{0} = {1}_fromString({2}.'
                                        'c_str())'.format(member, element,
                                                          name.lower())]),
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
        name = attribute['xml_name']
        up_name = strFunctions.upper_first(name)
        member = attribute['memberName']
        set_name = 'mIsSet{0}'.format(strFunctions.upper_first(attribute['name']))
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
        error = '{0}{1}{2}MustBe{3}'.format(self.package, self.class_name,
                                            up_name, num_type)
        att_error = '{0}{1}AllowedAttributes'.format(self.package,
                                                     self.class_name)
        if not global_variables.running_tests:
            if error not in global_variables.error_list:
                error = '{0}Unknown'.format(self.package)
            if att_error not in global_variables.error_list:
                att_error = '{0}Unknown'.format(self.package)
        line = ['numErrs = log->getNumErrors()',
                '{0} = attributes.readInto(\"{1}\", {2})'.format(set_name,
                                                                 name,
                                                                 member)]
        code.append(self.create_code_block('line', line))

        line = ['log->getNumErrors() == numErrs + 1 && '
                'log->contains(XMLAttributeTypeMismatch)',
                'log->remove(XMLAttributeTypeMismatch)',
                'std::string message = \"{0} attribute \'{1}\' '
                'from the <{2}> element must be an '
                'integer.\"'.format(self.package, name, self.class_name),
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
                     'from the <{2}> element.\"'.format(self.package, name,
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