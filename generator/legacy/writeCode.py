#!/usr/bin/env python
#
# @file   writeCode.py
# @brief  Create the cpp file for a new class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions
import createNewElementDictObj
import writeListOfCode
import writeCCode


def writeIncludesForDict(fileOut, pkg, elementDict):
  if elementDict.has_key('concrete'):
    fileOut.write('\n')      
    for elem in generalFunctions.getConcretes(elementDict['root'], elementDict['concrete']):
      fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkg.lower(), elem['element']))
    fileOut.write('\n')
  if elementDict.has_key('attribs'):
    attribs = elementDict['attribs']
    for i in range(0, len(attribs)):
      writeIncludesForDict(fileOut, pkg, attribs[i])

def writeIncludes(fileOut, element, pkg, hasMath, elementDict):
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkg.lower(), element))
  fileOut.write('#include <sbml/packages/{0}/validator/{1}SBMLError.h>\n'.format(pkg.lower(), pkg))
  fileOut.write('#include <sbml/util/ElementFilter.h>\n')
  writeIncludesForDict(fileOut, pkg, elementDict)
  if hasMath == True:
    fileOut.write('#include <sbml/math/MathML.h>\n')
  fileOut.write('\n\n');
  #  fileOut.write('#if WIN32 && !defined(CYGWIN)\n')
  #  fileOut.write('  #define isnan _isnan\n')
  #  fileOut.write('#endif\n')
  #  fileOut.write('\n\n');
  fileOut.write('using namespace std;\n')
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

# writes list of attributes
def writeAttributes(attrs, output, constType=0, pkg=""):
  for i in range(0, len(attrs)):
    writeAtt(attrs[i]['type'], attrs[i]['name'], output, constType, pkg, attrs[i])
  #  output.write('\n')


def writeAtt(atttype, name, output, constType, pkg, attrib):
  if atttype == 'SId' or atttype == 'SIdRef' or atttype == 'UnitSId' or atttype == 'UnitSIdRef' or atttype == 'string':
    output.write('  , m{0} ("")\n'.format(strFunctions.cap(name)))
  elif atttype == 'element':
    output.write('  , m{0} (NULL)\n'.format(strFunctions.cap(name)))
  elif atttype == 'lo_element' or atttype == 'inline_lo_element':
    if name.endswith('x'):
      output.write('  , m{0}es ('.format(strFunctions.cap((name))))
    else:
      output.write('  , m{0}{1} ('.format(strFunctions.cap(name), '' if name.endswith('s') else 's' ))
    if constType == 0:
      output.write(')\n')
    elif constType == 1:
      output.write('level, version, pkgVersion)\n')
    elif constType == 2:
      output.write('{0}ns)\n'.format(pkg))
  elif atttype == 'double':
    output.write('  , m{0} (numeric_limits<double>::quiet_NaN())\n'.format(strFunctions.cap(name)))
    output.write('  , mIsSet{0} (false)\n'.format(strFunctions.cap(name)))
  elif atttype == 'int' or atttype == 'uint':
    output.write('  , m{0} (SBML_INT_MAX)\n'.format(strFunctions.cap(name)))
    output.write('  , mIsSet{0} (false)\n'.format(strFunctions.cap(name)))
  elif atttype == 'bool':
    output.write('  , m{0} (false)\n'.format(strFunctions.cap(name)))
    output.write('  , mIsSet{0} (false)\n'.format(strFunctions.cap(name)))
  elif atttype == 'enum':
    output.write('  , m{0} ({1}_UNKNOWN)\n'.format(strFunctions.cap(name), attrib['element'].upper()))
  elif atttype == 'array':
    output.write('  , m{0} (NULL)\n'.format(strFunctions.cap(name)))
  else:
    output.write('  FIX ME   {0};\n'.format(name))


def writeCopyAttributes(attrs, output, tabs, name):
  for i in range(0, len(attrs)):
    attName = strFunctions.cap(attrs[i]['name'])
    atttype = attrs[i]['type']
    if atttype == 'array':
      output.write('{0}m{1}  = NULL;\n'.format(tabs, attName, name))
      output.write('{0}set{1}({2}.m{1}, {2}.m{1}Length);\n'.format(tabs, attName, name))
    elif atttype != 'lo_element' and  atttype != 'inline_lo_element':
      if atttype != 'element':
        output.write('{0}m{1}  = {2}.m{1};\n'.format(tabs, attName, name))
      else:
        output.write('{0}if ({2}.m{1} != NULL)\n'.format(tabs, strFunctions.cap(attrs[i]['name']), name))
        output.write('{0}'.format(tabs))
        output.write('{\n')
        if attrs[i]['name'] != 'math':
          output.write('{0}  m{1} = {2}.m{1}->clone();\n'.format(tabs, strFunctions.cap(attrs[i]['name']), name))
        else:
          output.write('{0}  m{1} = {2}.m{1}->deepCopy();\n'.format(tabs, strFunctions.cap(attrs[i]['name']), name))
        output.write('{0}'.format(tabs))
        output.write('}\n')
        output.write('{0}else\n'.format(tabs))
        output.write('{0}'.format(tabs))
        output.write('{\n')
        output.write('{0}  m{1} = NULL;\n'.format(tabs, strFunctions.cap(attrs[i]['name'])))
        output.write('{0}'.format(tabs))
        output.write('}\n')
    else:
      if attName.endswith('x'):
        output.write('{0}m{1}es  = {2}.m{1}es;\n'.format(tabs, attName, name))
      elif attName.endswith('s'):
        output.write('{0}m{1}  = {2}.m{1};\n'.format(tabs, attName, name))
      else:
        output.write('{0}m{1}s  = {2}.m{1}s;\n'.format(tabs, attName, name))
    if atttype == 'double' or atttype == 'int' or atttype == 'uint' or atttype == 'bool':
      output.write('{0}mIsSet{1}  = {2}.mIsSet{1};\n'.format(tabs, attName, name))


