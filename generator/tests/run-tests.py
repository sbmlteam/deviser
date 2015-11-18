#!/usr/bin/env python

import os

from util import global_variables
from tests import test_binding_code, test_cmake_code
from tests import test_cpp_code, test_exit_codes, test_tex_files


fails = []


def main():
    global_variables.running_tests = True
    total_fail = 0
    this_dir = os.getcwd()
    global path_to_tests

    test_case = os.path.join(this_dir, 'test_binding_code')
    os.chdir(test_case)
    fail = test_binding_code.run_bindings_tests.main()
    if fail > 0:
        total_fail += 1
        fails.append('bindings')

    test_case = os.path.join(this_dir, 'test_cmake_code')
    os.chdir(test_case)
    fail = test_cmake_code.run_cmake_tests.main()
    if fail > 0:
        total_fail += 1
        fails.append('cmake')

    test_case = os.path.join(this_dir, 'test_cpp_code')
    os.chdir(test_case)
    fail = test_cpp_code.run_cpp_tests.main()
    if fail > 0:
        total_fail += 1
        fails.append('cpp')

    test_case = os.path.join(this_dir, 'test_exit_codes')
    os.chdir(test_case)
    fail = test_exit_codes.run_exit_tests.main()
    if fail > 0:
        total_fail += 1
        fails.append('exit codes')

    test_case = os.path.join(this_dir, 'test_tex_files')
    os.chdir(test_case)
    fail = test_tex_files.run_tex_tests.main()
    if fail > 0:
        total_fail += 1
        fails.append('tex')

    if total_fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('Check {} fails'.format(total_fail))
        for name in fails:
            print(name)
    else:
        print('EVERYTHING PASSED')


if __name__ == '__main__':
    main()
