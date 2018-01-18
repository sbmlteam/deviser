/**
 * @file ClassOneTwo.cpp
 * @brief Implementation of the ClassOneTwo class.
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
#include <sbml/packages/coreversmultipkg/sbml/ClassOneTwo.h>
#include <sbml/packages/coreversmultipkg/validator/CoreversmultipkgSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ClassOneTwo using the given SBML Level, Version and
 * &ldquo;coreversmultipkg&rdquo; package version.
 */
ClassOneTwo::ClassOneTwo(unsigned int level,
                         unsigned int version,
                         unsigned int pkgVersion)
  : SBase(level, version)
  , mAtt1 (false)
  , mIsSetAtt1 (false)
  , mAttStr ("")
  , mAttInt (SBML_INT_MAX)
  , mIsSetAttInt (false)
  , mAtt2 (false)
  , mIsSetAtt2 (false)
  , mAttDbl (util_NaN())
  , mIsSetAttDbl (false)
  , mAttUnit ("")
  , mAttEnum (ABC_TYPE_INVALID)
{
  setSBMLNamespacesAndOwn(new CoreversmultipkgPkgNamespaces(level, version,
    pkgVersion));
}


/*
 * Creates a new ClassOneTwo using the given CoreversmultipkgPkgNamespaces
 * object.
 */
ClassOneTwo::ClassOneTwo(CoreversmultipkgPkgNamespaces *coreversmultipkgns)
  : SBase(coreversmultipkgns)
  , mAtt1 (false)
  , mIsSetAtt1 (false)
  , mAttStr ("")
  , mAttInt (SBML_INT_MAX)
  , mIsSetAttInt (false)
  , mAtt2 (false)
  , mIsSetAtt2 (false)
  , mAttDbl (util_NaN())
  , mIsSetAttDbl (false)
  , mAttUnit ("")
  , mAttEnum (ABC_TYPE_INVALID)
{
  setElementNamespace(coreversmultipkgns->getURI());
  loadPlugins(coreversmultipkgns);
}


/*
 * Copy constructor for ClassOneTwo.
 */
ClassOneTwo::ClassOneTwo(const ClassOneTwo& orig)
  : SBase( orig )
  , mAtt1 ( orig.mAtt1 )
  , mIsSetAtt1 ( orig.mIsSetAtt1 )
  , mAttStr ( orig.mAttStr )
  , mAttInt ( orig.mAttInt )
  , mIsSetAttInt ( orig.mIsSetAttInt )
  , mAtt2 ( orig.mAtt2 )
  , mIsSetAtt2 ( orig.mIsSetAtt2 )
  , mAttDbl ( orig.mAttDbl )
  , mIsSetAttDbl ( orig.mIsSetAttDbl )
  , mAttUnit ( orig.mAttUnit )
  , mAttEnum ( orig.mAttEnum )
{
}


/*
 * Assignment operator for ClassOneTwo.
 */
