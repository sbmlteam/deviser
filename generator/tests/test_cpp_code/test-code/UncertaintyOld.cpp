/**
 * @file UncertaintyOld.cpp
 * @brief Implementation of the UncertaintyOld class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
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
#include <sbml/packages/distrib/sbml/UncertaintyOld.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new UncertaintyOld using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
UncertaintyOld::UncertaintyOld(unsigned int level,
                               unsigned int version,
                               unsigned int pkgVersion)
  : SBase(level, version)
  , mUncertML (NULL)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new UncertaintyOld using the given DistribPkgNamespaces object.
 */
UncertaintyOld::UncertaintyOld(DistribPkgNamespaces *distribns)
  : SBase(distribns)
  , mUncertML (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for UncertaintyOld.
 */
UncertaintyOld::UncertaintyOld(const UncertaintyOld& orig)
  : SBase( orig )
  , mUncertML ( NULL )
{
  if (orig.mUncertML != NULL)
  {
    mUncertML = orig.mUncertML->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for UncertaintyOld.
 */
UncertaintyOld&
UncertaintyOld::operator=(const UncertaintyOld& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
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
 * Creates and returns a deep copy of this UncertaintyOld object.
 */
UncertaintyOld*
UncertaintyOld::clone() const
{
  return new UncertaintyOld(*this);
}


/*
 * Destructor for UncertaintyOld.
 */
UncertaintyOld::~UncertaintyOld()
{
  delete mUncertML;
  mUncertML = NULL;
}


/*
 * Returns the value of the "id" attribute of this UncertaintyOld.
 */
const std::string&
UncertaintyOld::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this UncertaintyOld.
 */
const std::string&
UncertaintyOld::getName() const
{
  return mName;
}


/*
 * Predicate returning @c true if this UncertaintyOld's "id" attribute is set.
 */
bool
UncertaintyOld::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this UncertaintyOld's "name" attribute is
 * set.
 */
bool
UncertaintyOld::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "name" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::setName(const std::string& name)
{
  mName = name;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::unsetId()
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
 * Unsets the value of the "name" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::unsetName()
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
 * Returns the value of the "UncertML" element of this UncertaintyOld.
 */
const UncertMLNode*
UncertaintyOld::getUncertML() const
{
  return mUncertML;
}


/*
 * Returns the value of the "UncertML" element of this UncertaintyOld.
 */
UncertMLNode*
UncertaintyOld::getUncertML()
{
  return mUncertML;
}


/*
 * Predicate returning @c true if this UncertaintyOld's "UncertML" element is
 * set.
 */
bool
UncertaintyOld::isSetUncertML() const
{
  return (mUncertML != NULL);
}


/*
 * Sets the value of the "UncertML" element of this UncertaintyOld.
 */
int
UncertaintyOld::setUncertML(const UncertMLNode* uncertML)
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
 * Unsets the value of the "UncertML" element of this UncertaintyOld.
 */
int
UncertaintyOld::unsetUncertML()
{
  delete mUncertML;
  mUncertML = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this UncertaintyOld object.
 */
const std::string&
UncertaintyOld::getElementName() const
{
  static const string name = "uncertaintyOld";
  return name;
}


/*
 * Returns the libSBML type code for this UncertaintyOld object.
 */
int
UncertaintyOld::getTypeCode() const
{
  return SBML_DISTRIB_UNCERTAINTY;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * UncertaintyOld object have been set.
 */
bool
UncertaintyOld::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * UncertaintyOld object have been set.
 */
bool
UncertaintyOld::hasRequiredElements() const
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
UncertaintyOld::writeElements(XMLOutputStream& stream) const
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
UncertaintyOld::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
UncertaintyOld::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
UncertaintyOld::connectToChild()
{
  SBase::connectToChild();
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
UncertaintyOld::enablePackageInternal(const std::string& pkgURI,
                                      const std::string& pkgPrefix,
                                      bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
UncertaintyOld::updateSBMLNamespace(const std::string& package,
                                    unsigned int level,
                                    unsigned int version)
{
  SBase::updateSBMLNamespace(package, level, version);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::getAttribute(const std::string& attributeName,
                             bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::getAttribute(const std::string& attributeName,
                             int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::getAttribute(const std::string& attributeName,
                             double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::getAttribute(const std::string& attributeName,
                             unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::getAttribute(const std::string& attributeName,
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

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this UncertaintyOld's attribute
 * "attributeName" is set.
 */
bool
UncertaintyOld::isSetAttribute(const std::string& attributeName) const
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

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::setAttribute(const std::string& attributeName,
                             unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::setAttribute(const std::string& attributeName,
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

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this UncertaintyOld.
 */
int
UncertaintyOld::unsetAttribute(const std::string& attributeName)
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

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this UncertaintyOld.
 */
SBase*
UncertaintyOld::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "uncertML")
  {
    return createUncertML();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this UncertaintyOld.
 */
int
UncertaintyOld::addChildObject(const std::string& elementName,
                               const SBase* element)
{
  if (elementName == "uncertML" && element->getTypeCode() == TO_DO)
  {
    return setUncertML((const UncertMLNode*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * UncertaintyOld.
 */
SBase*
UncertaintyOld::removeChildObject(const std::string& elementName,
                                  const std::string& id)
{
  if (elementName == "uncertML")
  {
    UncertMLNode * obj = getUncertML();
    if (unsetUncertML() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this UncertaintyOld.
 */
unsigned int
UncertaintyOld::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "uncertML")
  {
    if (isSetUncertML())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this UncertaintyOld.
 */
SBase*
UncertaintyOld::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "uncertML")
  {
    return getUncertML();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
UncertaintyOld::addExpectedAttributes(ExpectedAttributes& attributes)
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
UncertaintyOld::readAttributes(const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("distrib", DistribUncertaintyOldAllowedAttributes,
          pkgVersion, level, version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("distrib",
          DistribUncertaintyOldAllowedCoreAttributes, pkgVersion, level, version,
            details, getLine(), getColumn());
      }
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
      logEmptyString(mId, level, version, "<UncertaintyOld>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("distrib", DistribIdSyntaxRule, pkgVersion, level,
        version, "The id on the <" + getElementName() + "> is '" + mId + "', "
          "which does not conform to the syntax.", getLine(), getColumn());
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
      logEmptyString(mName, level, version, "<UncertaintyOld>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
UncertaintyOld::readOtherXML(XMLInputStream& stream)
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
UncertaintyOld::writeAttributes(XMLOutputStream& stream) const
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
 * Creates a new UncertaintyOld_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
UncertaintyOld_t *
UncertaintyOld_create(unsigned int level,
                      unsigned int version,
                      unsigned int pkgVersion)
{
  return new UncertaintyOld(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this UncertaintyOld_t object.
 */
LIBSBML_EXTERN
UncertaintyOld_t*
UncertaintyOld_clone(const UncertaintyOld_t* uo)
{
  if (uo != NULL)
  {
    return static_cast<UncertaintyOld_t*>(uo->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this UncertaintyOld_t object.
 */
LIBSBML_EXTERN
void
UncertaintyOld_free(UncertaintyOld_t* uo)
{
  if (uo != NULL)
  {
    delete uo;
  }
}


/*
 * Returns the value of the "id" attribute of this UncertaintyOld_t.
 */
LIBSBML_EXTERN
char *
UncertaintyOld_getId(const UncertaintyOld_t * uo)
{
  if (uo == NULL)
  {
    return NULL;
  }

  return uo->getId().empty() ? NULL : safe_strdup(uo->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this UncertaintyOld_t.
 */
LIBSBML_EXTERN
char *
UncertaintyOld_getName(const UncertaintyOld_t * uo)
{
  if (uo == NULL)
  {
    return NULL;
  }

  return uo->getName().empty() ? NULL : safe_strdup(uo->getName().c_str());
}


/*
 * Predicate returning @c 1 (true) if this UncertaintyOld_t's "id" attribute is
 * set.
 */
LIBSBML_EXTERN
int
UncertaintyOld_isSetId(const UncertaintyOld_t * uo)
{
  return (uo != NULL) ? static_cast<int>(uo->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this UncertaintyOld_t's "name" attribute
 * is set.
 */
LIBSBML_EXTERN
int
UncertaintyOld_isSetName(const UncertaintyOld_t * uo)
{
  return (uo != NULL) ? static_cast<int>(uo->isSetName()) : 0;
}


/*
 * Sets the value of the "id" attribute of this UncertaintyOld_t.
 */
LIBSBML_EXTERN
int
UncertaintyOld_setId(UncertaintyOld_t * uo, const char * id)
{
  return (uo != NULL) ? uo->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this UncertaintyOld_t.
 */
LIBSBML_EXTERN
int
UncertaintyOld_setName(UncertaintyOld_t * uo, const char * name)
{
  return (uo != NULL) ? uo->setName(name) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this UncertaintyOld_t.
 */
LIBSBML_EXTERN
int
UncertaintyOld_unsetId(UncertaintyOld_t * uo)
{
  return (uo != NULL) ? uo->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this UncertaintyOld_t.
 */
LIBSBML_EXTERN
int
UncertaintyOld_unsetName(UncertaintyOld_t * uo)
{
  return (uo != NULL) ? uo->unsetName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "UncertML" element of this UncertaintyOld_t.
 */
LIBSBML_EXTERN
const UncertMLNode_t*
UncertaintyOld_getUncertML(const UncertaintyOld_t * uo)
{
  if (uo == NULL)
  {
    return NULL;
  }

  return (UncertMLNode_t*)(uo->getUncertML());
}


/*
 * Predicate returning @c 1 (true) if this UncertaintyOld_t's "UncertML"
 * element is set.
 */
LIBSBML_EXTERN
int
UncertaintyOld_isSetUncertML(const UncertaintyOld_t * uo)
{
  return (uo != NULL) ? static_cast<int>(uo->isSetUncertML()) : 0;
}


/*
 * Sets the value of the "UncertML" element of this UncertaintyOld_t.
 */
LIBSBML_EXTERN
int
UncertaintyOld_setUncertML(UncertaintyOld_t * uo,
                           const UncertMLNode_t* uncertML)
{
  return (uo != NULL) ? uo->setUncertML(uncertML) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "UncertML" element of this UncertaintyOld_t.
 */
LIBSBML_EXTERN
int
UncertaintyOld_unsetUncertML(UncertaintyOld_t * uo)
{
  return (uo != NULL) ? uo->unsetUncertML() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * UncertaintyOld_t object have been set.
 */
LIBSBML_EXTERN
int
UncertaintyOld_hasRequiredAttributes(const UncertaintyOld_t * uo)
{
  return (uo != NULL) ? static_cast<int>(uo->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * UncertaintyOld_t object have been set.
 */
LIBSBML_EXTERN
int
UncertaintyOld_hasRequiredElements(const UncertaintyOld_t * uo)
{
  return (uo != NULL) ? static_cast<int>(uo->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


