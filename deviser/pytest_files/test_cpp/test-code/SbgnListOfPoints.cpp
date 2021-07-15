/**
 * @file SbgnListOfPoints.cpp
 * @brief Implementation of the SbgnListOfPoints class.
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
#include <sbgn/SbgnListOfPoints.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnListOfPoints using the given SBGN Level and @ p version
 * values.
 */
SbgnListOfPoints::SbgnListOfPoints(unsigned int level, unsigned int version)
  : SbgnListOf(level, version)
  , mElementName("point")
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnListOfPoints using the given SbgnNamespaces object @p
 * sbgnns.
 */
SbgnListOfPoints::SbgnListOfPoints(SbgnNamespaces *sbgnns)
  : SbgnListOf(sbgnns)
  , mElementName("point")
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnListOfPoints.
 */
SbgnListOfPoints::SbgnListOfPoints(const SbgnListOfPoints& orig)
  : SbgnListOf( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SbgnListOfPoints.
 */
SbgnListOfPoints&
SbgnListOfPoints::operator=(const SbgnListOfPoints& rhs)
{
  if (&rhs != this)
  {
    SbgnListOf::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnListOfPoints object.
 */
SbgnListOfPoints*
SbgnListOfPoints::clone() const
{
  return new SbgnListOfPoints(*this);
}


/*
 * Destructor for SbgnListOfPoints.
 */
SbgnListOfPoints::~SbgnListOfPoints()
{
}


/*
 * Get a Point from the SbgnListOfPoints.
 */
Point*
SbgnListOfPoints::get(unsigned int n)
{
  return static_cast<Point*>(SbgnListOf::get(n));
}


/*
 * Get a Point from the SbgnListOfPoints.
 */
const Point*
SbgnListOfPoints::get(unsigned int n) const
{
  return static_cast<const Point*>(SbgnListOf::get(n));
}


/*
 * Get a Point from the SbgnListOfPoints based on its identifier.
 */
Point*
SbgnListOfPoints::get(const std::string& sid)
{
  return const_cast<Point*>(static_cast<const
    SbgnListOfPoints&>(*this).get(sid));
}


/*
 * Get a Point from the SbgnListOfPoints based on its identifier.
 */
const Point*
SbgnListOfPoints::get(const std::string& sid) const
{
  vector<SbgnBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<Point>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const Point*> (*result);
}


/*
 * Removes the nth Point from this SbgnListOfPoints and returns a pointer to
 * it.
 */
Point*
SbgnListOfPoints::remove(unsigned int n)
{
  return static_cast<Point*>(SbgnListOf::remove(n));
}


/*
 * Removes the Point from this SbgnListOfPoints based on its identifier and
 * returns a pointer to it.
 */
Point*
SbgnListOfPoints::remove(const std::string& sid)
{
  SbgnBase* item = NULL;
  vector<SbgnBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<Point>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <Point*> (item);
}


/*
 * Adds a copy of the given Point to this SbgnListOfPoints.
 */
int
SbgnListOfPoints::addPoint(const Point* p)
{
  if (p == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (p->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != p->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != p->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(p)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(p);
  }
}


/*
 * Get the number of Point objects in this SbgnListOfPoints.
 */
unsigned int
SbgnListOfPoints::getNumPoints() const
{
  return size();
}


/*
 * Creates a new Point object, adds it to this SbgnListOfPoints object and
 * returns the Point object created.
 */
Point*
SbgnListOfPoints::createPoint()
{
  Point* p = NULL;

  try
  {
    p = new Point(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (p != NULL)
  {
    appendAndOwn(p);
  }

  return p;
}


/*
 * Returns the XML element name of this SbgnListOfPoints object.
 */
const std::string&
SbgnListOfPoints::getElementName() const
{
  return mElementName;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the XML name of this SbgnListOfPoints object.
 */
void
SbgnListOfPoints::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBGN type code for this SbgnListOfPoints object.
 */
int
SbgnListOfPoints::getTypeCode() const
{
  return SBGN_LIST_OF;
}


/*
 * Returns the libSBGN type code for the SBGN objects contained in this
 * SbgnListOfPoints object.
 */
int
SbgnListOfPoints::getItemTypeCode() const
{
  return SBGN_SBGNML_POINT;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new Point in this SbgnListOfPoints
 */
SbgnBase*
SbgnListOfPoints::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SbgnBase* object = NULL;

  if (name == mElementName)
  {
    object = new Point(getSbgnNamespaces());
    if (object)
    {
      dynamic_cast<Point*>(object)->setElementName(name);
    }

    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a Point_t from the SbgnListOf_t.
 */
LIBSBGN_EXTERN
Point_t*
SbgnListOfPoints_getPoint(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfPoints*>(slo)->get(n);
}


/*
 * Get a Point_t from the SbgnListOf_t based on its identifier.
 */
LIBSBGN_EXTERN
Point_t*
SbgnListOfPoints_getById(SbgnListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfPoints*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth Point_t from this SbgnListOf_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
Point_t*
SbgnListOfPoints_remove(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfPoints*>(slo)->remove(n);
}


/*
 * Removes the Point_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
Point_t*
SbgnListOfPoints_removeById(SbgnListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfPoints*>(slo)->remove(sid) :
    NULL;
}




LIBSBGN_CPP_NAMESPACE_END


