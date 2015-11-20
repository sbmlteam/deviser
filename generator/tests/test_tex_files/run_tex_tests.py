#!/usr/bin/env python

import os

from spec_files import TexValidationRulesFile, TexMacrosFile
from parseXML import ParseXML
from util import global_variables

use_new = True

fails = []
not_tested = []
path_to_tests = ''


def get_filename(name):
    global path_to_tests
    fname = '{}.xml'.format(name)
    filename = os.path.join(path_to_tests, 'test_xml_files', fname)
    return filename


def generate_validator(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = TexValidationRulesFile.TexValidationRulesFile(ob)
    all_files.write_file()
    os.chdir('../.')


def generate_macros(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = TexMacrosFile.TexMacrosFile(ob)
    all_files.write_file()
    os.chdir('../.')


# reads file containing expected sbml model and returns it as string
def read_file(path):
    filein = open(path, 'r')
    contents = filein.read()
    filein.close()
    return contents


def compare_files(infile, outfile):
    global fails
    global not_tested
    ret = 0
    if not os.path.isfile(infile):
        # we have not added a file to compare to
        not_tested.append(infile)
        return ret
    elif not os.path.isfile(outfile):
        print(outfile)
        fails.append(infile)
        print('{}=================>> MISSING'.format(outfile))
        return 1
    indata = read_file(infile)
    out = read_file(outfile)
    if indata.strip() == out.strip():
        print('{} .... PASSED'.format(outfile))
    else:
        fails.append(infile)
        print('{}=================>> FAILED'.format(outfile))
        ret = 1
    return ret


def run_test(name, test_type):
    filename = get_filename(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{}'.format(test_type, name))
    print('====================================================')
    if test_type == 'validation':
        generate_validator(filename)
        correct_file = '.\\test-tex\\{}\\apdx-validation.tex'.format(name)
        temp_file = '.\\temp\\apdx-validation.tex'
        fail = compare_files(correct_file, temp_file)
    elif test_type == 'macros':
        generate_macros(filename)
        correct_file = '.\\test-tex\\{}\\macros.tex'.format(name)
        temp_file = '.\\temp\\macros.tex'
        fail = compare_files(correct_file, temp_file)
    print('')
    return fail


def main():
    global_variables.running_tests = True
    global_variables.code_returned = global_variables.return_codes['success']
    fail = 0
    this_dir = os.getcwd()
    global path_to_tests

    (path_to_tests, other) = os.path.split(this_dir)
    if not os.path.isdir('temp'):
        os.mkdir('temp')

    name = 'qual'
    test_case = 'validation'
    fail += run_test(name, test_case)

    name = 'groups'
    test_case = 'macros'
    fail += run_test(name, test_case)

    if len(not_tested) > 0:
        print('The following files were not tested:')
        for name in not_tested:
            print(name)

    if fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('TEX FAILS')
        print('Check {} fails'.format(fail))
        for name in fails:
            print(name)

    return fail


if __name__ == '__main__':
    main()
