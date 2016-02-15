/**
 * @file ClassThree.cpp
 * @brief Implementation of the ClassThree class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
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
#include <sbml/packages/test/sbml/ClassThree.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ClassThree using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
ClassThree::ClassThree(unsigned int level,
                       unsigned int version,
                       unsigned int pkgVersion)
  : SBase(level, version)
  , mNumber (ENUM_INVALID)
  , mName (FRED_INVALID)
  , mBadName (FRED_INVALID)
  , mOtherNum (ENUM_INVALID)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ClassThree using the given TestPkgNamespaces object.
 */
ClassThree::ClassThree(TestPkgNamespaces *testns)
  : SBase(testns)
  , mNumber (ENUM_INVALID)
  , mName (FRED_INVALID)
  , mBadName (FRED_INVALID)
  , mOtherNum (ENUM_INVALID)
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for ClassThree.
 */
ClassThree::ClassThree(const ClassThree& orig)
  : SBase( orig )
  , mNumber ( orig.mNumber )
  , mName ( orig.mName )
  , mBadName ( orig.mBadName )
  , mOtherNum ( orig.mOtherNum )
{
}


/*
 * Assignment operator for ClassThree.
 */
ClassThree&
ClassThree::operator=(const ClassThree& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mNumber = rhs.mNumber;
    mName = rhs.mName;
    mBadName = rhs.mBadName;
    mOtherNum = rhs.mOtherNum;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ClassThree object.
 */
ClassThree*
ClassThree::clone() const
{
  return new ClassThree(*this);
}


/*
 * Destructor for ClassThree.
 */
ClassThree::~ClassThree()
{
}


/*
 * Returns the value of the "number" attribute of this ClassThree.
 */
Enum_t
ClassThree::getNumber() const
{
  return mNumber;
}


/*
 * Returns the value of the "number" attribute of this ClassThree.
 */
const std::string&
ClassThree::getNumberAsString() const
{
  static const std::string code_str = Enum_toString(mNumber);
  return code_str;
}


/*
 * Returns the value of the "name" attribute of this ClassThree.
 */
Fred_t
ClassThree::getName() const
{
  return mName;
}


/*
 * Returns the value of the "name" attribute of this ClassThree.
 */
const std::string&
ClassThree::getNameAsString() const
{
  static const std::string code_str = Fred_toString(mName);
  return code_str;
}


/*
 * Returns the value of the "badName" attribute of this ClassThree.
 */
Fred_t
ClassThree::getBadName() const
{
  return mBadName;
}


/*
 * Returns the value of the "badName" attribute of this ClassThree.
 */
const std::string&
ClassThree::getBadNameAsString() const
{
  static const std::string code_str = Fred_toString(mBadName);
  return code_str;
}


/*
 * Returns the value of the "otherNum" attribute of this ClassThree.
 */
Enum_t
ClassThree::getOtherNum() const
{
  return mOtherNum;
}


/*
 * Returns the value of the "otherNum" attribute of this ClassThree.
 */
const std::string&
ClassThree::getOtherNumAsString() const
{
  static const std::string code_str = Enum_toString(mOtherNum);
  return code_str;
}


/*
 * Predicate returning @c true if this ClassThree's "number" attribute is set.
 */
bool
ClassThree::isSetNumber() const
{
  return (mNumber != ENUM_INVALID);
}


/*
 * Predicate returning @c true if this ClassThree's "name" attribute is set.
 */
bool
ClassThree::isSetName() const
{
  return (mName != FRED_INVALID);
}


/*
 * Predicate returning @c true if this ClassThree's "badName" attribute is set.
 */
bool
ClassThree::isSetBadName() const
{
  return (mBadName != FRED_INVALID);
}


/*
 * Predicate returning @c true if this ClassThree's "otherNum" attribute is
 * set.
 */
bool
ClassThree::isSetOtherNum() const
{
  return (mOtherNum != ENUM_INVALID);
}


/*
 * Sets the value of the "number" attribute of this ClassThree.
 */
int
ClassThree::setNumber(const Enum_t number)
{
  if (Enum_isValid(number) == 0)
  {
    mNumber = ENUM_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mNumber = number;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "number" attribute of this ClassThree.
 */
int
ClassThree::setNumber(const std::string& number)
{
  if (Enum_isValidString(number.c_str()) == 0)
  {
    mNumber = ENUM_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mNumber = Enum_fromString(number.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "name" attribute of this ClassThree.
 */
int
ClassThree::setName(const Fred_t name)
{
  if (Fred_isValid(name) == 0)
  {
    mName = FRED_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mName = name;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "name" attribute of this ClassThree.
 */
int
ClassThree::setName(const std::string& name)
{
  if (Fred_isValidString(name.c_str()) == 0)
  {
    mName = FRED_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mName = Fred_fromString(name.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "badName" attribute of this ClassThree.
 */
int
ClassThree::setBadName(const Fred_t badName)
{
  if (Fred_isValid(badName) == 0)
  {
    mBadName = FRED_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mBadName = badName;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "badName" attribute of this ClassThree.
 */
int
ClassThree::setBadName(const std::string& badName)
{
  if (Fred_isValidString(badName.c_str()) == 0)
  {
    mBadName = FRED_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mBadName = Fred_fromString(badName.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "otherNum" attribute of this ClassThree.
 */
int
ClassThree::setOtherNum(const Enum_t otherNum)
{
  if (Enum_isValid(otherNum) == 0)
  {
    mOtherNum = ENUM_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mOtherNum = otherNum;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "otherNum" attribute of this ClassThree.
 */
int
ClassThree::setOtherNum(const std::string& otherNum)
{
  if (Enum_isValidString(otherNum.c_str()) == 0)
  {
    mOtherNum = ENUM_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mOtherNum = Enum_fromString(otherNum.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "number" attribute of this ClassThree.
 */
int
ClassThree::unsetNumber()
{
  mNumber = ENUM_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "name" attribute of this ClassThree.
 */
int
ClassThree::unsetName()
{
  mName = FRED_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "badName" attribute of this ClassThree.
 */
int
ClassThree::unsetBadName()
{
  mBadName = FRED_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "otherNum" attribute of this ClassThree.
 */
int
ClassThree::unsetOtherNum()
{
  mOtherNum = ENUM_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this ClassThree object.
 */
const std::string&
ClassThree::getElementName() const
{
  static const string name = "classThree";
  return name;
}


/*
 * Returns the libSBML type code for this ClassThree object.
 */
int
ClassThree::getTypeCode() const
{
  return SBML_TEST_CLASSTHREE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * ClassThree object have been set.
 */
bool
ClassThree::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetNumber() == false)
  {
    allPresent = false;
  }

  if (isSetName() == false)
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
ClassThree::writeElements(XMLOutputStream& stream) const
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
ClassThree::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
ClassThree::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
ClassThree::enablePackageInternal(const std::string& pkgURI,
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
ClassThree::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("number");

  attributes.add("name");

  attributes.add("badName");

  attributes.add("otherNum");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassThree::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("test", TestClassThreeAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("test", TestClassThreeAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  // 
  // number enum (use = "required" )
  // 

  std::string number;
  assigned = attributes.readInto("number", number);

  if (assigned == true)
  {
    if (number.empty() == true)
    {
      logEmptyString(number, level, version, "<ClassThree>");
    }
    else
    {
      mNumber = Enum_fromString(number.c_str());

      if (Enum_isValid(mNumber) == 0)
      {
        std::string msg = "The number on the <ClassThree> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + number + "', which is not a valid option.";

        log->logPackageError("test", TestClassThreeNumberMustBeEnumEnum,
          pkgVersion, level, version, msg);
      }
    }
  }
  else
  {
    std::string message = "Test attribute 'number' is missing.";
    log->logPackageError("test", TestClassThreeAllowedAttributes, pkgVersion,
      level, version, message);
  }

  // 
  // name enum (use = "required" )
  // 

  std::string name;
  assigned = attributes.readInto("name", name);

  if (assigned == true)
  {
    if (name.empty() == true)
    {
      logEmptyString(name, level, version, "<ClassThree>");
    }
    else
    {
      mName = Fred_fromString(name.c_str());

      if (Fred_isValid(mName) == 0)
      {
        std::string msg = "The name on the <ClassThree> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + name + "', which is not a valid option.";

        log->logPackageError("test", TestClassThreeNameMustBeFredEnum,
          pkgVersion, level, version, msg);
      }
    }
  }
  else
  {
    std::string message = "Test attribute 'name' is missing.";
    log->logPackageError("test", TestClassThreeAllowedAttributes, pkgVersion,
      level, version, message);
  }

  // 
  // badName enum (use = "optional" )
  // 

  std::string badname;
  assigned = attributes.readInto("badName", badname);

  if (assigned == true)
  {
    if (badname.empty() == true)
    {
      logEmptyString(badname, level, version, "<ClassThree>");
    }
    else
    {
      mBadName = Fred_fromString(badname.c_str());

      if (Fred_isValid(mBadName) == 0)
      {
        std::string msg = "The badName on the <ClassThree> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + badname + "', which is not a valid option.";

        log->logPackageError("test", TestClassThreeBadNameMustBeFredEnum,
          pkgVersion, level, version, msg);
      }
    }
  }

  // 
  // otherNum enum (use = "optional" )
  // 

  std::string othernum;
  assigned = attributes.readInto("otherNum", othernum);

  if (assigned == true)
  {
    if (othernum.empty() == true)
    {
      logEmptyString(othernum, level, version, "<ClassThree>");
    }
    else
    {
      mOtherNum = Enum_fromString(othernum.c_str());

      if (Enum_isValid(mOtherNum) == 0)
      {
        std::string msg = "The otherNum on the <ClassThree> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + othernum + "', which is not a valid option.";

        log->logPackageError("test", TestClassThreeOtherNumMustBeEnumEnum,
          pkgVersion, level, version, msg);
      }
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassThree::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetNumber() == true)
  {
    stream.writeAttribute("number", getPrefix(), Enum_toString(mNumber));
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), Fred_toString(mName));
  }

  if (isSetBadName() == true)
  {
    stream.writeAttribute("badName", getPrefix(), Fred_toString(mBadName));
  }

  if (isSetOtherNum() == true)
  {
    stream.writeAttribute("otherNum", getPrefix(), Enum_toString(mOtherNum));
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ClassThree_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
ClassThree_t *
ClassThree_create(unsigned int level,
                  unsigned int version,
                  unsigned int pkgVersion)
{
  return new ClassThree(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ClassThree_t object.
 */
LIBSBML_EXTERN
ClassThree_t*
ClassThree_clone(const ClassThree_t* ct)
{
  if (ct != NULL)
  {
    return static_cast<ClassThree_t*>(ct->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ClassThree_t object.
 */
LIBSBML_EXTERN
void
ClassThree_free(ClassThree_t* ct)
{
  if (ct != NULL)
  {
    delete ct;
  }
}


/*
 * Returns the value of the "number" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
Enum_t
ClassThree_getNumber(const ClassThree_t * ct)
{
  if (ct == NULL)
  {
    return ENUM_INVALID;
  }

  return ct->getNumber();
}


/*
 * Returns the value of the "number" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
const char *
ClassThree_getNumberAsString(const ClassThree_t * ct)
{
  return Enum_toString(ct->getNumber());
}


/*
 * Returns the value of the "name" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
Fred_t
ClassThree_getName(const ClassThree_t * ct)
{
  if (ct == NULL)
  {
    return FRED_INVALID;
  }

  return ct->getName();
}


/*
 * Returns the value of the "name" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
const char *
ClassThree_getNameAsString(const ClassThree_t * ct)
{
  return Fred_toString(ct->getName());
}


/*
 * Returns the value of the "badName" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
Fred_t
ClassThree_getBadName(const ClassThree_t * ct)
{
  if (ct == NULL)
  {
    return FRED_INVALID;
  }

  return ct->getBadName();
}


/*
 * Returns the value of the "badName" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
const char *
ClassThree_getBadNameAsString(const ClassThree_t * ct)
{
  return Fred_toString(ct->getBadName());
}


/*
 * Returns the value of the "otherNum" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
Enum_t
ClassThree_getOtherNum(const ClassThree_t * ct)
{
  if (ct == NULL)
  {
    return ENUM_INVALID;
  }

  return ct->getOtherNum();
}


/*
 * Returns the value of the "otherNum" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
const char *
ClassThree_getOtherNumAsString(const ClassThree_t * ct)
{
  return Enum_toString(ct->getOtherNum());
}


/*
 * Predicate returning @c 1 if this ClassThree_t's "number" attribute is set.
 */
LIBSBML_EXTERN
int
ClassThree_isSetNumber(const ClassThree_t * ct)
{
  return (ct != NULL) ? static_cast<int>(ct->isSetNumber()) : 0;
}


/*
 * Predicate returning @c 1 if this ClassThree_t's "name" attribute is set.
 */
LIBSBML_EXTERN
int
ClassThree_isSetName(const ClassThree_t * ct)
{
  return (ct != NULL) ? static_cast<int>(ct->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 if this ClassThree_t's "badName" attribute is set.
 */
LIBSBML_EXTERN
int
ClassThree_isSetBadName(const ClassThree_t * ct)
{
  return (ct != NULL) ? static_cast<int>(ct->isSetBadName()) : 0;
}


/*
 * Predicate returning @c 1 if this ClassThree_t's "otherNum" attribute is set.
 */
LIBSBML_EXTERN
int
ClassThree_isSetOtherNum(const ClassThree_t * ct)
{
  return (ct != NULL) ? static_cast<int>(ct->isSetOtherNum()) : 0;
}


/*
 * Sets the value of the "number" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_setNumber(ClassThree_t * ct, Enum_t number)
{
  return (ct != NULL) ? ct->setNumber(number) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "number" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_setNumberAsString(ClassThree_t * ct, const char * number)
{
  return (ct != NULL) ? ct->setNumber(number): LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_setName(ClassThree_t * ct, Fred_t name)
{
  return (ct != NULL) ? ct->setName(name) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_setNameAsString(ClassThree_t * ct, const char * name)
{
  return (ct != NULL) ? ct->setName(name): LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "badName" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_setBadName(ClassThree_t * ct, Fred_t badName)
{
  return (ct != NULL) ? ct->setBadName(badName) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "badName" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_setBadNameAsString(ClassThree_t * ct, const char * badName)
{
  return (ct != NULL) ? ct->setBadName(badName): LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "otherNum" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_setOtherNum(ClassThree_t * ct, Enum_t otherNum)
{
  return (ct != NULL) ? ct->setOtherNum(otherNum) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "otherNum" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_setOtherNumAsString(ClassThree_t * ct, const char * otherNum)
{
  return (ct != NULL) ? ct->setOtherNum(otherNum): LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "number" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_unsetNumber(ClassThree_t * ct)
{
  return (ct != NULL) ? ct->unsetNumber() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_unsetName(ClassThree_t * ct)
{
  return (ct != NULL) ? ct->unsetName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "badName" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_unsetBadName(ClassThree_t * ct)
{
  return (ct != NULL) ? ct->unsetBadName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "otherNum" attribute of this ClassThree_t.
 */
LIBSBML_EXTERN
int
ClassThree_unsetOtherNum(ClassThree_t * ct)
{
  return (ct != NULL) ? ct->unsetOtherNum() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * ClassThree_t object have been set.
 */
LIBSBML_EXTERN
int
ClassThree_hasRequiredAttributes(const ClassThree_t * ct)
{
  return (ct != NULL) ? static_cast<int>(ct->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


