#!/usr/bin/env python
#
# @file   writeExtensionHeader.py
# @brief  Create the extension files for a new class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions

def writeClassDefn(fileOut, nameOfClass, pkg, pkgDict = None):
  fileOut.write('class LIBSBML_EXTERN {0} : public SBMLExtension\n'.format(nameOfClass))
  fileOut.write('{\npublic:\n\n')
  writeRequiredMethods(fileOut)
  writeConstructors(fileOut, nameOfClass)
  writeGetFunctions(fileOut, pkg)
  writeInitFunction(fileOut, pkg)
  writeErrorFunction(fileOut, pkg)
  writeClassEnd(fileOut,pkgDict)

def writeClassEnd(fileOut, pkg = None):
  if pkg != None and pkg.has_key('addDecls'):
    fileOut.write(open(pkg['addDecls'], 'r').read())
  fileOut.write('};\n\n\n')
 
def writeConstructors(fileOut, nameOfClass):
 # indent = strFunctions.getIndent(nameOfClass)
  fileOut.write('  /**\n   * ' )
  fileOut.write('Creates a new {0}'.format(nameOfClass))
  fileOut.write('   */\n')
  fileOut.write('  {0}();\n\n\n'.format(nameOfClass))
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

def writeGetFunctions(fileOut, pkg):
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the name of this package ("{0}")\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return a string representing the name of this package ("{0}")\n'.format(pkg.lower()))
  fileOut.write('   */\n')
  fileOut.write('  virtual const std::string& getName() const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the URI (namespace) of the package corresponding to the combination of \n') 
  fileOut.write('   * the given sbml level, sbml version, and package version.\n')
  fileOut.write('   * Empty string will be returned if no corresponding URI exists.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param sbmlLevel the level of SBML\n')
  fileOut.write('   * @param sbmlVersion the version of SBML\n')
  fileOut.write('   * @param pkgVersion the version of package\n')
  fileOut.write('   *\n')
  fileOut.write('   * @return a string of the package URI\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual const std::string& getURI(unsigned int sbmlLevel,\n')
  fileOut.write('                                    unsigned int sbmlVersion,\n')
  fileOut.write('                                    unsigned int pkgVersion) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the SBML level with the given URI of this package.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param uri the string of URI that represents one of versions of {0} package\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return the SBML level with the given URI of this package. 0 will be returned\n')
  fileOut.write('   * if the given URI is invalid.\n')
  fileOut.write('   *\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual unsigned int getLevel(const std::string &uri) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the SBML version with the given URI of this package.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param uri the string of URI that represents one of versions of {0} package\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return the SBML version with the given URI of this package. 0 will be returned\n')
  fileOut.write('   * if the given URI is invalid.\n')
  fileOut.write('   *\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual unsigned int getVersion(const std::string &uri) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the package version with the given URI of this package.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param uri the string of URI that represents one of versions of {0} package\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return the package version with the given URI of this package. 0 will be returned\n')
  fileOut.write('   * if the given URI is invalid.\n')
  fileOut.write('   *\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual unsigned int getPackageVersion(const std::string &uri) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns an SBMLExtensionNamespaces<{0}Extension> object whose alias type is \n'.format(pkg))
  fileOut.write('   * {0}PkgNamespace.\n'.format(pkg))
  fileOut.write('   * Null will be returned if the given uri is not defined in the {0} package.\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @param uri the string of URI that represents one of versions of {0} package\n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return an {0}PkgNamespace object corresponding to the given uri. NULL will\n'.format(pkg))
  fileOut.write('   * be returned if the given URI is not defined in {0} package.\n'.format(pkg.lower()))
  fileOut.write('   */\n')
  fileOut.write('  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string &uri) const;\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * This method takes a type code from the {0} package and returns a string representing \n'.format(pkg))
  fileOut.write('   * the code.\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual const char* getStringFromTypeCode(int typeCode) const;\n\n\n')



