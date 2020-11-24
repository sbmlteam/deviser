#!/usr/bin/env python
#
# @file    generateCode.py
# @brief   function for generating all code files
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2018 by the California Institute of Technology
# (California, USA), the European Bioinformatics Institute (EMBL-EBI, UK)
# and the University of Heidelberg (Germany), with support from the National
# Institutes of Health (USA) under grant R01GM070923.  All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
# Neither the name of the California Institute of Technology (Caltech), nor
# of the European Bioinformatics Institute (EMBL-EBI), nor of the University
# of Heidelberg, nor the names of any contributors, may be used to endorse
# or promote products derived from this software without specific prior
# written permission.
# ------------------------------------------------------------------------ -->

import sys
import os
from parseXML import ParseXML
from code_files import (ExtensionFiles, CppFiles, ValidationFiles,
                        BaseClassFiles)
from bindings_files import BindingsFiles
from cmake_files import CMakeFiles
from base_files import BaseFile, BaseTemplateFile  # , BaseTxtFile
from util import global_variables as gv, strFunctions
import shutil

directories = []


def generate_code_for(filename, overwrite=True):
    """
    Main 'workhorse' function that creates a libSBML extension (??)
    for the given filename

    :param filename: name of file to parse, e.g. samples/dyn.xml
    :param overwrite: currently an issue (#12)
    :return: returns nothing
    """

    # Attempt to parse the XML file:
    gv.running_tests = False
    parser = ParseXML.ParseXML(filename)
    ob = []  # The big structure of dictionaries etc created from the DOM.
    if gv.code_returned == gv.return_codes['success']:
        # catch a problem in the parsing
        try:
            ob = parser.parse_deviser_xml()
        except Exception:
            gv.code_returned = gv.return_codes['parsing error']
    if gv.code_returned == gv.return_codes['success']:
        name = ob['name'.lower()]
        language = gv.language
        # TO DO REMEMBER TO REMOVE   TODO why?
        # try:
        if gv.is_package:
            generate_package_code(name, language, overwrite, ob)
        else:
            generate_other_library_code(name, language, overwrite, ob)
        # except:
        #     gv.code_returned \
        #         = gv.return_codes['unknown error - please report']


def generate_other_library_code(name, language, overwrite, ob):
    '''
    Documentation for this function incomplete until issue #12 resolved.

    Generate code when it's not a package.

    :param name: `name` attribute node value, e.g. "dyn" for samples/dyn.xml
    :param language: <language> node `name` value, e.g. "SBGN" or "SedML".
    :param overwrite: see issue #12 TODO
    :param ob: big dictionary structure representing nodes from the XML file.
    :returns: nothing
    '''
    if not create_dir_structure(name, language, overwrite):
        print('Problem encountered creating directories')
        print('Either delete what directory structure is there or')
        print('re run with overwrite=True')
        return False
    # for working_class in ob['baseElements']:
    #     strFunctions.prefix_classes(working_class)
    generate_other_library_code_files(name, ob)
    generate_bindings_files_for_other(name, ob)
    generate_cmake_files_for_other(name, ob)
    generate_global_files()


def generate_global_files():
    """
    Generate the global files required
    e.g. VERSION.txt, README.md, LICENSE.txt
    """
    version = BaseFile.BaseFile('VERSION', 'txt')
    major = gv.library_version['major']
    minor = gv.library_version['minor']
    rev = gv.library_version['revision']
    version.write_line_verbatim('{0}.{1}.{2}\n'.format(major, minor, rev))
    version.close_file()

    # Copy mydir/../util/templates/README.md
    readme = BaseTemplateFile.BaseTemplateFile('README.md', 'util')
    fileout = BaseFile.BaseFile('README', 'md')
    readme.copy_file_contents(fileout, 'README.md')
    fileout.close_file()

    lic = BaseFile.BaseFile('LICENSE', 'txt')
    lic.write_line_verbatim('LICENSE\n')
    lic.close_file()


def generate_package_code(name, language, overwrite, ob):
    '''
    Generate code for a package.

    :param name: `name` attribute node value, e.g. "dyn" for samples/dyn.xml
    :param language: <language> node `name` value, e.g. "SBGN" or "SedML".
    :param overwrite: see issue #12 TODO
    :param ob: big dictionary structure representing nodes from the XML file.
    :returns: nothing
    '''
    if not create_dir_structure(name, language, overwrite):
        print('Problem encountered creating directories.')
        print('Either delete what directory structure is there or')
        print('re-run with overwrite=True.')
        return
    gv.populate_error_list(ob)
    generate_code_files(name, ob)
    generate_bindings_files(name, ob)
    generate_cmake_files(name, ob)
    generate_example_files(ob)


