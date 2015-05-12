#!/usr/bin/env python
#
# @file   writeCHeader.py
# @brief  Create the C headers for a class
# @author Sarah Keating
#

import sys
import fileHeaders
import generalFunctions
import strFunctions


def writeConstructors(element, package, output):
  indent = strFunctions.getIndent(element)
  output.write('/**\n')
  output.write(' * Creates a new {0}_t structure using the given SBML @p level and\n'.format(element))
  output.write(' * @p version values.\n *\n')
  output.write(' * @param level an unsigned int, the SBML level to assign to this\n')
  output.write(' * {0}_t structure.\n *\n'.format(element))
  output.write(' * @param version an unsigned int, the SBML version to assign to this\n')
  output.write(' * {0}_t structure.\n *\n'.format(element))
  output.write(' * @returns the newly-created {0}_t structure, or a null pointer if\n'.format(element))
  output.write(' * an error occurred during construction.\n *\n')
  output.write(' * @copydetails doc_note_setting_lv\n *\n')
  output.write(' * @memberof {0}_t\n'.format(element))
  output.write(' */\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('{0}_t *\n'.format(element))
  output.write('{0}_create'.format(element))
  output.write('(unsigned int level, unsigned int version,\n')
  output.write('{0}       unsigned int pkgVersion);\n\n\n'.format(indent))
#  output.write('LIBSBML_EXTERN\n')
#  output.write('{0}_t *\n'.format(element))
#  output.write('{0}_createWithNS'.format(element))
#  output.write('(SBMLNamespaces_t *sbmlns);\n\n\n')
  output.write('/**\n')
  output.write(' * Frees the given {0}_t structure.\n * \n'.format(element))
  output.write(' * @param {0} the {1}_t structure to be freed.\n *\n'.format(strFunctions.objAbbrev(element), element))
  output.write(' * @memberof {0}_t\n'.format(element))
  output.write(' */\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('void\n')
  output.write('{0}_free'.format(element))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
  output.write('/**\n')
  output.write(' * Creates a deep copy of the given {0}_t structure.\n * \n'.format(element))
  output.write(' * @param {0} the {1}_t structure to be copied.\n *\n'.format(strFunctions.objAbbrev(element), element))
  output.write(' * @returns a (deep) copy of the given {0}_t structure, or a null\n'.format(element))
  output.write(' * pointer if a failure occurred.\n *\n')
  output.write(' * @memberof {0}_t\n'.format(element))
  output.write(' */\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('{0}_t *\n'.format(element))
  output.write('{0}_clone'.format(element))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))

def writeAttributeFunctions(attrs, output, element, dict):
  for i in range(0, len(attrs)):
    writeGetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeIsSetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeSetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    writeUnsetFunction(attrs[i], output, element)
  for i in range(0, len(attrs)):
    if attrs[i]['type'] == 'lo_element' or  attrs[i]['type'] == 'inline_lo_element':
      writeListOfSubElements(attrs[i], output, element)

def writeListOfSubElements(attrib, output, element):
  loname = generalFunctions.getListOfClassName(attrib, strFunctions.cap(attrib['element']))
  output.write('LIBSBML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_add{1}({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('{0}_t * {1});\n\n\n'.format(attrib['element'], strFunctions.objAbbrev(attrib['element'])))
  if attrib.has_key('abstract') == False or (attrib.has_key('abstract') and attrib['abstract'] == False):
    output.write('LIBSBML_EXTERN\n')
    output.write('{0}_t *\n'.format(attrib['element']))
    output.write('{0}_create{1}({0}_t * {2}' .format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
    output.write(');\n\n\n')
  elif attrib.has_key('concrete') and attrib.has_key('root'):    
    for elem in generalFunctions.getConcretes(attrib['root'], attrib['concrete']):
      output.write('LIBSBML_EXTERN\n')
      output.write('{0}_t *\n'.format(elem['element']))
      output.write('{0}_create{1}({0}_t * {2}' .format(element, strFunctions.cap(elem['name']), strFunctions.objAbbrev(element)))
      output.write(');\n\n\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('ListOf_t *\n')
  output.write('{0}_get{1}({0}_t * {2}) '.format(element, loname, strFunctions.objAbbrev(element)))
  output.write(';\n\n\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_get{1}({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('unsigned int n);\n\n\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_get{1}ById({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('const char * sid);\n\n\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('unsigned int\n')
  output.write('{0}_getNum{1}({0}_t * {2}' .format(element, strFunctions.capp(attrib['name']), strFunctions.objAbbrev(element)))
  output.write(');\n\n\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_remove{1}({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('unsigned int n);\n\n\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('{0}_t *\n'.format(attrib['element']))
  output.write('{0}_remove{1}ById({0}_t * {2}, '.format(element, strFunctions.cap(attrib['name']), strFunctions.objAbbrev(element)))
  output.write('const char * sid);\n\n\n')
 # writeListOfHeader.writeGetFunctions(output, attrib['element'], True, element)
 # writeListOfHeader.writeRemoveFunctions(output, attrib['element'], True, element)
 


def writeGetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  if att[3] == 'const char *':
    attTypeCode = 'const char *'
  else:
    attTypeCode = att[3]
  num = att[4]
  type = attrib['type']
  if type != 'element' and type != 'lo_element' and type != 'XMLNode*' and type != 'inline_lo_element':
    output.write('/**\n')
    output.write(' * Returns the value of the \"{0}\" attribute of the given {1}_t\n'.format(attName, element))
    output.write(' * structure.\n *\n')
    output.write(' * @param {0} the {1}_t structure.\n *\n'.format(strFunctions.objAbbrev(element), element))
    output.write(' * @return the {0} of this structure.\n *\n'.format(attName))
    output.write(' * @member of {0}_t\n'.format(element))
    output.write(' */\n')
    output.write('LIBSBML_EXTERN\n')
    output.write('{0}\n'.format(attTypeCode))
    output.write('{0}_get{1}'.format(element, capAttName))
    output.write('(const {0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
  elif type == 'XMLNode*':
    output.write('LIBSBML_EXTERN\n')
    output.write('XMLNode_t*\n')
    output.write('{0}_get{1}'.format(element, capAttName))
    output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))    
  elif type == 'element':
    if attrib['name'] == 'Math' or attrib['name'] == 'math':
      output.write('/**\n')
      output.write(' * Gets the mathematical expression of this {0}_t structure as an\n'.format(element))
      output.write(' * ASTNode_t structure.\n *\n')
      output.write(' * @param {0} the {1}_t structure.\n *\n'.format(strFunctions.objAbbrev(element), element))
      output.write(' * @return the math for this {0}_t, as an ASTNode_t.\n *\n'.format(element))
      output.write(' * @member of {0}_t\n'.format(element))
      output.write(' */\n')
      output.write('LIBSBML_EXTERN\n')
      output.write('const ASTNode_t*\n')
      output.write('{0}_getMath'.format(element))
      output.write('(const {0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
    else:
      output.write('LIBSBML_EXTERN\n')
      output.write('{0}_t*\n'.format(strFunctions.cap(attrib['element'])))
      output.write('{0}_get{1}'.format(element, capAttName))
      output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))

      if attrib.has_key('abstract') == False or (attrib.has_key('abstract') and attrib['abstract'] == False):
        output.write('LIBSBML_EXTERN\n')
        output.write('{0}_t*\n'.format(strFunctions.cap(attrib['element'])))
        output.write('{0}_create{1}'.format(element, capAttName))
        output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
      else:  
        for elem in generalFunctions.getConcretes(attrib['root'], attrib['concrete']):
          output.write('LIBSBML_EXTERN\n')
          output.write('{0}_t *\n'.format(elem['element']))
          output.write('{0}_create{1}({0}_t * {2}' .format(element, strFunctions.cap(elem['name']), strFunctions.objAbbrev(element)))
          output.write(');\n\n\n')

 
def writeIsSetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] != 'lo_element' and attrib['type'] != 'inline_lo_element':
    output.write('/**\n')
    output.write(' * Predicate returning @c 1 if the given {0}_t structure\'s \"{1}\"\n'.format(element, attName))
    output.write(' * is set.\n *\n')
    output.write(' * @param {0} the {1}_t structure.\n *\n'.format(strFunctions.objAbbrev(element), element))
    output.write(' * @return @c 1 if the \"{0}\" of this {1}_t structure is\n'.format(attName, element))
    output.write(' * set, @c 0 otherwise.\n *\n')
    output.write(' * @member of {0}_t\n'.format(element))
    output.write(' */\n')
    output.write('LIBSBML_EXTERN\n')
    output.write('int\n')
    output.write('{0}_isSet{1}'.format(element, capAttName))
    output.write('(const {0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
    

# note need to distinguish comments for different types
def writeSetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] != 'element' and attrib['type'] != 'lo_element' and attrib['type'] != 'XMLNode*' and attrib['type'] != 'inline_lo_element':
    output.write('/**\n')
    output.write(' * Sets the \"{0}\" attribute of the given {1}_t structure.\n *\n'.format(attName, element))
    if (attType == 'string'):
      output.write(' * This function copies the string given in @p string.  If the string is\n')
      output.write(' * a null pointer, this function performs {0}_unset{1}() instead.\n *\n'.format(element, capAttName))
    output.write(' * @param {0} the {1}_t structure.\n *\n'.format(strFunctions.objAbbrev(element), element))
    output.write(' * @param {0} the string to which the structures \"{1}\" attribute should be\n'.format(strFunctions.cleanStr(attName),attName))
    output.write(' * set.\n *\n')
    output.write(' * @return integer value indicating success/failure of the\n')
    output.write(' * function.  @if clike The value is drawn from the\n')
    output.write(' * enumeration #OperationReturnValues_t. @endif@~ The possible values\n')
    output.write(' * returned by this function are:\n')
    output.write(' * @li @link OperationReturnValues_t#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink\n')
    output.write(' * @li @link OperationReturnValues_t#LIBSBML_INVALID_ATTRIBUTE_VALUE LIBSBML_INVALID_ATTRIBUTE_VALUE@endlink\n')
    output.write(' * @li @link OperationReturnValues_t#LIBSBML_INVALID_OBJECT LIBSBML_INVALID_OBJECT@endlink\n *\n')
    if (attType == 'string'):
      output.write(' * @note Using this function with a null pointer for @p name is equivalent to\n')
      output.write(' * unsetting the value of the "name" attribute.\n * \n')
    output.write(' * @member of {0}_t\n'.format(element))
    output.write(' */\n')
    output.write('LIBSBML_EXTERN\n')
    output.write('int\n')
    output.write('{0}_set{1}'.format(element, capAttName))
    output.write('({0}_t * {1},'.format(element, strFunctions.objAbbrev(element)))
    output.write(' {0} {1});\n\n\n'.format(attTypeCode, strFunctions.cleanStr(attName)))
  elif attrib['type'] == 'XMLNode*':
    output.write('LIBSBML_EXTERN\n')
    output.write('int\n')
    output.write('{0}_set{1}'.format(element, capAttName))
    output.write('({0}_t * {1},'.format(element, strFunctions.objAbbrev(element)))
    output.write(' XMLNode_t* {0});\n\n\n'.format(strFunctions.cleanStr(attName)))
  elif attrib['type'] == 'element':
    if attrib['name'] == 'Math' or attrib['name'] == 'math':
      output.write('/**\n')
      output.write(' * Sets the mathematical expression of the given {0}_t structure.\n *\n'.format(element))
      output.write(' * @param {0} the {1}_t structure.\n *\n'.format(strFunctions.objAbbrev(element), element))
      output.write(' * @param math an ASTNode_t structure to be assigned as the \"math\"\n')
      output.write(' * subelement of this {0}_t.\n *\n'.format(element))
      output.write(' * @return integer value indicating success/failure of the\n')
      output.write(' * function.  @if clike The value is drawn from the\n')
      output.write(' * enumeration #OperationReturnValues_t. @endif@~ The possible values\n')
      output.write(' * returned by this function are:\n')
      output.write(' * @li @link OperationReturnValues_t#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink\n')
      output.write(' * @li @link OperationReturnValues_t#LIBSBML_INVALID_OBJECT LIBSBML_INVALID_OBJECT@endlink\n *\n')
      output.write(' * @member of {0}_t\n'.format(element))
      output.write(' */\n')
      output.write('LIBSBML_EXTERN\n')
      output.write('int\n')
      output.write('{0}_setMath'.format(element))
      output.write('({0}_t * {1},'.format(element, strFunctions.objAbbrev(element)))
      output.write(' const ASTNode_t* {0});\n\n\n'.format(strFunctions.cleanStr(attName)))
    else:
      output.write('LIBSBML_EXTERN\n')
      output.write('int\n')
      output.write('{0}_set{1}'.format(element, capAttName))
      output.write('({0}_t * {1},'.format(element, strFunctions.objAbbrev(element)))
      output.write(' {0}_t* {1});\n\n\n'.format(attrib['element'], strFunctions.cleanStr(attName)))
    
def writeUnsetFunction(attrib, output, element):
  att = generalFunctions.parseAttributeForC(attrib)
  attName = att[0]
  capAttName = att[1]
  attType = att[2]
  attTypeCode = att[3]
  num = att[4]
  if attrib['type'] == 'element' or attrib['type'] == 'lo_element' or attrib['type'] == 'inline_lo_element':
    return
  output.write('/**\n')
  output.write(' * Unsets the value of the \"{0}\" attribute of the given \n'.format(attName))
  output.write(' * {0}_t structure.\n *\n'.format(element))
  output.write(' * @param {0} the {1}_t structure.\n *\n'.format(strFunctions.objAbbrev(element), element))
  output.write(' * @return integer value indicating success/failure of the\n')
  output.write(' * function.  @if clike The value is drawn from the\n')
  output.write(' * enumeration #OperationReturnValues_t. @endif@~ The possible values\n')
  output.write(' * returned by this function are:\n')
  output.write(' * @li @link OperationReturnValues_t#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink\n')
  output.write(' * @li @link OperationReturnValues_t#LIBSBML_OPERATION_FAILED LIBSBML_OPERATION_FAILED@endlink\n')
  output.write(' * @li @link OperationReturnValues_t#LIBSBML_INVALID_OBJECT LIBSBML_INVALID_OBJECT@endlink\n *\n')
  output.write(' * @member of {0}_t\n'.format(element))
  output.write(' */\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_unset{1}'.format(element, capAttName))
  output.write('({0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))
    
 
def writeHasReqdAttrFunction(output, element):
  output.write('/**\n')
  output.write(' * Predicate returning @c 1 or *c 0 depending on whether all the required\n')
  output.write(' * attributes of the given {0}_t structure have been set.\n *\n'.format(element))
  output.write(' * @param {0} the {1}_t structure to check.\n *\n'.format(strFunctions.objAbbrev(element), element))
  output.write(' * @return @c 1 if all the required attributes for this\n')
  output.write(' * structure have been defined, @c 0 otherwise.\n *\n')
  output.write(' * @member of {0}_t\n'.format(element))
  output.write(' */\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_hasRequiredAttributes'.format(element))
  output.write('(const {0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))

def writeHasReqdElementsFunction(output, element):
  output.write('/**\n')
  output.write(' * Predicate returning @c 1 or *c 0 depending on whether all the required\n')
  output.write(' * sub-elements of the given {0}_t structure have been set.\n *\n'.format(element))
  output.write(' * @param {0} the {1}_t structure to check.\n *\n'.format(strFunctions.objAbbrev(element), element))
  output.write(' * @return @c 1 if all the required sub-elements for this\n')
  output.write(' * structure have been defined, @c 0 otherwise.\n *\n')
  output.write(' * @member of {0}_t\n'.format(element))
  output.write(' */\n')
  output.write('LIBSBML_EXTERN\n')
  output.write('int\n')
  output.write('{0}_hasRequiredElements'.format(element))
  output.write('(const {0}_t * {1});\n\n\n'.format(element, strFunctions.objAbbrev(element)))

    
def writeListOfHeaders(output, element, type, elementDict = None):
  loelement = generalFunctions.writeListOf(element)
  loelementClass = generalFunctions.getListOfClassName(elementDict, type)

  hasId = generalFunctions.hasIdAttribute (elementDict, element)  

  if hasId:
    output.write('LIBSBML_EXTERN\n')
    output.write('{0}_t *\n'.format(type))
    output.write('{0}_getById'.format(loelementClass))
    output.write('(ListOf_t * lo, const char * sid);\n\n\n')
    output.write('LIBSBML_EXTERN\n')
    output.write('{0}_t *\n'.format(type))
    output.write('{0}_removeById'.format(loelementClass))
    output.write('(ListOf_t * lo, const char * sid);\n\n\n')
 
# write the header file      
def createHeader(element, header):
  type = element['name']
  name = element['name']
  if element.has_key('elementName'):
    name = strFunctions.cap(element['elementName']) 
  if element.has_key('element'):
    type = element['element']

  writeConstructors(element['name'], element['package'], header)
  writeAttributeFunctions(element['attribs'], header, element['name'], element)
  writeHasReqdAttrFunction(header, element['name'])
  if element['hasChildren'] == True or element['hasMath'] == True:
    writeHasReqdElementsFunction(header, element['name'])
  if element['hasListOf'] == True:
    writeListOfHeaders(header, name, type, element)
 

  