#!/usr/bin/env python

import os
import test_functions

##############################################################################
# Set up variables
fails = []
total_fail = 0
this_dir = ''

#############################################################################
# Specific test functions


def run_test(name, test_type):
    """
    Run a test suite.

    :param name: name of test suite, e.g. 'binding'
    :param test_type: either 'code' or 'files' depending on whether the test
                      is creating code files or text files
    :return: nothing
    """
    global total_fail
    test_name = 'test_{0}_{1}'.format(name, test_type)
    test_case = os.path.join(this_dir, test_name)
    os.chdir(test_case)
    total_fail += test_functions.run_tests(test_name, name, fails)
    os.chdir(this_dir)


#########################################################################
# Main function


def main():
    """
    Run all the test suites and output helpful messages.
    """
    test_functions.set_running_tests()
    global this_dir
    this_dir = os.path.dirname(os.path.abspath(__file__))
    global total_fail

    run_test('binding', 'code')
    run_test('cmake', 'code')
    run_test('cpp', 'code')
    run_test('exit', 'code')
    run_test('matlab', 'code')
    ## update for latest python
    #run_test('tex', 'files')

    print('')

    if total_fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('Check {0} fails'.format(total_fail))
        for name in fails:
            print(name)
    else:
        print('EVERYTHING PASSED')


if __name__ == '__main__':
    main()
