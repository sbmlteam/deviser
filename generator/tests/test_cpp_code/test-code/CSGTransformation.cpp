/**
 * @file: CSGTransformation.cpp
 * @brief: Implementation of CSGTransformation.
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
#include <sbml/packages/spatial/sbml/CSGTransformation.h>
#include <sbml/packages/spatial/validator/SpatialSBMLError.h>
#include <sbml/util/ElementFilter.h>

#include <sbml/packages/spatial/sbml/CSGTranslation.h>
#include <sbml/packages/spatial/sbml/CSGRotation.h>
#include <sbml/packages/spatial/sbml/CSGScale.h>
#include <sbml/packages/spatial/sbml/CSGHomogeneousTransformation.h>
#include <sbml/packages/spatial/sbml/CSGPrimitive.h>
#include <sbml/packages/spatial/sbml/CSGTransformation.h>
#include <sbml/packages/spatial/sbml/CSGPseudoPrimitive.h>
#include <sbml/packages/spatial/sbml/CSGSetOperator.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new CSGTransformation using the given SBML @p level, @ p version
 * and package version values.
 */
CSGTransformation::CSGTransformation(unsigned int level,
                                     unsigned int version,
                                     unsigned int pkgVersion)
  : CSGNode(level, version)
  , mCsgNode (NULL)
{
  setSBMLNamespacesAndOwn(new SpatialPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new CSGTransformation using the given SpatialPkgNamespaces object.
 */
CSGTransformation::CSGTransformation(SpatialPkgNamespaces *spatialns)
  : CSGNode(spatialns)
  , mCsgNode (NULL)
{
  setElementNamespace(spatialns->getURI());
  connectToChild();
  loadPlugins(spatialns);
}


/*
 * Copy constructor for CSGTransformation.
 */
CSGTransformation::CSGTransformation(const CSGTransformation& orig)
  : CSGNode( orig )
  , mCsgNode ( NULL )
{
  if (orig.mCsgNode != NULL)
  {
    mCsgNode = orig.mCsgNode->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for CSGTransformation.
 */
CSGTransformation&
CSGTransformation::operator=(const CSGTransformation& rhs)
{
  if (&rhs != this)
  {
    CSGNode::operator=(rhs);
    delete mCsgNode;
    if (rhs.mCsgNode != NULL)
    {
      mCsgNode = rhs.mCsgNode->clone();
    }
    else
    {
      mCsgNode = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this CSGTransformation object.
 */
CSGTransformation*
CSGTransformation::clone() const
{
  return new CSGTransformation(*this);
}


/*
 * Destructor for CSGTransformation.
 */
CSGTransformation::~CSGTransformation()
{
  delete mCsgNode;
  mCsgNode = NULL;
}


/*
 * Returns the value of the "csgNode" element of this CSGTransformation.
 */
const CSGNode*
CSGTransformation::getCsgNode() const
{
  return mCsgNode;
}


/*
 * Returns the value of the "csgNode" element of this CSGTransformation.
 */
CSGNode*
CSGTransformation::getCsgNode()
{
  return mCsgNode;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * CSGTransformation's "csgNode" element has been set.
 */
bool
CSGTransformation::isSetCsgNode() const
{
  return (mCsgNode != NULL);
}


/*
 * Sets the value of the "csgNode" element of this CSGTransformation.
 */
int
CSGTransformation::setCsgNode(const CSGNode* csgNode)
{
  if (mCsgNode == csgNode)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (csgNode == NULL)
  {
    delete mCsgNode;
    mCsgNode = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mCsgNode;
    mCsgNode = (csgNode != NULL) ? csgNode->clone() : NULL;
    if (mCsgNode != NULL)
    {
      mCsgNode->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new CSGPrimitive object, adds it to this CSGTransformation object
 * and returns the CSGPrimitive object created.
 */
CSGPrimitive*
CSGTransformation::createCSGPrimitive()
{
  if (mCsgNode != NULL)
  {
    delete mCsgNode;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mCsgNode = new CSGPrimitive(spatialns);

  delete spatialns;

  connectToChild();

  return static_cast<CSGPrimitive*>(mCsgNode);
}


/*
 * Creates a new CSGTranslation object, adds it to this CSGTransformation
 * object and returns the CSGTranslation object created.
 */
CSGTranslation*
CSGTransformation::createCSGTranslation()
{
  if (mCsgNode != NULL)
  {
    delete mCsgNode;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mCsgNode = new CSGTranslation(spatialns);

  delete spatialns;

  connectToChild();

  return static_cast<CSGTranslation*>(mCsgNode);
}


/*
 * Creates a new CSGRotation object, adds it to this CSGTransformation object
 * and returns the CSGRotation object created.
 */
CSGRotation*
CSGTransformation::createCSGRotation()
{
  if (mCsgNode != NULL)
  {
    delete mCsgNode;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mCsgNode = new CSGRotation(spatialns);

  delete spatialns;

  connectToChild();

  return static_cast<CSGRotation*>(mCsgNode);
}


/*
 * Creates a new CSGScale object, adds it to this CSGTransformation object and
 * returns the CSGScale object created.
 */
CSGScale*
CSGTransformation::createCSGScale()
{
  if (mCsgNode != NULL)
  {
    delete mCsgNode;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mCsgNode = new CSGScale(spatialns);

  delete spatialns;

  connectToChild();

  return static_cast<CSGScale*>(mCsgNode);
}


/*
 * Creates a new CSGHomogeneousTransformation object, adds it to this
 * CSGTransformation object and returns the CSGHomogeneousTransformation object
 * created.
 */
CSGHomogeneousTransformation*
CSGTransformation::createCSGHomogeneousTransformation()
{
  if (mCsgNode != NULL)
  {
    delete mCsgNode;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mCsgNode = new CSGHomogeneousTransformation(spatialns);

  delete spatialns;

  connectToChild();

  return static_cast<CSGHomogeneousTransformation*>(mCsgNode);
}


/*
 * Creates a new CSGPseudoPrimitive object, adds it to this CSGTransformation
 * object and returns the CSGPseudoPrimitive object created.
 */
CSGPseudoPrimitive*
CSGTransformation::createCSGPseudoPrimitive()
{
  if (mCsgNode != NULL)
  {
    delete mCsgNode;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mCsgNode = new CSGPseudoPrimitive(spatialns);

  delete spatialns;

  connectToChild();

  return static_cast<CSGPseudoPrimitive*>(mCsgNode);
}


/*
 * Creates a new CSGSetOperator object, adds it to this CSGTransformation
 * object and returns the CSGSetOperator object created.
 */
CSGSetOperator*
CSGTransformation::createCSGSetOperator()
{
  if (mCsgNode != NULL)
  {
    delete mCsgNode;
  }

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());
  mCsgNode = new CSGSetOperator(spatialns);

  delete spatialns;

  connectToChild();

  return static_cast<CSGSetOperator*>(mCsgNode);
}


/*
 * Unsets the value of the "csgNode" element of this CSGTransformation.
 */
int
CSGTransformation::unsetCsgNode()
{
  delete mCsgNode;
  mCsgNode = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Predicate returning @c true if this abstract "CSGTransformation" is of type
 * CSGTranslation
 */
bool
CSGTransformation::isCSGTranslation() const
{
  return dynamic_cast<const CSGTranslation*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "CSGTransformation" is of type
 * CSGRotation
 */
bool
CSGTransformation::isCSGRotation() const
{
  return dynamic_cast<const CSGRotation*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "CSGTransformation" is of type
 * CSGScale
 */
bool
CSGTransformation::isCSGScale() const
{
  return dynamic_cast<const CSGScale*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "CSGTransformation" is of type
 * CSGHomogeneousTransformation
 */
bool
CSGTransformation::isCSGHomogeneousTransformation() const
{
  return dynamic_cast<const CSGHomogeneousTransformation*>(this) != NULL;
}


/*
 * Returns the XML name of this CSGTransformation object.
 */
const std::string&
CSGTransformation::getElementName() const
{
  static const string name = "csgTransformation";
  return name;
}


/*
 * Returns the libSBML typcode of this CSGTransformation object.
 */
int
CSGTransformation::getTypeCode() const
{
  return SBML_SPATIAL_CSGTRANSFORMATION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * CSGTransformation object have been set.
 */
bool
CSGTransformation::hasRequiredAttributes() const
{
  bool allPresent = CSGNode::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * CSGTransformation object have been set.
 */
bool
CSGTransformation::hasRequiredElements() const
{
  bool allPresent = CSGNode::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
CSGTransformation::writeElements(XMLOutputStream& stream) const
{
  CSGNode::writeElements(stream);

  if (isSetCsgNode() == true)
  {
    mCsgNode->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
CSGTransformation::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mCsgNode != NULL)
  {
    mCsgNode->accept(v);
  }

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
CSGTransformation::setSBMLDocument(SBMLDocument* d)
{
  CSGNode::setSBMLDocument(d);

  if (mCsgNode != NULL)
  {
    mCsgNode->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
CSGTransformation::connectToChild()
{
  CSGNode::connectToChild();

  if (mCsgNode != NULL)
  {
    mCsgNode->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
CSGTransformation::enablePackageInternal(const std::string& pkgURI,
                                         const std::string& pkgPrefix,
                                         bool flag)
{
  CSGNode::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetCsgNode())
  {
    mCsgNode->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
CSGTransformation::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mCsgNode != NULL)
  {
    if (mCsgNode->getId() == id)
    {
      return mCsgNode;
    }

    obj = mCsgNode->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
CSGTransformation::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mCsgNode != NULL)
  {
    if (mCsgNode->getMetaId() == metaid)
    {
      return mCsgNode;
    }

    obj = mCsgNode->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
CSGTransformation::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mCsgNode, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
CSGTransformation::createObject(XMLInputStream& stream)
{
  SBase* obj = CSGNode::createObject(stream);

  const std::string& name = stream.peek().getName();

  SPATIAL_CREATE_NS(spatialns, getSBMLNamespaces());

  if (name == "csgPrimitive")
  {
    mCsgNode = new CSGPrimitive(spatialns);
    obj = mCsgNode;
  }
  else if (name == "csgTranslation")
  {
    mCsgNode = new CSGTranslation(spatialns);
    obj = mCsgNode;
  }
  else if (name == "csgRotation")
  {
    mCsgNode = new CSGRotation(spatialns);
    obj = mCsgNode;
  }
  else if (name == "csgScale")
  {
    mCsgNode = new CSGScale(spatialns);
    obj = mCsgNode;
  }
  else if (name == "csgHomogeneousTransformation")
  {
    mCsgNode = new CSGHomogeneousTransformation(spatialns);
    obj = mCsgNode;
  }
  else if (name == "csgPseudoPrimitive")
  {
    mCsgNode = new CSGPseudoPrimitive(spatialns);
    obj = mCsgNode;
  }
  else if (name == "csgSetOperator")
  {
    mCsgNode = new CSGSetOperator(spatialns);
    obj = mCsgNode;
  }

  delete spatialns;

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new CSGTransformation_t using the given SBML @p level, @ p version
 * and package version values.
 */
LIBSBML_EXTERN
CSGTransformation_t *
CSGTransformation_create(unsigned int level,
                         unsigned int version,
                         unsigned int pkgVersion)
{
  return new CSGTransformation(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this CSGTransformation_t object.
 */
LIBSBML_EXTERN
CSGTransformation_t*
CSGTransformation_clone(const CSGTransformation_t* csgt)
{
  if (csgt != NULL)
  {
    return static_cast<CSGTransformation_t*>(csgt->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this CSGTransformation_t object.
 */
LIBSBML_EXTERN
void
CSGTransformation_free(CSGTransformation_t* csgt)
{
  if (csgt != NULL)
  {
    delete csgt;
  }
}


/*
 * Returns the value of the "csgNode" element of this CSGTransformation_t.
 */
LIBSBML_EXTERN
const CSGNode_t*
CSGTransformation_getCsgNode(const CSGTransformation_t * csgt)
{
  if (csgt == NULL)
  {
    return NULL;
  }

  return (CSGNode_t*)(csgt->getCsgNode());
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this
 * CSGTransformation_t's "csgNode" element has been set.
 */
LIBSBML_EXTERN
int
CSGTransformation_isSetCsgNode(const CSGTransformation_t * csgt)
{
  return (csgt != NULL) ? static_cast<int>(csgt->isSetCsgNode()) : 0;
}


/*
 * Sets the value of the "csgNode" element of this CSGTransformation_t.
 */
LIBSBML_EXTERN
int
CSGTransformation_setCsgNode(CSGTransformation_t * csgt,
                             const CSGNode_t* csgNode)
{
  return (csgt != NULL) ? csgt->setCsgNode(csgNode) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new CSGPrimitive_t object, adds it to this CSGTransformation_t
 * object and returns the CSGPrimitive_t object created.
 */
LIBSBML_EXTERN
CSGPrimitive_t*
CSGTransformation_createCSGPrimitive(CSGTransformation_t* csgt)
{
  return (csgt != NULL) ? csgt->createCSGPrimitive() : NULL;
}


/*
 * Creates a new CSGTranslation_t object, adds it to this CSGTransformation_t
 * object and returns the CSGTranslation_t object created.
 */
LIBSBML_EXTERN
CSGTranslation_t*
CSGTransformation_createCSGTranslation(CSGTransformation_t* csgt)
{
  return (csgt != NULL) ? csgt->createCSGTranslation() : NULL;
}


/*
 * Creates a new CSGRotation_t object, adds it to this CSGTransformation_t
 * object and returns the CSGRotation_t object created.
 */
LIBSBML_EXTERN
CSGRotation_t*
CSGTransformation_createCSGRotation(CSGTransformation_t* csgt)
{
  return (csgt != NULL) ? csgt->createCSGRotation() : NULL;
}


/*
 * Creates a new CSGScale_t object, adds it to this CSGTransformation_t object
 * and returns the CSGScale_t object created.
 */
LIBSBML_EXTERN
CSGScale_t*
CSGTransformation_createCSGScale(CSGTransformation_t* csgt)
{
  return (csgt != NULL) ? csgt->createCSGScale() : NULL;
}


/*
 * Creates a new CSGHomogeneousTransformation_t object, adds it to this
 * CSGTransformation_t object and returns the CSGHomogeneousTransformation_t
 * object created.
 */
LIBSBML_EXTERN
CSGHomogeneousTransformation_t*
CSGTransformation_createCSGHomogeneousTransformation(CSGTransformation_t* csgt)
{
  return (csgt != NULL) ? csgt->createCSGHomogeneousTransformation() : NULL;
}


/*
 * Creates a new CSGPseudoPrimitive_t object, adds it to this
 * CSGTransformation_t object and returns the CSGPseudoPrimitive_t object
 * created.
 */
LIBSBML_EXTERN
CSGPseudoPrimitive_t*
CSGTransformation_createCSGPseudoPrimitive(CSGTransformation_t* csgt)
{
  return (csgt != NULL) ? csgt->createCSGPseudoPrimitive() : NULL;
}


/*
 * Creates a new CSGSetOperator_t object, adds it to this CSGTransformation_t
 * object and returns the CSGSetOperator_t object created.
 */
LIBSBML_EXTERN
CSGSetOperator_t*
CSGTransformation_createCSGSetOperator(CSGTransformation_t* csgt)
{
  return (csgt != NULL) ? csgt->createCSGSetOperator() : NULL;
}


/*
 * Unsets the value of the "csgNode" element of this CSGTransformation_t.
 */
LIBSBML_EXTERN
int
CSGTransformation_unsetCsgNode(CSGTransformation_t * csgt)
{
  return (csgt != NULL) ? csgt->unsetCsgNode() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if this CSGTransformation_t is of type
 * CSGTranslation_t
 */
LIBSBML_EXTERN
int
CSGTransformation_isCSGTranslation(const CSGTransformation_t * csgt)
{
  return (csgt != NULL) ? static_cast<int>(csgt->isCSGTranslation()) : 0;
}


/*
 * Predicate returning @c 1 if this CSGTransformation_t is of type
 * CSGRotation_t
 */
LIBSBML_EXTERN
int
CSGTransformation_isCSGRotation(const CSGTransformation_t * csgt)
{
  return (csgt != NULL) ? static_cast<int>(csgt->isCSGRotation()) : 0;
}


/*
 * Predicate returning @c 1 if this CSGTransformation_t is of type CSGScale_t
 */
LIBSBML_EXTERN
int
CSGTransformation_isCSGScale(const CSGTransformation_t * csgt)
{
  return (csgt != NULL) ? static_cast<int>(csgt->isCSGScale()) : 0;
}


/*
 * Predicate returning @c 1 if this CSGTransformation_t is of type
 * CSGHomogeneousTransformation_t
 */
LIBSBML_EXTERN
int
CSGTransformation_isCSGHomogeneousTransformation(const CSGTransformation_t *
  csgt)
{
  return (csgt != NULL) ?
    static_cast<int>(csgt->isCSGHomogeneousTransformation()) : 0;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * CSGTransformation_t object have been set.
 */
LIBSBML_EXTERN
int
CSGTransformation_hasRequiredAttributes(const CSGTransformation_t * csgt)
{
  return (csgt != NULL) ? static_cast<int>(csgt->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this
 * CSGTransformation_t object have been set.
 */
LIBSBML_EXTERN
int
CSGTransformation_hasRequiredElements(const CSGTransformation_t * csgt)
{
  return (csgt != NULL) ? static_cast<int>(csgt->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


