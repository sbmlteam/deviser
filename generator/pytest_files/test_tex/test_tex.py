import os
import sys
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

@pytest.mark.skipif(sys.version_info < (3,6),
                    reason="requires python3.6")
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
