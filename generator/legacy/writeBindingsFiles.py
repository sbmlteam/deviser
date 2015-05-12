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
import generalFunctions

def isBaseClassForOthers(element, classes):
  for item in classes:
    if element['name'] == item['name']: 
      pass
    if item['baseClass'] == element['name']:
      return True
  return False

def createSBase(sbaseName):
  if sbaseName == 'SIMPLESPECIESREFERENCE':
    return 'MODIFIER_SPECIES_REFERENCE'
  elif sbaseName == 'SPECIESREFERENCE':
    return 'SPECIES_REFERENCE'
  elif sbaseName == 'FUNCTIONDEFINITION':
    return 'FUNCTION_DEFINITION'
  elif sbaseName == 'SBASE':
    return 'GENERIC_SBASE'
  else:
    return sbaseName

def writeCSharpExt(fileOut, name):
  capName = name.upper()
  fileOut.write('/**\n')
  fileOut.write(' * casting to most specific SBMLExtension object\n */\n\n')
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('%pragma(csharp) modulecode =\n')
  fileOut.write('%{\n')
  fileOut.write('  if (pkgName == "{0}")\n'.format(name))
  fileOut.write('  {\n')
  fileOut.write('    return new {0}Extension(cPtr, owner);\n'.format(strFunctions.cap(name)))
  fileOut.write('  }\n')
  fileOut.write('%}\n')
  fileOut.write('#endif /* USE_{0} */\n\n'.format(capName))

def writeJavaExt(fileOut, name):
  capName = name.upper()
  fileOut.write('/**\n')
  fileOut.write(' * casting to most specific SBMLExtension object\n */\n\n')
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('%pragma(java) modulecode =\n')
  fileOut.write('%{\n')
  fileOut.write('  if (pkgName.equals("{0}"))\n'.format(name))
  fileOut.write('  {\n')
  fileOut.write('    return new {0}Extension(cPtr, owner);\n'.format(strFunctions.cap(name)))
  fileOut.write('  }\n')
  fileOut.write('%}\n')
  fileOut.write('#endif // USE_{0}\n\n'.format(capName))

def writeExt(fileOut, name):
  capName = name.upper()
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('if (pkgName == "{0}")\n'.format(name))
  fileOut.write('{\n')
  fileOut.write('  return SWIGTYPE_p_{0}Extension;\n'.format(strFunctions.cap(name)))
  fileOut.write('}\n')
  fileOut.write('#endif // USE_{0} \n\n'.format(capName))

def writeCSharpNS(fileOut, name):
  capName = name.upper()
  fileOut.write('/**\n')
  fileOut.write(' * casting to most specific SBMLNamespaces object\n */\n\n')
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('%pragma(csharp) modulecode =\n')
  fileOut.write('%{\n')
  fileOut.write('  if (ns.hasURI({0}Extension.getXmlnsL3V1V1()))\n'.format(strFunctions.cap(name)))
  fileOut.write('  {\n')
  fileOut.write('    return new {0}PkgNamespaces(cPtr, owner);\n'.format(strFunctions.cap(name)))
  fileOut.write('  }\n')
  fileOut.write('%}\n')
  fileOut.write('#endif /* USE_{0} */\n\n'.format(capName))

def writeJavaNS(fileOut, name):
  capName = name.upper()
  fileOut.write('/**\n')
  fileOut.write(' * casting to most specific SBMLNamespaces object\n */\n\n')
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('%pragma(java) modulecode =\n')
  fileOut.write('%{\n')
  fileOut.write('  if (ns.hasURI({0}Extension.getXmlnsL3V1V1()))\n'.format(strFunctions.cap(name)))
  fileOut.write('  {\n')
  fileOut.write('    return new {0}PkgNamespaces(cPtr, owner);\n'.format(strFunctions.cap(name)))
  fileOut.write('  }\n')
  fileOut.write('%}\n')
  fileOut.write('#endif /* USE_{0} */\n\n'.format(capName))

