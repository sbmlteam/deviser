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

import writeHeader

def writeClassDefn(fileOut, nameOfClass, pkg, members, attribs, plugin):
  fileOut.write('class LIBSBML_EXTERN {0} : public SBasePlugin\n'.format(nameOfClass))
  fileOut.write('{\npublic:\n\n')
  writeConstructors(fileOut, nameOfClass, pkg)
  writeRequiredMethods(fileOut, attribs)
  writeGetFunctions(fileOut, pkg, members, nameOfClass, attribs)
  generalFunctions.writeSetDocHeader(fileOut)
  # TO DO - these properly
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  virtual void connectToParent (SBase* sbase);\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  virtual void enablePackageInternal(const std::string& pkgURI,\n')
  fileOut.write('                                     const std::string& pkgPrefix, bool flag);\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  virtual bool accept (SBMLVisitor& v) const;\n\n')
  generalFunctions.writeInternalEnd(fileOut)

  writeClassEnd(fileOut, members, attribs, plugin)

def writeClassEnd(fileOut, members, attribs, plugin):
  fileOut.write('protected:\n\n')
  generalFunctions.writeInternalStart(fileOut)
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
      fileOut.write('  ListOf{0}s m{0}s;\n'.format(mem['name']))
    else:
      fileOut.write('  {0}* m{0};\n'.format(mem['name']))
  for i in range (0, len(attribs)):
    mem = attribs[i]
    writeHeader.writeAtt(mem, fileOut);
  fileOut.write('\n')
  generalFunctions.writeInternalEnd(fileOut)

  if plugin.has_key('addDecls'):
    fileOut.write(open(plugin['addDecls'], 'r').read())

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

def writeGetFunctions(fileOut, pkg, members, plugin, attribs):
  fileOut.write('  //---------------------------------------------------------------\n')
  fileOut.write('  //\n')
  fileOut.write('  // Functions for interacting with the members of the plugin\n')
  fileOut.write('  //\n')
  fileOut.write('  //---------------------------------------------------------------\n\n')
  generalFunctions.writeGetAllElements(fileOut)
  for i in range (0, len(members)):
    mem = members[i]
    if mem['isListOf'] == True:
      writeFunctions(fileOut, mem['name'])
    else:
      writeMemberFunctions(fileOut, mem['name'], plugin)

  writeHeader.writeAttributeFunctions(attribs, fileOut, plugin, dict({}))
  
def writeMemberFunctions(fileOut, object, plugin):
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the {0} from this {1} object.\n'.format(object, plugin))
  fileOut.write('   *\n')
  fileOut.write('   * @return the {0} from object in this {1} object.\n'.format(object, plugin))
  fileOut.write('   */\n')
  fileOut.write('  const {0}* get{0} () const;\n\n\n'.format(object))

  fileOut.write('  /**\n')
  fileOut.write('   * Returns the {0} from this {1} object.\n'.format(object, plugin))
  fileOut.write('   *\n')
  fileOut.write('   * @return the {0} from object in this {1} object.\n'.format(object, plugin))
  fileOut.write('   */\n')
  fileOut.write('  {0}* get{0} ();\n\n\n'.format(object))


  fileOut.write('  /**\n')
  fileOut.write('   * Predicate returning @c true or @c false depending on ')
  fileOut.write('whether the\n    \"{0}\" '.format(object))
  fileOut.write('element has been set.\n   *\n')
  fileOut.write('   * @return @c true if the \"{0}\"'.format(object))
  fileOut.write(' element has been set,\n')
  fileOut.write('   * otherwise @c false is returned.\n')
  fileOut.write('   */\n')
  fileOut.write('  bool isSet{0}() const;\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Sets the {0} element in this {1} object.\n'.format(object, plugin))
  fileOut.write('   *\n')
  fileOut.write('   * @param {0} the {0}* to be set.\n'.format(strFunctions.lowerFirst(object), object))
  fileOut.write('   *\n')
  fileOut.write('   * @return integer value indicating success/failure of the\n')
  fileOut.write('   * function.  @if clike The value is drawn from the\n')
  fileOut.write('   * enumeration #OperationReturnValues_t. @endif The possible values\n')
  fileOut.write('   * returned by this function are:\n')
  fileOut.write('   * @li LIBSBML_OPERATION_SUCCESS\n')
  fileOut.write('   */\n')
  fileOut.write('  int set{0} (const {0}* {1});\n\n\n'.format(object, strFunctions.lowerFirst(object)))
  fileOut.write('  /**\n')
  fileOut.write('   * Creates a new {0} object and adds it to the {1} object.\n'.format(object, plugin))
  fileOut.write('   *\n')
  fileOut.write('   * @return the newly created {0} object.\n'.format(object))
  fileOut.write('   */\n')
  fileOut.write('  {0}* create{0} ();\n\n\n'.format(object))

def writeFunctions(fileOut, object):
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the ListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return ListOf{0}s object in this plugin object.\n'.format(object))
  fileOut.write('   */\n')
  fileOut.write('  const ListOf{0}s* getListOf{0}s () const;\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the ListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return ListOf{0}s object in this plugin object.\n'.format(object))
  fileOut.write('   */\n')
  fileOut.write('  ListOf{0}s* getListOf{0}s ();\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the {0} object that belongs to the given index. If the \n'.format(object)) 
  fileOut.write('   * index is invalid, NULL is returned.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param n the index number of the {0} to get\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return the nth {0} in the ListOf{0}s\n'.format(object))
  fileOut.write('   */\n')
  fileOut.write('  const {0}* get{0}(unsigned int n) const;\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the {0} object that belongs to the given index. If the \n'.format(object)) 
  fileOut.write('   * index is invalid, NULL is returned.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param n the index number of the {0} to get\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return the nth {0} in the ListOf{0}s\n'.format(object))
  fileOut.write('   */\n')
  fileOut.write('  {0}* get{0}(unsigned int n);\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the {0} object based on its identifier.\n'.format(object)) 
  fileOut.write('   *\n')
  fileOut.write('   * @param sid a string representing the id of the {0} to get\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return {0} in the ListOf{0}s with the given id\n'.format(object))
  fileOut.write('   * or NULL if no such {0} exists.\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @see get(unsigned int n)\n')
  fileOut.write('   * @see size()\n')
  fileOut.write('   */\n')
  fileOut.write('  const {0}* get{0}(const std::string& sid) const;\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the {0} object based on its identifier.\n'.format(object)) 
  fileOut.write('   *\n')
  fileOut.write('   * @param sid a string representing the id of the {0} to get\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return {0} in the ListOf{0}s with the given id\n'.format(object))
  fileOut.write('   * or NULL if no such {0} exists.\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @see get(unsigned int n)\n')
  fileOut.write('   * @see size()\n')
  fileOut.write('   */\n')
  fileOut.write('  {0}* get{0}(const std::string& sid);\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Adds a copy of the given {0} to the ListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @param {0} the {0} to be added.\n'.format(strFunctions.lowerFirst(object), object))
  fileOut.write('   *\n')
  fileOut.write('   * @return integer value indicating success/failure of the\n')
  fileOut.write('   * function.  @if clike The value is drawn from the\n')
  fileOut.write('   * enumeration #OperationReturnValues_t. @endif The possible values\n')
  fileOut.write('   * returned by this function are:\n')
  fileOut.write('   * @li LIBSBML_OPERATION_SUCCESS\n')
  fileOut.write('   */\n')
  fileOut.write('  int add{0} (const {0}* {1});\n\n\n'.format(object, strFunctions.lowerFirst(object)))
  fileOut.write('  /**\n')
  fileOut.write('   * Creates a new {0} object and adds it to the ListOf{0}s in this plugin object.\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return the newly created {0} object.\n'.format(object))
  fileOut.write('   */\n')
  fileOut.write('  {0}* create{0} ();\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Removes the nth {0} object from this plugin object\n'.format(object)) 
  fileOut.write('   * and returns a pointer to it.\n')
  fileOut.write('   *\n')
  fileOut.write('   * The caller owns the returned object and is responsible for\n')
  fileOut.write('   * deleting it.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param n the index of the {0} to remove\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return the {0} object removed \n'.format(object))
  fileOut.write('   * or NULL index was out of range.\n'.format(object))
  fileOut.write('   */\n')
  fileOut.write('  {0}* remove{0}(unsigned int n);\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Removes the {0} object with the given id from this plugin object\n'.format(object)) 
  fileOut.write('   * and returns a pointer to it.\n')
  fileOut.write('   *\n')
  fileOut.write('   * The caller owns the returned object and is responsible for\n')
  fileOut.write('   * deleting it.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @param sid a string representing the id of the {0} to remove\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return the {0} object removed \n'.format(object))
  fileOut.write('   * or NULL if no such {0} exists.\n'.format(object))
  fileOut.write('   */\n')
  fileOut.write('  {0}* remove{0}(const std::string& sid);\n\n\n'.format(object))
  fileOut.write('  /**\n')
  fileOut.write('   * Returns the number of {0} objects in this plugin object.\n'.format(object))
  fileOut.write('   *\n')
  fileOut.write('   * @return the number of {0} objects in this plugin object.\n'.format(object))
  fileOut.write('   */\n')
  fileOut.write('  unsigned int getNum{0}s () const;\n\n\n'.format(object))



# write the include files
def writeIncludes(fileOut, pkg, element, members, attribs):
  fileOut.write('\n\n');
  fileOut.write('#ifndef {0}_H__\n'.format(element))
  fileOut.write('#define {0}_H__\n'.format(element))
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/common/extern.h>\n')
  fileOut.write('\n\n');
  fileOut.write('#ifdef __cplusplus\n')
  fileOut.write('\n\n');
  fileOut.write('#include <sbml/extension/SBasePlugin.h>\n')
  for i in range (0, len(members)):
    mem = members[i]
    fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkg.lower(), mem['name']))
  if len(members) == 0:
    fileOut.write('#include <sbml/packages/{0}/extension/{1}Extension.h>\n'.format(pkg.lower(), pkg))
  for i in range (0, len(attribs)):
    if (attribs[i]['type'] == 'element' or attribs[i]['type'] == 'lo_element' or attribs[i]['type'] == 'inline_lo_element') and attribs[i]['name'] != 'math':
      if (attribs[i]['element'] == None):
        fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkg.lower(), strFunctions.cap(attribs[i]['name'])))
      else:
        fileOut.write('#include <sbml/packages/{0}/sbml/{1}.h>\n'.format(pkg.lower(), strFunctions.cap(attribs[i]['element'])))

  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_BEGIN\n')
  fileOut.write('\n\n');

