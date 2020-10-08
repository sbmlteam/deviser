/**
 * @file UnknownType.h
 * @brief Definition of the UnknownType class.
 * @author SBMLTeam
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
 * @class UnknownType
 * @sbmlbrief{test} TODO:Definition of the UnknownType class.
 */


#ifndef UnknownType_H__
#define UnknownType_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN UnknownType : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  FIXME_fred mAttribue;

  /** @endcond */

public:

  /**
   * Creates a new UnknownType using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * UnknownType.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * UnknownType.
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * UnknownType.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  UnknownType(unsigned int level = TestExtension::getDefaultLevel(),
              unsigned int version = TestExtension::getDefaultVersion(),
              unsigned int pkgVersion =
                TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new UnknownType using the given TestPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param testns the TestPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  UnknownType(TestPkgNamespaces *testns);


  /**
   * Copy constructor for UnknownType.
   *
   * @param orig the UnknownType instance to copy.
   */
  UnknownType(const UnknownType& orig);


  /**
   * Assignment operator for UnknownType.
   *
   * @param rhs the UnknownType object whose values are to be used as the basis
   * of the assignment.
   */
  UnknownType& operator=(const UnknownType& rhs);


  /**
   * Creates and returns a deep copy of this UnknownType object.
   *
   * @return a (deep) copy of this UnknownType object.
   */
  virtual UnknownType* clone() const;


  /**
   * Destructor for UnknownType.
   */
  virtual ~UnknownType();


  /**
   * Returns the value of the "attribue" attribute of this UnknownType.
   *
   * @return the value of the "attribue" attribute of this UnknownType as a
   * FIXME_fred.
   */
  FIXME_fred getAttribue() const;


  /**
   * Predicate returning @c true if this UnknownType's "attribue" attribute is
   * set.
   *
   * @return @c true if this UnknownType's "attribue" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetAttribue() const;


  /**
   * Sets the value of the "attribue" attribute of this UnknownType.
   *
   * @param attribue FIXME_fred value of the "attribue" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  int setAttribue(FIXME_fred attribue);


  /**
   * Unsets the value of the "attribue" attribute of this UnknownType.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAttribue();


  /**
   * Returns the XML element name of this UnknownType object.
   *
   * For UnknownType, the XML element name is always @c "unknownType".
   *
   * @return the name of this element, i.e. @c "unknownType".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this UnknownType object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_TEST_UNIT, SBMLTestTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * UnknownType object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * UnknownType have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this UnknownType.
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
   * Gets the value of the "attributeName" attribute of this UnknownType.
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
   * Gets the value of the "attributeName" attribute of this UnknownType.
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
   * Gets the value of the "attributeName" attribute of this UnknownType.
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
   * Gets the value of the "attributeName" attribute of this UnknownType.
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
   * Predicate returning @c true if this UnknownType's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this UnknownType's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this UnknownType.
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
   * Sets the value of the "attributeName" attribute of this UnknownType.
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
   * Sets the value of the "attributeName" attribute of this UnknownType.
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
   * Sets the value of the "attributeName" attribute of this UnknownType.
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
   * Sets the value of the "attributeName" attribute of this UnknownType.
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
   * Unsets the value of the "attributeName" attribute of this UnknownType.
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
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new UnknownType_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * UnknownType_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * UnknownType_t.
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * UnknownType_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof UnknownType_t
 */
LIBSBML_EXTERN
UnknownType_t *
UnknownType_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this UnknownType_t object.
 *
 * @param ut the UnknownType_t structure.
 *
 * @return a (deep) copy of this UnknownType_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof UnknownType_t
 */
LIBSBML_EXTERN
UnknownType_t*
UnknownType_clone(const UnknownType_t* ut);


/**
 * Frees this UnknownType_t object.
 *
 * @param ut the UnknownType_t structure.
 *
 * @memberof UnknownType_t
 */
LIBSBML_EXTERN
void
UnknownType_free(UnknownType_t* ut);


/**
 * Returns the value of the "attribue" attribute of this UnknownType_t.
 *
 * @param ut the UnknownType_t structure whose attribue is sought.
 *
 * @return the value of the "attribue" attribute of this UnknownType_t as a
 * FIXME_fred.
 *
 * @memberof UnknownType_t
 */
LIBSBML_EXTERN
FIXME_fred
UnknownType_getAttribue(const UnknownType_t * ut);


/**
 * Predicate returning @c 1 (true) if this UnknownType_t's "attribue" attribute
 * is set.
 *
 * @param ut the UnknownType_t structure.
 *
 * @return @c 1 (true) if this UnknownType_t's "attribue" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof UnknownType_t
 */
LIBSBML_EXTERN
int
UnknownType_isSetAttribue(const UnknownType_t * ut);


/**
 * Sets the value of the "attribue" attribute of this UnknownType_t.
 *
 * @param ut the UnknownType_t structure.
 *
 * @param attribue FIXME_fred value of the "attribue" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof UnknownType_t
 */
LIBSBML_EXTERN
int
UnknownType_setAttribue(UnknownType_t * ut, FIXME_fred attribue);


/**
 * Unsets the value of the "attribue" attribute of this UnknownType_t.
 *
 * @param ut the UnknownType_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof UnknownType_t
 */
LIBSBML_EXTERN
int
UnknownType_unsetAttribue(UnknownType_t * ut);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * UnknownType_t object have been set.
 *
 * @param ut the UnknownType_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * UnknownType_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof UnknownType_t
 */
LIBSBML_EXTERN
int
UnknownType_hasRequiredAttributes(const UnknownType_t * ut);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !UnknownType_H__ */


