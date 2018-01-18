/**
 * @file UncertaintyA.cpp
 * @brief Implementation of the UncertaintyA class.
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
#include <sbml/packages/distrib/sbml/UncertaintyA.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>
#include <sbml/util/ElementFilter.h>

#include <sbml/packages/distrib/sbml/BetaDistribution.h>
#include <sbml/packages/distrib/sbml/CauchyDistribution.h>
#include <sbml/packages/distrib/sbml/ChiSquareDistribution.h>
#include <sbml/packages/distrib/sbml/ExponentialDistribution.h>
#include <sbml/packages/distrib/sbml/FDistribution.h>
#include <sbml/packages/distrib/sbml/GammaDistribution.h>
#include <sbml/packages/distrib/sbml/InverseGammaDistribution.h>
#include <sbml/packages/distrib/sbml/LaPlaceDistribution.h>
#include <sbml/packages/distrib/sbml/LogNormalDistribution.h>
#include <sbml/packages/distrib/sbml/LogisticDistribution.h>
#include <sbml/packages/distrib/sbml/NormalDistribution.h>
#include <sbml/packages/distrib/sbml/ParetoDistribution.h>
#include <sbml/packages/distrib/sbml/RayleighDistribution.h>
#include <sbml/packages/distrib/sbml/StudentTDistribution.h>
#include <sbml/packages/distrib/sbml/UniformDistribution.h>
#include <sbml/packages/distrib/sbml/WeibullDistribution.h>
#include <sbml/packages/distrib/sbml/BinomialDistribution.h>
#include <sbml/packages/distrib/sbml/GeometricDistribution.h>
#include <sbml/packages/distrib/sbml/HypergeometricDistribution.h>
#include <sbml/packages/distrib/sbml/NegativeBinomialDistribution.h>
#include <sbml/packages/distrib/sbml/PoissonDistribution.h>
#include <sbml/packages/distrib/sbml/BernoulliDistribution.h>
#include <sbml/packages/distrib/sbml/CategoricalDistribution.h>
#include <sbml/packages/distrib/sbml/MultivariateDistribution.h>
#include <sbml/packages/distrib/sbml/ExternalDistribution.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new UncertaintyA using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
UncertaintyA::UncertaintyA(unsigned int level,
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
 * Creates a new UncertaintyA using the given DistribPkgNamespaces object.
 */
