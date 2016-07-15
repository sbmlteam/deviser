#!/usr/bin/env python

import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')

from code_files import CppFiles, BaseClassFiles, ValidationFiles, ExtensionFiles
from cmake_files import CMakeFiles
from bindings_files import BindingsFiles
from parseXML import ParseXML
from util import strFunctions, global_variables, generateCode

from tests import test_functions

##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions


def generate_new_cpp_header(filename, num):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    for working_class in ob['baseElements']:
        if working_class['name'] == global_variables.document_class:
            working_class['document'] = True
    working_class = ob['baseElements'][num]
    if working_class['name'] == global_variables.document_class:
        working_class['document'] = True
    os.chdir('./temp')
    all_files = CppFiles.CppFiles(working_class, True)
    all_files.write_files()
    os.chdir('../.')

def generate_templates(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    prefix = global_variables.prefix
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    for working_class in ob['baseElements']:
        if working_class['name'] == global_variables.document_class:
            working_class['document'] = True
    global_variables.populate_error_list(ob)
    ValidationFiles.ValidationFiles(ob, True)
    os.chdir('./temp')
    base_files = BaseClassFiles.BaseClassFiles(prefix,  ob['baseElements'], True)
    base_files.write_files()
    os.chdir('../.')

def generate_common_templates(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    for working_class in ob['baseElements']:
        if working_class['name'] == global_variables.document_class:
            working_class['document'] = True
    global_variables.populate_error_list(ob)
    prefix = global_variables.prefix
    os.chdir('./temp')
    base_files = BaseClassFiles.BaseClassFiles(prefix,  ob['baseElements'], True)
    base_files.write_common_files()
    os.chdir('../.')

def generate_forward(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    for working_class in ob['baseElements']:
        if working_class['name'] == global_variables.document_class:
            working_class['document'] = True
    global_variables.populate_error_list(ob)
    os.chdir('./temp')
    ext = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    ext.write_files()
    os.chdir('../.')

def generate_binding(filename, binding):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if os.path.isdir(binding):
        os.chdir(binding)
    else:
        os.makedirs(binding)
        os.chdir(binding)
    all_files = BindingsFiles.BindingFiles(ob, binding, True)
    all_files.write_files()
    os.chdir('../.')
    os.chdir('../.')

def generate_cmake(filename, binding):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if os.path.isdir(binding):
        os.chdir(binding)
    else:
        os.makedirs(binding)
        os.chdir(binding)
    this_dir = os.getcwd()
    test_functions.create_dir('src')
    os.chdir('src')
    test_functions.create_dir('bindings')
    test_functions.create_dir('{0}'.format(global_variables.language))
    os.chdir(this_dir)
    bind = CMakeFiles.CMakeFiles(ob, this_dir, True)
    bind.write_other_library_files()
    os.chdir('../.')
    os.chdir('../.')

def generate_global(filename):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    generateCode.generate_global_files()
    os.chdir('../.')

#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_code_headers(class_name, lib=None):
    if not lib:
        correct_file = '.\\test-code\\{0}.h'.format(class_name)
        temp_file = '.\\temp\\{0}.h'.format(class_name)
    else:
        correct_file = '.\\test-code\\{1}\\{0}.h'.format(class_name, lib)
        temp_file = '.\\temp\\{0}.h'.format(class_name)
    return compare_files(correct_file, temp_file)


def compare_code_impl(class_name):
    correct_file = '.\\test-code\\{0}.cpp'.format(class_name)
    temp_file = '.\\temp\\{0}.cpp'.format(class_name)
    return compare_files(correct_file, temp_file)


def compare_code_cmake(class_name):
    correct_file = '.\\test-code\\{0}.cmake'.format(class_name)
    temp_file = '.\\temp\\{0}.cmake'.format(class_name)
    return compare_files(correct_file, temp_file)

def compare_code_txt(class_name, ext='txt'):
    correct_file = '.\\test-code\\{0}.{1}'.format(class_name, ext)
    temp_file = '.\\temp\\{0}.{1}'.format(class_name, ext)
    return compare_files(correct_file, temp_file)

def compare_binding_headers(class_name, binding, prefix):
    correct_file = '.\\test-code\\{0}\\{2}\\{1}.h'.format(binding, class_name, prefix)
    temp_file = '.\\temp\\{0}\\{1}.h'.format(binding, class_name)
    return compare_files(correct_file, temp_file)

def compare_binding_impl(class_name, binding, prefix):
    correct_file = '.\\test-code\\{0}\\{2}\\{1}.cpp'.format(binding, class_name, prefix)
    temp_file = '.\\temp\\{0}\\{1}.cpp'.format(binding, class_name)
    return compare_files(correct_file, temp_file)

def compare_binding_interface(class_name, binding, prefix):
    correct_file = '.\\test-code\\{0}\\{2}\\{1}.i'.format(binding, class_name, prefix)
    temp_file = '.\\temp\\{0}\\{1}.i'.format(binding, class_name)
    return compare_files(correct_file, temp_file)

def compare_binding_file(class_name, binding, prefix):
    correct_file = '.\\test-code\\{0}\\{2}\\{1}'.format(binding, class_name, prefix)
    temp_file = '.\\temp\\{0}\\{1}'.format(binding, class_name)
    return compare_files(correct_file, temp_file)

def compare_cmake_file(this_dir, prefix):
    if this_dir == prefix:
        correct_file = '.\\test-code\\cmake\\{0}\\CMakeLists.txt'.format(prefix)
        temp_file = '.\\temp\\cmake\\CMakeLists.txt'
    else:
        correct_file = '.\\test-code\\cmake\\{1}\\{0}\\CMakeLists.txt'.format(this_dir, prefix)
        temp_file = '.\\temp\\cmake\\{0}\\CMakeLists.txt'.format(this_dir)
    return compare_files(correct_file, temp_file)

#############################################################################
# Specific test functions

def run_test(name, num, class_name, test_case, list_of):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_new_cpp_header(filename, num)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    if len(list_of) > 0:
        class_name = list_of
        fail += compare_code_headers(class_name)
        fail += compare_code_impl(class_name)
    print('')
    return fail


def run_templates(name, class_name, test_case, list_of):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_templates(filename)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    fail += compare_code_headers(list_of)
    fail += compare_code_impl(list_of)
    print('')
    return fail

def test_other_templates(prefix):
    fail = compare_code_headers('{0}ConstructorException'.format(prefix))
    fail += compare_code_impl('{0}ConstructorException'.format(prefix))
    fail += compare_code_headers('{0}Reader'.format(prefix))
    fail += compare_code_impl('{0}Reader'.format(prefix))
    fail += compare_code_headers('{0}Writer'.format(prefix))
    fail += compare_code_impl('{0}Writer'.format(prefix))
    fail += compare_code_headers('{0}ErrorLog'.format(prefix))
    fail += compare_code_impl('{0}ErrorLog'.format(prefix))
    fail += compare_code_headers('{0}Namespaces'.format(prefix))
    fail += compare_code_impl('{0}Namespaces'.format(prefix))
    fail += compare_code_headers('{0}Error'.format(prefix))
    fail += compare_code_impl('{0}Error'.format(prefix))
    fail += compare_code_headers('{0}Types'.format(prefix))
    fail += compare_code_headers('{0}TypeCodes'.format(prefix))
    fail += compare_code_impl('{0}TypeCodes'.format(prefix))
    fail += compare_code_headers('{0}Visitor'.format(prefix))
    fail += compare_code_impl('{0}Visitor'.format(prefix))
    fail += compare_code_headers('{0}ErrorTable'.format(prefix))
    print('')
    return fail

def test_common_templates(name, class_name, test_case, prefix, lib):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_common_templates(filename)
    fail = compare_code_headers('common', lib)
    fail += compare_code_headers('extern', lib)
    fail += compare_code_headers('lib{0}-config'.format(lib))
    fail += compare_code_impl('lib{0}-version'.format(lib))
    fail += compare_code_headers('{0}OperationReturnValues'.format(prefix))
    fail += compare_code_impl('{0}OperationReturnValues'.format(prefix))
    fail += compare_code_cmake('lib{0}-version.h'.format(lib))
    fail += compare_code_cmake('lib{0}-config-common.h'.format(lib))
    fail += compare_code_cmake('lib{0}-namespace.h'.format(lib))
    print('')
    return fail

def run_forward(name, class_name, test_case):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_forward(filename)
    fail = compare_code_headers(class_name)
    print('')
    return fail

def test_bindings(name, class_name, test_case, binding, prefix):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_binding(filename, binding)
    fail = 0
    if binding == 'swig':
        fail += compare_binding_headers('ListWrapper', binding, prefix)
        fail += compare_binding_headers('OStream', binding, prefix)
        fail += compare_binding_impl('OStream', binding, prefix)
        fail += compare_binding_interface('std_set', binding, prefix)
        fail += compare_binding_headers('lib{0}'.format(prefix), binding, prefix)
        fail += compare_binding_interface('lib{0}'.format(prefix), binding, prefix)
        fail += compare_binding_interface('ASTNodes', binding, prefix)
    elif binding == 'csharp':
        fail += compare_binding_impl('local', binding, prefix)
        fail += compare_binding_interface('local', binding, prefix)
        fail += compare_binding_interface('lib{0}'.format(prefix), binding, prefix)
        fail += compare_binding_file('CMakeLists.txt', binding, prefix)
        fail += compare_binding_file('compile-native-files.cmake', binding, prefix)
        fail += compare_binding_file('AssemblyInfo.cs.in', binding, prefix)
    print('')
    return fail

def test_cmake(name, class_name, test_case, binding, prefix):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_cmake(filename, binding)
    fail = 0
    fail += compare_cmake_file('{0}'.format(prefix), prefix)
    fail += compare_cmake_file('src'.format(prefix), prefix)
    fail += compare_cmake_file('src\\bindings'.format(prefix), prefix)
    fail += compare_cmake_file('src\\{0}'.format(global_variables.language, prefix), prefix)
    print('')
    return fail

def test_global(name, class_name, test_case):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_global(filename)
    fail = 0
    fail += compare_code_txt('VERSION')
    fail += compare_code_txt('README', 'md')
    print('')
    return fail


#########################################################################
# Main function

def main():

    # set up the enivornment
    this_dir = os.path.dirname(os.path.abspath(__file__))
    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0

    # run the individual tests
    name = 'test_sedml'
    num = 1
    class_name = 'SedModel'
    list_of = 'SedListOfModels'
    test_case = 'model'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 0
    class_name = 'SedDocument'
    list_of = ''
    test_case = 'document'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    class_name = 'SedBase'
    list_of = 'SedListOf'
    test_case = 'templates'
    fail += run_templates(name, class_name, test_case, list_of)
    fail += test_other_templates('Sed')

    name = 'test_sedml'
    class_name = 'SedBase'
    test_case = 'common'
    fail += test_common_templates(name, class_name, test_case, 'Sed', 'sedml')

    name = 'test_sedml'
    class_name = 'sedmlfwd'
    test_case = 'forward declarations'
    fail += run_forward(name, class_name, test_case)

    name = 'test_sedml'
    num = 3
    class_name = 'SedAddXML'
    list_of = ''
    test_case = 'xmlnode used'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 4
    class_name = 'SedSetValue'
    list_of = ''
    test_case = 'astnode used'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 5
    class_name = 'SedDataGenerator'
    list_of = ''
    test_case = 'astnode in getElementBySId bug'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 6
    class_name = 'SedRepeatedTask'
    list_of = ''
    test_case = 'attribute with different xml name'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 7
    class_name = 'SedSimulation'
    list_of = ''
    test_case = 'child element'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 8
    class_name = 'SedVectorRange'
    list_of = ''
    test_case = 'deal with vectors'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    class_name = 'libsedml'
    test_case = 'swig dir'
    binding = 'swig'
    fail += test_bindings(name, class_name, test_case, binding, 'sedml')

    name = 'test_sedml'
    class_name = 'libsedml'
    test_case = 'csharp dir'
    binding = 'csharp'
    fail += test_bindings(name, class_name, test_case, binding, 'sedml')

    name = 'test_sedml'
    class_name = 'libsedml'
    test_case = 'cmake'
    binding = 'cmake'
    fail += test_cmake(name, class_name, test_case, binding, 'sedml')

    name = 'test_sedml'
    class_name = 'libsedml'
    test_case = 'global files'
    fail += test_global(name, class_name, test_case)

    global_variables.reset()

    name = 'combine-archive'
    num = 0
    class_name = 'CaContent'
    list_of = 'CaListOfContents'
    test_case = 'check includes'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'combine-archive'
    class_name = 'CaBase'
    list_of = 'CaListOf'
    test_case = 'templates'
    fail += run_templates(name, class_name, test_case, list_of)
    fail += test_other_templates('Ca')


    name = 'combine-archive'
    class_name = 'CaBase'
    test_case = 'common'
    fail += test_common_templates(name, class_name, test_case, 'Ca', 'combine')

    name = 'combine-archive'
    num = 1
    class_name = 'CaOmexManifest'
    list_of = ''
    test_case = 'document'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'combine-archive'
    class_name = 'libcombine'
    test_case = 'cmake'
    binding = 'cmake'
    fail += test_cmake(name, class_name, test_case, binding, 'combine')

    test_functions.report('OTHER LIBRARY', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
