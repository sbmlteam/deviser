/**
 * @file SedSimulation.cpp
 * @brief Implementation of the SedSimulation class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2016, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#include <sedml/SedSimulation.h>
#include <sedml/SedListOfSimulations.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedSimulation using the given SEDML Level and @ p version
 * values.
 */
SedSimulation::SedSimulation(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mId ("")
  , mName ("")
  , mAlgorithm (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedSimulation using the given SedNamespaces object @p sedmlns.
 */
SedSimulation::SedSimulation(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mId ("")
  , mName ("")
  , mAlgorithm (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedSimulation.
 */
SedSimulation::SedSimulation(const SedSimulation& orig)
  : SedBase( orig )
  , mId ( orig.mId )
  , mName ( orig.mName )
  , mAlgorithm ( NULL )
{
  if (orig.mAlgorithm != NULL)
  {
    mAlgorithm = orig.mAlgorithm->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedSimulation.
 */
SedSimulation&
SedSimulation::operator=(const SedSimulation& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mId = rhs.mId;
    mName = rhs.mName;
    delete mAlgorithm;
    if (rhs.mAlgorithm != NULL)
    {
      mAlgorithm = rhs.mAlgorithm->clone();
    }
    else
    {
      mAlgorithm = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedSimulation object.
 */
SedSimulation*
SedSimulation::clone() const
{
  return new SedSimulation(*this);
}


/*
 * Destructor for SedSimulation.
 */
SedSimulation::~SedSimulation()
{
  delete mAlgorithm;
  mAlgorithm = NULL;
}


/*
 * Returns the value of the "id" attribute of this SedSimulation.
 */
const std::string&
SedSimulation::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this SedSimulation.
 */
const std::string&
SedSimulation::getName() const
{
  return mName;
}


/*
 * Predicate returning @c true if this SedSimulation's "id" attribute is set.
 */
bool
SedSimulation::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this SedSimulation's "name" attribute is set.
 */
bool
SedSimulation::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this SedSimulation.
 */
int
SedSimulation::setId(const std::string& id)
{
  mId = id;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "name" attribute of this SedSimulation.
 */
int
SedSimulation::setName(const std::string& name)
{
  mName = name;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this SedSimulation.
 */
int
SedSimulation::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "name" attribute of this SedSimulation.
 */
int
SedSimulation::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "algorithm" element of this SedSimulation.
 */
const SedAlgorithm*
SedSimulation::getAlgorithm() const
{
  return mAlgorithm;
}


/*
 * Returns the value of the "algorithm" element of this SedSimulation.
 */
SedAlgorithm*
SedSimulation::getAlgorithm()
{
  return mAlgorithm;
}


/*
 * Predicate returning @c true if this SedSimulation's "algorithm" element is
 * set.
 */
bool
SedSimulation::isSetAlgorithm() const
{
  return (mAlgorithm != NULL);
}


/*
 * Sets the value of the "algorithm" element of this SedSimulation.
 */
int
SedSimulation::setAlgorithm(const SedAlgorithm* algorithm)
{
  if (mAlgorithm == algorithm)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (algorithm == NULL)
  {
    delete mAlgorithm;
    mAlgorithm = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mAlgorithm;
    mAlgorithm = (algorithm != NULL) ? algorithm->clone() : NULL;
    if (mAlgorithm != NULL)
    {
      mAlgorithm->connectToParent(this);
    }

    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SedAlgorithm object, adds it to this SedSimulation object and
 * returns the SedAlgorithm object created.
 */
SedAlgorithm*
SedSimulation::createAlgorithm()
{
  if (mAlgorithm != NULL)
  {
    delete mAlgorithm;
  }

  mAlgorithm = new SedAlgorithm(getSedNamespaces());

  connectToChild();

  return mAlgorithm;
}


/*
 * Unsets the value of the "algorithm" element of this SedSimulation.
 */
int
SedSimulation::unsetAlgorithm()
{
  delete mAlgorithm;
  mAlgorithm = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this SedSimulation object.
 */
const std::string&
SedSimulation::getElementName() const
{
  static const string name = "simulation";
  return name;
}


/*
 * Returns the libSEDML type code for this SedSimulation object.
 */
int
SedSimulation::getTypeCode() const
{
  return SEDML_SIMULATION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedSimulation object have been set.
 */
bool
SedSimulation::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedSimulation object have been set.
 */
bool
SedSimulation::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedSimulation::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeElements(stream);

  if (isSetAlgorithm() == true)
  {
    mAlgorithm->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedSimulation::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedSimulation::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  if (mAlgorithm != NULL)
  {
    mAlgorithm->setSedDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedSimulation::connectToChild()
{
  SedBase::connectToChild();

  if (mAlgorithm != NULL)
  {
    mAlgorithm->connectToParent(this);
  }
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedSimulation::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  if (mAlgorithm != NULL)
  {
    if (mAlgorithm->getId() == id)
    {
      return mAlgorithm;
    }

    obj = mAlgorithm->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedSimulation::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "algorithm")
  {
    if (isSetAlgorithm())
    {
      getErrorLog()->logError(SedmlSimulationAllowedElements, getLevel(),
        getVersion());
    }

    mAlgorithm = new SedAlgorithm(getSedNamespaces());
    obj = mAlgorithm;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedSimulation::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("name");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedSimulation::readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  if (static_cast<SedListOfSimulations*>(getParentSedObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logError(SedmlLOSimulationsAllowedCoreAttributes, level, version,
          details);
      }
    }
  }

  SedBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logError(SedmlSedSimulationAllowedAttributes, level, version,
        details);
    }
  }

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<SedSimulation>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(SedmlIdSyntaxRule, level, version, "The id '" + mId + "' does "
        "not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Sedml attribute 'id' is missing from the "
      "<SedSimulation> element.";
    log->logError(SedmlSimulationAllowedAttributes, level, version, message);
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<SedSimulation>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedSimulation::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedSimulation_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedSimulation_t *
SedSimulation_create(unsigned int level, unsigned int version)
{
  return new SedSimulation(level, version);
}


/*
 * Creates and returns a deep copy of this SedSimulation_t object.
 */
LIBSEDML_EXTERN
SedSimulation_t*
SedSimulation_clone(const SedSimulation_t* ss)
{
  if (ss != NULL)
  {
    return static_cast<SedSimulation_t*>(ss->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedSimulation_t object.
 */
LIBSEDML_EXTERN
void
SedSimulation_free(SedSimulation_t* ss)
{
  if (ss != NULL)
  {
    delete ss;
  }
}


/*
 * Returns the value of the "id" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
const char *
SedSimulation_getId(const SedSimulation_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getId().empty() ? NULL : safe_strdup(ss->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
const char *
SedSimulation_getName(const SedSimulation_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getName().empty() ? NULL : safe_strdup(ss->getName().c_str());
}


/*
 * Predicate returning @c 1 if this SedSimulation_t's "id" attribute is set.
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetId(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this SedSimulation_t's "name" attribute is set.
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetName(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetName()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_setId(SedSimulation_t * ss, const char * id)
{
  return (ss != NULL) ? ss->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_setName(SedSimulation_t * ss, const char * name)
{
  return (ss != NULL) ? ss->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetId(SedSimulation_t * ss)
{
  return (ss != NULL) ? ss->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetName(SedSimulation_t * ss)
{
  return (ss != NULL) ? ss->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns the value of the "algorithm" element of this SedSimulation_t.
 */
LIBSEDML_EXTERN
const SedAlgorithm_t*
SedSimulation_getAlgorithm(const SedSimulation_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(ss->getAlgorithm());
}


/*
 * Predicate returning @c 1 if this SedSimulation_t's "algorithm" element is
 * set.
 */
LIBSEDML_EXTERN
int
SedSimulation_isSetAlgorithm(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetAlgorithm()) : 0;
}


/*
 * Sets the value of the "algorithm" element of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_setAlgorithm(SedSimulation_t * ss,
                           const SedAlgorithm_t* algorithm)
{
  return (ss != NULL) ? ss->setAlgorithm(algorithm) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Creates a new SedAlgorithm_t object, adds it to this SedSimulation_t object
 * and returns the SedAlgorithm_t object created.
 */
LIBSEDML_EXTERN
SedAlgorithm_t*
SedSimulation_createAlgorithm(SedSimulation_t* ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return (SedAlgorithm_t*)(ss->createAlgorithm());
}


/*
 * Unsets the value of the "algorithm" element of this SedSimulation_t.
 */
LIBSEDML_EXTERN
int
SedSimulation_unsetAlgorithm(SedSimulation_t * ss)
{
  return (ss != NULL) ? ss->unsetAlgorithm() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * SedSimulation_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSimulation_hasRequiredAttributes(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this
 * SedSimulation_t object have been set.
 */
LIBSEDML_EXTERN
int
SedSimulation_hasRequiredElements(const SedSimulation_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