UncertaintyA::UncertaintyA(DistribPkgNamespaces *distribns)
  : SBase(distribns)
  , mUncertStatistics (NULL)
  , mDistribution (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for UncertaintyA.
 */
UncertaintyA::UncertaintyA(const UncertaintyA& orig)
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
 * Assignment operator for UncertaintyA.
 */
UncertaintyA&
UncertaintyA::operator=(const UncertaintyA& rhs)
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
 * Creates and returns a deep copy of this UncertaintyA object.
 */
UncertaintyA*
UncertaintyA::clone() const
{
  return new UncertaintyA(*this);
}


/*
 * Destructor for UncertaintyA.
 */
UncertaintyA::~UncertaintyA()
{
  delete mUncertStatistics;
  mUncertStatistics = NULL;
  delete mDistribution;
  mDistribution = NULL;
}


/*
 * Returns the value of the "uncertStatistics" element of this UncertaintyA.
 */
const UncertStatistics*
UncertaintyA::getUncertStatistics() const
{
  return mUncertStatistics;
}


/*
 * Returns the value of the "uncertStatistics" element of this UncertaintyA.
 */
UncertStatistics*
UncertaintyA::getUncertStatistics()
{
  return mUncertStatistics;
}


/*
 * Returns the value of the "distribution" element of this UncertaintyA.
 */
const Distribution*
UncertaintyA::getDistribution() const
{
  return mDistribution;
}


/*
 * Returns the value of the "distribution" element of this UncertaintyA.
 */
Distribution*
UncertaintyA::getDistribution()
{
  return mDistribution;
}


/*
 * Predicate returning @c true if this UncertaintyA's "uncertStatistics"
 * element is set.
 */
bool
UncertaintyA::isSetUncertStatistics() const
{
  return (mUncertStatistics != NULL);
}


/*
 * Predicate returning @c true if this UncertaintyA's "distribution" element is
 * set.
 */
bool
UncertaintyA::isSetDistribution() const
{
  return (mDistribution != NULL);
}


/*
 * Sets the value of the "uncertStatistics" element of this UncertaintyA.
 */
int
UncertaintyA::setUncertStatistics(const UncertStatistics* uncertStatistics)
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
 * Sets the value of the "distribution" element of this UncertaintyA.
 */
int
UncertaintyA::setDistribution(const Distribution* distribution)
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
 * Creates a new UncertStatistics object, adds it to this UncertaintyA object
 * and returns the UncertStatistics object created.
 */
UncertStatistics*
UncertaintyA::createUncertStatistics()
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
 * Creates a new BetaDistribution object, adds it to this UncertaintyA object
 * and returns the BetaDistribution object created.
 */
BetaDistribution*
UncertaintyA::createBetaDistribution()
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
 * Creates a new CauchyDistribution object, adds it to this UncertaintyA object
 * and returns the CauchyDistribution object created.
 */
CauchyDistribution*
UncertaintyA::createCauchyDistribution()
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
 * Creates a new ChiSquareDistribution object, adds it to this UncertaintyA
 * object and returns the ChiSquareDistribution object created.
 */
ChiSquareDistribution*
UncertaintyA::createChiSquareDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new ChiSquareDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<ChiSquareDistribution*>(mDistribution);
}


/*
 * Creates a new ExponentialDistribution object, adds it to this UncertaintyA
 * object and returns the ExponentialDistribution object created.
 */
ExponentialDistribution*
UncertaintyA::createExponentialDistribution()
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
 * Creates a new FDistribution object, adds it to this UncertaintyA object and
 * returns the FDistribution object created.
 */
FDistribution*
UncertaintyA::createFDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new FDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<FDistribution*>(mDistribution);
}


/*
 * Creates a new GammaDistribution object, adds it to this UncertaintyA object
 * and returns the GammaDistribution object created.
 */
GammaDistribution*
UncertaintyA::createGammaDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new GammaDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<GammaDistribution*>(mDistribution);
}


/*
 * Creates a new InverseGammaDistribution object, adds it to this UncertaintyA
 * object and returns the InverseGammaDistribution object created.
 */
InverseGammaDistribution*
UncertaintyA::createInverseGammaDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new InverseGammaDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<InverseGammaDistribution*>(mDistribution);
}


/*
 * Creates a new LaPlaceDistribution object, adds it to this UncertaintyA
 * object and returns the LaPlaceDistribution object created.
 */
LaPlaceDistribution*
UncertaintyA::createLaPlaceDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new LaPlaceDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<LaPlaceDistribution*>(mDistribution);
}


/*
 * Creates a new LogNormalDistribution object, adds it to this UncertaintyA
 * object and returns the LogNormalDistribution object created.
 */
LogNormalDistribution*
UncertaintyA::createLogNormalDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new LogNormalDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<LogNormalDistribution*>(mDistribution);
}


/*
 * Creates a new LogisticDistribution object, adds it to this UncertaintyA
 * object and returns the LogisticDistribution object created.
 */
LogisticDistribution*
UncertaintyA::createLogisticDistribution()
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
 * Creates a new NormalDistribution object, adds it to this UncertaintyA object
 * and returns the NormalDistribution object created.
 */
NormalDistribution*
UncertaintyA::createNormalDistribution()
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
 * Creates a new ParetoDistribution object, adds it to this UncertaintyA object
 * and returns the ParetoDistribution object created.
 */
ParetoDistribution*
UncertaintyA::createParetoDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new ParetoDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<ParetoDistribution*>(mDistribution);
}


