#!/usr/bin/env python

import os
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../')
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../../')

from bindings_files import BindingsFiles
from parseXML import ParseXML

import test_functions

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
    Generate a downcast extension.  TODO such as?
    """
    all_files = set_up(filename, binding)
    all_files.write_downcast_extension()
    os.chdir(os.path.normpath('../..'))


def generate_bindings_downcast_ns(filename, binding):
    """
    Generate a downcast namespace.   TODO such as?
    """
    all_files = set_up(filename, binding)
    all_files.write_downcast_namespace()
    os.chdir(os.path.normpath('../..'))


def generate_bindings_downcast_pkgs(filename, binding, local):
    """
    Generate a downcast package. TODO such as?

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
    Generate a downcast plugin.  TODO such as?
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
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_ext_headers(class_name):
    """
    TODO This function doesn't appear to be used anywhere.
    """
    correct_file = os.path.normpath('./test-extension/{0}.h'.format(class_name))
    temp_file = os.path.normpath('./temp/{0}.h'.format(class_name))
    return test_functions.compare_files(correct_file, temp_file, fails,
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
    filename = test_functions.set_up_test(name, 'downcast-ns', binding)
    generate_bindings_downcast_ns(filename, binding)
    if name == 'test_vers':
        name = 'vers'
    fail = compare_code('local-downcast-namespaces-{0}'.format(name),
                        binding, ext)
    print('')
    return fail


# TODO I'm not sure what these different test functions are testing, exactly.


def run_test(name, binding, ext):
    """
    Run a test. TODO Sarah please expand...

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = test_functions.set_up_test(name, 'downcast-ext', binding)
    generate_bindings_downcast_ext(filename, binding)
    if name == 'test_vers':
        name = 'vers'
    fail = compare_code('local-downcast-extension-{0}'.format(name),
                        binding, ext)
    print('')
    return fail


def run_pkgs_test(name, binding, ext):
    """
    Run a pkgs test. TODO Sarah please expand...

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = test_functions.set_up_test(name, 'downcast-packages', binding)
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
    Run a local test. TODO Sarah please expand...

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :param local: TODO Sarah please expand...
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = test_functions.set_up_test(name, 'local', binding)
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
    Run a plugin test. TODO Sarah please expand...

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = test_functions.set_up_test(name, 'downcast-plugins', binding)
    generate_bindings_downcast_plugins(filename, binding)
    fail = compare_code('local-downcast-plugins-{0}'.format(name),
                        binding, ext)
    print('')
    return fail


def run_swig_test(name, binding, ext):
    """
    Run a SWIG test. TODO Sarah please expand...

    :param name: package name
    :param binding: the required binding, e.g. 'csharp', 'java', etc.
    :param ext: the file extension
    :return: 0 on success or missing file, 1 on failure.
    """
    filename = test_functions.set_up_test(name, 'native', binding)
    generate_bindings_downcast_pkgs(filename, binding, True)
    fail = compare_code('{0}-package'.format(name), binding, ext)
    print('')
    return fail


#########################################################################
# Main function

def main():

    # Set up the environment.
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, _) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0

    run_all = True

    if run_all:
        # run the individual tests
        # TODO Using pytest parameterization would be good here.

        name = 'spatial'
        test_case = 'csharp'
        ext = 'i'
        # my_tuple = ('spatial', 'csharp', 'i')
        # fail += run_test(my_tuple[0], my_tuple[1], my_tuple[2])
        # fail += run_test(name=my_tuple[0], binding=my_tuple[1], ext=my_tuple[2])
        fail += run_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'java'
        ext = 'i'
        fail += run_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'javascript'
        ext = 'cpp'
        fail += run_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'perl'
        ext = 'cpp'
        fail += run_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'php'
        ext = 'cpp'
        fail += run_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'python'
        ext = 'cpp'
        fail += run_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'r'
        ext = 'cpp'
        fail += run_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'ruby'
        ext = 'cpp'
        fail += run_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'csharp'
        ext = 'i'
        fail += run_ns_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'java'
        ext = 'i'
        fail += run_ns_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'javascript'
        ext = 'cpp'
        fail += run_ns_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'perl'
        ext = 'cpp'
        fail += run_ns_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'php'
        ext = 'cpp'
        fail += run_ns_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'python'
        ext = 'cpp'
        fail += run_ns_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'r'
        ext = 'cpp'
        fail += run_ns_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'ruby'
        ext = 'cpp'
        fail += run_ns_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'javascript'
        ext = 'cpp'
        fail += run_pkgs_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'ruby'
        ext = 'cpp'
        fail += run_plugin_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'java'
        ext = 'i'
        fail += run_pkgs_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'csharp'
        ext = 'i'
        fail += run_local_test(name, test_case, ext, False)

        name = 'spatial'
        test_case = 'php'
        ext = 'i'
        fail += run_local_test(name, test_case, ext, True)

        name = 'spatial'
        test_case = 'swig'
        ext = 'i'
        fail += run_swig_test(name, test_case, ext)

        name = 'spatial'
        test_case = 'swig'
        ext = 'h'
        fail += run_swig_test(name, test_case, ext)

        name = 'qual'
        test_case = 'javascript'
        ext = 'cpp'
        fail += run_plugin_test(name, test_case, ext)

        name = 'test_vers'
        test_case = 'java'
        ext = 'i'
        fail += run_test(name, test_case, ext)
        fail += run_ns_test(name, test_case, ext)
        fail += run_pkgs_test(name, test_case, ext)
    else:
        name = 'test_vers'
        test_case = 'java'
        ext = 'i'
        # TODO Why are two of these tests commented out here?
        # They didn't raise any errors when I tried running them.
        # fail += run_test(name, test_case, ext)
        fail += run_ns_test(name, test_case, ext)
        # fail += run_pkgs_test(name, test_case, ext)

    test_functions.report('BINDINGS', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
