/**
 * @file TSBComment.h
 * @brief Definition of the TSBComment class.
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
 * @class TSBComment
 * @sbmlbrief{tsb} TODO:Definition of the TSBComment class.
 */


#ifndef TSBComment_H__
#define TSBComment_H__


#include <tsb/common/extern.h>
#include <tsb/common/tsbfwd.h>


#ifdef __cplusplus


#include <string>


#include <tsb/TSBBase.h>


LIBTSB_CPP_NAMESPACE_BEGIN


class LIBTSB_EXTERN TSBComment : public TSBBase
{
protected:

  /** @cond doxygenlibTSBInternal */

  std::string mContributor;
  double mNumber;
  bool mIsSetNumber;
  std::string mPoint;

  /** @endcond */

public:

  /**
   * Creates a new TSBComment using the given TSB Level and @ p version values.
   *
   * @param level an unsigned int, the TSB Level to assign to this TSBComment.
   *
   * @param version an unsigned int, the TSB Version to assign to this
   * TSBComment.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  TSBComment(unsigned int level = TSB_DEFAULT_LEVEL,
             unsigned int version = TSB_DEFAULT_VERSION);


  /**
   * Creates a new TSBComment using the given TSBNamespaces object @p tsbns.
   *
   * @param tsbns the TSBNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  TSBComment(TSBNamespaces *tsbns);


  /**
   * Copy constructor for TSBComment.
   *
   * @param orig the TSBComment instance to copy.
   */
  TSBComment(const TSBComment& orig);


  /**
   * Assignment operator for TSBComment.
   *
   * @param rhs the TSBComment object whose values are to be used as the basis
   * of the assignment.
   */
  TSBComment& operator=(const TSBComment& rhs);


  /**
   * Creates and returns a deep copy of this TSBComment object.
   *
   * @return a (deep) copy of this TSBComment object.
   */
  virtual TSBComment* clone() const;


  /**
   * Destructor for TSBComment.
   */
  virtual ~TSBComment();


  /**
   * Returns the value of the "contributor" attribute of this TSBComment.
   *
   * @return the value of the "contributor" attribute of this TSBComment as a
   * string.
   */
  const std::string& getContributor() const;


  /**
   * Returns the value of the "number" attribute of this TSBComment.
   *
   * @return the value of the "number" attribute of this TSBComment as a
   * double.
   */
  double getNumber() const;


  /**
   * Returns the value of the "point" attribute of this TSBComment.
   *
   * @return the value of the "point" attribute of this TSBComment as a string.
   */
  const std::string& getPoint() const;


  /**
   * Predicate returning @c true if this TSBComment's "contributor" attribute
   * is set.
   *
   * @return @c true if this TSBComment's "contributor" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetContributor() const;


  /**
   * Predicate returning @c true if this TSBComment's "number" attribute is
   * set.
   *
   * @return @c true if this TSBComment's "number" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNumber() const;


  /**
   * Predicate returning @c true if this TSBComment's "point" attribute is set.
   *
   * @return @c true if this TSBComment's "point" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetPoint() const;


  /**
   * Sets the value of the "contributor" attribute of this TSBComment.
   *
   * @param contributor std::string& value of the "contributor" attribute to be
   * set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p contributor = @c NULL or an empty string is
   * equivalent to calling unsetContributor().
   */
  int setContributor(const std::string& contributor);


  /**
   * Sets the value of the "number" attribute of this TSBComment.
   *
   * @param number double value of the "number" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
   */
  int setNumber(double number);


  /**
   * Sets the value of the "point" attribute of this TSBComment.
   *
   * @param point std::string& value of the "point" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p point = @c NULL or an empty string is
   * equivalent to calling unsetPoint().
   */
  int setPoint(const std::string& point);


  /**
   * Unsets the value of the "contributor" attribute of this TSBComment.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetContributor();


  /**
   * Unsets the value of the "number" attribute of this TSBComment.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumber();


  /**
   * Unsets the value of the "point" attribute of this TSBComment.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPoint();


  /**
   * Returns the XML element name of this TSBComment object.
   *
   * For TSBComment, the XML element name is always @c "comment".
   *
   * @return the name of this element, i.e. @c "comment".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libTSB type code for this TSBComment object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the TSB type code for this object:
   * @tsbconstant{TSB_COMMENT, TSBTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * TSBComment object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * TSBComment have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the TSBComment object are:
   * @li "contributor"
   * @li "number"
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




  #ifndef SWIG



  /** @cond doxygenlibTSBInternal */

