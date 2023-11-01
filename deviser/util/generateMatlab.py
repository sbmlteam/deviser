#!/usr/bin/env python
#
# @file    generateExamples.py
# @brief   function for generating code examples
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

from deviser.base_files import BaseMatlabFile
from deviser.parseXML import ParseXML
from deviser.util import global_variables


def generate_matlab_for(filename, overwrite=True):
    global_variables.running_tests = False
    parser = ParseXML.ParseXML(filename)
    ob = dict()
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
        try:
            if global_variables.is_package:
                generate_matlab_code(name, ob)
        except:
            global_variables.code_returned \
                = global_variables.return_codes['unknown error - please report']


def generate_matlab_code(name, ob):
    filetypes = ['sf', 'dv', 'vt']
    for t in filetypes:
        ex = BaseMatlabFile.BaseMatlabFile(name, ob, t)
        ex.write_file()
        ex.close_file()


def main(args):
    if len(args) != 2:
        global_variables.code_returned = \
            global_variables.return_codes['missing function argument']
        print ('Usage: generateCode.py xmlfile')
    else:
        generate_matlab_for(args[1])
    if global_variables.code_returned == \
            global_variables.return_codes['success']:
        print('code successfully written')
    else:
        print('writing code failed')

    return global_variables.code_returned

if __name__ == '__main__':
    main(sys.argv)
