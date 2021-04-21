# Matthew S. Gillman, UCL, 19th April 2021.
import os, pytest

from ...tests import test_functions
from ...tests.test_other_library import run_other_library_tests as rolt
from ...util import strFunctions as sf, global_variables as gv


def setup():
    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))
    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')


@pytest.mark.parametrize('name, num, class_name, test_case, list_of', [
    ('test_sedml', 1, 'SedModel', 'model', 'SedListOfModels')
])
def test_cpp(name, num, class_name, test_case, list_of):
    """
    Run the C++ file tests.

    :param name: name of test group e.g. 'test_sedml', 'combine-archive'.
    :param num: list index, so we only generate a particular class not all of them
    :param class_name: name of C++ class (and thus .cpp/.h filenames), e.g. 'CaContent'
    :param test_case: brief test description
    :param list_of: class name (and thus filenames) of any corresponding "list of" class, e.g. 'CaListOfContents'
    """
    gv.reset()  # NB do we need to do this for every test? Will it break anything?
    filename = test_functions.set_up_test(name, class_name, test_case)
    rolt.generate_new_cpp_header(filename, num)
    assert 0 == rolt.compare_code_headers(class_name)
    assert 0 == rolt.compare_code_impl(class_name)
    if len(list_of) > 0:
        class_name = list_of
        assert 0 == rolt.compare_code_headers(class_name)
        assert 0 == rolt.compare_code_impl(class_name)