/**
 * @file ListOfChildren.cpp
 * @brief Implementation of the ListOfChildren class.
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
#include <sbml/packages/nasty/sbml/ListOfChildren.h>
#include <sbml/packages/nasty/validator/NastySBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ListOfChildren using the given SBML Level, Version and
 * &ldquo;nasty&rdquo; package version.
 */
ListOfChildren::ListOfChildren(unsigned int level,
                               unsigned int version,
                               unsigned int pkgVersion)
  : ListOf(level, version)
{
  setSBMLNamespacesAndOwn(new NastyPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ListOfChildren using the given NastyPkgNamespaces object.
 */
ListOfChildren::ListOfChildren(NastyPkgNamespaces *nastyns)
  : ListOf(nastyns)
{
  setElementNamespace(nastyns->getURI());
}


/*
 * Copy constructor for ListOfChildren.
 */
ListOfChildren::ListOfChildren(const ListOfChildren& orig)
  : ListOf( orig )
{
}


/*
 * Assignment operator for ListOfChildren.
 */
ListOfChildren&
ListOfChildren::operator=(const ListOfChildren& rhs)
{
  if (&rhs != this)
  {
    ListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ListOfChildren object.
 */
ListOfChildren*
ListOfChildren::clone() const
{
  return new ListOfChildren(*this);
}


/*
 * Destructor for ListOfChildren.
 */
ListOfChildren::~ListOfChildren()
{
}


/*
 * Get a Child from the ListOfChildren.
 */
Child*
ListOfChildren::get(unsigned int n)
{
  return static_cast<Child*>(ListOf::get(n));
}


/*
 * Get a Child from the ListOfChildren.
 */
const Child*
ListOfChildren::get(unsigned int n) const
{
  return static_cast<const Child*>(ListOf::get(n));
}


/*
 * Get a Child from the ListOfChildren based on its identifier.
 */
Child*
ListOfChildren::get(const std::string& sid)
{
  return const_cast<Child*>(static_cast<const
    ListOfChildren&>(*this).get(sid));
}


/*
 * Get a Child from the ListOfChildren based on its identifier.
 */
const Child*
ListOfChildren::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), IdEq<Child>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const Child*> (*result);
}


/*
 * Removes the nth Child from this ListOfChildren and returns a pointer to it.
 */
Child*
ListOfChildren::remove(unsigned int n)
{
  return static_cast<Child*>(ListOf::remove(n));
}


/*
 * Removes the Child from this ListOfChildren based on its identifier and
 * returns a pointer to it.
 */
Child*
ListOfChildren::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), IdEq<Child>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <Child*> (item);
}


/*
 * Adds a copy of the given Child to this ListOfChildren.
 */
int
ListOfChildren::addChild(const Child* c)
{
  if (c == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (c->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != c->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != c->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(c)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(c);
  }
}


/*
 * Get the number of Child objects in this ListOfChildren.
 */
unsigned int
ListOfChildren::getNumChildren() const
{
  return size();
}


/*
 * Creates a new Child object, adds it to this ListOfChildren object and
 * returns the Child object created.
 */
Child*
ListOfChildren::createChild()
{
  Child* c = NULL;

  try
  {
    NASTY_CREATE_NS(nastyns, getSBMLNamespaces());
    c = new Child(nastyns);
    delete nastyns;
  }
  catch (...)
  {
  }

  if (c != NULL)
  {
    appendAndOwn(c);
  }

  return c;
}


/*
 * Returns the XML element name of this ListOfChildren object.
 */
const std::string&
ListOfChildren::getElementName() const
{
  static const string name = "listOfChildren";
  return name;
}


/*
 * Returns the libSBML type code for this ListOfChildren object.
 */
int
ListOfChildren::getTypeCode() const
{
  return SBML_LIST_OF;
}


/*
 * Returns the libSBML type code for the SBML objects contained in this
 * ListOfChildren object.
 */
int
ListOfChildren::getItemTypeCode() const
{
  return SBML_NASTY_CHILD;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new Child in this ListOfChildren
 */
SBase*
ListOfChildren::createObject(XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SBase* object = NULL;
  NASTY_CREATE_NS(nastyns, getSBMLNamespaces());

  if (name == "child")
  {
    object = new Child(nastyns);
    appendAndOwn(object);
  }

  delete nastyns;
  return object;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the namespace for the Nasty package
 */
void
ListOfChildren::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    const XMLNamespaces* thisxmlns = getNamespaces();
    if (thisxmlns && thisxmlns->hasURI(NastyExtension::getXmlnsL3V1V1()))
    {
      xmlns.add(NastyExtension::getXmlnsL3V1V1(), prefix);
    }
  }

  stream << xmlns;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a Child_t from the ListOf_t.
 */
LIBSBML_EXTERN
Child_t*
ListOfChildren_getChild(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfChildren*>(lo)->get(n);
}


/*
 * Get a Child_t from the ListOf_t based on its identifier.
 */
LIBSBML_EXTERN
Child_t*
ListOfChildren_getById(ListOf_t* lo, const char *sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfChildren*>(lo)->get(sid) : NULL;
}


/*
 * Removes the nth Child_t from this ListOf_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Child_t*
ListOfChildren_remove(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfChildren*>(lo)->remove(n);
}


/*
 * Removes the Child_t from this ListOf_t based on its identifier and returns a
 * pointer to it.
 */
LIBSBML_EXTERN
Child_t*
ListOfChildren_removeById(ListOf_t* lo, const char* sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfChildren*>(lo)->remove(sid) : NULL;
}




LIBSBML_CPP_NAMESPACE_END


