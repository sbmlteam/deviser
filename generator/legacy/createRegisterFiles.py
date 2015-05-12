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
