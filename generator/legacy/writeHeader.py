#!/usr/bin/env python
#
# @file   writeHeader.py
# @brief  Create the header file for an object
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions
import writeListOfHeader
import createNewElementDictObj
import writeCHeader

def writeConstructors(element, package, output):
  indent = strFunctions.getIndent(element)
  output.write('  /**\n   * ' )
  output.write('Creates a new {0}'.format(element))
  output.write(' with the given level, version, and package version.\n')
  output.write('   *\n')
  output.write('   * @param level an unsigned int, the SBML Level to assign')
  output.write(' to this {0}\n'.format(element))
  output.write('   *\n')
  output.write('   * @param version an unsigned int, the SBML Version to assign')
  output.write(' to this {0}\n'.format(element))
  output.write('   *\n')
  output.write('   * @param pkgVersion an unsigned int, the SBML {0} Version to assign'.format(package))
  output.write(' to this {0}\n   */\n'.format(element))
  output.write('  {0}(unsigned int level      = '.format(element))
  output.write('{0}Extension::getDefaultLevel(),\n'.format(package))
  output.write('  {0}unsigned int version    = '.format(indent))
  output.write('{0}Extension::getDefaultVersion(),\n'.format(package))
  output.write('  {0}unsigned int pkgVersion = '.format(indent))
  output.write('{0}Extension::getDefaultPackageVersion());\n\n\n'.format(package))
  output.write('  /**\n   * ' )
  output.write('Creates a new {0}'.format(element))
  output.write(' with the given {0}PkgNamespaces object.\n'.format(package))
  output.write('   *\n')
  output.write('   * @param {0}ns the {1}PkgNamespaces object'.format(package.lower(), package))
  output.write('\n   */\n')
  output.write('  {0}({1}PkgNamespaces* {2}ns);\n\n\n '.format(element, package, package.lower()))
  output.write('  /**\n   * ' )
  output.write('Copy constructor for {0}.\n'.format(element))
  output.write('   *\n')
  output.write('   * @param orig; the {0} instance to copy.\n'.format(element))
  output.write('   */\n')
  output.write('  {0}(const {1}& orig);\n\n\n '.format(element, element))
  output.write('  /**\n   * ' )
  output.write('Assignment operator for {0}.\n'.format(element))
  output.write('   *\n')
  output.write('   * @param rhs; the object whose values are used as the basis\n')
  output.write('   * of the assignment\n   */\n')
  output.write('  {0}& operator=(const {1}& rhs);\n\n\n '.format(element, element))
  output.write('  /**\n   * ' )
  output.write('Creates and returns a deep copy of this {0} object.\n'.format(element))
  output.write('   *\n   * @return a (deep) copy of this {0} object.\n   */\n'.format(element))
  output.write('  virtual {0}* clone () const;\n\n\n '.format(element))
  output.write('  /**\n   * ' )
  output.write('Destructor for {0}.\n   */\n'.format(element))
  output.write('  virtual ~{0}();\n\n\n '.format(element))
  return

def writeAtt(attrib, output):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attType == 'string':
    output.write('  std::string   m{0};\n'.format(capAttName))
  elif attType == 'element':
    if attTypeCode == 'const ASTNode*' or attName== 'Math':
      output.write('  ASTNode*      m{0};\n'.format(capAttName))
    else:
      output.write('  {0}*      m{1};\n'.format(attrib['element'], capAttName))
      return
  elif attType == 'lo_element' or attType == 'inline_lo_element':
    if attrib.has_key('element'):
      output.write('  {0}   m{1};\n'.format(generalFunctions.getListOfClassName(attrib,attrib['element']), strFunctions.capp(attrib['name'])))
    else:
      output.write('  {0}   m{1};\n'.format(generalFunctions.getListOfClassName(attrib,capAttName), strFunctions.capp(attName)))
  elif attTypeCode == 'XMLNode*':
    output.write('  {0}   m{1};\n'.format('XMLNode*', capAttName))
  elif num == True:
    while len(attTypeCode) < 13:
      attTypeCode = attTypeCode + ' '
    output.write('  {1} m{0};\n'.format(capAttName, attTypeCode))
    output.write('  bool          mIsSet{0};\n'.format(capAttName))
  elif attType == 'boolean':
    output.write('  bool          m{0};\n'.format(capAttName))
    output.write('  bool          mIsSet{0};\n'.format(capAttName))
  elif attrib['type'] == 'enum':
    output.write('  {0}_t   m{1};\n'.format(attrib['element'], capAttName))
  elif attrib['type'] == 'array':
    output.write('  {0}*         m{1};\n'.format(attrib['element'], capAttName))
  else:
    output.write('  FIX ME   {0};\n'.format(attName))
 