def writeIncludeEnds(fileOut, element):
  fileOut.write('\n\n');
  fileOut.write('LIBSBML_CPP_NAMESPACE_END\n')
  fileOut.write('\n\n');
  fileOut.write('#endif /* __cplusplus */\n')
  fileOut.write('#endif /* {0}_H__ */\n\n\n'.format(element))

def writeRequiredMethods(fileOut, attribs):
  fileOut.write('  //---------------------------------------------------------------\n')
  fileOut.write('  //\n')
  fileOut.write('  // overridden virtual functions for read/write/check\n')
  fileOut.write('  //\n')
  fileOut.write('  //---------------------------------------------------------------\n\n')
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n')
  fileOut.write('   * Subclasses must override this method to create, store, and then\n')
  fileOut.write('   * return an SBML object corresponding to the next XMLToken in the\n')
  fileOut.write('   * XMLInputStream if they have their specific elements.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @return the SBML object corresponding to next XMLToken in the\n')
  fileOut.write('   * XMLInputStream or NULL if the token was not recognized.\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual SBase* createObject (XMLInputStream& stream);\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  generalFunctions.writeInternalStart(fileOut)
  fileOut.write('  /**\n')
  fileOut.write('   * Subclasses must override this method to write out their contained\n')
  fileOut.write('   * SBML objects as XML elements if they have their specific elements.\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual void writeElements (XMLOutputStream& stream) const;\n\n\n')
  generalFunctions.writeInternalEnd(fileOut)
  fileOut.write('  /**\n')
  fileOut.write('   * Checks if this plugin object has all the required elements.\n')
  fileOut.write('   *\n')
  fileOut.write('   * Subclasses must override this method \n')
  fileOut.write('   * if they have their specific elements.\n')
  fileOut.write('   *\n')
  fileOut.write('   * @return true if this plugin object has all the required elements\n')
  fileOut.write('   * otherwise false will be returned.\n')
  fileOut.write('   */\n')
  fileOut.write('  virtual bool hasRequiredElements () const;\n\n\n')
  fileOut.write('  //---------------------------------------------------------------\n\n\n')
  generalFunctions.writeAddExpectedHeader(fileOut)
  generalFunctions.writeReadAttributesHeader(fileOut)
  generalFunctions.writeWriteAttributesHeader(fileOut)

def createHeader(package, plugin):
  nameOfPackage = package['name']
  nameOfPlugin = plugin['sbase']
  nameOfClass = nameOfPackage + nameOfPlugin + 'Plugin'
  codeName = nameOfClass + '.h'
  code = open(codeName, 'w')
  fileHeaders.addFilename(code, codeName, nameOfClass)
  fileHeaders.addLicence(code)
  writeIncludes(code, nameOfPackage, nameOfClass, plugin['extension'], plugin['attribs'])
  writeClassDefn(code, nameOfClass, nameOfPackage, plugin['extension'], plugin['attribs'], plugin)
  writeIncludeEnds(code, nameOfClass)

  