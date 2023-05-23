/**
 * @file TSBDocument.h
 * @brief Definition of the TSBDocument class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
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
 * @class TSBDocument
 * @sbmlbrief{tsb} TODO:Definition of the TSBDocument class.
 */


#ifndef TSBDocument_H__
#define TSBDocument_H__


#include <tsb/common/extern.h>
#include <tsb/common/tsbfwd.h>


#ifdef __cplusplus


#include <string>


#include <tsb/TSBBase.h>
#include <tsb/TSBListOfComments.h>
#include <tsb/TSBErrorLog.h>


LIBTSB_CPP_NAMESPACE_BEGIN


class LIBTSB_EXTERN TSBDocument : public TSBBase
{
protected:

  /** @cond doxygenlibTSBInternal */

  unsigned int mLevel;
  bool mIsSetLevel;
  unsigned int mVersion;
  bool mIsSetVersion;
  TSBListOfComments mComments;
  TSBErrorLog mErrorLog;

  /** @endcond */

public:

  /**
   * Creates a new TSBDocument using the given TSB Level and @ p version
   * values.
   *
   * @param level an unsigned int, the TSB Level to assign to this TSBDocument.
   *
   * @param version an unsigned int, the TSB Version to assign to this
   * TSBDocument.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  TSBDocument(unsigned int level = TSB_DEFAULT_LEVEL,
              unsigned int version = TSB_DEFAULT_VERSION);


  /**
   * Creates a new TSBDocument using the given TSBNamespaces object @p tsbns.
   *
   * @param tsbns the TSBNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  TSBDocument(TSBNamespaces *tsbns);


  /**
   * Copy constructor for TSBDocument.
   *
   * @param orig the TSBDocument instance to copy.
   */
  TSBDocument(const TSBDocument& orig);


  /**
   * Assignment operator for TSBDocument.
   *
   * @param rhs the TSBDocument object whose values are to be used as the basis
   * of the assignment.
   */
  TSBDocument& operator=(const TSBDocument& rhs);


  /**
   * Creates and returns a deep copy of this TSBDocument object.
   *
   * @return a (deep) copy of this TSBDocument object.
   */
  virtual TSBDocument* clone() const;


  /**
   * Destructor for TSBDocument.
   */
  virtual ~TSBDocument();


  /**
   * Returns the value of the "level" attribute of this TSBDocument.
   *
   * @return the value of the "level" attribute of this TSBDocument as a
   * unsigned integer.
   */
  unsigned int getLevel() const;


  /**
   * Returns the value of the "version" attribute of this TSBDocument.
   *
   * @return the value of the "version" attribute of this TSBDocument as a
   * unsigned integer.
   */
  unsigned int getVersion() const;


  /**
   * Predicate returning @c true if this TSBDocument's "level" attribute is
   * set.
   *
   * @return @c true if this TSBDocument's "level" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetLevel() const;


  /**
   * Predicate returning @c true if this TSBDocument's "version" attribute is
   * set.
   *
   * @return @c true if this TSBDocument's "version" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetVersion() const;


  /**
   * Sets the value of the "level" attribute of this TSBDocument.
   *
   * @param level unsigned int value of the "level" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  int setLevel(unsigned int level);


  /**
   * Sets the value of the "version" attribute of this TSBDocument.
   *
   * @param version unsigned int value of the "version" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  int setVersion(unsigned int version);


  /**
   * Unsets the value of the "level" attribute of this TSBDocument.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLevel();


  /**
   * Unsets the value of the "version" attribute of this TSBDocument.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetVersion();


  /**
   * Returns the TSBListOfComments from this TSBDocument.
   *
   * @return the TSBListOfComments from this TSBDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see getComment(const std::string& sid)
   * @see getComment(unsigned int n)
   * @see getNumComments()
   * @see removeComment(const std::string& sid)
   * @see removeComment(unsigned int n)
   */
  const TSBListOfComments* getListOfComments() const;


