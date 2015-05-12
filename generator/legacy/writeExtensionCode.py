#!/usr/bin/env python
#
# @file   writeExtensionCode.py
# @brief  Create the extension files for a new class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import writeBindingsFiles
import strFunctions

def writeClass(fileOut, nameOfClass, pkg, elements):
  writeRequiredMethods(fileOut, nameOfClass, pkg, elements)
  writeConstructors(fileOut, nameOfClass)
  writeGetFunctions(fileOut, pkg, nameOfClass, elements)

def writeConstructors(fileOut, nameOfClass):
  fileOut.write('/*\n * Constructor\n */\n' )
  fileOut.write('{0}::{0}()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n * Copy constructor\n */\n' )
  fileOut.write('{0}::{0}(const {0}& orig) :\n '.format(nameOfClass))
  fileOut.write('  SBMLExtension(orig)\n')
  fileOut.write('{\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n * Assignment operator\n */\n' )
  fileOut.write('{0}&\n'.format(nameOfClass))
  fileOut.write('{0}::operator=(const {0}& rhs)\n '.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  if (&rhs != this)\n')
  fileOut.write('  {\n')
  fileOut.write('    SBMLExtension::operator=(rhs);\n')
  fileOut.write('  }\n')
  fileOut.write('  return *this;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n * Clone\n */\n' )
  fileOut.write('{0}*\n'.format(nameOfClass))
  fileOut.write('{0}::clone () const\n '.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return new {0}(*this);\n'.format(nameOfClass))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n * Destructor\n */\n' )
  fileOut.write('{0}::~{0}()\n '.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('}\n\n\n')

def writeGetFunctions(fileOut, pkg, nameOfClass, elements):
  fileOut.write('/*\n')
  fileOut.write(' * Returns the name of this package\n')
  fileOut.write(' */\n')
  fileOut.write('const std::string&\n')
  fileOut.write('{0}::getName() const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return getPackageName();\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the URI (namespace) of the package\n') 
  fileOut.write(' */\n')
  fileOut.write('const std::string&\n')
  fileOut.write('{0}::getURI(unsigned int sbmlLevel,\n'.format(nameOfClass))
  fileOut.write('                                  unsigned int sbmlVersion,\n')
  fileOut.write('                                  unsigned int pkgVersion) const\n')
  fileOut.write('{\n')
  fileOut.write('  if (sbmlLevel == 3)\n')
  fileOut.write('  {\n')
  fileOut.write('    if (sbmlVersion == 1)\n')
  fileOut.write('    {\n')
  fileOut.write('      if (pkgVersion == 1)\n')
  fileOut.write('      {\n')
  fileOut.write('        return getXmlnsL3V1V1();\n')
  fileOut.write('      }\n')
  fileOut.write('    }\n')
  fileOut.write('  }\n')
  fileOut.write('\n  static std::string empty = "";\n')
  fileOut.write('\n  return empty;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the SBML level with the given URI of this package.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getLevel(const std::string &uri) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  if (uri == getXmlnsL3V1V1())\n')
  fileOut.write('  {\n')
  fileOut.write('    return 3;\n')
  fileOut.write('  }\n')
  fileOut.write('\n  return 0;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the SBML version with the given URI of this package.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')   
  fileOut.write('{0}::getVersion(const std::string &uri) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  if (uri == getXmlnsL3V1V1())\n')
  fileOut.write('  {\n')
  fileOut.write('    return 1;\n')
  fileOut.write('  }\n')
  fileOut.write('\n  return 0;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the package version with the given URI of this package.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')   
  fileOut.write('{0}::getPackageVersion(const std::string &uri) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  if (uri == getXmlnsL3V1V1())\n')
  fileOut.write('  {\n')
  fileOut.write('    return 1;\n')
  fileOut.write('  }\n')
  fileOut.write('\n  return 0;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns an SBMLExtensionNamespaces<{0}Extension> object \n'.format(pkg))
  fileOut.write(' */\n')
  fileOut.write('SBMLNamespaces*\n')   
  fileOut.write('{0}::getSBMLExtensionNamespaces(const std::string &uri) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  {0}PkgNamespaces* pkgns = NULL;\n'.format(pkg))
  fileOut.write('  if (uri == getXmlnsL3V1V1())\n')
  fileOut.write('  {\n')
  fileOut.write('    pkgns = new {0}PkgNamespaces(3, 1, 1);\n'.format(pkg))
  fileOut.write('  }\n')
  fileOut.write('\n  return pkgns;\n')
  fileOut.write('}\n\n\n')



# write the include files
def writeIncludes(fileOut, element, pkg, plugins):
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/extension/SBMLExtensionRegister.h>\n')
  fileOut.write('#include <sbml/extension/SBMLExtensionRegistry.h>\n')
  fileOut.write('#include <sbml/extension/SBasePluginCreator.h>\n')
  fileOut.write('#include <sbml/extension/SBMLDocumentPlugin.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/packages/{0}/extension/{1}.h>\n'.format(pkg.lower(), element))

  list = []
  for i in range (0, len(plugins)):
    plug = plugins[i]
    if plug.has_key('package') and list.count(plug['package']) == 0 and plug['package'] != None:
        list.append(plug['package'])
    fileOut.write('#include <sbml/packages/{0}/extension/{1}{2}Plugin.h>\n'.format(pkg.lower(), pkg, plug['sbase']))
  fileOut.write('#include <sbml/packages/{0}/extension/{1}SBMLDocumentPlugin.h>\n'.format(pkg.lower(), pkg))
  fileOut.write('#include <sbml/packages/{0}/validator/{1}SBMLErrorTable.h>\n'.format(pkg.lower(), pkg))

  for item in list:
    fileOut.write('#include <sbml/packages/{0}/extension/{1}Extension.h>\n'.format(item.lower(), strFunctions.cap(item)))

  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <iostream>\n')
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

def writeIncludeEnds(fileOut, element):
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_END\n')
  fileOut.write('\n\n');
  fileOut.write('#endif /* __cplusplus */\n\n\n')

def writeInitFunction(fileOut, pkg, nameOfClass, plugins):
  fileOut.write('/*\n')
  fileOut.write(' * Initialization function of {0} extension module which is automatically invoked\n'.format(pkg.lower()))
  fileOut.write(' * by SBMLExtensionRegister class before main() function invoked. \n')
  fileOut.write(' */\n')
  fileOut.write('void\n')
  fileOut.write('{0}::init()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('  //\n')
  fileOut.write('  // 1. Check if the {0} package has already been registered\n'.format(pkg.lower()))
  fileOut.write('  //\n')
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('\n  if (SBMLExtensionRegistry::getInstance().isRegistered(getPackageName()))\n')
  fileOut.write('  {\n')
  fileOut.write('    // do nothing\n')
  fileOut.write('     return;\n')
  fileOut.write('  }\n\n')
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('  //\n')
  fileOut.write('  // 2. Creates an SBMLExtension derived object\n')
  fileOut.write('  //\n')
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('\n  {0}Extension {1}Extension;\n\n'.format(pkg, pkg.lower()));
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('  //\n')
  fileOut.write('  // 3. Creates the SBasePlugins required by this package\n')
  fileOut.write('  //\n')
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('\n  std::vector<std::string> packageURIs;\n');
  fileOut.write('  packageURIs.push_back(getXmlnsL3V1V1());\n');
  fileOut.write('\n  SBaseExtensionPoint sbmldocExtPoint("core", SBML_DOCUMENT);\n');
  # add an extension point for each class that has a plugin
  for i in range (0, len(plugins)):
    plug_ext = plugins[i]
    plug = plug_ext['sbase']
    if plug == 'SBase':
      fileOut.write('  SBaseExtensionPoint {0}ExtPoint("all", SBML_GENERIC_{1});\n'.format(plug.lower(), plug.upper()))
    else:
      typecode = 'SBML_{0}'.format(writeBindingsFiles.createSBase(plug.upper()));
      package = 'core'
      if plug_ext.has_key('package'): 
        package = plug_ext['package'].lower()
      if plug_ext.has_key('typecode'):
        typecode = plug_ext['typecode']
      fileOut.write('  SBaseExtensionPoint {0}ExtPoint("{1}", {2});\n'.format(plug.lower(), package, typecode))
  fileOut.write('\n')
  fileOut.write('  SBasePluginCreator<{0}SBMLDocumentPlugin, {0}Extension> sbmldocPluginCreator(sbmldocExtPoint, packageURIs);\n'.format(pkg))
  for i in range (0, len(plugins)):
    plug_ext = plugins[i]
    plug = plug_ext['sbase']
    fileOut.write('  SBasePluginCreator<{0}{1}Plugin, {0}Extension> {2}PluginCreator({2}ExtPoint, packageURIs);\n'.format(pkg, plug, plug.lower()))
  fileOut.write('\n')
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('  //\n')
  fileOut.write('  // 4. Adds the creator objects to the extension\n')
  fileOut.write('  //\n')
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('\n  {0}Extension.addSBasePluginCreator(&sbmldocPluginCreator);\n'.format(pkg.lower()))
  for i in range (0, len(plugins)):
    plug_ext = plugins[i]
    plug = plug_ext['sbase']
    fileOut.write('  {0}Extension.addSBasePluginCreator(&{1}PluginCreator);\n'.format(pkg.lower(), plug.lower()))
  fileOut.write('\n')
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('  //\n')
  fileOut.write('  // 5. Register the object with the registry\n')
  fileOut.write('  //\n')
  fileOut.write('  //----------------------------------------------------------------\n')
  fileOut.write('\n')
  fileOut.write('  int result = SBMLExtensionRegistry::getInstance().addExtension(&{0}Extension);\n'.format(pkg.lower()))
  fileOut.write('\n')
  fileOut.write('  if (result != LIBSBML_OPERATION_SUCCESS)\n')
  fileOut.write('  {\n')
  fileOut.write('    std::cerr << "[Error] {0}Extension::init() failed." << std::endl;\n'.format(pkg))
  fileOut.write('  }\n')
  fileOut.write('}\n\n\n')

def writeErrorFunction(fileOut, pkg, nameOfClass, offset):
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('/*\n')
  fileOut.write(' * Return error table entry. \n')
  fileOut.write(' */\n')
  fileOut.write('packageErrorTableEntry\n')
  fileOut.write('{0}::getErrorTable(unsigned int index) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return {0}ErrorTable[index];\n'.format(pkg.lower()))
  fileOut.write('}\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('/*\n')
  fileOut.write(' * Return error table index for this id. \n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getErrorTableIndex(unsigned int errorId) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  unsigned int tableSize = sizeof({0}ErrorTable)/sizeof({0}ErrorTable[0]);\n'.format(pkg.lower()))
  fileOut.write('  unsigned int index = 0;\n\n')
  fileOut.write('  for(unsigned int i = 0; i < tableSize; i++)\n')
  fileOut.write('  {\n')
  fileOut.write('    if (errorId == {0}ErrorTable[i].code)\n'.format(pkg.lower()))
  fileOut.write('    {\n')
  fileOut.write('      index = i;\n')
  fileOut.write('      break;\n')
  fileOut.write('    }\n\n')
  fileOut.write('  }\n\n')
  fileOut.write('  return index;\n')
  fileOut.write('}\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('/*\n')
  fileOut.write(' * Return error offset. \n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getErrorIdOffset() const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return {0};\n'.format(offset))
  fileOut.write('}\n\n')
  generalFunctions.writeInternalEnd(fileOut)


def writeRequiredMethods(fileOut, nameOfClass, pkg, elements):
  fileOut.write('/*---------------------------------------------------------------\n')
  fileOut.write(' *\n')
  fileOut.write(' * This block is global initialization code which should be automatically\n')
  fileOut.write(' * executed before invoking main() block.\n')
  fileOut.write(' *\n')
  fileOut.write(' */\n\n')
  fileOut.write('/*------------------ (START) ----------------------------------*/\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the package name of this extension.\n')
  fileOut.write(' */\n')
  fileOut.write('const std::string&\n')
  fileOut.write('{0}::getPackageName ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  static const std::string pkgName = "{0}";\n'.format(pkg.lower()))
  fileOut.write('  return pkgName;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the default SBML Level this extension.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getDefaultLevel ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return 3;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the default SBML Version this extension.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getDefaultVersion ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return 1;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the default SBML version this extension.\n')
  fileOut.write(' */\n')
  fileOut.write('unsigned int\n')
  fileOut.write('{0}::getDefaultPackageVersion ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return 1;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * XML namespaces of package.\n')
  fileOut.write(' */\n')
  fileOut.write('const std::string&\n')
  fileOut.write('{0}::getXmlnsL3V1V1 ()\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  static const std::string xmlns = "http://www.sbml.org/sbml/level3/version1/{0}/version1";\n'.format(pkg.lower()))
  fileOut.write('  return xmlns;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Adds this {0} object to the SBMLExtensionRegistry class.\n'.format(nameOfClass))
  fileOut.write(' * {0}::init function is automatically invoked when this\n'.format(nameOfClass))
  fileOut.write(' * object is instantiated\n')
  fileOut.write(' */\n')
  fileOut.write('static SBMLExtensionRegister<{0}> {1}ExtensionRegistry;\n\n\n'.format(nameOfClass, pkg.lower()))
  if len(elements) > 0:
    fileOut.write('static\nconst char * SBML_{0}_TYPECODE_STRINGS[] = \n'.format(pkg.upper()))
    fileOut.write('{\n')
    el = elements[0]
    name = el['name']
    fileOut.write('    "{0}"\n'.format(name))
    for i in range (1, len(elements)):
      el = elements[i]
      if el['typecode'] != 'HACK':
        name = el['name']
        fileOut.write('  , "{0}"\n'.format(name))
    fileOut.write('};\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Instantiate SBMLExtensionNamespaces<{0}>\n'.format(nameOfClass))
  fileOut.write(' * ({0}PkgNamespaces) for DLL.\n'.format(pkg))
  fileOut.write(' */\n')
  fileOut.write('template class LIBSBML_EXTERN  SBMLExtensionNamespaces<{0}>;\n\n\n'.format(nameOfClass))
  fileOut.write('/*------------------ (END) ----------------------------------*/\n\n')


def writeTypeDefns(fileOut, nameOfClass, pkg, elements, number, enums):
  length = len(elements)
  if length > 1:
    el = elements[0];
    el_ty_min = el['typecode']
    el = elements[length-1]
    i = 1
    while el['typecode'] == 'HACK':
      i = i + 1
      el = elements[length-i]
    el_ty_max = el['typecode']
    fileOut.write('/*\n')
    fileOut.write(' * This method takes a type code from the {0} package and returns a string representing \n'.format(pkg))
    fileOut.write(' */\n')
    fileOut.write('const char*\n')   
    fileOut.write('{0}::getStringFromTypeCode(int typeCode) const\n'.format(nameOfClass))
    fileOut.write('{\n')
    fileOut.write('  int min = {0};\n'.format(el_ty_min))
    fileOut.write('  int max = {0};\n'.format(el_ty_max))
    fileOut.write('\n  if ( typeCode < min || typeCode > max)\n')
    fileOut.write('  {\n')
    fileOut.write('    return "(Unknown SBML {0} Type)";\n'.format(pkg))
    fileOut.write('  }\n')
    fileOut.write('\n  return SBML_{0}_TYPECODE_STRINGS[typeCode - min];\n'.format(pkg.upper()))
    fileOut.write('}\n\n\n')
  for i in range(0, len(enums)):
    current = enums[i]
    values = current['values']
    numValues = len(values)
    fileOut.write('static\n')
    fileOut.write('const char * SBML_{0}_STRINGS[] = \n'.format(current['name'].upper()))
    fileOut.write('{\n')
    fileOut.write('   "Unknown {0}"\n'.format(current['name']))
    for j in range(0, numValues):
      fileOut.write(' , "{0}"\n'.format(values[j]['value']))
    fileOut.write('};\n\n\n')

    fileOut.write('/*\n')
    fileOut.write(' * This method takes a type code from the {0} enum and returns a string representing \n'.format(current['name']))
    fileOut.write(' */\n')
    fileOut.write('LIBSBML_EXTERN\n')
    fileOut.write('const char *\n')
    fileOut.write('{0}_toString({0}_t typeCode)\n'.format(current['name']))
    fileOut.write('{\n')
    fileOut.write('  int min = {0}_UNKNOWN;\n'.format(current['name'].upper()))
    fileOut.write('  int max = {0};\n'.format(values[numValues-1]['name']))
    fileOut.write('\n  if ( typeCode < min || typeCode > max)\n')
    fileOut.write('  {\n')
    fileOut.write('    return "(Unknown {0} value)";\n'.format(current['name']))
    fileOut.write('  }\n')
    fileOut.write('\n  return SBML_{0}_STRINGS[typeCode - min];\n'.format(current['name'].upper()))
    fileOut.write('}\n\n\n')

    fileOut.write('/*\n')
    fileOut.write(' * This method takes a string and tries to find a {0} code to match it\n'.format(current['name']))
    fileOut.write(' */\n')
    fileOut.write('LIBSBML_EXTERN\n')
    fileOut.write('{0}_t\n'.format(current['name']))
    fileOut.write('{0}_parse(const char* code)\n'.format(current['name']))
    fileOut.write('{\n')
    fileOut.write('  static const int size = sizeof(SBML_{0}_STRINGS) / sizeof(SBML_{0}_STRINGS[0]);\n'.format(current['name'].upper()))
    fileOut.write('  unsigned int i;\n')
    fileOut.write('  std::string type(code);\n')
    fileOut.write('  for (i = 0; i < size; ++i)\n')
    fileOut.write('  {\n')
    fileOut.write('    if (type == SBML_{0}_STRINGS[i])\n'.format(current['name'].upper()))
    fileOut.write('      return ({0}_t)i;\n'.format(current['name']))
    fileOut.write('  }\n')
    fileOut.write('  return {0}_UNKNOWN;\n'.format(current['name'].upper()))
    fileOut.write('}\n\n\n')





def createCode(package):
  nameOfPackage = package['name']
  nameOfClass = nameOfPackage + 'Extension'
  plugins = package['plugins']
  offset = package['offset']
  codeName = nameOfClass + '.cpp'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfClass)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfClass, nameOfPackage, plugins)
  writeClass(code, nameOfClass, nameOfPackage, package['elements'])
  writeTypeDefns(code, nameOfClass, nameOfPackage, package['elements'], package['number'], package['enums']) 
  writeInitFunction(code, nameOfPackage, nameOfClass, plugins)
  writeErrorFunction(code, nameOfPackage, nameOfClass, offset)

  if package.has_key('addDefs'):
    code.write(open(package['addDefs'], 'r').read())

  writeIncludeEnds(code, nameOfClass)

  