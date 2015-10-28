#!/usr/bin/env python

import os

from parseXML import createPackageFromXml
from code_files import CppFiles, ExtensionFiles, ValidationFiles
from parseXML import ParseXML
from util import global_variables

fails = []
not_tested = []


def generate_cpp_header(filename, num):
    ob = createPackageFromXml.parse_deviser_xml(filename)
    working_class = ob['baseElements'][num]
    os.chdir('./temp')
    all_files = CppFiles.CppFiles(working_class)
    all_files.write_files()
    os.chdir('../.')


def generate_new_cpp_header(filename, num):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    working_class = ob['baseElements'][num]
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


def generate_fwd_header(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    all_files.write_files()
    os.chdir('../.')


def generate_plugin_header(filename, num):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ExtensionFiles.ExtensionFiles(ob, '', True)
    all_files.write_plugin_files(num)
    os.chdir('../.')


def generate_error_header(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_error_header()
    os.chdir('../.')


def generate_validator(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_validator_files()
    os.chdir('../.')


def generate_constraints(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_constraints()
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


def run_test(name, num, class_name, test_case, list_of):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, class_name, test_case))
    print('====================================================')
    generate_new_cpp_header(filename, num)
    correct_file = '.\\test-code\\{}.h'.format(class_name)
    temp_file = '.\\temp\\{}.h'.format(class_name)
    fail = compare_files(correct_file, temp_file)
    correct_cpp_file = '.\\test-code\\{}.cpp'.format(class_name)
    temp_cpp_file = '.\\temp\\{}.cpp'.format(class_name)
    fail += compare_files(correct_cpp_file, temp_cpp_file)
    if len(list_of) > 0:
        class_name = list_of
        correct_file = '.\\test-code\\{}.h'.format(class_name)
        temp_file = '.\\temp\\{}.h'.format(class_name)
        fail += compare_files(correct_file, temp_file)
        correct_cpp_file = '.\\test-code\\{}.cpp'.format(class_name)
        temp_cpp_file = '.\\temp\\{}.cpp'.format(class_name)
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
    elif test == 1:
        generate_types_header(filename)
    else:
        generate_fwd_header(filename)
    correct_file = '.\\test-extension\\{}.h'.format(class_name)
    temp_file = '.\\temp\\{}.h'.format(class_name)
    fail = compare_files(correct_file, temp_file)
    if test == 0:
        correct_cpp_file = '.\\test-extension\\{}.cpp'.format(class_name)
        temp_cpp_file = '.\\temp\\{}.cpp'.format(class_name)
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
    fail = compare_files(correct_file, temp_file)
    correct_cpp_file = '.\\test-extension\\{}.cpp'.format(class_name)
    temp_cpp_file = '.\\temp\\{}.cpp'.format(class_name)
    fail += compare_files(correct_cpp_file, temp_cpp_file)
    print('')
    return fail


def run_valid_test(name, class_name, test_case, is_ext=True):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, class_name, test_case))
    print('====================================================')
    if is_ext:
        generate_error_header(filename)
        correct_file = '.\\test-extension\\{}.h'.format(class_name)
        temp_file = '.\\temp\\{}.h'.format(class_name)
        fail = compare_files(correct_file, temp_file)
    else:
        generate_validator(filename)
        correct_file = '.\\test-extension\\{}.h'.format(class_name)
        temp_file = '.\\temp\\{}.h'.format(class_name)
        fail = compare_files(correct_file, temp_file)
        correct_file = '.\\test-extension\\{}.cpp'.format(class_name)
        temp_file = '.\\temp\\{}.cpp'.format(class_name)
        fail += compare_files(correct_file, temp_file)
    print('')
    return fail


def run_constraints_test(name, class_name, test_case):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, class_name, test_case))
    print('====================================================')
    generate_constraints(filename)
    correct_file = '.\\test-extension\\{}.cpp'.format(class_name)
    temp_file = '.\\temp\\{}.cpp'.format(class_name)
    fail = compare_files(correct_file, temp_file)
    correct_cpp_file = '.\\test-extension\\{}Declared.cxx'.format(class_name)
    temp_cpp_file = '.\\temp\\{}Declared.cxx'.format(class_name)
    fail += compare_files(correct_cpp_file, temp_cpp_file)
    print('')
    return fail


