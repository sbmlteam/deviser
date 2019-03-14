/**
 * @file DiscreteUnivariateDistribution.cpp
 * @brief Implementation of the DiscreteUnivariateDistribution class.
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
#include <sbml/packages/distrib/sbml/DiscreteUnivariateDistribution.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>
#include <sbml/util/ElementFilter.h>

#include <sbml/packages/distrib/sbml/BinomialDistribution.h>
#include <sbml/packages/distrib/sbml/GeometricDistribution.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new DiscreteUnivariateDistribution using the given SBML Level,
 * Version and &ldquo;distrib&rdquo; package version.
 */
DiscreteUnivariateDistribution::DiscreteUnivariateDistribution(
                                                               unsigned int
                                                                 level,
                                                               unsigned int
                                                                 version,
                                                               unsigned int
                                                                 pkgVersion)
  : UnivariateDistribution(level, version, pkgVersion)
  , mTruncationLowerBound (NULL)
  , mTruncationUpperBound (NULL)
  , mElementName("discreteUnivariateDistribution")
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new DiscreteUnivariateDistribution using the given
 * DistribPkgNamespaces object.
 */
DiscreteUnivariateDistribution::DiscreteUnivariateDistribution(DistribPkgNamespaces
  *distribns)
  : UnivariateDistribution(distribns)
  , mTruncationLowerBound (NULL)
  , mTruncationUpperBound (NULL)
  , mElementName("discreteUnivariateDistribution")
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for DiscreteUnivariateDistribution.
 */
