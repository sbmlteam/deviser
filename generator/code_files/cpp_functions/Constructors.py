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

from util import strFunctions


class Constructors():
    """Class for all constructors"""

    def __init__(self, language, is_cpp_api, class_object):
        self.language = 'language'
        self.package = class_object['package']
        self.class_name = class_object['name']
        self.is_cpp_api = is_cpp_api
        if is_cpp_api:
            self.object_name = class_object['name']
        else:
            self.object_name = class_object['name'] + '_t'

        # check case of things where we assume upper/lower
        if self.package[0].islower():
            self.package = strFunctions.upper_first(class_object['package'])

    ########################################################################

    # Functions for writing constructors

    # function to write level version constructor
    def write_level_version_constructor(self):

        # create doc string header
        title_line = 'Creates a new {0} using the given SBML @p level' \
            .format(self.object_name)
        if self.package:
            title_line += ', @ p version and package version values.'
        else:
            title_line += ' and @ p version values.'

        params = ['@param level an unsigned int, the SBML Level to '
                  'assign to this {0}'.format(self.object_name),
                  '@param version an unsigned int, the SBML Version to '
                  'assign to this {0}'.format(self.object_name)]
        if self.package:
            params.append('@param pkgVersion an unsigned int, the SBML {0} '
                          'Version to assign to this {1}'
                          .format(self.package, self.object_name))

        return_lines = ['@throws SBMLConstructorException',
                        'Thrown if the given @p level and @p version '
                        'combination, or this kind of SBML object, are '
                        'either invalid or mismatched with respect to the '
                        'parent SBMLDocument object.',
                        '@copydetails doc_note_setting_lv']
        additional = ''

        # create the function declaration
        if self.is_cpp_api:
            function = self.class_name
            return_type = ''
        else:
            function = '{}_create'.format(self.class_name)
            return_type = '{0} *'.format(self.object_name)

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

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name})

    # function to write namespace constructor
    def write_namespace_constructor(self):
        # create doc string header
        title_line = 'Creates a new {0} using the given'\
            .format(self.object_name)
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
        additional = ''

        # create the function declaration
        if self.is_cpp_api:
            function = self.class_name
            return_type = ''
        else:
            function = '{0}_createWithNS'.format(self.class_name)
            return_type = '{0} *'.format(self.object_name)

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

        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name})

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
        function = '{}'.format(self.object_name)
        return_type = ''
        arguments = ['const {}& orig'.format(self.object_name)]
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name})

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
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': False,
                     'object_name': self.object_name})

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
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': True,
                     'virtual': True,
                     'object_name': self.object_name})

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
        return dict({'title_line': title_line,
                     'params': params,
                     'return_lines': return_lines,
                     'additional': additional,
                     'function': function,
                     'return_type': return_type,
                     'arguments': arguments,
                     'constant': False,
                     'virtual': True,
                     'object_name': self.object_name})
