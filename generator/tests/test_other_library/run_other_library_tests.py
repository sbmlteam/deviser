#!/usr/bin/env python

import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')

from code_files import CppFiles, BaseClassFiles, ValidationFiles, ExtensionFiles
from cmake_files import CMakeFiles
from bindings_files import BindingsFiles
from parseXML import ParseXML
from util import strFunctions, global_variables as gv, generateCode

from tests import test_functions

##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Specific generation functions


def generate_new_cpp_header(filename, num):
    ob = common_set_up(filename)
    working_class = ob['baseElements'][num]
    if working_class['name'] == gv.document_class:
        working_class['document'] = True
    go_into_new_directory()
    all_files = CppFiles.CppFiles(working_class, True)
    all_files.write_files()
    os.chdir('../../.')


def common_set_up(filename):
    """
    Perform common setting-up steps.

    :param filename: name of XML file to parse.
    :return: big dictionary structure obtained from the parsing.
    """
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    for working_class in ob['baseElements']:
        if working_class['name'] == gv.document_class:
            working_class['document'] = True
    return ob


def go_into_new_directory():
    """
    Create the new directory if required. Go into it.
    """
    os.chdir('./temp')
    new_dir = gv.language
    if not os.path.isdir(new_dir):
        os.mkdir(new_dir)
    os.chdir(new_dir)


def generate_templates(filename):
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    ValidationFiles.ValidationFiles(ob, True)
    go_into_new_directory()

    prefix = gv.prefix
    base_files = BaseClassFiles.BaseClassFiles(prefix,  ob['baseElements'], True)
    base_files.write_files()
    os.chdir('../../.')


def generate_common_templates(filename):
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    go_into_new_directory()

    prefix = gv.prefix
    base_files = BaseClassFiles.BaseClassFiles(prefix,  ob['baseElements'], True)
    base_files.write_common_files()
    os.chdir('../../.')


def generate_forward(filename):
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    go_into_new_directory()

    ext = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    ext.write_files()
    os.chdir('../../.')


def generate_enum(filename):
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    go_into_new_directory()

    ext = ExtensionFiles.ExtensionFiles(ob, 'enums', True)
    ext.write_files()
    os.chdir('../../.')


def generate_binding(filename, binding):
    ob = common_set_up(filename)
    go_into_new_directory()

    if not os.path.isdir(binding):
        os.mkdir(binding)
    os.chdir(binding)
    all_files = BindingsFiles.BindingFiles(ob, binding, True)
    all_files.write_files()
    os.chdir('../.')
    os.chdir('../../.')


def generate_cmake(filename, binding):
    ob = common_set_up(filename)
    go_into_new_directory()

    if not os.path.isdir(binding):
        os.mkdir(binding)
    os.chdir(binding)

    this_dir = os.getcwd()
    test_functions.create_dir('src')
    os.chdir('src')
    test_functions.create_dir('bindings')
    test_functions.create_dir('{0}'.format(gv.language))
    os.chdir(this_dir)
    bind = CMakeFiles.CMakeFiles(ob, this_dir, True)
    bind.write_other_library_files()
    os.chdir('../.')
    os.chdir('../../.')


def generate_global(filename):
    common_set_up(filename)  # Don't need ob!
    go_into_new_directory()
    generateCode.generate_global_files()
    os.chdir('../../.')

#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)

#########

def compare_code(class_name, end):
    correct_file = os.path.normpath('./test-code/{1}/{0}{2}'.format(class_name, gv.language, end))
    temp_file = os.path.normpath('./temp/{1}/{0}{2}'.format(class_name, gv.language, end))
    return compare_files(correct_file, temp_file)

def compare_code_headers(class_name):
    return compare_code(class_name, ".h")

def compare_code_impl(class_name):
    return compare_code(class_name, ".cpp")

def compare_code_cmake(class_name):
    return compare_code(class_name, ".cmake")

def compare_code_txt(class_name, ext='.txt'):
    return compare_code(class_name, ext)

#########

def compare_binding(class_name, binding, end, prefix=""):
    correct_file = os.path.normpath('./test-code/{2}/{0}/{1}{3}'.format(binding, class_name, gv.language, end))
    #if prefix:
    temp_file = os.path.normpath('./temp/{3}/{0}/{2}/{1}{4}'.format(binding, class_name, prefix, gv.language, end))
    #else:
        #temp_file = os.path.normpath('./temp/{2}/{0}/{1}{3}'.format(binding, class_name, gv.language, end))
    return compare_files(correct_file, temp_file)

def compare_binding_headers(class_name, binding, prefix):
    return compare_binding(class_name, binding, ".h", prefix)
# temp/omex/swig/combine/OStream.h=================>> MISSING
# temp/sedml/swig/sedml/OStream.h=================>> MISSING
# compare_binding_headers('OStream', binding is swig, prefix is sedml or combine??)
# present: temp/omex/swig/OStream.h  and  temp/sedml/swig/OStream.h

