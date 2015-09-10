#!/usr/bin/env python

import os

from bindings_files import BindingsFiles
from parseXML import ParseXML
from util import global_variables

use_new = True

fails = []


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


# reads file containing expected sbml model and returns it as string
def read_file(path):
    filein = open(path, 'r')
    contents = filein.read()
    filein.close()
    return contents


def compare_files(infile, outfile):
    global fails
    ret = 0
    if not os.path.isfile(infile) or not os.path.isfile(outfile):
        fails.append(infile)
        print('=================>> FAILED')
        return 1
    indata = read_file(infile)
    out = read_file(outfile)
    if indata.strip() == out.strip():
        print('PASSED')
    else:
        fails.append(infile)
        print('=================>> FAILED')
        ret = 1
    return ret


def run_ns_test(name, binding, ext):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, 'downcast-ns', binding))
    print('====================================================')
    generate_bindings_downcast_ns(filename, binding)
    correct_file = '.\\test-binding\\{}\\local-downcast-namespaces-{}' \
                   '.{}'.format(binding, name, ext)
    temp_file = '.\\temp\\{}\\local-downcast-namespaces-{}.' \
                '{}'.format(binding, name, ext)
    if os.path.exists(correct_file):
        print('local-downcast-namespaces-{}.{}'.format(name, ext))
        fail = compare_files(correct_file, temp_file)
    print('')
    return fail


def run_test(name, binding, ext):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, 'downcast-ext', binding))
    print('====================================================')
    generate_bindings_downcast_ext(filename, binding)
    correct_file = '.\\test-binding\\{}\\local-downcast-extension-{}.' \
                   '{}'.format(binding, name, ext)
    temp_file = '.\\temp\\{}\\local-downcast-extension-{}.' \
                '{}'.format(binding, name, ext)
    if os.path.exists(correct_file):
        print('local-downcast-extension-{}.{}'.format(name, ext))
        fail = compare_files(correct_file, temp_file)
    print('')
    return fail


def run_pkgs_test(name, binding, ext):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, 'downcast-packages', binding))
    print('====================================================')
    generate_bindings_downcast_pkgs(filename, binding, False)
    if binding == 'csharp' or binding == 'java':
        fileout = 'local-packages-{}.{}'.format(name, ext)
    else:
        fileout = 'local-downcast-packages-{}.{}'.format(name, ext)
    correct_file = '.\\test-binding\\{}\\{}'.format(binding, fileout)
    temp_file = '.\\temp\\{}\\{}'.format(binding, fileout)
    if os.path.exists(correct_file):
        print('{}'.format(fileout))
        fail = compare_files(correct_file, temp_file)
    else:
        print('{} file not found'.format(correct_file))
    print('')
    return fail


def run_local_test(name, binding, ext, local):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, 'local', binding))
    print('====================================================')
    generate_bindings_downcast_pkgs(filename, binding, local)
    if binding == 'csharp' or binding == 'java':
        fileout = 'local-packages-{}.{}'.format(name, ext)
    else:
        fileout = 'local-{}.{}'.format(name, ext)
    correct_file = '.\\test-binding\\{}\\{}'.format(binding, fileout)
    temp_file = '.\\temp\\{}\\{}'.format(binding, fileout)
    if os.path.exists(correct_file):
        print('{}'.format(fileout))
        fail = compare_files(correct_file, temp_file)
    else:
        print('{} file not found'.format(correct_file))
    print('')
    return fail


def run_plugin_test(name, binding, ext):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, 'downcast-plugins', binding))
    print('====================================================')
    generate_bindings_downcast_plugins(filename, binding)
    correct_file = '.\\test-binding\\{}\\local-downcast-plugins-{}.' \
                   '{}'.format(binding, name, ext)
    temp_file = '.\\temp\\{}\\local-downcast-plugins-{}.' \
                '{}'.format(binding, name, ext)
    if os.path.exists(correct_file):
        print('local-downcast-plugins-{}.{}'.format(name, ext))
        fail = compare_files(correct_file, temp_file)
    print('')
    return fail


def run_swig_test(name, binding, ext):
    filename = '.\\test_xml_files\\{}.xml'.format(name)
    fail = 0
    print('====================================================')
    print('Testing {}:{} {}'.format(name, binding, 'native'))
    print('====================================================')
    generate_bindings_downcast_pkgs(filename, binding, True)
    fileout = '{}-package.{}'.format(name, ext)
    correct_file = '.\\test-binding\\{}\\{}'.format(binding, fileout)
    temp_file = '.\\temp\\{}\\{}'.format(binding, fileout)
    if os.path.exists(correct_file):
        print('{}'.format(fileout))
        fail = compare_files(correct_file, temp_file)
    else:
        print('{} file not found'.format(correct_file))
    print('')
    return fail


def main():
    global_variables.running_tests = True
    fail = 0

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

    if fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('Check {} fails'.format(fail))
        for name in fails:
            print(name)


if __name__ == '__main__':
    main()
