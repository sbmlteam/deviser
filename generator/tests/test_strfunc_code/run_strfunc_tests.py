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


def main():

    # run the individual tests
    name = 'initial'
    fail = 0  # run_matlab_test(name)

    test_functions.report('strfunc', fail, fails, not_tested)
    return fail

if __name__ == '__main__':
    main()