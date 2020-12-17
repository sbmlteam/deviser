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


##############################################################################
# Specific generation functions

def setup(filename, name):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if not os.path.isdir(name):
        os.mkdir(name)
    os.chdir(name)
    return ob


def generate_validator(filename, name):
    ob = setup(filename, name)
    all_files = TexValidationRulesFile.TexValidationRulesFile(ob)
    all_files.write_file()
    os.chdir('../../.')


def generate_macros(filename, name):
    ob = setup(filename, name)
    all_files = TexMacrosFile.TexMacrosFile(ob)
    all_files.write_file()
    os.chdir('../../.')


def generate_body(filename, name):
    ob = setup(filename, name)
    all_files = TexBodySyntaxFile.TexBodySyntaxFile(ob)
    all_files.write_file()
    os.chdir('../../.')


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_validation(name):
    correct_file = os.path.normpath('./test-tex/{0}/apdx-validation.tex'.format(name))
    temp_file = os.path.normpath('./temp/{0}/apdx-validation.tex'.format(name))
    return compare_files(correct_file, temp_file)


def compare_macros(name):
    correct_file = os.path.normpath('./test-tex/{0}/macros.tex'.format(name))
    temp_file = os.path.normpath('./temp/{0}/macros.tex'.format(name))
    return compare_files(correct_file, temp_file)


def compare_body(name):
    correct_file = os.path.normpath('./test-tex/{0}/body.tex'.format(name))
    temp_file = os.path.normpath('./temp/{0}/body.tex'.format(name))
    return compare_files(correct_file, temp_file)


#############################################################################
# Specific test functions


def run_test(name, test_type):
    filename = test_functions.set_up_test(name, 'Tex', test_type)
    fail = 0
    if test_type == 'validation':
        generate_validator(filename, name)
        fail = compare_validation(name)
    elif test_type == 'macros':
        generate_macros(filename, name)
        fail = compare_macros(name)
    elif test_type == 'body':
        generate_body(filename, name)
        fail = compare_body(name)
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
        test_case = 'validation'
        fail += run_test(name, test_case)

        name = 'groups'
        test_case = 'macros'
        fail += run_test(name, test_case)

        name = 'groups'
        test_case = 'validation'
        fail += run_test(name, test_case)

        name = 'groups'
        test_case = 'body'
        fail += run_test(name, test_case)

        name = 'unknown_type'
        test_case = 'validation'
        fail += run_test(name, test_case)

        name = 'test_sidrefs'
        test_case = 'validation'
        fail += run_test(name, test_case)

        name = 'test_sidrefs'
        test_case = 'body'
        fail += run_test(name, test_case)

        name = 'test_lists'
        test_case = 'validation'
        fail += run_test(name, test_case)

        name = 'test_lists'
        test_case = 'body'
        fail += run_test(name, test_case)

        name = 'test_att'
        test_case = 'validation'
        fail += run_test(name, test_case)

    # write summary
    test_functions.report('TEX', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
