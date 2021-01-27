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
from util import strFunctions as SF


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
        self.matlab_big_space = 70 * ' '

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
        self.write_line('%%%% ADD isExtension')   # TODO necessary?
        if self.filetype == 'sf':
            self.write_is_extension('Fieldname')
        elif self.filetype == 'dv':
            self.write_is_extension('DefaultValue')
        elif self.filetype == 'vt':
            self.write_is_extension('ValueType')
        self.write_line('%%%% END isExtension')
        self.skip_line(2)
        self.write_line('%%%% ADD getFieldname')
        self.write_line('%%%% ADD getFieldname')  # TODO necessary?
        filetypes = {'sf': 'Fieldnames', 'dv': 'DefaultValues',
                     'vt': 'ValueType'}  # TODO should this be plural?
                     # If it is, we can also simplify the if-block above
                     # i.e. with (name + 's')
        self.write_get_fieldname_function(filetypes[self.filetype])
        self.write_line('%%%% END getFieldname')
        self.skip_line(2)
        self.write_line('%%%% ADD functions')
        self.write_line('%%%% ADD functions')  # TODO necessary?
        if self.filetype == 'sf':
            self.write_fieldnames()
        elif self.filetype == 'dv':
            self.write_default_values()
        elif self.filetype == 'vt':
            self.write_value_types()
        self.write_line('%%%% END functions')

    def write_fieldnames(self):
        self.write_line(self.short_matlab_comment_line)
        self.write_line('% Fieldnames')
        self.write_line(self.short_matlab_comment_line)
        self.skip_line()
        for plugin in self.plugins:
            self.write_get_plugin_fieldname(plugin)
            self.skip_line(2)
        for sbmlclass in self.sbml_classes:
            self.write_get_class_fieldname(sbmlclass)
            self.skip_line(2)

    def write_default_values(self):
        self.write_line(self.short_matlab_comment_line)
        self.write_line('% DefaultValues')
        self.write_line(self.short_matlab_comment_line)
        self.skip_line()
        for plugin in self.plugins:
            self.write_get_plugin_default_values(plugin)
            self.skip_line(2)
        for sbmlclass in self.sbml_classes:
            self.write_get_class_default_values(sbmlclass)
            self.skip_line(2)

    def write_value_types(self):
        self.write_line(self.short_matlab_comment_line)
        self.write_line('% ValueTypes')
        self.write_line(self.short_matlab_comment_line)
        self.skip_line()
        for plugin in self.plugins:
            self.write_get_plugin_values_types(plugin)
            self.skip_line(2)
        for sbmlclass in self.sbml_classes:
            self.write_get_class_values_types(sbmlclass)
            self.skip_line(2)

    def write_some_common_lines(self):
        """
        Utility function to write some common output.
        TODO a more descriptive name wouldn't go amiss.
        """
        self.write_line(self.matlab_big_space + 'version, pkgVersion)')
        self.write_more_common_lines()

    def write_more_common_lines(self):
        """
        Another utility function
        TODO yep, this one also needs a better name!
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
        Write the `end` characters at the end of a code block.
        """
        self.down_indent()
        for _ in range(0, 3):
            self.write_line('end;')
            self.down_indent()

    def write_get_plugin_values_types(self, plugin):
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = '
                                 'get{0}{1}ValueType(level, ...'.
                                 format(self.up_pack, plugin['sbase']))

        self.write_some_common_lines()
        num_fields = 1
        self.write_line('SBMLfieldnames = {')
        self.write_line('\'uint\', ...')
        for extension in plugin['extension']:
            self.write_line('\'structure\', ...'.format())
            num_fields += 1
        for extension in plugin['lo_extension']:
            self.write_line('\'structure\', ...')
            num_fields += 1
        for attrib in plugin['attribs']:
            self.write_line('{0}, ...'.format(self.get_value_type(attrib)))
            num_fields += 1
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.write_ends()

    def write_get_class_values_types(self, sbmlclass):
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = '
                                 'get{0}ValueType(level, ...'.
                                 format(sbmlclass['name']))
        self.write_some_common_lines()

        num_fields = 9
        self.write_line('SBMLfieldnames = {')
        self.write_line('\'{0}\', ...'.format(sbmlclass['typecode']))
        for _ in range(0, 3):
            self.write_line('\'char\', ...')
        self.write_line('\'structure\', ...')
        self.write_line('\'int\', ...')
        for attrib in sbmlclass['attribs']:
            self.write_line('{0}, ...'.format(self.get_value_type(attrib)))
            num_fields += 1
        self.write_line('\'uint\', ...')
        self.write_line('\'uint\', ...')
        self.write_line('\'uint\', ...'.format(self.package))  # TODO Unused argument
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.write_ends()

    def get_value_type(self, attrib):
        att_type = attrib['type']
        att_name = attrib['name']
        if att_type in ['SId', 'SIdRef', 'string', 'enum']:
            return '\'char\''
        elif att_type == 'bool':
            return '\'bool\''
        elif att_type == 'uint' or att_type == 'int':
            return '\'uint\''
        elif att_type == 'lo_element':
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
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = '
                                 'get{0}{1}DefaultValues(level, ...'.
                                 format(self.up_pack, plugin['sbase']))
        self.write_some_common_lines()

        num_fields = 1
        self.write_line('SBMLfieldnames = {')
        self.write_line('int32(pkgVersion), ...')
        for extension in plugin['extension']:
            self.write_line('[], ...'.format())
            num_fields += 1
        for extension in plugin['lo_extension']:
            self.write_line('[], ...')
            num_fields += 1
        for attrib in plugin['attribs']:
            self.write_line('{0}, ...'.format(self.get_type(attrib)))
            num_fields += 1
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.down_indent()
        for _ in range(0, 3):
            self.write_line('end;')
            self.down_indent()

    def write_get_class_default_values(self, sbmlclass):
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields]'
                                 ' = get{0}DefaultValues(level, ...'.
                                 format(sbmlclass['name']))

        self.write_some_common_lines()

        num_fields = 9
        self.write_line('SBMLfieldnames = {')
        self.write_line('\'{0}\', ...'.format(sbmlclass['typecode']))
        for _ in range(0, 3):
            self.write_line('\'\', ...')
        self.write_line('[], ...')
        self.write_line('int32(-1), ...')
        for attrib in sbmlclass['attribs']:
            self.write_line('{0}, ...'.format(self.get_type(attrib)))
            num_fields += 1
        self.write_line('3, ...')
        self.write_line('int32(version), ...')
        self.write_line('int32(pkgVersion), ...'.format(self.package))  # TODO Unused argument
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.write_ends()

    def get_type(self, attrib):
        att_type = attrib['type']
        att_name = attrib['name']
        if att_type in ['SId', 'SIdRef', 'string', 'enum']:
            return '\'\''
        elif att_type in ['bool', 'uint', 'int']:
            return 'int32(0)'
        elif att_type == 'lo_element':
            return '[]'
        elif att_type == 'element':
            if att_name == 'math':
                return '\'\''
            else:
                return '[]'
        elif att_type == 'double':
            return '0/0'
        else:
            return att_type

    def write_get_plugin_fieldname(self, plugin):
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields]'
                                 ' = get{0}{1}Fieldnames(level, ...'.
                                 format(self.up_pack, plugin['sbase']))

        self.write_some_common_lines()

        num_fields = 1
        self.write_line('SBMLfieldnames = {')
        self.write_line('\'{0}_version\', ...'.format(self.package))
        for extension in plugin['extension']:
            self.write_line('\'{0}_{1}\', ...'.
                            format(self.package,
                                   SF.lower_first(extension['name'])))
            num_fields += 1
        for extension in plugin['lo_extension']:
            self.write_line('\'{0}_{1}\', ...'.
                            format(self.package,
                                   SF.lower_first(extension['name'])))
            num_fields += 1
        for attrib in plugin['attribs']:
            self.write_line('\'{0}_{1}\', ...'.
                            format(self.package,
                                   SF.lower_first(attrib['name'])))
            num_fields += 1
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.write_ends()

    def write_get_class_fieldname(self, sbmlclass):
        self.write_line(self.matlab_comment_line)
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields]'
                                 ' = get{0}Fieldnames(level, ...'.
                                 format(sbmlclass['name']))

        self.write_some_common_lines()

        num_fields = 9
        self.write_line('SBMLfieldnames = {')
        self.write_line('\'typecode\', ...')
        self.write_line('\'metaid\', ...')
        self.write_line('\'notes\', ...')
        self.write_line('\'annotation\', ...')
        self.write_line('\'cvterms\', ...')
        self.write_line('\'sboTerm\', ...')
        for attrib in sbmlclass['attribs']:
            if attrib['name'] == 'math':
                self.write_line('\'{0}\', ...'.format(attrib['name']))
            else:
                self.write_line('\'{0}_{1}\', ...'.format(self.package,
                                                          attrib['name']))
            num_fields += 1
        self.write_line('\'level\', ...')
        self.write_line('\'version\', ...')
        self.write_line('\'{0}_version\', ...'.format(self.package))
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.write_ends()

    def write_get_fieldname_function(self, functionType):
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
        for sbmlclass in self.sbml_classes:  # TODO Unused argument:
            self.write_line_verbatim('case {0}\'{1}\', \'{3}\', \'{4}\','
                                     ' \'{6}_{4}\'{5}'.
                                     format(self.open_br,
                                            sbmlclass['typecode'],
                                            sbmlclass['name'].upper(),
                                            sbmlclass['name'],
                                            SF.lower_first(sbmlclass['name']),
                                            self.close_br, self.package))
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

    def write_is_extension(self, functionType):
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
