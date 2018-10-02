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
from code_files import ExtensionFiles, CppFiles, ValidationFiles, BaseClassFiles
from bindings_files import BindingsFiles
from cmake_files import CMakeFiles
from base_files import BaseFile, BaseTemplateFile, BaseTxtFile
from util import global_variables, strFunctions
import shutil

directories = []


def generate_code_for(filename, overwrite=True):
    global_variables.running_tests = False
    parser = ParseXML.ParseXML(filename)
    ob = []
    if global_variables.code_returned == \
            global_variables.return_codes['success']:
        # catch a problem in the parsing
        try:
            ob = parser.parse_deviser_xml()
        except:
            global_variables.code_returned \
                = global_variables.return_codes['parsing error']
    if global_variables.code_returned == \
            global_variables.return_codes['success']:
        name = ob['name'.lower()]
        language = global_variables.language
        # TO DO REMEMBER TO REMOVE
        # try:
        if global_variables.is_package:
            generate_package_code(name, language, overwrite, ob)
        else:
            generate_other_library_code(name, language, overwrite, ob)
        # except:
        #     global_variables.code_returned \
        #         = global_variables.return_codes['unknown error - please report']


def generate_other_library_code(name, language, overwrite, ob):
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
    version = BaseFile.BaseFile('VERSION', 'txt')
    major = global_variables.library_version['major']
    minor = global_variables.library_version['minor']
    rev = global_variables.library_version['revision']
    version.write_line_verbatim('{0}.{1}.{2}\n'.format(major, minor, rev))
    version.close_file()
    readme = BaseTemplateFile.BaseTemplateFile('README.md', 'util')
    fileout = BaseFile.BaseFile('README', 'md')
    readme.copy_file_contents(fileout, 'README.md')
    fileout.close_file()
    lic = BaseFile.BaseFile('LICENSE', 'txt')
    lic.write_line_verbatim('LICENSE\n')
    lic.close_file()


def generate_package_code(name, language, overwrite, ob):
    if not create_dir_structure(name, language, overwrite):
        print('Problem encountered creating directories')
        print('Either delete what directory structure is there or')
        print('re run with overwrite=True')
        return False
    global_variables.populate_error_list(ob)
    generate_code_files(name, ob)
    generate_bindings_files(name, ob)
    generate_cmake_files(name, ob)
    generate_example_files(name, ob)

def generate_example_files(name, ob):
    this_dir = os.getcwd()
    os.chdir('examples')
    cmake = CMakeFiles.CMakeFiles(ob, this_dir, True)
    cmake.write_example_files()
    os.chdir(this_dir)

def generate_cmake_files(name, ob):
    os.chdir('{0}'.format(name))
    this_dir = os.getcwd()
    cmake = CMakeFiles.CMakeFiles(ob, this_dir, True)
    cmake.write_files()
    os.chdir(this_dir)


def generate_cmake_files_for_other(name, ob):
    os.chdir('{0}'.format(name))
    this_dir = os.getcwd()
    cmake = CMakeFiles.CMakeFiles(ob, this_dir, True)
    cmake.write_other_library_files()
    os.chdir(this_dir)


def generate_bindings_files(name, ob):
    this_dir = os.getcwd()
    csharp_dir = '{0}{1}src{1}bindings{1}csharp'.format(name, os.sep)
    java_dir = '{0}{1}src{1}bindings{1}java'.format(name, os.sep)
    javascript_dir = '{0}{1}src{1}bindings{1}javascript'.format(name, os.sep)
    perl_dir = '{0}{1}src{1}bindings{1}perl'.format(name, os.sep)
    php_dir = '{0}{1}src{1}bindings{1}php'.format(name, os.sep)
    python_dir = '{0}{1}src{1}bindings{1}python'.format(name, os.sep)
    r_dir = '{0}{1}src{1}bindings{1}r'.format(name, os.sep)
    ruby_dir = '{0}{1}src{1}bindings{1}ruby'.format(name, os.sep)
    swig_dir = '{0}{1}src{1}bindings{1}swig'.format(name, os.sep)

    os.chdir(csharp_dir)
    bind = BindingsFiles.BindingFiles(ob, 'csharp', True)
    bind.write_files()
    os.chdir(this_dir)

    os.chdir(java_dir)
    bind = BindingsFiles.BindingFiles(ob, 'java', True)
    bind.write_files()
    os.chdir(this_dir)

    os.chdir(javascript_dir)
    bind = BindingsFiles.BindingFiles(ob, 'javascript', True)
    bind.write_files()
    os.chdir(this_dir)

    os.chdir(perl_dir)
    bind = BindingsFiles.BindingFiles(ob, 'perl', True)
    bind.write_files()
    os.chdir(this_dir)

    os.chdir(php_dir)
    bind = BindingsFiles.BindingFiles(ob, 'php', True)
    bind.write_files()
    os.chdir(this_dir)

    os.chdir(python_dir)
    bind = BindingsFiles.BindingFiles(ob, 'python', True)
    bind.write_files()
    os.chdir(this_dir)

    os.chdir(r_dir)
    bind = BindingsFiles.BindingFiles(ob, 'r', True)
    bind.write_files()
    os.chdir(this_dir)

    os.chdir(ruby_dir)
    bind = BindingsFiles.BindingFiles(ob, 'ruby', True)
    bind.write_files()
    os.chdir(this_dir)

    os.chdir(swig_dir)
    bind = BindingsFiles.BindingFiles(ob, 'swig', True)
    bind.write_files()
    os.chdir(this_dir)


