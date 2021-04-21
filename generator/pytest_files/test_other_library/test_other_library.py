# Matthew S. Gillman, UCL, 19th April 2021.
import os, pytest

from ...tests import test_functions
from ...tests.test_other_library import run_other_library_tests as rolt
from ...util import global_variables as gv


def setup():
    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))
    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')


@pytest.mark.parametrize('name, num, class_name, test_case, list_of', [
    # Tests from old rolt.testSedML()
    ('test_sedml', 1, 'SedModel', 'model', 'SedListOfModels'),
    ('test_sedml', 0, 'SedDocument', 'document', ''),
    ('test_sedml', 3, 'SedAddXML', 'xmlnode used', ''),
    ('test_sedml', 26, 'SedSetValue', 'astnode used', ''),
    ('test_sedml', 12, 'SedDataGenerator', 'astnode in getElementBySId bug', ''),
    ('test_sedml', 33, 'SedRepeatedTask', 'attribute with different xml name', ''),
    ('test_sedml', 7, 'SedSimulation', 'child element', ''),
    ('test_sedml', 28, 'SedVectorRange', 'deal with vectors', ''),
    ('test_sedml', 10, 'SedAbstractTask', 'catch different abstract types', 'SedListOfTasks'),
    # TODO: shouldn't next one's description be about different output types??
    ('test_sedml', 13, 'SedOutput', 'catch different abstract types', 'SedListOfOutputs'),

    # Tests from old rolt.testCombine()
    ('combine-archive', 0, 'CaContent', 'check includes', 'CaListOfContents'),
    ('combine-archive', 1, 'CaOmexManifest', 'document', ''),

])
def test_cpp(name, num, class_name, test_case, list_of):
    """
    Based on rolt.run_test(). Run the C++ file tests.

    :param name: name of test group e.g. 'test_sedml', 'combine-archive'.
    :param num: list index, so we only generate a particular class not all of them
    :param class_name: name of C++ class (and thus .cpp/.h filenames), e.g. 'CaContent'
    :param test_case: brief test description
    :param list_of: class name (and thus filenames) of any corresponding "list of" class, e.g. 'CaListOfContents'
    """
    gv.reset()  # NB do we need to do this for every test? Will it break anything?
    #import pdb; pdb.set_trace()
    filename = test_functions.set_up_test(name, class_name, test_case)  # XML library file.
    assert filename is not None and filename != ""
    rolt.generate_new_cpp_header(filename, num)
    assert 0 == rolt.compare_code_headers(class_name)
    assert 0 == rolt.compare_code_impl(class_name)
    if len(list_of) > 0:
        class_name = list_of
        assert 0 == rolt.compare_code_headers(class_name)
        assert 0 == rolt.compare_code_impl(class_name)


@pytest.mark.parametrize('name, class_name, test_case, list_of', [
    # Tests from old rolt.testCombine()
    ('test_sedml', 'SedBase', 'templates', 'SedListOf'),
    ('combine-archive', 'CaBase', 'templates', 'CaListOf'),
])
def test_templates(name, class_name, test_case, list_of):
    """
    Based on old rolt.run_templates() function. Run the 'template' file tests.

    :param name: name of test group e.g. 'test_sedml', 'combine-archive'.
    :param class_name: name of C++ class (and thus .cpp/.h filenames), e.g. 'SedBase'
    :param test_case: brief test description, e.g. 'templates'.
    :param list_of: class name (and thus filenames) of any corresponding "list of" class, e.g. 'SedListOf'
    """
    gv.reset()
    filename = test_functions.set_up_test(name, class_name, test_case)
    assert filename is not None and filename != ""
    rolt.generate_templates(filename)
    assert 0 == rolt.compare_code_headers(class_name)
    assert 0 == rolt.compare_code_impl(class_name)
    assert 0 == rolt.compare_code_headers(list_of)
    assert 0 == rolt.compare_code_impl(list_of)


