/**
 * @file FbcModelPlugin.cpp
 * @brief Implementation of the FbcModelPlugin class.
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
#include <sbml/packages/fbc/extension/FbcModelPlugin.h>
#include <sbml/packages/fbc/validator/FbcSBMLError.h>
#include <sbml/util/ElementFilter.h>
#include <sbml/Model.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new FbcModelPlugin using the given URI, prefix and package
 * namespace.
 */
FbcModelPlugin::FbcModelPlugin(const std::string& uri,
                               const std::string& prefix,
                               FbcPkgNamespaces* fbcns)
  : SBasePlugin(uri, prefix, fbcns)
  , mStrict (false)
  , mIsSetStrict (false)
  , mObjectives (fbcns)
  , mFluxBounds (fbcns)
  , mGeneProducts (fbcns)
{
  connectToChild();
}


/*
 * Copy constructor for FbcModelPlugin.
 */
FbcModelPlugin::FbcModelPlugin(const FbcModelPlugin& orig)
  : SBasePlugin( orig )
  , mStrict ( orig.mStrict )
  , mIsSetStrict ( orig.mIsSetStrict )
  , mObjectives ( orig.mObjectives )
  , mFluxBounds ( orig.mFluxBounds )
  , mGeneProducts ( orig.mGeneProducts )
{
  connectToChild();
}


/*
 * Assignment operator for FbcModelPlugin.
 */
