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
        self.package = package.lower()
        self.pkg_ref = pkg_ref
        self.up_package = strFunctions.upper_first(self.package)

        self.full_pkg_command = '\\{}Package'.format(strFunctions.texify(self.fullname))
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
        self.number += 10101
        rule = self.write_ns_rule(self)
        self.add_rule(rule)

        # self.number += 1
        # rule = self.write_package_object_rule(self)
        # self.add_rule(rule)
        #
        # for i in range(0, len(self.reqd_att)):
        #     self.number += 1
        #     rule = self.write_attribute_type_rule(self, self.reqd_att[i])
        #     self.add_rule(rule)
        #
        # for i in range(0, len(self.opt_att)):
        #     self.number += 1
        #     rule = self.write_attribute_type_rule(self, self.opt_att[i])
        #     self.add_rule(rule)
        #
        # if len(self.opt_child_lo_elem) > 0:
        #     self.number += 1
        #     rule = self.write_optional_lo_rule()
        #     self.add_rule(rule)
        #
        # for i in range(0, len(self.opt_child_lo_elem)):
        #     self.number += 1
        #     rule = \
        #         self.write_core_subobject_rule(self, self.opt_child_lo_elem[i])
        #     self.add_rule(rule)
        #
        # for i in range(0, len(self.reqd_child_lo_elem)):
        #     self.number += 1
        #     rule = \
        #         self.write_core_subobject_rule(self,
        #                                        self.reqd_child_lo_elem[i])
        #     self.add_rule(rule)
        #
        # for i in range(0, len(self.opt_child_lo_elem)):
        #     self.number += 1
        #     rule = \
        #         self.write_core_attribute_rule(self, self.opt_child_lo_elem[i])
        #     self.add_rule(rule)
        #
        # for i in range(0, len(self.reqd_child_lo_elem)):
        #     self.number += 1
        #     rule = \
        #         self.write_core_attribute_rule(self,
        #                                        self.reqd_child_lo_elem[i])
        #     self.add_rule(rule)
        #
    def add_rule(self, rule):
        if rule is not None:
            self.rules.append(rule)
        else:
            # we did not write a rule
            self.number -= 1