@pytest.mark.parametrize('name, class_name, test_case, prefix, lib', [
    ('test_sedml', 'SedBase', 'common', 'Sed', 'sedml'),
    ('combine-archive', 'CaBase', 'common', 'Ca', 'combine'),

])
def test_common_templates(name, class_name, test_case, prefix, lib):
    """
    Based on rolt.test_common_templates() function.
    Compare 'common' template files.

    :param name: e.g. 'test_sedml'
    :param class_name: C++ class/filenames, e.g. 'SedBase'
    :param test_case: e.g. 'common'
    :param prefix: e.g. 'Sed'
    :param lib: used for comparing lib files, e.g. 'sedml' for 'libsedml-*'.
    :return: number of failed tests.
    """
    filename = test_functions.set_up_test(name, class_name, test_case)
    rolt.generate_common_templates(filename)
    assert 0 == rolt.compare_code_headers('common')
    assert 0 == rolt.compare_code_headers('extern')
    assert 0 == rolt.compare_code_headers('lib{0}-config'.format(lib))
    assert 0 == rolt.compare_code_impl('lib{0}-version'.format(lib))
    assert 0 == rolt.compare_code_headers('{0}OperationReturnValues'.format(prefix))
    assert 0 == rolt.compare_code_impl('{0}OperationReturnValues'.format(prefix))
    assert 0 == rolt.compare_code_cmake('lib{0}-version.h'.format(lib))
    assert 0 == rolt.compare_code_cmake('lib{0}-config-common.h'.format(lib))
    assert 0 == rolt.compare_code_cmake('lib{0}-namespace.h'.format(lib))


@pytest.mark.parametrize('name, class_name, test_case', [
    ('test_sedml', 'SedmlEnumerations', 'enumerations'),
])
def test_enum(name, class_name, test_case):
    """
    Based on old run_enum() function.
    Run extension types file tests.

    :param name: stub of XML file name, e.g. 'test_sedml' for file test_sedml.xml.
    :param class_name: test class, e.g. 'SedmlEnumerations'
    :param test_case: brief description of tests, e.g. 'enumerations'.
    """
    filename = test_functions.set_up_test(name, class_name, test_case)
    rolt.generate_enum(filename)
    assert 0 == rolt.compare_code_headers(class_name)
    assert 0 == rolt.compare_code_impl(class_name)


@pytest.mark.parametrize('name, class_name, test_case, binding, prefix', [
    ('test_sedml', 'libsedml', 'swig dir', 'swig', 'sedml'),
    ('test_sedml', 'libsedml', 'csharp dir', 'csharp', 'sedml'),
    ('combine-archive', 'libcombine', 'csharp dir', 'csharp', 'combine'),
    ('combine-archive', 'libcombine', 'swig dir', 'swig', 'combine'),
])
def test_bindings(name, class_name, test_case, binding, prefix):
    """
    Based on old test_bindings() function.
    Compare the 'bindings' files.

    :param name: stub of XML filename, e.g. 'test_sedml' for file test_sedml.xml.
    :param class_name: the test class, e.g. 'libsedml'
    :param test_case: brief description of tests, e.g. 'swig dir'
    :param binding: the binding type, e.g. 'swig'
    :param prefix: used to match library files, e.g. 'combine' matches libcombine-*.*
    """
    filename = test_functions.set_up_test(name, class_name, test_case)
    rolt.generate_binding(filename, binding)
    if binding == 'swig':
        assert 0 == rolt.compare_binding_headers('ListWrapper', binding, "")
        assert 0 == rolt.compare_binding_headers('OStream', binding, "")
        assert 0 == rolt.compare_binding_impl('OStream', binding, "")
        assert 0 == rolt.compare_binding_interface('std_set', binding, "")
        assert 0 == rolt.compare_binding_headers('lib{0}'.format(prefix), binding, "")
        assert 0 == rolt.compare_binding_interface('lib{0}'.format(prefix), binding, "")
        assert 0 == rolt.compare_binding_interface('ASTNodes', binding, "")
    elif binding == 'csharp':
        assert 0 == rolt.compare_binding_impl('local', binding, "")
        assert 0 == rolt.compare_binding_interface('local', binding, "")
        assert 0 == rolt.compare_binding_interface('lib{0}'.format(prefix), binding, "")
        assert 0 == rolt.compare_binding_file('CMakeLists.txt', binding, "")
        assert 0 == rolt.compare_binding_file('compile-native-files.cmake', binding, "")
        assert 0 == rolt.compare_binding_file('AssemblyInfo.cs.in', binding, "")

# tests waiting to be done
"""
    name = 'test_sedml'
    class_name = 'sedmlfwd'
    test_case = 'forward declarations'
    fail += run_forward(name, class_name, test_case)

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
    """

# tests from old testCombine() function
"""
gv.reset()

name = 'combine-archive'
class_name = 'libcombine'
# test_case = 'cmake'
# binding = 'cmake'
fail += test_cmake(name, class_name)  # , test_case, binding)  # , 'combine')

return fail
"""