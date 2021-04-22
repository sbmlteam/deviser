# Matthew S. Gillman, UCL, 22nd April 2021.
import os
import pytest

from ...tests import test_functions
from ...tests.test_examples import run_examples_tests as ret
from ...util import global_variables as gv


def setup():
    """
    NB Not to be confused with set_up() in run_examples_tests.py!
    """
    # Set up the environment
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')


@pytest.mark.parametrize('name', [
    ('lo_children'),
    ('base_class'),
    ('qual'),
    ('spatial'),
    ('groups'),  # This one was commented-out in run_examples_tests.py
])
def test_xml(name):
    assert 0 == ret.run_xml_test(name)


@pytest.mark.parametrize('name, start, stop', [
    ("spatial", 8, 13),
    ("spatial", 15, 19),
    ("spatial", 22, 26),
    ("spatial", 32, 36),
    ("spatial", 41, 45),
    ("spatial", 53, 54),
    ("spatial", 60, 61),
    ("spatial", 65, 66),
])
def test_specific_xml_fail(name, start, stop):
    """
    TODO: explanation needed.

    :param name: XML file to parse
    :param start:
    :param stop:
    """
    assert 0 == ret.run_specific_xml_fail_tests(name, start, stop)


@pytest.mark.parametrize('name', [
    ('base_class'),
    ('groups'),  # This one was commented-out in run_examples_tests.py
])
def test_xml_fail(name):
    assert 0 == ret.run_xml_fail_tests(name)


    # run the individual tests
    # name = 'qual'
    # fail += run_test(name)
    #
    # name = 'lo_children'
    # fail += run_test(name)
    #


