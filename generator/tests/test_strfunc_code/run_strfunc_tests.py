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

    fail += run_strfunc_test(sf.upper_first, 'cat', 'Cat')
    # fail += run_strfunc_test(sf.upper_first, 'cat', 'CAT')  # Failure test
    data = {'cat': 'Cat', 'csgsomething': 'CSGsomething', 'csgcat': 'CSGcat',
            'cscat': 'Cscat', 'csgeometry': 'CSGeometry',
            'csGeometry': 'CSGeometry', 'a': 'A'}
    for (input, expected) in data.items():
        fail += run_strfunc_test(sf.upper_first, input, expected)

    # A varargs example
    fail += run_strfunc_test(sf.wrap_token, 'fred',
                             '\\token{cat:\\-fred}', pkg='cat')

    test_functions.report('strfunc', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