def writeNS(fileOut, name):
  capName = name.upper()
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('if (pkgName == "{0}")\n'.format(name))
  fileOut.write('{\n')
  fileOut.write('  return SWIGTYPE_p_SBMLExtensionNamespacesT_{0}Extension_t;\n'.format(strFunctions.cap(name)))
  fileOut.write('}\n')
  fileOut.write('#endif // USE_{0} \n\n'.format(capName))

def writeCSharp(fileOut, name, plugins, classes):
  capName = name.upper()
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('/**\n')
  fileOut.write(' * Adds DownCastBase(long cPtr, boolean owner) method for the {0} package extension\n'.format(name))
  fileOut.write(' */\n')
  fileOut.write('%typemap(cscode) {0}Extension\n'.format(strFunctions.cap(name)))
  fileOut.write('%{\n')
  fileOut.write('  public override SBasePlugin DowncastSBasePlugin(IntPtr cPtr, bool owner)\n')
  fileOut.write('  {\n')
  fileOut.write('    if (cPtr.Equals(IntPtr.Zero)) return null;\n\n')
  fileOut.write('    SBasePlugin sbp = new SBasePlugin(cPtr, false);\n')
  fileOut.write('    SBase sb = sbp.getParentSBMLObject();\n\n')
  fileOut.write('    switch( sb.getTypeCode() )\n')
  fileOut.write('    {\n')
  listOfPlugins = []
  for plugin in plugins:
    typecode = 'SBML_{0}'.format(createSBase(plugin['sbase'].upper()))
    if plugin.has_key('typecode') and plugin['typecode'] != None:
      typecode = plugin['typecode']    

    if typecode != 'SBML_LIST_OF':
      fileOut.write('      case (int) libsbml.{0}:\n'.format(typecode))
      fileOut.write('        return new {0}{1}Plugin(cPtr, owner);\n\n'.format(strFunctions.cap(name), plugin['sbase']))
      
    else:
      listOfPlugins.append(plugin)

  if len(listOfPlugins) > 0: 
    fileOut.write('      case (int) libsbml.SBML_LIST_OF:\n')
    fileOut.write('      {\n')
    fileOut.write('        string name = sb.getElementName();\n')
    for plugin in listOfPlugins:
      fileOut.write('        if (name == "{0}")\n'.format(strFunctions.lowerFirst(plugin['sbase'])))
      fileOut.write('          return new {0}{1}Plugin(cPtr, owner);\n\n'.format(strFunctions.cap(name), plugin['sbase']))
    fileOut.write('        return new SBasePlugin(cPtr, owner);\n')
    fileOut.write('      }\n')

  fileOut.write('      default:\n')
  fileOut.write('        return new SBasePlugin(cPtr, owner);\n')
  fileOut.write('    }\n')
  fileOut.write('  }\n\n')
  fileOut.write('  public override SBase DowncastSBase(IntPtr cPtr, bool owner)\n')
  fileOut.write('  {\n')
  fileOut.write('    if (cPtr.Equals(IntPtr.Zero)) return null;\n\n')
  fileOut.write('    SBase sb = new SBase(cPtr, false);\n')
  fileOut.write('    switch( sb.getTypeCode() )\n')
  fileOut.write('    {\n')
  fileOut.write('      case (int) libsbml.SBML_LIST_OF:\n')
  fileOut.write('        string name = sb.getElementName();\n')
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      loName = strFunctions.listOfName (classes[i]['name'])
      if classes[i].has_key('lo_elementName'):
        loName = classes[i]['lo_elementName']
      if (i==0):
        fileOut.write('        if (name == "{0}")\n'.format(loName))
      else :
        fileOut.write('        else if (name == "{0}")\n'.format(loName))
      fileOut.write('        {\n')
      fileOut.write('          return new {0}(cPtr, owner);\n'.format(generalFunctions.getListOfClassName (classes[i], classes[i]['name'])))
      fileOut.write('        }\n')
  fileOut.write('\n        return new ListOf(cPtr, owner);\n\n')
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('      case (int) libsbml.{0}:\n'.format(classes[i]['typecode']))
      fileOut.write('        return new {0}(cPtr, owner);\n\n'.format(classes[i]['name']))
  fileOut.write('      default:\n')
  fileOut.write('        return new SBase(cPtr, owner);\n')
  fileOut.write('    }\n')
  fileOut.write('  }\n\n')
  fileOut.write('%}\n\n')
  fileOut.write('COVARIANT_RTYPE_CLONE({0}Extension)\n'.format(strFunctions.cap(name)))
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('COVARIANT_RTYPE_CLONE({0})\n'.format(classes[i]['name']))
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      loName = generalFunctions.getListOfClassName (classes[i], classes[i]['name'])
      fileOut.write('COVARIANT_RTYPE_CLONE({0})\n'.format(strFunctions.cap(loName)))
  fileOut.write('\n')
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      fileOut.write('COVARIANT_RTYPE_LISTOF_GET_REMOVE({0})\n'.format(classes[i]['name']))
  fileOut.write('\n')
  fileOut.write('SBMLCONSTRUCTOR_EXCEPTION({0}PkgNamespaces)\n'.format(strFunctions.cap(name)))
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('SBMLCONSTRUCTOR_EXCEPTION({0})\n'.format(classes[i]['name']))
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      loName = generalFunctions.getListOfClassName (classes[i], classes[i]['name'])
      fileOut.write('SBMLCONSTRUCTOR_EXCEPTION({0})\n'.format(strFunctions.cap(loName)))
  fileOut.write('\n')
  for i in range (0, len(classes)):
    if (classes[i]['abstract'] == True or isBaseClassForOthers(classes[i], classes)):
      fileOut.write('//\n')
      fileOut.write('// Convert {0} objects into the most specific object possible.\n'.format(classes[i]['name']))
      fileOut.write('//\n')
      fileOut.write('%typemap("csout") {0}*\n'.format(classes[i]['name']))
      fileOut.write('{\n')
      fileOut.write('	return ({0}) libsbml.DowncastSBase($imcall, $owner);\n'.format(classes[i]['name']))
      fileOut.write('}\n')
      fileOut.write('\n')
  fileOut.write('\n')
  fileOut.write('#endif /* USE_{0} */\n\n'.format(capName))

