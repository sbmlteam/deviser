#!/usr/bin/env python
#
# @file    BaseMatlabFile.py
# @brief   base class for all matlab files to be generated
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


from . import BaseFile
from util import strFunctions


class BaseMatlabFile(BaseFile.BaseFile):
    """Common base class for all LaTeX files"""

    def __init__(self, name, object_desc):
        BaseFile.BaseFile.__init__(self, name, '.m')

        # change the comment delimiter and line length
        self.comment = '%'
        self.line_length = 72

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

    ########################################################################

    def write_file(self):
        self.write_get_field()
        self.skip_line(2)
        self.write_is_extension()
        self.skip_line(2)
        self.write_get_fieldname_function()
        self.skip_line(2)
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.write_line('% Fieldnames')
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.skip_line()
        for plugin in self.plugins:
            self.write_get_plugin_fieldname(plugin)
            self.skip_line(2)
        for sbmlclass in self.sbml_classes:
            self.write_get_class_fieldname(sbmlclass)
            self.skip_line(2)
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.write_line('% DefaultValues')
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.skip_line()
        for plugin in self.plugins:
            self.write_get_plugin_default_values(plugin)
            self.skip_line(2)
        for sbmlclass in self.sbml_classes:
            self.write_get_class_default_values(sbmlclass)
            self.skip_line(2)
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.write_line('% ValueTypes')
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.skip_line()
        for plugin in self.plugins:
            self.write_get_plugin_values_types(plugin)
            self.skip_line(2)
        for sbmlclass in self.sbml_classes:
            self.write_get_class_values_types(sbmlclass)
            self.skip_line(2)


    def write_get_plugin_values_types(self, plugin):
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = get{0}{1}DefaultValues(level, ...'.format(self.up_pack, plugin['sbase']))
        self.write_line('                                                                      version, pkgVersion)')
        self.up_indent()

        self.write_line('if (~isValidLevelVersionCombination(level, version))')
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

        num_fields = 1
        self.write_line('SBMLfieldnames = {')
        self.write_line('int32(pkgVersion), ...')
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

        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()


    def write_get_class_values_types(self, sbmlclass):
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = get{0}DefaultValues(level, ...'.format(sbmlclass['name']))
        self.write_line('                                                                      version, pkgVersion)')
        self.up_indent()

        self.write_line('if (~isValidLevelVersionCombination(level, version))')
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

        num_fields = 9
        self.write_line('SBMLfieldnames = {')
        self.write_line('\'{0}\', ...'.format(sbmlclass['typecode']))
        self.write_line('\'char\', ...')
        self.write_line('\'char\', ...')
        self.write_line('\'char\', ...')
        self.write_line('\'structure\', ...')
        self.write_line('\'int\', ...')
        for attrib in sbmlclass['attribs']:
            self.write_line('{0}, ...'.format(self.get_value_type(attrib)))
            num_fields += 1
        self.write_line('\'uint\', ...')
        self.write_line('\'uint\', ...')
        self.write_line('\'uint\', ...'.format(self.package))
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()

    def get_value_type(self, attrib):
        att_type = attrib['type']
        att_name = attrib['name']
        if att_type == 'SId' or att_type == 'SIdRef' or att_type == 'string' or att_type == 'enum':
            return '\'char\''
        elif att_type == 'bool' or att_type == 'uint':
            return '\'uint\''
        elif att_type == 'lo_element':
            return '\'structure\''
        elif att_type == 'element':
            if att_name == 'math':
                return '\'\''
            else:
                return '\'structure\''
        elif att_type == 'double':
            return '\'double\''
        else:
            return att_type


    def write_get_plugin_default_values(self, plugin):
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = get{0}{1}DefaultValues(level, ...'.format(self.up_pack, plugin['sbase']))
        self.write_line('                                                                      version, pkgVersion)')
        self.up_indent()

        self.write_line('if (~isValidLevelVersionCombination(level, version))')
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
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()


    def write_get_class_default_values(self, sbmlclass):
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = get{0}DefaultValues(level, ...'.format(sbmlclass['name']))
        self.write_line('                                                                      version, pkgVersion)')
        self.up_indent()

        self.write_line('if (~isValidLevelVersionCombination(level, version))')
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

        num_fields = 9
        self.write_line('SBMLfieldnames = {')
        self.write_line('\'{0}\', ...'.format(sbmlclass['typecode']))
        self.write_line('\'\', ...')
        self.write_line('\'\', ...')
        self.write_line('\'\', ...')
        self.write_line('[], ...')
        self.write_line('int32(-1), ...')
        for attrib in sbmlclass['attribs']:
            self.write_line('{0}, ...'.format(self.get_type(attrib)))
            num_fields += 1
        self.write_line('3, ...')
        self.write_line('int32(version), ...')
        self.write_line('int32(pkgVersion), ...'.format(self.package))
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()

    def get_type(self, attrib):
        att_type = attrib['type']
        att_name = attrib['name']
        if att_type == 'SId' or att_type == 'SIdRef' or att_type == 'string' or att_type == 'enum':
            return '\'\''
        elif att_type == 'bool' or att_type == 'uint':
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
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = get{0}{1}Fieldnames(level, ...'.format(self.up_pack, plugin['sbase']))
        self.write_line('                                                                      version, pkgVersion)')
        self.up_indent()

        self.write_line('if (~isValidLevelVersionCombination(level, version))')
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

        num_fields = 1
        self.write_line('SBMLfieldnames = {')
        self.write_line('\'{0}_version\', ...'.format(self.package))
        for extension in plugin['extension']:
            self.write_line('\'{0}_{1}\', ...'.format(self.package, strFunctions.lower_first(extension['name'])))
            num_fields += 1
        for extension in plugin['lo_extension']:
            self.write_line('\'{0}_{1}\', ...'.format(self.package, strFunctions.lower_first(extension['name'])))
            num_fields += 1
        for attrib in plugin['attribs']:
            self.write_line('\'{0}_{1}\', ...'.format(self.package, strFunctions.lower_first(attrib['name'])))
            num_fields += 1
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()


    def write_get_class_fieldname(self, sbmlclass):
        self.write_line('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
        self.write_line_verbatim('function [SBMLfieldnames, nNumberFields] = get{0}Fieldnames(level, ...'.format(sbmlclass['name']))
        self.write_line('                                                                      version, pkgVersion)')
        self.up_indent()

        self.write_line('if (~isValidLevelVersionCombination(level, version))')
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

        num_fields = 9
        self.write_line('SBMLfieldnames = {')
        self.write_line('\'typecode\', ...')
        self.write_line('\'metaid\', ...')
        self.write_line('\'notes\', ...')
        self.write_line('\'annotation\', ...')
        self.write_line('\'cvterms\', ...')
        self.write_line('\'sboTerm\', ...')
        for attrib in sbmlclass['attribs']:
            self.write_line('\'{0}_{1}\', ...'.format(self.package, attrib['name']))
            num_fields += 1
        self.write_line('\'level\', ...')
        self.write_line('\'version\', ...')
        self.write_line('\'{0}_version\', ...'.format(self.package))
        self.write_line('};')
        self.write_line('nNumberFields = {0};'.format(num_fields))

        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
        self.down_indent()


    def write_get_fieldname_function(self):
        self.write_line('function [found, fhandle] = get{0}FieldnameFunction(typecode)'.format(self.up_pack))
        self.up_indent()
        self.write_line('found = 1;')
        self.write_line('switch (typecode)')
        self.up_indent()
        for sbmlclass in self.sbml_classes:
            self.write_line_verbatim('case {0}\'{1}\', \'{3}\', \'{4}\', \'{6}_{4}\'{5}'.format(
                self.open_br, sbmlclass['typecode'], sbmlclass['name'].upper(), sbmlclass['name'], strFunctions.lower_first(sbmlclass['name']),
                self.close_br, self.package))
            self.up_indent()
            self.write_line('fhandle = str2func(\'get{0}Fieldnames\');'.format(sbmlclass['name']))
            self.down_indent()
        for plugin in self.plugins:
            self.write_line_verbatim('case {0}\'SBML_{1}_{2}\', \'{1}{3}\', \'SBML_{2}\', \'{3}\', \'{4}\'{5}'.format(
                self.open_br, self.up_pack, plugin['sbase'].upper(), plugin['sbase'], plugin['sbase'].lower(),
                self.close_br))
            self.up_indent()
            self.write_line('fhandle = str2func(\'get{0}{1}Fieldnames\');'.format(self.up_pack, plugin['sbase']))
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
        self.write_line('function extend = is{0}Extension(typecode)'.format(self.up_pack))
        self.up_indent()
        self.write_line('extend = 0;')
        self.write_line('switch (typecode)')
        self.up_indent()
        for plugin in self.plugins:
            self.write_line_verbatim('case {0}\'SBML_{1}_{2}\', \'{1}{3}\', \'SBML_{2}\', \'{3}\', \'{4}\'{5}'.format(
                self.open_br, self.up_pack, plugin['sbase'].upper(), plugin['sbase'], plugin['sbase'].lower(),
                self.close_br))
            self.up_indent()
            self.write_line('extend = 1;')
            self.down_indent()
        self.down_indent()
        self.write_line('end;')
        self.down_indent()


    def write_get_field(self):
        self.write_line('if strcmp(pkg, \'{0}\'))'.format(self.package))
        self.up_indent()
        self.write_line('if (extension)')
        self.up_indent()
        self.write_line('if (is{0}Extension(typecode))'.format(self.up_pack))
        self.up_indent()
        self.write_line('[found, fhandle] = get{0}FieldnameFunction(typecode);'.format(self.up_pack))
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('else')
        self.up_indent()
        self.write_line('[found, fhandle] = get{0}FieldnameFunction(typecode);'.format(self.up_pack))
        self.down_indent()
        self.write_line('end;')
        self.down_indent()
        self.write_line('end;')
