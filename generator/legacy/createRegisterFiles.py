#!/usr/bin/env python
#
# @file    createRegisterFiles.py
# @brief   creates the register files
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
import fileHeaders
import strFunctions

	
def writeCode(name):
	capName = name.upper()
	codeName = name + '-register.cxx'
	fileOut = open(codeName, 'w')
	fileHeaders.addFilename(fileOut, codeName, name)
	fileHeaders.addLicence(fileOut)
	fileOut.write('\n')
	fileOut.write('#ifdef USE_{0}\n'.format(capName))
	fileOut.write('  {0}Extension::init();\n'.format(strFunctions.cap(name)))
	fileOut.write('#endif\n')
	
	
def writeHeader(name):
	capName = name.upper()
	codeName = name + '-register.h'
	fileOut = open(codeName, 'w')
	fileHeaders.addFilename(fileOut, codeName, name)
	fileHeaders.addLicence(fileOut)
	fileOut.write('\n')
	fileOut.write('#ifdef USE_{0}\n'.format(capName))
	fileOut.write('  #include <sbml/packages/{0}/extension/{1}Extension.h>\n'.format(name, strFunctions.cap(name)))
	fileOut.write('#endif\n\n')
	
def main(name):
	writeHeader(name)
	writeCode(name)
