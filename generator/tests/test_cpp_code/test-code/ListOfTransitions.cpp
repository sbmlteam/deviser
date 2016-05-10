/**
 * @file ListOfTransitions.cpp
 * @brief Implementation of the ListOfTransitions class.
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
#include <sbml/packages/qual/sbml/ListOfTransitions.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ListOfTransitions using the given SBML Level, Version and
 * &ldquo;qual&rdquo; package version.
 */
ListOfTransitions::ListOfTransitions(unsigned int level,
                                     unsigned int version,
                                     unsigned int pkgVersion)
  : ListOf(level, version)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ListOfTransitions using the given QualPkgNamespaces object.
 */
ListOfTransitions::ListOfTransitions(QualPkgNamespaces *qualns)
  : ListOf(qualns)
{
  setElementNamespace(qualns->getURI());
}


/*
 * Copy constructor for ListOfTransitions.
 */
ListOfTransitions::ListOfTransitions(const ListOfTransitions& orig)
  : ListOf( orig )
{
}


/*
 * Assignment operator for ListOfTransitions.
 */
ListOfTransitions&
ListOfTransitions::operator=(const ListOfTransitions& rhs)
{
  if (&rhs != this)
  {
    ListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ListOfTransitions object.
 */
ListOfTransitions*
ListOfTransitions::clone() const
{
  return new ListOfTransitions(*this);
}


/*
 * Destructor for ListOfTransitions.
 */
ListOfTransitions::~ListOfTransitions()
{
}


/*
 * Get a Transition from the ListOfTransitions.
 */
Transition*
ListOfTransitions::get(unsigned int n)
{
  return static_cast<Transition*>(ListOf::get(n));
}


/*
 * Get a Transition from the ListOfTransitions.
 */
const Transition*
ListOfTransitions::get(unsigned int n) const
{
  return static_cast<const Transition*>(ListOf::get(n));
}


/*
 * Get a Transition from the ListOfTransitions based on its identifier.
 */
Transition*
ListOfTransitions::get(const std::string& sid)
{
  return const_cast<Transition*>(static_cast<const
    ListOfTransitions&>(*this).get(sid));
}


/*
 * Get a Transition from the ListOfTransitions based on its identifier.
 */
const Transition*
ListOfTransitions::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), IdEq<Transition>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const Transition*>
    (*result);
}


/*
 * Removes the nth Transition from this ListOfTransitions and returns a pointer
 * to it.
 */
Transition*
ListOfTransitions::remove(unsigned int n)
{
  return static_cast<Transition*>(ListOf::remove(n));
}


/*
 * Removes the Transition from this ListOfTransitions based on its identifier
 * and returns a pointer to it.
 */
Transition*
ListOfTransitions::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), IdEq<Transition>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <Transition*> (item);
}


/*
 * Adds a copy of the given Transition to this ListOfTransitions.
 */
int
ListOfTransitions::addTransition(const Transition* t)
{
  if (t == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (t->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != t->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != t->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(t)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(t);
  }
}


/*
 * Get the number of Transition objects in this ListOfTransitions.
 */
unsigned int
ListOfTransitions::getNumTransitions() const
{
  return size();
}


/*
 * Creates a new Transition object, adds it to this ListOfTransitions object
 * and returns the Transition object created.
 */
Transition*
ListOfTransitions::createTransition()
{
  Transition* t = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    t = new Transition(qualns);
    delete qualns;
  }
  catch (...)
  {
  }

  if (t != NULL)
  {
    appendAndOwn(t);
  }

  return t;
}


/*
 * Returns the XML element name of this ListOfTransitions object.
 */
const std::string&
ListOfTransitions::getElementName() const
{
  static const string name = "listOfTransitions";
  return name;
}


/*
 * Returns the libSBML type code for this ListOfTransitions object.
 */
int
ListOfTransitions::getTypeCode() const
{
  return SBML_LIST_OF;
}


/*
 * Returns the libSBML type code for the SBML objects contained in this
 * ListOfTransitions object.
 */
int
ListOfTransitions::getItemTypeCode() const
{
  return SBML_QUAL_TRANSITION;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new Transition in this ListOfTransitions
 */
SBase*
ListOfTransitions::createObject(XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SBase* object = NULL;
  QUAL_CREATE_NS(qualns, getSBMLNamespaces());

  if (name == "transition")
  {
    object = new Transition(qualns);
    appendAndOwn(object);
  }

  delete qualns;
  return object;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the namespace for the Qual package
 */
void
ListOfTransitions::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    const XMLNamespaces* thisxmlns = getNamespaces();
    if (thisxmlns && thisxmlns->hasURI(QualExtension::getXmlnsL3V1V1()))
    {
      xmlns.add(QualExtension::getXmlnsL3V1V1(), prefix);
    }
  }

  stream << xmlns;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a Transition_t from the ListOf_t.
 */
LIBSBML_EXTERN
const Transition_t*
ListOfTransitions_getTransition(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfTransitions*>(lo)->get(n);
}


/*
 * Get a Transition_t from the ListOf_t based on its identifier.
 */
LIBSBML_EXTERN
const Transition_t*
ListOfTransitions_getById(ListOf_t* lo, const char *sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfTransitions*>(lo)->get(sid) : NULL;
}


/*
 * Removes the nth Transition_t from this ListOf_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Transition_t*
ListOfTransitions_remove(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfTransitions*>(lo)->remove(n);
}


/*
 * Removes the Transition_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
Transition_t*
ListOfTransitions_removeById(ListOf_t* lo, const char* sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfTransitions*>(lo)->remove(sid) :
    NULL;
}




LIBSBML_CPP_NAMESPACE_END


