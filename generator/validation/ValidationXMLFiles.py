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


    def write_fail_file(self, filename, subtree):
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
            # if self.rule_needs_tests(rule):
            #     filename = 'aaa-fail-01-{0}'.format(number)
            #     subtree = self.tree
            #     self.write_fail_file(filename, subtree)

    ###########################################################################

    def determine_rules(self):
        # number = self.offset
        # rules = ValidationRulesGeneral\
        #     .ValidationRulesGeneral(self.fullname, number, self.package,
        #                             self.pkg_ref, self.level, self.version,
        #                             self.pkg_version, self.reqd_status)
        # rules.determine_rules()
        # self.class_rules += rules.rules
        number = self.offset + 20200
        for i in range(0, len(self.plugins)):
            rules = ValidationRulesForPlugin.ValidationRulesForPlugin(
                self.plugins[i], self.fullname, number,
                self.package, self.pkg_ref)
            rules.determine_rules()
            self.class_rules += rules.rules
            number += 100
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
        tests = self.get_tests(rule)
        if not tests:
            return
        number = 1
        # write a passing test
        filename = '{0}-pass-00-{1}'.format(rule['number'],
                                            self.get_number(number))
        self.write_file(filename)

        # write failing tests
        for i in range(0, len(tests)):
            filename = '{0}-fail-01-{1}'.format(rule['number'],
                                                self.get_number(number))
            subtree = self.create_appropriate_tree(tests[i], rule['plugin'])
            if self.is_toplevel_fail(tests[i]['name']):
                self.write_toplevel_fail_file(filename, tests[i]['name'])
            else:
                self.write_fail_file(filename, subtree)
            number += 1

    ########################################################################
    # helper functions

    def get_number(self, number):
        if number < 10:
            str_num = '0{0}'.format(number)
        else:
            str_num = '{0}'.format(number)
        return str_num

    def get_tests(self, rule):
        tc = rule['typecode']
        test_needed = []
        if tc.endswith('Unknown'):
            test_needed = None
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
            loname = rule['lo_object'][0]['listOfClassName']
            test_needed = [dict({'name': 'empty_lo', 'object': rule['object'],
                                 'lo_child': loname})]
            for i in range(1, len(rule['lo_object'])):
                loname = rule['lo_object'][i]['listOfClassName']
                test_needed.append(dict({'name': 'empty_lo', 'object': rule['object'],
                                 'lo_child': loname}))
        elif tc.endswith('AllowedElements'):
            if len(rule['lo_object']) == 0:
                for i in range(0, len(rule['opt'])):
                    if rule['opt'][i]['isListOf']:
                        name = rule['opt'][i]['listOfClassName']
                    else:
                        name = rule['opt'][i]['name']
                    test_needed.append(dict({'name': 'add_element',
                                             'object': rule['object'],
                                             'child': name}))
        return test_needed

    def is_toplevel_fail(self, code):
        toplevel_codes = ['missing_ns', 'incorrect_ns', 'missing_reqd',
                          'incorrect_type_reqd', 'incorrect_value_reqd']
        if code in toplevel_codes:
            return True
        else:
            return False

    def create_appropriate_tree(self, test, plugin=False):
        subtree = []
        if test['name'] == 'empty_lo':
            subtree = self.remove_element(test['object'], test['lo_child'], plugin)
        elif test['name'] == 'add_element':
            subtree = self.duplicate_element(test['object'], test['child'], plugin)
        elif test['name'] == 'remove_empty':
            subtree = self.remove_element(test['object'], test['child'], plugin)
        return subtree

    def remove_element(self, object, name, plugin):
        subtree = copy.deepcopy(self.tree)
        if plugin:
            for i in range(0, len(subtree)):
                if subtree[i]['base'] == object:
                    break
            for j in range(0, len(subtree[i]['children'])):
                if subtree[i]['children'][j]['name'] == name:
                    subtree[i]['children'][j]['children'] = []
        return subtree

    def duplicate_element(self, object, name, plugin):
        subtree = copy.deepcopy(self.tree)
        if plugin:
            for i in range(0, len(subtree)):
                if subtree[i]['base'] == object:
                    break
            for j in range(0, len(subtree[i]['children'])):
                if subtree[i]['children'][j]['name'] == name:
                    subtree[i]['children'].append(subtree[i]['children'][j])
        return subtree

