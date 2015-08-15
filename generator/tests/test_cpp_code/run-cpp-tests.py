#!/usr/bin/env python

import os

from parseXML import createPackageFromXml
from code_files import CppFiles, ExtensionFiles
from parseXML import ParseXML

use_new = True


def generate_cpp_header(filename, num):
    ob = createPackageFromXml.parse_deviser_xml(filename)
    working_class = ob['sbmlElements'][num]
    os.chdir('./temp')
    all_files = CppFiles.CppFiles(working_class)
    all_files.write_files()
    os.chdir('../.')


def generate_new_cpp_header(filename, num):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    working_class = ob['sbmlElements'][num]
    os.chdir('./temp')
    all_files = CppFiles.CppFiles(working_class, True)
    all_files.write_files()
    os.chdir('../.')


def generate_extension_header(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ExtensionFiles.ExtensionFiles(ob, '', True)
    all_files.write_files()
    os.chdir('../.')


def generate_types_header(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ExtensionFiles.ExtensionFiles(ob, 'types', True)
    all_files.write_files()
    os.chdir('../.')


def generate_plugin_header(filename, num):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ExtensionFiles.ExtensionFiles(ob, True)
    all_files.write_plugin_files(num)
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
        print('=================>> FAILED')
        ret = 1
    return ret


def run_test(name, num, class_name, test_case, list_of):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, class_name, test_case))
    print('====================================================')
    if use_new:
        generate_new_cpp_header(filename, num)
    else:
        generate_cpp_header(filename, num)
    correct_file = '.\\test-code\\{}.h'.format(class_name)
    temp_file = '.\\temp\\{}.h'.format(class_name)
    if os.path.isfile(correct_file):
        print('{}.h'.format(class_name))
        fail = compare_files(correct_file, temp_file)
    correct_cpp_file = '.\\test-code\\{}.cpp'.format(class_name)
    temp_cpp_file = '.\\temp\\{}.cpp'.format(class_name)
    if os.path.isfile(correct_cpp_file):
        print('{}.cpp'.format(class_name))
        fail += compare_files(correct_cpp_file, temp_cpp_file)
    if len(list_of) > 0:
        class_name = list_of
        print('{}.h'.format(class_name))
        correct_file = '.\\test-code\\{}.h'.format(class_name)
        temp_file = '.\\temp\\{}.h'.format(class_name)
        fail += compare_files(correct_file, temp_file)
        correct_cpp_file = '.\\test-code\\{}.cpp'.format(class_name)
        temp_cpp_file = '.\\temp\\{}.cpp'.format(class_name)
        if os.path.isfile(correct_cpp_file):
            print('{}.cpp'.format(class_name))
            fail += compare_files(correct_cpp_file, temp_cpp_file)
    print('')
    return fail


def run_ext_test(name, class_name, test_case, test):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, class_name, test_case))
    print('====================================================')
    if test == 0:
        generate_extension_header(filename)
    else:
        generate_types_header(filename)
    correct_file = '.\\test-extension\\{}.h'.format(class_name)
    temp_file = '.\\temp\\{}.h'.format(class_name)
    if os.path.isfile(correct_file):
        print('{}.h'.format(class_name))
        fail = compare_files(correct_file, temp_file)
    correct_cpp_file = '.\\test-extension\\{}.cpp'.format(class_name)
    temp_cpp_file = '.\\temp\\{}.cpp'.format(class_name)
    if os.path.isfile(correct_cpp_file):
        print('{}.cpp'.format(class_name))
        fail += compare_files(correct_cpp_file, temp_cpp_file)
    print('')
    return fail


def run_plug_test(name, class_name, test_case, num):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, class_name, test_case))
    print('====================================================')
    generate_plugin_header(filename, num)
    correct_file = '.\\test-extension\\{}.h'.format(class_name)
    temp_file = '.\\temp\\{}.h'.format(class_name)
    if os.path.isfile(correct_file):
        print('{}.h'.format(class_name))
        fail = compare_files(correct_file, temp_file)
    correct_cpp_file = '.\\test-extension\\{}.cpp'.format(class_name)
    temp_cpp_file = '.\\temp\\{}.cpp'.format(class_name)
    if os.path.isfile(correct_cpp_file) and os.path.isfile(temp_cpp_file):
        print('{}.cpp'.format(class_name))
        fail += compare_files(correct_cpp_file, temp_cpp_file)
    print('')
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

    name = 'spatial'
    num = 35
    class_name = 'SpatialPoints'
    list_of = ''
    test_case = 'array type'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 8
    class_name = 'SampledFieldGeometry'
    list_of = ''
    test_case = 'non sbase base class'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 9
    class_name = 'SampledField'
    list_of = ''
    test_case = 'additional code files'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 18
    class_name = 'CSGTransformation'
    list_of = ''
    test_case = 'abstract non base class'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 3
    class_name = 'Boundary'
    list_of = ''
    test_case = 'overwrites element name'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_att'
    num = 1
    class_name = 'Unit'
    list_of = ''
    test_case = 'unit sid ref'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_att'
    num = 2
    class_name = 'MyLoTest'
    list_of = 'ListOfMyLoTests'
    test_case = 'attribute on ListOf'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'qual'
    num = 5
    class_name = 'FunctionTerm'
    list_of = 'ListOfFunctionTerms'
    test_case = 'an element on ListOf'
    fail += run_test(name, num, class_name, test_case, list_of)

    if use_new:
        name = 'test_vers'
        num = 0
        class_name = 'ClassOne'
        list_of = ''
        test_case = 'multiple versions'
        fail += run_test(name, num, class_name, test_case, list_of)

    name = 'qual'
    class_name = 'QualExtension'
    test_case = 'basic extension file'
    fail += run_ext_test(name, class_name, test_case, 0)

    name = 'qual'
    num = 0
    class_name = 'QualModelPlugin'
    test_case = 'basic plugin'
    fail += run_plug_test(name, class_name, test_case, num)

    name = 'qual'
    class_name = 'QualExtensionTypes'
    test_case = 'the types '
    fail += run_ext_test(name, class_name, test_case, 1)

    if fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('Check {} fails'.format(fail))


if __name__ == '__main__':
    main()
