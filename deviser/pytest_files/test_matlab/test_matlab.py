import os, shutil
import pytest

from ...pytest_files import functions
from . import run_matlab_tests as rmt


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


@pytest.mark.parametrize('name, filetype', [
    ('qual', 'sf'),
    ('qual', 'dv'),
    ('qual', 'vt'),
])
def test_matlab(name, filetype):
    filename = functions.set_up_test(name, 'MATLAB')
    rmt.generate_matlab_files(filename, name)
    # for filetype in rmt.filetypes:
    assert rmt.compare_matlab(name, filetype) == 0
