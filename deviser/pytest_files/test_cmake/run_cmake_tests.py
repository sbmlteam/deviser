#!/usr/bin/env python

import os


from ...cmake_files import CMakeFiles
from ...parseXML import ParseXML

from .. import functions


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
    generate the CMake `package` files.

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
    """
    Generic set-up code used by the test wrapper function.
    Parse XML file and use the big dictionary structure obtained to
    generate the CMake `register` files.

    :param filename: the XML file to parse
    :return: nothing
    """
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir(os.path.normpath('./temp'))
    all_files = CMakeFiles.CMakeFiles(ob, os.getcwd(), True)
    all_files.write_register_files()
    os.chdir(os.path.normpath('../.'))


def generate_cmake_example_files(filename, name):
    """
    Generic set-up code used by the test wrapper function.
    Parse XML file and use the big dictionary structure obtained to
    generate the CMake `example` files.

    :param filename: the XML file to parse
    :param name: name of subdirectory to be created under examples/c++/
    :return: nothing
    """
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
    """
    Do a string comparison of the contents of two files.

    :param correct_file: reference file
    :param temp_file: file generated during tests
    :return: 0 on success, or file not present; 1 on failure.
    """
    return functions.compare_files(correct_file, temp_file, fails,
                                   not_tested)


def compare_cmake(name):  # , is_src=False):
    """
    Do a string comparison of the contents of two files.

    :param name: TODO
    :return: 0 on success, or file not present; 1 on failure.
    """
    correct_file = os.path.normpath('./test-cmake/{0}-package.cmake'.
                                    format(name))
    temp_file = os.path.normpath('./temp/{0}-package.cmake'.format(name))
    return compare_files(correct_file, temp_file)


def compare_cmake_register(name, is_cxx=False):
    """
    Compare two cmake 'register' files.

    :param name: first part of filename
    :param is_cxx: Use True if a .cxx file, otherwise False
    :return: 0 on success, or file not present; 1 on failure.
    """
    if is_cxx:
        correct_file = os.path.normpath('./test-cmake/{0}-register.h'.
                                        format(name))
        temp_file = os.path.normpath('./temp/{0}-register.h'.format(name))
    else:
        correct_file = os.path.normpath('./test-cmake/{0}-register.cxx'.
                                        format(name))
        temp_file = os.path.normpath('./temp/{0}-register.cxx'.format(name))
    return compare_files(correct_file, temp_file)


def compare_cmake_example(name, is_txt=False):
    """
    Compare two cmake 'register' files.

    :param name: first part of filename, or directory name if
                 'is_txt' is True and name is 'spatial'
    :param is_txt: Use True if files end in .txt, otherwise False
    :return: 0 on success, or file not present; 1 on failure.
    """
    if is_txt and name == 'spatial':
        correct_file = os.path.normpath('./test-cmake/examples/CMakeLists.txt')
        temp_file = os.path.normpath('./temp/examples/c++/{0}/CMakeLists.txt'.format(name))
    else:
        correct_file = os.path.normpath('./test-cmake/examples/{0}-package.cmake'.format(name))
        temp_file = os.path.normpath('./temp/examples/{0}-package.cmake'.format(name))
    return compare_files(correct_file, temp_file)


def compare_examples(name):
    """
    Compare two 'example' files.

    :param name: first part of filename, and a subdir under temp/examples/c++/
    :return: 0 on success, or file not present; 1 on failure.
    """
    correct_file = os.path.normpath('./test-cmake/examples/c++/{0}_example1.cpp'.format(name))
    temp_file = os.path.normpath('./temp/examples/c++/{0}/{0}_example1.cpp'.format(name))
    return compare_files(correct_file, temp_file)

#############################################################################
# Specific test functions


def run_cmake_test(name):
    """
    General CMake test.

    :param name: stub of XML filename, e.g. 'dyn' for filename 'dyn.xml'
    :return: 0 if all comparisons succeed, else number of failures.
    """
    filename = functions.set_up_test(name, 'CMake')
    generate_cmake_files(filename)
    fail = compare_cmake(name)
    # fail += compare_cmake(name, True)
    print('')
    return fail


def run_register_test(name):
    """
    CMake 'register' test.

    :param name: stub of XML filename, e.g. 'dyn' for filename 'dyn.xml'
    :return: 0 if all comparisons succeed, else number of failures.
    """
    filename = functions.set_up_test(name, 'CMake', 'register')
    generate_cmake_register_files(filename)
    fail = compare_cmake_register(name)
    fail += compare_cmake_register(name, True)
    print('')
    return fail


def run_example_test(name):
    """
    CMake 'example' test.

    :param name: stub of XML filename, e.g. 'dyn' for filename 'dyn.xml'
    :return: 0 if all comparisons succeed, else number of failures.
    """
    filename = functions.set_up_test(name, 'CMake', 'example')
    generate_cmake_example_files(filename, name)
    fail = compare_cmake_example(name)
    fail += compare_cmake_example(name, True)
    fail += compare_examples(name)
    print('')
    return fail


