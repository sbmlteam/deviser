#!/usr/bin/env python

import os

import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')

from spec_files import TexValidationRulesFile, TexMacrosFile, TexBodySyntaxFile
from parseXML import ParseXML

import test_functions


##############################################################################
# Set up variables
fails = []
not_tested = []


def setup(filename, name):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if not os.path.isdir(name):
        os.mkdir(name)
    os.chdir(name)
    return ob


def generate_files(filename, name, type):
    assert type in ['apdx-validation', 'macros', 'body']
    ob = setup(filename, name)
    if type == 'apdx-validation':
        all_files = TexValidationRulesFile.TexValidationRulesFile(ob)
    elif type == 'macros':
        all_files = TexMacrosFile.TexMacrosFile(ob)
    else:  # type == 'body':
        all_files = TexBodySyntaxFile.TexBodySyntaxFile(ob)
    all_files.write_file()
    os.chdir('../../.')


def compare_items(name, type):
    assert type in ['apdx-validation', 'macros', 'body']
    correct_file = os.path.normpath('./test-tex/{0}/{1}.tex'.format(name, type))
    temp_file = os.path.normpath('./temp/{0}/{1}.tex'.format(name, type))
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)

#############################################################################
# Specific test functions


def run_test(name, test_type):
    filename = test_functions.set_up_test(name, 'Tex', test_type)
    generate_files(filename, name, test_type)
    fail = compare_items(name, test_type)
    print('')
    return fail


#########################################################################
# Main function


def main():

    runall = True
    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, _) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0

    # These tests all appear to be independent from each other,
    # so I'm assuming their order doesn't matter.
    name = 'spatial'
    test_case = 'body'
    fail += run_test(name, test_case)

    if runall:
        # Run the other individual tests.
        name = 'qual'
        test_case = 'apdx-validation'
        fail += run_test(name, test_case)

        name = 'groups'
        test_case = 'macros'
        fail += run_test(name, test_case)

        name = 'groups'
        test_case = 'apdx-validation'
        fail += run_test(name, test_case)

        name = 'groups'
        test_case = 'body'
        fail += run_test(name, test_case)

        name = 'unknown_type'
        test_case = 'apdx-validation'
        fail += run_test(name, test_case)

        name = 'test_sidrefs'
        test_case = 'apdx-validation'
        fail += run_test(name, test_case)

        name = 'test_sidrefs'
        test_case = 'body'
        fail += run_test(name, test_case)

        name = 'test_lists'
        test_case = 'apdx-validation'
        fail += run_test(name, test_case)

        name = 'test_lists'
        test_case = 'body'
        fail += run_test(name, test_case)

        name = 'test_att'
        test_case = 'apdx-validation'
        fail += run_test(name, test_case)

    # write summary
    test_functions.report('TEX', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
