/**
 * @file ListOfAssociations.cpp
 * @brief Implementation of the ListOfAssociations class.
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
#include <sbml/packages/fbc/sbml/ListOfAssociations.h>
#include <sbml/packages/fbc/validator/FbcSBMLError.h>

#include <sbml/packages/fbc/sbml/FbcAnd.h>
#include <sbml/packages/fbc/sbml/FbcOr.h>
#include <sbml/packages/fbc/sbml/GeneProductRef.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ListOfAssociations using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 */
ListOfAssociations::ListOfAssociations(unsigned int level,
                                       unsigned int version,
                                       unsigned int pkgVersion)
  : ListOf(level, version)
  , mElementName("listOfAssociations")
{
  setSBMLNamespacesAndOwn(new FbcPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ListOfAssociations using the given FbcPkgNamespaces object.
 */
ListOfAssociations::ListOfAssociations(FbcPkgNamespaces *fbcns)
  : ListOf(fbcns)
  , mElementName("listOfAssociations")
{
  setElementNamespace(fbcns->getURI());
}


/*
 * Copy constructor for ListOfAssociations.
 */
ListOfAssociations::ListOfAssociations(const ListOfAssociations& orig)
  : ListOf( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for ListOfAssociations.
 */
ListOfAssociations&
ListOfAssociations::operator=(const ListOfAssociations& rhs)
{
  if (&rhs != this)
  {
    ListOf::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ListOfAssociations object.
 */
ListOfAssociations*
ListOfAssociations::clone() const
{
  return new ListOfAssociations(*this);
}


/*
 * Destructor for ListOfAssociations.
 */
ListOfAssociations::~ListOfAssociations()
{
}


/*
 * Get an Association from the ListOfAssociations.
 */
Association*
ListOfAssociations::get(unsigned int n)
{
  return static_cast<Association*>(ListOf::get(n));
}


/*
 * Get an Association from the ListOfAssociations.
 */
const Association*
ListOfAssociations::get(unsigned int n) const
{
  return static_cast<const Association*>(ListOf::get(n));
}


/*
 * Get an Association from the ListOfAssociations based on its identifier.
 */
Association*
ListOfAssociations::get(const std::string& sid)
{
  return const_cast<Association*>(static_cast<const
    ListOfAssociations&>(*this).get(sid));
}


/*
 * Get an Association from the ListOfAssociations based on its identifier.
 */
const Association*
ListOfAssociations::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), IdEq<Association>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const Association*>
    (*result);
}


/*
 * Removes the nth Association from this ListOfAssociations and returns a
 * pointer to it.
 */
Association*
ListOfAssociations::remove(unsigned int n)
{
  return static_cast<Association*>(ListOf::remove(n));
}


/*
 * Removes the Association from this ListOfAssociations based on its identifier
 * and returns a pointer to it.
 */
Association*
ListOfAssociations::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), IdEq<Association>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <Association*> (item);
}


/*
 * Adds a copy of the given Association to this ListOfAssociations.
 */
int
ListOfAssociations::addAssociation(const Association* a)
{
  if (a == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (a->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != a->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != a->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(a)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(a);
  }
}


/*
 * Get the number of Association objects in this ListOfAssociations.
 */
unsigned int
ListOfAssociations::getNumAssociations() const
{
  return size();
}


/*
 * Creates a new FbcAnd object, adds it to this ListOfAssociations object and
 * returns the FbcAnd object created.
 */
FbcAnd*
ListOfAssociations::createAnd()
{
  FbcAnd* fa = NULL;

  try
  {
    FBC_CREATE_NS_WITH_VERSION(fbcns, getSBMLNamespaces(),
      getPackageVersion());
    fa = new FbcAnd(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (fa != NULL)
  {
    appendAndOwn(fa);
  }

  return fa;
}


/*
 * Creates a new FbcOr object, adds it to this ListOfAssociations object and
 * returns the FbcOr object created.
 */
FbcOr*
ListOfAssociations::createOr()
{
  FbcOr* fo = NULL;

  try
  {
    FBC_CREATE_NS_WITH_VERSION(fbcns, getSBMLNamespaces(),
      getPackageVersion());
    fo = new FbcOr(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (fo != NULL)
  {
    appendAndOwn(fo);
  }

  return fo;
}


/*
 * Creates a new GeneProductRef object, adds it to this ListOfAssociations
 * object and returns the GeneProductRef object created.
 */
GeneProductRef*
ListOfAssociations::createGeneProductRef()
{
  GeneProductRef* gpr = NULL;

  try
  {
    FBC_CREATE_NS_WITH_VERSION(fbcns, getSBMLNamespaces(),
      getPackageVersion());
    gpr = new GeneProductRef(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (gpr != NULL)
  {
    appendAndOwn(gpr);
  }

  return gpr;
}


/*
 * Returns the XML element name of this ListOfAssociations object.
 */
const std::string&
ListOfAssociations::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the XML name of this ListOfAssociations object.
 */
void
ListOfAssociations::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBML type code for this ListOfAssociations object.
 */
int
ListOfAssociations::getTypeCode() const
{
  return SBML_LIST_OF;
}


/*
 * Returns the libSBML type code for the SBML objects contained in this
 * ListOfAssociations object.
 */
int
ListOfAssociations::getItemTypeCode() const
{
  return SBML_FBC_ASSOCIATION;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new Association in this ListOfAssociations
 */
SBase*
ListOfAssociations::createObject(XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SBase* object = NULL;
  FBC_CREATE_NS(fbcns, getSBMLNamespaces());

  if (name == "association")
  {
    object = new Association(fbcns);
    appendAndOwn(object);
  }

  if (name == "fbcAnd")
  {
    object = new FbcAnd(fbcns);
    appendAndOwn(object);
  }

  if (name == "fbcOr")
  {
    object = new FbcOr(fbcns);
    appendAndOwn(object);
  }

  if (name == "geneProductRef")
  {
    object = new GeneProductRef(fbcns);
    appendAndOwn(object);
  }

  delete fbcns;
  return object;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * checks concrete types
 */
bool
ListOfAssociations::isValidTypeForList(SBase* item)
{
  unsigned int tc = item->getTypeCode();

  return ((tc == SBML_FBC_AND) || (tc == SBML_FBC_OR) || (tc ==
    SBML_FBC_GENEPRODUCTREF));
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get an Association_t from the ListOf_t.
 */
LIBSBML_EXTERN
Association_t*
ListOfAssociations_getAssociation(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfAssociations*>(lo)->get(n);
}


/*
 * Get an Association_t from the ListOf_t based on its identifier.
 */
LIBSBML_EXTERN
Association_t*
ListOfAssociations_getById(ListOf_t* lo, const char *sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfAssociations*>(lo)->get(sid) :
    NULL;
}


/*
 * Removes the nth Association_t from this ListOf_t and returns a pointer to
 * it.
 */
LIBSBML_EXTERN
Association_t*
ListOfAssociations_remove(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfAssociations*>(lo)->remove(n);
}


/*
 * Removes the Association_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
Association_t*
ListOfAssociations_removeById(ListOf_t* lo, const char* sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfAssociations*>(lo)->remove(sid) :
    NULL;
}




LIBSBML_CPP_NAMESPACE_END


