#!/usr/bin/env python
#
# @file   createCMakeFiles.py
# @brief  Create teh directory structure for package code
# @author Sarah Keating
#

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
