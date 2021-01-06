#!/usr/bin/env python

import os

import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')

from cmake_files import CMakeFiles
from parseXML import ParseXML

import test_functions


##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions


def generate_cmake_files(filename):
    """
    Generic set-up code used by the test wrapper function.
    Parse XML file and use the big dictionary structure obtained to
    generate the CMake package files.

    :param filename: the XML file to parse
    :return: nothing
    """
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir(os.path.normpath('./temp'))
    if not os.path.exists('src'):
        os.mkdir('src')
    all_files = CMakeFiles.CMakeFiles(ob, os.getcwd(), True)
    all_files.write_package_files()
    os.chdir(os.path.normpath('../.'))


def generate_cmake_register_files(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir(os.path.normpath('./temp'))
    all_files = CMakeFiles.CMakeFiles(ob, os.getcwd(), True)
    all_files.write_register_files()
    os.chdir(os.path.normpath('../.'))

def generate_cmake_example_files(filename, name):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir(os.path.normpath('./temp'))
    if not os.path.exists('examples'):
        os.mkdir('examples')
        os.mkdir(os.path.normpath('examples/c++'))
    os.mkdir(os.path.normpath('examples/c++/{0}'.format(name)))
    os.chdir('examples')
    all_files = CMakeFiles.CMakeFiles(ob, os.getcwd(), True)
    all_files.write_example_files()
    os.chdir(os.path.normpath('../../../../.'))


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_cmake(name, is_src=False):
    if is_src:
        correct_file = os.path.normpath('./test-cmake/{0}-package.cmake'.format(name))
        temp_file = os.path.normpath('./temp/{0}-package.cmake'.format(name))
    else:
        correct_file = os.path.normpath('./test-cmake/{0}-package.cmake'.format(name))
        temp_file = os.path.normpath('./temp/{0}-package.cmake'.format(name))
    return compare_files(correct_file, temp_file)


def compare_cmake_register(name, is_cxx=False):
    if is_cxx:
        correct_file = os.path.normpath('./test-cmake/{0}-register.h'.format(name))
        temp_file = os.path.normpath('./temp/{0}-register.h'.format(name))
    else:
        correct_file = os.path.normpath('./test-cmake/{0}-register.cxx'.format(name))
        temp_file = os.path.normpath('./temp/{0}-register.cxx'.format(name))
    return compare_files(correct_file, temp_file)

def compare_cmake_example(name, is_txt=False):
    if is_txt and name=='spatial':
        correct_file = os.path.normpath('./test-cmake/examples/CMakeLists.txt')
        temp_file = os.path.normpath('./temp/examples/c++/{0}/CMakeLists.txt'.format(name))
    else:
        correct_file = os.path.normpath('./test-cmake/examples/{0}-package.cmake'.format(name))
        temp_file = os.path.normpath('./temp/examples/{0}-package.cmake'.format(name))
    return compare_files(correct_file, temp_file)

def compare_examples(name):
    correct_file = os.path.normpath('./test-cmake/examples/c++/{0}_example1.cpp'.format(name))
    temp_file = os.path.normpath('./temp/examples/c++/{0}/{0}_example1.cpp'.format(name))
    return compare_files(correct_file, temp_file)

#############################################################################
# Specific test functions


def run_cmake_test(name):
    filename = test_functions.set_up_test(name, 'CMake')
    generate_cmake_files(filename)
    fail = compare_cmake(name)
    fail += compare_cmake(name, True)
    print('')
    return fail


def run_register_test(name):
    filename = test_functions.set_up_test(name, 'CMake', 'register')
    generate_cmake_register_files(filename)
    fail = compare_cmake_register(name)
    fail += compare_cmake_register(name, True)
    print('')
    return fail


def run_example_test(name):
    filename = test_functions.set_up_test(name, 'CMake', 'example')
    generate_cmake_example_files(filename, name)
    fail = compare_cmake_example(name)
    fail += compare_cmake_example(name, True)
    fail += compare_examples(name)
    print('')
    return fail



#########################################################################
# Main function


def main():

    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0

    # Run the individual tests.  TODO Consider using a pytest fixture.
    name = 'spatial'
    fail += run_cmake_test(name)

    name = 'spatial'
    fail += run_register_test(name)

    name = 'spatial'
    fail += run_example_test(name)

    name = 'groups'
    fail += run_example_test(name)

    test_functions.report('CMAKE', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
