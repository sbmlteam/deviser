#!/usr/bin/env python

import os
import sys

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')
import deviser
import test_functions
from ..util import global_variables as gv

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
    """
    General function for running command-line Deviser tests.

    :param name: general name of test
    :param flag: a command-line flag
    :param expected_return: what we expect the test to return.
    :return: 0 on success, 1 on failure
    """
    error = gv.get_return_code(expected_return)
    filename = test_functions.set_up_test(name, flag, error)
    args = []
    if flag in ['-g', '-l', 'wrong']:
        args.append('deviser')
        args.append(flag)
        args.append(filename)
    elif flag == 'missing':
        args.append('deviser')
        args.append(filename)

    generate_deviser(args)
    fail = test_functions.compare_return_codes(name, flag, expected_return,
                                               fails)
    print('')
    return fail


#########################################################################
# Main function


def main():

    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)

    fail = 0

    # Run the individual tests.
    fail += run_deviser_test('non-existent', '-g',
                             gv.return_codes['failed to read file'])
    fail += run_deviser_test('test_child', '-g',
                             gv.return_codes['success'])
    fail += run_deviser_test('test_child', 'missing',
                             gv.return_codes['missing function argument'])
    fail += run_deviser_test('test_child', 'wrong',
                             gv.return_codes['invalid function arguments'])
    # TODO sort for latest python ** UPDATE 15th December 2020 this seems to work fine on Python 2 and 3.6.12
    # fail += run_deviser_test('test_child', '-l',
    #                          gv.return_codes['success'])
    fail += run_deviser_test('invalid', '-g',
                             gv.return_codes['parsing error'])
    fail += run_deviser_test('invalid', '-l',
                             gv.return_codes['parsing error'])
    fail += run_deviser_test('unknown_type', '-g',
                             gv.return_codes['unknown type used'])
    fail += run_deviser_test('unknown_error', '-g',
                             gv.return_codes['missing required information'])
    fail += run_deviser_test('bad_lo_element', '-g',
                             gv.return_codes['unknown type used'])
    fail += run_deviser_test('bad_concretes', '-g',
                             gv.return_codes['missing required information'])

    test_functions.report('EXIT CODES', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
