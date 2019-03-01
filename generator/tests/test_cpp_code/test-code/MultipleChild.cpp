/**
 * @file MultipleChild.cpp
 * @brief Implementation of the MultipleChild class.
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
#include <sbml/packages/twoatonce/sbml/MultipleChild.h>
#include <sbml/packages/twoatonce/validator/TwoatonceSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new MultipleChild using the given SBML Level, Version and
 * &ldquo;twoatonce&rdquo; package version.
 */
MultipleChild::MultipleChild(unsigned int level,
                             unsigned int version,
                             unsigned int pkgVersion)
  : SBase(level, version)
  , mNumAtt (util_NaN())
  , mIsSetNumAtt (false)
  , mClassIds (level, version, pkgVersion)
  , mNormalClass (NULL)
{
  setSBMLNamespacesAndOwn(new TwoatoncePkgNamespaces(level, version,
    pkgVersion));
  connectToChild();
}


/*
 * Creates a new MultipleChild using the given TwoatoncePkgNamespaces object.
 */
MultipleChild::MultipleChild(TwoatoncePkgNamespaces *twoatoncens)
  : SBase(twoatoncens)
  , mNumAtt (util_NaN())
  , mIsSetNumAtt (false)
  , mClassIds (twoatoncens)
  , mNormalClass (NULL)
{
  setElementNamespace(twoatoncens->getURI());
  connectToChild();
  loadPlugins(twoatoncens);
}


/*
 * Copy constructor for MultipleChild.
 */
