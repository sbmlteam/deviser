#!/usr/bin/python

import strFunctions


class ValidationRulesForPlugin():
    """Class for creating the validation rules for an plugin object"""

    def __init__(self, object_desc, spec_name, number, package, pkg_ref):
        # members from object
        self.name = object_desc['sbase']
        self.fullname = spec_name
        self.number = number
        self.package = package.lower()
        self.pkg_ref = pkg_ref

        # useful repeated text strings
        self.valid = '\\validRule{'
        self.start_b = '{'
        self.end_b = '}'

        self.formatted_name = '\{}'.format(object_desc['sbase'])
        self.indef = strFunctions.get_indefinite(object_desc['sbase'])
        self.indef_u = strFunctions.upper_first(self.indef)

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
        name = strFunctions.wrap_token(attribute['name'], self.package)
        if att_type == 'SId':
            return
        elif att_type == 'SIdRef':
            ref_name = strFunctions.upper_first(attribute['name'])
            # hack for render
            if ref_name == 'StartHead' or ref_name == 'EndHead':
                ref_name = 'LineEnding'
            text = 'The value of the attribute {} of {} {} object must be ' \
                   'the identifier of an existing \{} object defined in the ' \
                   'enclosing \Model object.'\
                .format(name, self.indef, self.formatted_name, ref_name)
        elif att_type == 'string':
            text = 'The attribute {} on {} {} must have a value of data ' \
                   'type {}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token('string'))
        elif att_type == 'int' or att_type == 'uint':
            text = 'The attribute {} on {} {} must have a value of data ' \
                   'type {}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token('integer'))
        elif att_type == 'double':
            text = 'The attribute {} on {} {} must have a value of data ' \
                   'type {}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token('double'))
        elif att_type == 'boolean':
            text = 'The attribute {} on {} {} must have a value of data ' \
                   'type {}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token('boolean'))
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
        elif att_type == 'array':
            text = 'The value of the attribute {} of {} {} object must ' \
                   'be an array of values of type {}.'\
                .format(name, self.indef, self.formatted_name,
                        strFunctions.wrap_token(attribute['element']))
        else:
            text = 'FIX ME: Encountered an unknown attribute type {} in ' \
                   'ValidationRulesForClass:write_attribute_type_rule'\
                .format(att_type)

        ref = '{}, {}.'\
            .format(self.pkg_ref, strFunctions.wrap_section(self.name))
        sev = 'ERROR'
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev})

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
        else:
            text = 'A {0} object may have the optional SBML Level~3 ' \
                   'Core attributes {1} and {2}. No other attributes from the ' \
                   'SBML Level 3 Core namespaces are permitted on a {0} object.'\
                .format(strFunctions.get_element_name(lo_child),
                        strFunctions.wrap_token('metaid'),
                        strFunctions.wrap_token('sboTerm'))
            ref = '{}, {}.'\
                .format(self.pkg_ref, strFunctions.wrap_section(self.name))
            sev = 'ERROR'
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev})

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
        else:
            if 'type' in lo_child:
                loname = strFunctions.get_element_name(lo_child)
                element = lo_child['element']
            else:
                # we are in a plugin so have different fields
                loname = strFunctions.cap_list_of_name(lo_child['name'])
                element = lo_child['name']
            text = 'Apart from the general notes and annotations subobjects ' \
                   'permitted on all SBML objects, a {} container object ' \
                   'may only contain \{} objects.'\
                .format(loname, element)
            ref = '{}, {}.'\
                .format(self.pkg_ref, strFunctions.wrap_section(self.name))
            sev = 'ERROR'
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev})

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
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev})

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
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev})

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
        return dict({'number': self.number, 'text': text,
                     'reference': ref, 'severity': sev})
