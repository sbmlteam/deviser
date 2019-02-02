/**
 * @file ClassThree.h
 * @brief Definition of the ClassThree class.
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
 * @class ClassThree
 * @sbmlbrief{test} TODO:Definition of the ClassThree class.
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
 * @class doc_classthree_number
 *
 * @par
 * The attribute "number" on a ClassThree object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Test specification, the following are the
 * allowable values for "number":
 * <ul>
 * <li> @c "One", TODO:add description
 *
 * <li> @c "Two", TODO:add description
 *
 * </ul>
 *
 * @class doc_classthree_name
 *
 * @par
 * The attribute "name" on a ClassThree object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Test specification, the following are the
 * allowable values for "name":
 * <ul>
 * <li> @c "tom", TODO:add description
 *
 * <li> @c "dick", TODO:add description
 *
 * </ul>
 *
 * @class doc_classthree_badName
 *
 * @par
 * The attribute "badName" on a ClassThree object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Test specification, the following are the
 * allowable values for "badName":
 * <ul>
 * <li> @c "tom", TODO:add description
 *
 * <li> @c "dick", TODO:add description
 *
 * </ul>
 *
 * @class doc_classthree_otherNum
 *
 * @par
 * The attribute "otherNum" on a ClassThree object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Test specification, the following are the
 * allowable values for "otherNum":
 * <ul>
 * <li> @c "One", TODO:add description
 *
 * <li> @c "Two", TODO:add description
 *
 * </ul>
 *
 * @class doc_classthree_longEnum
 *
 * @par
 * The attribute "longEnum" on a ClassThree object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Test specification, the following are the
 * allowable values for "longEnum":
 * <ul>
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3", TODO:add description
 *
 * <li> @c "sarahasdfghjklkjhgfdsasdfghjhjklqwertyqwrtyhgfdssfghkjakakalkalklpoiutytrewhhhhhhhsshshshshshhshshhshhshhsssssssssssaaevenlongerlongerlongeraZ", TODO:add description
 *
 * </ul>
 */


#ifndef ClassThree_H__
#define ClassThree_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ClassThree : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  Enum_t mNumber;
  Fred_t mBadName;
  Enum_t mOtherNum;
  ExtraLong_t mLongEnum;

  /** @endcond */

