/**
 * @file BernoulliDistribution.cpp
 * @brief Implementation of the BernoulliDistribution class.
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
#include <sbml/packages/distrib/sbml/BernoulliDistribution.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new BernoulliDistribution using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
BernoulliDistribution::BernoulliDistribution(unsigned int level,
                                             unsigned int version,
                                             unsigned int pkgVersion)
  : CategoricalUnivariateDistribution(level, version)
  , mProb (NULL)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new BernoulliDistribution using the given DistribPkgNamespaces
 * object.
 */
BernoulliDistribution::BernoulliDistribution(DistribPkgNamespaces *distribns)
  : CategoricalUnivariateDistribution(distribns)
  , mProb (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for BernoulliDistribution.
 */
BernoulliDistribution::BernoulliDistribution(const BernoulliDistribution& orig)
  : CategoricalUnivariateDistribution( orig )
  , mProb ( NULL )
{
  if (orig.mProb != NULL)
  {
    mProb = orig.mProb->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for BernoulliDistribution.
 */
BernoulliDistribution&
BernoulliDistribution::operator=(const BernoulliDistribution& rhs)
{
  if (&rhs != this)
  {
    CategoricalUnivariateDistribution::operator=(rhs);
    delete mProb;
    if (rhs.mProb != NULL)
    {
      mProb = rhs.mProb->clone();
    }
    else
    {
      mProb = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this BernoulliDistribution object.
 */
BernoulliDistribution*
BernoulliDistribution::clone() const
{
  return new BernoulliDistribution(*this);
}


/*
 * Destructor for BernoulliDistribution.
 */
BernoulliDistribution::~BernoulliDistribution()
{
  delete mProb;
  mProb = NULL;
}


/*
 * Returns the value of the "prob" element of this BernoulliDistribution.
 */
const UncertValue*
BernoulliDistribution::getProb() const
{
  return mProb;
}


/*
 * Returns the value of the "prob" element of this BernoulliDistribution.
 */
UncertValue*
BernoulliDistribution::getProb()
{
  return mProb;
}


/*
 * Predicate returning @c true if this BernoulliDistribution's "prob" element
 * is set.
 */
bool
BernoulliDistribution::isSetProb() const
{
  return (mProb != NULL);
}


/*
 * Sets the value of the "prob" element of this BernoulliDistribution.
 */
int
BernoulliDistribution::setProb(const UncertValue* prob)
{
  if (mProb == prob)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (prob == NULL)
  {
    delete mProb;
    mProb = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mProb;
    mProb = (prob != NULL) ? prob->clone() : NULL;
    if (mProb != NULL)
    {
      mProb->setElementName("prob");
      mProb->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new UncertValue object, adds it to this BernoulliDistribution
 * object and returns the UncertValue object created.
 */
UncertValue*
BernoulliDistribution::createProb()
{
  if (mProb != NULL)
  {
    delete mProb;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mProb = new UncertValue(distribns);

  mProb->setElementName("prob");

  delete distribns;

  connectToChild();

  return mProb;
}


/*
 * Unsets the value of the "prob" element of this BernoulliDistribution.
 */
int
BernoulliDistribution::unsetProb()
{
  delete mProb;
  mProb = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this BernoulliDistribution object.
 */
const std::string&
BernoulliDistribution::getElementName() const
{
  static const string name = "bernoulliDistribution";
  return name;
}


/*
 * Returns the libSBML type code for this BernoulliDistribution object.
 */
int
BernoulliDistribution::getTypeCode() const
{
  return SBML_DISTRIB_BERNOULLIDISTRIBUTION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * BernoulliDistribution object have been set.
 */
bool
BernoulliDistribution::hasRequiredAttributes() const
{
  bool allPresent = CategoricalUnivariateDistribution::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * BernoulliDistribution object have been set.
 */
bool
BernoulliDistribution::hasRequiredElements() const
{
  bool allPresent = CategoricalUnivariateDistribution::hasRequiredElements();

  if (isSetProb() == false)
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
BernoulliDistribution::writeElements(XMLOutputStream& stream) const
{
  CategoricalUnivariateDistribution::writeElements(stream);

  if (isSetProb() == true)
  {
    mProb->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
BernoulliDistribution::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mProb != NULL)
  {
    mProb->accept(v);
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
BernoulliDistribution::setSBMLDocument(SBMLDocument* d)
{
  CategoricalUnivariateDistribution::setSBMLDocument(d);

  if (mProb != NULL)
  {
    mProb->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
BernoulliDistribution::connectToChild()
{
  CategoricalUnivariateDistribution::connectToChild();

  if (mProb != NULL)
  {
    mProb->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
BernoulliDistribution::enablePackageInternal(const std::string& pkgURI,
                                             const std::string& pkgPrefix,
                                             bool flag)
{
  CategoricalUnivariateDistribution::enablePackageInternal(pkgURI, pkgPrefix,
    flag);

  if (isSetProb())
  {
    mProb->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::getAttribute(const std::string& attributeName,
                                    bool& value) const
{
  int return_value =
    CategoricalUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::getAttribute(const std::string& attributeName,
                                    int& value) const
{
  int return_value =
    CategoricalUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::getAttribute(const std::string& attributeName,
                                    double& value) const
{
  int return_value =
    CategoricalUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::getAttribute(const std::string& attributeName,
                                    unsigned int& value) const
{
  int return_value =
    CategoricalUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::getAttribute(const std::string& attributeName,
                                    std::string& value) const
{
  int return_value =
    CategoricalUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::getAttribute(const std::string& attributeName,
                                    const char* value) const
{
  int return_value =
    CategoricalUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this BernoulliDistribution's attribute
 * "attributeName" is set.
 */
bool
BernoulliDistribution::isSetAttribute(const std::string& attributeName) const
{
  bool value =
    CategoricalUnivariateDistribution::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::setAttribute(const std::string& attributeName,
                                    bool value)
{
  int return_value =
    CategoricalUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::setAttribute(const std::string& attributeName,
                                    int value)
{
  int return_value =
    CategoricalUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::setAttribute(const std::string& attributeName,
                                    double value)
{
  int return_value =
    CategoricalUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::setAttribute(const std::string& attributeName,
                                    unsigned int value)
{
  int return_value =
    CategoricalUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::setAttribute(const std::string& attributeName,
                                    const std::string& value)
{
  int return_value =
    CategoricalUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::setAttribute(const std::string& attributeName,
                                    const char* value)
{
  int return_value =
    CategoricalUnivariateDistribution::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * BernoulliDistribution.
 */
int
BernoulliDistribution::unsetAttribute(const std::string& attributeName)
{
  int value = CategoricalUnivariateDistribution::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this
 * BernoulliDistribution.
 */
SBase*
BernoulliDistribution::createChildObject(const std::string& elementName)
{
  CategoricalUnivariateDistribution* obj = NULL;

  if (elementName == "prob")
  {
    return createProb();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this BernoulliDistribution.
 */
int
BernoulliDistribution::addChildObject(const std::string& elementName,
                                      const SBase* element)
{
  if (elementName == "prob" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTVALUE)
  {
    return setProb((const UncertValue*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * BernoulliDistribution.
 */
SBase*
BernoulliDistribution::removeChildObject(const std::string& elementName,
                                         const std::string& id)
{
  if (elementName == "prob")
  {
    UncertValue * obj = getProb();
    if (unsetProb() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this BernoulliDistribution.
 */
unsigned int
BernoulliDistribution::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "prob")
  {
    if (isSetProb())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this BernoulliDistribution.
 */
SBase*
BernoulliDistribution::getObject(const std::string& elementName,
                                 unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "prob")
  {
    return getProb();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
BernoulliDistribution::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mProb != NULL)
  {
    if (mProb->getId() == id)
    {
      return mProb;
    }

    obj = mProb->getElementBySId(id);
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
BernoulliDistribution::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mProb != NULL)
  {
    if (mProb->getMetaId() == metaid)
    {
      return mProb;
    }

    obj = mProb->getElementByMetaId(metaid);
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
BernoulliDistribution::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mProb, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
BernoulliDistribution::createObject(XMLInputStream& stream)
{
  SBase* obj = CategoricalUnivariateDistribution::createObject(stream);

  const std::string& name = stream.peek().getName();

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());

  if (name == "prob")
  {
    if (isSetProb())
    {
      getErrorLog()->logPackageError("distrib",
        DistribBernoulliDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    delete mProb;
    mProb = new UncertValue(distribns);
    mProb->setElementName(name);
    obj = mProb;
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
BernoulliDistribution::addExpectedAttributes(ExpectedAttributes& attributes)
{
  CategoricalUnivariateDistribution::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
BernoulliDistribution::readAttributes(const XMLAttributes& attributes,
                                      const ExpectedAttributes&
                                        expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  CategoricalUnivariateDistribution::readAttributes(attributes,
    expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("distrib",
        DistribBernoulliDistributionAllowedAttributes, pkgVersion, level,
          version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("distrib",
        DistribBernoulliDistributionAllowedCoreAttributes, pkgVersion, level,
          version, details);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
BernoulliDistribution::writeAttributes(XMLOutputStream& stream) const
{
  CategoricalUnivariateDistribution::writeAttributes(stream);

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new BernoulliDistribution_t using the given SBML Level, Version
 * and &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
BernoulliDistribution_t *
BernoulliDistribution_create(unsigned int level,
                             unsigned int version,
                             unsigned int pkgVersion)
{
  return new BernoulliDistribution(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this BernoulliDistribution_t object.
 */
LIBSBML_EXTERN
BernoulliDistribution_t*
BernoulliDistribution_clone(const BernoulliDistribution_t* bd)
{
  if (bd != NULL)
  {
    return static_cast<BernoulliDistribution_t*>(bd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this BernoulliDistribution_t object.
 */
LIBSBML_EXTERN
void
BernoulliDistribution_free(BernoulliDistribution_t* bd)
{
  if (bd != NULL)
  {
    delete bd;
  }
}


/*
 * Returns the value of the "prob" element of this BernoulliDistribution_t.
 */
LIBSBML_EXTERN
const UncertValue_t*
BernoulliDistribution_getProb(const BernoulliDistribution_t * bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->getProb());
}


/*
 * Predicate returning @c 1 (true) if this BernoulliDistribution_t's "prob"
 * element is set.
 */
LIBSBML_EXTERN
int
BernoulliDistribution_isSetProb(const BernoulliDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->isSetProb()) : 0;
}


/*
 * Sets the value of the "prob" element of this BernoulliDistribution_t.
 */
LIBSBML_EXTERN
int
BernoulliDistribution_setProb(BernoulliDistribution_t * bd,
                              const UncertValue_t* prob)
{
  return (bd != NULL) ? bd->setProb(prob) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new UncertValue_t object, adds it to this BernoulliDistribution_t
 * object and returns the UncertValue_t object created.
 */
LIBSBML_EXTERN
UncertValue_t*
BernoulliDistribution_createProb(BernoulliDistribution_t* bd)
{
  if (bd == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(bd->createProb());
}


/*
 * Unsets the value of the "prob" element of this BernoulliDistribution_t.
 */
LIBSBML_EXTERN
int
BernoulliDistribution_unsetProb(BernoulliDistribution_t * bd)
{
  return (bd != NULL) ? bd->unsetProb() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * BernoulliDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
BernoulliDistribution_hasRequiredAttributes(const BernoulliDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this
 * BernoulliDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
BernoulliDistribution_hasRequiredElements(const BernoulliDistribution_t * bd)
{
  return (bd != NULL) ? static_cast<int>(bd->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


