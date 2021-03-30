import os
import pytest

from ...tests import test_functions
from ...tests.test_binding_code import run_bindings_tests as rbt


def setup():

    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, _) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    # print(f"this_dir is {this_dir}")
    # print(f"path_to_tests is {path_to_tests}")


def test_something():
    assert (1 == 1)


@pytest.mark.parametrize("name, binding, ext", [
    ('spatial', 'csharp', 'i'),
    ('spatial', 'java', 'i'),
    ('spatial', 'javascript', 'cpp'),
    ('spatial', 'perl', 'cpp'),
    ('spatial', 'php', 'cpp'),
    ('spatial', 'python', 'cpp'),
    ('spatial', 'r', 'cpp'),
    ('spatial', 'ruby', 'cpp'),
])
def test_basic(name, binding, ext):
    assert rbt.run_test(name, binding, ext) == 0