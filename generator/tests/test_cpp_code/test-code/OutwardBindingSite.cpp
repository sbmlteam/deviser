/**
 * @file OutwardBindingSite.cpp
 * @brief Implementation of the OutwardBindingSite class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
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
#include <sbml/packages/multi/sbml/OutwardBindingSite.h>
#include <sbml/packages/multi/sbml/ListOfOutwardBindingSites.h>
#include <sbml/packages/multi/validator/MultiSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new OutwardBindingSite using the given SBML Level, Version and
 * &ldquo;multi&rdquo; package version.
 */
OutwardBindingSite::OutwardBindingSite(unsigned int level,
                                       unsigned int version,
                                       unsigned int pkgVersion)
  : SBase(level, version)
  , mBindingStatus (BINDING_STATUS_INVALID)
  , mComponent ("")
{
  setSBMLNamespacesAndOwn(new MultiPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new OutwardBindingSite using the given MultiPkgNamespaces object.
 */
OutwardBindingSite::OutwardBindingSite(MultiPkgNamespaces *multins)
  : SBase(multins)
  , mBindingStatus (BINDING_STATUS_INVALID)
  , mComponent ("")
{
  setElementNamespace(multins->getURI());
  loadPlugins(multins);
}


/*
 * Copy constructor for OutwardBindingSite.
 */
OutwardBindingSite::OutwardBindingSite(const OutwardBindingSite& orig)
  : SBase( orig )
  , mBindingStatus ( orig.mBindingStatus )
  , mComponent ( orig.mComponent )
{
}


/*
 * Assignment operator for OutwardBindingSite.
 */
OutwardBindingSite&
OutwardBindingSite::operator=(const OutwardBindingSite& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mBindingStatus = rhs.mBindingStatus;
    mComponent = rhs.mComponent;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this OutwardBindingSite object.
 */
OutwardBindingSite*
OutwardBindingSite::clone() const
{
  return new OutwardBindingSite(*this);
}


/*
 * Destructor for OutwardBindingSite.
 */
OutwardBindingSite::~OutwardBindingSite()
{
}


/*
 * Returns the value of the "id" attribute of this OutwardBindingSite.
 */
const std::string&
OutwardBindingSite::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this OutwardBindingSite.
 */
const std::string&
OutwardBindingSite::getName() const
{
  return mName;
}


/*
 * Returns the value of the "bindingStatus" attribute of this
 * OutwardBindingSite.
 */
BindingStatus_t
OutwardBindingSite::getBindingStatus() const
{
  return mBindingStatus;
}


/*
 * Returns the value of the "bindingStatus" attribute of this
 * OutwardBindingSite.
 */
std::string
OutwardBindingSite::getBindingStatusAsString() const
{
  std::string code_str = BindingStatus_toString(mBindingStatus);
  return code_str;
}


/*
 * Returns the value of the "component" attribute of this OutwardBindingSite.
 */
const std::string&
OutwardBindingSite::getComponent() const
{
  return mComponent;
}


/*
 * Predicate returning @c true if this OutwardBindingSite's "id" attribute is
 * set.
 */
bool
OutwardBindingSite::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this OutwardBindingSite's "name" attribute is
 * set.
 */
bool
OutwardBindingSite::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Predicate returning @c true if this OutwardBindingSite's "bindingStatus"
 * attribute is set.
 */
bool
OutwardBindingSite::isSetBindingStatus() const
{
  return (mBindingStatus != BINDING_STATUS_INVALID);
}


/*
 * Predicate returning @c true if this OutwardBindingSite's "component"
 * attribute is set.
 */
bool
OutwardBindingSite::isSetComponent() const
{
  return (mComponent.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "name" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setName(const std::string& name)
{
  mName = name;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "bindingStatus" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setBindingStatus(const BindingStatus_t bindingStatus)
{
  if (BindingStatus_isValid(bindingStatus) == 0)
  {
    mBindingStatus = BINDING_STATUS_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mBindingStatus = bindingStatus;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "bindingStatus" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setBindingStatus(const std::string& bindingStatus)
{
  mBindingStatus = BindingStatus_fromString(bindingStatus.c_str());

  if (mBindingStatus == BINDING_STATUS_INVALID)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "component" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setComponent(const std::string& component)
{
  if (!(SyntaxChecker::isValidInternalSId(component)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mComponent = component;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "id" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::unsetId()
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
 * Unsets the value of the "name" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::unsetName()
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
 * Unsets the value of the "bindingStatus" attribute of this
 * OutwardBindingSite.
 */
int
OutwardBindingSite::unsetBindingStatus()
{
  mBindingStatus = BINDING_STATUS_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "component" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::unsetComponent()
{
  mComponent.erase();

  if (mComponent.empty() == true)
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
OutwardBindingSite::renameSIdRefs(const std::string& oldid,
                                  const std::string& newid)
{
  if (isSetComponent() && mComponent == oldid)
  {
    setComponent(newid);
  }
}


/*
 * Returns the XML element name of this OutwardBindingSite object.
 */
const std::string&
OutwardBindingSite::getElementName() const
{
  static const string name = "outwardBindingSite";
  return name;
}


/*
 * Returns the libSBML type code for this OutwardBindingSite object.
 */
int
OutwardBindingSite::getTypeCode() const
{
  return SBML_MULTI_OUTWARD_BINDING_SITE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * OutwardBindingSite object have been set.
 */
bool
OutwardBindingSite::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetBindingStatus() == false)
  {
    allPresent = false;
  }

  if (isSetComponent() == false)
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
OutwardBindingSite::writeElements(XMLOutputStream& stream) const
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
OutwardBindingSite::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
OutwardBindingSite::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
OutwardBindingSite::enablePackageInternal(const std::string& pkgURI,
                                          const std::string& pkgPrefix,
                                          bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::getAttribute(const std::string& attributeName,
                                 bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::getAttribute(const std::string& attributeName,
                                 int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::getAttribute(const std::string& attributeName,
                                 double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::getAttribute(const std::string& attributeName,
                                 unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "bindingStatus")
  {
    value = getBindingStatusAsString();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "component")
  {
    value = getComponent();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this OutwardBindingSite's attribute
 * "attributeName" is set.
 */
bool
OutwardBindingSite::isSetAttribute(const std::string& attributeName) const
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
  else if (attributeName == "bindingStatus")
  {
    value = isSetBindingStatus();
  }
  else if (attributeName == "component")
  {
    value = isSetComponent();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setAttribute(const std::string& attributeName,
                                 double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setAttribute(const std::string& attributeName,
                                 unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this OutwardBindingSite.
 */
int
OutwardBindingSite::setAttribute(const std::string& attributeName,
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
  else if (attributeName == "bindingStatus")
  {
    return_value = setBindingStatus(value);
  }
  else if (attributeName == "component")
  {
    return_value = setComponent(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * OutwardBindingSite.
 */
int
OutwardBindingSite::unsetAttribute(const std::string& attributeName)
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
  else if (attributeName == "bindingStatus")
  {
    value = unsetBindingStatus();
  }
  else if (attributeName == "component")
  {
    value = unsetComponent();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
OutwardBindingSite::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("name");

  attributes.add("bindingStatus");

  attributes.add("component");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
OutwardBindingSite::readAttributes(const XMLAttributes& attributes,
                                   const ExpectedAttributes&
                                     expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (log && getParentSBMLObject() &&
    static_cast<ListOfOutwardBindingSites*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("multi",
          MultiSpeciesLOOutwardBindingSitesAllowedAttributes, pkgVersion, level,
            version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("multi",
          MultiSpeciesLOOutwardBindingSitesAllowedCoreAttributes, pkgVersion,
            level, version, details);
      }
    }
  }

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
        log->logPackageError("multi", MultiOutwardBindingSiteAllowedAttributes,
          pkgVersion, level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("multi",
          MultiOutwardBindingSiteAllowedCoreAttributes, pkgVersion, level,
            version, details);
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
      logEmptyString(mId, level, version, "<OutwardBindingSite>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("multi", MultiIdSyntaxRule, pkgVersion, level,
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
      logEmptyString(mName, level, version, "<OutwardBindingSite>");
    }
  }

  // 
  // bindingStatus enum (use = "required" )
  // 

  std::string bindingStatus;
  assigned = attributes.readInto("bindingStatus", bindingStatus);

  if (assigned == true)
  {
    if (bindingStatus.empty() == true)
    {
      logEmptyString(bindingStatus, level, version, "<OutwardBindingSite>");
    }
    else
    {
      mBindingStatus = BindingStatus_fromString(bindingStatus.c_str());

      if (BindingStatus_isValid(mBindingStatus) == 0)
      {
        std::string msg = "The bindingStatus on the <OutwardBindingSite> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + bindingStatus + "', which is not a valid option.";

        log->logPackageError("multi",
          MultiOutwardBindingSiteBindingStatusMustBeBindingStatusEnum,
            pkgVersion, level, version, msg);
      }
    }
  }
  else
  {
    std::string message = "Multi attribute 'bindingStatus' is missing.";
    log->logPackageError("multi", MultiOutwardBindingSiteAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // component SIdRef (use = "required" )
  // 

  assigned = attributes.readInto("component", mComponent);

  if (assigned == true)
  {
    if (mComponent.empty() == true)
    {
      logEmptyString(mComponent, level, version, "<OutwardBindingSite>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mComponent) == false)
    {
      std::string msg = "The component attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mComponent + "', which does not conform to the syntax.";
      log->logPackageError("multi",
        MultiOutwardBindingSiteComponentMustBeMultiSpeciesType,SpeciesTypeInstance,SpeciesTypeComponentIndex,
          pkgVersion, level, version, msg, getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Multi attribute 'component' is missing from the "
      "<OutwardBindingSite> element.";
    log->logPackageError("multi", MultiOutwardBindingSiteAllowedAttributes,
      pkgVersion, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
OutwardBindingSite::writeAttributes(XMLOutputStream& stream) const
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

  if (isSetBindingStatus() == true)
  {
    stream.writeAttribute("bindingStatus", getPrefix(),
      BindingStatus_toString(mBindingStatus));
  }

  if (isSetComponent() == true)
  {
    stream.writeAttribute("component", getPrefix(), mComponent);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new OutwardBindingSite_t using the given SBML Level, Version and
 * &ldquo;multi&rdquo; package version.
 */
LIBSBML_EXTERN
OutwardBindingSite_t *
OutwardBindingSite_create(unsigned int level,
                          unsigned int version,
                          unsigned int pkgVersion)
{
  return new OutwardBindingSite(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this OutwardBindingSite_t object.
 */
LIBSBML_EXTERN
OutwardBindingSite_t*
OutwardBindingSite_clone(const OutwardBindingSite_t* obs)
{
  if (obs != NULL)
  {
    return static_cast<OutwardBindingSite_t*>(obs->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this OutwardBindingSite_t object.
 */
LIBSBML_EXTERN
void
OutwardBindingSite_free(OutwardBindingSite_t* obs)
{
  if (obs != NULL)
  {
    delete obs;
  }
}


/*
 * Returns the value of the "id" attribute of this OutwardBindingSite_t.
 */
LIBSBML_EXTERN
char *
OutwardBindingSite_getId(const OutwardBindingSite_t * obs)
{
  if (obs == NULL)
  {
    return NULL;
  }

  return obs->getId().empty() ? NULL : safe_strdup(obs->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this OutwardBindingSite_t.
 */
LIBSBML_EXTERN
char *
OutwardBindingSite_getName(const OutwardBindingSite_t * obs)
{
  if (obs == NULL)
  {
    return NULL;
  }

  return obs->getName().empty() ? NULL : safe_strdup(obs->getName().c_str());
}


/*
 * Returns the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 */
LIBSBML_EXTERN
BindingStatus_t
OutwardBindingSite_getBindingStatus(const OutwardBindingSite_t * obs)
{
  if (obs == NULL)
  {
    return BINDING_STATUS_INVALID;
  }

  return obs->getBindingStatus();
}


/*
 * Returns the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 */
LIBSBML_EXTERN
char *
OutwardBindingSite_getBindingStatusAsString(const OutwardBindingSite_t * obs)
{
  return (char*)(BindingStatus_toString(obs->getBindingStatus()));
}


/*
 * Returns the value of the "component" attribute of this OutwardBindingSite_t.
 */
LIBSBML_EXTERN
char *
OutwardBindingSite_getComponent(const OutwardBindingSite_t * obs)
{
  if (obs == NULL)
  {
    return NULL;
  }

  return obs->getComponent().empty() ? NULL :
    safe_strdup(obs->getComponent().c_str());
}


/*
 * Predicate returning @c 1 (true) if this OutwardBindingSite_t's "id"
 * attribute is set.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_isSetId(const OutwardBindingSite_t * obs)
{
  return (obs != NULL) ? static_cast<int>(obs->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this OutwardBindingSite_t's "name"
 * attribute is set.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_isSetName(const OutwardBindingSite_t * obs)
{
  return (obs != NULL) ? static_cast<int>(obs->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this OutwardBindingSite_t's
 * "bindingStatus" attribute is set.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_isSetBindingStatus(const OutwardBindingSite_t * obs)
{
  return (obs != NULL) ? static_cast<int>(obs->isSetBindingStatus()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this OutwardBindingSite_t's "component"
 * attribute is set.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_isSetComponent(const OutwardBindingSite_t * obs)
{
  return (obs != NULL) ? static_cast<int>(obs->isSetComponent()) : 0;
}


/*
 * Sets the value of the "id" attribute of this OutwardBindingSite_t.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setId(OutwardBindingSite_t * obs, const char * id)
{
  return (obs != NULL) ? obs->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this OutwardBindingSite_t.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setName(OutwardBindingSite_t * obs, const char * name)
{
  return (obs != NULL) ? obs->setName(name) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setBindingStatus(OutwardBindingSite_t * obs,
                                    BindingStatus_t bindingStatus)
{
  return (obs != NULL) ? obs->setBindingStatus(bindingStatus) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setBindingStatusAsString(OutwardBindingSite_t * obs,
                                            const char * bindingStatus)
{
  return (obs != NULL) ? obs->setBindingStatus(bindingStatus):
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "component" attribute of this OutwardBindingSite_t.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setComponent(OutwardBindingSite_t * obs,
                                const char * component)
{
  return (obs != NULL) ? obs->setComponent(component) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this OutwardBindingSite_t.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_unsetId(OutwardBindingSite_t * obs)
{
  return (obs != NULL) ? obs->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this OutwardBindingSite_t.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_unsetName(OutwardBindingSite_t * obs)
{
  return (obs != NULL) ? obs->unsetName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_unsetBindingStatus(OutwardBindingSite_t * obs)
{
  return (obs != NULL) ? obs->unsetBindingStatus() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "component" attribute of this OutwardBindingSite_t.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_unsetComponent(OutwardBindingSite_t * obs)
{
  return (obs != NULL) ? obs->unsetComponent() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * OutwardBindingSite_t object have been set.
 */
LIBSBML_EXTERN
int
OutwardBindingSite_hasRequiredAttributes(const OutwardBindingSite_t * obs)
{
  return (obs != NULL) ? static_cast<int>(obs->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


