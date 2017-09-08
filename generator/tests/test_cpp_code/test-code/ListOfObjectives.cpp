/**
 * @file ListOfObjectives.cpp
 * @brief Implementation of the ListOfObjectives class.
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
#include <sbml/packages/fbc/sbml/ListOfObjectives.h>
#include <sbml/packages/fbc/validator/FbcSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ListOfObjectives using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 */
ListOfObjectives::ListOfObjectives(unsigned int level,
                                   unsigned int version,
                                   unsigned int pkgVersion)
  : ListOf(level, version)
  , mActiveObjective ("")
{
  setSBMLNamespacesAndOwn(new FbcPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ListOfObjectives using the given FbcPkgNamespaces object.
 */
ListOfObjectives::ListOfObjectives(FbcPkgNamespaces *fbcns)
  : ListOf(fbcns)
  , mActiveObjective ("")
{
  setElementNamespace(fbcns->getURI());
}


/*
 * Copy constructor for ListOfObjectives.
 */
ListOfObjectives::ListOfObjectives(const ListOfObjectives& orig)
  : ListOf( orig )
  , mActiveObjective ( orig.mActiveObjective )
{
}


/*
 * Assignment operator for ListOfObjectives.
 */
ListOfObjectives&
ListOfObjectives::operator=(const ListOfObjectives& rhs)
{
  if (&rhs != this)
  {
    ListOf::operator=(rhs);
    mActiveObjective = rhs.mActiveObjective;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ListOfObjectives object.
 */
ListOfObjectives*
ListOfObjectives::clone() const
{
  return new ListOfObjectives(*this);
}


/*
 * Destructor for ListOfObjectives.
 */
ListOfObjectives::~ListOfObjectives()
{
}


/*
 * Returns the value of the "activeObjective" attribute of this
 * ListOfObjectives.
 */
const std::string&
ListOfObjectives::getActiveObjective() const
{
  return mActiveObjective;
}


/*
 * Predicate returning @c true if this ListOfObjectives's "activeObjective"
 * attribute is set.
 */
bool
ListOfObjectives::isSetActiveObjective() const
{
  return (mActiveObjective.empty() == false);
}


/*
 * Sets the value of the "activeObjective" attribute of this ListOfObjectives.
 */
int
ListOfObjectives::setActiveObjective(const std::string& activeObjective)
{
  if (!(SyntaxChecker::isValidInternalSId(activeObjective)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mActiveObjective = activeObjective;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "activeObjective" attribute of this
 * ListOfObjectives.
 */
int
ListOfObjectives::unsetActiveObjective()
{
  mActiveObjective.erase();

  if (mActiveObjective.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Get an Objective from the ListOfObjectives.
 */
Objective*
ListOfObjectives::get(unsigned int n)
{
  return static_cast<Objective*>(ListOf::get(n));
}


/*
 * Get an Objective from the ListOfObjectives.
 */
const Objective*
ListOfObjectives::get(unsigned int n) const
{
  return static_cast<const Objective*>(ListOf::get(n));
}


/*
 * Get an Objective from the ListOfObjectives based on its identifier.
 */
Objective*
ListOfObjectives::get(const std::string& sid)
{
  return const_cast<Objective*>(static_cast<const
    ListOfObjectives&>(*this).get(sid));
}


/*
 * Get an Objective from the ListOfObjectives based on its identifier.
 */
const Objective*
ListOfObjectives::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), IdEq<Objective>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const Objective*>
    (*result);
}


/*
 * Removes the nth Objective from this ListOfObjectives and returns a pointer
 * to it.
 */
Objective*
ListOfObjectives::remove(unsigned int n)
{
  return static_cast<Objective*>(ListOf::remove(n));
}


/*
 * Removes the Objective from this ListOfObjectives based on its identifier and
 * returns a pointer to it.
 */
Objective*
ListOfObjectives::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), IdEq<Objective>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <Objective*> (item);
}


/*
 * Adds a copy of the given Objective to this ListOfObjectives.
 */
int
ListOfObjectives::addObjective(const Objective* o)
{
  if (o == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (o->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != o->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != o->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(o)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(o);
  }
}


/*
 * Get the number of Objective objects in this ListOfObjectives.
 */
unsigned int
ListOfObjectives::getNumObjectives() const
{
  return size();
}


/*
 * Creates a new Objective object, adds it to this ListOfObjectives object and
 * returns the Objective object created.
 */
Objective*
ListOfObjectives::createObjective()
{
  Objective* o = NULL;

  try
  {
    FBC_CREATE_NS_WITH_VERSION(fbcns, getSBMLNamespaces(),
      getPackageVersion());
    o = new Objective(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (o != NULL)
  {
    appendAndOwn(o);
  }

  return o;
}


/*
 * Returns the XML element name of this ListOfObjectives object.
 */
const std::string&
ListOfObjectives::getElementName() const
{
  static const string name = "listOfObjectives";
  return name;
}


/*
 * Returns the libSBML type code for this ListOfObjectives object.
 */
int
ListOfObjectives::getTypeCode() const
{
  return SBML_LIST_OF;
}


/*
 * Returns the libSBML type code for the SBML objects contained in this
 * ListOfObjectives object.
 */
int
ListOfObjectives::getItemTypeCode() const
{
  return SBML_FBC_OBJECTIVE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * ListOfObjectives object have been set.
 */
bool
ListOfObjectives::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new Objective in this ListOfObjectives
 */
SBase*
ListOfObjectives::createObject(XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SBase* object = NULL;
  FBC_CREATE_NS(fbcns, getSBMLNamespaces());

  if (name == "objective")
  {
    object = new Objective(fbcns);
    appendAndOwn(object);
  }

  delete fbcns;
  return object;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
ListOfObjectives::addExpectedAttributes(ExpectedAttributes& attributes)
{
  ListOf::addExpectedAttributes(attributes);

  unsigned int level = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && coreVersion == 1 && pkgVersion == 1)
  {
    attributes.add("activeObjective");
  }

  if (level == 3 && coreVersion == 1 && pkgVersion == 2)
  {
    attributes.add("activeObjective");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ListOfObjectives::readAttributes(const XMLAttributes& attributes,
                                 const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  ListOf::readAttributes(attributes, expectedAttributes);
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
ListOfObjectives::readL3V1V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();

  // 
  // activeObjective SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("activeObjective", mActiveObjective);

  if (assigned == true)
  {
    if (mActiveObjective.empty() == true)
    {
      logEmptyString(mActiveObjective, level, version, "<ListOfObjectives>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mActiveObjective) == false)
    {
      log->logPackageError("fbc",
        FbcListOfObjectivesActiveObjectiveMustBeObjective, pkgVersion, level,
          version, "The attribute activeObjective='" + mActiveObjective + "' does "
            "not conform to the syntax.", getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ListOfObjectives::readL3V1V2Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();

  // 
  // activeObjective SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("activeObjective", mActiveObjective);

  if (assigned == true)
  {
    if (mActiveObjective.empty() == true)
    {
      logEmptyString(mActiveObjective, level, version, "<ListOfObjectives>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mActiveObjective) == false)
    {
      log->logPackageError("fbc",
        FbcListOfObjectivesActiveObjectiveMustBeObjective, pkgVersion, level,
          version, "The attribute activeObjective='" + mActiveObjective + "' does "
            "not conform to the syntax.", getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ListOfObjectives::writeAttributes(XMLOutputStream& stream) const
{
  ListOf::writeAttributes(stream);

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
ListOfObjectives::writeL3V1V1Attributes(XMLOutputStream& stream) const
{
  if (isSetActiveObjective() == true)
  {
    stream.writeAttribute("activeObjective", getPrefix(), mActiveObjective);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ListOfObjectives::writeL3V1V2Attributes(XMLOutputStream& stream) const
{
  if (isSetActiveObjective() == true)
  {
    stream.writeAttribute("activeObjective", getPrefix(), mActiveObjective);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the namespace for the Fbc package
 */
void
ListOfObjectives::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    const XMLNamespaces* thisxmlns = getNamespaces();
    if (thisxmlns && thisxmlns->hasURI(FbcExtension::getXmlnsL3V1V1()))
    {
      xmlns.add(FbcExtension::getXmlnsL3V1V1(), prefix);
    }
  }

  stream << xmlns;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Returns the value of the "activeObjective" attribute of this ListOf_t.
 */
LIBSBML_EXTERN
const char *
ListOfObjectives_getActiveObjective(const ListOf_t * lo)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast<const ListOfObjectives*>(lo)->getActiveObjective().empty()
    ? NULL : safe_strdup(static_cast<const
      ListOfObjectives*>(lo)->getActiveObjective().c_str());
}


/*
 * Predicate returning @c 1 (true) if this ListOf_t's "activeObjective"
 * attribute is set.
 */
LIBSBML_EXTERN
int
ListOfObjectives_isSetActiveObjective(const ListOf_t * lo)
{
  return (static_cast<const ListOfObjectives*>(lo) != NULL) ?
    static_cast<int>(static_cast<const
      ListOfObjectives*>(lo)->isSetActiveObjective()) : 0;
}


/*
 * Sets the value of the "activeObjective" attribute of this ListOf_t.
 */
LIBSBML_EXTERN
int
ListOfObjectives_setActiveObjective(ListOf_t * lo,
                                    const char * activeObjective)
{
  return (static_cast<ListOfObjectives*>(lo) != NULL) ?
    static_cast<ListOfObjectives*>(lo)->setActiveObjective(activeObjective) :
      LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "activeObjective" attribute of this ListOf_t.
 */
LIBSBML_EXTERN
int
ListOfObjectives_unsetActiveObjective(ListOf_t * lo)
{
  return (static_cast<ListOfObjectives*>(lo) != NULL) ?
    static_cast<ListOfObjectives*>(lo)->unsetActiveObjective() :
      LIBSBML_INVALID_OBJECT;
}


/*
 * Get an Objective_t from the ListOf_t.
 */
LIBSBML_EXTERN
const Objective_t*
ListOfObjectives_getObjective(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfObjectives*>(lo)->get(n);
}


/*
 * Get an Objective_t from the ListOf_t based on its identifier.
 */
LIBSBML_EXTERN
const Objective_t*
ListOfObjectives_getById(ListOf_t* lo, const char *sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfObjectives*>(lo)->get(sid) : NULL;
}


/*
 * Removes the nth Objective_t from this ListOf_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Objective_t*
ListOfObjectives_remove(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfObjectives*>(lo)->remove(n);
}


/*
 * Removes the Objective_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
Objective_t*
ListOfObjectives_removeById(ListOf_t* lo, const char* sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfObjectives*>(lo)->remove(sid) :
    NULL;
}




LIBSBML_CPP_NAMESPACE_END


