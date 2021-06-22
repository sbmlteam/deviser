#!/usr/bin/env python

####################################################
## NOTE this file is a work in progress and not part of testing as yet

import os
import sys

from ...base_files import BaseMatlabFile
from ...parseXML import ParseXML
from .. import test_functions


##############################################################################
# Set up variables
fails = []
not_tested = []
filetypes = ['sf',  # Uses Matlab str2func().
             'dv',  # Creates/uses various DefaultValues functions.
             'vt']  # Creates/uses various ValueType functions.


##############################################################################
# Specific generation functions


def generate_matlab_files(filename, name):
    """
    Parse XML file and generate Matlab file from the information obtained.

    :param filename: XML file to parse
    :param name: stub of the name, e.g. 'qual'
    :returns: nothing
    """
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    for type in filetypes:
        ml = BaseMatlabFile.BaseMatlabFile(name, ob, type)
        ml.write_file()
    os.chdir('../.')


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    """
    Compare a reference file and a file generated by the code tests.

    :param correct_file: the reference file
    :param temp_file: the generated file
    :return: 0 if files identical, 1 otherwise.
    """
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_matlab(name, filetype):
    """
    Compare two Matlab files. Specifically, is the generated file
    identical to the reference version?

    :param name: the stub of the file name
    :param filetype: one of our recognised 'filetypes'
    :return: 0 if files identical, 1 otherwise.
    """
    assert filetype in filetypes
    correct_file = os.path.normpath('./test-matlab/{0}{1}.m'.format(name, filetype))
    temp_file = os.path.normpath('./temp/{0}{1}.m'.format(name, filetype))
    return compare_files(correct_file, temp_file)


#############################################################################
# Specific test functions


def run_matlab_tests(name):
    """
    Run the Matlab test; generate files and compare with reference versions.

    :param name: stub  of name e.g. 'qual'
    :returns: number of failures
    """
    filename = test_functions.set_up_test(name, 'MATLAB')
    generate_matlab_files(filename, name)
    fails_here = 0
    for filetype in filetypes:
        fails_here += compare_matlab(name, filetype)
    print('')
    return fails_here


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

    # Run the individual tests.
    name = 'qual'
    fail += run_matlab_tests(name)

    test_functions.report('matlab', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
