/**
 * @file MyRequiredClass.cpp
 * @brief Implementation of the MyRequiredClass class.
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
 */
#include <sbml/packages/test/sbml/MyRequiredClass.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new MyRequiredClass using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
MyRequiredClass::MyRequiredClass(unsigned int level,
                                 unsigned int version,
                                 unsigned int pkgVersion)
  : SBase(level, version)
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
  , mMetaidref1 ("")
  , mNotmetaid ("")
  , mVectorDouble ()
  , mVectorDouble1 ()
  , mVectorInt ()
  , mVectorInt1 ()
  , mArrayD (NULL)
  , mArrayInt (NULL)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new MyRequiredClass using the given TestPkgNamespaces object.
 */
MyRequiredClass::MyRequiredClass(TestPkgNamespaces *testns)
  : SBase(testns)
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
  , mMetaidref1 ("")
  , mNotmetaid ("")
  , mVectorDouble ()
  , mVectorDouble1 ()
  , mVectorInt ()
  , mVectorInt1 ()
  , mArrayD (NULL)
  , mArrayInt (NULL)
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for MyRequiredClass.
 */
MyRequiredClass::MyRequiredClass(const MyRequiredClass& orig)
  : SBase( orig )
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
  , mMetaidref1 ( orig.mMetaidref1 )
  , mNotmetaid ( orig.mNotmetaid )
  , mVectorDouble ( orig.mVectorDouble )
  , mVectorDouble1 ( orig.mVectorDouble1 )
  , mVectorInt ( orig.mVectorInt )
  , mVectorInt1 ( orig.mVectorInt1 )
  , mArrayD ( NULL )
  , mArrayInt ( NULL )
{
  setArrayD(orig.mArrayD, orig.mArrayDLength);

  setArrayInt(orig.mArrayInt, orig.mArrayIntLength);

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
    mMetaidref1 = rhs.mMetaidref1;
    mNotmetaid = rhs.mNotmetaid;
    mVectorDouble = rhs.mVectorDouble;
    mVectorDouble1 = rhs.mVectorDouble1;
    mVectorInt = rhs.mVectorInt;
    mVectorInt1 = rhs.mVectorInt1;
    mArrayD = NULL;
    setArrayD(rhs.mArrayD, rhs.mArrayDLength);
    mArrayInt = NULL;
    setArrayInt(rhs.mArrayInt, rhs.mArrayIntLength);
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
  if (mArrayD != NULL)
  {
    delete [] mArrayD;
  }

  mArrayD = NULL;

  if (mArrayInt != NULL)
  {
    delete [] mArrayInt;
  }

  mArrayInt = NULL;
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
 * Returns the value of the "metaidref1" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getMetaidref1() const
{
  return mMetaidref1;
}


/*
 * Returns the value of the "notmetaid" attribute of this MyRequiredClass.
 */
const std::string&
MyRequiredClass::getNotmetaid() const
{
  return mNotmetaid;
}


/*
 * Returns the value of the "vectorDouble" attribute of this MyRequiredClass.
 */
const std::vector<double>&
MyRequiredClass::getVectorDouble() const
{
  return mVectorDouble;
}


/*
 * Returns the value of the "vectorDouble1" attribute of this MyRequiredClass.
 */
const std::vector<double>&
MyRequiredClass::getVectorDouble1() const
{
  return mVectorDouble1;
}


/*
 * Returns the value of the "vectorInt" attribute of this MyRequiredClass.
 */
const std::vector<int>&
MyRequiredClass::getVectorInt() const
{
  return mVectorInt;
}


/*
 * Returns the value of the "vectorInt1" attribute of this MyRequiredClass.
 */
const std::vector<int>&
MyRequiredClass::getVectorInt1() const
{
  return mVectorInt1;
}


/*
 * Returns the value of the "arrayD" attribute of this MyRequiredClass.
 */
void
MyRequiredClass::getArrayD(double* outArray) const
{
  if (outArray == NULL || mArrayD == NULL)
  {
    return;
  }

  memcpy(outArray, mArrayD, sizeof(double)*mArrayDLength);
}


/*
 * Returns the value of the "arrayInt" attribute of this MyRequiredClass.
 */
void
MyRequiredClass::getArrayInt(int* outArray) const
{
  if (outArray == NULL || mArrayInt == NULL)
  {
    return;
  }

  memcpy(outArray, mArrayInt, sizeof(int)*mArrayIntLength);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "id" attribute is set.
 */
bool
MyRequiredClass::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "name" attribute is
 * set.
 */
bool
MyRequiredClass::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "num" attribute is
 * set.
 */
bool
MyRequiredClass::isSetNum() const
{
  return mIsSetNum;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "num2" attribute is
 * set.
 */
bool
MyRequiredClass::isSetNum2() const
{
  return mIsSetNum2;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "num3" attribute is
 * set.
 */
bool
MyRequiredClass::isSetNum3() const
{
  return mIsSetNum3;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "num1" attribute is
 * set.
 */
bool
MyRequiredClass::isSetNum1() const
{
  return mIsSetNum1;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "true" attribute is
 * set.
 */
bool
MyRequiredClass::isSetTrue() const
{
  return mIsSetTrue;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "false" attribute is
 * set.
 */
bool
MyRequiredClass::isSetFalse() const
{
  return mIsSetFalse;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "unit" attribute is
 * set.
 */
bool
MyRequiredClass::isSetUnit() const
{
  return (mUnit.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "ref1" attribute is
 * set.
 */
bool
MyRequiredClass::isSetRef1() const
{
  return (mRef1.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "ref2" attribute is
 * set.
 */
bool
MyRequiredClass::isSetRef2() const
{
  return (mRef2.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "refUnit" attribute is
 * set.
 */
bool
MyRequiredClass::isSetRefUnit() const
{
  return (mRefUnit.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "correctId" attribute
 * is set.
 */
bool
MyRequiredClass::isSetCorrectId() const
{
  return (mCorrectId.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "posint" attribute is
 * set.
 */
bool
MyRequiredClass::isSetPosint() const
{
  return mIsSetPosint;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "posint2" attribute is
 * set.
 */
bool
MyRequiredClass::isSetPosint2() const
{
  return mIsSetPosint2;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "posint1" attribute is
 * set.
 */
bool
MyRequiredClass::isSetPosint1() const
{
  return mIsSetPosint1;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "metaid" attribute is
 * set.
 */
bool
MyRequiredClass::isSetMetaid() const
{
  return (mMetaid.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "metaid1" attribute is
 * set.
 */
bool
MyRequiredClass::isSetMetaid1() const
{
  return (mMetaid1.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "num4" attribute is
 * set.
 */
bool
MyRequiredClass::isSetNum4() const
{
  return mIsSetNum4;
}


/*
 * Predicate returning @c true if this MyRequiredClass's "metaidref1" attribute
 * is set.
 */
bool
MyRequiredClass::isSetMetaidref1() const
{
  return (mMetaidref1.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "notmetaid" attribute
 * is set.
 */
bool
MyRequiredClass::isSetNotmetaid() const
{
  return (mNotmetaid.empty() == false);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "vectorDouble"
 * attribute is set.
 */
bool
MyRequiredClass::hasVectorDoubles() const
{
  return mVectorDouble.size() > 0;
}


/*
 * Return the number of elements in this MyRequiredClass's "vectorDouble"
 * attribute.
 */
unsigned int
MyRequiredClass::getNumVectorDoubles() const
{
  return (unsigned int)(mVectorDouble.size());
}


/*
 * Predicate returning @c true if this MyRequiredClass's "vectorDouble1"
 * attribute is set.
 */
bool
MyRequiredClass::hasVectorDouble1s() const
{
  return mVectorDouble1.size() > 0;
}


/*
 * Return the number of elements in this MyRequiredClass's "vectorDouble1"
 * attribute.
 */
unsigned int
MyRequiredClass::getNumVectorDouble1s() const
{
  return (unsigned int)(mVectorDouble1.size());
}


/*
 * Predicate returning @c true if this MyRequiredClass's "vectorInt" attribute
 * is set.
 */
bool
MyRequiredClass::hasVectorInts() const
{
  return mVectorInt.size() > 0;
}


/*
 * Return the number of elements in this MyRequiredClass's "vectorInt"
 * attribute.
 */
unsigned int
MyRequiredClass::getNumVectorInts() const
{
  return (unsigned int)(mVectorInt.size());
}


/*
 * Predicate returning @c true if this MyRequiredClass's "vectorInt1" attribute
 * is set.
 */
bool
MyRequiredClass::hasVectorInt1s() const
{
  return mVectorInt1.size() > 0;
}


/*
 * Return the number of elements in this MyRequiredClass's "vectorInt1"
 * attribute.
 */
unsigned int
MyRequiredClass::getNumVectorInt1s() const
{
  return (unsigned int)(mVectorInt1.size());
}


/*
 * Predicate returning @c true if this MyRequiredClass's "arrayD" attribute is
 * set.
 */
bool
MyRequiredClass::isSetArrayD() const
{
  return (mArrayD != NULL);
}


/*
 * Predicate returning @c true if this MyRequiredClass's "arrayInt" attribute
 * is set.
 */
bool
MyRequiredClass::isSetArrayInt() const
{
  return (mArrayInt != NULL);
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
 * Sets the value of the "metaidref1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setMetaidref1(const std::string& metaidref1)
{
  mMetaidref1 = metaidref1;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "notmetaid" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setNotmetaid(const std::string& notmetaid)
{
  mNotmetaid = notmetaid;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "vectorDouble" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setVectorDouble(const std::vector<double>& vectorDouble)
{
  mVectorDouble = vectorDouble;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Adds another value to the "vectorDouble" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::addVectorDouble(double vectorDouble)
{
  mVectorDouble.push_back(vectorDouble);
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "vectorDouble1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setVectorDouble1(const std::vector<double>& vectorDouble1)
{
  mVectorDouble1 = vectorDouble1;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Adds another value to the "vectorDouble1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::addVectorDouble1(double vectorDouble1)
{
  mVectorDouble1.push_back(vectorDouble1);
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "vectorInt" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setVectorInt(const std::vector<int>& vectorInt)
{
  mVectorInt = vectorInt;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Adds another value to the "vectorInt" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::addVectorInt(int vectorInt)
{
  mVectorInt.push_back(vectorInt);
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "vectorInt1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setVectorInt1(const std::vector<int>& vectorInt1)
{
  mVectorInt1 = vectorInt1;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Adds another value to the "vectorInt1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::addVectorInt1(int vectorInt1)
{
  mVectorInt1.push_back(vectorInt1);
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "arrayD" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setArrayD(double* inArray, int arrayLength)
{
  if (inArray == NULL)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }

  if (mArrayD != NULL)
  {
    delete[] mArrayD;
  }

  mArrayD = new double[arrayLength];
  memcpy(mArrayD, inArray, sizeof(double)*arrayLength);
  mIsSetArrayDLength = true;
  mArrayDLength = arrayLength;

  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "arrayInt" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setArrayInt(int* inArray, int arrayLength)
{
  if (inArray == NULL)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }

  if (mArrayInt != NULL)
  {
    delete[] mArrayInt;
  }

  mArrayInt = new int[arrayLength];
  memcpy(mArrayInt, inArray, sizeof(int)*arrayLength);
  mIsSetArrayIntLength = true;
  mArrayIntLength = arrayLength;

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
 * Unsets the value of the "metaidref1" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetMetaidref1()
{
  mMetaidref1.erase();

  if (mMetaidref1.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "notmetaid" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetNotmetaid()
{
  mNotmetaid.erase();

  if (mNotmetaid.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Clears the "vectorDouble" element of this MyRequiredClass.
 */
int
MyRequiredClass::clearVectorDoubles()
{
  mVectorDouble.clear();
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Clears the "vectorDouble1" element of this MyRequiredClass.
 */
int
MyRequiredClass::clearVectorDouble1s()
{
  mVectorDouble1.clear();
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Clears the "vectorInt" element of this MyRequiredClass.
 */
int
MyRequiredClass::clearVectorInts()
{
  mVectorInt.clear();
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Clears the "vectorInt1" element of this MyRequiredClass.
 */
int
MyRequiredClass::clearVectorInt1s()
{
  mVectorInt1.clear();
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "arrayD" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetArrayD()
{
  if (mArrayD != NULL)
  {
    delete[] mArrayD;
  }

  mArrayD = NULL;

  return unsetArrayDLength();
}


/*
 * Unsets the value of the "arrayInt" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetArrayInt()
{
  if (mArrayInt != NULL)
  {
    delete[] mArrayInt;
  }

  mArrayInt = NULL;

  return unsetArrayIntLength();
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
 * Returns the XML element name of this MyRequiredClass object.
 */
const std::string&
MyRequiredClass::getElementName() const
{
  static const string name = "myRequiredClass";
  return name;
}


/*
 * Returns the libSBML type code for this MyRequiredClass object.
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

  if (isSetMetaidref1() == false)
  {
    allPresent = false;
  }

  if (isSetNotmetaid() == false)
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

  if (hasVectorDoubles())
  {
    for (std::vector<double>::const_iterator it = mVectorDouble.begin(); it !=
      mVectorDouble.end(); ++it)
    {
      stream.startElement("vectorDouble");
      stream.setAutoIndent(false);
      stream << " " << *it << " ";
      stream.endElement("vectorDouble");
      stream.setAutoIndent(true);
    }
  }

  if (hasVectorDouble1s())
  {
    for (std::vector<double>::const_iterator it = mVectorDouble1.begin(); it !=
      mVectorDouble1.end(); ++it)
    {
      stream.startElement("vectorDouble1");
      stream.setAutoIndent(false);
      stream << " " << *it << " ";
      stream.endElement("vectorDouble1");
      stream.setAutoIndent(true);
    }
  }

  if (hasVectorInts())
  {
    for (std::vector<int>::const_iterator it = mVectorInt.begin(); it !=
      mVectorInt.end(); ++it)
    {
      stream.startElement("vectorInt");
      stream.setAutoIndent(false);
      stream << " " << *it << " ";
      stream.endElement("vectorInt");
      stream.setAutoIndent(true);
    }
  }

  if (hasVectorInt1s())
  {
    for (std::vector<int>::const_iterator it = mVectorInt1.begin(); it !=
      mVectorInt1.end(); ++it)
    {
      stream.startElement("vectorInt1");
      stream.setAutoIndent(false);
      stream << " " << *it << " ";
      stream.endElement("vectorInt1");
      stream.setAutoIndent(true);
    }
  }
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
 * used to write arrays
 */
void
MyRequiredClass::write(XMLOutputStream& stream) const
{
  stream.startElement(getElementName(), getPrefix());
  writeAttributes(stream);

  if (isSetArrayInt())
  {
    for (int i = 0; i < mArrayIntLength; ++i)
    {
      stream << (long)mArrayInt[i] << " ";
    }
  }

  stream.endElement(getElementName(), getPrefix());
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
 * Gets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::getAttribute(const std::string& attributeName,
                              bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "true")
  {
    value = getTrue();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "false")
  {
    value = getFalse();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::getAttribute(const std::string& attributeName,
                              int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "num3")
  {
    value = getNum3();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "num4")
  {
    value = getNum4();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::getAttribute(const std::string& attributeName,
                              double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "num1")
  {
    value = getNum1();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::getAttribute(const std::string& attributeName,
                              unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "num")
  {
    value = getNum();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "num2")
  {
    value = getNum2();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "posint")
  {
    value = getPosint();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "posint2")
  {
    value = getPosint2();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "posint1")
  {
    value = getPosint1();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::getAttribute(const std::string& attributeName,
                              std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "name")
  {
    value = getName();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "unit")
  {
    value = getUnit();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "ref1")
  {
    value = getRef1();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "ref2")
  {
    value = getRef2();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "refUnit")
  {
    value = getRefUnit();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "correctId")
  {
    value = getCorrectId();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "metaid")
  {
    value = getMetaid();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "metaid1")
  {
    value = getMetaid1();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "metaidref1")
  {
    value = getMetaidref1();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "notmetaid")
  {
    value = getNotmetaid();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::getAttribute(const std::string& attributeName,
                              const char* value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "name")
  {
    value = getName().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "unit")
  {
    value = getUnit().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "ref1")
  {
    value = getRef1().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "ref2")
  {
    value = getRef2().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "refUnit")
  {
    value = getRefUnit().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "correctId")
  {
    value = getCorrectId().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "metaid")
  {
    value = getMetaid().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "metaid1")
  {
    value = getMetaid1().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "metaidref1")
  {
    value = getMetaidref1().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "notmetaid")
  {
    value = getNotmetaid().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this MyRequiredClass's attribute
 * "attributeName" is set.
 */
bool
MyRequiredClass::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "name")
  {
    value = isSetName();
  }
  else if (attributeName == "num")
  {
    value = isSetNum();
  }
  else if (attributeName == "num2")
  {
    value = isSetNum2();
  }
  else if (attributeName == "num3")
  {
    value = isSetNum3();
  }
  else if (attributeName == "num1")
  {
    value = isSetNum1();
  }
  else if (attributeName == "true")
  {
    value = isSetTrue();
  }
  else if (attributeName == "false")
  {
    value = isSetFalse();
  }
  else if (attributeName == "unit")
  {
    value = isSetUnit();
  }
  else if (attributeName == "ref1")
  {
    value = isSetRef1();
  }
  else if (attributeName == "ref2")
  {
    value = isSetRef2();
  }
  else if (attributeName == "refUnit")
  {
    value = isSetRefUnit();
  }
  else if (attributeName == "correctId")
  {
    value = isSetCorrectId();
  }
  else if (attributeName == "posint")
  {
    value = isSetPosint();
  }
  else if (attributeName == "posint2")
  {
    value = isSetPosint2();
  }
  else if (attributeName == "posint1")
  {
    value = isSetPosint1();
  }
  else if (attributeName == "metaid")
  {
    value = isSetMetaid();
  }
  else if (attributeName == "metaid1")
  {
    value = isSetMetaid1();
  }
  else if (attributeName == "num4")
  {
    value = isSetNum4();
  }
  else if (attributeName == "metaidref1")
  {
    value = isSetMetaidref1();
  }
  else if (attributeName == "notmetaid")
  {
    value = isSetNotmetaid();
  }
  else if (attributeName == "vectorDouble")
  {
    value = isSetVectorDouble();
  }
  else if (attributeName == "vectorDouble1")
  {
    value = isSetVectorDouble1();
  }
  else if (attributeName == "vectorInt")
  {
    value = isSetVectorInt();
  }
  else if (attributeName == "vectorInt1")
  {
    value = isSetVectorInt1();
  }
  else if (attributeName == "arrayD")
  {
    value = isSetArrayD();
  }
  else if (attributeName == "arrayInt")
  {
    value = isSetArrayInt();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "true")
  {
    return_value = setTrue(value);
  }
  else if (attributeName == "false")
  {
    return_value = setFalse(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "num3")
  {
    return_value = setNum3(value);
  }
  else if (attributeName == "num4")
  {
    return_value = setNum4(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "num1")
  {
    return_value = setNum1(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setAttribute(const std::string& attributeName,
                              unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "num")
  {
    return_value = setNum(value);
  }
  else if (attributeName == "num2")
  {
    return_value = setNum2(value);
  }
  else if (attributeName == "posint")
  {
    return_value = setPosint(value);
  }
  else if (attributeName == "posint2")
  {
    return_value = setPosint2(value);
  }
  else if (attributeName == "posint1")
  {
    return_value = setPosint1(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setAttribute(const std::string& attributeName,
                              const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "name")
  {
    return_value = setName(value);
  }
  else if (attributeName == "unit")
  {
    return_value = setUnit(value);
  }
  else if (attributeName == "ref1")
  {
    return_value = setRef1(value);
  }
  else if (attributeName == "ref2")
  {
    return_value = setRef2(value);
  }
  else if (attributeName == "refUnit")
  {
    return_value = setRefUnit(value);
  }
  else if (attributeName == "correctId")
  {
    return_value = setCorrectId(value);
  }
  else if (attributeName == "metaid")
  {
    return_value = setMetaid(value);
  }
  else if (attributeName == "metaid1")
  {
    return_value = setMetaid1(value);
  }
  else if (attributeName == "metaidref1")
  {
    return_value = setMetaidref1(value);
  }
  else if (attributeName == "notmetaid")
  {
    return_value = setNotmetaid(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::setAttribute(const std::string& attributeName,
                              const char* value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "name")
  {
    return_value = setName(value);
  }
  else if (attributeName == "unit")
  {
    return_value = setUnit(value);
  }
  else if (attributeName == "ref1")
  {
    return_value = setRef1(value);
  }
  else if (attributeName == "ref2")
  {
    return_value = setRef2(value);
  }
  else if (attributeName == "refUnit")
  {
    return_value = setRefUnit(value);
  }
  else if (attributeName == "correctId")
  {
    return_value = setCorrectId(value);
  }
  else if (attributeName == "metaid")
  {
    return_value = setMetaid(value);
  }
  else if (attributeName == "metaid1")
  {
    return_value = setMetaid1(value);
  }
  else if (attributeName == "metaidref1")
  {
    return_value = setMetaidref1(value);
  }
  else if (attributeName == "notmetaid")
  {
    return_value = setNotmetaid(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this MyRequiredClass.
 */
int
MyRequiredClass::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "name")
  {
    value = unsetName();
  }
  else if (attributeName == "num")
  {
    value = unsetNum();
  }
  else if (attributeName == "num2")
  {
    value = unsetNum2();
  }
  else if (attributeName == "num3")
  {
    value = unsetNum3();
  }
  else if (attributeName == "num1")
  {
    value = unsetNum1();
  }
  else if (attributeName == "true")
  {
    value = unsetTrue();
  }
  else if (attributeName == "false")
  {
    value = unsetFalse();
  }
  else if (attributeName == "unit")
  {
    value = unsetUnit();
  }
  else if (attributeName == "ref1")
  {
    value = unsetRef1();
  }
  else if (attributeName == "ref2")
  {
    value = unsetRef2();
  }
  else if (attributeName == "refUnit")
  {
    value = unsetRefUnit();
  }
  else if (attributeName == "correctId")
  {
    value = unsetCorrectId();
  }
  else if (attributeName == "posint")
  {
    value = unsetPosint();
  }
  else if (attributeName == "posint2")
  {
    value = unsetPosint2();
  }
  else if (attributeName == "posint1")
  {
    value = unsetPosint1();
  }
  else if (attributeName == "metaid")
  {
    value = unsetMetaid();
  }
  else if (attributeName == "metaid1")
  {
    value = unsetMetaid1();
  }
  else if (attributeName == "num4")
  {
    value = unsetNum4();
  }
  else if (attributeName == "metaidref1")
  {
    value = unsetMetaidref1();
  }
  else if (attributeName == "notmetaid")
  {
    value = unsetNotmetaid();
  }
  else if (attributeName == "vectorDouble")
  {
    value = clearVectorDouble();
  }
  else if (attributeName == "vectorDouble1")
  {
    value = clearVectorDouble1();
  }
  else if (attributeName == "vectorInt")
  {
    value = clearVectorInt();
  }
  else if (attributeName == "vectorInt1")
  {
    value = clearVectorInt1();
  }
  else if (attributeName == "arrayD")
  {
    value = unsetArrayD();
  }
  else if (attributeName == "arrayInt")
  {
    value = unsetArrayInt();
  }

  return value;
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

  attributes.add("metaidref1");

  attributes.add("notmetaid");

  attributes.add("vectorDouble");

  attributes.add("vectorDouble1");

  attributes.add("vectorInt");

  attributes.add("vectorInt1");
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
      log->logPackageError("test", TestIdSyntaxRule, pkgVersion, level,
        version, "The id on the <" + getElementName() + "> is '" + mId + "',which "
          "does not conform to the syntax.", getLine(), getColumn());
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
      log->logPackageError("test",
        TestMyRequiredClassNumMustBeNonNegativeInteger, pkgVersion, level,
          version, message);
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
      log->logPackageError("test",
        TestMyRequiredClassNum2MustBeNonNegativeInteger, pkgVersion, level,
          version, message);
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

  numErrs = log->getNumErrors();
  mIsSetTrue = attributes.readInto("true", mTrue);

  if (mIsSetTrue == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("test", TestMyRequiredClassTrueMustBeBoolean,
        pkgVersion, level, version);
    }
    else
    {
      std::string message = "Test attribute 'true' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }

  // 
  // false bool (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetFalse = attributes.readInto("false", mFalse);

  if (mIsSetFalse == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("test", TestMyRequiredClassFalseMustBeBoolean,
        pkgVersion, level, version);
    }
    else
    {
      std::string message = "Test attribute 'false' is missing from the "
        "<MyRequiredClass> element.";
      log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
        pkgVersion, level, version, message);
    }
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
      log->logPackageError("test", TestMyRequiredClassUnitMustBeUnitSId,
        pkgVersion, level, version, "The attribute unit='" + mUnit + "' does not "
          "conform to the syntax.", getLine(), getColumn());
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
      log->logPackageError("test", TestMyRequiredClassRef1MustBeThing1,
        pkgVersion, level, version, "The attribute ref1='" + mRef1 + "' does not "
          "conform to the syntax.", getLine(), getColumn());
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
      log->logPackageError("test", TestMyRequiredClassRef2MustBeThing2,
        pkgVersion, level, version, "The attribute ref2='" + mRef2 + "' does not "
          "conform to the syntax.", getLine(), getColumn());
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
      log->logPackageError("test", TestMyRequiredClassRefUnitMustBeUnitSId,
        pkgVersion, level, version, "The attribute refUnit='" + mRefUnit + "' "
          "does not conform to the syntax.", getLine(), getColumn());
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
      log->logPackageError("test", TestIdSyntaxRule, pkgVersion, level,
        version, "The id on the <" + getElementName() + "> is '" + mCorrectId +
          "',which does not conform to the syntax.", getLine(), getColumn());
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
      log->logPackageError("test",
        TestMyRequiredClassPosintMustBeNonNegativeInteger, pkgVersion, level,
          version, message);
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
      log->logPackageError("test",
        TestMyRequiredClassPosint2MustBeNonNegativeInteger, pkgVersion, level,
          version, message);
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
      log->logPackageError("test",
        TestMyRequiredClassPosint1MustBeNonNegativeInteger, pkgVersion, level,
          version, message);
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
  // metaid ID (use = "required" )
  // 

  assigned = attributes.readInto("metaid", mMetaid);

  if (assigned == true)
  {
    if (mMetaid.empty() == true)
    {
      logEmptyString(mMetaid, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidXMLID(mMetaid) == false)
    {
      log->logPackageError("test", TestMyRequiredClassMetaidMustBeID,
        pkgVersion, level, version, "The attribute metaid='" + mMetaid + "' does "
          "not conform to the syntax.", getLine(), getColumn());
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
  // metaid1 ID (use = "required" )
  // 

  assigned = attributes.readInto("metaid1", mMetaid1);

  if (assigned == true)
  {
    if (mMetaid1.empty() == true)
    {
      logEmptyString(mMetaid1, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidXMLID(mMetaid1) == false)
    {
      log->logPackageError("test", TestMyRequiredClassMetaid1MustBeID,
        pkgVersion, level, version, "The attribute metaid1='" + mMetaid1 + "' "
          "does not conform to the syntax.", getLine(), getColumn());
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

  // 
  // metaidref1 IDREF (use = "required" )
  // 

  assigned = attributes.readInto("metaidref1", mMetaidref1);

  if (assigned == true)
  {
    if (mMetaidref1.empty() == true)
    {
      logEmptyString(mMetaidref1, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidXMLID(mMetaidref1) == false)
    {
      log->logPackageError("test", TestMyRequiredClassMetaidref1MustBeID,
        pkgVersion, level, version, "The attribute metaidref1='" + mMetaidref1 +
          "' does not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Test attribute 'metaidref1' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // notmetaid ID (use = "required" )
  // 

  assigned = attributes.readInto("notmetaid", mNotmetaid);

  if (assigned == true)
  {
    if (mNotmetaid.empty() == true)
    {
      logEmptyString(mNotmetaid, level, version, "<MyRequiredClass>");
    }
    else if (SyntaxChecker::isValidXMLID(mNotmetaid) == false)
    {
      log->logPackageError("test", TestMyRequiredClassNotmetaidMustBeID,
        pkgVersion, level, version, "The attribute notmetaid='" + mNotmetaid + "' "
          "does not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Test attribute 'notmetaid' is missing from the "
      "<MyRequiredClass> element.";
    log->logPackageError("test", TestMyRequiredClassAllowedAttributes,
      pkgVersion, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
MyRequiredClass::readOtherXML(XMLInputStream& stream)
{
  bool read = false;

  while (stream.peek().getName() == "vectorDouble")
  {
    stream.next();
    stringstream text;
    while (stream.isGood() && stream.peek().isText())
    {
      text << stream.next().getCharacters();
    }

    double value;
    text >> value;
    if (!text.fail())
    {
      mVectorDouble.push_back(value);
    }

    stream.next();
    read = true;
  }

  while (stream.peek().getName() == "vectorDouble1")
  {
    stream.next();
    stringstream text;
    while (stream.isGood() && stream.peek().isText())
    {
      text << stream.next().getCharacters();
    }

    double value;
    text >> value;
    if (!text.fail())
    {
      mVectorDouble1.push_back(value);
    }

    stream.next();
    read = true;
  }

  while (stream.peek().getName() == "vectorInt")
  {
    stream.next();
    stringstream text;
    while (stream.isGood() && stream.peek().isText())
    {
      text << stream.next().getCharacters();
    }

    int value;
    text >> value;
    if (!text.fail())
    {
      mVectorInt.push_back(value);
    }

    stream.next();
    read = true;
  }

  while (stream.peek().getName() == "vectorInt1")
  {
    stream.next();
    stringstream text;
    while (stream.isGood() && stream.peek().isText())
    {
      text << stream.next().getCharacters();
    }

    int value;
    text >> value;
    if (!text.fail())
    {
      mVectorInt1.push_back(value);
    }

    stream.next();
    read = true;
  }

  if (SBase::readOtherXML(stream))
  {
    read = true;
  }

  return read;
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

  if (isSetMetaidref1() == true)
  {
    stream.writeAttribute("metaidref1", getPrefix(), mMetaidref1);
  }

  if (isSetNotmetaid() == true)
  {
    stream.writeAttribute("notmetaid", getPrefix(), mNotmetaid);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the array data as a text element
 */
void
MyRequiredClass::setElementText(const std::string& text)
{
  stringstream strStream(text);
  int val;
  vector<int> valuesVector;

  while (strStream >> val)
  {
    valuesVector.push_back(val);
  }

  unsigned int length = (unsigned int)valuesVector.size();

  if (length > 0)
  {
    int* data = new int[length];
    for (unsigned int i = 0; i < length; ++i)
    {
      data[i] = valuesVector.at(i);
    }

    setArrayInt(data, length);
    delete[] data;
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new MyRequiredClass_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
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
 * Returns the value of the "metaidref1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getMetaidref1(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getMetaidref1().empty() ? NULL :
    safe_strdup(mrc->getMetaidref1().c_str());
}


/*
 * Returns the value of the "notmetaid" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
const char *
MyRequiredClass_getNotmetaid(const MyRequiredClass_t * mrc)
{
  if (mrc == NULL)
  {
    return NULL;
  }

  return mrc->getNotmetaid().empty() ? NULL :
    safe_strdup(mrc->getNotmetaid().c_str());
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetId(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "name" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetName(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "num" attribute is set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "num2" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum2(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum2()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "num3" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum3(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum3()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "num1" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum1()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "true" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetTrue(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetTrue()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "false" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetFalse(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetFalse()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "unit" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetUnit(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetUnit()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "ref1" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetRef1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetRef1()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "ref2" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetRef2(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetRef2()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "refUnit" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetRefUnit(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetRefUnit()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "correctId" attribute
 * is set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetCorrectId(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetCorrectId()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "posint" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetPosint(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetPosint()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "posint2" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetPosint2(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetPosint2()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "posint1" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetPosint1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetPosint1()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "metaid" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetMetaid(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetMetaid()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "metaid1" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetMetaid1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetMetaid1()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "num4" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNum4(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNum4()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "metaidref1" attribute
 * is set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetMetaidref1(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetMetaidref1()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "notmetaid" attribute
 * is set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetNotmetaid(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetNotmetaid()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "arrayD" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetArrayD(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetArrayD()) : 0;
}


/*
 * Predicate returning @c 1 if this MyRequiredClass_t's "arrayInt" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyRequiredClass_isSetArrayInt(const MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? static_cast<int>(mrc->isSetArrayInt()) : 0;
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
 * Sets the value of the "metaidref1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setMetaidref1(MyRequiredClass_t * mrc,
                              const char * metaidref1)
{
  return (mrc != NULL) ? mrc->setMetaidref1(metaidref1) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "notmetaid" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setNotmetaid(MyRequiredClass_t * mrc, const char * notmetaid)
{
  return (mrc != NULL) ? mrc->setNotmetaid(notmetaid) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "arrayD" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setArrayD(MyRequiredClass_t* mrc,
                          double* arrayD,
                          int arrayLength)
{
  return (mrc != NULL) ? mrc->setArrayD(arrayD, arrayLength) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "arrayInt" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_setArrayInt(MyRequiredClass_t* mrc,
                            int* arrayInt,
                            int arrayLength)
{
  return (mrc != NULL) ? mrc->setArrayInt(arrayInt, arrayLength) :
    LIBSBML_INVALID_OBJECT;
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
 * Unsets the value of the "metaidref1" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetMetaidref1(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetMetaidref1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "notmetaid" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetNotmetaid(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetNotmetaid() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "arrayD" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetArrayD(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetArrayD() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "arrayInt" attribute of this MyRequiredClass_t.
 */
LIBSBML_EXTERN
int
MyRequiredClass_unsetArrayInt(MyRequiredClass_t * mrc)
{
  return (mrc != NULL) ? mrc->unsetArrayInt() : LIBSBML_INVALID_OBJECT;
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