def writeJava(fileOut, name, plugins, classes):
  capName = name.upper()
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('/**\n')
  fileOut.write(' * Adds DownCastBase(long cPtr, boolean owner) method for the {0} package extension\n'.format(name))
  fileOut.write(' */\n')
  fileOut.write('%typemap(javacode) {0}Extension\n'.format(strFunctions.cap(name)))
  fileOut.write('%{\n')
  fileOut.write('  public SBasePlugin DowncastSBasePlugin(long cPtr, boolean owner)\n')
  fileOut.write('  {\n')
  fileOut.write('    if (cPtr == 0) return null;\n\n')
  fileOut.write('    SBasePlugin sbp = new SBasePlugin(cPtr, false);\n')
  fileOut.write('    SBase sb = sbp.getParentSBMLObject();\n\n')
  fileOut.write('    switch( sb.getTypeCode() )\n')
  fileOut.write('    {\n')

  listOfPlugins = []
  for plugin in plugins:
    typecode = 'SBML_{0}'.format(createSBase(plugin['sbase'].upper()))
    if plugin.has_key('typecode') and plugin['typecode'] != None:
      typecode = plugin['typecode']    

    if typecode != 'SBML_LIST_OF':
      fileOut.write('      case (int) libsbml.{0}:\n'.format(typecode))
      fileOut.write('        return new {0}{1}Plugin(cPtr, owner);\n\n'.format(strFunctions.cap(name), plugin['sbase']))
      
    else:
      listOfPlugins.append(plugin)

  if len(listOfPlugins) > 0: 
    fileOut.write('      case (int) libsbml.SBML_LIST_OF:\n')
    fileOut.write('      {\n')
    fileOut.write('        String name = sb.getElementName();\n')
    for plugin in listOfPlugins:
      fileOut.write('        if (name.equals("{0}"))\n'.format(strFunctions.lowerFirst(plugin['sbase'])))
      fileOut.write('          return new {0}{1}Plugin(cPtr, owner);\n\n'.format(strFunctions.cap(name), plugin['sbase']))
    fileOut.write('        return new SBasePlugin(cPtr, owner);\n')
    fileOut.write('      }\n')

  fileOut.write('      default:\n')
  fileOut.write('        return new SBasePlugin(cPtr, owner);\n')
  fileOut.write('    }\n')
  fileOut.write('  }\n\n')
  fileOut.write('  public SBase DowncastSBase(long cPtr, boolean owner)\n')
  fileOut.write('  {\n')
  fileOut.write('    if (cPtr == 0) return null;\n\n')
  fileOut.write('    SBase sb = new SBase(cPtr, false);\n')
  fileOut.write('    switch( sb.getTypeCode() )\n')
  fileOut.write('    {\n')
  fileOut.write('      case (int) libsbml.SBML_LIST_OF:\n')
  fileOut.write('        String name = sb.getElementName();\n')
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      loName = strFunctions.listOfName(classes[i]['name'])
      if classes[i].has_key('lo_elementName'):
        loName = classes[i]['lo_elementName']
      if (i==0):
        fileOut.write('        if (name.equals("{0}"))\n'.format(loName))
      else :
        fileOut.write('        else if (name.equals("{0}"))\n'.format(loName))
      fileOut.write('        {\n')
      fileOut.write('          return new {0}(cPtr, owner);\n'.format(generalFunctions.getListOfClassName (classes[i], classes[i]['name'])))
      fileOut.write('        }\n')
  fileOut.write('\n        return new ListOf(cPtr, owner);\n\n')
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('      case (int) libsbml.{0}:\n'.format(classes[i]['typecode']))
      fileOut.write('        return new {0}(cPtr, owner);\n\n'.format(classes[i]['name']))
  fileOut.write('      default:\n')
  fileOut.write('        return new SBase(cPtr, owner);\n')
  fileOut.write('    }\n')
  fileOut.write('  }\n\n')
  fileOut.write('%}\n\n')
  fileOut.write('COVARIANT_RTYPE_CLONE({0}Extension)\n'.format(strFunctions.cap(name)))
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('COVARIANT_RTYPE_CLONE({0})\n'.format(classes[i]['name']))
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      loName = generalFunctions.getListOfClassName (classes[i], classes[i]['name'])
      fileOut.write('COVARIANT_RTYPE_CLONE({0})\n'.format(strFunctions.cap(loName)))
  fileOut.write('\n')
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      fileOut.write('COVARIANT_RTYPE_LISTOF_GET_REMOVE({0})\n'.format(classes[i]['name']))
  fileOut.write('\n')
  fileOut.write('SBMLCONSTRUCTOR_EXCEPTION({0}PkgNamespaces)\n'.format(strFunctions.cap(name)))
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('SBMLCONSTRUCTOR_EXCEPTION({0})\n'.format(classes[i]['name']))
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      loName = generalFunctions.getListOfClassName (classes[i], classes[i]['name'])
      fileOut.write('SBMLCONSTRUCTOR_EXCEPTION({0})\n'.format(strFunctions.cap(loName)))
  fileOut.write('\n')
  for i in range (0, len(classes)):
    if (classes[i]['abstract'] == True or isBaseClassForOthers(classes[i], classes)):
      fileOut.write('//\n')
      fileOut.write('// Convert {0} objects into the most specific object possible.\n'.format(classes[i]['name']))
      fileOut.write('//\n')
      fileOut.write('%typemap("javaout") {0}*\n'.format(classes[i]['name']))
      fileOut.write('{\n')
      fileOut.write('	return ({0}) libsbml.DowncastSBase($jnicall, $owner);\n'.format(classes[i]['name']))
      fileOut.write('}\n')
      fileOut.write('\n')

  fileOut.write('\n')
  fileOut.write('#endif /* USE_{0} */\n\n'.format(capName))

