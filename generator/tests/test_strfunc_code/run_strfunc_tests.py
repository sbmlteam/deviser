#!/usr/bin/env python
import os

import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')

from util import strFunctions as sf

import test_functions

##############################################################################
# Set up variables
fails = []
not_tested = []

#def compare_strings(expected, actual):
#    return expected == actual

def run_strfunc_test(func, input, expected_output, **kwargs):
    actual_output = func(input, **kwargs)
    if actual_output == expected_output:
        return 0
    else:
        errormsg = "*** Error in strfunc test!"
        errormsg += "function:{0}, actual output:{1}, but expected:{2}".format(func, actual_output, expected_output)
        print(errormsg)
        return 1


def main():

    # run the individual tests
    name = 'initial'
    fail = 0  # run_matlab_test(name)

    fail += run_strfunc_test(sf.upper_first, 'cat', 'Cat')
    # fail += run_strfunc_test(sf.upper_first, 'cat', 'CAT')  # Deliberate failure example

    fail += run_strfunc_test(sf.wrap_token, 'fred', '\\token{cat:\\-fred}', pkg='cat')

    test_functions.report('strfunc', fail, fails, not_tested)
    return fail

if __name__ == '__main__':
    main()