def writeConstructors(element, package, output, attrs, hasChildren=False, hasMath=False, elementDict=None, childrenOverwrite=False):
  baseClass = 'SBase'
  if elementDict != None and elementDict.has_key('baseClass'):
    baseClass = elementDict['baseClass']
  output.write('/*\n')
  output.write(' * Creates a new {0}'.format(element))
  output.write(' with the given level, version, and package version.\n */\n')
  output.write('{0}::{0} (unsigned int level, unsigned int version, unsigned int pkgVersion)\n'.format(element))
  output.write('  : {0}(level, version)\n'.format(baseClass))
  writeAttributes(attrs, output, 1)
  if childrenOverwrite:
    output.write('  , mElementName("{0}")\n'.format(strFunctions.lowerFirst(elementDict['name'])))
  output.write('{\n')
  output.write('  // set an SBMLNamespaces derived object of this package\n')
  output.write('  setSBMLNamespacesAndOwn(new {0}PkgNamespaces(level, version, pkgVersion));\n'.format(package))
  if hasChildren == True or hasMath == True:
    output.write('\n  // connect to child objects\n')
    output.write('  connectToChild();\n')
  output.write('}\n\n\n')
  output.write('/*\n')
  output.write(' * Creates a new {0}'.format(element))
  output.write(' with the given {0}PkgNamespaces object.\n */\n'.format(package))
  output.write('{0}::{0} ({1}PkgNamespaces* {2}ns)\n'.format(element, package, package.lower()))
  output.write('  : {1}({0}ns)\n'.format(package.lower(), baseClass))
  writeAttributes(attrs, output, 2, package.lower())
  if childrenOverwrite:
    output.write('  , mElementName("{0}")\n'.format(strFunctions.lowerFirst(elementDict['name'])))
  output.write('{\n')
  output.write('  // set the element namespace of this object\n')
  output.write('  setElementNamespace({0}ns->getURI());\n'.format(package.lower()))
  if hasChildren == True:
    output.write('\n  // connect to child objects\n')
    output.write('  connectToChild();\n')
  output.write('\n  // load package extensions bound with this object (if any) \n')
  output.write('  loadPlugins({0}ns);\n'.format(package.lower()))
  output.write('}\n\n\n')
  output.write('/*\n')
  output.write(' * Copy constructor for {0}.\n */\n'.format(element))
  output.write('{0}::{0} (const {0}& orig)\n'.format(element, package, package.lower()))
  output.write('  : {0}(orig)\n'.format(baseClass))
  output.write('{\n')
  output.write('  if (&orig == NULL)\n')
  output.write('  {\n')
  output.write('    throw SBMLConstructorException("Null argument to copy constructor");\n')
  output.write('  }\n')
  output.write('  else\n')
  output.write('  {\n')
  writeCopyAttributes(attrs, output, '    ', 'orig')
  if childrenOverwrite:
    output.write('    mElementName = orig.mElementName;\n')

  if hasChildren == True:
    output.write('\n    // connect to child objects\n')
    output.write('    connectToChild();\n')
  output.write('  }\n')
  output.write('}\n\n\n')
  output.write('/*\n')
  output.write(' * Assignment for {0}.\n */\n'.format(element))
  output.write('{0}&\n{0}::operator=(const {0}& rhs)\n'.format(element))
  output.write('{\n')
  output.write('  if (&rhs == NULL)\n')
  output.write('  {\n')
  output.write('    throw SBMLConstructorException("Null argument to assignment");\n')
  output.write('  }\n')
  output.write('  else if (&rhs != this)\n')
  output.write('  {\n')
  output.write('    {0}::operator=(rhs);\n'.format(baseClass))
  writeCopyAttributes(attrs, output, '    ', 'rhs')
  if childrenOverwrite:
    output.write('    mElementName = rhs.mElementName;\n')

  if hasChildren == True:
    output.write('\n    // connect to child objects\n')
    output.write('    connectToChild();\n')
  output.write('  }\n')
  output.write('  return *this;\n')
  output.write('}\n\n\n')
  output.write('/*\n')
  output.write(' * Clone for {0}.\n */\n'.format(element))
  output.write('{0}*\n{0}::clone () const\n'.format(element))
  output.write('{\n')
  output.write('  return new {0}(*this);\n'.format(element))
  output.write('}\n\n\n')
  output.write('/*\n')
  output.write(' * Destructor for {0}.\n */\n'.format(element))
  output.write('{0}::~{0} ()\n'.format(element))
  output.write('{\n')
  if hasMath == True:
    output.write('  delete mMath;\n')
    output.write('  mMath = NULL;\n')
  for i in range (0, len(attrs)):
    current = attrs[i];
    if current['type'] == 'element' and current['name'] != 'math':
      output.write('  delete m{0};\n'.format(strFunctions.cap(current['name'])))
      output.write('  m{0} = NULL;\n'.format(strFunctions.cap(current['name'])))
    elif current['type'] == 'array':      
      output.write('  if (m{0} != NULL)\n'.format(strFunctions.cap(current['name'])))
      output.write('    delete[] m{0};\n'.format(strFunctions.cap(current['name'])))
      output.write('  m{0} = NULL;\n'.format(strFunctions.cap(current['name'])))

  output.write('}\n\n\n')