###############################################################################

    # Functions for parsing each rule type

    # write rule about attribute type
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
        short = 'The {} namespace is not correctly declared.'.format(self.up_package)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        tc = '{}NSUndeclared'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    # write core attribute rule
    def write_core_attribute_rule(self, lo_child=None):
        if lo_child is None:
            text = '{0} {1} object may have the optional SBML Level~3 ' \
                   'Core attributes {2} and {3}. No other attributes from the ' \
                   'SBML Level 3 Core namespaces are permitted on {4} {1}.'\
                .format(self.indef_u, self.formatted_name,
                        strFunctions.wrap_token('metaid'),
                        strFunctions.wrap_token('sboTerm'), self.indef)
            ref = 'SBML Level~3 Version~1 Core, Section~3.2.'
            sev = 'ERROR'
            tc = '{}{}AllowedCoreAttributes'.format(self.up_package, self.name)
        else:
            lo_name = strFunctions.plural(lo_child['name'])
            text = 'A {0} object may have the optional SBML Level~3 ' \
                   'Core attributes {1} and {2}. No other attributes from the ' \
                   'SBML Level 3 Core namespaces are permitted on a {0} object.'\
                .format(strFunctions.get_element_name(lo_child),
                        strFunctions.wrap_token('metaid'),
                        strFunctions.wrap_token('sboTerm'))
            ref = '{}, {}.'\
                .format(self.pkg_ref, strFunctions.wrap_section(self.name))
            sev = 'ERROR'
            tc = '{}{}LO{}AllowedCoreAttributes'.format(self.up_package,
                                                        self.name, lo_name)
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Core attributes allowed on <{}>.'.format(self.name)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    # write core subobjects rule
    @staticmethod
    def write_core_subobject_rule(self, lo_child=None):
        if lo_child is None:
            text = '{0} {1} object may have the optional SBML Level~3 ' \
                   'Core subobjects for notes and annotations. No other ' \
                   'elements from the SBML Level 3 Core namespaces are ' \
                   'permitted on {2} {1}.'\
                .format(self.indef_u, self.formatted_name, self.indef)
            ref = 'SBML Level~3 Version~1 Core, Section~3.2.'
            sev = 'ERROR'
            tc = '{}{}AllowedCoreElements'.format(self.up_package, self.name)
        else:
            if 'type' in lo_child:
                loname = strFunctions.get_element_name(lo_child)
                element = lo_child['element']
                lo_name = strFunctions.plural(element)
            else:
                # we are in a plugin so have different fields
                loname = strFunctions.cap_list_of_name(lo_child['name'])
                element = lo_child['name']
                lo_name = strFunctions.plural(element)
            text = 'Apart from the general notes and annotations subobjects ' \
                   'permitted on all SBML objects, a {} container object ' \
                   'may only contain \{} objects.'\
                .format(loname, element)
            ref = '{}, {}.'\
                .format(self.pkg_ref, strFunctions.wrap_section(self.name))
            sev = 'ERROR'
            tc = '{}{}LO{}AllowedElements'.format(self.up_package, self.name,
                                                  lo_name)
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Core elements allowed on <{}>.'.format(self.name)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    def write_package_attribute_rule(self):
        if len(self.reqd_att) == 0 and len(self.opt_att) == 0:
            return
        reqd = self.parse_required(self, self.reqd_att)
        opt = self.parse_optional(self, self.opt_att)
        no_other_statement = 'No other attributes from the SBML Level 3 {} ' \
                             'namespaces are permitted on {} {} object. '\
            .format(self.fullname, self.indef, self.formatted_name)
        if len(opt) == 0 and len(reqd) > 0:
            text = '{} {} object must have {}. {}'\
                .format(self.indef_u, self.formatted_name,
                        reqd, no_other_statement)
        elif len(reqd) == 0 and len(opt) > 0:
            text = '{} {} object may have {}. {}'\
                .format(self.indef_u, self.formatted_name,
                        opt, no_other_statement)
        else:
            text = '{} {} object must have {}, and may have {}. {}'\
                .format(self.indef_u, self.formatted_name,
                        reqd, opt, no_other_statement)
        ref = '{}, {}.'\
            .format(self.pkg_ref, strFunctions.wrap_section(self.name))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Attributes allowed on <{}>.'.format(self.name)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        tc = '{}{}AllowedAttributes'.format(self.up_package, self.name)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    def write_package_object_rule(self):
        if len(self.reqd_elem) == 0 and len(self.opt_elem) == 0:
            return
        reqd = self.parse_required_elements(self.reqd_elem)
        opt = self.parse_optional_elements(self.opt_elem)
        no_other_statement = 'No other elements from the SBML Level 3 {} ' \
                             'namespaces are permitted on {} {} object. '\
            .format(self.fullname, self.indef, self.formatted_name)
        if len(opt) == 0 and len(reqd) > 0:
            text = '{} {} object must contain {}. {}'\
                .format(self.indef_u, self.formatted_name,
                        reqd, no_other_statement)
        elif len(reqd) == 0 and len(opt) > 0:
            text = '{} {} object may contain {}. {}'\
                .format(self.indef_u, self.formatted_name,
                        opt, no_other_statement)
        else:
            text = '{} {} object must contain {}, and may contain {}. {}'\
                .format(self.indef_u, self.formatted_name,
                        reqd, opt, no_other_statement)
        ref = '{}, {}.'\
            .format(self.pkg_ref, strFunctions.wrap_section(self.name))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Elements allowed on <{}>.'.format(self.name)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        tc = '{}{}AllowedElements'.format(self.up_package, self.name)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    #########################################################################

    # Functions for parsing particular bits
    # parse the required attribute sentence
    @staticmethod
    def parse_required(self, attributes):
        num = len(attributes)
        if num == 0:
            return ''
        elif num == 1:
            return 'the required attribute {}'\
                .format(strFunctions.wrap_token(attributes[0]['name'],
                                                self.package))
        else:
            required_statement = 'the required attributes {}'\
                .format(strFunctions.wrap_token(attributes[0]['name'],
                                                self.package))
            i = 1
            while i < num - 1:
                required_statement += ', {}'\
                    .format(strFunctions.wrap_token(attributes[i]['name'],
                                                    self.package))
                i += 1
            required_statement += ' and {}'\
                .format(strFunctions.wrap_token(attributes[i]['name'],
                                                self.package))
            return required_statement

    # parse the optional attribute sentence
    @staticmethod
    def parse_optional(self, attributes):
        num = len(attributes)
        if num == 0:
            return ''
        elif num == 1:
            return 'the optional attribute {}' \
                .format(strFunctions.wrap_token(attributes[0]['name'],
                                                self.package))
        else:
            optional_statement = 'the optional attributes {}' \
                .format(strFunctions.wrap_token(attributes[0]['name'],
                                                self.package))
            i = 1
            while i < num - 1:
                optional_statement += ', {}' \
                    .format(strFunctions.wrap_token(attributes[i]['name'],
                                                    self.package))
                i += 1
            optional_statement += ' and {}' \
                .format(strFunctions.wrap_token(attributes[i]['name'],
                                                self.package))
            return optional_statement

    # parse the required elements sentence
    @staticmethod
    def parse_required_elements(attributes):
        num = len(attributes)
        if num == 0:
            return ''
        elif num == 1:
            return 'one and only one instance of the {} element'\
                .format(strFunctions.get_element_name(attributes[0]))
        else:
            required_statement = 'one and only one instance of each of the {}'\
                .format(strFunctions.get_element_name(attributes[0]))
            i = 1
            while i < num - 1:
                required_statement += ', {}'\
                    .format(strFunctions.get_element_name(attributes[i]))
                i += 1
            required_statement += ' and \{} elements'\
                .format(strFunctions.get_element_name(attributes[i]))
            return required_statement

    # parse the optional attribute sentence
    @staticmethod
    def parse_optional_elements(attributes):
        num = len(attributes)
        if num == 0:
            return ''
        elif num == 1:
            return 'one and only one instance of the {} element' \
                .format(strFunctions.get_element_name(attributes[0]))
        else:
            optional_statement = 'one and only one instance of each of the {}' \
                .format(strFunctions.get_element_name(attributes[0]))
            i = 1
            while i < num - 1:
                optional_statement += ', {}' \
                    .format(strFunctions.get_element_name(attributes[i]))
                i += 1
            optional_statement += ' and {} elements'\
                .format(strFunctions.get_element_name(attributes[i]))
            return optional_statement

    ########################################################################

    # divide attributes into elements/attributes required and optional
    @staticmethod
    def parse_attributes(self, attributes):
        for i in range(0, len(attributes)):
            texname = strFunctions.replace_digits(attributes[i]['name'])
            attributes[i]['texname'] = texname
            if attributes[i]['type'] == 'element':
                if attributes[i]['reqd'] is True:
                    self.reqd_elem.append(attributes[i])
                else:
                    self.opt_elem.append(attributes[i])
            elif attributes[i]['type'] == 'lo_element' \
                    or attributes[i]['type'] == 'inline_lo_element':
                if attributes[i]['reqd'] is True:
                    self.reqd_child_lo_elem.append(attributes[i])
                    self.reqd_elem.append(attributes[i])
                else:
                    self.opt_elem.append(attributes[i])
                    self.opt_child_lo_elem.append(attributes[i])
            else:
                if attributes[i]['reqd'] is True:
                    self.reqd_att.append(attributes[i])
                else:
                    self.opt_att.append(attributes[i])

    # divide attributes into elements/attributes required and optional
    @staticmethod
    def parse_extensions(self, extensions, lo_extensions):
        if len(extensions) == 0 and len(lo_extensions) == 0:
            return
        for i in range(0, len(extensions)):
            extension = extensions[i]
            if extension['isListOf']:
                self.opt_child_lo_elem.append(extension)
                self.opt_elem.append(extension)
            else:
                self.opt_elem.append(extension)
        for i in range(0, len(lo_extensions)):
            extension = lo_extensions[i]
            if extension['isListOf']:
                self.opt_child_lo_elem.append(extension)
                self.opt_elem.append(extension)
            else:
                self.opt_elem.append(extension)

    ########################################################################

    # deal with enumerations
    @staticmethod
    def parse_enum_values(enum, enums):
        this_enum = None
        for i in range(0, len(enums)):
            if enum == enums[i]['name']:
                this_enum = enums[i]
                break
        if this_enum is None:
            return 'FIX ME: Failed to find the enum {} in parse_enum_values'\
                .format(enum)
        else:
            i = 0
            values = '\"{}\"'.format(this_enum['values'][i]['value'])
            for i in range(1, len(this_enum['values'])-1):
                values += ', \"{}\"'.format(this_enum['values'][i]['value'])
            values += ' or \"{}\"'.format(this_enum['values'][i+1]['value'])
            return values

    #######################################################################

    # functions for listOf child elements

    # might not be lo elements
    def write_optional_lo_rule(self):
        number = len(self.opt_child_lo_elem)
        if number > 1:
            obj = 'objects'
            pred = 'these'
            i = 0
            elements = '{}'.format(strFunctions.get_element_name(
                self.opt_child_lo_elem[i]))
            for i in range(1, number-1):
                elements += ', {}'.format(strFunctions.get_element_name(
                    self.opt_child_lo_elem[i]))
            elements += ' and {}'.format(strFunctions.get_element_name(
                self.opt_child_lo_elem[i+1]))
        else:
            obj = 'object'
            pred = 'this'
            elements = '{}'.format(strFunctions.get_element_name(
                self.opt_child_lo_elem[0]))

        text = 'The {0} sub{1} on {2} {3} object is optional, but if ' \
               'present, {4} container {1} must not be empty.'\
            .format(elements, obj, self.indef, self.formatted_name, pred)
        ref = 'SBML Level~3 Specification for {} Version~1, {}.'\
            .format(self.fullname, strFunctions.wrap_section(self.name))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'No Empty ListOf elements allowed on <{}>.'.format(self.name)
        lib_ref = 'L3V1 {} V1 Section'.format(self.up_package)
        tc = '{}{}EmptyLOElements'.format(self.up_package, self.name, )
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})
