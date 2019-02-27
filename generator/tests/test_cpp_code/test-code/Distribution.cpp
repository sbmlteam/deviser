/**
 * @file Distribution.cpp
 * @brief Implementation of the Distribution class.
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
#include <sbml/packages/distrib/sbml/Distribution.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>

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
 * Creates a new Distribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
Distribution::Distribution(unsigned int level,
                           unsigned int version,
                           unsigned int pkgVersion)
  : SBase(level, version)
  , mElementName("distribution")
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
}


/*
 * Creates a new Distribution using the given DistribPkgNamespaces object.
 */
Distribution::Distribution(DistribPkgNamespaces *distribns)
  : SBase(distribns)
  , mElementName("distribution")
{
  setElementNamespace(distribns->getURI());
  loadPlugins(distribns);
}


/*
 * Copy constructor for Distribution.
 */
Distribution::Distribution(const Distribution& orig)
  : SBase( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for Distribution.
 */
Distribution&
Distribution::operator=(const Distribution& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Distribution object.
 */
Distribution*
Distribution::clone() const
{
  return new Distribution(*this);
}


/*
 * Destructor for Distribution.
 */
Distribution::~Distribution()
{
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * BetaDistribution
 */
bool
Distribution::isBetaDistribution() const
{
  return dynamic_cast<const BetaDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * CauchyDistribution
 */
bool
Distribution::isCauchyDistribution() const
{
  return dynamic_cast<const CauchyDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * ExponentialDistribution
 */
bool
Distribution::isExponentialDistribution() const
{
  return dynamic_cast<const ExponentialDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * LogisticDistribution
 */
bool
Distribution::isLogisticDistribution() const
{
  return dynamic_cast<const LogisticDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * NormalDistribution
 */
bool
Distribution::isNormalDistribution() const
{
  return dynamic_cast<const NormalDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * BinomialDistribution
 */
bool
Distribution::isBinomialDistribution() const
{
  return dynamic_cast<const BinomialDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * GeometricDistribution
 */
bool
Distribution::isGeometricDistribution() const
{
  return dynamic_cast<const GeometricDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * BernoulliDistribution
 */
bool
Distribution::isBernoulliDistribution() const
{
  return dynamic_cast<const BernoulliDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * CategoricalDistribution
 */
bool
Distribution::isCategoricalDistribution() const
{
  return dynamic_cast<const CategoricalDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * MultivariateDistribution
 */
bool
Distribution::isMultivariateDistribution() const
{
  return dynamic_cast<const MultivariateDistribution*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Distribution" is of type
 * ExternalDistribution
 */
bool
Distribution::isExternalDistribution() const
{
  return dynamic_cast<const ExternalDistribution*>(this) != NULL;
}


/*
 * Returns the XML element name of this Distribution object.
 */
const std::string&
Distribution::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the XML name of this Distribution object.
 */
void
Distribution::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBML type code for this Distribution object.
 */
int
Distribution::getTypeCode() const
{
  return SBML_DISTRIB_DISTRIBUTION;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Distribution::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Distribution::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Distribution::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Distribution::enablePackageInternal(const std::string& pkgURI,
                                    const std::string& pkgPrefix,
                                    bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Distribution's attribute "attributeName"
 * is set.
 */
bool
Distribution::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Distribution.
 */
int
Distribution::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new BetaDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
BetaDistribution_t *
Distribution_createBetaDistribution(unsigned int level,
                                    unsigned int version,
                                    unsigned int pkgVersion)
{
  return new BetaDistribution(level, version, pkgVersion);
}


/*
 * Creates a new CauchyDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
CauchyDistribution_t *
Distribution_createCauchyDistribution(unsigned int level,
                                      unsigned int version,
                                      unsigned int pkgVersion)
{
  return new CauchyDistribution(level, version, pkgVersion);
}


/*
 * Creates a new ExponentialDistribution using the given SBML Level, Version
 * and &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
ExponentialDistribution_t *
Distribution_createExponentialDistribution(unsigned int level,
                                           unsigned int version,
                                           unsigned int pkgVersion)
{
  return new ExponentialDistribution(level, version, pkgVersion);
}


/*
 * Creates a new LogisticDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
LogisticDistribution_t *
Distribution_createLogisticDistribution(unsigned int level,
                                        unsigned int version,
                                        unsigned int pkgVersion)
{
  return new LogisticDistribution(level, version, pkgVersion);
}


/*
 * Creates a new NormalDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
NormalDistribution_t *
Distribution_createNormalDistribution(unsigned int level,
                                      unsigned int version,
                                      unsigned int pkgVersion)
{
  return new NormalDistribution(level, version, pkgVersion);
}


/*
 * Creates a new BinomialDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
BinomialDistribution_t *
Distribution_createBinomialDistribution(unsigned int level,
                                        unsigned int version,
                                        unsigned int pkgVersion)
{
  return new BinomialDistribution(level, version, pkgVersion);
}


/*
 * Creates a new GeometricDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
GeometricDistribution_t *
Distribution_createGeometricDistribution(unsigned int level,
                                         unsigned int version,
                                         unsigned int pkgVersion)
{
  return new GeometricDistribution(level, version, pkgVersion);
}


/*
 * Creates a new BernoulliDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
BernoulliDistribution_t *
Distribution_createBernoulliDistribution(unsigned int level,
                                         unsigned int version,
                                         unsigned int pkgVersion)
{
  return new BernoulliDistribution(level, version, pkgVersion);
}


/*
 * Creates a new CategoricalDistribution using the given SBML Level, Version
 * and &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
CategoricalDistribution_t *
Distribution_createCategoricalDistribution(unsigned int level,
                                           unsigned int version,
                                           unsigned int pkgVersion)
{
  return new CategoricalDistribution(level, version, pkgVersion);
}


/*
 * Creates a new MultivariateDistribution using the given SBML Level, Version
 * and &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
MultivariateDistribution_t *
Distribution_createMultivariateDistribution(unsigned int level,
                                            unsigned int version,
                                            unsigned int pkgVersion)
{
  return new MultivariateDistribution(level, version, pkgVersion);
}


/*
 * Creates a new ExternalDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
ExternalDistribution_t *
Distribution_createExternalDistribution(unsigned int level,
                                        unsigned int version,
                                        unsigned int pkgVersion)
{
  return new ExternalDistribution(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Distribution_t object.
 */
LIBSBML_EXTERN
Distribution_t*
Distribution_clone(const Distribution_t* d)
{
  if (d != NULL)
  {
    return static_cast<Distribution_t*>(d->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Distribution_t object.
 */
LIBSBML_EXTERN
void
Distribution_free(Distribution_t* d)
{
  if (d != NULL)
  {
    delete d;
  }
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * BetaDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isBetaDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isBetaDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * CauchyDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isCauchyDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isCauchyDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * ExponentialDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isExponentialDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isExponentialDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * LogisticDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isLogisticDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isLogisticDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * NormalDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isNormalDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isNormalDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * BinomialDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isBinomialDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isBinomialDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * GeometricDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isGeometricDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isGeometricDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * BernoulliDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isBernoulliDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isBernoulliDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * CategoricalDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isCategoricalDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isCategoricalDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * MultivariateDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isMultivariateDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isMultivariateDistribution()) : 0;
}


/*
 * Predicate returning @c 1 if this Distribution_t is of type
 * ExternalDistribution_t
 */
LIBSBML_EXTERN
int
Distribution_isExternalDistribution(const Distribution_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isExternalDistribution()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


