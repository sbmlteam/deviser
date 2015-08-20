#!/usr/bin/env python
#
# @file    generateCode.py
# @brief   function for generating all code files
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2014 by the California Institute of Technology
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
from code_files import ExtensionFiles, CppFiles

directories = []


def generate_code_for(filename, overwrite=True):
    this_dir = os.getcwd()
    parser = ParseXML.ParseXML(filename)
    ob = parser.parse_deviser_xml()
    name = ob['name'.lower()]
    language = 'sbml'
    if not create_dir_structure(name, language, overwrite):
        print'Problem encountered creating directories'
        print('Either delete what directory structure is there or')
        print('re run with overwrite=True')
        return False
    common_dir = '{0}{1}src{1}{2}{1}packages{1}{0}{1}common'.format(name,
                                                                    os.sep,
                                                                    language)
    os.chdir(common_dir)
    ext = ExtensionFiles.ExtensionFiles(ob, 'types', True)
    ext.write_files()
    ext = ExtensionFiles.ExtensionFiles(ob, 'fwd', True)
    ext.write_files()
    os.chdir(this_dir)
    extension_dir = '{0}{1}src{1}{2}{1}packages{1}{0}{1}' \
                    'extension'.format(name, os.sep, language)
    os.chdir(extension_dir)
    ext = ExtensionFiles.ExtensionFiles(ob, '', True)
    ext.write_files()
    for i in range(0, len(ob['plugins'])+1):
        ext.write_plugin_files(i)
    os.chdir(this_dir)
    sbml_dir = '{0}{1}src{1}{2}{1}packages{1}{0}{1}{2}'.format(name, os.sep,
                                                               language)
    os.chdir(sbml_dir)
    for working_class in ob['sbmlElements']:
        all_files = CppFiles.CppFiles(working_class, True)
        all_files.write_files()
    os.chdir(this_dir)


def populate_directories(name, lang):
    global directories
    sep = os.sep
    directories = ['{}'.format(name),
                   '{}{}examples'.format(name, sep),
                   '{}{}src'.format(name, sep),
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


def create_dir_structure(pkgname, lang, overwrite):
    populate_directories(pkgname, lang)
    print 'creating directory structure for {0}'.format(pkgname)
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
            print 'some parts of the directory structure exist and ' \
                  'others are missing'
            print('terminating as we are not sure what is going on')
            done = False
    else:
        os.mkdir(name)
        print 'creating dir {0}'.format(name)
        done = True
    return done


def main(args):
    success = False
    if len(args) != 2:
        print ('Usage: generateCode.py xmlfile')
    else:
        success = generate_code_for(args[1])
    if success:
        print('code successfully written')
    else:
        print('writing code failed')

if __name__ == '__main__':
    main(sys.argv)
