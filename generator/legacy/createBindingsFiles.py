#!/usr/bin/env python
#
# @file    createBindingsFiles.py
# @brief   creates files for the bindings
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
import writeBindingsFiles

	
def writeCSharpFiles(name, plugins, classes):
	capName = name.upper()
	codeName = 'local-downcast-extension-' + name + '.i'
	fileOut = open(codeName, 'w')
	writeBindingsFiles.writeCSharpExt(fileOut, name)
	codeName1 = 'local-downcast-namespaces-' + name + '.i'
	fileOut1 = open(codeName1, 'w')
	writeBindingsFiles.writeCSharpNS(fileOut1, name)
	codeName2 = 'local-packages-' + name + '.i'
	fileOut2 = open(codeName2, 'w')
	fileHeaders.addFilename(fileOut2, codeName2, name)
	fileHeaders.addLicence(fileOut2)
	writeBindingsFiles.writeCSharp(fileOut2, name, plugins, classes)

def writeJavaFiles(name, plugins, classes):
	capName = name.upper()
	codeName = 'local-downcast-extension-' + name + '.i'
	fileOut = open(codeName, 'w')
	writeBindingsFiles.writeJavaExt(fileOut, name)
	codeName1 = 'local-downcast-namespaces-' + name + '.i'
	fileOut1 = open(codeName1, 'w')
	writeBindingsFiles.writeJavaNS(fileOut1, name)
	codeName2 = 'local-packages-' + name + '.i'
	fileOut2 = open(codeName2, 'w')
	fileHeaders.addFilename(fileOut2, codeName2, name)
	fileHeaders.addLicence(fileOut2)
	writeBindingsFiles.writeJava(fileOut2, name, plugins, classes)
	
def writeGenericFiles(name, plugins, classes):
	capName = name.upper()
	codeName = 'local-downcast-extension-' + name + '.cpp'
	fileOut = open(codeName, 'w')
	writeBindingsFiles.writeExt(fileOut, name)
	codeName1 = 'local-downcast-namespaces-' + name + '.cpp'
	fileOut1 = open(codeName1, 'w')
	writeBindingsFiles.writeNS(fileOut1, name)
	codeName2 = 'local-downcast-packages-' + name + '.cpp'
	fileOut2 = open(codeName2, 'w')
	writeBindingsFiles.writePkg(fileOut2, name, classes)
	codeName3 = 'local-downcast-plugins-' + name + '.cpp'
	fileOut3 = open(codeName3, 'w')
	writeBindingsFiles.writePlugins(fileOut3, name, plugins)
	codeName4 = 'local-' + name + '.i'
	fileOut4 = open(codeName4, 'w')
	writeBindingsFiles.writeLocal(fileOut4, name, classes)
	
def writeSwigFiles(name, plugins, classes):
	capName = name.upper()
	codeName = name + '-package.h'
	fileOut = open(codeName, 'w')
	writeBindingsFiles.writeSwigHeader(fileOut, name, plugins, classes)
	codeName1 = name + '-package.i'
	fileOut1 = open(codeName1, 'w')
	writeBindingsFiles.writeSwig(fileOut1, name, plugins, classes)
	
def main(package):
	nameOfPackage = package['name']
	name = nameOfPackage.lower()
	plugins = package['plugins']
	classes = package['sbmlElements']
	os.chdir('./csharp')
	writeCSharpFiles(name, plugins, classes)
	os.chdir('../java')
	writeJavaFiles(name, plugins, classes)
	os.chdir('../javascript')
	writeGenericFiles(name, plugins, classes)
	os.chdir('../perl')
	writeGenericFiles(name, plugins, classes)
	os.chdir('../php')
	writeGenericFiles(name, plugins, classes)
	os.chdir('../python')
	writeGenericFiles(name, plugins, classes)
	os.chdir('../r')
	writeGenericFiles(name, plugins, classes)
	os.chdir('../ruby')
	writeGenericFiles(name, plugins, classes)
	os.chdir('../swig')
	writeSwigFiles(name, plugins, classes)
