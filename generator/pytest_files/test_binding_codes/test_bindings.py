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
    ('test_vers', 'java', 'i'),
])
def test_basic(name, binding, ext):
    assert rbt.run_test(name, binding, ext) == 0


@pytest.mark.parametrize("name, binding, ext", [
    ('spatial', 'csharp', 'i'),
    ('spatial', 'java', 'i'),
    ('spatial', 'javascript', 'cpp'),
    ('spatial', 'perl', 'cpp'),
    ('spatial', 'php', 'cpp'),
    ('spatial', 'python', 'cpp'),
    ('spatial', 'r', 'cpp'),
    ('spatial', 'ruby', 'cpp'),
    ('test_vers', 'java', 'i'),
])
def test_ns(name, binding, ext):
    assert rbt.run_ns_test(name, binding, ext) == 0


@pytest.mark.parametrize("name, binding, ext", [
    ('spatial', 'javascript', 'cpp'),
    ('spatial', 'java', 'i'),
    ('test_vers', 'java', 'i'),
])
def test_pkgs(name, binding, ext):
    assert rbt.run_pkgs_test(name, binding, ext) == 0


@pytest.mark.parametrize("name, binding, ext, local", [
    ('spatial', 'csharp', 'i', 'False'),
    ('spatial', 'php', 'i', 'True'),
])
def test_local(name, binding, ext, local):
    assert rbt.run_local_test(name, binding, ext, local) == 0


@pytest.mark.parametrize("name, binding, ext", [
    ('spatial', 'ruby', 'cpp'),
    ('qual', 'javascript', 'cpp'),
])
def test_plugin(name, binding, ext):
    assert rbt.run_plugin_test(name, binding, ext) == 0


@pytest.mark.parametrize("name, binding, ext", [
    ('spatial', 'swig', 'i'),
    ('spatial', 'swig', 'h'),
])
def test_swig(name, binding, ext):
    assert rbt.run_swig_test(name, binding, ext) == 0