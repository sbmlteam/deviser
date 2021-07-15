#!/usr/bin/env python
"""
Generating the binding files creates a number of files for each language,
as well as swig and local specific files.

Every language will generate a file to downcast extensions, namespaces and
specific classes.

e.g. generating csharp bindings for package 'spatial' will result in files:

bindings
    csharp
        local-downcast-extension-spatial.i
        local-downcast-namespaces-spatial.i
        local-packages-spatial.i
    swig
        spatial-packages.h
        spatial-packages.i

Certain languages will also require .cpp files.

Testing these involves creating each of these specific files for a
language/package combination and having distinct functions to create and
compare the files.
"""

import os

from ...bindings_files import BindingsFiles
from ...parseXML import ParseXML

from .. import functions

##############################################################################
# Set up variables
fails = []
not_tested = []

##############################################################################
# Specific generation functions


def set_up(filename, binding):
    """
    Generic set-up code used by all the specific generation functions.
    Parse XML file and use the big dictionary structure obtained to
    generate a bindings file of the required binding.

    :param filename: the XML file to parse
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :return: the new file object
    """
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir(os.path.normpath('./temp'))
    if os.path.isdir(binding):
        os.chdir(binding)
    else:
        os.makedirs(binding)
        os.chdir(binding)
    all_files = BindingsFiles.BindingFiles(ob, binding, True)
    return all_files


def generate_bindings_downcast_ext(filename, binding):
    """
    Generate a downcast extension file.

    :param filename: name of the file to generate
    :param binding: string indicating which language binding to generate
    """
    all_files = set_up(filename, binding)
    all_files.write_downcast_extension()
    os.chdir(os.path.normpath('../..'))


def generate_bindings_downcast_ns(filename, binding):
    """
    Generate a downcast namespace.
    """
    all_files = set_up(filename, binding)
    all_files.write_downcast_namespace()
    os.chdir(os.path.normpath('../..'))


def generate_bindings_downcast_pkgs(filename, binding, local):
    """
    Generate a downcast package.

    :param filename:
    :param binding:
    :param local:
    """
    all_files = set_up(filename, binding)
    if binding == 'swig':
        all_files.write_swig_files()
    elif local:
        all_files.write_local()
    else:
        all_files.write_downcast_packages()
    os.chdir(os.path.normpath('../..'))


def generate_bindings_downcast_plugins(filename, binding):
    """
    Generate a downcast plugin.
    """
    all_files = set_up(filename, binding)
    all_files.write_downcast_plugins()
    os.chdir(os.path.normpath('../..'))

#############################################################################
# Specific compare functions


def compare_code(name, binding, ext):
    """
    Compare a reference file with a temporary test version of the file.

    :param name: name of reference file
    :param binding: which binding, e.g. 'java'
    :param ext: the file extension
    :returns: 0 on success or missing file, 1 on failure.
    """
    correct_file = os.path.normpath('./test-binding/{0}/{1}.{2}'.format(binding, name, ext))
    temp_file = os.path.normpath('./temp/{0}/{1}.{2}'.format(binding, name, ext))
    return functions.compare_files(correct_file, temp_file, fails,
                                   not_tested)


#############################################################################
# Specific test functions

def run_ns_test(name, binding, ext):
    """
    Run a namespace test.

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = functions.set_up_test(name, 'downcast-ns', binding)
    generate_bindings_downcast_ns(filename, binding)
    if name == 'test_vers':
        name = 'vers'
    fail = compare_code('local-downcast-namespaces-{0}'.format(name),
                        binding, ext)
    print('')
    return fail


def run_test(name, binding, ext):
    """
    Run a test.

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = functions.set_up_test(name, 'downcast-ext', binding)
    generate_bindings_downcast_ext(filename, binding)
    if name == 'test_vers':
        name = 'vers'
    fail = compare_code('local-downcast-extension-{0}'.format(name),
                        binding, ext)
    print('')
    return fail


def run_pkgs_test(name, binding, ext):
    """
    Run a pkgs test.

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = functions.set_up_test(name, 'downcast-packages', binding)
    generate_bindings_downcast_pkgs(filename, binding, False)
    if name == 'test_vers':
        name = 'vers'
    if binding == 'csharp' or binding == 'java':
        this_name = 'local-packages-{0}'.format(name)
    else:
        this_name = 'local-downcast-packages-{0}'.format(name)
    fail = compare_code(this_name, binding, ext)
    print('')
    return fail


def run_local_test(name, binding, ext, local):
    """
    Run a local test.

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :param local:
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = functions.set_up_test(name, 'local', binding)
    generate_bindings_downcast_pkgs(filename, binding, local)
    if binding == 'csharp' or binding == 'java':
        this_name = 'local-packages-{0}'.format(name)
    else:
        this_name = 'local-{0}'.format(name)
    fail = compare_code(this_name, binding, ext)
    print('')
    return fail


def run_plugin_test(name, binding, ext):
    """
    Run a plugin test.

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = functions.set_up_test(name, 'downcast-plugins', binding)
    generate_bindings_downcast_plugins(filename, binding)
    fail = compare_code('local-downcast-plugins-{0}'.format(name),
                        binding, ext)
    print('')
    return fail


def run_swig_test(name, binding, ext):
    """
    Run a SWIG test.

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = functions.set_up_test(name, 'native', binding)
    generate_bindings_downcast_pkgs(filename, binding, True)
    fail = compare_code('{0}-package'.format(name), binding, ext)
    print('')
    return fail
