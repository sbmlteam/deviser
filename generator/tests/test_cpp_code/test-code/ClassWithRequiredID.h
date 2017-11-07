/**
 * @file ClassWithRequiredID.h
 * @brief Definition of the ClassWithRequiredID class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2017 jointly by the following organizations:
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
 * @class ClassWithRequiredID
 * @sbmlbrief{twoatonce} TODO:Definition of the ClassWithRequiredID class.
 */


#ifndef ClassWithRequiredID_H__
#define ClassWithRequiredID_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/twoatonce/common/twoatoncefwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/twoatonce/extension/TwoatonceExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ClassWithRequiredID : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */


  /** @endcond */

public:

  /**
   * Creates a new ClassWithRequiredID using the given SBML Level, Version and
   * &ldquo;twoatonce&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ClassWithRequiredID.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ClassWithRequiredID.
   *
   * @param pkgVersion an unsigned int, the SBML Twoatonce Version to assign to
   * this ClassWithRequiredID.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ClassWithRequiredID(unsigned int level =
    TwoatonceExtension::getDefaultLevel(),
                      unsigned int version =
                        TwoatonceExtension::getDefaultVersion(),
                      unsigned int pkgVersion =
                        TwoatonceExtension::getDefaultPackageVersion());


  /**
   * Creates a new ClassWithRequiredID using the given TwoatoncePkgNamespaces
   * object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param twoatoncens the TwoatoncePkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ClassWithRequiredID(TwoatoncePkgNamespaces *twoatoncens);


  /**
   * Copy constructor for ClassWithRequiredID.
   *
   * @param orig the ClassWithRequiredID instance to copy.
   */
  ClassWithRequiredID(const ClassWithRequiredID& orig);


  /**
   * Assignment operator for ClassWithRequiredID.
   *
   * @param rhs the ClassWithRequiredID object whose values are to be used as
   * the basis of the assignment.
   */
  ClassWithRequiredID& operator=(const ClassWithRequiredID& rhs);


  /**
   * Creates and returns a deep copy of this ClassWithRequiredID object.
   *
   * @return a (deep) copy of this ClassWithRequiredID object.
   */
  virtual ClassWithRequiredID* clone() const;


  /**
   * Destructor for ClassWithRequiredID.
   */
  virtual ~ClassWithRequiredID();


  /**
   * Returns the value of the "id" attribute of this ClassWithRequiredID.
   *
   * @return the value of the "id" attribute of this ClassWithRequiredID as a
   * string.
   */
  virtual const std::string& getId() const;


  /**
   * Predicate returning @c true if this ClassWithRequiredID's "id" attribute
   * is set.
   *
   * @return @c true if this ClassWithRequiredID's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this ClassWithRequiredID.
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
   * Unsets the value of the "id" attribute of this ClassWithRequiredID.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Returns the XML element name of this ClassWithRequiredID object.
   *
   * For ClassWithRequiredID, the XML element name is always
   * @c "classWithRequiredID".
   *
   * @return the name of this element, i.e. @c "classWithRequiredID".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ClassWithRequiredID object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_TWOATONCE_CLASSWITHREQUIREDID,
   * SBMLTwoatonceTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * ClassWithRequiredID object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * ClassWithRequiredID have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the ClassWithRequiredID object are:
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
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * ClassWithRequiredID.
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
   * ClassWithRequiredID.
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
   * ClassWithRequiredID.
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
   * ClassWithRequiredID.
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
   * ClassWithRequiredID.
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
   * Gets the value of the "attributeName" attribute of this
   * ClassWithRequiredID.
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
                           const char* value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this ClassWithRequiredID's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this ClassWithRequiredID's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * ClassWithRequiredID.
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
   * ClassWithRequiredID.
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
   * ClassWithRequiredID.
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
   * ClassWithRequiredID.
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
   * ClassWithRequiredID.
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
   * Sets the value of the "attributeName" attribute of this
   * ClassWithRequiredID.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, const char*
    value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this
   * ClassWithRequiredID.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


protected:


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
 * Creates a new ClassWithRequiredID_t using the given SBML Level, Version and
 * &ldquo;twoatonce&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * ClassWithRequiredID_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ClassWithRequiredID_t.
 *
 * @param pkgVersion an unsigned int, the SBML Twoatonce Version to assign to
 * this ClassWithRequiredID_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ClassWithRequiredID_t
 */
LIBSBML_EXTERN
ClassWithRequiredID_t *
ClassWithRequiredID_create(unsigned int level,
                           unsigned int version,
                           unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this ClassWithRequiredID_t object.
 *
 * @param cwrid the ClassWithRequiredID_t structure.
 *
 * @return a (deep) copy of this ClassWithRequiredID_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ClassWithRequiredID_t
 */
LIBSBML_EXTERN
ClassWithRequiredID_t*
ClassWithRequiredID_clone(const ClassWithRequiredID_t* cwrid);


/**
 * Frees this ClassWithRequiredID_t object.
 *
 * @param cwrid the ClassWithRequiredID_t structure.
 *
 * @memberof ClassWithRequiredID_t
 */
LIBSBML_EXTERN
void
ClassWithRequiredID_free(ClassWithRequiredID_t* cwrid);


/**
 * Returns the value of the "id" attribute of this ClassWithRequiredID_t.
 *
 * @param cwrid the ClassWithRequiredID_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this ClassWithRequiredID_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof ClassWithRequiredID_t
 */
LIBSBML_EXTERN
char *
ClassWithRequiredID_getId(const ClassWithRequiredID_t * cwrid);


/**
 * Predicate returning @c 1 (true) if this ClassWithRequiredID_t's "id"
 * attribute is set.
 *
 * @param cwrid the ClassWithRequiredID_t structure.
 *
 * @return @c 1 (true) if this ClassWithRequiredID_t's "id" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof ClassWithRequiredID_t
 */
LIBSBML_EXTERN
int
ClassWithRequiredID_isSetId(const ClassWithRequiredID_t * cwrid);


/**
 * Sets the value of the "id" attribute of this ClassWithRequiredID_t.
 *
 * @param cwrid the ClassWithRequiredID_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling ClassWithRequiredID_unsetId().
 *
 * @memberof ClassWithRequiredID_t
 */
LIBSBML_EXTERN
int
ClassWithRequiredID_setId(ClassWithRequiredID_t * cwrid, const char * id);


/**
 * Unsets the value of the "id" attribute of this ClassWithRequiredID_t.
 *
 * @param cwrid the ClassWithRequiredID_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassWithRequiredID_t
 */
LIBSBML_EXTERN
int
ClassWithRequiredID_unsetId(ClassWithRequiredID_t * cwrid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * ClassWithRequiredID_t object have been set.
 *
 * @param cwrid the ClassWithRequiredID_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * ClassWithRequiredID_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the ClassWithRequiredID_t object are:
 * @li "id"
 *
 * @memberof ClassWithRequiredID_t
 */
LIBSBML_EXTERN
int
ClassWithRequiredID_hasRequiredAttributes(const ClassWithRequiredID_t * cwrid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ClassWithRequiredID_H__ */