MultipleChild::MultipleChild(const MultipleChild& orig)
  : SBase( orig )
  , mNumAtt ( orig.mNumAtt )
  , mIsSetNumAtt ( orig.mIsSetNumAtt )
  , mClassIds ( orig.mClassIds )
  , mNormalClass ( NULL )
{
  if (orig.mNormalClass != NULL)
  {
    mNormalClass = orig.mNormalClass->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for MultipleChild.
 */
MultipleChild&
MultipleChild::operator=(const MultipleChild& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mNumAtt = rhs.mNumAtt;
    mIsSetNumAtt = rhs.mIsSetNumAtt;
    mClassIds = rhs.mClassIds;
    delete mNormalClass;
    if (rhs.mNormalClass != NULL)
    {
      mNormalClass = rhs.mNormalClass->clone();
    }
    else
    {
      mNormalClass = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this MultipleChild object.
 */
MultipleChild*
MultipleChild::clone() const
{
  return new MultipleChild(*this);
}


/*
 * Destructor for MultipleChild.
 */
MultipleChild::~MultipleChild()
{
  delete mNormalClass;
  mNormalClass = NULL;
}


/*
 * Returns the value of the "id" attribute of this MultipleChild.
 */
const std::string&
MultipleChild::getId() const
{
  return mId;
}


/*
 * Returns the value of the "numAtt" attribute of this MultipleChild.
 */
double
MultipleChild::getNumAtt() const
{
  return mNumAtt;
}


/*
 * Predicate returning @c true if this MultipleChild's "id" attribute is set.
 */
bool
MultipleChild::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this MultipleChild's "numAtt" attribute is
 * set.
 */
bool
MultipleChild::isSetNumAtt() const
{
  return mIsSetNumAtt;
}


/*
 * Sets the value of the "id" attribute of this MultipleChild.
 */
int
MultipleChild::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "numAtt" attribute of this MultipleChild.
 */
int
MultipleChild::setNumAtt(double numAtt)
{
  mNumAtt = numAtt;
  mIsSetNumAtt = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this MultipleChild.
 */
int
MultipleChild::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "numAtt" attribute of this MultipleChild.
 */
int
MultipleChild::unsetNumAtt()
{
  mNumAtt = util_NaN();
  mIsSetNumAtt = false;

  if (isSetNumAtt() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "normalClass" element of this MultipleChild.
 */
const NormalClass*
MultipleChild::getNormalClass() const
{
  return mNormalClass;
}


/*
 * Returns the value of the "normalClass" element of this MultipleChild.
 */
NormalClass*
MultipleChild::getNormalClass()
{
  return mNormalClass;
}


/*
 * Predicate returning @c true if this MultipleChild's "normalClass" element is
 * set.
 */
bool
MultipleChild::isSetNormalClass() const
{
  return (mNormalClass != NULL);
}


/*
 * Sets the value of the "normalClass" element of this MultipleChild.
 */
int
MultipleChild::setNormalClass(const NormalClass* normalClass)
{
  if (normalClass == NULL)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (normalClass->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != normalClass->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != normalClass->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != normalClass->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mNormalClass;
    mNormalClass = (normalClass != NULL) ?
      static_cast<NormalClass*>(normalClass->clone()) : NULL;
    if (mNormalClass != NULL) mNormalClass->connectToParent(this);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new NormalClass object, adds it to this MultipleChild object and
 * returns the NormalClass object created.
 */
NormalClass*
MultipleChild::createNormalClass()
{
  if (mNormalClass != NULL)
  {
    delete mNormalClass;
  }

  TWOATONCE_CREATE_NS(twoatoncens, getSBMLNamespaces());
  mNormalClass = new NormalClass(twoatoncens);

  delete twoatoncens;

  connectToChild();

  return mNormalClass;
}


/*
 * Unsets the value of the "normalClass" element of this MultipleChild.
 */
int
MultipleChild::unsetNormalClass()
{
  delete mNormalClass;
  mNormalClass = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the ListOfClassIds from this MultipleChild.
 */
const ListOfClassIds*
MultipleChild::getListOfClassIds() const
{
  return &mClassIds;
}


/*
 * Returns the ListOfClassIds from this MultipleChild.
 */
ListOfClassIds*
MultipleChild::getListOfClassIds()
{
  return &mClassIds;
}


/*
 * Get a ClassId from the MultipleChild.
 */
ClassId*
MultipleChild::getClassId(unsigned int n)
{
  return mClassIds.get(n);
}


/*
 * Get a ClassId from the MultipleChild.
 */
const ClassId*
MultipleChild::getClassId(unsigned int n) const
{
  return mClassIds.get(n);
}


/*
 * Get a ClassId from the MultipleChild based on its identifier.
 */
ClassId*
MultipleChild::getClassId(const std::string& sid)
{
  return mClassIds.get(sid);
}


/*
 * Get a ClassId from the MultipleChild based on its identifier.
 */
const ClassId*
MultipleChild::getClassId(const std::string& sid) const
{
  return mClassIds.get(sid);
}


/*
 * Adds a copy of the given ClassId to this MultipleChild.
 */
int
MultipleChild::addClassId(const ClassId* ci)
{
  if (ci == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (ci->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != ci->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ci->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(ci)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (ci->isSetId() && (mClassIds.get(ci->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mClassIds.append(ci);
  }
}


/*
 * Get the number of ClassId objects in this MultipleChild.
 */
unsigned int
MultipleChild::getNumClassIds() const
{
  return mClassIds.size();
}


/*
 * Creates a new ClassId object, adds it to this MultipleChild object and
 * returns the ClassId object created.
 */
ClassId*
MultipleChild::createClassId()
{
  ClassId* ci = NULL;

  try
  {
    TWOATONCE_CREATE_NS_WITH_VERSION(twoatoncens, getSBMLNamespaces(),
      getPackageVersion());
    ci = new ClassId(twoatoncens);
    delete twoatoncens;
  }
  catch (...)
  {
  }

  if (ci != NULL)
  {
    mClassIds.appendAndOwn(ci);
  }

  return ci;
}


/*
 * Removes the nth ClassId from this MultipleChild and returns a pointer to it.
 */
ClassId*
MultipleChild::removeClassId(unsigned int n)
{
  return mClassIds.remove(n);
}


/*
 * Removes the ClassId from this MultipleChild based on its identifier and
 * returns a pointer to it.
 */
ClassId*
MultipleChild::removeClassId(const std::string& sid)
{
  return mClassIds.remove(sid);
}


/*
 * Returns the XML element name of this MultipleChild object.
 */
const std::string&
MultipleChild::getElementName() const
{
  static const string name = "multipleChild";
  return name;
}


/*
 * Returns the libSBML type code for this MultipleChild object.
 */
int
MultipleChild::getTypeCode() const
{
  return SBML_TWOATONCE_MULTIPLECHILD;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * MultipleChild object have been set.
 */
bool
MultipleChild::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
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
MultipleChild::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetNormalClass() == true)
  {
    mNormalClass->write(stream);
  }

  if (getNumClassIds() > 0)
  {
    mClassIds.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
MultipleChild::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mNormalClass != NULL)
  {
    mNormalClass->accept(v);
  }

  mClassIds.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
MultipleChild::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  if (mNormalClass != NULL)
  {
    mNormalClass->setSBMLDocument(d);
  }

  mClassIds.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
MultipleChild::connectToChild()
{
  SBase::connectToChild();

  if (mNormalClass != NULL)
  {
    mNormalClass->connectToParent(this);
  }

  mClassIds.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
MultipleChild::enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetNormalClass())
  {
    mNormalClass->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  mClassIds.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
MultipleChild::updateSBMLNamespace(const std::string& package,
                                   unsigned int level,
                                   unsigned int version)
{
  SBase::updateSBMLNamespace(package, level, version);

  if (mNormalClass != NULL)
  {
    mNormalClass->updateSBMLNamespace(package, level, version);
  }

  mClassIds.updateSBMLNamespace(package, level, version);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::getAttribute(const std::string& attributeName,
                            bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::getAttribute(const std::string& attributeName,
                            int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::getAttribute(const std::string& attributeName,
                            double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "numAtt")
  {
    value = getNumAtt();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::getAttribute(const std::string& attributeName,
                            unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::getAttribute(const std::string& attributeName,
                            std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this MultipleChild's attribute
 * "attributeName" is set.
 */
bool
MultipleChild::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "numAtt")
  {
    value = isSetNumAtt();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "numAtt")
  {
    return_value = setNumAtt(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::setAttribute(const std::string& attributeName,
                            unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::setAttribute(const std::string& attributeName,
                            const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this MultipleChild.
 */
int
MultipleChild::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "numAtt")
  {
    value = unsetNumAtt();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this MultipleChild.
 */
SBase*
MultipleChild::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "normalClass")
  {
    return createNormalClass();
  }
  else if (elementName == "classId")
  {
    return createClassId();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this MultipleChild.
 */
int
MultipleChild::addChildObject(const std::string& elementName,
                              const SBase* element)
{
  if (elementName == "normalClass" && element->getTypeCode() ==
    SBML_TWOATONCE_NORMALCLASS)
  {
    return setNormalClass((const NormalClass*)(element));
  }
  else if (elementName == "classId" && element->getTypeCode() ==
    SBML_TWOATONCE_CLASSID)
  {
    return addClassId((const ClassId*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * MultipleChild.
 */
SBase*
MultipleChild::removeChildObject(const std::string& elementName,
                                 const std::string& id)
{
  if (elementName == "normalClass")
  {
    NormalClass * obj = getNormalClass();
    if (unsetNormalClass() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "classId")
  {
    return removeClassId(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this MultipleChild.
 */
unsigned int
MultipleChild::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "normalClass")
  {
    if (isSetNormalClass())
    {
      return 1;
    }
  }
  else if (elementName == "classId")
  {
    return getNumClassIds();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this MultipleChild.
 */
SBase*
MultipleChild::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "normalClass")
  {
    return getNormalClass();
  }
  else if (elementName == "classId")
  {
    return getClassId(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
MultipleChild::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mNormalClass != NULL)
  {
    if (mNormalClass->getId() == id)
    {
      return mNormalClass;
    }

    obj = mNormalClass->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mClassIds.getId() == id)
  {
    return &mClassIds;
  }

  obj = mClassIds.getElementBySId(id);

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
MultipleChild::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mNormalClass != NULL)
  {
    if (mNormalClass->getMetaId() == metaid)
    {
      return mNormalClass;
    }

    obj = mNormalClass->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mClassIds.getMetaId() == metaid)
  {
    return &mClassIds;
  }

  obj = mClassIds.getElementByMetaId(metaid);

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
MultipleChild::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mNormalClass, filter);

  ADD_FILTERED_LIST(ret, sublist, mClassIds, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
MultipleChild::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  TWOATONCE_CREATE_NS(twoatoncens, getSBMLNamespaces());

  if (name == "normalClass")
  {
    if (isSetNormalClass())
    {
      getErrorLog()->logPackageError("twoatonce",
        TwoatonceMultipleChildAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mNormalClass;
    mNormalClass = new NormalClass(twoatoncens);
    obj = mNormalClass;
  }
  else if (name == "listOfClassIds")
  {
    if (mClassIds.size() != 0)
    {
      getErrorLog()->logPackageError("twoatonce",
        TwoatonceMultipleChildAllowedElements, getPackageVersion(), getLevel(),
          getVersion());
    }

    obj = &mClassIds;
  }

  delete twoatoncens;

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
MultipleChild::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  unsigned int level = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && coreVersion == 1 && pkgVersion == 1)
  {
    attributes.add("id");
    attributes.add("numAtt");
  }

  if (level == 3 && coreVersion == 2 && pkgVersion == 1)
  {
    attributes.add("numAtt");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
MultipleChild::readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

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
        log->logPackageError("twoatonce",
          TwoatonceMultipleChildAllowedAttributes, pkgVersion, level, version,
            details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("twoatonce",
          TwoatonceMultipleChildAllowedCoreAttributes, pkgVersion, level,
            version, details);
      }
    }
  }

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    readL3V1V1Attributes(attributes);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    readL3V2V1Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
MultipleChild::readL3V1V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // id SId (use = "required" )
  // 

  XMLTriple tripleID("id", mURI, getPrefix());
  assigned = attributes.readInto(tripleID, mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<MultipleChild>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("twoatonce", TwoatonceIdSyntaxRule, pkgVersion,
        level, version, "The id on the <" + getElementName() + "> is '" + mId +
          "', which does not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Twoatonce attribute 'id' is missing from the "
      "<MultipleChild> element.";
    log->logPackageError("twoatonce", TwoatonceMultipleChildAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // numAtt double (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNumAtt = attributes.readInto("numAtt", mNumAtt);

  if ( mIsSetNumAtt == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Twoatonce attribute 'numAtt' from the "
        "<MultipleChild> element must be an integer.";
      log->logPackageError("twoatonce",
        TwoatonceMultipleChildNumAttMustBeDouble, pkgVersion, level, version,
          message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
MultipleChild::readL3V2V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<MultipleChild>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("twoatonce", TwoatonceIdSyntaxRule, pkgVersion,
        level, version, "The id on the <" + getElementName() + "> is '" + mId +
          "', which does not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Twoatonce attribute 'id' is missing from the "
      "<MultipleChild> element.";
    log->logPackageError("twoatonce", TwoatonceMultipleChildAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // numAtt double (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetNumAtt = attributes.readInto("numAtt", mNumAtt);

  if ( mIsSetNumAtt == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Twoatonce attribute 'numAtt' from the "
        "<MultipleChild> element must be an integer.";
      log->logPackageError("twoatonce",
        TwoatonceMultipleChildNumAttMustBeDouble, pkgVersion, level, version,
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
MultipleChild::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    writeL3V1V1Attributes(stream);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    writeL3V2V1Attributes(stream);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
MultipleChild::writeL3V1V1Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetNumAtt() == true)
  {
    stream.writeAttribute("numAtt", getPrefix(), mNumAtt);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
MultipleChild::writeL3V2V1Attributes(XMLOutputStream& stream) const
{
  if (isSetNumAtt() == true)
  {
    stream.writeAttribute("numAtt", getPrefix(), mNumAtt);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new MultipleChild_t using the given SBML Level, Version and
 * &ldquo;twoatonce&rdquo; package version.
 */
LIBSBML_EXTERN
MultipleChild_t *
MultipleChild_create(unsigned int level,
                     unsigned int version,
                     unsigned int pkgVersion)
{
  return new MultipleChild(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this MultipleChild_t object.
 */
LIBSBML_EXTERN
MultipleChild_t*
MultipleChild_clone(const MultipleChild_t* mc)
{
  if (mc != NULL)
  {
    return static_cast<MultipleChild_t*>(mc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this MultipleChild_t object.
 */
LIBSBML_EXTERN
void
MultipleChild_free(MultipleChild_t* mc)
{
  if (mc != NULL)
  {
    delete mc;
  }
}


/*
 * Returns the value of the "id" attribute of this MultipleChild_t.
 */
LIBSBML_EXTERN
char *
MultipleChild_getId(const MultipleChild_t * mc)
{
  if (mc == NULL)
  {
    return NULL;
  }

  return mc->getId().empty() ? NULL : safe_strdup(mc->getId().c_str());
}


/*
 * Returns the value of the "numAtt" attribute of this MultipleChild_t.
 */
LIBSBML_EXTERN
double
MultipleChild_getNumAtt(const MultipleChild_t * mc)
{
  return (mc != NULL) ? mc->getNumAtt() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this MultipleChild_t's "id" attribute is
 * set.
 */
LIBSBML_EXTERN
int
MultipleChild_isSetId(const MultipleChild_t * mc)
{
  return (mc != NULL) ? static_cast<int>(mc->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this MultipleChild_t's "numAtt" attribute
 * is set.
 */
LIBSBML_EXTERN
int
MultipleChild_isSetNumAtt(const MultipleChild_t * mc)
{
  return (mc != NULL) ? static_cast<int>(mc->isSetNumAtt()) : 0;
}


/*
 * Sets the value of the "id" attribute of this MultipleChild_t.
 */
LIBSBML_EXTERN
int
MultipleChild_setId(MultipleChild_t * mc, const char * id)
{
  return (mc != NULL) ? mc->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "numAtt" attribute of this MultipleChild_t.
 */
LIBSBML_EXTERN
int
MultipleChild_setNumAtt(MultipleChild_t * mc, double numAtt)
{
  return (mc != NULL) ? mc->setNumAtt(numAtt) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this MultipleChild_t.
 */
LIBSBML_EXTERN
int
MultipleChild_unsetId(MultipleChild_t * mc)
{
  return (mc != NULL) ? mc->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "numAtt" attribute of this MultipleChild_t.
 */
LIBSBML_EXTERN
int
MultipleChild_unsetNumAtt(MultipleChild_t * mc)
{
  return (mc != NULL) ? mc->unsetNumAtt() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "normalClass" element of this MultipleChild_t.
 */
LIBSBML_EXTERN
const NormalClass_t*
MultipleChild_getNormalClass(const MultipleChild_t * mc)
{
  if (mc == NULL)
  {
    return NULL;
  }

  return (NormalClass_t*)(mc->getNormalClass());
}


/*
 * Predicate returning @c 1 (true) if this MultipleChild_t's "normalClass"
 * element is set.
 */
LIBSBML_EXTERN
int
MultipleChild_isSetNormalClass(const MultipleChild_t * mc)
{
  return (mc != NULL) ? static_cast<int>(mc->isSetNormalClass()) : 0;
}


/*
 * Sets the value of the "normalClass" element of this MultipleChild_t.
 */
LIBSBML_EXTERN
int
MultipleChild_setNormalClass(MultipleChild_t * mc,
                             const NormalClass_t* normalClass)
{
  return (mc != NULL) ? mc->setNormalClass(normalClass) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new NormalClass_t object, adds it to this MultipleChild_t object
 * and returns the NormalClass_t object created.
 */
LIBSBML_EXTERN
NormalClass_t*
MultipleChild_createNormalClass(MultipleChild_t* mc)
{
  if (mc == NULL)
  {
    return NULL;
  }

  return (NormalClass_t*)(mc->createNormalClass());
}


/*
 * Unsets the value of the "normalClass" element of this MultipleChild_t.
 */
LIBSBML_EXTERN
int
MultipleChild_unsetNormalClass(MultipleChild_t * mc)
{
  return (mc != NULL) ? mc->unsetNormalClass() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing ClassId_t objects from this MultipleChild_t.
 */
LIBSBML_EXTERN
ListOf_t*
MultipleChild_getListOfClassIds(MultipleChild_t* mc)
{
  return (mc != NULL) ? mc->getListOfClassIds() : NULL;
}


/*
 * Get a ClassId_t from the MultipleChild_t.
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_getClassId(MultipleChild_t* mc, unsigned int n)
{
  return (mc != NULL) ? mc->getClassId(n) : NULL;
}


/*
 * Get a ClassId_t from the MultipleChild_t based on its identifier.
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_getClassIdById(MultipleChild_t* mc, const char *sid)
{
  return (mc != NULL && sid != NULL) ? mc->getClassId(sid) : NULL;
}


/*
 * Adds a copy of the given ClassId_t to this MultipleChild_t.
 */
LIBSBML_EXTERN
int
MultipleChild_addClassId(MultipleChild_t* mc, const ClassId_t* ci)
{
  return (mc != NULL) ? mc->addClassId(ci) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of ClassId_t objects in this MultipleChild_t.
 */
LIBSBML_EXTERN
unsigned int
MultipleChild_getNumClassIds(MultipleChild_t* mc)
{
  return (mc != NULL) ? mc->getNumClassIds() : SBML_INT_MAX;
}


/*
 * Creates a new ClassId_t object, adds it to this MultipleChild_t object and
 * returns the ClassId_t object created.
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_createClassId(MultipleChild_t* mc)
{
  return (mc != NULL) ? mc->createClassId() : NULL;
}


/*
 * Removes the nth ClassId_t from this MultipleChild_t and returns a pointer to
 * it.
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_removeClassId(MultipleChild_t* mc, unsigned int n)
{
  return (mc != NULL) ? mc->removeClassId(n) : NULL;
}


/*
 * Removes the ClassId_t from this MultipleChild_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
ClassId_t*
MultipleChild_removeClassIdById(MultipleChild_t* mc, const char* sid)
{
  return (mc != NULL && sid != NULL) ? mc->removeClassId(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * MultipleChild_t object have been set.
 */
LIBSBML_EXTERN
int
MultipleChild_hasRequiredAttributes(const MultipleChild_t * mc)
{
  return (mc != NULL) ? static_cast<int>(mc->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


