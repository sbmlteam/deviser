#!/usr/bin/env python
#
# @file   createValidatorFiles.py
# @brief  Create the validator src files files
# @author Sarah Keating
#

import sys, os
import fileHeaders
import generalFunctions

def replaceTags(line, pkg):
  if '$PKGNAME' in line:
    line = line.replace('$PKGNAME', pkg)
  if '$LOWERPKGNAME' in line:
    line = line.replace('$LOWERPKGNAME', pkg.lower())
  return line
  
def createValidatorHeader(pkg):
  inputFile = os.path.dirname(__file__)  + '/templateValidHead.txt' 
  headerName = pkg + 'Validator.h'
  header = open(headerName, 'w')
  nameOfElement = pkg + 'Validator'
  fileHeaders.addFilename(header, headerName, nameOfElement)
  fileHeaders.addLicence(header)
  header.write('\n#ifndef {0}Validator__H\n'.format(pkg))
  header.write('#define {0}Validator__H\n\n\n'.format(pkg))
  header.write('#ifdef __cplusplus\n\n\n')
  generalFunctions.writeInternalStart(header)
  header.write('#include <list>\n')
  header.write('#include <string>\n')
  generalFunctions.writeInternalEnd(header)
  input = open(inputFile, 'r')
  for line in input:
    if line[0:13] != 'TEMPLATE_STOP':
      line = replaceTags(line, pkg)
      header.write(line)
    else:
      break
  header.write('#endif  /* __cplusplus*/\n')  
  header.write('#endif  /* {0}Validator__H */\n'.format(pkg))
  input.close()
  header.close()

def createValidatorFile(pkg, classes):
  inputFile = os.path.dirname(__file__)  + '/templateValidCPP.txt' 
  fileName = pkg + 'Validator.cpp'
  output = open(fileName, 'w')
  nameOfElement = pkg + 'Validator'
  fileHeaders.addFilename(output, fileName, nameOfElement)
  fileHeaders.addLicence(output)
  output.write('#include <sbml/validator/VConstraint.h>\n\n')
  output.write('#include <sbml/packages/{0}/common/{1}ExtensionTypes.h>\n'.format(pkg.lower(), pkg))
  output.write('#include <sbml/packages/{0}/validator/{1}Validator.h>\n\n'.format(pkg.lower(), pkg))
  generalFunctions.writeInternalStart(output)
  output.write('using namespace std;\n\n')
  generalFunctions.writeInternalEnd(output)
  output.write('LIBSBML_CPP_NAMESPACE_BEGIN\n\n')
  input = open(inputFile, 'r')
  for line in input:
    if line[0:13] != 'TEMPLATE_STOP':
      line = replaceTags(line, pkg)
      output.write(line)
    else:
      break
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      output.write('  ConstraintSet<{0}>      m{0};\n'.format(classes[i]['name']))
  for line in input:
    if line[0:13] != 'TEMPLATE_STOP':
      line = replaceTags(line, pkg)
      output.write(line)
    else:
      break
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      output.write('  if (dynamic_cast< TConstraint<{0}>* >(c) != NULL)\n'.format(classes[i]['name']))
      output.write('  {\n')
      output.write('    m{0}.add( static_cast< TConstraint<{0}>* >(c) );\n'.format(classes[i]['name']))
      output.write('    return;\n  }\n\n')
  for line in input:
    if line[0:13] != 'TEMPLATE_STOP':
      line = replaceTags(line, pkg)
      output.write(line)
    else:
      break
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      output.write('  bool visit (const {0} &x)\n'.format(classes[i]['name']))
      output.write('  {\n')
      output.write('    v.m{0}Constraints->m{1}.applyTo(m, x);\n'.format(pkg, classes[i]['name']))
      output.write('    return !v.m{0}Constraints->m{1}.empty();\n'.format(pkg, classes[i]['name']))
      output.write('  }\n\n')
  output.write('  virtual bool visit(const SBase &x)\n')
  output.write('  {\n')
  output.write('    if (&x == NULL || x.getPackageName() != "{0}")\n'.format(pkg.lower()))
  output.write('    {\n      return SBMLVisitor::visit(x);\n    }\n\n')
  output.write('    int code = x.getTypeCode();\n\n')
  output.write('    const ListOf* list = dynamic_cast<const ListOf*>(&x);\n\n')
  output.write('    if (list != NULL)\n')
  output.write('    {\n')
  output.write('      return SBMLVisitor::visit(x);\n')
  output.write('    }\n')
  output.write('    else\n')
  output.write('    {\n')
  order = 0
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      if order == 0:
        output.write('      if (code == {0})\n'.format(classes[i]['typecode']))
        order = order + 1
      else:
        output.write('      else if (code == {0})\n'.format(classes[i]['typecode']))
      output.write('      {\n')
      output.write('        return visit((const {0}&)x);\n'.format(classes[i]['name']))
      output.write('      }\n')
  for line in input:
    if line[0:13] != 'TEMPLATE_STOP':
      line = replaceTags(line, pkg)
      output.write(line)
    else:
      break
  input.close()
  output.close()

