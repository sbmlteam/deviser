#!/usr/bin/env python
#
# @file    generateLatex.py
# @brief   function for generating all latex files
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

"""Function for generating all latex files"""

import os
import sys

from . import global_variables as gv
from spec_files import TexBodySyntaxFile, TexValidationRulesFile, TexMacrosFile
from ..parseXML import ParseXML


def generateLatexFor(filename):

    # Look to see if figures are present:
    gv.deviser_file = filename
    gv.current_dir = os.getcwd()
    figs_dir = '{0}{1}{2}'.format(gv.current_dir, os.sep, 'figures')
    if os.path.exists(figs_dir):
        gv.figures_present = True

    # Now get info from XML file.
    parser = ParseXML.ParseXML(filename)
    ob = dict()
    if gv.code_returned == gv.return_codes['success']:
        # catch a problem in the parsing
        try:
            ob = parser.parse_deviser_xml()
        except Exception:
            gv.code_returned = gv.return_codes['parsing error']

    if gv.code_returned == gv.return_codes['success']:
        # File writing:
        try:
            ff = TexValidationRulesFile.TexValidationRulesFile(ob)
            ff.write_file()
            ff.close_file()
            body = TexBodySyntaxFile.TexBodySyntaxFile(ob)
            body.write_file()
            body.close_file()
            macros = TexMacrosFile.TexMacrosFile(ob)
            macros.write_file()
            macros.close_file()
        except Exception:
            gv.code_returned = gv.return_codes['unknown error - please report']


def main(args):
    """Checks correct number of args, then invokes main generate function."""
    if len(args) != 2:
        print('Usage: generateLatex.py xmlfile')
    else:
        generateLatexFor(args[1])


if __name__ == '__main__':
    main(sys.argv)
