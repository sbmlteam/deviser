# Matthew S. Gillman, UCL, 31st March 2021.
import os
import pytest

from ...tests import test_functions
from ...tests.test_strfunc_code import run_strfunc_tests as rst
from ...util import strFunctions as sf, global_variables as gv


# Please try and keep functions in same order as in the strFunctions.py file
# for ease of reference (and to see what is missing).
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
foodat = {"FooParameter": "ListOfFooParameters"}
foxcatchild = {"fox": "listOfFoxes", "cat": "listOfCats",
             "child": "listOfChildren"}
foocat = {"FooParameter": "ListOfFooParameters", "cat": "ListOfCats"}
foosbmlcat = {"FooParameter": "SBMLListOfFooParameters", "cat": "SBMLListOfCats"}

# Please try and keep functions in same order as in the strFunctions.py file
# for ease of reference (and to see what is missing).
@pytest.mark.parametrize('func, test_data, kwargs, do_first', [
    (sf.upper_first, catdat, {}, ''),
    (sf.lower_first, rst.swap_dictionary(catdat), {}, ''),

    (sf.abbrev_name, {"thisIsATest": "iat", "CAT": "cat", "cat": "c", "c": "c", "C": "c"}, {}, ''),
    (sf.abbrev_lo_name, {"spaghetti": "", "ListOfFoo": "LOFoo", "ListOfFOO": "LOFOO"}, {}, ''),

    (sf.list_of_name, foodat, {'add_prefix': True}, 'gv.reset()'),
    (sf.list_of_name, foodat, {'add_prefix': False}, ''),
    (sf.list_of_name, foodat, {'add_prefix': False}, 'gv.is_package = False'),
    (sf.list_of_name, {"FooParameter": "SBMLListOfFooParameters"}, {'add_prefix': True}, ''),

    (sf.lower_list_of_name_no_prefix, foxcatchild, {}, 'gv.reset()'),
    (sf.lower_list_of_name_no_prefix, foxcatchild, {}, 'gv.is_package = False'),

    (sf.cap_list_of_name, foocat, {'add_prefix': False}, 'gv.reset()'),
    (sf.cap_list_of_name, foocat, {'add_prefix': True}, ''),
    (sf.cap_list_of_name, foocat, {'add_prefix': False}, 'gv.is_package = False'),
    (sf.cap_list_of_name, foosbmlcat, {'add_prefix': True}, ''),



])
def test_many_things(func, test_data, kwargs, do_first):
    """
    Execute a set of individual tests on a strFunc function.

    :param func: the function under test
    :param test_data: dictionary of test data
                      (keys=inputs, values=expected outputs)
    :param kwargs: dictionary of any named arguments for the function
    :param do_first: string of command(s) (separated by semi-colons)
           to be executed before running the test.
           Example: do_first = 'ans = 2 + 2; print(ans)'
    """
    if do_first:
        exec(do_first)
    for (input, expected) in test_data.items():
        actual_output = func(input, **kwargs)
        assert actual_output == expected

