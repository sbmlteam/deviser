#!/usr/bin/env python

import os
import sys

from ...code_files import CppFiles, BaseClassFiles, ValidationFiles, ExtensionFiles
from ...cmake_files import CMakeFiles
from ...bindings_files import BindingsFiles
from ...parseXML import ParseXML
from ...util import strFunctions, global_variables as gv, generateCode

from .. import test_functions

##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Utility functions

def common_set_up(filename):
    """
    Perform common setting-up steps.

    :param filename: name of XML file to parse.
    :return: big dictionary structure obtained from the parsing.
    """
    parser = ParseXML.ParseXML(filename)
    if parser is None:
        return None
    ob = parser.parse_deviser_xml()
    if ob is None:
        return None
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    for working_class in ob['baseElements']:
        if working_class['name'] == gv.document_class:
            working_class['document'] = True
    return ob


def go_into_new_directory():
    """
    Create the new ./temp directory if required. Go into it.
    """
    os.chdir('./temp')
    new_dir = gv.language
    if not os.path.isdir(new_dir):
        os.mkdir(new_dir)
    os.chdir(new_dir)


##############################################################################
# Specific generation functions


def generate_new_cpp_header(filename, num):
    """
    Generate new C++ header and code files.

    :param filename: the XML file to parse.
    :param num: index allowing code to generate for just one class rather
                than all - it's a list index.
    :return: nothing
    """
    ob = common_set_up(filename)
    assert ob is not None, "file not found: %s" % filename
    working_class = ob['baseElements'][num]
    if working_class['name'] == gv.document_class:
        working_class['document'] = True
    go_into_new_directory()
    all_files = CppFiles.CppFiles(working_class, True)
    all_files.write_files()
    os.chdir('../../.')


def generate_templates(filename):
    """
    Several of the files for other libraries are generated using
    templates with appropriate names etc added. See
    generator/code_files/templates.
    This function tests these

    :param filename: the XML file to parse.
    :return: nothing

    Validation class causes the errors for things to be enumerated and strings
    added. These will be needed by templates so with testing we have to
    create them first
    """
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    ValidationFiles.ValidationFiles(ob, True)
    go_into_new_directory()

    prefix = gv.prefix
    base_files = BaseClassFiles.BaseClassFiles(prefix,  ob['baseElements'], True)
    base_files.write_files()
    os.chdir('../../.')


def generate_common_templates(filename):
    """
    Write the 'common' files. These are the files that will be part of
    the common directory as they are used by all files in library.

    :param filename: the XML file to parse.
    :return: nothing
    """
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    go_into_new_directory()

    prefix = gv.prefix
    base_files = BaseClassFiles.BaseClassFiles(prefix,  ob['baseElements'], True)
    base_files.write_common_files()
    os.chdir('../../.')


def generate_forward(filename):
    """
    Write extension file with forward declaration of all opaque C types.

    :param filename: the XML file to parse.
    :return: nothing
    """
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    go_into_new_directory()

    ext = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    ext.write_files()
    os.chdir('../../.')


def generate_enum(filename):
    """
    According to ExtensionFile.py, this writes the extension types file.

    :param filename: the XML file to parse.
    :return: nothing

    For SBML, the extension file includes all the enums that are associated
    with a package. When generating code for a different library we still
    need a file that lists any enums so we create a version of the same file.

    Need to review this issue #44
    """
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    go_into_new_directory()

    ext = ExtensionFiles.ExtensionFiles(ob, 'enums', True)
    ext.write_files()
    os.chdir('../../.')


def generate_binding(filename, binding):
    """
    Generate the "binding" files.

    :param filename: the XML file to parse.
    :param binding: binding to use, e.g. 'swig', 'cmake', 'csharp'.
    :return: nothing
    """
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
    """
    Write CMake files CMakeLists.txt

    :param filename: the XML file to parse.
    :param binding: language binding, e.g. 'cmake'.
    :return: nothing
    """
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
    """
    Generate the global files required
    e.g. VERSION.txt, README.md, LICENSE.txt.

    :param filename: the XML file to parse.
    :return: nothing
    """
    common_set_up(filename)  # Don't need ob!
    go_into_new_directory()
    generateCode.generate_global_files()
    os.chdir('../../.')

