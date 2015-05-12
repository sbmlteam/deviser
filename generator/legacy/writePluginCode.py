#!/usr/bin/env python
#
# @file   writePluginCode.py
# @brief  Create the extension files for a new class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions

import writeCode

def writeClassDefn(fileOut, nameOfClass, pkg, members, attribs, plugin = None):
  writeConstructors(fileOut, nameOfClass, pkg, members, attribs)
  writeRequiredMethods(fileOut, nameOfClass, members, pkg, attribs, plugin)
  writeGetFunctions(fileOut, pkg, members, nameOfClass, attribs)
  writeOtherFunctions(fileOut, nameOfClass, members, attribs)

def writeOtherFunctions(fileOut, nameOfClass, members, attribs):
  fileOut.write('/*\n' )
  fileOut.write(' * Set the SBMLDocument.\n')
  fileOut.write(' */\n')
  fileOut.write('void\n')
  fileOut.write('{0}::setSBMLDocument(SBMLDocument* d)\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  SBasePlugin::setSBMLDocument(d);\n\n')
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
        fileOut.write('  if (getNum{0}s() > 0)\n'.format(mem['name']))
        fileOut.write('  {\n')
        fileOut.write('    m{0}s.setSBMLDocument(d);\n'.format(mem['name']))
        fileOut.write('  }\n')
    else:
      fileOut.write('  if (isSet{0}() == true)\n'.format(mem['name']))
      fileOut.write('  {\n')
      fileOut.write('    m{0}->setSBMLDocument(d);\n'.format(mem['name']))
      fileOut.write('  }\n')
  for i in range (0, len(attribs)):
    mem = attribs[i]
    if mem['type'] == 'lo_element' or mem['type'] == 'inline_lo_element':
        #fileOut.write('  if (getNum{0}s() > 0)\n'.format(strFunctions.cap(mem['name'])))
        fileOut.write('  {\n')
        fileOut.write('    m{0}s.setSBMLDocument(d);\n'.format(strFunctions.cap(mem['name'])))
        fileOut.write('  }\n')
    elif mem['type'] == 'element':
      #fileOut.write('  if (isSet{0}() == true)\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  {\n')
      fileOut.write('    m{0}->setSBMLDocument(d);\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  }\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n' )
  fileOut.write(' * Connect to parent.\n')
  fileOut.write(' */\n')
  fileOut.write('void\n')
  fileOut.write('{0}::connectToParent(SBase* sbase)\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  SBasePlugin::connectToParent(sbase);\n\n')
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
        fileOut.write('  if (getNum{0}s() > 0)\n'.format(mem['name']))
        fileOut.write('  {\n')
        fileOut.write('    m{0}s.connectToParent(sbase);\n'.format(mem['name']))
        fileOut.write('  }\n')
    else:
      fileOut.write('  if (isSet{0}() == true)\n'.format(mem['name']))
      fileOut.write('  {\n')
      fileOut.write('    m{0}->connectToParent(sbase);\n'.format(mem['name']))
      fileOut.write('  }\n')
  for i in range (0, len(attribs)):
    mem = attribs[i]
    if mem['type'] == 'lo_element' or mem['type'] == 'inline_lo_element':
        fileOut.write('  if (getNum{0}s() > 0)\n'.format(strFunctions.cap(mem['name'])))
        fileOut.write('  {\n')
        fileOut.write('    m{0}s.connectToParent(sbase);\n'.format(strFunctions.cap(mem['name'])))
        fileOut.write('  }\n')
    elif mem['type'] == 'element':
      fileOut.write('  if (isSet{0}() == true)\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  {\n')
      fileOut.write('    m{0}->connectToParent(sbase);\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  }\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n' )
  fileOut.write(' * Enables the given package.\n')
  fileOut.write(' */\n')
  fileOut.write('void\n')
  fileOut.write('{0}::enablePackageInternal(const std::string& pkgURI,\n'.format(nameOfClass))
  fileOut.write('                                   const std::string& pkgPrefix, bool flag)\n')
  fileOut.write('{\n')
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
        fileOut.write('  if (getNum{0}s() > 0)\n'.format(mem['name']))
        fileOut.write('  {\n')
        fileOut.write('    m{0}s.enablePackageInternal(pkgURI, pkgPrefix, flag);\n'.format(mem['name']))
        fileOut.write('  }\n')
    else:
      fileOut.write('  if (isSet{0}() == true)\n'.format(mem['name']))
      fileOut.write('  {\n')
      fileOut.write('    m{0}->enablePackageInternal(pkgURI, pkgPrefix, flag);\n'.format(mem['name']))
      fileOut.write('  }\n')
  for i in range (0, len(attribs)):
    mem = attribs[i]
    if mem['type'] == 'lo_element' or mem['type'] == 'inline_lo_element':
        fileOut.write('  if (getNum{0}s() > 0)\n'.format(strFunctions.cap(mem['name'])))
        fileOut.write('  {\n')
        fileOut.write('    m{0}s.enablePackageInternal(pkgURI, pkgPrefix, flag);\n'.format(strFunctions.cap(mem['name'])))
        fileOut.write('  }\n')
    elif mem['type'] == 'lo_element'  or mem['type'] == 'inline_lo_element':
      fileOut.write('  if (isSet{0}() == true)\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  {\n')
      fileOut.write('    m{0}->enablePackageInternal(pkgURI, pkgPrefix, flag);\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  }\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n' )
  fileOut.write(' * Accept the SBMLVisitor.\n')
  fileOut.write(' */\n')
  fileOut.write('bool\n')
  fileOut.write('{0}::accept(SBMLVisitor& v) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  const Model * model = static_cast<const Model * >(this->getParentSBMLObject());\n\n')
  fileOut.write('  v.visit(*model);\n')
  fileOut.write('  v.leave(*model);\n\n')
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
      fileOut.write('  for(unsigned int i = 0; i < getNum{0}s(); i++)\n'.format(mem['name']))
      fileOut.write('  {\n')
      fileOut.write('    get{0}(i)->accept(v);\n'.format(mem['name']))
      fileOut.write('  }\n\n')
  for i in range (0, len(attribs)):
    mem = attribs[i]
    if mem['type'] == 'lo_element'  or mem['type'] == 'inline_lo_element':
      fileOut.write('  for(unsigned int i = 0; i < getNum{0}s(); i++)\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  {\n')
      fileOut.write('    get{0}(i)->accept(v);\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  }\n\n')
  fileOut.write('  return true;\n')
  fileOut.write('}\n\n\n')

