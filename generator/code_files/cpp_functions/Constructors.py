#!/usr/bin/env python
#
# @file    Constructors.py
# @brief   class for constructors for c++ and c
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
        self.xml_name = strFunctions.lower_first(class_object['name'])
        self.is_plugin = False
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']
        self.is_doc_plugin = False
        if 'is_doc_plugin' in class_object:
            self.is_doc_plugin = class_object['is_doc_plugin']

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
            ob_name = '{} ({})'.format(self.concretes[i]['element'],
                                       self.object_name)
            create = 'create{}'.format(self.concretes[i]['element'])
        # create doc string header
        title_line = 'Creates a new {} using the given {} @p level' \
            .format(ob_name, self.cap_language)
        if global_variables.is_package:
            title_line += ', @ p version and package version values.'
        else:
            title_line += ' and @ p version values.'

        params = ['@param level an unsigned int, the {} Level to '
                  'assign to this {}'.format(self.cap_language,
                                             self.object_name),
                  '@param version an unsigned int, the {} Version to '
                  'assign to this {}'.format(self.cap_language,
                                             self.object_name)]
        if global_variables.is_package:
            params.append('@param pkgVersion an unsigned int, the {} {} '
                          'Version to assign to this {}'
                          .format(self.cap_language, self.package,
                                  self.object_name))

        return_lines = ['@throws {}Constructor'
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
            function = '{}_{}'.format(self.class_name, create)
            return_type = '{0} *'.format(self.object_name)

        arguments_no_defaults = []
        if global_variables.is_package:
            arguments = [
                'unsigned int level = '
                '{}Extension::getDefaultLevel()'.format(self.package),
                'unsigned int version = '
                '{}Extension::getDefaultVersion()'.format(self.package),
                'unsigned int pkgVersion = '
                '{}Extension::getDefaultPackageVersion()'.format(self.package)]
            arguments_no_defaults = ['unsigned int level',
                                     'unsigned int version',
                                     'unsigned int pkgVersion']
        else:
            arguments = ['unsigned int level',
                         'unsigned int version']
            arguments_no_defaults = ['unsigned int level',
                                     'unsigned int version']

        # create the function implementation
        constructor_args = self.write_constructor_args(None)
        if global_variables.is_package:
            if self.is_cpp_api:
                implementation = ['set{}NamespacesAndOwn(new {}PkgNamespaces'
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
                implementation = ['return new {}(level, version, '
                                  'pkgVersion)'.format(name)]
        else:
            if self.is_cpp_api:
                implementation = ['set{0}NamespacesAndOwn(new {0}Namespaces('
                                  'level, '
                                  'version))'.format(global_variables.prefix)]
            else:
                implementation = ['return new {}(level, '
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
            ob_name = '{} ({})'.format(self.concretes[i]['element'],
                                       self.object_name)
            create = 'create{}'.format(self.concretes[i]['element'])
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
            params.append('@param {0}ns the {1}PkgNamespaces object'
                          .format(self.package.lower(), self.package))
        else:
            params.append('@param {0}ns the {1}Namespaces object'
                          .format(self.language, global_variables.prefix))

        return_lines = ['@throws {}Constructor'
                        'Exception'.format(self.cap_language),
                        'Thrown if the given @p level and @p version '
                        'combination, or this kind of {} object, are either '
                        'invalid or mismatched with respect to the parent '
                        '{} object.'.format(self.cap_language,
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
            ns = '{}ns'.format(self.package.lower())
        else:
            if self.is_cpp_api:
                arguments.append('{0}Namespaces *{1}ns'
                                 .format(global_variables.prefix,
                                         self.language))
            else:
                arguments.append('{0}Namespaces_t *{1}ns'
                                 .format(global_variables.prefix,
                                         self.language))
            ns = '{}ns'.format(self.language)

        # create the function implementation
        constructor_args = self.write_constructor_args(ns)
        if global_variables.is_package:
            implementation = ['setElementNamespace({}'
                              'ns->getURI())'.format(self.package.lower())]
            if self.has_children:
                implementation.append('connectToChild()')
            if not self.is_list_of:
                implementation.append('loadPlugins({}ns)'
                                      .format(self.package.lower()))
        else:
            implementation = ['set{0}NamespacesAndOwn(new {0}Namespaces'
                              '(level, '
                              'version))'.format(global_variables.prefix)]
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
            ob_name = '{} ({})'.format(self.concretes[i]['element'],
                                       self.object_name)
            create = 'create{}'.format(self.concretes[i]['element'])
        # create doc string header
        title_line = 'Creates a new {0}.'.format(ob_name)
        params = []

        return_lines = []
        additional = ''

        # create the function declaration
        if self.is_cpp_api:
            function = self.class_name
            return_type = ''
        else:
            function = '{}_{}'.format(self.class_name, create)
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
        params = ['@param uri a string, representing the uri of the package',
                  '@param prefix a string, the prefix to be used',
                  '@param {}ns, a pointer to the {}PkgNamespaces object to '
                  'be used'.format(package, up_package)]

        return_lines = []
        additional = ''

        # create the function declaration
        function = self.class_name
        return_type = ''

        arguments = ['const std::string& uri', 'const std::string& prefix',
                     '{}PkgNamespaces* '
                     '{}ns'.format(up_package, package)]

        ns = '{}ns'.format(package)
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
        title_line = 'Copy constructor for {}.'.format(self.object_name)
        params = ['@param orig; the {} instance to copy.'.format(
            self.object_name)]
        return_lines = []
        additional = []
        # create function decl
        function = '{}'.format(self.object_name)
        return_type = ''
        arguments = ['const {}& orig'.format(self.object_name)]
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
            implementation = ['orig.{} != NULL'.format(member),
                              '{0} = orig.{0}->{1}()'.format(member,
                                                             clone)]
            code.append(self.create_code_block('if', implementation))
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
        title_line = 'Assignment operator for {}.'.format(self.object_name)
        params = ['@param rhs; the {} object whose values are to be used '
                  'as the basis of the assignment'.format(self.object_name)]
        return_lines = []
        additional = []
        function = 'operator='.format(self.object_name)
        return_type = '{}&'.format(self.object_name)
        arguments = ['const {}& rhs'.format(self.object_name)]
        # create the function implementation
        args = ['&rhs != this'] + self.write_assignment_args(self)
        clone = 'clone'
        for i in range(0, len(self.child_elements)):
            element = self.child_elements[i]
            member = element['memberName']
            args += ['delete {}'.format(member)]
            if element['element'] == 'ASTNode':
                clone = 'deepCopy'
            implementation = ['rhs.{} != NULL'.format(member),
                              '{0} = rhs.{0}->{1}()'.format(member,
                                                            clone),
                              'else', '{} = NULL'.format(member)]
            args += [self.create_code_block('if_else', implementation)]
        implementation = args
        if self.has_children:
            implementation.append('connectToChild()')
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
        title_line = 'Creates and returns a deep copy of this {} object.'\
            .format(self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}; the {} structure'
                          .format(abbrev_object, self.object_name))
        return_lines = ['@return a (deep) copy of this {} object.'.format(
            self.object_name)]
        additional = []
        if self.is_cpp_api:
            function = 'clone'
        else:
            function = '{}_clone'.format(self.class_name)
        return_type = '{}*'.format(self.object_name)
        arguments = []
        if not self.is_cpp_api:
            arguments.append('const {}* {}'.format(self.object_name,
                                                   abbrev_object))
        # create the function implementation
        if self.is_cpp_api:
            implementation = ['return new {}(*this)'.format(self.object_name)]
            code_type = 'line'
        else:
            implementation = ['{} != NULL'.format(abbrev_object),
                              'return static_cast<{}*>({}->'
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
            title_line = 'Destructor for {}.'.format(self.object_name)
        else:
            title_line = 'Frees this {} object.'.format(self.object_name)
        params = []
        if not self.is_cpp_api:
            params.append('@param {}; the {} structure'
                          .format(abbrev_object, self.object_name))
        return_lines = []
        additional = []
        if self.is_cpp_api:
            function = '~{}'.format(self.object_name)
            return_type = ''
        else:
            function = '{}_free'.format(self.class_name)
            return_type = 'void'
        arguments = []
        if not self.is_cpp_api:
            arguments.append('{}* {}'.format(self.object_name, abbrev_object))
        # create the function implementation
        if self.is_cpp_api:
            implementation = []
            code = []
            for attrib in self.attributes:
                if attrib['isArray']:
                    member = attrib['memberName']
                    code.append(self.create_code_block(
                        'if', ['{} != NULL'.format(member),
                               'delete [] {}'.format(member)]))
                    code.append(self.create_code_block(
                        'line', ['{} = NULL'.format(member)]))
            for i in range(0, len(self.child_elements)):
                element = self.child_elements[i]
                member = element['memberName']
                implementation.append('delete {}'.format(member))
                implementation.append('{} = NULL'.format(member))
            if len(implementation) > 0:
                code.append(self.create_code_block('line', implementation))
        else:
            implementation = ['{} != NULL'.format(abbrev_object),
                              'delete {}'.format(abbrev_object)]
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
            constructor_args = [': {}(level, version)'.format(self.base_class)]
            parameters = 'level, version, pkgVersion'
        elif ns is not None and self.is_plugin:
            constructor_args = [': {}(uri, prefix, '
                                '{})'.format(self.base_class, ns)]
            parameters = '{}'.format(ns)
        else:
            constructor_args = [': {}({})'.format(self.base_class, ns)]
            parameters = '{}ns'.format(self.package.lower())
        for attrib in self.attributes:
            if attrib['attType'] == 'lo_element':
                constructor_args.append(', {} '
                                        '({})'.format(attrib['memberName'],
                                                      parameters))
            else:
                constructor_args.append(', {} ({})'.format(attrib['memberName'],
                                                           attrib['default']))
            if attrib['isNumber'] or attrib['attType'] == 'boolean':
                constructor_args.append(', mIsSet{} (false)'
                                        .format(attrib['capAttName']))
        if self.overwrites_children:
            constructor_args.append(', mElementName(\"'
                                    '{}\")'.format(self.xml_name))
        return constructor_args

    @staticmethod
    def write_copy_constructor_args(self):
        constructor_args = [': {}( orig )'.format(self.base_class)]
        for attrib in self.attributes:
            if attrib['isArray']:
                constructor_args.append(', {0} ( NULL )'
                                        .format(attrib['memberName']))
            elif attrib['type'] != 'element' and attrib['element'] != 'ASTNode':
                constructor_args.append(', {0} ( orig.{0} )'
                                        .format(attrib['memberName']))
                if attrib['isNumber'] or attrib['attType'] == 'boolean':
                    constructor_args.append(', mIsSet{0} ( orig.mIsSet{0} )'
                                            .format(attrib['capAttName']))
            else:
                constructor_args.append(', {} ( NULL )'
                                        .format(attrib['memberName']))
        if self.overwrites_children:
            constructor_args.append(', mElementName ( orig.mElementName )')

        return constructor_args

    @staticmethod
    def write_assignment_args(self):
        constructor_args = ['{}::operator=(rhs)'.format(self.base_class)]
        for attrib in self.attributes:
            if attrib['isArray']:
                member = attrib['memberName']
                length = strFunctions.upper_first(attrib['name'])
                constructor_args.append('{} = NULL'.format(member))
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
        line = ['set{}(orig.{}, orig.{})'.format(name, member, length)]
        return line

    @staticmethod
    def create_code_block(code_type, lines):
        code = dict({'code_type': code_type, 'code': lines})
        return code
