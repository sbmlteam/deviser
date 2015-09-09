#!/usr/bin/env python

import os

from cmake_files import CMakeFiles
from parseXML import ParseXML
from util import global_variables

use_new = True

fails = []


def generate_cmake_files(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if not os.path.exists('src'):
        os.mkdir('src')
    all_files = CMakeFiles.CMakeFiles(ob, os.getcwd(), True)
    all_files.write_files()
    os.chdir('../.')


# reads file containing expected sbml model and returns it as string
def read_file(path):
    filein = open(path, 'r')
    contents = filein.read()
    filein.close()
    return contents


def compare_files(infile, outfile):
    global fails
    ret = 0
    if not os.path.isfile(infile) or not os.path.isfile(outfile):
        fails.append(infile)
        print('=================>> FAILED')
        return 1
    indata = read_file(infile)
    out = read_file(outfile)
    if indata.strip() == out.strip():
        print('PASSED')
    else:
        fails.append(infile)
        print('=================>> FAILED')
        ret = 1
    return ret


def run_cmake_test(name):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:CMake files'.format(name))
    print('====================================================')
    generate_cmake_files(filename)
    cmake = '{}-package.cmake'.format(name)
    correct_file = '.\\test-cmake\\{}'.format(cmake)
    temp_file = '.\\temp\\{}'.format(cmake)
    if os.path.exists(correct_file):
        print('{}'.format(cmake))
        fail = compare_files(correct_file, temp_file)
    else:
        print('unable to find {}'.format(cmake))
    print('')
    correct_file = '.\\test-cmake\\src\\{}'.format(cmake)
    temp_file = '.\\temp\\src\\{}'.format(cmake)
    if os.path.exists(correct_file):
        print('{}'.format(cmake))
        fail += compare_files(correct_file, temp_file)
    else:
        print('unable to find src//{}'.format(cmake))
    print('')

    return fail


def run_register_test(name):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:CMake register files'.format(name))
    print('====================================================')
    generate_cmake_files(filename)
    cmake = '{}-register.h'.format(name)
    correct_file = '.\\test-cmake\\{}'.format(cmake)
    temp_file = '.\\temp\\{}'.format(cmake)
    if os.path.exists(correct_file):
        print('{}'.format(cmake))
        fail = compare_files(correct_file, temp_file)
    else:
        print('unable to find {}'.format(cmake))
    print('')
    cmake = '{}-register.cxx'.format(name)
    correct_file = '.\\test-cmake\\{}'.format(cmake)
    temp_file = '.\\temp\\{}'.format(cmake)
    if os.path.exists(correct_file):
        print('{}'.format(cmake))
        fail += compare_files(correct_file, temp_file)
    else:
        print('unable to find src//{}'.format(cmake))
    print('')

    return fail


def main():
    global_variables.running_tests = True
    fail = 0

    name = 'spatial'
    fail += run_cmake_test(name)

    name = 'spatial'
    fail += run_register_test(name)

    if fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('Check {} fails'.format(fail))
        for name in fails:
            print(name)


if __name__ == '__main__':
    main()
