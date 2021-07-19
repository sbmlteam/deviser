#!/usr/bin/env python

import os

from ...code_files import CppFiles, ExtensionFiles, ValidationFiles
from ...parseXML import ParseXML

from .. import functions


##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions

def common_setup(filename):
    """
    Generic set-up code. Parse XML file and go into ./temp.

    :param filename: XML file to parse
    :return: the big dictionary structure generated from the XML.
    """
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    return ob


def generate_new_cpp_header(filename, num):
    """
    Generate cpp files.

    :param filename: name of XML file to parse.
    :param num: index of item in list which is the value
        (in the big dictionary structure) for the key 'baseElements'.
        It is the index so that we can do code for just one class and
        not whole of the object returned from ParseXML
    :return: nothing
    """
    ob = common_setup(filename)
    working_class = ob['baseElements'][num]
    all_files = CppFiles.CppFiles(working_class, True)
    all_files.write_files()
    os.chdir('../.')


def generate_generic_header(filename, ext_type):
    """
    Generate Extension files with specified package.

    :param filename: XML file to parse.
    :param ext_type: required extension file, e.g. 'types', 'fwd' or ''
    :return: nothing.
    """
    ob = common_setup(filename)
    all_files = ExtensionFiles.ExtensionFiles(ob, ext_type, True)
    all_files.write_files()
    os.chdir('../.')


def generate_extension_header(filename):
    generate_generic_header(filename, '')


def generate_types_header(filename):
    generate_generic_header(filename, 'types')


def generate_fwd_header(filename):
    generate_generic_header(filename, 'fwd')


def generate_plugin_header(filename, num):
    """
    Generate plugin files.

    :param filename: XML file to parse.
    :param num: plugin #.
    :return: nothing.
    """
    ob = common_setup(filename)
    all_files = ExtensionFiles.ExtensionFiles(ob, '', True)
    all_files.write_plugin_files(num)
    os.chdir('../.')


def generate_error_header(filename):
    """
    Generate error header files.

    :param filename: XML file to parse
    :return: nothing
    """
    ob = common_setup(filename)
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_error_header()
    all_files.write_error_table_header()
    os.chdir('../.')


def generate_validator(filename):
    """
    Generate the set of Validation files.

    :param filename: XML file to parse.
    :return: nothing
    """
    ob = common_setup(filename)
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_validator_files()
    os.chdir('../.')


def generate_constraints(filename):
    """
    Generate the 'constraints' files.

    :param filename: XML file to parse
    :return: nothing.
    """
    ob = common_setup(filename)
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_constraints()
    os.chdir('../.')


#############################################################################
# Specific compare functions

def compare_files(folder, class_name, file_ending):
    """
    Generic function for comparing a reference file with a test one.

    :param folder: directory (e.g. 'test-code', 'test-extension') housing reference file.
    :param class_name: C++ class name, and stub of .cpp and .h files in test-code/ and test-extension/.
    :param file_ending: end of file name, e.g. '.h', '.cpp', 'Declared.cxx'
    :returns: 0 on success, or file not present; 1 on failure.
    """
    correct_file = os.path.normpath('./{0}/{1}{2}'.format(folder, class_name, file_ending))
    temp_file = os.path.normpath('./temp/{0}{1}'.format(class_name, file_ending))
    return functions.compare_files(correct_file, temp_file, fails,
                                   not_tested)


def compare_code_headers(class_name):
    """
    Wrapper to help compare two code header files.
    """
    return compare_files('test-code', class_name, '.h')


def compare_ext_headers(class_name):
    """
    Wrapper to help compare two extension header files.
    """
    return compare_files('test-extension', class_name, '.h')


def compare_code_impl(class_name):
    """
    Wrapper to help compare two code implementation files.
    """
    return compare_files('test-code', class_name, '.cpp')


def compare_ext_impl(class_name, declared=False):
    """
    Wrapper to help compare two extension implementation files.
    """
    if declared:
        ending = 'Declared.cxx'
    else:
        ending = '.cpp'
    return compare_files('test-extension', class_name, ending)


#############################################################################
# Specific test functions


def run_test(name, num, class_name, test_case, list_of):
    """
    Most commonly-used test function.

    :param name: which set of tests this relates to. e.g. 'test_att'
    :param num: index??? TODO please Sarah.
    :param class_name: C++ class name/start of .h and .cpp file names.
    :param test_case: brief description, e.g. 'all types attributes required'
    :param list_of: e.g. 'ListOfFunctionTerms'. Can be ''.
    :return: number of test failures.
    """
    filename = functions.set_up_test(name, class_name, test_case)
    generate_new_cpp_header(filename, num)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    if len(list_of) > 0:
        class_name = list_of
        fail += compare_code_headers(class_name)
        fail += compare_code_impl(class_name)
    print('')
    return fail


def run_ext_test(name, class_name, test_case, test):
    """
    Run an 'extension' test.

    :param name: which set of tests this relates to, e.g. 'qual'
    :param class_name: C++ class name/start of .h and .cpp file names, e.g. 'QualExtension'.
    :param test_case: brief description, e.g. 'basic extension file'
    :param test: integer specifying which type of header file to generate.
    :return: number of failed tests
    """
    filename = functions.set_up_test(name, class_name, test_case)
    if test == 0:
        generate_extension_header(filename)
    elif test == 1:
        generate_types_header(filename)
    else:
        generate_fwd_header(filename)
    fail = compare_ext_headers(class_name)
    if test == 0:
        fail += compare_ext_impl(class_name)
    print('')
    return fail


def run_plug_test(name, class_name, test_case, num):
    """
    Run a 'plugin' test.

    :param name: which set of tests this relates to, e.g. 'qual'
    :param class_name: C++ class name/start of .h and .cpp file names, e.g. 'QualModelPlugin'
    :param test_case: brief description, e.g. 'basic plugin'
    :param num: plugin #. It's just the index in the list of plugins that are
                 part of large dict object form ParseXML
    :return: number of failed tests.
    """
    filename = functions.set_up_test(name, class_name, test_case)
    generate_plugin_header(filename, num)
    fail = compare_ext_headers(class_name)
    fail += compare_ext_impl(class_name)
    print('')
    return fail


def run_valid_test(name, class_name, test_case, generate_error_files=True):
    """
    Run a 'validation' test.

    :param name: which set of tests this relates to, e.g. 'test_att'
    :param class_name: C++ class name/start of .h and .cpp file names,
        e.g. 'TestSBMLError' or SBMLValidator.h
    :param test_case: brief description, e.g. 'error enumeration'
    :param generate_error_files: determines which file to generate, Error.h and
        ErrorTable.h if True, otherwise Validator files
    :return: number of failed tests.
    """
    filename = functions.set_up_test(name, class_name, test_case)
    if generate_error_files:
        generate_error_header(filename)
        fail = compare_ext_headers(class_name)
        fail += compare_ext_headers('{0}Table'.format(class_name))
    else:
        generate_validator(filename)
        fail = compare_ext_headers(class_name)
        fail += compare_ext_impl(class_name)
    print('')
    return fail


def run_constraints_test(name, class_name, test_case):
    """
    Run a 'constraints' test.

    :param name: which set of tests this relates to, e.g. 'spatial'
    :param class_name: C++ class name/start of .h and .cpp file names, e.g. 'SpatialConsistencyConstraints'
    :param test_case: brief description, e.g. 'constraints'
    :return: number of failed tests
    """
    filename = functions.set_up_test(name, class_name, test_case)
    generate_constraints(filename)
    fail = compare_ext_impl(class_name)
    fail += compare_ext_impl(class_name, declared=True)
    print('')
    return fail


