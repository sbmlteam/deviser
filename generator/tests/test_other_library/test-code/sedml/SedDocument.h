/**
 * @file SedDocument.h
 * @brief Definition of the SedDocument class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2016, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedDocument
 * @sbmlbrief{sedml} TODO:Definition of the SedDocument class.
 */


#ifndef SedDocument_H__
#define SedDocument_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOfModels.h>
#include <sedml/SedErrorLog.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedDocument : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  int mLevel;
  bool mIsSetLevel;
  int mVersion;
  bool mIsSetVersion;
  SedListOfModels mModels;
  SedErrorLog mErrorLog;

  /** @endcond */

public:

  /**
   * Creates a new SedDocument using the given SEDML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedDocument.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedDocument.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedDocument(unsigned int level = SEDML_DEFAULT_LEVEL,
              unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedDocument using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedDocument(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedDocument.
   *
   * @param orig the SedDocument instance to copy.
   */
  SedDocument(const SedDocument& orig);


  /**
   * Assignment operator for SedDocument.
   *
   * @param rhs the SedDocument object whose values are to be used as the basis
   * of the assignment.
   */
  SedDocument& operator=(const SedDocument& rhs);


  /**
   * Creates and returns a deep copy of this SedDocument object.
   *
   * @return a (deep) copy of this SedDocument object.
   */
  virtual SedDocument* clone() const;


  /**
   * Destructor for SedDocument.
   */
  virtual ~SedDocument();


  /**
   * Returns the value of the "level" attribute of this SedDocument.
   *
   * @return the value of the "level" attribute of this SedDocument as a
   * integer.
   */
  int getLevel() const;


  /**
   * Returns the value of the "version" attribute of this SedDocument.
   *
   * @return the value of the "version" attribute of this SedDocument as a
   * integer.
   */
  int getVersion() const;


  /**
   * Predicate returning @c true if this SedDocument's "level" attribute is
   * set.
   *
   * @return @c true if this SedDocument's "level" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLevel() const;


  /**
   * Predicate returning @c true if this SedDocument's "version" attribute is
   * set.
   *
   * @return @c true if this SedDocument's "version" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetVersion() const;


  /**
   * Sets the value of the "level" attribute of this SedDocument.
   *
   * @param level int value of the "level" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLevel(int level);


  /**
   * Sets the value of the "version" attribute of this SedDocument.
   *
   * @param version int value of the "version" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setVersion(int version);


  /**
   * Unsets the value of the "level" attribute of this SedDocument.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLevel();


  /**
   * Unsets the value of the "version" attribute of this SedDocument.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetVersion();


  /**
   * Returns the SedListOfModels from this SedDocument.
   *
   * @return the SedListOfModels from this SedDocument.
   */
  const SedListOfModels* getListOfModels() const;


  /**
   * Returns the SedListOfModels from this SedDocument.
   *
   * @return the SedListOfModels from this SedDocument.
   */
  SedListOfModels* getListOfModels();


  /**
   * Get a SedModel from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedModel to
   * retrieve.
   *
   * @return the nth SedModel in the SedListOfModels within this SedDocument.
   *
   * @see getNumModels()
   */
  SedModel* getModel(unsigned int n);


  /**
   * Get a SedModel from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedModel to
   * retrieve.
   *
   * @return the nth SedModel in the SedListOfModels within this SedDocument.
   *
   * @see getNumModels()
   */
  const SedModel* getModel(unsigned int n) const;


  /**
   * Get a SedModel from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedModel to
   * retrieve.
   *
   * @return the SedModel in the SedListOfModels within this SedDocument with
   * the given id or NULL if no such SedModel exists.
   *
   * @see getModel(unsigned int n)
   * @see getNumModels()
   */
  SedModel* getModel(const std::string& sid);


  /**
   * Get a SedModel from the SedDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SedModel to
   * retrieve.
   *
   * @return the SedModel in the SedListOfModels within this SedDocument with
   * the given id or NULL if no such SedModel exists.
   *
   * @see getModel(unsigned int n)
   * @see getNumModels()
   */
  const SedModel* getModel(const std::string& sid) const;


  /**
   * Adds a copy of the given SedModel to this SedDocument.
   *
   * @param sm the SedModel object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createModel()
   */
  int addModel(const SedModel* sm);


  /**
   * Get the number of SedModel objects in this SedDocument.
   *
   * @return the number of SedModel objects in this SedDocument.
   */
  unsigned int getNumModels() const;


  /**
   * Creates a new SedModel object, adds it to this SedDocument object and
   * returns the SedModel object created.
   *
   * @return a new SedModel object instance.
   *
   * @see addModel(const SedModel* sm)
   */
  SedModel* createModel();


  /**
   * Removes the nth SedModel from this SedDocument and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SedModel to remove.
   *
   * @return a pointer to the nth SedModel in this SedDocument.
   *
   * @see getNumModels
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  SedModel* removeModel(unsigned int n);


  /**
   * Removes the SedModel from this SedDocument based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedModel to remove.
   *
   * @return the SedModel in this SedDocument based on the identifier or NULL
   * if no such SedModel exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  SedModel* removeModel(const std::string& sid);


  /**
   * Returns the XML element name of this SedDocument object.
   *
   * For SedDocument, the XML element name is always @c "sedML".
   *
   * @return the name of this element, i.e. @c "sedML".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedDocument object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   *
   * @sedmlconstant{SEDML_DOCUMENT, SEDMLSedmlTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedDocument object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedDocument have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedDocument object are:
   * @li "level"
   * @li "version"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SedDocument object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedDocument have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedDocument object are:
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Accepts the given SedVisitor
   */
  virtual bool accept(SedVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the parent SedDocument
   */
  virtual void setSedDocument(SedDocument* d);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           const char* value) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Predicate returning @c true if this SedDocument's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedDocument's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, const char*
    value);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this SedDocument.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates and returns an new "elementName" object in this SedDocument.
   *
   * @param elementName, the name of the element to create.
   *
   * pointer to the element created.
   */
  virtual SBase* createObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the number of "elementName" in this SedDocument.
   *
   * @param elementName, the name of the element to get number of.
   *
   * unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Returns the nth object of "objectName" in this SedDocument.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * pointer to the object.
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
   * @return a pointer to the SedBase element with the given @p id.
   */
  virtual SedBase* getElementBySId(const std::string& id);


  /**
   * Returns the value of the "Namespaces" element of this SedDocument.
   *
   * @return the value of the "Namespaces" element of this SedDocument as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*.
   */
  virtual const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* getNamespaces()
    const;


  /**
   * Returns the value of the "Namespaces" element of this SedDocument.
   *
   * @return the value of the "Namespaces" element of this SedDocument as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*.
   */
  virtual LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* getNamespaces();


  /**
   * Returns the value of the "SedErrorLog" element of this SedDocument.
   *
   * @return the value of the "SedErrorLog" element of this SedDocument as a
   * SedErrorLog*.
   */
  const SedErrorLog* getErrorLog() const;


  /**
   * Returns the value of the "SedErrorLog" element of this SedDocument.
   *
   * @return the value of the "SedErrorLog" element of this SedDocument as a
   * SedErrorLog*.
   */
  SedErrorLog* getErrorLog();


  /**
   * Get a SedError from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedError to
   * retrieve.
   *
   * @return the nth SedError in the SedListOfErrors within this SedDocument.
   *
   * @see getNumErrors()
   */
  SedError* getError(unsigned int n);


  /**
   * Get a SedError from the SedDocument.
   *
   * @param n an unsigned int representing the index of the SedError to
   * retrieve.
   *
   * @return the nth SedError in the SedListOfErrors within this SedDocument.
   *
   * @see getNumErrors()
   */
  const SedError* getError(unsigned int n) const;


  /**
   * Get the number of SedError objects in this SedDocument.
   *
   * @return the number of SedError objects in this SedDocument.
   */
  unsigned int getNumErrors() const;


  /**
   * Get the number of SedError objects in this SedDocument with the given
   * severity.
   *
   * @param severity the severity of the SedError to return.
   *
   * @return the number of SedError objects in this SedDocument.
   */
  unsigned int getNumErrors(unsigned int severity) const;


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the namespace for the Sedml package
   */
  virtual void writeXMLNS(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedDocument_t using the given SEDML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this
 * SedDocument_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedDocument_t.
 *
 * @throws SEDMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SEDML object, are either invalid or mismatched with respect to the parent
 * SedDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDocument_t *
SedDocument_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedDocument_t object.
 *
 * @param sd the SedDocument_t structure.
 *
 * @return a (deep) copy of this SedDocument_t object.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedDocument_t*
SedDocument_clone(const SedDocument_t* sd);


/**
 * Frees this SedDocument_t object.
 *
 * @param sd the SedDocument_t structure.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
void
SedDocument_free(SedDocument_t* sd);


/**
 * Returns the value of the "level" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose level is sought.
 *
 * @return the value of the "level" attribute of this SedDocument_t as a
 * integer.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_getLevel(const SedDocument_t * sd);


/**
 * Returns the value of the "version" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose version is sought.
 *
 * @return the value of the "version" attribute of this SedDocument_t as a
 * integer.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_getVersion(const SedDocument_t * sd);


/**
 * Predicate returning @c 1 if this SedDocument_t's "level" attribute is set.
 *
 * @param sd the SedDocument_t structure.
 *
 * @return @c 1 if this SedDocument_t's "level" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_isSetLevel(const SedDocument_t * sd);


/**
 * Predicate returning @c 1 if this SedDocument_t's "version" attribute is set.
 *
 * @param sd the SedDocument_t structure.
 *
 * @return @c 1 if this SedDocument_t's "version" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_isSetVersion(const SedDocument_t * sd);


/**
 * Sets the value of the "level" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure.
 *
 * @param level int value of the "level" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_setLevel(SedDocument_t * sd, int level);


/**
 * Sets the value of the "version" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure.
 *
 * @param version int value of the "version" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_setVersion(SedDocument_t * sd, int version);


/**
 * Unsets the value of the "level" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_unsetLevel(SedDocument_t * sd);


/**
 * Unsets the value of the "version" attribute of this SedDocument_t.
 *
 * @param sd the SedDocument_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_unsetVersion(SedDocument_t * sd);


/**
 * Returns a ListOf_t* containing SedModel_t objects from this SedDocument_t.
 *
 * @param sd the SedDocument_t structure whose "SedListOfModels" is sought.
 *
 * @return the "SedListOfModels" from this SedDocument_t as a ListOf_t *.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfModels(SedDocument_t* sd);


/**
 * Get a SedModel_t from the SedDocument_t.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedModel_t to
 * retrieve.
 *
 * @return the nth SedModel_t in the SedListOfModels within this SedDocument.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
const SedModel_t*
SedDocument_getModel(SedDocument_t* sd, unsigned int n);


/**
 * Get a SedModel_t from the SedDocument_t based on its identifier.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedModel_t to
 * retrieve.
 *
 * @return the SedModel_t in the SedListOfModels within this SedDocument with
 * the given id or NULL if no such SedModel_t exists.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
const SedModel_t*
SedDocument_getModelById(SedDocument_t* sd, const char *sid);


/**
 * Adds a copy of the given SedModel_t to this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to which the SedModel_t should be
 * added.
 *
 * @param sm the SedModel_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_addModel(SedDocument_t* sd, const SedModel_t* sm);


/**
 * Get the number of SedModel_t objects in this SedDocument_t.
 *
 * @param sd the SedDocument_t structure to query.
 *
 * @return the number of SedModel_t objects in this SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumModels(SedDocument_t* sd);


/**
 * Creates a new SedModel_t object, adds it to this SedDocument_t object and
 * returns the SedModel_t object created.
 *
 * @param sd the SedDocument_t structure to which the SedModel_t should be
 * added.
 *
 * @return a new SedModel_t object instance.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_createModel(SedDocument_t* sd);


/**
 * Removes the nth SedModel_t from this SedDocument_t and returns a pointer to
 * it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedModel_t to remove.
 *
 * @return a pointer to the nth SedModel_t in this SedDocument_t.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_removeModel(SedDocument_t* sd, unsigned int n);


/**
 * Removes the SedModel_t from this SedDocument_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sd the SedDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SedModel_t to remove.
 *
 * @return the SedModel_t in this SedDocument_t based on the identifier or NULL
 * if no such SedModel_t exists.
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_removeModelById(SedDocument_t* sd, const char* sid);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * SedDocument_t object have been set.
 *
 * @param sd the SedDocument_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * SedDocument_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the SedDocument_t object are:
 * @li "level"
 * @li "version"
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_hasRequiredAttributes(const SedDocument_t * sd);


/**
 * Predicate returning @c 1 if all the required elements for this SedDocument_t
 * object have been set.
 *
 * @param sd the SedDocument_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this
 * SedDocument_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the SedDocument_t object are:
 *
 * @memberof SedDocument_t
 */
LIBSEDML_EXTERN
int
SedDocument_hasRequiredElements(const SedDocument_t * sd);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedDocument_H__ */


