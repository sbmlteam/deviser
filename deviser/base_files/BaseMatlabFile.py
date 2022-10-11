#!/usr/bin/env python
#
# @file    BaseMatlabFile.py
# @brief   Base class for all MATLAB files to be generated
# @author  Frank Bergmann
# @author  Sarah Keating
# @author  Matthew S. Gillman
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


from . import BaseFile
from ..util import strFunctions as SF
from ..util import query


class BaseMatlabFile(BaseFile.BaseFile):
    """Common base class for all Matlab files"""

    def __init__(self, name, object_desc, filetype):
        BaseFile.BaseFile.__init__(self, name+filetype, 'm')

        # change the comment delimiter and line length
        self.comment = '%'
        self.line_length = 72

        self.matlab_comment_line = 68 * '%'
        self.long_matlab_comment_line = 78 * '%'
        self.short_matlab_comment_line = 32 * '%'
        self.matlab_big_space = 55 * ' '

        self.package = object_desc['name']
        self.up_pack = self.package.upper()
        self.fullname = object_desc['fullname']
        self.sbml_classes = object_desc['baseElements']
        self.offset = object_desc['offset']
        self.plugins = object_desc['plugins']
        self.enums = object_desc['enums']
        self.level = object_desc['base_level']
        self.version = object_desc['base_version']
        self.pkg_version = object_desc['pkg_version']
        self.num_versions = 1 if 'num_versions' not in object_desc else object_desc['num_versions']

        if object_desc['required']:
            self.reqd_status = 'true'
        else:
            self.reqd_status = 'false'

        self.prim_class = []

        self.start_b = '{'
        self.end_b = '}'

        self.filetype = filetype

    ########################################################################

    def write_file(self):
        """
        Write a big chunk of the Matlab file.
        """
        self.write_line('%%%%% REMOVE END')
        self.write_line('%%%%% ADD ADDITIONAL')
        if self.filetype == 'sf':
            self.write_get_field('Fieldname')
        elif self.filetype == 'dv':
            self.write_get_field('DefaultValue')
        elif self.filetype == 'vt':
            self.write_get_field('ValueType')
        self.write_line('%%%%% REMOVE END')
        self.write_line('%%%%% ADD ADDITIONAL')
        self.skip_line(2)
        self.write_line(self.long_matlab_comment_line)
        self.write_line('%%%% ADD isExtension')
        self.write_line('%%%% ADD isExtension')   # TODO both necessary?
        if self.filetype == 'sf':
            self.write_is_extension()
        elif self.filetype == 'dv':
            self.write_is_extension()
        elif self.filetype == 'vt':
            self.write_is_extension()
        self.write_line('%%%% END isExtension')
        self.skip_line(2)
        self.write_line('%%%% ADD getFieldname')
        self.write_line('%%%% ADD getFieldname')  # TODO both necessary?
        filetypes = {'sf': 'Fieldnames', 'dv': 'DefaultValues',
                     'vt': 'ValueType'}  # TODO should this be plural?
                     # If it is, we can also simplify the if-block above
                     # i.e. with (name + 's') and use dictionary
        self.write_get_fieldname_function(filetypes[self.filetype])
        self.write_line('%%%% END getFieldname')
        self.skip_line(2)
        self.write_line('%%%% ADD functions')
        self.write_line('%%%% ADD functions')  # TODO both necessary?
        if self.filetype == 'sf':
            self.write_fieldnames()
        elif self.filetype == 'dv':
            self.write_default_values()
        elif self.filetype == 'vt':
            self.write_value_types()
        self.write_line('%%%% END functions')

    def write_fieldnames(self):
        """
        Write the getXXXFieldnames() functions in the Matlab file.
        """
        self.write_line(self.short_matlab_comment_line)
        self.write_line('% Fieldnames')
        self.write_line(self.short_matlab_comment_line)
        self.skip_line()
        # Write the getXXXFieldnames() function for each plugin:
        for plugin in self.plugins:
            self.write_get_plugin_fieldname(plugin)
            self.skip_line(2)
        # Write a getXXXFieldnames() function for each sbml class:
        for sbmlclass in self.sbml_classes:
            self.write_get_class_fieldname(sbmlclass)
            self.skip_line(2)

    def write_default_values(self):
        """
        Write the getXXXDefaultValues() functions to the Matlab file.
        """
        self.write_line(self.short_matlab_comment_line)
        self.write_line('% DefaultValues')
        self.write_line(self.short_matlab_comment_line)
        self.skip_line()
        # Write a getXXXDefaultValues() function for each plugin:
        for plugin in self.plugins:
            self.write_get_plugin_default_values(plugin)
            self.skip_line(2)
        # Write a getXXXDefaultValues() function for each sbml class:
        for sbmlclass in self.sbml_classes:
            self.write_get_class_default_values(sbmlclass)
            self.skip_line(2)

    def write_value_types(self):
        """
        Write the getXXXValueType() functions to the Matlab file
        """
        self.write_line(self.short_matlab_comment_line)
        self.write_line('% ValueTypes')
        self.write_line(self.short_matlab_comment_line)
        self.skip_line()
        # Write the getXXXValueType() function for each plugin:
        for plugin in self.plugins:
            self.write_get_plugin_values_types(plugin)
            self.skip_line(2)
        # Write the getXXXValueType() function for each sbml class.
        for sbmlclass in self.sbml_classes:
            self.write_get_class_values_types(sbmlclass)
            self.skip_line(2)

    def write_function_args(self):
        """
        Utility function to write some common output.
        The first line closes a matlab function argument list.
        """
        self.write_line_verbatim(self.matlab_big_space + 'version, pkgVersion)')

    def write_function_setup(self):
        """
        Utility function to write some common output.
        """
        self.up_indent()
        self.write_line('if (~isValidLevelVersionCombination(level,'
                        ' version))')
        self.up_indent()
        self.write_line('error (\'invalid level/version combination\');')
        self.down_indent()
        self.write_line('end;')
        self.skip_line()

        self.write_line('SBMLfieldnames = [];')
        self.write_line('nNumberFields = 0;')
        self.skip_line()
        self.write_line('if (level == 3)')
        self.up_indent()
        self.write_line('if (version < 3)')
        self.up_indent()
        self.write_line('if (pkgVersion == 1)')
        self.up_indent()

    def write_ends(self):
        """
        Another utility function, used a number of times.
        Write the `end` keywords at the end of a code block.
        """
        self.down_indent()
        for _ in range(0, 3):
            self.write_line('end;')
            self.down_indent()

    def write_get_plugin_values_types(self, plugin):
        """
        Write the getXXXValueType() function for a plugin.

        :param plugin: dictionary representing the <plugin> node.
        """
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = '
                                 'get{0}{1}ValueType(level, ...'.
                                 format(self.up_pack, plugin['sbase']))

        self.write_function_args()
        self.write_function_setup()
        v = 1
        for i in range(0, self.num_versions):
            num_fields = 0
            if plugin['version_info'][i]:
                self.write_line('SBMLfieldnames = {')
                for extension in plugin['extension']:
                    if extension['version_info'][i]:
                        self.write_line('\'structure\', ...'.format())
                        num_fields += 1
                        attribs = self.get_lo_attributes(extension)
                        for attrib in attribs:
                            num_fields = self.write_attribute_vt(attrib, i, num_fields)
                for extension in plugin['lo_extension']:
                    if extension['version_info'][i]:
                        self.write_line('\'structure\', ...')
                        num_fields += 1
                        attribs = self.get_lo_attributes(extension)
                        for attrib in attribs:
                            num_fields = self.write_attribute_vt(attrib, i, num_fields)
                for attrib in plugin['attribs']:
                    num_fields = self.write_attribute_vt(attrib, i, num_fields)
                self.write_line('\'uint\', ...')
                self.write_line('\'uint\', ...')
                self.write_line('\'uint\', ...'.format(v))
                # e.g. "'qual_version', ..."
                num_fields += 3
                self.write_line('};')
                self.write_line('nNumberFields = {0};'.format(num_fields))

            self.down_indent()
            v = v + 1
            if v <= self.num_versions:
                self.write_line('elseif (pkgVersion == {0})'.format(v))
                self.up_indent()

        self.write_ends()

    def write_get_class_values_types(self, sbmlclass):
        """
        Write info from an sbml class

        :param sbmlclass: dictionary representing the sbml class.
        """
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = '
                                 'get{0}ValueType(level, ...'.
                                 format(sbmlclass['name']))
        self.write_function_args()
        self.write_function_setup()

        v = 1
        for i in range(0, self.num_versions):
            num_fields = 0
            if sbmlclass['version_info'][i]:
                self.write_line('SBMLfieldnames = {')
                num_fields = 9
                self.write_line('\'{0}\', ...'.format(sbmlclass['typecode']))
                for _ in range(0, 3):
                    self.write_line('\'char\', ...')
                self.write_line('\'structure\', ...')
                self.write_line('\'int\', ...')
                for attrib in sbmlclass['attribs']:
                    num_fields = self.write_attribute_vt(attrib, i, num_fields)
                self.write_line('\'uint\', ...')
                self.write_line('\'uint\', ...')
                self.write_line('\'uint\', ...')  # .format(self.package))
                self.write_line('};')
                self.write_line('nNumberFields = {0};'.format(num_fields))
            self.down_indent()
            v = v + 1
            if v <= self.num_versions:
                self.write_line('else if (pkgVersion == {0})'.format(v))
                self.up_indent()
        self.write_ends()

    def get_value_type(self, attrib):
        """
        Get the Matlab value type from an attribute's value type.

        :param attrib: dictionary representing an <attribute> node.
        """
        att_type = attrib['type']
        att_name = attrib['name']
        if att_type in ['SId', 'SIdRef', 'string', 'enum']:
            return '\'char\''
        elif att_type == 'bool':
            return '\'bool\''
        elif att_type == 'uint':
            return '\'uint\''
        elif att_type == 'int':
            return '\'int\''
        elif att_type == 'lo_element' or att_type == 'inline_lo_element':
            return '\'structure\''
        elif att_type == 'element':
            if att_name == 'math':
                return '\'char\''
            else:
                return '\'structure\''
        elif att_type == 'double':
            return '\'double\''
        else:
            return att_type

    def write_get_plugin_default_values(self, plugin):
        """
        Write default values from a plugin.

        :param plugin: dictionary representing the <plugin> node.
        """
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = '
                                 'get{0}{1}DefaultValues(level, ...'.
                                 format(self.up_pack, plugin['sbase']))
        self.write_function_args()
        self.write_function_setup()

        v = 1
        for i in range(0, self.num_versions):
            num_fields = 0
            if plugin['version_info'][i]:
                self.write_line('SBMLfieldnames = {')
                for extension in plugin['extension']:
                    if extension['version_info'][i]:
                        self.write_line('[], ...'.format())
                        num_fields += 1
                        attribs = self.get_lo_attributes(extension)
                        for attrib in attribs:
                            num_fields = self.write_attribute_dv(attrib, i, num_fields)
                for extension in plugin['lo_extension']:
                    if extension['version_info'][i]:
                        self.write_line('[], ...')
                        num_fields += 1
                        attribs = self.get_lo_attributes(extension)
                        for attrib in attribs:
                            num_fields = self.write_attribute_dv(attrib, i, num_fields)
                for attrib in plugin['attribs']:
                    num_fields = self.write_attribute_dv(attrib, i, num_fields)
                self.write_line('int32(3), ...')
                self.write_line('int32(1), ...')
                self.write_line('int32({0}), ...'.format(v))
                # e.g. "'qual_version', ..."
                num_fields += 3
                self.write_line('};')
                self.write_line('nNumberFields = {0};'.format(num_fields))

            self.down_indent()
            v = v + 1
            if v <= self.num_versions:
                self.write_line('elseif (pkgVersion == {0})'.format(v))
                self.up_indent()

        self.write_ends()

    def write_get_class_default_values(self, sbmlclass):
        """
        Write the default values from an sbml class.

        :param sbmlclass: dictionary representing the sbml class.
        """
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields]'
                                 ' = get{0}DefaultValues(level, ...'.
                                 format(sbmlclass['name']))

        self.write_function_args()
        self.write_function_setup()

        v = 1
        for i in range(0, self.num_versions):
            num_fields = 0
            if sbmlclass['version_info'][i]:
                self.write_line('SBMLfieldnames = {')
                num_fields = 9
                self.write_line('\'{0}\', ...'.format(sbmlclass['typecode']))
                for _ in range(0, 3):
                    self.write_line('\'\', ...')
                self.write_line('[], ...')
                self.write_line('int32(-1), ...')
                for attrib in sbmlclass['attribs']:
                    num_fields = self.write_attribute_dv(attrib, i, num_fields)
                self.write_line('int32(3), ...')
                self.write_line('int32(1), ...')
                self.write_line('int32({0}), ...'.format(v))
                self.write_line('};')
                self.write_line('nNumberFields = {0};'.format(num_fields))
            self.down_indent()
            v = v + 1
            if v <= self.num_versions:
                self.write_line('else if (pkgVersion == {0})'.format(v))
                self.up_indent()
        self.write_ends()

    def get_type(self, attrib):
        """
        Get the Matlab type of an attribute

        :param attrib: dictionary representing an <attribute> node.

        TODO I'm not sure what the difference id between a Matlab type and a
        Matlab value type, per function get_value_type() above.
        """
        att_type = attrib['type']
        att_name = attrib['name']
        if att_type in ['SId', 'SIdRef', 'string', 'enum']:
            return '\'\''
        elif att_type in ['bool', 'uint', 'int']:
            return 'int32(0)'
        elif att_type in ['lo_element', 'inline_lo_element']:
            return '[]'
        elif att_type == 'element':
            return '\'\'' if att_name == 'math' else '[]'
        elif att_type == 'double':
            return '0/0'
        else:
            return att_type

    def write_attribute(self, attrib, version, num_fields):
        if attrib['version_info'][version]:
            if attrib['name'] == 'math':
                self.write_line('\'{0}\', ...'.format(attrib['name']))
            else:
                self.write_line('\'{0}_{1}\', ...'.format(self.package,
                                                          attrib['name']))
            num_fields += 1
            if self.get_type(attrib) == 'int32(0)' or self.get_type(attrib) == '0/0':
                self.write_line('\'isSet{0}_{1}\', ...'.
                                format(self.package,
                                       SF.lower_first(attrib['name'])))
                num_fields += 1
        return num_fields

    def write_attribute_dv(self, attrib, version, num_fields):
        if attrib['version_info'][version]:
            if attrib['name'] == 'math':
                self.write_line('\'{0}\', ...'.format(attrib['name']))
            else:
                self.write_line('{0}, ...'.format(self.get_type(attrib)))
            num_fields += 1
            if self.get_type(attrib) == 'int32(0)' or self.get_type(attrib) == '0/0':
                self.write_line('int32(0), ...')
                num_fields += 1
        return num_fields

    def write_attribute_vt(self, attrib, version, num_fields):
        if attrib['version_info'][version]:
            if attrib['name'] == 'math':
                self.write_line('\'{0}\', ...'.format(attrib['name']))
            else:
                self.write_line('{0}, ...'.format(self.get_value_type(attrib)))
            num_fields += 1
            if self.get_type(attrib) == 'int32(0)' or self.get_type(attrib) == '0/0':
                self.write_line('\'bool\', ...')
                num_fields += 1
        return num_fields

    def get_lo_attributes(self, extension):
        element = query.get_class(extension['name'], extension['root'])
        return element['lo_attribs']

    def write_get_plugin_fieldname(self, plugin):
        """
        Writes a "getXXXFieldnames() Matlab function for a plugin
        e.g. "getQUALModelFieldnames()" and its body

        :param plugin: dictionary representing the <plugin> node
        """
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields]'
                                 ' = get{0}{1}Fieldnames(level, ...'.
                                 format(self.up_pack, plugin['sbase']))
        self.write_function_args()
        self.write_function_setup()

        v = 1
        for i in range(0, self.num_versions):
            num_fields = 0
            if plugin['version_info'][i]:
                self.write_line('SBMLfieldnames = {')
                for extension in plugin['extension']:
                    if extension['version_info'][i]:
                        self.write_line('\'{0}_{1}\', ...'.
                                        format(self.package,
                                               SF.lower_first(extension['name'])))
                        num_fields += 1
                        attribs = self.get_lo_attributes(extension)
                        for attrib in attribs:
                            num_fields = self.write_attribute(attrib, i, num_fields)

                for extension in plugin['lo_extension']:
                    if extension['version_info'][i]:
                        self.write_line('\'{0}_{1}\', ...'.
                                        format(self.package,
                                               SF.lower_first(extension['name'])))
                        num_fields += 1
                        attribs = self.get_lo_attributes(extension)
                        for attrib in attribs:
                            num_fields = self.write_attribute(attrib, i, num_fields)
                for attrib in plugin['attribs']:
                    num_fields = self.write_attribute(attrib, i, num_fields)
                self.write_line('\'level\', ...')
                self.write_line('\'version\', ...')
                self.write_line('\'{0}_version\', ...'.format(self.package))
                # e.g. "'qual_version', ..."
                num_fields += 3

                self.write_line('};')
                self.write_line('nNumberFields = {0};'.format(num_fields))
            self.down_indent()
            v = v + 1
            if v <= self.num_versions:
                self.write_line('elseif (pkgVersion == {0})'.format(v))
                self.up_indent()

        self.write_ends()

    def write_get_class_fieldname(self, sbmlclass):
        """
        Writes a "getXXXFieldnames() Matlab function for an sbml class
        e.g. "getQUALModelFieldnames()" and its body

        :param sbmlclass: dictionary representing the sbml class
        """
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields]'
                                 ' = get{0}Fieldnames(level, ...'.
                                 format(sbmlclass['name']))

        self.write_function_args()
        self.write_function_setup()

        v = 1
        for i in range(0, self.num_versions):
            num_fields = 0
            if sbmlclass['version_info'][i]:
                self.write_line('SBMLfieldnames = {')
                num_fields = 9
                self.write_line('\'typecode\', ...')
                self.write_line('\'metaid\', ...')
                self.write_line('\'notes\', ...')
                self.write_line('\'annotation\', ...')
                self.write_line('\'cvterms\', ...')
                self.write_line('\'sboTerm\', ...')
                for attrib in sbmlclass['attribs']:
                    num_fields = self.write_attribute(attrib, i, num_fields)
                self.write_line('\'level\', ...')
                self.write_line('\'version\', ...')
                self.write_line('\'{0}_version\', ...'.format(self.package))
                self.write_line('};')
                self.write_line('nNumberFields = {0};'.format(num_fields))
            self.down_indent()
            v = v + 1
            if v <= self.num_versions:
                self.write_line('else if (pkgVersion == {0})'.format(v))
                self.up_indent()
        self.write_ends()

    def write_get_fieldname_function(self, functionType):
        """
        Write a getXXXFunction() function for the given functionType

        :param functionType: e.g. 'Fieldnames'.
        """
        length = len(functionType)
        if not functionType.endswith('s'):
            length += 1
        self.write_line('function [found, fhandle] = '
                        'get{0}{1}Function(typecode)'.
                        format(self.up_pack, functionType[0:length-1]))
        self.up_indent()
        self.write_line('found = 1;')
        self.write_line('switch (typecode)')
        self.up_indent()
        for sbmlclass in self.sbml_classes:
            self.write_line_verbatim('case {0}\'{1}\', \'{2}\', \'{3}\','
                                     ' \'{5}_{3}\'{4}'.
                                     format(self.open_br,
                                            sbmlclass['typecode'],
                                            # sbmlclass['name'].upper(),
                                            sbmlclass['name'],
                                            SF.lower_first(sbmlclass['name']),
                                            self.close_br, self.package))
            # e.g. sbmlclass['name'] = 'QualitativeSpecies',
            # sbmlclass['typecode'] = 'SBML_QUAL_QUALITATIVE_SPECIES',
            # self.package = 'qual'
            self.up_indent()
            self.write_line('fhandle = str2func(\'get{0}{1}\');'.
                            format(sbmlclass['name'], functionType))
            self.down_indent()
        for plugin in self.plugins:
            self.write_line_verbatim('case {0}\'SBML_{1}_{2}\', \'{1}{3}\','
                                     ' \'SBML_{2}\', \'{3}\', \'{4}\'{5}'.
                                     format(self.open_br, self.up_pack,
                                            plugin['sbase'].upper(),
                                            plugin['sbase'],
                                            plugin['sbase'].lower(),
                                            self.close_br))
            # e.g. plugin['sbase'] = 'Model', self.up_pack = 'QUAL'
            self.up_indent()
            self.write_line('fhandle = str2func(\'get{0}{1}{2}\');'.
                            format(self.up_pack, plugin['sbase'],
                                   functionType))
            self.down_indent()
        self.write_line('otherwise')
        self.up_indent()
        self.write_line('fhandle = str2func(\'disp\');')
        self.write_line('found = 0;')
        self.down_indent()
        self.down_indent()
        self.write_line('end;')
        self.down_indent()

    def write_is_extension(self):
        """
        Write an isXXXExtension() function in the Matlab file.
        """
        self.write_line('function extend = is{0}Extension(typecode)'.
                        format(self.up_pack))
        self.up_indent()
        self.write_line('extend = 0;')
        self.write_line('switch (typecode)')
        self.up_indent()
        for plugin in self.plugins:
            self.write_line_verbatim('case {0}\'SBML_{1}_{2}\', \'{1}{3}\','
                                     ' \'SBML_{2}\', \'{3}\', \'{4}\'{5}'.
                                     format(self.open_br, self.up_pack,
                                            plugin['sbase'].upper(),
                                            plugin['sbase'],
                                            plugin['sbase'].lower(),
                                            self.close_br))
            self.up_indent()
            self.write_line('extend = 1;')
            self.down_indent()
        self.down_indent()
        self.write_line('end;')
        self.down_indent()

    def write_get_field(self, functionType):
        """
        Write a function to get a certain field
        e.g. getQUALFieldnameFunction()

        :param functionType: currently one of 'Fieldname',
             'DefaultValue' or 'ValueType'.
        """
        useS = ''
        self.up_indent(2)
        self.write_line('elseif strcmp(pkg, \'{0}\')'.format(self.package))
        self.up_indent()
        self.write_line('if (extension)')
        self.up_indent()
        self.write_line('if (is{0}Extension(typecode))'.format(self.up_pack))
        self.up_indent()
        self.write_line('[found, fhandle] = get{0}{1}{2}Function(typecode);'.
                        format(self.up_pack, functionType, useS))
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('else')
        self.up_indent()
        self.write_line('[found, fhandle] = get{0}{1}{2}Function(typecode);'.
                        format(self.up_pack, functionType, useS))
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent(2)
