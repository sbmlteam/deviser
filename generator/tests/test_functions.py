#!/usr/bin/env python

import os
import shutil
import sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/..')
from util import global_variables as gv


path_to_tests = ''
function_table = {'binding': 'run_bindings_tests',
                  'cmake': 'run_cmake_tests',
                  'cpp': 'run_cpp_tests',
                  'exit': 'run_exit_tests',
                  'matlab': 'run_matlab_tests',
                  'tex': 'run_tex_tests'}


def set_path_to_tests(dirname):
    """
    Set up; set global value of the path to the tests.

    :param dirname: the directory containing the tests.
    :return: nothing
    """
    global path_to_tests
    path_to_tests = dirname
    remove_temp()
    set_running_tests()


def set_running_tests():
    """
    Set running tests variable.
    Needs to be separate as the global run test function uses it
    """
    gv.running_tests = True
    gv.code_returned = gv.return_codes['success']


def set_up_test(name, class_name, test_case=''):
    """
    Get the xml filename, and print a banner defining the test.

    :param name: stub of XML filename, e.g. 'dyn' for filename 'dyn.xml'
    :param class_name: test class, e.g. 'MATLAB', 'Examples'.
    :param test_case: brief test description, to output on screen
    :return: path to the required XML file.
    """
    set_running_tests()
    print('====================================================')
    print('Testing {0}:{1} {2}'.format(name, class_name, test_case))
    print('====================================================')
    fname = '{0}.xml'.format(name)
    filename = os.path.join(path_to_tests, 'test_xml_files', fname)
    return filename


def read_file(path):
    """
    Reads file containing expected sbml model and returns it as string.

    :param path: location of file to read
    :returns: contents of the file, as a string.
    """
    filein = open(path, 'r')
    contents = filein.read()
    filein.close()
    return contents


def compare_files(infile, outfile, fails, not_tested):
    """
    Do a string comparison of the contents of two files.

    :param infile: reference file
    :param outfile: file generated during tests
    :param fails: list of failure cases
    :param not_tested: list of untested cases
    :returns: 0 on success, or file not present; 1 on failure.
    """
    ret = 0
    if not os.path.isfile(infile):
        # we have not added a file to compare to
        not_tested.append(infile)
        return ret
    elif not os.path.isfile(outfile):
        print(outfile)
        fails.append(infile)
        print('{0}=================>> MISSING'.format(outfile))
        return 1
    indata = read_file(infile)
    out = read_file(outfile)
    if indata.strip() == out.strip():
        print('{0} .... PASSED'.format(outfile))
    else:
        fails.append(infile)
        print('{0}=================>> FAILED'.format(outfile))
        ret = 1
    return ret


def compare_return_codes(name, flag, expected_return, fails):
    """
    Compare return code from a test with that expected.

    :param name: general name of test
    :param flag: a command-line flag
    :param expected_return: expected return code from a test
    :param fails: list of failure cases
    :return: 0 on success, 1 on failure.
    """
    ret = 0
    this_return = gv.code_returned
    expected = gv.get_return_code(expected_return)
    if this_return == expected_return:
        print('{0} returned \'{1}\' as expected'.format(name, expected))
    else:
        ret = 1
        fails.append('{0}: {1} {2}'.format(name, flag, expected_return))
        print('Incorrect Return: {0} Expected: '
              '{1}'.format(gv.get_return_code(this_return),
                           gv.get_return_code(expected_return)))
    return ret


def run_tests(test_name, name, fails):
    """
    Run a set of tests.

    :param test_name: name of test, e.g. 'test_binding_code'
    :param name: e.g. 'code' TODO not entirely sure what this is
    :param fails: list of failure cases
    :returns: 0 if all tests pass, 1 if at least one failure case.
    """
    ret = 0
    print('====================================================')
    print('Running {0}'.format(test_name))
    print('====================================================')
    module = '{0}.{1}.main()'.format(test_name, function_table[name])
    # I have a circular dependency in my imports if I declare these globally
    # see http://stackoverflow.com/questions/9252543/importerror-cannot-import-name-x
    import test_binding_code
    import test_cmake_code
    import test_cpp_code
    import test_exit_code
    import test_tex_files
    import test_matlab_code
    fail = eval(module)
    if fail > 0:
        ret = 1
        fails.append(name)
        print('{0}=================>> FAILED'.format(test_name))
    else:
        print('{0} .... PASSED'.format(test_name))
    print('')
    return ret


def report(name, fail, fails, not_tested):
    """
    Write a report for the tests.

    :param name: name of test suite, e.g. 'EXIT CODES'
    :param fail: number of test failures encountered
    :param fails: list of failure cases
    :param not_tested: list of untested cases
    :returns: nothing
    """
    print('****************************************************************')
    print('REPORT for {0} Tests'.format(name))

    if len(not_tested) > 0:
        print('The following files were not tested:')
        for name in not_tested:
            print(name)
    else:
        print('All tests were run.')

    if fail > 0:
        print('!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
        print('{0} fails reported:'.format(fail))
        for name in fails:
            print(name)
    else:
        print('No fails reported.')
    print('****************************************************************')
    print('')


def remove_temp():
    """
    Create temp directory, or replace it if it exists already.
    """
    if not os.path.isdir('temp'):
        os.mkdir('temp')
    else:
        shutil.rmtree('temp')
        os.mkdir('temp')


def create_dir(newdir):
    """
    Create a new directory, or replace it if it exists already.

    :param newdir: path to the new directory (or the one to be replaced)
    :return: nothing
    """
    if not os.path.isdir(newdir):
        os.mkdir(newdir)
    else:
        shutil.rmtree(newdir)
        os.mkdir(newdir)
