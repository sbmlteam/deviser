/**
 * @file Fred.cpp
 * @brief Implementation of the Fred class.
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
#include <sbml/packages/x/sbml/Fred.h>
#include <sbml/packages/x/validator/XSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Fred using the given SBML Level, Version and &ldquo;x&rdquo;
 * package version.
 */
Fred::Fred(unsigned int level, unsigned int version, unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mBool (false)
  , mIsSetBool (false)
  , mNum (SBML_INT_MAX)
  , mIsSetNum (false)
  , mStr ("")
  , mKind (KIND_INVALID)
{
  setSBMLNamespacesAndOwn(new XPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new Fred using the given XPkgNamespaces object.
 */
Fred::Fred(XPkgNamespaces *xns)
  : SBase(xns)
  , mId ("")
  , mBool (false)
  , mIsSetBool (false)
  , mNum (SBML_INT_MAX)
  , mIsSetNum (false)
  , mStr ("")
  , mKind (KIND_INVALID)
{
  setElementNamespace(xns->getURI());
  loadPlugins(xns);
}


/*
 * Copy constructor for Fred.
 */
Fred::Fred(const Fred& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mBool ( orig.mBool )
  , mIsSetBool ( orig.mIsSetBool )
  , mNum ( orig.mNum )
  , mIsSetNum ( orig.mIsSetNum )
  , mStr ( orig.mStr )
  , mKind ( orig.mKind )
{
}


/*
 * Assignment operator for Fred.
 */
Fred&
Fred::operator=(const Fred& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mBool = rhs.mBool;
    mIsSetBool = rhs.mIsSetBool;
    mNum = rhs.mNum;
    mIsSetNum = rhs.mIsSetNum;
    mStr = rhs.mStr;
    mKind = rhs.mKind;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Fred object.
 */
Fred*
Fred::clone() const
{
  return new Fred(*this);
}


/*
 * Destructor for Fred.
 */
Fred::~Fred()
{
}


/*
 * Returns the value of the "id" attribute of this Fred.
 */
const std::string&
Fred::getId() const
{
  return mId;
}


/*
 * Returns the value of the "bool" attribute of this Fred.
 */
bool
Fred::getBool() const
{
  return mBool;
}


/*
 * Returns the value of the "num" attribute of this Fred.
 */
int
Fred::getNum() const
{
  return mNum;
}


/*
 * Returns the value of the "str" attribute of this Fred.
 */
const std::string&
Fred::getStr() const
{
  return mStr;
}


/*
 * Returns the value of the "kind" attribute of this Fred.
 */
Kind_t
Fred::getKind() const
{
  return mKind;
}


/*
 * Returns the value of the "kind" attribute of this Fred.
 */
const std::string&
Fred::getKindAsString() const
{
  static const std::string code_str = Kind_toString(mKind);
  return code_str;
}


/*
 * Predicate returning @c true if this Fred's "id" attribute is set.
 */
bool
Fred::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this Fred's "bool" attribute is set.
 */
bool
Fred::isSetBool() const
{
  return mIsSetBool;
}


/*
 * Predicate returning @c true if this Fred's "num" attribute is set.
 */
bool
Fred::isSetNum() const
{
  return mIsSetNum;
}


/*
 * Predicate returning @c true if this Fred's "str" attribute is set.
 */
bool
Fred::isSetStr() const
{
  return (mStr.empty() == false);
}


/*
 * Predicate returning @c true if this Fred's "kind" attribute is set.
 */
bool
Fred::isSetKind() const
{
  return (mKind != KIND_INVALID);
}


/*
 * Sets the value of the "id" attribute of this Fred.
 */
int
Fred::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "bool" attribute of this Fred.
 */
int
Fred::setBool(bool bool)
{
  mBool = bool;
  mIsSetBool = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "num" attribute of this Fred.
 */
int
Fred::setNum(int num)
{
  mNum = num;
  mIsSetNum = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "str" attribute of this Fred.
 */
int
Fred::setStr(const std::string& str)
{
  mStr = str;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "kind" attribute of this Fred.
 */
int
Fred::setKind(const Kind_t kind)
{
  if (Kind_isValid(kind) == 0)
  {
    mKind = KIND_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mKind = kind;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "kind" attribute of this Fred.
 */
int
Fred::setKind(const std::string& kind)
{
  if (Kind_isValidString(kind.c_str()) == 0)
  {
    mKind = KIND_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mKind = Kind_fromString(kind.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "id" attribute of this Fred.
 */
int
Fred::unsetId()
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
 * Unsets the value of the "bool" attribute of this Fred.
 */
int
Fred::unsetBool()
{
  mBool = false;
  mIsSetBool = false;

  if (isSetBool() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "num" attribute of this Fred.
 */
int
Fred::unsetNum()
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
 * Unsets the value of the "str" attribute of this Fred.
 */
int
Fred::unsetStr()
{
  mStr.erase();

  if (mStr.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "kind" attribute of this Fred.
 */
int
Fred::unsetKind()
{
  mKind = KIND_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this Fred object.
 */
const std::string&
Fred::getElementName() const
{
  static const string name = "fred";
  return name;
}


/*
 * Returns the libSBML type code for this Fred object.
 */
int
Fred::getTypeCode() const
{
  return SBML_X_FRED;
}


/*
 * Predicate returning @c true if all the required attributes for this Fred
 * object have been set.
 */
bool
Fred::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetNum() == false)
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
Fred::writeElements(XMLOutputStream& stream) const
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
Fred::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Fred::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Fred::enablePackageInternal(const std::string& pkgURI,
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
Fred::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("identifier");

  attributes.add("myBoolean");

  attributes.add("myNumber");

  attributes.add("myString");

  attributes.add("myEnum");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Fred::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("x", XFredAllowedAttributes, pkgVersion, level,
        version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("x", XFredAllowedCoreAttributes, pkgVersion, level,
        version, details);
    }
  }

  // 
  // identifier SId (use = "required" )
  // 

  assigned = attributes.readInto("identifier", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<Fred>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(InvalidIdSyntax, level, version, "The id '" + mId + "' does not "
        "conform to the syntax.");
    }
  }
  else
  {
    std::string message = "X attribute 'identifier' is missing from the <Fred> "
      "element.";
    log->logPackageError("x", XFredAllowedAttributes, pkgVersion, level,
      version, message);
  }

  // 
  // myBoolean bool (use = "optional" )
  // 

  mIsSetBool = attributes.readInto("myBoolean", mBool);

  // 
  // myNumber int (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNum = attributes.readInto("myNumber", mNum);

  if ( mIsSetNum == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "X attribute 'myNumber' from the <Fred> element "
        "must be an integer.";
      log->logPackageError("x", XFredMyNumberMustBeInteger, pkgVersion, level,
        version, message);
    }
    else
    {
      std::string message = "X attribute 'myNumber' is missing from the <Fred> "
        "element.";
      log->logPackageError("x", XFredAllowedAttributes, pkgVersion, level,
        version, message);
    }
  }

  // 
  // myString string (use = "optional" )
  // 

  assigned = attributes.readInto("myString", mStr);

  if (assigned == true)
  {
    if (mStr.empty() == true)
    {
      logEmptyString(mStr, level, version, "<Fred>");
    }
  }

  // 
  // myEnum enum (use = "optional" )
  // 

  std::string myenum;
  assigned = attributes.readInto("myEnum", myenum);

  if (assigned == true)
  {
    if (myenum.empty() == true)
    {
      logEmptyString(myenum, level, version, "<Fred>");
    }
    else
    {
      mKind = Kind_fromString(myenum.c_str());

      if (Kind_isValid(mKind) == 0)
      {
        std::string msg = "The myEnum on the <Fred> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + myenum + "', which is not a valid option.";

        log->logPackageError("x", XFredMyEnumMustBeKindEnum, pkgVersion, level,
          version, msg);
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
Fred::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("identifier", getPrefix(), mId);
  }

  if (isSetBool() == true)
  {
    stream.writeAttribute("myBoolean", getPrefix(), mBool);
  }

  if (isSetNum() == true)
  {
    stream.writeAttribute("myNumber", getPrefix(), mNum);
  }

  if (isSetStr() == true)
  {
    stream.writeAttribute("myString", getPrefix(), mStr);
  }

  if (isSetKind() == true)
  {
    stream.writeAttribute("myEnum", getPrefix(), Kind_toString(mKind));
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Fred_t using the given SBML Level, Version and &ldquo;x&rdquo;
 * package version.
 */
LIBSBML_EXTERN
Fred_t *
Fred_create(unsigned int level, unsigned int version, unsigned int pkgVersion)
{
  return new Fred(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Fred_t object.
 */
LIBSBML_EXTERN
Fred_t*
Fred_clone(const Fred_t* f)
{
  if (f != NULL)
  {
    return static_cast<Fred_t*>(f->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Fred_t object.
 */
LIBSBML_EXTERN
void
Fred_free(Fred_t* f)
{
  if (f != NULL)
  {
    delete f;
  }
}


/*
 * Returns the value of the "id" attribute of this Fred_t.
 */
LIBSBML_EXTERN
const char *
Fred_getId(const Fred_t * f)
{
  if (f == NULL)
  {
    return NULL;
  }

  return f->getId().empty() ? NULL : safe_strdup(f->getId().c_str());
}


/*
 * Returns the value of the "bool" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_getBool(const Fred_t * f)
{
  return (f != NULL) ? static_cast<int>(f->getBool()) : 0;
}


/*
 * Returns the value of the "num" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_getNum(const Fred_t * f)
{
  return (f != NULL) ? f->getNum() : SBML_INT_MAX;
}


/*
 * Returns the value of the "str" attribute of this Fred_t.
 */
LIBSBML_EXTERN
const char *
Fred_getStr(const Fred_t * f)
{
  if (f == NULL)
  {
    return NULL;
  }

  return f->getStr().empty() ? NULL : safe_strdup(f->getStr().c_str());
}


/*
 * Returns the value of the "kind" attribute of this Fred_t.
 */
LIBSBML_EXTERN
Kind_t
Fred_getKind(const Fred_t * f)
{
  if (f == NULL)
  {
    return KIND_INVALID;
  }

  return f->getKind();
}


/*
 * Returns the value of the "kind" attribute of this Fred_t.
 */
LIBSBML_EXTERN
const char *
Fred_getKindAsString(const Fred_t * f)
{
  return Kind_toString(f->getKind());
}


/*
 * Predicate returning @c 1 if this Fred_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
Fred_isSetId(const Fred_t * f)
{
  return (f != NULL) ? static_cast<int>(f->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this Fred_t's "bool" attribute is set.
 */
LIBSBML_EXTERN
int
Fred_isSetBool(const Fred_t * f)
{
  return (f != NULL) ? static_cast<int>(f->isSetBool()) : 0;
}


/*
 * Predicate returning @c 1 if this Fred_t's "num" attribute is set.
 */
LIBSBML_EXTERN
int
Fred_isSetNum(const Fred_t * f)
{
  return (f != NULL) ? static_cast<int>(f->isSetNum()) : 0;
}


/*
 * Predicate returning @c 1 if this Fred_t's "str" attribute is set.
 */
LIBSBML_EXTERN
int
Fred_isSetStr(const Fred_t * f)
{
  return (f != NULL) ? static_cast<int>(f->isSetStr()) : 0;
}


/*
 * Predicate returning @c 1 if this Fred_t's "kind" attribute is set.
 */
LIBSBML_EXTERN
int
Fred_isSetKind(const Fred_t * f)
{
  return (f != NULL) ? static_cast<int>(f->isSetKind()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_setId(Fred_t * f, const char * id)
{
  return (f != NULL) ? f->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "bool" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_setBool(Fred_t * f, int bool)
{
  return (f != NULL) ? f->setBool(bool) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "num" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_setNum(Fred_t * f, int num)
{
  return (f != NULL) ? f->setNum(num) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "str" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_setStr(Fred_t * f, const char * str)
{
  return (f != NULL) ? f->setStr(str) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "kind" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_setKind(Fred_t * f, Kind_t kind)
{
  return (f != NULL) ? f->setKind(kind) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "kind" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_setKindAsString(Fred_t * f, const char * kind)
{
  return (f != NULL) ? f->setKind(kind): LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_unsetId(Fred_t * f)
{
  return (f != NULL) ? f->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "bool" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_unsetBool(Fred_t * f)
{
  return (f != NULL) ? f->unsetBool() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "num" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_unsetNum(Fred_t * f)
{
  return (f != NULL) ? f->unsetNum() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "str" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_unsetStr(Fred_t * f)
{
  return (f != NULL) ? f->unsetStr() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "kind" attribute of this Fred_t.
 */
LIBSBML_EXTERN
int
Fred_unsetKind(Fred_t * f)
{
  return (f != NULL) ? f->unsetKind() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this Fred_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Fred_hasRequiredAttributes(const Fred_t * f)
{
  return (f != NULL) ? static_cast<int>(f->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


