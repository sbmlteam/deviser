/**
 * @file Objective.cpp
 * @brief Implementation of the Objective class.
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
#include <sbml/packages/fbc/sbml/Objective.h>
#include <sbml/packages/fbc/sbml/ListOfObjectives.h>
#include <sbml/packages/fbc/validator/FbcSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Objective using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 */
Objective::Objective(unsigned int level,
                     unsigned int version,
                     unsigned int pkgVersion)
  : SBase(level, version)
  , mType (FBC_TYPE_INVALID)
  , mFluxObjectives (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new FbcPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new Objective using the given FbcPkgNamespaces object.
 */
Objective::Objective(FbcPkgNamespaces *fbcns)
  : SBase(fbcns)
  , mType (FBC_TYPE_INVALID)
  , mFluxObjectives (fbcns)
{
  setElementNamespace(fbcns->getURI());
  connectToChild();
  loadPlugins(fbcns);
}


/*
 * Copy constructor for Objective.
 */
Objective::Objective(const Objective& orig)
  : SBase( orig )
  , mType ( orig.mType )
  , mFluxObjectives ( orig.mFluxObjectives )
{
  connectToChild();
}


/*
 * Assignment operator for Objective.
 */
Objective&
Objective::operator=(const Objective& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mType = rhs.mType;
    mFluxObjectives = rhs.mFluxObjectives;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Objective object.
 */
Objective*
Objective::clone() const
{
  return new Objective(*this);
}


/*
 * Destructor for Objective.
 */
Objective::~Objective()
{
}


/*
 * Returns the value of the "id" attribute of this Objective.
 */
const std::string&
Objective::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this Objective.
 */
const std::string&
Objective::getName() const
{
  return mName;
}


/*
 * Returns the value of the "type" attribute of this Objective.
 */
FbcType_t
Objective::getType() const
{
  return mType;
}


/*
 * Returns the value of the "type" attribute of this Objective.
 */
const std::string&
Objective::getTypeAsString() const
{
  static const std::string code_str = FbcType_toString(mType);
  return code_str;
}


/*
 * Predicate returning @c true if this Objective's "id" attribute is set.
 */
bool
Objective::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this Objective's "name" attribute is set.
 */
bool
Objective::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Predicate returning @c true if this Objective's "type" attribute is set.
 */
bool
Objective::isSetType() const
{
  return (mType != FBC_TYPE_INVALID);
}


/*
 * Sets the value of the "id" attribute of this Objective.
 */
int
Objective::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "name" attribute of this Objective.
 */
int
Objective::setName(const std::string& name)
{
  mName = name;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "type" attribute of this Objective.
 */
int
Objective::setType(const FbcType_t type)
{
  if (FbcType_isValid(type) == 0)
  {
    mType = FBC_TYPE_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = type;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "type" attribute of this Objective.
 */
int
Objective::setType(const std::string& type)
{
  if (FbcType_isValidString(type.c_str()) == 0)
  {
    mType = FBC_TYPE_INVALID;
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mType = FbcType_fromString(type.c_str());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "id" attribute of this Objective.
 */
int
Objective::unsetId()
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
 * Unsets the value of the "name" attribute of this Objective.
 */
int
Objective::unsetName()
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
 * Unsets the value of the "type" attribute of this Objective.
 */
int
Objective::unsetType()
{
  mType = FBC_TYPE_INVALID;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the ListOfFluxObjectives from this Objective.
 */
const ListOfFluxObjectives*
Objective::getListOfFluxObjectives() const
{
  return &mFluxObjectives;
}


/*
 * Returns the ListOfFluxObjectives from this Objective.
 */
ListOfFluxObjectives*
Objective::getListOfFluxObjectives()
{
  return &mFluxObjectives;
}


/*
 * Get a FluxObjective from the Objective.
 */
FluxObjective*
Objective::getFluxObjective(unsigned int n)
{
  return mFluxObjectives.get(n);
}


/*
 * Get a FluxObjective from the Objective.
 */
const FluxObjective*
Objective::getFluxObjective(unsigned int n) const
{
  return mFluxObjectives.get(n);
}


/*
 * Get a FluxObjective from the Objective based on its identifier.
 */
FluxObjective*
Objective::getFluxObjective(const std::string& sid)
{
  return mFluxObjectives.get(sid);
}


/*
 * Get a FluxObjective from the Objective based on its identifier.
 */
const FluxObjective*
Objective::getFluxObjective(const std::string& sid) const
{
  return mFluxObjectives.get(sid);
}


/*
 * Get a FluxObjective from the Objective based on the Reaction to which it
 * refers.
 */
const FluxObjective*
Objective::getFluxObjectiveByReaction(const std::string& sid) const
{
  return mFluxObjectives.getByReaction(sid);
}


/*
 * Get a FluxObjective from the Objective based on the Reaction to which it
 * refers.
 */
FluxObjective*
Objective::getFluxObjectiveByReaction(const std::string& sid)
{
  return mFluxObjectives.getByReaction(sid);
}


/*
 * Adds a copy of the given FluxObjective to this Objective.
 */
int
Objective::addFluxObjective(const FluxObjective* fo)
{
  if (fo == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (fo->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != fo->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != fo->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(fo)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (fo->isSetId() && (mFluxObjectives.get(fo->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mFluxObjectives.append(fo);
  }
}


/*
 * Get the number of FluxObjective objects in this Objective.
 */
unsigned int
Objective::getNumFluxObjectives() const
{
  return mFluxObjectives.size();
}


/*
 * Creates a new FluxObjective object, adds it to this Objective object and
 * returns the FluxObjective object created.
 */
FluxObjective*
Objective::createFluxObjective()
{
  FluxObjective* fo = NULL;

  try
  {
    FBC_CREATE_NS_WITH_VERSION(fbcns, getSBMLNamespaces(),
      getPackageVersion());
    fo = new FluxObjective(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (fo != NULL)
  {
    mFluxObjectives.appendAndOwn(fo);
  }

  return fo;
}


/*
 * Removes the nth FluxObjective from this Objective and returns a pointer to
 * it.
 */
FluxObjective*
Objective::removeFluxObjective(unsigned int n)
{
  return mFluxObjectives.remove(n);
}


/*
 * Removes the FluxObjective from this Objective based on its identifier and
 * returns a pointer to it.
 */
FluxObjective*
Objective::removeFluxObjective(const std::string& sid)
{
  return mFluxObjectives.remove(sid);
}


/*
 * Returns the XML element name of this Objective object.
 */
const std::string&
Objective::getElementName() const
{
  static const string name = "objective";
  return name;
}


/*
 * Returns the libSBML type code for this Objective object.
 */
int
Objective::getTypeCode() const
{
  return SBML_FBC_OBJECTIVE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * Objective object have been set.
 */
bool
Objective::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetType() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this Objective
 * object have been set.
 */
bool
Objective::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Objective::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (getNumFluxObjectives() > 0)
  {
    mFluxObjectives.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Objective::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  mFluxObjectives.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Objective::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  mFluxObjectives.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Objective::connectToChild()
{
  SBase::connectToChild();

  mFluxObjectives.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Objective::enablePackageInternal(const std::string& pkgURI,
                                 const std::string& pkgPrefix,
                                 bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  mFluxObjectives.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "type")
  {
    value = getTypeAsString();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "type")
  {
    value = getTypeAsString().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Objective's attribute "attributeName" is
 * set.
 */
bool
Objective::isSetAttribute(const std::string& attributeName) const
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
  else if (attributeName == "type")
  {
    value = isSetType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::setAttribute(const std::string& attributeName,
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
  else if (attributeName == "type")
  {
    return_value = setType(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::setAttribute(const std::string& attributeName, const char* value)
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
  else if (attributeName == "type")
  {
    return_value = setType(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Objective.
 */
int
Objective::unsetAttribute(const std::string& attributeName)
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
  else if (attributeName == "type")
  {
    value = unsetType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this Objective.
 */
SBase*
Objective::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "fluxObjective")
  {
    return createFluxObjective();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this Objective.
 */
int
Objective::addChildObject(const std::string& elementName,
                          const SBase* element)
{
  if (elementName == "fluxObjective" && element->getTypeCode() ==
    SBML_FBC_FLUXOBJECTIVE)
  {
    return addFluxObjective((const FluxObjective*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Objective.
 */
SBase*
Objective::removeChildObject(const std::string& elementName,
                             const std::string& id)
{
  if (elementName == "fluxObjective")
  {
    return removeFluxObjective(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this Objective.
 */
unsigned int
Objective::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "fluxObjective")
  {
    return getNumFluxObjectives();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this Objective.
 */
SBase*
Objective::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "fluxObjective")
  {
    return getFluxObjective(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
Objective::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mFluxObjectives.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
Objective::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mFluxObjectives.getMetaId() == metaid)
  {
    return &mFluxObjectives;
  }

  obj = mFluxObjectives.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
Objective::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mFluxObjectives, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
Objective::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfFluxObjectives")
  {
    if (mFluxObjectives.size() != 0)
    {
      getErrorLog()->logPackageError("fbc", FbcObjectiveAllowedElements,
        getPackageVersion(), getLevel(), getVersion());
    }

    obj = &mFluxObjectives;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
Objective::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  unsigned int level = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && coreVersion == 1 && pkgVersion == 1)
  {
    attributes.add("id");
    attributes.add("name");
    attributes.add("type");
  }

  if (level == 3 && coreVersion == 1 && pkgVersion == 2)
  {
    attributes.add("id");
    attributes.add("name");
    attributes.add("type");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Objective::readAttributes(const XMLAttributes& attributes,
                          const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (static_cast<ListOfObjectives*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("fbc", FbcModelLOObjectivesAllowedAttributes,
          pkgVersion, level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("fbc", FbcModelLOObjectivesAllowedCoreAttributes,
          pkgVersion, level, version, details);
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("fbc", FbcObjectiveAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("fbc", FbcObjectiveAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    readL3V1V1Attributes(attributes);
  }

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    readL3V1V2Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Objective::readL3V1V1Attributes(const XMLAttributes& attributes)
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
      logEmptyString(mId, level, version, "<Objective>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("fbc", FbcIdSyntaxRule, pkgVersion, level, version,
        "The id on the <" + getElementName() + "> is '" + mId + "',which does not "
          "conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Fbc attribute 'id' is missing from the <Objective> "
      "element.";
    log->logPackageError("fbc", FbcObjectiveAllowedAttributes, pkgVersion,
      level, version, message);
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<Objective>");
    }
  }

  // 
  // type enum (use = "required" )
  // 

  std::string type;
  assigned = attributes.readInto("type", type);

  if (assigned == true)
  {
    if (type.empty() == true)
    {
      logEmptyString(type, level, version, "<Objective>");
    }
    else
    {
      mType = FbcType_fromString(type.c_str());

      if (FbcType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <Objective> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logPackageError("fbc", FbcObjectiveTypeMustBeFbcTypeEnum,
          pkgVersion, level, version, msg);
      }
    }
  }
  else
  {
    std::string message = "Fbc attribute 'type' is missing.";
    log->logPackageError("fbc", FbcObjectiveAllowedAttributes, pkgVersion,
      level, version, message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Objective::readL3V1V2Attributes(const XMLAttributes& attributes)
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
      logEmptyString(mId, level, version, "<Objective>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("fbc", FbcIdSyntaxRule, pkgVersion, level, version,
        "The id on the <" + getElementName() + "> is '" + mId + "',which does not "
          "conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Fbc attribute 'id' is missing from the <Objective> "
      "element.";
    log->logPackageError("fbc", FbcObjectiveAllowedAttributes, pkgVersion,
      level, version, message);
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<Objective>");
    }
  }

  // 
  // type enum (use = "required" )
  // 

  std::string type;
  assigned = attributes.readInto("type", type);

  if (assigned == true)
  {
    if (type.empty() == true)
    {
      logEmptyString(type, level, version, "<Objective>");
    }
    else
    {
      mType = FbcType_fromString(type.c_str());

      if (FbcType_isValid(mType) == 0)
      {
        std::string msg = "The type on the <Objective> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + type + "', which is not a valid option.";

        log->logPackageError("fbc", FbcObjectiveTypeMustBeFbcTypeEnum,
          pkgVersion, level, version, msg);
      }
    }
  }
  else
  {
    std::string message = "Fbc attribute 'type' is missing.";
    log->logPackageError("fbc", FbcObjectiveAllowedAttributes, pkgVersion,
      level, version, message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Objective::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    writeL3V1V1Attributes(stream);
  }

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    writeL3V1V2Attributes(stream);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Objective::writeL3V1V1Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), FbcType_toString(mType));
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Objective::writeL3V1V2Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }

  if (isSetType() == true)
  {
    stream.writeAttribute("type", getPrefix(), FbcType_toString(mType));
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Objective_t using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 */
LIBSBML_EXTERN
Objective_t *
Objective_create(unsigned int level,
                 unsigned int version,
                 unsigned int pkgVersion)
{
  return new Objective(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Objective_t object.
 */
LIBSBML_EXTERN
Objective_t*
Objective_clone(const Objective_t* o)
{
  if (o != NULL)
  {
    return static_cast<Objective_t*>(o->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Objective_t object.
 */
LIBSBML_EXTERN
void
Objective_free(Objective_t* o)
{
  if (o != NULL)
  {
    delete o;
  }
}


/*
 * Returns the value of the "id" attribute of this Objective_t.
 */
LIBSBML_EXTERN
char *
Objective_getId(const Objective_t * o)
{
  if (o == NULL)
  {
    return NULL;
  }

  return o->getId().empty() ? NULL : safe_strdup(o->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this Objective_t.
 */
LIBSBML_EXTERN
char *
Objective_getName(const Objective_t * o)
{
  if (o == NULL)
  {
    return NULL;
  }

  return o->getName().empty() ? NULL : safe_strdup(o->getName().c_str());
}


/*
 * Returns the value of the "type" attribute of this Objective_t.
 */
LIBSBML_EXTERN
FbcType_t
Objective_getType(const Objective_t * o)
{
  if (o == NULL)
  {
    return FBC_TYPE_INVALID;
  }

  return o->getType();
}


/*
 * Returns the value of the "type" attribute of this Objective_t.
 */
LIBSBML_EXTERN
const char *
Objective_getTypeAsString(const Objective_t * o)
{
  return FbcType_toString(o->getType());
}


/*
 * Predicate returning @c 1 (true) if this Objective_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
Objective_isSetId(const Objective_t * o)
{
  return (o != NULL) ? static_cast<int>(o->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Objective_t's "name" attribute is
 * set.
 */
LIBSBML_EXTERN
int
Objective_isSetName(const Objective_t * o)
{
  return (o != NULL) ? static_cast<int>(o->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Objective_t's "type" attribute is
 * set.
 */
LIBSBML_EXTERN
int
Objective_isSetType(const Objective_t * o)
{
  return (o != NULL) ? static_cast<int>(o->isSetType()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Objective_t.
 */
LIBSBML_EXTERN
int
Objective_setId(Objective_t * o, const char * id)
{
  return (o != NULL) ? o->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this Objective_t.
 */
LIBSBML_EXTERN
int
Objective_setName(Objective_t * o, const char * name)
{
  return (o != NULL) ? o->setName(name) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this Objective_t.
 */
LIBSBML_EXTERN
int
Objective_setType(Objective_t * o, FbcType_t type)
{
  return (o != NULL) ? o->setType(type) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "type" attribute of this Objective_t.
 */
LIBSBML_EXTERN
int
Objective_setTypeAsString(Objective_t * o, const char * type)
{
  return (o != NULL) ? o->setType(type): LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Objective_t.
 */
LIBSBML_EXTERN
int
Objective_unsetId(Objective_t * o)
{
  return (o != NULL) ? o->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this Objective_t.
 */
LIBSBML_EXTERN
int
Objective_unsetName(Objective_t * o)
{
  return (o != NULL) ? o->unsetName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "type" attribute of this Objective_t.
 */
LIBSBML_EXTERN
int
Objective_unsetType(Objective_t * o)
{
  return (o != NULL) ? o->unsetType() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing FluxObjective_t objects from this
 * Objective_t.
 */
LIBSBML_EXTERN
ListOf_t*
Objective_getListOfFluxObjectives(Objective_t* o)
{
  return (o != NULL) ? o->getListOfFluxObjectives() : NULL;
}


/*
 * Get a FluxObjective_t from the Objective_t.
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_getFluxObjective(Objective_t* o, unsigned int n)
{
  return (o != NULL) ? o->getFluxObjective(n) : NULL;
}


/*
 * Get a FluxObjective_t from the Objective_t based on its identifier.
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_getFluxObjectiveById(Objective_t* o, const char *sid)
{
  return (o != NULL && sid != NULL) ? o->getFluxObjective(sid) : NULL;
}


/*
 * Get a FluxObjective_t from the Objective_t based on the Reaction to which it
 * refers.
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_getFluxObjectiveByReaction(Objective_t* o, const char *sid)
{
  return (o != NULL && sid != NULL) ? o->getFluxObjectiveByReaction(sid) :
    NULL;
}


/*
 * Adds a copy of the given FluxObjective_t to this Objective_t.
 */
LIBSBML_EXTERN
int
Objective_addFluxObjective(Objective_t* o, const FluxObjective_t* fo)
{
  return (o != NULL) ? o->addFluxObjective(fo) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of FluxObjective_t objects in this Objective_t.
 */
LIBSBML_EXTERN
unsigned int
Objective_getNumFluxObjectives(Objective_t* o)
{
  return (o != NULL) ? o->getNumFluxObjectives() : SBML_INT_MAX;
}


/*
 * Creates a new FluxObjective_t object, adds it to this Objective_t object and
 * returns the FluxObjective_t object created.
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_createFluxObjective(Objective_t* o)
{
  return (o != NULL) ? o->createFluxObjective() : NULL;
}


/*
 * Removes the nth FluxObjective_t from this Objective_t and returns a pointer
 * to it.
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_removeFluxObjective(Objective_t* o, unsigned int n)
{
  return (o != NULL) ? o->removeFluxObjective(n) : NULL;
}


/*
 * Removes the FluxObjective_t from this Objective_t based on its identifier
 * and returns a pointer to it.
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_removeFluxObjectiveById(Objective_t* o, const char* sid)
{
  return (o != NULL && sid != NULL) ? o->removeFluxObjective(sid) : NULL;
}


/*
 * Predicate returning @c 1 if all the required attributes for this Objective_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Objective_hasRequiredAttributes(const Objective_t * o)
{
  return (o != NULL) ? static_cast<int>(o->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this Objective_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Objective_hasRequiredElements(const Objective_t * o)
{
  return (o != NULL) ? static_cast<int>(o->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


