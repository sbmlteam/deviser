#!/usr/bin/env python
#
# @file    generateRNG.py
# @brief   function for generating RNG schema
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

"""Function for generating RNG schema"""

import sys

from ..parseXML import ParseXML
from ..util import global_variables as gv
from ..validation import RNGSchemaFiles


def generate_rng_for(filename):  # , overwrite=True):
    """
    Parse XML file and then invokes RNG file generation code.

    :param filename: the XML file to parse
    :return: returns nothing.
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
            generate_rng(ob)
        # except Exception :
        # gv.code_returned = gv.return_codes['unknown error - please report']


def generate_rng(ob):
    """
    Wrapper function. Creates RNG Schema file.

    :param ob: the big dictionary object produced by XML file parsing.
    :return: returns nothing.
    """
    ex = RNGSchemaFiles.RNGSchemaFiles(ob)
    ex.write_file()


def main(args):
    """
    Checks correct number of arguments and then invokes RNG code.
    """
    if len(args) != 2:
        gv.code_returned = gv.return_codes['incorrect number function arguments']
        print('Usage: generateRNG.py xmlfile')
    else:
        generate_rng_for(args[1])
    if gv.code_returned == gv.return_codes['success']:
        print('code successfully written')
    else:
        print('writing rng failed')

    return gv.code_returned


if __name__ == '__main__':
    main(sys.argv)