FbcModelPlugin&
FbcModelPlugin::operator=(const FbcModelPlugin& rhs)
{
  if (&rhs != this)
  {
    SBasePlugin::operator=(rhs);
    mStrict = rhs.mStrict;
    mIsSetStrict = rhs.mIsSetStrict;
    mObjectives = rhs.mObjectives;
    mFluxBounds = rhs.mFluxBounds;
    mGeneProducts = rhs.mGeneProducts;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this FbcModelPlugin object.
 */
FbcModelPlugin*
FbcModelPlugin::clone() const
{
  return new FbcModelPlugin(*this);
}


/*
 * Destructor for FbcModelPlugin.
 */
FbcModelPlugin::~FbcModelPlugin()
{
}


/*
 * Returns the value of the "strict" attribute of this FbcModelPlugin.
 */
bool
FbcModelPlugin::getStrict() const
{
  return mStrict;
}


/*
 * Predicate returning @c true if this FbcModelPlugin's "strict" attribute is
 * set.
 */
bool
FbcModelPlugin::isSetStrict() const
{
  return mIsSetStrict;
}


/*
 * Sets the value of the "strict" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::setStrict(bool strict)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (coreLevel == 3 && coreVersion == 1 && pkgVersion == 2)
  {
    mStrict = strict;
    mIsSetStrict = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    mStrict = strict;
    mIsSetStrict = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Unsets the value of the "strict" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::unsetStrict()
{
  mStrict = false;
  mIsSetStrict = false;

  if (isSetStrict() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the ListOfObjectives from this FbcModelPlugin.
 */
const ListOfObjectives*
FbcModelPlugin::getListOfObjectives() const
{
  return &mObjectives;
}


/*
 * Returns the ListOfObjectives from this FbcModelPlugin.
 */
ListOfObjectives*
FbcModelPlugin::getListOfObjectives()
{
  return &mObjectives;
}


/*
 * Get an Objective from the FbcModelPlugin.
 */
Objective*
FbcModelPlugin::getObjective(unsigned int n)
{
  return static_cast< Objective*>(mObjectives.get(n));
}


/*
 * Get an Objective from the FbcModelPlugin.
 */
const Objective*
FbcModelPlugin::getObjective(unsigned int n) const
{
  return static_cast<const Objective*>(mObjectives.get(n));
}


/*
 * Get an Objective from the FbcModelPlugin based on its identifier.
 */
Objective*
FbcModelPlugin::getObjective(const std::string& sid)
{
  return static_cast< Objective*>(mObjectives.get(sid));
}


/*
 * Get an Objective from the FbcModelPlugin based on its identifier.
 */
const Objective*
FbcModelPlugin::getObjective(const std::string& sid) const
{
  return static_cast<const Objective*>(mObjectives.get(sid));
}


/*
 * Adds a copy of the given Objective to this FbcModelPlugin.
 */
int
FbcModelPlugin::addObjective(const Objective* o)
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
  else if (getPackageVersion() != o->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else if (o->isSetId() && (mObjectives.get(o->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mObjectives.append(o);
  }
}


/*
 * Get the number of Objective objects in this FbcModelPlugin.
 */
unsigned int
FbcModelPlugin::getNumObjectives() const
{
  return mObjectives.size();
}


/*
 * Creates a new Objective object, adds it to this FbcModelPlugin object and
 * returns the Objective object created.
 */
Objective*
FbcModelPlugin::createObjective()
{
  Objective* o = NULL;

  try
  {
    FBC_CREATE_NS(fbcns, getSBMLNamespaces());
    o = new Objective(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (o != NULL)
  {
    mObjectives.appendAndOwn(o);
  }

  return o;
}


/*
 * Removes the nth Objective from this FbcModelPlugin and returns a pointer to
 * it.
 */
Objective*
FbcModelPlugin::removeObjective(unsigned int n)
{
  return static_cast<Objective*>(mObjectives.remove(n));
}


/*
 * Removes the Objective from this FbcModelPlugin based on its identifier and
 * returns a pointer to it.
 */
Objective*
FbcModelPlugin::removeObjective(const std::string& sid)
{
  return static_cast<Objective*>(mObjectives.remove(sid));
}


/*
 * Returns the ListOfFluxBounds from this FbcModelPlugin.
 */
const ListOfFluxBounds*
FbcModelPlugin::getListOfFluxBounds() const
{
  return &mFluxBounds;
}


/*
 * Returns the ListOfFluxBounds from this FbcModelPlugin.
 */
ListOfFluxBounds*
FbcModelPlugin::getListOfFluxBounds()
{
  return &mFluxBounds;
}


/*
 * Get a FluxBound from the FbcModelPlugin.
 */
FluxBound*
FbcModelPlugin::getFluxBound(unsigned int n)
{
  return static_cast< FluxBound*>(mFluxBounds.get(n));
}


/*
 * Get a FluxBound from the FbcModelPlugin.
 */
const FluxBound*
FbcModelPlugin::getFluxBound(unsigned int n) const
{
  return static_cast<const FluxBound*>(mFluxBounds.get(n));
}


/*
 * Get a FluxBound from the FbcModelPlugin based on its identifier.
 */
FluxBound*
FbcModelPlugin::getFluxBound(const std::string& sid)
{
  return static_cast< FluxBound*>(mFluxBounds.get(sid));
}


/*
 * Get a FluxBound from the FbcModelPlugin based on its identifier.
 */
const FluxBound*
FbcModelPlugin::getFluxBound(const std::string& sid) const
{
  return static_cast<const FluxBound*>(mFluxBounds.get(sid));
}


/*
 * Get a FluxBound from the FbcModelPlugin based on the Reaction to which it
 * refers.
 */
const FluxBound*
FbcModelPlugin::getFluxBoundByReaction(const std::string& sid) const
{
  return mFluxBounds.getByReaction(sid);
}


/*
 * Get a FluxBound from the FbcModelPlugin based on the Reaction to which it
 * refers.
 */
FluxBound*
FbcModelPlugin::getFluxBoundByReaction(const std::string& sid)
{
  return mFluxBounds.getByReaction(sid);
}


/*
 * Adds a copy of the given FluxBound to this FbcModelPlugin.
 */
int
FbcModelPlugin::addFluxBound(const FluxBound* fb)
{
  if (fb == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (fb->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != fb->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != fb->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != fb->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else if (fb->isSetId() && (mFluxBounds.get(fb->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mFluxBounds.append(fb);
  }
}


/*
 * Get the number of FluxBound objects in this FbcModelPlugin.
 */
unsigned int
FbcModelPlugin::getNumFluxBounds() const
{
  return mFluxBounds.size();
}


/*
 * Creates a new FluxBound object, adds it to this FbcModelPlugin object and
 * returns the FluxBound object created.
 */
FluxBound*
FbcModelPlugin::createFluxBound()
{
  FluxBound* fb = NULL;

  try
  {
    FBC_CREATE_NS(fbcns, getSBMLNamespaces());
    fb = new FluxBound(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (fb != NULL)
  {
    mFluxBounds.appendAndOwn(fb);
  }

  return fb;
}


/*
 * Removes the nth FluxBound from this FbcModelPlugin and returns a pointer to
 * it.
 */
FluxBound*
FbcModelPlugin::removeFluxBound(unsigned int n)
{
  return static_cast<FluxBound*>(mFluxBounds.remove(n));
}


/*
 * Removes the FluxBound from this FbcModelPlugin based on its identifier and
 * returns a pointer to it.
 */
FluxBound*
FbcModelPlugin::removeFluxBound(const std::string& sid)
{
  return static_cast<FluxBound*>(mFluxBounds.remove(sid));
}


/*
 * Returns the ListOfGeneProducts from this FbcModelPlugin.
 */
const ListOfGeneProducts*
FbcModelPlugin::getListOfGeneProducts() const
{
  return &mGeneProducts;
}


/*
 * Returns the ListOfGeneProducts from this FbcModelPlugin.
 */
ListOfGeneProducts*
FbcModelPlugin::getListOfGeneProducts()
{
  return &mGeneProducts;
}


/*
 * Get a GeneProduct from the FbcModelPlugin.
 */
GeneProduct*
FbcModelPlugin::getGeneProduct(unsigned int n)
{
  return static_cast< GeneProduct*>(mGeneProducts.get(n));
}


/*
 * Get a GeneProduct from the FbcModelPlugin.
 */
const GeneProduct*
FbcModelPlugin::getGeneProduct(unsigned int n) const
{
  return static_cast<const GeneProduct*>(mGeneProducts.get(n));
}


/*
 * Get a GeneProduct from the FbcModelPlugin based on its identifier.
 */
GeneProduct*
FbcModelPlugin::getGeneProduct(const std::string& sid)
{
  return static_cast< GeneProduct*>(mGeneProducts.get(sid));
}


/*
 * Get a GeneProduct from the FbcModelPlugin based on its identifier.
 */
const GeneProduct*
FbcModelPlugin::getGeneProduct(const std::string& sid) const
{
  return static_cast<const GeneProduct*>(mGeneProducts.get(sid));
}


/*
 * Get a GeneProduct from the FbcModelPlugin based on the AssociatedSpecies to
 * which it refers.
 */
const GeneProduct*
FbcModelPlugin::getGeneProductByAssociatedSpecies(const std::string& sid) const
{
  return mGeneProducts.getByAssociatedSpecies(sid);
}


/*
 * Get a GeneProduct from the FbcModelPlugin based on the AssociatedSpecies to
 * which it refers.
 */
GeneProduct*
FbcModelPlugin::getGeneProductByAssociatedSpecies(const std::string& sid)
{
  return mGeneProducts.getByAssociatedSpecies(sid);
}


/*
 * Adds a copy of the given GeneProduct to this FbcModelPlugin.
 */
int
FbcModelPlugin::addGeneProduct(const GeneProduct* gp)
{
  if (gp == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (gp->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != gp->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != gp->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != gp->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else if (gp->isSetId() && (mGeneProducts.get(gp->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mGeneProducts.append(gp);
  }
}


/*
 * Get the number of GeneProduct objects in this FbcModelPlugin.
 */
unsigned int
FbcModelPlugin::getNumGeneProducts() const
{
  return mGeneProducts.size();
}


/*
 * Creates a new GeneProduct object, adds it to this FbcModelPlugin object and
 * returns the GeneProduct object created.
 */
GeneProduct*
FbcModelPlugin::createGeneProduct()
{
  GeneProduct* gp = NULL;

  try
  {
    FBC_CREATE_NS(fbcns, getSBMLNamespaces());
    gp = new GeneProduct(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (gp != NULL)
  {
    mGeneProducts.appendAndOwn(gp);
  }

  return gp;
}


/*
 * Removes the nth GeneProduct from this FbcModelPlugin and returns a pointer
 * to it.
 */
GeneProduct*
FbcModelPlugin::removeGeneProduct(unsigned int n)
{
  return static_cast<GeneProduct*>(mGeneProducts.remove(n));
}


/*
 * Removes the GeneProduct from this FbcModelPlugin based on its identifier and
 * returns a pointer to it.
 */
GeneProduct*
FbcModelPlugin::removeGeneProduct(const std::string& sid)
{
  return static_cast<GeneProduct*>(mGeneProducts.remove(sid));
}


/*
 * Predicate returning @c true if all the required attributes for this
 * FbcModelPlugin object have been set.
 */
bool
FbcModelPlugin::hasRequiredAttributes() const
{
  bool allPresent = true;

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    if (isSetStrict() == false)
    {
      allPresent = false;
    }
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
FbcModelPlugin::writeElements(XMLOutputStream& stream) const
{
  if (getNumObjectives() > 0)
  {
    mObjectives.write(stream);
  }

  if (getNumFluxBounds() > 0)
  {
    mFluxBounds.write(stream);
  }

  if (getNumGeneProducts() > 0)
  {
    mGeneProducts.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
FbcModelPlugin::accept(SBMLVisitor& v) const
{
  const Model* m = static_cast<const Model*>(this->getParentSBMLObject());
  v.visit(*m);
  v.leave(*m);

  mObjectives.accept(v);

  mFluxBounds.accept(v);

  mGeneProducts.accept(v);

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
FbcModelPlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);

  mObjectives.setSBMLDocument(d);

  mFluxBounds.setSBMLDocument(d);

  mGeneProducts.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
FbcModelPlugin::connectToChild()
{
  connectToParent(getParentSBMLObject());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to parent element
 */
void
FbcModelPlugin::connectToParent(SBase* base)
{
  SBasePlugin::connectToParent(base);

  mObjectives.connectToParent(base);

  mFluxBounds.connectToParent(base);

  mGeneProducts.connectToParent(base);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
FbcModelPlugin::enablePackageInternal(const std::string& pkgURI,
                                      const std::string& pkgPrefix,
                                      bool flag)
{
  mObjectives.enablePackageInternal(pkgURI, pkgPrefix, flag);

  mFluxBounds.enablePackageInternal(pkgURI, pkgPrefix, flag);

  mGeneProducts.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
FbcModelPlugin::updateSBMLNamespace(const std::string& package,
                                    unsigned int level,
                                    unsigned int version)
{
  SBasePlugin::updateSBMLNamespace(package, level, version);

  mObjectives.updateSBMLNamespace(package, level, version);

  mFluxBounds.updateSBMLNamespace(package, level, version);

  mGeneProducts.updateSBMLNamespace(package, level, version);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::getAttribute(const std::string& attributeName,
                             bool& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "strict")
  {
    value = getStrict();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::getAttribute(const std::string& attributeName,
                             int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::getAttribute(const std::string& attributeName,
                             double& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::getAttribute(const std::string& attributeName,
                             unsigned int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::getAttribute(const std::string& attributeName,
                             std::string& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this FbcModelPlugin's attribute
 * "attributeName" is set.
 */
bool
FbcModelPlugin::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBasePlugin::isSetAttribute(attributeName);

  if (attributeName == "strict")
  {
    value = isSetStrict();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  if (attributeName == "strict")
  {
    return_value = setStrict(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::setAttribute(const std::string& attributeName,
                             unsigned int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::setAttribute(const std::string& attributeName,
                             const std::string& value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this FbcModelPlugin.
 */
int
FbcModelPlugin::unsetAttribute(const std::string& attributeName)
{
  int value = SBasePlugin::unsetAttribute(attributeName);

  if (attributeName == "strict")
  {
    value = unsetStrict();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this FbcModelPlugin.
 */
SBase*
FbcModelPlugin::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "objective")
  {
    return createObjective();
  }
  else if (elementName == "fluxBound")
  {
    return createFluxBound();
  }
  else if (elementName == "geneProduct")
  {
    return createGeneProduct();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this FbcModelPlugin.
 */
int
FbcModelPlugin::addChildObject(const std::string& elementName,
                               const SBase* element)
{
  if (elementName == "objective" && element->getTypeCode() ==
    SBML_FBC_OBJECTIVE)
  {
    return addObjective((const Objective*)(element));
  }
  else if (elementName == "fluxBound" && element->getTypeCode() ==
    SBML_FBC_FLUXBOUND)
  {
    return addFluxBound((const FluxBound*)(element));
  }
  else if (elementName == "geneProduct" && element->getTypeCode() ==
    SBML_FBC_GENEPRODUCT)
  {
    return addGeneProduct((const GeneProduct*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * FbcModelPlugin.
 */
SBase*
FbcModelPlugin::removeChildObject(const std::string& elementName,
                                  const std::string& id)
{
  if (elementName == "objective")
  {
    return removeObjective(id);
  }
  else if (elementName == "fluxBound")
  {
    return removeFluxBound(id);
  }
  else if (elementName == "geneProduct")
  {
    return removeGeneProduct(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this FbcModelPlugin.
 */
unsigned int
FbcModelPlugin::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "objective")
  {
    return getNumObjectives();
  }
  else if (elementName == "fluxBound")
  {
    return getNumFluxBounds();
  }
  else if (elementName == "geneProduct")
  {
    return getNumGeneProducts();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this FbcModelPlugin.
 */
SBase*
FbcModelPlugin::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "objective")
  {
    return getObjective(index);
  }
  else if (elementName == "fluxBound")
  {
    return getFluxBound(index);
  }
  else if (elementName == "geneProduct")
  {
    return getGeneProduct(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
FbcModelPlugin::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mObjectives.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mFluxBounds.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mGeneProducts.getElementBySId(id);

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
FbcModelPlugin::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mObjectives.getMetaId() == metaid)
  {
    return &mObjectives;
  }

  if (mFluxBounds.getMetaId() == metaid)
  {
    return &mFluxBounds;
  }

  if (mGeneProducts.getMetaId() == metaid)
  {
    return &mGeneProducts;
  }

  obj = mObjectives.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mFluxBounds.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mGeneProducts.getElementByMetaId(metaid);

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
FbcModelPlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mObjectives, filter);
  ADD_FILTERED_LIST(ret, sublist, mFluxBounds, filter);
  ADD_FILTERED_LIST(ret, sublist, mGeneProducts, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Append items from model (used in comp flattening)
 */
int
FbcModelPlugin::appendFrom(const Model* model)
{
  int ret = LIBSBML_OPERATION_SUCCESS;

  if (model == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  const FbcModelPlugin* plug = static_cast<const
    FbcModelPlugin*>(model->getPlugin(getPrefix()));

  if (plug == NULL)
  {
    return ret;
  }

  Model* parent = static_cast<Model*>(getParentSBMLObject());

  if (parent == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  ret = mObjectives.appendFrom(plug->getListOfObjectives());

  if (ret != LIBSBML_OPERATION_SUCCESS)
  {
    return ret;
  }

  ret = mFluxBounds.appendFrom(plug->getListOfFluxBounds());

  if (ret != LIBSBML_OPERATION_SUCCESS)
  {
    return ret;
  }

  ret = mGeneProducts.appendFrom(plug->getListOfGeneProducts());

  if (ret != LIBSBML_OPERATION_SUCCESS)
  {
    return ret;
  }

  return ret;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
FbcModelPlugin::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();
  const XMLNamespaces& xmlns = stream.peek().getNamespaces();
  const std::string& prefix = stream.peek().getPrefix();

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ?
    xmlns.getPrefix(mURI) : mPrefix;

  if (prefix == targetPrefix)
  {
    if (name == "listOfObjectives")
    {
      if (getErrorLog() && mObjectives.size() != 0)
      {
        getErrorLog()->logPackageError("fbc", FbcModelAllowedElements,
          getPackageVersion(), getLevel(), getVersion(), "", getLine(),
            getColumn());
      }

      obj = &mObjectives;
      if (targetPrefix.empty())
      {
        mObjectives.getSBMLDocument()->enableDefaultNS(mURI, true);
      }
    }
    else if (name == "listOfFluxBounds")
    {
      if (getErrorLog() && mFluxBounds.size() != 0)
      {
        getErrorLog()->logPackageError("fbc", FbcModelAllowedElements,
          getPackageVersion(), getLevel(), getVersion(), "", getLine(),
            getColumn());
      }

      obj = &mFluxBounds;
      if (targetPrefix.empty())
      {
        mFluxBounds.getSBMLDocument()->enableDefaultNS(mURI, true);
      }
    }
    else if (name == "listOfGeneProducts")
    {
      if (getErrorLog() && mGeneProducts.size() != 0)
      {
        getErrorLog()->logPackageError("fbc", FbcModelAllowedElements,
          getPackageVersion(), getLevel(), getVersion(), "", getLine(),
            getColumn());
      }

      obj = &mGeneProducts;
      if (targetPrefix.empty())
      {
        mGeneProducts.getSBMLDocument()->enableDefaultNS(mURI, true);
      }
    }
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
FbcModelPlugin::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBasePlugin::addExpectedAttributes(attributes);

  unsigned int level = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && coreVersion == 1 && pkgVersion == 2)
  {
    attributes.add("strict");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
FbcModelPlugin::readAttributes(const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBasePlugin::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("fbc", FbcModelAllowedAttributes, pkgVersion,
          level, version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("fbc", FbcModelAllowedAttributes, pkgVersion,
          level, version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == NotSchemaConformant)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(NotSchemaConformant);
        log->logPackageError("fbc", FbcModelAllowedAttributes, pkgVersion,
          level, version, details, getLine(), getColumn());
      }
    }
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
FbcModelPlugin::readL3V1V2Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // strict bool (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetStrict = attributes.readInto("strict", mStrict);

  if (mIsSetStrict == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("fbc", FbcModelStrictMustBeBoolean, pkgVersion,
        level, version);
    }
    else
    {
      std::string message = "Fbc attribute 'strict' is missing from the "
        "<FbcModelPlugin> element.";
      log->logPackageError("fbc", FbcModelAllowedAttributes, pkgVersion, level,
        version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
FbcModelPlugin::writeAttributes(XMLOutputStream& stream) const
{
  SBasePlugin::writeAttributes(stream);

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    writeL3V1V2Attributes(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
FbcModelPlugin::writeL3V1V2Attributes(XMLOutputStream& stream) const
{
  if (isSetStrict() == true)
  {
    stream.writeAttribute("strict", getPrefix(), mStrict);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Returns a ListOf_t * containing Objective_t objects from this
 * FbcModelPlugin_t.
 */
LIBSBML_EXTERN
ListOf_t*
FbcModelPlugin_getListOfObjectives(FbcModelPlugin_t* fmp)
{
  return (fmp != NULL) ? fmp->getListOfObjectives() : NULL;
}


/*
 * Get an Objective_t from the FbcModelPlugin_t.
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_getObjective(FbcModelPlugin_t* fmp, unsigned int n)
{
  return (fmp != NULL) ? fmp->getObjective(n) : NULL;
}


/*
 * Get an Objective_t from the FbcModelPlugin_t based on its identifier.
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_getObjectiveById(FbcModelPlugin_t* fmp, const char *sid)
{
  return (fmp != NULL && sid != NULL) ? fmp->getObjective(sid) : NULL;
}


/*
 * Adds a copy of the given Objective_t to this FbcModelPlugin_t.
 */
LIBSBML_EXTERN
int
FbcModelPlugin_addObjective(FbcModelPlugin_t* fmp, const Objective_t* o)
{
  return (fmp != NULL) ? fmp->addObjective(o) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Objective_t objects in this FbcModelPlugin_t.
 */
LIBSBML_EXTERN
unsigned int
FbcModelPlugin_getNumObjectives(FbcModelPlugin_t* fmp)
{
  return (fmp != NULL) ? fmp->getNumObjectives() : SBML_INT_MAX;
}


/*
 * Creates a new Objective_t object, adds it to this FbcModelPlugin_t object
 * and returns the Objective_t object created.
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_createObjective(FbcModelPlugin_t* fmp)
{
  return (fmp != NULL) ? fmp->createObjective() : NULL;
}


/*
 * Removes the nth Objective_t from this FbcModelPlugin_t and returns a pointer
 * to it.
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_removeObjective(FbcModelPlugin_t* fmp, unsigned int n)
{
  return (fmp != NULL) ? fmp->removeObjective(n) : NULL;
}


/*
 * Removes the Objective_t from this FbcModelPlugin_t based on its identifier
 * and returns a pointer to it.
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_removeObjectiveById(FbcModelPlugin_t* fmp, const char* sid)
{
  return (fmp != NULL && sid != NULL) ? fmp->removeObjective(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing FluxBound_t objects from this
 * FbcModelPlugin_t.
 */
LIBSBML_EXTERN
ListOf_t*
FbcModelPlugin_getListOfFluxBounds(FbcModelPlugin_t* fmp)
{
  return (fmp != NULL) ? fmp->getListOfFluxBounds() : NULL;
}


/*
 * Get a FluxBound_t from the FbcModelPlugin_t.
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_getFluxBound(FbcModelPlugin_t* fmp, unsigned int n)
{
  return (fmp != NULL) ? fmp->getFluxBound(n) : NULL;
}


/*
 * Get a FluxBound_t from the FbcModelPlugin_t based on its identifier.
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_getFluxBoundById(FbcModelPlugin_t* fmp, const char *sid)
{
  return (fmp != NULL && sid != NULL) ? fmp->getFluxBound(sid) : NULL;
}


/*
 * Get a FluxBound_t from the FbcModelPlugin_t based on the Reaction to which
 * it refers.
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_getFluxBoundByReaction(FbcModelPlugin_t* fmp, const char *sid)
{
  return (fmp != NULL && sid != NULL) ? fmp->getFluxBoundByReaction(sid) :
    NULL;
}


/*
 * Adds a copy of the given FluxBound_t to this FbcModelPlugin_t.
 */
LIBSBML_EXTERN
int
FbcModelPlugin_addFluxBound(FbcModelPlugin_t* fmp, const FluxBound_t* fb)
{
  return (fmp != NULL) ? fmp->addFluxBound(fb) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of FluxBound_t objects in this FbcModelPlugin_t.
 */
LIBSBML_EXTERN
unsigned int
FbcModelPlugin_getNumFluxBounds(FbcModelPlugin_t* fmp)
{
  return (fmp != NULL) ? fmp->getNumFluxBounds() : SBML_INT_MAX;
}


/*
 * Creates a new FluxBound_t object, adds it to this FbcModelPlugin_t object
 * and returns the FluxBound_t object created.
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_createFluxBound(FbcModelPlugin_t* fmp)
{
  return (fmp != NULL) ? fmp->createFluxBound() : NULL;
}


/*
 * Removes the nth FluxBound_t from this FbcModelPlugin_t and returns a pointer
 * to it.
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_removeFluxBound(FbcModelPlugin_t* fmp, unsigned int n)
{
  return (fmp != NULL) ? fmp->removeFluxBound(n) : NULL;
}


/*
 * Removes the FluxBound_t from this FbcModelPlugin_t based on its identifier
 * and returns a pointer to it.
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_removeFluxBoundById(FbcModelPlugin_t* fmp, const char* sid)
{
  return (fmp != NULL && sid != NULL) ? fmp->removeFluxBound(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing GeneProduct_t objects from this
 * FbcModelPlugin_t.
 */
LIBSBML_EXTERN
ListOf_t*
FbcModelPlugin_getListOfGeneProducts(FbcModelPlugin_t* fmp)
{
  return (fmp != NULL) ? fmp->getListOfGeneProducts() : NULL;
}


/*
 * Get a GeneProduct_t from the FbcModelPlugin_t.
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_getGeneProduct(FbcModelPlugin_t* fmp, unsigned int n)
{
  return (fmp != NULL) ? fmp->getGeneProduct(n) : NULL;
}


/*
 * Get a GeneProduct_t from the FbcModelPlugin_t based on its identifier.
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_getGeneProductById(FbcModelPlugin_t* fmp, const char *sid)
{
  return (fmp != NULL && sid != NULL) ? fmp->getGeneProduct(sid) : NULL;
}


/*
 * Get a GeneProduct_t from the FbcModelPlugin_t based on the AssociatedSpecies
 * to which it refers.
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_getGeneProductByAssociatedSpecies(FbcModelPlugin_t* fmp,
                                                 const char *sid)
{
  return (fmp != NULL && sid != NULL) ?
    fmp->getGeneProductByAssociatedSpecies(sid) : NULL;
}


/*
 * Adds a copy of the given GeneProduct_t to this FbcModelPlugin_t.
 */
LIBSBML_EXTERN
int
FbcModelPlugin_addGeneProduct(FbcModelPlugin_t* fmp, const GeneProduct_t* gp)
{
  return (fmp != NULL) ? fmp->addGeneProduct(gp) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of GeneProduct_t objects in this FbcModelPlugin_t.
 */
LIBSBML_EXTERN
unsigned int
FbcModelPlugin_getNumGeneProducts(FbcModelPlugin_t* fmp)
{
  return (fmp != NULL) ? fmp->getNumGeneProducts() : SBML_INT_MAX;
}


/*
 * Creates a new GeneProduct_t object, adds it to this FbcModelPlugin_t object
 * and returns the GeneProduct_t object created.
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_createGeneProduct(FbcModelPlugin_t* fmp)
{
  return (fmp != NULL) ? fmp->createGeneProduct() : NULL;
}


/*
 * Removes the nth GeneProduct_t from this FbcModelPlugin_t and returns a
 * pointer to it.
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_removeGeneProduct(FbcModelPlugin_t* fmp, unsigned int n)
{
  return (fmp != NULL) ? fmp->removeGeneProduct(n) : NULL;
}


/*
 * Removes the GeneProduct_t from this FbcModelPlugin_t based on its identifier
 * and returns a pointer to it.
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_removeGeneProductById(FbcModelPlugin_t* fmp, const char* sid)
{
  return (fmp != NULL && sid != NULL) ? fmp->removeGeneProduct(sid) : NULL;
}


/*
 * Returns the value of the "strict" attribute of this FbcModelPlugin_t.
 */
LIBSBML_EXTERN
int
FbcModelPlugin_getStrict(const FbcModelPlugin_t * fmp)
{
  return (fmp != NULL) ? static_cast<int>(fmp->getStrict()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this FbcModelPlugin_t's "strict"
 * attribute is set.
 */
LIBSBML_EXTERN
int
FbcModelPlugin_isSetStrict(const FbcModelPlugin_t * fmp)
{
  return (fmp != NULL) ? static_cast<int>(fmp->isSetStrict()) : 0;
}


/*
 * Sets the value of the "strict" attribute of this FbcModelPlugin_t.
 */
LIBSBML_EXTERN
int
FbcModelPlugin_setStrict(FbcModelPlugin_t * fmp, int strict)
{
  return (fmp != NULL) ? fmp->setStrict(strict) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "strict" attribute of this FbcModelPlugin_t.
 */
LIBSBML_EXTERN
int
FbcModelPlugin_unsetStrict(FbcModelPlugin_t * fmp)
{
  return (fmp != NULL) ? fmp->unsetStrict() : LIBSBML_INVALID_OBJECT;
}




LIBSBML_CPP_NAMESPACE_END


