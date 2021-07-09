#!/usr/bin/env python
#
# @file    generateXML.py
# @brief   function for generating XML examples
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

import os
import sys

from ..parseXML import ParseXML
from ..util import global_variables as gv
from ..validation import ValidationXMLFiles

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/..')


def generate_xml_for(filename):  # , overwrite=True):
    """
    Parse XML input file, then write XML output file.

    :param filename: the XML input file
    :return: returns nothing
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
        # try:
        if gv.is_package:
            generate_example_xml(ob)
        # except Exception:
        #  gv.code_returned = gv.return_codes['unknown error - please report']


def generate_example_xml(ob):
    """
    Wrapper function to invoke the main XML Validation constructor.

    :param ob: big dictionary object structure obtained from input XML file.
    :returns: returns nothing.
    """
    ex = ValidationXMLFiles.ValidationXMLFiles(ob)
    ex.write_all_files()


def main(args):
    """
    Checks correct number of arguments and then invokes XML code.
    """
    if len(args) != 2:
        gv.code_returned = gv.return_codes['missing function argument']
        print('Usage: generateXML.py xmlfile')
    else:
        generate_xml_for(args[1])
    if gv.code_returned == gv.return_codes['success']:
        print('code successfully written')
    else:
        print('writing code failed')

    return gv.code_returned


if __name__ == '__main__':
    main(sys.argv)
