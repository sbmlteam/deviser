/**
 * @file DrawFromDistribution.cpp
 * @brief Implementation of the DrawFromDistribution class.
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
#include <sbml/packages/distrib/sbml/DrawFromDistribution.h>
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
 * Creates a new DrawFromDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
DrawFromDistribution::DrawFromDistribution(unsigned int level,
                                           unsigned int version,
                                           unsigned int pkgVersion)
  : SBase(level, version)
  , mDistribInputs (level, version, pkgVersion)
  , mDistribution (NULL)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new DrawFromDistribution using the given DistribPkgNamespaces
 * object.
 */
DrawFromDistribution::DrawFromDistribution(DistribPkgNamespaces *distribns)
  : SBase(distribns)
  , mDistribInputs (distribns)
  , mDistribution (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for DrawFromDistribution.
 */
DrawFromDistribution::DrawFromDistribution(const DrawFromDistribution& orig)
  : SBase( orig )
  , mDistribInputs ( orig.mDistribInputs )
  , mDistribution ( NULL )
{
  if (orig.mDistribution != NULL)
  {
    mDistribution = orig.mDistribution->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for DrawFromDistribution.
 */
DrawFromDistribution&
DrawFromDistribution::operator=(const DrawFromDistribution& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mDistribInputs = rhs.mDistribInputs;
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
 * Creates and returns a deep copy of this DrawFromDistribution object.
 */
DrawFromDistribution*
DrawFromDistribution::clone() const
{
  return new DrawFromDistribution(*this);
}


/*
 * Destructor for DrawFromDistribution.
 */
DrawFromDistribution::~DrawFromDistribution()
{
  delete mDistribution;
  mDistribution = NULL;
}


/*
 * Returns the value of the "distribution" element of this
 * DrawFromDistribution.
 */
const Distribution*
DrawFromDistribution::getDistribution() const
{
  return mDistribution;
}


/*
 * Returns the value of the "distribution" element of this
 * DrawFromDistribution.
 */
Distribution*
DrawFromDistribution::getDistribution()
{
  return mDistribution;
}


/*
 * Predicate returning @c true if this DrawFromDistribution's "distribution"
 * element is set.
 */
bool
DrawFromDistribution::isSetDistribution() const
{
  return (mDistribution != NULL);
}


/*
 * Sets the value of the "distribution" element of this DrawFromDistribution.
 */
int
DrawFromDistribution::setDistribution(const Distribution* distribution)
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
 * Creates a new BetaDistribution object, adds it to this DrawFromDistribution
 * object and returns the BetaDistribution object created.
 */
BetaDistribution*
DrawFromDistribution::createBetaDistribution()
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
 * Creates a new CauchyDistribution object, adds it to this
 * DrawFromDistribution object and returns the CauchyDistribution object
 * created.
 */
CauchyDistribution*
DrawFromDistribution::createCauchyDistribution()
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
 * Creates a new ExponentialDistribution object, adds it to this
 * DrawFromDistribution object and returns the ExponentialDistribution object
 * created.
 */
ExponentialDistribution*
DrawFromDistribution::createExponentialDistribution()
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
 * Creates a new LogisticDistribution object, adds it to this
 * DrawFromDistribution object and returns the LogisticDistribution object
 * created.
 */
LogisticDistribution*
DrawFromDistribution::createLogisticDistribution()
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
 * Creates a new NormalDistribution object, adds it to this
 * DrawFromDistribution object and returns the NormalDistribution object
 * created.
 */
NormalDistribution*
DrawFromDistribution::createNormalDistribution()
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
 * Creates a new BinomialDistribution object, adds it to this
 * DrawFromDistribution object and returns the BinomialDistribution object
 * created.
 */
BinomialDistribution*
DrawFromDistribution::createBinomialDistribution()
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
 * Creates a new GeometricDistribution object, adds it to this
 * DrawFromDistribution object and returns the GeometricDistribution object
 * created.
 */
GeometricDistribution*
DrawFromDistribution::createGeometricDistribution()
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
 * Creates a new BernoulliDistribution object, adds it to this
 * DrawFromDistribution object and returns the BernoulliDistribution object
 * created.
 */
BernoulliDistribution*
DrawFromDistribution::createBernoulliDistribution()
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
 * Creates a new CategoricalDistribution object, adds it to this
 * DrawFromDistribution object and returns the CategoricalDistribution object
 * created.
 */
CategoricalDistribution*
DrawFromDistribution::createCategoricalDistribution()
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
 * Creates a new MultivariateDistribution object, adds it to this
 * DrawFromDistribution object and returns the MultivariateDistribution object
 * created.
 */
MultivariateDistribution*
DrawFromDistribution::createMultivariateDistribution()
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
 * Creates a new ExternalDistribution object, adds it to this
 * DrawFromDistribution object and returns the ExternalDistribution object
 * created.
 */
ExternalDistribution*
DrawFromDistribution::createExternalDistribution()
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
 * Unsets the value of the "distribution" element of this DrawFromDistribution.
 */
int
DrawFromDistribution::unsetDistribution()
{
  delete mDistribution;
  mDistribution = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the ListOfDistribInputs from this DrawFromDistribution.
 */
const ListOfDistribInputs*
DrawFromDistribution::getListOfDistribInputs() const
{
  return &mDistribInputs;
}


/*
 * Returns the ListOfDistribInputs from this DrawFromDistribution.
 */
ListOfDistribInputs*
DrawFromDistribution::getListOfDistribInputs()
{
  return &mDistribInputs;
}


/*
 * Get a DistribInput from the DrawFromDistribution.
 */
DistribInput*
DrawFromDistribution::getDistribInput(unsigned int n)
{
  return mDistribInputs.get(n);
}


/*
 * Get a DistribInput from the DrawFromDistribution.
 */
const DistribInput*
DrawFromDistribution::getDistribInput(unsigned int n) const
{
  return mDistribInputs.get(n);
}


/*
 * Get a DistribInput from the DrawFromDistribution based on its identifier.
 */
DistribInput*
DrawFromDistribution::getDistribInput(const std::string& sid)
{
  return mDistribInputs.get(sid);
}


/*
 * Get a DistribInput from the DrawFromDistribution based on its identifier.
 */
const DistribInput*
DrawFromDistribution::getDistribInput(const std::string& sid) const
{
  return mDistribInputs.get(sid);
}


/*
 * Adds a copy of the given DistribInput to this DrawFromDistribution.
 */
int
DrawFromDistribution::addDistribInput(const DistribInput* di)
{
  if (di == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (di->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != di->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != di->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(di)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (di->isSetId() && (mDistribInputs.get(di->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mDistribInputs.append(di);
  }
}


/*
 * Get the number of DistribInput objects in this DrawFromDistribution.
 */
unsigned int
DrawFromDistribution::getNumDistribInputs() const
{
  return mDistribInputs.size();
}


/*
 * Creates a new DistribInput object, adds it to this DrawFromDistribution
 * object and returns the DistribInput object created.
 */
DistribInput*
DrawFromDistribution::createDistribInput()
{
  DistribInput* di = NULL;

  try
  {
    DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
    di = new DistribInput(distribns);
    delete distribns;
  }
  catch (...)
  {
  }

  if (di != NULL)
  {
    mDistribInputs.appendAndOwn(di);
  }

  return di;
}


/*
 * Removes the nth DistribInput from this DrawFromDistribution and returns a
 * pointer to it.
 */
DistribInput*
DrawFromDistribution::removeDistribInput(unsigned int n)
{
  return mDistribInputs.remove(n);
}


/*
 * Removes the DistribInput from this DrawFromDistribution based on its
 * identifier and returns a pointer to it.
 */
DistribInput*
DrawFromDistribution::removeDistribInput(const std::string& sid)
{
  return mDistribInputs.remove(sid);
}


/*
 * Returns the XML element name of this DrawFromDistribution object.
 */
const std::string&
DrawFromDistribution::getElementName() const
{
  static const string name = "drawFromDistribution";
  return name;
}


/*
 * Returns the libSBML type code for this DrawFromDistribution object.
 */
int
DrawFromDistribution::getTypeCode() const
{
  return SBML_DISTRIB_DRAWFROMDISTRIBUTION;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
DrawFromDistribution::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetDistribution() == true)
  {
    mDistribution->write(stream);
  }

  if (getNumDistribInputs() > 0)
  {
    mDistribInputs.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
DrawFromDistribution::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mDistribution != NULL)
  {
    mDistribution->accept(v);
  }

  mDistribInputs.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
DrawFromDistribution::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  if (mDistribution != NULL)
  {
    mDistribution->setSBMLDocument(d);
  }

  mDistribInputs.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
DrawFromDistribution::connectToChild()
{
  SBase::connectToChild();

  if (mDistribution != NULL)
  {
    mDistribution->connectToParent(this);
  }

  mDistribInputs.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
DrawFromDistribution::enablePackageInternal(const std::string& pkgURI,
                                            const std::string& pkgPrefix,
                                            bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetDistribution())
  {
    mDistribution->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  mDistribInputs.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
DrawFromDistribution::updateSBMLNamespace(const std::string& package,
                                          unsigned int level,
                                          unsigned int version)
{
  SBase::updateSBMLNamespace(package, level, version);

  if (mDistribution != NULL)
  {
    mDistribution->updateSBMLNamespace(package, level, version);
  }

  mDistribInputs.updateSBMLNamespace(package, level, version);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::getAttribute(const std::string& attributeName,
                                   bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::getAttribute(const std::string& attributeName,
                                   int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::getAttribute(const std::string& attributeName,
                                   double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::getAttribute(const std::string& attributeName,
                                   unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::getAttribute(const std::string& attributeName,
                                   std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this DrawFromDistribution's attribute
 * "attributeName" is set.
 */
bool
DrawFromDistribution::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::setAttribute(const std::string& attributeName,
                                   bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::setAttribute(const std::string& attributeName,
                                   int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::setAttribute(const std::string& attributeName,
                                   double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::setAttribute(const std::string& attributeName,
                                   unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::setAttribute(const std::string& attributeName,
                                   const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * DrawFromDistribution.
 */
int
DrawFromDistribution::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this
 * DrawFromDistribution.
 */
SBase*
DrawFromDistribution::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "betaDistribution")
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
  else if (elementName == "distribInput")
  {
    return createDistribInput();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this DrawFromDistribution.
 */
int
DrawFromDistribution::addChildObject(const std::string& elementName,
                                     const SBase* element)
{
  if (elementName == "betaDistribution" && element->getTypeCode() ==
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
  else if (elementName == "distribInput" && element->getTypeCode() ==
    SBML_DISTRIB_DISTRIBINPUT)
  {
    return addDistribInput((const DistribInput*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * DrawFromDistribution.
 */
SBase*
DrawFromDistribution::removeChildObject(const std::string& elementName,
                                        const std::string& id)
{
  if (elementName == "betaDistribution")
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
  else if (elementName == "distribInput")
  {
    return removeDistribInput(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this DrawFromDistribution.
 */
unsigned int
DrawFromDistribution::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "distribution")
  {
    if (isSetDistribution())
    {
      return 1;
    }
  }
  else if (elementName == "distribInput")
  {
    return getNumDistribInputs();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this DrawFromDistribution.
 */
SBase*
DrawFromDistribution::getObject(const std::string& elementName,
                                unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "distribution")
  {
    return getDistribution();
  }
  else if (elementName == "distribInput")
  {
    return getDistribInput(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
DrawFromDistribution::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

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

  obj = mDistribInputs.getElementBySId(id);

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
DrawFromDistribution::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

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

  if (mDistribInputs.getMetaId() == metaid)
  {
    return &mDistribInputs;
  }

  obj = mDistribInputs.getElementByMetaId(metaid);

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
DrawFromDistribution::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mDistribution, filter);

  ADD_FILTERED_LIST(ret, sublist, mDistribInputs, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
DrawFromDistribution::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());

  if (name == "betaDistribution")
  {
    if (isSetDistribution())
    {
      getErrorLog()->logPackageError("distrib",
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
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
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    delete mDistribution;
    mDistribution = new ExternalDistribution(distribns);
    obj = mDistribution;
  }

  if (name == "listOfDistribInputs")
  {
    if (mDistribInputs.size() != 0)
    {
      getErrorLog()->logPackageError("distrib",
        DistribDrawFromDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    obj = &mDistribInputs;
  }

  delete distribns;

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new DrawFromDistribution_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
DrawFromDistribution_t *
DrawFromDistribution_create(unsigned int level,
                            unsigned int version,
                            unsigned int pkgVersion)
{
  return new DrawFromDistribution(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this DrawFromDistribution_t object.
 */
LIBSBML_EXTERN
DrawFromDistribution_t*
DrawFromDistribution_clone(const DrawFromDistribution_t* dfd)
{
  if (dfd != NULL)
  {
    return static_cast<DrawFromDistribution_t*>(dfd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this DrawFromDistribution_t object.
 */
LIBSBML_EXTERN
void
DrawFromDistribution_free(DrawFromDistribution_t* dfd)
{
  if (dfd != NULL)
  {
    delete dfd;
  }
}


/*
 * Returns the value of the "distribution" element of this
 * DrawFromDistribution_t.
 */
LIBSBML_EXTERN
const Distribution_t*
DrawFromDistribution_getDistribution(const DrawFromDistribution_t * dfd)
{
  if (dfd == NULL)
  {
    return NULL;
  }

  return (Distribution_t*)(dfd->getDistribution());
}


/*
 * Predicate returning @c 1 (true) if this DrawFromDistribution_t's
 * "distribution" element is set.
 */
LIBSBML_EXTERN
int
DrawFromDistribution_isSetDistribution(const DrawFromDistribution_t * dfd)
{
  return (dfd != NULL) ? static_cast<int>(dfd->isSetDistribution()) : 0;
}


/*
 * Sets the value of the "distribution" element of this DrawFromDistribution_t.
 */
LIBSBML_EXTERN
int
DrawFromDistribution_setDistribution(DrawFromDistribution_t * dfd,
                                     const Distribution_t* distribution)
{
  return (dfd != NULL) ? dfd->setDistribution(distribution) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new BetaDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the BetaDistribution_t object
 * created.
 */
LIBSBML_EXTERN
BetaDistribution_t*
DrawFromDistribution_createBetaDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createBetaDistribution() : NULL;
}


/*
 * Creates a new CauchyDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the CauchyDistribution_t object
 * created.
 */
LIBSBML_EXTERN
CauchyDistribution_t*
DrawFromDistribution_createCauchyDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createCauchyDistribution() : NULL;
}


/*
 * Creates a new ExponentialDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the ExponentialDistribution_t
 * object created.
 */
LIBSBML_EXTERN
ExponentialDistribution_t*
DrawFromDistribution_createExponentialDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createExponentialDistribution() : NULL;
}


/*
 * Creates a new LogisticDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the LogisticDistribution_t object
 * created.
 */
LIBSBML_EXTERN
LogisticDistribution_t*
DrawFromDistribution_createLogisticDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createLogisticDistribution() : NULL;
}


/*
 * Creates a new NormalDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the NormalDistribution_t object
 * created.
 */
LIBSBML_EXTERN
NormalDistribution_t*
DrawFromDistribution_createNormalDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createNormalDistribution() : NULL;
}


/*
 * Creates a new BinomialDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the BinomialDistribution_t object
 * created.
 */
LIBSBML_EXTERN
BinomialDistribution_t*
DrawFromDistribution_createBinomialDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createBinomialDistribution() : NULL;
}


/*
 * Creates a new GeometricDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the GeometricDistribution_t object
 * created.
 */
LIBSBML_EXTERN
GeometricDistribution_t*
DrawFromDistribution_createGeometricDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createGeometricDistribution() : NULL;
}


/*
 * Creates a new BernoulliDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the BernoulliDistribution_t object
 * created.
 */
LIBSBML_EXTERN
BernoulliDistribution_t*
DrawFromDistribution_createBernoulliDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createBernoulliDistribution() : NULL;
}


/*
 * Creates a new CategoricalDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the CategoricalDistribution_t
 * object created.
 */
LIBSBML_EXTERN
CategoricalDistribution_t*
DrawFromDistribution_createCategoricalDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createCategoricalDistribution() : NULL;
}


/*
 * Creates a new MultivariateDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the MultivariateDistribution_t
 * object created.
 */
LIBSBML_EXTERN
MultivariateDistribution_t*
DrawFromDistribution_createMultivariateDistribution(DrawFromDistribution_t*
  dfd)
{
  return (dfd != NULL) ? dfd->createMultivariateDistribution() : NULL;
}


/*
 * Creates a new ExternalDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the ExternalDistribution_t object
 * created.
 */
LIBSBML_EXTERN
ExternalDistribution_t*
DrawFromDistribution_createExternalDistribution(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createExternalDistribution() : NULL;
}


/*
 * Unsets the value of the "distribution" element of this
 * DrawFromDistribution_t.
 */
LIBSBML_EXTERN
int
DrawFromDistribution_unsetDistribution(DrawFromDistribution_t * dfd)
{
  return (dfd != NULL) ? dfd->unsetDistribution() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing DistribInput_t objects from this
 * DrawFromDistribution_t.
 */
LIBSBML_EXTERN
ListOf_t*
DrawFromDistribution_getListOfDistribInputs(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->getListOfDistribInputs() : NULL;
}


/*
 * Get a DistribInput_t from the DrawFromDistribution_t.
 */
LIBSBML_EXTERN
DistribInput_t*
DrawFromDistribution_getDistribInput(DrawFromDistribution_t* dfd,
                                     unsigned int n)
{
  return (dfd != NULL) ? dfd->getDistribInput(n) : NULL;
}


/*
 * Get a DistribInput_t from the DrawFromDistribution_t based on its
 * identifier.
 */
LIBSBML_EXTERN
DistribInput_t*
DrawFromDistribution_getDistribInputById(DrawFromDistribution_t* dfd,
                                         const char *sid)
{
  return (dfd != NULL && sid != NULL) ? dfd->getDistribInput(sid) : NULL;
}


/*
 * Adds a copy of the given DistribInput_t to this DrawFromDistribution_t.
 */
LIBSBML_EXTERN
int
DrawFromDistribution_addDistribInput(DrawFromDistribution_t* dfd,
                                     const DistribInput_t* di)
{
  return (dfd != NULL) ? dfd->addDistribInput(di) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of DistribInput_t objects in this DrawFromDistribution_t.
 */
LIBSBML_EXTERN
unsigned int
DrawFromDistribution_getNumDistribInputs(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->getNumDistribInputs() : SBML_INT_MAX;
}


/*
 * Creates a new DistribInput_t object, adds it to this DrawFromDistribution_t
 * object and returns the DistribInput_t object created.
 */
LIBSBML_EXTERN
DistribInput_t*
DrawFromDistribution_createDistribInput(DrawFromDistribution_t* dfd)
{
  return (dfd != NULL) ? dfd->createDistribInput() : NULL;
}


/*
 * Removes the nth DistribInput_t from this DrawFromDistribution_t and returns
 * a pointer to it.
 */
LIBSBML_EXTERN
DistribInput_t*
DrawFromDistribution_removeDistribInput(DrawFromDistribution_t* dfd,
                                        unsigned int n)
{
  return (dfd != NULL) ? dfd->removeDistribInput(n) : NULL;
}


/*
 * Removes the DistribInput_t from this DrawFromDistribution_t based on its
 * identifier and returns a pointer to it.
 */
LIBSBML_EXTERN
DistribInput_t*
DrawFromDistribution_removeDistribInputById(DrawFromDistribution_t* dfd,
                                            const char* sid)
{
  return (dfd != NULL && sid != NULL) ? dfd->removeDistribInput(sid) : NULL;
}




LIBSBML_CPP_NAMESPACE_END