def writePkg(fileOut, name, classes):
  capName = name.upper()
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('else if (pkgName == "{0}")\n'.format(name))
  fileOut.write('{\n')
  fileOut.write('  switch (sb->getTypeCode() )\n')
  fileOut.write('  {\n')
  fileOut.write('    case SBML_LIST_OF:\n')
  fileOut.write('      name = sb->getElementName();\n')
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      loName = strFunctions.listOfName(classes[i]['name'])
      if classes[i].has_key('lo_elementName'):
        loName = classes[i]['lo_elementName']
      if (i==0):
        fileOut.write('      if (name == "{0}")\n'.format(loName))
      else :
        fileOut.write('      else if (name == "{0}")\n'.format(loName))
      fileOut.write('      {\n')
      fileOut.write('        return SWIGTYPE_p_{0};\n'.format(generalFunctions.getListOfClassName (classes[i], classes[i]['name'])))
      fileOut.write('      }\n')
  fileOut.write('\n      return SWIGTYPE_p_ListOf;\n\n')
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('    case {0}:\n'.format(classes[i]['typecode']))
      fileOut.write('      return SWIGTYPE_p_{0};\n\n'.format(classes[i]['name']))
  fileOut.write('    default:\n')
  fileOut.write('      return SWIGTYPE_p_SBase;\n')
  fileOut.write('  }\n')
  fileOut.write('}\n\n')
  fileOut.write('#endif // USE_{0} \n\n'.format(capName))

