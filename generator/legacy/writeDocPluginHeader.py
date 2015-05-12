#!/usr/bin/env python
#
# @file   writePluginHeader.py
# @brief  Create the extension files for a new class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions

def writeClassDefn(fileOut, nameOfClass, pkg):
  fileOut.write('class LIBSBML_EXTERN {0} : public SBMLDocumentPlugin\n'.format(nameOfClass))
  fileOut.write('{\npublic:\n\n')
  writeConstructors(fileOut, nameOfClass, pkg)
  writeReadAttMethods(fileOut)
  writeOtherFunctions(fileOut, nameOfClass, pkg)
  writeClassEnd(fileOut)

def writeClassEnd(fileOut):
  fileOut.write('protected:\n\n')
  generalFunctions.writeInternalStart(fileOut)
  generalFunctions.writeInternalEnd(fileOut)
  fileOut.write('};\n\n\n')
 
def writeConstructors(fileOut, nameOfClass, pkg):
 # indent = strFunctions.getIndent(nameOfClass)
  fileOut.write('  /**\n   * ' )
  fileOut.write('Creates a new {0}\n'.format(nameOfClass))
  fileOut.write('   */\n')
  fileOut.write('  {0}(const std::string& uri, const std::string& prefix, \n'.format(nameOfClass))
  fileOut.write('                                 {0}PkgNamespaces* {1}ns);\n\n\n'.format(pkg, pkg.lower()))
  fileOut.write('  /**\n   * ' )
  fileOut.write('Copy constructor for {0}.\n'.format(nameOfClass))
  fileOut.write('   *\n')
  fileOut.write('   * @param orig; the {0} instance to copy.\n'.format(nameOfClass))
  fileOut.write('   */\n')
  fileOut.write('  {0}(const {1}& orig);\n\n\n '.format(nameOfClass, nameOfClass))
  fileOut.write('  /**\n   * ' )
  fileOut.write('Assignment operator for {0}.\n'.format(nameOfClass))
  fileOut.write('   *\n')
  fileOut.write('   * @param rhs; the object whose values are used as the basis\n')
  fileOut.write('   * of the assignment\n   */\n')
  fileOut.write('  {0}& operator=(const {1}& rhs);\n\n\n '.format(nameOfClass, nameOfClass))
  fileOut.write('  /**\n   * ' )
  fileOut.write('Creates and returns a deep copy of this {0} object.\n'.format(nameOfClass))
  fileOut.write('   *\n   * @return a (deep) copy of this {0} object.\n   */\n'.format(nameOfClass))
  fileOut.write('  virtual {0}* clone () const;\n\n\n '.format(nameOfClass))
  fileOut.write('  /**\n   * ' )
  fileOut.write('Destructor for {0}.\n   */\n'.format(nameOfClass))
  fileOut.write('  virtual ~{0}();\n\n\n '.format(nameOfClass))

def writeOtherFunctions(fileOut, nameOfClass, pkg):
 # indent = strFunctions.getIndent(nameOfClass)
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n   * ' )
  fileOut.write('Returns boolean based on whether flattening of a comp model has been implemented.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @returns @c true if flattening for composed models has been implemented,\n')
  fileOut.write('   * false otherwise.\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual bool isCompFlatteningImplemented() const;\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n   * ' )
  fileOut.write('Check consistency function.\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual unsigned int checkConsistency();\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)
#  generalFunctions.writeInternalStart(fileOut)
#  fileOut.write('  /**\n   * ' )
#  fileOut.write('Accepts the SBMLVisitor.\n'.format(nameOfClass))
#  fileOut.write('   */\n')
#  fileOut.write('  virtual bool accept(SBMLVisitor& v) const;\n\n\n '.format(nameOfClass, nameOfClass))
#  generalFunctions.writeInternalEnd(fileOut)

 

# write the include files
def writeIncludes(fileOut, element, pkg):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/common/extern.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/extension/SBMLDocumentPlugin.h>\n')
  fileOut.write('#include <sbml/packages/{0}/extension/{1}Extension.h>\n'.format(pkg.lower(), pkg))
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

def writeIncludeEnds(fileOut, element):
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_END\n')
  fileOut.write('\n\n');
  fileOut.write('#endif /* __cplusplus */\n')
  fileOut.write('#endif /* {0}_H__ */\n\n\n'.format(element))

def writeReadAttMethods(fileOut):
  fileOut.write('#ifndef SWIG\n\n')
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n')
  fileOut.write('   * Reads the attributes of corresponding package in SBMLDocument element\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual void readAttributes (const XMLAttributes& attributes, \n')
  fileOut.write('                               const ExpectedAttributes& expectedAttributes);\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  fileOut.write('#endif // SWIG\n\n')

def createHeader(package):
  nameOfPackage = package['name']
  nameOfClass = nameOfPackage + 'SBMLDocumentPlugin'
  codeName = nameOfClass + '.h'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfClass)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfClass, nameOfPackage)
  writeClassDefn(code, nameOfClass, nameOfPackage)
  writeIncludeEnds(code, nameOfClass)

  