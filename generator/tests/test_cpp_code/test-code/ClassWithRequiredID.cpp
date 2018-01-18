/**
 * @file ClassWithRequiredID.cpp
 * @brief Implementation of the ClassWithRequiredID class.
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
#include <sbml/packages/twoatonce/sbml/ClassWithRequiredID.h>
#include <sbml/packages/twoatonce/validator/TwoatonceSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ClassWithRequiredID using the given SBML Level, Version and
 * &ldquo;twoatonce&rdquo; package version.
 */
ClassWithRequiredID::ClassWithRequiredID(unsigned int level,
                                         unsigned int version,
                                         unsigned int pkgVersion)
  : SBase(level, version)
{
  setSBMLNamespacesAndOwn(new TwoatoncePkgNamespaces(level, version,
    pkgVersion));
}


/*
 * Creates a new ClassWithRequiredID using the given TwoatoncePkgNamespaces
 * object.
 */
ClassWithRequiredID::ClassWithRequiredID(TwoatoncePkgNamespaces *twoatoncens)
  : SBase(twoatoncens)
{
  setElementNamespace(twoatoncens->getURI());
  loadPlugins(twoatoncens);
}


/*
 * Copy constructor for ClassWithRequiredID.
 */
ClassWithRequiredID::ClassWithRequiredID(const ClassWithRequiredID& orig)
  : SBase( orig )
{
}


/*
 * Assignment operator for ClassWithRequiredID.
 */
