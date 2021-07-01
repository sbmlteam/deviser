#!/usr/bin/env python
# Tests for deviser/util/strFunctions.py
# Matthew Gillman, UCL, December 2020
# I guess we'll need a copyright statement, etc., here?
import os
import sys


from .. import test_functions

from ...util import strFunctions as sf, global_variables as gv


##############################################################################


def run_strfunc_test(func, input, expected_output, fails, **kwargs):
    """
    Run a single test case on a strFunc function, and check that
    the actual output returned is the same as that expected.

    :param func: the strFunc function under test
    :param input: input to function
    :param expected_output: what we expect the function to return. Can be None.
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
        errormsg += "function:{0}, input:{1}, output:{2}, expected:{3}."\
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

    TODO should we move this to test_functions.py? The test function to run
    one test (here, `run_str_func`) could be a new func2 argument above,
    to make this more generic.
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

    TODO should we move this to test_functions.py?
    """
    new_dict = {}
    for (key, value) in old_dict.items():
        new_dict[value] = key
    return new_dict


def compare_dictionaries(input, expected, fails):
    """
    Are these two dictionaries the same?
    If no, find out at least one place where they are different.

    :param input: the first dictionary
    :param expected: what the first is expected to be
    :param fails: the list of failure cases' strings
    :return 0 on success, 1 on failure.

    TODO should we move this to test_functions.py?
    """
    if input == expected:
        return 0

    # Failure.
    errormsg = "*** Error in strfunc test! "
    fails.append(errormsg)
    check_keys(input, expected, fails)
    check_keys(expected, input, fails)
    return 1


def check_keys(first, second, fails):
    """
    Check two dictionaries. Only expected to be called if they
    are different in some way. Report if at least one key of first dict
    is missing from second. And for keys which are present in both,
    report if there is a difference in the values. Add details to
    fails list.

    NB This won't report more than one failure, e.g.
    if there are two (or more) keys in first missing from second,
    and/or different values in second, this will only report the first
    error it finds.

    :param first: the first dictionary
    :param second: the second dictionary
    :fails: the list of failure cases we are keeping
    :return: nothing

    TODO should we move this to test_functions.py?
    """
    first_keys = list(first.keys())
    for k in first_keys:
        if k not in second:
            msg = "Key {0} is in one dict but not in other".format(k)
            fails.append(msg)
            return
        if first[k] != second[k]:
            msg = "Key {0} has value {1} in one dict but value {2} in other". \
                format(k, first[k], second[k])
            fails.append(msg)
            return


def single_then_plural(name):
    singular = sf.singular(name)
    return sf.plural(singular)


def plural_then_single(name):
    plural = sf.plural(name)
    return sf.singular(plural)


