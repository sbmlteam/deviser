/**
 * @file: ParametricGeometry.cpp
 * @brief: Implementation of ParametricGeometry.
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
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
#include <sbml/packages/spatial/sbml/ParametricGeometry.h>
#include <sbml/packages/spatial/validator/SpatialSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ParametricGeometry using the given SBML @p level, @ p version
 * and package version values.
 */
ParametricGeometry::ParametricGeometry(unsigned int level,
                                       unsigned int version,
                                       unsigned int pkgVersion)
  : GeometryDefinition(level, version)
  , mSpatialPoints (NULL)
  , mParametricObjects (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new SpatialPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new ParametricGeometry using the given SpatialPkgNamespaces
 * object.
 */
ParametricGeometry::ParametricGeometry(SpatialPkgNamespaces *spatialns)
  : GeometryDefinition(spatialns)
  , mSpatialPoints (NULL)
  , mParametricObjects (spatialns)
{
  setElementNamespace(spatialns->getURI());
  connectToChild();
  loadPlugins(spatialns);
}


/*
 * Copy constructor for ParametricGeometry.
 */
ParametricGeometry::ParametricGeometry(const ParametricGeometry& orig)
  : GeometryDefinition( orig )
  , mSpatialPoints ( NULL )
  , mParametricObjects ( orig.mParametricObjects )
{
  if (orig.mSpatialPoints != NULL)
  {
    mSpatialPoints = orig.mSpatialPoints->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for ParametricGeometry.
 */
ParametricGeometry&
ParametricGeometry::operator=(const ParametricGeometry& rhs)
{
  if (&rhs != this)
  {
    GeometryDefinition::operator=(rhs);
    mParametricObjects = rhs.mParametricObjects;
    delete mSpatialPoints;
    if (rhs.mSpatialPoints != NULL)
    {
      mSpatialPoints = rhs.mSpatialPoints->clone();
    }
    else
    {
      mSpatialPoints = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ParametricGeometry object.
 */
ParametricGeometry*
ParametricGeometry::clone() const
{
  return new ParametricGeometry(*this);
}


/*
 * Destructor for ParametricGeometry.
 */
ParametricGeometry::~ParametricGeometry()
{
  delete mSpatialPoints;
  mSpatialPoints = NULL;
}


/*
 * Returns the value of the "spatialPoints" element of this ParametricGeometry.
 */
const SpatialPoints*
ParametricGeometry::getSpatialPoints() const
{
  return mSpatialPoints;
}


/*
 * Returns the value of the "spatialPoints" element of this ParametricGeometry.
 */
SpatialPoints*
ParametricGeometry::getSpatialPoints()
{
  return mSpatialPoints;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * ParametricGeometry's "spatialPoints" element has been set.
 */
bool
ParametricGeometry::isSetSpatialPoints() const
{
  return (mSpatialPoints != NULL);
}


/*
 * Sets the value of the "spatialPoints" element of this ParametricGeometry.
 */
int
ParametricGeometry::setSpatialPoints(const SpatialPoints* spatialPoints)
{
  if (mSpatialPoints == spatialPoints)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (spatialPoints == NULL)
  {
    delete mSpatialPoints;
    mSpatialPoints = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mSpatialPoints;
    mSpatialPoints = (spatialPoints != NULL) ? spatialPoints->clone() : NULL;
    if (mSpatialPoints != NULL)
    {
      mSpatialPoints->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SpatialPoints object, adds it to this ParametricGeometry
 * object and returns the SpatialPoints object created.
 */
SpatialPoints*
ParametricGeometry::createSpatialPoints()
{
  if (mSpatialPoints != NULL)
  {
    delete mSpatialPoints;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mSpatialPoints = new SpatialPoints(spatialns);

  delete spatialns;

  connectToChild();

  return mSpatialPoints;
}


/*
 * Unsets the value of the "spatialPoints" element of this ParametricGeometry.
 */
int
ParametricGeometry::unsetSpatialPoints()
{
  delete mSpatialPoints;
  mSpatialPoints = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the ListOfParametricObjects from this ParametricGeometry.
 */
const ListOfParametricObjects*
ParametricGeometry::getListOfParametricObjects() const
{
  return &mParametricObjects;
}


/*
 * Returns the ListOfParametricObjects from this ParametricGeometry.
 */
ListOfParametricObjects*
ParametricGeometry::getListOfParametricObjects()
{
  return &mParametricObjects;
}


/*
 * Get a ParametricObject from the ParametricGeometry.
 */
ParametricObject*
ParametricGeometry::getParametricObject(unsigned int n)
{
  return mParametricObjects.get(n);
}


/*
 * Get a ParametricObject from the ParametricGeometry.
 */
const ParametricObject*
ParametricGeometry::getParametricObject(unsigned int n) const
{
  return mParametricObjects.get(n);
}


/*
 * Get a ParametricObject from the ParametricGeometry based on its identifier.
 */
ParametricObject*
ParametricGeometry::getParametricObject(const std::string& sid)
{
  return mParametricObjects.get(sid);
}


/*
 * Get a ParametricObject from the ParametricGeometry based on its identifier.
 */
const ParametricObject*
ParametricGeometry::getParametricObject(const std::string& sid) const
{
  return mParametricObjects.get(sid);
}


/*
 * Get a ParametricObject from the ParametricGeometry based on the DomainType
 * to which it refers.
 */
const ParametricObject*
ParametricGeometry::getParametricObjectByDomainType(const std::string& sid)
  const
{
  return mParametricObjects.getByDomainType(sid);
}


/*
 * Get a ParametricObject from the ParametricGeometry based on the DomainType
 * to which it refers.
 */
ParametricObject*
ParametricGeometry::getParametricObjectByDomainType(const std::string& sid)
{
  return mParametricObjects.getByDomainType(sid);
}


/*
 * Adds a copy of the given ParametricObject to this ParametricGeometry.
 */
int
ParametricGeometry::addParametricObject(const ParametricObject* po)
{
  if (po == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (po->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != po->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != po->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(po)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (po->isSetId() && (mParametricObjects.get(po->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    mParametricObjects.append(po);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of ParametricObject objects in this ParametricGeometry.
 */
unsigned int
ParametricGeometry::getNumParametricObjects() const
{
  return mParametricObjects.size();
}


/*
 * Creates a new ParametricObject object, adds it to this ParametricGeometry
 * object and returns the ParametricObject object created.
 */
ParametricObject*
ParametricGeometry::createParametricObject()
{
  ParametricObject* po = NULL;

  try
  {
    SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
    po = new ParametricObject(spatialns);
    delete spatialns;
  }
  catch (...)
  {
  }

  if (po != NULL)
  {
    mParametricObjects.appendAndOwn(po);
  }

  return po;
}


/*
 * Removes the nth ParametricObject from this ParametricGeometry and returns a
 * pointer to it.
 */
ParametricObject*
ParametricGeometry::removeParametricObject(unsigned int n)
{
  return mParametricObjects.remove(n);
}


/*
 * Removes the ParametricObject from this ParametricGeometry based on its
 * identifier and returns a pointer to it.
 */
ParametricObject*
ParametricGeometry::removeParametricObject(const std::string& sid)
{
  return mParametricObjects.remove(sid);
}


/*
 * Returns the XML name of this ParametricGeometry object.
 */
const std::string&
ParametricGeometry::getElementName() const
{
  static const string name = "parametricGeometry";
  return name;
}


/*
 * Returns the libSBML typcode of this ParametricGeometry object.
 */
int
ParametricGeometry::getTypeCode() const
{
  return SBML_SPATIAL_PARAMETRICGEOMETRY;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * ParametricGeometry object have been set.
 */
bool
ParametricGeometry::hasRequiredAttributes() const
{
  bool allPresent = GeometryDefinition::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * ParametricGeometry object have been set.
 */
bool
ParametricGeometry::hasRequiredElements() const
{
  bool allPresent = GeometryDefinition::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
ParametricGeometry::writeElements(XMLOutputStream& stream) const
{
  GeometryDefinition::writeElements(stream);

  if (isSetSpatialPoints() == true)
  {
    mSpatialPoints->write(stream);
  }

  if (getNumParametricObjects() > 0)
  {
    mParametricObjects.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
ParametricGeometry::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mSpatialPoints != NULL)
  {
    mSpatialPoints->accept(v);
  }

  mParametricObjects.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
ParametricGeometry::setSBMLDocument(SBMLDocument* d)
{
  GeometryDefinition::setSBMLDocument(d);

  if (mSpatialPoints != NULL)
  {
    mSpatialPoints->setSBMLDocument(d);
  }

  mParametricObjects.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
ParametricGeometry::connectToChild()
{
  GeometryDefinition::connectToChild();

  if (mSpatialPoints != NULL)
  {
    mSpatialPoints->connectToParent(this);
  }

  mParametricObjects.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
ParametricGeometry::enablePackageInternal(const std::string& pkgURI,
                                          const std::string& pkgPrefix,
                                          bool flag)
{
  GeometryDefinition::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetSpatialPoints())
  {
    mSpatialPoints->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  mParametricObjects.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
ParametricGeometry::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mSpatialPoints != NULL)
  {
    if (mSpatialPoints->getId() == id)
    {
      return mSpatialPoints;
    }

    obj = mSpatialPoints->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  obj = mParametricObjects.getElementBySId(id);

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
ParametricGeometry::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mSpatialPoints != NULL)
  {
    if (mSpatialPoints->getMetaId() == metaid)
    {
      return mSpatialPoints;
    }

    obj = mSpatialPoints->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mParametricObjects.getMetaId() == metaid)
  {
    return &mParametricObjects;
  }

  obj = mParametricObjects.getElementByMetaId(metaid);

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
ParametricGeometry::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mSpatialPoints, filter);

  ADD_FILTERED_LIST(ret, sublist, mParametricObjects, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
ParametricGeometry::createObject(XMLInputStream& stream)
{
  SBase* obj = GeometryDefinition::createObject(stream);

  const std::string& name = stream.peek().getName();

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());

  if (name == "spatialPoints")
  {
    if (mSpatialPoints != NULL)
    {
      getErrorLog()->logPackageError("spatial",
        SpatialParametricGeometryAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    mSpatialPoints = new SpatialPoints(spatialns);
    obj = mSpatialPoints;
  }
  else if (name == "listOfParametricObjects")
  {
    if (mParametricObjects.size() != 0)
    {
      getErrorLog()->logPackageError("spatial",
        SpatialParametricGeometryAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    obj = &mParametricObjects;
  }

  delete spatialns;

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ParametricGeometry_t using the given SBML @p level, @ p
 * version and package version values.
 */
LIBSBML_EXTERN
ParametricGeometry_t *
ParametricGeometry_create(unsigned int level,
                          unsigned int version,
                          unsigned int pkgVersion)
{
  return new ParametricGeometry(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ParametricGeometry_t object.
 */
LIBSBML_EXTERN
ParametricGeometry_t*
ParametricGeometry_clone(const ParametricGeometry_t* pg)
{
  if (pg != NULL)
  {
    return static_cast<ParametricGeometry_t*>(pg->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ParametricGeometry_t object.
 */
LIBSBML_EXTERN
void
ParametricGeometry_free(ParametricGeometry_t* pg)
{
  if (pg != NULL)
  {
    delete pg;
  }
}


/*
 * Returns the value of the "spatialPoints" element of this
 * ParametricGeometry_t.
 */
LIBSBML_EXTERN
const SpatialPoints_t*
ParametricGeometry_getSpatialPoints(const ParametricGeometry_t * pg)
{
  if (pg == NULL)
  {
    return NULL;
  }

  return (SpatialPoints_t*)(pg->getSpatialPoints());
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * ParametricGeometry_t's "spatialPoints" element has been set.
 */
LIBSBML_EXTERN
int
ParametricGeometry_isSetSpatialPoints(const ParametricGeometry_t * pg)
{
  return (pg != NULL) ? static_cast<int>(pg->isSetSpatialPoints()) : 0;
}


/*
 * Sets the value of the "spatialPoints" element of this ParametricGeometry_t.
 */
LIBSBML_EXTERN
int
ParametricGeometry_setSpatialPoints(ParametricGeometry_t * pg,
                                    const SpatialPoints_t* spatialPoints)
{
  return (pg != NULL) ? pg->setSpatialPoints(spatialPoints) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new SpatialPoints_t object, adds it to this ParametricGeometry_t
 * object and returns the SpatialPoints_t object created.
 */
LIBSBML_EXTERN
SpatialPoints_t*
ParametricGeometry_createSpatialPoints(ParametricGeometry_t* pg)
{
  if (pg == NULL)
  {
    return NULL;
  }

  return (SpatialPoints_t*)(pg->createSpatialPoints());
}


/*
 * Unsets the value of the "spatialPoints" element of this
 * ParametricGeometry_t.
 */
LIBSBML_EXTERN
int
ParametricGeometry_unsetSpatialPoints(ParametricGeometry_t * pg)
{
  return (pg != NULL) ? pg->unsetSpatialPoints() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t* containing ParametricObject_t objects from this
 * ParametricGeometry_t.
 */
LIBSBML_EXTERN
ListOf_t*
ParametricGeometry_getListOfParametricObjects(ParametricGeometry_t* pg)
{
  return (pg != NULL) ? pg->getListOfParametricObjects() : NULL;
}


/*
 * Get a ParametricObject_t from the ParametricGeometry_t.
 */
LIBSBML_EXTERN
const ParametricObject_t*
ParametricGeometry_getParametricObject(ParametricGeometry_t* pg,
                                       unsigned int n)
{
  return (pg != NULL) ? pg->getParametricObject(n) : NULL;
}


/*
 * Get a ParametricObject_t from the ParametricGeometry_t based on its
 * identifier.
 */
LIBSBML_EXTERN
const ParametricObject_t*
ParametricGeometry_getParametricObjectById(ParametricGeometry_t* pg,
                                           const char *sid)
{
  return (pg != NULL && sid != NULL) ? pg->getParametricObject(sid) : NULL;
}


/*
 * Get a ParametricObject_t from the ParametricGeometry_t based on the
 * DomainType to which it refers.
 */
LIBSBML_EXTERN
const ParametricObject_t*
ParametricGeometry_getParametricObjectByDomainType(ParametricGeometry_t* pg,
                                                   const char *sid)
{
  return (pg != NULL && sid != NULL) ? pg->getParametricObjectByDomainType(sid)
    : NULL;
}


/*
 * Adds a copy of the given ParametricObject_t to this ParametricGeometry_t.
 */
LIBSBML_EXTERN
int
ParametricGeometry_addParametricObject(ParametricGeometry_t* pg,
                                       const ParametricObject_t* po)
{
  return (pg != NULL) ? pg->addParametricObject(po) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of ParametricObject_t objects in this ParametricGeometry_t.
 */
LIBSBML_EXTERN
unsigned int
ParametricGeometry_getNumParametricObjects(ParametricGeometry_t* pg)
{
  return (pg != NULL) ? pg->getNumParametricObjects() : SBML_INT_MAX;
}


/*
 * Creates a new ParametricObject_t object, adds it to this
 * ParametricGeometry_t object and returns the ParametricObject_t object
 * created.
 */
LIBSBML_EXTERN
ParametricObject_t*
ParametricGeometry_createParametricObject(ParametricGeometry_t* pg)
{
  return (pg != NULL) ? pg->createParametricObject() : NULL;
}


/*
 * Removes the nth ParametricObject_t from this ParametricGeometry_t and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
ParametricObject_t*
ParametricGeometry_removeParametricObject(ParametricGeometry_t* pg,
                                          unsigned int n)
{
  return (pg != NULL) ? pg->removeParametricObject(n) : NULL;
}


/*
 * Removes the ParametricObject_t from this ParametricGeometry_t based on its
 * identifier and returns a pointer to it.
 */
LIBSBML_EXTERN
ParametricObject_t*
ParametricGeometry_removeParametricObjectById(ParametricGeometry_t* pg,
                                              const char* sid)
{
  return (pg != NULL && sid != NULL) ? pg->removeParametricObject(sid) : NULL;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * ParametricGeometry_t object have been set.
 */
LIBSBML_EXTERN
int
ParametricGeometry_hasRequiredAttributes(const ParametricGeometry_t * pg)
{
  return (pg != NULL) ? static_cast<int>(pg->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this
 * ParametricGeometry_t object have been set.
 */
LIBSBML_EXTERN
int
ParametricGeometry_hasRequiredElements(const ParametricGeometry_t * pg)
{
  return (pg != NULL) ? static_cast<int>(pg->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END

