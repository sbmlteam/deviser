# Trying out pytest with Deviser cpp tests
# Matthew S. Gillman, UCL, 17th February 2021
import os
import sys
import pytest

from ... import deviser
from ...tests import test_functions
from ...tests.test_cpp_code import run_cpp_tests as rct  # For now.
from ...util import global_variables as gv



def test_something():
    assert (1 == 1)

@pytest.mark.parametrize("name, num, class_name, list_of, test_case", [
    ('copy', 0, 'Def', '', 'class with XMLNode'),

    # A test with garbage input like this will still succeed with things
    # as they currently are:
    # ('copy', 0, 'Defggggggggg', '', 'class with XMLNode'),
])
def test_cpp(name, num, class_name, list_of, test_case):
    this_dir = os.path.dirname(os.path.abspath(__file__))
    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')

    assert rct.run_test(name, num, class_name, test_case, list_of) == 0