def main():
    global_variables.running_tests = True

    fail = 0
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

    name = 'test_att'
    num = 0
    class_name = 'MyTestClass'
    list_of = ''
    test_case = 'all types of attributes'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_att'
    num = 3
    class_name = 'MyRequiredClass'
    list_of = ''
    test_case = 'all types attributes required'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_att'
    num = 4
    class_name = 'ArrayChild'
    list_of = ''
    test_case = 'child elements and arrays'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'qual'
    num = 5
    class_name = 'FunctionTerm'
    list_of = 'ListOfFunctionTerms'
    test_case = 'an element on ListOf'
    fail += run_test(name, num, class_name, test_case, list_of)

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

    name = 'qual'
    class_name = 'qualfwd'
    test_case = 'forward declarations '
    fail += run_ext_test(name, class_name, test_case, 2)

    name = 'qual'
    num = 1
    class_name = 'QualSBMLDocumentPlugin'
    test_case = 'document plugin'
    fail += run_plug_test(name, class_name, test_case, num)

    name = 'qual'
    class_name = 'QualSBMLError'
    test_case = 'error enumeration '
    fail += run_valid_test(name, class_name, test_case)

    name = 'qual'
    class_name = 'QualConsistencyValidator'
    test_case = 'validator'
    fail += run_valid_test(name, class_name, test_case, False)

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

    name = 'spatial'
    num = 13
    class_name = 'ParametricGeometry'
    list_of = ''
    test_case = 'child element and child lo_element'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 12
    class_name = 'AnalyticVolume'
    list_of = ''
    test_case = 'class with math child'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 33
    class_name = 'MixedGeometry'
    list_of = ''
    test_case = 'class with math child'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 26
    class_name = 'CSGSetOperator'
    list_of = ''
    test_case = 'contains list of that has abstracts that are abstract'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'spatial'
    num = 1
    class_name = 'SpatialCompartmentPlugin'
    test_case = 'plugin with child element'
    fail += run_plug_test(name, class_name, test_case, num)

    name = 'spatial'
    num = 3
    class_name = 'SpatialParameterPlugin'
    test_case = 'plugin with additional code'
    fail += run_plug_test(name, class_name, test_case, num)

    name = 'spatial'
    num = 4
    class_name = 'SpatialReactionPlugin'
    test_case = 'plugin only attributes'
    fail += run_plug_test(name, class_name, test_case, num)

    name = 'spatial'
    num = 5
    class_name = 'SpatialSBMLDocumentPlugin'
    test_case = 'include line over extends'
    fail += run_plug_test(name, class_name, test_case, num)

    name = 'spatial'
    class_name = 'SpatialConsistencyConstraints'
    test_case = 'constraints'
    fail += run_constraints_test(name, class_name, test_case)

    name = 'spatial'
    class_name = 'SpatialValidator'
    test_case = 'validator'
    fail += run_valid_test(name, class_name, test_case, False)

    name = 'test_vers'
    num = 0
    class_name = 'ClassOne'
    list_of = ''
    test_case = 'multiple versions'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_vers'
    num = 2
    class_name = 'BBB'
    list_of = ''
    test_case = 'multiple versions same child lo'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_vers'
    num = 0
    class_name = 'VersModelPlugin'
    test_case = 'versions of plugins - attributes'
    fail += run_plug_test(name, class_name, test_case, num)

    name = 'test_vers'
    num = 1
    class_name = 'VersSpeciesPlugin'
    test_case = 'versions of plugins - elements'
    fail += run_plug_test(name, class_name, test_case, num)

    name = 'test_vers'
    class_name = 'VersExtension'
    test_case = 'multi version extension file'
    fail += run_ext_test(name, class_name, test_case, 0)

    name = 'fbc_v2'
    num = 5
    class_name = 'FbcAnd'
    list_of = ''
    test_case = 'inline_lo_element'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_child'
    num = 0
    class_name = 'MySEDClass'
    list_of = ''
    test_case = 'different language'
    # global_variables.set_globals('sedml', 'SedBase', 'SedDocument', 'Sed',
    #                              'Libsedml', False)
    fail += run_test(name, num, class_name, test_case, list_of)

    if len(not_tested) > 0:
        print('The following files were not tested:')
        for name in not_tested:
            print(name)

    if fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('Check {} fails'.format(fail))
        for name in fails:
            print(name)


if __name__ == '__main__':
    main()
