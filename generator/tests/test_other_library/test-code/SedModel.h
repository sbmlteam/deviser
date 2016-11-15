/**
 * @file SedModel.h
 * @brief Definition of the SedModel class.
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
 * @class SedModel
 * @sbmlbrief{sedml} TODO:Definition of the SedModel class.
 */


#ifndef SedModel_H__
#define SedModel_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedBase.h>
#include <sedml/SedListOfChanges.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class LIBSEDML_EXTERN SedModel : public SedBase
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mId;
  std::string mName;
  std::string mLanguage;
  std::string mSource;
  SedListOfChanges mChanges;

  /** @endcond */

public:

  /**
   * Creates a new SedModel using the given SEDML Level and @ p version values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this SedModel.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedModel.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedModel(unsigned int level = SEDML_DEFAULT_LEVEL,
           unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedModel using the given SedNamespaces object @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @throws SEDMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SEDML object, are either invalid or mismatched with respect to the parent
   * SedDocument object.
   * @copydetails doc_note_setting_lv
   */
  SedModel(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedModel.
   *
   * @param orig the SedModel instance to copy.
   */
  SedModel(const SedModel& orig);


  /**
   * Assignment operator for SedModel.
   *
   * @param rhs the SedModel object whose values are to be used as the basis of
   * the assignment.
   */
  SedModel& operator=(const SedModel& rhs);


  /**
   * Creates and returns a deep copy of this SedModel object.
   *
   * @return a (deep) copy of this SedModel object.
   */
  virtual SedModel* clone() const;


  /**
   * Destructor for SedModel.
   */
  virtual ~SedModel();


  /**
   * Returns the value of the "id" attribute of this SedModel.
   *
   * @return the value of the "id" attribute of this SedModel as a string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this SedModel.
   *
   * @return the value of the "name" attribute of this SedModel as a string.
   */
  const std::string& getName() const;


  /**
   * Returns the value of the "language" attribute of this SedModel.
   *
   * @return the value of the "language" attribute of this SedModel as a
   * string.
   */
  const std::string& getLanguage() const;


  /**
   * Returns the value of the "source" attribute of this SedModel.
   *
   * @return the value of the "source" attribute of this SedModel as a string.
   */
  const std::string& getSource() const;


  /**
   * Predicate returning @c true if this SedModel's "id" attribute is set.
   *
   * @return @c true if this SedModel's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true if this SedModel's "name" attribute is set.
   *
   * @return @c true if this SedModel's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetName() const;


  /**
   * Predicate returning @c true if this SedModel's "language" attribute is
   * set.
   *
   * @return @c true if this SedModel's "language" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLanguage() const;


  /**
   * Predicate returning @c true if this SedModel's "source" attribute is set.
   *
   * @return @c true if this SedModel's "source" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetSource() const;


  /**
   * Sets the value of the "id" attribute of this SedModel.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Sets the value of the "name" attribute of this SedModel.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setName(const std::string& name);


  /**
   * Sets the value of the "language" attribute of this SedModel.
   *
   * @param language std::string& value of the "language" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLanguage(const std::string& language);


  /**
   * Sets the value of the "source" attribute of this SedModel.
   *
   * @param source std::string& value of the "source" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setSource(const std::string& source);


  /**
   * Unsets the value of the "id" attribute of this SedModel.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "name" attribute of this SedModel.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetName();


  /**
   * Unsets the value of the "language" attribute of this SedModel.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLanguage();


  /**
   * Unsets the value of the "source" attribute of this SedModel.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSource();


  /**
   * Returns the SedListOfChanges from this SedModel.
   *
   * @return the SedListOfChanges from this SedModel.
   */
  const SedListOfChanges* getListOfChanges() const;


  /**
   * Returns the SedListOfChanges from this SedModel.
   *
   * @return the SedListOfChanges from this SedModel.
   */
  SedListOfChanges* getListOfChanges();


  /**
   * Get a SedChange from the SedModel.
   *
   * @param n an unsigned int representing the index of the SedChange to
   * retrieve.
   *
   * @return the nth SedChange in the SedListOfChanges within this SedModel.
   *
   * @see getNumChanges()
   */
  SedChange* getChange(unsigned int n);


  /**
   * Get a SedChange from the SedModel.
   *
   * @param n an unsigned int representing the index of the SedChange to
   * retrieve.
   *
   * @return the nth SedChange in the SedListOfChanges within this SedModel.
   *
   * @see getNumChanges()
   */
  const SedChange* getChange(unsigned int n) const;


  /**
   * Adds a copy of the given SedChange to this SedModel.
   *
   * @param sc the SedChange object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createChange()
   */
  int addChange(const SedChange* sc);


  /**
   * Get the number of SedChange objects in this SedModel.
   *
   * @return the number of SedChange objects in this SedModel.
   */
  unsigned int getNumChanges() const;


  /**
   * Creates a new SedAddXML object, adds it to this SedModel object and
   * returns the SedAddXML object created.
   *
   * @return a new SedAddXML object instance.
   *
   * @see addChange(const SedChange* sc)
   */
  SedAddXML* createAddXML();


  /**
   * Removes the nth SedChange from this SedModel and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedChange to
   * remove.
   *
   * @return a pointer to the nth SedChange in this SedModel.
   *
   * @see getNumChanges
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  SedChange* removeChange(unsigned int n);


  /**
   * Returns the XML element name of this SedModel object.
   *
   * For SedModel, the XML element name is always @c "model".
   *
   * @return the name of this element, i.e. @c "model".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSEDML type code for this SedModel object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   *
   * @sedmlconstant{SEDML_MODEL, SEDMLSedmlTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SedModel object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SedModel have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SedModel object are:
   * @li "id"
   * @li "source"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this SedModel
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SedModel have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SedModel object are:
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Gets the value of the "attributeName" attribute of this SedModel.
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
   * Predicate returning @c true if this SedModel's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SedModel's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Sets the value of the "attributeName" attribute of this SedModel.
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
   * Unsets the value of the "attributeName" attribute of this SedModel.
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
   * Creates and returns an new "elementName" object in this SedModel.
   *
   * @param objectName, the name of the element to create.
   *
   * pointer to the object created.
   */
  virtual SBase* createObject(const std::string& elementName);

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


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SedModel_t using the given SEDML Level and @ p version values.
 *
 * @param level an unsigned int, the SEDML Level to assign to this SedModel_t.
 *
 * @param version an unsigned int, the SEDML Version to assign to this
 * SedModel_t.
 *
 * @throws SEDMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SEDML object, are either invalid or mismatched with respect to the parent
 * SedDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedModel_t *
SedModel_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SedModel_t object.
 *
 * @param sm the SedModel_t structure.
 *
 * @return a (deep) copy of this SedModel_t object.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedModel_t*
SedModel_clone(const SedModel_t* sm);


/**
 * Frees this SedModel_t object.
 *
 * @param sm the SedModel_t structure.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
void
SedModel_free(SedModel_t* sm);


/**
 * Returns the value of the "id" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SedModel_t as a pointer to a
 * string.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
const char *
SedModel_getId(const SedModel_t * sm);


/**
 * Returns the value of the "name" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SedModel_t as a pointer to
 * a string.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
const char *
SedModel_getName(const SedModel_t * sm);


/**
 * Returns the value of the "language" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure whose language is sought.
 *
 * @return the value of the "language" attribute of this SedModel_t as a
 * pointer to a string.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
const char *
SedModel_getLanguage(const SedModel_t * sm);


/**
 * Returns the value of the "source" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure whose source is sought.
 *
 * @return the value of the "source" attribute of this SedModel_t as a pointer
 * to a string.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
const char *
SedModel_getSource(const SedModel_t * sm);


/**
 * Predicate returning @c 1 if this SedModel_t's "id" attribute is set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 if this SedModel_t's "id" attribute has been set, otherwise @c
 * 0 is returned.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_isSetId(const SedModel_t * sm);


/**
 * Predicate returning @c 1 if this SedModel_t's "name" attribute is set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 if this SedModel_t's "name" attribute has been set, otherwise
 * @c 0 is returned.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_isSetName(const SedModel_t * sm);


/**
 * Predicate returning @c 1 if this SedModel_t's "language" attribute is set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 if this SedModel_t's "language" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_isSetLanguage(const SedModel_t * sm);


/**
 * Predicate returning @c 1 if this SedModel_t's "source" attribute is set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 if this SedModel_t's "source" attribute has been set, otherwise
 * @c 0 is returned.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_isSetSource(const SedModel_t * sm);


/**
 * Sets the value of the "id" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_setId(SedModel_t * sm, const char * id);


/**
 * Sets the value of the "name" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_setName(SedModel_t * sm, const char * name);


/**
 * Sets the value of the "language" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @param language const char * value of the "language" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_setLanguage(SedModel_t * sm, const char * language);


/**
 * Sets the value of the "source" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @param source const char * value of the "source" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_INVALID_ATTRIBUTE_VALUE,
 * OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_setSource(SedModel_t * sm, const char * source);


/**
 * Unsets the value of the "id" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_unsetId(SedModel_t * sm);


/**
 * Unsets the value of the "name" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_unsetName(SedModel_t * sm);


/**
 * Unsets the value of the "language" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_unsetLanguage(SedModel_t * sm);


/**
 * Unsets the value of the "source" attribute of this SedModel_t.
 *
 * @param sm the SedModel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_unsetSource(SedModel_t * sm);


/**
 * Returns a ListOf_t* containing SedChange_t objects from this SedModel_t.
 *
 * @param sm the SedModel_t structure whose "SedListOfChanges" is sought.
 *
 * @return the "SedListOfChanges" from this SedModel_t as a ListOf_t *.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedListOf_t*
SedModel_getListOfChanges(SedModel_t* sm);


/**
 * Get a SedChange_t from the SedModel_t.
 *
 * @param sm the SedModel_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedChange_t to
 * retrieve.
 *
 * @return the nth SedChange_t in the SedListOfChanges within this SedModel.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
const SedChange_t*
SedModel_getChange(SedModel_t* sm, unsigned int n);


/**
 * Adds a copy of the given SedChange_t to this SedModel_t.
 *
 * @param sm the SedModel_t structure to which the SedChange_t should be added.
 *
 * @param sc the SedChange_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_addChange(SedModel_t* sm, const SedChange_t* sc);


/**
 * Get the number of SedChange_t objects in this SedModel_t.
 *
 * @param sm the SedModel_t structure to query.
 *
 * @return the number of SedChange_t objects in this SedModel_t.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
unsigned int
SedModel_getNumChanges(SedModel_t* sm);


/**
 * Creates a new SedAddXML_t object, adds it to this SedModel_t object and
 * returns the SedAddXML_t object created.
 *
 * @param sm the SedModel_t structure to which the SedAddXML_t should be added.
 *
 * @return a new SedAddXML_t object instance.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedAddXML_t*
SedModel_createAddXML(SedModel_t* sm);


/**
 * Removes the nth SedChange_t from this SedModel_t and returns a pointer to
 * it.
 *
 * @param sm the SedModel_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedChange_t to
 * remove.
 *
 * @return a pointer to the nth SedChange_t in this SedModel_t.
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
SedChange_t*
SedModel_removeChange(SedModel_t* sm, unsigned int n);


/**
 * Predicate returning @c 1 if all the required attributes for this SedModel_t
 * object have been set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this SedModel_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the SedModel_t object are:
 * @li "id"
 * @li "source"
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_hasRequiredAttributes(const SedModel_t * sm);


/**
 * Predicate returning @c 1 if all the required elements for this SedModel_t
 * object have been set.
 *
 * @param sm the SedModel_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this SedModel_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the SedModel_t object are:
 *
 * @memberof SedModel_t
 */
LIBSEDML_EXTERN
int
SedModel_hasRequiredElements(const SedModel_t * sm);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedModel_H__ */


