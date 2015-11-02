#!/usr/bin/env python
#
# @file    ValidationRulesGeneral.py
# @brief   class to generate the validation rules for a plugin
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

from util import strFunctions


class ValidationRulesGeneral():
    """Class for creating the general validation rules"""

    def __init__(self, spec_name, number, package, pkg_ref, level, version,
                 pkg_version):
        # members from object
        self.fullname = spec_name
        self.number = number
        self.offset = number
        self.package = package.lower()
        self.pkg_ref = pkg_ref
        self.up_package = strFunctions.upper_first(self.package)

        self.full_pkg_command = \
            '\\{}Package'.format(strFunctions.texify(self.fullname))
        # useful repeated text strings
        self.valid = '\\validRule{'
        self.start_b = '{'
        self.end_b = '}'

        self.level = level
        self.version = version
        self.pkg_version = pkg_version

        self.rules = []
        self.tc = 'TBC'

    ########################################################################

    # Write a structure detailing the rules for the class

    def determine_rules(self):
        # write rules increasing the number
        self.number += 10100
        rule = self.write_unknown_rule(self)
        self.add_rule(rule)

        self.number += 1
        rule = self.write_ns_rule(self)
        self.add_rule(rule)

        self.number += 1
        rule = self.write_element_not_ns_rule(self)
        self.add_rule(rule)

        self.number = self.offset + 10301
        rule = self.write_id_rule(self)
        self.add_rule(rule)

        self.number += 1
        rule = self.write_id_syntax_rule(self)
        self.add_rule(rule)

        self.number = self.offset + 20101
        rule = self.write_reqd_rule(self)
        self.add_rule(rule)

        self.number += 1
        rule = self.write_reqd_bool_rule(self)
        self.add_rule(rule)

        self.number += 1
        rule = self.write_reqd_value_rule(self)
        self.add_rule(rule)

    def add_rule(self, rule):
        if rule is not None:
            self.rules.append(rule)
        else:
            # we did not write a rule
            self.number -= 1

###############################################################################

    # Functions for parsing each rule type

    # write rule about ns
    @staticmethod
    def write_unknown_rule(self):
        text = 'Unknown error from {}'.format(self.up_package)
        ref = ''
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Unknown error from {}'.format(self.up_package)
        lib_ref = ''
        tc = '{}Unknown'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    # write rules about ns
    @staticmethod
    def write_ns_rule(self):
        text = 'To conform to the {0} specification for SBML Level~{1} ' \
               'Version~{2}, an SBML document must declare the use of the ' \
               'following XML Namespace: \\uri{3}http://www.sbml.org/sbml/' \
               'level{1}/version{2}/{4}/version{5}{6}.'\
            .format(self.full_pkg_command, self.level, self.version,
                    self.start_b, self.package, self.pkg_version, self.end_b)
        ref = '{} {}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('xml-namespace', False))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'The {} namespace is not correctly ' \
                'declared.'.format(self.up_package)
        lib_ref = 'L3V1 {} V1 Section 3.1'.format(self.up_package)
        tc = '{}NSUndeclared'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    def write_element_not_ns_rule(self):
        text = 'Wherever they appear in an SBML document, elements and ' \
               'attributes from the {} package must be declared either ' \
               'implicitly or explicitly to be in the XML namespace ' \
               '\\uri{}http://www.sbml.org/sbml/level{}/version{}' \
               '/{}/version{}{}.'\
            .format(self.full_pkg_command, self.start_b, self.level,
                    self.version, self.package, self.pkg_version, self.end_b)
        ref = '{} {}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('xml-namespace', False))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Element not in {} namespace'.format(self.up_package)
        lib_ref = 'L3V1 {} V1 Section 3.1'.format(self.up_package)
        tc = '{}ElementNotInNs'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    def write_id_rule(self):
        text = '(Extends validation rule \\#10301 in the \\sbmlthreecore ' \
               'specification. TO DO list scope of ids)'
        ref = '{} {}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('primitive-types', False))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Duplicate \'id\' attribute value'
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        tc = '{}DuplicateComponentId'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    def write_id_syntax_rule(self):
        text = 'The value of a {0} must conform to the syntax of ' \
               'the \\class{1}SBML{2} data type \\primtype{1}SId{2}'\
            .format(strFunctions.wrap_token('id', self.package),
                    self.start_b, self.end_b)
        ref = '{} {}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('primitive-types', False))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Invalid SId syntax'.format(self.up_package)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        tc = '{}IdSyntaxRule'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    def write_reqd_rule(self):
        text = 'In all SBML documents using the \\{}Package, the ' \
               '\\class{}SBML{} object must have the {} attribute.'\
            .format(strFunctions.upper_first(self.package), self.start_b,
                    self.end_b,
                    strFunctions.wrap_token('required', self.package))
        ref = 'SBML Level~3 Version~1 Core, Section~4.1.2.'
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Required {}:required attribute on <sbml>'.format(self.package)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        tc = '{}AttributeRequiredMissing'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    def write_reqd_bool_rule(self):
        text = 'The value of attribute {0} on the \\class{1}SBML{2} object ' \
               'must be of data type \\primtype{1}boolean{2}.' \
            .format(strFunctions.wrap_token('required', self.package),
                    self.start_b, self.end_b)
        ref = 'SBML Level~3 Version~1 Core, Section~4.1.2.'
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'The {}:required attribute must be Boolean'.format(self.package)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        tc = '{}AttributeRequiredMustBeBoolean'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    def write_reqd_value_rule(self):
        text = 'The value of attribute {0} on the \\class{1}SBML{2} object ' \
               'must be set to \\val{1}{3}{2}.' \
            .format(strFunctions.wrap_token('required', self.package),
                    self.start_b, self.end_b, 'false')
        ref = '{} {}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('xml-namespace', False))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'The {}:required attribute must be \'FIX ME\''.format(self.package)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        tc = '{}AttributeRequiredMustHaveValue'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})
