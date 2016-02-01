#!/usr/bin/env python
#
# @file    ValidationRulesForPlugins.py
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


class ValidationRulesForPlugin():
    """Class for creating the validation rules for an plugin object"""

    def __init__(self, object_desc, spec_name, number, package, pkg_ref):
        # members from object
        self.name = object_desc['sbase']
        self.fullname = spec_name
        self.number = number
        self.package = package.lower()
        self.pkg_ref = pkg_ref
        self.up_package = strFunctions.upper_first(self.package)

        # useful repeated text strings
        self.valid = '\\validRule{'
        self.start_b = '{'
        self.end_b = '}'

        self.formatted_name = '\{0}'.format(object_desc['sbase'])
        self.indef = strFunctions.get_indefinite(object_desc['sbase'])
        self.indef_u = strFunctions.upper_first(self.indef)
        self.lower_name = strFunctions.lower_first(self.name)

        self.reqd_att = []
        self.opt_att = []
        self.reqd_elem = []
        self.opt_elem = []
        self.reqd_child_lo_elem = []
        self.opt_child_lo_elem = []

        self.parse_attributes(self, object_desc['attribs'])
        self.parse_extensions(self, object_desc['extension'],
                              object_desc['lo_extension'])
        self.rules = []
        self.tc = 'TBC'

    ########################################################################

    # Write a structure detailing the rules for the class

    def determine_rules(self):
        # write rules increasing the number
        self.number += 1
        rule = self.write_package_attribute_rule(self)
        self.add_rule(rule)

        self.number += 1
        rule = self.write_package_object_rule(self)
        self.add_rule(rule)

        for i in range(0, len(self.reqd_att)):
            self.number += 1
            rule = self.write_attribute_type_rule(self, self.reqd_att[i])
            self.add_rule(rule)

        for i in range(0, len(self.opt_att)):
            self.number += 1
            rule = self.write_attribute_type_rule(self, self.opt_att[i])
            self.add_rule(rule)

        if len(self.opt_child_lo_elem) > 0:
            self.number += 1
            rule = self.write_optional_lo_rule()
            self.add_rule(rule)

        for i in range(0, len(self.opt_child_lo_elem)):
            self.number += 1
            rule = \
                self.write_core_subobject_rule(self, self.opt_child_lo_elem[i])
            self.add_rule(rule)

        for i in range(0, len(self.reqd_child_lo_elem)):
            self.number += 1
            rule = \
                self.write_core_subobject_rule(self,
                                               self.reqd_child_lo_elem[i])
            self.add_rule(rule)

        for i in range(0, len(self.opt_child_lo_elem)):
            self.number += 1
            rule = \
                self.write_core_attribute_rule(self, self.opt_child_lo_elem[i])
            self.add_rule(rule)

        for i in range(0, len(self.reqd_child_lo_elem)):
            self.number += 1
            rule = \
                self.write_core_attribute_rule(self,
                                               self.reqd_child_lo_elem[i])
            self.add_rule(rule)

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
    def write_attribute_type_rule(self, attribute):
        att_type = attribute['type']
        att_name = strFunctions.upper_first(attribute['name'])
        name = strFunctions.wrap_token(attribute['name'], self.package)
        rule_type = 'String'
        if att_type == 'SId':
            return
        elif att_type == 'SIdRef':
            ref_name = strFunctions.upper_first(attribute['name'])
            # hack for render
            if ref_name == 'StartHead' or ref_name == 'EndHead':
                ref_name = 'LineEnding'
            text = 'The value of the attribute {0} of {1} {2} object must be ' \
                   'the identifier of an existing \{3} object defined in the ' \
                   'enclosing \Model object.'\
                .format(name, self.indef, self.formatted_name, ref_name)
            rule_type = ref_name
        elif att_type == 'string':
            text = 'The attribute {0} on {1} {2} must have a value of data ' \
                   'type {3}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token('string'))
        elif att_type == 'int' or att_type == 'uint':
            text = 'The attribute {0} on {1} {2} must have a value of data ' \
                   'type {3}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token('integer'))
            rule_type = 'Integer' if att_type == 'int' else 'UnInteger'
        elif att_type == 'double':
            text = 'The attribute {0} on {1} {2} must have a value of data ' \
                   'type {3}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token('double'))
            rule_type = 'Double'
        elif att_type == 'bool' or att_type == 'boolean':
            text = 'The attribute {0} on {1} {2} must have a value of data ' \
                   'type {3}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token('boolean'))
            rule_type = 'Boolean'
        elif att_type == 'enum':
            enum_name = attribute['element']
            enums = attribute['parent']['root']['enums']
            enum_values = self.parse_enum_values(enum_name, enums)
            text = 'The value of the attribute {0} of {1} {2} object must ' \
                   'conform to the syntax of SBML data type {3} and ' \
                   'may only take on the allowed values of {3} defined ' \
                   'in SBML; that is the value must be one of the ' \
                   'following {4}.'.format(name, self.indef,
                                           self.formatted_name,
                                           strFunctions.wrap_enum(enum_name),
                                           enum_values)
            rule_type = '{0}Enum'.format(attribute['element'])
        elif att_type == 'array':
            text = 'The value of the attribute {0} of {1} {2} object must ' \
                   'be an array of values of type {3}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token(attribute['element']))
        else:
            text = 'FIX ME: Encountered an unknown attribute type {0} in ' \
                   'ValidationRulesForClass:write_attribute_type_rule'\
                .format(att_type)

        ref = '{0}, {1}.'\
            .format(self.pkg_ref, strFunctions.wrap_section(self.name))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Attribute {0} values allowed on <{1}>.' \
                ''.format(attribute['name'], self.lower_name)
        lib_ref = 'L3V1 {0} V1 Section'.format(self.up_package)
        tc = '{0}{1}{2}MustBe{3}'.format(self.up_package, self.name, att_name,
                                         rule_type)
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
            tc = '{0}{1}AllowedCoreAttributes'.format(self.up_package,
                                                      self.name)
        else:
            lo_name = strFunctions.plural(lo_child['name'])
            text = 'A {0} object may have the optional SBML Level~3 ' \
                   'Core attributes {1} and {2}. No other attributes from the ' \
                   'SBML Level 3 Core namespaces are permitted on a {0} object.'\
                .format(strFunctions.get_element_name(lo_child),
                        strFunctions.wrap_token('metaid'),
                        strFunctions.wrap_token('sboTerm'))
            ref = '{0}, {1}.'\
                .format(self.pkg_ref, strFunctions.wrap_section(self.name))
            sev = 'ERROR'
            tc = '{0}{1}LO{2}AllowedCoreAttributes'.format(self.up_package,
                                                           self.name, lo_name)
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Core attributes allowed on <{0}>.'.format(self.lower_name)
        lib_ref = 'L3V1 {0} V1 Section'.format(self.up_package)
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
            tc = '{0}{1}AllowedCoreElements'.format(self.up_package, self.name)
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
                   'permitted on all SBML objects, a {0} container object ' \
                   'may only contain \{1} objects.'\
                .format(loname, element)
            ref = '{0}, {1}.'\
                .format(self.pkg_ref, strFunctions.wrap_section(self.name))
            sev = 'ERROR'
            tc = '{0}{1}LO{2}AllowedElements'.format(self.up_package, self.name,
                                                     lo_name)
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Core elements allowed on <{0}>.'.format(self.lower_name)
        lib_ref = 'L3V1 {0} V1 Section'.format(self.up_package)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref,
                     'plugin': True, 'object': self.name, 'lo_object': ['aaa']})

    @staticmethod
    def write_package_attribute_rule(self):
        if len(self.reqd_att) == 0 and len(self.opt_att) == 0:
            return
        reqd = self.parse_required(self, self.reqd_att)
        opt = self.parse_optional(self, self.opt_att)
        no_other_statement = 'No other attributes from the SBML Level 3 {0} ' \
                             'namespaces are permitted on {1} {2} object. '\
            .format(self.fullname, self.indef, self.formatted_name)
        if len(opt) == 0 and len(reqd) > 0:
            text = '{0} {1} object must have {2}. {3}'\
                .format(self.indef_u, self.formatted_name,
                        reqd, no_other_statement)
        elif len(reqd) == 0 and len(opt) > 0:
            text = '{0} {1} object may have {2}. {3}'\
                .format(self.indef_u, self.formatted_name,
                        opt, no_other_statement)
        else:
            text = '{0} {1} object must have {2}, and may have {3}. {4}'\
                .format(self.indef_u, self.formatted_name,
                        reqd, opt, no_other_statement)
        ref = '{0}, {1}.'\
            .format(self.pkg_ref, strFunctions.wrap_section(self.name))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Attributes allowed on <{0}>.'.format(self.lower_name)
        lib_ref = 'L3V1 {0} V1 Section'.format(self.up_package)
        tc = '{0}{1}AllowedAttributes'.format(self.up_package, self.name)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref})

    @staticmethod
    def write_package_object_rule(self):
        if len(self.reqd_elem) == 0 and len(self.opt_elem) == 0:
            return
        reqd = self.parse_required_elements(self.reqd_elem)
        opt = self.parse_optional_elements(self.opt_elem)
        no_other_statement = 'No other elements from the SBML Level 3 {0} ' \
                             'namespaces are permitted on {1} {2} object. '\
            .format(self.fullname, self.indef, self.formatted_name)
        if len(opt) == 0 and len(reqd) > 0:
            text = '{0} {1} object must contain {2}. {3}'\
                .format(self.indef_u, self.formatted_name,
                        reqd, no_other_statement)
        elif len(reqd) == 0 and len(opt) > 0:
            text = '{0} {1} object may contain {2}. {3}'\
                .format(self.indef_u, self.formatted_name,
                        opt, no_other_statement)
        else:
            text = '{0} {1} object must contain {2}, and may contain {3}. {4}'\
                .format(self.indef_u, self.formatted_name,
                        reqd, opt, no_other_statement)
        ref = '{0}, {1}.'\
            .format(self.pkg_ref, strFunctions.wrap_section(self.name))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        short = 'Elements allowed on <{0}>.'.format(self.lower_name)
        lib_ref = 'L3V1 {0} V1 Section'.format(self.up_package)
        tc = '{0}{1}AllowedElements'.format(self.up_package, self.name)
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref,
                     'plugin': True, 'object': self.name, 'lo_object': [],
                     'reqd': self.reqd_elem, 'opt': self.opt_elem})

    # functions for listOf child elements

    def write_optional_lo_rule(self):
        number = len(self.opt_child_lo_elem)
        unusual_min = False
        no_min = 0
        # check whether have unusual minimums
        for i in range(0, number):
            if 'min_lo_children' in self.opt_child_lo_elem[i]:
                min_no = self.opt_child_lo_elem[i]['min_lo_children']
                if min_no == 0:
                    unusual_min = True
                    no_min += 1
                elif min_no > 1:
                    unusual_min = True
        if no_min == number:
            return None
        if number > 1:
            obj = 'objects'
            pred = 'these'
            i = 0
            elements = '{0}'.format(strFunctions.get_element_name(
                self.opt_child_lo_elem[i]))
            for i in range(1, number-1):
                elements += ', {0}'.format(strFunctions.get_element_name(
                    self.opt_child_lo_elem[i]))
            elements += ' and {0}'.format(strFunctions.get_element_name(
                self.opt_child_lo_elem[i+1]))
        else:
            obj = 'object'
            pred = 'this'
            elements = '{0}'.format(strFunctions.get_element_name(
                self.opt_child_lo_elem[0]))

        text = 'The {0} sub{1} on {2} {3} object is optional, but if ' \
               'present, {4} container {1} must not be empty.'\
            .format(elements, obj, self.indef, self.formatted_name, pred)
        if unusual_min:
            for i in range(0, number):
                num = strFunctions.replace_digits(str(
                    self.opt_child_lo_elem[i]['min_lo_children'])).lower()
                name = strFunctions.get_element_name(self.opt_child_lo_elem[i])
                text += 'The {0} must contain at least {1} instances of the ' \
                        '\{2} object.'.format(name, num,
                                              self.opt_child_lo_elem[i]['name'])
        ref = 'SBML Level~3 Specification for {0} Version~1, {1}.'\
            .format(self.fullname, strFunctions.wrap_section(self.name))
        sev = 'ERROR'
        lib_sev = 'LIBSBML_SEV_ERROR'
        lib_ref = 'L3V1 {0} V1 Section'.format(self.up_package)
        if unusual_min:
            short = 'No children in ListOf elements allowed on <{0}>.' \
                    ''.format(self.name)
            tc = '{0}{1}LOElementChildren'.format(self.up_package, self.name, )
        else:
            short = 'No Empty ListOf elements allowed on <{0}>.' \
                    ''.format(self.name)
            tc = '{0}{1}EmptyLOElements'.format(self.up_package, self.name, )
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev, 'typecode': tc,
                     'lib_sev': lib_sev, 'short': short, 'lib_ref': lib_ref,
                     'plugin': True, 'object': self.name,
                     'lo_object': self.opt_child_lo_elem})

    #########################################################################

    # Functions for parsing particular bits
    # parse the required attribute sentence
    @staticmethod
    def parse_required(self, attributes):
        num = len(attributes)
        if num == 0:
            return ''
        elif num == 1:
            return 'the required attribute {0}'\
                .format(strFunctions.wrap_token(attributes[0]['name'],
                                                self.package))
        else:
            required_statement = 'the required attributes {0}'\
                .format(strFunctions.wrap_token(attributes[0]['name'],
                                                self.package))
            i = 1
            while i < num - 1:
                required_statement += ', {0}'\
                    .format(strFunctions.wrap_token(attributes[i]['name'],
                                                    self.package))
                i += 1
            required_statement += ' and {0}'\
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
            return 'the optional attribute {0}' \
                .format(strFunctions.wrap_token(attributes[0]['name'],
                                                self.package))
        else:
            optional_statement = 'the optional attributes {0}' \
                .format(strFunctions.wrap_token(attributes[0]['name'],
                                                self.package))
            i = 1
            while i < num - 1:
                optional_statement += ', {0}' \
                    .format(strFunctions.wrap_token(attributes[i]['name'],
                                                    self.package))
                i += 1
            optional_statement += ' and {0}' \
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
            return 'one and only one instance of the {0} element'\
                .format(strFunctions.get_element_name(attributes[0]))
        else:
            required_statement = 'one and only one instance of each of the {0}'\
                .format(strFunctions.get_element_name(attributes[0]))
            i = 1
            while i < num - 1:
                required_statement += ', {0}'\
                    .format(strFunctions.get_element_name(attributes[i]))
                i += 1
            required_statement += ' and \{0} elements'\
                .format(strFunctions.get_element_name(attributes[i]))
            return required_statement

    # parse the optional attribute sentence
    @staticmethod
    def parse_optional_elements(attributes):
        num = len(attributes)
        if num == 0:
            return ''
        elif num == 1:
            return 'one and only one instance of the {0} element' \
                .format(strFunctions.get_element_name(attributes[0]))
        else:
            optional_statement = 'one and only one instance of each of the {0}' \
                .format(strFunctions.get_element_name(attributes[0]))
            i = 1
            while i < num - 1:
                optional_statement += ', {0}' \
                    .format(strFunctions.get_element_name(attributes[i]))
                i += 1
            optional_statement += ' and {0} elements'\
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
            return 'FIX ME: Failed to find the enum {0} in parse_enum_values'\
                .format(enum)
        else:
            i = 0
            values = '\"{0}\"'.format(this_enum['values'][i]['value'])
            for i in range(1, len(this_enum['values'])-1):
                values += ', \"{0}\"'.format(this_enum['values'][i]['value'])
            values += ' or \"{0}\"'.format(this_enum['values'][i+1]['value'])
            return values

    ##########################################################################

    # functions to create test information for generating xml files
    def parse_elements(self, elements):
        return['ListOfGroups']