def writeAttributes(attrs, output):
  output.write('protected:\n\n')
  for i in range(0, len(attrs)):
    writeAtt(attrs[i], output)  
  output.write('\n\n')

def writeGetFunction(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'lo_element' or attrib['type'] == 'inline_lo_element':
    return
  elif attrib['type'] == 'array':
    output.write('  /**\n');
    output.write('   * The "{0}" attribute of this {1} is returned in an {2} array (pointer)\n'.format(attName, element, attTypeCode));
    output.write('   * that is passed as argument to the method (this is needed while using SWIG to\n');
    output.write('   * convert int[] from C++ to Java). The method itself has a return type void.\n');
    output.write('   *\n');
    output.write('   * NOTE: you have to pre-allocate the array with the correct length!');
    output.write('   *\n');
    output.write('   * @return void.\n');
    output.write('   */\n');
    output.write('  void get{0}({1} outArray) const;\n\n\n'.format(capAttName, attTypeCode));
  elif attrib['type'] == 'element':
    if attrib['name'] == 'Math' or attrib['name'] == 'math':
      output.write('  /**\n')
      output.write('   * Returns the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('   *\n')
      output.write('   * @return the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('   */\n')
      output.write('  virtual const ASTNode*')
      output.write(' get{0}() const;\n\n\n'.format(capAttName))
    else:
      output.write('  /**\n')
      output.write('   * Returns the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('   *\n')
      output.write('   * @return the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('   */\n')
      output.write('  virtual const {0}*'.format(attrib['element']))
      output.write(' get{0}() const;\n\n\n'.format(capAttName))
      
      output.write('  /**\n')
      output.write('   * Returns the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('   *\n')
      output.write('   * @return the \"{0}\"'.format(attName))
      output.write(' element of this {0}.\n'.format(element))
      output.write('   */\n')
      output.write('  virtual {0}*'.format(attrib['element']))
      output.write(' get{0}();\n\n\n'.format(capAttName))

      if attrib['abstract'] == False:
        output.write('  /**\n')
        output.write('   * Creates a new \"{0}\"'.format(attrib['element']))
        output.write(' and sets it for this {0}.\n'.format(element))
        output.write('   *\n')
        output.write('   * @return the created \"{0}\"'.format(attrib['element']))
        output.write(' element of this {0}.\n'.format(element))
        output.write('   */\n')
        output.write('  virtual {0}*'.format(attrib['element']))
        output.write(' create{0}();\n\n\n'.format(capAttName))
      else:
        for concrete in generalFunctions.getConcretes(attrib['root'], attrib['concrete']):
          output.write('  /**\n')
          output.write('   * Creates a new \"{0}\"'.format(attName))
          output.write(' and sets it for this {0}.\n'.format(element))
          output.write('   */\n')
          output.write('  virtual {0}*'.format(concrete['element']))
          output.write(' create{0}();\n\n\n'.format(strFunctions.cap(concrete['name'])))
  else:
    output.write('  /**\n')
    output.write('   * Returns the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('   *\n')
    output.write('   * @return the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0} as a {1}.\n'.format(element, attType))
    output.write('   */\n')
    output.write('  virtual {0}'.format(attTypeCode))
    output.write(' get{0}() const;\n\n\n'.format(capAttName))
     
def writeIsSetFunction(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'lo_element' or attrib['type'] == 'inline_lo_element':
    return
  elif attrib['type'] == 'element':
    output.write('  /**\n')
    output.write('   * Predicate returning @c true or @c false depending on ')
    output.write('whether this\n   * {0}\'s \"{1}\" '.format(element, attName))
    output.write('element has been set.\n   *\n')
    output.write('   * @return @c true if this {0}\'s \"{1}\"'.format(element, attName))
    output.write(' element has been set,\n')
    output.write('   * otherwise @c false is returned.\n')
    output.write('   */\n')
    output.write('  virtual bool isSet{0}() const;\n\n\n'.format(capAttName))
  else:
    output.write('  /**\n')
    output.write('   * Predicate returning @c true or @c false depending on ')
    output.write('whether this\n   * {0}\'s \"{1}\" '.format(element, attName))
    output.write('attribute has been set.\n   *\n')
    output.write('   * @return @c true if this {0}\'s \"{1}\"'.format(element, attName))
    output.write(' attribute has been set,\n')
    output.write('   * otherwise @c false is returned.\n')
    output.write('   */\n')
    output.write('  virtual bool isSet{0}() const;\n\n\n'.format(capAttName))
   
def writeSetFunction(attrib, output, element):
  att = generalFunctions.parseAttribute(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  if attType == 'string':
    attTypeCode = 'const std::string&' 
  else:
    attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'lo_element' or attrib['type'] == 'inline_lo_element':
    return
  elif attrib['type'] == 'array':
    output.write('  /**\n')
    output.write('   * Sets the \"{0}\"'.format(attName))
    output.write(' element of this {0}.\n'.format(element))
    output.write('   *\n')
    output.write('   * @param inArray; {1} array to be set (it will be copied).\n'.format(attName, attTypeCode))
    output.write('   * @param arrayLength; the length of the array.\n')
    output.write('   *\n')
    output.write('   * @return integer value indicating success/failure of the\n')
    output.write('   * function.  @if clike The value is drawn from the\n')
    output.write('   * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('   * returned by this function are:\n')
    output.write('   * @li LIBSBML_OPERATION_SUCCESS\n')
    output.write('   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE\n')
    output.write('   */\n')
    output.write('  virtual int set{0}('.format(capAttName))
    output.write('{0} inArray, int arrayLength);\n\n\n'.format(attTypeCode))
  elif attrib['type'] == 'element':
    output.write('  /**\n')
    output.write('   * Sets the \"{0}\"'.format(attName))
    output.write(' element of this {0}.\n'.format(element))
    output.write('   *\n')
    output.write('   * @param {0}; {1} to be set.\n'.format(strFunctions.cleanStr(attName), attTypeCode))
    output.write('   *\n')
    output.write('   * @return integer value indicating success/failure of the\n')
    output.write('   * function.  @if clike The value is drawn from the\n')
    output.write('   * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('   * returned by this function are:\n')
    output.write('   * @li LIBSBML_OPERATION_SUCCESS\n')
    output.write('   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE\n')
    output.write('   */\n')
    output.write('  virtual int set{0}('.format(capAttName))
    output.write('{0} {1});\n\n\n'.format(attTypeCode, strFunctions.cleanStr(attName)))
  else:
    output.write('  /**\n')
    output.write('   * Sets the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('   *\n')
    output.write('   * @param {0}; {1} value of the "{2}" attribute to be set\n'.format(strFunctions.cleanStr(attName), attTypeCode, attName))
    output.write('   *\n')
    output.write('   * @return integer value indicating success/failure of the\n')
    output.write('   * function.  @if clike The value is drawn from the\n')
    output.write('   * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('   * returned by this function are:\n')
    output.write('   * @li LIBSBML_OPERATION_SUCCESS\n')
    output.write('   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE\n')
    output.write('   */\n')
    output.write('  virtual int set{0}('.format(capAttName))
    output.write('{0} {1});\n\n\n'.format(attTypeCode, strFunctions.cleanStr(attName)))

    if attrib['type'] == 'enum':
      output.write('  /**\n')
      output.write('   * Sets the value of the \"{0}\"'.format(strFunctions.cleanStr(attName)))
      output.write(' attribute of this {0}.\n'.format(element))
      output.write('   *\n')
      output.write('   * @param {0}; string value of the "{1}" attribute to be set\n'.format(strFunctions.cleanStr(attName), attName))
      output.write('   *\n')
      output.write('   * @return integer value indicating success/failure of the\n')
      output.write('   * function.  @if clike The value is drawn from the\n')
      output.write('   * enumeration #OperationReturnValues_t. @endif The possible values\n')
      output.write('   * returned by this function are:\n')
      output.write('   * @li LIBSBML_OPERATION_SUCCESS\n')
      output.write('   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE\n')
      output.write('   */\n')
      output.write('  virtual int set{0}('.format(capAttName))
      output.write('const std::string& {0});\n\n\n'.format(strFunctions.cleanStr(attName)))

     
  
def writeUnsetFunction(attrib, output, element):
  attName = attrib['name']
  capAttName = strFunctions.cap(attName)
  if attrib['type'] == 'lo_element' or attrib['type'] == 'inline_lo_element':
    return
  elif attrib['type'] == 'element':
    output.write('  /**\n')
    output.write('   * Unsets the \"{0}\"'.format(attName))
    output.write(' element of this {0}.\n'.format(element))
    output.write('   *\n')
    output.write('   * @return integer value indicating success/failure of the\n')
    output.write('   * function.  @if clike The value is drawn from the\n')
    output.write('   * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('   * returned by this function are:\n')
    output.write('   * @li LIBSBML_OPERATION_SUCCESS\n')
    output.write('   * @li LIBSBML_OPERATION_FAILED\n')
    output.write('   */\n')
    output.write('  virtual int unset{0}();\n\n\n'.format(capAttName))
  else:
    output.write('  /**\n')
    output.write('   * Unsets the value of the \"{0}\"'.format(attName))
    output.write(' attribute of this {0}.\n'.format(element))
    output.write('   *\n')
    output.write('   * @return integer value indicating success/failure of the\n')
    output.write('   * function.  @if clike The value is drawn from the\n')
    output.write('   * enumeration #OperationReturnValues_t. @endif The possible values\n')
    output.write('   * returned by this function are:\n')
    output.write('   * @li LIBSBML_OPERATION_SUCCESS\n')
    output.write('   * @li LIBSBML_OPERATION_FAILED\n')
    output.write('   */\n')
    output.write('  virtual int unset{0}();\n\n\n'.format(capAttName))
   
  
   
def writeAttributeFunctions(attrs, output, element, elementDict):
  for i in range(0, len(attrs)):
    writeGetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeIsSetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeSetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeUnsetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] == 'lo_element' or attrs[i]['type'] == 'inline_lo_element':
      writeListOfSubFunctions(attrs[i], output, element, elementDict)
  if elementDict.has_key('abstract'): 
    if elementDict['abstract']:
      concretes = generalFunctions.getConcretes(elementDict['root'], elementDict['concrete'])
      for i in range(0, len(concretes)):
        concrete = concretes[i]
        # write     
        output.write('  /**\n')
        output.write('   * Returns @c true, if this abstract \"{0}\"'.format(element))
        output.write(' is of type {0}.\n'.format(concrete['element']))
        output.write('   *\n')
        output.write('   * @return @c true, if this abstract \"{0}\"'.format(element))
        output.write(' is of type {0}.\n'.format(concrete['element']))
        output.write('   *\n')
        output.write('   */\n')
        output.write('  virtual bool is{0}() const;\n\n\n'.format(concrete['element']))

def writeListOfSubFunctions(attrib, output, element, elementDict):
  lotype = generalFunctions.getListOfClassName(attrib,strFunctions.cap(attrib['element']))
  loname = generalFunctions.writeListOf(strFunctions.cap(attrib['name']))
  output.write('  /**\n')
  output.write('   * Returns the  \"{0}\"'.format(lotype))
  output.write(' in this {0} object.\n'.format(element))
  output.write('   *\n')
  output.write('   * @return the \"{0}\"'.format(lotype))
  output.write(' attribute of this {0}.\n'.format(element))
  output.write('   */\n')
  output.write('  const {0}*'.format(lotype))
  output.write(' get{0}() const;\n\n\n'.format(loname))
  output.write('  /**\n')
  output.write('   * Returns the  \"{0}\"'.format(lotype))
  output.write(' in this {0} object.\n'.format(element))
  output.write('   *\n')
  output.write('   * @return the \"{0}\"'.format(lotype))
  output.write(' attribute of this {0}.\n'.format(element))
  output.write('   */\n')
  output.write('  {0}*'.format(lotype))
  output.write(' get{0}();\n\n\n'.format(loname))
  writeListOfHeader.writeGetFunctions(output, strFunctions.cap(attrib['name']), attrib['element'], True, element, attrib)
  output.write('  /**\n')
  output.write('   * Adds a copy the given \"{0}\" to this {1}.\n'.format(attrib['element'], element))
  output.write('   *\n')
  output.write('   * @param {0}; the {1} object to add\n'.format(strFunctions.objAbbrev(attrib['element']), attrib['element']))
  output.write('   *\n')
  output.write('   * @return integer value indicating success/failure of the\n')
  output.write('   * function.  @if clike The value is drawn from the\n')
  output.write('   * enumeration #OperationReturnValues_t. @endif The possible values\n')
  output.write('   * returned by this function are:\n')
  output.write('   * @li LIBSBML_OPERATION_SUCCESS\n')
  output.write('   * @li LIBSBML_INVALID_ATTRIBUTE_VALUE\n')
  output.write('   */\n')
  output.write('  int add{0}(const {1}* {2});\n\n\n'.format(strFunctions.cap(attrib['name']), attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  output.write('  /**\n')
  output.write('   * Get the number of {0} objects in this {1}.\n'.format(attrib['element'], element))
  output.write('   *\n')
  output.write('   * @return the number of {0} objects in this {1}\n'.format(attrib['element'], element))
  output.write('   */\n')
  output.write('  unsigned int getNum{0}() const;\n\n\n'.format(strFunctions.capp(attrib['name'])))
  if attrib.has_key('abstract') == False or (attrib.has_key('abstract') and attrib['abstract'] == False):
    output.write('  /**\n')
    output.write('   * Creates a new {0} object, adds it to this {1}s\n'.format(attrib['element'], element))
    output.write('   * {0} and returns the {1} object created. \n'.format(lotype, attrib['element']))
    output.write('   *\n')
    output.write('   * @return a new {0} object instance\n'.format(attrib['element']))
    output.write('   *\n')
    output.write('   * @see add{0}(const {1}* {2})\n'.format(strFunctions.cap(attrib['name']), attrib['element'], strFunctions.objAbbrev(attrib['element'])))
    output.write('   */\n')
    output.write('  {0}* create{1}();\n\n\n'.format(attrib['element'], strFunctions.cap(attrib['name'])))
  elif attrib.has_key('concrete'):
    for elem in generalFunctions.getConcretes(attrib['root'], attrib['concrete']):
      output.write('  /**\n')
      output.write('   * Creates a new {0} object, adds it to this {1}s\n'.format(elem['element'], element))
      output.write('   * {0} and returns the {1} object created. \n'.format(lotype, elem['element']))
      output.write('   *\n')
      output.write('   * @return a new {0} object instance\n'.format(elem['element']))
      output.write('   *\n')
      output.write('   * @see add{0}(const {0}* {1})\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
      output.write('   */\n')
      output.write('  {0}* create{1}();\n\n\n'.format(elem['element'], strFunctions.cap(elem['name'])))
  writeListOfHeader.writeRemoveFunctions(output, strFunctions.cap(attrib['name']), attrib['element'], True, element,attrib)
 
#write class
def writeClass(attributes, header, nameOfElement, nameOfPackage, hasChildren, hasMath, isListOf, elementDict):
  header.write('class LIBSBML_EXTERN {0} :'.format(nameOfElement))
  baseClass = 'SBase'
  childrenOverwrite = elementDict.has_key('childrenOverwriteElementName') and elementDict['childrenOverwriteElementName']
  if elementDict.has_key('baseClass') and elementDict['baseClass'] != None:
    baseClass = elementDict['baseClass']
  header.write(' public {0}\n{1}\n\n'.format(baseClass, '{'))
  writeAttributes(attributes, header)
  if childrenOverwrite:
    header.write('  std::string   mElementName;\n\n')
  header.write('public:\n\n')
  writeConstructors(nameOfElement, nameOfPackage, header)
  writeAttributeFunctions(attributes, header, nameOfElement, elementDict)
  if hasMath == True or generalFunctions.hasSIdRef(attributes) == True:
    generalFunctions.writeRenameSIdHeader(header)

  if hasChildren == True:
    generalFunctions.writeGetAllElements(header)    
  generalFunctions.writeCommonHeaders(header, nameOfElement, attributes, False, hasChildren, hasMath)
  generalFunctions.writeInternalHeaders(header, isListOf, hasChildren)

  if generalFunctions.hasArray(elementDict):
    header.write('  virtual void write(XMLOutputStream& stream) const;\n\n\n')
  if childrenOverwrite:
    header.write('  virtual void setElementName(const std::string& name);\n\n\n')

  header.write('protected:\n\n')
  generalFunctions.writeProtectedHeaders(header, attributes, hasChildren, hasMath, baseClass, elementDict)
  if generalFunctions.hasArray(elementDict):
    header.write('  virtual void setElementText(const std::string &text);\n\n\n')

  if elementDict.has_key('addDecls'):
    header.write(open(elementDict['addDecls'], 'r').read())

  header.write('\n};\n\n')
 
# write the include files
def writeIncludes(fileOut, element, pkg, attribs, elementDict):
  baseClass = 'SBase'
  if elementDict.has_key('baseClass') and elementDict['baseClass'] != None:
    baseClass = elementDict['baseClass']
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/common/extern.h>\n')
  fileOut.write('#include <sbml/common/sbmlfwd.h>\n')
  fileOut.write('#include <sbml/packages/{0}/common/{0}fwd.h>\n'.format(pkg.lower()))
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <string>\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/SBase.h>\n')
  fileOut.write('#include <sbml/ListOf.h>\n')
  fileOut.write('#include <sbml/packages/{0}/extension/{1}Extension.h>\n'.format(pkg.lower(), pkg))
  if baseClass != 'SBase':
    fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkg.lower(), baseClass))
  fileOut.write('\n')

  for i in range (0, len(attribs)):
    current = attribs[i]
    if (current['type'] == 'element' or current['type'] == 'lo_element' or current['type'] == 'inline_lo_element') and current['name'] != 'math':
      if current['type'] != 'element':
        fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkg.lower(), strFunctions.cap(attribs[i]['element'])))
      else: 
        fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkg.lower(), strFunctions.cap(attribs[i]['element'])))
  fileOut.write('\nLIBSBML_CPP_NAMESPACE_BEGIN\n\n')

  if elementDict.has_key('concrete'):
    for elem in generalFunctions.getConcretes(elementDict['root'], elementDict['concrete']):
      fileOut.write('class {0};\n'.format(elem['element']))
    fileOut.write('\n')

  fileOut.write('\n\n');
  
def writeCPPEnd(fileOut):
  fileOut.write('\n\nLIBSBML_CPP_NAMESPACE_END\n\n')
  fileOut.write('#endif  /*  __cplusplus  */\n\n')
  
def writeCStart(fileOut):
  fileOut.write('#ifndef SWIG\n\n')
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\nBEGIN_C_DECLS\n\n')
  

def writeCEnd(fileOut, element):
  fileOut.write('\n\nEND_C_DECLS\n')
  fileOut.write('LIBSBML_CPP_NAMESPACE_END\n\n')
  fileOut.write('#endif  /*  !SWIG  */\n\n')
  fileOut.write('#endif /*  {0}_H__  */\n\n'.format(element))
 
  
 
 
# write the header file      
def createHeader(element):
  nameOfElement = element['name']
  nameOfPackage = element['package']
  sbmltypecode = element['typecode']
  isListOf = element['hasListOf']
  attributes = element['attribs']
  hasChildren = element['hasChildren']
  hasMath = element['hasMath']
  headerName = nameOfElement + '.h'
  header = open(headerName, 'w')
  fileHeaders.addFilename(header, headerName, nameOfElement)
  fileHeaders.addLicence(header)
  writeIncludes(header, nameOfElement, nameOfPackage, attributes, element)
  writeClass(attributes, header, nameOfElement, nameOfPackage, hasChildren, hasMath, False, element)
  if isListOf == True:
    writeListOfHeader.createHeader(element, header)
  writeCPPEnd(header)
  writeCStart(header)
  writeCHeader.createHeader(element, header)
  writeCEnd(header, nameOfElement)

#if len(sys.argv) != 2:
#  print 'Usage: writeHeader.py element'
#else:
#  element = createNewElementDictObj.createFBCObj()
#  createHeader(element)
  

  