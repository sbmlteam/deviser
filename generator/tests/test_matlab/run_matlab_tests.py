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
filetypes = ['sf', 'dv', 'vt']


##############################################################################
# Specific generation functions


def generate_matlab_files(filename, name):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    for type in filetypes:  #['sf', 'dv', 'vt']:
        ml = BaseMatlabFile.BaseMatlabFile(name, ob, type)
        ml.write_file()
    os.chdir('../.')


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_matlab(name, filetype):

    assert filetype in filetypes  # ['sf', 'dv', 'vt']
    correct_file = '.\\test-matlab\\{0}{1}.m'.format(name, filetype)
    temp_file = '.\\temp\\{0}{1}.m'.format(name, filetype)
    return compare_files(correct_file, temp_file)



#############################################################################
# Specific test functions


def run_matlab_test(name):
    filename = test_functions.set_up_test(name, 'MATLAB')
    generate_matlab_files(filename, name)
    fails_here = 0
    for filetype in filetypes:  #['sf', 'dv', 'vt']:
        fails_here += compare_matlab(name, filetype)
    print('')
    return fails_here


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

    # Run the individual tests.
    name = 'qual'
    fail += run_matlab_test(name)

    test_functions.report('matlab', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