def writeGetCode(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  if attType == 'lo_element' or attType == 'inline_lo_element':
    return

  if attrib['type'] == 'array':
    output.write('/*\n');
    output.write(' * The "{0}" attribute of this {1} is returned in an {2} array (pointer)\n'.format(attName, element, attTypeCode));
    output.write(' * that is passed as argument to the method (this is needed while using SWIG to\n');
    output.write(' * convert int[] from C++ to Java). The method itself has a return type void.\n');
    output.write(' *\n');
    output.write(' * NOTE: you have to pre-allocate the array with the correct length!'); 
    output.write(' *\n');
    output.write(' * @return void.\n');
    output.write(' */\n');
    output.write('void\n{0}::get{1}({2} outArray) const\n'.format(element,capAttName, attTypeCode));
    output.write('{\n');
    output.write('   if (outArray == NULL || m{0} == NULL) return;\n\n'.format(capAttName))
    output.write('   memcpy(outArray , m{0}, sizeof({1})*m{0}Length);\n'.format(capAttName, attrib['element']));
    output.write('}\n\n\n');
    return

  output.write('/*\n')
  output.write(' * Returns the value of the \"{0}\"'.format(attName))
  output.write(' attribute of this {0}.\n'.format(element))
  output.write(' */\n')
  if attType == 'element' and attTypeCode != 'const ASTNode*':
    output.write('const {0}\n'.format(attTypeCode))
  else:
    output.write('{0}\n'.format(attTypeCode))
  output.write('{0}::get{1}() const\n'.format(element, capAttName))
  output.write('{\n')
  output.write('  return m{0};\n'.format(capAttName))
  output.write('}\n\n\n')

  if attType == 'element' and attName != 'math':
    # return non-const elements as well
    output.write('/*\n')
    output.write(' * Returns the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write(' */\n')
    output.write('{0}\n'.format(attTypeCode))
    output.write('{0}::get{1}()\n'.format(element, capAttName))
    output.write('{\n')
    output.write('  return m{0};\n'.format(capAttName))
    output.write('}\n\n\n')

    pkgName = attrib['root']['name']

    if attrib['abstract'] == False:
      output.write('/*\n')
      output.write(' * Creates a new \"{0}\"'.format(attName))
      output.write(' element of this {0} and returns it.\n'.format(element))
      output.write(' */\n')
      output.write('{0}\n'.format(attTypeCode))
      output.write('{0}::create{1}()\n'.format(element, capAttName))
      output.write('{\n')
      if attName == 'math' or attName == 'Math' or attType == 'XMLNode*':
        output.write('  if (m{0} != NULL) delete m{0};\n'.format(capAttName))
        output.write('  m{0} = new {1}();\n'.format(capAttName, attrib['element']))
        output.write('  return m{0};\n'.format(capAttName))
      else:
        output.write('  if (m{0} != NULL) delete m{0};\n'.format(capAttName))
        output.write('  {0}_CREATE_NS({1}ns, getSBMLNamespaces());\n'.format(pkgName.upper(), pkgName.lower()))
        output.write('  m{0} = new {1}({2}ns);\n'.format(capAttName, attrib['element'], pkgName.lower()))
        if generalFunctions.overridesElementName(attrib):
          output.write('  m{0}->setElementName("{1}");\n'.format(capAttName, attrib['name']));
        output.write('  delete {0}ns;\n'.format(pkgName.lower()))
        output.write('  connectToChild();\n'.format(pkgName.lower()))          
        output.write('  return m{0};\n'.format(capAttName))
      output.write('}\n\n\n')
    else:
      for concrete in generalFunctions.getConcretes(attrib['root'], attrib['concrete']):
        output.write('/*\n')
        output.write(' * Creates a new \"{0}\"'.format(attName))
        output.write(' element of this {0} and returns it.\n'.format(element))
        output.write(' */\n')
        output.write('{0}*\n'.format(concrete['element']))
        output.write('{0}::create{1}()\n'.format(element, strFunctions.cap(concrete['name'])))
        output.write('{\n')
        output.write('  if (m{0} != NULL) delete m{0};\n'.format(capAttName))
        output.write('  {0}_CREATE_NS({1}ns, getSBMLNamespaces());\n'.format(pkgName.upper(), pkgName.lower()))
        output.write('  m{0} = new {1}({2}ns);\n'.format(capAttName, concrete['element'], pkgName.lower()))
        if generalFunctions.overridesElementName(concrete):
          output.write('  m{0}->setElementName("{1}");\n'.format(capAttName, attrib['name']));
        output.write('  delete {0}ns;\n'.format(pkgName.lower()))
        output.write('  connectToChild();\n'.format(pkgName.lower()))          
        output.write('  return static_cast<{0}*>(m{1});\n'.format(concrete['element'], capAttName))
        output.write('}\n\n\n')


def writeIsSetCode(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attType == 'lo_element' or attType == 'inline_lo_element':
    return
  output.write('/*\n')
  output.write(' * Returns true/false if {0} is set.\n'.format(attName))
  output.write(' */\n')
  output.write('bool\n')
  output.write('{0}::isSet{1}() const\n'.format(element, capAttName))
  output.write('{\n')
  if attType == 'string':
    output.write('  return (m{0}.empty() == false);\n'.format(capAttName))
  elif attType == 'element' or attType == 'XMLNode*':
    output.write('  return (m{0} != NULL);\n'.format(capAttName))
  elif num == True:
    output.write('  return mIsSet{0};\n'.format(capAttName))
  elif attType == 'boolean':
    output.write('  return mIsSet{0};\n'.format(capAttName))
  elif attrib['type'] == 'enum':
    output.write('  return m{0} != {1}_UNKNOWN;\n'.format(capAttName, attrib['element'].upper()))
  elif attrib['type'] == 'array':
    output.write('  return (m{0} != NULL);\n'.format(capAttName))
  output.write('}\n\n\n')


def writeSetCode(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  cleanName = strFunctions.cleanStr(attName)
  capAttName = att[1]
  attType = att[2]
  if attType == 'string':
    attTypeCode = 'const std::string&'
  else:
    attTypeCode = att[3]
  num = att[4]
  if attType == 'lo_element' or attType == 'inline_lo_element':
    return
  if attrib['type'] == 'array':
    output.write('/*\n')
    output.write(' * Sets the \"{0}\"'.format(attName))
    output.write(' element of this {0}.\n'.format(element))
    output.write(' *\n')
    output.write(' * @param inArray; {1} array to be set (it will be copied).\n'.format(attName, attTypeCode))
    output.write(' * @param arrayLength; the length of the array.\n')
    output.write(' *\n')
    output.write(' * @return integer value indicating success/failure of the\n')
    output.write(' * function.  @if clike The value is drawn from the\n')
    output.write(' * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write(' * returned by this function are:\n')
    output.write(' * @li LIBSBML_OPERATION_SUCCESS\n')
    output.write(' * @li LIBSBML_INVALID_ATTRIBUTE_VALUE\n')
    output.write(' */\n')
    output.write('int\n{0}::set{1}('.format(element, capAttName))
    output.write('{0} inArray, int arrayLength)\n'.format(attTypeCode))
    output.write('{\n')
    output.write('  if (inArray == NULL) return LIBSBML_INVALID_ATTRIBUTE_VALUE;\n')
    output.write('\n')
    output.write('  if (m{0} != NULL) delete[] m{0};\n'.format(capAttName))
    output.write('  m{0} = new {1}[arrayLength];\n'.format(capAttName, attrib['element']))
    output.write('  memcpy(m{0}, inArray, sizeof({1})*arrayLength);\n'.format(capAttName, attrib['element']))
    output.write('  mIsSet{0}Length = true;\n'.format(capAttName))
    output.write('  m{0}Length = arrayLength;\n'.format(capAttName))
    output.write('\n')
    output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
    output.write('}\n')
    return
  output.write('/*\n')
  output.write(' * Sets {0} and returns value indicating success.\n'.format(attName))
  output.write(' */\n')
  output.write('int\n')
  output.write('{0}::set{1}({2} {3})\n'.format(element, capAttName, attTypeCode, cleanName))
  output.write('{\n')
  if attType == 'string':
    if attName == 'id':
      output.write('  return SyntaxChecker::checkAndSetSId({0}, m{1});\n'.format(attName, capAttName))
    else:
      output.write('  if (&({0}) == NULL)\n'.format(cleanName))
      output.write('  {\n    return LIBSBML_INVALID_ATTRIBUTE_VALUE;\n  }\n')
      if attrib['type'] == 'SIdRef':
        output.write('  else if (!(SyntaxChecker::isValidInternalSId({0})))\n'.format(cleanName))
        output.write('  {\n    return LIBSBML_INVALID_ATTRIBUTE_VALUE;\n  }\n')
      output.write('  else\n  {\n')
      output.write('    m{0} = {1};\n'.format(capAttName, cleanName))
      output.write('    return LIBSBML_OPERATION_SUCCESS;\n  }\n')
  elif num == True:
    output.write('  m{0} = {1};\n'.format(capAttName, cleanName))
    output.write('  mIsSet{0} = true;\n'.format(capAttName))
    output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
  elif attrib['type'] == 'enum':
    output.write('  m{0} = {1};\n'.format(capAttName, cleanName))
    output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
  elif attrib['type'] == 'array':
    output.write('  m{0} = {1};\n'.format(capAttName, cleanName))
    output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
  elif attType == 'boolean':
    output.write('  m{0} = {1};\n'.format(capAttName, cleanName))
    output.write('  mIsSet{0} = true;\n'.format(capAttName))
    output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
  elif attType == 'XMLNode*':
      output.write('  if (m{0} == {1})\n'.format(capAttName, cleanName))
      output.write('  {\n    return LIBSBML_OPERATION_SUCCESS;\n  }\n')
      output.write('  else if ({0} == NULL)\n'.format(cleanName))
      output.write('  {\n')
      output.write('    delete m{0};\n'.format(capAttName))
      output.write('    m{0} = NULL;\n'.format(capAttName))
      output.write('    return LIBSBML_OPERATION_SUCCESS;\n  }\n')
      output.write('  delete m{0};\n'.format(capAttName))
      output.write('  m{0} = ({1} != NULL) ?\n'.format(capAttName, cleanName))
      output.write('    {0}->clone() : NULL;\n'.format(cleanName))
      output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
  elif attType == 'element':
    output.write('  if (m{0} == {1})\n'.format(capAttName, cleanName))
    output.write('  {\n    return LIBSBML_OPERATION_SUCCESS;\n  }\n')
    output.write('  else if ({0} == NULL)\n'.format(cleanName))
    output.write('  {\n')
    output.write('    delete m{0};\n'.format(capAttName))
    output.write('    m{0} = NULL;\n'.format(capAttName))
    output.write('    return LIBSBML_OPERATION_SUCCESS;\n  }\n')
    if attTypeCode == 'const ASTNode*':
      output.write('  else if (!({0}->isWellFormedASTNode()))\n'.format(cleanName))
      output.write('  {\n    return LIBSBML_INVALID_OBJECT;\n  }\n')
    output.write('  else\n  {\n')
    output.write('    delete m{0};\n'.format(capAttName))
    output.write('    m{0} = ({1} != NULL) ?\n'.format(capAttName, cleanName))
    if attTypeCode == 'const ASTNode*':
      output.write('      {0}->deepCopy() : NULL;\n'.format(cleanName))
    else:
      output.write('      static_cast<{0}>({1}->clone()) : NULL;\n'.format(attTypeCode, cleanName))
    output.write('    if (m{0} != NULL)\n'.format(capAttName))
    output.write('    {\n')
    if attTypeCode == 'const ASTNode*':
      output.write('      m{0}->setParentSBMLObject(this);\n'.format(capAttName, cleanName))
    else:
      if generalFunctions.overridesElementName(attrib):
        output.write('      m{0}->setElementName("{1}");\n'.format(capAttName, cleanName))
      output.write('      m{0}->connectToParent(this);\n'.format(capAttName, cleanName))
    output.write('    }\n')
    output.write('    return LIBSBML_OPERATION_SUCCESS;\n  }\n')
  output.write('}\n\n\n')

  if attrib['type'] == 'enum':
    output.write('/*\n')
    output.write(' * Sets {0} and returns value indicating success.\n'.format(attName))
    output.write(' */\n')
    output.write('int\n')
    output.write('{0}::set{1}(const std::string& {2})\n'.format(element, capAttName, cleanName))
    output.write('{\n')
    output.write('  {0}_t parsed = {0}_parse({1}.c_str());\n'.format(attrib['element'], cleanName))
    output.write('  if (parsed == {0}_UNKNOWN) return LIBSBML_INVALID_ATTRIBUTE_VALUE;\n'.format(attrib['element'].upper(), cleanName))
    output.write('  m{0} = parsed;\n'.format(capAttName))
    output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
    output.write('}\n\n\n')



def writeUnsetCode(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attType == 'lo_element' or attType == 'inline_lo_element':
    return
  output.write('/*\n')
  output.write(' * Unsets {0} and returns value indicating success.\n'.format(attName))
  output.write(' */\n')
  output.write('int\n')
  output.write('{0}::unset{1}()\n'.format(element, capAttName))
  output.write('{\n')
  if attType == 'string':
    output.write('  m{0}.erase();\n\n'.format(capAttName))
    output.write('  if (m{0}.empty() == true)\n'.format(capAttName))
    output.write('  {\n    return LIBSBML_OPERATION_SUCCESS;\n  }\n')
    output.write('  else\n  {\n')
    output.write('    return LIBSBML_OPERATION_FAILED;\n  }\n')
  elif num == True:
    if attType == 'double':
      output.write('  m{0} = numeric_limits<double>::quiet_NaN();\n'.format(capAttName))
    else:
      output.write('  m{0} = SBML_INT_MAX;\n'.format(capAttName))
    output.write('  mIsSet{0} = false;\n\n'.format(capAttName))
    output.write('  if (isSet{0}() == false)\n'.format(capAttName))
    output.write('  {\n    return LIBSBML_OPERATION_SUCCESS;\n  }\n')
    output.write('  else\n  {\n')
    output.write('    return LIBSBML_OPERATION_FAILED;\n  }\n')
  elif attType == 'boolean':
    output.write('  m{0} = false;\n'.format(capAttName))
    output.write('  mIsSet{0} = false;\n'.format(capAttName))
    output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
  elif attType == 'element':
    output.write('  delete m{0};\n'.format(capAttName))
    output.write('  m{0} = NULL;\n'.format(capAttName))
    output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
  elif attrib['type'] == 'enum':
    output.write('  m{0} = {1}_UNKNOWN;\n'.format(capAttName, attrib['element'].upper()))
    output.write('  return LIBSBML_OPERATION_SUCCESS;\n')
  elif attrib['type'] == 'array':
    output.write('  if (m{0} != NULL)\n'.format(capAttName))
    output.write('   delete[] m{0};\n'.format(capAttName))
    output.write('  m{0} = NULL;\n'.format(capAttName))
    output.write('  return unset{0}Length();\n'.format(capAttName))
  output.write('}\n\n\n')

# for each attribute write a set/get/isset/unset
def writeAttributeCode(attrs, output, element, pkgName, elementDict):
  for i in range(0, len(attrs)):
    if attrs[i]['type'] != 'lo_element' and attrs[i]['type'] != 'inline_lo_element':
      writeGetCode(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] != 'lo_element' and attrs[i]['type'] != 'inline_lo_element':
      writeIsSetCode(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] != 'lo_element' and attrs[i]['type'] != 'inline_lo_element':
      writeSetCode(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeUnsetCode(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] == 'lo_element' or attrs[i]['type'] == 'inline_lo_element':
      writeListOfSubFunctions(attrs[i], output, element, pkgName)
  if elementDict.has_key('abstract'): 
    if elementDict['abstract']:
      concretes = generalFunctions.getConcretes(elementDict['root'], elementDict['concrete'])
      for i in range(0, len(concretes)):
        concrete = concretes[i]
        output.write('/*\n')
        output.write(' * Return @c true if of type {0}.\n'.format(concrete['element']))
        output.write(' */\n')
        output.write('bool\n')
        output.write('{0}::is{1}() const\n'.format(element, concrete['element']))
        output.write('{\n')
        output.write('  return dynamic_cast<const {0}*>(this) != NULL;\n'.format(concrete['element']))
        output.write('}\n\n\n')        


def writeListOfSubFunctions(attrib, output, element, pkgName):
  lotype = generalFunctions.getListOfClassName(attrib, strFunctions.cap(attrib['element']))
  loname = generalFunctions.writeListOf(strFunctions.cap(attrib['name']))
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  output.write('/*\n')
  output.write(' * Returns the  \"{0}\"'.format(lotype))
  output.write(' in this {0} object.\n'.format(element))
  output.write(' */\n')
  output.write('const {0}*\n'.format(lotype))
  output.write('{0}::get{1}() const\n'.format(element, loname))
  output.write('{\n')
  output.write('  return &m{0};\n'.format(strFunctions.capp(attName)))
  output.write('}\n\n\n')
  output.write('/*\n')
  output.write(' * Returns the  \"{0}\"'.format(lotype))
  output.write(' in this {0} object.\n'.format(element))
  output.write(' */\n')
  output.write('{0}*\n'.format(lotype))
  output.write('{0}::get{1}()\n'.format(element, loname))
  output.write('{\n')
  output.write('  return &m{0};\n'.format(strFunctions.capp(attName)))
  output.write('}\n\n\n')
  writeListOfCode.writeRemoveFunctions(output, strFunctions.cap(attrib['name']), attrib['element'], True, element, capAttName, attrib)
  writeListOfCode.writeGetFunctions(output, strFunctions.cap(attrib['name']), attrib['element'], True, element, capAttName, attrib)
  output.write('/*\n')
  output.write(' * Adds a copy the given \"{0}\" to this {1}.\n'.format(attrib['element'], element))
  output.write(' *\n')
  output.write(' * @param {0}; the {1} object to add\n'.format(strFunctions.objAbbrev(attrib['element']), attrib['element']))
  output.write(' *\n')
  output.write(' * @return integer value indicating success/failure of the\n')
  output.write(' * function.  @if clike The value is drawn from the\n')
  output.write(' * enumeration #OperationReturnValues_t. @endif The possible values\n')
  output.write(' * returned by this function are:\n')
  output.write(' * @li LIBSBML_OPERATION_SUCCESS\n')
  output.write(' * @li LIBSBML_INVALID_ATTRIBUTE_VALUE\n')
  output.write(' */\n')
  output.write('int\n')
  output.write('{0}::add{1}(const {2}* {3})\n'.format(element, strFunctions.cap(attrib['name']), attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  output.write('{\n')
  output.write('  if ({0} == NULL)\n'.format(strFunctions.objAbbrev(attrib['element'])))
  output.write('  {\n')
  output.write('    return LIBSBML_OPERATION_FAILED;\n')
  output.write('  }\n')
  output.write('  else if ({0}->hasRequiredAttributes() == false)\n'.format(strFunctions.objAbbrev(attrib['element'])))
  output.write('  {\n')
  output.write('    return LIBSBML_INVALID_OBJECT;\n')
  output.write('  }\n')
  output.write('  else if (getLevel() != {0}->getLevel())\n'.format(strFunctions.objAbbrev(attrib['element'])))
  output.write('  {\n')
  output.write('    return LIBSBML_LEVEL_MISMATCH;\n')
  output.write('  }\n')
  output.write('  else if (getVersion() != {0}->getVersion())\n'.format(strFunctions.objAbbrev(attrib['element'])))
  output.write('  {\n')
  output.write('    return LIBSBML_VERSION_MISMATCH;\n')
  output.write('  }\n')
  if not element.endswith('Plugin'):
    output.write(
      '  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const SBase *>({0})) == false)\n'.format(
        strFunctions.objAbbrev(attrib['element'])))
    output.write('  {\n')
    output.write('    return LIBSBML_NAMESPACES_MISMATCH;\n')
    output.write('  }\n')
  output.write('  else\n'.format(strFunctions.objAbbrev(attrib['element'])))
  output.write('  {\n')
  output.write('    m{0}.append({1});\n'.format(strFunctions.capp(attrib['name']),strFunctions.objAbbrev(attrib['element'])))
  output.write('    return LIBSBML_OPERATION_SUCCESS;\n')
  output.write('  }\n')
  output.write('}\n\n\n')
  output.write('/*\n')
  output.write(' * Get the number of {0} objects in this {1}.\n'.format(attrib['element'], element))
  output.write(' *\n')
  output.write(' * @return the number of {0} objects in this {1}\n'.format(attrib['element'], element))
  output.write(' */\n')
  output.write('unsigned int\n')
  output.write('{0}::getNum{1}() const\n'.format(element, strFunctions.capp(attrib['name'])))
  output.write('{\n')
  output.write('  return m{0}.size();\n'.format(strFunctions.capp(attrib['name'])))
  output.write('}\n\n\n')
  if attrib.has_key('abstract') == False or (attrib.has_key('abstract') and attrib['abstract'] == False):
      output.write('/*\n')
      output.write(' * Creates a new {0} object, adds it to this {1}s\n'.format(attrib['element'], element))
      output.write(' * {0} and returns the {1} object created. \n'.format(element, attrib['element']))
      output.write(' *\n')
      output.write(' * @return a new {0} object instance\n'.format(attrib['element']))
      output.write(' *\n')
      output.write(' * @see add{0}(const {0}* {1})\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
      output.write(' */\n')
      output.write('{0}*\n'.format(attrib['element']))
      output.write('{0}::create{1}()\n'.format(element, strFunctions.cap(attrib['name'])))
      output.write('{\n')
      output.write('  {0}* {1} = NULL;\n\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
      output.write('  try\n')
      output.write('  {\n')
      output.write('    {0}_CREATE_NS({1}ns, getSBMLNamespaces());\n'.format(pkgName.upper(), pkgName.lower()))
      output.write(
        '    {0} = new {1}({2}ns);\n'.format(strFunctions.objAbbrev(attrib['element']), attrib['element'], pkgName.lower()))
      output.write('    delete {0}ns;\n'.format(pkgName.lower()))
      output.write('  }\n')
      output.write('  catch (...)\n')
      output.write('  {\n')
      output.write('    /* here we do not create a default object as the level/version must\n')
      output.write('     * match the parent object\n')
      output.write('     *\n')
      output.write('     * do nothing\n')
      output.write('     */\n')
      output.write('  }\n\n')
      output.write('  if({0} != NULL)\n'.format(strFunctions.objAbbrev(attrib['element'])))
      output.write('  {\n')
      output.write('    m{0}.appendAndOwn({1});\n'.format(strFunctions.capp(attrib['name']), strFunctions.objAbbrev(attrib['element'])))
      output.write('  }\n\n')
      output.write('  return {0};\n'.format(strFunctions.objAbbrev(attrib['element'])))
      output.write('}\n\n\n')
  elif attrib.has_key('concrete'):
    for elem in generalFunctions.getConcretes(attrib['root'], attrib['concrete']):
      output.write('/**\n')
      output.write(' * Creates a new {0} object, adds it to this {1}s\n'.format(elem['element'], element))
      output.write(' * {0} and returns the {1} object created. \n'.format(lotype, elem['element']))
      output.write(' *\n')
      output.write(' * @return a new {0} object instance\n'.format(elem['element']))
      output.write(' *\n')
      output.write(' * @see add{0}(const {0}*)\n'.format(strFunctions.cap(attrib['element'])))
      output.write(' */\n')
      output.write('{0}* \n'.format(elem['element']))
      output.write('{0}::create{1}()\n'.format(element, strFunctions.cap(elem['name'])))
      output.write('{\n')
      output.write('  {0}* {1} = NULL;\n\n'.format(elem['element'], strFunctions.objAbbrev(elem['element'])))
      output.write('  try\n')
      output.write('  {\n')
      output.write('    {0}_CREATE_NS({1}ns, getSBMLNamespaces());\n'.format(pkgName.upper(), pkgName.lower()))
      output.write(
        '    {0} = new {1}({2}ns);\n'.format(strFunctions.objAbbrev(elem['element']), elem['element'], pkgName.lower()))
      output.write('    delete {0}ns;\n'.format(pkgName.lower()))
      output.write('  }\n')
      output.write('  catch (...)\n')
      output.write('  {\n')
      output.write('    /* here we do not create a default object as the level/version must\n')
      output.write('     * match the parent object\n')
      output.write('     *\n')
      output.write('     * do nothing\n')
      output.write('     */\n')
      output.write('  }\n\n')
      output.write('  if({0} != NULL)\n'.format(strFunctions.objAbbrev(elem['element'])))
      output.write('  {\n')
      output.write('    m{0}.appendAndOwn({1});\n'.format(strFunctions.capp(attrib['name']), strFunctions.objAbbrev(elem['element'])))
      output.write('  }\n\n')
      output.write('  return {0};\n'.format(strFunctions.objAbbrev(elem['element'])))
      output.write('}\n\n\n')


def createCode(element):
  nameOfElement = element['name']
  nameOfPackage = element['package']
  sbmltypecode = element['typecode']
  isListOf = element['hasListOf']
  attributes = element['attribs']
  hasChildren = element['hasChildren']
  hasMath = element['hasMath']
  baseClass = 'SBase'
  childrenOverwrite = element.has_key('childrenOverwriteElementName') and element['childrenOverwriteElementName']

  if element != None and element.has_key('baseClass'):
    baseClass = element['baseClass']
    if baseClass == None: 
      baseClass = 'SBase'

  codeName = nameOfElement + '.cpp'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfElement)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfElement, nameOfPackage, hasMath, element)
  writeConstructors(nameOfElement, nameOfPackage, code, attributes, hasChildren, hasMath, element, childrenOverwrite)
  writeAttributeCode(attributes, code, nameOfElement, nameOfPackage, element)
  if hasMath == True or generalFunctions.hasSIdRef(attributes) == True:
    generalFunctions.writeRenameSIdCode(code, nameOfElement, attributes, hasMath)
  if hasChildren == True:
    generalFunctions.writeGetAllElementsCode(code, nameOfElement, attributes)
  generalFunctions.writeCommonCPPCode(code, nameOfElement, sbmltypecode, attributes, False, hasChildren, hasMath, element,baseClass)
  generalFunctions.writeInternalCPPCode(code, nameOfElement, attributes, hasChildren, hasMath,baseClass, isListOf)
  generalFunctions.writeProtectedCPPCode(code, nameOfElement, attributes, False, hasChildren, hasMath, nameOfPackage,
                                         isListOf, baseClass, element)
  
  if generalFunctions.hasArray(element):
    
    # writes the array to model
    code.write('void\n{0}::write(XMLOutputStream& stream) const\n'.format(element['name']))
    code.write('{\n')
    code.write('  stream.startElement(getElementName(), getPrefix());\n')
    code.write('  writeAttributes(stream);\n')

    att = generalFunctions.getByType(element['attribs'], 'array')
    if att != None:
      capAttName = strFunctions.cap(att['name'])
      attType = att['element'];
      if attType == 'int':
        attType = 'long'
      code.write('  if(isSet{0}())\n'.format(capAttName))
      code.write('  {\n')
      code.write('    for (int i = 0; i < m{0}Length; ++i)\n'.format(capAttName))
      code.write('    {\n')
      code.write('      stream << ({0})m{1}[i] << " ";\n'.format(attType, capAttName))
      code.write('    }\n')
      code.write('  }\n')
    code.write('  stream.endElement(getElementName(), getPrefix());\n')
    code.write('}\n\n\n')

    # set element text, parses the text
    code.write('void\n{0}::setElementText(const std::string &text)\n'.format(element['name']))
    code.write('{\n')
    code.write('  stringstream strStream(text); // Insert the string into a stream\n')
    code.write('  {0} val;\n'.format(att['element']))
    code.write('  vector<{0}> valuesVector;\n'.format(att['element']))
    code.write('  while (strStream >> val)\n')
    code.write('  {\n')
    code.write('    valuesVector.push_back(val);\n')
    code.write('  }\n')
    code.write('\n')
    code.write('  // convert the vector to an array\n')
    code.write('  unsigned int length = (unsigned int)valuesVector.size();\n')
    code.write('  if (length > 0)\n')
    code.write('  {\n')
    code.write('\n')
    code.write('    {0}* data = new {0}[length];\n'.format(att['element']))
    code.write('    for (unsigned int i = 0; i < length; ++i)\n')
    code.write('    {\n')
    code.write('      data[i] = valuesVector.at(i);\n')
    code.write('    }\n')
    code.write('\n')
    code.write('    set{0}(data, length);\n'.format(strFunctions.cap(att['name'])))
    code.write('    delete[] data;\n')
    code.write('  }\n')     
    code.write('}\n')

  if element.has_key('addDefs'):
    code.write(open(element['addDefs'], 'r').read())

  if isListOf == True:
    writeListOfCode.createCode(element, code)
  writeCCode.createCode(element, code)

#if len(sys.argv) != 2:
#  print 'Usage: writeCode.py element'
#else:
#  element = createNewElementDictObj.createFBCObjective()
#  createCode(element)
  

  