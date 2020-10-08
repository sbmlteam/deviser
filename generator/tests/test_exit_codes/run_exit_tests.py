#!/usr/bin/env python

import os

import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')
import test_functions

from util import global_variables
import deviser

##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions


def generate_deviser(args):
    deviser.main(args)

#############################################################################
# Specific test functions


def run_deviser_test(name, flag, expected_return):
    error = global_variables.get_return_code(expected_return)
    filename = test_functions.set_up_test(name, flag, error)
    args = []
    if flag == '-g'or flag == '-l':
        args.append('deviser')
        args.append(flag)
        args.append(filename)
    elif flag == 'missing':
        args.append('deviser')
        args.append(filename)
    elif flag == 'wrong':
        args.append('deviser')
        args.append(flag)
        args.append(filename)

    generate_deviser(args)
    fail = test_functions.compare_return_codes(name, flag, expected_return,
                                               fails)
    print('')
    return fail


#########################################################################
# Main function


def main():

    # set up the enivornment
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)

    fail = 0

    # run the individual tests
    fail += run_deviser_test('non-existent', '-g',
                             global_variables.
                             return_codes['failed to read file'])
    fail += run_deviser_test('test_child', '-g',
                             global_variables.
                             return_codes['success'])
    fail += run_deviser_test('test_child', 'missing',
                             global_variables.
                             return_codes['missing function argument'])
    fail += run_deviser_test('test_child', 'wrong',
                             global_variables.
                             return_codes['invalid function arguments'])
    # TODO sort for latest python
    # fail += run_deviser_test('test_child', '-l',
    #                          global_variables.
    #                          return_codes['success'])
    fail += run_deviser_test('invalid', '-g',
                             global_variables.
                             return_codes['parsing error'])
    fail += run_deviser_test('invalid', '-l',
                             global_variables.
                             return_codes['parsing error'])
    fail += run_deviser_test('unknown_type', '-g',
                             global_variables.
                             return_codes['unknown type used'])
    fail += run_deviser_test('unknown_error', '-g',
                             global_variables.
                             return_codes['missing required information'])
    fail += run_deviser_test('bad_lo_element', '-g',
                             global_variables.
                             return_codes['unknown type used'])
    fail += run_deviser_test('bad_concretes', '-g',
                             global_variables.
                             return_codes['missing required information'])


    test_functions.report('EXIT CODES', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
