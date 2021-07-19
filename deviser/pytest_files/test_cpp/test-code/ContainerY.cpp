/**
 * @file ContainerY.cpp
 * @brief Implementation of the ContainerY class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
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
#include <sbml/packages/x/sbml/ContainerY.h>
#include <sbml/packages/x/validator/XSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ContainerY using the given SBML Level, Version and
 * &ldquo;x&rdquo; package version.
 */
ContainerY::ContainerY(unsigned int level,
                       unsigned int version,
                       unsigned int pkgVersion)
  : SBase(level, version)
  , mFreds (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new XPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new ContainerY using the given XPkgNamespaces object.
 */
ContainerY::ContainerY(XPkgNamespaces *xns)
  : SBase(xns)
  , mFreds (xns)
{
  setElementNamespace(xns->getURI());
  connectToChild();
  loadPlugins(xns);
}


/*
 * Copy constructor for ContainerY.
 */
ContainerY::ContainerY(const ContainerY& orig)
  : SBase( orig )
  , mFreds ( orig.mFreds )
{
  connectToChild();
}


/*
 * Assignment operator for ContainerY.
 */
ContainerY&
ContainerY::operator=(const ContainerY& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mFreds = rhs.mFreds;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ContainerY object.
 */
ContainerY*
ContainerY::clone() const
{
  return new ContainerY(*this);
}


/*
 * Destructor for ContainerY.
 */
ContainerY::~ContainerY()
{
}


/*
 * Returns the ListOfFreds from this ContainerY.
 */
const ListOfFreds*
ContainerY::getListOfFreds() const
{
  return &mFreds;
}


/*
 * Returns the ListOfFreds from this ContainerY.
 */
ListOfFreds*
ContainerY::getListOfFreds()
{
  return &mFreds;
}


/*
 * Get a Fred from the ContainerY.
 */
Fred*
ContainerY::getFred(unsigned int n)
{
  return mFreds.get(n);
}


/*
 * Get a Fred from the ContainerY.
 */
const Fred*
ContainerY::getFred(unsigned int n) const
{
  return mFreds.get(n);
}


/*
 * Get a Fred from the ContainerY based on its identifier.
 */
Fred*
ContainerY::getFred(const std::string& sid)
{
  return mFreds.get(sid);
}


/*
 * Get a Fred from the ContainerY based on its identifier.
 */
const Fred*
ContainerY::getFred(const std::string& sid) const
{
  return mFreds.get(sid);
}


/*
 * Adds a copy of the given Fred to this ContainerY.
 */
int
ContainerY::addFred(const Fred* f)
{
  if (f == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (f->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != f->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != f->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(f)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (f->isSetId() && (mFreds.get(f->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mFreds.append(f);
  }
}


/*
 * Get the number of Fred objects in this ContainerY.
 */
unsigned int
ContainerY::getNumFreds() const
{
  return mFreds.size();
}


/*
 * Creates a new Fred object, adds it to this ContainerY object and returns the
 * Fred object created.
 */
Fred*
ContainerY::createFred()
{
  Fred* f = NULL;

  try
  {
    X_CREATE_NS(xns, getSBMLNamespaces());
    f = new Fred(xns);
    delete xns;
  }
  catch (...)
  {
  }

  if (f != NULL)
  {
    mFreds.appendAndOwn(f);
  }

  return f;
}


/*
 * Removes the nth Fred from this ContainerY and returns a pointer to it.
 */
Fred*
ContainerY::removeFred(unsigned int n)
{
  return mFreds.remove(n);
}


/*
 * Removes the Fred from this ContainerY based on its identifier and returns a
 * pointer to it.
 */
Fred*
ContainerY::removeFred(const std::string& sid)
{
  return mFreds.remove(sid);
}


/*
 * Returns the XML element name of this ContainerY object.
 */
const std::string&
ContainerY::getElementName() const
{
  static const string name = "containerY";
  return name;
}


/*
 * Returns the libSBML type code for this ContainerY object.
 */
int
ContainerY::getTypeCode() const
{
  return SBML_X_CONTAINERX;
}


/*
 * Predicate returning @c true if all the required elements for this ContainerY
 * object have been set.
 */
bool
ContainerY::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
ContainerY::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (getNumFreds() > 0)
  {
    mFreds.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
ContainerY::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  mFreds.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
ContainerY::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  mFreds.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
ContainerY::connectToChild()
{
  SBase::connectToChild();

  mFreds.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
ContainerY::enablePackageInternal(const std::string& pkgURI,
                                  const std::string& pkgPrefix,
                                  bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  mFreds.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::getAttribute(const std::string& attributeName,
                         const char* value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this ContainerY's attribute "attributeName"
 * is set.
 */
bool
ContainerY::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::setAttribute(const std::string& attributeName, const char* value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this ContainerY.
 */
int
ContainerY::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this ContainerY.
 */
SBase*
ContainerY::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "fred")
  {
    return createFred();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this ContainerY.
 */
int
ContainerY::addChildObject(const std::string& elementName,
                           const SBase* element)
{
  if (elementName == "fred" && element->getTypeCode() == SBML_X_FRED)
  {
    return addFred((const Fred*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * ContainerY.
 */
SBase*
ContainerY::removeChildObject(const std::string& elementName,
                              const std::string& id)
{
  if (elementName == "fred")
  {
    return removeFred(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this ContainerY.
 */
unsigned int
ContainerY::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "fred")
  {
    return getNumFreds();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this ContainerY.
 */
SBase*
ContainerY::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "fred")
  {
    return getFred(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
ContainerY::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mFreds.getElementBySId(id);

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
ContainerY::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mFreds.getMetaId() == metaid)
  {
    return &mFreds;
  }

  obj = mFreds.getElementByMetaId(metaid);

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
ContainerY::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mFreds, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
ContainerY::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfFreds")
  {
    if (mFreds.size() != 0)
    {
      getErrorLog()->logPackageError("x", XContainerYAllowedElements,
        getPackageVersion(), getLevel(), getVersion());
    }

    obj = &mFreds;
  }

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ContainerY_t using the given SBML Level, Version and
 * &ldquo;x&rdquo; package version.
 */
LIBSBML_EXTERN
ContainerY_t *
ContainerY_create(unsigned int level,
                  unsigned int version,
                  unsigned int pkgVersion)
{
  return new ContainerY(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ContainerY_t object.
 */
LIBSBML_EXTERN
ContainerY_t*
ContainerY_clone(const ContainerY_t* cy)
{
  if (cy != NULL)
  {
    return static_cast<ContainerY_t*>(cy->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ContainerY_t object.
 */
LIBSBML_EXTERN
void
ContainerY_free(ContainerY_t* cy)
{
  if (cy != NULL)
  {
    delete cy;
  }
}


/*
 * Returns a ListOf_t* containing Fred_t objects from this ContainerY_t.
 */
LIBSBML_EXTERN
ListOf_t*
ContainerY_getListOfFreds(ContainerY_t* cy)
{
  return (cy != NULL) ? cy->getListOfFreds() : NULL;
}


/*
 * Get a Fred_t from the ContainerY_t.
 */
LIBSBML_EXTERN
const Fred_t*
ContainerY_getFred(ContainerY_t* cy, unsigned int n)
{
  return (cy != NULL) ? cy->getFred(n) : NULL;
}


/*
 * Get a Fred_t from the ContainerY_t based on its identifier.
 */
LIBSBML_EXTERN
const Fred_t*
ContainerY_getFredById(ContainerY_t* cy, const char *sid)
{
  return (cy != NULL && sid != NULL) ? cy->getFred(sid) : NULL;
}


/*
 * Adds a copy of the given Fred_t to this ContainerY_t.
 */
LIBSBML_EXTERN
int
ContainerY_addFred(ContainerY_t* cy, const Fred_t* f)
{
  return (cy != NULL) ? cy->addFred(f) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Fred_t objects in this ContainerY_t.
 */
LIBSBML_EXTERN
unsigned int
ContainerY_getNumFreds(ContainerY_t* cy)
{
  return (cy != NULL) ? cy->getNumFreds() : SBML_INT_MAX;
}


/*
 * Creates a new Fred_t object, adds it to this ContainerY_t object and returns
 * the Fred_t object created.
 */
LIBSBML_EXTERN
Fred_t*
ContainerY_createFred(ContainerY_t* cy)
{
  return (cy != NULL) ? cy->createFred() : NULL;
}


/*
 * Removes the nth Fred_t from this ContainerY_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Fred_t*
ContainerY_removeFred(ContainerY_t* cy, unsigned int n)
{
  return (cy != NULL) ? cy->removeFred(n) : NULL;
}


/*
 * Removes the Fred_t from this ContainerY_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
Fred_t*
ContainerY_removeFredById(ContainerY_t* cy, const char* sid)
{
  return (cy != NULL && sid != NULL) ? cy->removeFred(sid) : NULL;
}


/*
 * Predicate returning @c 1 if all the required elements for this ContainerY_t
 * object have been set.
 */
LIBSBML_EXTERN
int
ContainerY_hasRequiredElements(const ContainerY_t * cy)
{
  return (cy != NULL) ? static_cast<int>(cy->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


