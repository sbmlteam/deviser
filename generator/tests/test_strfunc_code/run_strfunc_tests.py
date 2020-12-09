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


def swap_dictionary(old_dict):
    """
    Use the values of the old dictionary as keys for the new one,
    and the keys of the old dictionary as the values of the new one.

    :param old_dict: the old (i.e. input) dictionary
    :return: the newly-created dictionary
    """
    new_dict = {}
    for (key, value) in old_dict.items():
        new_dict[value] = key
    return new_dict


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
    data2 = swap_dictionary(data)
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
    fail += execute_tests(sf.cap_list_of_name_no_prefix, data, fails)

    # plural_no_prefix() tests
    # TODO this one and remove_prefix() are a bit tricky (broken?)
    gv.reset()
    data = {"fox": "foxes", "child": "children", "SBMLchild": "SBMLchildren"}
    fail += execute_tests(sf.plural_no_prefix, data, fails)
    gv.is_package = False
    gv.prefix = "Rosie"
    data = {"Rosiefox": "foxes", "Rosiechild": "children", "RosieCat": "Cats"}
    fail += execute_tests(sf.plural_no_prefix, data, fails)
    gv.is_package = True
    data = {"Rosiefox": "Rosiefoxes", "Rosiechild": "Rosiechildren", "RosieCat": "RosieCats"}
    fail += execute_tests(sf.plural_no_prefix, data, fails)

    # plural() tests
    data = {"cat": "cats", "dogs": "dogs", "child": "children",
            "disinformation": "disinformation", "fox": "foxes",
            "party": "parties", "cloud": "clouds", "something": "somethings"}
    fail += execute_tests(sf.plural, data, fails)

    # singular() tests
    data2 = swap_dictionary(data)
    data2['dogs'] = 'dog'  # Just need to tweak this one entry. Otherwise OK.
    fail += execute_tests(sf.singular, data2, fails)

    # remove_prefix() tests - this is a complicated function to test!



    # get_indefinite() tests
    data = {"apple": "an", "biscuit": "a", "elephant": "an", "image": "an",
            "polar bear": "a", "orangutan": "an", "under secretary": "an",
            "zither": "a"}
    fail += execute_tests(sf.get_indefinite, data, fails)

    # standard_element_name() tests - another tricky one!

    # get_library_suffix() tests
    data = {"library": "Rary", "libSBML": "Sbml", "cat": "Cat", "lib": ""}
    fail += execute_tests(sf.get_library_suffix, data, fails)

    # A varargs example - wrap_token
    fail += run_strfunc_test(sf.wrap_token, 'fred',
                             '\\token{cat:\\-fred}', fails, pkg='cat')
    # need more tests for this func!

    # wrap_type() tests - I don't really understand this one!

    # wrap_section() tests - or this one!

    # make_class() tests
    fail += run_strfunc_test(sf.make_class, 'Irenaeus', 'irenaeus-class', fails)
    fail += run_strfunc_test(sf.make_class, 'Irenaeus', 'extended-irenaeus-class',
                             fails, add_extended=True)

    # wrap_enum() tests
    fail += run_strfunc_test(sf.wrap_enum, 'cat', '\\primtype{cat}', fails)

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