def writePlugins(fileOut, name, plugins):
  capName = name.upper()
  fileOut.write('#ifdef USE_{0}\n'.format(capName))
  fileOut.write('if (pkgName == "{0}")\n'.format(name))
  fileOut.write('{\n')
  for i in range (0, len(plugins)):
    plugin = plugins[i]
    if (i == 0):
      fileOut.write('  if ')
    else:
      fileOut.write('  else if ')
    typecode = 'SBML_{0}'.format(createSBase(plugin['sbase'].upper()))
    if plugin.has_key('typecode') and plugin['typecode'] != None:
      typecode = plugin['typecode']
    fileOut.write('(sb->getTypeCode() == {0})\n'.format(typecode))
    fileOut.write('  {\n')
    if typecode != 'SBML_LIST_OF':
      fileOut.write('    return SWIGTYPE_p_{0}{1}Plugin;\n'.format(strFunctions.cap(name), plugin['sbase']))
    else:

      fileOut.write('    std::string name = sb->getElementName();\n')
      fileOut.write('    if(name == "{0}")\n'.format(strFunctions.lowerFirst(plugin['sbase'])))
      fileOut.write('      return SWIGTYPE_p_{0}{1}Plugin;\n'.format(strFunctions.cap(name), plugin['sbase']))
    
    fileOut.write('  }\n')
  fileOut.write('}\n')
  fileOut.write('\n')
  fileOut.write('#endif // USE_{0} \n\n'.format(capName))

def writeLocal(fileOut, name, classes):
  capName = name.upper()
  fileOut.write('#ifdef USE_{0}\n\n'.format(capName))
  fileOut.write('SBMLCONSTRUCTOR_EXCEPTION({0}PkgNamespaces)\n'.format(strFunctions.cap(name)))
  for i in range (0, len(classes)):
    if classes[i]['typecode'] != 'HACK':
      fileOut.write('SBMLCONSTRUCTOR_EXCEPTION({0})\n'.format(classes[i]['name']))
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      loName = strFunctions.listOfName(classes[i]['name'])
      fileOut.write('SBMLCONSTRUCTOR_EXCEPTION({0})\n'.format(strFunctions.cap(loName)))
  fileOut.write('\n')
  
  for i in range (0, len(classes)):
    if (classes[i]['abstract'] == True or isBaseClassForOthers(classes[i], classes)):
      fileOut.write('/**\n')
      fileOut.write(' * Convert {0} objects into the most specific object possible.\n'.format(classes[i]['name']))
      fileOut.write(' */\n')
      fileOut.write('%typemap(out) {0}*\n'.format(classes[i]['name']))
      fileOut.write('{\n')
      fileOut.write('	$result = SWIG_NewPointerObj($1, GetDowncastSwigTypeForPackage($1, "{0}"), $owner | %newpointer_flags);\n'.format(name))
      fileOut.write('}\n')
      fileOut.write('\n')
  fileOut.write('\n')
  fileOut.write('#endif // USE_{0} \n\n'.format(capName))

