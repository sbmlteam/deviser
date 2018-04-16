/**
 * @file MultipleChild.h
 * @brief Definition of the MultipleChild class.
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
 * @class MultipleChild
 * @sbmlbrief{twoatonce} TODO:Definition of the MultipleChild class.
 */


#ifndef MultipleChild_H__
#define MultipleChild_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/twoatonce/common/twoatoncefwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/twoatonce/extension/TwoatonceExtension.h>
#include <sbml/packages/twoatonce/sbml/NormalClass.h>
#include <sbml/packages/twoatonce/sbml/ListOfClassIds.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN MultipleChild : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  double mNumAtt;
  bool mIsSetNumAtt;
  ListOfClassIds mClassIds;
  NormalClass* mNormalClass;

  /** @endcond */

public:

  /**
   * Creates a new MultipleChild using the given SBML Level, Version and
   * &ldquo;twoatonce&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * MultipleChild.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * MultipleChild.
   *
   * @param pkgVersion an unsigned int, the SBML Twoatonce Version to assign to
   * this MultipleChild.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  MultipleChild(unsigned int level = TwoatonceExtension::getDefaultLevel(),
                unsigned int version = TwoatonceExtension::getDefaultVersion(),
                unsigned int pkgVersion =
                  TwoatonceExtension::getDefaultPackageVersion());


  /**
   * Creates a new MultipleChild using the given TwoatoncePkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param twoatoncens the TwoatoncePkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  MultipleChild(TwoatoncePkgNamespaces *twoatoncens);


  /**
   * Copy constructor for MultipleChild.
   *
   * @param orig the MultipleChild instance to copy.
   */
  MultipleChild(const MultipleChild& orig);


  /**
   * Assignment operator for MultipleChild.
   *
   * @param rhs the MultipleChild object whose values are to be used as the
   * basis of the assignment.
   */
  MultipleChild& operator=(const MultipleChild& rhs);


  /**
   * Creates and returns a deep copy of this MultipleChild object.
   *
   * @return a (deep) copy of this MultipleChild object.
   */
  virtual MultipleChild* clone() const;


  /**
   * Destructor for MultipleChild.
   */
  virtual ~MultipleChild();


  /**
   * Returns the value of the "id" attribute of this MultipleChild.
   *
   * @return the value of the "id" attribute of this MultipleChild as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "numAtt" attribute of this MultipleChild.
   *
   * @return the value of the "numAtt" attribute of this MultipleChild as a
   * double.
   */
  double getNumAtt() const;


  /**
   * Predicate returning @c true if this MultipleChild's "id" attribute is set.
   *
   * @return @c true if this MultipleChild's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this MultipleChild's "numAtt" attribute is
   * set.
   *
   * @return @c true if this MultipleChild's "numAtt" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNumAtt() const;


  /**
   * Sets the value of the "id" attribute of this MultipleChild.
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
   * Sets the value of the "numAtt" attribute of this MultipleChild.
   *
   * @param numAtt double value of the "numAtt" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNumAtt(double numAtt);


  /**
   * Unsets the value of the "id" attribute of this MultipleChild.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "numAtt" attribute of this MultipleChild.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumAtt();


  /**
   * Returns the value of the "normalClass" element of this MultipleChild.
   *
   * @return the value of the "normalClass" element of this MultipleChild as a
   * NormalClass*.
   */
  const NormalClass* getNormalClass() const;


  /**
   * Returns the value of the "normalClass" element of this MultipleChild.
   *
   * @return the value of the "normalClass" element of this MultipleChild as a
   * NormalClass*.
   */
  NormalClass* getNormalClass();


  /**
   * Predicate returning @c true if this MultipleChild's "normalClass" element
   * is set.
   *
   * @return @c true if this MultipleChild's "normalClass" element has been
   * set, otherwise @c false is returned.
   */
  bool isSetNormalClass() const;


  /**
   * Sets the value of the "normalClass" element of this MultipleChild.
   *
   * @param normalClass NormalClass* value of the "normalClass" element to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNormalClass(const NormalClass* normalClass);


  /**
   * Creates a new NormalClass object, adds it to this MultipleChild object and
   * returns the NormalClass object created.
   *
   * @return a new NormalClass object instance.
   */
  NormalClass* createNormalClass();


  /**
   * Unsets the value of the "normalClass" element of this MultipleChild.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNormalClass();


  /**
   * Returns the ListOfClassIds from this MultipleChild.
   *
   * @return the ListOfClassIds from this MultipleChild.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addClassId(const ClassId* object)
   * @see createClassId()
   * @see getClassId(const std::string& sid)
   * @see getClassId(unsigned int n)
   * @see getNumClassIds()
   * @see removeClassId(const std::string& sid)
   * @see removeClassId(unsigned int n)
   */
  const ListOfClassIds* getListOfClassIds() const;


  /**
   * Returns the ListOfClassIds from this MultipleChild.
   *
   * @return the ListOfClassIds from this MultipleChild.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addClassId(const ClassId* object)
   * @see createClassId()
   * @see getClassId(const std::string& sid)
   * @see getClassId(unsigned int n)
   * @see getNumClassIds()
   * @see removeClassId(const std::string& sid)
   * @see removeClassId(unsigned int n)
   */
  ListOfClassIds* getListOfClassIds();


  /**
   * Get a ClassId from the MultipleChild.
   *
   * @param n an unsigned int representing the index of the ClassId to
   * retrieve.
   *
   * @return the nth ClassId in the ListOfClassIds within this MultipleChild.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addClassId(const ClassId* object)
   * @see createClassId()
   * @see getClassId(const std::string& sid)
   * @see getNumClassIds()
   * @see removeClassId(const std::string& sid)
   * @see removeClassId(unsigned int n)
   */
  ClassId* getClassId(unsigned int n);


  /**
   * Get a ClassId from the MultipleChild.
   *
   * @param n an unsigned int representing the index of the ClassId to
   * retrieve.
   *
   * @return the nth ClassId in the ListOfClassIds within this MultipleChild.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addClassId(const ClassId* object)
   * @see createClassId()
   * @see getClassId(const std::string& sid)
   * @see getNumClassIds()
   * @see removeClassId(const std::string& sid)
   * @see removeClassId(unsigned int n)
   */
  const ClassId* getClassId(unsigned int n) const;


  /**
   * Get a ClassId from the MultipleChild based on its identifier.
   *
   * @param sid a string representing the identifier of the ClassId to
   * retrieve.
   *
   * @return the ClassId in the ListOfClassIds within this MultipleChild with
   * the given @p sid or @c NULL if no such ClassId exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addClassId(const ClassId* object)
   * @see createClassId()
   * @see getClassId(unsigned int n)
   * @see getNumClassIds()
   * @see removeClassId(const std::string& sid)
   * @see removeClassId(unsigned int n)
   */
  ClassId* getClassId(const std::string& sid);


  /**
   * Get a ClassId from the MultipleChild based on its identifier.
   *
   * @param sid a string representing the identifier of the ClassId to
   * retrieve.
   *
   * @return the ClassId in the ListOfClassIds within this MultipleChild with
   * the given @p sid or @c NULL if no such ClassId exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addClassId(const ClassId* object)
   * @see createClassId()
   * @see getClassId(unsigned int n)
   * @see getNumClassIds()
   * @see removeClassId(const std::string& sid)
   * @see removeClassId(unsigned int n)
   */
  const ClassId* getClassId(const std::string& sid) const;


  /**
   * Adds a copy of the given ClassId to this MultipleChild.
   *
   * @param ci the ClassId object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createClassId()
   * @see getClassId(const std::string& sid)
   * @see getClassId(unsigned int n)
   * @see getNumClassIds()
   * @see removeClassId(const std::string& sid)
   * @see removeClassId(unsigned int n)
   */
  int addClassId(const ClassId* ci);


  /**
   * Get the number of ClassId objects in this MultipleChild.
   *
   * @return the number of ClassId objects in this MultipleChild.
   *
   *
   * @see addClassId(const ClassId* object)
   * @see createClassId()
   * @see getClassId(const std::string& sid)
   * @see getClassId(unsigned int n)
   * @see removeClassId(const std::string& sid)
   * @see removeClassId(unsigned int n)
   */
  unsigned int getNumClassIds() const;


  /**
   * Creates a new ClassId object, adds it to this MultipleChild object and
   * returns the ClassId object created.
   *
   * @return a new ClassId object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addClassId(const ClassId* object)
   * @see getClassId(const std::string& sid)
   * @see getClassId(unsigned int n)
   * @see getNumClassIds()
   * @see removeClassId(const std::string& sid)
   * @see removeClassId(unsigned int n)
   */
  ClassId* createClassId();


  /**
   * Removes the nth ClassId from this MultipleChild and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the ClassId to remove.
   *
   * @return a pointer to the nth ClassId in this MultipleChild.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addClassId(const ClassId* object)
   * @see createClassId()
   * @see getClassId(const std::string& sid)
   * @see getClassId(unsigned int n)
   * @see getNumClassIds()
   * @see removeClassId(const std::string& sid)
   */
  ClassId* removeClassId(unsigned int n);


  /**
   * Removes the ClassId from this MultipleChild based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the ClassId to remove.
   *
   * @return the ClassId in this MultipleChild based on the identifier or NULL
   * if no such ClassId exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addClassId(const ClassId* object)
   * @see createClassId()
   * @see getClassId(const std::string& sid)
   * @see getClassId(unsigned int n)
   * @see getNumClassIds()
   * @see removeClassId(unsigned int n)
   */
  ClassId* removeClassId(const std::string& sid);


  /**
   * Returns the XML element name of this MultipleChild object.
   *
   * For MultipleChild, the XML element name is always @c "multipleChild".
   *
   * @return the name of this element, i.e. @c "multipleChild".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this MultipleChild object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_TWOATONCE_MULTIPLECHILD, SBMLTwoatonceTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * MultipleChild object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * MultipleChild have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the MultipleChild object are:
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
   * Gets the value of the "attributeName" attribute of this MultipleChild.
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
   * Gets the value of the "attributeName" attribute of this MultipleChild.
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
   * Gets the value of the "attributeName" attribute of this MultipleChild.
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
   * Gets the value of the "attributeName" attribute of this MultipleChild.
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
   * Gets the value of the "attributeName" attribute of this MultipleChild.
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
   * Predicate returning @c true if this MultipleChild's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this MultipleChild's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this MultipleChild.
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
   * Sets the value of the "attributeName" attribute of this MultipleChild.
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
   * Sets the value of the "attributeName" attribute of this MultipleChild.
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
   * Sets the value of the "attributeName" attribute of this MultipleChild.
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
   * Sets the value of the "attributeName" attribute of this MultipleChild.
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
   * Unsets the value of the "attributeName" attribute of this MultipleChild.
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
   * Creates and returns an new "elementName" object in this MultipleChild.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this MultipleChild.
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
   * MultipleChild.
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
   * Returns the number of "elementName" in this MultipleChild.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this MultipleChild.
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
  virtual void readL3V1V1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readL3V2V1Attributes(const XMLAttributes& attributes);

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
  virtual void writeL3V1V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeL3V2V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new MultipleChild_t using the given SBML Level, Version and
 * &ldquo;twoatonce&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * MultipleChild_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * MultipleChild_t.
 *
 * @param pkgVersion an unsigned int, the SBML Twoatonce Version to assign to
 * this MultipleChild_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
MultipleChild_t *
MultipleChild_create(unsigned int level,
                     unsigned int version,
                     unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this MultipleChild_t object.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @return a (deep) copy of this MultipleChild_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
MultipleChild_t*
MultipleChild_clone(const MultipleChild_t* mc);


/**
 * Frees this MultipleChild_t object.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
void
MultipleChild_free(MultipleChild_t* mc);


/**
 * Returns the value of the "id" attribute of this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this MultipleChild_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
char *
MultipleChild_getId(const MultipleChild_t * mc);


/**
 * Returns the value of the "numAtt" attribute of this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure whose numAtt is sought.
 *
 * @return the value of the "numAtt" attribute of this MultipleChild_t as a
 * double.
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
double
MultipleChild_getNumAtt(const MultipleChild_t * mc);


/**
 * Predicate returning @c 1 (true) if this MultipleChild_t's "id" attribute is
 * set.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @return @c 1 (true) if this MultipleChild_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_isSetId(const MultipleChild_t * mc);


/**
 * Predicate returning @c 1 (true) if this MultipleChild_t's "numAtt" attribute
 * is set.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @return @c 1 (true) if this MultipleChild_t's "numAtt" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_isSetNumAtt(const MultipleChild_t * mc);


/**
 * Sets the value of the "id" attribute of this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling MultipleChild_unsetId().
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_setId(MultipleChild_t * mc, const char * id);


/**
 * Sets the value of the "numAtt" attribute of this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @param numAtt double value of the "numAtt" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_setNumAtt(MultipleChild_t * mc, double numAtt);


/**
 * Unsets the value of the "id" attribute of this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_unsetId(MultipleChild_t * mc);


/**
 * Unsets the value of the "numAtt" attribute of this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_unsetNumAtt(MultipleChild_t * mc);


/**
 * Returns the value of the "normalClass" element of this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure whose normalClass is sought.
 *
 * @return the value of the "normalClass" element of this MultipleChild_t as a
 * NormalClass*.
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
const NormalClass_t*
MultipleChild_getNormalClass(const MultipleChild_t * mc);


/**
 * Predicate returning @c 1 (true) if this MultipleChild_t's "normalClass"
 * element is set.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @return @c 1 (true) if this MultipleChild_t's "normalClass" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_isSetNormalClass(const MultipleChild_t * mc);


/**
 * Sets the value of the "normalClass" element of this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @param normalClass NormalClass_t* value of the "normalClass" element to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_setNormalClass(MultipleChild_t * mc,
                             const NormalClass_t* normalClass);


/**
 * Creates a new NormalClass_t object, adds it to this MultipleChild_t object
 * and returns the NormalClass_t object created.
 *
 * @param mc the MultipleChild_t structure to which the NormalClass_t should be
 * added.
 *
 * @return a new NormalClass_t object instance.
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
NormalClass_t*
MultipleChild_createNormalClass(MultipleChild_t* mc);


/**
 * Unsets the value of the "normalClass" element of this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_unsetNormalClass(MultipleChild_t * mc);


/**
 * Returns a ListOf_t * containing ClassId_t objects from this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure whose ListOfClassIds is sought.
 *
 * @return the ListOfClassIds from this MultipleChild_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see MultipleChild_addClassId()
 * @see MultipleChild_createClassId()
 * @see MultipleChild_getClassIdById()
 * @see MultipleChild_getClassId()
 * @see MultipleChild_getNumClassIds()
 * @see MultipleChild_removeClassIdById()
 * @see MultipleChild_removeClassId()
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
ListOf_t*
MultipleChild_getListOfClassIds(MultipleChild_t* mc);


/**
 * Get a ClassId_t from the MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure to search.
 *
 * @param n an unsigned int representing the index of the ClassId_t to
 * retrieve.
 *
 * @return the nth ClassId_t in the ListOfClassIds within this MultipleChild.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_getClassId(MultipleChild_t* mc, unsigned int n);


/**
 * Get a ClassId_t from the MultipleChild_t based on its identifier.
 *
 * @param mc the MultipleChild_t structure to search.
 *
 * @param sid a string representing the identifier of the ClassId_t to
 * retrieve.
 *
 * @return the ClassId_t in the ListOfClassIds within this MultipleChild with
 * the given @p sid or @c NULL if no such ClassId_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_getClassIdById(MultipleChild_t* mc, const char *sid);


/**
 * Adds a copy of the given ClassId_t to this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure to which the ClassId_t should be
 * added.
 *
 * @param ci the ClassId_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_addClassId(MultipleChild_t* mc, const ClassId_t* ci);


/**
 * Get the number of ClassId_t objects in this MultipleChild_t.
 *
 * @param mc the MultipleChild_t structure to query.
 *
 * @return the number of ClassId_t objects in this MultipleChild_t.
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
unsigned int
MultipleChild_getNumClassIds(MultipleChild_t* mc);


/**
 * Creates a new ClassId_t object, adds it to this MultipleChild_t object and
 * returns the ClassId_t object created.
 *
 * @param mc the MultipleChild_t structure to which the ClassId_t should be
 * added.
 *
 * @return a new ClassId_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_createClassId(MultipleChild_t* mc);


/**
 * Removes the nth ClassId_t from this MultipleChild_t and returns a pointer to
 * it.
 *
 * @param mc the MultipleChild_t structure to search.
 *
 * @param n an unsigned int representing the index of the ClassId_t to remove.
 *
 * @return a pointer to the nth ClassId_t in this MultipleChild_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_removeClassId(MultipleChild_t* mc, unsigned int n);


/**
 * Removes the ClassId_t from this MultipleChild_t based on its identifier and
 * returns a pointer to it.
 *
 * @param mc the MultipleChild_t structure to search.
 *
 * @param sid a string representing the identifier of the ClassId_t to remove.
 *
 * @return the ClassId_t in this MultipleChild_t based on the identifier or
 * NULL if no such ClassId_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_removeClassIdById(MultipleChild_t* mc, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * MultipleChild_t object have been set.
 *
 * @param mc the MultipleChild_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * MultipleChild_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the MultipleChild_t object are:
 * @li "id"
 *
 * @memberof MultipleChild_t
 */
LIBSBML_EXTERN
int
MultipleChild_hasRequiredAttributes(const MultipleChild_t * mc);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !MultipleChild_H__ */


