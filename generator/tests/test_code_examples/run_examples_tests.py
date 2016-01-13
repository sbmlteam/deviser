#!/usr/bin/env python

import os

from example_code_files import CppExampleFile
from parseXML import ParseXML
from util import strFunctions

from tests import test_functions

##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions


def generate_example(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = CppExampleFile.CppExampleFile(ob)
    all_files.write_file()
    os.chdir('../.')
    return ob['name']


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)

def compare_examples(pkg):
    correct_file = '.\\test-examples\\{0}_example1.cpp'.format(pkg)
    temp_file = '.\\temp\\{0}_example1.cpp'.format(pkg)
    return compare_files(correct_file, temp_file)


#############################################################################
# Specific test functions


def run_test(name):
    filename = test_functions.set_up_test(name, 'Examples')
    pkg = generate_example(filename)
    fail = compare_examples(pkg)
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
    fail += run_test(name)

    # run the individual tests
    name = 'lo_children'
    fail += run_test(name)

    # write summary
    test_functions.report('examples', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
