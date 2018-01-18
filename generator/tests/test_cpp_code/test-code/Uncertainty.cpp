/**
 * @file Uncertainty.cpp
 * @brief Implementation of the Uncertainty class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2017 jointly by the following organizations:
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
#include <sbml/packages/distrib/sbml/Uncertainty.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>
#include <sbml/util/ElementFilter.h>

#include <sbml/packages/distrib/sbml/BetaDistribution.h>
#include <sbml/packages/distrib/sbml/CauchyDistribution.h>
#include <sbml/packages/distrib/sbml/ExponentialDistribution.h>
#include <sbml/packages/distrib/sbml/LogisticDistribution.h>
#include <sbml/packages/distrib/sbml/NormalDistribution.h>
#include <sbml/packages/distrib/sbml/BinomialDistribution.h>
#include <sbml/packages/distrib/sbml/GeometricDistribution.h>
#include <sbml/packages/distrib/sbml/BernoulliDistribution.h>
#include <sbml/packages/distrib/sbml/CategoricalDistribution.h>
#include <sbml/packages/distrib/sbml/MultivariateDistribution.h>
#include <sbml/packages/distrib/sbml/ExternalDistribution.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Uncertainty using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
Uncertainty::Uncertainty(unsigned int level,
                         unsigned int version,
                         unsigned int pkgVersion)
  : SBase(level, version)
  , mUncertStatistics (NULL)
  , mDistribution (NULL)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new Uncertainty using the given DistribPkgNamespaces object.
 */
