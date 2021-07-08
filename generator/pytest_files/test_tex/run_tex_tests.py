#!/usr/bin/env python

import os


from .spec_files import TexValidationRulesFile, TexMacrosFile, TexBodySyntaxFile
from .parseXML import ParseXML

from  import test_functions


##############################################################################
# Set up variables
fails = []
not_tested = []


def setup(filename, name):
    """
    Parses XML file and obtains big dictionary structure of information
    about it. Creates directory for test file, if required.

    :param filename: name of the XML file to parse
    :param name: name of the temporary directory
    :returns: the big dictionary structure.
    """
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if not os.path.isdir(name):
        os.mkdir(name)
    os.chdir(name)
    return ob


def generate_files(filename, name, type):
    """
    Generate the file to test.

    :param filename: the name of the file
    :param name: directory in which to create the file
    :type: one of ['apdx-validation', 'macros', 'body']
    :returns: nothing
    """
    assert type in ['apdx-validation', 'macros', 'body']
    ob = setup(filename, name)
    if type == 'apdx-validation':
        all_files = TexValidationRulesFile.TexValidationRulesFile(ob)
    elif type == 'macros':
        all_files = TexMacrosFile.TexMacrosFile(ob)
    else:  # type == 'body':
        all_files = TexBodySyntaxFile.TexBodySyntaxFile(ob)
    all_files.write_file()
    os.chdir('../../.')


def compare_items(name, type):
    """
    Compare two files, reference and temporary versions.

    :param name: name of the directory housing the file.
    :param type: one of ['apdx-validation', 'macros', 'body']
    :return: 0 if success or file missing, 1 on failure
    """
    assert type in ['apdx-validation', 'macros', 'body']
    correct_file = os.path.normpath('./test-tex/{0}/{1}.tex'.format(name, type))
    temp_file = os.path.normpath('./temp/{0}/{1}.tex'.format(name, type))
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def run_test(name, test_type):
    """
    Generic test function.

    :param name: directory name
    :param test_type: a valid test type e.g. 'macros'
    :returns: 0 if success or file missing, 1 if failure.
    """
    filename = test_functions.set_up_test(name, 'Tex', test_type)
    generate_files(filename, name, test_type)
    fail = compare_items(name, test_type)
    print('')
    return fail


