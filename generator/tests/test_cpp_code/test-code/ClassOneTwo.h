/**
 * @file ClassOneTwo.h
 * @brief Definition of the ClassOneTwo class.
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
 * @class ClassOneTwo
 * @sbmlbrief{coreversmultipkg} TODO:Definition of the ClassOneTwo class.
 */

/**
 * <!-- ~ ~ ~ ~ ~ Start of common documentation strings ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * The following text is used as common documentation blocks copied multiple
 * times elsewhere in this file. The use of @class is a hack needed because
 * Doxygen's @copydetails command has limited functionality. Symbols
 * beginning with "doc_" are marked as ignored in our Doxygen configuration.
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ -->
 *
 *
 * @class doc_classonetwo_attEnum
 *
 * @par
 * The attribute "attEnum" on a ClassOneTwo object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Coreversmultipkg specification, the following
 * are the
 * allowable values for "attEnum":
 * <ul>
 * <li> @c "maximize", TODO:add description
 *
 * <li> @c "minimize", TODO:add description
 *
 * </ul>
 */


#ifndef ClassOneTwo_H__
#define ClassOneTwo_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/coreversmultipkg/common/coreversmultipkgfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/coreversmultipkg/extension/CoreversmultipkgExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ClassOneTwo : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  bool mAtt1;
  bool mIsSetAtt1;
  std::string mAttStr;
  int mAttInt;
  bool mIsSetAttInt;
  bool mAtt2;
  bool mIsSetAtt2;
  double mAttDbl;
  bool mIsSetAttDbl;
  std::string mAttUnit;
  AbcType_t mAttEnum;

  /** @endcond */

