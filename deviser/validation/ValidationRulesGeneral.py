#!/usr/bin/env python
#
# @file    ValidationRulesGeneral.py
# @brief   class to generate the validation rules for a plugin
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

from ..util import strFunctions, global_variables


class ValidationRulesGeneral:
    """Class for creating the general validation rules"""

    def __init__(self, spec_name, number, package, pkg_ref, level, version,
                 pkg_version, reqd_status, full_pkg_command):
        # members from object
        self.fullname = spec_name
        self.number = number
        self.offset = number
        self.package = package.lower()
        self.pkg_ref = pkg_ref
        self.up_package = strFunctions.upper_first(self.package)
        if reqd_status:
            self.reqd_status = 'true'
        else:
            self.reqd_status = 'false'

        self.full_pkg_command = full_pkg_command
        # useful repeated text strings
        self.valid = '\\validRule{'
        self.start_b = '{'
        self.end_b = '}'

        self.level = level
        self.version = version
        self.pkg_version = pkg_version

        self.rules = []
        self.tc = 'TBC'
        # constants for rules
        if global_variables.is_sbml:
            self.lib_ref = 'L3V1 {0} V1 Section'.format(self.up_package)
            self.up_package = strFunctions.upper_first(self.package)
        else:
            self.lib_ref = '{0} L{1}V{2} Section '.format(self.up_package.upper(), self.level, self.version)
            self.up_package = self.package.upper()

    ########################################################################

    # Write a structure detailing the rules for the class

    def determine_rules(self):
        # write rules increasing the number
        if global_variables.is_sbml:
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

            if global_variables.is_package:
                self.number = self.offset + 20101
                rule = self.write_reqd_rule(self)
                self.add_rule(rule)

                self.number += 1
                rule = self.write_reqd_bool_rule(self)
                self.add_rule(rule)

                self.number += 1
                rule = self.write_reqd_value_rule(self)
                self.add_rule(rule)
            else:
                self.number += 1
                rule = self.write_metaid_syntax_rule(self)
                self.add_rule(rule)

                self.number = self.offset + 20101
                rule = self.write_valid_ns_rule(self)
                self.add_rule(rule)

                self.number += 1
                rule = self.write_allowed_attributes_rule(self)
                self.add_rule(rule)

                self.number += 1
                rule = self.write_empty_list_rule(self)
                self.add_rule(rule)
        else:
            self.number += 10100
            rule = self.write_unknown_rule(self)
            self.add_rule(rule)

            self.number += 1
            rule = self.write_ns_rule(self)
            self.add_rule(rule)

            self.number += 1
            rule = self.write_element_not_ns_rule(self)
            self.add_rule(rule)

            self.number = 10201
            rule = self.write_metaid_syntax_rule(self)
            self.add_rule(rule)

            self.number = 10301
            rule = self.write_annotation_rule(self, 1)
            self.add_rule(rule)

            self.number += 1
            rule = self.write_annotation_rule(self, 2)
            self.add_rule(rule)

            self.number += 1
            rule = self.write_annotation_rule(self, 3)
            self.add_rule(rule)

            self.number = 10401
            rule = self.write_notes_rule(self, 1)
            self.add_rule(rule)

            self.number += 1
            rule = self.write_notes_rule(self, 2)
            self.add_rule(rule)

            self.number += 1
            rule = self.write_notes_rule(self, 3)
            self.add_rule(rule)

            self.number += 1
            rule = self.write_notes_rule(self, 4)
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
        text = 'Unknown error from {0}'.format(self.up_package.upper())
        ref = ''
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'Unknown error from {0}'.format(self.up_package.upper())*10
        tc = global_variables.unknown_error
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    # write rules about ns
    @staticmethod
    def write_ns_rule(self):
        if global_variables.is_sbml:
            text = 'To conform to the {0} specification for {7} Level~{1} ' \
                   'Version~{2}, an {7} document must declare ' \
                   '\\uri{3}http://www.sbml.org/sbml/' \
                   'level{1}/version{2}/{4}/version{5}{6} as the XMLNamespace ' \
                   'to use for elements of this package.'\
                .format(self.full_pkg_command, self.level, self.version,
                        self.start_b, self.package, self.pkg_version, self.end_b,
                        global_variables.language.upper())
        else:
            text = 'To conform to the {0} specification for {7} Level~{1} ' \
                   'Version~{2}, an {7} document must declare ' \
                   '\\uri{3}{8}{6} as the XMLNamespace ' \
                   'to use for elements of this package.'\
                .format(self.full_pkg_command, self.level, self.version,
                        self.start_b, self.package, self.pkg_version, self.end_b,
                        global_variables.language.upper(), global_variables.namespaces[0]['namespace'])

        ref = '{0} {1}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('xml-namespace', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'The {0} namespace is not correctly ' \
                'declared.'.format(self.up_package)

        tc = '{0}NSUndeclared'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_element_not_ns_rule(self):
        if global_variables.is_sbml:
            text = 'Wherever they appear in an SBML document, elements and ' \
                   'attributes from the {0} must use the ' \
                   '\\uri{1}http://www.sbml.org/sbml/level{2}/version{3}' \
                   '/{4}/version{5}{6} namespace, declaring so either explicitly ' \
                   'or implicitly.'\
                .format(self.full_pkg_command, self.start_b, self.level,
                        self.version, self.package, self.pkg_version, self.end_b)
        else:
            text = 'Wherever they appear in a {7} document, elements and ' \
                   'attributes from the {0} must use the ' \
                   '\\uri{1}{8}{6} namespace, declaring so either explicitly ' \
                   'or implicitly.' \
                .format(self.full_pkg_command, self.start_b, self.level,
                        self.version, self.package, self.pkg_version, self.end_b,
                        global_variables.language.upper(), global_variables.namespaces[0]['namespace'])
        ref = '{0} {1}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('xml-namespace', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'Element not in {0} namespace'.format(self.up_package)
        tc = '{0}ElementNotInNs'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_id_rule(self):
        text = '(Extends validation rule \\#10301 in the \\sbmlthreecore ' \
               'specification. TO DO list scope of ids)'
        ref = 'SBML Level~3 Version~1 Core, Section~3.1.7.'
        # ref = '{0} {1}.'\
        #     .format(self.pkg_ref,
        #             strFunctions.wrap_section('primitive-types', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'Duplicate \'id\' attribute value'
        tc = '{0}DuplicateComponentId'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_id_syntax_rule(self):
        text = 'The value of a {0} must conform to the syntax of ' \
               'the \\class{1}SBML{2} data type \\primtype{1}SId{2}'\
            .format(strFunctions.wrap_token('id', self.package),
                    self.start_b, self.end_b)
        ref = 'SBML Level~3 Version~1 Core, Section~3.1.7.'
        # ref = '{0} {1}.'\
        #     .format(self.pkg_ref,
        #             strFunctions.wrap_section('primitive-types', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'Invalid SId syntax'.format(self.up_package)
        tc = '{0}IdSyntaxRule'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_reqd_rule(self):
        text = 'In all SBML documents using the {0}, the ' \
               '\\class{1}SBML{2} object must have the {3} attribute.'\
            .format(self.full_pkg_command, self.start_b,
                    self.end_b,
                    strFunctions.wrap_token('required', self.package))
        ref = 'SBML Level~3 Version~1 Core, Section~4.1.2.'
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'Required {0}:required attribute on <sbml>'.format(self.package)
        tc = '{0}AttributeRequiredMissing'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_reqd_bool_rule(self):
        text = 'The value of attribute {0} on the \\class{1}SBML{2} object ' \
               'must be of data type \\primtype{1}boolean{2}.' \
            .format(strFunctions.wrap_token('required', self.package),
                    self.start_b, self.end_b)
        ref = 'SBML Level~3 Version~1 Core, Section~4.1.2.'
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'The {0}:required attribute must be Boolean' \
                ''.format(self.package)
        tc = '{0}AttributeRequiredMustBeBoolean'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_reqd_value_rule(self):
        text = 'The value of attribute {0} on the \\class{1}SBML{2} object ' \
               'must be set to \\val{1}{3}{2}.' \
            .format(strFunctions.wrap_token('required', self.package),
                    self.start_b, self.end_b, self.reqd_status)
        ref = '{0} {1}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('xml-namespace', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'The {0}:required attribute must be \'{1}\'' \
                ''.format(self.package, self.reqd_status)
        tc = '{0}AttributeRequiredMustHaveValue'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_metaid_syntax_rule(self):
        if global_variables.is_sbml:
            text = 'The value of a {0} must conform to the syntax of ' \
                   'the XML Type ID'\
                .format(strFunctions.wrap_token('metaid', self.package))
            ref = 'SBML Level~3 Version~1 Core, Section~3.1.6.'
        else:
            text = 'The value of a {0} must conform to the syntax of ' \
                   'the XML Type ID'\
                .format(strFunctions.wrap_token('metaid', self.package))
            ref = 'metaid'

        # ref = '{0} {1}.'\
        #     .format(self.pkg_ref,
        #             strFunctions.wrap_section('primitive-types', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'Invalid SId syntax'.format(self.up_package)
        tc = '{0}InvalidMetaidSyntax'.format(global_variables.prefix)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_valid_ns_rule(self):
        text = 'Invalid namespace declared.'
        ref = '{0} {1}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('primitive-types', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'Invalid namespace'.format(self.up_package)
        tc = 'InvalidNamespaceOn{0}'.format(global_variables.prefix)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_allowed_attributes_rule(self):
        text = 'Allowed attributes'
        ref = '{0} {1}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('primitive-types', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'Allowed attributes'.format(self.up_package)
        tc = 'AllowedAttributes'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_empty_list_rule(self):
        text = 'No empty lists'
        ref = '{0} {1}.'\
            .format(self.pkg_ref,
                    strFunctions.wrap_section('primitive-types', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        short = 'No empty listOf'.format(self.up_package)
        tc = '{0}EmptyListElement'.format(global_variables.prefix)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_annotation_rule(self, num):
        if num == 1:
            text = 'Every top-level XML element within an \\{0} object must ' \
                   'have an XML namespace declared.'.format(global_variables.annot_element)
            short = 'No ns for {0}'.format(global_variables.annot_element)
            tc = '{0}NoAnnotationNS'.format(global_variables.prefix)
        elif num == 2:
            text = 'A given XML namespace cannot be the namespace of more than one top-level' \
                   'element within a given \\{0} object.'.format(global_variables.annot_element)
            short = 'Repeat ns for {0}'.format(global_variables.annot_element)
            tc = '{0}RepeatAnnotationNS'.format(global_variables.prefix)
        else:
            text = 'A given {0} element may contain at most one \\{1} ' \
                   'subobject.'.format(global_variables.language.upper(), global_variables.annot_element)
            short = 'Only one {0}'.format(global_variables.annot_element)
            tc = '{0}OnlyOneAnnotation'.format(global_variables.prefix)

        ref = '{0} {1}.' \
            .format(self.pkg_ref,
                    strFunctions.wrap_section('annotation-use', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})

    @staticmethod
    def write_notes_rule(self, num):
        if num == 1:
            text = 'The contents of a \\{0} object must be explicitly placed in the ' \
                   'XHTML XML namespace. '.format('Notes')
            short = 'Notes not in XHTML'
            tc = 'NotesInXHTML'
        elif num == 2:
            text = 'The contents of a \\{0} object must not contain an XML declaration, ' \
                   '\\ie a string of the form \\val{1}<?xml version="1.0" encoding="UTF-8"?>{2} or ' \
                   'similar.'.format('Notes', '{', '}')
            short = 'No XML decl in Notes'
            tc = 'XMLDeclNotes'
        elif num == 3:
            text = 'The content of a \\{0} object must not contain an XML DOCTYPE declaration, ' \
                   '\\ie a string beginning with the characters \\val{1}<!DOCTYPE{2}.'.format('Notes', '{', '}')
            short = 'No DOCTYPE in Notes'
            tc = 'DOCTYPEInNotes'
        else:
            text = 'A given {0} element may contain at most one \\{1} ' \
                   'subobject.'.format(global_variables.language.upper(), 'Notes')
            short = 'Only one {0}'.format('Notes')
            tc = '{0}OnlyOneNotes'.format(global_variables.prefix)
        ref = '{0} {1}.' \
            .format(self.pkg_ref,
                    strFunctions.wrap_section('notes', False))
        sev = 'ERROR'
        lib_sev = '{0}_SEV_ERROR'.format(global_variables.up_full_lib)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': self.lib_ref})
