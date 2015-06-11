#!/usr/bin/env python

import os

from parseXML import createPackageFromXml
from code_files import CppFiles


def generate_cpp_header(filename, num):
    ob = createPackageFromXml.parse_deviser_xml(filename)
    working_class = ob['sbmlElements'][num]
    os.chdir('./temp')
    all_files = CppFiles.CppFiles(working_class)
    all_files.write_files()
    os.chdir('../.')


# reads file containing expected sbml model and returns it as string
def read_file(path):
    filein = open(path, 'r')
    contents = filein.read()
    filein.close()
    return contents


def compare_files(infile, outfile):
    ret = 0
    indata = read_file(infile)
    out = read_file(outfile)
    if indata.strip() == out.strip():
        print('PASSED')
    else:
        print('FAILED')
        ret = 1
    return ret


def run_test(name, num, class_name, test_case, list_of):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    print('Testing {}:{} {}'.format(name, class_name, test_case))
    generate_cpp_header(filename, num)
    correct_file = '.\\test-code\\{}.h'.format(class_name)
    temp_file = '.\\temp\\{}.h'.format(class_name)
    fail = compare_files(correct_file, temp_file)
    if len(list_of) > 0:
        class_name = list_of
        print('Testing {}:{} {}'.format(name, class_name, test_case))
        correct_file = '.\\test-code\\{}.h'.format(class_name)
        temp_file = '.\\temp\\{}.h'.format(class_name)
        fail += compare_files(correct_file, temp_file)
    return fail


def main():
    fail = 0
    name = 'qual'
    num = 3
    class_name = 'Output'
    list_of = 'ListOfOutputs'
    test_case = 'simple class'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'qual'
    num = 1
    class_name = 'Transition'
    list_of = 'ListOfTransitions'
    test_case = 'class with child list of elements'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 12
    class_name = 'AnalyticVolume'
    list_of = ''
    test_case = 'class with math child'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'distrib'
    num = 2
    class_name = 'Uncertainty'
    list_of = ''
    test_case = 'class with other child'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 7
    class_name = 'CoordinateComponent'
    list_of = 'ListOfCoordinateComponents'
    test_case = 'class with same child element diff name'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_att'
    num = 0
    class_name = 'MyTestClass'
    list_of = ''
    test_case = 'all types of attributes'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 17
    class_name = 'CSGNode'
    list_of = 'ListOfCSGNodes'
    test_case = 'abstract'
    fail += run_test(name, num, class_name, test_case, list_of)

    if fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('Check {} fails'.format(fail))
    # filename = 'C:\Development\git\deviser\samples\qual.xml'
    #
    # generate_cpp_header(filename, 3)
    #
    # my_file = '.\\test-code\\Output.h'
    # new_file = '.\\temp\\Output.h'
    #
    # compare_files(my_file, new_file)
    #
    # my_file = '.\\test-code\\ListOfOutputs.h'
    # new_file = 'ListOfOutputs.h'
    #
    # compare_files(my_file, new_file)
    #
    # generate_cpp_header(filename, 1)
    #
    # my_file = '.\\test-code\\Transition.h'
    # new_file = 'Transition.h'
    #
    # compare_files(my_file, new_file)
    #
    # my_file = '.\\test-code\\ListOfTransitions.h'
    # new_file = 'ListOfTransitions.h'
    #
    # compare_files(my_file, new_file)
    #
    # filename = 'C:\Users\Sarah\Dropbox\sbmlteam\deviser\specs2\\spatial.xml'
    #
    # generate_cpp_header(filename, 12)
    #
    # my_file = '.\\test-code\\AnalyticVolume.h'
    # new_file = 'AnalyticVolume.h'
    #
    # compare_files(my_file, new_file)


if __name__ == '__main__':
    main()