public:

  /**
   * Creates a new ClassOneTwo using the given SBML Level, Version and
   * &ldquo;coreversmultipkg&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ClassOneTwo.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ClassOneTwo.
   *
   * @param pkgVersion an unsigned int, the SBML Coreversmultipkg Version to
   * assign to this ClassOneTwo.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ClassOneTwo(unsigned int level =
    CoreversmultipkgExtension::getDefaultLevel(),
              unsigned int version =
                CoreversmultipkgExtension::getDefaultVersion(),
              unsigned int pkgVersion =
                CoreversmultipkgExtension::getDefaultPackageVersion());


  /**
   * Creates a new ClassOneTwo using the given CoreversmultipkgPkgNamespaces
   * object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param coreversmultipkgns the CoreversmultipkgPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ClassOneTwo(CoreversmultipkgPkgNamespaces *coreversmultipkgns);


  /**
   * Copy constructor for ClassOneTwo.
   *
   * @param orig the ClassOneTwo instance to copy.
   */
  ClassOneTwo(const ClassOneTwo& orig);


  /**
   * Assignment operator for ClassOneTwo.
   *
   * @param rhs the ClassOneTwo object whose values are to be used as the basis
   * of the assignment.
   */
  ClassOneTwo& operator=(const ClassOneTwo& rhs);


  /**
   * Creates and returns a deep copy of this ClassOneTwo object.
   *
   * @return a (deep) copy of this ClassOneTwo object.
   */
  virtual ClassOneTwo* clone() const;


  /**
   * Destructor for ClassOneTwo.
   */
  virtual ~ClassOneTwo();


  /**
   * Returns the value of the "id" attribute of this ClassOneTwo.
   *
   * @return the value of the "id" attribute of this ClassOneTwo as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "att1" attribute of this ClassOneTwo.
   *
   * @return the value of the "att1" attribute of this ClassOneTwo as a
   * boolean.
   */
  bool getAtt1() const;


  /**
   * Returns the value of the "attStr" attribute of this ClassOneTwo.
   *
   * @return the value of the "attStr" attribute of this ClassOneTwo as a
   * string.
   */
  const std::string& getAttStr() const;


  /**
   * Returns the value of the "attInt" attribute of this ClassOneTwo.
   *
   * @return the value of the "attInt" attribute of this ClassOneTwo as a
   * integer.
   */
  int getAttInt() const;


  /**
   * Returns the value of the "att2" attribute of this ClassOneTwo.
   *
   * @return the value of the "att2" attribute of this ClassOneTwo as a
   * boolean.
   */
  bool getAtt2() const;


  /**
   * Returns the value of the "attDbl" attribute of this ClassOneTwo.
   *
   * @return the value of the "attDbl" attribute of this ClassOneTwo as a
   * double.
   */
  double getAttDbl() const;


  /**
   * Returns the value of the "attUnit" attribute of this ClassOneTwo.
   *
   * @return the value of the "attUnit" attribute of this ClassOneTwo as a
   * string.
   */
  const std::string& getAttUnit() const;


  /**
   * Returns the value of the "attEnum" attribute of this ClassOneTwo.
   *
   * @return the value of the "attEnum" attribute of this ClassOneTwo as a
   * AbcType_t.
   *
   * @copydetails doc_classonetwo_attEnum
   * @if clike The value is drawn from the enumeration @ref AbcType_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{OBJECTIVE_TYPE_MAXIMIZE, AbcType_t}
   * @li @sbmlconstant{OBJECTIVE_TYPE_MINIMIZE, AbcType_t}
   * @li @sbmlconstant{CLASS_ONE_TWO_ATT_ENUM_INVALID, AbcType_t}
   */
  AbcType_t getAttEnum() const;


  /**
   * Returns the value of the "attEnum" attribute of this ClassOneTwo.
   *
   * @return the value of the "attEnum" attribute of this ClassOneTwo as a
   * string.
   *
   * @copydetails doc_classonetwo_attEnum
   * The possible values returned by this method are:
   * @li @c "maximize"
   * @li @c "minimize"
   * @li @c "invalid ClassOneTwoAttEnum"
   */
  const std::string& getAttEnumAsString() const;


  /**
   * Predicate returning @c true if this ClassOneTwo's "id" attribute is set.
   *
   * @return @c true if this ClassOneTwo's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this ClassOneTwo's "att1" attribute is set.
   *
   * @return @c true if this ClassOneTwo's "att1" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetAtt1() const;


  /**
   * Predicate returning @c true if this ClassOneTwo's "attStr" attribute is
   * set.
   *
   * @return @c true if this ClassOneTwo's "attStr" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetAttStr() const;


  /**
   * Predicate returning @c true if this ClassOneTwo's "attInt" attribute is
   * set.
   *
   * @return @c true if this ClassOneTwo's "attInt" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetAttInt() const;


  /**
   * Predicate returning @c true if this ClassOneTwo's "att2" attribute is set.
   *
   * @return @c true if this ClassOneTwo's "att2" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetAtt2() const;


  /**
   * Predicate returning @c true if this ClassOneTwo's "attDbl" attribute is
   * set.
   *
   * @return @c true if this ClassOneTwo's "attDbl" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetAttDbl() const;


  /**
   * Predicate returning @c true if this ClassOneTwo's "attUnit" attribute is
   * set.
   *
   * @return @c true if this ClassOneTwo's "attUnit" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetAttUnit() const;


  /**
   * Predicate returning @c true if this ClassOneTwo's "attEnum" attribute is
   * set.
   *
   * @return @c true if this ClassOneTwo's "attEnum" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_classonetwo_attEnum
   */
  bool isSetAttEnum() const;


  /**
   * Sets the value of the "id" attribute of this ClassOneTwo.
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
   * Sets the value of the "att1" attribute of this ClassOneTwo.
   *
   * @param att1 bool value of the "att1" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAtt1(bool att1);


  /**
   * Sets the value of the "attStr" attribute of this ClassOneTwo.
   *
   * @param attStr std::string& value of the "attStr" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p attStr = @c NULL or an empty string is
   * equivalent to calling unsetAttStr().
   */
  int setAttStr(const std::string& attStr);


  /**
   * Sets the value of the "attInt" attribute of this ClassOneTwo.
   *
   * @param attInt int value of the "attInt" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAttInt(int attInt);


  /**
   * Sets the value of the "att2" attribute of this ClassOneTwo.
   *
   * @param att2 bool value of the "att2" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAtt2(bool att2);


  /**
   * Sets the value of the "attDbl" attribute of this ClassOneTwo.
   *
   * @param attDbl double value of the "attDbl" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAttDbl(double attDbl);


  /**
   * Sets the value of the "attUnit" attribute of this ClassOneTwo.
   *
   * @param attUnit std::string& value of the "attUnit" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAttUnit(const std::string& attUnit);


  /**
   * Sets the value of the "attEnum" attribute of this ClassOneTwo.
   *
   * @param attEnum @if clike AbcType_t@else int@endif value of the "attEnum"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classonetwo_attEnum
   */
  int setAttEnum(const AbcType_t attEnum);


  /**
   * Sets the value of the "attEnum" attribute of this ClassOneTwo.
   *
   * @param attEnum std::string& of the "attEnum" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classonetwo_attEnum
   */
  int setAttEnum(const std::string& attEnum);


  /**
   * Unsets the value of the "id" attribute of this ClassOneTwo.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "att1" attribute of this ClassOneTwo.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAtt1();


  /**
   * Unsets the value of the "attStr" attribute of this ClassOneTwo.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAttStr();


  /**
   * Unsets the value of the "attInt" attribute of this ClassOneTwo.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAttInt();


  /**
   * Unsets the value of the "att2" attribute of this ClassOneTwo.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAtt2();


  /**
   * Unsets the value of the "attDbl" attribute of this ClassOneTwo.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAttDbl();


  /**
   * Unsets the value of the "attUnit" attribute of this ClassOneTwo.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAttUnit();


  /**
   * Unsets the value of the "attEnum" attribute of this ClassOneTwo.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_classonetwo_attEnum
   */
  int unsetAttEnum();


  /**
   * Returns the XML element name of this ClassOneTwo object.
   *
   * For ClassOneTwo, the XML element name is always @c "classOneTwo".
   *
   * @return the name of this element, i.e. @c "classOneTwo".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ClassOneTwo object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_COREVERS_CLASSONETWO, SBMLCoreversmultipkgTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * ClassOneTwo object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * ClassOneTwo have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the ClassOneTwo object are:
   * @li "id"
   * @li "attEnum"
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
   * Gets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Gets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Gets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Gets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Gets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Predicate returning @c true if this ClassOneTwo's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this ClassOneTwo's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Sets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Sets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Sets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Sets the value of the "attributeName" attribute of this ClassOneTwo.
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
   * Unsets the value of the "attributeName" attribute of this ClassOneTwo.
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
  virtual void readL3V1V2Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readL3V2V1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readL3V2V2Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readL4V1V1Attributes(const XMLAttributes& attributes);

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
  virtual void writeL3V1V2Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeL3V2V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeL3V2V2Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeL4V1V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new ClassOneTwo_t using the given SBML Level, Version and
 * &ldquo;coreversmultipkg&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * ClassOneTwo_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ClassOneTwo_t.
 *
 * @param pkgVersion an unsigned int, the SBML Coreversmultipkg Version to
 * assign to this ClassOneTwo_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
ClassOneTwo_t *
ClassOneTwo_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this ClassOneTwo_t object.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return a (deep) copy of this ClassOneTwo_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
ClassOneTwo_t*
ClassOneTwo_clone(const ClassOneTwo_t* cot);


/**
 * Frees this ClassOneTwo_t object.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
void
ClassOneTwo_free(ClassOneTwo_t* cot);


/**
 * Returns the value of the "id" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this ClassOneTwo_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
char *
ClassOneTwo_getId(const ClassOneTwo_t * cot);


/**
 * Returns the value of the "att1" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure whose att1 is sought.
 *
 * @return the value of the "att1" attribute of this ClassOneTwo_t as a
 * boolean.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_getAtt1(const ClassOneTwo_t * cot);


/**
 * Returns the value of the "attStr" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure whose attStr is sought.
 *
 * @return the value of the "attStr" attribute of this ClassOneTwo_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
char *
ClassOneTwo_getAttStr(const ClassOneTwo_t * cot);


/**
 * Returns the value of the "attInt" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure whose attInt is sought.
 *
 * @return the value of the "attInt" attribute of this ClassOneTwo_t as a
 * integer.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_getAttInt(const ClassOneTwo_t * cot);


/**
 * Returns the value of the "att2" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure whose att2 is sought.
 *
 * @return the value of the "att2" attribute of this ClassOneTwo_t as a
 * boolean.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_getAtt2(const ClassOneTwo_t * cot);


/**
 * Returns the value of the "attDbl" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure whose attDbl is sought.
 *
 * @return the value of the "attDbl" attribute of this ClassOneTwo_t as a
 * double.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
double
ClassOneTwo_getAttDbl(const ClassOneTwo_t * cot);


/**
 * Returns the value of the "attUnit" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure whose attUnit is sought.
 *
 * @return the value of the "attUnit" attribute of this ClassOneTwo_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
char *
ClassOneTwo_getAttUnit(const ClassOneTwo_t * cot);


/**
 * Returns the value of the "attEnum" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure whose attEnum is sought.
 *
 * @return the value of the "attEnum" attribute of this ClassOneTwo_t as a
 * AbcType_t.
 *
 * @copydetails doc_classonetwo_attEnum
 * @if clike The value is drawn from the enumeration @ref AbcType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{OBJECTIVE_TYPE_MAXIMIZE, AbcType_t}
 * @li @sbmlconstant{OBJECTIVE_TYPE_MINIMIZE, AbcType_t}
 * @li @sbmlconstant{CLASS_ONE_TWO_ATT_ENUM_INVALID, AbcType_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
AbcType_t
ClassOneTwo_getAttEnum(const ClassOneTwo_t * cot);


/**
 * Returns the value of the "attEnum" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure whose attEnum is sought.
 *
 * @return the value of the "attEnum" attribute of this ClassOneTwo_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_classonetwo_attEnum
 * The possible values returned by this method are:
 * @li @c "maximize"
 * @li @c "minimize"
 * @li @c "invalid ClassOneTwoAttEnum"
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
const char *
ClassOneTwo_getAttEnumAsString(const ClassOneTwo_t * cot);


/**
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "id" attribute is
 * set.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return @c 1 (true) if this ClassOneTwo_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetId(const ClassOneTwo_t * cot);


/**
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "att1" attribute is
 * set.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return @c 1 (true) if this ClassOneTwo_t's "att1" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAtt1(const ClassOneTwo_t * cot);


/**
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attStr" attribute
 * is set.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return @c 1 (true) if this ClassOneTwo_t's "attStr" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttStr(const ClassOneTwo_t * cot);


/**
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attInt" attribute
 * is set.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return @c 1 (true) if this ClassOneTwo_t's "attInt" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttInt(const ClassOneTwo_t * cot);


/**
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "att2" attribute is
 * set.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return @c 1 (true) if this ClassOneTwo_t's "att2" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAtt2(const ClassOneTwo_t * cot);


/**
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attDbl" attribute
 * is set.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return @c 1 (true) if this ClassOneTwo_t's "attDbl" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttDbl(const ClassOneTwo_t * cot);


/**
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attUnit" attribute
 * is set.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return @c 1 (true) if this ClassOneTwo_t's "attUnit" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttUnit(const ClassOneTwo_t * cot);


/**
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attEnum" attribute
 * is set.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return @c 1 (true) if this ClassOneTwo_t's "attEnum" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_classonetwo_attEnum
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttEnum(const ClassOneTwo_t * cot);


/**
 * Sets the value of the "id" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling ClassOneTwo_unsetId().
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_setId(ClassOneTwo_t * cot, const char * id);


/**
 * Sets the value of the "att1" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @param att1 int value of the "att1" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAtt1(ClassOneTwo_t * cot, int att1);


/**
 * Sets the value of the "attStr" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @param attStr const char * value of the "attStr" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p attStr = @c NULL or an empty string is
 * equivalent to calling ClassOneTwo_unsetAttStr().
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttStr(ClassOneTwo_t * cot, const char * attStr);


/**
 * Sets the value of the "attInt" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @param attInt int value of the "attInt" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttInt(ClassOneTwo_t * cot, int attInt);


/**
 * Sets the value of the "att2" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @param att2 int value of the "att2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAtt2(ClassOneTwo_t * cot, int att2);


/**
 * Sets the value of the "attDbl" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @param attDbl double value of the "attDbl" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttDbl(ClassOneTwo_t * cot, double attDbl);


/**
 * Sets the value of the "attUnit" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @param attUnit const char * value of the "attUnit" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttUnit(ClassOneTwo_t * cot, const char * attUnit);


/**
 * Sets the value of the "attEnum" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @param attEnum AbcType_t value of the "attEnum" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classonetwo_attEnum
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttEnum(ClassOneTwo_t * cot, AbcType_t attEnum);


/**
 * Sets the value of the "attEnum" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @param attEnum const char * of the "attEnum" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classonetwo_attEnum
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttEnumAsString(ClassOneTwo_t * cot, const char * attEnum);


/**
 * Unsets the value of the "id" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetId(ClassOneTwo_t * cot);


/**
 * Unsets the value of the "att1" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAtt1(ClassOneTwo_t * cot);


/**
 * Unsets the value of the "attStr" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttStr(ClassOneTwo_t * cot);


/**
 * Unsets the value of the "attInt" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttInt(ClassOneTwo_t * cot);


/**
 * Unsets the value of the "att2" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAtt2(ClassOneTwo_t * cot);


/**
 * Unsets the value of the "attDbl" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttDbl(ClassOneTwo_t * cot);


/**
 * Unsets the value of the "attUnit" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttUnit(ClassOneTwo_t * cot);


/**
 * Unsets the value of the "attEnum" attribute of this ClassOneTwo_t.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classonetwo_attEnum
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttEnum(ClassOneTwo_t * cot);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * ClassOneTwo_t object have been set.
 *
 * @param cot the ClassOneTwo_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * ClassOneTwo_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the ClassOneTwo_t object are:
 * @li "id"
 * @li "attEnum"
 *
 * @memberof ClassOneTwo_t
 */
LIBSBML_EXTERN
int
ClassOneTwo_hasRequiredAttributes(const ClassOneTwo_t * cot);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ClassOneTwo_H__ */