/*
 * Creates a new RayleighDistribution object, adds it to this UncertaintyA
 * object and returns the RayleighDistribution object created.
 */
RayleighDistribution*
UncertaintyA::createRayleighDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new RayleighDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<RayleighDistribution*>(mDistribution);
}


/*
 * Creates a new StudentTDistribution object, adds it to this UncertaintyA
 * object and returns the StudentTDistribution object created.
 */
StudentTDistribution*
UncertaintyA::createStudentTDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new StudentTDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<StudentTDistribution*>(mDistribution);
}


/*
 * Creates a new UniformDistribution object, adds it to this UncertaintyA
 * object and returns the UniformDistribution object created.
 */
UniformDistribution*
UncertaintyA::createUniformDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new UniformDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<UniformDistribution*>(mDistribution);
}


/*
 * Creates a new WeibullDistribution object, adds it to this UncertaintyA
 * object and returns the WeibullDistribution object created.
 */
WeibullDistribution*
UncertaintyA::createWeibullDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new WeibullDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<WeibullDistribution*>(mDistribution);
}


/*
 * Creates a new BinomialDistribution object, adds it to this UncertaintyA
 * object and returns the BinomialDistribution object created.
 */
BinomialDistribution*
UncertaintyA::createBinomialDistribution()
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
 * Creates a new GeometricDistribution object, adds it to this UncertaintyA
 * object and returns the GeometricDistribution object created.
 */
GeometricDistribution*
UncertaintyA::createGeometricDistribution()
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
 * Creates a new HypergeometricDistribution object, adds it to this
 * UncertaintyA object and returns the HypergeometricDistribution object
 * created.
 */
HypergeometricDistribution*
UncertaintyA::createHypergeometricDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new HypergeometricDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<HypergeometricDistribution*>(mDistribution);
}


/*
 * Creates a new NegativeBinomialDistribution object, adds it to this
 * UncertaintyA object and returns the NegativeBinomialDistribution object
 * created.
 */
NegativeBinomialDistribution*
UncertaintyA::createNegativeBinomialDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new NegativeBinomialDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<NegativeBinomialDistribution*>(mDistribution);
}


/*
 * Creates a new PoissonDistribution object, adds it to this UncertaintyA
 * object and returns the PoissonDistribution object created.
 */
