/**
 * @file ExponentialDistribution.cpp
 * @brief Implementation of the ExponentialDistribution class.
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
#include <sbml/packages/distrib/sbml/ExponentialDistribution.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ExponentialDistribution using the given SBML Level, Version
 * and &ldquo;distrib&rdquo; package version.
 */
ExponentialDistribution::ExponentialDistribution(unsigned int level,
                                                 unsigned int version,
                                                 unsigned int pkgVersion)
  : ContinuousUnivariateDistribution(level, version, pkgVersion)
  , mRate (NULL)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new ExponentialDistribution using the given DistribPkgNamespaces
 * object.
 */
ExponentialDistribution::ExponentialDistribution(DistribPkgNamespaces
  *distribns)
  : ContinuousUnivariateDistribution(distribns)
  , mRate (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for ExponentialDistribution.
 */
ExponentialDistribution::ExponentialDistribution(const ExponentialDistribution&
  orig)
  : ContinuousUnivariateDistribution( orig )
  , mRate ( NULL )
{
  if (orig.mRate != NULL)
  {
    mRate = orig.mRate->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for ExponentialDistribution.
 */
ExponentialDistribution&
ExponentialDistribution::operator=(const ExponentialDistribution& rhs)
{
  if (&rhs != this)
  {
    ContinuousUnivariateDistribution::operator=(rhs);
    delete mRate;
    if (rhs.mRate != NULL)
    {
      mRate = rhs.mRate->clone();
    }
    else
    {
      mRate = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ExponentialDistribution object.
 */
ExponentialDistribution*
ExponentialDistribution::clone() const
{
  return new ExponentialDistribution(*this);
}


/*
 * Destructor for ExponentialDistribution.
 */
ExponentialDistribution::~ExponentialDistribution()
{
  delete mRate;
  mRate = NULL;
}


/*
 * Returns the value of the "rate" element of this ExponentialDistribution.
 */
const UncertValue*
ExponentialDistribution::getRate() const
{
  return mRate;
}


/*
 * Returns the value of the "rate" element of this ExponentialDistribution.
 */
UncertValue*
ExponentialDistribution::getRate()
{
  return mRate;
}


/*
 * Predicate returning @c true if this ExponentialDistribution's "rate" element
 * is set.
 */
bool
ExponentialDistribution::isSetRate() const
{
  return (mRate != NULL);
}


/*
 * Sets the value of the "rate" element of this ExponentialDistribution.
 */
int
ExponentialDistribution::setRate(const UncertValue* rate)
{
  if (mRate == rate)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (rate == NULL)
  {
    delete mRate;
    mRate = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mRate;
    mRate = (rate != NULL) ? rate->clone() : NULL;
    if (mRate != NULL)
    {
      mRate->setElementName("rate");
      mRate->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new UncertValue object, adds it to this ExponentialDistribution
 * object and returns the UncertValue object created.
 */
UncertValue*
ExponentialDistribution::createRate()
{
  if (mRate != NULL)
  {
    delete mRate;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mRate = new UncertValue(distribns);

  mRate->setElementName("rate");

  delete distribns;

  connectToChild();

  return mRate;
}


/*
 * Unsets the value of the "rate" element of this ExponentialDistribution.
 */
int
ExponentialDistribution::unsetRate()
{
  delete mRate;
  mRate = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this ExponentialDistribution object.
 */
const std::string&
ExponentialDistribution::getElementName() const
{
  static const string name = "exponentialDistribution";
  return name;
}


/*
 * Returns the libSBML type code for this ExponentialDistribution object.
 */
int
ExponentialDistribution::getTypeCode() const
{
  return SBML_DISTRIB_EXPONENTIALDISTRIBUTION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * ExponentialDistribution object have been set.
 */
bool
ExponentialDistribution::hasRequiredAttributes() const
{
  bool allPresent = ContinuousUnivariateDistribution::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * ExponentialDistribution object have been set.
 */
bool
ExponentialDistribution::hasRequiredElements() const
{
  bool allPresent = ContinuousUnivariateDistribution::hasRequiredElements();

  if (isSetRate() == false)
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
ExponentialDistribution::writeElements(XMLOutputStream& stream) const
{
  ContinuousUnivariateDistribution::writeElements(stream);

  if (isSetRate() == true)
  {
    mRate->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
ExponentialDistribution::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mRate != NULL)
  {
    mRate->accept(v);
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
ExponentialDistribution::setSBMLDocument(SBMLDocument* d)
{
  ContinuousUnivariateDistribution::setSBMLDocument(d);

  if (mRate != NULL)
  {
    mRate->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
ExponentialDistribution::connectToChild()
{
  ContinuousUnivariateDistribution::connectToChild();

  if (mRate != NULL)
  {
    mRate->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
ExponentialDistribution::enablePackageInternal(const std::string& pkgURI,
                                               const std::string& pkgPrefix,
                                               bool flag)
{
  ContinuousUnivariateDistribution::enablePackageInternal(pkgURI, pkgPrefix,
    flag);

  if (isSetRate())
  {
    mRate->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
ExponentialDistribution::updateSBMLNamespace(const std::string& package,
                                             unsigned int level,
                                             unsigned int version)
{
  ContinuousUnivariateDistribution::updateSBMLNamespace(package, level,
    version);

  if (mRate != NULL)
  {
    mRate->updateSBMLNamespace(package, level, version);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::getAttribute(const std::string& attributeName,
                                      bool& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::getAttribute(const std::string& attributeName,
                                      int& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::getAttribute(const std::string& attributeName,
                                      double& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::getAttribute(const std::string& attributeName,
                                      unsigned int& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::getAttribute(const std::string& attributeName,
                                      std::string& value) const
{
  int return_value =
    ContinuousUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this ExponentialDistribution's attribute
 * "attributeName" is set.
 */
bool
ExponentialDistribution::isSetAttribute(const std::string& attributeName) const
{
  bool value = ContinuousUnivariateDistribution::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::setAttribute(const std::string& attributeName,
                                      bool value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::setAttribute(const std::string& attributeName,
                                      int value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::setAttribute(const std::string& attributeName,
                                      double value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::setAttribute(const std::string& attributeName,
                                      unsigned int value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::setAttribute(const std::string& attributeName,
                                      const std::string& value)
{
  int return_value =
    ContinuousUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * ExponentialDistribution.
 */
int
ExponentialDistribution::unsetAttribute(const std::string& attributeName)
{
  int value = ContinuousUnivariateDistribution::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this
 * ExponentialDistribution.
 */
SBase*
ExponentialDistribution::createChildObject(const std::string& elementName)
{
  ContinuousUnivariateDistribution* obj = NULL;

  if (elementName == "rate")
  {
    return createRate();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this ExponentialDistribution.
 */
int
ExponentialDistribution::addChildObject(const std::string& elementName,
                                        const SBase* element)
{
  if (elementName == "rate" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTVALUE)
  {
    return setRate((const UncertValue*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * ExponentialDistribution.
 */
SBase*
ExponentialDistribution::removeChildObject(const std::string& elementName,
                                           const std::string& id)
{
  if (elementName == "rate")
  {
    UncertValue * obj = mRate;
    mRate = NULL; return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this ExponentialDistribution.
 */
unsigned int
ExponentialDistribution::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "rate")
  {
    if (isSetRate())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this ExponentialDistribution.
 */
SBase*
ExponentialDistribution::getObject(const std::string& elementName,
                                   unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "rate")
  {
    return getRate();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
ExponentialDistribution::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mRate != NULL)
  {
    if (mRate->getId() == id)
    {
      return mRate;
    }

    obj = mRate->getElementBySId(id);
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
ExponentialDistribution::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mRate != NULL)
  {
    if (mRate->getMetaId() == metaid)
    {
      return mRate;
    }

    obj = mRate->getElementByMetaId(metaid);
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
ExponentialDistribution::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mRate, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
ExponentialDistribution::createObject(XMLInputStream& stream)
{
  SBase* obj = ContinuousUnivariateDistribution::createObject(stream);

  const std::string& name = stream.peek().getName();

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());

  if (name == "rate")
  {
    if (getErrorLog() && isSetRate())
    {
      getErrorLog()->logPackageError("distrib",
        DistribExponentialDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion(), "", getLine(), getColumn());
    }

    delete mRate;
    mRate = new UncertValue(distribns);
    mRate->setElementName(name);
    obj = mRate;
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
ExponentialDistribution::addExpectedAttributes(ExpectedAttributes& attributes)
{
  ContinuousUnivariateDistribution::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ExponentialDistribution::readAttributes(const XMLAttributes& attributes,
                                        const ExpectedAttributes&
                                          expectedAttributes)
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
          DistribExponentialDistributionAllowedAttributes, pkgVersion, level,
            version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("distrib",
          DistribExponentialDistributionAllowedCoreAttributes, pkgVersion, level,
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
ExponentialDistribution::writeAttributes(XMLOutputStream& stream) const
{
  ContinuousUnivariateDistribution::writeAttributes(stream);

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ExponentialDistribution_t using the given SBML Level, Version
 * and &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
ExponentialDistribution_t *
ExponentialDistribution_create(unsigned int level,
                               unsigned int version,
                               unsigned int pkgVersion)
{
  return new ExponentialDistribution(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ExponentialDistribution_t object.
 */
LIBSBML_EXTERN
ExponentialDistribution_t*
ExponentialDistribution_clone(const ExponentialDistribution_t* ed)
{
  if (ed != NULL)
  {
    return static_cast<ExponentialDistribution_t*>(ed->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ExponentialDistribution_t object.
 */
LIBSBML_EXTERN
void
ExponentialDistribution_free(ExponentialDistribution_t* ed)
{
  if (ed != NULL)
  {
    delete ed;
  }
}


/*
 * Returns the value of the "rate" element of this ExponentialDistribution_t.
 */
LIBSBML_EXTERN
const UncertValue_t*
ExponentialDistribution_getRate(const ExponentialDistribution_t * ed)
{
  if (ed == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(ed->getRate());
}


/*
 * Predicate returning @c 1 (true) if this ExponentialDistribution_t's "rate"
 * element is set.
 */
LIBSBML_EXTERN
int
ExponentialDistribution_isSetRate(const ExponentialDistribution_t * ed)
{
  return (ed != NULL) ? static_cast<int>(ed->isSetRate()) : 0;
}


/*
 * Sets the value of the "rate" element of this ExponentialDistribution_t.
 */
LIBSBML_EXTERN
int
ExponentialDistribution_setRate(ExponentialDistribution_t * ed,
                                const UncertValue_t* rate)
{
  return (ed != NULL) ? ed->setRate(rate) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new UncertValue_t object, adds it to this
 * ExponentialDistribution_t object and returns the UncertValue_t object
 * created.
 */
LIBSBML_EXTERN
UncertValue_t*
ExponentialDistribution_createRate(ExponentialDistribution_t* ed)
{
  if (ed == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(ed->createRate());
}


/*
 * Unsets the value of the "rate" element of this ExponentialDistribution_t.
 */
LIBSBML_EXTERN
int
ExponentialDistribution_unsetRate(ExponentialDistribution_t * ed)
{
  return (ed != NULL) ? ed->unsetRate() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * ExponentialDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
ExponentialDistribution_hasRequiredAttributes(const ExponentialDistribution_t *
  ed)
{
  return (ed != NULL) ? static_cast<int>(ed->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * ExponentialDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
ExponentialDistribution_hasRequiredElements(const ExponentialDistribution_t *
  ed)
{
  return (ed != NULL) ? static_cast<int>(ed->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


