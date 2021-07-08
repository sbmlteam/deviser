import os
import sys
import pytest

from ...pytest_files import test_functions
from . import run_tex_tests as rtt


def setup():
    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, _) = os.path.split(this_dir)
    temp_dir = os.path.join(this_dir, 'temp')
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir(temp_dir):
        os.mkdir(temp_dir)
    os.chdir(this_dir)

# @pytest.mark.skipif(sys.version_info < (3,6),
#                    reason="requires python3.6")
@pytest.mark.parametrize("name, test_type", [
    ('spatial', 'body'),
    ('qual', 'apdx-validation'),
    ('groups', 'macros'),
    ('groups', 'apdx-validation'),
    ('groups', 'body'),
    ('unknown_type', 'apdx-validation'),
    ('test_sidrefs', 'apdx-validation'),
    ('test_sidrefs', 'body'),
    ('test_lists', 'apdx-validation'),
    ('test_lists', 'body'),
    ('test_att', 'apdx-validation'),
])
def test_tex(name, test_type):
    assert rtt.run_test(name, test_type) == 0