def writeErrors(header, table, spec, element, pkg, offset, classes):
    writeErrorStart(header, element)
    writeErrorTableStart(table, element, pkg)
    writeGeneralErrors(header, table, spec, pkg, offset)

    writeErrorEnd(header, element, pkg)
    writeErrorTableEnd(table, element)

def writeGeneralErrors(header, table, spec, pkg, offset):
    errorNum = offset+10100
    header.write('  {0}UnknownError                  = {1}\n\n'.format(pkg, errorNum));
    table.write('  //{0}\n'.format(errorNum));
    table.write('  {')
    table.write('  {0}UnknownError,\n'.format(pkg));
    table.write('    "Unknown error from {0}",\n'.format(pkg.lower()))
    table.write('    LIBSBML_CAT_GENERAL_CONSISTENCY,\n')
    table.write('    LIBSBML_SEV_ERROR,\n')
    table.write('    "Unknown error from {0}",\n'.format(pkg.lower()))
    table.write('    { " "\n')
    table.write('    }\n')
    table.write('  },\n')

    errorNum = errorNum+1
    header.write('  {0}NSUndeclared                  = {1}\n\n\n'.format(pkg, errorNum));
    table.write('  //{0}\n'.format(errorNum));
    table.write('  {')
    table.write('  {0}NSUndeclared,\n'.format(pkg));
    table.write('    \"The {0} ns is not correctly declared\",\n'.format(pkg.lower()))
    table.write('    LIBSBML_CAT_GENERAL_CONSISTENCY,\n')
    table.write('    LIBSBML_SEV_ERROR,\n')
    table.write('   To conform to Version 1 of the {0}\n'.format(pkg))
    table.write('    { " "\n')
    table.write('    }\n')
    table.write('  },\n\n')


def writeErrorStart(fileOut, element):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('\nLIBSBML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\nBEGIN_C_DECLS\n')
  fileOut.write('\n\n');
  fileOut.write('typedef enum\n')
  fileOut.write('{\n')

def writeErrorEnd(fileOut, element, pkg):
  fileOut.write('}')
  fileOut.write('  {0}SBMLErrorCode_t;\n'.format(pkg))
  fileOut.write('\nEND_C_DECLS\n')
  fileOut.write('\nLIBSBML_CPP_NAMESPACE_END\n\n')
  fileOut.write('#endif  /*  {0}_h__  */\n\n'.format(element))

