# Trying out pytest with Deviser generator tests
# Matthew Gillman, UCL, 16th December 2020
import os
import shutil

import pytest

from ...pytest_files import functions
from ...util import global_variables as gv
from deviser.__main__ import run_generation

global output_test_dir

def setup():
    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))
    os.chdir(this_dir)
    os.chdir('..')
    upper_dr = os.getcwd()
    test_dir = os.path.join(upper_dr, 'testingout')
    if not os.path.isdir(test_dir):
        os.mkdir(test_dir)
    global output_test_dir
    output_test_dir = test_dir
    os.chdir(this_dir)


def teardown():
    # delete temp dir
    this_dir = os.path.dirname(os.path.abspath(__file__))
    temp_dir = os.path.join(this_dir, 'temp')
    if os.path.isdir(temp_dir):
        shutil.rmtree(temp_dir)
    os.chdir(this_dir)
    os.chdir('..')
    if os.path.isdir('testingout'):
        shutil.rmtree('testingout')
    os.chdir(this_dir)


@pytest.mark.parametrize("name, flag, outdir, expected_return", [
    ('non-existent', '-g', 'None', 'failed to read file'),
    ('test_child', '-g', 'None', 'success'),
    ('test_child', 'missing', 'None',  'incorrect number function arguments'),
    ('test_child', 'added', 'None', 'incorrect number function arguments'),
    ('test_child', 'wrong', 'None', 'invalid function arguments'),
    ('test_child', '-g', 'outdir', 'invalid function arguments'),
    ('test_child', '-g',  'global', 'success'),
    # ('test_child', '-l', 'None', 'success'),  # Apparently problematic before?
    ('invalid', '-g', 'None', 'parsing error'),
    ('invalid', '-l', 'None', 'parsing error'),
    ('unknown_type', '-g', 'None',  'unknown type used'),
    ('unknown_error', '-g', 'None',  'missing required information'),
    ('bad_lo_element', '-g', 'None',  'unknown type used'),
    ('bad_concretes', '-g', 'None',  'missing required information'),
])
def test_deviser(name, flag, outdir, expected_return):
    """
    General function for running command-line Deviser tests.

    :param name: general name of test
    :param flag: a command-line flag
    :param outdir: optional output dir
    :param expected_return: what we expect the test to return.
    :return: 0 on success, 1 on failure
    """
    this_dir = os.path.dirname(os.path.abspath(__file__))
    (path_to_tests, _) = os.path.split(this_dir)
    functions.set_path_to_tests(path_to_tests)

    expected_return_number = gv.return_codes[expected_return]
    error = gv.get_return_code(expected_return_number)
    filename = functions.set_up_test(name, flag, error)
    args = []
    if flag in ['-g', '-l', 'wrong']:
        args.append('deviser')
        args.append(flag)
        args.append(filename)
        if outdir != 'None':
            if outdir == 'global':
                args.append(output_test_dir)
            else:
                args.append(outdir)
    elif flag == 'missing':
        args.append('deviser')
        args.append(filename)
    elif flag == 'added':
        args.append('deviser')
        args.append('-g')
        args.append(filename)
        args.append('outdir')
        args.append('extra')
    else:
        raise Exception
    run_generation(args)
    assert gv.code_returned == expected_return_number
