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
        number = 1
        for i in range(0, len(self.class_rules)):
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
        # for i in range(0, len(self.sbml_classes)):
        #     # hack for render
        #     if self.sbml_classes[i]['name'] == 'RelAbsVector':
        #         continue
        #     rules = ValidationRulesForClass\
        #         .ValidationRulesForClass(self.sbml_classes[i],
        #                                  self.fullname, number, self.package,
        #                                  self.pkg_ref)
        #     rules.determine_rules()
        #     self.class_rules += rules.rules
        #     number += 100

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
            subtree = self.create_appropriate_tree(passes[i], rule['plugin'])
            self.write_specific_file(filename, subtree)
            number += 1

        # write failing tests
        number = 1
        for i in range(0, len(tests)):
            filename = '{0}-fail-01-{1}'.format(rule['number'],
                                                self.get_number(number))
            if 'plugin' in rule:
                subtree = self.create_appropriate_tree(tests[i], rule['plugin'])
            else:
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
            # need to sort this if not a lo
            if not rule['lo']:
                for element in rule['opt']:
                    if element['isListOf']:
                        name = element['listOfClassName']
                    else:
                        name = element['name']
                    test_needed.append(dict({'name': 'add_element',
                                             'object': rule['object'],
                                             'child': name}))
                for element in rule['reqd']:
                    if element['isListOf']:
                        name = element['listOfClassName']
                    else:
                        name = element['name']
                    test_needed.append(dict({'name': 'remove_element',
                                             'object': rule['object'],
                                             'child': name}))
        elif tc.endswith('AllowedCoreElements'):
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

    def create_appropriate_tree(self, test, plugin=False):
        subtree = []
        if test['name'] == 'empty_lo':
            subtree = self.remove_element(test['object'], test['lo_child'], plugin)
        elif test['name'] == 'add_element':
            subtree = self.duplicate_element(test['object'], test['child'], plugin)
        elif test['name'] == 'add_core_element':
            elem = 'model' if 'type' not in test else test['type']
            subtree = self.add_element(test['object'], test['child'], elem, 'core', plugin)
        elif test['name'] == 'add_core_attribute':
            attrib = 'name' if 'type' not in test else test['type']
            subtree = self.add_attrib(test['object'], test['child'], attrib, 'core', plugin)
        elif test['name'] == 'remove_empty':
            subtree = self.remove_element(test['object'], test['child'], plugin)
        return subtree

    def remove_element(self, parent, name, plugin):
        subtree = copy.deepcopy(self.tree)
        if plugin:
            match = self.match_child_from_plugin(subtree, name, parent)
            if match:
                match['children'] = []
        return subtree

    def duplicate_element(self, parent, name, plugin):
        # sort for nesting
        subtree = copy.deepcopy(self.tree)
        if plugin:
            for i in range(0, len(subtree)):
                if subtree[i]['base'] == parent:
                    break
            for j in range(0, len(subtree[i]['children'])):
                if subtree[i]['children'][j]['name'] == name:
                    subtree[i]['children'].append(subtree[i]['children'][j])
        return subtree

    def add_element(self, parent, child, new_obj, ext, plugin):
        subtree = copy.deepcopy(self.tree)
        if plugin:
            match = self.match_child_from_plugin(subtree, child, parent)
            if match:
                match['children'].append(self.make_object(new_obj, ext))
        return subtree

    def add_attrib(self, parent, child, new_obj, ext, plugin):
        subtree = copy.deepcopy(self.tree)
        if plugin:
            match = self.match_child_from_plugin(subtree, child, parent)
            if match:
                match['attribs'].append(self.make_attrib(new_obj, ext))
        else:
            for plug_obj in subtree:
                match = self.match_child(plug_obj, child)
                if match:
                    match['attribs'].append(self.make_attrib(new_obj, ext))
                    break
        return subtree

    def make_object(self, new_obj, ext):
        return dict({'name': new_obj, 'ext': 'core', 'children': [], 'attribs': []})

    def make_attrib(self, new_obj, ext):
        att_type = 'ID'
        if new_obj == 'sboTerm':
            att_type = 'SBO'
        return dict({'xml_name': new_obj, 'ext': 'core', 'type': att_type})

    def match_child(self, parent, child):
        match = None
        if 'name' in parent and parent['name'] == child:
            return parent
        for i in range(0, len(parent['children'])):
            match = self.match_child(parent['children'][i], child)
            if match:
                return match
        return match

    def match_child_from_plugin(self, parent, child, parent_name):
        match = None
        for i in range(0, len(parent)):
            if parent[i]['base'] == parent_name:
                break
        match = self.match_child(parent[i], child)
        return match

