/**
 * @file MyRequiredClass.h
 * @brief Definition of MyRequiredClass.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2015 jointly by the following organizations:
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
 */


#ifndef MyRequiredClass_H__
#define MyRequiredClass_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN MyRequiredClass : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  std::string mName;
  unsigned int mNum;
  bool mIsSetNum;
  unsigned int mNum2;
  bool mIsSetNum2;
  int mNum3;
  bool mIsSetNum3;
  double mNum1;
  bool mIsSetNum1;
  bool mTrue;
  bool mIsSetTrue;
  bool mFalse;
  bool mIsSetFalse;
  std::string mUnit;
  std::string mRef1;
  std::string mRef2;
  std::string mRefUnit;
  std::string mCorrectId;
  unsigned int mPosint;
  bool mIsSetPosint;
  unsigned int mPosint2;
  bool mIsSetPosint2;
  unsigned int mPosint1;
  bool mIsSetPosint1;
  std::string mMetaid;
  std::string mMetaid1;
  int mNum4;
  bool mIsSetNum4;
  std::string mMetaidref1;

  /** @endcond */

public:

  /**
   * Creates a new MyRequiredClass using the given SBML @p level, @ p version
   * and package version values.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * MyRequiredClass
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * MyRequiredClass
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * MyRequiredClass
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MyRequiredClass(unsigned int level = TestExtension::getDefaultLevel(),
                  unsigned int version = TestExtension::getDefaultVersion(),
                  unsigned int pkgVersion =
                    TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new MyRequiredClass using the given TestPkgNamespaces object.
   *
   * @param testns the TestPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MyRequiredClass(TestPkgNamespaces *testns);


  /**
   * Copy constructor for MyRequiredClass.
   *
   * @param orig; the MyRequiredClass instance to copy.
   */
  MyRequiredClass(const MyRequiredClass& orig);


  /**
   * Assignment operator for MyRequiredClass.
   *
   * @param rhs; the MyRequiredClass object whose values are to be used as the
   * basis of the assignment
   */
  MyRequiredClass& operator=(const MyRequiredClass& rhs);


  /**
   * Creates and returns a deep copy of this MyRequiredClass object.
   *
   * @return a (deep) copy of this MyRequiredClass object.
   */
  virtual MyRequiredClass* clone() const;


  /**
   * Destructor for MyRequiredClass.
   */
  virtual ~MyRequiredClass();


  /**
   * Returns the value of the "id" attribute of this MyRequiredClass.
   *
   * @return the value of the "id" attribute of this MyRequiredClass as a
   * string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this MyRequiredClass.
   *
   * @return the value of the "name" attribute of this MyRequiredClass as a
   * string.
   */
  const std::string& getName() const;


  /**
   * Returns the value of the "num" attribute of this MyRequiredClass.
   *
   * @return the value of the "num" attribute of this MyRequiredClass as a
   * unsigned integer.
   */
  unsigned int getNum() const;


  /**
   * Returns the value of the "num2" attribute of this MyRequiredClass.
   *
   * @return the value of the "num2" attribute of this MyRequiredClass as a
   * unsigned integer.
   */
  unsigned int getNum2() const;


  /**
   * Returns the value of the "num3" attribute of this MyRequiredClass.
   *
   * @return the value of the "num3" attribute of this MyRequiredClass as a
   * integer.
   */
  int getNum3() const;


  /**
   * Returns the value of the "num1" attribute of this MyRequiredClass.
   *
   * @return the value of the "num1" attribute of this MyRequiredClass as a
   * double.
   */
  double getNum1() const;


  /**
   * Returns the value of the "true" attribute of this MyRequiredClass.
   *
   * @return the value of the "true" attribute of this MyRequiredClass as a
   * boolean.
   */
  bool getTrue() const;


  /**
   * Returns the value of the "false" attribute of this MyRequiredClass.
   *
   * @return the value of the "false" attribute of this MyRequiredClass as a
   * boolean.
   */
  bool getFalse() const;


  /**
   * Returns the value of the "unit" attribute of this MyRequiredClass.
   *
   * @return the value of the "unit" attribute of this MyRequiredClass as a
   * string.
   */
  const std::string& getUnit() const;


  /**
   * Returns the value of the "ref1" attribute of this MyRequiredClass.
   *
   * @return the value of the "ref1" attribute of this MyRequiredClass as a
   * string.
   */
  const std::string& getRef1() const;


  /**
   * Returns the value of the "ref2" attribute of this MyRequiredClass.
   *
   * @return the value of the "ref2" attribute of this MyRequiredClass as a
   * string.
   */
  const std::string& getRef2() const;


  /**
   * Returns the value of the "refUnit" attribute of this MyRequiredClass.
   *
   * @return the value of the "refUnit" attribute of this MyRequiredClass as a
   * string.
   */
  const std::string& getRefUnit() const;


  /**
   * Returns the value of the "correctId" attribute of this MyRequiredClass.
   *
   * @return the value of the "correctId" attribute of this MyRequiredClass as
   * a string.
   */
  const std::string& getCorrectId() const;


  /**
   * Returns the value of the "posint" attribute of this MyRequiredClass.
   *
   * @return the value of the "posint" attribute of this MyRequiredClass as a
   * unsigned integer.
   */
  unsigned int getPosint() const;


  /**
   * Returns the value of the "posint2" attribute of this MyRequiredClass.
   *
   * @return the value of the "posint2" attribute of this MyRequiredClass as a
   * unsigned integer.
   */
  unsigned int getPosint2() const;


  /**
   * Returns the value of the "posint1" attribute of this MyRequiredClass.
   *
   * @return the value of the "posint1" attribute of this MyRequiredClass as a
   * unsigned integer.
   */
  unsigned int getPosint1() const;


  /**
   * Returns the value of the "metaid" attribute of this MyRequiredClass.
   *
   * @return the value of the "metaid" attribute of this MyRequiredClass as a
   * string.
   */
  const std::string& getMetaid() const;


  /**
   * Returns the value of the "metaid1" attribute of this MyRequiredClass.
   *
   * @return the value of the "metaid1" attribute of this MyRequiredClass as a
   * string.
   */
  const std::string& getMetaid1() const;


  /**
   * Returns the value of the "num4" attribute of this MyRequiredClass.
   *
   * @return the value of the "num4" attribute of this MyRequiredClass as a
   * integer.
   */
  int getNum4() const;


  /**
   * Returns the value of the "metaidref1" attribute of this MyRequiredClass.
   *
   * @return the value of the "metaidref1" attribute of this MyRequiredClass as
   * a string.
   */
  const std::string& getMetaidref1() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "id" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "name" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetName() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "num" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "num" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "num2" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "num2" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum2() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "num3" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "num3" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum3() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "num1" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "num1" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum1() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "true" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "true" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTrue() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "false" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "false" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetFalse() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "unit" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "unit" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetUnit() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "ref1" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "ref1" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRef1() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "ref2" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "ref2" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRef2() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "refUnit" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "refUnit" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetRefUnit() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "correctId" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "correctId" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetCorrectId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "posint" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "posint" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetPosint() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "posint2" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "posint2" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetPosint2() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "posint1" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "posint1" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetPosint1() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "metaid" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "metaid" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetMetaid() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "metaid1" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "metaid1" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetMetaid1() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "num4" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "num4" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum4() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyRequiredClass's "metaidref1" attribute has been set.
   *
   * @return @c true if this MyRequiredClass's "metaidref1" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetMetaidref1() const;


  /**
   * Sets the value of the "id" attribute of this MyRequiredClass.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Sets the value of the "name" attribute of this MyRequiredClass.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setName(const std::string& name);


  /**
   * Sets the value of the "num" attribute of this MyRequiredClass.
   *
   * @param num unsigned int value of the "num" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum(unsigned int num);


  /**
   * Sets the value of the "num2" attribute of this MyRequiredClass.
   *
   * @param num2 unsigned int value of the "num2" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum2(unsigned int num2);


  /**
   * Sets the value of the "num3" attribute of this MyRequiredClass.
   *
   * @param num3 int value of the "num3" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum3(int num3);


  /**
   * Sets the value of the "num1" attribute of this MyRequiredClass.
   *
   * @param num1 double value of the "num1" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum1(double num1);


  /**
   * Sets the value of the "true" attribute of this MyRequiredClass.
   *
   * @param true bool value of the "true" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTrue(bool true);


  /**
   * Sets the value of the "false" attribute of this MyRequiredClass.
   *
   * @param false bool value of the "false" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setFalse(bool false);


  /**
   * Sets the value of the "unit" attribute of this MyRequiredClass.
   *
   * @param unit std::string& value of the "unit" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUnit(const std::string& unit);


  /**
   * Sets the value of the "ref1" attribute of this MyRequiredClass.
   *
   * @param ref1 std::string& value of the "ref1" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRef1(const std::string& ref1);


  /**
   * Sets the value of the "ref2" attribute of this MyRequiredClass.
   *
   * @param ref2 std::string& value of the "ref2" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRef2(const std::string& ref2);


  /**
   * Sets the value of the "refUnit" attribute of this MyRequiredClass.
   *
   * @param refUnit std::string& value of the "refUnit" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRefUnit(const std::string& refUnit);


  /**
   * Sets the value of the "correctId" attribute of this MyRequiredClass.
   *
   * @param correctId std::string& value of the "correctId" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCorrectId(const std::string& correctId);


  /**
   * Sets the value of the "posint" attribute of this MyRequiredClass.
   *
   * @param posint unsigned int value of the "posint" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPosint(unsigned int posint);


  /**
   * Sets the value of the "posint2" attribute of this MyRequiredClass.
   *
   * @param posint2 unsigned int value of the "posint2" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPosint2(unsigned int posint2);


  /**
   * Sets the value of the "posint1" attribute of this MyRequiredClass.
   *
   * @param posint1 unsigned int value of the "posint1" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPosint1(unsigned int posint1);


  /**
   * Sets the value of the "metaid" attribute of this MyRequiredClass.
   *
   * @param metaid std::string& value of the "metaid" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMetaid(const std::string& metaid);


  /**
   * Sets the value of the "metaid1" attribute of this MyRequiredClass.
   *
   * @param metaid1 std::string& value of the "metaid1" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMetaid1(const std::string& metaid1);


  /**
   * Sets the value of the "num4" attribute of this MyRequiredClass.
   *
   * @param num4 int value of the "num4" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum4(int num4);


  /**
   * Sets the value of the "metaidref1" attribute of this MyRequiredClass.
   *
   * @param metaidref1 std::string& value of the "metaidref1" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMetaidref1(const std::string& metaidref1);


  /**
   * Unsets the value of the "id" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "name" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetName();


  /**
   * Unsets the value of the "num" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum();


  /**
   * Unsets the value of the "num2" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum2();


  /**
   * Unsets the value of the "num3" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum3();


  /**
   * Unsets the value of the "num1" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum1();


  /**
   * Unsets the value of the "true" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTrue();


  /**
   * Unsets the value of the "false" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetFalse();


  /**
   * Unsets the value of the "unit" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUnit();


  /**
   * Unsets the value of the "ref1" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRef1();


  /**
   * Unsets the value of the "ref2" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRef2();


  /**
   * Unsets the value of the "refUnit" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRefUnit();


  /**
   * Unsets the value of the "correctId" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCorrectId();


  /**
   * Unsets the value of the "posint" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPosint();


  /**
   * Unsets the value of the "posint2" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPosint2();


  /**
   * Unsets the value of the "posint1" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPosint1();


  /**
   * Unsets the value of the "metaid" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMetaid();


  /**
   * Unsets the value of the "metaid1" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMetaid1();


  /**
   * Unsets the value of the "num4" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum4();


  /**
   * Unsets the value of the "metaidref1" attribute of this MyRequiredClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMetaidref1();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML name of this MyRequiredClass object.
   *
   * @return the name of this element; that is "myRequiredClass".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML typcode of this MyRequiredClass object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{MY_TEST_TYPE, SBMLTestTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * MyRequiredClass object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * MyRequiredClass have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the MyRequiredClass object are:
   * @li "id"
   * @li "name"
   * @li "num"
   * @li "num2"
   * @li "num3"
   * @li "num1"
   * @li "true"
   * @li "false"
   * @li "unit"
   * @li "ref1"
   * @li "ref2"
   * @li "refUnit"
   * @li "correctId"
   * @li "posint"
   * @li "posint2"
   * @li "posint1"
   * @li "metaid"
   * @li "metaid1"
   * @li "num4"
   * @li "metaidref1"
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
 * Creates a new MyRequiredClass_t using the given SBML @p level, @ p version
 * and package version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * MyRequiredClass_t
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * MyRequiredClass_t
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * MyRequiredClass_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
MyRequiredClass_t *
MyRequiredClass_create(unsigned int level = TestExtension::getDefaultLevel(),
                       unsigned int version =
                         TestExtension::getDefaultVersion(),
                       unsigned int pkgVersion =
                         TestExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this MyRequiredClass_t object.
 *
 * @param mrc; the MyRequiredClass_t structure
 *
 * @return a (deep) copy of this MyRequiredClass_t object.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
MyRequiredClass_t*
MyRequiredClass_clone(const MyRequiredClass_t* mrc);


/**
 * Frees this MyRequiredClass_t object.
 *
 * @param mrc; the MyRequiredClass_t structure
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
void
MyRequiredClass_free(MyRequiredClass_t* mrc);


/**
 * Returns the value of the "id" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this MyRequiredClass_t as a
 * pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getId(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "name" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this MyRequiredClass_t as a
 * pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getName(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "num" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose num is sought.
 *
 * @return the value of the "num" attribute of this MyRequiredClass_t as a
 * unsigned integer.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getNum(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "num2" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose num2 is sought.
 *
 * @return the value of the "num2" attribute of this MyRequiredClass_t as a
 * unsigned integer.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getNum2(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "num3" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose num3 is sought.
 *
 * @return the value of the "num3" attribute of this MyRequiredClass_t as a
 * integer.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_getNum3(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "num1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose num1 is sought.
 *
 * @return the value of the "num1" attribute of this MyRequiredClass_t as a
 * double.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
double
MyRequiredClass_getNum1(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "true" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose true is sought.
 *
 * @return the value of the "true" attribute of this MyRequiredClass_t as a
 * boolean.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_getTrue(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "false" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose false is sought.
 *
 * @return the value of the "false" attribute of this MyRequiredClass_t as a
 * boolean.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_getFalse(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "unit" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose unit is sought.
 *
 * @return the value of the "unit" attribute of this MyRequiredClass_t as a
 * pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getUnit(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "ref1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose ref1 is sought.
 *
 * @return the value of the "ref1" attribute of this MyRequiredClass_t as a
 * pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getRef1(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "ref2" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose ref2 is sought.
 *
 * @return the value of the "ref2" attribute of this MyRequiredClass_t as a
 * pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getRef2(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "refUnit" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose refUnit is sought.
 *
 * @return the value of the "refUnit" attribute of this MyRequiredClass_t as a
 * pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getRefUnit(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "correctId" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose correctId is sought.
 *
 * @return the value of the "correctId" attribute of this MyRequiredClass_t as
 * a pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getCorrectId(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "posint" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose posint is sought.
 *
 * @return the value of the "posint" attribute of this MyRequiredClass_t as a
 * unsigned integer.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getPosint(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "posint2" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose posint2 is sought.
 *
 * @return the value of the "posint2" attribute of this MyRequiredClass_t as a
 * unsigned integer.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getPosint2(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "posint1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose posint1 is sought.
 *
 * @return the value of the "posint1" attribute of this MyRequiredClass_t as a
 * unsigned integer.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getPosint1(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "metaid" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose metaid is sought.
 *
 * @return the value of the "metaid" attribute of this MyRequiredClass_t as a
 * pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getMetaid(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "metaid1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose metaid1 is sought.
 *
 * @return the value of the "metaid1" attribute of this MyRequiredClass_t as a
 * pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getMetaid1(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "num4" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose num4 is sought.
 *
 * @return the value of the "num4" attribute of this MyRequiredClass_t as a
 * integer.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_getNum4(const MyRequiredClass_t * mrc);


/**
 * Returns the value of the "metaidref1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure whose metaidref1 is sought.
 *
 * @return the value of the "metaidref1" attribute of this MyRequiredClass_t as
 * a pointer to a string.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getMetaidref1(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "id" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "id" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetId(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "name" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "name" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetName(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "num" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num2" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "num2" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum2(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num3" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "num3" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum3(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num1" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "num1" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum1(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "true" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "true" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetTrue(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "false" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "false" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetFalse(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "unit" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "unit" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetUnit(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "ref1" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "ref1" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetRef1(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "ref2" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "ref2" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetRef2(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "refUnit" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "refUnit" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetRefUnit(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "correctId" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "correctId" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetCorrectId(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "posint" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "posint" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetPosint(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "posint2" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "posint2" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetPosint2(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "posint1" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "posint1" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetPosint1(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "metaid" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "metaid" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetMetaid(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "metaid1" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "metaid1" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetMetaid1(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num4" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "num4" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum4(const MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "metaidref1" attribute has been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 if this MyRequiredClass_t's "metaidref1" attribute has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetMetaidref1(const MyRequiredClass_t * mrc);


/**
 * Sets the value of the "id" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setId(MyRequiredClass_t * mrc, const char * id);


/**
 * Sets the value of the "name" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setName(MyRequiredClass_t * mrc, const char * name);


/**
 * Sets the value of the "num" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param num unsigned int value of the "num" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum(MyRequiredClass_t * mrc, unsigned int num);


/**
 * Sets the value of the "num2" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param num2 unsigned int value of the "num2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum2(MyRequiredClass_t * mrc, unsigned int num2);


/**
 * Sets the value of the "num3" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param num3 int value of the "num3" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum3(MyRequiredClass_t * mrc, int num3);


/**
 * Sets the value of the "num1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param num1 double value of the "num1" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum1(MyRequiredClass_t * mrc, double num1);


/**
 * Sets the value of the "true" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param true int value of the "true" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setTrue(MyRequiredClass_t * mrc, int true);


/**
 * Sets the value of the "false" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param false int value of the "false" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setFalse(MyRequiredClass_t * mrc, int false);


/**
 * Sets the value of the "unit" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param unit const char * value of the "unit" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setUnit(MyRequiredClass_t * mrc, const char * unit);


/**
 * Sets the value of the "ref1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param ref1 const char * value of the "ref1" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setRef1(MyRequiredClass_t * mrc, const char * ref1);


/**
 * Sets the value of the "ref2" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param ref2 const char * value of the "ref2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setRef2(MyRequiredClass_t * mrc, const char * ref2);


/**
 * Sets the value of the "refUnit" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param refUnit const char * value of the "refUnit" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setRefUnit(MyRequiredClass_t * mrc, const char * refUnit);


/**
 * Sets the value of the "correctId" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param correctId const char * value of the "correctId" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setCorrectId(MyRequiredClass_t * mrc, const char * correctId);


/**
 * Sets the value of the "posint" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param posint unsigned int value of the "posint" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setPosint(MyRequiredClass_t * mrc, unsigned int posint);


/**
 * Sets the value of the "posint2" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param posint2 unsigned int value of the "posint2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setPosint2(MyRequiredClass_t * mrc, unsigned int posint2);


/**
 * Sets the value of the "posint1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param posint1 unsigned int value of the "posint1" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setPosint1(MyRequiredClass_t * mrc, unsigned int posint1);


/**
 * Sets the value of the "metaid" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param metaid const char * value of the "metaid" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setMetaid(MyRequiredClass_t * mrc, const char * metaid);


/**
 * Sets the value of the "metaid1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param metaid1 const char * value of the "metaid1" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setMetaid1(MyRequiredClass_t * mrc, const char * metaid1);


/**
 * Sets the value of the "num4" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param num4 int value of the "num4" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum4(MyRequiredClass_t * mrc, int num4);


/**
 * Sets the value of the "metaidref1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @param metaidref1 const char * value of the "metaidref1" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_setMetaidref1(MyRequiredClass_t * mrc,
                              const char * metaidref1);


/**
 * Unsets the value of the "id" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetId(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "name" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetName(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "num" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "num2" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum2(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "num3" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum3(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "num1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum1(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "true" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetTrue(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "false" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetFalse(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "unit" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetUnit(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "ref1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetRef1(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "ref2" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetRef2(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "refUnit" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetRefUnit(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "correctId" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetCorrectId(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "posint" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetPosint(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "posint2" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetPosint2(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "posint1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetPosint1(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "metaid" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetMetaid(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "metaid1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetMetaid1(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "num4" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum4(MyRequiredClass_t * mrc);


/**
 * Unsets the value of the "metaidref1" attribute of this MyRequiredClass_t.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetMetaidref1(MyRequiredClass_t * mrc);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * MyRequiredClass_t object have been set.
 *
 * @param mrc the MyRequiredClass_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * MyRequiredClass_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the MyRequiredClass_t object are:
 * @li "id"
 * @li "name"
 * @li "num"
 * @li "num2"
 * @li "num3"
 * @li "num1"
 * @li "true"
 * @li "false"
 * @li "unit"
 * @li "ref1"
 * @li "ref2"
 * @li "refUnit"
 * @li "correctId"
 * @li "posint"
 * @li "posint2"
 * @li "posint1"
 * @li "metaid"
 * @li "metaid1"
 * @li "num4"
 * @li "metaidref1"
 *
 * @memberof MyRequiredClass_t
 */
LIBSBML_EXTERN
int
MyRequiredClass_hasRequiredAttributes(const MyRequiredClass_t * mrc);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !MyRequiredClass_H__ */


