#!/usr/bin/env python
#
# @file    BindingsFiles.py
# @brief   class for generating the bindings files
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

from . import BaseBindingsFiles
from . import DowncastExtensionFile
from . import DowncastNamespaceFile
from . import DowncastPackagesFile
from . import DowncastPluginsFile
from . import NativeSwigFile
from util import global_variables


class BindingFiles():
    """Class for all Bindings files"""

    def __init__(self, pkg_object, binding, verbose=False):
        # # members from object
        self.package = pkg_object['name']
        self.verbose = verbose
        self.binding = binding
        self.language = global_variables.language
        self.elements = pkg_object['baseElements']
        self.plugins = pkg_object['plugins']
        self.lv_info = pkg_object['lv_info']

    #########################################################################
    # package files

    def write_downcast_extension(self):
        if not global_variables.is_package:
            return
        name = 'local-downcast-extension-{0}'.format(self.package)
        ext = DowncastExtensionFile.DowncastExtensionFile(name,
                                                          self.package,
                                                          self.binding)
        if self.verbose:
            print('Writing file {0}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()

    def write_downcast_namespace(self):
        if not global_variables.is_package:
            return
        name = 'local-downcast-namespaces-{0}'.format(self.package)
        ext = DowncastNamespaceFile.DowncastNamespaceFile(name,
                                                          self.package,
                                                          self.binding,
                                                          self.lv_info)
        if self.verbose:
            print('Writing file {0}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()

    def write_downcast_packages(self):
        if not global_variables.is_package:
            return
        if self.binding == 'csharp' or self.binding == 'java':
            name = 'local-packages-{0}'.format(self.package)
        else:
            name = 'local-downcast-packages-{0}'.format(self.package)
        ext = DowncastPackagesFile.DowncastPackagesFile(name,
                                                        self.package,
                                                        self.binding,
                                                        self.elements,
                                                        self.plugins)
        if self.verbose and ext.fileout:
            print('Writing file {0}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()

    def write_downcast_plugins(self):
        if not global_variables.is_package:
            return
        name = 'local-downcast-plugins-{0}'.format(self.package)
        ext = DowncastPluginsFile.DowncastPluginsFile(name,
                                                      self.package,
                                                      self.binding,
                                                      self.plugins)
        if self.verbose and ext.fileout:
            print('Writing file {0}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()

    #########################################################################
    # local files

    def write_local(self):
        if global_variables.is_package:
            self.write_local_package_files()
        else:
            self.write_local_library_files()

    def write_local_package_files(self):
        if self.binding == 'csharp' or self.binding == 'java':
            return
        else:
            name = 'local-{0}'.format(self.package)
        ext = DowncastPackagesFile.DowncastPackagesFile(name,
                                                        self.package,
                                                        self.binding,
                                                        self.elements,
                                                        self.plugins,
                                                        True)
        if self.verbose and ext.fileout:
            print('Writing file {0}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()

    def write_local_library_files(self):
        base_files = BaseBindingsFiles.BaseBindingsFiles(self.elements,
                                                         self.binding, True)
        base_files.write_files()

    ########################################################################
    # write files in the swig directory

    def write_swig_files(self):
        if global_variables.is_package:
            self.write_swig_package_files()
        else:
            self.write_swig_library_files()

    def write_swig_package_files(self):
        name = '{0}-package'.format(self.package)
        ext = NativeSwigFile.NativeSwigFile(name, self.package, self.elements,
                                            self.plugins, is_header=True)
        if self.verbose and ext.fileout:
            print('Writing file {0}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()

        name = '{0}-package'.format(self.package)
        ext = NativeSwigFile.NativeSwigFile(name, self.package, self.elements,
                                            self.plugins, is_header=False)
        if self.verbose and ext.fileout:
            print('Writing file {0}'.format(ext.fileout.filename))
        ext.write_file()
        ext.close_file()

    def write_swig_library_files(self):
        base_files = BaseBindingsFiles.BaseBindingsFiles(self.elements,
                                                         'swig', True)
        base_files.write_files()

    ########################################################################
    # other library files
    def write_cmake_file(self):
        if global_variables.is_package:
            return
        base_files = BaseBindingsFiles.BaseBindingsFiles(self.elements,
                                                         self.binding, True)
        base_files.write_files()

    ########################################################################

    def write_files(self):
        if self.binding != 'swig':
            self.write_downcast_extension()
            self.write_downcast_namespace()
            self.write_downcast_packages()
            self.write_downcast_plugins()
            self.write_local()
        else:
            self.write_swig_files()
