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

from code_files import CppExampleFile
from parseXML import ParseXML
from util import global_variables as gv

"""Code used to generate the examples."""


def generate_example_for(filename):  # , overwrite=True):
    """
    Extract data structure from an XML file and write
    example code with it.

    :param filename: the XML file we are using
    :returns: returns nothing, but does update gv.code_returned.
    """
    gv.running_tests = False
    parser = ParseXML.ParseXML(filename)
    ob = dict()
    if gv.code_returned == gv.return_codes['success']:
        # catch a problem in the parsing
        try:
            ob = parser.parse_deviser_xml()
        except Exception:
            gv.code_returned = gv.return_codes['parsing error']
    if gv.code_returned == gv.return_codes['success']:
        # Next line does nothing, should be name = ob['name'].lower() anyway?
        # name = ob['name'.lower()]
        try:
            if gv.is_package:
                generate_example_code(ob)
        except Exception:
            gv.code_returned = gv.return_codes['unknown error - please report']


def generate_example_code(ob):
    '''
    Generate the example code for a pkg_code object
    (big dictionary structure of information from an XML file).

    :param ob: the pkg_code object
    :return: returns nothing
    '''
    ex = CppExampleFile.CppExampleFile(ob)
    ex.write_file()
    ex.close_file()


def main(args):
    """
    Main function. Check correct number of args and generates example.

    :param args: the command-line arguments
    :returns: the `global_variable.code_returned` value
    """
    if len(args) != 2:
        gv.code_returned = gv.return_codes['missing function argument']
        print('Usage: generateCode.py xmlfile')
    else:
        generate_example_for(args[1])
    if gv.code_returned == gv.return_codes['success']:
        print('code successfully written')
    else:
        print('writing code failed')

    return gv.code_returned


if __name__ == '__main__':
    main(sys.argv)