#############################################################################
# Specific compare functions


def compare_files(correct_file, temp_file):
    """
    Wrapper function to compare two files: are they identical?

    :param correct_file: the reference file we are comparing against
    :param temp_file: temporary file generated by the test code.
    :returns: 0 on success (= files are identical), or file not present; 1 on failure.
    """
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)

#########

def compare_code(class_name, end):
    """
    Compare two 'code' files. Are they identical?

    :param class_name: name of C++ class used in the test.
    :param end: file extension, e.g. ".h", ".txt", etc.
    :returns: 0 on success, or file not present; 1 on failure.
    """
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
    """
    Compare two "binding" files.

    :param class_name: C++ class, e.g. "OStream"
    :param binding: the language binding,e.g. "swig" or "csharp"
    :param end: file extension, e.g. ".txt", ".cpp"
    :param prefix: I don't think this is ever used in any function calls.
    :returns: 0 on success, or file not present; 1 on failure.
    """
    correct_file = os.path.normpath('./test-code/{2}/{0}/{1}{3}'.format(binding, class_name, gv.language, end))
    # if prefix:
    temp_file = os.path.normpath('./temp/{3}/{0}/{2}/{1}{4}'.format(binding, class_name, prefix, gv.language, end))
    # else:
        # temp_file = os.path.normpath('./temp/{2}/{0}/{1}{3}'.format(binding, class_name, gv.language, end))
    return compare_files(correct_file, temp_file)


def compare_binding_headers(class_name, binding, prefix):
    return compare_binding(class_name, binding, ".h", prefix)

def compare_binding_impl(class_name, binding, prefix):
    return compare_binding(class_name, binding, ".cpp", prefix)

def compare_binding_interface(class_name, binding, prefix):
    return compare_binding(class_name, binding, ".i", prefix)

def compare_binding_file(class_name, binding, prefix):
    return compare_binding(class_name, binding, "", prefix)

##########

def compare_cmake_file(this_dir):
    """
    Compare a temporary test CMakeLists.txt file with the reference one.

    :param this_dir: lowest subdir containing the reference version of the file.
    :return: 0 on success, or file not present; 1 on failure.
    """
    correct_file = os.path.normpath('./test-code/{1}/cmake/{0}/CMakeLists.txt'.format(this_dir, gv.language))
    temp_file = os.path.normpath('./temp/{1}/cmake/{0}/CMakeLists.txt'.format(this_dir, gv.language))
    return compare_files(correct_file, temp_file)


#############################################################################
# Specific test functions


def run_test(name, num, class_name, test_case, list_of):
    """
    Run the C++ file tests.

    :param name: name of test group e.g. 'test_sedml', 'combine-archive'.
    :param num: list index, so we only generate a particular class not all of them
    :param class_name: name of C++ class (and thus .cpp/.h filenames), e.g. 'CaContent'
    :param test_case: brief test description
    :param list_of: class name (and thus filenames) of any corresponding "list of" class, e.g. 'CaListOfContents'
    :return: number of failed tests
    """
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
    """
    Run the 'template' file tests.

    :param name: name of test group e.g. 'test_sedml', 'combine-archive'.
    :param class_name: name of C++ class (and thus .cpp/.h filenames), e.g. 'SedBase'
    :param test_case: brief test description, e.g. 'templates'.
    :param list_of: class name (and thus filenames) of any corresponding "list of" class, e.g. 'SedListOf'
    :return: number of failed tests
    """
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_templates(filename)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    fail += compare_code_headers(list_of)
    fail += compare_code_impl(list_of)
    print('')
    return fail


def test_other_templates(prefix):
    """
    Compare a lot of different 'template' files.

    :param prefix: the start of the filename, e.g. Sed' or 'Ca'.
    :return: number of failed tests.
    """
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
    """
    Compare 'common' template files.

    :param name: e.g. 'test_sedml'
    :param class_name: C++ class/filenames, e.g. 'SedBase'
    :param test_case: e.g. 'common'
    :param prefix: e.g. 'Sed'
    :param lib: used for comparing lib files, e.g. 'sedml' for 'libsedml-*'.
    :return: number of failed tests.
    """
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
    """
    Run 'forward declaration' tests.

    :param name: stub of XML filename, e.g. 'test_sedml' for file test_sedml.xml.
    :param class_name: test class, e.g. 'sedmlfwd'
    :param test_case: brief test description, e.g. 'forward declarations'
    """
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_forward(filename)
    fail = compare_code_headers(class_name)
    print('')
    return fail


