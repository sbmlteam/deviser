/**
 * @file BinomialDistribution.cpp
 * @brief Implementation of the BinomialDistribution class.
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
#include <sbml/packages/distrib/sbml/BinomialDistribution.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new BinomialDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
BinomialDistribution::BinomialDistribution(unsigned int level,
                                           unsigned int version,
                                           unsigned int pkgVersion)
  : DiscreteUnivariateDistribution(level, version, pkgVersion)
  , mNumberOfTrials (NULL)
  , mProbabilityOfSuccess (NULL)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new BinomialDistribution using the given DistribPkgNamespaces
 * object.
 */
BinomialDistribution::BinomialDistribution(DistribPkgNamespaces *distribns)
  : DiscreteUnivariateDistribution(distribns)
  , mNumberOfTrials (NULL)
  , mProbabilityOfSuccess (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for BinomialDistribution.
 */
BinomialDistribution::BinomialDistribution(const BinomialDistribution& orig)
  : DiscreteUnivariateDistribution( orig )
  , mNumberOfTrials ( NULL )
  , mProbabilityOfSuccess ( NULL )
{
  if (orig.mNumberOfTrials != NULL)
  {
    mNumberOfTrials = orig.mNumberOfTrials->clone();
  }

  if (orig.mProbabilityOfSuccess != NULL)
  {
    mProbabilityOfSuccess = orig.mProbabilityOfSuccess->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for BinomialDistribution.
 */
BinomialDistribution&
BinomialDistribution::operator=(const BinomialDistribution& rhs)
{
  if (&rhs != this)
  {
    DiscreteUnivariateDistribution::operator=(rhs);
    delete mNumberOfTrials;
    if (rhs.mNumberOfTrials != NULL)
    {
      mNumberOfTrials = rhs.mNumberOfTrials->clone();
    }
    else
    {
      mNumberOfTrials = NULL;
    }

    delete mProbabilityOfSuccess;
    if (rhs.mProbabilityOfSuccess != NULL)
    {
      mProbabilityOfSuccess = rhs.mProbabilityOfSuccess->clone();
    }
    else
    {
      mProbabilityOfSuccess = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this BinomialDistribution object.
 */
BinomialDistribution*
BinomialDistribution::clone() const
{
  return new BinomialDistribution(*this);
}


/*
 * Destructor for BinomialDistribution.
 */
BinomialDistribution::~BinomialDistribution()
{
  delete mNumberOfTrials;
  mNumberOfTrials = NULL;
  delete mProbabilityOfSuccess;
  mProbabilityOfSuccess = NULL;
}


/*
 * Returns the value of the "numberOfTrials" element of this
 * BinomialDistribution.
 */
const UncertValue*
BinomialDistribution::getNumberOfTrials() const
{
  return mNumberOfTrials;
}


/*
 * Returns the value of the "numberOfTrials" element of this
 * BinomialDistribution.
 */
UncertValue*
BinomialDistribution::getNumberOfTrials()
{
  return mNumberOfTrials;
}


/*
 * Returns the value of the "probabilityOfSuccess" element of this
 * BinomialDistribution.
 */
const UncertValue*
BinomialDistribution::getProbabilityOfSuccess() const
{
  return mProbabilityOfSuccess;
}


/*
 * Returns the value of the "probabilityOfSuccess" element of this
 * BinomialDistribution.
 */
UncertValue*
BinomialDistribution::getProbabilityOfSuccess()
{
  return mProbabilityOfSuccess;
}


/*
 * Predicate returning @c true if this BinomialDistribution's "numberOfTrials"
 * element is set.
 */
bool
BinomialDistribution::isSetNumberOfTrials() const
{
  return (mNumberOfTrials != NULL);
}


/*
 * Predicate returning @c true if this BinomialDistribution's
 * "probabilityOfSuccess" element is set.
 */
bool
BinomialDistribution::isSetProbabilityOfSuccess() const
{
  return (mProbabilityOfSuccess != NULL);
}


/*
 * Sets the value of the "numberOfTrials" element of this BinomialDistribution.
 */
int
BinomialDistribution::setNumberOfTrials(const UncertValue* numberOfTrials)
{
  if (mNumberOfTrials == numberOfTrials)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (numberOfTrials == NULL)
  {
    delete mNumberOfTrials;
    mNumberOfTrials = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mNumberOfTrials;
    mNumberOfTrials = (numberOfTrials != NULL) ? numberOfTrials->clone() :
      NULL;
    if (mNumberOfTrials != NULL)
    {
      mNumberOfTrials->setElementName("numberOfTrials");
      mNumberOfTrials->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "probabilityOfSuccess" element of this
 * BinomialDistribution.
 */
int
BinomialDistribution::setProbabilityOfSuccess(const UncertValue*
  probabilityOfSuccess)
{
  if (mProbabilityOfSuccess == probabilityOfSuccess)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (probabilityOfSuccess == NULL)
  {
    delete mProbabilityOfSuccess;
    mProbabilityOfSuccess = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mProbabilityOfSuccess;
    mProbabilityOfSuccess = (probabilityOfSuccess != NULL) ?
      probabilityOfSuccess->clone() : NULL;
    if (mProbabilityOfSuccess != NULL)
    {
      mProbabilityOfSuccess->setElementName("probabilityOfSuccess");
      mProbabilityOfSuccess->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new UncertValue object, adds it to this BinomialDistribution
 * object and returns the UncertValue object created.
 */
UncertValue*
BinomialDistribution::createNumberOfTrials()
{
  if (mNumberOfTrials != NULL)
  {
    delete mNumberOfTrials;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mNumberOfTrials = new UncertValue(distribns);

  mNumberOfTrials->setElementName("numberOfTrials");

  delete distribns;

  connectToChild();

  return mNumberOfTrials;
}


/*
 * Creates a new UncertValue object, adds it to this BinomialDistribution
 * object and returns the UncertValue object created.
 */
UncertValue*
BinomialDistribution::createProbabilityOfSuccess()
{
  if (mProbabilityOfSuccess != NULL)
  {
    delete mProbabilityOfSuccess;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mProbabilityOfSuccess = new UncertValue(distribns);

  mProbabilityOfSuccess->setElementName("probabilityOfSuccess");

  delete distribns;

  connectToChild();

  return mProbabilityOfSuccess;
}


/*
 * Unsets the value of the "numberOfTrials" element of this
 * BinomialDistribution.
 */
int
BinomialDistribution::unsetNumberOfTrials()
{
  delete mNumberOfTrials;
  mNumberOfTrials = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "probabilityOfSuccess" element of this
 * BinomialDistribution.
 */
int
BinomialDistribution::unsetProbabilityOfSuccess()
{
  delete mProbabilityOfSuccess;
  mProbabilityOfSuccess = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this BinomialDistribution object.
 */
const std::string&
BinomialDistribution::getElementName() const
{
  static const string name = "binomialDistribution";
  return name;
}


/*
 * Returns the libSBML type code for this BinomialDistribution object.
 */
int
BinomialDistribution::getTypeCode() const
{
  return SBML_DISTRIB_BINOMIALDISTRIBUTION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * BinomialDistribution object have been set.
 */
bool
BinomialDistribution::hasRequiredAttributes() const
{
  bool allPresent = DiscreteUnivariateDistribution::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * BinomialDistribution object have been set.
 */
bool
BinomialDistribution::hasRequiredElements() const
{
  bool allPresent = DiscreteUnivariateDistribution::hasRequiredElements();

  if (isSetNumberOfTrials() == false)
  {
    allPresent = false;
  }

  if (isSetProbabilityOfSuccess() == false)
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
BinomialDistribution::writeElements(XMLOutputStream& stream) const
{
  DiscreteUnivariateDistribution::writeElements(stream);

  if (isSetNumberOfTrials() == true)
  {
    mNumberOfTrials->write(stream);
  }

  if (isSetProbabilityOfSuccess() == true)
  {
    mProbabilityOfSuccess->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
BinomialDistribution::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mNumberOfTrials != NULL)
  {
    mNumberOfTrials->accept(v);
  }

  if (mProbabilityOfSuccess != NULL)
  {
    mProbabilityOfSuccess->accept(v);
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
BinomialDistribution::setSBMLDocument(SBMLDocument* d)
{
  DiscreteUnivariateDistribution::setSBMLDocument(d);

  if (mNumberOfTrials != NULL)
  {
    mNumberOfTrials->setSBMLDocument(d);
  }

  if (mProbabilityOfSuccess != NULL)
  {
    mProbabilityOfSuccess->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
BinomialDistribution::connectToChild()
{
  DiscreteUnivariateDistribution::connectToChild();

  if (mNumberOfTrials != NULL)
  {
    mNumberOfTrials->connectToParent(this);
  }

  if (mProbabilityOfSuccess != NULL)
  {
    mProbabilityOfSuccess->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
BinomialDistribution::enablePackageInternal(const std::string& pkgURI,
                                            const std::string& pkgPrefix,
                                            bool flag)
{
  DiscreteUnivariateDistribution::enablePackageInternal(pkgURI, pkgPrefix,
    flag);

  if (isSetNumberOfTrials())
  {
    mNumberOfTrials->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetProbabilityOfSuccess())
  {
    mProbabilityOfSuccess->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
BinomialDistribution::updateSBMLNamespace(const std::string& package,
                                          unsigned int level,
                                          unsigned int version)
{
  DiscreteUnivariateDistribution::updateSBMLNamespace(package, level, version);

  if (mNumberOfTrials != NULL)
  {
    mNumberOfTrials->updateSBMLNamespace(package, level, version);
  }

  if (mProbabilityOfSuccess != NULL)
  {
    mProbabilityOfSuccess->updateSBMLNamespace(package, level, version);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::getAttribute(const std::string& attributeName,
                                   bool& value) const
{
  int return_value =
    DiscreteUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::getAttribute(const std::string& attributeName,
                                   int& value) const
{
  int return_value =
    DiscreteUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::getAttribute(const std::string& attributeName,
                                   double& value) const
{
  int return_value =
    DiscreteUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::getAttribute(const std::string& attributeName,
                                   unsigned int& value) const
{
  int return_value =
    DiscreteUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::getAttribute(const std::string& attributeName,
                                   std::string& value) const
{
  int return_value =
    DiscreteUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this BinomialDistribution's attribute
 * "attributeName" is set.
 */
bool
BinomialDistribution::isSetAttribute(const std::string& attributeName) const
{
  bool value = DiscreteUnivariateDistribution::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::setAttribute(const std::string& attributeName,
                                   bool value)
{
  int return_value =
    DiscreteUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::setAttribute(const std::string& attributeName,
                                   int value)
{
  int return_value =
    DiscreteUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::setAttribute(const std::string& attributeName,
                                   double value)
{
  int return_value =
    DiscreteUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::setAttribute(const std::string& attributeName,
                                   unsigned int value)
{
  int return_value =
    DiscreteUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::setAttribute(const std::string& attributeName,
                                   const std::string& value)
{
  int return_value =
    DiscreteUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * BinomialDistribution.
 */
int
BinomialDistribution::unsetAttribute(const std::string& attributeName)
{
  int value = DiscreteUnivariateDistribution::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this
 * BinomialDistribution.
 */
SBase*
BinomialDistribution::createChildObject(const std::string& elementName)
{
  DiscreteUnivariateDistribution* obj = NULL;

  if (elementName == "numberOfTrials")
  {
    return createNumberOfTrials();
  }
  else if (elementName == "probabilityOfSuccess")
  {
    return createProbabilityOfSuccess();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this BinomialDistribution.
 */
int
BinomialDistribution::addChildObject(const std::string& elementName,
                                     const SBase* element)
{
  if (elementName == "numberOfTrials" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTVALUE)
  {
    return setNumberOfTrials((const UncertValue*)(element));
  }
  else if (elementName == "probabilityOfSuccess" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTVALUE)
  {
    return setProbabilityOfSuccess((const UncertValue*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * BinomialDistribution.
 */
SBase*
BinomialDistribution::removeChildObject(const std::string& elementName,
                                        const std::string& id)
{
  if (elementName == "numberOfTrials")
  {
    UncertValue * obj = getNumberOfTrials();
    if (unsetNumberOfTrials() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "probabilityOfSuccess")
  {
    UncertValue * obj = getProbabilityOfSuccess();
    if (unsetProbabilityOfSuccess() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this BinomialDistribution.
 */
unsigned int
BinomialDistribution::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "numberOfTrials")
  {
    if (isSetNumberOfTrials())
    {
      return 1;
    }
  }
  else if (elementName == "probabilityOfSuccess")
  {
    if (isSetProbabilityOfSuccess())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this BinomialDistribution.
 */
SBase*
BinomialDistribution::getObject(const std::string& elementName,
                                unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "numberOfTrials")
  {
    return getNumberOfTrials();
  }
  else if (elementName == "probabilityOfSuccess")
  {
    return getProbabilityOfSuccess();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
BinomialDistribution::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mNumberOfTrials != NULL)
  {
    if (mNumberOfTrials->getId() == id)
    {
      return mNumberOfTrials;
    }

    obj = mNumberOfTrials->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mProbabilityOfSuccess != NULL)
  {
    if (mProbabilityOfSuccess->getId() == id)
    {
      return mProbabilityOfSuccess;
    }

    obj = mProbabilityOfSuccess->getElementBySId(id);
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
BinomialDistribution::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mNumberOfTrials != NULL)
  {
    if (mNumberOfTrials->getMetaId() == metaid)
    {
      return mNumberOfTrials;
    }

    obj = mNumberOfTrials->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mProbabilityOfSuccess != NULL)
  {
    if (mProbabilityOfSuccess->getMetaId() == metaid)
    {
      return mProbabilityOfSuccess;
    }

    obj = mProbabilityOfSuccess->getElementByMetaId(metaid);
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
BinomialDistribution::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mNumberOfTrials, filter);
  ADD_FILTERED_POINTER(ret, sublist, mProbabilityOfSuccess, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
BinomialDistribution::createObject(XMLInputStream& stream)
{
  SBase* obj = DiscreteUnivariateDistribution::createObject(stream);

  const std::string& name = stream.peek().getName();

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());

  if (name == "numberOfTrials")
  {
    if (isSetNumberOfTrials())
    {
      getErrorLog()->logPackageError("distrib",
        DistribBinomialDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    delete mNumberOfTrials;
    mNumberOfTrials = new UncertValue(distribns);
    mNumberOfTrials->setElementName(name);
    obj = mNumberOfTrials;
  }
  else if (name == "probabilityOfSuccess")
  {
    if (isSetProbabilityOfSuccess())
    {
      getErrorLog()->logPackageError("distrib",
        DistribBinomialDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    delete mProbabilityOfSuccess;
    mProbabilityOfSuccess = new UncertValue(distribns);
    mProbabilityOfSuccess->setElementName(name);
    obj = mProbabilityOfSuccess;
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
BinomialDistribution::addExpectedAttributes(ExpectedAttributes& attributes)
{
  DiscreteUnivariateDistribution::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
BinomialDistribution::readAttributes(const XMLAttributes& attributes,
                                     const ExpectedAttributes&
                                       expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  DiscreteUnivariateDistribution::readAttributes(attributes,
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
          DistribBinomialDistributionAllowedAttributes, pkgVersion, level,
            version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("distrib",
          DistribBinomialDistributionAllowedCoreAttributes, pkgVersion, level,
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
BinomialDistribution::writeAttributes(XMLOutputStream& stream) const
{
  DiscreteUnivariateDistribution::writeAttributes(stream);

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new BinomialDistribution_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
BinomialDistribution_t *
BinomialDistribution_create(unsigned int level,
                            unsigned int version,
                            unsigned int pkgVersion)
{
  return new BinomialDistribution(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this BinomialDistribution_t object.
 */
LIBSBML_EXTERN
BinomialDistribution_t*
BinomialDistribution_clone(const BinomialDistribution_t* bd)
{
  if (bd != NULL)
  {
    return static_cast<BinomialDistribution_t*>(bd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this BinomialDistribution_t object.
 */
LIBSBML_EXTERN
void
BinomialDistribution_free(BinomialDistribution_t* bd)
{
  if (bd != NULL)
  {
    delete bd;
  }
}


/*
 * Returns the value of the "numberOfTrials" element of this
 * BinomialDistribution_t.
 */
LIBSBML_EXTERN
const UncertValue_t*
BinomialDistribution_getNumberOfTrials(const BinomialDistribution_t * bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->getNumberOfTrials());
}


/*
 * Returns the value of the "probabilityOfSuccess" element of this
 * BinomialDistribution_t.
 */
LIBSBML_EXTERN
const UncertValue_t*
BinomialDistribution_getProbabilityOfSuccess(const BinomialDistribution_t * bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->getProbabilityOfSuccess());
}


/*
 * Predicate returning @c 1 (true) if this BinomialDistribution_t's
 * "numberOfTrials" element is set.
 */
LIBSBML_EXTERN
int
BinomialDistribution_isSetNumberOfTrials(const BinomialDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->isSetNumberOfTrials()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this BinomialDistribution_t's
 * "probabilityOfSuccess" element is set.
 */
LIBSBML_EXTERN
int
BinomialDistribution_isSetProbabilityOfSuccess(const BinomialDistribution_t *
  bd)
{
  return (bd != NULL) ? static_cast<int>(bd->isSetProbabilityOfSuccess()) : 0;
}


/*
 * Sets the value of the "numberOfTrials" element of this
 * BinomialDistribution_t.
 */
LIBSBML_EXTERN
int
BinomialDistribution_setNumberOfTrials(BinomialDistribution_t * bd,
                                       const UncertValue_t* numberOfTrials)
{
  return (bd != NULL) ? bd->setNumberOfTrials(numberOfTrials) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "probabilityOfSuccess" element of this
 * BinomialDistribution_t.
 */
LIBSBML_EXTERN
int
BinomialDistribution_setProbabilityOfSuccess(BinomialDistribution_t * bd,
                                             const UncertValue_t*
                                               probabilityOfSuccess)
{
  return (bd != NULL) ? bd->setProbabilityOfSuccess(probabilityOfSuccess) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new UncertValue_t object, adds it to this BinomialDistribution_t
 * object and returns the UncertValue_t object created.
 */
LIBSBML_EXTERN
UncertValue_t*
BinomialDistribution_createNumberOfTrials(BinomialDistribution_t* bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->createNumberOfTrials());
}


/*
 * Creates a new UncertValue_t object, adds it to this BinomialDistribution_t
 * object and returns the UncertValue_t object created.
 */
LIBSBML_EXTERN
UncertValue_t*
BinomialDistribution_createProbabilityOfSuccess(BinomialDistribution_t* bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->createProbabilityOfSuccess());
}


/*
 * Unsets the value of the "numberOfTrials" element of this
 * BinomialDistribution_t.
 */
LIBSBML_EXTERN
int
BinomialDistribution_unsetNumberOfTrials(BinomialDistribution_t * bd)
{
  return (bd != NULL) ? bd->unsetNumberOfTrials() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "probabilityOfSuccess" element of this
 * BinomialDistribution_t.
 */
LIBSBML_EXTERN
int
BinomialDistribution_unsetProbabilityOfSuccess(BinomialDistribution_t * bd)
{
  return (bd != NULL) ? bd->unsetProbabilityOfSuccess() :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * BinomialDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
BinomialDistribution_hasRequiredAttributes(const BinomialDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * BinomialDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
BinomialDistribution_hasRequiredElements(const BinomialDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


