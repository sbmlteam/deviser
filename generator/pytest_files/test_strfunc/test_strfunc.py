import os
import pytest

from ...tests import test_functions
from ...tests.test_strfunc_code import run_strfunc_tests as rst
from ...util import strFunctions as sf, global_variables as gv

def test_something():
    assert (1 == 1)


@pytest.mark.parametrize('func, input, expected_output, kwargs', [
    (sf.upper_first, 'cat', 'Cat', {}),
])
def test_one_thing(func, input, expected_output, kwargs):
    """
    Run a single test case on a strFunc function, and check that
    the actual output returned is the same as that expected.

    :param func: the strFunc function under test
    :param input: input to function
    :param expected_output: what we expect the function to return. Can be None.
    :param kwargs: dictionary of keyword arguments, if any, for the function
               under test.
    """
    #if kwargs:
    #    actual_output = func(input, **kwargs)
    #else:
    #    actual_output = func(input)
    actual_output = func(input, **kwargs)
    assert actual_output == expected_output