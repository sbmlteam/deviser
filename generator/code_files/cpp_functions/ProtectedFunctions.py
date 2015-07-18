#!/usr/bin/env python
#
# @file    ProtectedFunctions.py
# @brief   class to create protected functions
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

from util import strFunctions, query


class ProtectedFunctions():
    """Class for all protected functions"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object):
        self.language = language
        self.package = class_object['package']
        self.class_name = class_object['name']
        self.is_cpp_api = is_cpp_api
        self.is_list_of = is_list_of
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

        self.typecode = class_object['typecode']
        self.attributes = class_object['class_attributes']
        self.all_attributes = class_object['attribs']
        self.sid_refs = class_object['sid_refs']
        self.has_math = class_object['hasMath']
        self.base_class = class_object['baseClass']
        self.child_base_class = ''
        if 'child_base_class' in class_object:
            self.child_base_class = class_object['child_base_class']
        self.concretes = []
        if 'concretes' in class_object:
            self.concretes = class_object['concretes']
        self.has_array = class_object['has_array']

        # check case of things where we assume upper/lower
        if self.package[0].islower():
            self.package = strFunctions.upper_first(class_object['package'])

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

    ########################################################################

    # Functions for writing createObject

    # function to write create_object
    def write_create_object(self):
        # if not list of only write if has children other than math
        if not self.is_list_of and \
                not query.has_children_not_math(self.all_attributes):
            return

        # create comment parts
        if self.is_list_of:
            title_line = 'Creates a new {} in this ' \
                         '{}'.format(self.object_child_name, self.object_name)
        else:
            title_line = 'Creates a new object from the next XMLToken ' \
                         'on the XMLInputStream'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'createObject'
        return_type = 'SBase*'
        arguments = ['XMLInputStream& stream']

        # create the function implementation
        ns = '{}ns'.format(self.package.lower())
        upkg = self.package.upper()
        if self.is_list_of:
            implementation = ['const std::string& name = '
                              'stream.peek().getName()',
                              'SBase* object = NULL']
            code = [dict({'code_type': 'line', 'code': implementation})]
            implementation = ['name == \"{}\"'.format(self.child_name.lower()),
                              '{}_CREATE_NS({}, '
                              'getSBMLNamespaces())'.format(upkg,
                                                            ns),
                              'object = new {}({})'.format(self.child_name,
                                                           ns),
                              'appendAndOwn(object)',
                              'delete {}'.format(ns)]
            code.append(self.create_code_block('if', implementation))
            code.append(self.create_code_block('line', ['return object']))
        else:
            implementation = ['TO DO']
            code = [dict({'code_type': 'line', 'code': implementation})]

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

    # Functions for attributes/elements

    # function to write addExpectedAttributes
    def write_add_expected_attributes(self):
        if self.is_list_of:
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
        implementation = ['{}::addExpectedAttributes'
                          '(attributes)'.format(self.base_class)]
        code = [dict({'code_type': 'line', 'code': implementation})]
        for i in range(0, len(self.attributes)):
            name = self.attributes[i]['name']
            implementation = ['attributes.add(\"{}\")'.format(name)]
            code.append(dict({'code_type': 'line', 'code': implementation}))

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
        if self.is_list_of:
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
                          'unsigned int version = getVersion()',
                          'unsigned int numErrs',
                          'bool assigned = false',
                          'SBMLErrorLog* log = getErrorLog()']
        code = [dict({'code_type': 'line', 'code': implementation})]

        line = ['log->getError(n)->geErrorId() == UnknownPackageAttribute',
                'const std::string details = log->getError(n)->getMessage()',
                'log->remove(UnknownPackageAttribute)',
                'log->logPackageError(\"{}\", {}LO{}AllowedAttributes, '
                'getPackageVersion(), level, version, '
                'details)'.format(self.package.lower(), self.package,
                                  self.class_name),
                'else if', 'log->getError(n)->getErrorId() == '
                           'UnknownCoreAttribute',
                'const std::string details = log->getError(n)->getMessage()',
                'log->remove(UnknownCoreAttribute)',
                'log->logPackageError(\"{}\", {}LO{}AllowedAttributes, '
                'getPackageVersion(), level, version, '
                'details)'.format(self.package.lower(), self.package,
                                  self.class_name)]
        if_err = self.create_code_block('else_if', line)

        line = ['int n = numErrs-1; n >= 0; n--', if_err]
        for_loop = self.create_code_block('for', line)

        line = ['static_cast<{}*>(getParentSBMLObject())->size() '
                '< 2'.format(strFunctions.cap_list_of_name(self.class_name)),
                'numErrs = log->getNumErrors()', for_loop]
        code.append(self.create_code_block('if', line))

        line = ['SBase::readAttributes(attributes, expectedAttributes)',
                'numErrs = log->getNumErrors()']
        code.append(self.create_code_block('line', line))

        line = ['log->getError(n)->geErrorId() == UnknownPackageAttribute',
                'const std::string details = log->getError(n)->getMessage()',
                'log->remove(UnknownPackageAttribute)',
                'log->logPackageError(\"{}\", {}{}AllowedAttributes, '
                'getPackageVersion(), level, version, '
                'details)'.format(self.package.lower(), self.package,
                                  self.class_name),
                'else if', 'log->getError(n)->getErrorId() == '
                           'UnknownCoreAttribute',
                'const std::string details = log->getError(n)->getMessage()',
                'log->remove(UnknownCoreAttribute)',
                'log->logPackageError(\"{}\", {}{}AllowedAttributes, '
                'getPackageVersion(), level, version, '
                'details)'.format(self.package.lower(), self.package,
                                  self.class_name)]
        if_err = self.create_code_block('else_if', line)

        line = ['int n = numErrs-1; n >= 0; n--', if_err]
        code.append(self.create_code_block('for', line))

        for i in range(0, len(self.attributes)):
            self.write_read_att(i, code)

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
        if self.is_list_of or not self.has_math:
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
        implementation = ['TO DO']
        code = [dict({'code_type': 'line', 'code': implementation})]

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
        if self.is_list_of:
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
        implementation = ['SBase::writeAttributes(stream)']
        code = [dict({'code_type': 'line', 'code': implementation})]

        for i in range(0, len(self.attributes)):
            self.write_write_att(i, code)

        code.append(self.create_code_block('line',
                                           ['SBase::writeExtension'
                                            'Attributes(stream)']))

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
            return

        # create comment parts
        title_line = 'Writes the namespace for the {} package'\
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
        implementation = ['thisxmlns && thisxmlns->hasURI({}Extension::'
                          'getXmlnsL3V1V1())'.format(self.package),
                          'xmlns.add({}Extension::getXmlnsL3V1V1(), '
                          'prefix)'.format(self.package)]
        nested_if = self.create_code_block('if', implementation)
        implementation = ['prefix.empty()',
                          'XMLNamespaces* thisxmlns = getNamespaces()',
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

        # create the function implementation
        implementation = ['TO DO']
        code = [dict({'code_type': 'line', 'code': implementation})]

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
        arguments = ['{}* item'.format(self.child_base_class)]

        # create the function implementation
        implementation = ['TO DO']
        code = [dict({'code_type': 'line', 'code': implementation})]

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

    #####################################################################

    # HELPER FUNCTIONS

    def write_write_att(self, index, code):
        name = self.attributes[index]['name']
        cap_name = self.attributes[index]['capAttName']
        member = self.attributes[index]['memberName']
        att_type = self.attributes[index]['attType']
        if att_type == 'enum':
            element = self.attributes[index]['element']
            variable = '{}_toString({})'.format(element, member)
        else:
            variable = member
        line = ['isSet{}() == true'.format(cap_name),
                'stream.writeAttribute(\"{}\", getPrefix(), '
                '{})'.format(name, variable)]
        code.append(self.create_code_block('if', line))

    def write_read_att(self, index, code):
        attribute = self.attributes[index]
        name = attribute['name']
        att_type = attribute['type']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'

        implementation = ['', '{} {} (use = \"{}\"'
                              ' )'.format(name, att_type, status),
                          '']
        code.append(self.create_code_block('comment', implementation))

        if att_type == 'SId' or att_type == 'SIdRef':
            self.write_sid_read(index, code)
        elif att_type == 'enum':
            self.write_enum_read(index, code)
        elif att_type == 'string':
            self.write_string_read(index, code)
        elif att_type == 'int':
            self.write_uint_read(index, code)
        else:
            line = ['assigned = attributes.readInto(\"{}\", '
                    '{})'.format(name, member)]
            code.append(self.create_code_block('line', line))

    def write_sid_read(self, index, code):
        attribute = self.attributes[index]
        name = attribute['name']
        att_type = attribute['type']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'

        line = ['assigned = attributes.readInto(\"{}\", {})'.format(name,
                                                                    member)]
        code.append(self.create_code_block('line', line))

        if att_type == 'SId':
            invalid_line = '\"The id \'\" + {} + \"\' does not conform to ' \
                           'the syntax.\"'.format(member)
        else:
            invalid_line = '\"The syntax of the attribute {}=\'\" + {} + ' \
                           '\"\' does not conform to the ' \
                           'syntax.\"'.format(name, member)
        line = ['{}.empty() == true'.format(member),
                'logEmptyString({}, level, version, '
                '\"<{}>\")'.format(member, self.class_name),
                'else if',
                'SyntaxChecker::isValidSBMLSId({}) == false'.format(member),
                'logError(InvalidIdSyntax, level, version, '
                '{})'.format(invalid_line)]
        first_if = self.create_code_block('else_if', line)

        line = 'assigned == true'
        if status == 'optional':
            block = [line, first_if]
            code.append(self.create_code_block('if', block))
        else:
            extra_lines = ['std::string message = \"{} attribute \'{}\' '
                           'is missing.\"'.format(self.package, name),
                           'getErrorLog()->logPackageError(\"{}\", '
                           '{}{}AllowedAttributes, getPackageVersion(), '
                           'level, version, message'
                           ')'.format(self.package.lower(), self.package,
                                      self.class_name)]
            block = [line, first_if, 'else',
                     self.create_code_block('line', extra_lines)]
            code.append(self.create_code_block('if_else', block))

    def write_string_read(self, index, code):
        attribute = self.attributes[index]
        name = attribute['name']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'

        line = ['assigned = attributes.readInto(\"{}\", {})'.format(name,
                                                                    member)]
        code.append(self.create_code_block('line', line))

        line = ['{}.empty() == true'.format(member),
                'logEmptyString({}, level, version, '
                '\"<{}>\")'.format(member, self.class_name)]
        first_if = self.create_code_block('if', line)

        line = 'assigned == true'
        if status == 'optional':
            block = [line, first_if]
            code.append(self.create_code_block('if', block))
        else:
            extra_lines = ['std::string message = \"{} attribute \'{}\' '
                           'is missing.\"'.format(self.package, name),
                           'log->logPackageError(\"{}\", '
                           '{}{}AllowedAttributes, getPackageVersion(), '
                           'level, version, message'
                           ')'.format(self.package.lower(), self.package,
                                      self.class_name)]
            block = [line, first_if, 'else',
                     self.create_code_block('line', extra_lines)]
            code.append(self.create_code_block('if_else', block))

    def write_enum_read(self, index, code):
        attribute = self.attributes[index]
        name = attribute['name']
        element = attribute['element']
        member = attribute['memberName']
        status = 'required' if attribute['reqd'] else 'optional'

        line = ['std::string {}'.format(name.lower()),
                'assigned = attributes.readInto(\"{}\", '
                '{})'.format(name, name.lower())]
        code.append(self.create_code_block('line', line))

        line = ['isSetId()', 'msg += \"with id \'\" + getId() + \"\'\"']
        if_id = self.create_code_block('if', line)

        line = ['{0}_isValid{0}({1}) == 0'.format(element, member),
                self.create_code_block('line',
                                       ['std::string msg = \"The {} on the <{}'
                                        '> \"'.format(name, self.class_name)]),
                if_id,
                self.create_code_block('line',
                                       ['msg += \"is \'\" + {} + \"\', which '
                                        'is not a valid option.'
                                        '\"'.format(name.lower())]),
                self.create_code_block('line', ['log->logPackage'
                                                'Error(\"{}\", {}{}Values, '
                                                'getPackageVersion(), level,'
                                                ' version, msg)'
                                       .format(self.package.lower(),
                                               self.package, element)])]
        second_if = self.create_code_block('if', line)

        line = ['{}.empty() == true'.format(name.lower()),
                'logEmptyString({}, level, version, '
                '\"<{}>\")'.format(name.lower(), self.class_name),
                'else',
                self.create_code_block('line',
                                       ['{} = {}_fromString({}.'
                                        'c_str())'.format(member, element,
                                                          name.lower())]),
                second_if]
        first_if = self.create_code_block('if_else', line)

        line = 'assigned == true'
        if status == 'optional':
            block = [line, first_if]
            code.append(self.create_code_block('if', block))
        else:
            extra_lines = ['std::string message = \"{} attribute \'{}\' '
                           'is missing.\"'.format(self.package, name),
                           'log->logPackageError(\"{}\", '
                           '{}{}AllowedAttributes, getPackageVersion(), '
                           'level, version, message'
                           ')'.format(self.package.lower(), self.package,
                                      self.class_name)]
            block = [line, first_if, 'else',
                     self.create_code_block('line', extra_lines)]
            code.append(self.create_code_block('if_else', block))

    def write_uint_read(self, index, code):
        attribute = self.attributes[index]
        name = attribute['name']
        up_name = strFunctions.upper_first(name)
        member = attribute['memberName']
        set_name = 'mIsSet{}'.format(strFunctions.upper_first(name))

        line = ['numErrs = getErrorLog()->getNumErrors()',
                '{} = attributes.readInto(\"{}\", {})'.format(set_name,
                                                              name,
                                                              member)]
        code.append(self.create_code_block('line', line))

        line = ['log->getNumErrors() == numErrs + 1 && '
                'log->contains(XMLAttributeTypeMismatch)',
                'log->remove(XMLAttributeTypeMismatch)',
                'log->logPackageError(\"{}\", {}{}MustBeInteger,'
                ' getPackageVersion(), level, version, msg.str()))'.format(
                    self.package.lower(), self.package, up_name)]
        if_error = self.create_code_block('if', line)

        line = ['isSetId()', 'msg << \"with id \'\" << getId() << \"\' \"']
        if_id = self.create_code_block('if', line)

        line = ['{} < 0'.format(member), 'std::stringstream msg',
                'msg << \"The {} of the <{}> \"'.format(name, self.class_name),
                if_id,
                'msg << \"is \'\" << {} << \"\', which is '
                'negative.\"'.format(member),
                'log->logPackageError(\"{}\", {}{}MustBeNonNegative,'
                ' getPackageVersion(), level, version'.format(
                    self.package.lower(), self.package, up_name)]
        if_neg = self.create_code_block('if', line)

        line = [' {} == false'.format(set_name),
                if_error, 'else', if_neg]
        second_if = self.create_code_block('if_else', line)
        code.append(second_if)

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
