/**
 * @file MyTestClass.cpp
 * @brief Implementation of the MyTestClass class.
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
#include <sbml/packages/test/sbml/MyTestClass.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new MyTestClass using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
MyTestClass::MyTestClass(unsigned int level,
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
  , mIdRef ("")
  , mIdref1 ("")
  , mIdref2 ("")
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new MyTestClass using the given TestPkgNamespaces object.
 */
MyTestClass::MyTestClass(TestPkgNamespaces *testns)
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
  , mIdRef ("")
  , mIdref1 ("")
  , mIdref2 ("")
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for MyTestClass.
 */
MyTestClass::MyTestClass(const MyTestClass& orig)
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
  , mIdRef ( orig.mIdRef )
  , mIdref1 ( orig.mIdref1 )
  , mIdref2 ( orig.mIdref2 )
{
}


/*
 * Assignment operator for MyTestClass.
 */
MyTestClass&
MyTestClass::operator=(const MyTestClass& rhs)
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
    mIdRef = rhs.mIdRef;
    mIdref1 = rhs.mIdref1;
    mIdref2 = rhs.mIdref2;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this MyTestClass object.
 */
MyTestClass*
MyTestClass::clone() const
{
  return new MyTestClass(*this);
}


/*
 * Destructor for MyTestClass.
 */
MyTestClass::~MyTestClass()
{
}


/*
 * Returns the value of the "id" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getName() const
{
  return mName;
}


/*
 * Returns the value of the "num" attribute of this MyTestClass.
 */
unsigned int
MyTestClass::getNum() const
{
  return mNum;
}


/*
 * Returns the value of the "num2" attribute of this MyTestClass.
 */
unsigned int
MyTestClass::getNum2() const
{
  return mNum2;
}


/*
 * Returns the value of the "num3" attribute of this MyTestClass.
 */
int
MyTestClass::getNum3() const
{
  return mNum3;
}


/*
 * Returns the value of the "num1" attribute of this MyTestClass.
 */
double
MyTestClass::getNum1() const
{
  return mNum1;
}


/*
 * Returns the value of the "true" attribute of this MyTestClass.
 */
bool
MyTestClass::getTrue() const
{
  return mTrue;
}


/*
 * Returns the value of the "false" attribute of this MyTestClass.
 */
bool
MyTestClass::getFalse() const
{
  return mFalse;
}


/*
 * Returns the value of the "unit" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getUnit() const
{
  return mUnit;
}


/*
 * Returns the value of the "ref1" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getRef1() const
{
  return mRef1;
}


/*
 * Returns the value of the "ref2" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getRef2() const
{
  return mRef2;
}


/*
 * Returns the value of the "refUnit" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getRefUnit() const
{
  return mRefUnit;
}


/*
 * Returns the value of the "correctId" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getCorrectId() const
{
  return mCorrectId;
}


/*
 * Returns the value of the "idRef" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getIdRef() const
{
  return mIdRef;
}


/*
 * Returns the value of the "idref1" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getIdref1() const
{
  return mIdref1;
}


/*
 * Returns the value of the "idref2" attribute of this MyTestClass.
 */
const std::string&
MyTestClass::getIdref2() const
{
  return mIdref2;
}


/*
 * Predicate returning @c true if this MyTestClass's "id" attribute is set.
 */
bool
MyTestClass::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this MyTestClass's "name" attribute is set.
 */
bool
MyTestClass::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Predicate returning @c true if this MyTestClass's "num" attribute is set.
 */
bool
MyTestClass::isSetNum() const
{
  return mIsSetNum;
}


/*
 * Predicate returning @c true if this MyTestClass's "num2" attribute is set.
 */
bool
MyTestClass::isSetNum2() const
{
  return mIsSetNum2;
}


/*
 * Predicate returning @c true if this MyTestClass's "num3" attribute is set.
 */
bool
MyTestClass::isSetNum3() const
{
  return mIsSetNum3;
}


