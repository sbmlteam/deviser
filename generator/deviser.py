#!/usr/bin/env python
#
# @file    deviser.py
# @brief   command line tool for invoking the deviser scripts
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2015 by the California Institute of Technology
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
#


import sys

from util import generateLatex, generateCode
from legacy import run


def generatePackageFor(filename):
    """This function generates a libSBML extension for the given filename"""
    generateCode.generate_code_for(filename, True)


def generateLegacyPackageFor(filename):
    """This function generates a libSBML extension for the given filename
       using the legacy code"""
    run.generatePackageForFile(filename)


def generateLaTeXFor(filename):
    """This function generates a LaTeX scaffold for the given filename"""
    generateLatex.generateLatexFor(filename)


def main(args):
    """Usage: deviser  [--generate | --latex ] input-filename
       This program will use a Deviser xml file, and generate either a C++
       libSBML extionsion for it, or generate a LaTeX scaffold for its
       specification.
    """

    if len(args) != 3:
        print(main.__doc__)
        sys.exit(1)

    operation = args[1].lower()
    filename = args[2]
  
    if operation == '--legacy' or operation == '-gl':
        generateLegacyPackageFor(filename)
    if operation == '--generate' or operation == '-g':
        generatePackageFor(filename)
    elif operation == '--latex' or operation == '-l':
        generateLaTeXFor(filename)
    else:
        print(main.__doc__)
        sys.exit(1)

    return 0
  
if __name__ == '__main__':
    main(sys.argv)