def generate_example_files(ob):
    '''
    Generate the CMake/C++ files in the `examples` directory

    :param ob: pkg_object (big dictionary structure of info from XML file)
    :return: returns nothing
    '''
    this_dir = os.getcwd()
    os.chdir('examples')
    cmake = CMakeFiles.CMakeFiles(ob, this_dir, True)
    cmake.write_example_files()
    os.chdir(this_dir)


def generate_cmake_files(name, ob):
    """
    Generate CMake files in directory `name`.

    :param name: directory in which to create the files.
    :param ob: big dictionary structure of info from XML file
    :return: returns nothing.
    """
    os.chdir('{0}'.format(name))
    this_dir = os.getcwd()
    cmake = CMakeFiles.CMakeFiles(ob, this_dir, True)
    cmake.write_files()
    os.chdir(this_dir)


def generate_cmake_files_for_other(name, ob):
    """
    Generate CMake base files for other library implementations.

    :param name: directory in which to create the files.
    :param ob: big dictionary structure of info from XML file
    :return: returns nothing.
    """
    os.chdir('{0}'.format(name))
    this_dir = os.getcwd()
    cmake = CMakeFiles.CMakeFiles(ob, this_dir, True)
    cmake.write_other_library_files()
    os.chdir(this_dir)


def generate_binding_files_in_dir(name, startdir, language, ob):
    """
    cd into a directory, write out files, then cd back to initial directory.

    :param name:
    :param startdir: dictionary we started from.
    :param language: a string like "csharp" or "java".
    :param ob: the large dictionary structure of node information.
    :return: returns nothing.

    This function is to replace blocks of code like this:

    csharp_dir = '{0}{1}src{1}bindings{1}csharp'.format(name, os.sep)
    os.chdir(csharp_dir)
    bind = BindingsFiles.BindingFiles(ob, 'csharp', True)
    bind.write_files()
    os.chdir(this_dir)

    We could add an option for swig. But we would then have to check it worked
    for the swig call in both generate_bindings_files() and
    generate_bindings_files_for_other(); the latter has a call to
    write_swig_library_files(), but the latter has the usual write_files()
    call.
    """
    lang_dir = '{0}{1}src{1}bindings{1}{2}'.format(name, os.sep, language)
    os.chdir(lang_dir)
    bind = BindingsFiles.BindingFiles(ob, language, True)
    bind.write_files()
    os.chdir(startdir)


def generate_bindings_files(name, ob):
    """
    Verbosely generate bindings files for C/C++ code to
    connect to code in other languages.

    :param name: used in names of directories in which to create the files.
    :param ob: big dictionary structure of info from XML file
    :return: returns nothing.
    """
    this_dir = os.getcwd()

    languages = ['csharp', 'java', 'javascript', 'perl', 'php', 'python', \
                 'r', 'ruby', 'swig']
    for lang in languages:
        generate_binding_files_in_dir(name, this_dir, lang, ob)

    #generate_binding_files_in_dir(name, this_dir, 'csharp', ob)
    #generate_binding_files_in_dir(name, this_dir, 'java', ob)
    #generate_binding_files_in_dir(name, this_dir, 'javascript', ob)
    #generate_binding_files_in_dir(name, this_dir, 'perl', ob)
    #generate_binding_files_in_dir(name, this_dir, 'php', ob)
    #generate_binding_files_in_dir(name, this_dir, 'python', ob)
    #generate_binding_files_in_dir(name, this_dir, 'r', ob)
    #generate_binding_files_in_dir(name, this_dir, 'ruby', ob)
    #generate_binding_files_in_dir(name, this_dir, 'swig', ob)


def generate_bindings_files_for_other(name, ob):
    """
    Called when we're not generating code for a package.

    :param name: used in names of directories in which to create the files.
    :param ob: big dictionary structure of info from XML file
    :return: returns nothing.
    """
    this_dir = os.getcwd()
    languages = ['csharp', 'java', 'python', ]
                 # 'javascript', 'perl', 'php', 'r', 'ruby', 'swig']

    for lang in languages:
        generate_binding_files_in_dir(name, this_dir, lang, ob)

    swig_dir = '{0}{1}src{1}bindings{1}swig'.format(name, os.sep)
    os.chdir(swig_dir)
    bind = BindingsFiles.BindingFiles(ob, 'swig', True)
    # This line doesn't appear in generate_bindings_files():
    bind.write_swig_library_files()
    os.chdir(this_dir)


