#!/usr/bin/env python
#
# @file    TexMacrosFile.py
# @brief   class to generate the LaTeX macros file
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


import re

from ..base_files import BaseTexFile
from ..util import strFunctions


class TexMacrosFile(BaseTexFile.BaseTexFile):
    """Class for the definition of class name macros in LaTeX"""

    def __init__(self, object_desc):

        # derived members for description
        self.brief_description = 'Macros definition for specification'

        BaseTexFile.BaseTexFile.__init__(self, 'macros', 'tex', object_desc)

        # self.full_pkg_command = '\\{}Package'.format(self.fulltexname)
        # self.brief_pkg_command = '\\{}'.format(self.upper_package)

        self.core_classes = ['Model', 'Compartment', 'Species', 'Parameter',
                             'Rule', 'InitialAssignment', 'Reaction', 'Event',
                             'Constraint', 'SpeciesReference',
                             'EventAssignment',
                             'KineticLaw', 'LocalParameter']

    ########################################################################

    # Write the command for each class
    def write_macro_for_class(self, sbml_class):
        self.write_text_line('\\newcommand{0}\\{1}{2}{0}\\defRef{0}{4}{2}'
                        '{0}{3}{2}{2}'
                             .format(self.start_b, sbml_class['texname'],
                                     self.end_b,
                                     strFunctions.make_tex_class(sbml_class['texname']),
                                     sbml_class['name']))

    # Write commands for each ListOf class
    def write_macro_for_listof(self, sbml_class):
        if sbml_class['hasListOf']:
            if 'lo_elementName' in sbml_class \
                    and sbml_class['lo_elementName'] != '':
                lo_name = strFunctions.upper_first(
                    sbml_class['lo_elementName'])
            else:
                lo_name = strFunctions.cap_list_of_name(sbml_class['name'])
            self.write_text_line('\\newcommand{0}\\{1}{2}{0}\\defRef{0}{1}{2}'
                            '{0}{3}{2}{2}'
                                 .format(self.start_b, lo_name, self.end_b,
                                         strFunctions.make_tex_class(lo_name)))
            # hack for render
            if sbml_class['name'] == 'GradientBase':
                self.write_text_line('\\newcommand{0}\\{4}{2}{0}\\defRef{0}{1}{2}'
                                '{0}{3}{2}{2}'
                                     .format(self.start_b, lo_name, self.end_b,
                                             strFunctions.make_tex_class(lo_name),
                                        'ListOfGradientBases'))
            elif sbml_class['name'] == 'RenderPoint':
                self.write_text_line('\\newcommand{0}\\{4}{2}{0}\\defRef{0}{1}{2}'
                                '{0}{3}{2}{2}'
                                     .format(self.start_b, lo_name, self.end_b,
                                             strFunctions.make_tex_class(lo_name),
                                        'ListOfRenderPoints'))

    # Write commands for each primitive type
    def write_macro_for_enum(self, enum):
        # check for underscores
        cmd_name = re.sub('_t', 't', enum['name'])
        self.write_text_line('\\newcommand{0}\\{1}{2}{0}\\defRef{0}{3}{2}'
                        '{0}{4}{2}{2}'
                             .format(self.start_b, cmd_name,
                                self.end_b, enum['name'],
                                'primitive-types'))

    # Write commands for each plugin
    def write_macro_for_plugin(self, plugin):
        if plugin['sbase'] not in self.core_classes:
            self.write_text_line('\\newcommand{0}\\{1}{2}{0}\\defRef{0}{4}{2}'
                            '{0}{3}{2}{2}'
                                 .format(self.start_b, plugin['sbase'],
                                         self.end_b,
                                         strFunctions.make_tex_class(plugin['sbase']),
                                         plugin['sbase']))

    # Write general commands
    def write_general_commands(self):
        self.write_comment_line('\\newcommand{\\fixttspace}{\\hspace*{1pt}}')

        self.write_text_line('\\newcommand{0}\\const{1}[1]{0}\\texttt{0} #1{1}{1}'
                             .format(self.start_b, self.end_b))
        self.skip_line()
        self.write_text_line('\\newcommand{0}\\sbmlthreecore{1}{0}SBML Level~{2} '
                        'Version~{3} Core\\xspace{1}'.format(self.start_b,
                                                             self.end_b,
                                                             self.level,
                                                             self.version))
        self.write_text_line('\\newcommand{0}{1}{2}{0}\\textsf{0}{3}'
                        '{2} package\\xspace{2}'.format(self.start_b,
                                                        self.full_pkg_command,
                                                        self.end_b,
                                                        self.fullname))
        self.write_text_line('\\newcommand{0}{1}{2}{0}\\textsf{0}{3}{2}'
                        '\\xspace{2}'
                             .format(self.start_b,
                                self.brief_pkg_command,
                                self.end_b,
                                self.fullname))
        self.skip_line()
        self.write_text_line('\\newcommand{0}\\TODO{1}[1]{0}\\colorbox{0}blue{1}'
                        '{0}\\textcolor{0}white{1}{0}TODO: #1{1}{1}{1}'
                             .format(self.start_b, self.end_b))
        self.skip_line()

    #########################################################################
    # Write file

    def write_file(self):
        BaseTexFile.BaseTexFile.write_file(self)
        self.write_general_commands()
        self.skip_line()
        self.write_comment_line('commands for classes')
        for i in range(0, len(self.sbml_classes)):
            # hack for render
            if self.sbml_classes[i]['name'] != "RelAbsVector":
                self.write_macro_for_class(self.sbml_classes[i])
        self.skip_line()
        self.write_comment_line('commands for listOfClasses')
        for i in range(0, len(self.sbml_classes)):
            self.write_macro_for_listof(self.sbml_classes[i])
        self.skip_line()
        self.write_comment_line('commands for types')
        for i in range(0, len(self.enums)):
            self.write_macro_for_enum(self.enums[i])
        for i in range(0, len(self.prim_class)):
            self.write_macro_for_enum(self.prim_class[i])
        self.skip_line()
        self.write_comment_line('commands for plugins')
        for i in range(0, len(self.plugins)):
            self.write_macro_for_plugin(self.plugins[i])

    # override
    def add_file_header(self):
        self.skip_line()