def run_enum(name, class_name, test_case):
    """
    Run extension types file tests.

    :param name: stub of XML file name, e.g. 'test_sedml' for file test_sedml.xml.
    :param class_name: test class, e.g. 'SedmlEnumerations'
    :param test_case: brief description of tests, e.g. 'enumerations'.
    """
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_enum(filename)
    fail = compare_code_headers(class_name)
    fail += compare_code_impl(class_name)
    print('')
    return fail


def test_bindings(name, class_name, test_case, binding, prefix):
    """
    Compare the 'bindings' files.

    :param name: stub of XML filename, e.g. 'test_sedml' for file test_sedml.xml.
    :param class_name: the test class, e.g. 'libsedml'
    :param test_case: brief description of tests, e.g. 'swig dir'
    :param binding: the binding type, e.g. 'swig'
    :param prefix: used to match library files, e.g. 'combine' matches libcombine-*.*
    :returns: number of failed tests.
    """
    filename = test_functions.set_up_test(name, class_name, test_case)
    generate_binding(filename, binding)
    fail = 0
    if binding == 'swig':
        fail += compare_binding_headers('ListWrapper', binding, "")
        fail += compare_binding_headers('OStream', binding, "")
        fail += compare_binding_impl('OStream', binding, "")
        fail += compare_binding_interface('std_set', binding, "")
        fail += compare_binding_headers('lib{0}'.format(prefix), binding, "")
        fail += compare_binding_interface('lib{0}'.format(prefix), binding, "")
        fail += compare_binding_interface('ASTNodes', binding, "")
    elif binding == 'csharp':
        fail += compare_binding_impl('local', binding, "")
        fail += compare_binding_interface('local', binding, "")
        fail += compare_binding_interface('lib{0}'.format(prefix), binding, "")
        fail += compare_binding_file('CMakeLists.txt', binding, "")
        fail += compare_binding_file('compile-native-files.cmake', binding, "")
        fail += compare_binding_file('AssemblyInfo.cs.in', binding, "")
    print('')
    return fail


def test_cmake(name, class_name):   # , test_case, binding):  # , prefix):
    """
    Generate and compare CMake files.

    TODO the following need more details:

    :param name: name of test, e.g. 'test_sedml' or 'combine-archive'.
    :param class_name:   e.g. 'libsedml' or 'libcombine'
    :returns: number of failed tests
    """
    filename = test_functions.set_up_test(name, class_name, "cmake")
    generate_cmake(filename, "cmake")
    fail = 0
    fail += compare_cmake_file("")
    fail += compare_cmake_file('src')
    fail += compare_cmake_file('src/bindings')
    fail += compare_cmake_file('src/{0}'.format(gv.language))
    print('')
    return fail


def test_global(name, class_name, test_case):
    """
    Generate and compare 'global' files, e.g. VERSION.txt, README.md.

    :param name: test file stub, e.g. 'test_sedml' for test_sedml.xml
    :param class_name: test class e.g. 'libsedml'
    :param test_case: brief description of test, e.g. 'global files'
    :returns: number of failed tests.
    """
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
    """
    Run the sedml tests.

    :param fail: integer number of tests failed so far
    :returns: updated value of `fail` after running these tests.
    """
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
    test_case = 'enumerations'
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
    # test_case = 'cmake'
    # binding = 'cmake'
    fail += test_cmake(name, class_name)  # , test_case, binding)  # , 'sedml')

    name = 'test_sedml'
    class_name = 'libsedml'
    test_case = 'global files'
    fail += test_global(name, class_name, test_case)

    return fail


def testCombine(fail):
    """
    Run the 'combine' tests.

    :param fail: integer number of tests failed so far
    :returns: updated value of `fail` after running these tests.
    """
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
    # test_case = 'cmake'
    # binding = 'cmake'
    fail += test_cmake(name, class_name)  # , test_case, binding)  # , 'combine')

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
