#!/usr/bin/env python
#
# @file    generateTest.py
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

from code_files import CppTestFile
from generateExamples import generate_example_for  # As almost identical anyway

from util import global_variables as gv

"""Code to generate tests"""


def generate_example_code(ob):
    '''
    Generate the example code for a pkg_code object
    (big dictionary structure of information from an XML file).

    :param ob: the pkg_code object
    :return: returns nothing
    '''
    ex = CppTestFile.CppTestFile(ob)
    ex.write_file()
    ex.close_file()


def main(args):
    """
    Main function. Checks correct number of args and generates example.

    :param args: the command-line arguments
    :returns: the `global_variable.code_returned` value
    """
    if len(args) != 2:
        gv.code_returned = gv.return_codes['missing function argument']
        print('Usage: generateCode.py xmlfile')
    else:
        generate_example_for(args[1], generate_example_code, is_package=False)
    if gv.code_returned == gv.return_codes['success']:
        print('code successfully written')
    else:
        print('writing code failed')

    return gv.code_returned


if __name__ == '__main__':
    main(sys.argv)
