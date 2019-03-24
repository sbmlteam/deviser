/**
 * @file BetaDistribution.cpp
 * @brief Implementation of the BetaDistribution class.
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
#include <sbml/packages/distrib/sbml/BetaDistribution.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new BetaDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
BetaDistribution::BetaDistribution(unsigned int level,
                                   unsigned int version,
                                   unsigned int pkgVersion)
  : ContinuousUnivariateDistribution(level, version, pkgVersion)
  , mAlpha (NULL)
  , mBeta (NULL)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new BetaDistribution using the given DistribPkgNamespaces object.
 */
BetaDistribution::BetaDistribution(DistribPkgNamespaces *distribns)
  : ContinuousUnivariateDistribution(distribns)
  , mAlpha (NULL)
  , mBeta (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for BetaDistribution.
 */
BetaDistribution::BetaDistribution(const BetaDistribution& orig)
  : ContinuousUnivariateDistribution( orig )
  , mAlpha ( NULL )
  , mBeta ( NULL )
{
  if (orig.mAlpha != NULL)
  {
    mAlpha = orig.mAlpha->clone();
  }

  if (orig.mBeta != NULL)
  {
    mBeta = orig.mBeta->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for BetaDistribution.
 */
BetaDistribution&
BetaDistribution::operator=(const BetaDistribution& rhs)
{
  if (&rhs != this)
  {
    ContinuousUnivariateDistribution::operator=(rhs);
    delete mAlpha;
    if (rhs.mAlpha != NULL)
    {
      mAlpha = rhs.mAlpha->clone();
    }
    else
    {
      mAlpha = NULL;
    }

    delete mBeta;
    if (rhs.mBeta != NULL)
    {
      mBeta = rhs.mBeta->clone();
    }
    else
    {
      mBeta = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this BetaDistribution object.
 */
BetaDistribution*
BetaDistribution::clone() const
{
  return new BetaDistribution(*this);
}


/*
 * Destructor for BetaDistribution.
 */
BetaDistribution::~BetaDistribution()
{
  delete mAlpha;
  mAlpha = NULL;
  delete mBeta;
  mBeta = NULL;
}


/*
 * Returns the value of the "alpha" element of this BetaDistribution.
 */
const UncertValue*
BetaDistribution::getAlpha() const
{
  return mAlpha;
}


/*
 * Returns the value of the "alpha" element of this BetaDistribution.
 */
UncertValue*
BetaDistribution::getAlpha()
{
  return mAlpha;
}


/*
 * Returns the value of the "beta" element of this BetaDistribution.
 */
const UncertValue*
BetaDistribution::getBeta() const
{
  return mBeta;
}


/*
 * Returns the value of the "beta" element of this BetaDistribution.
 */
UncertValue*
BetaDistribution::getBeta()
{
  return mBeta;
}


/*
 * Predicate returning @c true if this BetaDistribution's "alpha" element is
 * set.
 */
bool
BetaDistribution::isSetAlpha() const
{
  return (mAlpha != NULL);
}


/*
 * Predicate returning @c true if this BetaDistribution's "beta" element is
 * set.
 */
bool
BetaDistribution::isSetBeta() const
{
  return (mBeta != NULL);
}


/*
 * Sets the value of the "alpha" element of this BetaDistribution.
 */
int
BetaDistribution::setAlpha(const UncertValue* alpha)
{
  if (mAlpha == alpha)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (alpha == NULL)
  {
    delete mAlpha;
    mAlpha = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mAlpha;
    mAlpha = (alpha != NULL) ? alpha->clone() : NULL;
    if (mAlpha != NULL)
    {
      mAlpha->setElementName("alpha");
      mAlpha->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "beta" element of this BetaDistribution.
 */
int
BetaDistribution::setBeta(const UncertValue* beta)
{
  if (mBeta == beta)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (beta == NULL)
  {
    delete mBeta;
    mBeta = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mBeta;
    mBeta = (beta != NULL) ? beta->clone() : NULL;
    if (mBeta != NULL)
    {
      mBeta->setElementName("beta");
      mBeta->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new UncertValue object, adds it to this BetaDistribution object
 * and returns the UncertValue object created.
 */
UncertValue*
BetaDistribution::createAlpha()
{
  if (mAlpha != NULL)
  {
    delete mAlpha;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mAlpha = new UncertValue(distribns);

  mAlpha->setElementName("alpha");

  delete distribns;

  connectToChild();

  return mAlpha;
}


/*
 * Creates a new UncertValue object, adds it to this BetaDistribution object
 * and returns the UncertValue object created.
 */
UncertValue*
BetaDistribution::createBeta()
{
  if (mBeta != NULL)
  {
    delete mBeta;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mBeta = new UncertValue(distribns);

  mBeta->setElementName("beta");

  delete distribns;

  connectToChild();

  return mBeta;
}


/*
 * Unsets the value of the "alpha" element of this BetaDistribution.
 */
int
BetaDistribution::unsetAlpha()
{
  delete mAlpha;
  mAlpha = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "beta" element of this BetaDistribution.
 */
int
BetaDistribution::unsetBeta()
{
  delete mBeta;
  mBeta = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this BetaDistribution object.
 */
const std::string&
BetaDistribution::getElementName() const
{
  static const string name = "betaDistribution";
  return name;
}


/*
 * Returns the libSBML type code for this BetaDistribution object.
 */
int
BetaDistribution::getTypeCode() const
{
  return SBML_DISTRIB_BETADISTRIBUTION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * BetaDistribution object have been set.
 */
bool
BetaDistribution::hasRequiredAttributes() const
{
  bool allPresent = ContinuousUnivariateDistribution::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * BetaDistribution object have been set.
 */
bool
BetaDistribution::hasRequiredElements() const
{
  bool allPresent = ContinuousUnivariateDistribution::hasRequiredElements();

  if (isSetAlpha() == false)
  {
    allPresent = false;
  }

  if (isSetBeta() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
BetaDistribution::writeElements(XMLOutputStream& stream) const
{
  ContinuousUnivariateDistribution::writeElements(stream);

  if (isSetAlpha() == true)
  {
    mAlpha->write(stream);
  }

  if (isSetBeta() == true)
  {
    mBeta->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
BetaDistribution::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mAlpha != NULL)
  {
    mAlpha->accept(v);
  }

  if (mBeta != NULL)
  {
    mBeta->accept(v);
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
BetaDistribution::setSBMLDocument(SBMLDocument* d)
{
  ContinuousUnivariateDistribution::setSBMLDocument(d);

  if (mAlpha != NULL)
  {
    mAlpha->setSBMLDocument(d);
  }

  if (mBeta != NULL)
  {
    mBeta->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
BetaDistribution::connectToChild()
{
  ContinuousUnivariateDistribution::connectToChild();

  if (mAlpha != NULL)
  {
    mAlpha->connectToParent(this);
  }

  if (mBeta != NULL)
  {
    mBeta->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
BetaDistribution::enablePackageInternal(const std::string& pkgURI,
                                        const std::string& pkgPrefix,
                                        bool flag)
{
  ContinuousUnivariateDistribution::enablePackageInternal(pkgURI, pkgPrefix,
    flag);

  if (isSetAlpha())
  {
    mAlpha->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetBeta())
  {
    mBeta->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
BetaDistribution::updateSBMLNamespace(const std::string& package,
                                      unsigned int level,
                                      unsigned int version)
{
  ContinuousUnivariateDistribution::updateSBMLNamespace(package, level,
    version);

  if (mAlpha != NULL)
  {
    mAlpha->updateSBMLNamespace(package, level, version);
  }

  if (mBeta != NULL)
  {
    mBeta->updateSBMLNamespace(package, level, version);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::getAttribute(const std::string& attributeName,
                               bool& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::getAttribute(const std::string& attributeName,
                               int& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::getAttribute(const std::string& attributeName,
                               double& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::getAttribute(const std::string& attributeName,
                               unsigned int& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::getAttribute(const std::string& attributeName,
                               std::string& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this BetaDistribution's attribute
 * "attributeName" is set.
 */
bool
BetaDistribution::isSetAttribute(const std::string& attributeName) const
{
  bool value = ContinuousUnivariateDistribution::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::setAttribute(const std::string& attributeName, bool value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::setAttribute(const std::string& attributeName, int value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::setAttribute(const std::string& attributeName, double value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::setAttribute(const std::string& attributeName,
                               unsigned int value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::setAttribute(const std::string& attributeName,
                               const std::string& value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this BetaDistribution.
 */
int
BetaDistribution::unsetAttribute(const std::string& attributeName)
{
  int value = ContinuousUnivariateDistribution::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this BetaDistribution.
 */
SBase*
BetaDistribution::createChildObject(const std::string& elementName)
{
  ContinuousUnivariateDistribution* obj = NULL;

  if (elementName == "alpha")
  {
    return createAlpha();
  }
  else if (elementName == "beta")
  {
    return createBeta();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this BetaDistribution.
 */
int
BetaDistribution::addChildObject(const std::string& elementName,
                                 const SBase* element)
{
  if (elementName == "alpha" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTVALUE)
  {
    return setAlpha((const UncertValue*)(element));
  }
  else if (elementName == "beta" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTVALUE)
  {
    return setBeta((const UncertValue*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * BetaDistribution.
 */
SBase*
BetaDistribution::removeChildObject(const std::string& elementName,
                                    const std::string& id)
{
  if (elementName == "alpha")
  {
    UncertValue * obj = getAlpha();
    if (unsetAlpha() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "beta")
  {
    UncertValue * obj = getBeta();
    if (unsetBeta() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this BetaDistribution.
 */
unsigned int
BetaDistribution::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "alpha")
  {
    if (isSetAlpha())
    {
      return 1;
    }
  }
  else if (elementName == "beta")
  {
    if (isSetBeta())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this BetaDistribution.
 */
SBase*
BetaDistribution::getObject(const std::string& elementName,
                            unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "alpha")
  {
    return getAlpha();
  }
  else if (elementName == "beta")
  {
    return getBeta();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
BetaDistribution::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mAlpha != NULL)
  {
    if (mAlpha->getId() == id)
    {
      return mAlpha;
    }

    obj = mAlpha->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mBeta != NULL)
  {
    if (mBeta->getId() == id)
    {
      return mBeta;
    }

    obj = mBeta->getElementBySId(id);
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
BetaDistribution::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mAlpha != NULL)
  {
    if (mAlpha->getMetaId() == metaid)
    {
      return mAlpha;
    }

    obj = mAlpha->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mBeta != NULL)
  {
    if (mBeta->getMetaId() == metaid)
    {
      return mBeta;
    }

    obj = mBeta->getElementByMetaId(metaid);
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
BetaDistribution::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mAlpha, filter);
  ADD_FILTERED_POINTER(ret, sublist, mBeta, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
BetaDistribution::createObject(XMLInputStream& stream)
{
  SBase* obj = ContinuousUnivariateDistribution::createObject(stream);

  const std::string& name = stream.peek().getName();

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());

  if (name == "alpha")
  {
    if (isSetAlpha())
    {
      getErrorLog()->logPackageError("distrib",
        DistribBetaDistributionAllowedElements, getPackageVersion(), getLevel(),
          getVersion(), "", getLine(), getColumn());
    }

    delete mAlpha;
    mAlpha = new UncertValue(distribns);
    mAlpha->setElementName(name);
    obj = mAlpha;
  }
  else if (name == "beta")
  {
    if (isSetBeta())
    {
      getErrorLog()->logPackageError("distrib",
        DistribBetaDistributionAllowedElements, getPackageVersion(), getLevel(),
          getVersion(), "", getLine(), getColumn());
    }

    delete mBeta;
    mBeta = new UncertValue(distribns);
    mBeta->setElementName(name);
    obj = mBeta;
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
BetaDistribution::addExpectedAttributes(ExpectedAttributes& attributes)
{
  ContinuousUnivariateDistribution::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
BetaDistribution::readAttributes(const XMLAttributes& attributes,
                                 const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  ContinuousUnivariateDistribution::readAttributes(attributes,
    expectedAttributes);

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
          DistribBetaDistributionAllowedAttributes, pkgVersion, level, version,
            details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("distrib",
          DistribBetaDistributionAllowedCoreAttributes, pkgVersion, level,
            version, details, getLine(), getColumn());
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
BetaDistribution::writeAttributes(XMLOutputStream& stream) const
{
  ContinuousUnivariateDistribution::writeAttributes(stream);

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new BetaDistribution_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
BetaDistribution_t *
BetaDistribution_create(unsigned int level,
                        unsigned int version,
                        unsigned int pkgVersion)
{
  return new BetaDistribution(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this BetaDistribution_t object.
 */
LIBSBML_EXTERN
BetaDistribution_t*
BetaDistribution_clone(const BetaDistribution_t* bd)
{
  if (bd != NULL)
  {
    return static_cast<BetaDistribution_t*>(bd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this BetaDistribution_t object.
 */
LIBSBML_EXTERN
void
BetaDistribution_free(BetaDistribution_t* bd)
{
  if (bd != NULL)
  {
    delete bd;
  }
}


/*
 * Returns the value of the "alpha" element of this BetaDistribution_t.
 */
LIBSBML_EXTERN
const UncertValue_t*
BetaDistribution_getAlpha(const BetaDistribution_t * bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->getAlpha());
}


/*
 * Returns the value of the "beta" element of this BetaDistribution_t.
 */
LIBSBML_EXTERN
const UncertValue_t*
BetaDistribution_getBeta(const BetaDistribution_t * bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->getBeta());
}


/*
 * Predicate returning @c 1 (true) if this BetaDistribution_t's "alpha" element
 * is set.
 */
LIBSBML_EXTERN
int
BetaDistribution_isSetAlpha(const BetaDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->isSetAlpha()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this BetaDistribution_t's "beta" element
 * is set.
 */
LIBSBML_EXTERN
int
BetaDistribution_isSetBeta(const BetaDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->isSetBeta()) : 0;
}


/*
 * Sets the value of the "alpha" element of this BetaDistribution_t.
 */
LIBSBML_EXTERN
int
BetaDistribution_setAlpha(BetaDistribution_t * bd, const UncertValue_t* alpha)
{
  return (bd != NULL) ? bd->setAlpha(alpha) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "beta" element of this BetaDistribution_t.
 */
LIBSBML_EXTERN
int
BetaDistribution_setBeta(BetaDistribution_t * bd, const UncertValue_t* beta)
{
  return (bd != NULL) ? bd->setBeta(beta) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new UncertValue_t object, adds it to this BetaDistribution_t
 * object and returns the UncertValue_t object created.
 */
LIBSBML_EXTERN
UncertValue_t*
BetaDistribution_createAlpha(BetaDistribution_t* bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->createAlpha());
}


/*
 * Creates a new UncertValue_t object, adds it to this BetaDistribution_t
 * object and returns the UncertValue_t object created.
 */
LIBSBML_EXTERN
UncertValue_t*
BetaDistribution_createBeta(BetaDistribution_t* bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->createBeta());
}


/*
 * Unsets the value of the "alpha" element of this BetaDistribution_t.
 */
LIBSBML_EXTERN
int
BetaDistribution_unsetAlpha(BetaDistribution_t * bd)
{
  return (bd != NULL) ? bd->unsetAlpha() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "beta" element of this BetaDistribution_t.
 */
LIBSBML_EXTERN
int
BetaDistribution_unsetBeta(BetaDistribution_t * bd)
{
  return (bd != NULL) ? bd->unsetBeta() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * BetaDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
BetaDistribution_hasRequiredAttributes(const BetaDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * BetaDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
BetaDistribution_hasRequiredElements(const BetaDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


