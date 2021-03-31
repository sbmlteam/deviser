import os
import pytest

from ...tests import test_functions
from ...tests.test_strfunc_code import run_strfunc_tests as rst
from ...util import strFunctions as sf, global_variables as gv


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


catdat = {'cat': 'Cat', 'csgsomething': 'CSGsomething', 'csgcat': 'CSGcat',
            'cscat': 'Cscat', 'csgeometry': 'CSGeometry',
            'csGeometry': 'CSGeometry', 'a': 'A'}

@pytest.mark.parametrize('func, test_data, kwargs', [
    (sf.upper_first, catdat, {}),
    (sf.lower_first, rst.swap_dictionary(catdat), {}),
])
def test_many_things(func, test_data, kwargs):
    """
    Execute a set of individual tests on a strFunc function.

    :param func: the function under test
    :param test_data: dictionary of test data
                      (keys=inputs, values=expected outputs)
    :param kwargs: dictionary of any named arguments for the function
    """
    for (input, expected) in test_data.items():
        actual_output = func(input, **kwargs)
        assert actual_output == expected