def generate_code_files(name, ob):
    """
    Write Extension files (for plugins) and Validation files (for cpp).
    Called by generate_package_code()

    :param name: used in names of directories in which to create the files.
    :param ob: big dictionary structure of info from XML file
    :return: returns nothing.
    """
    this_dir = os.getcwd()
    language = gv.language
    common_dir = '{0}{1}src{1}{2}{1}packages{1}{0}{1}common'.format(name,
                                                                    os.sep,
                                                                    language)
    extension_dir = '{0}{1}src{1}{2}{1}packages{1}{0}{1}' \
                    'extension'.format(name, os.sep, language)
    valid_dir = '{0}{1}src{1}{2}{1}packages{1}{0}{1}validator'.format(name,
                                                                      os.sep,
                                                                      language)
    constraints_dir = '{0}{1}src{1}{2}{1}packages{1}{0}{1}validator{1}' \
                      'constraints'.format(name, os.sep, language)
    sbml_dir = '{0}{1}src{1}{2}{1}packages{1}{0}{1}{2}'.format(name, os.sep,
                                                               language)
    os.chdir(common_dir)
    ext = ExtensionFiles.ExtensionFiles(ob, 'types', True)
    ext.write_files()
    ext = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    ext.write_files()
    os.chdir(this_dir)

    os.chdir(extension_dir)
    ext = ExtensionFiles.ExtensionFiles(ob, '', True)
    ext.write_files()
    for i in range(0, len(ob['plugins'])+1):
        ext.write_plugin_files(i)
    os.chdir(this_dir)

    os.chdir(valid_dir)
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_files()
    os.chdir(this_dir)

    os.chdir(constraints_dir)
    all_files = ValidationFiles.ValidationFiles(ob, True)
    all_files.write_constraint_files()
    os.chdir(this_dir)

    # need to do this last so that the error table is populated
    os.chdir(sbml_dir)
    for working_class in ob['baseElements']:
        all_files = CppFiles.CppFiles(working_class, True)
        all_files.write_files()
    for add_file in gv.add_implementation:
        shutil.copy(add_file, os.getcwd())
    for add_file in gv.add_declaration:
        shutil.copy(add_file, os.getcwd())

    os.chdir(this_dir)


def generate_other_library_code_files(name, ob):
    """
    Used when not generating a package.
    Called by generate_other_library_code()

    :param name: used in names of directories in which to create the files.
    :param ob: big dictionary structure of info from XML file
    :return: returns nothing.
    """
    this_dir = os.getcwd()
    language = gv.language
    prefix = gv.prefix
    main_dir = '{0}{1}src{1}{2}'.format(name, os.sep, language)
    common_dir = '{0}{1}src{1}{2}{1}common'.format(name, os.sep, language)
    # binding_dir = '{0}{1}src{1}bindings'.format(name, os.sep)
    os.chdir(main_dir)

    # take these lines out to write without prefix
    for working_class in ob['baseElements']:
        strFunctions.prefix_classes(working_class)

    # this populates the error structures
    ValidationFiles.ValidationFiles(ob, True)  # Can check retval if required.
    for working_class in ob['baseElements']:
        if working_class['name'] == gv.document_class:
            working_class['document'] = True
        all_files = CppFiles.CppFiles(working_class, True)
        all_files.write_files()
    base_files = BaseClassFiles.\
        BaseClassFiles(prefix, ob['baseElements'], True)
    base_files.write_files()
    os.chdir(this_dir)

    os.chdir(common_dir)
    base_files.write_common_files()
    ext = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    ext.write_files()
    if 'enums' in ob and len(ob['enums']) > 0:
        ext = ExtensionFiles.ExtensionFiles(ob, 'enums', True)
        ext.write_files()
    os.chdir(this_dir)


