import os
import pytest

from ...tests import test_functions
from ...tests.test_matlab_code import run_matlab_tests as rmt


def setup():
    # set up the environment
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')


@pytest.mark.parametrize('name, filetype', [
    ('qual', 'sf'),
    ('qual', 'dv'),
    ('qual', 'vt'),
])
def test_matlab(name, filetype):
    filename = test_functions.set_up_test(name, 'MATLAB')
    rmt.generate_matlab_files(filename, name)
    # for filetype in rmt.filetypes:
    assert rmt.compare_matlab(name, filetype) == 0
