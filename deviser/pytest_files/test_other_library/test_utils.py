#!/usr/bin/env python

import os

from ...code_files import CppFiles, OtherLibraryFiles, ValidationFiles, ExtensionFiles
from ...cmake_files import CMakeFiles
from ...bindings_files import BindingsFiles
from ...parseXML import ParseXML
from ...util import strFunctions, global_variables as gv, generateCode

from .. import functions

##############################################################################
# Set up variables
fails = []
not_tested = []


##############################################################################
# Utility functions

def common_set_up(filename):
    """
    Perform common setting-up steps.

    :param filename: name of XML file to parse.
    :return: big dictionary structure obtained from the parsing.
    """
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    for wc in ob['baseElements']:
        strFunctions.prefix_classes(wc)
    for working_class in ob['baseElements']:
        if working_class['name'] == gv.document_class:
            working_class['document'] = True
    return ob


def go_into_new_directory():
    """
    Create the new ./temp directory if required. Go into it.
    """
    this_dir = os.getcwd()
    temp_dir = os.path.join(this_dir, 'temp')
    if not os.path.isdir(temp_dir):
        os.mkdir(temp_dir)
    os.chdir(temp_dir)
    new_dir = gv.language
    if not os.path.isdir(new_dir):
        os.mkdir(new_dir)
    os.chdir(new_dir)


##############################################################################
# Specific generation functions


def generate_new_cpp_header(filename, num):
    """
    Generate new C++ header and code files.

    :param filename: the XML file to parse.
    :param num: index allowing code to generate for just one class rather
                than all - it's a list index.
    :return: nothing
    """
    ob = common_set_up(filename)
    working_class = ob['baseElements'][num]
    if working_class['name'] == gv.document_class:
        working_class['document'] = True
    go_into_new_directory()
    all_files = CppFiles.CppFiles(working_class, True)
    all_files.write_files()
    os.chdir('../../.')


def generate_templates(filename):
    """
    Several of the files for other libraries are generated using
    templates with appropriate names etc added. See
    generator/code_files/templates.
    This function tests these

    :param filename: the XML file to parse.
    :return: nothing

    Validation class causes the errors for things to be enumerated and strings
    added. These will be needed by templates so with testing we have to
    create them first
    """
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    ValidationFiles.ValidationFiles(ob, True)
    go_into_new_directory()

    prefix = gv.prefix
    base_files = OtherLibraryFiles.OtherLibraryFiles(prefix, ob['baseElements'], True)
    base_files.write_files()
    os.chdir('../../.')


def generate_common_templates(filename):
    """
    Write the 'common' files. These are the files that will be part of
    the common directory as they are used by all files in library.

    :param filename: the XML file to parse.
    :return: nothing
    """
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    go_into_new_directory()

    prefix = gv.prefix
    base_files = OtherLibraryFiles.OtherLibraryFiles(prefix, ob['baseElements'], True)
    base_files.write_common_files()
    os.chdir('../../.')


def generate_forward(filename):
    """
    Write extension file with forward declaration of all opaque C types.

    :param filename: the XML file to parse.
    :return: nothing
    """
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    go_into_new_directory()

    ext = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    ext.write_files()
    os.chdir('../../.')


def generate_enum(filename):
    """
    According to ExtensionFile.py, this writes the extension types file.

    :param filename: the XML file to parse.
    :return: nothing

    For SBML, the extension file includes all the enums that are associated
    with a package. When generating code for a different library we still
    need a file that lists any enums so we create a version of the same file.

    Need to review this issue #44
    """
    ob = common_set_up(filename)
    gv.populate_error_list(ob)
    go_into_new_directory()

    ext = ExtensionFiles.ExtensionFiles(ob, 'enums', True)
    ext.write_files()
    os.chdir('../../.')


def generate_binding(filename, binding):
    """
    Generate the "binding" files.

    :param filename: the XML file to parse.
    :param binding: binding to use, e.g. 'swig', 'cmake', 'csharp'.
    :return: nothing
    """
    ob = common_set_up(filename)
    go_into_new_directory()

    if not os.path.isdir(binding):
        os.mkdir(binding)
    os.chdir(binding)
    all_files = BindingsFiles.BindingFiles(ob, binding, True)
    all_files.write_files()
    os.chdir('../.')
    os.chdir('../../.')