PoissonDistribution*
UncertaintyA::createPoissonDistribution()
{
  if (mDistribution != NULL)
  {
    delete mDistribution;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mDistribution = new PoissonDistribution(distribns);

  delete distribns;

  connectToChild();

  return static_cast<PoissonDistribution*>(mDistribution);
}


/*
 * Creates a new BernoulliDistribution object, adds it to this UncertaintyA
 * object and returns the BernoulliDistribution object created.
 */
BernoulliDistribution*
UncertaintyA::createBernoulliDistribution()
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
 * Creates a new CategoricalDistribution object, adds it to this UncertaintyA
 * object and returns the CategoricalDistribution object created.
 */
CategoricalDistribution*
UncertaintyA::createCategoricalDistribution()
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
 * Creates a new MultivariateDistribution object, adds it to this UncertaintyA
 * object and returns the MultivariateDistribution object created.
 */
MultivariateDistribution*
UncertaintyA::createMultivariateDistribution()
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
 * Creates a new ExternalDistribution object, adds it to this UncertaintyA
 * object and returns the ExternalDistribution object created.
 */
ExternalDistribution*
UncertaintyA::createExternalDistribution()
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
 * Unsets the value of the "uncertStatistics" element of this UncertaintyA.
 */
int
UncertaintyA::unsetUncertStatistics()
{
  delete mUncertStatistics;
  mUncertStatistics = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "distribution" element of this UncertaintyA.
 */
int
UncertaintyA::unsetDistribution()
{
  delete mDistribution;
  mDistribution = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this UncertaintyA object.
 */
const std::string&
UncertaintyA::getElementName() const
{
  static const string name = "uncertainty";
  return name;
}


/*
 * Returns the libSBML type code for this UncertaintyA object.
 */
int
UncertaintyA::getTypeCode() const
{
  return SBML_DISTRIB_UNCERTAINTY;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
UncertaintyA::writeElements(XMLOutputStream& stream) const
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
UncertaintyA::accept(SBMLVisitor& v) const
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
UncertaintyA::setSBMLDocument(SBMLDocument* d)
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
UncertaintyA::connectToChild()
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
UncertaintyA::enablePackageInternal(const std::string& pkgURI,
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
 * Gets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this UncertaintyA's attribute "attributeName"
 * is set.
 */
bool
UncertaintyA::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this UncertaintyA.
 */
int
UncertaintyA::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this UncertaintyA.
 */
SBase*
UncertaintyA::createChildObject(const std::string& elementName)
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
  else if (elementName == "chiSquareDistribution")
  {
    return createChiSquareDistribution();
  }
  else if (elementName == "exponentialDistribution")
  {
    return createExponentialDistribution();
  }
  else if (elementName == "fDistribution")
  {
    return createFDistribution();
  }
  else if (elementName == "gammaDistribution")
  {
    return createGammaDistribution();
  }
  else if (elementName == "inverseGammaDistribution")
  {
    return createInverseGammaDistribution();
  }
  else if (elementName == "laPlaceDistribution")
  {
    return createLaPlaceDistribution();
  }
  else if (elementName == "logNormalDistribution")
  {
    return createLogNormalDistribution();
  }
  else if (elementName == "logisticDistribution")
  {
    return createLogisticDistribution();
  }
  else if (elementName == "normalDistribution")
  {
    return createNormalDistribution();
  }
  else if (elementName == "paretoDistribution")
  {
    return createParetoDistribution();
  }
  else if (elementName == "rayleighDistribution")
  {
    return createRayleighDistribution();
  }
  else if (elementName == "studentTDistribution")
  {
    return createStudentTDistribution();
  }
  else if (elementName == "uniformDistribution")
  {
    return createUniformDistribution();
  }
  else if (elementName == "weibullDistribution")
  {
    return createWeibullDistribution();
  }
  else if (elementName == "binomialDistribution")
  {
    return createBinomialDistribution();
  }
  else if (elementName == "geometricDistribution")
  {
    return createGeometricDistribution();
  }
  else if (elementName == "hypergeometricDistribution")
  {
    return createHypergeometricDistribution();
  }
  else if (elementName == "negativeBinomialDistribution")
  {
    return createNegativeBinomialDistribution();
  }
  else if (elementName == "poissonDistribution")
  {
    return createPoissonDistribution();
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
 * Adds a new "elementName" object to this UncertaintyA.
 */
int
UncertaintyA::addChildObject(const std::string& elementName,
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
  else if (elementName == "chiSquareDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_CHISQUAREDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "exponentialDistribution" && element->getTypeCode()
    == SBML_DISTRIB_EXPONENTIALDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "fDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_FDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "gammaDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_GAMMADISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "inverseGammaDistribution" && element->getTypeCode()
    == SBML_DISTRIB_INVERSEGAMMADISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "laPlaceDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_LAPLACEDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "logNormalDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_LOGNORMALDISTRIBUTION)
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
  else if (elementName == "paretoDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_PARETODISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "rayleighDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_RAYLEIGHDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "studentTDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_STUDENTTDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "uniformDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_UNIFORMDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "weibullDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_WEIBULLDISTRIBUTION)
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
  else if (elementName == "hypergeometricDistribution" &&
    element->getTypeCode() == SBML_DISTRIB_HYPERGEOMETRICDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "negativeBinomialDistribution" &&
    element->getTypeCode() == SBML_DISTRIB_NEGATIVEBINOMIALDISTRIBUTION)
  {
    return setDistribution((const Distribution*)(element));
  }
  else if (elementName == "poissonDistribution" && element->getTypeCode() ==
    SBML_DISTRIB_POISSONDISTRIBUTION)
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
 * UncertaintyA.
 */
SBase*
UncertaintyA::removeChildObject(const std::string& elementName,
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
  else if (elementName == "chiSquareDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "exponentialDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "fDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "gammaDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "inverseGammaDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "laPlaceDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "logNormalDistribution")
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
  else if (elementName == "paretoDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "rayleighDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "studentTDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "uniformDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "weibullDistribution")
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
  else if (elementName == "hypergeometricDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "negativeBinomialDistribution")
  {
    Distribution * obj = getDistribution();
    if (unsetDistribution() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "poissonDistribution")
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
 * Returns the number of "elementName" in this UncertaintyA.
 */
unsigned int
UncertaintyA::getNumObjects(const std::string& elementName)
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
 * Returns the nth object of "objectName" in this UncertaintyA.
 */
SBase*
UncertaintyA::getObject(const std::string& elementName, unsigned int index)
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
UncertaintyA::getElementBySId(const std::string& id)
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
UncertaintyA::getElementByMetaId(const std::string& metaid)
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
UncertaintyA::getAllElements(ElementFilter* filter)
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
UncertaintyA::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());

  if (name == "betaDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
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
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new CauchyDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "chiSquareDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new ChiSquareDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "exponentialDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new ExponentialDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "fDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new FDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "gammaDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new GammaDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "inverseGammaDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new InverseGammaDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "laPlaceDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new LaPlaceDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "logNormalDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new LogNormalDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "logisticDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
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
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new NormalDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "paretoDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new ParetoDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "rayleighDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new RayleighDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "studentTDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new StudentTDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "uniformDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new UniformDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "weibullDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new WeibullDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "binomialDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
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
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new GeometricDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "hypergeometricDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new HypergeometricDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "negativeBinomialDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new NegativeBinomialDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "poissonDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mDistribution;
    mDistribution = new PoissonDistribution(distribns);
    obj = mDistribution;
  }
  else if (name == "bernoulliDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
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
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
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
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
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
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
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
        DistribUncertaintyAAllowedElements, getPackageVersion(), getLevel(),
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
 * Creates a new UncertaintyA_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
UncertaintyA_t *
UncertaintyA_create(unsigned int level,
                    unsigned int version,
                    unsigned int pkgVersion)
{
  return new UncertaintyA(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this UncertaintyA_t object.
 */
LIBSBML_EXTERN
UncertaintyA_t*
UncertaintyA_clone(const UncertaintyA_t* ua)
{
  if (ua != NULL)
  {
    return static_cast<UncertaintyA_t*>(ua->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this UncertaintyA_t object.
 */
LIBSBML_EXTERN
void
UncertaintyA_free(UncertaintyA_t* ua)
{
  if (ua != NULL)
  {
    delete ua;
  }
}


/*
 * Returns the value of the "uncertStatistics" element of this UncertaintyA_t.
 */
LIBSBML_EXTERN
const UncertStatistics_t*
UncertaintyA_getUncertStatistics(const UncertaintyA_t * ua)
{
  if (ua == NULL)
  {
    return NULL;
  }

  return (UncertStatistics_t*)(ua->getUncertStatistics());
}


/*
 * Returns the value of the "distribution" element of this UncertaintyA_t.
 */
LIBSBML_EXTERN
const Distribution_t*
UncertaintyA_getDistribution(const UncertaintyA_t * ua)
{
  if (ua == NULL)
  {
    return NULL;
  }

  return (Distribution_t*)(ua->getDistribution());
}


/*
 * Predicate returning @c 1 (true) if this UncertaintyA_t's "uncertStatistics"
 * element is set.
 */
LIBSBML_EXTERN
int
UncertaintyA_isSetUncertStatistics(const UncertaintyA_t * ua)
{
  return (ua != NULL) ? static_cast<int>(ua->isSetUncertStatistics()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this UncertaintyA_t's "distribution"
 * element is set.
 */
LIBSBML_EXTERN
int
UncertaintyA_isSetDistribution(const UncertaintyA_t * ua)
{
  return (ua != NULL) ? static_cast<int>(ua->isSetDistribution()) : 0;
}


/*
 * Sets the value of the "uncertStatistics" element of this UncertaintyA_t.
 */
LIBSBML_EXTERN
int
UncertaintyA_setUncertStatistics(UncertaintyA_t * ua,
                                 const UncertStatistics_t* uncertStatistics)
{
  return (ua != NULL) ? ua->setUncertStatistics(uncertStatistics) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "distribution" element of this UncertaintyA_t.
 */
LIBSBML_EXTERN
int
UncertaintyA_setDistribution(UncertaintyA_t * ua,
                             const Distribution_t* distribution)
{
  return (ua != NULL) ? ua->setDistribution(distribution) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new UncertStatistics_t object, adds it to this UncertaintyA_t
 * object and returns the UncertStatistics_t object created.
 */
LIBSBML_EXTERN
UncertStatistics_t*
UncertaintyA_createUncertStatistics(UncertaintyA_t* ua)
{
  if (ua == NULL)
  {
    return NULL;
  }

  return (UncertStatistics_t*)(ua->createUncertStatistics());
}


/*
 * Creates a new BetaDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the BetaDistribution_t object created.
 */
LIBSBML_EXTERN
BetaDistribution_t*
UncertaintyA_createBetaDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createBetaDistribution() : NULL;
}


/*
 * Creates a new CauchyDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the CauchyDistribution_t object created.
 */
LIBSBML_EXTERN
CauchyDistribution_t*
UncertaintyA_createCauchyDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createCauchyDistribution() : NULL;
}


/*
 * Creates a new ChiSquareDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the ChiSquareDistribution_t object created.
 */
LIBSBML_EXTERN
ChiSquareDistribution_t*
UncertaintyA_createChiSquareDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createChiSquareDistribution() : NULL;
}


/*
 * Creates a new ExponentialDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the ExponentialDistribution_t object
 * created.
 */
LIBSBML_EXTERN
ExponentialDistribution_t*
UncertaintyA_createExponentialDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createExponentialDistribution() : NULL;
}


/*
 * Creates a new FDistribution_t object, adds it to this UncertaintyA_t object
 * and returns the FDistribution_t object created.
 */
LIBSBML_EXTERN
FDistribution_t*
UncertaintyA_createFDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createFDistribution() : NULL;
}


/*
 * Creates a new GammaDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the GammaDistribution_t object created.
 */
LIBSBML_EXTERN
GammaDistribution_t*
UncertaintyA_createGammaDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createGammaDistribution() : NULL;
}


/*
 * Creates a new InverseGammaDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the InverseGammaDistribution_t object
 * created.
 */
LIBSBML_EXTERN
InverseGammaDistribution_t*
UncertaintyA_createInverseGammaDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createInverseGammaDistribution() : NULL;
}


/*
 * Creates a new LaPlaceDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the LaPlaceDistribution_t object created.
 */
LIBSBML_EXTERN
LaPlaceDistribution_t*
UncertaintyA_createLaPlaceDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createLaPlaceDistribution() : NULL;
}


/*
 * Creates a new LogNormalDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the LogNormalDistribution_t object created.
 */
LIBSBML_EXTERN
LogNormalDistribution_t*
UncertaintyA_createLogNormalDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createLogNormalDistribution() : NULL;
}


/*
 * Creates a new LogisticDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the LogisticDistribution_t object created.
 */
LIBSBML_EXTERN
LogisticDistribution_t*
UncertaintyA_createLogisticDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createLogisticDistribution() : NULL;
}


/*
 * Creates a new NormalDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the NormalDistribution_t object created.
 */
LIBSBML_EXTERN
NormalDistribution_t*
UncertaintyA_createNormalDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createNormalDistribution() : NULL;
}


/*
 * Creates a new ParetoDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the ParetoDistribution_t object created.
 */
LIBSBML_EXTERN
ParetoDistribution_t*
UncertaintyA_createParetoDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createParetoDistribution() : NULL;
}


/*
 * Creates a new RayleighDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the RayleighDistribution_t object created.
 */
LIBSBML_EXTERN
RayleighDistribution_t*
UncertaintyA_createRayleighDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createRayleighDistribution() : NULL;
}


/*
 * Creates a new StudentTDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the StudentTDistribution_t object created.
 */
LIBSBML_EXTERN
StudentTDistribution_t*
UncertaintyA_createStudentTDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createStudentTDistribution() : NULL;
}


/*
 * Creates a new UniformDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the UniformDistribution_t object created.
 */
LIBSBML_EXTERN
UniformDistribution_t*
UncertaintyA_createUniformDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createUniformDistribution() : NULL;
}


/*
 * Creates a new WeibullDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the WeibullDistribution_t object created.
 */
LIBSBML_EXTERN
WeibullDistribution_t*
UncertaintyA_createWeibullDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createWeibullDistribution() : NULL;
}


/*
 * Creates a new BinomialDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the BinomialDistribution_t object created.
 */
LIBSBML_EXTERN
BinomialDistribution_t*
UncertaintyA_createBinomialDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createBinomialDistribution() : NULL;
}


/*
 * Creates a new GeometricDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the GeometricDistribution_t object created.
 */
LIBSBML_EXTERN
GeometricDistribution_t*
UncertaintyA_createGeometricDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createGeometricDistribution() : NULL;
}


/*
 * Creates a new HypergeometricDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the HypergeometricDistribution_t object
 * created.
 */
LIBSBML_EXTERN
HypergeometricDistribution_t*
UncertaintyA_createHypergeometricDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createHypergeometricDistribution() : NULL;
}


/*
 * Creates a new NegativeBinomialDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the NegativeBinomialDistribution_t object
 * created.
 */
LIBSBML_EXTERN
NegativeBinomialDistribution_t*
UncertaintyA_createNegativeBinomialDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createNegativeBinomialDistribution() : NULL;
}


