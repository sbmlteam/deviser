#!/usr/bin/env python
#
# @file    Constructors.py
# @brief   class for constructors for c++ and c
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


class Constructors():
    """Class for all constructors"""

    def __init__(self, language, is_cpp_api, class_object):
        self.language = language
        self.cap_language = language.upper()
        self.package = class_object['package']
        self.class_name = class_object['name']
        self.is_cpp_api = is_cpp_api
        if is_cpp_api:
            self.object_name = class_object['name']
        else:
            self.object_name = class_object['name'] + '_t'

        self.concretes = class_object['concretes']
        self.base_class = class_object['baseClass']
        self.attributes = query.get_unique_attributes(class_object['attribs'])
        self.is_list_of = False
        if class_object['name'].startswith('ListOf'):
            self.is_list_of = True

        self.has_children = class_object['has_children']
        self.child_elements = class_object['child_elements']
        self.overwrites_children = class_object['overwrites_children']
        if 'elementName' in class_object and class_object['elementName'] != '':
            self.xml_name = \
                strFunctions.lower_first(class_object['elementName'])
        else:
            self.xml_name = strFunctions.lower_first(class_object['name'])
        self.is_plugin = False
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']
        self.is_doc_plugin = False
        if 'is_doc_plugin' in class_object:
            self.is_doc_plugin = class_object['is_doc_plugin']
        self.document = False
        if 'document' in class_object:
            self.document = class_object['document']



    ########################################################################

    # Functions for writing constructors

    # function to write level version constructor
    def write_level_version_constructor(self, index=0):
        if (len(self.concretes) == 0 and index == 0) or index == -1:
            ob_name = self.object_name
            create = 'create'
        elif self.is_cpp_api:
            ob_name = self.object_name
            create = 'create'
        else:
            if index == 0:
                return
            else:
                i = index - 1
            ob_name = '{0} ({1})'.format(self.concretes[i]['element'],
                                       self.object_name)
            create = 'create{0}'.format(self.concretes[i]['element'])
        # create doc string header
        title_line = 'Creates a new {0} using the given {1} Level' \
            .format(ob_name, self.cap_language)
        if global_variables.is_package:
            title_line += ', Version and &ldquo;{0}&rdquo; package ' \
                          'version.'.format(strFunctions.
                                            lower_first(self.package))
        else:
            title_line += ' and @ p version values.'

        params = ['@param level an unsigned int, the {0} Level to '
                  'assign to this {1}.'.format(self.cap_language,
                                             self.object_name),
                  '@param version an unsigned int, the {0} Version to '
                  'assign to this {1}.'.format(self.cap_language,
                                             self.object_name)]
        if global_variables.is_package:
            params.append('@param pkgVersion an unsigned int, the {0} {1} '
                          'Version to assign to this {2}.'
                          .format(self.cap_language, self.package,
                                  self.object_name))

        return_lines = ['@throws {0}Constructor'
                        'Exception'.format(self.cap_language),
                        'Thrown if the given @p level and @p version '
                        'combination, or this kind of {0} object, are either '
                        'invalid or mismatched with respect to the parent '
                        '{1} object.'.format(self.cap_language,
                                             global_variables.document_class),
                        '@copydetails doc_note_setting_lv']
        additional = ''

        # create the function declaration
        if self.is_cpp_api:
            function = self.class_name
            return_type = ''
        else:
            function = '{0}_{1}'.format(self.class_name, create)
            return_type = '{0} *'.format(self.object_name)

        if global_variables.is_package:
            arguments = [
                'unsigned int level = '
                '{0}Extension::getDefaultLevel()'.format(self.package),
                'unsigned int version = '
                '{0}Extension::getDefaultVersion()'.format(self.package),
                'unsigned int pkgVersion = '
                '{0}Extension::getDefaultPackageVersion()'.format(self.package)]
            arguments_no_defaults = ['unsigned int level',
                                     'unsigned int version',
                                     'unsigned int pkgVersion']
        else:
            if self.is_cpp_api:
                arguments = ['unsigned int level = {0}_DEFAULT_'
                             'LEVEL'.format(global_variables.language.upper()),
                             'unsigned int version = {0}_DEFAULT_VERSI'
                             'ON'.format(global_variables.language.upper())]
                arguments_no_defaults = ['unsigned int level',
                                         'unsigned int version']
            else:
                arguments = ['unsigned int level', 'unsigned int version']
                arguments_no_defaults = ['unsigned int level',
                                         'unsigned int version']

        # create the function implementation
        constructor_args = self.write_constructor_args(None)
        if global_variables.is_package:
            if self.is_cpp_api:
                implementation = ['set{0}NamespacesAndOwn(new {1}PkgNamespaces'
                                  '(level, version, '
                                  'pkgVersion))'.format(global_variables.prefix,
                                                        self.package)]
                if self.has_children:
                    implementation.append('connectToChild()')
            else:
                if index == 0 or index == -1:
                    name = self.class_name
                else:
                    name = self.concretes[index-1]['element']
                implementation = ['return new {0}(level, version, '
                                  'pkgVersion)'.format(name)]
        else:
            if self.is_cpp_api:
                implementation = ['set{0}NamespacesAndOwn(new {0}Namespaces('
                                  'level, '
                                  'version))'.format(global_variables.prefix)]
                if self.document:
                    implementation.append('setLevel(level)')
                    implementation.append('setVersion(version)')
                    implementation.append('set{0}Document(this)'.format(global_variables.prefix))
                if self.has_children:
                    implementation.append('connectToChild()')
            else:
                implementation = ['return new {0}(level, '
                                  'version)'.format(self.class_name)]

        code = [dict({'code_type': 'line', 'code': implementation})]

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name,
                     'implementation': code,
                     'args_no_defaults': arguments_no_defaults,
                     'constructor_args': constructor_args})

    # function to write namespace constructor
    def write_namespace_constructor(self, index=0):
        if len(self.concretes) == 0 and index == 0:
            ob_name = self.object_name
            create = 'create'
        elif self.is_cpp_api:
            ob_name = self.object_name
            create = 'create'
        else:
            if index == 0:
                return
            else:
                i = index - 1
            ob_name = '{0} ({1})'.format(self.concretes[i]['element'],
                                       self.object_name)
            create = 'create{0}'.format(self.concretes[i]['element'])
        # create doc string header
        title_line = 'Creates a new {0} using the given'\
            .format(ob_name)
        if global_variables.is_package:
            title_line = title_line + ' {0}PkgNamespaces object.' \
                .format(self.package)
        else:
            title_line = title_line + ' {0}Namespaces object @p {1}ns.' \
                .format(global_variables.prefix, self.language)

        params = []
        if global_variables.is_package:
            params.append('@param {0}ns the {1}PkgNamespaces object.'
                          .format(self.package.lower(), self.package))
        else:
            params.append('@param {0}ns the {1}Namespaces object.'
                          .format(self.language, global_variables.prefix))

        return_lines = ['@throws {0}Constructor'
                        'Exception'.format(self.cap_language),
                        'Thrown if the given @p level and @p version '
                        'combination, or this kind of {0} object, are either '
                        'invalid or mismatched with respect to the parent '
                        '{1} object.'.format(self.cap_language,
                                             global_variables.document_class),
                        '@copydetails doc_note_setting_lv']
        additional = ''

        # create the function declaration
        if self.is_cpp_api:
            function = self.class_name
            return_type = ''
        else:
            function = '{0}_{1}WithNS'.format(self.class_name, create)
            return_type = '{0} *'.format(self.object_name)

        arguments = []

        if global_variables.is_package:
            if self.is_cpp_api:
                arguments.append('{0}PkgNamespaces *{1}ns'
                                 .format(self.package, self.package.lower()))
            else:
                arguments.append('{0}PkgNamespaces_t *{1}ns'
                                 .format(self.package, self.package.lower()))
            ns = '{0}ns'.format(self.package.lower())
        else:
            if self.is_cpp_api:
                arguments.append('{0}Namespaces *{1}ns'
                                 .format(global_variables.prefix,
                                         self.language))
            else:
                arguments.append('{0}Namespaces_t *{1}ns'
                                 .format(global_variables.prefix,
                                         self.language))
            ns = '{0}ns'.format(self.language)

        # create the function implementation
        constructor_args = self.write_constructor_args(ns)