Uncertainty::Uncertainty(DistribPkgNamespaces *distribns)
  : SBase(distribns)
  , mUncertStatistics (NULL)
  , mDistribution (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for Uncertainty.
 */
Uncertainty::Uncertainty(const Uncertainty& orig)
  : SBase( orig )
  , mUncertStatistics ( NULL )
  , mDistribution ( NULL )
{
  if (orig.mUncertStatistics != NULL)
  {
    mUncertStatistics = orig.mUncertStatistics->clone();
  }

  if (orig.mDistribution != NULL)
  {
    mDistribution = orig.mDistribution->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Uncertainty.
 */
Uncertainty&
Uncertainty::operator=(const Uncertainty& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    delete mUncertStatistics;
    if (rhs.mUncertStatistics != NULL)
    {
      mUncertStatistics = rhs.mUncertStatistics->clone();
    }
    else
    {
      mUncertStatistics = NULL;
    }

    delete mDistribution;
    if (rhs.mDistribution != NULL)
    {
      mDistribution = rhs.mDistribution->clone();
    }
    else
    {
      mDistribution = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Uncertainty object.
 */
Uncertainty*
Uncertainty::clone() const
{
  return new Uncertainty(*this);
}


/*
 * Destructor for Uncertainty.
 */
Uncertainty::~Uncertainty()
{
  delete mUncertStatistics;
  mUncertStatistics = NULL;
  delete mDistribution;
  mDistribution = NULL;
}


/*
 * Returns the value of the "uncertStatistics" element of this Uncertainty.
 */
const UncertStatistics*
Uncertainty::getUncertStatistics() const
{
  return mUncertStatistics;
}


/*
 * Returns the value of the "uncertStatistics" element of this Uncertainty.
 */
UncertStatistics*
Uncertainty::getUncertStatistics()
{
  return mUncertStatistics;
}


/*
 * Returns the value of the "distribution" element of this Uncertainty.
 */
const Distribution*
Uncertainty::getDistribution() const
{
  return mDistribution;
}


/*
 * Returns the value of the "distribution" element of this Uncertainty.
 */
Distribution*
Uncertainty::getDistribution()
{
  return mDistribution;
}


/*
 * Predicate returning @c true if this Uncertainty's "uncertStatistics" element
 * is set.
 */
bool
Uncertainty::isSetUncertStatistics() const
{
  return (mUncertStatistics != NULL);
}


/*
 * Predicate returning @c true if this Uncertainty's "distribution" element is
 * set.
 */
bool
Uncertainty::isSetDistribution() const
{
  return (mDistribution != NULL);
}


/*
 * Sets the value of the "uncertStatistics" element of this Uncertainty.
 */
int
Uncertainty::setUncertStatistics(const UncertStatistics* uncertStatistics)
{
  if (mUncertStatistics == uncertStatistics)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (uncertStatistics == NULL)
  {
    delete mUncertStatistics;
    mUncertStatistics = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mUncertStatistics;
    mUncertStatistics = (uncertStatistics != NULL) ? uncertStatistics->clone()
      : NULL;
    if (mUncertStatistics != NULL)
    {
      mUncertStatistics->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "distribution" element of this Uncertainty.
 */
int
Uncertainty::setDistribution(const Distribution* distribution)
{
  if (mDistribution == distribution)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (distribution == NULL)
  {
    delete mDistribution;
    mDistribution = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mDistribution;
    mDistribution = (distribution != NULL) ? distribution->clone() : NULL;
    if (mDistribution != NULL)
    {
      mDistribution->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new UncertStatistics object, adds it to this Uncertainty object
 * and returns the UncertStatistics object created.
 */
UncertStatistics*
Uncertainty::createUncertStatistics()
{
  if (mUncertStatistics != NULL)
  {
    delete mUncertStatistics;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mUncertStatistics = new UncertStatistics(distribns);

  delete distribns;

  connectToChild();

  return mUncertStatistics;
}


/*
 * Creates a new BetaDistribution object, adds it to this Uncertainty object
 * and returns the BetaDistribution object created.
 */
BetaDistribution*
Uncertainty::createBetaDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new BetaDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<BetaDistribution*>(mDistribution);
}


/*
 * Creates a new CauchyDistribution object, adds it to this Uncertainty object
 * and returns the CauchyDistribution object created.
 */
CauchyDistribution*
Uncertainty::createCauchyDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new CauchyDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<CauchyDistribution*>(mDistribution);
}


/*
 * Creates a new ExponentialDistribution object, adds it to this Uncertainty
 * object and returns the ExponentialDistribution object created.
 */
ExponentialDistribution*
Uncertainty::createExponentialDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new ExponentialDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<ExponentialDistribution*>(mDistribution);
}


/*
 * Creates a new LogisticDistribution object, adds it to this Uncertainty
 * object and returns the LogisticDistribution object created.
 */
LogisticDistribution*
Uncertainty::createLogisticDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new LogisticDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<LogisticDistribution*>(mDistribution);
}


/*
 * Creates a new NormalDistribution object, adds it to this Uncertainty object
 * and returns the NormalDistribution object created.
 */
NormalDistribution*
Uncertainty::createNormalDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new NormalDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<NormalDistribution*>(mDistribution);
}


/*
 * Creates a new BinomialDistribution object, adds it to this Uncertainty
 * object and returns the BinomialDistribution object created.
 */
BinomialDistribution*
Uncertainty::createBinomialDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new BinomialDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<BinomialDistribution*>(mDistribution);
}


/*
 * Creates a new GeometricDistribution object, adds it to this Uncertainty
 * object and returns the GeometricDistribution object created.
 */
GeometricDistribution*
Uncertainty::createGeometricDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new GeometricDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<GeometricDistribution*>(mDistribution);
}


/*
 * Creates a new BernoulliDistribution object, adds it to this Uncertainty
 * object and returns the BernoulliDistribution object created.
 */
BernoulliDistribution*
Uncertainty::createBernoulliDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new BernoulliDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<BernoulliDistribution*>(mDistribution);
}


/*
 * Creates a new CategoricalDistribution object, adds it to this Uncertainty
 * object and returns the CategoricalDistribution object created.
 */
CategoricalDistribution*
Uncertainty::createCategoricalDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new CategoricalDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<CategoricalDistribution*>(mDistribution);
}


/*
 * Creates a new MultivariateDistribution object, adds it to this Uncertainty
 * object and returns the MultivariateDistribution object created.
 */
MultivariateDistribution*
Uncertainty::createMultivariateDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new MultivariateDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<MultivariateDistribution*>(mDistribution);
}


/*
 * Creates a new ExternalDistribution object, adds it to this Uncertainty
 * object and returns the ExternalDistribution object created.
 */
ExternalDistribution*
Uncertainty::createExternalDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new ExternalDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<ExternalDistribution*>(mDistribution);
}


/*
 * Unsets the value of the "uncertStatistics" element of this Uncertainty.
 */
int
Uncertainty::unsetUncertStatistics()
{
  delete mUncertStatistics;
  mUncertStatistics = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "distribution" element of this Uncertainty.
 */
int
Uncertainty::unsetDistribution()
{
  delete mDistribution;
  mDistribution = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this Uncertainty object.
 */
const std::string&
Uncertainty::getElementName() const
{
  static const string name = "uncertainty";
  return name;
}


/*
 * Returns the libSBML type code for this Uncertainty object.
 */
int
Uncertainty::getTypeCode() const
{
  return SBML_DISTRIB_UNCERTAINTY;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Uncertainty::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetUncertStatistics() == true)
  {
    mUncertStatistics->write(stream);
  }

  if (isSetDistribution() == true)
  {
    mDistribution->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Uncertainty::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mUncertStatistics != NULL)
  {
    mUncertStatistics->accept(v);
  }

  if (mDistribution != NULL)
  {
    mDistribution->accept(v);
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
Uncertainty::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  if (mUncertStatistics != NULL)
  {
    mUncertStatistics->setSBMLDocument(d);
  }

  if (mDistribution != NULL)
  {
    mDistribution->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Uncertainty::connectToChild()
{
  SBase::connectToChild();

  if (mUncertStatistics != NULL)
  {
    mUncertStatistics->connectToParent(this);
  }

  if (mDistribution != NULL)
  {
    mDistribution->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Uncertainty::enablePackageInternal(const std::string& pkgURI,
                                   const std::string& pkgPrefix,
                                   bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetUncertStatistics())
  {
    mUncertStatistics->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetDistribution())
  {
    mDistribution->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::getAttribute(const std::string& attributeName,
                          std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Uncertainty's attribute "attributeName"
 * is set.
 */
bool
Uncertainty::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Uncertainty.
 */
int
Uncertainty::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this Uncertainty.
 */
SBase*
Uncertainty::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "uncertStatistics")
  {
    return createUncertStatistics();
  }
  else if (elementName == "betaDistribution")
  {
    return createBetaDistribution();
  }
  else if (elementName == "cauchyDistribution")
  {
    return createCauchyDistribution();
  }
  else if (elementName == "exponentialDistribution")
  {
    return createExponentialDistribution();
  }
  else if (elementName == "logisticDistribution")
  {
    return createLogisticDistribution();
  }
  else if (elementName == "normalDistribution")
  {
    return createNormalDistribution();
  }
  else if (elementName == "binomialDistribution")
  {
    return createBinomialDistribution();
  }
  else if (elementName == "geometricDistribution")
  {
    return createGeometricDistribution();
  }
  else if (elementName == "bernoulliDistribution")
  {
    return createBernoulliDistribution();
  }
  else if (elementName == "categoricalDistribution")
  {
    return createCategoricalDistribution();
  }
  else if (elementName == "multivariateDistribution")
  {
    return createMultivariateDistribution();
  }
  else if (elementName == "externalDistribution")
  {
    return createExternalDistribution();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this Uncertainty.
 */
int
Uncertainty::addChildObject(const std::string& elementName,
                            const SBase* element)
{
  if (elementName == "uncertStatistics" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTSTATISTICS)
  {
    return setUncertStatistics((const UncertStatistics*)(element));
  }
  else if (elementName == "betaDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_BETADISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "cauchyDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_CAUCHYDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "exponentialDistribution" && element->getTypeCode()
    == SBML_DISTRIB_EXPONENTIALDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "logisticDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_LOGISTICDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "normalDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_NORMALDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "binomialDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_BINOMIALDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "geometricDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_GEOMETRICLDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "bernoulliDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_BERNOULLIDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "categoricalDistribution" && element->getTypeCode()
    == SBML_DISTRIB_CATEGORICALDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "multivariateDistribution" && element->getTypeCode()
    == SBML_DISTRIB_MULTIVARIATEDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "externalDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_EXTERNALDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Uncertainty.
 */
SBase*
Uncertainty::removeChildObject(const std::string& elementName,
                               const std::string& id)
{
  if (elementName == "uncertStatistics")
  {
    UncertStatistics * obj = getUncertStatistics();
    if (unsetUncertStatistics() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "betaDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "cauchyDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "exponentialDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "logisticDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "normalDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "binomialDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "geometricDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "bernoulliDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "categoricalDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "multivariateDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "externalDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this Uncertainty.
 */
unsigned int
Uncertainty::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "uncertStatistics")
  {
    if (isSetUncertStatistics())
    {
      return 1;
    }
  }
  else if (elementName == "distribution")
  {
    if (isSetDistribution())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this Uncertainty.
 */
SBase*
Uncertainty::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "uncertStatistics")
  {
    return getUncertStatistics();
  }
  else if (elementName == "distribution")
  {
    return getDistribution();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
Uncertainty::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mUncertStatistics != NULL)
  {
    if (mUncertStatistics->getId() == id)
    {
      return mUncertStatistics;
    }

    obj = mUncertStatistics->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mDistribution != NULL)
  {
    if (mDistribution->getId() == id)
    {
      return mDistribution;
    }

    obj = mDistribution->getElementBySId(id);
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
Uncertainty::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mUncertStatistics != NULL)
  {
    if (mUncertStatistics->getMetaId() == metaid)
    {
      return mUncertStatistics;
    }

    obj = mUncertStatistics->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mDistribution != NULL)
  {
    if (mDistribution->getMetaId() == metaid)
    {
      return mDistribution;
    }

    obj = mDistribution->getElementByMetaId(metaid);
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
Uncertainty::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mUncertStatistics, filter);
  ADD_FILTERED_POINTER(ret, sublist, mDistribution, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
Uncertainty::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());

  if (name == "betaDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new BetaDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "cauchyDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new CauchyDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "exponentialDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new ExponentialDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "logisticDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new LogisticDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "normalDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new NormalDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "binomialDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new BinomialDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "geometricDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new GeometricDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "bernoulliDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new BernoulliDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "categoricalDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new CategoricalDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "multivariateDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new MultivariateDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "externalDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new ExternalDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "uncertStatistics")
  {
    if (isSetUncertStatistics())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mUncertStatistics;
    mUncertStatistics = new UncertStatistics(distribns);
    obj = mUncertStatistics;
  }

  delete distribns;

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Uncertainty_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
Uncertainty_t *
Uncertainty_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
{
  return new Uncertainty(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Uncertainty_t object.
 */
LIBSBML_EXTERN
Uncertainty_t*
Uncertainty_clone(const Uncertainty_t* u)
{
  if (u != NULL)
  {
    return static_cast<Uncertainty_t*>(u->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Uncertainty_t object.
 */
LIBSBML_EXTERN
void
Uncertainty_free(Uncertainty_t* u)
{
  if (u != NULL)
  {
    delete u;
  }
}


/*
 * Returns the value of the "uncertStatistics" element of this Uncertainty_t.
 */
LIBSBML_EXTERN
const UncertStatistics_t*
Uncertainty_getUncertStatistics(const Uncertainty_t * u)
{
  if (u == NULL)
  {
    return NULL;
  }

  return (UncertStatistics_t*)(u->getUncertStatistics());
}


/*
 * Returns the value of the "distribution" element of this Uncertainty_t.
 */
LIBSBML_EXTERN
const Distribution_t*
Uncertainty_getDistribution(const Uncertainty_t * u)
{
  if (u == NULL)
  {
    return NULL;
  }

  return (Distribution_t*)(u->getDistribution());
}


/*
 * Predicate returning @c 1 (true) if this Uncertainty_t's "uncertStatistics"
 * element is set.
 */
LIBSBML_EXTERN
int
Uncertainty_isSetUncertStatistics(const Uncertainty_t * u)
{
  return (u != NULL) ? static_cast<int>(u->isSetUncertStatistics()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Uncertainty_t's "distribution"
 * element is set.
 */
LIBSBML_EXTERN
int
Uncertainty_isSetDistribution(const Uncertainty_t * u)
{
  return (u != NULL) ? static_cast<int>(u->isSetDistribution()) : 0;
}


/*
 * Sets the value of the "uncertStatistics" element of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_setUncertStatistics(Uncertainty_t * u,
                                const UncertStatistics_t* uncertStatistics)
{
  return (u != NULL) ? u->setUncertStatistics(uncertStatistics) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "distribution" element of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_setDistribution(Uncertainty_t * u,
                            const Distribution_t* distribution)
{
  return (u != NULL) ? u->setDistribution(distribution) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new UncertStatistics_t object, adds it to this Uncertainty_t
 * object and returns the UncertStatistics_t object created.
 */
LIBSBML_EXTERN
UncertStatistics_t*
Uncertainty_createUncertStatistics(Uncertainty_t* u)
{
  if (u == NULL)
  {
    return NULL;
  }

  return (UncertStatistics_t*)(u->createUncertStatistics());
}


/*
 * Creates a new BetaDistribution_t object, adds it to this Uncertainty_t
 * object and returns the BetaDistribution_t object created.
 */
LIBSBML_EXTERN
BetaDistribution_t*
Uncertainty_createBetaDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createBetaDistribution() : NULL;
}


/*
 * Creates a new CauchyDistribution_t object, adds it to this Uncertainty_t
 * object and returns the CauchyDistribution_t object created.
 */
LIBSBML_EXTERN
CauchyDistribution_t*
Uncertainty_createCauchyDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createCauchyDistribution() : NULL;
}


/*
 * Creates a new ExponentialDistribution_t object, adds it to this
 * Uncertainty_t object and returns the ExponentialDistribution_t object
 * created.
 */
LIBSBML_EXTERN
ExponentialDistribution_t*
Uncertainty_createExponentialDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createExponentialDistribution() : NULL;
}


/*
 * Creates a new LogisticDistribution_t object, adds it to this Uncertainty_t
 * object and returns the LogisticDistribution_t object created.
 */
LIBSBML_EXTERN
LogisticDistribution_t*
Uncertainty_createLogisticDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createLogisticDistribution() : NULL;
}


/*
 * Creates a new NormalDistribution_t object, adds it to this Uncertainty_t
 * object and returns the NormalDistribution_t object created.
 */
LIBSBML_EXTERN
NormalDistribution_t*
Uncertainty_createNormalDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createNormalDistribution() : NULL;
}


/*
 * Creates a new BinomialDistribution_t object, adds it to this Uncertainty_t
 * object and returns the BinomialDistribution_t object created.
 */
LIBSBML_EXTERN
BinomialDistribution_t*
Uncertainty_createBinomialDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createBinomialDistribution() : NULL;
}


/*
 * Creates a new GeometricDistribution_t object, adds it to this Uncertainty_t
 * object and returns the GeometricDistribution_t object created.
 */
LIBSBML_EXTERN
GeometricDistribution_t*
Uncertainty_createGeometricDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createGeometricDistribution() : NULL;
}


/*
 * Creates a new BernoulliDistribution_t object, adds it to this Uncertainty_t
 * object and returns the BernoulliDistribution_t object created.
 */
LIBSBML_EXTERN
BernoulliDistribution_t*
Uncertainty_createBernoulliDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createBernoulliDistribution() : NULL;
}


/*
 * Creates a new CategoricalDistribution_t object, adds it to this
 * Uncertainty_t object and returns the CategoricalDistribution_t object
 * created.
 */
LIBSBML_EXTERN
CategoricalDistribution_t*
Uncertainty_createCategoricalDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createCategoricalDistribution() : NULL;
}


/*
 * Creates a new MultivariateDistribution_t object, adds it to this
 * Uncertainty_t object and returns the MultivariateDistribution_t object
 * created.
 */
LIBSBML_EXTERN
MultivariateDistribution_t*
Uncertainty_createMultivariateDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createMultivariateDistribution() : NULL;
}


/*
 * Creates a new ExternalDistribution_t object, adds it to this Uncertainty_t
 * object and returns the ExternalDistribution_t object created.
 */
LIBSBML_EXTERN
ExternalDistribution_t*
Uncertainty_createExternalDistribution(Uncertainty_t* u)
{
  return (u != NULL) ? u->createExternalDistribution() : NULL;
}


/*
 * Unsets the value of the "uncertStatistics" element of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_unsetUncertStatistics(Uncertainty_t * u)
{
  return (u != NULL) ? u->unsetUncertStatistics() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "distribution" element of this Uncertainty_t.
 */
LIBSBML_EXTERN
int
Uncertainty_unsetDistribution(Uncertainty_t * u)
{
  return (u != NULL) ? u->unsetDistribution() : LIBSBML_INVALID_OBJECT;
}




LIBSBML_CPP_NAMESPACE_END