ClassWithRequiredID&
ClassWithRequiredID::operator=(const ClassWithRequiredID& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ClassWithRequiredID object.
 */
ClassWithRequiredID*
ClassWithRequiredID::clone() const
{
  return new ClassWithRequiredID(*this);
}


/*
 * Destructor for ClassWithRequiredID.
 */
ClassWithRequiredID::~ClassWithRequiredID()
{
}


/*
 * Returns the value of the "id" attribute of this ClassWithRequiredID.
 */
const std::string&
ClassWithRequiredID::getId() const
{
  return mId;
}


/*
 * Predicate returning @c true if this ClassWithRequiredID's "id" attribute is
 * set.
 */
bool
ClassWithRequiredID::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Unsets the value of the "id" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::unsetId()
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
 * Returns the XML element name of this ClassWithRequiredID object.
 */
const std::string&
ClassWithRequiredID::getElementName() const
{
  static const string name = "classWithRequiredID";
  return name;
}


/*
 * Returns the libSBML type code for this ClassWithRequiredID object.
 */
int
ClassWithRequiredID::getTypeCode() const
{
  return SBML_TWOATONCE_CLASSWITHREQUIREDID;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * ClassWithRequiredID object have been set.
 */
bool
ClassWithRequiredID::hasRequiredAttributes() const
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
ClassWithRequiredID::writeElements(XMLOutputStream& stream) const
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
ClassWithRequiredID::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
ClassWithRequiredID::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
ClassWithRequiredID::enablePackageInternal(const std::string& pkgURI,
                                           const std::string& pkgPrefix,
                                           bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::getAttribute(const std::string& attributeName,
                                  bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::getAttribute(const std::string& attributeName,
                                  int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::getAttribute(const std::string& attributeName,
                                  double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::getAttribute(const std::string& attributeName,
                                  unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::getAttribute(const std::string& attributeName,
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
 * Predicate returning @c true if this ClassWithRequiredID's attribute
 * "attributeName" is set.
 */
bool
ClassWithRequiredID::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::setAttribute(const std::string& attributeName,
                                  bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::setAttribute(const std::string& attributeName,
                                  double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::setAttribute(const std::string& attributeName,
                                  unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassWithRequiredID.
 */
int
ClassWithRequiredID::setAttribute(const std::string& attributeName,
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
 * Unsets the value of the "attributeName" attribute of this
 * ClassWithRequiredID.
 */
int
ClassWithRequiredID::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
ClassWithRequiredID::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  unsigned int level = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && coreVersion == 1 && pkgVersion == 1)
  {
    attributes.add("id");
  }

  if (level == 3 && coreVersion == 2 && pkgVersion == 1)
  {
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassWithRequiredID::readAttributes(const XMLAttributes& attributes,
                                    const ExpectedAttributes&
                                      expectedAttributes)
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
      log->logPackageError("twoatonce",
        TwoatonceClassWithRequiredIDAllowedAttributes, pkgVersion, level,
          version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("twoatonce",
        TwoatonceClassWithRequiredIDAllowedCoreAttributes, pkgVersion, level,
          version, details);
    }
  }

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    readL3V1V1Attributes(attributes);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    readL3V2V1Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassWithRequiredID::readL3V1V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<ClassWithRequiredID>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("twoatonce", TwoatonceIdSyntaxRule, pkgVersion,
        level, version, "The id on the <" + getElementName() + "> is '" + mId +
          "', which does not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Twoatonce attribute 'id' is missing from the "
      "<ClassWithRequiredID> element.";
    log->logPackageError("twoatonce",
      TwoatonceClassWithRequiredIDAllowedAttributes, pkgVersion, level, version,
        message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ClassWithRequiredID::readL3V2V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<ClassWithRequiredID>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("twoatonce", TwoatonceIdSyntaxRule, pkgVersion,
        level, version, "The id on the <" + getElementName() + "> is '" + mId +
          "', which does not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Twoatonce attribute 'id' is missing from the "
      "<ClassWithRequiredID> element.";
    log->logPackageError("twoatonce",
      TwoatonceClassWithRequiredIDAllowedAttributes, pkgVersion, level, version,
        message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassWithRequiredID::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    writeL3V1V1Attributes(stream);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    writeL3V2V1Attributes(stream);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassWithRequiredID::writeL3V1V1Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ClassWithRequiredID::writeL3V2V1Attributes(XMLOutputStream& stream) const
{
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ClassWithRequiredID_t using the given SBML Level, Version and
 * &ldquo;twoatonce&rdquo; package version.
 */
LIBSBML_EXTERN
ClassWithRequiredID_t *
ClassWithRequiredID_create(unsigned int level,
                           unsigned int version,
                           unsigned int pkgVersion)
{
  return new ClassWithRequiredID(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ClassWithRequiredID_t object.
 */
LIBSBML_EXTERN
ClassWithRequiredID_t*
ClassWithRequiredID_clone(const ClassWithRequiredID_t* cwrid)
{
  if (cwrid != NULL)
  {
    return static_cast<ClassWithRequiredID_t*>(cwrid->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ClassWithRequiredID_t object.
 */
LIBSBML_EXTERN
void
ClassWithRequiredID_free(ClassWithRequiredID_t* cwrid)
{
  if (cwrid != NULL)
  {
    delete cwrid;
  }
}


/*
 * Returns the value of the "id" attribute of this ClassWithRequiredID_t.
 */
LIBSBML_EXTERN
char *
ClassWithRequiredID_getId(const ClassWithRequiredID_t * cwrid)
{
  if (cwrid == NULL)
  {
    return NULL;
  }

  return cwrid->getId().empty() ? NULL : safe_strdup(cwrid->getId().c_str());
}


/*
 * Predicate returning @c 1 (true) if this ClassWithRequiredID_t's "id"
 * attribute is set.
 */
LIBSBML_EXTERN
int
ClassWithRequiredID_isSetId(const ClassWithRequiredID_t * cwrid)
{
  return (cwrid != NULL) ? static_cast<int>(cwrid->isSetId()) : 0;
}


/*
 * Sets the value of the "id" attribute of this ClassWithRequiredID_t.
 */
LIBSBML_EXTERN
int
ClassWithRequiredID_setId(ClassWithRequiredID_t * cwrid, const char * id)
{
  return (cwrid != NULL) ? cwrid->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this ClassWithRequiredID_t.
 */
LIBSBML_EXTERN
int
ClassWithRequiredID_unsetId(ClassWithRequiredID_t * cwrid)
{
  return (cwrid != NULL) ? cwrid->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * ClassWithRequiredID_t object have been set.
 */
LIBSBML_EXTERN
int
ClassWithRequiredID_hasRequiredAttributes(const ClassWithRequiredID_t * cwrid)
{
  return (cwrid != NULL) ? static_cast<int>(cwrid->hasRequiredAttributes()) :
    0;
}




LIBSBML_CPP_NAMESPACE_END