ClassOneTwo&
ClassOneTwo::operator=(const ClassOneTwo& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mAtt1 = rhs.mAtt1;
    mIsSetAtt1 = rhs.mIsSetAtt1;
    mAttStr = rhs.mAttStr;
    mAttInt = rhs.mAttInt;
    mIsSetAttInt = rhs.mIsSetAttInt;
    mAtt2 = rhs.mAtt2;
    mIsSetAtt2 = rhs.mIsSetAtt2;
    mAttDbl = rhs.mAttDbl;
    mIsSetAttDbl = rhs.mIsSetAttDbl;
    mAttUnit = rhs.mAttUnit;
    mAttEnum = rhs.mAttEnum;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ClassOneTwo object.
 */
ClassOneTwo*
ClassOneTwo::clone() const
{
  return new ClassOneTwo(*this);
}


/*
 * Destructor for ClassOneTwo.
 */
ClassOneTwo::~ClassOneTwo()
{
}


/*
 * Returns the value of the "id" attribute of this ClassOneTwo.
 */
const std::string&
ClassOneTwo::getId() const
{
  return mId;
}


/*
 * Returns the value of the "att1" attribute of this ClassOneTwo.
 */
bool
ClassOneTwo::getAtt1() const
{
  return mAtt1;
}


/*
 * Returns the value of the "attStr" attribute of this ClassOneTwo.
 */
const std::string&
ClassOneTwo::getAttStr() const
{
  return mAttStr;
}


/*
 * Returns the value of the "attInt" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::getAttInt() const
{
  return mAttInt;
}


/*
 * Returns the value of the "att2" attribute of this ClassOneTwo.
 */
bool
ClassOneTwo::getAtt2() const
{
  return mAtt2;
}


/*
 * Returns the value of the "attDbl" attribute of this ClassOneTwo.
 */
double
ClassOneTwo::getAttDbl() const
{
  return mAttDbl;
}


/*
 * Returns the value of the "attUnit" attribute of this ClassOneTwo.
 */
const std::string&
ClassOneTwo::getAttUnit() const
{
  return mAttUnit;
}


/*
 * Returns the value of the "attEnum" attribute of this ClassOneTwo.
 */
AbcType_t
ClassOneTwo::getAttEnum() const
{
  return mAttEnum;
}


/*
 * Returns the value of the "attEnum" attribute of this ClassOneTwo.
 */
const std::string&
ClassOneTwo::getAttEnumAsString() const
{
  static const std::string code_str = AbcType_toString(mAttEnum);
  return code_str;
}


/*
 * Predicate returning @c true if this ClassOneTwo's "id" attribute is set.
 */
bool
ClassOneTwo::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this ClassOneTwo's "att1" attribute is set.
 */
bool
ClassOneTwo::isSetAtt1() const
{
  return mIsSetAtt1;
}


/*
 * Predicate returning @c true if this ClassOneTwo's "attStr" attribute is set.
 */
bool
ClassOneTwo::isSetAttStr() const
{
  return (mAttStr.empty() == false);
}


/*
 * Predicate returning @c true if this ClassOneTwo's "attInt" attribute is set.
 */
bool
ClassOneTwo::isSetAttInt() const
{
  return mIsSetAttInt;
}


/*
 * Predicate returning @c true if this ClassOneTwo's "att2" attribute is set.
 */
bool
ClassOneTwo::isSetAtt2() const
{
  return mIsSetAtt2;
}


/*
 * Predicate returning @c true if this ClassOneTwo's "attDbl" attribute is set.
 */
bool
ClassOneTwo::isSetAttDbl() const
{
  return mIsSetAttDbl;
}


/*
 * Predicate returning @c true if this ClassOneTwo's "attUnit" attribute is
 * set.
 */
bool
ClassOneTwo::isSetAttUnit() const
{
  return (mAttUnit.empty() == false);
}


/*
 * Predicate returning @c true if this ClassOneTwo's "attEnum" attribute is
 * set.
 */
bool
ClassOneTwo::isSetAttEnum() const
{
  return (mAttEnum != ABC_TYPE_INVALID);
}


/*
 * Sets the value of the "id" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setId(const std::string& id)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if ((coreLevel == 3 && coreVersion == 1 && pkgVersion == 2) || (coreLevel ==
    3 && coreVersion == 2 && pkgVersion == 1) || (coreLevel == 3 && coreVersion
      == 2 && pkgVersion == 2))
  {
    return SyntaxChecker::checkAndSetSId(id, mId);
  }
  else
  {
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "att1" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAtt1(bool att1)
{
  mAtt1 = att1;
  mIsSetAtt1 = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "attStr" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttStr(const std::string& attStr)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (coreLevel == 3 && coreVersion == 1 && pkgVersion == 2)
  {
    mAttStr = attStr;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "attInt" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttInt(int attInt)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if ((coreLevel == 3 && coreVersion == 1 && pkgVersion == 2) || (coreLevel ==
    3 && coreVersion == 2 && pkgVersion == 2))
  {
    mAttInt = attInt;
    mIsSetAttInt = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    mAttInt = attInt;
    mIsSetAttInt = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "att2" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAtt2(bool att2)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if ((coreLevel == 3 && coreVersion == 2 && pkgVersion == 1) || (coreLevel ==
    3 && coreVersion == 2 && pkgVersion == 2) || (coreLevel == 4 && coreVersion
      == 1 && pkgVersion == 1))
  {
    mAtt2 = att2;
    mIsSetAtt2 = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    mAtt2 = att2;
    mIsSetAtt2 = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "attDbl" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttDbl(double attDbl)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (coreLevel == 3 && coreVersion == 2 && pkgVersion == 1)
  {
    mAttDbl = attDbl;
    mIsSetAttDbl = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    mAttDbl = attDbl;
    mIsSetAttDbl = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "attUnit" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttUnit(const std::string& attUnit)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (coreLevel == 4 && coreVersion == 1 && pkgVersion == 1)
  {
    if (!(SyntaxChecker::isValidInternalUnitSId(attUnit)))
    {
      return LIBSBML_INVALID_ATTRIBUTE_VALUE;
    }
    else
    {
      mAttUnit = attUnit;
      return LIBSBML_OPERATION_SUCCESS;
    }
  }
  else
  {
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "attEnum" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttEnum(const AbcType_t attEnum)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (coreLevel == 4 && coreVersion == 1 && pkgVersion == 1)
  {
    if (AbcType_isValid(attEnum) == 0)
    {
      mAttEnum = ABC_TYPE_INVALID;
      return LIBSBML_INVALID_ATTRIBUTE_VALUE;
    }
    else
    {
      mAttEnum = attEnum;
      return LIBSBML_OPERATION_SUCCESS;
    }
  }
  else
  {
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "attEnum" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttEnum(const std::string& attEnum)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (coreLevel == 4 && coreVersion == 1 && pkgVersion == 1)
  {
    if (AbcType_isValidString(attEnum.c_str()) == 0)
    {
      mAttEnum = ABC_TYPE_INVALID;
      return LIBSBML_INVALID_ATTRIBUTE_VALUE;
    }
    else
    {
      mAttEnum = AbcType_fromString(attEnum.c_str());
      return LIBSBML_OPERATION_SUCCESS;
    }
  }
  else
  {
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Unsets the value of the "id" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::unsetId()
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
 * Unsets the value of the "att1" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::unsetAtt1()
{
  mAtt1 = false;
  mIsSetAtt1 = false;

  if (isSetAtt1() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "attStr" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::unsetAttStr()
{
  mAttStr.erase();

  if (mAttStr.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "attInt" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::unsetAttInt()
{
  mAttInt = SBML_INT_MAX;
  mIsSetAttInt = false;

  if (isSetAttInt() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "att2" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::unsetAtt2()
{
  mAtt2 = false;
  mIsSetAtt2 = false;

  if (isSetAtt2() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "attDbl" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::unsetAttDbl()
{
  mAttDbl = util_NaN();
  mIsSetAttDbl = false;

  if (isSetAttDbl() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "attUnit" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::unsetAttUnit()
{
  mAttUnit.erase();

  if (mAttUnit.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "attEnum" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::unsetAttEnum()
{
  mAttEnum = ABC_TYPE_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this ClassOneTwo object.
 */
const std::string&
ClassOneTwo::getElementName() const
{
  static const string name = "classOneTwo";
  return name;
}


/*
 * Returns the libSBML type code for this ClassOneTwo object.
 */
int
ClassOneTwo::getTypeCode() const
{
  return SBML_COREVERS_CLASSONETWO;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * ClassOneTwo object have been set.
 */
bool
ClassOneTwo::hasRequiredAttributes() const
{
  bool allPresent = true;

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if ((level == 3 && version == 1 && pkgVersion == 2) || (level == 3 && version
    == 2 && pkgVersion == 1) || (level == 3 && version == 2 && pkgVersion == 2))
  {
    if (isSetId() == false)
    {
      allPresent = false;
    }
  }

  if (level == 4 && version == 1 && pkgVersion == 1)
  {
    if (isSetAttEnum() == false)
    {
      allPresent = false;
    }
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
ClassOneTwo::writeElements(XMLOutputStream& stream) const
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
ClassOneTwo::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
ClassOneTwo::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
ClassOneTwo::enablePackageInternal(const std::string& pkgURI,
                                   const std::string& pkgPrefix,
                                   bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "att1")
  {
    value = getAtt1();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "att2")
  {
    value = getAtt2();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "attInt")
  {
    value = getAttInt();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "attDbl")
  {
    value = getAttDbl();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "attStr")
  {
    value = getAttStr();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "attUnit")
  {
    value = getAttUnit();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "attEnum")
  {
    value = getAttEnumAsString();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this ClassOneTwo's attribute "attributeName"
 * is set.
 */
bool
ClassOneTwo::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "att1")
  {
    value = isSetAtt1();
  }
  else if (attributeName == "attStr")
  {
    value = isSetAttStr();
  }
  else if (attributeName == "attInt")
  {
    value = isSetAttInt();
  }
  else if (attributeName == "att2")
  {
    value = isSetAtt2();
  }
  else if (attributeName == "attDbl")
  {
    value = isSetAttDbl();
  }
  else if (attributeName == "attUnit")
  {
    value = isSetAttUnit();
  }
  else if (attributeName == "attEnum")
  {
    value = isSetAttEnum();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "att1")
  {
    return_value = setAtt1(value);
  }
  else if (attributeName == "att2")
  {
    return_value = setAtt2(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "attInt")
  {
    return_value = setAttInt(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "attDbl")
  {
    return_value = setAttDbl(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "attStr")
  {
    return_value = setAttStr(value);
  }
  else if (attributeName == "attUnit")
  {
    return_value = setAttUnit(value);
  }
  else if (attributeName == "attEnum")
  {
    return_value = setAttEnum(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this ClassOneTwo.
 */
int
ClassOneTwo::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "att1")
  {
    value = unsetAtt1();
  }
  else if (attributeName == "attStr")
  {
    value = unsetAttStr();
  }
  else if (attributeName == "attInt")
  {
    value = unsetAttInt();
  }
  else if (attributeName == "att2")
  {
    value = unsetAtt2();
  }
  else if (attributeName == "attDbl")
  {
    value = unsetAttDbl();
  }
  else if (attributeName == "attUnit")
  {
    value = unsetAttUnit();
  }
  else if (attributeName == "attEnum")
  {
    value = unsetAttEnum();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
ClassOneTwo::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  unsigned int level = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && coreVersion == 1 && pkgVersion == 2)
  {
    attributes.add("id");
    attributes.add("att1");
    attributes.add("attStr");
    attributes.add("attInt");
  }

  if (level == 3 && coreVersion == 2 && pkgVersion == 1)
  {
    attributes.add("att1");
    attributes.add("att2");
    attributes.add("attDbl");
  }

  if (level == 3 && coreVersion == 2 && pkgVersion == 2)
  {
    attributes.add("att1");
    attributes.add("att2");
    attributes.add("attInt");
  }

  if (level == 4 && coreVersion == 1 && pkgVersion == 1)
  {
    attributes.add("att1");
    attributes.add("att2");
    attributes.add("attUnit");
    attributes.add("attEnum");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassOneTwo::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAllowedAttributes, pkgVersion, level, version,
          details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAllowedCoreAttributes, pkgVersion, level,
          version, details);
    }
  }

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    readL3V1V2Attributes(attributes);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    readL3V2V1Attributes(attributes);
  }

  if (level == 3 && version == 2 && pkgVersion == 2)
  {
    readL3V2V2Attributes(attributes);
  }

  if (level == 4 && version == 1 && pkgVersion == 1)
  {
    readL4V1V1Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassOneTwo::readL3V1V2Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<ClassOneTwo>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("coreversmultipkg", CoreversmultipkgIdSyntaxRule,
        pkgVersion, level, version, "The id on the <" + getElementName() + "> is "
          "'" + mId + "', which does not conform to the syntax.", getLine(),
            getColumn());
    }
  }
  else
  {
    std::string message = "Coreversmultipkg attribute 'id' is missing from the "
      "<ClassOneTwo> element.";
    log->logPackageError("coreversmultipkg",
      CoreversmultipkgClassOneTwoAllowedAttributes, pkgVersion, level, version,
        message);
  }

  // 
  // att1 bool (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAtt1 = attributes.readInto("att1", mAtt1);

  if (mIsSetAtt1 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAtt1MustBeBoolean, pkgVersion, level,
          version);
    }
  }

  // 
  // attStr string (use = "optional" )
  // 

  assigned = attributes.readInto("attStr", mAttStr);

  if (assigned == true)
  {
    if (mAttStr.empty() == true)
    {
      logEmptyString(mAttStr, level, version, "<ClassOneTwo>");
    }
  }

  // 
  // attInt int (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAttInt = attributes.readInto("attInt", mAttInt);

  if ( mIsSetAttInt == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Coreversmultipkg attribute 'attInt' from the "
        "<ClassOneTwo> element must be an integer.";
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAttIntMustBeInteger, pkgVersion, level,
          version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassOneTwo::readL3V2V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<ClassOneTwo>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("coreversmultipkg", CoreversmultipkgIdSyntaxRule,
        pkgVersion, level, version, "The id on the <" + getElementName() + "> is "
          "'" + mId + "', which does not conform to the syntax.", getLine(),
            getColumn());
    }
  }
  else
  {
    std::string message = "Coreversmultipkg attribute 'id' is missing from the "
      "<ClassOneTwo> element.";
    log->logPackageError("coreversmultipkg",
      CoreversmultipkgClassOneTwoAllowedAttributes, pkgVersion, level, version,
        message);
  }

  // 
  // att1 bool (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAtt1 = attributes.readInto("att1", mAtt1);

  if (mIsSetAtt1 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAtt1MustBeBoolean, pkgVersion, level,
          version);
    }
  }

  // 
  // att2 bool (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAtt2 = attributes.readInto("att2", mAtt2);

  if (mIsSetAtt2 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAtt2MustBeBoolean, pkgVersion, level,
          version);
    }
  }

  // 
  // attDbl double (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAttDbl = attributes.readInto("attDbl", mAttDbl);

  if ( mIsSetAttDbl == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Coreversmultipkg attribute 'attDbl' from the "
        "<ClassOneTwo> element must be an integer.";
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAttDblMustBeDouble, pkgVersion, level,
          version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassOneTwo::readL3V2V2Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<ClassOneTwo>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("coreversmultipkg", CoreversmultipkgIdSyntaxRule,
        pkgVersion, level, version, "The id on the <" + getElementName() + "> is "
          "'" + mId + "', which does not conform to the syntax.", getLine(),
            getColumn());
    }
  }
  else
  {
    std::string message = "Coreversmultipkg attribute 'id' is missing from the "
      "<ClassOneTwo> element.";
    log->logPackageError("coreversmultipkg",
      CoreversmultipkgClassOneTwoAllowedAttributes, pkgVersion, level, version,
        message);
  }

  // 
  // att1 bool (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAtt1 = attributes.readInto("att1", mAtt1);

  if (mIsSetAtt1 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAtt1MustBeBoolean, pkgVersion, level,
          version);
    }
  }

  // 
  // att2 bool (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAtt2 = attributes.readInto("att2", mAtt2);

  if (mIsSetAtt2 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAtt2MustBeBoolean, pkgVersion, level,
          version);
    }
  }

  // 
  // attInt int (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAttInt = attributes.readInto("attInt", mAttInt);

  if ( mIsSetAttInt == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Coreversmultipkg attribute 'attInt' from the "
        "<ClassOneTwo> element must be an integer.";
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAttIntMustBeInteger, pkgVersion, level,
          version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassOneTwo::readL4V1V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // att1 bool (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAtt1 = attributes.readInto("att1", mAtt1);

  if (mIsSetAtt1 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAtt1MustBeBoolean, pkgVersion, level,
          version);
    }
  }

  // 
  // att2 bool (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetAtt2 = attributes.readInto("att2", mAtt2);

  if (mIsSetAtt2 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAtt2MustBeBoolean, pkgVersion, level,
          version);
    }
  }

  // 
  // attUnit UnitSId (use = "optional" )
  // 

  assigned = attributes.readInto("attUnit", mAttUnit);

  if (assigned == true)
  {
    if (mAttUnit.empty() == true)
    {
      logEmptyString(mAttUnit, level, version, "<ClassOneTwo>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mAttUnit) == false)
    {
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgClassOneTwoAttUnitMustBeUnitSId, pkgVersion, level,
          version, "The attribute attUnit='" + mAttUnit + "' does not conform to "
            "the syntax.", getLine(), getColumn());
    }
  }

  // 
  // attEnum enum (use = "required" )
  // 

  std::string attEnum;
  assigned = attributes.readInto("attEnum", attEnum);

  if (assigned == true)
  {
    if (attEnum.empty() == true)
    {
      logEmptyString(attEnum, level, version, "<ClassOneTwo>");
    }
    else
    {
      mAttEnum = AbcType_fromString(attEnum.c_str());

      if (AbcType_isValid(mAttEnum) == 0)
      {
        std::string msg = "The attEnum on the <ClassOneTwo> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + attEnum + "', which is not a valid option.";

        log->logPackageError("coreversmultipkg",
          CoreversmultipkgClassOneTwoAttEnumMustBeAbcTypeEnum, pkgVersion, level,
            version, msg);
      }
    }
  }
  else
  {
    std::string message = "Coreversmultipkg attribute 'attEnum' is missing.";
    log->logPackageError("coreversmultipkg",
      CoreversmultipkgClassOneTwoAllowedAttributes, pkgVersion, level, version,
        message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassOneTwo::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    writeL3V1V2Attributes(stream);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    writeL3V2V1Attributes(stream);
  }

  if (level == 3 && version == 2 && pkgVersion == 2)
  {
    writeL3V2V2Attributes(stream);
  }

  if (level == 4 && version == 1 && pkgVersion == 1)
  {
    writeL4V1V1Attributes(stream);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassOneTwo::writeL3V1V2Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetAtt1() == true)
  {
    stream.writeAttribute("att1", getPrefix(), mAtt1);
  }

  if (isSetAttStr() == true)
  {
    stream.writeAttribute("attStr", getPrefix(), mAttStr);
  }

  if (isSetAttInt() == true)
  {
    stream.writeAttribute("attInt", getPrefix(), mAttInt);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassOneTwo::writeL3V2V1Attributes(XMLOutputStream& stream) const
{
  if (isSetAtt1() == true)
  {
    stream.writeAttribute("att1", getPrefix(), mAtt1);
  }

  if (isSetAtt2() == true)
  {
    stream.writeAttribute("att2", getPrefix(), mAtt2);
  }

  if (isSetAttDbl() == true)
  {
    stream.writeAttribute("attDbl", getPrefix(), mAttDbl);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassOneTwo::writeL3V2V2Attributes(XMLOutputStream& stream) const
{
  if (isSetAtt1() == true)
  {
    stream.writeAttribute("att1", getPrefix(), mAtt1);
  }

  if (isSetAtt2() == true)
  {
    stream.writeAttribute("att2", getPrefix(), mAtt2);
  }

  if (isSetAttInt() == true)
  {
    stream.writeAttribute("attInt", getPrefix(), mAttInt);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassOneTwo::writeL4V1V1Attributes(XMLOutputStream& stream) const
{
  if (isSetAtt1() == true)
  {
    stream.writeAttribute("att1", getPrefix(), mAtt1);
  }

  if (isSetAtt2() == true)
  {
    stream.writeAttribute("att2", getPrefix(), mAtt2);
  }

  if (isSetAttUnit() == true)
  {
    stream.writeAttribute("attUnit", getPrefix(), mAttUnit);
  }

  if (isSetAttEnum() == true)
  {
    stream.writeAttribute("attEnum", getPrefix(), AbcType_toString(mAttEnum));
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ClassOneTwo_t using the given SBML Level, Version and
 * &ldquo;coreversmultipkg&rdquo; package version.
 */
LIBSBML_EXTERN
ClassOneTwo_t *
ClassOneTwo_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
{
  return new ClassOneTwo(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ClassOneTwo_t object.
 */
LIBSBML_EXTERN
ClassOneTwo_t*
ClassOneTwo_clone(const ClassOneTwo_t* cot)
{
  if (cot != NULL)
  {
    return static_cast<ClassOneTwo_t*>(cot->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ClassOneTwo_t object.
 */
LIBSBML_EXTERN
void
ClassOneTwo_free(ClassOneTwo_t* cot)
{
  if (cot != NULL)
  {
    delete cot;
  }
}


/*
 * Returns the value of the "id" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
char *
ClassOneTwo_getId(const ClassOneTwo_t * cot)
{
  if (cot == NULL)
  {
    return NULL;
  }

  return cot->getId().empty() ? NULL : safe_strdup(cot->getId().c_str());
}


/*
 * Returns the value of the "att1" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_getAtt1(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->getAtt1()) : 0;
}


/*
 * Returns the value of the "attStr" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
char *
ClassOneTwo_getAttStr(const ClassOneTwo_t * cot)
{
  if (cot == NULL)
  {
    return NULL;
  }

  return cot->getAttStr().empty() ? NULL :
    safe_strdup(cot->getAttStr().c_str());
}


/*
 * Returns the value of the "attInt" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_getAttInt(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->getAttInt() : SBML_INT_MAX;
}


/*
 * Returns the value of the "att2" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_getAtt2(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->getAtt2()) : 0;
}


/*
 * Returns the value of the "attDbl" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
double
ClassOneTwo_getAttDbl(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->getAttDbl() : util_NaN();
}


/*
 * Returns the value of the "attUnit" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
char *
ClassOneTwo_getAttUnit(const ClassOneTwo_t * cot)
{
  if (cot == NULL)
  {
    return NULL;
  }

  return cot->getAttUnit().empty() ? NULL :
    safe_strdup(cot->getAttUnit().c_str());
}


/*
 * Returns the value of the "attEnum" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
AbcType_t
ClassOneTwo_getAttEnum(const ClassOneTwo_t * cot)
{
  if (cot == NULL)
  {
    return ABC_TYPE_INVALID;
  }

  return cot->getAttEnum();
}


/*
 * Returns the value of the "attEnum" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
const char *
ClassOneTwo_getAttEnumAsString(const ClassOneTwo_t * cot)
{
  return AbcType_toString(cot->getAttEnum());
}


/*
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "id" attribute is
 * set.
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetId(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "att1" attribute is
 * set.
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAtt1(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->isSetAtt1()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attStr" attribute
 * is set.
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttStr(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->isSetAttStr()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attInt" attribute
 * is set.
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttInt(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->isSetAttInt()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "att2" attribute is
 * set.
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAtt2(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->isSetAtt2()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attDbl" attribute
 * is set.
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttDbl(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->isSetAttDbl()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attUnit" attribute
 * is set.
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttUnit(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->isSetAttUnit()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this ClassOneTwo_t's "attEnum" attribute
 * is set.
 */
LIBSBML_EXTERN
int
ClassOneTwo_isSetAttEnum(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->isSetAttEnum()) : 0;
}


/*
 * Sets the value of the "id" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_setId(ClassOneTwo_t * cot, const char * id)
{
  return (cot != NULL) ? cot->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "att1" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAtt1(ClassOneTwo_t * cot, int att1)
{
  return (cot != NULL) ? cot->setAtt1(att1) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "attStr" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttStr(ClassOneTwo_t * cot, const char * attStr)
{
  return (cot != NULL) ? cot->setAttStr(attStr) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "attInt" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttInt(ClassOneTwo_t * cot, int attInt)
{
  return (cot != NULL) ? cot->setAttInt(attInt) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "att2" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAtt2(ClassOneTwo_t * cot, int att2)
{
  return (cot != NULL) ? cot->setAtt2(att2) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "attDbl" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttDbl(ClassOneTwo_t * cot, double attDbl)
{
  return (cot != NULL) ? cot->setAttDbl(attDbl) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "attUnit" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttUnit(ClassOneTwo_t * cot, const char * attUnit)
{
  return (cot != NULL) ? cot->setAttUnit(attUnit) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "attEnum" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttEnum(ClassOneTwo_t * cot, AbcType_t attEnum)
{
  return (cot != NULL) ? cot->setAttEnum(attEnum) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "attEnum" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_setAttEnumAsString(ClassOneTwo_t * cot, const char * attEnum)
{
  return (cot != NULL) ? cot->setAttEnum(attEnum): LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetId(ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "att1" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAtt1(ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->unsetAtt1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "attStr" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttStr(ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->unsetAttStr() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "attInt" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttInt(ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->unsetAttInt() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "att2" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAtt2(ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->unsetAtt2() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "attDbl" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttDbl(ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->unsetAttDbl() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "attUnit" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttUnit(ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->unsetAttUnit() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "attEnum" attribute of this ClassOneTwo_t.
 */
LIBSBML_EXTERN
int
ClassOneTwo_unsetAttEnum(ClassOneTwo_t * cot)
{
  return (cot != NULL) ? cot->unsetAttEnum() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * ClassOneTwo_t object have been set.
 */
LIBSBML_EXTERN
int
ClassOneTwo_hasRequiredAttributes(const ClassOneTwo_t * cot)
{
  return (cot != NULL) ? static_cast<int>(cot->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


