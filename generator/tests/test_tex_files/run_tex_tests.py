#!/usr/bin/env python

import os

from spec_files import TexValidationRulesFile, TexMacrosFile, TexBodySyntaxFile
from parseXML import ParseXML
from util import global_variables

use_new = True

fails = []
not_tested = []
path_to_tests = ''


def get_filename(name):
    global path_to_tests
    fname = '{0}.xml'.format(name)
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


def generate_body(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = TexBodySyntaxFile.TexBodySyntaxFile(ob)
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
        print('{0}=================>> MISSING'.format(outfile))
        return 1
    indata = read_file(infile)
    out = read_file(outfile)
    if indata.strip() == out.strip():
        print('{0} .... PASSED'.format(outfile))
    else:
        fails.append(infile)
        print('{0}=================>> FAILED'.format(outfile))
        ret = 1
    return ret


def run_test(name, test_type):
    filename = get_filename(name)
    correct_file = ''
    temp_file = ''
    print('====================================================')
    print('Testing {0}:{1}'.format(test_type, name))
    print('====================================================')
    if test_type == 'validation':
        generate_validator(filename)
        correct_file = '.\\test-tex\\{0}\\apdx-validation.tex'.format(name)
        temp_file = '.\\temp\\apdx-validation.tex'
    elif test_type == 'macros':
        generate_macros(filename)
        correct_file = '.\\test-tex\\{0}\\macros.tex'.format(name)
        temp_file = '.\\temp\\macros.tex'
    elif test_type == 'body':
        generate_body(filename)
        correct_file = '.\\test-tex\\{0}\\body.tex'.format(name)
        temp_file = '.\\temp\\body.tex'
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

    name = 'groups'
    test_case = 'validation'
    fail += run_test(name, test_case)

    name = 'groups'
    test_case = 'body'
    fail += run_test(name, test_case)

    name = 'unknown_type'
    test_case = 'validation'
    fail += run_test(name, test_case)

    if len(not_tested) > 0:
        print('The following files were not tested:')
        for name in not_tested:
            print(name)

    if fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('TEX FAILS')
        print('Check {0} fails'.format(fail))
        for name in fails:
            print(name)

    return fail


if __name__ == '__main__':
    main()