/*
 * Creates a new PoissonDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the PoissonDistribution_t object created.
 */
LIBSBML_EXTERN
PoissonDistribution_t*
UncertaintyA_createPoissonDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createPoissonDistribution() : NULL;
}


/*
 * Creates a new BernoulliDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the BernoulliDistribution_t object created.
 */
LIBSBML_EXTERN
BernoulliDistribution_t*
UncertaintyA_createBernoulliDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createBernoulliDistribution() : NULL;
}


/*
 * Creates a new CategoricalDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the CategoricalDistribution_t object
 * created.
 */
LIBSBML_EXTERN
CategoricalDistribution_t*
UncertaintyA_createCategoricalDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createCategoricalDistribution() : NULL;
}


/*
 * Creates a new MultivariateDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the MultivariateDistribution_t object
 * created.
 */
LIBSBML_EXTERN
MultivariateDistribution_t*
UncertaintyA_createMultivariateDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createMultivariateDistribution() : NULL;
}


/*
 * Creates a new ExternalDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the ExternalDistribution_t object created.
 */
LIBSBML_EXTERN
ExternalDistribution_t*
UncertaintyA_createExternalDistribution(UncertaintyA_t* ua)
{
  return (ua != NULL) ? ua->createExternalDistribution() : NULL;
}


/*
 * Unsets the value of the "uncertStatistics" element of this UncertaintyA_t.
 */
LIBSBML_EXTERN
int
UncertaintyA_unsetUncertStatistics(UncertaintyA_t * ua)
{
  return (ua != NULL) ? ua->unsetUncertStatistics() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "distribution" element of this UncertaintyA_t.
 */
LIBSBML_EXTERN
int
UncertaintyA_unsetDistribution(UncertaintyA_t * ua)
{
  return (ua != NULL) ? ua->unsetDistribution() : LIBSBML_INVALID_OBJECT;
}




LIBSBML_CPP_NAMESPACE_END


