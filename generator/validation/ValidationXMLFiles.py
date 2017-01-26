#!/usr/bin/env python
#
# @file    ValidationXMLFiles.py
# @brief   class for generating XML files
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


import copy

from . import ValidationRulesGeneral, ValidationRulesForClass
from . import ValidationRulesForPlugin
from base_files import BaseXMLFile
from util import strFunctions, query, global_variables


class ValidationXMLFiles():
    '''class to write validation xml files'''

    def __init__(self, lib_object, verbose=False):
        # members from object
        self.lib_object = lib_object
        self.verbose = verbose
        self.package = strFunctions.lower_first(lib_object['name'])
        self.reqd = 'false'
        if lib_object['required']:
            self.reqd = 'true'
        self.offset = lib_object['offset']
        self.sbml_classes = lib_object['baseElements']
        self.enums = lib_object['enums']
        self.plugins = lib_object['plugins']
        self.fullname = lib_object['fullname']
        self.level = lib_object['base_level']
        self.version = lib_object['base_version']
        self.pkg_version = lib_object['pkg_version']
        self.pkg_ref = 'NA'
        self.reqd_status = lib_object['required']

        self.tree = query.create_object_tree(lib_object, False)

        self.class_rules = []

    ##########################################################################

    def write_file(self, filename):
        xml = BaseXMLFile.BaseXMLFile(filename, self.package,
                                      self.reqd)
        xml.write_xml(self.tree)
        xml.close_file()


    def write_specific_file(self, filename, subtree):
        xml = BaseXMLFile.BaseXMLFile(filename, self.package,
                                      self.reqd)
        xml.write_xml(subtree)
        xml.close_file()

    def write_toplevel_fail_file(self, filename, code):
        xml = BaseXMLFile.BaseXMLFile(filename, self.package,
                                      self.reqd)
        xml.write_xml(self.tree, code)
        xml.close_file()

    ###########################################################################
    def write_all_files(self):
        self.determine_rules()
        self.write_file('test_xml')

        # for i in range(0, len(self.class_rules)):
        #     self.write_appropriate_test_cases(self.class_rules[i])

        for i in range(24, 50):
             self.write_appropriate_test_cases(self.class_rules[i])
    ###########################################################################

    def determine_rules(self):
        number = self.offset
        rules = ValidationRulesGeneral\
            .ValidationRulesGeneral(self.fullname, number, self.package,
                                    self.pkg_ref, self.level, self.version,
                                    self.pkg_version, self.reqd_status)
        rules.determine_rules()
        self.class_rules += rules.rules
        number = self.offset + 20200
        for i in range(0, len(self.plugins)):
            rules = ValidationRulesForPlugin.ValidationRulesForPlugin(
                self.plugins[i], self.fullname, number,
                self.package, self.pkg_ref)
            rules.determine_rules()
            self.class_rules += rules.rules
            number += 100
        # number = self.offset + 20300 ##############################################################################
        for i in range(0, len(self.sbml_classes)):
            # hack for render
            if self.sbml_classes[i]['name'] == 'RelAbsVector':
                continue
            rules = ValidationRulesForClass\
                .ValidationRulesForClass(self.sbml_classes[i],
                                         self.fullname, number, self.package,
                                         self.pkg_ref)
            rules.determine_rules()
            self.class_rules += rules.rules
            number += 100

    def write_appropriate_test_cases(self, rule):
        [tests, passes] = self.get_tests(rule)
        if len(tests) == 0 and len(passes) == 0:
            return
        number = 1
        # write a passing test
        filename = '{0}-pass-00-{1}'.format(rule['number'],
                                            self.get_number(number))
        self.write_file(filename)
        number += 1
        for i in range(0, len(passes)):
            filename = '{0}-pass-00-{1}'.format(rule['number'],
                                                self.get_number(number))
            subtree = self.create_appropriate_tree(passes[i])
            self.write_specific_file(filename, subtree)
            number += 1

        # write failing tests
        number = 1
        for i in range(0, len(tests)):
            filename = '{0}-fail-01-{1}'.format(rule['number'],
                                                self.get_number(number))
            subtree = self.create_appropriate_tree(tests[i])

            if self.is_toplevel_fail(tests[i]['name']):
                self.write_toplevel_fail_file(filename, tests[i]['name'])
            else:
                self.write_specific_file(filename, subtree)
            number += 1

    ########################################################################

    # function to work out what tests are needed for each rule

    def get_tests(self, rule):
        passes = []
        tc = rule['typecode']
        test_needed = []
        if tc.endswith('Unknown'):
            test_needed = []
        elif tc.endswith('NSUndeclared'):
            test_needed = [dict({'name': 'missing_ns'}),
                           dict({'name': 'incorrect_ns'})]
        elif tc.endswith('AttributeRequiredMissing'):
            test_needed = [dict({'name': 'missing_reqd'})]
        elif tc.endswith('AttributeRequiredMustBeBoolean'):
            test_needed = [dict({'name': 'incorrect_type_reqd'})]
        elif tc.endswith('AttributeRequiredMustHaveValue'):
            test_needed = [dict({'name': 'incorrect_value_reqd'})]
        elif tc.endswith('EmptyLOElements'):
            for element in rule['lo_object']:
                loname = element['listOfClassName']
                test_needed.append(dict({'name': 'empty_lo', 'object': rule['object'],
                                 'lo_child': loname}))
        elif tc.endswith('AllowedElements'):
            for element in rule['opt']:
                if 'isListOf' in element and element['isListOf']:
                    name = element['listOfClassName']
                    if len(name) == 0:
                        name = strFunctions.cap_list_of_name_no_prefix(element['name'])
                else:
                    name = element['name']
                test_needed.append(dict({'name': 'duplicate_element',
                                         'object': rule['object'],
                                         'child': name}))
            for element in rule['reqd']:
                if 'isListOf' in element and element['isListOf']:
                    name = element['listOfClassName']
                else:
                    name = element['name']
                test_needed.append(dict({'name': 'remove_element',
                                         'object': rule['object'],
                                         'child': name}))
        elif tc.endswith('AllowedCoreElements'):
            if self.is_lo_rule(rule):
                for element in rule['opt']:
                    if element['isListOf']:
                        name = element['listOfClassName']
                    else:
                        name = element['name']
                    test_needed.append(dict({'name': 'add_core_element',
                                             'object': rule['object'],
                                             'child': name}))
                    passes.append(dict({'name': 'add_core_element',
                                             'object': rule['object'],
                                             'child': name,
                                             'type': 'annotation'}))
                    passes.append(dict({'name': 'add_core_element',
                                             'object': rule['object'],
                                             'child': name,
                                             'type': 'notes'}))
                for element in rule['reqd']:
                    if element['isListOf']:
                        name = element['listOfClassName']
                    else:
                        name = element['name']
                    test_needed.append(dict({'name': 'add_core_element',
                                             'object': rule['object'],
                                             'child': name}))
                    passes.append(dict({'name': 'add_core_element',
                                             'object': rule['object'],
                                             'child': name,
                                             'type': 'annotation'}))
                    passes.append(dict({'name': 'add_core_element',
                                             'object': rule['object'],
                                             'child': name,
                                             'type': 'notes'}))
            else:
                test_needed.append(dict({'name': 'add_core_element',
                                         'object': rule['object'],
                                         'child': rule['object']}))
                passes.append(dict({'name': 'add_core_element',
                                         'object': rule['object'],
                                         'child': rule['object'],
                                         'type': 'annotation'}))
                passes.append(dict({'name': 'add_core_element',
                                         'object': rule['object'],
                                         'child': rule['object'],
                                         'type': 'notes'}))
        elif tc.endswith('AllowedCoreAttributes'):
            if self.is_lo_rule(rule):
                for element in rule['opt']:
                    name = self.get_name(element)
                    test_needed.append(dict({'name': 'add_core_attribute',
                                             'object': rule['object'],
                                             'child': name}))
                    passes.append(dict({'name': 'add_core_attribute',
                                             'object': rule['object'],
                                             'child': name,
                                             'type': 'metaid'}))
                    passes.append(dict({'name': 'add_core_attribute',
                                             'object': rule['object'],
                                             'child': name,
                                             'type': 'sboTerm'}))
                for element in rule['reqd']:
                    name = self.get_name(element)
                    test_needed.append(dict({'name': 'add_core_attribute',
                                             'object': rule['object'],
                                             'child': name}))
                    passes.append(dict({'name': 'add_core_attribute',
                                             'object': rule['object'],
                                             'child': name,
                                             'type': 'metaid'}))
                    passes.append(dict({'name': 'add_core_attribute',
                                             'object': rule['object'],
                                             'child': name,
                                             'type': 'sboTerm'}))
            else:
                test_needed.append(dict({'name': 'add_core_attribute',
                                         'object': rule['object'],
                                         'child': rule['object']}))
                passes.append(dict({'name': 'add_core_attribute',
                                         'object': rule['object'],
                                         'child': rule['object'],
                                         'type': 'metaid'}))
                passes.append(dict({'name': 'add_core_attribute',
                                         'object': rule['object'],
                                         'child': rule['object'],
                                         'type': 'sboTerm'}))
        elif tc.endswith('AllowedAttributes'):
            if self.is_lo_rule(rule):
                test_needed.append(dict({'name': 'add_pkg_attribute',
                                         'object': rule['object'],
                                         'child': rule['lo_object']}))
                for attribute in rule['opt']:
                    name = attribute['name']
                    passes.append(dict({'name': 'remove_attribute',
                                        'object': rule['object'],
                                        'child': rule['lo_object'],
                                        'attrib': name}))
                for attribute in rule['reqd']:
                    name = attribute['name']
                    test_needed.append(dict({'name': 'remove_attribute',
                                             'object': rule['object'],
                                             'child': rule['lo_object'],
                                             'attrib': name}))

            else:
                test_needed.append(dict({'name': 'add_pkg_attribute',
                                         'object': rule['object'],
                                         'child': rule['object']}))
                for attribute in rule['opt']:
                    name = attribute['name']
                    passes.append(dict({'name': 'remove_attribute',
                                        'object': rule['object'],
                                        'child': rule['object'],
                                        'attrib': name}))
                for attribute in rule['reqd']:
                    name = attribute['name']
                    test_needed.append(dict({'name': 'remove_attribute',
                                             'object': rule['object'],
                                             'child': rule['object'],
                                             'attrib': name}))
        elif self.is_attribute_type_rule(tc):
            test_needed.append(dict({'name': 'replace_attribute',
                                     'object': rule['object'],
                                     'child': rule['object'],
                                     'attrib': strFunctions.lower_first(rule['attrib']),
                                     'att_type': rule['attrib_type']}))
        else:
            print(tc)

        return [test_needed, passes]


    ########################################################################
    # helper functions

    @staticmethod
    def get_number(number):
        if number < 10:
            str_num = '0{0}'.format(number)
        else:
            str_num = '{0}'.format(number)
        return str_num

    @staticmethod
    def is_toplevel_fail(code):
        toplevel_codes = ['missing_ns', 'incorrect_ns', 'missing_reqd',
                          'incorrect_type_reqd', 'incorrect_value_reqd']
        if code in toplevel_codes:
            return True
        else:
            return False

    @staticmethod
    def is_attribute_type_rule(code):
        if 'MustBe' in code:
            return True
        else:
            return False

    @staticmethod
    def is_lo_rule(rule):
        is_lo = False
        if 'lo' in rule:
            is_lo = rule['lo']
        return is_lo

    @staticmethod
    def get_name(element):
        if element['isListOf']:
            name = element['listOfClassName']
        else:
            name = element['name']
        return name

    #########################################################################

    # functions that manipulate the tree

    def create_appropriate_tree(self, test):
        subtree = []
        if test['name'] == 'empty_lo':
            subtree = self.remove_element(test['object'], test['lo_child'])
        elif test['name'] == 'duplicate_element':
            subtree = self.duplicate_element(test['object'], test['child'])
        elif test['name'] == 'add_pkg_element':
            elem = 'model' if 'type' not in test else test['type']
            subtree = self.add_element(test['object'], test['child'], elem, self.package)
        elif test['name'] == 'add_core_element':
            elem = 'model' if 'type' not in test else test['type']
            subtree = self.add_element(test['object'], test['child'], elem, 'core')
        elif test['name'] == 'add_core_attribute':
            attrib = 'foo' if 'type' not in test else test['type']
            subtree = self.add_attrib(test['object'], test['child'], attrib, 'core')
        elif test['name'] == 'add_pkg_attribute':
            attrib = 'foo' if 'type' not in test else test['type']
            subtree = self.add_attrib(test['object'], test['child'], attrib, self.package)
        elif test['name'] == 'remove_attribute':
            subtree = self.remove_attrib(test['object'], test['child'], test['attrib'])
        elif test['name'] == 'remove_empty':
            subtree = self.remove_element(test['object'], test['child'])
        elif test['name'] == 'replace_attribute':
            subtree = self.replace_attribute_type(test['object'], test['child'], test['attrib'], test['att_type'])
        return subtree

    def remove_element(self, parent, child):
        subtree = copy.deepcopy(self.tree)
        match = self.match_child(subtree, parent, child)
        if match:
            match['children'] = []
        return subtree

    def duplicate_element(self, parent, child):
        # sort for nesting
        subtree = copy.deepcopy(self.tree)
        match = self.match_child(subtree, parent, child)
        match_parent = self.match_child(subtree, parent, parent)
        if match and match_parent:
            match_parent['children'].append(match)
        return subtree

    def add_element(self, parent, child, new_obj, ext):
        subtree = copy.deepcopy(self.tree)
        match = self.match_child(subtree, parent, child)
        if match:
            match['children'].append(self.make_object(new_obj, ext))
        return subtree

    def add_attrib(self, parent, child, new_obj, ext):
        subtree = copy.deepcopy(self.tree)
        match = self.match_child(subtree, parent, child)
        if match:
            match['attribs'].append(self.make_attrib(new_obj, ext))
        return subtree

    def remove_attrib(self, parent, child, att):
        subtree = copy.deepcopy(self.tree)
        match = self.match_child(subtree, parent, child)
        if match:
            for attrib in match['attribs']:
                if attrib['name'] == att:
                    match['attribs'].remove(attrib)
                    break
        return subtree

    def replace_attribute_type(self, parent, child, att, att_type):
        subtree = copy.deepcopy(self.tree)
        match = self.match_child(subtree, parent, child)
        if match:
            for attrib in match['attribs']:
                if attrib['name'] == att:
                    attrib['type'] = self.get_differing_type(att_type)
                    break
        return subtree

    def get_differing_type(self, att_type):
        string_types = ['enum', 'IDREF', 'ID', 'SId', 'SIdRef'
                          'UnitSId', 'UnitSIdRef', 'string']
        if att_type in string_types:
            return 'double'
        else:
            return 'string'

    def make_object(self, new_obj, ext):
        return dict({'name': new_obj, 'ext': ext, 'children': [], 'attribs': []})

    def make_attrib(self, new_obj, ext):
        att_type = 'ID'
        if new_obj == 'sboTerm':
            att_type = 'SBO'
        return dict({'xml_name': new_obj, 'ext': ext, 'type': att_type})

    def find_match(self, tree, child):
        match = None
        if 'name' in tree and tree['name'] == child:
            return tree
        for i in range(0, len(tree['children'])):
            match = self.find_match(tree['children'][i], child)
            if match:
                return match
        return match

    def find_match_from_plugin(self, tree, parent, child):
        match = None
        found = False
        for i in range(0, len(tree)):
            if tree[i]['base'] == parent:
                found = True
                break
        if found:
            if tree[i]['base'] == child:
                match = tree[i]
            else:
                match = self.find_match(tree[i], child)
        else:
            for i in range(0, len(tree)):
                match = self.find_match(tree[i], child)
                if match:
                    break;
        return match

    def match_child(self, tree, parent, child):
        match = None
        if not tree:
            return match
        if 'base' in tree[0]:
            match = self.find_match_from_plugin(tree, parent, child)
        else:
            match = self.find_match(tree, child)
        return match

    def match_parent(self, tree, parent, child):
        match = None
        if not tree:
            return match
        if 'base' in tree[0]:
            match = self.find_match_from_plugin(tree, parent, parent)
        else:
            match = self.find_match(tree, parent)
        return match