def generate_cmake(filename, binding):
    """
    Write CMake files CMakeLists.txt

    :param filename: the XML file to parse.
    :param binding: language binding, e.g. 'cmake'.
    :return: nothing
    """
    ob = common_set_up(filename)
    go_into_new_directory()

    if not os.path.isdir(binding):
        os.mkdir(binding)
    os.chdir(binding)

    this_dir = os.getcwd()
    functions.create_dir('src')
    os.chdir('src')
    functions.create_dir('bindings')
    functions.create_dir('{0}'.format(gv.language))
    os.chdir(this_dir)
    bind = CMakeFiles.CMakeFiles(ob, this_dir, True)
    bind.write_other_library_files()
    os.chdir('../.')
    os.chdir('../../.')


def generate_global(filename):
    """
    Generate the global files required
    e.g. VERSION.txt, README.md, LICENSE.txt.

    :param filename: the XML file to parse.
    :return: nothing
    """
    common_set_up(filename)  # Don't need ob!
    go_into_new_directory()
    generateCode.generate_global_files()
    os.chdir('../../.')

#############################################################################
# Specific compare functions


def compare_files(correct_file, temp_file):
    """
    Wrapper function to compare two files: are they identical?

    :param correct_file: the reference file we are comparing against
    :param temp_file: temporary file generated by the test code.
    :returns: 0 on success (= files are identical), or file not present; 1 on failure.
    """
    return functions.compare_files(correct_file, temp_file, fails,
                                   not_tested)

#########

def compare_code(class_name, end):
    """
    Compare two 'code' files. Are they identical?

    :param class_name: name of C++ class used in the test.
    :param end: file extension, e.g. ".h", ".txt", etc.
    :returns: 0 on success, or file not present; 1 on failure.
    """
    correct_file = os.path.normpath('./test-code/{1}/{0}{2}'.format(class_name, gv.language, end))
    temp_file = os.path.normpath('./temp/{1}/{0}{2}'.format(class_name, gv.language, end))
    return compare_files(correct_file, temp_file)

def compare_code_headers(class_name):
    return compare_code(class_name, ".h") if not class_name == '' else 0

def compare_code_impl(class_name):
    return compare_code(class_name, ".cpp") if not class_name == '' else 0

def compare_code_cmake(class_name):
    return compare_code(class_name, ".cmake")

def compare_code_txt(class_name, ext='.txt'):
    return compare_code(class_name, ext)

#########

def compare_binding(class_name, binding, end, prefix=""):
    """
    Compare two "binding" files.

    :param class_name: C++ class, e.g. "OStream"
    :param binding: the language binding,e.g. "swig" or "csharp"
    :param end: file extension, e.g. ".txt", ".cpp"
    :param prefix: I don't think this is ever used in any function calls.
    :returns: 0 on success, or file not present; 1 on failure.
    """
    correct_file = os.path.normpath('./test-code/{2}/{0}/{1}{3}'.format(binding, class_name, gv.language, end))
    # if prefix:
    temp_file = os.path.normpath('./temp/{3}/{0}/{2}/{1}{4}'.format(binding, class_name, prefix, gv.language, end))
    # else:
        # temp_file = os.path.normpath('./temp/{2}/{0}/{1}{3}'.format(binding, class_name, gv.language, end))
    return compare_files(correct_file, temp_file)


def compare_binding_headers(class_name, binding, prefix):
    return compare_binding(class_name, binding, ".h", prefix)

def compare_binding_impl(class_name, binding, prefix):
    return compare_binding(class_name, binding, ".cpp", prefix)

def compare_binding_interface(class_name, binding, prefix):
    return compare_binding(class_name, binding, ".i", prefix)

def compare_binding_file(class_name, binding, prefix):
    return compare_binding(class_name, binding, "", prefix)

##########

def compare_cmake_file(this_dir):
    """
    Compare a temporary test CMakeLists.txt file with the reference one.

    :param this_dir: lowest subdir containing the reference version of the file.
    :return: 0 on success, or file not present; 1 on failure.
    """
    correct_file = os.path.normpath('./test-code/{1}/cmake/{0}/CMakeLists.txt'.format(this_dir, gv.language))
    temp_file = os.path.normpath('./temp/{1}/cmake/{0}/CMakeLists.txt'.format(this_dir, gv.language))
    return compare_files(correct_file, temp_file)


#############################################################################
# Specific test functions


