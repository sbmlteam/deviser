#!/usr/bin/env python

import os

import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')

from code_files import CppExampleFile
from validation import ValidationXMLFiles
from parseXML import ParseXML

from tests import test_functions

##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions

def set_up(filename):
    """
    Parse an XML file and get the big dictionary structure of information
    from it.

    :param filename: the file to parse
    :return: the big dictionary structure.
    """
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir(os.path.normpath('./temp'))
    if not os.path.exists(ob['name']):
        os.mkdir(ob['name'])
    os.chdir(os.path.normpath('./{0}'.format(ob['name'])))
    return ob


def generate_example(filename):
    """
    Generate a C++ example.

    :param filename: XML file to parse
    :return: package name, e.g. 'dyn'
    """
    ob = set_up(filename)
    all_files = CppExampleFile.CppExampleFile(ob)
    all_files.write_file()
    os.chdir(os.path.normpath('../../.'))
    return ob['name']


def generate_xml(filename):
    """
    Generate an XML example.

    :param filename: XML file to parse
    :return: package name, e.g. 'dyn'
    """
    ob = set_up(filename)
    all_files = ValidationXMLFiles.ValidationXMLFiles(ob)
    all_files.write_file('test_xml')
    os.chdir(os.path.normpath('../../.'))
    return ob['name']


def generate_xml_fails(filename):
    """
    Generate a failure example?????? TODO unsure

    :param filename: XML file to parse
    :return: package name, e.g. 'dyn'
    """
    ob = set_up(filename)
    all_files = ValidationXMLFiles.ValidationXMLFiles(ob)
    all_files.write_all_files()
    os.chdir(os.path.normpath('../../.'))
    return ob['name']


def generate_some_xml_fails(filename, start, stop, number=-1):
    """
    Generate

    :param filename: XML file to parse
    :param start:
    :param stop:
    :param number: number of files to write? TODO not sure.
    :return: package name, e.g. 'dyn'

    TODO Sorry Sarah I'm a bit confused by this one!
    """
    ob = set_up(filename)
    all_files = ValidationXMLFiles.ValidationXMLFiles(ob)
    if number > -1:
        all_files.set_num_components(number)
    all_files.write_test_files(start, stop)
    os.chdir(os.path.normpath('../../.'))
    return ob['name']

#############################################################################
# Specific compare functions

# TODO we could merge some of these into a more generic function.

def compare_files(correct_file, temp_file):
    """
    See if two files are the same.

    :param correct_file: the reference file we are comparing against.
    :param temp_file: the temporary file generated in the test, which
                      we compare with correct_file.
    :return: 0 on success (or file not present), 1 on failure.

    TODO I don't think we really need this wrapper function;
    test code could just call test_functions.compare_files() directly.
    """
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_examples(pkg):
    """
    Compare a reference example C++ file with a temporary one.

    :param pkg: name of XML package, e.g. 'dyn'.
    :return: 0 on success or file not present, 1 on failure.
    """
    correct_file = os.path.normpath('./test-examples/{0}/{0}_example1.cpp'.format(pkg))
    temp_file = os.path.normpath('./temp/{0}/{0}_example1.cpp'.format(pkg))
    return compare_files(correct_file, temp_file)


def compare_xml(pkg):
    """
    Compare a reference example XML file with a temporary one.

    :param pkg: name of XML package, e.g. 'dyn'.
    :return: 0 on success or file not present, 1 on failure.
    """
    correct_file = os.path.normpath('./test-examples/{0}/test_xml.xml'.format(pkg))
    temp_file = os.path.normpath('./temp/{0}/test_xml.xml'.format(pkg))
    return compare_files(correct_file, temp_file)


def compare_xml_fails(pkg):
    """
    Compare a set of reference example XML files in a directory
    with those we generated in a temporary directory.

    :param pkg: name of XML package, e.g. 'dyn'.
    :return: 0 on success or file not present, 1 on failure.
    """
    fail = 0
    correct_file_dir = os.path.normpath('./test-examples/{0}'.format(pkg))
    temp_file_dir = os.path.normpath('./temp/{0}'.format(pkg))
    for f in os.listdir(temp_file_dir):
        if f.endswith('xml'):
            correct_file = os.path.normpath('{0}/{1}'.format(correct_file_dir, f))
            temp_file = os.path.normpath('{0}/{1}'.format(temp_file_dir, f))
            fail += compare_files(correct_file, temp_file)
    return fail


#############################################################################
# Specific test functions

# TODO Again, some scope for rationalisation here.

def run_test(name):
    """
    Run a C++ file test.

    :param name: XML package name, e.g. 'dyn'
    :return 0 on success (or file not present), 1 on failure.
    """
    filename = test_functions.set_up_test(name, 'Examples')
    pkg = generate_example(filename)
    fail = compare_examples(pkg)
    print('')
    return fail


def run_xml_test(name):
    """
    Run an XML file test.

    :param name: XML package name, e.g. 'dyn'
    :return 0 on success (or file not present), 1 on failure.
    """
    filename = test_functions.set_up_test(name, 'Examples')
    pkg = generate_xml(filename)
    fail = compare_xml(pkg)
    print('')
    return fail


def run_xml_fail_tests(name):
    """
    Run an XML failure file test.

    :param name: XML package name, e.g. 'dyn'
    :return 0 on success (or file not present), 1 on failure.
    """
    filename = test_functions.set_up_test(name, 'Examples')
    pkg = generate_xml_fails(filename)
    fail = compare_xml_fails(pkg)
    print('')
    return fail


def run_specific_xml_fail_tests(name, start, stop, number=-1):
    """
    Generate specific XML failure test cases???

    :param name: XML file to parse
    :param start:
    :param stop:
    :param number: number of files to write? TODO not sure.
    :return: 0 on success or file mising, 1 on failure.

    TODO Sorry Sarah I'm a bit confused by this one as well!
    """
    filename = test_functions.set_up_test(name, 'Examples')
    pkg = generate_some_xml_fails(filename, start, stop, number)
    fail = compare_xml_fails(pkg)
    print('')
    return fail

#########################################################################
# Main function


# TODO sort out the tests which are failing, and those which are being
# skipped because a file isn't present.

def main():

    # Set up the environment
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0

    # run the individual tests
    # name = 'qual'
    # fail += run_test(name)
    #
    # name = 'lo_children'
    # fail += run_test(name)
    #
    name = 'lo_children'
    fail += run_xml_test(name)

    name = 'base_class'
    fail += run_xml_test(name)

    name = 'base_class'
    fail += run_xml_fail_tests(name)
    #
    # name = 'groups'
    # fail += run_xml_test(name)

    # name = 'groups'
    # fail += run_xml_fail_tests(name)

    name = 'qual'
    fail += run_xml_test(name)

    name = 'spatial'
    fail += run_xml_test(name)
    # Pytest parameterization is good for this sort of thing:
    fail += run_specific_xml_fail_tests(name, 8, 13)
    fail += run_specific_xml_fail_tests(name, 15, 19)
    fail += run_specific_xml_fail_tests(name, 22, 26)
    fail += run_specific_xml_fail_tests(name, 32, 36)
    fail += run_specific_xml_fail_tests(name, 41, 45)
    fail += run_specific_xml_fail_tests(name, 53, 54)
    fail += run_specific_xml_fail_tests(name, 60, 61)
    fail += run_specific_xml_fail_tests(name, 65, 66)

    #name = 'multi'
    #fail += run_specific_xml_fail_tests(name, 1, 2, 0)
    #
    # write summary
    test_functions.report('examples', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
