/**
 * @file Category.cpp
 * @brief Implementation of the Category class.
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
#include <sbml/packages/distrib/sbml/Category.h>
#include <sbml/packages/distrib/sbml/ListOfCategories.h>
#include <sbml/packages/distrib/validator/DistribSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Category using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
Category::Category(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
  : SBase(level, version)
  , mRank (SBML_INT_MAX)
  , mIsSetRank (false)
  , mProbability (NULL)
  , mValue (NULL)
{
  setSBMLNamespacesAndOwn(new DistribPkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new Category using the given DistribPkgNamespaces object.
 */
Category::Category(DistribPkgNamespaces *distribns)
  : SBase(distribns)
  , mRank (SBML_INT_MAX)
  , mIsSetRank (false)
  , mProbability (NULL)
  , mValue (NULL)
{
  setElementNamespace(distribns->getURI());
  connectToChild();
  loadPlugins(distribns);
}


/*
 * Copy constructor for Category.
 */
Category::Category(const Category& orig)
  : SBase( orig )
  , mRank ( orig.mRank )
  , mIsSetRank ( orig.mIsSetRank )
  , mProbability ( NULL )
  , mValue ( NULL )
{
  if (orig.mProbability != NULL)
  {
    mProbability = orig.mProbability->clone();
  }

  if (orig.mValue != NULL)
  {
    mValue = orig.mValue->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Category.
 */
Category&
Category::operator=(const Category& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mRank = rhs.mRank;
    mIsSetRank = rhs.mIsSetRank;
    delete mProbability;
    if (rhs.mProbability != NULL)
    {
      mProbability = rhs.mProbability->clone();
    }
    else
    {
      mProbability = NULL;
    }

    delete mValue;
    if (rhs.mValue != NULL)
    {
      mValue = rhs.mValue->clone();
    }
    else
    {
      mValue = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Category object.
 */
Category*
Category::clone() const
{
  return new Category(*this);
}


/*
 * Destructor for Category.
 */
Category::~Category()
{
  delete mProbability;
  mProbability = NULL;
  delete mValue;
  mValue = NULL;
}


/*
 * Returns the value of the "rank" attribute of this Category.
 */
unsigned int
Category::getRank() const
{
  return mRank;
}


/*
 * Predicate returning @c true if this Category's "rank" attribute is set.
 */
bool
Category::isSetRank() const
{
  return mIsSetRank;
}


/*
 * Sets the value of the "rank" attribute of this Category.
 */
int
Category::setRank(unsigned int rank)
{
  mRank = rank;
  mIsSetRank = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "rank" attribute of this Category.
 */
int
Category::unsetRank()
{
  mRank = SBML_INT_MAX;
  mIsSetRank = false;

  if (isSetRank() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "probability" element of this Category.
 */
const UncertValue*
Category::getProbability() const
{
  return mProbability;
}


/*
 * Returns the value of the "probability" element of this Category.
 */
UncertValue*
Category::getProbability()
{
  return mProbability;
}


/*
 * Returns the value of the "value" element of this Category.
 */
const UncertValue*
Category::getValue() const
{
  return mValue;
}


/*
 * Returns the value of the "value" element of this Category.
 */
UncertValue*
Category::getValue()
{
  return mValue;
}


/*
 * Predicate returning @c true if this Category's "probability" element is set.
 */
bool
Category::isSetProbability() const
{
  return (mProbability != NULL);
}


/*
 * Predicate returning @c true if this Category's "value" element is set.
 */
bool
Category::isSetValue() const
{
  return (mValue != NULL);
}


/*
 * Sets the value of the "probability" element of this Category.
 */
int
Category::setProbability(const UncertValue* probability)
{
  if (mProbability == probability)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (probability == NULL)
  {
    delete mProbability;
    mProbability = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mProbability;
    mProbability = (probability != NULL) ? probability->clone() : NULL;
    if (mProbability != NULL)
    {
      mProbability->setElementName("probability");
      mProbability->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "value" element of this Category.
 */
int
Category::setValue(const UncertValue* value)
{
  if (mValue == value)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (value == NULL)
  {
    delete mValue;
    mValue = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mValue;
    mValue = (value != NULL) ? value->clone() : NULL;
    if (mValue != NULL)
    {
      mValue->setElementName("value");
      mValue->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new UncertValue object, adds it to this Category object and
 * returns the UncertValue object created.
 */
UncertValue*
Category::createProbability()
{
  if (mProbability != NULL)
  {
    delete mProbability;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mProbability = new UncertValue(distribns);

  mProbability->setElementName("probability");

  delete distribns;

  connectToChild();

  return mProbability;
}


/*
 * Creates a new UncertValue object, adds it to this Category object and
 * returns the UncertValue object created.
 */
UncertValue*
Category::createValue()
{
  if (mValue != NULL)
  {
    delete mValue;
  }

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());
  mValue = new UncertValue(distribns);

  mValue->setElementName("value");

  delete distribns;

  connectToChild();

  return mValue;
}


/*
 * Unsets the value of the "probability" element of this Category.
 */
int
Category::unsetProbability()
{
  delete mProbability;
  mProbability = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "value" element of this Category.
 */
int
Category::unsetValue()
{
  delete mValue;
  mValue = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this Category object.
 */
const std::string&
Category::getElementName() const
{
  static const string name = "category";
  return name;
}


/*
 * Returns the libSBML type code for this Category object.
 */
int
Category::getTypeCode() const
{
  return SBML_DISTRIB_CATEGORY;
}


/*
 * Predicate returning @c true if all the required attributes for this Category
 * object have been set.
 */
bool
Category::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this Category
 * object have been set.
 */
bool
Category::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetValue() == false)
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
Category::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetProbability() == true)
  {
    mProbability->write(stream);
  }

  if (isSetValue() == true)
  {
    mValue->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Category::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mProbability != NULL)
  {
    mProbability->accept(v);
  }

  if (mValue != NULL)
  {
    mValue->accept(v);
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
Category::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  if (mProbability != NULL)
  {
    mProbability->setSBMLDocument(d);
  }

  if (mValue != NULL)
  {
    mValue->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Category::connectToChild()
{
  SBase::connectToChild();

  if (mProbability != NULL)
  {
    mProbability->connectToParent(this);
  }

  if (mValue != NULL)
  {
    mValue->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Category::enablePackageInternal(const std::string& pkgURI,
                                const std::string& pkgPrefix,
                                bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetProbability())
  {
    mProbability->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetValue())
  {
    mValue->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
Category::updateSBMLNamespace(const std::string& package,
                              unsigned int level,
                              unsigned int version)
{
  SBase::updateSBMLNamespace(package, level, version);

  if (mProbability != NULL)
  {
    mProbability->updateSBMLNamespace(package, level, version);
  }

  if (mValue != NULL)
  {
    mValue->updateSBMLNamespace(package, level, version);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Category.
 */
int
Category::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Category.
 */
int
Category::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Category.
 */
int
Category::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Category.
 */
int
Category::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "rank")
  {
    value = getRank();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Category.
 */
int
Category::getAttribute(const std::string& attributeName,
                       std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Category's attribute "attributeName" is
 * set.
 */
bool
Category::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "rank")
  {
    value = isSetRank();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Category.
 */
int
Category::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Category.
 */
int
Category::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Category.
 */
int
Category::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Category.
 */
int
Category::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "rank")
  {
    return_value = setRank(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Category.
 */
int
Category::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Category.
 */
int
Category::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "rank")
  {
    value = unsetRank();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this Category.
 */
SBase*
Category::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "probability")
  {
    return createProbability();
  }
  else if (elementName == "value")
  {
    return createValue();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this Category.
 */
int
Category::addChildObject(const std::string& elementName, const SBase* element)
{
  if (elementName == "probability" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTVALUE)
  {
    return setProbability((const UncertValue*)(element));
  }
  else if (elementName == "value" && element->getTypeCode() ==
    SBML_DISTRIB_UNCERTVALUE)
  {
    return setValue((const UncertValue*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Category.
 */
SBase*
Category::removeChildObject(const std::string& elementName,
                            const std::string& id)
{
  if (elementName == "probability")
  {
    UncertValue * obj = getProbability();
    if (unsetProbability() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "value")
  {
    UncertValue * obj = getValue();
    if (unsetValue() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this Category.
 */
unsigned int
Category::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "probability")
  {
    if (isSetProbability())
    {
      return 1;
    }
  }
  else if (elementName == "value")
  {
    if (isSetValue())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this Category.
 */
SBase*
Category::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "probability")
  {
    return getProbability();
  }
  else if (elementName == "value")
  {
    return getValue();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
Category::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mProbability != NULL)
  {
    if (mProbability->getId() == id)
    {
      return mProbability;
    }

    obj = mProbability->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mValue != NULL)
  {
    if (mValue->getId() == id)
    {
      return mValue;
    }

    obj = mValue->getElementBySId(id);
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
Category::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mProbability != NULL)
  {
    if (mProbability->getMetaId() == metaid)
    {
      return mProbability;
    }

    obj = mProbability->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mValue != NULL)
  {
    if (mValue->getMetaId() == metaid)
    {
      return mValue;
    }

    obj = mValue->getElementByMetaId(metaid);
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
Category::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mProbability, filter);
  ADD_FILTERED_POINTER(ret, sublist, mValue, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
Category::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  DISTRIB_CREATE_NS(distribns, getSBMLNamespaces());

  if (name == "probability")
  {
    if (isSetProbability())
    {
      getErrorLog()->logPackageError("distrib", DistribCategoryAllowedElements,
        getPackageVersion(), getLevel(), getVersion(), "", getLine(),
          getColumn());
    }

    delete mProbability;
    mProbability = new UncertValue(distribns);
    mProbability->setElementName(name);
    obj = mProbability;
  }
  else if (name == "value")
  {
    if (isSetValue())
    {
      getErrorLog()->logPackageError("distrib", DistribCategoryAllowedElements,
        getPackageVersion(), getLevel(), getVersion(), "", getLine(),
          getColumn());
    }

    delete mValue;
    mValue = new UncertValue(distribns);
    mValue->setElementName(name);
    obj = mValue;
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
Category::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("rank");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Category::readAttributes(const XMLAttributes& attributes,
                         const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (log && getParentSBMLObject() &&
    static_cast<ListOfCategories*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("distrib",
          DistribCategoricalDistributionLOCategoriesAllowedAttributes,
            pkgVersion, level, version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("distrib",
          DistribCategoricalDistributionLOCategoriesAllowedCoreAttributes,
            pkgVersion, level, version, details, getLine(), getColumn());
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("distrib", DistribCategoryAllowedAttributes,
          pkgVersion, level, version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("distrib", DistribCategoryAllowedCoreAttributes,
          pkgVersion, level, version, details, getLine(), getColumn());
      }
    }
  }

  // 
  // rank uint (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetRank = attributes.readInto("rank", mRank);

  if ( mIsSetRank == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Distrib attribute 'rank' from the <Category> "
        "element must be an integer.";
      log->logPackageError("distrib",
        DistribCategoryRankMustBeNonNegativeInteger, pkgVersion, level, version,
          message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Category::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetRank() == true)
  {
    stream.writeAttribute("rank", getPrefix(), mRank);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Category_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 */
LIBSBML_EXTERN
Category_t *
Category_create(unsigned int level,
                unsigned int version,
                unsigned int pkgVersion)
{
  return new Category(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Category_t object.
 */
LIBSBML_EXTERN
Category_t*
Category_clone(const Category_t* c)
{
  if (c != NULL)
  {
    return static_cast<Category_t*>(c->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Category_t object.
 */
LIBSBML_EXTERN
void
Category_free(Category_t* c)
{
  if (c != NULL)
  {
    delete c;
  }
}


/*
 * Returns the value of the "rank" attribute of this Category_t.
 */
LIBSBML_EXTERN
unsigned int
Category_getRank(const Category_t * c)
{
  return (c != NULL) ? c->getRank() : SBML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this Category_t's "rank" attribute is
 * set.
 */
LIBSBML_EXTERN
int
Category_isSetRank(const Category_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetRank()) : 0;
}


/*
 * Sets the value of the "rank" attribute of this Category_t.
 */
LIBSBML_EXTERN
int
Category_setRank(Category_t * c, unsigned int rank)
{
  return (c != NULL) ? c->setRank(rank) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "rank" attribute of this Category_t.
 */
LIBSBML_EXTERN
int
Category_unsetRank(Category_t * c)
{
  return (c != NULL) ? c->unsetRank() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "probability" element of this Category_t.
 */
LIBSBML_EXTERN
const UncertValue_t*
Category_getProbability(const Category_t * c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(c->getProbability());
}


/*
 * Returns the value of the "value" element of this Category_t.
 */
LIBSBML_EXTERN
const UncertValue_t*
Category_getValue(const Category_t * c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(c->getValue());
}


/*
 * Predicate returning @c 1 (true) if this Category_t's "probability" element
 * is set.
 */
LIBSBML_EXTERN
int
Category_isSetProbability(const Category_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetProbability()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Category_t's "value" element is set.
 */
LIBSBML_EXTERN
int
Category_isSetValue(const Category_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetValue()) : 0;
}


/*
 * Sets the value of the "probability" element of this Category_t.
 */
LIBSBML_EXTERN
int
Category_setProbability(Category_t * c, const UncertValue_t* probability)
{
  return (c != NULL) ? c->setProbability(probability) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "value" element of this Category_t.
 */
LIBSBML_EXTERN
int
Category_setValue(Category_t * c, const UncertValue_t* value)
{
  return (c != NULL) ? c->setValue(value) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new UncertValue_t object, adds it to this Category_t object and
 * returns the UncertValue_t object created.
 */
LIBSBML_EXTERN
UncertValue_t*
Category_createProbability(Category_t* c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(c->createProbability());
}


/*
 * Creates a new UncertValue_t object, adds it to this Category_t object and
 * returns the UncertValue_t object created.
 */
LIBSBML_EXTERN
UncertValue_t*
Category_createValue(Category_t* c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return (UncertValue_t*)(c->createValue());
}


/*
 * Unsets the value of the "probability" element of this Category_t.
 */
LIBSBML_EXTERN
int
Category_unsetProbability(Category_t * c)
{
  return (c != NULL) ? c->unsetProbability() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "value" element of this Category_t.
 */
LIBSBML_EXTERN
int
Category_unsetValue(Category_t * c)
{
  return (c != NULL) ? c->unsetValue() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Category_t object have been set.
 */
LIBSBML_EXTERN
int
Category_hasRequiredAttributes(const Category_t * c)
{
  return (c != NULL) ? static_cast<int>(c->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * Category_t object have been set.
 */
LIBSBML_EXTERN
int
Category_hasRequiredElements(const Category_t * c)
{
  return (c != NULL) ? static_cast<int>(c->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


