/**
 * @file PluginidSBasePlugin.h
 * @brief Definition of the PluginidSBasePlugin class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class PluginidSBasePlugin
 * @sbmlbrief{pluginid} Extension of SBase.
 */


#ifndef PluginidSBasePlugin_H__
#define PluginidSBasePlugin_H__


#include <sbml/common/extern.h>


#ifdef __cplusplus


#include <sbml/extension/SBasePlugin.h>
#include <sbml/packages/pluginid/sbml/OtherNormalClass.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN PluginidSBasePlugin : public SBasePlugin
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  std::string mPlugAtt;
  OtherNormalClass* mOtherNormalClass;

  /** @endcond */

public:

  /**
   * Creates a new PluginidSBasePlugin using the given URI, prefix and package
   * namespace.
   *
   * @param uri a string, representing the URI of the SBML Level&nbsp;3 package
   * implemented by this libSBML package extension.
   *
   * @param prefix a string, the XML namespace prefix being used for this
   * package.
   *
   * @param pluginidns a pointer to the namesspaces object
   * (PluginidPkgNamespaces) for this package.
   *
   * @copydetails doc_what_are_xmlnamespaces
   *
   * @copydetails doc_what_are_sbmlnamespaces
   */
  PluginidSBasePlugin(const std::string& uri,
                      const std::string& prefix,
                      PluginidPkgNamespaces* pluginidns);


  /**
   * Copy constructor for PluginidSBasePlugin.
   *
   * @param orig the PluginidSBasePlugin instance to copy.
   */
  PluginidSBasePlugin(const PluginidSBasePlugin& orig);


  /**
   * Assignment operator for PluginidSBasePlugin.
   *
   * @param rhs the PluginidSBasePlugin object whose values are to be used as
   * the basis of the assignment.
   */
  PluginidSBasePlugin& operator=(const PluginidSBasePlugin& rhs);


  /**
   * Creates and returns a deep copy of this PluginidSBasePlugin object.
   *
   * @return a (deep) copy of this PluginidSBasePlugin object.
   */
  virtual PluginidSBasePlugin* clone() const;


  /**
   * Destructor for PluginidSBasePlugin.
   */
  virtual ~PluginidSBasePlugin();


  /**
   * Returns the value of the "id" attribute of this PluginidSBasePlugin.
   *
   * @return the value of the "id" attribute of this PluginidSBasePlugin as a
   * string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "plugAtt" attribute of this PluginidSBasePlugin.
   *
   * @return the value of the "plugAtt" attribute of this PluginidSBasePlugin
   * as a string.
   */
  const std::string& getPlugAtt() const;


  /**
   * Predicate returning @c true if this PluginidSBasePlugin's "id" attribute
   * is set.
   *
   * @return @c true if this PluginidSBasePlugin's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this PluginidSBasePlugin's "plugAtt"
   * attribute is set.
   *
   * @return @c true if this PluginidSBasePlugin's "plugAtt" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetPlugAtt() const;


  /**
   * Sets the value of the "id" attribute of this PluginidSBasePlugin.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * Calling this function with @p id = @c NULL or an empty string is
   * equivalent to calling unsetId().
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "plugAtt" attribute of this PluginidSBasePlugin.
   *
   * @param plugAtt std::string& value of the "plugAtt" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p plugAtt = @c NULL or an empty string is
   * equivalent to calling unsetPlugAtt().
   */
  int setPlugAtt(const std::string& plugAtt);


  /**
   * Unsets the value of the "id" attribute of this PluginidSBasePlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "plugAtt" attribute of this PluginidSBasePlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPlugAtt();


  /**
   * Returns the value of the "otherNormalClass" element of this
   * PluginidSBasePlugin.
   *
   * @return the value of the "otherNormalClass" element of this
   * PluginidSBasePlugin as a OtherNormalClass*.
   */
  const OtherNormalClass* getOtherNormalClass() const;


  /**
   * Returns the value of the "otherNormalClass" element of this
   * PluginidSBasePlugin.
   *
   * @return the value of the "otherNormalClass" element of this
   * PluginidSBasePlugin as a OtherNormalClass*.
   */
  OtherNormalClass* getOtherNormalClass();


  /**
   * Predicate returning @c true if this PluginidSBasePlugin's
   * "otherNormalClass" element is set.
   *
   * @return @c true if this PluginidSBasePlugin's "otherNormalClass" element
   * has been set, otherwise @c false is returned.
   */
  bool isSetOtherNormalClass() const;


  /**
   * Sets the value of the "otherNormalClass" element of this
   * PluginidSBasePlugin.
   *
   * @param otherNormalClass OtherNormalClass* value of the "otherNormalClass"
   * element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOtherNormalClass(const OtherNormalClass* otherNormalClass);


  /**
   * Creates a new OtherNormalClass object, adds it to this PluginidSBasePlugin
   * object and returns the OtherNormalClass object created.
   *
   * @return a new OtherNormalClass object instance.
   */
  OtherNormalClass* createOtherNormalClass();


  /**
   * Unsets the value of the "otherNormalClass" element of this
   * PluginidSBasePlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOtherNormalClass();


  /**
   * Predicate returning @c true if all the required attributes for this
   * PluginidSBasePlugin object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * PluginidSBasePlugin have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the PluginidSBasePlugin object are:
   * @li "id"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument
   */
  virtual void setSBMLDocument(SBMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Connects to parent element
   */
  virtual void connectToParent(SBase* base);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Updates the namespaces when setLevelVersion is used
   */
  virtual void updateSBMLNamespace(const std::string& package,
                                   unsigned int level,
                                   unsigned int version);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this PluginidSBasePlugin's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this PluginidSBasePlugin's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this
   * PluginidSBasePlugin.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates and returns an new "elementName" object in this
   * PluginidSBasePlugin.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this PluginidSBasePlugin.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SBase* element);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * PluginidSBasePlugin.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SBase* removeChildObject(const std::string& elementName,
                                   const std::string& id);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the number of "elementName" in this PluginidSBasePlugin.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this PluginidSBasePlugin.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SBase* getObject(const std::string& elementName, unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid. If no
   * such object is found this method returns @c NULL.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List* pointer of pointers to all SBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(ElementFilter * filter = NULL);



  /** @cond doxygenLibsbmlInternal */

  /**
   * Append items from model (used in comp flattening)
   *
   * @param model a pointer to a model object.
   *
   */
  int appendFrom(const Model* model);

  /** @endcond */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  void readL3V1V1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  void readL3V2V1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  void writeL3V1V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  void writeL3V2V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Returns the value of the "id" attribute of this PluginidSBasePlugin_t.
 *
 * @param psbp the PluginidSBasePlugin_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this PluginidSBasePlugin_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
char *
PluginidSBasePlugin_getId(const PluginidSBasePlugin_t * psbp);


/**
 * Returns the value of the "plugAtt" attribute of this PluginidSBasePlugin_t.
 *
 * @param psbp the PluginidSBasePlugin_t structure whose plugAtt is sought.
 *
 * @return the value of the "plugAtt" attribute of this PluginidSBasePlugin_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
char *
PluginidSBasePlugin_getPlugAtt(const PluginidSBasePlugin_t * psbp);


/**
 * Predicate returning @c 1 (true) if this PluginidSBasePlugin_t's "id"
 * attribute is set.
 *
 * @param psbp the PluginidSBasePlugin_t structure.
 *
 * @return @c 1 (true) if this PluginidSBasePlugin_t's "id" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_isSetId(const PluginidSBasePlugin_t * psbp);


/**
 * Predicate returning @c 1 (true) if this PluginidSBasePlugin_t's "plugAtt"
 * attribute is set.
 *
 * @param psbp the PluginidSBasePlugin_t structure.
 *
 * @return @c 1 (true) if this PluginidSBasePlugin_t's "plugAtt" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_isSetPlugAtt(const PluginidSBasePlugin_t * psbp);


/**
 * Sets the value of the "id" attribute of this PluginidSBasePlugin_t.
 *
 * @param psbp the PluginidSBasePlugin_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling PluginidSBasePlugin_unsetId().
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_setId(PluginidSBasePlugin_t * psbp, const char * id);


/**
 * Sets the value of the "plugAtt" attribute of this PluginidSBasePlugin_t.
 *
 * @param psbp the PluginidSBasePlugin_t structure.
 *
 * @param plugAtt const char * value of the "plugAtt" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p plugAtt = @c NULL or an empty string is
 * equivalent to calling PluginidSBasePlugin_unsetPlugAtt().
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_setPlugAtt(PluginidSBasePlugin_t * psbp,
                               const char * plugAtt);


/**
 * Unsets the value of the "id" attribute of this PluginidSBasePlugin_t.
 *
 * @param psbp the PluginidSBasePlugin_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_unsetId(PluginidSBasePlugin_t * psbp);


/**
 * Unsets the value of the "plugAtt" attribute of this PluginidSBasePlugin_t.
 *
 * @param psbp the PluginidSBasePlugin_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_unsetPlugAtt(PluginidSBasePlugin_t * psbp);


/**
 * Returns the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin_t.
 *
 * @param psbp the PluginidSBasePlugin_t structure whose otherNormalClass is
 * sought.
 *
 * @return the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin_t as a OtherNormalClass*.
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
const OtherNormalClass_t*
PluginidSBasePlugin_getOtherNormalClass(const PluginidSBasePlugin_t * psbp);


/**
 * Predicate returning @c 1 (true) if this PluginidSBasePlugin_t's
 * "otherNormalClass" element is set.
 *
 * @param psbp the PluginidSBasePlugin_t structure.
 *
 * @return @c 1 (true) if this PluginidSBasePlugin_t's "otherNormalClass"
 * element has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_isSetOtherNormalClass(const PluginidSBasePlugin_t * psbp);


/**
 * Sets the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin_t.
 *
 * @param psbp the PluginidSBasePlugin_t structure.
 *
 * @param otherNormalClass OtherNormalClass_t* value of the "otherNormalClass"
 * element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_setOtherNormalClass(PluginidSBasePlugin_t * psbp,
                                        const OtherNormalClass_t*
                                          otherNormalClass);


/**
 * Creates a new OtherNormalClass_t object, adds it to this
 * PluginidSBasePlugin_t object and returns the OtherNormalClass_t object
 * created.
 *
 * @param psbp the PluginidSBasePlugin_t structure to which the
 * OtherNormalClass_t should be added.
 *
 * @return a new OtherNormalClass_t object instance.
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
OtherNormalClass_t*
PluginidSBasePlugin_createOtherNormalClass(PluginidSBasePlugin_t* psbp);


/**
 * Unsets the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin_t.
 *
 * @param psbp the PluginidSBasePlugin_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof PluginidSBasePlugin_t
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_unsetOtherNormalClass(PluginidSBasePlugin_t * psbp);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !PluginidSBasePlugin_H__ */


