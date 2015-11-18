#!/usr/bin/env python

import os

from util import global_variables
import deviser

fails = []
not_tested = []
path_to_tests = ''


def get_filename(name):
    global path_to_tests
    fname = '{}.xml'.format(name)
    filename = os.path.join(path_to_tests, 'test_xml_files', fname)
    return filename


def generate_deviser(args):
    deviser.main(args)


def run_deviser_test(name, flag, expected_return):
    filename = get_filename(name)
    error = global_variables.get_return_code(expected_return)
    print('====================================================')
    print('Testing {} {} {}'.format(name, flag, error))
    print('====================================================')
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
    fail = 0
    if global_variables.code_returned != expected_return:
        fail = 1
        fails.append('{}: {} {}'.format(name, flag, expected_return))
        print('Incorrect Return: {} Expected: '
              '{}'.format(global_variables.get_return_code(global_variables.
                                                           code_returned),
                          global_variables.get_return_code(expected_return)))
    print('')
    return fail


def main():
    global_variables.running_tests = True
    global_variables.code_returned = global_variables.return_codes['success']
    this_dir = os.getcwd()
    global path_to_tests

    (path_to_tests, other) = os.path.split(this_dir)

    fail = 0
    fail += run_deviser_test('non-existent', '-g',
                             global_variables.
                             return_codes['failed to read file'])
    fail += run_deviser_test('non-existent', '-l',
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
    fail += run_deviser_test('test_child', '-l',
                             global_variables.
                             return_codes['success'])
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
                             return_codes['unknown error - please report'])

    if len(not_tested) > 0:
        print('The following files were not tested:')
        for name in not_tested:
            print(name)

    if fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('EXIT CODES FAILED')
        print('Check {} fails'.format(fail))
        for name in fails:
            print(name)

    return fail


if __name__ == '__main__':
    main()
