/**
 * @file ClassOne.cpp
 * @brief Implementation of the ClassOne class.
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
#include <sbml/packages/vers/sbml/ClassOne.h>
#include <sbml/packages/vers/validator/VersSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ClassOne using the given SBML Level, Version and
 * &ldquo;vers&rdquo; package version.
 */
ClassOne::ClassOne(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mAtt1 (false)
  , mIsSetAtt1 (false)
  , mAtt2 (false)
  , mIsSetAtt2 (false)
{
  setSBMLNamespacesAndOwn(new VersPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ClassOne using the given VersPkgNamespaces object.
 */
ClassOne::ClassOne(VersPkgNamespaces *versns)
  : SBase(versns)
  , mId ("")
  , mAtt1 (false)
  , mIsSetAtt1 (false)
  , mAtt2 (false)
  , mIsSetAtt2 (false)
{
  setElementNamespace(versns->getURI());
  loadPlugins(versns);
}


/*
 * Copy constructor for ClassOne.
 */
ClassOne::ClassOne(const ClassOne& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mAtt1 ( orig.mAtt1 )
  , mIsSetAtt1 ( orig.mIsSetAtt1 )
  , mAtt2 ( orig.mAtt2 )
  , mIsSetAtt2 ( orig.mIsSetAtt2 )
{
}


/*
 * Assignment operator for ClassOne.
 */
ClassOne&
ClassOne::operator=(const ClassOne& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mAtt1 = rhs.mAtt1;
    mIsSetAtt1 = rhs.mIsSetAtt1;
    mAtt2 = rhs.mAtt2;
    mIsSetAtt2 = rhs.mIsSetAtt2;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ClassOne object.
 */
ClassOne*
ClassOne::clone() const
{
  return new ClassOne(*this);
}


/*
 * Destructor for ClassOne.
 */
ClassOne::~ClassOne()
{
}


/*
 * Returns the value of the "id" attribute of this ClassOne.
 */
const std::string&
ClassOne::getId() const
{
  return mId;
}


/*
 * Returns the value of the "att1" attribute of this ClassOne.
 */
bool
ClassOne::getAtt1() const
{
  return mAtt1;
}


/*
 * Returns the value of the "att2" attribute of this ClassOne.
 */
bool
ClassOne::getAtt2() const
{
  return mAtt2;
}


/*
 * Predicate returning @c true if this ClassOne's "id" attribute is set.
 */
bool
ClassOne::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this ClassOne's "att1" attribute is set.
 */
bool
ClassOne::isSetAtt1() const
{
  return mIsSetAtt1;
}


/*
 * Predicate returning @c true if this ClassOne's "att2" attribute is set.
 */
bool
ClassOne::isSetAtt2() const
{
  return mIsSetAtt2;
}


/*
 * Sets the value of the "id" attribute of this ClassOne.
 */
int
ClassOne::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "att1" attribute of this ClassOne.
 */
int
ClassOne::setAtt1(bool att1)
{
  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    mAtt1 = att1;
    mIsSetAtt1 = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    mAtt1 = att1;
    mIsSetAtt1 = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "att2" attribute of this ClassOne.
 */
int
ClassOne::setAtt2(bool att2)
{
  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    mAtt2 = att2;
    mIsSetAtt2 = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
  else
  {
    mAtt2 = att2;
    mIsSetAtt2 = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "id" attribute of this ClassOne.
 */
int
ClassOne::unsetId()
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
 * Unsets the value of the "att1" attribute of this ClassOne.
 */
int
ClassOne::unsetAtt1()
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
 * Unsets the value of the "att2" attribute of this ClassOne.
 */
int
ClassOne::unsetAtt2()
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
 * Returns the XML element name of this ClassOne object.
 */
const std::string&
ClassOne::getElementName() const
{
  static const string name = "classOne";
  return name;
}


/*
 * Returns the libSBML type code for this ClassOne object.
 */
int
ClassOne::getTypeCode() const
{
  return CLASS_ONE;
}


/*
 * Predicate returning @c true if all the required attributes for this ClassOne
 * object have been set.
 */
bool
ClassOne::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
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
ClassOne::writeElements(XMLOutputStream& stream) const
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
ClassOne::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
ClassOne::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
ClassOne::enablePackageInternal(const std::string& pkgURI,
                                const std::string& pkgPrefix,
                                bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassOne.
 */
int
ClassOne::getAttribute(const std::string& attributeName, bool& value) const
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
 * Gets the value of the "attributeName" attribute of this ClassOne.
 */
int
ClassOne::getAttribute(const std::string& attributeName,
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

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this ClassOne's attribute "attributeName" is
 * set.
 */
bool
ClassOne::isSetAttribute(const std::string& attributeName) const
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
  else if (attributeName == "att2")
  {
    value = isSetAtt2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassOne.
 */
int
ClassOne::setAttribute(const std::string& attributeName, bool value)
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
 * Sets the value of the "attributeName" attribute of this ClassOne.
 */
int
ClassOne::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this ClassOne.
 */
int
ClassOne::unsetAttribute(const std::string& attributeName)
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
  else if (attributeName == "att2")
  {
    value = unsetAtt2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
ClassOne::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    attributes.add("id");
    attributes.add("att1");
  }
  else
  {
    attributes.add("id");
    attributes.add("att2");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassOne::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("vers", VersClassOneAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("vers", VersClassOneAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  if (pkgVersion == 1)
  {
    readV1Attributes(attributes);
  }
  else
  {
    readV2Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassOne::readV1Attributes(const XMLAttributes& attributes)
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
      logEmptyString(mId, level, version, "<ClassOne>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(VersIdSyntaxRule, level, version, "The id '" + mId + "' does not "
        "conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Vers attribute 'id' is missing from the <ClassOne> "
      "element.";
    log->logPackageError("vers", VersClassOneAllowedAttributes, pkgVersion,
      level, version, message);
  }

  // 
  // att1 bool (use = "optional" )
  // 

  mIsSetAtt1 = attributes.readInto("att1", mAtt1);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassOne::readV2Attributes(const XMLAttributes& attributes)
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
      logEmptyString(mId, level, version, "<ClassOne>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(VersIdSyntaxRule, level, version, "The id '" + mId + "' does not "
        "conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Vers attribute 'id' is missing from the <ClassOne> "
      "element.";
    log->logPackageError("vers", VersClassOneAllowedAttributes, pkgVersion,
      level, version, message);
  }

  // 
  // att2 bool (use = "optional" )
  // 

  mIsSetAtt2 = attributes.readInto("att2", mAtt2);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassOne::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    writeV1Attributes(stream);
  }
  else
  {
    writeV2Attributes(stream);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassOne::writeV1Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetAtt1() == true)
  {
    stream.writeAttribute("att1", getPrefix(), mAtt1);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassOne::writeV2Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetAtt2() == true)
  {
    stream.writeAttribute("att2", getPrefix(), mAtt2);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ClassOne_t using the given SBML Level, Version and
 * &ldquo;vers&rdquo; package version.
 */
LIBSBML_EXTERN
ClassOne_t *
ClassOne_create(unsigned int level,
                unsigned int version,
                unsigned int pkgVersion)
{
  return new ClassOne(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ClassOne_t object.
 */
LIBSBML_EXTERN
ClassOne_t*
ClassOne_clone(const ClassOne_t* co)
{
  if (co != NULL)
  {
    return static_cast<ClassOne_t*>(co->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ClassOne_t object.
 */
LIBSBML_EXTERN
void
ClassOne_free(ClassOne_t* co)
{
  if (co != NULL)
  {
    delete co;
  }
}


/*
 * Returns the value of the "id" attribute of this ClassOne_t.
 */
LIBSBML_EXTERN
const char *
ClassOne_getId(const ClassOne_t * co)
{
  if (co == NULL)
  {
    return NULL;
  }

  return co->getId().empty() ? NULL : safe_strdup(co->getId().c_str());
}


/*
 * Returns the value of the "att1" attribute of this ClassOne_t.
 */
LIBSBML_EXTERN
int
ClassOne_getAtt1(const ClassOne_t * co)
{
  return (co != NULL) ? static_cast<int>(co->getAtt1()) : 0;
}


/*
 * Returns the value of the "att2" attribute of this ClassOne_t.
 */
LIBSBML_EXTERN
int
ClassOne_getAtt2(const ClassOne_t * co)
{
  return (co != NULL) ? static_cast<int>(co->getAtt2()) : 0;
}


/*
 * Predicate returning @c 1 if this ClassOne_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
ClassOne_isSetId(const ClassOne_t * co)
{
  return (co != NULL) ? static_cast<int>(co->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this ClassOne_t's "att1" attribute is set.
 */
LIBSBML_EXTERN
int
ClassOne_isSetAtt1(const ClassOne_t * co)
{
  return (co != NULL) ? static_cast<int>(co->isSetAtt1()) : 0;
}


/*
 * Predicate returning @c 1 if this ClassOne_t's "att2" attribute is set.
 */
LIBSBML_EXTERN
int
ClassOne_isSetAtt2(const ClassOne_t * co)
{
  return (co != NULL) ? static_cast<int>(co->isSetAtt2()) : 0;
}


/*
 * Sets the value of the "id" attribute of this ClassOne_t.
 */
LIBSBML_EXTERN
int
ClassOne_setId(ClassOne_t * co, const char * id)
{
  return (co != NULL) ? co->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "att1" attribute of this ClassOne_t.
 */
LIBSBML_EXTERN
int
ClassOne_setAtt1(ClassOne_t * co, int att1)
{
  return (co != NULL) ? co->setAtt1(att1) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "att2" attribute of this ClassOne_t.
 */
LIBSBML_EXTERN
int
ClassOne_setAtt2(ClassOne_t * co, int att2)
{
  return (co != NULL) ? co->setAtt2(att2) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this ClassOne_t.
 */
LIBSBML_EXTERN
int
ClassOne_unsetId(ClassOne_t * co)
{
  return (co != NULL) ? co->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "att1" attribute of this ClassOne_t.
 */
LIBSBML_EXTERN
int
ClassOne_unsetAtt1(ClassOne_t * co)
{
  return (co != NULL) ? co->unsetAtt1() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "att2" attribute of this ClassOne_t.
 */
LIBSBML_EXTERN
int
ClassOne_unsetAtt2(ClassOne_t * co)
{
  return (co != NULL) ? co->unsetAtt2() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this ClassOne_t
 * object have been set.
 */
LIBSBML_EXTERN
int
ClassOne_hasRequiredAttributes(const ClassOne_t * co)
{
  return (co != NULL) ? static_cast<int>(co->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


