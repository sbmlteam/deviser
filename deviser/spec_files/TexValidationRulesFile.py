#!/usr/bin/env python
#
# @file    TexValidationRules.py
# @brief   class to generate the LaTeX apdx-validation file
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

import os
import re

from ..base_files import BaseTexFile
from ..util import global_variables, strFunctions
from ..validation import ValidationRulesForClass
from ..validation import ValidationRulesForPlugin
from ..validation import ValidationRulesGeneral


class TexValidationRulesFile(BaseTexFile.BaseTexFile):
    """Class for the validation appendix in LaTeX"""

    def __init__(self, object_desc):
        # derived members for description
        self.brief_description = 'Validation rules appendix for specification'

        # useful repeated text strings
        self.valid = '\\validRule{'
        self.consist = '\\consistencyRule{'

        BaseTexFile.BaseTexFile.__init__(self, 'apdx-validation', 'tex',
                                         object_desc)
        if global_variables.is_sbml:
            self.pkg_ref = 'SBML Level~{0} Specification for {1}, ' \
                           'Version~{2}'.format(self.level,
                                                self.fullname, self.pkg_version)
            self.full_pkg_command = '\\{0}Package'.format(self.fulltexname)
            self.brief_pkg_command = '\\{0}'.format(self.upper_package)
            self.reqd_status = object_desc['required']
        else:
            self.pkg_ref = '{3} Level~{0} Specification for {1}, ' \
                           'Version~{2}'.format(self.level,
                                                self.fullname, self.version,
                                                global_variables.language.upper())
            self.full_pkg_command = '\\{0}'.format(self.fulltexname)
            self.brief_pkg_command = '\\{0}'.format(self.upper_package)
            self.reqd_status = False

    ########################################################################

    # Write a rule
    def write_rule(self, rule, name='', texname=''):
        substitute_name = False
        if name != texname:
            substitute_name = True

        text = rule['text']
        ref = rule['reference']
        if substitute_name:
            text = re.sub(name, texname, text)
            ref = re.sub(name.lower(), texname.lower(), ref)

        if rule['severity'] == 'ERROR':
            severity = self.valid
        else:
            severity = self.consist

        if global_variables.is_sbml:
            self.write_text_line('{0}{1}-{2}{3}{4}{5} (Reference: {6}){7}'
                                 .format(severity, self.package,
                                    rule['number']-self.offset,
                                    self.end_b, self.start_b, text,
                                    ref, self.end_b))
        else:
            self.write_text_line('{0}{1}-{2}{3}{4}{5} (Reference: {6}){7}'
                                 .format(severity, global_variables.language,
                                    rule['number'],
                                    self.end_b, self.start_b, text,
                                    ref, self.end_b))

    ####################################################################

    def write_general_rules(self, rules):
        self.write_text_line('\subsubsection*{General rules about this package}')
        self.skip_line()
        for i in range(1, 3):
            self.write_rule(rules[i])
            self.skip_line()

    def write_identifier_rules(self, rules):
        self.write_text_line(
            '\subsubsection*{General rules about identifiers}')
        self.skip_line()
        if global_variables.is_sbml:
            for i in range(3, 5):
                self.write_rule(rules[i])
                self.skip_line()
        else:
            self.write_rule(rules[3])
            self.skip_line()

    def write_rules_for_annotation(self, rules):
        """
        Write the annotation rules for another library
        :param rules:
        :return:
        """
        self.write_text_line(
            '\subsubsection*{0}General rules for \\token{0}{1}{2} elements{2}'.format('{', global_variables.annot_element, '}'))
        self.skip_line()
        for i in range(4, 7):
            self.write_rule(rules[i])
            self.skip_line()

    def write_rules_for_notes(self, rules):
        """
        Write the notes rules for another library
        :param rules:
        :return:
        """
        self.write_text_line(
            '\subsubsection*{General rules for \\token{notes} elements}')
        self.skip_line()
        for i in range(7, 11):
            self.write_rule(rules[i])
            self.skip_line()

    def write_extended_sbml_rules(self, rules):
        self.write_text_line('\subsubsection*{Rules for the '
                        'extended \\class{SBML} class}')
        self.skip_line()
        for i in range(5, 8):
            self.write_rule(rules[i])
            self.skip_line()

    # Write rules for a plugin
    def write_rules_for_plugin(self, name, rules):
        # section heading
        self.write_text_line('\subsubsection*{Rules for extended \class{'
                             + '{0}'.format(name) + '} object}')
        self.skip_line()

        for i in range(0, len(rules)):
            self.write_rule(rules[i])
            self.skip_line()

    # Write rules for a class
    def write_rules_for_class(self, name, texname, rules):
        # section heading
        self.write_text_line('\subsubsection*{Rules for \class{'
                             + '{0}'.format(name) + '} object}')
        self.skip_line()

        for i in range(0, len(rules)):
            self.write_rule(rules[i], name, texname)
            self.skip_line()

    ########################################################################

    # write parts of file that can be copied from text

    def get_text(self, filename):
        file_in = open(os.path.dirname(__file__) + '/' + filename, 'r')
        intro = file_in.read()
        file_in.close()
        intro = re.sub(r'SHORTNAME', r'\\{0}'.format(self.upper_package),
                       intro)
        intro = re.sub(r'PACKAGENAME', r'\\{0}Package'.format(self.fulltexname),
                       intro)
        intro = re.sub(r'LEVELNUM', r'{0}'.format(self.level), intro)
        intro = re.sub(r'VERSIONNUM', r'{0}'.format(self.version), intro)
        intro = re.sub(r'PKGNAME', r'{0}'.format(self.package), intro)
        return intro

    def write_introduction(self):
        self.write_text_line('\section{Validation of SBML documents}')
        self.write_text_line('\label{apdx-validation}')
        self.skip_line()
        self.write_text_line('\subsection{Validation and consistency rules}')
        self.write_text_line('\label{validation-rules}')
        self.skip_line()
        self.write_text_line(self.get_text('valid_intro_para1.txt'))
        self.skip_line()
        self.write_text_line('\\begin{description}')
        self.skip_line()
        self.write_text_line(self.get_text('valid_intro_para2.txt'))
        self.skip_line()
        self.write_text_line(self.get_text('valid_intro_para3.txt'))
        self.skip_line()
        self.write_text_line(self.get_text('valid_intro_para4.txt'))
        self.skip_line()
        self.write_text_line('\\end{description}')
        self.skip_line()
        self.write_text_line(self.get_text('valid_intro_para5.txt'))
        self.skip_line()
        self.write_text_line(self.get_text('valid_intro_para6.txt'))
        self.skip_line()

    ########################################################################
    # Write file

    def write_file(self):
        BaseTexFile.BaseTexFile.write_file(self)
        self.skip_line()
        self.write_introduction()
        rules = ValidationRulesGeneral.ValidationRulesGeneral(
            self.fullname, self.offset,
            self.package, self.pkg_ref, self.level, self.version,
            self.pkg_version, self.reqd_status, self.full_pkg_command)
        rules.determine_rules()
        self.write_general_rules(rules.rules)
        self.write_identifier_rules(rules.rules)
        if global_variables.is_sbml:
            self.write_to_do('ANY LIST OF ELEMENTS THAT HAVE ATTRIBUTES')
            self.write_extended_sbml_rules(rules.rules)
        else:
            self.write_rules_for_annotation(rules.rules)
            self.write_rules_for_notes(rules.rules)
        number = self.offset + 20200 if global_variables.is_sbml else 20100
        for i in range(0, len(self.plugins)):
            rules = ValidationRulesForPlugin.ValidationRulesForPlugin(
                self.plugins[i], self.fullname, number,
                self.package, self.pkg_ref)
            rules.determine_rules()
            self.write_rules_for_plugin(self.plugins[i]['sbase'], rules.rules)
            self.skip_line()
            number += 100
        for i in range(0, len(self.sbml_classes)):
            # hack for render
            if self.sbml_classes[i]['name'] == 'RelAbsVector':
                continue
            rules = ValidationRulesForClass\
                .ValidationRulesForClass(self.sbml_classes[i],
                                         self.fullname, number, self.package,
                                         self.pkg_ref)
            rules.determine_rules()
            self.write_rules_for_class(self.sbml_classes[i]['name'],
                                       self.sbml_classes[i]['texname'],
                                       rules.rules)
            self.skip_line()
            if not global_variables.is_sbml:
                for att in self.sbml_classes[i]['attribs']:
                    if att['type'] == 'lo_element':
                        rules.rules = []
                        number += 100
                        rules.number = number

                        rules.add_lo_rules()
                        self.write_rules_for_class(strFunctions.cap_list_of_name_no_prefix(att['name']),
                                                   att['texname'], rules.rules)
                        self.skip_line()

            number += 100

    # override
    def add_file_header(self):
        self.write_comment_line('-*- TeX-master: "main"; fill-column: 72 -*-')
