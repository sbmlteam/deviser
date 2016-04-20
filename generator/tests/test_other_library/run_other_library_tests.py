#!/usr/bin/env python

import os

from code_files import CppFiles, BaseClassFiles, ValidationFiles, ExtensionFiles
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
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    working_class = ob['baseElements'][num]
    if working_class['name'] == global_variables.document_class:
        working_class['document'] = True
    os.chdir('./temp')
    all_files = CppFiles.CppFiles(working_class, True)
    all_files.write_files()
    os.chdir('../.')

def generate_templates(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    prefix = global_variables.prefix
    os.chdir('./temp')
    base_files = BaseClassFiles.BaseClassFiles(prefix,  ob['baseElements'], True)
    base_files.write_files()
    os.chdir('../.')

def generate_common_templates(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    prefix = global_variables.prefix
    os.chdir('./temp')
    base_files = BaseClassFiles.BaseClassFiles(prefix,  ob['baseElements'], True)
    base_files.write_common_files()
    os.chdir('../.')

def generate_validator(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    os.chdir('./temp')
    valid = ValidationFiles.ValidationFiles(ob, True)
    valid.write_error_table_header()
    os.chdir('../.')

def generate_forward(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    os.chdir('./temp')
    ext = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    ext.write_files()
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


def compare_code_cmake(class_name):
    correct_file = '.\\test-code\\{0}.cmake'.format(class_name)
    temp_file = '.\\temp\\{0}.cmake'.format(class_name)
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


def run_templates(name, class_name, test_case, list_of):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_templates(filename)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    fail += compare_code_headers(list_of)
    fail += compare_code_impl(list_of)
    print('')
    return fail

def test_other_templates():
    fail = compare_code_headers('SedConstructorException')
    fail += compare_code_impl('SedConstructorException')
    fail += compare_code_headers('SedReader')
    fail += compare_code_impl('SedReader')
    fail += compare_code_headers('SedWriter')
    fail += compare_code_impl('SedWriter')
    fail += compare_code_headers('SedErrorLog')
    fail += compare_code_impl('SedErrorLog')
    fail += compare_code_headers('SedNamespaces')
    fail += compare_code_impl('SedNamespaces')
    fail += compare_code_headers('SedError')
    fail += compare_code_impl('SedError')
    fail += compare_code_headers('SedTypes')
    fail += compare_code_headers('SedTypeCodes')
    fail += compare_code_impl('SedTypeCodes')
    fail += compare_code_headers('SedVisitor')
    fail += compare_code_impl('SedVisitor')
    print('')
    return fail

def test_common_templates(name, class_name, test_case):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_common_templates(filename)
    fail = compare_code_headers('common')
    fail += compare_code_headers('extern')
    fail += compare_code_headers('libsedml-config')
    fail += compare_code_impl('libsedml-version')
    fail += compare_code_headers('SedOperationReturnValues')
    fail += compare_code_impl('SedOperationReturnValues')
    fail += compare_code_cmake('libsedml-version.h')
    fail += compare_code_cmake('libsedml-config-common.h')
    fail += compare_code_cmake('libsedml-namespace.h')
    print('')
    return fail

def run_validator(name, class_name, test_case):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_validator(filename)
    fail = compare_code_headers(class_name)
    print('')
    return fail

def run_forward(name, class_name, test_case):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_forward(filename)
    fail = compare_code_headers(class_name)
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
    num = 1
    class_name = 'SedModel'
    list_of = 'SedListOfModels'
    test_case = 'model'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 0
    class_name = 'SedDocument'
    list_of = ''
    test_case = 'document'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    class_name = 'SedBase'
    list_of = 'SedListOf'
    test_case = 'templates'
    fail += run_templates(name, class_name, test_case, list_of)
    fail += test_other_templates()

    name = 'test_sedml'
    class_name = 'SedErrorTable'
    test_case = 'document'
    fail += run_validator(name, class_name, test_case)

    name = 'test_sedml'
    class_name = 'SedBase'
    test_case = 'common'
    fail += test_common_templates(name, class_name, test_case)

    name = 'test_sedml'
    class_name = 'sedmlfwd'
    test_case = 'forward declarations'
    fail += run_forward(name, class_name, test_case)

    test_functions.report('OTHER LIBRARY', fail, fails, not_tested)
    return fail

if __name__ == '__main__':
    main()
