#!/usr/bin/env python
#
# @file    GeneralFunctions.py
# @brief   class to create general functions
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

from util import strFunctions, global_variables, query


class GeneralFunctions():
    """Class for general functions"""

    def __init__(self, language, is_cpp_api, is_list_of, class_object, lv_info=[]):
        self.language = language
        self.cap_language = language.upper()
        self.package = class_object['package']
        self.class_name = class_object['name']
        self.has_std_base = class_object['has_std_base']
        self.base_class = class_object['baseClass']
        self.is_cpp_api = is_cpp_api
        self.is_list_of = is_list_of
        self.is_plugin = False
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']
        self.is_doc_plugin = False
        if 'is_doc_plugin' in class_object:
            self.is_doc_plugin = class_object['is_doc_plugin']
        self.ext_class = ''
        if self.is_plugin:
            self.ext_class = class_object['sbase']
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
        self.element_name = ''
        self.override_name = False
        if 'elementName' in class_object and not is_list_of:
            self.element_name = class_object['elementName']
            if self.element_name == '':
                self.override_name = False
            else:
                self.override_name = not \
                    strFunctions.compare_no_case(self.element_name,
                                                 self.class_name)
        if not global_variables.is_package:
            self.override_name = True
            if is_list_of:
                self.element_name = \
                    strFunctions.lower_list_of_name_no_prefix(class_object['lo_child'])
            else:
                self.element_name = class_object['elementName']


        self.typecode = class_object['typecode']
        self.attributes = class_object['class_attributes']
        self.sid_refs = class_object['sid_refs']
        self.unit_sid_refs = class_object['unit_sid_refs']
        self.child_lo_elements = class_object['child_lo_elements']
        self.child_elements = class_object['child_elements']
        self.has_math = class_object['has_math']
        self.has_array = class_object['has_array']
        self.overwrites_children = class_object['overwrites_children']
        # we do overwrite if we have concrete
        if not self.overwrites_children and 'concretes' in class_object:
            if len(class_object['concretes']) > 0:
                self.overwrites_children = True


        self.has_children = class_object['has_children']
        self.has_only_math = class_object['has_only_math']
        self.num_non_std_children = class_object['num_non_std_children']
        self.num_children = class_object['num_children']
        self.std_base = class_object['std_base']

        self.required = 'false'
        if 'is_doc_plugin' in class_object:
            if class_object['reqd']:
                self.required = 'true'

        self.version_attributes = []
        if 'num_versions' in class_object and class_object['num_versions'] > 1:
            self.has_multiple_versions = True
            for i in range(0, class_object['num_versions']):
                self.version_attributes.append(
                    query.get_version_attributes(class_object['attribs'], i))
        else:
            self.has_multiple_versions = False

        self.lv_info = lv_info
        self.document = False
        if 'document' in class_object:
            self.document = class_object['document']

        # useful variables
        if not self.is_cpp_api and self.is_list_of:
            self.struct_name = self.object_child_name
        else:
            self.struct_name = self.object_name
        self.abbrev_parent = strFunctions.abbrev_name(self.object_name)
        if self.is_cpp_api is False:
            self.true = '@c 1 (true)'
            self.false = '@c 0 (false)'
        else:
            self.true = '@c true'
            self.false = '@c false'

        # status
        if self.is_cpp_api:
            if self.is_list_of:
                self.status = 'cpp_list'
            else:
                self.status = 'cpp_not_list'
        else:
            if self.is_list_of:
                self.status = 'c_list'
            else:
                self.status = 'c_not_list'

    ########################################################################

    # Functions for writing renamesidref

    # function to write rename_sid_ref
    def write_rename_sidrefs(self):
        # only write is not list of and has sidrefs
        if not self.status == 'cpp_not_list':
            return
        elif len(self.sid_refs) == 0 and len(self.unit_sid_refs) == 0\
                and not self.has_math:
            return

        # create comment parts
        title_line = '@copydoc doc_renamesidref_common'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'renameSIdRefs'
        return_type = 'void'
        arguments = ['const std::string& oldid', 'const std::string& newid']

        # create the function implementation
        code = []
        for i in range(0, len(self.sid_refs)):
            ref = self.sid_refs[i]
            implementation = ['isSet{0}() && {1} == '
                              'oldid'.format(ref['capAttName'],
                                             ref['memberName']),
                              'set{0}(newid)'.format(ref['capAttName'])]
            code.append(dict({'code_type': 'if', 'code': implementation}))
        for i in range(0, len(self.unit_sid_refs)):
            ref = self.unit_sid_refs[i]
            implementation = ['isSet{0}() && {1} == '
                              'oldid'.format(ref['capAttName'],
                                             ref['memberName']),
                              'set{0}(newid)'.format(ref['capAttName'])]
            code.append(dict({'code_type': 'if', 'code': implementation}))
        if self.has_math:
            implementation = ['isSetMath()',
                              'mMath->renameSIdRefs(oldid, newid)']
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

    ########################################################################

    # Functions for writing get element/typecode functionss

    # function to write getElement
    def write_get_element_name(self):
        if not self.is_cpp_api:
            return
        # create comment parts
        if self.override_name:
            name = self.element_name
        else:
            name = strFunctions.lower_first(self.object_name)
        title_line = 'Returns the XML element name of this {0} object.'\
            .format(self.object_name,)
        params = ['For {0}, the XML element name is always @c '
                  '\"{1}\".'.format(self.object_name, name)]
        return_lines = ['@return the name of this element, i.e. @c \"{0}\"'
                        '.'.format(name)]
        additional = []

        # create the function declaration
        arguments = []
        function = 'getElementName'
        return_type = 'const std::string&'

        # create the function implementation
        if self.overwrites_children:
            implementation = ['return mElementName']
        else:
            implementation = ['static const string name = \"{0}\"'.format(name),
                              'return name']
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

    # function to write getTypeCode
    def write_get_typecode(self):
        if not self.is_cpp_api:
            return

        # create comment
        lib = global_variables.library_name;
        if self.cap_language == 'SBML' or self.cap_language == 'SEDML':
            lib = 'lib{0}'.format(self.cap_language)

        title_line = 'Returns the {0} type code for this {1} object.'\
            .format(lib, self.object_name)
        params = ['@copydetails doc_what_are_typecodes']
        return_lines = ['@return the {0} type code for this '
                        'object:'.format(self.cap_language)]
        additional = []
        if global_variables.is_package:
            if self.is_list_of:
                line = '@{0}constant{2}{1}_LIST_OF, ' \
                       '{1}TypeCode_t{3}.'.format(self.language, self.cap_language,
                                                 '{', '}')
            else:
                line = '@{0}constant{1}{2}, {3}{4}' \
                       'TypeCode_t{5}.'.format(self.language, '{', self.typecode,
                                              self.cap_language, self.package, '}')
        else:
            if self.is_list_of:
                line = '@{0}constant{2}{1}_LIST_OF, ' \
                       '{4}TypeCode_t{3}.'.format(self.language, self.cap_language,
                                                 '{', '}', global_variables.prefix)
            else:
                line = '@{0}constant{1}{2}, {3}' \
                       'TypeCode_t{4}.'.format(self.language, '{', self.typecode,
                                              global_variables.prefix, '}')
        return_lines.append(line)
        additional.append('@copydetails doc_warning_typecodes_not_unique')
        if not self.is_list_of:
            additional.append(' ')
            additional.append('@see getElementName()')
            if global_variables.is_package:
                additional.append('@see getPackageName()')

        # create function declaration
        function = 'getTypeCode'
        arguments = []
        return_type = 'int'

        # create the function implementation
        if self.is_list_of:
            implementation = ['return {0}_LIST_OF'.format(self.cap_language)]
        else:
            implementation = ['return {0}'.format(self.typecode)]
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

    # function to write getTypeCode
    def write_get_item_typecode(self):
        # only needed for cpp list of class
        if not self.status == 'cpp_list':
            return
        # create comment
        title_line = 'Returns the lib{0} type code for the {0} objects ' \
                     'contained in this {1} object.'.format(self.cap_language,
                                                            self.object_name)
        params = ['@copydetails doc_what_are_typecodes']
        return_lines = ['@return the {0} typecode for the '
                        'objects contained in this '
                        '{1}:'.format(self.cap_language, self.object_name)]
        additional = []
        if global_variables.is_package:
            line = '@{0}constant{1}{2}, {3}{4}TypeCode_t{5}.' \
                   ''.format(self.language, '{', self.typecode, self.cap_language,
                             self.package, '}')
        else:
            line = '@{0}constant{1}{2}, {3}TypeCode_t{4}.'.format(self.language, '{', self.typecode,
                                                                  global_variables.prefix, '}')
        return_lines.append(line)
        additional.append('@copydetails doc_warning_typecodes_not_unique')
        additional.append(' ')
        additional.append('@see getElementName()')
        if global_variables.is_package:
            additional.append('@see getPackageName()')

        # create function declaration
        function = 'getItemTypeCode'
        arguments = []
        return_type = 'int'

        # create the function implementation
        implementation = ['return {0}'.format(self.typecode)]
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

    # Functions for writing checking necessary children status

    # function to write hasRequiredAttributes
    def write_has_required_attributes(self):
        if self.has_std_base and len(self.attributes) == 0:
            return

        # create comment parts
        title_line = 'Predicate returning {0} if all the required ' \
                     'attributes for this {1} object have been set.'\
            .format(self.true, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(self.abbrev_parent, self.object_name))

        return_lines = ['@return {0} to indicate that all the required '
                        'attributes of this {1} have been set, otherwise '
                        '{2} is returned.'.format(self.true, self.object_name,
                                                  self.false)]
        reqd_atts_names = []
        additional = []
        for i in range(0, len(self.attributes)):
            if self.attributes[i]['reqd']:
                att_name = self.attributes[i]['xml_name']
                reqd_atts_names.append(att_name)
        if len(reqd_atts_names) > 0:
            additional = [' ', '@note The required attributes for the {0} object'
                               ' are:'.format(self.object_name)]
            for reqd_atts_name in reqd_atts_names:
                additional.append('@li \"{0}\"'.format(reqd_atts_name))

        # create the function declaration
        if self.is_cpp_api:
            function = 'hasRequiredAttributes'
            return_type = 'bool'
        else:
            function = '{0}_hasRequiredAttributes'.format(self.class_name)
            return_type = 'int'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(self.object_name, self.abbrev_parent))

        # create the function implementation
        if self.is_cpp_api:
            if self.has_std_base:
                all_present = 'true'
            else:
                all_present = '{0}::hasRequired' \
                              'Attributes()'.format(self.base_class)
            code = [dict({'code_type': 'line',
                          'code': ['bool all'
                                   'Present = {0}'.format(all_present)]})]
            if self.has_multiple_versions:
                [reqd_atts, reqd_versions] = self.get_multiple_version_info()
                if len(reqd_versions) > 0:
                    implementation = ['unsigned int level = getLevel()', 'unsigned int version = getVersion()',
                                      'unsigned int pkgVersion = getPackageVersion()']
                    code.append(self.create_code_block('line', implementation))

                for att in reqd_atts:
                    implementation = ['isSet{0}() == false'.format(att), 'allPresent = false']
                    code.append(dict({'code_type': 'if', 'code': implementation}))

                for att in reqd_versions:
                    lv_needed = []
                    for i in range(0, len(att['versions'])):
                        if att['versions'][i]:
                            lv_needed.append(i)
                    if len(lv_needed) > 1:
                        line = ''
                        for lv in lv_needed:
                            level = self.lv_info[lv]['core_level']
                            vers = self.lv_info[lv]['core_version']
                            pkg = self.lv_info[lv]['pkg_version']
                            this_line = 'level == {0} && version == {1} && pkgVersion == {2}'.format(level, vers, pkg)
                            line = line + '({0}) || '.format(this_line)
                        length = len(line)
                        line = line[0:length-4]
                    else:
                        level = self.lv_info[lv_needed[0]]['core_level']
                        vers = self.lv_info[lv_needed[0]]['core_version']
                        pkg = self.lv_info[lv_needed[0]]['pkg_version']
                        line = 'level == {0} && version == {1} && pkgVersion == {2}'.format(level, vers, pkg)
                    implementation = ['isSet{0}() == false'.format(att['cap']), 'allPresent = false']
                    nested_if = dict({'code_type': 'if', 'code': implementation})
                    code.append(dict({'code_type': 'if', 'code': [line, nested_if]}))

            else:
                for i in range(0, len(self.attributes)):
                    att = self.attributes[i]
                    if att['reqd']:
                        implementation = ['isSet{0}() == '
                                          'false'.format(att['capAttName']),
                                          'allPresent = false']
                        code.append(dict({'code_type': 'if',
                                          'code': implementation}))
            code.append(dict({'code_type': 'line',
                              'code': ['return allPresent']}))
        else:
            line = ['return ({0} != NULL) ? static_cast<int>({0}->'
                    'hasRequiredAttributes()) : 0'.format(self.abbrev_parent)]
            code = [dict({'code_type': 'line', 'code': line})]

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

    def get_multiple_version_info(self):
        num_versions = len(self.version_attributes)
        reqd_atts = []
        required_attributes = []
        for attribute in self.attributes:
            name = attribute['name']
            reqd_version = []
            for i in range(0, num_versions):
                reqd_version.append(self.get_reqd_in_version(i, name))
            if True in reqd_version:
                if False in reqd_version:
                    # sometimes required sometimes not
                    required_attributes.append(dict({'name': name, 'versions': reqd_version, 'cap': attribute['capAttName']}))
                else:
                    # always requiresd
                    reqd_atts.append(attribute['capAttName'])
        return [reqd_atts, required_attributes]

    def get_reqd_in_version(self, i, name):
        match = False
        j = 0
        while not match and j < len(self.version_attributes[i]):
            att = self.version_attributes[i][j]
            if att['name'] == name:
                match = True
                break
            j = j + 1
        if not match:
            return False
        else:
            return self.version_attributes[i][j]['reqd']

    # function to write hasRequiredElements
    def write_has_required_elements(self):
        if not self.has_children:
            return
        has_reqd_children = False
        # if this is not a derived class and has no required elements dont write the function
        if not self.has_std_base:
            has_reqd_children = True
        if not has_reqd_children:
            for att in self.child_elements:
                if att['reqd']:
                    has_reqd_children = True
            for att in self.child_lo_elements:
                if att['reqd']:
                    has_reqd_children = True
        if not has_reqd_children:
            return

        # create comment parts
        title_line = 'Predicate returning {0} if all the required ' \
                     'elements for this {1} object have been set.'\
            .format(self.true, self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(self.abbrev_parent, self.object_name))

        return_lines = ['@return {0} to indicate that all the required '
                        'elements of this {1} have been set, otherwise '
                        '{2} is returned.'.format(self.true, self.object_name,
                                                  self.false)]
        additional = [' ', '@note The required elements for the {0} object'
                           ' are:'.format(self.object_name)]
        for i in range(0, len(self.child_elements)):
            if self.child_elements[i]['reqd']:
                additional.append('@li \"{0}\"'
                                  .format(self.child_elements[i]['name']))
        for i in range(0, len(self.child_lo_elements)):
            if self.child_lo_elements[i]['reqd']:
                additional.append('@li \"{0}\"'
                                  .format(self.child_lo_elements[i]['name']))

        # create the function declaration
        if self.is_cpp_api:
            function = 'hasRequiredElements'
            return_type = 'bool'
        else:
            function = '{0}_hasRequiredElements'.format(self.class_name)
            return_type = 'int'

        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0} * {1}'
                             .format(self.object_name, self.abbrev_parent))
        # create the function implementation
        if self.is_cpp_api:
            if self.has_std_base:
                all_present = 'true'
            else:
                all_present = '{0}::hasRequired' \
                              'Elements()'.format(self.base_class)
            code = [dict({'code_type': 'line',
                          'code': ['bool allPresent '
                                   '= {0}'.format(all_present)]})]
            for i in range(0, len(self.child_elements)):
                att = self.child_elements[i]
                if att['reqd']:
                    implementation = ['isSet{0}() == '
                                      'false'.format(att['capAttName']),
                                      'allPresent = false']
                    code.append(dict({'code_type': 'if',
                                      'code': implementation}))
            for i in range(0, len(self.child_lo_elements)):
                att = self.child_lo_elements[i]
                if att['reqd']:
                    name = strFunctions.upper_first(att['pluralName'])
                    implementation = ['getNum{0}() == '
                                      '0'.format(name),
                                      'allPresent = false']
                    code.append(dict({'code_type': 'if',
                                      'code': implementation}))
            code.append(dict({'code_type': 'line',
                              'code': ['return allPresent']}))
        else:
            line = ['return ({0} != NULL) ? static_cast<int>({0}->'
                    'hasRequiredElements()) : 0'.format(self.abbrev_parent)]
            code = [dict({'code_type': 'line', 'code': line})]

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

    # Functions for writing general functions: writeElement, accept
    #                                setDocument, write (if we have an array)

    def has_child_elements(self):
        if self.child_elements and len(self.child_elements) > 0:
            return True
        elif self.child_lo_elements and len(self.child_lo_elements) > 0:
            return True
        else:
            return False

    # function to write writeElement
    def write_write_elements(self):
        if not self.status == 'cpp_not_list':
            if not(self.status == 'cpp_list' and len(self.child_elements) > 0):
                return
        elif self.is_doc_plugin and not self.has_child_elements():
            return

        # create comment parts
        title_line = 'Write any contained elements'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'writeElements'
        return_type = 'void'
        if global_variables.is_package:
            arguments = ['XMLOutputStream& stream']
        else:
            arguments = ['LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream']

        # create the function implementation
        base = self.base_class
        if not self.is_plugin:
            code = [dict({'code_type': 'line',
                          'code': ['{0}::writeElements(stream)'.format(base)]})]
        else:
            code = []
        for i in range(0, len(self.child_elements)):
            att = self.child_elements[i]
            if att['element'] == 'ASTNode':
                if global_variables.is_package:
                    line = ['writeMathML(getMath(), stream, get{0}'
                            'Namespaces())'.format(global_variables.prefix)]
                else:
                    line = ['writeMathML(getMath(), stream, NULL)']
            elif att['element'] == 'XMLNode':
                line = ['stream.startElement(\"{0}\")'.format(att['name']),
                        'stream << *{0}'.format(att['memberName']),
                        'stream.endElement(\"{0}\")'.format(att['name'])]
            else:
                line = ['{0}->write(stream)'.format(att['memberName'])]
            implementation = ['isSet{0}() == true'.format(att['capAttName'])]
            implementation += line
            code.append(dict({'code_type': 'if',
                              'code': implementation}))
        for i in range(0, len(self.child_lo_elements)):
            att = self.child_lo_elements[i]
            if self.is_plugin:
                name = att['pluralName'][6:]
            else:
                # hack for spatial csg elements
                if self.package == 'Spatial' and \
                        att['pluralName'].startswith('csg'):
                    name = 'CSG' + att['pluralName'][3:]
                else:
                    if 'used_child_name' in att:
                        name = strFunctions.upper_first(strFunctions.plural(att['used_child_name']))
                    elif 'xml_name' in att and att['xml_name'] != att['name']:
                        name = strFunctions.upper_first(strFunctions.plural(att['xml_name']))
                    else:
                        name = strFunctions.remove_prefix(strFunctions.upper_first(att['pluralName']))
                    # fix for sbgn but may need to sort
                    #name = strFunctions.plural(att['capAttName'])
            if att['type'] == 'inline_lo_element':
                implementation = ['unsigned int i = 0; i < getNum{0}(); i++'.format(name),
                                  'get{0}(i)->write(stream)'.format(strFunctions.singular(name))]
                code.append(dict({'code_type': 'for',
                                  'code': implementation}))
            else:
                qualifier = '.'
                if 'recursive_child' in att and att['recursive_child']:
                    qualifier = '->'
                implementation = ['getNum{0}() > '
                                  '0'.format(name),
                                  '{0}{1}write(stream)'.format(att['memberName'], qualifier)]
                code.append(dict({'code_type': 'if',
                                  'code': implementation}))
        if not self.is_plugin and global_variables.is_package:
            code.append(dict({'code_type': 'line',
                              'code': ['{0}::writeExtension'
                                       'Elements'
                                       '(stream)'.format(self.std_base)]}))
        # look and see if we have a vector attribute which would need
        # to be written here
        for attrib in self.attributes:
            if 'isVector' in attrib and attrib['isVector']:
                code.append(self.write_write_vector(attrib))
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

    def write_write_vector(self, attrib):
        implementation = ['std::vector<{0}>::const_iterator it = {1}.begin(); '
                          'it != {1}.end(); ++it'.format(attrib['element'], attrib['memberName']),
                          'stream.startElement(\"{0}\")'.format(attrib['name']),
                          'stream.setAutoIndent(false)',
                          'stream << \" \" << *it << \"  \"',
                          'stream.endElement(\"{0}\")'.format(attrib['name']),
                          'stream.setAutoIndent(true)']
        nested_for = self.create_code_block('for', implementation)
        implementation = ['has{0}()'.format(strFunctions.plural(attrib['capAttName'])),
                          nested_for]
        code = self.create_code_block('if', implementation)
        return code

    # function to write accept
    def write_accept(self):
        if not self.status == 'cpp_not_list':
            return

        # create comment parts
        title_line = 'Accepts the given ' \
                     '{0}Visitor'.format(global_variables.prefix)
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'accept'
        return_type = 'bool'
        arguments = ['{0}Visitor& v'.format(global_variables.prefix)]

        # create the function implementation
        simple = False
        # cover cases where a doc plugin is used (no children but not simple)
        # or there are children but they are non std based children (simple)
        if self.has_children:
            if self.num_children == self.num_non_std_children:
                simple = True
        else:
            if not self.is_plugin:
                simple = True
        if not global_variables.is_package:
            implementation = ['return false']
            code = [dict({'code_type': 'line', 'code': implementation})]
        elif simple:
            implementation = ['return v.visit(*this)']
            code = [dict({'code_type': 'line', 'code': implementation})]
        else:
            if not self.is_plugin:
                code = [dict({'code_type': 'line',
                              'code': ['v.visit(*this)']})]
            else:
                obj = strFunctions.abbrev_name(self.ext_class)
                implementation = ['const {0}* {1} = static_cast<const {0}*>'
                                  '(this->getParent{2}Object()'
                                  ')'.format(self.ext_class, obj,
                                             self.cap_language),
                                  'v.visit(*{0})'.format(obj),
                                  'v.leave(*{0})'.format(obj)]
                code = [self.create_code_block('line', implementation)]
            for i in range(0, len(self.child_elements)):
                elem = self.child_elements[i]
                implementation = ['{0} != NULL'.format(elem['memberName']),
                                  '{0}->accept(v)'.format(elem['memberName'])]
                code.append(dict({'code_type': 'if',
                                  'code': implementation}))
            for i in range(0, len(self.child_lo_elements)):
                att = self.child_lo_elements[i]
                qualifier = '.'
                if 'recursive_child' in att and att['recursive_child']:
                    qualifier = '->'
                implementation = ['{0}{1}accept(v)'.format(att['memberName'], qualifier)]
                code.append(dict({'code_type': 'line',
                                  'code': implementation}))
            if not self.is_plugin:
                code.append(dict({'code_type': 'line',
                                  'code': ['v.leave(*this)', 'return true']}))
            else:
                code.append(self.create_code_block('line', ['return true']))

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

    # function to write setDocument
    def write_set_document(self):
        if not self.status == 'cpp_not_list':
            return
        elif self.is_doc_plugin and not self.has_child_elements():
            return

        # create comment parts
        title_line = 'Sets the parent ' \
                     '{0}'.format(global_variables.document_class)
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'set{0}'.format(global_variables.document_class)
        return_type = 'void'
        arguments = ['{0}* d'.format(global_variables.document_class)]

        # create the function implementation
        if self.base_class:
            line = '{0}::set{1}(d)'.format(self.base_class,
                                           global_variables.document_class)
            implementation = [line]
            code = [dict({'code_type': 'line', 'code': implementation})]
        else:
            code = []
        if self.has_children and not self.has_only_math:
            for i in range(0, len(self.child_elements)):
                att = self.child_elements[i]
                if 'is_ml' in att and att['is_ml']:
                    continue
                else:
                    implementation = ['{0} != NULL'.format(att['memberName']),
                                      '{0}->{1}'
                                      '(d)'.format(att['memberName'], function)]
                    code.append(self.create_code_block('if', implementation))
            for i in range(0, len(self.child_lo_elements)):
                att = self.child_lo_elements[i]
                symbol ='.'
                if 'recursive_child' in att and att['recursive_child']:
                    symbol = '->'
                implementation = ['{0}{2}{1}'
                                  '(d)'.format(att['memberName'], function, symbol)]
                code.append(dict({'code_type': 'line',
                                  'code': implementation}))

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

    # function to write_write if there is an array
    def write_write(self):
        if not self.has_array:
            return
        elif not self.status == 'cpp_not_list':
            return

        # create comment parts
        title_line = 'used to write arrays'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'write'
        return_type = 'void'
        if global_variables.is_package:
            arguments = ['XMLOutputStream& stream']
        else:
            arguments = ['LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream']

        # create the function implementation
        # find the array attribute
        name = ''
        member = ''
        array_type = ''
        for attrib in self.attributes:
            if attrib['isArray']:
                name = attrib['capAttName']
                member = attrib['memberName']
                array_type = attrib['element']
            if array_type == 'int':
                array_type = 'long'
        code = [self.create_code_block('line',
                                       ['stream.startElement(getElementName(), '
                                        'getPrefix())',
                                        'writeAttributes(stream)'])]
        nested_for = self.create_code_block(
            'for', ['int i = 0; i < m{0}Length; ++i'.format(name),
                    'stream << ({0}){1}[i] << \" \"'
                    ''.format(array_type, member)])
        implementation = ['isSet{0}()'.format(name), nested_for]
        code.append(self.create_code_block('if', implementation))
        code.append(self.create_code_block(
            'line', ['stream.endElement(getElementName(), getPrefix())']))

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

    # function to write updateNamespace
    def write_update_ns(self):
        if not self.status == 'cpp_not_list':
            return
        elif not self.has_child_elements():
            return

        # create comment parts
        title_line = 'Updates the namespaces when setLevelVersion is used'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'updateSBMLNamespace'
        return_type = 'void'
        arguments = ['const std::string& package', 'unsigned int level', 'unsigned int version']

        # create the function implementation
        if self.base_class:
            line = '{0}::updateSBMLNamespace(package, level, version)'.format(self.base_class)
            implementation = [line]
            code = [dict({'code_type': 'line', 'code': implementation})]
        else:
            code = []

        if self.has_children and not self.has_only_math:
            for i in range(0, len(self.child_elements)):
                att = self.child_elements[i]
                if 'is_ml' in att and att['is_ml']:
                    continue
                else:
                    implementation = ['{0} != NULL'.format(att['memberName']),
                                      '{0}->{1}'
                                      '(package, level, version)'.format(att['memberName'], function)]
                    code.append(self.create_code_block('if', implementation))
            for i in range(0, len(self.child_lo_elements)):
                att = self.child_lo_elements[i]
                qualifier = '.'
                if 'recursive_child' in att and att['recursive_child']:
                    qualifier = '->'
                implementation = ['{0}{2}{1}'
                                  '(package, level, version)'.format(att['memberName'], function, qualifier)]
                code.append(dict({'code_type': 'line',
                                  'code': implementation}))

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

    # Functions for dealing with packages: enablePackage, connectToChild

    # function to write enable_package
    def write_enable_package(self):
        if not self.status == 'cpp_not_list':
            return
        elif self.is_doc_plugin and not self.has_child_elements():
            return

        # create comment parts
        title_line = 'Enables/disables the given package with this element'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'enablePackageInternal'
        return_type = 'void'
        arguments = ['const std::string& pkgURI',
                     'const std::string& pkgPrefix', 'bool flag']

        # create the function implementation
        code = []
        if not self.is_plugin and self.base_class:
            implementation = ['{0}::enablePackageInternal(pkgURI, pkgPrefix, '
                              'flag)'.format(self.base_class)]
            code = [dict({'code_type': 'line', 'code': implementation})]
        if self.has_children and not self.has_only_math:
            for i in range(0, len(self.child_elements)):
                att = self.child_elements[i]
                if 'is_ml' in att and att['is_ml']:
                    continue
                else:
                    implementation = ['isSet{0}()'.format(att['capAttName']),
                                      '{0}->enablePackageInternal'
                                      '(pkgURI, pkgPrefix, '
                                      'flag)'.format(att['memberName'])]
                    code.append(dict({'code_type': 'if',
                                      'code': implementation}))
            for i in range(0, len(self.child_lo_elements)):
                att = self.child_lo_elements[i]
                qualifier = '.'
                if 'recursive_child' in att and att['recursive_child']:
                    qualifier = '->'
                implementation = ['{0}{1}enablePackageInternal'
                                  '(pkgURI, pkgPrefix, '
                                  'flag)'.format(att['memberName'], qualifier)]
                code.append(dict({'code_type': 'line',
                                  'code': implementation}))

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

    # function to write connectToChild
    def write_connect_to_child(self):
        if not self.is_cpp_api:
            return
        elif not self.has_children:
            return

        # create comment parts
        title_line = 'Connects to child elements'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'connectToChild'
        return_type = 'void'
        arguments = []

        # create the function implementation
        if not self.is_plugin:
            implementation = ['{0}::connectToChild()'.format(self.base_class)]
            code = [dict({'code_type': 'line', 'code': implementation})]
            for i in range(0, len(self.child_elements)):
                att = self.child_elements[i]
                if 'is_ml' in att and att['is_ml']:
                    continue
                else:
                    implementation = ['{0} != NULL'.format(att['memberName']),
                                      '{0}->connectToParent'
                                      '(this)'.format(att['memberName'])]
                    code.append(self.create_code_block('if', implementation))
            for i in range(0, len(self.child_lo_elements)):
                att = self.child_lo_elements[i]
                symbol ='.'
                if 'recursive_child' in att and att['recursive_child']:
                    symbol = '->'
                implementation = ['{0}{1}connectToParent'
                                  '(this)'.format(att['memberName'], symbol)]
                code.append(dict({'code_type': 'line',
                                  'code': implementation}))
        else:
            code = [self.create_code_block('line',
                                           ['connectToParent(getParent'
                                            '{0}Object()'
                                            ')'.format(self.cap_language)])]
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

    # function to write connectToParent
    def write_connect_to_parent(self):
        if not self.is_cpp_api:
            return
        elif not self.has_children:
            return

        # create comment parts
        title_line = 'Connects to parent element'
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        function = 'connectToParent'
        return_type = 'void'
        if self.is_doc_plugin:
            arguments = ['{0}* base'.format(global_variables.baseClass)]
        else:
            arguments = ['{0}* base'.format(self.std_base)]

        # create the function implementation
        implementation = ['{0}::connectToParent(base)'.format(self.base_class)]
        code = [dict({'code_type': 'line', 'code': implementation})]
        for i in range(0, len(self.child_elements)):
            att = self.child_elements[i]
            if 'is_ml' in att and att['is_ml']:
                continue
            else:
                implementation = ['{0} != NULL'.format(att['memberName']),
                                  '{0}->connectToParent'
                                  '(base)'.format(att['memberName'])]
                code.append(self.create_code_block('if', implementation))
        for i in range(0, len(self.child_lo_elements)):
            att = self.child_lo_elements[i]
            symbol ='.'
            if 'recursive_child' in att and att['recursive_child']:
                symbol = '->'
            implementation = ['{0}{1}connectToParent'
                              '(base)'.format(att['memberName'], symbol)]
            code.append(dict({'code_type': 'line',
                              'code': implementation}))

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

    # Functions for when an element has a different XML name

    # function to write setElementName
    def write_set_element_name(self):
        if not self.is_cpp_api:
            return
        if not self.overwrites_children:
            return
        # create comment parts
        title_line = 'Sets the XML name of this {0} object.'\
            .format(self.object_name,)
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        arguments = ['const std::string& name']
        function = 'setElementName'
        return_type = 'void'

        # create the function implementation
        implementation = ['mElementName = name']
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

    # Functions for document plugin

    # function to write is comp flattening done
    def write_is_comp_flat(self):
        if not self.is_doc_plugin:
            return

        # create comment parts
        title_line = 'Predicate indicating whether \'comp\' flattening has ' \
                     'been implemented for the {0} package.' \
                     ''.format(self.package)
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        arguments = []
        function = 'isCompFlatteningImplemented'
        return_type = 'bool'

        # create the function implementation
        code = [dict({'code_type': 'line', 'code': ['return false']})]

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

    # function to write check consistency
    def write_check_consistency(self):
        if not self.is_doc_plugin:
            return

        # create comment parts
        title_line = 'Calls check consistency for any relevant ' \
                     '{0} validators.'.format(self.package)
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        arguments = []
        function = 'checkConsistency'
        return_type = 'unsigned int'

        # create the function implementation
        implementation = ['unsigned int nerrors = 0',
                          'unsigned int total_errors = 0']
        code = [self.create_code_block('line', implementation)]
        implementation = ['{0}* doc = static_cast<{0}*>(this->'
                          'getParent{1}'
                          'Object())'.format(global_variables.document_class,
                                             self.cap_language),
                          '{0}ErrorLog* log = doc->getError'
                          'Log()'.format(self.cap_language)]
        code.append(self.create_code_block('line', implementation))
        implementation = ['unsigned char applicableValidators = '
                          'doc->getApplicableValidators()',
                          'bool id = ((applicableValidators & 0x01) ==0x01)',
                          'bool core = ((applicableValidators & 0x02) ==0x02)']
        code.append(self.create_code_block('line', implementation))
        implementation = ['{0}IdentifierConsistencyValidator '
                          'id_validator'.format(self.package),
                          '{0}ConsistencyValidator '
                          'core_validator'.format(self.package)]
        code.append(self.create_code_block('line', implementation))
        implementation = self.get_validator_block('id')
        code.append(self.create_code_block('if', implementation))
        implementation = self.get_validator_block('core')
        code.append(self.create_code_block('if', implementation))
        code.append(self.create_code_block('line', ['return total_errors']))

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

    # function to write read attributes
    # note not the standard read attributes function; this is specific to
    # the document plugin
    def write_read_attributes(self):
        if not self.is_doc_plugin:
            return

        # sort error names to be used
        error = '{0}AttributeRequiredMustBeBoolean'.format(self.package)
        req_error = '{0}AttributeRequiredMissing'.format(self.package)
        value_error = '{0}AttributeRequiredMustHaveValue'.format(self.package)
        # create comment parts
        title_line = 'Reads the {0} attributes in the top-level ' \
                     'element.'.format(self.package)
        params = []
        return_lines = []
        additional = []

        # create the function declaration
        if global_variables.is_package:
            arguments = ['const XMLAttributes& attributes',
                         'const ExpectedAttributes& expectedAttributes']
        else:
            arguments = ['const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes& attributes',
                         'const LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes& expectedAttributes']
        function = 'readAttributes'
        return_type = 'void'

        # create the function implementation
        implementation = ['get{0}() != NULL && get{0}()->'
                          'getLevel() < '
                          '3'.format(global_variables.document_class),
                          'return']
        code = [dict({'code_type': 'if', 'code': implementation})]
        if global_variables.is_package:
            triple = 'XMLTriple'
        else:
            triple = 'LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple'
        implementation = ['{0}ErrorLog* log = getErrorLog'
                          '()'.format(self.cap_language),
                          'unsigned int numErrs = log->getNumErrors()',
                          '{0} tripleReqd(\"required\", mURI, '
                          'getPrefix())'.format(triple),
                          'bool assigned = attributes.readInto(tripleReqd, '
                          'mRequired)']
        code.append(self.create_code_block('line', implementation))
        implementation = ['log->getNumErrors() == numErrs + 1 && '
                          'log->contains(XMLAttributeTypeMismatch)',
                          'log->remove(XMLAttributeTypeMismatch)',
                          'log->logPackageError(\"{0}\", {1}, '
                          'getPackageVersion(), getLevel(), '
                          'getVersion(), "", getLine(), getColumn())'
                          ''.format(self.package.lower(), error),
                          'else',
                          'log->logPackageError(\"{0}\", {1}, '
                          'getPackageVersion(), getLevel(), '
                          'getVersion(), "", getLine(), getColumn())'
                          ''.format(self.package.lower(), req_error)
                          ]
        nested_if = self.create_code_block('if_else', implementation)
        implementation = ['mRequired != {0}'.format(self.required),
                          'log->logPackageError(\"{0}\", {1}, '
                          'getPackageVersion(), getLevel(), '
                          'getVersion(), "", getLine(), getColumn())'
                          ''.format(self.package.lower(), value_error)
                          ]
        second_nested_if = self.create_code_block('if', implementation)
        implementation = ['assigned == false', nested_if,
                          'else', 'mIsSetRequired = true', second_nested_if]
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

    ########################################################################

    # HELPER FUNCTIONS

    def get_validator_block(self, valid_id):
        bail_if = self.create_code_block('if',
                                         ['log->getNumFailsWithSeverity(LIB{0}'
                                          '_SEV_ERROR) > '
                                          '0'.format(self.cap_language),
                                          'return total_errors'])
        errors_if = self.create_code_block('if',
                                           ['nerrors > 0',
                                            'log->add({0}_validator.get'
                                            'Failures())'.format(valid_id),
                                            bail_if])
        code_block = ['{0}'.format(valid_id),
                      '{0}_validator.init()'.format(valid_id),
                      'nerrors = {0}_validator.validate(*doc)'.format(valid_id),
                      'total_errors += nerrors', errors_if]
        return code_block

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
