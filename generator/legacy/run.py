#!/usr/bin/env python
#
# @file   createDirStruct.py
# @brief  Create the directory structure for package code
# @author Sarah Keating
#

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
