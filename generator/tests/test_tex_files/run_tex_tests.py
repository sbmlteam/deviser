#!/usr/bin/env python

import os

from spec_files import TexValidationRulesFile, TexMacrosFile, TexBodySyntaxFile
from parseXML import ParseXML

from tests import test_functions

##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions


def generate_validator(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = TexValidationRulesFile.TexValidationRulesFile(ob)
    all_files.write_file()
    os.chdir('../.')


def generate_macros(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = TexMacrosFile.TexMacrosFile(ob)
    all_files.write_file()
    os.chdir('../.')


def generate_body(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = TexBodySyntaxFile.TexBodySyntaxFile(ob)
    all_files.write_file()
    os.chdir('../.')


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_validation(name):
    correct_file = '.\\test-tex\\{0}\\apdx-validation.tex'.format(name)
    temp_file = '.\\temp\\apdx-validation.tex'.format(name)
    return compare_files(correct_file, temp_file)


def compare_macros(name):
    correct_file = '.\\test-tex\\{0}\\macros.tex'.format(name)
    temp_file = '.\\temp\\macros.tex'.format(name)
    return compare_files(correct_file, temp_file)


def compare_body(name):
    correct_file = '.\\test-tex\\{0}\\body.tex'.format(name)
    temp_file = '.\\temp\\body.tex'.format(name)
    return compare_files(correct_file, temp_file)


#############################################################################
# Specific test functions


def run_test(name, test_type):
    filename = test_functions.set_up_test(name, 'Tex', test_type)
    fail = 0
    if test_type == 'validation':
        generate_validator(filename)
        fail = compare_validation(name)
    elif test_type == 'macros':
        generate_macros(filename)
        fail = compare_macros(name)
    elif test_type == 'body':
        generate_body(filename)
        fail = compare_body(name)
    print('')
    return fail


#########################################################################
# Main function


def main():

    # set up the enivornment
    this_dir = os.getcwd()

    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0

    # run the individual tests
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

    # write summary
    test_functions.report('TEX', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
