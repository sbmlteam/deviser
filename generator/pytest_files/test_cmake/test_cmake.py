import os
import pytest

from ...tests import test_functions
from ...tests.test_cmake_code import run_cmake_tests as rct


def setup():

    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, _) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')


@pytest.mark.parametrize("name, funcname", [
    ('spatial', 'run_cmake_test'),
    ('spatial', 'run_register_test'),
    ('spatial', 'run_example_test'),
    ('groups', 'run_example_test'),
])
def test_all(name, funcname):
    """
    Get the appropriate function, then execute it with 'name' argument.
    """
    # assert rct.func(name) == 0
    # funcstr = f"rct.{func}({name})"
    # assert rct.run_cmake_test(name) == 0
    # assert exec(funcstr) == 0
    # print(f"function str is: *{funcstr}*")
    mydict = {
              'run_cmake_test': rct.run_cmake_test,
              'run_register_test': rct.run_register_test,
              'run_example_test': rct.run_example_test,
              }
    myfunc = mydict[funcname]
    assert myfunc(name) == 0
