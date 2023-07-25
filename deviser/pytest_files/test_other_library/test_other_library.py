# Matthew S. Gillman, UCL, 19th April 2021.
import os
import shutil

import pytest

from ...pytest_files import functions
from . import test_utils
from ...util import global_variables as gv


def setup():
    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, _) = os.path.split(this_dir)
    temp_dir = os.path.join(this_dir, 'temp')
    functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir(temp_dir):
        os.mkdir(temp_dir)
    os.chdir(this_dir)


def teardown():
    # delete temp dir
    this_dir = os.path.dirname(os.path.abspath(__file__))
    temp_dir = os.path.join(this_dir, 'temp')
    if os.path.isdir(temp_dir):
        shutil.rmtree(temp_dir)


@pytest.mark.parametrize('name, num, class_name, test_case, list_of', [
#     ('test_sedml', 1, 'SedModel', 'model', 'SedListOfModels'),
#     ('test_sedml', 0, 'SedDocument', 'document', ''),
#     ('test_sedml', 3, 'SedAddXML', 'xmlnode used', ''),
#     ('test_sedml', 26, 'SedSetValue', 'astnode used', ''),
#     ('test_sedml', 12, 'SedDataGenerator', 'astnode in getElementBySId bug', ''),
#     ('test_sedml', 33, 'SedRepeatedTask', 'attribute with different xml name', ''),
#     ('test_sedml', 7, 'SedSimulation', 'child element', ''),
#     ('test_sedml', 28, 'SedVectorRange', 'deal with vectors', ''),
#     ('test_sedml', 10, 'SedAbstractTask', 'catch different abstract types',
#      'SedListOfTasks'),
#     ('test_sedml', 13, 'SedOutput', 'catch different abstract types',
#      'SedListOfOutputs'),
#     ('combine-archive', 0, 'CaContent', 'check includes', 'CaListOfContents'),
#     ('combine-archive', 1, 'CaOmexManifest', 'document', ''),
     ('testsbxml', 1, 'TSBComment', 'comment class', 'TSBListOfComments'),
    ('testsbxml', 0, 'TSBDocument', 'document', ''),
])
def test_cpp(name, num, class_name, test_case, list_of):
    """
    Based on old test_utils.run_templates() function. Run the 'template' file tests.#

    :param name: name of test group e.g. 'test_sedml', 'combine-archive'.
    :param class_name: name of C++ class (and thus .cpp/.h filenames),
                e.g. 'SedBase'
    :param test_case: brief test description, e.g. 'templates'.
    :param list_of: class name (and thus filenames) of any corresponding
                "list of" class, e.g. 'SedListOf'
    """
    gv.reset()
    xml_filename = functions.set_up_test(name, class_name, test_case)
    assert xml_filename is not None and xml_filename != ""
    test_utils.generate_new_cpp_header(xml_filename, num)
    assert 0 == test_utils.compare_code_headers(class_name)
    assert 0 == test_utils.compare_code_impl(class_name)
    if len(list_of) > 0:
       class_name = list_of
       assert 0 == test_utils.compare_code_headers(class_name)
       assert 0 == test_utils.compare_code_impl(class_name)


@pytest.mark.parametrize('name, class_name, test_case, list_of', [
#     # Tests from old test_utils.testCombine()
#     ('test_sedml', 'SedBase', 'templates', 'SedListOf'),
#     ('combine-archive', 'CaBase', 'templates', 'CaListOf'),
    ('testsbxml', 'TSBBase', 'templates', 'TSBListOf'),
    ('testsbxml', 'TSBError', 'templates', ''),
    ('testsbxml', 'TSBErrorTable', 'templates', ''),
    ('testsbxml', 'TSBErrorLog', 'templates', ''),
    ('testsbxml', 'TSBNamespaces', 'templates', ''),
    ('testsbxml', 'TSBReader', 'templates', ''),
    ('testsbxml', 'TSBVisitor', 'templates', ''),
    ('testsbxml', 'TSBTypeCodes', 'templates', ''),
    ('testsbxml', 'TSBTypes', 'templates', ''),
    ('testsbxml', 'TSBWriter', 'templates', ''),
])
def test_templates(name, class_name, test_case, list_of):
    """
    Based on old test_utils.run_templates() function. Run the 'template' file tests.

    :param name: name of test group e.g. 'test_sedml', 'combine-archive'.
    :param class_name: name of C++ class (and thus .cpp/.h filenames),
                 e.g. 'SedBase'
    :param test_case: brief test description, e.g. 'templates'.
    :param list_of: class name (and thus filenames) of any corresponding
                 "list of" class, e.g. 'SedListOf'
    """
    gv.reset()
    xml_filename = functions.set_up_test(name, class_name, test_case)
    assert xml_filename is not None and xml_filename != ""
    test_utils.generate_templates(xml_filename)
    assert 0 == test_utils.compare_code_headers(class_name)
    if not class_name.endswith('ErrorTable') and not class_name.endswith('Types'):
        assert 0 == test_utils.compare_code_impl(class_name)
    assert 0 == test_utils.compare_code_headers(list_of)
    assert 0 == test_utils.compare_code_impl(list_of)


