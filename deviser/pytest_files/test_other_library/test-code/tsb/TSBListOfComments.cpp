/**
 * @file TSBListOfComments.cpp
 * @brief Implementation of the TSBListOfComments class.
 * @author DEVISER
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
#include <tsb/TSBListOfComments.h>
#include <xml/XMLInputStream.h>


using namespace std;



LIBTSB_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new TSBListOfComments using the given TSB Level and @ p version
 * values.
 */
TSBListOfComments::TSBListOfComments(unsigned int level, unsigned int version)
  : TSBListOf(level, version)
{
  setTSBNamespacesAndOwn(new TSBNamespaces(level, version));
}


/*
 * Creates a new TSBListOfComments using the given TSBNamespaces object @p
 * tsbns.
 */
TSBListOfComments::TSBListOfComments(TSBNamespaces *tsbns)
  : TSBListOf(tsbns)
{
  setElementNamespace(tsbns->getURI());
}


/*
 * Copy constructor for TSBListOfComments.
 */
TSBListOfComments::TSBListOfComments(const TSBListOfComments& orig)
  : TSBListOf( orig )
{
}


/*
 * Assignment operator for TSBListOfComments.
 */
TSBListOfComments&
TSBListOfComments::operator=(const TSBListOfComments& rhs)
{
  if (&rhs != this)
  {
    TSBListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this TSBListOfComments object.
 */
TSBListOfComments*
TSBListOfComments::clone() const
{
  return new TSBListOfComments(*this);
}


/*
 * Destructor for TSBListOfComments.
 */
TSBListOfComments::~TSBListOfComments()
{
}


/*
 * Get a TSBComment from the TSBListOfComments.
 */
TSBComment*
TSBListOfComments::get(unsigned int n)
{
  return static_cast<TSBComment*>(TSBListOf::get(n));
}


/*
 * Get a TSBComment from the TSBListOfComments.
 */
const TSBComment*
TSBListOfComments::get(unsigned int n) const
{
  return static_cast<const TSBComment*>(TSBListOf::get(n));
}


/*
 * Get a TSBComment from the TSBListOfComments based on its identifier.
 */
TSBComment*
TSBListOfComments::get(const std::string& sid)
{
  return const_cast<TSBComment*>(static_cast<const
    TSBListOfComments&>(*this).get(sid));
}


/*
 * Get a TSBComment from the TSBListOfComments based on its identifier.
 */
const TSBComment*
TSBListOfComments::get(const std::string& sid) const
{
  vector<TSBBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), TSBIdEq<TSBComment>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const TSBComment*>
    (*result);
}


/*
 * Removes the nth TSBComment from this TSBListOfComments and returns a pointer
 * to it.
 */
TSBComment*
TSBListOfComments::remove(unsigned int n)
{
  return static_cast<TSBComment*>(TSBListOf::remove(n));
}


/*
 * Removes the TSBComment from this TSBListOfComments based on its identifier
 * and returns a pointer to it.
 */
TSBComment*
TSBListOfComments::remove(const std::string& sid)
{
  TSBBase* item = NULL;
  vector<TSBBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), TSBIdEq<TSBComment>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <TSBComment*> (item);
}


/*
 * Adds a copy of the given TSBComment to this TSBListOfComments.
 */
int
TSBListOfComments::addComment(const TSBComment* tsbc)
{
  if (tsbc == NULL)
  {
    return LIBTSB_OPERATION_FAILED;
  }
  else if (tsbc->hasRequiredAttributes() == false)
  {
    return LIBTSB_INVALID_OBJECT;
  }
  else if (getLevel() != tsbc->getLevel())
  {
    return LIBTSB_LEVEL_MISMATCH;
  }
  else if (getVersion() != tsbc->getVersion())
  {
    return LIBTSB_VERSION_MISMATCH;
  }
  else if (matchesRequiredTSBNamespacesForAddition(static_cast<const
    TSBBase*>(tsbc)) == false)
  {
    return LIBTSB_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(tsbc);
  }
}


/*
 * Get the number of TSBComment objects in this TSBListOfComments.
 */
unsigned int
TSBListOfComments::getNumComments() const
{
  return size();
}


/*
 * Creates a new TSBComment object, adds it to this TSBListOfComments object
 * and returns the TSBComment object created.
 */
TSBComment*
TSBListOfComments::createComment()
{
  TSBComment* tsbc = NULL;

  try
  {
    tsbc = new TSBComment(getTSBNamespaces());
  }
  catch (...)
  {
  }

  if (tsbc != NULL)
  {
    appendAndOwn(tsbc);
  }

  return tsbc;
}


/*
 * Returns the XML element name of this TSBListOfComments object.
 */
const std::string&
TSBListOfComments::getElementName() const
{
  static const string name = "listOfComments";
  return name;
}


/*
 * Returns the libTSB type code for this TSBListOfComments object.
 */
int
TSBListOfComments::getTypeCode() const
{
  return TSB_LIST_OF;
}


/*
 * Returns the libTSB type code for the TSB objects contained in this
 * TSBListOfComments object.
 */
int
TSBListOfComments::getItemTypeCode() const
{
  return TSB_COMMENT;
}



/** @cond doxygenlibTSBInternal */

/*
 * Creates a new TSBComment in this TSBListOfComments
 */
TSBBase*
TSBListOfComments::createObject(XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  TSBBase* object = NULL;

  if (name == "comment")
  {
    object = new TSBComment(getTSBNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a TSBComment_t from the TSBListOf_t.
 */
LIBTSB_EXTERN
TSBComment_t*
TSBListOfComments_getComment(TSBListOf_t* tsblo, unsigned int n)
{
  if (tsblo == NULL)
  {
    return NULL;
  }

  return static_cast <TSBListOfComments*>(tsblo)->get(n);
}


/*
 * Get a TSBComment_t from the TSBListOf_t based on its identifier.
 */
LIBTSB_EXTERN
TSBComment_t*
TSBListOfComments_getById(TSBListOf_t* tsblo, const char *sid)
{
  if (tsblo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <TSBListOfComments*>(tsblo)->get(sid) :
    NULL;
}


/*
 * Removes the nth TSBComment_t from this TSBListOf_t and returns a pointer to
 * it.
 */
LIBTSB_EXTERN
TSBComment_t*
TSBListOfComments_remove(TSBListOf_t* tsblo, unsigned int n)
{
  if (tsblo == NULL)
  {
    return NULL;
  }

  return static_cast <TSBListOfComments*>(tsblo)->remove(n);
}


/*
 * Removes the TSBComment_t from this TSBListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBTSB_EXTERN
TSBComment_t*
TSBListOfComments_removeById(TSBListOf_t* tsblo, const char* sid)
{
  if (tsblo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <TSBListOfComments*>(tsblo)->remove(sid) :
    NULL;
}




LIBTSB_CPP_NAMESPACE_END