def writeSwigHeader(fileOut, name, plugins, classes):
  capName = strFunctions.cap(name)
  fileOut.write('#ifdef USE_{0}\n\n'.format(name.upper()))
  fileOut.write('#include <sbml/packages/{0}/extension/{1}Extension.h>\n'.format(name, capName))
  alreadyIncluded = []
  for plugin in plugins:
    package = name
    if plugin.has_key('package') and plugin['package'] != None:
      package = plugin['package']
    capPackageName = strFunctions.cap(package)
    if package != name and alreadyIncluded.count(package) == 0:
      alreadyIncluded.append(package)
      fileOut.write('#include <sbml/packages/{0}/extension/{1}Extension.h>\n'.format(package, capPackageName))
      fileOut.write('#include <sbml/packages/{0}/common/{1}ExtensionTypes.h>\n'.format(package, capPackageName))
    fileOut.write('#include <sbml/packages/{0}/extension/{1}{2}Plugin.h>\n'.format(name, capName, plugin['sbase']))
  fileOut.write('#include <sbml/packages/{0}/common/{1}ExtensionTypes.h>\n'.format(name, capName))
  for clazz in classes:
    if clazz['typecode'] != 'HACK':
      fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(name, clazz['name']))
  fileOut.write('\n')
  fileOut.write('#endif // USE_{0} \n\n'.format(name.upper()))


def getClassByName (classes, name):
  for clazz in classes:
    if clazz['name'] == name:
      return clazz
  return None

# utility function that includes the base class first, ensuring that 
# swig knows about it 
def writeBaseClassFirst(classes, clazz, pkgName, fileOut, written):
  baseClass = 'SBase'
  if clazz.has_key('baseClass'): 
    baseClass = clazz['baseClass']
  if written.count(baseClass) == 0:
    written.append(baseClass)
    if generalFunctions.coreClasses().count(baseClass) == 0:
      base = getClassByName(classes, baseClass)
      if base != None:
        writeBaseClassFirst(classes, base, pkgName, fileOut, written)
  fileOut.write('%include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkgName, clazz['name']))
  written.append(clazz['name'])


def writeSwig(fileOut, name, plugins, classes):
  capName = strFunctions.cap(name)
  fileOut.write('#ifdef USE_{0}\n\n'.format(name.upper()))
  for i in range (0, len(classes)):
    if (classes[i]['hasListOf'] == True):
      fileOut.write('%newobject remove{0};\n'.format(classes[i]['name']))
  fileOut.write('\n%template ({0}PkgNamespaces) SBMLExtensionNamespaces<{0}Extension>;\n\n'.format(capName))
  fileOut.write('%include <sbml/packages/{0}/extension/{1}Extension.h>\n'.format(name, capName))
  for i in range (0, len(plugins)):
    fileOut.write('%include <sbml/packages/{0}/extension/{1}{2}Plugin.h>\n'.format(name, capName, plugins[i]['sbase']))
  written = []
  for clazz in classes:
    if clazz['typecode'] != 'HACK' and written.count(clazz['name']) == 0:
      # write out baseclass first if present and not a core class
      writeBaseClassFirst(classes, clazz, name, fileOut, written)
  fileOut.write('\n')
  fileOut.write('#endif /* USE_{0} */\n\n'.format(name.upper()))



