#!/usr/bin/env python

####################################################
## NOTE this file is a work in progress and not part of testing as yet


import os
from xml.dom.minidom import parse


from ...code_files import CppExampleFile
from ...validation import ValidationXMLFiles
from ...parseXML import ParseXML

from .. import test_functions

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
    Generate a failure example (creates an xml
    file that would fail validation)

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

    Sarah: "This was a work in progress and is not included in overall test run"
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