@pytest.mark.parametrize('name, class_name, test_case, prefix, lib', [
#     ('test_sedml', 'SedBase', 'common', 'Sed', 'sedml'),
#     ('combine-archive', 'CaBase', 'common', 'Ca', 'combine'),
    ('testsbxml', 'TSBBase', 'common', 'TSB', 'tsb'),
])
def test_common_templates(name, class_name, test_case, prefix, lib):
    """
    Based on test_utils.test_common_templates() function.
    Compare 'common' template files.

    :param name: e.g. 'test_sedml'
    :param class_name: C++ class/filenames, e.g. 'SedBase'
    :param test_case: e.g. 'common'
    :param prefix: e.g. 'Sed'
    :param lib: used for comparing lib files, e.g. 'sedml' for 'libsedml-*'.
    :return: number of failed tests.
    """
    gv.reset()
    xml_filename = functions.set_up_test(name, class_name, test_case)
    test_utils.generate_common_templates(xml_filename)
    assert 0 == test_utils.compare_code_headers('common')
    assert 0 == test_utils.compare_code_headers('extern')
    assert 0 == test_utils.compare_code_headers('lib{0}-config'.format(lib))
    assert 0 == test_utils.compare_code_impl('lib{0}-version'.format(lib))
    assert 0 == test_utils.compare_code_headers('{0}OperationReturnValues'.
                                                format(prefix))
    assert 0 == test_utils.compare_code_impl('{0}OperationReturnValues'.
                                             format(prefix))
    assert 0 == test_utils.compare_code_cmake('lib{0}-version.h'.format(lib))
    assert 0 == test_utils.compare_code_cmake('lib{0}-config-common.h'.format(lib))
    assert 0 == test_utils.compare_code_cmake('lib{0}-namespace.h'.format(lib))
