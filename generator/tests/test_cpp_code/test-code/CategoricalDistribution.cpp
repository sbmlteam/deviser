/**
 * @file CategoricalDistribution.cpp
 * @brief Implementation of the CategoricalDistribution class.
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
#include <sbml/packages/distrib/sbml/CategoricalDistribution.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new CategoricalDistribution using the given SBML Level, Version
 * and &ldquo;distrib&rdquo; package version.
 */
CategoricalDistribution::CategoricalDistribution(unsigned int level,
                                                 unsigned int version,
                                                 unsigned int pkgVersion)
  : CategoricalUnivariateDistribution(level, version)
  , mCategories (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new CategoricalDistribution using the given DistribPkgNamespaces
 * object.
 */
CategoricalDistribution::CategoricalDistribution(DistribPkgNamespaces
  *distribns)
  : CategoricalUnivariateDistribution(distribns)
  , mCategories (distribns)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for CategoricalDistribution.
 */
CategoricalDistribution::CategoricalDistribution(const CategoricalDistribution&
  orig)
  : CategoricalUnivariateDistribution( orig )
  , mCategories ( orig.mCategories )
{
  connectToChild();
}


/*
 * Assignment operator for CategoricalDistribution.
 */
CategoricalDistribution&
CategoricalDistribution::operator=(const CategoricalDistribution& rhs)
{
  if (&rhs != this)
  {
    CategoricalUnivariateDistribution::operator=(rhs);
    mCategories = rhs.mCategories;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this CategoricalDistribution object.
 */
CategoricalDistribution*
CategoricalDistribution::clone() const
{
  return new CategoricalDistribution(*this);
}


/*
 * Destructor for CategoricalDistribution.
 */
CategoricalDistribution::~CategoricalDistribution()
{
}


/*
 * Returns the ListOfCategories from this CategoricalDistribution.
 */
const ListOfCategories*
CategoricalDistribution::getListOfCategories() const
{
  return &mCategories;
}


/*
 * Returns the ListOfCategories from this CategoricalDistribution.
 */
ListOfCategories*
CategoricalDistribution::getListOfCategories()
{
  return &mCategories;
}


/*
 * Get a Category from the CategoricalDistribution.
 */
Category*
CategoricalDistribution::getCategory(unsigned int n)
{
  return mCategories.get(n);
}


/*
 * Get a Category from the CategoricalDistribution.
 */
const Category*
CategoricalDistribution::getCategory(unsigned int n) const
{
  return mCategories.get(n);
}


/*
 * Adds a copy of the given Category to this CategoricalDistribution.
 */
int
CategoricalDistribution::addCategory(const Category* c)
{
  if (c == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (c->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != c->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != c->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(c)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mCategories.append(c);
  }
}


/*
 * Get the number of Category objects in this CategoricalDistribution.
 */
unsigned int
CategoricalDistribution::getNumCategories() const
{
  return mCategories.size();
}


/*
 * Creates a new Category object, adds it to this CategoricalDistribution
 * object and returns the Category object created.
 */
Category*
CategoricalDistribution::createCategory()
{
  Category* c = NULL;

  try
  {
    DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
    c = new Category(distribns);
    delete distribns;
  }
  catch (...)
  {
  }

  if (c != NULL)
  {
    mCategories.appendAndOwn(c);
  }

  return c;
}


/*
 * Removes the nth Category from this CategoricalDistribution and returns a
 * pointer to it.
 */
Category*
CategoricalDistribution::removeCategory(unsigned int n)
{
  return mCategories.remove(n);
}


/*
 * Returns the XML element name of this CategoricalDistribution object.
 */
const std::string&
CategoricalDistribution::getElementName() const
{
  static const string name = "categoricalDistribution";
  return name;
}


/*
 * Returns the libSBML type code for this CategoricalDistribution object.
 */
int
CategoricalDistribution::getTypeCode() const
{
  return SBML_DISTRIB_CATEGORICALDISTRIBUTION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * CategoricalDistribution object have been set.
 */
bool
CategoricalDistribution::hasRequiredAttributes() const
{
  bool allPresent = CategoricalUnivariateDistribution::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * CategoricalDistribution object have been set.
 */
bool
CategoricalDistribution::hasRequiredElements() const
{
  bool allPresent = CategoricalUnivariateDistribution::hasRequiredElements();

  if (getNumCategories() == 0)
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
CategoricalDistribution::writeElements(XMLOutputStream& stream) const
{
  CategoricalUnivariateDistribution::writeElements(stream);

  if (getNumCategories() > 0)
  {
    mCategories.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
CategoricalDistribution::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  mCategories.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
CategoricalDistribution::setSBMLDocument(SBMLDocument* d)
{
  CategoricalUnivariateDistribution::setSBMLDocument(d);

  mCategories.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
CategoricalDistribution::connectToChild()
{
  CategoricalUnivariateDistribution::connectToChild();

  mCategories.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
CategoricalDistribution::enablePackageInternal(const std::string& pkgURI,
                                               const std::string& pkgPrefix,
                                               bool flag)
{
  CategoricalUnivariateDistribution::enablePackageInternal(pkgURI, pkgPrefix,
    flag);

  mCategories.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CategoricalDistribution.
 */
int
CategoricalDistribution::getAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::getAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::getAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::getAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::getAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::getAttribute(const std::string& attributeName,
                                      const char* value) const
{
  int return_value =
    CategoricalUnivariateDistribution::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this CategoricalDistribution's attribute
 * "attributeName" is set.
 */
bool
CategoricalDistribution::isSetAttribute(const std::string& attributeName) const
{
  bool value =
    CategoricalUnivariateDistribution::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CategoricalDistribution.
 */
int
CategoricalDistribution::setAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::setAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::setAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::setAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::setAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::setAttribute(const std::string& attributeName,
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
 * CategoricalDistribution.
 */
int
CategoricalDistribution::unsetAttribute(const std::string& attributeName)
{
  int value = CategoricalUnivariateDistribution::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this
 * CategoricalDistribution.
 */
SBase*
CategoricalDistribution::createChildObject(const std::string& elementName)
{
  CategoricalUnivariateDistribution* obj = NULL;

  if (elementName == "category")
  {
    return createCategory();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this CategoricalDistribution.
 */
int
CategoricalDistribution::addChildObject(const std::string& elementName,
                                        const SBase* element)
{
  if (elementName == "category" && element->getTypeCode() ==
    SBML_DISTRIB_CATEGORY)
  {
    return addCategory((const Category*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * CategoricalDistribution.
 */
SBase*
CategoricalDistribution::removeChildObject(const std::string& elementName,
                                           const std::string& id)
{
  if (elementName == "category")
  {
    for (unsigned int i = 0; i < getNumCategories(); i++)
    {
      if (getCategory(i)->getId() == id)
      {
        return removeCategory(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this CategoricalDistribution.
 */
unsigned int
CategoricalDistribution::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "category")
  {
    return getNumCategories();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this CategoricalDistribution.
 */
SBase*
CategoricalDistribution::getObject(const std::string& elementName,
                                   unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "category")
  {
    return getCategory(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
CategoricalDistribution::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mCategories.getElementBySId(id);

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
CategoricalDistribution::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mCategories.getMetaId() == metaid)
  {
    return &mCategories;
  }

  obj = mCategories.getElementByMetaId(metaid);

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
CategoricalDistribution::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mCategories, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
CategoricalDistribution::createObject(XMLInputStream& stream)
{
  SBase* obj = CategoricalUnivariateDistribution::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "listOfCategories")
  {
    if (mCategories.size() != 0)
    {
      getErrorLog()->logPackageError("distrib",
        DistribCategoricalDistributionAllowedElements, getPackageVersion(),
          getLevel(), getVersion());
    }

    obj = &mCategories;
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
CategoricalDistribution::addExpectedAttributes(ExpectedAttributes& attributes)
{
  CategoricalUnivariateDistribution::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
CategoricalDistribution::readAttributes(const XMLAttributes& attributes,
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
        DistribCategoricalDistributionAllowedAttributes, pkgVersion, level,
          version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("distrib",
        DistribCategoricalDistributionAllowedCoreAttributes, pkgVersion, level,
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
CategoricalDistribution::writeAttributes(XMLOutputStream& stream) const
{
  CategoricalUnivariateDistribution::writeAttributes(stream);

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new CategoricalDistribution_t using the given SBML Level, Version
 * and &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
CategoricalDistribution_t *
CategoricalDistribution_create(unsigned int level,
                               unsigned int version,
                               unsigned int pkgVersion)
{
  return new CategoricalDistribution(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this CategoricalDistribution_t object.
 */
LIBSBML_EXTERN
CategoricalDistribution_t*
CategoricalDistribution_clone(const CategoricalDistribution_t* cd)
{
  if (cd != NULL)
  {
    return static_cast<CategoricalDistribution_t*>(cd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this CategoricalDistribution_t object.
 */
LIBSBML_EXTERN
void
CategoricalDistribution_free(CategoricalDistribution_t* cd)
{
  if (cd != NULL)
  {
    delete cd;
  }
}


/*
 * Returns a ListOf_t* containing Category_t objects from this
 * CategoricalDistribution_t.
 */
LIBSBML_EXTERN
ListOf_t*
CategoricalDistribution_getListOfCategories(CategoricalDistribution_t* cd)
{
  return (cd != NULL) ? cd->getListOfCategories() : NULL;
}


/*
 * Get a Category_t from the CategoricalDistribution_t.
 */
LIBSBML_EXTERN
Category_t*
CategoricalDistribution_getCategory(CategoricalDistribution_t* cd,
                                    unsigned int n)
{
  return (cd != NULL) ? cd->getCategory(n) : NULL;
}


/*
 * Adds a copy of the given Category_t to this CategoricalDistribution_t.
 */
LIBSBML_EXTERN
int
CategoricalDistribution_addCategory(CategoricalDistribution_t* cd,
                                    const Category_t* c)
{
  return (cd != NULL) ? cd->addCategory(c) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Category_t objects in this CategoricalDistribution_t.
 */
LIBSBML_EXTERN
unsigned int
CategoricalDistribution_getNumCategories(CategoricalDistribution_t* cd)
{
  return (cd != NULL) ? cd->getNumCategories() : SBML_INT_MAX;
}


/*
 * Creates a new Category_t object, adds it to this CategoricalDistribution_t
 * object and returns the Category_t object created.
 */
LIBSBML_EXTERN
Category_t*
CategoricalDistribution_createCategory(CategoricalDistribution_t* cd)
{
  return (cd != NULL) ? cd->createCategory() : NULL;
}


/*
 * Removes the nth Category_t from this CategoricalDistribution_t and returns a
 * pointer to it.
 */
LIBSBML_EXTERN
Category_t*
CategoricalDistribution_removeCategory(CategoricalDistribution_t* cd,
                                       unsigned int n)
{
  return (cd != NULL) ? cd->removeCategory(n) : NULL;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * CategoricalDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
CategoricalDistribution_hasRequiredAttributes(const CategoricalDistribution_t *
  cd)
{
  return (cd != NULL) ? static_cast<int>(cd->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this
 * CategoricalDistribution_t object have been set.
 */
LIBSBML_EXTERN
int
CategoricalDistribution_hasRequiredElements(const CategoricalDistribution_t *
  cd)
{
  return (cd != NULL) ? static_cast<int>(cd->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