/*
 * Predicate returning @c true if this MyTestClass's "num1" attribute is set.
 */
bool
MyTestClass::isSetNum1() const
{
  return mIsSetNum1;
}


/*
 * Predicate returning @c true if this MyTestClass's "true" attribute is set.
 */
bool
MyTestClass::isSetTrue() const
{
  return mIsSetTrue;
}


/*
 * Predicate returning @c true if this MyTestClass's "false" attribute is set.
 */
bool
MyTestClass::isSetFalse() const
{
  return mIsSetFalse;
}


/*
 * Predicate returning @c true if this MyTestClass's "unit" attribute is set.
 */
bool
MyTestClass::isSetUnit() const
{
  return (mUnit.empty() == false);
}


/*
 * Predicate returning @c true if this MyTestClass's "ref1" attribute is set.
 */
bool
MyTestClass::isSetRef1() const
{
  return (mRef1.empty() == false);
}


/*
 * Predicate returning @c true if this MyTestClass's "ref2" attribute is set.
 */
bool
MyTestClass::isSetRef2() const
{
  return (mRef2.empty() == false);
}


/*
 * Predicate returning @c true if this MyTestClass's "refUnit" attribute is
 * set.
 */
bool
MyTestClass::isSetRefUnit() const
{
  return (mRefUnit.empty() == false);
}


/*
 * Predicate returning @c true if this MyTestClass's "correctId" attribute is
 * set.
 */
bool
MyTestClass::isSetCorrectId() const
{
  return (mCorrectId.empty() == false);
}


/*
 * Predicate returning @c true if this MyTestClass's "idRef" attribute is set.
 */
bool
MyTestClass::isSetIdRef() const
{
  return (mIdRef.empty() == false);
}


/*
 * Predicate returning @c true if this MyTestClass's "idref1" attribute is set.
 */
bool
MyTestClass::isSetIdref1() const
{
  return (mIdref1.empty() == false);
}


/*
 * Predicate returning @c true if this MyTestClass's "idref2" attribute is set.
 */