DiscreteUnivariateDistribution::DiscreteUnivariateDistribution(const
  DiscreteUnivariateDistribution& orig)
  : UnivariateDistribution( orig )
  , mTruncationLowerBound ( NULL )
  , mTruncationUpperBound ( NULL )
  , mElementName ( orig.mElementName )
{
  if (orig.mTruncationLowerBound != NULL)
  {
    mTruncationLowerBound = orig.mTruncationLowerBound->clone();
  }

  if (orig.mTruncationUpperBound != NULL)
  {
    mTruncationUpperBound = orig.mTruncationUpperBound->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for DiscreteUnivariateDistribution.
 */
DiscreteUnivariateDistribution&
DiscreteUnivariateDistribution::operator=(const DiscreteUnivariateDistribution&
  rhs)
{
  if (&rhs != this)
  {
    UnivariateDistribution::operator=(rhs);
    mElementName = rhs.mElementName;
    delete mTruncationLowerBound;
    if (rhs.mTruncationLowerBound != NULL)
    {
      mTruncationLowerBound = rhs.mTruncationLowerBound->clone();
    }
    else
    {
      mTruncationLowerBound = NULL;
    }

    delete mTruncationUpperBound;
    if (rhs.mTruncationUpperBound != NULL)
    {
      mTruncationUpperBound = rhs.mTruncationUpperBound->clone();
    }
    else
    {
      mTruncationUpperBound = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this DiscreteUnivariateDistribution
 * object.
 */
DiscreteUnivariateDistribution*
DiscreteUnivariateDistribution::clone() const
{
  return new DiscreteUnivariateDistribution(*this);
}


/*
 * Destructor for DiscreteUnivariateDistribution.
 */
DiscreteUnivariateDistribution::~DiscreteUnivariateDistribution()
{
  delete mTruncationLowerBound;
  mTruncationLowerBound = NULL;
  delete mTruncationUpperBound;
  mTruncationUpperBound = NULL;
}


/*
 * Returns the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution.
 */
const UncertBound*
DiscreteUnivariateDistribution::getTruncationLowerBound() const
{
  return mTruncationLowerBound;
}


/*
 * Returns the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution.
 */
UncertBound*
DiscreteUnivariateDistribution::getTruncationLowerBound()
{
  return mTruncationLowerBound;
}


/*
 * Returns the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution.
 */
const UncertBound*
DiscreteUnivariateDistribution::getTruncationUpperBound() const
{
  return mTruncationUpperBound;
}


/*
 * Returns the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution.
 */
UncertBound*
DiscreteUnivariateDistribution::getTruncationUpperBound()
{
  return mTruncationUpperBound;
}


/*
 * Predicate returning @c true if this DiscreteUnivariateDistribution's
 * "truncationLowerBound" element is set.
 */
bool
DiscreteUnivariateDistribution::isSetTruncationLowerBound() const
{
  return (mTruncationLowerBound != NULL);
}


/*
 * Predicate returning @c true if this DiscreteUnivariateDistribution's
 * "truncationUpperBound" element is set.
 */
bool
DiscreteUnivariateDistribution::isSetTruncationUpperBound() const
{
  return (mTruncationUpperBound != NULL);
}


/*
 * Sets the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::setTruncationLowerBound(const UncertBound*
  truncationLowerBound)
{
  if (mTruncationLowerBound == truncationLowerBound)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (truncationLowerBound == NULL)
  {
    delete mTruncationLowerBound;
    mTruncationLowerBound = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mTruncationLowerBound;
    mTruncationLowerBound = (truncationLowerBound != NULL) ?
      truncationLowerBound->clone() : NULL;
    if (mTruncationLowerBound != NULL)
    {
      mTruncationLowerBound->setElementName("truncationLowerBound");
      mTruncationLowerBound->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::setTruncationUpperBound(const UncertBound*
  truncationUpperBound)
{
  if (mTruncationUpperBound == truncationUpperBound)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (truncationUpperBound == NULL)
  {
    delete mTruncationUpperBound;
    mTruncationUpperBound = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mTruncationUpperBound;
    mTruncationUpperBound = (truncationUpperBound != NULL) ?
      truncationUpperBound->clone() : NULL;
    if (mTruncationUpperBound != NULL)
    {
      mTruncationUpperBound->setElementName("truncationUpperBound");
      mTruncationUpperBound->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new UncertBound object, adds it to this
 * DiscreteUnivariateDistribution object and returns the UncertBound object
 * created.
 */
UncertBound*
DiscreteUnivariateDistribution::createTruncationLowerBound()
{
  if (mTruncationLowerBound != NULL)
  {
    delete mTruncationLowerBound;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mTruncationLowerBound = new UncertBound(distribns);

  mTruncationLowerBound->setElementName("truncationLowerBound");

  delete distribns;

  connectToChild();

  return mTruncationLowerBound;
}


/*
 * Creates a new UncertBound object, adds it to this
 * DiscreteUnivariateDistribution object and returns the UncertBound object
 * created.
 */
UncertBound*
DiscreteUnivariateDistribution::createTruncationUpperBound()
{
  if (mTruncationUpperBound != NULL)
  {
    delete mTruncationUpperBound;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mTruncationUpperBound = new UncertBound(distribns);

  mTruncationUpperBound->setElementName("truncationUpperBound");

  delete distribns;

  connectToChild();

  return mTruncationUpperBound;
}


/*
 * Unsets the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::unsetTruncationLowerBound()
{
  delete mTruncationLowerBound;
  mTruncationLowerBound = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::unsetTruncationUpperBound()
{
  delete mTruncationUpperBound;
  mTruncationUpperBound = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Predicate returning @c true if this abstract
 * "DiscreteUnivariateDistribution" is of type BinomialDistribution
 */
bool
DiscreteUnivariateDistribution::isBinomialDistribution() const
{
  return dynamic_cast<const BinomialDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract
 * "DiscreteUnivariateDistribution" is of type GeometricDistribution
 */
bool
DiscreteUnivariateDistribution::isGeometricDistribution() const
{
  return dynamic_cast<const GeometricDistribution*>(this) != NULL;
}


/*
 * Returns the XML element name of this DiscreteUnivariateDistribution object.
 */
const std::string&
DiscreteUnivariateDistribution::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the XML name of this DiscreteUnivariateDistribution object.
 */
void
DiscreteUnivariateDistribution::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBML type code for this DiscreteUnivariateDistribution
 * object.
 */
int
DiscreteUnivariateDistribution::getTypeCode() const
{
  return SBML_DISTRIB_DISCRETEUNIVARIATEDISTRIBUTION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * DiscreteUnivariateDistribution object have been set.
 */
bool
DiscreteUnivariateDistribution::hasRequiredAttributes() const
{
  bool allPresent = UnivariateDistribution::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * DiscreteUnivariateDistribution object have been set.
 */
bool
DiscreteUnivariateDistribution::hasRequiredElements() const
{
  bool allPresent = UnivariateDistribution::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
DiscreteUnivariateDistribution::writeElements(XMLOutputStream& stream) const
{
  UnivariateDistribution::writeElements(stream);

  if (isSetTruncationLowerBound() == true)
  {
    mTruncationLowerBound->write(stream);
  }

  if (isSetTruncationUpperBound() == true)
  {
    mTruncationUpperBound->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
DiscreteUnivariateDistribution::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mTruncationLowerBound != NULL)
  {
    mTruncationLowerBound->accept(v);
  }

  if (mTruncationUpperBound != NULL)
  {
    mTruncationUpperBound->accept(v);
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
DiscreteUnivariateDistribution::setSBMLDocument(SBMLDocument* d)
{
  UnivariateDistribution::setSBMLDocument(d);

  if (mTruncationLowerBound != NULL)
  {
    mTruncationLowerBound->setSBMLDocument(d);
  }

  if (mTruncationUpperBound != NULL)
  {
    mTruncationUpperBound->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
DiscreteUnivariateDistribution::connectToChild()
{
  UnivariateDistribution::connectToChild();

  if (mTruncationLowerBound != NULL)
  {
    mTruncationLowerBound->connectToParent(this);
  }

  if (mTruncationUpperBound != NULL)
  {
    mTruncationUpperBound->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
DiscreteUnivariateDistribution::enablePackageInternal(
                                                      const std::string&
                                                        pkgURI,
                                                      const std::string&
                                                        pkgPrefix,
                                                      bool flag)
{
  UnivariateDistribution::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetTruncationLowerBound())
  {
    mTruncationLowerBound->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetTruncationUpperBound())
  {
    mTruncationUpperBound->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
DiscreteUnivariateDistribution::updateSBMLNamespace(const std::string& package,
                                                    unsigned int level,
                                                    unsigned int version)
{
  UnivariateDistribution::updateSBMLNamespace(package, level, version);

  if (mTruncationLowerBound != NULL)
  {
    mTruncationLowerBound->updateSBMLNamespace(package, level, version);
  }

  if (mTruncationUpperBound != NULL)
  {
    mTruncationUpperBound->updateSBMLNamespace(package, level, version);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::getAttribute(const std::string& attributeName,
                                             bool& value) const
{
  int return_value = UnivariateDistribution::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::getAttribute(const std::string& attributeName,
                                             int& value) const
{
  int return_value = UnivariateDistribution::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::getAttribute(const std::string& attributeName,
                                             double& value) const
{
  int return_value = UnivariateDistribution::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::getAttribute(const std::string& attributeName,
                                             unsigned int& value) const
{
  int return_value = UnivariateDistribution::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::getAttribute(const std::string& attributeName,
                                             std::string& value) const
{
  int return_value = UnivariateDistribution::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this DiscreteUnivariateDistribution's
 * attribute "attributeName" is set.
 */
bool
DiscreteUnivariateDistribution::isSetAttribute(const std::string&
  attributeName) const
{
  bool value = UnivariateDistribution::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::setAttribute(const std::string& attributeName,
                                             bool value)
{
  int return_value = UnivariateDistribution::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::setAttribute(const std::string& attributeName,
                                             int value)
{
  int return_value = UnivariateDistribution::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::setAttribute(const std::string& attributeName,
                                             double value)
{
  int return_value = UnivariateDistribution::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::setAttribute(const std::string& attributeName,
                                             unsigned int value)
{
  int return_value = UnivariateDistribution::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::setAttribute(const std::string& attributeName,
                                             const std::string& value)
{
  int return_value = UnivariateDistribution::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::unsetAttribute(const std::string&
  attributeName)
{
  int value = UnivariateDistribution::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this
 * DiscreteUnivariateDistribution.
 */
SBase*
DiscreteUnivariateDistribution::createChildObject(const std::string&
  elementName)
{
  UnivariateDistribution* obj = NULL;

  if (elementName == "truncationLowerBound")
  {
    return createTruncationLowerBound();
  }
  else if (elementName == "truncationUpperBound")
  {
    return createTruncationUpperBound();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this DiscreteUnivariateDistribution.
 */
int
DiscreteUnivariateDistribution::addChildObject(const std::string& elementName,
                                               const SBase* element)
{
  if (elementName == "truncationLowerBound" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTBOUND)
  {
    return setTruncationLowerBound((const UncertBound*)(element));
  }
  else if (elementName == "truncationUpperBound" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTBOUND)
  {
    return setTruncationUpperBound((const UncertBound*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * DiscreteUnivariateDistribution.
 */
SBase*
DiscreteUnivariateDistribution::removeChildObject(
                                                  const std::string&
                                                    elementName,
                                                  const std::string& id)
{
  if (elementName == "truncationLowerBound")
  {
    UncertBound * obj = getTruncationLowerBound();
    if (unsetTruncationLowerBound() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "truncationUpperBound")
  {
    UncertBound * obj = getTruncationUpperBound();
    if (unsetTruncationUpperBound() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this DiscreteUnivariateDistribution.
 */
unsigned int
DiscreteUnivariateDistribution::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "truncationLowerBound")
  {
    if (isSetTruncationLowerBound())
    {
      return 1;
    }
  }
  else if (elementName == "truncationUpperBound")
  {
    if (isSetTruncationUpperBound())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this
 * DiscreteUnivariateDistribution.
 */
SBase*
DiscreteUnivariateDistribution::getObject(const std::string& elementName,
                                          unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "truncationLowerBound")
  {
    return getTruncationLowerBound();
  }
  else if (elementName == "truncationUpperBound")
  {
    return getTruncationUpperBound();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
DiscreteUnivariateDistribution::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mTruncationLowerBound != NULL)
  {
    if (mTruncationLowerBound->getId() == id)
    {
      return mTruncationLowerBound;
    }

    obj = mTruncationLowerBound->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mTruncationUpperBound != NULL)
  {
    if (mTruncationUpperBound->getId() == id)
    {
      return mTruncationUpperBound;
    }

    obj = mTruncationUpperBound->getElementBySId(id);
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
DiscreteUnivariateDistribution::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mTruncationLowerBound != NULL)
  {
    if (mTruncationLowerBound->getMetaId() == metaid)
    {
      return mTruncationLowerBound;
    }

    obj = mTruncationLowerBound->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mTruncationUpperBound != NULL)
  {
    if (mTruncationUpperBound->getMetaId() == metaid)
    {
      return mTruncationUpperBound;
    }

    obj = mTruncationUpperBound->getElementByMetaId(metaid);
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
DiscreteUnivariateDistribution::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mTruncationLowerBound, filter);
  ADD_FILTERED_POINTER(ret, sublist, mTruncationUpperBound, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
DiscreteUnivariateDistribution::createObject(XMLInputStream& stream)
{
  SBase* obj = UnivariateDistribution::createObject(stream);

  const std::string& name = stream.peek().getName();

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());

  if (name == "truncationLowerBound")
  {
    if (isSetTruncationLowerBound())
    {
      getErrorLog()->logPackageError("distrib",
        DistribDiscreteUnivariateDistributionAllowedElements,
          getPackageVersion(), getLevel(), getVersion());
    }

    delete mTruncationLowerBound;
    mTruncationLowerBound = new UncertBound(distribns);
    mTruncationLowerBound->setElementName(name);
    obj = mTruncationLowerBound;
  }
  else if (name == "truncationUpperBound")
  {
    if (isSetTruncationUpperBound())
    {
      getErrorLog()->logPackageError("distrib",
        DistribDiscreteUnivariateDistributionAllowedElements,
          getPackageVersion(), getLevel(), getVersion());
    }

    delete mTruncationUpperBound;
    mTruncationUpperBound = new UncertBound(distribns);
    mTruncationUpperBound->setElementName(name);
    obj = mTruncationUpperBound;
  }

  delete distribns;

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
DiscreteUnivariateDistribution::addExpectedAttributes(ExpectedAttributes&
  attributes)
{
  UnivariateDistribution::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
DiscreteUnivariateDistribution::readAttributes(const XMLAttributes& attributes,
                                               const ExpectedAttributes&
                                                 expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  UnivariateDistribution::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("distrib",
          DistribDiscreteUnivariateDistributionAllowedAttributes, pkgVersion,
            level, version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("distrib",
          DistribDiscreteUnivariateDistributionAllowedCoreAttributes, pkgVersion,
            level, version, details, getLine(), getColumn());
      }
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
DiscreteUnivariateDistribution::writeAttributes(XMLOutputStream& stream) const
{
  UnivariateDistribution::writeAttributes(stream);

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new DiscreteUnivariateDistribution_t using the given SBML Level,
 * Version and &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
DiscreteUnivariateDistribution_t *
DiscreteUnivariateDistribution_create(unsigned int level,
                                      unsigned int version,
                                      unsigned int pkgVersion)
{
  return new DiscreteUnivariateDistribution(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this DiscreteUnivariateDistribution_t
 * object.
 */
LIBSBML_EXTERN
DiscreteUnivariateDistribution_t*
DiscreteUnivariateDistribution_clone(const DiscreteUnivariateDistribution_t*
  dud)
{
  if (dud != NULL)
  {
    return static_cast<DiscreteUnivariateDistribution_t*>(dud->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this DiscreteUnivariateDistribution_t object.
 */
LIBSBML_EXTERN
void
DiscreteUnivariateDistribution_free(DiscreteUnivariateDistribution_t* dud)
{
  if (dud != NULL)
  {
    delete dud;
  }
}


/*
 * Returns the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution_t.
 */
LIBSBML_EXTERN
const UncertBound_t*
DiscreteUnivariateDistribution_getTruncationLowerBound(const
  DiscreteUnivariateDistribution_t * dud)
{
  if (dud == NULL)
  {
    return NULL;
  }

  return (UncertBound_t*)(dud->getTruncationLowerBound());
}


/*
 * Returns the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution_t.
 */
LIBSBML_EXTERN
const UncertBound_t*
DiscreteUnivariateDistribution_getTruncationUpperBound(const
  DiscreteUnivariateDistribution_t * dud)
{
  if (dud == NULL)
  {
    return NULL;
  }

  return (UncertBound_t*)(dud->getTruncationUpperBound());
}


/*
 * Predicate returning @c 1 (true) if this DiscreteUnivariateDistribution_t's
 * "truncationLowerBound" element is set.
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_isSetTruncationLowerBound(const
  DiscreteUnivariateDistribution_t * dud)
{
  return (dud != NULL) ? static_cast<int>(dud->isSetTruncationLowerBound()) :
    0;
}


/*
 * Predicate returning @c 1 (true) if this DiscreteUnivariateDistribution_t's
 * "truncationUpperBound" element is set.
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_isSetTruncationUpperBound(const
  DiscreteUnivariateDistribution_t * dud)
{
  return (dud != NULL) ? static_cast<int>(dud->isSetTruncationUpperBound()) :
    0;
}


/*
 * Sets the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution_t.
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_setTruncationLowerBound(
                                                       DiscreteUnivariateDistribution_t
                                                         * dud,
                                                       const UncertBound_t* truncationLowerBound)
{
  return (dud != NULL) ? dud->setTruncationLowerBound(truncationLowerBound) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution_t.
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_setTruncationUpperBound(
                                                       DiscreteUnivariateDistribution_t
                                                         * dud,
                                                       const UncertBound_t* truncationUpperBound)
{
  return (dud != NULL) ? dud->setTruncationUpperBound(truncationUpperBound) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new UncertBound_t object, adds it to this
 * DiscreteUnivariateDistribution_t object and returns the UncertBound_t object
 * created.
 */
LIBSBML_EXTERN
UncertBound_t*
DiscreteUnivariateDistribution_createTruncationLowerBound(DiscreteUnivariateDistribution_t*
  dud)
{
  if (dud == NULL)
  {
    return NULL;
  }

  return (UncertBound_t*)(dud->createTruncationLowerBound());
}


/*
 * Creates a new UncertBound_t object, adds it to this
 * DiscreteUnivariateDistribution_t object and returns the UncertBound_t object
 * created.
 */
LIBSBML_EXTERN
UncertBound_t*
DiscreteUnivariateDistribution_createTruncationUpperBound(DiscreteUnivariateDistribution_t*
  dud)
{
  if (dud == NULL)
  {
    return NULL;
  }

  return (UncertBound_t*)(dud->createTruncationUpperBound());
}


/*
 * Unsets the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution_t.
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_unsetTruncationLowerBound(DiscreteUnivariateDistribution_t
  * dud)
{
  return (dud != NULL) ? dud->unsetTruncationLowerBound() :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution_t.
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_unsetTruncationUpperBound(DiscreteUnivariateDistribution_t
  * dud)
{
  return (dud != NULL) ? dud->unsetTruncationUpperBound() :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if this DiscreteUnivariateDistribution_t is of type
 * BinomialDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_isBinomialDistribution(const
  DiscreteUnivariateDistribution_t * dud)
{
  return (dud != NULL) ? static_cast<int>(dud->isBinomialDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this DiscreteUnivariateDistribution_t is of type
 * GeometricDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_isGeometricDistribution(const
  DiscreteUnivariateDistribution_t * dud)
{
  return (dud != NULL) ? static_cast<int>(dud->isGeometricDistribution()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * DiscreteUnivariateDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_hasRequiredAttributes(const
  DiscreteUnivariateDistribution_t * dud)
{
  return (dud != NULL) ? static_cast<int>(dud->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * DiscreteUnivariateDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_hasRequiredElements(const
  DiscreteUnivariateDistribution_t * dud)
{
  return (dud != NULL) ? static_cast<int>(dud->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


