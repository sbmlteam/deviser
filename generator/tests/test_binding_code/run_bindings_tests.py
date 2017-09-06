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


def generate_bindings_downcast_ext(filename, binding):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if os.path.isdir(binding):
        os.chdir(binding)
    else:
        os.makedirs(binding)
        os.chdir(binding)
    all_files = BindingsFiles.BindingFiles(ob, binding, True)
    all_files.write_downcast_extension()
    os.chdir('../.')
    os.chdir('../.')


def generate_bindings_downcast_ns(filename, binding):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if os.path.isdir(binding):
        os.chdir(binding)
    else:
        os.makedirs(binding)
        os.chdir(binding)
    all_files = BindingsFiles.BindingFiles(ob, binding, True)
    all_files.write_downcast_namespace()
    os.chdir('../.')
    os.chdir('../.')


def generate_bindings_downcast_pkgs(filename, binding, local):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if os.path.isdir(binding):
        os.chdir(binding)
    else:
        os.makedirs(binding)
        os.chdir(binding)
    all_files = BindingsFiles.BindingFiles(ob, binding, True)
    if binding == 'swig':
        all_files.write_swig_files()
    elif local:
        all_files.write_local()
    else:
        all_files.write_downcast_packages()
    os.chdir('../.')
    os.chdir('../.')


def generate_bindings_downcast_plugins(filename, binding):
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    os.chdir('./temp')
    if os.path.isdir(binding):
        os.chdir(binding)
    else:
        os.makedirs(binding)
        os.chdir(binding)
    all_files = BindingsFiles.BindingFiles(ob, binding, True)
    all_files.write_downcast_plugins()
    os.chdir('../.')
    os.chdir('../.')


#############################################################################
# Specific compare functions

def compare_files(correct_file, temp_file):
    return test_functions.compare_files(correct_file, temp_file, fails,
                                        not_tested)


def compare_code(name, binding, ext):
    correct_file = '.\\test-binding\\{0}\\{1}.{2}'.format(binding, name, ext)
    temp_file = '.\\temp\\{0}\\{1}.{2}'.format(binding, name, ext)
    return compare_files(correct_file, temp_file)


def compare_ext_headers(class_name):
    correct_file = '.\\test-extension\\{0}.h'.format(class_name)
    temp_file = '.\\temp\\{0}.h'.format(class_name)
    return compare_files(correct_file, temp_file)


#############################################################################
# Specific test functions

def run_ns_test(name, binding, ext):
    filename = test_functions.set_up_test(name, 'downcast-ns', binding)
    generate_bindings_downcast_ns(filename, binding)
    if name == 'test_vers':
        name = 'vers'
    fail = compare_code('local-downcast-namespaces-{0}'.format(name),
                        binding, ext)
    print('')
    return fail


def run_test(name, binding, ext):
    filename = test_functions.set_up_test(name, 'downcast-ext', binding)
    generate_bindings_downcast_ext(filename, binding)
    if name == 'test_vers':
        name = 'vers'
    fail = compare_code('local-downcast-extension-{0}'.format(name),
                        binding, ext)
    print('')
    return fail


def run_pkgs_test(name, binding, ext):
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
    filename = test_functions.set_up_test(name, 'downcast-plugins', binding)
    generate_bindings_downcast_plugins(filename, binding)
    fail = compare_code('local-downcast-plugins-{0}'.format(name),
                        binding, ext)
    print('')
    return fail


def run_swig_test(name, binding, ext):
    filename = test_functions.set_up_test(name, 'native', binding)
    generate_bindings_downcast_pkgs(filename, binding, True)
    fail = compare_code('{0}-package'.format(name), binding, ext)
    print('')
    return fail


#########################################################################
# Main function

def main():

    # set up the enivornment
    this_dir = os.path.dirname(os.path.abspath(__file__))

    (path_to_tests, other) = os.path.split(this_dir)
    test_functions.set_path_to_tests(path_to_tests)
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    fail = 0

    runall = True
#    runall = False
    if runall:
        # run the individual tests
        name = 'spatial'
        test_case = 'csharp'
        ext = 'i'
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
#        fail += run_test(name, test_case, ext)
        fail += run_ns_test(name, test_case, ext)
#        fail += run_pkgs_test(name, test_case, ext)

    test_functions.report('BINDINGS', fail, fails, not_tested)
    return fail


if __name__ == '__main__':
    main()
