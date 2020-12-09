#!/usr/bin/env python
import os
import sys


import test_functions

from util import strFunctions as sf, global_variables as gv

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')


##############################################################################


def run_strfunc_test(func, input, expected_output, fails, **kwargs):
    """
    Run a single test case on a strFunc function, and check that
    the actual output returned is the same as that expected.

    :param func: the strFunc function under test
    :param input: input to function
    :param expected_output: what we expect the function to return
    :param fails: the list of failure information strings.
    :param **kwargs: any additional named arguments for the function
    :return: 0 on success, 1 on failure
    """
    actual_output = func(input, **kwargs)
    # We should maybe use test_functions.compare_return_codes() here,
    # although none of the other test files seem to use it!
    if actual_output == expected_output:
        return 0
    else:
        errormsg = "*** Error in strfunc test! "
        errormsg += "function:{0}, input:{1}, actual output:{2}, but expected:{3}."\
            .format(func, input, actual_output, expected_output)
        fails.append(errormsg)
        return 1


def execute_tests(func, test_data, fails, **kwargs):
    """
    Execute a set of individual tests on a strFunc function.

    :param func: the function under test
    :param test_data: dictionary of test data
                      (keys=inputs, values=expected outputs)
    :param fails: the list of failure information strings.
    :param **kwargs: any named arguments for the function
    :return: number of failed tests for this set.
    """
    counter = 0
    for (input, expected) in test_data.items():
        counter += run_strfunc_test(func, input, expected, fails, **kwargs)
    return counter


def main():

    # NOTE: the test sets below are in the same order as the functions
    # appear in strFunctions.py. Please maintain that. Thanks.

    # Set up variables
    fails = []
    not_tested = []
    fail = 0

    # upper_first() tests
    fail += run_strfunc_test(sf.upper_first, 'cat', 'Cat', fails)
    # fail += run_strfunc_test(sf.upper_first, 'cat', 'CAT')  # Failure test
    data = {'cat': 'Cat', 'csgsomething': 'CSGsomething', 'csgcat': 'CSGcat',
            'cscat': 'Cscat', 'csgeometry': 'CSGeometry',
            'csGeometry': 'CSGeometry', 'a': 'A'}
    fail += execute_tests(sf.upper_first, data, fails)

    # lower_first() tests - it's virtually the exact opposite of upper_first()
    data2 = {}  # Exact opposite of dictionary used in upper_first() tests.
    for (input, expected) in data.items():
        data2[expected] = input
    fail += execute_tests(sf.lower_first, data2, fails)

    # get_indent() tests
    data = {'': 1, 'elephant': 9}
    fail += execute_tests(sf.get_indent, data, fails)

    # abbrev_name() tests
    data = {"thisIsATest": "iat", "CAT": "cat", "cat": "c", "c": "c", "C": "c"}
    fail += execute_tests(sf.abbrev_name, data, fails)

    # abbrev_lo_name() tests
    data = {"spaghetti": "LOtti", "SPAGHETTI": "LOTTI", "": "LO"}
    fail += execute_tests(sf.abbrev_lo_name, data, fails)

    # list_of_name() tests
    gv.reset()
    data = {"FooParameter": "ListOfFooParameters"}
    fail += execute_tests(sf.list_of_name, data, fails, addPrefix=True)
    fail += execute_tests(sf.list_of_name, data, fails, addPrefix=False)
    # print(f"gv is package: {gv.is_package}, gv prefix: {gv.prefix}")
    gv.is_package = False
    data = {"FooParameter": "SBMLListOfFooParameters"}
    fail += execute_tests(sf.list_of_name, data, fails, addPrefix=True)

    # lower_list_of_name_no_prefix() tests
    data = {"fox": "listOfFoxes", "cat": "listOfCats", "child": "listOfChildren"}
    fail += execute_tests(sf.lower_list_of_name_no_prefix, data, fails)

    # cap_list_of_name() tests
    gv.reset()
    data = {"FooParameter": "ListOfFooParameters", "cat": "ListOfCats"}
    fail += execute_tests(sf.cap_list_of_name, data, fails, addPrefix=False)
    gv.is_package = False
    data = {"FooParameter": "SBMLListOfFooParameters", "cat": "SBMLListOfCats"}
    fail += execute_tests(sf.cap_list_of_name, data, fails, addPrefix=True)

    # cap_list_of_name_no_prefix() tests
    gv.reset()
    data = {"FooParameter": "ListOfFooParameters", "cat": "ListOfCats"}
    #fail += execute_tests(sf.cap_list_of_name_no_prefix, data, fails)
    # plural_no_prefix() tests

    # plural() tests

    # singular() tests

    # remove_prefix() tests

    # get_indefinite() tests

    # standard_element_name() tests

    # get_library_suffix() tests

    # A varargs example - wrap_token
    fail += run_strfunc_test(sf.wrap_token, 'fred',
                             '\\token{cat:\\-fred}', fails, pkg='cat')
    # need more tests for this func

    # wrap_type() tests

    # wrap_section() tests

    # make_class() tests

    # wrap_enum() tests

    # get_sid_refs() tests

    # get_element_name() tests

    # get_element_name_no_prefix() tests

    # replace_digits() tests

    # replace_underscore() tests

    # remove_spaces() tests

    # remove_hyphens() tests

    # texify() tests

    # compare_no_case() tests

    # get_class_from_plugin() tests

    # prefix_name() tests

    # prefix_classes() tests

    # is_camel_case() tests


    test_functions.report('strfunc', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()