bool
MyTestClass::isSetIdref2() const
{
  return (mIdref2.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this MyTestClass.
 */
int
MyTestClass::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "name" attribute of this MyTestClass.
 */
int
MyTestClass::setName(const std::string& name)
{
  mName = name;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num" attribute of this MyTestClass.
 */
int
MyTestClass::setNum(unsigned int num)
{
  mNum = num;
  mIsSetNum = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num2" attribute of this MyTestClass.
 */
int
MyTestClass::setNum2(unsigned int num2)
{
  mNum2 = num2;
  mIsSetNum2 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num3" attribute of this MyTestClass.
 */
int
MyTestClass::setNum3(int num3)
{
  mNum3 = num3;
  mIsSetNum3 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num1" attribute of this MyTestClass.
 */
int
MyTestClass::setNum1(double num1)
{
  mNum1 = num1;
  mIsSetNum1 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "true" attribute of this MyTestClass.
 */
int
MyTestClass::setTrue(bool true)
{
  mTrue = true;
  mIsSetTrue = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "false" attribute of this MyTestClass.
 */
int
MyTestClass::setFalse(bool false)
{
  mFalse = false;
  mIsSetFalse = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "unit" attribute of this MyTestClass.
 */
int
MyTestClass::setUnit(const std::string& unit)
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
 * Sets the value of the "ref1" attribute of this MyTestClass.
 */
int
MyTestClass::setRef1(const std::string& ref1)
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
 * Sets the value of the "ref2" attribute of this MyTestClass.
 */
int
MyTestClass::setRef2(const std::string& ref2)
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
 * Sets the value of the "refUnit" attribute of this MyTestClass.
 */
int
MyTestClass::setRefUnit(const std::string& refUnit)
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
 * Sets the value of the "correctId" attribute of this MyTestClass.
 */
int
MyTestClass::setCorrectId(const std::string& correctId)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "idRef" attribute of this MyTestClass.
 */
int
MyTestClass::setIdRef(const std::string& idRef)
{
  mIdRef = idRef;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "idref1" attribute of this MyTestClass.
 */
int
MyTestClass::setIdref1(const std::string& idref1)
{
  mIdref1 = idref1;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "idref2" attribute of this MyTestClass.
 */
int
MyTestClass::setIdref2(const std::string& idref2)
{
  mIdref2 = idref2;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this MyTestClass.
 */
int
MyTestClass::unsetId()
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
 * Unsets the value of the "name" attribute of this MyTestClass.
 */
int
MyTestClass::unsetName()
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
 * Unsets the value of the "num" attribute of this MyTestClass.
 */
int
MyTestClass::unsetNum()
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
 * Unsets the value of the "num2" attribute of this MyTestClass.
 */
int
MyTestClass::unsetNum2()
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
 * Unsets the value of the "num3" attribute of this MyTestClass.
 */
int
MyTestClass::unsetNum3()
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
 * Unsets the value of the "num1" attribute of this MyTestClass.
 */
int
MyTestClass::unsetNum1()
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
 * Unsets the value of the "true" attribute of this MyTestClass.
 */
int
MyTestClass::unsetTrue()
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
 * Unsets the value of the "false" attribute of this MyTestClass.
 */
int
MyTestClass::unsetFalse()
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
 * Unsets the value of the "unit" attribute of this MyTestClass.
 */
int
MyTestClass::unsetUnit()
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
 * Unsets the value of the "ref1" attribute of this MyTestClass.
 */
int
MyTestClass::unsetRef1()
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
 * Unsets the value of the "ref2" attribute of this MyTestClass.
 */
int
MyTestClass::unsetRef2()
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
 * Unsets the value of the "refUnit" attribute of this MyTestClass.
 */
int
MyTestClass::unsetRefUnit()
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
 * Unsets the value of the "correctId" attribute of this MyTestClass.
 */
int
MyTestClass::unsetCorrectId()
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
 * Unsets the value of the "idRef" attribute of this MyTestClass.
 */
int
MyTestClass::unsetIdRef()
{
  mIdRef.erase();

  if (mIdRef.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "idref1" attribute of this MyTestClass.
 */
int
MyTestClass::unsetIdref1()
{
  mIdref1.erase();

  if (mIdref1.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "idref2" attribute of this MyTestClass.
 */
int
MyTestClass::unsetIdref2()
{
  mIdref2.erase();

  if (mIdref2.empty() == true)
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
MyTestClass::renameSIdRefs(const std::string& oldid, const std::string& newid)
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
 * Returns the XML element name of this MyTestClass object.
 */
const std::string&
MyTestClass::getElementName() const
{
  static const string name = "myTestClass";
  return name;
}


/*
 * Returns the libSBML type code for this MyTestClass object.
 */
int
MyTestClass::getTypeCode() const
{
  return MY_TEST_TYPE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * MyTestClass object have been set.
 */
bool
MyTestClass::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
MyTestClass::writeElements(XMLOutputStream& stream) const
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
MyTestClass::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
MyTestClass::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
MyTestClass::enablePackageInternal(const std::string& pkgURI,
                                   const std::string& pkgPrefix,
                                   bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::getAttribute(const std::string& attributeName, bool& value) const
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
 * Gets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::getAttribute(const std::string& attributeName, int& value) const
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

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::getAttribute(const std::string& attributeName,
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
 * Gets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::getAttribute(const std::string& attributeName,
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

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "idRef")
  {
    value = getIdRef();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "idref1")
  {
    value = getIdref1();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "idref2")
  {
    value = getIdref2();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "idRef")
  {
    value = getIdRef().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "idref1")
  {
    value = getIdref1().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "idref2")
  {
    value = getIdref2().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this MyTestClass's attribute "attributeName"
 * is set.
 */
bool
MyTestClass::isSetAttribute(const std::string& attributeName) const
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
  else if (attributeName == "idRef")
  {
    value = isSetIdRef();
  }
  else if (attributeName == "idref1")
  {
    value = isSetIdref1();
  }
  else if (attributeName == "idref2")
  {
    value = isSetIdref2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::setAttribute(const std::string& attributeName, bool value)
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
 * Sets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "num3")
  {
    return_value = setNum3(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::setAttribute(const std::string& attributeName, double value)
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
 * Sets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::setAttribute(const std::string& attributeName,
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

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::setAttribute(const std::string& attributeName,
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
  else if (attributeName == "idRef")
  {
    return_value = setIdRef(value);
  }
  else if (attributeName == "idref1")
  {
    return_value = setIdref1(value);
  }
  else if (attributeName == "idref2")
  {
    return_value = setIdref2(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::setAttribute(const std::string& attributeName, const char* value)
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
  else if (attributeName == "idRef")
  {
    return_value = setIdRef(value);
  }
  else if (attributeName == "idref1")
  {
    return_value = setIdref1(value);
  }
  else if (attributeName == "idref2")
  {
    return_value = setIdref2(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this MyTestClass.
 */
int
MyTestClass::unsetAttribute(const std::string& attributeName)
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
  else if (attributeName == "idRef")
  {
    value = unsetIdRef();
  }
  else if (attributeName == "idref1")
  {
    value = unsetIdref1();
  }
  else if (attributeName == "idref2")
  {
    value = unsetIdref2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
MyTestClass::addExpectedAttributes(ExpectedAttributes& attributes)
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

  attributes.add("idRef");

  attributes.add("idref1");

  attributes.add("idref2");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
MyTestClass::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("test", TestMyTestClassAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("test", TestMyTestClassAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  // 
  // id SId (use = "optional" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<MyTestClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("test", TestIdSyntaxRule, pkgVersion, level,
        version, "The id on the <" + getElementName() + "> is '" + mId + "',which "
          "does not conform to the syntax.", getLine(), getColumn());
    }
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<MyTestClass>");
    }
  }

  // 
  // num uint (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum = attributes.readInto("num", mNum);

  if ( mIsSetNum == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'num' from the <MyTestClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyTestClassNumMustBeNonNegativeInteger,
        pkgVersion, level, version, message);
    }
  }

  // 
  // num2 uint (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum2 = attributes.readInto("num2", mNum2);

  if ( mIsSetNum2 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'num2' from the <MyTestClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyTestClassNum2MustBeNonNegativeInteger,
        pkgVersion, level, version, message);
    }
  }

  // 
  // num3 int (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum3 = attributes.readInto("num3", mNum3);

  if ( mIsSetNum3 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'num3' from the <MyTestClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyTestClassNum3MustBeInteger,
        pkgVersion, level, version, message);
    }
  }

  // 
  // num1 double (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum1 = attributes.readInto("num1", mNum1);

  if ( mIsSetNum1 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Test attribute 'num1' from the <MyTestClass> "
        "element must be an integer.";
      log->logPackageError("test", TestMyTestClassNum1MustBeDouble, pkgVersion,
        level, version, message);
    }
  }

  // 
  // true bool (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetTrue = attributes.readInto("true", mTrue);

  if (mIsSetTrue == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("test", TestMyTestClassTrueMustBeBoolean,
        pkgVersion, level, version);
    }
  }

  // 
  // false bool (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetFalse = attributes.readInto("false", mFalse);

  if (mIsSetFalse == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("test", TestMyTestClassFalseMustBeBoolean,
        pkgVersion, level, version);
    }
  }

  // 
  // unit UnitSId (use = "optional" )
  // 

  assigned = attributes.readInto("unit", mUnit);

  if (assigned == true)
  {
    if (mUnit.empty() == true)
    {
      logEmptyString(mUnit, level, version, "<MyTestClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mUnit) == false)
    {
      log->logPackageError("test", TestMyTestClassUnitMustBeUnitSId,
        pkgVersion, level, version, "The attribute unit='" + mUnit + "' does not "
          "conform to the syntax.", getLine(), getColumn());
    }
  }

  // 
  // ref1 SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("ref1", mRef1);

  if (assigned == true)
  {
    if (mRef1.empty() == true)
    {
      logEmptyString(mRef1, level, version, "<MyTestClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mRef1) == false)
    {
      log->logPackageError("test", TestMyTestClassRef1MustBeThing1, pkgVersion,
        level, version, "The attribute ref1='" + mRef1 + "' does not conform to "
          "the syntax.", getLine(), getColumn());
    }
  }

  // 
  // ref2 SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("ref2", mRef2);

  if (assigned == true)
  {
    if (mRef2.empty() == true)
    {
      logEmptyString(mRef2, level, version, "<MyTestClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mRef2) == false)
    {
      log->logPackageError("test", TestMyTestClassRef2MustBeThing2, pkgVersion,
        level, version, "The attribute ref2='" + mRef2 + "' does not conform to "
          "the syntax.", getLine(), getColumn());
    }
  }

  // 
  // refUnit UnitSIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("refUnit", mRefUnit);

  if (assigned == true)
  {
    if (mRefUnit.empty() == true)
    {
      logEmptyString(mRefUnit, level, version, "<MyTestClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mRefUnit) == false)
    {
      log->logPackageError("test", TestMyTestClassRefUnitMustBeUnitSId,
        pkgVersion, level, version, "The attribute refUnit='" + mRefUnit + "' "
          "does not conform to the syntax.", getLine(), getColumn());
    }
  }

  // 
  // correctId SId (use = "optional" )
  // 

  assigned = attributes.readInto("correctId", mCorrectId);

  if (assigned == true)
  {
    if (mCorrectId.empty() == true)
    {
      logEmptyString(mCorrectId, level, version, "<MyTestClass>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mCorrectId) == false)
    {
      log->logPackageError("test", TestIdSyntaxRule, pkgVersion, level,
        version, "The id on the <" + getElementName() + "> is '" + mCorrectId +
          "',which does not conform to the syntax.", getLine(), getColumn());
    }
  }

  // 
  // idRef IDREF (use = "optional" )
  // 

  assigned = attributes.readInto("idRef", mIdRef);

  if (assigned == true)
  {
    if (mIdRef.empty() == true)
    {
      logEmptyString(mIdRef, level, version, "<MyTestClass>");
    }
    else if (SyntaxChecker::isValidXMLID(mIdRef) == false)
    {
      log->logPackageError("test", TestMyTestClassIdRefMustBeID, pkgVersion,
        level, version, "The attribute idRef='" + mIdRef + "' does not conform to "
          "the syntax.", getLine(), getColumn());
    }
  }

  // 
  // idref1 IDREF (use = "optional" )
  // 

  assigned = attributes.readInto("idref1", mIdref1);

  if (assigned == true)
  {
    if (mIdref1.empty() == true)
    {
      logEmptyString(mIdref1, level, version, "<MyTestClass>");
    }
    else if (SyntaxChecker::isValidXMLID(mIdref1) == false)
    {
      log->logPackageError("test", TestMyTestClassIdref1MustBeID, pkgVersion,
        level, version, "The attribute idref1='" + mIdref1 + "' does not conform "
          "to the syntax.", getLine(), getColumn());
    }
  }

  // 
  // idref2 IDREF (use = "optional" )
  // 

  assigned = attributes.readInto("idref2", mIdref2);

  if (assigned == true)
  {
    if (mIdref2.empty() == true)
    {
      logEmptyString(mIdref2, level, version, "<MyTestClass>");
    }
    else if (SyntaxChecker::isValidXMLID(mIdref2) == false)
    {
      log->logPackageError("test", TestMyTestClassIdref2MustBeID, pkgVersion,
        level, version, "The attribute idref2='" + mIdref2 + "' does not conform "
          "to the syntax.", getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
MyTestClass::writeAttributes(XMLOutputStream& stream) const
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

  if (isSetIdRef() == true)
  {
    stream.writeAttribute("idRef", getPrefix(), mIdRef);
  }

  if (isSetIdref1() == true)
  {
    stream.writeAttribute("idref1", getPrefix(), mIdref1);
  }

  if (isSetIdref2() == true)
  {
    stream.writeAttribute("idref2", getPrefix(), mIdref2);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new MyTestClass_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
MyTestClass_t *
MyTestClass_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
{
  return new MyTestClass(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this MyTestClass_t object.
 */
LIBSBML_EXTERN
MyTestClass_t*
MyTestClass_clone(const MyTestClass_t* mtc)
{
  if (mtc != NULL)
  {
    return static_cast<MyTestClass_t*>(mtc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this MyTestClass_t object.
 */
LIBSBML_EXTERN
void
MyTestClass_free(MyTestClass_t* mtc)
{
  if (mtc != NULL)
  {
    delete mtc;
  }
}


/*
 * Returns the value of the "id" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getId(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getId().empty() ? NULL : safe_strdup(mtc->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getName(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getName().empty() ? NULL : safe_strdup(mtc->getName().c_str());
}


/*
 * Returns the value of the "num" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
unsigned int
MyTestClass_getNum(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->getNum() : SBML_INT_MAX;
}


/*
 * Returns the value of the "num2" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
unsigned int
MyTestClass_getNum2(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->getNum2() : SBML_INT_MAX;
}


/*
 * Returns the value of the "num3" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_getNum3(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->getNum3() : SBML_INT_MAX;
}


/*
 * Returns the value of the "num1" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
double
MyTestClass_getNum1(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->getNum1() : util_NaN();
}


/*
 * Returns the value of the "true" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_getTrue(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->getTrue()) : 0;
}


/*
 * Returns the value of the "false" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_getFalse(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->getFalse()) : 0;
}


/*
 * Returns the value of the "unit" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getUnit(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getUnit().empty() ? NULL : safe_strdup(mtc->getUnit().c_str());
}


/*
 * Returns the value of the "ref1" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getRef1(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getRef1().empty() ? NULL : safe_strdup(mtc->getRef1().c_str());
}


/*
 * Returns the value of the "ref2" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getRef2(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getRef2().empty() ? NULL : safe_strdup(mtc->getRef2().c_str());
}


/*
 * Returns the value of the "refUnit" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getRefUnit(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getRefUnit().empty() ? NULL :
    safe_strdup(mtc->getRefUnit().c_str());
}


/*
 * Returns the value of the "correctId" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getCorrectId(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getCorrectId().empty() ? NULL :
    safe_strdup(mtc->getCorrectId().c_str());
}


/*
 * Returns the value of the "idRef" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getIdRef(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getIdRef().empty() ? NULL : safe_strdup(mtc->getIdRef().c_str());
}


/*
 * Returns the value of the "idref1" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getIdref1(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getIdref1().empty() ? NULL :
    safe_strdup(mtc->getIdref1().c_str());
}


/*
 * Returns the value of the "idref2" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
const char *
MyTestClass_getIdref2(const MyTestClass_t * mtc)
{
  if (mtc == NULL)
  {
    return NULL;
  }

  return mtc->getIdref2().empty() ? NULL :
    safe_strdup(mtc->getIdref2().c_str());
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetId(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "name" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetName(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "num" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetNum(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetNum()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "num2" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetNum2(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetNum2()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "num3" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetNum3(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetNum3()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "num1" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetNum1(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetNum1()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "true" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetTrue(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetTrue()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "false" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetFalse(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetFalse()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "unit" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetUnit(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetUnit()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "ref1" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetRef1(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetRef1()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "ref2" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetRef2(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetRef2()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "refUnit" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetRefUnit(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetRefUnit()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "correctId" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetCorrectId(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetCorrectId()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "idRef" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetIdRef(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetIdRef()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "idref1" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetIdref1(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetIdref1()) : 0;
}


/*
 * Predicate returning @c 1 if this MyTestClass_t's "idref2" attribute is set.
 */
LIBSBML_EXTERN
int
MyTestClass_isSetIdref2(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->isSetIdref2()) : 0;
}


/*
 * Sets the value of the "id" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setId(MyTestClass_t * mtc, const char * id)
{
  return (mtc != NULL) ? mtc->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setName(MyTestClass_t * mtc, const char * name)
{
  return (mtc != NULL) ? mtc->setName(name) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setNum(MyTestClass_t * mtc, unsigned int num)
{
  return (mtc != NULL) ? mtc->setNum(num) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num2" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setNum2(MyTestClass_t * mtc, unsigned int num2)
{
  return (mtc != NULL) ? mtc->setNum2(num2) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num3" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setNum3(MyTestClass_t * mtc, int num3)
{
  return (mtc != NULL) ? mtc->setNum3(num3) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num1" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setNum1(MyTestClass_t * mtc, double num1)
{
  return (mtc != NULL) ? mtc->setNum1(num1) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "true" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setTrue(MyTestClass_t * mtc, int true)
{
  return (mtc != NULL) ? mtc->setTrue(true) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "false" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setFalse(MyTestClass_t * mtc, int false)
{
  return (mtc != NULL) ? mtc->setFalse(false) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "unit" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setUnit(MyTestClass_t * mtc, const char * unit)
{
  return (mtc != NULL) ? mtc->setUnit(unit) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "ref1" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setRef1(MyTestClass_t * mtc, const char * ref1)
{
  return (mtc != NULL) ? mtc->setRef1(ref1) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "ref2" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setRef2(MyTestClass_t * mtc, const char * ref2)
{
  return (mtc != NULL) ? mtc->setRef2(ref2) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "refUnit" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setRefUnit(MyTestClass_t * mtc, const char * refUnit)
{
  return (mtc != NULL) ? mtc->setRefUnit(refUnit) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "correctId" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setCorrectId(MyTestClass_t * mtc, const char * correctId)
{
  return (mtc != NULL) ? mtc->setCorrectId(correctId) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "idRef" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setIdRef(MyTestClass_t * mtc, const char * idRef)
{
  return (mtc != NULL) ? mtc->setIdRef(idRef) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "idref1" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setIdref1(MyTestClass_t * mtc, const char * idref1)
{
  return (mtc != NULL) ? mtc->setIdref1(idref1) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "idref2" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_setIdref2(MyTestClass_t * mtc, const char * idref2)
{
  return (mtc != NULL) ? mtc->setIdref2(idref2) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetId(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetName(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetNum(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetNum() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num2" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetNum2(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetNum2() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num3" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetNum3(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetNum3() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num1" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetNum1(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetNum1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "true" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetTrue(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetTrue() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "false" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetFalse(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetFalse() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "unit" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetUnit(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetUnit() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "ref1" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetRef1(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetRef1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "ref2" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetRef2(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetRef2() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "refUnit" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetRefUnit(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetRefUnit() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "correctId" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetCorrectId(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetCorrectId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "idRef" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetIdRef(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetIdRef() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "idref1" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetIdref1(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetIdref1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "idref2" attribute of this MyTestClass_t.
 */
LIBSBML_EXTERN
int
MyTestClass_unsetIdref2(MyTestClass_t * mtc)
{
  return (mtc != NULL) ? mtc->unsetIdref2() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * MyTestClass_t object have been set.
 */
LIBSBML_EXTERN
int
MyTestClass_hasRequiredAttributes(const MyTestClass_t * mtc)
{
  return (mtc != NULL) ? static_cast<int>(mtc->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