#
#
# @pytest.mark.parametrize('name, class_name, test_case', [
#     ('test_sedml', 'SedmlEnumerations', 'enumerations'),
# ])
# def test_enum(name, class_name, test_case):
#     """
#     Based on old run_enum() function.
#     Run extension types file tests.
#
#     :param name: stub of XML file name, e.g. 'test_sedml' for
#                file test_sedml.xml.
#     :param class_name: test class, e.g. 'SedmlEnumerations'
#     :param test_case: brief description of tests, e.g. 'enumerations'.
#     """
#     gv.reset()
#     xml_filename = functions.set_up_test(name, class_name, test_case)
#     test_utils.generate_enum(xml_filename)
#     assert 0 == test_utils.compare_code_headers(class_name)
#     assert 0 == test_utils.compare_code_impl(class_name)
#
#
# @pytest.mark.parametrize('name, class_name, test_case, binding, prefix', [
#     ('test_sedml', 'libsedml', 'swig dir', 'swig', 'sedml'),
#     ('test_sedml', 'libsedml', 'csharp dir', 'csharp', 'sedml'),
#     ('combine-archive', 'libcombine', 'csharp dir', 'csharp', 'combine'),
#     ('combine-archive', 'libcombine', 'swig dir', 'swig', 'combine'),
# ])
# def test_bindings(name, class_name, test_case, binding, prefix):
#     """
#     Based on old test_bindings() function.
#     Compare the 'bindings' files.
#
#     :param name: stub of XML filename, e.g. 'test_sedml' for
#               file test_sedml.xml.
#     :param class_name: the test class, e.g. 'libsedml'
#     :param test_case: brief description of tests, e.g. 'swig dir'
#     :param binding: the binding type, e.g. 'swig'
#     :param prefix: used to match library files, e.g. 'combine' matches
#               libcombine-*.*
#     """
#     gv.reset()
#     xml_filename = functions.set_up_test(name, class_name, test_case)
#     test_utils.generate_binding(xml_filename, binding)
#     if binding == 'swig':
#         assert 0 == test_utils.compare_binding_headers('ListWrapper', binding, "")
#         assert 0 == test_utils.compare_binding_headers('OStream', binding, "")
#         assert 0 == test_utils.compare_binding_impl('OStream', binding, "")
#         assert 0 == test_utils.compare_binding_interface('std_set', binding, "")
#         assert 0 == test_utils.compare_binding_headers('lib{0}'.format(prefix),
#                                                        binding, "")
#         assert 0 == test_utils.compare_binding_interface('lib{0}'.format(prefix),
#                                                          binding, "")
#         assert 0 == test_utils.compare_binding_interface('ASTNodes', binding, "")
#     elif binding == 'csharp':
#         assert 0 == test_utils.compare_binding_impl('local', binding, "")
#         assert 0 == test_utils.compare_binding_interface('local', binding, "")
#         assert 0 == test_utils.compare_binding_interface('lib{0}'.format(prefix),
#                                                          binding, "")
#         assert 0 == test_utils.compare_binding_file('CMakeLists.txt', binding, "")
#         assert 0 == test_utils.compare_binding_file('compile-native-files.cmake',
#                                                     binding, "")
#         assert 0 == test_utils.compare_binding_file('AssemblyInfo.cs.in',
#                                                     binding, "")
#
#
@pytest.mark.parametrize('name, class_name', [
# #    ('test_sedml', 'libsedml'),
#     ('combine-archive', 'libcombine'),
     ('testsbxml', 'libTSB')
])
def test_cmake(name, class_name):
    """
    Based on old test_cmake() function in run_other_library_tests.py
    Generate and compare CMake files.

    TODO the following need more details:

    :param name: name of test, e.g. 'test_sedml' or 'combine-archive'.
    :param class_name:   e.g. 'libsedml' or 'libcombine'
    """
    gv.reset()
    xml_filename = functions.set_up_test(name, class_name, "cmake")
    test_utils.generate_cmake(xml_filename, "cmake")
    assert 0 == test_utils.compare_cmake_file('')
    assert 0 == test_utils.compare_cmake_file('src')
    assert 0 == test_utils.compare_cmake_file('src/bindings')
    assert 0 == test_utils.compare_cmake_file('src/{0}'.format(gv.language))


@pytest.mark.parametrize('name, class_name, test_case', [
    ('testsbxml', 'libTSB', 'global files'),
])
def test_global(name, class_name, test_case):
    """
    Based on old test_utils.test_global() function.
    Generate and compare 'global' files, e.g. VERSION.txt, README.md.

    :param name: test file stub, e.g. 'test_sedml' for test_sedml.xml
    :param class_name: test class e.g. 'libsedml'
    :param test_case: brief description of test, e.g. 'global files'
    """
    xml_filename = functions.set_up_test(name, class_name, test_case)
    test_utils.generate_global(xml_filename)
    assert 0 == test_utils.compare_code_txt('VERSION')
    assert 0 == test_utils.compare_code_txt('README', '.md')


# @pytest.mark.parametrize('name, class_name, test_case', [
#     ('test_sedml', 'sedmlfwd', 'forward declarations'),
# ])
# def test_forward(name, class_name, test_case):
#     """
#     Based on old run_forward() function.
#     Run 'forward declaration' tests.
#
#     :param name: stub of XML filename, e.g. 'test_sedml'
#                  for file test_sedml.xml.
#     :param class_name: test class, e.g. 'sedmlfwd'
#     :param test_case: brief test description, e.g. 'forward declarations'
#     """
#     gv.reset()
#     xml_filename = functions.set_up_test(name, class_name, test_case)
#     test_utils.generate_forward(xml_filename)
#     assert 0 == test_utils.compare_code_headers(class_name)