# Functions to create the appropriate directory structure
def populate_package_directories(name, lang):
    global directories
    sep = os.sep
    directories = ['{0}'.format(name),
                   '{0}{1}examples'.format(name, sep),
                   '{0}{1}examples{1}c++'.format(name, sep),
                   '{0}{1}examples{1}c++{1}{0}'.format(name, sep),
                   '{0}{1}src'.format(name, sep),
                   '{0}{1}src{1}bindings'.format(name, sep),
                   '{0}{1}src{1}bindings{1}csharp'.format(name, sep),
                   '{0}{1}src{1}bindings{1}java'.format(name, sep),
                   '{0}{1}src{1}bindings{1}javascript'.format(name, sep),
                   '{0}{1}src{1}bindings{1}perl'.format(name, sep),
                   '{0}{1}src{1}bindings{1}php'.format(name, sep),
                   '{0}{1}src{1}bindings{1}python'.format(name, sep),
                   '{0}{1}src{1}bindings{1}r'.format(name, sep),
                   '{0}{1}src{1}bindings{1}ruby'.format(name, sep),
                   '{0}{1}src{1}bindings{1}swig'.format(name, sep),
                   '{0}{1}src{1}{2}'.format(name, sep, lang),
                   '{0}{1}src{1}{2}{1}packages'.format(name, sep, lang),
                   '{0}{1}src{1}{2}{1}packages{1}{0}'.format(name, sep, lang),
                   '{0}{1}src{1}{2}{1}packages{1}{0}{1}common'.format(name,
                                                                      sep,
                                                                      lang),
                   '{0}{1}src{1}{2}{1}packages{1}{0}{1}extension'.format(name,
                                                                         sep,
                                                                         lang),
                   '{0}{1}src{1}{2}{1}packages{1}{0}{1}{2}'.format(name, sep,
                                                                   lang),
                   '{0}{1}src{1}{2}{1}packages{1}{0}{1}validator'.format(name,
                                                                         sep,
                                                                         lang),
                   '{0}{1}src{1}{2}{1}packages{1}{0}{1}validator{1}'
                   'constraints'.format(name, sep, lang)]


def populate_other_library_directories(name, lang):
    global directories
    sep = os.sep
    directories = ['{0}'.format(name),
                   '{0}{1}examples'.format(name, sep),
                   '{0}{1}src'.format(name, sep),
                   '{0}{1}src{1}bindings'.format(name, sep),
                   '{0}{1}src{1}bindings{1}csharp'.format(name, sep),
                   '{0}{1}src{1}bindings{1}java'.format(name, sep),
                   '{0}{1}src{1}bindings{1}javascript'.format(name, sep),
                   '{0}{1}src{1}bindings{1}perl'.format(name, sep),
                   '{0}{1}src{1}bindings{1}php'.format(name, sep),
                   '{0}{1}src{1}bindings{1}python'.format(name, sep),
                   '{0}{1}src{1}bindings{1}r'.format(name, sep),
                   '{0}{1}src{1}bindings{1}ruby'.format(name, sep),
                   '{0}{1}src{1}bindings{1}swig'.format(name, sep),
                   '{0}{1}src{1}{2}'.format(name, sep, lang),
                   '{0}{1}src{1}{2}{1}common'.format(name, sep, lang)]


def create_dir_structure(pkgname, lang, overwrite):
    '''
    Documentation for this function held off until issue #12 resolved.
    '''
    if gv.is_package:
        populate_package_directories(pkgname, lang)
    else:
        populate_other_library_directories(pkgname, lang)
    print('creating directory structure for {0}'.format(pkgname))
    index = 0
    all_present = False
    if os.path.exists(pkgname):
        all_present = check_directory_structure()
        index = 1
    done = True
    if not all_present:
        while done and index < len(directories):
            done = create_dir(directories[index], overwrite)
            index += 1
    elif not overwrite:
        print('directory already exists - terminating to avoid overwriting')
        done = False
    else:
        print('directory already exists - files may get overwritten')
    return done


def check_directory_structure():
    global directories
    for directory in directories:
        if not os.path.exists(directory):
            return False
    return True


def create_dir(name, skip_existing):
    """ skip_existing seems to be a synonym for `overwrite` parameter,
     used in function create_dir_structure(). I don't think it is being
     used properly here.

     See deviser issue #12
     """
    if os.path.exists(name):
        if skip_existing:
            done = True
        else:
            print('some parts of the directory structure exist and '
                  'others are missing')
            print('terminating as we are not sure what is going on')
            done = False
    else:
        os.mkdir(name)
        print('creating dir {0}'.format(name))
        done = True
    return done


def main(args):
    if len(args) != 2:  # TODO could be *too many* args as well.
        gv.code_returned = gv.return_codes['missing function argument']
        print('Usage: generateCode.py xmlfile')
    else:
        generate_code_for(args[1])
    if gv.code_returned == gv.return_codes['success']:
        print('code successfully written')
    else:
        print('writing code failed')

    return gv.code_returned


if __name__ == '__main__':
    main(sys.argv)