#  generalFunctions.writeSetDocHeader(fileOut)
#  # TO DO - these properly
#  fileOut.write('virtual void connectToParent (SBase* sbase);\n\n\n')
#  fileOut.write('virtual void enablePackageInternal(const std::string& pkgURI,\n')
#  fileOut.write('                                   const std::string& pkgPrefix, bool flag);\n\n\n')

def writeConstructors(fileOut, nameOfClass, pkg, members, attrs):
 # indent = strFunctions.getIndent(nameOfClass)
  fileOut.write('/*\n' )
  fileOut.write(' * Creates a new {0}\n'.format(nameOfClass))
  fileOut.write(' */\n')
  fileOut.write('{0}::{0}(const std::string& uri,  \n'.format(nameOfClass))
  fileOut.write('                                 const std::string& prefix, \n')
  fileOut.write('                               {0}PkgNamespaces* {1}ns) :\n'.format(pkg, pkg.lower()))
  fileOut.write('    SBasePlugin(uri, prefix, {0}ns)\n'.format(pkg.lower()))
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
      fileOut.write('  , m{0}s ({1}ns)\n'.format(mem['name'], pkg.lower()))
    else:
      fileOut.write('  , m{0}  ( NULL )\n'.format(mem['name']))
  writeCode.writeAttributes(attrs, fileOut, 2, pkg.lower())
  fileOut.write('{\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n' )
  fileOut.write(' * Copy constructor for {0}.\n'.format(nameOfClass))
  fileOut.write(' */\n')
  fileOut.write('{0}::{0}(const {1}& orig) :\n'.format(nameOfClass, nameOfClass))
  fileOut.write('    SBasePlugin(orig)\n')
  for i in range (0, len(members)):
    mem = members[i]    
    if mem['isListOf'] == True:
      fileOut.write('  , m{0}s ( orig.m{0}s)\n'.format(mem['name']))
    else:
      fileOut.write('  , m{0} ( NULL )\n'.format(mem['name']))
  fileOut.write('{\n')
  for i in range (0, len(members)):
    mem = members[i]    
    if mem['isListOf'] == False:
      fileOut.write('  if (orig.m{0} != NULL)\n'.format(mem['name']))
      fileOut.write('  {\n')
      fileOut.write('    m{0} = orig.m{0}->clone();\n'.format(mem['name']))
      fileOut.write('  }\n')
  writeCode.writeCopyAttributes(attrs, fileOut, '    ', 'orig')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n' )
  fileOut.write(' * Assignment operator for {0}.\n'.format(nameOfClass))
  fileOut.write(' */\n')
  fileOut.write('{0}& \n'.format(nameOfClass))
  fileOut.write('{0}::operator=(const {0}& rhs)\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  if (&rhs != this)\n')
  fileOut.write('  {\n')
  fileOut.write('    this->SBasePlugin::operator=(rhs);\n')
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
      fileOut.write('    m{0}s = rhs.m{0}s;\n'.format(mem['name']))
    else:
      fileOut.write('    delete m{0};\n'.format(mem['name']))
      fileOut.write('    m{0} = NULL;\n'.format(mem['name']))
      fileOut.write('    if (rhs.m{0} != NULL)\n'.format(mem['name']))
      fileOut.write('      m{0} = rhs.m{0}->clone();\n'.format(mem['name']))
  writeCode.writeCopyAttributes(attrs, fileOut, '    ', 'rhs')
  fileOut.write('  }\n\n')
  fileOut.write('  return *this;\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n' )
  fileOut.write(' * Creates and returns a deep copy of this {0} object.\n'.format(nameOfClass))
  fileOut.write(' */\n')
  fileOut.write('{0}* \n'.format(nameOfClass))
  fileOut.write('{0}::clone () const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return new {0}(*this);\n'.format(nameOfClass))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n' )
  fileOut.write(' * Destructor for {0}.\n'.format(nameOfClass))
  fileOut.write(' */\n')
  fileOut.write('{0}::~{0}()\n'.format(nameOfClass))
  fileOut.write('{\n')
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == False:
      fileOut.write('  delete m{0};\n'.format(mem['name']))
      fileOut.write('  m{0} = NULL;\n'.format(mem['name']))
  fileOut.write('}\n\n\n')

