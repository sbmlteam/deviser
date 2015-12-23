#!/usr/bin/env python

import os

from tests import test_functions

##############################################################################
# Set up variables
fails = []
total_fail = 0
this_dir = ''

#############################################################################
# Specific test functions


def run_test(name, test_type):
    global total_fail
    test_name = 'test_{0}_{1}'.format(name, test_type)
    test_case = os.path.join(this_dir, test_name)
    os.chdir(test_case)
    total_fail += test_functions.run_tests(test_name, name, fails)
    os.chdir(this_dir)


#########################################################################
# Main function


def main():
    test_functions.set_running_tests()
    global this_dir
    this_dir = os.getcwd()
    global total_fail

    run_test('binding', 'code')
    run_test('cmake', 'code')
    run_test('cpp', 'code')
    run_test('exit', 'codes')
    run_test('tex', 'files')

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