def compare_binding_impl(class_name, binding, prefix):
    return compare_binding(class_name, binding, ".cpp", prefix)

def compare_binding_interface(class_name, binding, prefix):
    return compare_binding(class_name, binding, ".i", prefix)

def compare_binding_file(class_name, binding, prefix):
    return compare_binding(class_name, binding, "", prefix)

##########

def compare_cmake_file(this_dir, prefix):
    correct_file = os.path.normpath('./test-code/{0}/cmake/CMakeLists.txt'.format(gv.language))
    temp_file = os.path.normpath('./temp/{1}/cmake/{0}/CMakeLists.txt'.format(this_dir, gv.language))
    #temp_file = os.path.normpath('./temp/{0}/cmake/{0}/CMakeLists.txt'.format(gv.language))
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
    fail = compare_code_headers('common')
    fail += compare_code_headers('extern')
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


def run_enum(name, class_name, test_case):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_enum(filename)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    print('')
    return fail


def test_bindings(name, class_name, test_case, binding, prefix):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_binding(filename, binding)
    fail = 0
    if binding == 'swig':
        fail += compare_binding_headers('ListWrapper', binding, "") #prefix)
        fail += compare_binding_headers('OStream', binding, "") #prefix)
        fail += compare_binding_impl('OStream', binding, "") #prefix)
        fail += compare_binding_interface('std_set', binding, "") #prefix)
        fail += compare_binding_headers('lib{0}'.format(prefix), binding, "") #prefix)
        fail += compare_binding_interface('lib{0}'.format(prefix), binding, "") #prefix)
        fail += compare_binding_interface('ASTNodes', binding, "") #prefix)
    elif binding == 'csharp':
        fail += compare_binding_impl('local', binding, "") #prefix)
        fail += compare_binding_interface('local', binding, "") #prefix)
        fail += compare_binding_interface('lib{0}'.format(prefix), binding, "") #prefix)
        fail += compare_binding_file('CMakeLists.txt', binding, "") #prefix)
        fail += compare_binding_file('compile-native-files.cmake', binding, "") #prefix)
        fail += compare_binding_file('AssemblyInfo.cs.in', binding, "") #prefix)
    print('')
    return fail


def test_cmake(name, class_name, test_case, binding, prefix):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_cmake(filename, binding)
    fail = 0
    fail += compare_cmake_file("", prefix)
    fail += compare_cmake_file('src', prefix)
    fail += compare_cmake_file('src/bindings', prefix)
    fail += compare_cmake_file('src/{0}'.format(gv.language), prefix)
    print('')
    return fail


def test_global(name, class_name, test_case):
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_global(filename)
    fail = 0
    fail += compare_code_txt('VERSION')
    fail += compare_code_txt('README', '.md')
    print('')
    return fail


#########################################################################
# Main functions

def testSedML(fail):
    gv.reset()

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
    class_name = 'SedmlEnumerations'
    test_case = 'enumnerations'
    fail += run_enum(name, class_name, test_case)

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
    num = 26
    class_name = 'SedSetValue'
    list_of = ''
    test_case = 'astnode used'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 12
    class_name = 'SedDataGenerator'
    list_of = ''
    test_case = 'astnode in getElementBySId bug'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 33
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
    num = 28
    class_name = 'SedVectorRange'
    list_of = ''
    test_case = 'deal with vectors'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 10
    class_name = 'SedAbstractTask'
    list_of = 'SedListOfTasks'
    test_case = 'catch different abstract types'
    fail += run_test(name, num, class_name, test_case, list_of)

    name = 'test_sedml'
    num = 13
    class_name = 'SedOutput'
    list_of = 'SedListOfOutputs'
    test_case = 'catch different abstract types'
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

    return fail


def testCombine(fail):
    gv.reset()

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
    test_case = 'csharp dir'
    binding = 'csharp'
    fail += test_bindings(name, class_name, test_case, binding, 'combine')

    name = 'combine-archive'
    class_name = 'libcombine'
    test_case = 'swig dir'
    binding = 'swig'
    fail += test_bindings(name, class_name, test_case, binding, 'combine')

    name = 'combine-archive'
    class_name = 'libcombine'
    test_case = 'cmake'
    binding = 'cmake'
    fail += test_cmake(name, class_name, test_case, binding, 'combine')

    return fail


def main():

    test_all = True
#    test_all = False
    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))
    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0
    gv.reset()

    if test_all:
        fail = testSedML(fail)
        fail = testCombine(fail)
    else:
        name = 'test_sedml'
        num = 33
        class_name = 'SedRepeatedTask'
        list_of = ''
        test_case = 'attribute with different xml name'
        fail += run_test(name, num, class_name, test_case, list_of)

    test_functions.report('OTHER LIBRARY', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
