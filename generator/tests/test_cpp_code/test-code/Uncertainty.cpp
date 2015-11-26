/**
 * @file Uncertainty.cpp
 * @brief Implementation of Uncertainty.
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
#include <sbml/packages/distrib/sbml/Uncertainty.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Uncertainty using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
Uncertainty::Uncertainty(unsigned int level,
                         unsigned int version,
                         unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mName ("")
  , mUncertML (NULL)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new Uncertainty using the given DistribPkgNamespaces object.
 */
Uncertainty::Uncertainty(DistribPkgNamespaces *distribns)
  : SBase(distribns)
  , mId ("")
  , mName ("")
  , mUncertML (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for Uncertainty.
 */
Uncertainty::Uncertainty(const Uncertainty& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mName ( orig.mName )
  , mUncertML ( NULL )
{
  if (orig.mUncertML != NULL)
  {
    mUncertML = orig.mUncertML->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Uncertainty.
 */
Uncertainty&
Uncertainty::operator=(const Uncertainty& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mName = rhs.mName;
    delete mUncertML;
    if (rhs.mUncertML != NULL)
    {
      mUncertML = rhs.mUncertML->clone();
    }
    else
    {
      mUncertML = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Uncertainty object.
 */
Uncertainty*
Uncertainty::clone() const
{
  return new Uncertainty(*this);
}


/*
 * Destructor for Uncertainty.
 */
Uncertainty::~Uncertainty()
{
  delete mUncertML;
  mUncertML = NULL;
}


/*
 * Returns the value of the "id" attribute of this Uncertainty.
 */
const std::string&
Uncertainty::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this Uncertainty.
 */
const std::string&
Uncertainty::getName() const
{
  return mName;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * Uncertainty's "id" attribute has been set.
 */
bool
Uncertainty::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * Uncertainty's "name" attribute has been set.
 */
bool
Uncertainty::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this Uncertainty.
 */
int
Uncertainty::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "name" attribute of this Uncertainty.
 */
int
Uncertainty::setName(const std::string& name)
{
  mName = name;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this Uncertainty.
 */
int
Uncertainty::unsetId()
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
 * Unsets the value of the "name" attribute of this Uncertainty.
 */
int
Uncertainty::unsetName()
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
 * Returns the value of the "uncertML" element of this Uncertainty.
 */
const UncertMLNode*
Uncertainty::getUncertML() const
{
  return mUncertML;
}


/*
 * Returns the value of the "uncertML" element of this Uncertainty.
 */
UncertMLNode*
Uncertainty::getUncertML()
{
  return mUncertML;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * Uncertainty's "uncertML" element has been set.
 */
bool
Uncertainty::isSetUncertML() const
{
  return (mUncertML != NULL);
}


/*
 * Sets the value of the "uncertML" element of this Uncertainty.
 */
int
Uncertainty::setUncertML(const UncertMLNode* uncertML)
{
  if (mUncertML == uncertML)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (uncertML == NULL)
  {
    delete mUncertML;
    mUncertML = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mUncertML;
    mUncertML = (uncertML != NULL) ? uncertML->clone() : NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "uncertML" element of this Uncertainty.
 */
int
Uncertainty::unsetUncertML()
{
  delete mUncertML;
  mUncertML = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this Uncertainty object.
 */
const std::string&
Uncertainty::getElementName() const
{
  static const string name = "uncertainty";
  return name;
}


/*
 * Returns the libSBML type code for this Uncertainty object.
 */
int
Uncertainty::getTypeCode() const
{
  return SBML_DISTRIB_UNCERTAINTY;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * Uncertainty object have been set.
 */
bool
Uncertainty::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * Uncertainty object have been set.
 */
bool
Uncertainty::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetUncertML() == false)
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
Uncertainty::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetUncertML() == true)
  {
    mUncertML->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Uncertainty::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Uncertainty::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Uncertainty::connectToChild()
{
  SBase::connectToChild();
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Uncertainty::enablePackageInternal(const std::string& pkgURI,
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
Uncertainty::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("name");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Uncertainty::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("distrib", DistribUncertaintyAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("distrib", DistribUncertaintyAllowedCoreAttributes,
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
      logEmptyString(mId, level, version, "<Uncertainty>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(InvalidIdSyntax, level, version, "The id '" + mId + "' does not "
        "conform to the syntax.");
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
      logEmptyString(mName, level, version, "<Uncertainty>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
Uncertainty::readOtherXML(XMLInputStream& stream)
{
  bool read = false;
  const string& name = stream.peek().getName();

  if (name == "UncertML")
  {
    const XMLToken& token = stream.next();
    stream.skipText();
    delete mUncertML;
    XMLNode* xml = new XMLNode(stream);
    mUncertML = new UncertMLNode(xml);
    stream.skipPastEnd(token);
    delete xml;
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
Uncertainty::writeAttributes(XMLOutputStream& stream) const
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

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Uncertainty_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
Uncertainty_t *
Uncertainty_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
{
  return new Uncertainty(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Uncertainty_t object.
 */
LIBSBML_EXTERN
Uncertainty_t*
Uncertainty_clone(const Uncertainty_t* u)
{
  if (u != NULL)
  {
    return static_cast<Uncertainty_t*>(u->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Uncertainty_t object.
 */
LIBSBML_EXTERN
void
Uncertainty_free(Uncertainty_t* u)
{
  if (u != NULL)
  {
    delete u;
  }
}


/*
 * Returns the value of the "id" attribute of this Uncertainty_t.
 */
LIBSBML_EXTERN
const char *
Uncertainty_getId(const Uncertainty_t * u)
{
  if (u == NULL)
  {
    return NULL;
  }

  return u->getId().empty() ? NULL : safe_strdup(u->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this Uncertainty_t.
 */
LIBSBML_EXTERN
const char *
Uncertainty_getName(const Uncertainty_t * u)
{
  if (u == NULL)
  {
    return NULL;
  }

  return u->getName().empty() ? NULL : safe_strdup(u->getName().c_str());
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this Uncertainty_t's
 * "id" attribute has been set.
 */
LIBSBML_EXTERN
int
Uncertainty_isSetId(const Uncertainty_t * u)
{
  return (u != NULL) ? static_cast<int>(u->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this Uncertainty_t's
 * "name" attribute has been set.
 */
LIBSBML_EXTERN
int
Uncertainty_isSetName(const Uncertainty_t * u)
{
  return (u != NULL) ? static_cast<int>(u->isSetName()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_setId(Uncertainty_t * u, const char * id)
{
  return (u != NULL) ? u->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_setName(Uncertainty_t * u, const char * name)
{
  return (u != NULL) ? u->setName(name) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_unsetId(Uncertainty_t * u)
{
  return (u != NULL) ? u->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_unsetName(Uncertainty_t * u)
{
  return (u != NULL) ? u->unsetName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "uncertML" element of this Uncertainty_t.
 */
LIBSBML_EXTERN
const UncertMLNode_t*
Uncertainty_getUncertML(const Uncertainty_t * u)
{
  if (u == NULL)
  {
    return NULL;
  }

  return (UncertMLNode_t*)(u->getUncertML());
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this Uncertainty_t's
 * "uncertML" element has been set.
 */
LIBSBML_EXTERN
int
Uncertainty_isSetUncertML(const Uncertainty_t * u)
{
  return (u != NULL) ? static_cast<int>(u->isSetUncertML()) : 0;
}


/*
 * Sets the value of the "uncertML" element of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_setUncertML(Uncertainty_t * u, const UncertMLNode_t* uncertML)
{
  return (u != NULL) ? u->setUncertML(uncertML) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "uncertML" element of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_unsetUncertML(Uncertainty_t * u)
{
  return (u != NULL) ? u->unsetUncertML() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * Uncertainty_t object have been set.
 */
LIBSBML_EXTERN
int
Uncertainty_hasRequiredAttributes(const Uncertainty_t * u)
{
  return (u != NULL) ? static_cast<int>(u->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this Uncertainty_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Uncertainty_hasRequiredElements(const Uncertainty_t * u)
{
  return (u != NULL) ? static_cast<int>(u->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


