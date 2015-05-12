#!/usr/bin/env python
#
# @file   createDirStruct.py
# @brief  Create teh directory structure for package code
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

if len(sys.argv) < 2:
  print 'Usage: run.py name <fileName>'
else:
  name = sys.argv[1]
  packageDefn = None
  if len(sys.argv) > 2:
    packageDefn = createPackageFromXml.parseDeviserXML(sys.argv[2])
  else:
    packageDefn = createNewPackage.createPackage(name)
  if packageDefn == None:
    print 'package definition for {0} not available'.format(name)
    sys.exit(0)
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

