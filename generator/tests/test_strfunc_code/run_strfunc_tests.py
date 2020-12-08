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
    else:
        errormsg = "*** Error in strfunc test!"
        errormsg += "function:{0}, actual output:{1}, but expected:{2}"\
            .format(func, actual_output, expected_output)
        print(errormsg)
        return 1


def main():

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



    # A varargs example
    fail += run_strfunc_test(sf.wrap_token, 'fred',
                             '\\token{cat:\\-fred}', pkg='cat')

    test_functions.report('strfunc', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()

    """
    remaining functions to test:
    
lower_first
get_indent
abbrev_name
abbrev_lo_name
list_of_name
lower_list_of_name_no_prefix
cap_list_of_name
cap_list_of_name_no_prefix
plural_no_prefix
plural
singular
remove_prefix
get_indefinite
standard_element_name
get_library_suffix
wrap_token
wrap_type
wrap_section
make_class
wrap_enum
get_sid_refs
get_element_name
get_element_name_no_prefix
replace_digits
replace_underscore
remove_spaces
remove_hyphens
texify
compare_no_case
get_class_from_plugin
prefix_name
prefix_classes
is_camel_case
"""