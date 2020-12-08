#!/usr/bin/env python

import os

import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')

from base_files import BaseMatlabFile
from parseXML import ParseXML

import test_functions


##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions


def generate_matlab_files(filename, name):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    ml = BaseMatlabFile.BaseMatlabFile(name, ob, 'sf')
    ml.write_file()
    ml = BaseMatlabFile.BaseMatlabFile(name, ob, 'dv')
    ml.write_file()
    ml = BaseMatlabFile.BaseMatlabFile(name, ob, 'vt')
    ml.write_file()
    os.chdir('../.')


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_matlab(name, filetype):
    if filetype == 'sf':
        correct_file = '.\\test-matlab\\{0}sf.m'.format(name)
        temp_file = '.\\temp\\{0}sf.m'.format(name)
    elif filetype == 'dv':
        correct_file = '.\\test-matlab\\{0}dv.m'.format(name)
        temp_file = '.\\temp\\{0}dv.m'.format(name)
    elif filetype == 'vt':
        correct_file = '.\\test-matlab\\{0}vt.m'.format(name)
        temp_file = '.\\temp\\{0}vt.m'.format(name)
    return compare_files(correct_file, temp_file)



#############################################################################
# Specific test functions


def run_matlab_test(name):
    filename = test_functions.set_up_test(name, 'MATLAB')
    generate_matlab_files(filename, name)
    fail = compare_matlab(name, 'sf')
    fail += compare_matlab(name, 'dv')
    fail += compare_matlab(name, 'vt')
    print('')
    return fail


#########################################################################
# Main function


def main():

    # set up the environment
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0

    # run the individual tests
    name = 'qual'
    fail += run_matlab_test(name)

    test_functions.report('matlab', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
