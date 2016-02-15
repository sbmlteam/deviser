#!/usr/bin/env python

import os

from code_files import CppExampleFile
from validation import ValidationXMLFiles
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
    if not os.path.exists(ob['name']):
        os.mkdir(ob['name'])
    os.chdir('./{0}'.format(ob['name']))
    all_files = CppExampleFile.CppExampleFile(ob)
    all_files.write_file()
    os.chdir('../../.')
    return ob['name']


def generate_xml(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if not os.path.exists(ob['name']):
        os.mkdir(ob['name'])
    os.chdir('./{0}'.format(ob['name']))
    all_files = ValidationXMLFiles.ValidationXMLFiles(ob)
    all_files.write_file('test_xml')
    os.chdir('../../.')
    return ob['name']


def generate_xml_fails(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if not os.path.exists(ob['name']):
        os.mkdir(ob['name'])
    os.chdir('./{0}'.format(ob['name']))
    all_files = ValidationXMLFiles.ValidationXMLFiles(ob)
    all_files.write_all_files()
    os.chdir('../../.')
    return ob['name']


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)

def compare_examples(pkg):
    correct_file = '.\\test-examples\\{0}\\{0}_example1.cpp'.format(pkg)
    temp_file = '.\\temp\\{0}\\{0}_example1.cpp'.format(pkg)
    return compare_files(correct_file, temp_file)

def compare_xml(pkg):
    correct_file = '.\\test-examples\\{0}\\test_xml.xml'.format(pkg)
    temp_file = '.\\temp\\{0}\\test_xml.xml'.format(pkg)
    return compare_files(correct_file, temp_file)


def compare_xml_fails(pkg):
    fail = 0
    correct_file_dir = '.\\test-examples\\{0}'.format(pkg)
    temp_file_dir = '.\\temp\\{0}'.format(pkg)
    for f in os.listdir(temp_file_dir):
        if f.endswith('xml'):
            correct_file = '{0}\\{1}'.format(correct_file_dir, f)
            temp_file = '{0}\\{1}'.format(temp_file_dir, f)
            fail += compare_files(correct_file, temp_file)
    return fail




#############################################################################
# Specific test functions


def run_test(name):
    filename = test_functions.set_up_test(name, 'Examples')
    pkg = generate_example(filename)
    fail = compare_examples(pkg)
    print('')
    return fail

def run_xml_test(name):
    filename = test_functions.set_up_test(name, 'Examples')
    pkg = generate_xml(filename)
    fail = compare_xml(pkg)
    print('')
    return fail

def run_xml_fail_tests(name):
    filename = test_functions.set_up_test(name, 'Examples')
    pkg = generate_xml_fails(filename)
    fail = compare_xml_fails(pkg)
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

    name = 'lo_children'
    fail += run_test(name)

    name = 'lo_children'
    fail += run_xml_test(name)

    name = 'base_class'
    fail += run_xml_test(name)

    name = 'base_class'
    fail += run_xml_fail_tests(name)

    name = 'groups'
    fail += run_xml_test(name)

    name = 'groups'
    fail += run_xml_fail_tests(name)

    name = 'qual'
    fail += run_xml_test(name)

    # write summary
    test_functions.report('examples', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
