#!/usr/bin/env python
#
# @file   createSBMLFiles.py
# @brief  Create the sbml files
# @author Sarah Keating
#

import sys
import createDirStruct
import writeCode
import writeHeader

if len(sys.argv) != 1:
  print 'Usage: createSBMLFiles.py'
else:
  element = createNewElementDictObj.createCompDeletion()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createCompSubModel()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createSBaseRef()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createCompPort()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createCompReplacedE()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createCompReplacedBy()
  writeCode.createCode(element)
  writeHeader.createHeader(element)
  element = createNewElementDictObj.createCompExtModDef()
  writeCode.createCode(element)
  writeHeader.createHeader(element)

  
  
  # element = createNewElementDictObj.createQualInput()
  # writeCode.createCode(element)
  # writeHeader.createHeader(element)
  # element = createNewElementDictObj.createQualOutput()
  # writeCode.createCode(element)
  # writeHeader.createHeader(element)
  # element = createNewElementDictObj.createQualDefaultTerm()
  # writeCode.createCode(element)
  # writeHeader.createHeader(element)
