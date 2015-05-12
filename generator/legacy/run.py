#!/usr/bin/env python
#
# @file    run.py
# @brief   invokes the code generation
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
import writeCode
import writeHeader
import createExtensionFiles
import createNewPackage
import createCommonFiles
import createCMakeFiles
import createRegisterFiles
import createBindingsFiles
import createArchiveFile
import createValidatorFiles
import createPackageFromXml
import createDirStruct

def getPackageDefinitionFromArgs(args):
  packageDefn = None
  name = args[1]
  if len(args) > 2:
    packageDefn = createPackageFromXml.parseDeviserXML(args[2])
  else:
    packageDefn = createNewPackage.createPackage(name)
  if packageDefn == None:
    print 'package definition for {0} not available'.format(name)
    sys.exit(0)
  return packageDefn

def getPackageDefinitionFromFile(filename):
  return createPackageFromXml.parseDeviserXML(filename)

def generatePackageForFile(filename):
  packageDefn = getPackageDefinitionFromFile(filename)
  generatePackageForDefinition(packageDefn)
  
def generatePackageForDefinition(packageDefn):
  name = packageDefn['name'].lower()
  thisDir = os.getcwd()
  extDir = './' + name + '/src/sbml/packages/' + name + '/extension'
  sbmlDir = './' + name + '/src/sbml/packages/' + name + '/sbml'
  cmnDir = './' + name + '/src/sbml/packages/' + name + '/common'
  valDir = './' + name + '/src/sbml/packages/' + name + '/validator'
  packDir = './' + name + '/src/sbml/packages'
  bindDir = './' + name + '/src/bindings'
  #check directories exist
  
  if os.path.exists(extDir) == False:
    createDirStruct.createDirectories(name)
    #print 'directory structure for {0} not available - please run createDirStruct'.format(name)
    #sys.exit(0)
    
  os.chdir(extDir)
  createExtensionFiles.main(packageDefn)
  os.chdir(thisDir)
  os.chdir(sbmlDir)
  elements = packageDefn['sbmlElements']
  for i in range (0, len(elements)):
    element = elements[i]
    writeCode.createCode(element)
    writeHeader.createHeader(element)
  os.chdir(thisDir)
  os.chdir(cmnDir)
  createCommonFiles.main(packageDefn)
  os.chdir(thisDir)
  os.chdir(valDir)
  createValidatorFiles.main(packageDefn)
  os.chdir(thisDir)
  createCMakeFiles.main(packageDefn)
  os.chdir(thisDir)
  os.chdir(packDir)
  createRegisterFiles.main(name)
  os.chdir(thisDir)
  os.chdir(bindDir)
  createBindingsFiles.main(packageDefn)
  os.chdir(thisDir)
  createArchiveFile.main(name)
  
def main(args):
  """Usage: run.py name <fileName>"""
  if len(args) < 2:
    print (main.__doc__)
  else:
    packageDefn = getPackageDefinitionFromArgs(args)
    generatePackageForDefinition(packageDefn)
  return 0

if __name__ == '__main__':
  main(sys.argv)  
