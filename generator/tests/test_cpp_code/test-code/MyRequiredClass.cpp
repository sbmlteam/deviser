/**
 * @file MyRequiredClass.cpp
 * @brief Implementation of MyRequiredClass.
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
#include <sbml/packages/test/sbml/MyRequiredClass.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new MyRequiredClass using the given SBML @p level, @ p version and
 * package version values.
 */
MyRequiredClass::MyRequiredClass(unsigned int level,
                                 unsigned int version,
                                 unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mName ("")
  , mNum (SBML_INT_MAX)
  , mIsSetNum (false)
  , mNum2 (SBML_INT_MAX)
  , mIsSetNum2 (false)
  , mNum3 (SBML_INT_MAX)
  , mIsSetNum3 (false)
  , mNum1 (util_NaN())
  , mIsSetNum1 (false)
  , mTrue (false)
  , mIsSetTrue (false)
  , mFalse (false)
  , mIsSetFalse (false)
  , mUnit ("")
  , mRef1 ("")
  , mRef2 ("")
  , mRefUnit ("")
  , mCorrectId ("")
  , mPosint (SBML_INT_MAX)
  , mIsSetPosint (false)
  , mPosint2 (SBML_INT_MAX)
  , mIsSetPosint2 (false)
  , mPosint1 (SBML_INT_MAX)
  , mIsSetPosint1 (false)
  , mMetaid ("")
  , mMetaid1 ("")
  , mNum4 (SBML_INT_MAX)
  , mIsSetNum4 (false)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new MyRequiredClass using the given TestPkgNamespaces object.
 */
MyRequiredClass::MyRequiredClass(TestPkgNamespaces *testns)
  : SBase(testns)
  , mId ("")
  , mName ("")
  , mNum (SBML_INT_MAX)
  , mIsSetNum (false)
  , mNum2 (SBML_INT_MAX)
  , mIsSetNum2 (false)
  , mNum3 (SBML_INT_MAX)
  , mIsSetNum3 (false)
  , mNum1 (util_NaN())
  , mIsSetNum1 (false)
  , mTrue (false)
  , mIsSetTrue (false)
  , mFalse (false)
  , mIsSetFalse (false)
  , mUnit ("")
  , mRef1 ("")
  , mRef2 ("")
  , mRefUnit ("")
  , mCorrectId ("")
  , mPosint (SBML_INT_MAX)
  , mIsSetPosint (false)
  , mPosint2 (SBML_INT_MAX)
  , mIsSetPosint2 (false)
  , mPosint1 (SBML_INT_MAX)
  , mIsSetPosint1 (false)
  , mMetaid ("")
  , mMetaid1 ("")
  , mNum4 (SBML_INT_MAX)
  , mIsSetNum4 (false)
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for MyRequiredClass.
 */
MyRequiredClass::MyRequiredClass(const MyRequiredClass& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mName ( orig.mName )
  , mNum ( orig.mNum )
  , mIsSetNum ( orig.mIsSetNum )
  , mNum2 ( orig.mNum2 )
  , mIsSetNum2 ( orig.mIsSetNum2 )
  , mNum3 ( orig.mNum3 )
  , mIsSetNum3 ( orig.mIsSetNum3 )
  , mNum1 ( orig.mNum1 )
  , mIsSetNum1 ( orig.mIsSetNum1 )
  , mTrue ( orig.mTrue )
  , mIsSetTrue ( orig.mIsSetTrue )
  , mFalse ( orig.mFalse )
  , mIsSetFalse ( orig.mIsSetFalse )
  , mUnit ( orig.mUnit )
  , mRef1 ( orig.mRef1 )
  , mRef2 ( orig.mRef2 )
  , mRefUnit ( orig.mRefUnit )
  , mCorrectId ( orig.mCorrectId )
  , mPosint ( orig.mPosint )
  , mIsSetPosint ( orig.mIsSetPosint )
  , mPosint2 ( orig.mPosint2 )
  , mIsSetPosint2 ( orig.mIsSetPosint2 )
  , mPosint1 ( orig.mPosint1 )
  , mIsSetPosint1 ( orig.mIsSetPosint1 )
  , mMetaid ( orig.mMetaid )
  , mMetaid1 ( orig.mMetaid1 )
  , mNum4 ( orig.mNum4 )
  , mIsSetNum4 ( orig.mIsSetNum4 )
{
}


/*
 * Assignment operator for MyRequiredClass.
 */
MyRequiredClass&
MyRequiredClass::operator=(const MyRequiredClass& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mName = rhs.mName;
    mNum = rhs.mNum;
    mIsSetNum = rhs.mIsSetNum;
    mNum2 = rhs.mNum2;
    mIsSetNum2 = rhs.mIsSetNum2;
    mNum3 = rhs.mNum3;
    mIsSetNum3 = rhs.mIsSetNum3;
    mNum1 = rhs.mNum1;
    mIsSetNum1 = rhs.mIsSetNum1;
    mTrue = rhs.mTrue;
    mIsSetTrue = rhs.mIsSetTrue;
    mFalse = rhs.mFalse;
    mIsSetFalse = rhs.mIsSetFalse;
    mUnit = rhs.mUnit;
    mRef1 = rhs.mRef1;
    mRef2 = rhs.mRef2;
    mRefUnit = rhs.mRefUnit;
    mCorrectId = rhs.mCorrectId;
    mPosint = rhs.mPosint;
    mIsSetPosint = rhs.mIsSetPosint;
    mPosint2 = rhs.mPosint2;
    mIsSetPosint2 = rhs.mIsSetPosint2;
    mPosint1 = rhs.mPosint1;
    mIsSetPosint1 = rhs.mIsSetPosint1;
    mMetaid = rhs.mMetaid;
    mMetaid1 = rhs.mMetaid1;
    mNum4 = rhs.mNum4;
    mIsSetNum4 = rhs.mIsSetNum4;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this MyRequiredClass object.
 */
MyRequiredClass*
MyRequiredClass::clone() const
{
  return new MyRequiredClass(*this);
}


/*
 * Destructor for MyRequiredClass.
 */
MyRequiredClass::~MyRequiredClass()
{
}


/*
 * Returns the value of the "id" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getName() const
{
  return mName;
}


/*
 * Returns the value of the "num" attribute of this MyRequiredClass.
 */
unsigned int
MyRequiredClass::getNum() const
{
  return mNum;
}


/*
 * Returns the value of the "num2" attribute of this MyRequiredClass.
 */
unsigned int
MyRequiredClass::getNum2() const
{
  return mNum2;
}


/*
 * Returns the value of the "num3" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::getNum3() const
{
  return mNum3;
}


/*
 * Returns the value of the "num1" attribute of this MyRequiredClass.
 */
double
MyRequiredClass::getNum1() const
{
  return mNum1;
}


/*
 * Returns the value of the "true" attribute of this MyRequiredClass.
 */
bool
MyRequiredClass::getTrue() const
{
  return mTrue;
}


/*
 * Returns the value of the "false" attribute of this MyRequiredClass.
 */
bool
MyRequiredClass::getFalse() const
{
  return mFalse;
}


/*
 * Returns the value of the "unit" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getUnit() const
{
  return mUnit;
}


/*
 * Returns the value of the "ref1" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getRef1() const
{
  return mRef1;
}


/*
 * Returns the value of the "ref2" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getRef2() const
{
  return mRef2;
}


/*
 * Returns the value of the "refUnit" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getRefUnit() const
{
  return mRefUnit;
}


/*
 * Returns the value of the "correctId" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getCorrectId() const
{
  return mCorrectId;
}


/*
 * Returns the value of the "posint" attribute of this MyRequiredClass.
 */
unsigned int
MyRequiredClass::getPosint() const
{
  return mPosint;
}


/*
 * Returns the value of the "posint2" attribute of this MyRequiredClass.
 */
unsigned int
MyRequiredClass::getPosint2() const
{
  return mPosint2;
}


/*
 * Returns the value of the "posint1" attribute of this MyRequiredClass.
 */
unsigned int
MyRequiredClass::getPosint1() const
{
  return mPosint1;
}


/*
 * Returns the value of the "metaid" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getMetaid() const
{
  return mMetaid;
}


/*
 * Returns the value of the "metaid1" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getMetaid1() const
{
  return mMetaid1;
}


/*
 * Returns the value of the "num4" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::getNum4() const
{
  return mNum4;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "id" attribute has been set.
 */
bool
MyRequiredClass::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "name" attribute has been set.
 */
bool
MyRequiredClass::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "num" attribute has been set.
 */
bool
MyRequiredClass::isSetNum() const
{
  return mIsSetNum;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "num2" attribute has been set.
 */
bool
MyRequiredClass::isSetNum2() const
{
  return mIsSetNum2;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "num3" attribute has been set.
 */
bool
MyRequiredClass::isSetNum3() const
{
  return mIsSetNum3;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "num1" attribute has been set.
 */
bool
MyRequiredClass::isSetNum1() const
{
  return mIsSetNum1;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "true" attribute has been set.
 */
bool
MyRequiredClass::isSetTrue() const
{
  return mIsSetTrue;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "false" attribute has been set.
 */
bool
MyRequiredClass::isSetFalse() const
{
  return mIsSetFalse;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "unit" attribute has been set.
 */
bool
MyRequiredClass::isSetUnit() const
{
  return (mUnit.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "ref1" attribute has been set.
 */
bool
MyRequiredClass::isSetRef1() const
{
  return (mRef1.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "ref2" attribute has been set.
 */
bool
MyRequiredClass::isSetRef2() const
{
  return (mRef2.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "refUnit" attribute has been set.
 */
bool
MyRequiredClass::isSetRefUnit() const
{
  return (mRefUnit.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "correctId" attribute has been set.
 */
bool
MyRequiredClass::isSetCorrectId() const
{
  return (mCorrectId.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "posint" attribute has been set.
 */
bool
MyRequiredClass::isSetPosint() const
{
  return mIsSetPosint;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "posint2" attribute has been set.
 */
bool
MyRequiredClass::isSetPosint2() const
{
  return mIsSetPosint2;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "posint1" attribute has been set.
 */
bool
MyRequiredClass::isSetPosint1() const
{
  return mIsSetPosint1;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "metaid" attribute has been set.
 */
bool
MyRequiredClass::isSetMetaid() const
{
  return (mMetaid.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "metaid1" attribute has been set.
 */
bool
MyRequiredClass::isSetMetaid1() const
{
  return (mMetaid1.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MyRequiredClass's "num4" attribute has been set.
 */
bool
MyRequiredClass::isSetNum4() const
{
  return mIsSetNum4;
}


/*
 * Sets the value of the "id" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "name" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setName(const std::string& name)
{
  mName = name;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setNum(unsigned int num)
{
  mNum = num;
  mIsSetNum = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num2" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setNum2(unsigned int num2)
{
  mNum2 = num2;
  mIsSetNum2 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num3" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setNum3(int num3)
{
  mNum3 = num3;
  mIsSetNum3 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setNum1(double num1)
{
  mNum1 = num1;
  mIsSetNum1 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "true" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setTrue(bool true)
{
  mTrue = true;
  mIsSetTrue = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "false" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setFalse(bool false)
{
  mFalse = false;
  mIsSetFalse = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "unit" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setUnit(const std::string& unit)
{
  if (!(SyntaxChecker::isValidInternalUnitSId(unit)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mUnit = unit;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "ref1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setRef1(const std::string& ref1)
{
  if (!(SyntaxChecker::isValidInternalSId(ref1)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mRef1 = ref1;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "ref2" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setRef2(const std::string& ref2)
{
  if (!(SyntaxChecker::isValidInternalSId(ref2)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mRef2 = ref2;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "refUnit" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setRefUnit(const std::string& refUnit)
{
  if (!(SyntaxChecker::isValidInternalUnitSId(refUnit)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mRefUnit = refUnit;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "correctId" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setCorrectId(const std::string& correctId)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "posint" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setPosint(unsigned int posint)
{
  mPosint = posint;
  mIsSetPosint = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "posint2" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setPosint2(unsigned int posint2)
{
  mPosint2 = posint2;
  mIsSetPosint2 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "posint1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setPosint1(unsigned int posint1)
{
  mPosint1 = posint1;
  mIsSetPosint1 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "metaid" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setMetaid(const std::string& metaid)
{
  mMetaid = metaid;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "metaid1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setMetaid1(const std::string& metaid1)
{
  mMetaid1 = metaid1;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num4" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setNum4(int num4)
{
  mNum4 = num4;
  mIsSetNum4 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "name" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "num" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetNum()
{
  mNum = SBML_INT_MAX;
  mIsSetNum = false;

  if (isSetNum() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "num2" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetNum2()
{
  mNum2 = SBML_INT_MAX;
  mIsSetNum2 = false;

  if (isSetNum2() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "num3" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetNum3()
{
  mNum3 = SBML_INT_MAX;
  mIsSetNum3 = false;

  if (isSetNum3() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "num1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetNum1()
{
  mNum1 = util_NaN();
  mIsSetNum1 = false;

  if (isSetNum1() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "true" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetTrue()
{
  mTrue = false;
  mIsSetTrue = false;

  if (isSetTrue() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "false" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetFalse()
{
  mFalse = false;
  mIsSetFalse = false;

  if (isSetFalse() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "unit" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetUnit()
{
  mUnit.erase();

  if (mUnit.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "ref1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetRef1()
{
  mRef1.erase();

  if (mRef1.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "ref2" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetRef2()
{
  mRef2.erase();

  if (mRef2.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "refUnit" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetRefUnit()
{
  mRefUnit.erase();

  if (mRefUnit.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "correctId" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetCorrectId()
{
  mCorrectId.erase();

  if (mCorrectId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "posint" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetPosint()
{
  mPosint = SBML_INT_MAX;
  mIsSetPosint = false;

  if (isSetPosint() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "posint2" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetPosint2()
{
  mPosint2 = SBML_INT_MAX;
  mIsSetPosint2 = false;

  if (isSetPosint2() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "posint1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetPosint1()
{
  mPosint1 = SBML_INT_MAX;
  mIsSetPosint1 = false;

  if (isSetPosint1() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "metaid" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetMetaid()
{
  mMetaid.erase();

  if (mMetaid.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "metaid1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetMetaid1()
{
  mMetaid1.erase();

  if (mMetaid1.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "num4" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetNum4()
{
  mNum4 = SBML_INT_MAX;
  mIsSetNum4 = false;

  if (isSetNum4() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * @copydoc doc_renamesidref_common
 */
void
MyRequiredClass::renameSIdRefs(const std::string& oldid,
                               const std::string& newid)
{
  if (isSetRef1() && mRef1 == oldid)
  {
    setRef1(newid);
  }

  if (isSetRef2() && mRef2 == oldid)
  {
    setRef2(newid);
  }

  if (isSetRefUnit() && mRefUnit == oldid)
  {
    setRefUnit(newid);
  }
}


/*
 * Returns the XML name of this MyRequiredClass object.
 */
const std::string&
MyRequiredClass::getElementName() const
{
  static const string name = "myRequiredClass";
  return name;
}


/*
 * Returns the libSBML typcode of this MyRequiredClass object.
 */
int
MyRequiredClass::getTypeCode() const
{
  return MY_TEST_TYPE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * MyRequiredClass object have been set.
 */
bool
MyRequiredClass::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetName() == false)
  {
    allPresent = false;
  }

  if (isSetNum() == false)
  {
    allPresent = false;
  }

  if (isSetNum2() == false)
  {
    allPresent = false;
  }

  if (isSetNum3() == false)
  {
    allPresent = false;
  }

  if (isSetNum1() == false)
  {
    allPresent = false;
  }

  if (isSetTrue() == false)
  {
    allPresent = false;
  }

  if (isSetFalse() == false)
  {
    allPresent = false;
  }

  if (isSetUnit() == false)
  {
    allPresent = false;
  }

  if (isSetRef1() == false)
  {
    allPresent = false;
  }

  if (isSetRef2() == false)
  {
    allPresent = false;
  }

  if (isSetRefUnit() == false)
  {
    allPresent = false;
  }

  if (isSetCorrectId() == false)
  {
    allPresent = false;
  }

  if (isSetPosint() == false)
  {
    allPresent = false;
  }

  if (isSetPosint2() == false)
  {
    allPresent = false;
  }

  if (isSetPosint1() == false)
  {
    allPresent = false;
  }

  if (isSetMetaid() == false)
  {
    allPresent = false;
  }

  if (isSetMetaid1() == false)
  {
    allPresent = false;
  }

  if (isSetNum4() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
MyRequiredClass::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
MyRequiredClass::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
MyRequiredClass::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
MyRequiredClass::enablePackageInternal(const std::string& pkgURI,
                                       const std::string& pkgPrefix,
                                       bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
MyRequiredClass::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("name");

  attributes.add("num");

  attributes.add("num2");

  attributes.add("num3");

  attributes.add("num1");

  attributes.add("true");

  attributes.add("false");

  attributes.add("unit");

  attributes.add("ref1");

  attributes.add("ref2");

  attributes.add("refUnit");

  attributes.add("correctId");

  attributes.add("posint");

  attributes.add("posint2");

  attributes.add("posint1");

  attributes.add("metaid");

  attributes.add("metaid1");

  attributes.add("num4");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
MyRequiredClass::readAttributes(const XMLAttributes& attributes,
                                const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("test", TestMyRequiredClassAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(InvalidIdSyntax, level, version, "The id '" + mId + "' does not "
        "conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Test attribute 'id' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // name string (use = "required" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<MyRequiredClass>");
    }
  }
  else
  {
    std::string message = "Test attribute 'name' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // num uint (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum = attributes.readInto("num", mNum);

  if ( mIsSetNum == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'num' from the <MyRequiredClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyRequiredClassNumMustBeUnInteger,
        pkgVersion, level, version, message);
    }
    else
    {
      std::string message = "Test attribute 'num' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }

  // 
  // num2 uint (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum2 = attributes.readInto("num2", mNum2);

  if ( mIsSetNum2 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'num2' from the <MyRequiredClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyRequiredClassNum2MustBeUnInteger,
        pkgVersion, level, version, message);
    }
    else
    {
      std::string message = "Test attribute 'num2' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }

  // 
  // num3 int (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum3 = attributes.readInto("num3", mNum3);

  if ( mIsSetNum3 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'num3' from the <MyRequiredClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyRequiredClassNum3MustBeInteger,
        pkgVersion, level, version, message);
    }
    else
    {
      std::string message = "Test attribute 'num3' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }

  // 
  // num1 double (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum1 = attributes.readInto("num1", mNum1);

  if ( mIsSetNum1 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'num1' from the <MyRequiredClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyRequiredClassNum1MustBeDouble,
        pkgVersion, level, version, message);
    }
    else
    {
      std::string message = "Test attribute 'num1' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }

  // 
  // true bool (use = "required" )
  // 

  mIsSetTrue = attributes.readInto("true", mTrue);

  if (!mIsSetTrue)
  {
    std::string message = "Test attribute 'true' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // false bool (use = "required" )
  // 

  mIsSetFalse = attributes.readInto("false", mFalse);

  if (!mIsSetFalse)
  {
    std::string message = "Test attribute 'false' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // unit UnitSId (use = "required" )
  // 

  assigned = attributes.readInto("unit", mUnit);

  if (assigned == true)
  {
    if (mUnit.empty() == true)
    {
      logEmptyString(mUnit, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mUnit) == false)
    {
      logError(InvalidIdSyntax, level, version, "The attribute unit='" + mUnit
        + "' does not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Test attribute 'unit' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // ref1 SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("ref1", mRef1);

  if (assigned == true)
  {
    if (mRef1.empty() == true)
    {
      logEmptyString(mRef1, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mRef1) == false)
    {
      logError(InvalidIdSyntax, level, version, "The attribute ref1='" + mRef1
        + "' does not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Test attribute 'ref1' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // ref2 SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("ref2", mRef2);

  if (assigned == true)
  {
    if (mRef2.empty() == true)
    {
      logEmptyString(mRef2, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mRef2) == false)
    {
      logError(InvalidIdSyntax, level, version, "The attribute ref2='" + mRef2
        + "' does not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Test attribute 'ref2' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // refUnit UnitSIdRef (use = "required" )
  // 

  assigned = attributes.readInto("refUnit", mRefUnit);

  if (assigned == true)
  {
    if (mRefUnit.empty() == true)
    {
      logEmptyString(mRefUnit, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mRefUnit) == false)
    {
      logError(InvalidIdSyntax, level, version, "The attribute refUnit='" +
        mRefUnit + "' does not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Test attribute 'refUnit' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // correctId SId (use = "required" )
  // 

  assigned = attributes.readInto("correctId", mCorrectId);

  if (assigned == true)
  {
    if (mCorrectId.empty() == true)
    {
      logEmptyString(mCorrectId, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mCorrectId) == false)
    {
      logError(InvalidIdSyntax, level, version, "The id '" + mCorrectId + "' "
        "does not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Test attribute 'correctId' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // posint uint (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetPosint = attributes.readInto("posint", mPosint);

  if ( mIsSetPosint == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'posint' from the <MyRequiredClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyRequiredClassPosintMustBeUnInteger,
        pkgVersion, level, version, message);
    }
    else
    {
      std::string message = "Test attribute 'posint' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }

  // 
  // posint2 uint (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetPosint2 = attributes.readInto("posint2", mPosint2);

  if ( mIsSetPosint2 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'posint2' from the "
        "<MyRequiredClass> element must be an integer.";
      log->logPackageError("test", TestMyRequiredClassPosint2MustBeUnInteger,
        pkgVersion, level, version, message);
    }
    else
    {
      std::string message = "Test attribute 'posint2' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }

  // 
  // posint1 uint (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetPosint1 = attributes.readInto("posint1", mPosint1);

  if ( mIsSetPosint1 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'posint1' from the "
        "<MyRequiredClass> element must be an integer.";
      log->logPackageError("test", TestMyRequiredClassPosint1MustBeUnInteger,
        pkgVersion, level, version, message);
    }
    else
    {
      std::string message = "Test attribute 'posint1' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }

  // 
  // metaid string (use = "required" )
  // 

  assigned = attributes.readInto("metaid", mMetaid);

  if (assigned == true)
  {
    if (mMetaid.empty() == true)
    {
      logEmptyString(mMetaid, level, version, "<MyRequiredClass>");
    }
  }
  else
  {
    std::string message = "Test attribute 'metaid' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // metaid1 string (use = "required" )
  // 

  assigned = attributes.readInto("metaid1", mMetaid1);

  if (assigned == true)
  {
    if (mMetaid1.empty() == true)
    {
      logEmptyString(mMetaid1, level, version, "<MyRequiredClass>");
    }
  }
  else
  {
    std::string message = "Test attribute 'metaid1' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // num4 int (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum4 = attributes.readInto("num4", mNum4);

  if ( mIsSetNum4 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'num4' from the <MyRequiredClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyRequiredClassNum4MustBeInteger,
        pkgVersion, level, version, message);
    }
    else
    {
      std::string message = "Test attribute 'num4' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
MyRequiredClass::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }

  if (isSetNum() == true)
  {
    stream.writeAttribute("num", getPrefix(), mNum);
  }

  if (isSetNum2() == true)
  {
    stream.writeAttribute("num2", getPrefix(), mNum2);
  }

  if (isSetNum3() == true)
  {
    stream.writeAttribute("num3", getPrefix(), mNum3);
  }

  if (isSetNum1() == true)
  {
    stream.writeAttribute("num1", getPrefix(), mNum1);
  }

  if (isSetTrue() == true)
  {
    stream.writeAttribute("true", getPrefix(), mTrue);
  }

  if (isSetFalse() == true)
  {
    stream.writeAttribute("false", getPrefix(), mFalse);
  }

  if (isSetUnit() == true)
  {
    stream.writeAttribute("unit", getPrefix(), mUnit);
  }

  if (isSetRef1() == true)
  {
    stream.writeAttribute("ref1", getPrefix(), mRef1);
  }

  if (isSetRef2() == true)
  {
    stream.writeAttribute("ref2", getPrefix(), mRef2);
  }

  if (isSetRefUnit() == true)
  {
    stream.writeAttribute("refUnit", getPrefix(), mRefUnit);
  }

  if (isSetCorrectId() == true)
  {
    stream.writeAttribute("correctId", getPrefix(), mCorrectId);
  }

  if (isSetPosint() == true)
  {
    stream.writeAttribute("posint", getPrefix(), mPosint);
  }

  if (isSetPosint2() == true)
  {
    stream.writeAttribute("posint2", getPrefix(), mPosint2);
  }

  if (isSetPosint1() == true)
  {
    stream.writeAttribute("posint1", getPrefix(), mPosint1);
  }

  if (isSetMetaid() == true)
  {
    stream.writeAttribute("metaid", getPrefix(), mMetaid);
  }

  if (isSetMetaid1() == true)
  {
    stream.writeAttribute("metaid1", getPrefix(), mMetaid1);
  }

  if (isSetNum4() == true)
  {
    stream.writeAttribute("num4", getPrefix(), mNum4);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new MyRequiredClass_t using the given SBML @p level, @ p version
 * and package version values.
 */
LIBSBML_EXTERN
MyRequiredClass_t *
MyRequiredClass_create(unsigned int level,
                       unsigned int version,
                       unsigned int pkgVersion)
{
  return new MyRequiredClass(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this MyRequiredClass_t object.
 */
LIBSBML_EXTERN
MyRequiredClass_t*
MyRequiredClass_clone(const MyRequiredClass_t* mrc)
{
  if (mrc != NULL)
  {
    return static_cast<MyRequiredClass_t*>(mrc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this MyRequiredClass_t object.
 */
LIBSBML_EXTERN
void
MyRequiredClass_free(MyRequiredClass_t* mrc)
{
  if (mrc != NULL)
  {
    delete mrc;
  }
}


/*
 * Returns the value of the "id" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getId(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getId().empty() ? NULL : safe_strdup(mrc->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getName(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getName().empty() ? NULL : safe_strdup(mrc->getName().c_str());
}


/*
 * Returns the value of the "num" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getNum(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->getNum() : SBML_INT_MAX;
}


/*
 * Returns the value of the "num2" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getNum2(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->getNum2() : SBML_INT_MAX;
}


/*
 * Returns the value of the "num3" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_getNum3(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->getNum3() : SBML_INT_MAX;
}


/*
 * Returns the value of the "num1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
double
MyRequiredClass_getNum1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->getNum1() : util_NaN();
}


/*
 * Returns the value of the "true" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_getTrue(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->getTrue()) : 0;
}


/*
 * Returns the value of the "false" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_getFalse(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->getFalse()) : 0;
}


/*
 * Returns the value of the "unit" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getUnit(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getUnit().empty() ? NULL : safe_strdup(mrc->getUnit().c_str());
}


/*
 * Returns the value of the "ref1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getRef1(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getRef1().empty() ? NULL : safe_strdup(mrc->getRef1().c_str());
}


/*
 * Returns the value of the "ref2" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getRef2(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getRef2().empty() ? NULL : safe_strdup(mrc->getRef2().c_str());
}


/*
 * Returns the value of the "refUnit" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getRefUnit(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getRefUnit().empty() ? NULL :
    safe_strdup(mrc->getRefUnit().c_str());
}


/*
 * Returns the value of the "correctId" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getCorrectId(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getCorrectId().empty() ? NULL :
    safe_strdup(mrc->getCorrectId().c_str());
}


/*
 * Returns the value of the "posint" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getPosint(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->getPosint() : SBML_INT_MAX;
}


/*
 * Returns the value of the "posint2" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getPosint2(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->getPosint2() : SBML_INT_MAX;
}


/*
 * Returns the value of the "posint1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
unsigned int
MyRequiredClass_getPosint1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->getPosint1() : SBML_INT_MAX;
}


/*
 * Returns the value of the "metaid" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getMetaid(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getMetaid().empty() ? NULL :
    safe_strdup(mrc->getMetaid().c_str());
}


/*
 * Returns the value of the "metaid1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getMetaid1(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getMetaid1().empty() ? NULL :
    safe_strdup(mrc->getMetaid1().c_str());
}


/*
 * Returns the value of the "num4" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_getNum4(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->getNum4() : SBML_INT_MAX;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "id" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetId(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "name" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetName(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num2" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum2(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum2()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num3" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum3(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum3()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num1" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum1()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "true" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetTrue(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetTrue()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "false" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetFalse(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetFalse()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "unit" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetUnit(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetUnit()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "ref1" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetRef1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetRef1()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "ref2" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetRef2(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetRef2()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "refUnit" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetRefUnit(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetRefUnit()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "correctId" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetCorrectId(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetCorrectId()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "posint" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetPosint(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetPosint()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "posint2" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetPosint2(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetPosint2()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "posint1" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetPosint1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetPosint1()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "metaid" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetMetaid(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetMetaid()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "metaid1" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetMetaid1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetMetaid1()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * MyRequiredClass_t's "num4" attribute has been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum4(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum4()) : 0;
}


/*
 * Sets the value of the "id" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setId(MyRequiredClass_t * mrc, const char * id)
{
  return (mrc != NULL) ? mrc->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setName(MyRequiredClass_t * mrc, const char * name)
{
  return (mrc != NULL) ? mrc->setName(name) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum(MyRequiredClass_t * mrc, unsigned int num)
{
  return (mrc != NULL) ? mrc->setNum(num) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num2" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum2(MyRequiredClass_t * mrc, unsigned int num2)
{
  return (mrc != NULL) ? mrc->setNum2(num2) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num3" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum3(MyRequiredClass_t * mrc, int num3)
{
  return (mrc != NULL) ? mrc->setNum3(num3) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum1(MyRequiredClass_t * mrc, double num1)
{
  return (mrc != NULL) ? mrc->setNum1(num1) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "true" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setTrue(MyRequiredClass_t * mrc, int true)
{
  return (mrc != NULL) ? mrc->setTrue(true) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "false" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setFalse(MyRequiredClass_t * mrc, int false)
{
  return (mrc != NULL) ? mrc->setFalse(false) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "unit" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setUnit(MyRequiredClass_t * mrc, const char * unit)
{
  return (mrc != NULL) ? mrc->setUnit(unit) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "ref1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setRef1(MyRequiredClass_t * mrc, const char * ref1)
{
  return (mrc != NULL) ? mrc->setRef1(ref1) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "ref2" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setRef2(MyRequiredClass_t * mrc, const char * ref2)
{
  return (mrc != NULL) ? mrc->setRef2(ref2) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "refUnit" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setRefUnit(MyRequiredClass_t * mrc, const char * refUnit)
{
  return (mrc != NULL) ? mrc->setRefUnit(refUnit) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "correctId" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setCorrectId(MyRequiredClass_t * mrc, const char * correctId)
{
  return (mrc != NULL) ? mrc->setCorrectId(correctId) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "posint" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setPosint(MyRequiredClass_t * mrc, unsigned int posint)
{
  return (mrc != NULL) ? mrc->setPosint(posint) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "posint2" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setPosint2(MyRequiredClass_t * mrc, unsigned int posint2)
{
  return (mrc != NULL) ? mrc->setPosint2(posint2) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "posint1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setPosint1(MyRequiredClass_t * mrc, unsigned int posint1)
{
  return (mrc != NULL) ? mrc->setPosint1(posint1) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "metaid" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setMetaid(MyRequiredClass_t * mrc, const char * metaid)
{
  return (mrc != NULL) ? mrc->setMetaid(metaid) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "metaid1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setMetaid1(MyRequiredClass_t * mrc, const char * metaid1)
{
  return (mrc != NULL) ? mrc->setMetaid1(metaid1) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num4" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNum4(MyRequiredClass_t * mrc, int num4)
{
  return (mrc != NULL) ? mrc->setNum4(num4) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetId(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetName(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetNum() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num2" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum2(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetNum2() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num3" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum3(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetNum3() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum1(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetNum1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "true" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetTrue(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetTrue() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "false" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetFalse(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetFalse() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "unit" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetUnit(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetUnit() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "ref1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetRef1(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetRef1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "ref2" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetRef2(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetRef2() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "refUnit" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetRefUnit(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetRefUnit() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "correctId" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetCorrectId(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetCorrectId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "posint" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetPosint(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetPosint() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "posint2" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetPosint2(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetPosint2() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "posint1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetPosint1(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetPosint1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "metaid" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetMetaid(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetMetaid() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "metaid1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetMetaid1(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetMetaid1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num4" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNum4(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetNum4() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * MyRequiredClass_t object have been set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_hasRequiredAttributes(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