# write the include files
def writeIncludes(fileOut, element, pkg):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/common/extern.h>\n')
  fileOut.write('#include <sbml/SBMLTypeCodes.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/extension/SBMLExtension.h>\n')
  fileOut.write('#include <sbml/extension/SBMLExtensionNamespaces.h>\n')
  fileOut.write('#include <sbml/extension/SBMLExtensionRegister.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_CREATE_NS\n'.format(pkg.upper()))
  fileOut.write('  #define {0}_CREATE_NS(variable, sbmlns)\\\n'.format(pkg.upper()))
  fileOut.write('    EXTENSION_CREATE_NS({0}PkgNamespaces, variable, sbmlns);\n'.format(pkg))
  fileOut.write('#endif\n')
  fileOut.write('\n\n');
  fileOut.write('#include <vector>\n')
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

def writeIncludeEnds(fileOut, element):
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_END\n')
  fileOut.write('\n\n');
  fileOut.write('#endif /* __cplusplus */\n')
  fileOut.write('#endif /* {0}_H__ */\n\n\n'.format(element))

def writeInitFunction(fileOut, pkg):
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n')
  fileOut.write('   * Initializes {0} extension by creating an object of this class with \n'.format(pkg.lower()))
  fileOut.write('   * required SBasePlugin derived objects and registering the object \n')
  fileOut.write('   * to the SBMLExtensionRegistry class.\n')
  fileOut.write('   *\n')
  fileOut.write('   * (NOTE) This function is automatically invoked when creating the following\n')
  fileOut.write('   *        global object in {0}Extension.cpp\n'.format(pkg))
  fileOut.write('   *\n')
  fileOut.write('   *        static SBMLExtensionRegister<{0}Extension> {1}ExtensionRegistry;\n'.format(pkg, pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   */\n')
  fileOut.write('  static void init();\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)

def writeErrorFunction(fileOut, pkg):
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n')
  fileOut.write('   * Return the entry in the error table at this index. \n')
  fileOut.write('   *\n')
  fileOut.write('   * @param index an unsigned intgere representing the index of the error in the {0}SBMLErrorTable\n'.format(pkg))
  fileOut.write('   *\n')
  fileOut.write('   * @return packageErrorTableEntry object in the {0}SBMLErrorTable corresponding to the index given.\n'.format(pkg))
  fileOut.write('   */\n')
  fileOut.write('  virtual packageErrorTableEntry getErrorTable(unsigned int index) const;\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n')
  fileOut.write('   * Return the index in the error table with the given errorId. \n')
  fileOut.write('   *\n')
  fileOut.write('   * @param errorId an unsigned intgere representing the errorId of the error in the {0}SBMLErrorTable\n'.format(pkg))
  fileOut.write('   *\n')
  fileOut.write('   * @return unsigned integer representing the index in the {0}SBMLErrorTable corresponding to the errorId given.\n'.format(pkg))
  fileOut.write('   */\n')
  fileOut.write('  virtual unsigned int getErrorTableIndex(unsigned int errorId) const;\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n')
  fileOut.write('   * Return the offset for the errorId range for the {0} L3 package. \n'.format(pkg.lower()))
  fileOut.write('   *\n')
  fileOut.write('   * @return unsigned intege representing the  offset for errors {0}SBMLErrorTable.\n'.format(pkg))
  fileOut.write('   */\n')
  fileOut.write('  virtual unsigned int getErrorIdOffset() const;\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)


def writeRequiredMethods(fileOut):
  fileOut.write('  //---------------------------------------------------------------\n')
  fileOut.write('  //\n')
  fileOut.write('  // Required class methods\n')
  fileOut.write('  //\n')
  fileOut.write('  //---------------------------------------------------------------\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the package name of this extension.\n')
  fileOut.write('   */\n')
  fileOut.write('  static const std::string& getPackageName ();\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the default SBML Level this extension.\n')
  fileOut.write('   */\n')
  fileOut.write('  static unsigned int getDefaultLevel();\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the default SBML Version this extension.\n')
  fileOut.write('   */\n')
  fileOut.write('  static unsigned int getDefaultVersion();\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the default SBML version this extension.\n')
  fileOut.write('   */\n')
  fileOut.write('  static unsigned int getDefaultPackageVersion();\n\n\n')
  fileOut.write('  /**\n')
  fileOut.write('   * Returns URI of supported versions of this package.\n')
  fileOut.write('   */\n')
  fileOut.write('  static const std::string&  getXmlnsL3V1V1();\n\n\n')
  fileOut.write('  //\n')
  fileOut.write('  // Other URI needed in this package (if any)\n')
  fileOut.write('  //\n')
  fileOut.write('  //---------------------------------------------------------------\n\n\n')

def writeTypeDefns(fileOut, nameOfClass, nameOfPkg, elements, number, enums):
  fileOut.write('// --------------------------------------------------------------------\n')
  fileOut.write('//\n')
  fileOut.write('// Required typedef definitions\n') 
  fileOut.write('//\n')
  fileOut.write('// {0}PkgNamespaces is derived from the SBMLNamespaces class and\n'.format(nameOfPkg))
  fileOut.write('// used when creating an object of SBase derived classes defined in\n')
  fileOut.write('// {0} package.\n'.format(nameOfPkg.lower()))
  fileOut.write('//\n')
  fileOut.write('// --------------------------------------------------------------------\n')
  fileOut.write('//\n')
  fileOut.write('// (NOTE)\n')
  fileOut.write('//\n')
  fileOut.write('// SBMLExtensionNamespaces<{0}> must be instantiated\n'.format(nameOfClass))
  fileOut.write('// in {0}.cpp for DLL.\n'.format(nameOfClass))
  fileOut.write('//\n')
  fileOut.write('typedef SBMLExtensionNamespaces<{0}> {1}PkgNamespaces;\n\n'.format(nameOfClass, nameOfPkg))
  if len(elements) > 0:
    fileOut.write('typedef enum\n{\n')
    el = elements[0];
    el_ty = el['typecode']
    fileOut.write('    {0}  = {1}\n'.format(el_ty, number))
    for i in range (1, len(elements)):
      el = elements[i];
      el_ty = el['typecode']
      if el_ty != 'HACK':
        fileOut.write('  , {0:<30} = {1}\n'.format(el_ty, number+i))
    fileOut.write('}')
    fileOut.write(' SBML{0}TypeCode_t;\n\n\n'.format(nameOfPkg))

  for i in range(0,len(enums)):
    current = enums[i]
    fileOut.write('typedef enum\n{\n')
    fileOut.write('    {0}_UNKNOWN  /*!< Unknown {1} */\n'.format(current['name'].upper(), current['name']))
    values = current['values']
    for j in range(0, len(values)):
      val = values[j]
      fileOut.write('  , {0} /*!< {1} */\n'.format(val['name'], val['value']))
    fileOut.write('}')
    fileOut.write(' {0}_t;\n\n\n'.format(current['name']))
    
    fileOut.write('LIBSBML_EXTERN\n')
    fileOut.write('const char *\n')
    fileOut.write('{0}_toString({0}_t code);\n\n\n'.format(current['name']))

    fileOut.write('LIBSBML_EXTERN\n')
    fileOut.write('{0}_t\n'.format(current['name']))
    fileOut.write('{0}_parse(const char* code);\n\n\n'.format(current['name']))


def createHeader(package):
  nameOfPackage = package['name']
  nameOfClass = nameOfPackage + 'Extension'
  codeName = nameOfClass + '.h'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfClass)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfClass, nameOfPackage)
  writeClassDefn(code, nameOfClass, nameOfPackage, package)
  writeTypeDefns(code, nameOfClass, nameOfPackage, package['elements'], package['number'], package['enums']) 
  writeIncludeEnds(code, nameOfClass)

  