  /**
   * Returns the TSBListOfComments from this TSBDocument.
   *
   * @return the TSBListOfComments from this TSBDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see getComment(const std::string& sid)
   * @see getComment(unsigned int n)
   * @see getNumComments()
   * @see removeComment(const std::string& sid)
   * @see removeComment(unsigned int n)
   */
  TSBListOfComments* getListOfComments();


  /**
   * Get a TSBComment from the TSBDocument.
   *
   * @param n an unsigned int representing the index of the TSBComment to
   * retrieve.
   *
   * @return the nth TSBComment in the TSBListOfComments within this
   * TSBDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see getComment(const std::string& sid)
   * @see getNumComments()
   * @see removeComment(const std::string& sid)
   * @see removeComment(unsigned int n)
   */
  TSBComment* getComment(unsigned int n);


  /**
   * Get a TSBComment from the TSBDocument.
   *
   * @param n an unsigned int representing the index of the TSBComment to
   * retrieve.
   *
   * @return the nth TSBComment in the TSBListOfComments within this
   * TSBDocument or @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see getComment(const std::string& sid)
   * @see getNumComments()
   * @see removeComment(const std::string& sid)
   * @see removeComment(unsigned int n)
   */
  const TSBComment* getComment(unsigned int n) const;


  /**
   * Adds a copy of the given TSBComment to this TSBDocument.
   *
   * @param tsbc the TSBComment object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createComment()
   * @see getComment(const std::string& sid)
   * @see getComment(unsigned int n)
   * @see getNumComments()
   * @see removeComment(const std::string& sid)
   * @see removeComment(unsigned int n)
   */
  int addComment(const TSBComment* tsbc);


  /**
   * Get the number of TSBComment objects in this TSBDocument.
   *
   * @return the number of TSBComment objects in this TSBDocument.
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see getComment(const std::string& sid)
   * @see getComment(unsigned int n)
   * @see removeComment(const std::string& sid)
   * @see removeComment(unsigned int n)
   */
  unsigned int getNumComments() const;


  /**
   * Creates a new TSBComment object, adds it to this TSBDocument object and
   * returns the TSBComment object created.
   *
   * @return a new TSBComment object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see getComment(const std::string& sid)
   * @see getComment(unsigned int n)
   * @see getNumComments()
   * @see removeComment(const std::string& sid)
   * @see removeComment(unsigned int n)
   */
  TSBComment* createComment();


  /**
   * Removes the nth TSBComment from this TSBDocument and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the TSBComment to
   * remove.
   *
   * @return a pointer to the nth TSBComment in this TSBDocument.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addComment(const TSBComment* object)
   * @see createComment()
   * @see getComment(const std::string& sid)
   * @see getComment(unsigned int n)
   * @see getNumComments()
   * @see removeComment(const std::string& sid)
   */
  TSBComment* removeComment(unsigned int n);


  /**
   * Returns the XML element name of this TSBDocument object.
   *
   * For TSBDocument, the XML element name is always @c "tsb".
   *
   * @return the name of this element, i.e. @c "tsb".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libTSB type code for this TSBDocument object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the TSB type code for this object:
   * @tsbconstant{TSB_DOCUMENT, TSBTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * TSBDocument object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * TSBDocument have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the TSBDocument object are:
   * @li "level"
   * @li "version"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenlibTSBInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Accepts the given TSBVisitor
   */
  virtual bool accept(TSBVisitor& v) const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Sets the parent TSBDocument
   */
  virtual void setTSBDocument(TSBDocument* d);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenlibTSBInternal */

  /**
   * Gets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Gets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Gets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Gets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Gets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Predicate returning @c true if this TSBDocument's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this TSBDocument's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Sets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Sets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Sets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Sets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Sets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this TSBDocument.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Creates and returns an new "elementName" object in this TSBDocument.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual TSBBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Adds a new "elementName" object to this TSBDocument.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const TSBBase* element);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * TSBDocument.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual TSBBase* removeChildObject(const std::string& elementName,
                                     const std::string& id);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Returns the number of "elementName" in this TSBDocument.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Returns the nth object of "objectName" in this TSBDocument.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual TSBBase* getObject(const std::string& elementName,
                             unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the TSBBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual TSBBase* getElementBySId(const std::string& id);


  /**
   * Returns a List of all child TSBBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List pointer of pointers to all TSBBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(TSBElementFilter * filter = NULL);


  /**
   * Returns the value of the "Namespaces" element of this TSBDocument.
   *
   * @return the value of the "Namespaces" element of this TSBDocument as a
   *  XMLNamespaces*.
   */
  virtual const  XMLNamespaces* getNamespaces()
    const;


  /**
   * Returns the value of the "Namespaces" element of this TSBDocument.
   *
   * @return the value of the "Namespaces" element of this TSBDocument as a
   *  XMLNamespaces*.
   */
  virtual  XMLNamespaces* getNamespaces();


  /**
   * Returns the value of the "TSBErrorLog" element of this TSBDocument.
   *
   * @return the value of the "TSBErrorLog" element of this TSBDocument as a
   * TSBErrorLog*.
   */
  const TSBErrorLog* getErrorLog() const;


  /**
   * Returns the value of the "TSBErrorLog" element of this TSBDocument.
   *
   * @return the value of the "TSBErrorLog" element of this TSBDocument as a
   * TSBErrorLog*.
   */
  TSBErrorLog* getErrorLog();


  /**
   * Get a TSBError from the TSBDocument.
   *
   * @param n an unsigned int representing the index of the TSBError to
   * retrieve.
   *
   * @return the nth TSBError within this TSBDocument or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see getNumErrors()
   */
  TSBError* getError(unsigned int n);


  /**
   * Get a TSBError from the TSBDocument.
   *
   * @param n an unsigned int representing the index of the TSBError to
   * retrieve.
   *
   * @return the nth TSBError within this TSBDocument or @c NULL if no such
   * object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see getNumErrors()
   */
  const TSBError* getError(unsigned int n) const;


  /**
   * Get the number of TSBError objects in this TSBDocument.
   *
   * @return the number of TSBError objects in this TSBDocument.
   *
   * @see getError(unsigned int n)
   */
  unsigned int getNumErrors() const;


  /**
   * Get the number of TSBError objects in this TSBDocument with the given
   * severity.
   *
   * @param severity the severity of the TSBError to return.
   *
   * @return the number of TSBError objects in this TSBDocument.
   *
   * @see getError(unsigned int n)
   */
  unsigned int getNumErrors(unsigned int severity) const;


protected:


  /** @cond doxygenlibTSBInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual TSBBase* createObject( XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Writes the namespace for the Tsb package
   */
  virtual void writeXMLNS( XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBTSB_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBTSB_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new TSBDocument_t using the given TSB Level and @ p version
 * values.
 *
 * @param level an unsigned int, the TSB Level to assign to this TSBDocument_t.
 *
 * @param version an unsigned int, the TSB Version to assign to this
 * TSBDocument_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
TSBDocument_t *
TSBDocument_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this TSBDocument_t object.
 *
 * @param tsbd the TSBDocument_t structure.
 *
 * @return a (deep) copy of this TSBDocument_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
TSBDocument_t*
TSBDocument_clone(const TSBDocument_t* tsbd);


/**
 * Frees this TSBDocument_t object.
 *
 * @param tsbd the TSBDocument_t structure.
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
void
TSBDocument_free(TSBDocument_t* tsbd);


/**
 * Returns the value of the "level" attribute of this TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure whose level is sought.
 *
 * @return the value of the "level" attribute of this TSBDocument_t as a
 * unsigned integer.
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
unsigned int
TSBDocument_getLevel(const TSBDocument_t * tsbd);


/**
 * Returns the value of the "version" attribute of this TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure whose version is sought.
 *
 * @return the value of the "version" attribute of this TSBDocument_t as a
 * unsigned integer.
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
unsigned int
TSBDocument_getVersion(const TSBDocument_t * tsbd);


/**
 * Predicate returning @c 1 (true) if this TSBDocument_t's "level" attribute is
 * set.
 *
 * @param tsbd the TSBDocument_t structure.
 *
 * @return @c 1 (true) if this TSBDocument_t's "level" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
int
TSBDocument_isSetLevel(const TSBDocument_t * tsbd);


/**
 * Predicate returning @c 1 (true) if this TSBDocument_t's "version" attribute
 * is set.
 *
 * @param tsbd the TSBDocument_t structure.
 *
 * @return @c 1 (true) if this TSBDocument_t's "version" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
int
TSBDocument_isSetVersion(const TSBDocument_t * tsbd);


/**
 * Sets the value of the "level" attribute of this TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure.
 *
 * @param level unsigned int value of the "level" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
int
TSBDocument_setLevel(TSBDocument_t * tsbd, unsigned int level);


/**
 * Sets the value of the "version" attribute of this TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure.
 *
 * @param version unsigned int value of the "version" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
int
TSBDocument_setVersion(TSBDocument_t * tsbd, unsigned int version);


/**
 * Unsets the value of the "level" attribute of this TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
int
TSBDocument_unsetLevel(TSBDocument_t * tsbd);


/**
 * Unsets the value of the "version" attribute of this TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
int
TSBDocument_unsetVersion(TSBDocument_t * tsbd);


/**
 * Returns a ListOf_t * containing TSBComment_t objects from this
 * TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure whose TSBListOfComments is sought.
 *
 * @return the TSBListOfComments from this TSBDocument_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see TSBDocument_addComment()
 * @see TSBDocument_createComment()
 * @see TSBDocument_getCommentById()
 * @see TSBDocument_getComment()
 * @see TSBDocument_getNumComments()
 * @see TSBDocument_removeCommentById()
 * @see TSBDocument_removeComment()
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
TSBListOf_t*
TSBDocument_getListOfComments(TSBDocument_t* tsbd);


/**
 * Get a TSBComment_t from the TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the TSBComment_t to
 * retrieve.
 *
 * @return the nth TSBComment_t in the TSBListOfComments within this
 * TSBDocument or @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
TSBComment_t*
TSBDocument_getComment(TSBDocument_t* tsbd, unsigned int n);


/**
 * Adds a copy of the given TSBComment_t to this TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure to which the TSBComment_t should be
 * added.
 *
 * @param tsbc the TSBComment_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
int
TSBDocument_addComment(TSBDocument_t* tsbd, const TSBComment_t* tsbc);


/**
 * Get the number of TSBComment_t objects in this TSBDocument_t.
 *
 * @param tsbd the TSBDocument_t structure to query.
 *
 * @return the number of TSBComment_t objects in this TSBDocument_t.
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
unsigned int
TSBDocument_getNumComments(TSBDocument_t* tsbd);


/**
 * Creates a new TSBComment_t object, adds it to this TSBDocument_t object and
 * returns the TSBComment_t object created.
 *
 * @param tsbd the TSBDocument_t structure to which the TSBComment_t should be
 * added.
 *
 * @return a new TSBComment_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
TSBComment_t*
TSBDocument_createComment(TSBDocument_t* tsbd);


/**
 * Removes the nth TSBComment_t from this TSBDocument_t and returns a pointer
 * to it.
 *
 * @param tsbd the TSBDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the TSBComment_t to
 * remove.
 *
 * @return a pointer to the nth TSBComment_t in this TSBDocument_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
TSBComment_t*
TSBDocument_removeComment(TSBDocument_t* tsbd, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * TSBDocument_t object have been set.
 *
 * @param tsbd the TSBDocument_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * TSBDocument_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the TSBDocument_t object are:
 * @li "level"
 * @li "version"
 *
 * @memberof TSBDocument_t
 */
LIBTSB_EXTERN
int
TSBDocument_hasRequiredAttributes(const TSBDocument_t * tsbd);




END_C_DECLS




LIBTSB_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !TSBDocument_H__ */