public:

  /**
   * Creates a new ClassThree using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this ClassThree.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ClassThree.
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * ClassThree.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ClassThree(unsigned int level = TestExtension::getDefaultLevel(),
             unsigned int version = TestExtension::getDefaultVersion(),
             unsigned int pkgVersion =
               TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new ClassThree using the given TestPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param testns the TestPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ClassThree(TestPkgNamespaces *testns);


  /**
   * Copy constructor for ClassThree.
   *
   * @param orig the ClassThree instance to copy.
   */
  ClassThree(const ClassThree& orig);


  /**
   * Assignment operator for ClassThree.
   *
   * @param rhs the ClassThree object whose values are to be used as the basis
   * of the assignment.
   */
  ClassThree& operator=(const ClassThree& rhs);


  /**
   * Creates and returns a deep copy of this ClassThree object.
   *
   * @return a (deep) copy of this ClassThree object.
   */
  virtual ClassThree* clone() const;


  /**
   * Destructor for ClassThree.
   */
  virtual ~ClassThree();


  /**
   * Returns the value of the "number" attribute of this ClassThree.
   *
   * @return the value of the "number" attribute of this ClassThree as a
   * Enum_t.
   *
   * @copydetails doc_classthree_number
   * @if clike The value is drawn from the enumeration @ref Enum_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{TEST_ENUM_ONE, Enum_t}
   * @li @sbmlconstant{TEST_ENUM_TWO, Enum_t}
   * @li @sbmlconstant{TEST_ENUM_INVALID, Enum_t}
   */
  Enum_t getNumber() const;


  /**
   * Returns the value of the "number" attribute of this ClassThree.
   *
   * @return the value of the "number" attribute of this ClassThree as a
   * string.
   *
   * @copydetails doc_classthree_number
   * The possible values returned by this method are:
   * @li @c "One"
   * @li @c "Two"
   * @li @c "invalid Enum value"
   */
  std::string getNumberAsString() const;


  /**
   * Returns the value of the "name" attribute of this ClassThree.
   *
   * @return the value of the "name" attribute of this ClassThree as a Fred_t.
   *
   * @copydetails doc_classthree_name
   * @if clike The value is drawn from the enumeration @ref Fred_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{TEST_FRED_T_TOM, Fred_t}
   * @li @sbmlconstant{TEST_FRED_T_DICK, Fred_t}
   * @li @sbmlconstant{TEST_FRED_INVALID, Fred_t}
   */
  virtual Fred_t getName() const;


  /**
   * Returns the value of the "name" attribute of this ClassThree.
   *
   * @return the value of the "name" attribute of this ClassThree as a string.
   *
   * @copydetails doc_classthree_name
   * The possible values returned by this method are:
   * @li @c "tom"
   * @li @c "dick"
   * @li @c "invalid Fred value"
   */
  std::string getNameAsString() const;


  /**
   * Returns the value of the "badName" attribute of this ClassThree.
   *
   * @return the value of the "badName" attribute of this ClassThree as a
   * Fred_t.
   *
   * @copydetails doc_classthree_badName
   * @if clike The value is drawn from the enumeration @ref Fred_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{TEST_FRED_T_TOM, Fred_t}
   * @li @sbmlconstant{TEST_FRED_T_DICK, Fred_t}
   * @li @sbmlconstant{TEST_FRED_INVALID, Fred_t}
   */
  Fred_t getBadName() const;


  /**
   * Returns the value of the "badName" attribute of this ClassThree.
   *
   * @return the value of the "badName" attribute of this ClassThree as a
   * string.
   *
   * @copydetails doc_classthree_badName
   * The possible values returned by this method are:
   * @li @c "tom"
   * @li @c "dick"
   * @li @c "invalid Fred value"
   */
  std::string getBadNameAsString() const;


  /**
   * Returns the value of the "otherNum" attribute of this ClassThree.
   *
   * @return the value of the "otherNum" attribute of this ClassThree as a
   * Enum_t.
   *
   * @copydetails doc_classthree_otherNum
   * @if clike The value is drawn from the enumeration @ref Enum_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{TEST_ENUM_ONE, Enum_t}
   * @li @sbmlconstant{TEST_ENUM_TWO, Enum_t}
   * @li @sbmlconstant{TEST_ENUM_INVALID, Enum_t}
   */
  Enum_t getOtherNum() const;


  /**
   * Returns the value of the "otherNum" attribute of this ClassThree.
   *
   * @return the value of the "otherNum" attribute of this ClassThree as a
   * string.
   *
   * @copydetails doc_classthree_otherNum
   * The possible values returned by this method are:
   * @li @c "One"
   * @li @c "Two"
   * @li @c "invalid Enum value"
   */
  std::string getOtherNumAsString() const;


  /**
   * Returns the value of the "longEnum" attribute of this ClassThree.
   *
   * @return the value of the "longEnum" attribute of this ClassThree as a
   * ExtraLong_t.
   *
   * @copydetails doc_classthree_longEnum
   * @if clike The value is drawn from the enumeration @ref ExtraLong_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{TEST_EXTRALONG_FRANK, ExtraLong_t}
   * @li @sbmlconstant{TEST_EXTRALONG_SARAH, ExtraLong_t}
   * @li @sbmlconstant{TEST_EXTRALONG_INVALID, ExtraLong_t}
   */
  ExtraLong_t getLongEnum() const;


  /**
   * Returns the value of the "longEnum" attribute of this ClassThree.
   *
   * @return the value of the "longEnum" attribute of this ClassThree as a
   * string.
   *
   * @copydetails doc_classthree_longEnum
   * The possible values returned by this method are:
   * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3"
   * @li @c "sarahasdfghjklkjhgfdsasdfghjhjklqwertyqwrtyhgfdssfghkjakakalkalklpoiutytrewhhhhhhhsshshshshshhshshhshhshhsssssssssssaaevenlongerlongerlongeraZ"
   * @li @c "invalid ExtraLong value"
   */
  std::string getLongEnumAsString() const;


  /**
   * Predicate returning @c true if this ClassThree's "number" attribute is
   * set.
   *
   * @return @c true if this ClassThree's "number" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_classthree_number
   */
  bool isSetNumber() const;


  /**
   * Predicate returning @c true if this ClassThree's "name" attribute is set.
   *
   * @return @c true if this ClassThree's "name" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_classthree_name
   */
  virtual bool isSetName() const;


  /**
   * Predicate returning @c true if this ClassThree's "badName" attribute is
   * set.
   *
   * @return @c true if this ClassThree's "badName" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_classthree_badName
   */
  bool isSetBadName() const;


  /**
   * Predicate returning @c true if this ClassThree's "otherNum" attribute is
   * set.
   *
   * @return @c true if this ClassThree's "otherNum" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_classthree_otherNum
   */
  bool isSetOtherNum() const;


  /**
   * Predicate returning @c true if this ClassThree's "longEnum" attribute is
   * set.
   *
   * @return @c true if this ClassThree's "longEnum" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_classthree_longEnum
   */
  bool isSetLongEnum() const;


  /**
   * Sets the value of the "number" attribute of this ClassThree.
   *
   * @param number @if clike Enum_t@else int@endif value of the "number"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_number
   */
  int setNumber(const Enum_t number);


  /**
   * Sets the value of the "number" attribute of this ClassThree.
   *
   * @param number std::string& of the "number" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_number
   */
  int setNumber(const std::string& number);


  /**
   * Sets the value of the "name" attribute of this ClassThree.
   *
   * @param name @if clike Fred_t@else int@endif value of the "name" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_name
   */
  virtual int setName(const Fred_t name);


  /**
   * Sets the value of the "name" attribute of this ClassThree.
   *
   * @param name std::string& of the "name" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_name
   */
  int setName(const std::string& name);


  /**
   * Sets the value of the "badName" attribute of this ClassThree.
   *
   * @param badName @if clike Fred_t@else int@endif value of the "badName"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_badName
   */
  int setBadName(const Fred_t badName);


  /**
   * Sets the value of the "badName" attribute of this ClassThree.
   *
   * @param badName std::string& of the "badName" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_badName
   */
  int setBadName(const std::string& badName);


  /**
   * Sets the value of the "otherNum" attribute of this ClassThree.
   *
   * @param otherNum @if clike Enum_t@else int@endif value of the "otherNum"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_otherNum
   */
  int setOtherNum(const Enum_t otherNum);


  /**
   * Sets the value of the "otherNum" attribute of this ClassThree.
   *
   * @param otherNum std::string& of the "otherNum" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_otherNum
   */
  int setOtherNum(const std::string& otherNum);


  /**
   * Sets the value of the "longEnum" attribute of this ClassThree.
   *
   * @param longEnum @if clike ExtraLong_t@else int@endif value of the
   * "longEnum" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_longEnum
   */
  int setLongEnum(const ExtraLong_t longEnum);


  /**
   * Sets the value of the "longEnum" attribute of this ClassThree.
   *
   * @param longEnum std::string& of the "longEnum" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_classthree_longEnum
   */
  int setLongEnum(const std::string& longEnum);


  /**
   * Unsets the value of the "number" attribute of this ClassThree.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_classthree_number
   */
  int unsetNumber();


  /**
   * Unsets the value of the "name" attribute of this ClassThree.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_classthree_name
   */
  virtual int unsetName();


  /**
   * Unsets the value of the "badName" attribute of this ClassThree.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_classthree_badName
   */
  int unsetBadName();


  /**
   * Unsets the value of the "otherNum" attribute of this ClassThree.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_classthree_otherNum
   */
  int unsetOtherNum();


  /**
   * Unsets the value of the "longEnum" attribute of this ClassThree.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_classthree_longEnum
   */
  int unsetLongEnum();


  /**
   * Returns the XML element name of this ClassThree object.
   *
   * For ClassThree, the XML element name is always @c "classThree".
   *
   * @return the name of this element, i.e. @c "classThree".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ClassThree object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_TEST_CLASSTHREE, SBMLTestTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * ClassThree object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * ClassThree have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the ClassThree object are:
   * @li "number"
   * @li "name"
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
   * Gets the value of the "attributeName" attribute of this ClassThree.
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
   * Gets the value of the "attributeName" attribute of this ClassThree.
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
   * Gets the value of the "attributeName" attribute of this ClassThree.
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
   * Gets the value of the "attributeName" attribute of this ClassThree.
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
   * Gets the value of the "attributeName" attribute of this ClassThree.
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
   * Predicate returning @c true if this ClassThree's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this ClassThree's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ClassThree.
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
   * Sets the value of the "attributeName" attribute of this ClassThree.
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
   * Sets the value of the "attributeName" attribute of this ClassThree.
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
   * Sets the value of the "attributeName" attribute of this ClassThree.
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
   * Sets the value of the "attributeName" attribute of this ClassThree.
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
   * Unsets the value of the "attributeName" attribute of this ClassThree.
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
 * Creates a new ClassThree_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this ClassThree_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ClassThree_t.
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * ClassThree_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
ClassThree_t *
ClassThree_create(unsigned int level,
                  unsigned int version,
                  unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this ClassThree_t object.
 *
 * @param ct the ClassThree_t structure.
 *
 * @return a (deep) copy of this ClassThree_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
ClassThree_t*
ClassThree_clone(const ClassThree_t* ct);


/**
 * Frees this ClassThree_t object.
 *
 * @param ct the ClassThree_t structure.
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
void
ClassThree_free(ClassThree_t* ct);


/**
 * Returns the value of the "number" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose number is sought.
 *
 * @return the value of the "number" attribute of this ClassThree_t as a
 * Enum_t.
 *
 * @copydetails doc_classthree_number
 * @if clike The value is drawn from the enumeration @ref Enum_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{TEST_ENUM_ONE, Enum_t}
 * @li @sbmlconstant{TEST_ENUM_TWO, Enum_t}
 * @li @sbmlconstant{TEST_ENUM_INVALID, Enum_t}
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
Enum_t
ClassThree_getNumber(const ClassThree_t * ct);


/**
 * Returns the value of the "number" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose number is sought.
 *
 * @return the value of the "number" attribute of this ClassThree_t as a const
 * char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_classthree_number
 * The possible values returned by this method are:
 * @li @c "One"
 * @li @c "Two"
 * @li @c "invalid Enum value"
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
char *
ClassThree_getNumberAsString(const ClassThree_t * ct);


/**
 * Returns the value of the "name" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this ClassThree_t as a Fred_t.
 *
 * @copydetails doc_classthree_name
 * @if clike The value is drawn from the enumeration @ref Fred_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{TEST_FRED_T_TOM, Fred_t}
 * @li @sbmlconstant{TEST_FRED_T_DICK, Fred_t}
 * @li @sbmlconstant{TEST_FRED_INVALID, Fred_t}
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
Fred_t
ClassThree_getName(const ClassThree_t * ct);


/**
 * Returns the value of the "name" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this ClassThree_t as a const
 * char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_classthree_name
 * The possible values returned by this method are:
 * @li @c "tom"
 * @li @c "dick"
 * @li @c "invalid Fred value"
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
char *
ClassThree_getNameAsString(const ClassThree_t * ct);


/**
 * Returns the value of the "badName" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose badName is sought.
 *
 * @return the value of the "badName" attribute of this ClassThree_t as a
 * Fred_t.
 *
 * @copydetails doc_classthree_badName
 * @if clike The value is drawn from the enumeration @ref Fred_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{TEST_FRED_T_TOM, Fred_t}
 * @li @sbmlconstant{TEST_FRED_T_DICK, Fred_t}
 * @li @sbmlconstant{TEST_FRED_INVALID, Fred_t}
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
Fred_t
ClassThree_getBadName(const ClassThree_t * ct);


/**
 * Returns the value of the "badName" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose badName is sought.
 *
 * @return the value of the "badName" attribute of this ClassThree_t as a const
 * char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_classthree_badName
 * The possible values returned by this method are:
 * @li @c "tom"
 * @li @c "dick"
 * @li @c "invalid Fred value"
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
char *
ClassThree_getBadNameAsString(const ClassThree_t * ct);


/**
 * Returns the value of the "otherNum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose otherNum is sought.
 *
 * @return the value of the "otherNum" attribute of this ClassThree_t as a
 * Enum_t.
 *
 * @copydetails doc_classthree_otherNum
 * @if clike The value is drawn from the enumeration @ref Enum_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{TEST_ENUM_ONE, Enum_t}
 * @li @sbmlconstant{TEST_ENUM_TWO, Enum_t}
 * @li @sbmlconstant{TEST_ENUM_INVALID, Enum_t}
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
Enum_t
ClassThree_getOtherNum(const ClassThree_t * ct);


/**
 * Returns the value of the "otherNum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose otherNum is sought.
 *
 * @return the value of the "otherNum" attribute of this ClassThree_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_classthree_otherNum
 * The possible values returned by this method are:
 * @li @c "One"
 * @li @c "Two"
 * @li @c "invalid Enum value"
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
char *
ClassThree_getOtherNumAsString(const ClassThree_t * ct);


/**
 * Returns the value of the "longEnum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose longEnum is sought.
 *
 * @return the value of the "longEnum" attribute of this ClassThree_t as a
 * ExtraLong_t.
 *
 * @copydetails doc_classthree_longEnum
 * @if clike The value is drawn from the enumeration @ref ExtraLong_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{TEST_EXTRALONG_FRANK, ExtraLong_t}
 * @li @sbmlconstant{TEST_EXTRALONG_SARAH, ExtraLong_t}
 * @li @sbmlconstant{TEST_EXTRALONG_INVALID, ExtraLong_t}
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
ExtraLong_t
ClassThree_getLongEnum(const ClassThree_t * ct);


/**
 * Returns the value of the "longEnum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure whose longEnum is sought.
 *
 * @return the value of the "longEnum" attribute of this ClassThree_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_classthree_longEnum
 * The possible values returned by this method are:
 * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3"
 * @li @c "sarahasdfghjklkjhgfdsasdfghjhjklqwertyqwrtyhgfdssfghkjakakalkalklpoiutytrewhhhhhhhsshshshshshhshshhshhshhsssssssssssaaevenlongerlongerlongeraZ"
 * @li @c "invalid ExtraLong value"
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
char *
ClassThree_getLongEnumAsString(const ClassThree_t * ct);


/**
 * Predicate returning @c 1 (true) if this ClassThree_t's "number" attribute is
 * set.
 *
 * @param ct the ClassThree_t structure.
 *
 * @return @c 1 (true) if this ClassThree_t's "number" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_classthree_number
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_isSetNumber(const ClassThree_t * ct);


/**
 * Predicate returning @c 1 (true) if this ClassThree_t's "name" attribute is
 * set.
 *
 * @param ct the ClassThree_t structure.
 *
 * @return @c 1 (true) if this ClassThree_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_classthree_name
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_isSetName(const ClassThree_t * ct);


/**
 * Predicate returning @c 1 (true) if this ClassThree_t's "badName" attribute
 * is set.
 *
 * @param ct the ClassThree_t structure.
 *
 * @return @c 1 (true) if this ClassThree_t's "badName" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_classthree_badName
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_isSetBadName(const ClassThree_t * ct);


/**
 * Predicate returning @c 1 (true) if this ClassThree_t's "otherNum" attribute
 * is set.
 *
 * @param ct the ClassThree_t structure.
 *
 * @return @c 1 (true) if this ClassThree_t's "otherNum" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_classthree_otherNum
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_isSetOtherNum(const ClassThree_t * ct);


/**
 * Predicate returning @c 1 (true) if this ClassThree_t's "longEnum" attribute
 * is set.
 *
 * @param ct the ClassThree_t structure.
 *
 * @return @c 1 (true) if this ClassThree_t's "longEnum" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_classthree_longEnum
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_isSetLongEnum(const ClassThree_t * ct);


/**
 * Sets the value of the "number" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param number Enum_t value of the "number" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_number
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setNumber(ClassThree_t * ct, Enum_t number);


/**
 * Sets the value of the "number" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param number const char * of the "number" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_number
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setNumberAsString(ClassThree_t * ct, const char * number);


/**
 * Sets the value of the "name" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param name Fred_t value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_name
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setName(ClassThree_t * ct, Fred_t name);


/**
 * Sets the value of the "name" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param name const char * of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_name
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setNameAsString(ClassThree_t * ct, const char * name);


/**
 * Sets the value of the "badName" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param badName Fred_t value of the "badName" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_badName
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setBadName(ClassThree_t * ct, Fred_t badName);


/**
 * Sets the value of the "badName" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param badName const char * of the "badName" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_badName
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setBadNameAsString(ClassThree_t * ct, const char * badName);


/**
 * Sets the value of the "otherNum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param otherNum Enum_t value of the "otherNum" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_otherNum
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setOtherNum(ClassThree_t * ct, Enum_t otherNum);


/**
 * Sets the value of the "otherNum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param otherNum const char * of the "otherNum" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_otherNum
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setOtherNumAsString(ClassThree_t * ct, const char * otherNum);


/**
 * Sets the value of the "longEnum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param longEnum ExtraLong_t value of the "longEnum" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_longEnum
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setLongEnum(ClassThree_t * ct, ExtraLong_t longEnum);


/**
 * Sets the value of the "longEnum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @param longEnum const char * of the "longEnum" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_longEnum
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_setLongEnumAsString(ClassThree_t * ct, const char * longEnum);


/**
 * Unsets the value of the "number" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_number
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_unsetNumber(ClassThree_t * ct);


/**
 * Unsets the value of the "name" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_name
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_unsetName(ClassThree_t * ct);


/**
 * Unsets the value of the "badName" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_badName
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_unsetBadName(ClassThree_t * ct);


/**
 * Unsets the value of the "otherNum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_otherNum
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_unsetOtherNum(ClassThree_t * ct);


/**
 * Unsets the value of the "longEnum" attribute of this ClassThree_t.
 *
 * @param ct the ClassThree_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_classthree_longEnum
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_unsetLongEnum(ClassThree_t * ct);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * ClassThree_t object have been set.
 *
 * @param ct the ClassThree_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * ClassThree_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the ClassThree_t object are:
 * @li "number"
 * @li "name"
 *
 * @memberof ClassThree_t
 */
LIBSBML_EXTERN
int
ClassThree_hasRequiredAttributes(const ClassThree_t * ct);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ClassThree_H__ */


