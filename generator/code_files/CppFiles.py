#!/usr/bin/env python
#
# @file    CppFiles.py
# @brief   class for generating cpp files
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

import CppHeaderFile
import CppCodeFile
from util import strFunctions, query


class CppFiles():
    """Class for all Cpp files"""

    def __init__(self, class_object):
        # members from object
        self.class_object = class_object

    def write_files(self):
        working_class = self.class_object
        working_class['is_list_of'] = False
        working_class['sid_refs'] = \
            query.get_sid_refs(self.class_object['attribs'])
        working_class['unit_sid_refs'] = \
            query.get_sid_refs(self.class_object['attribs'], unit=True)
        header = CppHeaderFile.CppHeaderFile(working_class)
        header.write_file()
        header.close_file()
        code = CppCodeFile.CppCodeFile(working_class)
        code.write_file()
        code.close_file()
        if self.class_object['hasListOf']:
            lo_working_class = self.create_list_of_description()
            lo_header = CppHeaderFile.CppHeaderFile(lo_working_class)
            lo_header.write_file()
            lo_header.close_file()
            lo_code = CppCodeFile.CppCodeFile(lo_working_class)
            lo_code.write_file()
            lo_code.close_file()

    def create_list_of_description(self):
        lo_name = strFunctions.list_of_name(self.class_object['name'])
        descrip = self.class_object
        descrip['is_list_of'] = True
        descrip['attribs'] = self.class_object['lo_attribs']
        descrip['child_base_class'] = self.class_object['baseClass']
        descrip['baseClass'] = 'ListOf'
        descrip['list_of_name'] = lo_name
        descrip['lo_child'] = self.class_object['name']
        descrip['name'] = lo_name
        return descrip