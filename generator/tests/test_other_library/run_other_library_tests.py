#!/usr/bin/env python

import os

from code_files import CppFiles, BaseClassFiles
from parseXML import ParseXML
from util import strFunctions, global_variables

from tests import test_functions

##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions


def generate_new_cpp_header(filename, num):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    working_class = ob['baseElements'][num]
    strFunctions.prefix_classes(working_class)
    os.chdir('./temp')
    all_files = CppFiles.CppFiles(working_class, True)
    all_files.write_files()
    os.chdir('../.')

def generate_templates(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    prefix = global_variables.prefix
    os.chdir('./temp')
    base_files = BaseClassFiles.BaseClassFiles(prefix, True)
    base_files.write_files()
    os.chdir('../.')

#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_code_headers(class_name):
    correct_file = '.\\test-code\\{0}.h'.format(class_name)
    temp_file = '.\\temp\\{0}.h'.format(class_name)
    return compare_files(correct_file, temp_file)


def compare_code_impl(class_name):
    correct_file = '.\\test-code\\{0}.cpp'.format(class_name)
    temp_file = '.\\temp\\{0}.cpp'.format(class_name)
    return compare_files(correct_file, temp_file)


#############################################################################
# Specific test functions

def run_test(name, num, class_name, test_case, list_of):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_new_cpp_header(filename, num)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    if len(list_of) > 0:
        class_name = list_of
        fail += compare_code_headers(class_name)
        fail += compare_code_impl(class_name)
    print('')
    return fail


def run_templates(name, class_name, test_case):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_templates(filename)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    # if len(list_of) > 0:
    #     class_name = list_of
    #     fail += compare_code_headers(class_name)
    #     fail += compare_code_impl(class_name)
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
    name = 'test_sedml'
    num = 0
    class_name = 'SedModel'
    list_of = 'SedListOfModels'
    test_case = 'model'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 0
    class_name = 'SedBase'
    list_of = ''
    test_case = 'templates'
    fail += run_templates(name, class_name, test_case)

    test_functions.report('OTHER LIBRARY', fail, fails, not_tested)
    return fail

if __name__ == '__main__':
    main()