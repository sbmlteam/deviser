import os
import pytest

from ...tests import test_functions
from ...tests.test_tex_files import run_tex_tests as rtt


def setup():
    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, _) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')


def test_something():
    assert (1 == 1)


@pytest.mark.parametrize("name, test_type", [
    ('spatial', 'body'),
])
def test_tex(name, test_type):
    assert rtt.run_test(name, test_type) == 0