def generate_bindings_files_for_other(name, ob):
    this_dir = os.getcwd()
    csharp_dir = '{0}{1}src{1}bindings{1}csharp'.format(name, os.sep)
    java_dir = '{0}{1}src{1}bindings{1}java'.format(name, os.sep)
    javascript_dir = '{0}{1}src{1}bindings{1}javascript'.format(name, os.sep)
    perl_dir = '{0}{1}src{1}bindings{1}perl'.format(name, os.sep)
    php_dir = '{0}{1}src{1}bindings{1}php'.format(name, os.sep)
    python_dir = '{0}{1}src{1}bindings{1}python'.format(name, os.sep)
    r_dir = '{0}{1}src{1}bindings{1}r'.format(name, os.sep)
    ruby_dir = '{0}{1}src{1}bindings{1}ruby'.format(name, os.sep)
    swig_dir = '{0}{1}src{1}bindings{1}swig'.format(name, os.sep)

    os.chdir(java_dir)
    bind = BindingsFiles.BindingFiles(ob, 'java', True)
    bind.write_files()
    os.chdir(this_dir)

    # os.chdir(javascript_dir)
    # bind = BindingsFiles.BindingFiles(ob, 'javascript', True)
    # bind.write_files()
    # os.chdir(this_dir)
    #
    # os.chdir(perl_dir)
    # bind = BindingsFiles.BindingFiles(ob, 'perl', True)
    # bind.write_files()
    # os.chdir(this_dir)
    #
    # os.chdir(php_dir)
    # bind = BindingsFiles.BindingFiles(ob, 'php', True)
    # bind.write_files()
    # os.chdir(this_dir)
    #
    # os.chdir(python_dir)
    # bind = BindingsFiles.BindingFiles(ob, 'python', True)
    # bind.write_files()
    # os.chdir(this_dir)
    #
    # os.chdir(r_dir)
    # bind = BindingsFiles.BindingFiles(ob, 'r', True)
    # bind.write_files()
    # os.chdir(this_dir)
    #
    # os.chdir(ruby_dir)
    # bind = BindingsFiles.BindingFiles(ob, 'ruby', True)
    # bind.write_files()
    # os.chdir(this_dir)

    os.chdir(swig_dir)
    bind = BindingsFiles.BindingFiles(ob, 'swig', True)
    bind.write_swig_library_files()
    os.chdir(this_dir)

    os.chdir(csharp_dir)
    bind = BindingsFiles.BindingFiles(ob, 'csharp', True)
    bind.write_files()
    os.chdir(this_dir)


def generate_code_files(name, ob):
    this_dir = os.getcwd()
    language = global_variables.language
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
    for add_file in global_variables.add_implementation:
        shutil.copy(add_file, os.getcwd())
    for add_file in global_variables.add_declaration:
        shutil.copy(add_file, os.getcwd())

    os.chdir(this_dir)


def generate_other_library_code_files(name, ob):
    this_dir = os.getcwd()
    language = global_variables.language
    prefix = global_variables.prefix
    main_dir = '{0}{1}src{1}{2}'.format(name, os.sep, language)
    common_dir = '{0}{1}src{1}{2}{1}common'.format(name, os.sep, language)
    binding_dir = '{0}{1}src{1}bindings'.format(name, os.sep)
    os.chdir(main_dir)
# take these lines out to write without prefix
    for working_class in ob['baseElements']:
        strFunctions.prefix_classes(working_class)
    # this populates the error structures
    valid = ValidationFiles.ValidationFiles(ob, True)
    for working_class in ob['baseElements']:
        if working_class['name'] == global_variables.document_class:
            working_class['document'] = True
        all_files = CppFiles.CppFiles(working_class, True)
        all_files.write_files()
    base_files = BaseClassFiles.BaseClassFiles(prefix, ob['baseElements'], True)
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
    if global_variables.is_package:
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
    if os.path.exists(name):
        if skip_existing:
            done = True
        else:
            print('some parts of the directory structure exist and ' \
                  'others are missing')
            print('terminating as we are not sure what is going on')
            done = False
    else:
        os.mkdir(name)
        print('creating dir {0}'.format(name))
        done = True
    return done


def main(args):
    if len(args) != 2:
        global_variables.code_returned = \
            global_variables.return_codes['missing function argument']
        print ('Usage: generateCode.py xmlfile')
    else:
        generate_code_for(args[1])
    if global_variables.code_returned == \
            global_variables.return_codes['success']:
        print('code successfully written')
    else:
        print('writing code failed')

    return global_variables.code_returned

if __name__ == '__main__':
    main(sys.argv)