#        if global_variables.is_package:
        implementation = ['setElementNamespace({0}'
                          '->getURI())'.format(ns)]
        if self.document:
            if global_variables.has_level_version:
                implementation.append('setLevel({0}->getLevel())'.format(ns))
                implementation.append('setVersion({0}->getVersion())'.format(ns))
            implementation.append('set{0}(this)'.format(global_variables.document_class))

        if self.has_children:
            implementation.append('connectToChild()')
        if global_variables.is_package and not self.is_list_of:
            implementation.append('loadPlugins({0}ns)'
                                  .format(self.package.lower()))
        # else:
        #     implementation = ['set{0}NamespacesAndOwn(new {0}Namespaces'
        #                       '(level, '
        #                       'version))'.format(global_variables.prefix)]
        code = [dict({'code_type': 'line', 'code': implementation})]

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name,
                     'implementation': code,
                     'constructor_args': constructor_args})

    # function to write general constructor
    def write_constructor(self, index=0):
        if len(self.concretes) == 0 and index == 0:
            ob_name = self.object_name
            create = 'create'
        elif self.is_cpp_api:
            ob_name = self.object_name
            create = 'create'
        else:
            if index == 0:
                return
            else:
                i = index - 1
            ob_name = '{0} ({1})'.format(self.concretes[i]['element'],
                                       self.object_name)
            create = 'create{0}'.format(self.concretes[i]['element'])
        # create doc string header
        title_line = 'Creates a new {0} instance.'.format(ob_name)
        params = []

        return_lines = []
        additional = ''

        # create the function declaration
        if self.is_cpp_api:
            function = self.class_name
            return_type = ''
        else:
            function = '{0}_{1}'.format(self.class_name, create)
            return_type = '{0} *'.format(self.object_name)

        arguments = []

        # create the function implementation
        code = [dict({'code_type': 'blank', 'code': []})]

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name,
                     'implementation': code})

    # function to write uri constructor for plugins
    def write_uri_constructor(self):
        ob_name = self.object_name
        package = self.package.lower()
        up_package = strFunctions.upper_first(self.package)
        # create doc string header
        title_line = 'Creates a new {0} using the given uri, prefix and ' \
                     'package namespace.'.format(ob_name)
        params = ['@param uri a string, representing the uri of the package.',
                  '@param prefix a string, the prefix to be used.',
                  '@param {0}ns a pointer to the {1}PkgNamespaces object to '
                  'be used.'.format(package, up_package)]

        return_lines = []
        additional = ''

        # create the function declaration
        function = self.class_name
        return_type = ''

        arguments = ['const std::string& uri', 'const std::string& prefix',
                     '{0}PkgNamespaces* '
                     '{1}ns'.format(up_package, package)]

        ns = '{0}ns'.format(package)
        constructor_args = self.write_constructor_args(ns)
        # create the function implementation
        if self.is_doc_plugin or not self.has_children:
            code = []
        else:
            code = [dict({'code_type': 'line', 'code': ['connectToChild()']})]

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name,
                     'implementation': code,
                     'constructor_args': constructor_args})

    # function to write copy constructor
    def write_copy_constructor(self):
        # do not write for C API
        if self.is_cpp_api is False:
            return
        # create doc string header
        title_line = 'Copy constructor for {0}.'.format(self.object_name)
        params = ['@param orig the {0} instance to copy.'.format(
            self.object_name)]
        return_lines = []
        additional = []
        # create function decl
        function = '{0}'.format(self.object_name)
        return_type = ''
        arguments = ['const {0}& orig'.format(self.object_name)]
        # create the function implementation
        constructor_args = self.write_copy_constructor_args(self)
        code = []
        clone = 'clone'
        for i in range(0, len(self.attributes)):
            if self.attributes[i]['isArray']:
                line = self.write_set_array(i)
                code.append(self.create_code_block('line', line))
        for i in range(0, len(self.child_elements)):
            element = self.child_elements[i]
            member = element['memberName']
            if element['element'] == 'ASTNode':
                clone = 'deepCopy'
            implementation = ['orig.{0} != NULL'.format(member),
                              '{0} = orig.{0}->{1}()'.format(member,
                                                             clone)]
            code.append(self.create_code_block('if', implementation))
        if self.document:
            implementation = ['set{0}(this)'.format(global_variables.document_class)]
            code.append(dict({'code_type': 'line', 'code': implementation}))
        if self.has_children:
            implementation = ['connectToChild()']
            code.append(dict({'code_type': 'line', 'code': implementation}))
        else:
            implementation = ['']
            code.append(dict({'code_type': 'blank', 'code': implementation}))

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name,
                     'implementation': code,
                     'constructor_args': constructor_args})

    # function to write assignment operator
    def write_assignment_operator(self):
        # do not write for C API
        if self.is_cpp_api is False:
            return
        # create doc string header
        title_line = 'Assignment operator for {0}.'.format(self.object_name)
        params = ['@param rhs the {0} object whose values are to be used '
                  'as the basis of the assignment.'.format(self.object_name)]
        return_lines = []
        additional = []
        function = 'operator='.format(self.object_name)
        return_type = '{0}&'.format(self.object_name)
        arguments = ['const {0}& rhs'.format(self.object_name)]
        # create the function implementation
        args = ['&rhs != this'] + self.write_assignment_args(self)
        clone = 'clone'
        for i in range(0, len(self.child_elements)):
            element = self.child_elements[i]
            member = element['memberName']
            args += ['delete {0}'.format(member)]
            if element['element'] == 'ASTNode':
                clone = 'deepCopy'
            implementation = ['rhs.{0} != NULL'.format(member),
                              '{0} = rhs.{0}->{1}()'.format(member,
                                                            clone),
                              'else', '{0} = NULL'.format(member)]
            args += [self.create_code_block('if_else', implementation)]
        implementation = args
        if self.has_children:
            implementation.append('connectToChild()')
        if self.document:
            implementation.append('set{0}(this)'.format(global_variables.document_class))

        implementation2 = ['return *this']
        code = [dict({'code_type': 'if', 'code': implementation}),
                dict({'code_type': 'line', 'code': implementation2})]

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name,
                     'implementation': code})

    # function to write clone
    def write_clone(self):
        abbrev_object = strFunctions.abbrev_name(self.class_name)
        # create doc string header
        title_line = 'Creates and returns a deep copy of this {0} object.'\
            .format(self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(abbrev_object, self.object_name))
        return_lines = ['@return a (deep) copy of this {0} object.'.format(
            self.object_name)]
        additional = []
        if self.is_cpp_api:
            function = 'clone'
        else:
            function = '{0}_clone'.format(self.class_name)
        return_type = '{0}*'.format(self.object_name)
        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {0}* {1}'.format(self.object_name,
                                                   abbrev_object))
        # create the function implementation
        if self.is_cpp_api:
            implementation = ['return new {0}(*this)'.format(self.object_name)]
            code_type = 'line'
        else:
            implementation = ['{0} != NULL'.format(abbrev_object),
                              'return static_cast<{0}*>({1}->'
                              'clone())'.format(self.object_name,
                                                abbrev_object),
                              'else', 'return NULL']
            code_type = 'if_else'
        code = [self.create_code_block(code_type, implementation)]

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.object_name,
                     'implementation': code})

    # function to write destructor
    def write_destructor(self):
        abbrev_object = strFunctions.abbrev_name(self.class_name)
        # create doc string header
        if self.is_cpp_api:
            title_line = 'Destructor for {0}.'.format(self.object_name)
        else:
            title_line = 'Frees this {0} object.'.format(self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {0} the {1} structure.'
                          .format(abbrev_object, self.object_name))
        return_lines = []
        additional = []
        if self.is_cpp_api:
            function = '~{0}'.format(self.object_name)
            return_type = ''
        else:
            function = '{0}_free'.format(self.class_name)
            return_type = 'void'
        arguments = []
        if not self.is_cpp_api:
            arguments.append('{0}* {1}'.format(self.object_name, abbrev_object))
        # create the function implementation
        if self.is_cpp_api:
            implementation = []
            code = []
            for attrib in self.attributes:
                if attrib['isArray']:
                    member = attrib['memberName']
                    code.append(self.create_code_block(
                        'if', ['{0} != NULL'.format(member),
                               'delete [] {0}'.format(member)]))
                    code.append(self.create_code_block(
                        'line', ['{0} = NULL'.format(member)]))
            for i in range(0, len(self.child_elements)):
                element = self.child_elements[i]
                member = element['memberName']
                implementation.append('delete {0}'.format(member))
                implementation.append('{0} = NULL'.format(member))
            if len(implementation) > 0:
                code.append(self.create_code_block('line', implementation))
        else:
            implementation = ['{0} != NULL'.format(abbrev_object),
                              'delete {0}'.format(abbrev_object)]
            code = [self.create_code_block('if', implementation)]

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.object_name,
                     'implementation': code})

    ########################################################################

    # HELPER FUNCTIONS

    def write_constructor_args(self, ns):
        if ns is None:
            constructor_args = [': {0}(level, version)'.format(self.base_class)]
            if global_variables.is_package:
                parameters = 'level, version, pkgVersion'
            else:
                parameters = 'level, version'
        elif ns is not None and self.is_plugin:
            constructor_args = [': {0}(uri, prefix, '
                                '{1})'.format(self.base_class, ns)]
            parameters = '{0}'.format(ns)
        else:
            if global_variables.is_package:
                constructor_args = [': {0}({1})'.format(self.base_class, ns)]
                parameters = '{0}ns'.format(self.package.lower())
            else:
                constructor_args = [': {0}({1})'.format(self.base_class, ns)]
                parameters = '{0}'.format(ns)
        if not self.base_class:
            constructor_args = []
            sep = ':'
        else:
            sep = ','
        for attrib in self.attributes:
            if attrib['attType'] == 'lo_element':
                constructor_args.append('{0} {1} '
                                        '({2})'.format(sep,
                                                      attrib['memberName'],
                                                      parameters))
                sep = ','
            elif 'isVector' in attrib and attrib['isVector']:
                constructor_args.append('{0} {1} '
                                        '()'.format(sep, attrib['memberName']))
                sep = ','
            else:
                constructor_args.append('{0} {1} '
                                        '({2})'.format(sep, attrib['memberName'],
                                                      attrib['default']))
                sep = ','
            if attrib['isNumber'] or attrib['attType'] == 'boolean':
                constructor_args.append(', mIsSet{0} (false)'
                                        .format(attrib['capAttName']))
        if self.overwrites_children:
            constructor_args.append('{0} mElementName(\"'
                                    '{1}\")'.format(sep, self.xml_name))
        return constructor_args

    @staticmethod
    def write_copy_constructor_args(self):
        sep = ':'
        if self.base_class:
            constructor_args = ['{0} {1}( orig )'.format(sep, self.base_class)]
            sep = ','
        else:
            constructor_args = []
        for attrib in self.attributes:
            if attrib['isArray']:
                constructor_args.append('{0} {1} ( NULL )'
                                        .format(sep, attrib['memberName']))
                sep = ','
            elif attrib['type'] != 'element' and attrib['element'] != 'ASTNode':
                constructor_args.append('{1} {0} ( orig.{0} )'
                                        .format(attrib['memberName'], sep))
                sep = ','
                if attrib['isNumber'] or attrib['attType'] == 'boolean':
                    constructor_args.append('{1} mIsSet{0} ( orig.mIsSet{0} )'
                                            .format(attrib['capAttName'], sep))
                    sep = ','
            else:
                constructor_args.append('{0} {1} ( NULL )'
                                        .format(sep, attrib['memberName']))
                sep = ','
        if self.overwrites_children:
            constructor_args.append('{0} mElementName '
                                    '( orig.mElementName )'.format(sep))

        return constructor_args

    @staticmethod
    def write_assignment_args(self):
        if self.base_class:
            constructor_args = ['{0}::operator=(rhs)'.format(self.base_class)]
        else:
            constructor_args = []
        for attrib in self.attributes:
            if attrib['isArray']:
                member = attrib['memberName']
                length = strFunctions.upper_first(attrib['name'])
                constructor_args.append('{0} = NULL'.format(member))
                constructor_args.append('set{0}(rhs.{1}, '
                                        'rhs.{1}Length)'.format(length, member))
            elif attrib['type'] != 'element':
                constructor_args.append('{0} = rhs.{0}'
                                        .format(attrib['memberName']))
                if attrib['isNumber'] or attrib['attType'] == 'boolean':
                    constructor_args.append('mIsSet{0} = rhs.mIsSet{0}'
                                            .format(attrib['capAttName']))
        if self.overwrites_children:
            constructor_args.append('mElementName = rhs.mElementName')
        return constructor_args

    def write_set_array(self, index):
        name = self.attributes[index]['capAttName']
        member = self.attributes[index]['memberName']
        length = member + 'Length'
        line = ['set{0}(orig.{1}, orig.{2})'.format(name, member, length)]
        return line

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