  /**
   * Gets the value of the "attributeName" attribute of this TSBComment.
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
   * Gets the value of the "attributeName" attribute of this TSBComment.
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
   * Gets the value of the "attributeName" attribute of this TSBComment.
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
   * Gets the value of the "attributeName" attribute of this TSBComment.
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
   * Gets the value of the "attributeName" attribute of this TSBComment.
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
   * Predicate returning @c true if this TSBComment's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this TSBComment's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibTSBInternal */

  /**
   * Sets the value of the "attributeName" attribute of this TSBComment.
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
   * Sets the value of the "attributeName" attribute of this TSBComment.
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
   * Sets the value of the "attributeName" attribute of this TSBComment.
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
   * Sets the value of the "attributeName" attribute of this TSBComment.
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
   * Sets the value of the "attributeName" attribute of this TSBComment.
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
   * Unsets the value of the "attributeName" attribute of this TSBComment.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


protected:


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


};



LIBTSB_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBTSB_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new TSBComment_t using the given TSB Level and @ p version values.
 *
 * @param level an unsigned int, the TSB Level to assign to this TSBComment_t.
 *
 * @param version an unsigned int, the TSB Version to assign to this
 * TSBComment_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
TSBComment_t *
TSBComment_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this TSBComment_t object.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @return a (deep) copy of this TSBComment_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
TSBComment_t*
TSBComment_clone(const TSBComment_t* tsbc);


/**
 * Frees this TSBComment_t object.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
void
TSBComment_free(TSBComment_t* tsbc);


/**
 * Returns the value of the "contributor" attribute of this TSBComment_t.
 *
 * @param tsbc the TSBComment_t structure whose contributor is sought.
 *
 * @return the value of the "contributor" attribute of this TSBComment_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
char *
TSBComment_getContributor(const TSBComment_t * tsbc);


/**
 * Returns the value of the "number" attribute of this TSBComment_t.
 *
 * @param tsbc the TSBComment_t structure whose number is sought.
 *
 * @return the value of the "number" attribute of this TSBComment_t as a
 * double.
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
double
TSBComment_getNumber(const TSBComment_t * tsbc);


/**
 * Returns the value of the "point" attribute of this TSBComment_t.
 *
 * @param tsbc the TSBComment_t structure whose point is sought.
 *
 * @return the value of the "point" attribute of this TSBComment_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
char *
TSBComment_getPoint(const TSBComment_t * tsbc);


/**
 * Predicate returning @c 1 (true) if this TSBComment_t's "contributor"
 * attribute is set.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @return @c 1 (true) if this TSBComment_t's "contributor" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_isSetContributor(const TSBComment_t * tsbc);


/**
 * Predicate returning @c 1 (true) if this TSBComment_t's "number" attribute is
 * set.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @return @c 1 (true) if this TSBComment_t's "number" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_isSetNumber(const TSBComment_t * tsbc);


/**
 * Predicate returning @c 1 (true) if this TSBComment_t's "point" attribute is
 * set.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @return @c 1 (true) if this TSBComment_t's "point" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_isSetPoint(const TSBComment_t * tsbc);


/**
 * Sets the value of the "contributor" attribute of this TSBComment_t.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @param contributor const char * value of the "contributor" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p contributor = @c NULL or an empty string is
 * equivalent to calling TSBComment_unsetContributor().
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_setContributor(TSBComment_t * tsbc, const char * contributor);


/**
 * Sets the value of the "number" attribute of this TSBComment_t.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @param number double value of the "number" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_setNumber(TSBComment_t * tsbc, double number);


/**
 * Sets the value of the "point" attribute of this TSBComment_t.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @param point const char * value of the "point" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p point = @c NULL or an empty string is
 * equivalent to calling TSBComment_unsetPoint().
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_setPoint(TSBComment_t * tsbc, const char * point);


/**
 * Unsets the value of the "contributor" attribute of this TSBComment_t.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_unsetContributor(TSBComment_t * tsbc);


/**
 * Unsets the value of the "number" attribute of this TSBComment_t.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_unsetNumber(TSBComment_t * tsbc);


/**
 * Unsets the value of the "point" attribute of this TSBComment_t.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @tsbconstant{LIBTSB_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_OPERATION_FAILED, OperationReturnValues_t}
 * @li @tsbconstant{LIBTSB_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_unsetPoint(TSBComment_t * tsbc);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * TSBComment_t object have been set.
 *
 * @param tsbc the TSBComment_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * TSBComment_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the TSBComment_t object are:
 * @li "contributor"
 * @li "number"
 *
 * @memberof TSBComment_t
 */
LIBTSB_EXTERN
int
TSBComment_hasRequiredAttributes(const TSBComment_t * tsbc);




END_C_DECLS




LIBTSB_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !TSBComment_H__ */