def writeGetFunctions(fileOut, pkg, members, nameOfClass, attribs):
  fileOut.write('//---------------------------------------------------------------\n')
  fileOut.write('//\n')
  fileOut.write('// Functions for interacting with the members of the plugin\n')
  fileOut.write('//\n')
  fileOut.write('//---------------------------------------------------------------\n\n')
  generalFunctions.writeGetAllElementsCodePlug(fileOut, nameOfClass, members, attribs)
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
      writeLOFunctions(fileOut, mem['name'], nameOfClass, pkg)
    else:
      writeFunctions(fileOut, mem['name'], nameOfClass, pkg)
  if len(attribs) > 0:
    writeCode.writeAttributeCode(attribs, fileOut, nameOfClass, pkg, dict({}));
  fileOut.write('//---------------------------------------------------------------\n\n\n')
  
def writeFunctions(fileOut, object, nameOfClass, pkg):
  ob = strFunctions.lowerFirst(object) 
  fileOut.write('/*\n')
  fileOut.write(' * Returns the {0} from this {1} object.\n'.format(object, nameOfClass))
  fileOut.write(' */\n')
  fileOut.write('const {0}* \n'.format(object))
  fileOut.write('{0}::get{1} () const\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  return m{0};\n'.format(object))
  fileOut.write('}\n\n\n')

  fileOut.write('/*\n')
  fileOut.write(' * Returns the {0} from this {1} object.\n'.format(object, nameOfClass))
  fileOut.write(' */\n')
  fileOut.write('{0}* \n'.format(object))
  fileOut.write('{0}::get{1} ()\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  return m{0};\n'.format(object))
  fileOut.write('}\n\n\n')
  
  fileOut.write('/*\n')
  fileOut.write(' * @return @c true if the \"{0}\"'.format(object))
  fileOut.write(' element has been set,\n')
  fileOut.write(' */\n')
  fileOut.write('bool \n'.format(object))
  fileOut.write('{0}::isSet{1} () const\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  return (m{0} != NULL);\n'.format(object))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Sets the {0} element in this {1} object.\n'.format(object, nameOfClass))
  fileOut.write(' */\n')
  fileOut.write('int\n'.format(object))
  fileOut.write('{0}::set{1}(const {1}* {2})\n'.format(nameOfClass, object, ob))
  fileOut.write('{\n')
  fileOut.write('  if ({0} == NULL)\n'.format(ob))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_OPERATION_FAILED;\n')
  fileOut.write('  }\n')
  fileOut.write('  else if ({0}->hasRequiredElements() == false)\n'.format(ob))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_INVALID_OBJECT;\n')
  fileOut.write('  }\n')
  fileOut.write('  else if (getLevel() != {0}->getLevel())\n'.format(ob))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_LEVEL_MISMATCH;\n')
  fileOut.write('  }\n')
  fileOut.write('  else if (getVersion() != {0}->getVersion())\n'.format(ob))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_VERSION_MISMATCH;\n')
  fileOut.write('  }\n')
  fileOut.write('  else if (getPackageVersion() != {0}->getPackageVersion())\n'.format(ob))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_PKG_VERSION_MISMATCH;\n')
  fileOut.write('  }\n')
  fileOut.write('  else\n')
  fileOut.write('  {\n')
  fileOut.write('    delete m{0};\n'.format(object))
  fileOut.write('    m{0} = static_cast<{0}*>({1}->clone());\n'.format(object, ob))
  fileOut.write('    return LIBSBML_OPERATION_SUCCESS;\n')
  fileOut.write('  }\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Creates a new {0} object and adds it to the {1} object.\n'.format(object, nameOfClass))
  fileOut.write(' */\n')
  fileOut.write('{0}*\n'.format(object))
  fileOut.write('{0}::create{1}()\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  delete m{0};\n'.format(object))
  fileOut.write('  {0}_CREATE_NS({1}ns, getSBMLNamespaces());\n'.format(pkg.upper(), pkg.lower()))
  fileOut.write('  m{0} = new {0}({1}ns);\n\n'.format(object, pkg.lower()))
  fileOut.write('  m{0}->setSBMLDocument(this->getSBMLDocument());\n\n'.format(object))
  fileOut.write('  delete {0}ns;\n\n'.format(pkg.lower()))
  fileOut.write('  return m{0};\n'.format(object))
  fileOut.write('}\n\n\n')