def writeError(fileOut, element, pkg, offset, classes):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('\nLIBSBML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\nBEGIN_C_DECLS\n')
  fileOut.write('\n\n');
  fileOut.write('typedef enum\n')
  fileOut.write('{\n')
  fileOut.write('  {0}UnknownError                  = {1}\n\n\n'.format(pkg, offset+10100));
  fileOut.write('}')
  fileOut.write('  {0}SBMLErrorCode_t;\n'.format(pkg))
  fileOut.write('\nEND_C_DECLS\n')
  fileOut.write('\nLIBSBML_CPP_NAMESPACE_END\n\n')
  fileOut.write('#endif  /*  {0}_h__  */\n\n'.format(element))

def writeErrorTable(fileOut, element, pkg, offset, classes):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/packages/{0}/validator/{1}SBMLError.h>\n\n'.format(pkg.lower(), pkg))
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n\n')
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('static const packageErrorTableEntry {0}ErrorTable[] = \n'.format(pkg.lower()))
  fileOut.write('{\n')
  fileOut.write('  //{0}\n'.format(offset+10100));
  fileOut.write('  {')
  fileOut.write('  {0}UnknownError,\n'.format(pkg));
  fileOut.write('    "Unknown error from {0}",\n'.format(pkg.lower()))
  fileOut.write('    LIBSBML_CAT_GENERAL_CONSISTENCY,\n')
  fileOut.write('    LIBSBML_SEV_ERROR,\n')
  fileOut.write('    "Unknown error from {0}",\n'.format(pkg.lower()))
  fileOut.write('    { " "\n')
  fileOut.write('    }\n')
  fileOut.write('  }\n\n')
  fileOut.write('};\n\n')
  fileOut.write('\nLIBSBML_CPP_NAMESPACE_END\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  fileOut.write('#endif  /*  {0}_h__  */\n\n'.format(element))


def writeErrorTableStart(fileOut, element, pkg):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/packages/{0}/validator/{1}SBMLError.h>\n\n'.format(pkg.lower(), pkg))
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n\n')
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('static const packageErrorTableEntry {0}ErrorTable[] = \n'.format(pkg.lower()))
  fileOut.write('{\n')

def writeErrorTableEnd(fileOut, element):
  fileOut.write('};\n\n')
  fileOut.write('\nLIBSBML_CPP_NAMESPACE_END\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  fileOut.write('#endif  /*  {0}_h__  */\n\n'.format(element))


def createErrorFiles(pkg, offset, classes):
  nameOfElement = pkg + 'SBMLError'
  fileName = nameOfElement + '.h'
  output = open(fileName, 'w')
  fileHeaders.addFilename(output, fileName, nameOfElement)
  fileHeaders.addLicence(output)
  writeError(output, nameOfElement, pkg, offset, classes)
  nameOfElement1 = pkg + 'SBMLErrorTable'
  fileName1 = nameOfElement1 + '.h'
  output1 = open(fileName1, 'w')
  fileHeaders.addFilename(output1, fileName1, nameOfElement1)
  fileHeaders.addLicence(output1)
  fileName2 = nameOfElement + '.txt'
  output2 = open(fileName2, 'w')
  writeErrorTable(output1, nameOfElement1, pkg, offset, classes)
  #writeErrors(output, output1, output2, nameOfElement, pkg,offset, classes)

def writeConsistencyHeader(fileOut, element, pkg, type):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n\n')
  fileOut.write('#include <sbml/packages/{0}/validator/{1}Validator.h>\n\n'.format(pkg.lower(), pkg))
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n\n')
  fileOut.write('class {0}: public {1}Validator\n'.format(element, pkg))
  fileOut.write('{\n')
  fileOut.write('public:\n\n')
  fileOut.write('  {0} () :\n'.format(element))
  if type == "":
    fileOut.write('    {0}Validator(LIBSBML_CAT_GENERAL_CONSISTENCY)'.format(pkg))
  elif type == "Identifier":
    fileOut.write('    {0}Validator(LIBSBML_CAT_IDENTIFIER_CONSISTENCY)'.format(pkg))
  fileOut.write(' { }\n\n')
  fileOut.write('  virtual ~{0} () '.format(element))
  fileOut.write('{ }\n\n')
  fileOut.write('   virtual void init ();\n')
  fileOut.write('};\n\n')
  fileOut.write('LIBSBML_CPP_NAMESPACE_END\n\n')
  fileOut.write('#endif  /* __cplusplus*/\n')  
  fileOut.write('#endif  /* {0}_H__ */\n\n\n'.format(element))
  generalFunctions.writeInternalEnd(fileOut)
  fileOut.close()
  
def writeConsistencyFile(fileOut, element, pkg, type):
  fileOut.write('\n\n');
  fileOut.write('#ifndef doxygen_ignore\n\n')
  fileOut.write('#include <sbml/packages/{0}/validator/{1}.h>\n\n'.format(pkg.lower(), element))
  fileOut.write('#include "constraints/{0}{1}ConsistencyConstraints.cpp"\n\n'.format(pkg, type))
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n\n')
  fileOut.write('void\n')
  fileOut.write('{0}::init ()\n'.format(element))
  fileOut.write('{\n')
  fileOut.write('#define  AddingConstraintsToValidator 1\n')
  fileOut.write('#include "constraints/{0}{1}ConsistencyConstraints.cpp"\n'.format(pkg, type))
  fileOut.write('}\n\n')
  fileOut.write('LIBSBML_CPP_NAMESPACE_END\n\n')
  fileOut.write('#endif  /* __doxygen_ignore */\n\n')  
  generalFunctions.writeInternalEnd(fileOut)
  fileOut.close()
  
def createConsistencyFiles(pkg, type):
  nameOfElement = pkg + type + 'ConsistencyValidator'
  fileName = nameOfElement + '.h'
  output = open(fileName, 'w')
  generalFunctions.writeInternalStart(output)
  fileHeaders.addFilename(output, fileName, nameOfElement)
  fileHeaders.addLicence(output)
  writeConsistencyHeader(output, nameOfElement, pkg, type)
  fileName1 = nameOfElement + '.cpp'
  output1 = open(fileName1, 'w')
  generalFunctions.writeInternalStart(output1)
  fileHeaders.addFilename(output1, fileName1, nameOfElement)
  fileHeaders.addLicence(output1)
  writeConsistencyFile(output1, nameOfElement, pkg, type)
  
def createConstraintsFile(pkg, type):
  nameOfElement = pkg + type + 'ConsistencyConstraints'
  fileName = nameOfElement + '.cpp'
  output = open(fileName, 'w')
  generalFunctions.writeInternalStart(output)
  fileHeaders.addFilename(output, fileName, nameOfElement)
  fileHeaders.addLicence(output)
  output.write('\n#ifndef  AddingConstraintsToValidator\n\n')
  output.write('#include <sbml/validator/VConstraint.h>\n\n')
  output.write('#include <sbml/packages/{0}/validator/{1}SBMLError.h>\n\n'.format(pkg.lower(), pkg))
  output.write('#endif  /* AddingConstrainstToValidator */\n\n')
  output.write('#include <sbml/validator/ConstraintMacros.h>\n\n')
  output.write('/** @cond doxygenIgnored */\n\n')
  output.write('using namespace std;\n\n')
  output.write('/** @endcond */\n\n')
  output.write('/** PUT CONSTRAINTS HERE */\n\n')
  generalFunctions.writeInternalEnd(output)
  

  
def main(package):
  nameOfPackage = package['name']
  classes = package['sbmlElements']
  offset = package['offset']
  createValidatorHeader(nameOfPackage)
  createValidatorFile(nameOfPackage, classes)
  createErrorFiles(nameOfPackage, offset, classes)
  createConsistencyFiles(nameOfPackage, "")
  createConsistencyFiles(nameOfPackage, "Identifier")
  os.chdir('constraints')
  createConstraintsFile(nameOfPackage, "")
  createConstraintsFile(nameOfPackage, "Identifier")
  
