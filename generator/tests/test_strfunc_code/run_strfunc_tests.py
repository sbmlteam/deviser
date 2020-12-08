#!/usr/bin/env python
import os
import sys

import test_functions

from util import strFunctions as sf

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')


##############################################################################
# Set up variables
fails = []
not_tested = []


def run_strfunc_test(func, input, expected_output, **kwargs):
    actual_output = func(input, **kwargs)
    if actual_output == expected_output:
        return 0
    else:  # NB is the msg below meant to go in fails?
        errormsg = "*** Error in strfunc test!"
        errormsg += "function:{0}, actual output:{1}, but expected:{2}"\
            .format(func, actual_output, expected_output)
        print(errormsg)
        return 1


def main():

    # NOTE: the test sets below are in the same order as the functions
    # appear in strFunctions.py. Please maintain that. Thanks.

    # run the individual tests
    fail = 0

    # upper_first() tests
    fail += run_strfunc_test(sf.upper_first, 'cat', 'Cat')
    # fail += run_strfunc_test(sf.upper_first, 'cat', 'CAT')  # Failure test
    data = {'cat': 'Cat', 'csgsomething': 'CSGsomething', 'csgcat': 'CSGcat',
            'cscat': 'Cscat', 'csgeometry': 'CSGeometry',
            'csGeometry': 'CSGeometry', 'a': 'A'}
    data2 = {}  # Exact opposite of the data dictionary. Used in next test!
    for (input, expected) in data.items():
        fail += run_strfunc_test(sf.upper_first, input, expected)
        data2[expected] = input

    # lower_first() tests - it's virtually the exact opposite of upper_first()
    for (input, expected) in data2.items():
        fail += run_strfunc_test(sf.lower_first, input, expected)

    # get_indent() tests
    data = {'': 1, 'elephant': 9}
    for (input, expected) in data.items():
        fail += run_strfunc_test(sf.get_indent, input, expected)

    # abbrev_name() tests


    # abbrev_lo_name() tests

    # list_of_name() tests

    # lower_list_of_name_no_prefix() tests

    # cap_list_of_name() tests

    # cap_list_of_name_no_prefix() tests

    # plural_no_prefix() tests

    # plural() tests

    # singular() tests

    # remove_prefix() tests

    # get_indefinite() tests

    # standard_element_name() tests

    # get_library_suffix() tests

    # A varargs example - wrap_token
    fail += run_strfunc_test(sf.wrap_token, 'fred',
                             '\\token{cat:\\-fred}', pkg='cat')
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