def writeLOFunctions(fileOut, object, nameOfClass, pkg):
  ob = strFunctions.objAbbrev(object) 
  fileOut.write('/*\n')
  fileOut.write(' * Returns the ListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write(' */\n')
  fileOut.write('const ListOf{0}s* \n'.format(object))
  fileOut.write('{0}::getListOf{1}s () const\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  return &this->m{0}s;\n'.format(object))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the ListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write(' */\n')
  fileOut.write('ListOf{0}s* \n'.format(object))
  fileOut.write('{0}::getListOf{1}s ()\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  return &this->m{0}s;\n'.format(object))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the {0} object that belongs to the given index.\n'.format(object)) 
  fileOut.write(' */\n')
  fileOut.write('const {0}*\n'.format(object))
  fileOut.write('{0}::get{1}(unsigned int n) const\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  return static_cast<const {0}*>(m{0}s.get(n));\n'.format(object))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the {0} object that belongs to the given index.\n'.format(object)) 
  fileOut.write(' */\n')
  fileOut.write('{0}*\n'.format(object))
  fileOut.write('{0}::get{1}(unsigned int n)\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  return static_cast<{0}*>(m{0}s.get(n));\n'.format(object))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the {0} object based on its identifier.\n'.format(object)) 
  fileOut.write(' */\n')
  fileOut.write('const {0}*\n'.format(object))
  fileOut.write('{0}::get{1}(const std::string& sid) const\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  return static_cast<const {0}*>(m{0}s.get(sid));\n'.format(object))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the {0} object based on its identifier.\n'.format(object)) 
  fileOut.write(' */\n')
  fileOut.write('{0}*\n'.format(object))
  fileOut.write('{0}::get{1}(const std::string& sid)\n'.format(nameOfClass, object))
  fileOut.write('{\n')
  fileOut.write('  return static_cast<{0}*>(m{0}s.get(sid));\n'.format(object))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Adds a copy of the given {0} to the ListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write(' */\n')
  fileOut.write('int\n')
  fileOut.write('{2}::add{0} (const {0}* {1})\n'.format(object, strFunctions.lowerFirst(object), nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  if ({0} == NULL)\n'.format(strFunctions.lowerFirst(object)))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_OPERATION_FAILED;\n')
  fileOut.write('  }\n')
  fileOut.write('  else if ({0}->hasRequiredElements() == false)\n'.format(strFunctions.lowerFirst(object)))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_INVALID_OBJECT;\n')
  fileOut.write('  }\n')
  fileOut.write('  else if (getLevel() != {0}->getLevel())\n'.format(strFunctions.lowerFirst(object)))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_LEVEL_MISMATCH;\n')
  fileOut.write('  }\n')
  fileOut.write('  else if (getVersion() != {0}->getVersion())\n'.format(strFunctions.lowerFirst(object)))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_VERSION_MISMATCH;\n')
  fileOut.write('  }\n')
  fileOut.write('  else if (getPackageVersion() != {0}->getPackageVersion())\n'.format(strFunctions.lowerFirst(object)))
  fileOut.write('  {\n')
  fileOut.write('    return LIBSBML_PKG_VERSION_MISMATCH;\n')
  fileOut.write('  }\n')
  fileOut.write('  else\n')
  fileOut.write('  {\n')
  fileOut.write('    m{0}s.append({1});\n'.format(object, strFunctions.lowerFirst(object)))
  fileOut.write('  }\n\n')
  fileOut.write('  return LIBSBML_OPERATION_SUCCESS;\n\n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Creates a new {0} object and adds it to the ListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write(' */\n')
  fileOut.write('{0}* \n'.format(object))
  fileOut.write('{1}::create{0} ()\n'.format(object, nameOfClass))
  fileOut.write('{\n')
  fileOut.write('   {0}* {1} = NULL;\n\n'.format(object, ob))
  fileOut.write('  try\n')
  fileOut.write('  {\n')
  fileOut.write('    {0}_CREATE_NS({1}ns, getSBMLNamespaces());\n'.format(pkg.upper(), pkg.lower()))
  fileOut.write('    {0} = new {1}({2}ns);\n'.format(ob, object, pkg.lower()))
  fileOut.write('    delete {0}ns;\n'.format(pkg.lower()))
  fileOut.write('  }\n')
  fileOut.write('  catch(...)\n')
  fileOut.write('  {\n')
  fileOut.write('  }\n\n')
  fileOut.write('  if ({0} != NULL)\n'.format(ob))
  fileOut.write('  {\n')
  fileOut.write('    m{0}s.appendAndOwn({1});\n'.format(object, ob))
  fileOut.write('  }\n\n')
  fileOut.write('  return {0};\n'.format(ob))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Removes the nth {0} object from this plugin object\n'.format(object)) 
  fileOut.write(' */\n')
  fileOut.write('{0}* \n'.format(object))
  fileOut.write('{1}::remove{0}(unsigned int n)\n'.format(object, nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return static_cast<{0}*>(m{0}s.remove(n));\n'.format(object))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Removes the {0} object with the given id from this plugin object\n'.format(object)) 
  fileOut.write(' */\n')
  fileOut.write('{0}* \n'.format(object))
  fileOut.write('{1}::remove{0}(const std::string& sid)\n'.format(object, nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return static_cast<{0}*>(m{0}s.remove(sid));\n'.format(object))
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Returns the number of {0} objects in this plugin object.\n'.format(object))
  fileOut.write(' */\n')
  fileOut.write('unsigned int \n')
  fileOut.write('{1}::getNum{0}s () const\n'.format(object, nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  return m{0}s.size();\n'.format(object))
  fileOut.write('}\n\n\n')



# write the include files
def writeIncludes(fileOut, pkg, element):
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/packages/{0}/extension/{1}.h>\n'.format(pkg.lower(), element))
  fileOut.write('#include <sbml/packages/{0}/validator/{1}SBMLError.h>\n'.format(pkg.lower(), pkg))
  fileOut.write('#include <sbml/util/ElementFilter.h>\n'.format(pkg.lower(), pkg))
  fileOut.write('#include <sbml/Model.h>\n'.format(pkg.lower(), pkg))
  fileOut.write('\n\n');
  fileOut.write('using namespace std;\n')
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

def writeIncludeEnds(fileOut, element):
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_END\n')
  fileOut.write('\n\n');
  fileOut.write('#endif /* __cplusplus */\n\n\n')

def writeRequiredMethods(fileOut, nameOfClass, members, pkg, attribs, plugin = None):
  fileOut.write('//---------------------------------------------------------------\n')
  fileOut.write('//\n')
  fileOut.write('// overridden virtual functions for read/write/check\n')
  fileOut.write('//\n')
  fileOut.write('//---------------------------------------------------------------\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * create object\n')
  fileOut.write(' */\n')
  fileOut.write('SBase*\n')
  fileOut.write('{0}::createObject (XMLInputStream& stream)\n'.format(nameOfClass))
  fileOut.write('{\n')

  numMembers = len(members)
  numAttribs = generalFunctions.countMembers(attribs)

  if numMembers + numAttribs > 0: 
    fileOut.write('  SBase* object = NULL; \n\n')
    fileOut.write('  const std::string&      name   = stream.peek().getName(); \n')
    fileOut.write('  const XMLNamespaces&    xmlns  = stream.peek().getNamespaces(); \n')
    fileOut.write('  const std::string&      prefix = stream.peek().getPrefix(); \n\n')
    fileOut.write('  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ? xmlns.getPrefix(mURI) : mPrefix;\n\n')
    fileOut.write('  if (prefix == targetPrefix) \n')
    fileOut.write('  { \n')
    fileOut.write('    {0}_CREATE_NS({1}ns, getSBMLNamespaces());\n'.format(pkg.upper(), pkg.lower()))
    ifCount = 1
    for i in range (0, len(members)):
      mem = members[i]
      if mem['isListOf'] == True:
        writeCreateLOObject(fileOut, mem, ifCount)
      else:
        writeCreateObject(fileOut, mem, ifCount, pkg)
      ifCount = ifCount + 1  
    for i in range (0, len(attribs)):
      mem = attribs[i]
      if mem['type'] == 'lo_element' or mem['type'] == 'inline_lo_element':
        writeCreateLOObject(fileOut, mem, ifCount)
        ifCount = ifCount + 1
      elif mem['type'] == 'element':
        writeCreateObject(fileOut, mem, ifCount, pkg)
        ifCount = ifCount + 1
    fileOut.write('\n    delete {0}ns;\n'.format(pkg.lower()))
    fileOut.write('  } \n\n')
    fileOut.write('  return object; \n')
  else: 
    fileOut.write('  return NULL; \n')
  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * write elements\n')
  fileOut.write(' */\n')
  fileOut.write('void\n')
  fileOut.write('{0}::writeElements (XMLOutputStream& stream) const\n'.format(nameOfClass))
  fileOut.write('{\n')
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
      fileOut.write('  if (getNum{0}() > 0) \n'.format(strFunctions.capp(mem['name'])))
      fileOut.write('  { \n')
      fileOut.write('    m{0}s.write(stream);\n'.format(mem['name']))
      fileOut.write('  } \n')
    else:
      fileOut.write('  if (isSet{0}() == true) \n'.format(mem['name']))
      fileOut.write('  { \n')
      fileOut.write('    m{0}->write(stream);\n'.format(mem['name']))
      fileOut.write('  } \n')

  for i in range (0, len(attribs)):
    mem = attribs[i]
    if mem['type'] == 'lo_element' or mem['type'] == 'inline_lo_element':
      fileOut.write('  if (getNum{0}() > 0) \n'.format(strFunctions.capp(mem['name'])))
      fileOut.write('  { \n')
      fileOut.write('    m{0}s.write(stream);\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  } \n')
    elif mem['type'] == 'element':
      fileOut.write('  if (isSet{0}() == true) \n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  { \n')
      fileOut.write('    m{0}->write(stream);\n'.format(strFunctions.cap(mem['name'])))
      fileOut.write('  } \n')

  fileOut.write('}\n\n\n')
  fileOut.write('/*\n')
  fileOut.write(' * Checks if this plugin object has all the required elements.\n')
  fileOut.write(' */\n')
  fileOut.write('bool\n')
  fileOut.write('{0}::hasRequiredElements () const\n'.format(nameOfClass))
  fileOut.write('{\n')
  fileOut.write('  bool allPresent = true; \n\n')
  fileOut.write('  // TO DO \n\n')
  fileOut.write('  return allPresent; \n')
  fileOut.write('}\n\n\n')

  generalFunctions.writeAddExpectedCPPCode(fileOut, nameOfClass, attribs, 'SBasePlugin')
  generalFunctions.writeReadAttributesCPPCode(fileOut, nameOfClass, attribs, pkg, False, 'SBasePlugin', plugin)
  generalFunctions.writeWriteAttributesCPPCode(fileOut, nameOfClass, attribs, 'SBasePlugin')

def writeCreateObject(fileOut, mem, ifCount, pkg):
  name = strFunctions.cap(mem['name'])
  if ifCount == 1:
    fileOut.write('    if (name == "{0}" ) \n'.format(strFunctions.lowerFirst(name)))
  else:
    fileOut.write('    else if (name == "{0}" ) \n'.format(strFunctions.lowerFirst(name)))
  fileOut.write('    { \n')
  fileOut.write('      m{0} = new {0}({1}ns);\n\n'.format(name, pkg.lower()))
  fileOut.write('      object = m{0};\n\n'.format(name))
  fileOut.write('    } \n')

def writeCreateLOObject(fileOut, mem, ifCount):
  name = strFunctions.cap(mem['name'])
  if ifCount == 1:
    fileOut.write('    if (name == "listOf{0}s" ) \n'.format(name))
  else:
    fileOut.write('    else if (name == "listOf{0}s" ) \n'.format(name))
  fileOut.write('    { \n')
  fileOut.write('      object = &m{0}s;\n\n'.format(name))
  fileOut.write('      if (targetPrefix.empty() == true) \n')
  fileOut.write('      { \n')
  fileOut.write('        m{0}s.getSBMLDocument()->enableDefaultNS(mURI, true); \n'.format(name))
  fileOut.write('      } \n')
  fileOut.write('    } \n')

def createCode(package, plugin):
  nameOfPackage = package['name']
  nameOfPlugin = plugin['sbase']
  nameOfClass = nameOfPackage + nameOfPlugin + 'Plugin'
  codeName = nameOfClass + '.cpp'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfClass)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfPackage, nameOfClass)
  writeClassDefn(code, nameOfClass, nameOfPackage, plugin['extension'],plugin['attribs'], plugin)
  
  if plugin.has_key('addDefs'):
    code.write(open(plugin['addDefs'], 'r').read())

  writeIncludeEnds(code, nameOfClass)



  