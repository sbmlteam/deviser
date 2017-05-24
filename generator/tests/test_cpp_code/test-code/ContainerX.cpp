/**
 * @file ContainerX.cpp
 * @brief Implementation of the ContainerX class.
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
#include <sbml/packages/x/sbml/ContainerX.h>
#include <sbml/packages/x/validator/XSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ContainerX using the given SBML Level, Version and
 * &ldquo;x&rdquo; package version.
 */
ContainerX::ContainerX(unsigned int level,
                       unsigned int version,
                       unsigned int pkgVersion)
  : SBase(level, version)
  , mFreds (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new XPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new ContainerX using the given XPkgNamespaces object.
 */
ContainerX::ContainerX(XPkgNamespaces *xns)
  : SBase(xns)
  , mFreds (xns)
{
  setElementNamespace(xns->getURI());
  connectToChild();
  loadPlugins(xns);
}


/*
 * Copy constructor for ContainerX.
 */
ContainerX::ContainerX(const ContainerX& orig)
  : SBase( orig )
  , mFreds ( orig.mFreds )
{
  connectToChild();
}


/*
 * Assignment operator for ContainerX.
 */
ContainerX&
ContainerX::operator=(const ContainerX& rhs)
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
 * Creates and returns a deep copy of this ContainerX object.
 */
ContainerX*
ContainerX::clone() const
{
  return new ContainerX(*this);
}


/*
 * Destructor for ContainerX.
 */
ContainerX::~ContainerX()
{
}


/*
 * Returns the ListOfFreds from this ContainerX.
 */
const ListOfFreds*
ContainerX::getListOfFreds() const
{
  return &mFreds;
}


/*
 * Returns the ListOfFreds from this ContainerX.
 */
ListOfFreds*
ContainerX::getListOfFreds()
{
  return &mFreds;
}


/*
 * Get a Fred from the ContainerX.
 */
Fred*
ContainerX::getFred(unsigned int n)
{
  return mFreds.get(n);
}


/*
 * Get a Fred from the ContainerX.
 */
const Fred*
ContainerX::getFred(unsigned int n) const
{
  return mFreds.get(n);
}


/*
 * Get a Fred from the ContainerX based on its identifier.
 */
Fred*
ContainerX::getFred(const std::string& sid)
{
  return mFreds.get(sid);
}


/*
 * Get a Fred from the ContainerX based on its identifier.
 */
const Fred*
ContainerX::getFred(const std::string& sid) const
{
  return mFreds.get(sid);
}


/*
 * Adds a copy of the given Fred to this ContainerX.
 */
int
ContainerX::addFred(const Fred* f)
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
 * Get the number of Fred objects in this ContainerX.
 */
unsigned int
ContainerX::getNumFreds() const
{
  return mFreds.size();
}


/*
 * Creates a new Fred object, adds it to this ContainerX object and returns the
 * Fred object created.
 */
Fred*
ContainerX::createFred()
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
 * Removes the nth Fred from this ContainerX and returns a pointer to it.
 */
Fred*
ContainerX::removeFred(unsigned int n)
{
  return mFreds.remove(n);
}


/*
 * Removes the Fred from this ContainerX based on its identifier and returns a
 * pointer to it.
 */
Fred*
ContainerX::removeFred(const std::string& sid)
{
  return mFreds.remove(sid);
}


/*
 * Returns the XML element name of this ContainerX object.
 */
const std::string&
ContainerX::getElementName() const
{
  static const string name = "containerX";
  return name;
}


/*
 * Returns the libSBML type code for this ContainerX object.
 */
int
ContainerX::getTypeCode() const
{
  return SBML_X_CONTAINERX;
}


/*
 * Predicate returning @c true if all the required elements for this ContainerX
 * object have been set.
 */
bool
ContainerX::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
ContainerX::writeElements(XMLOutputStream& stream) const
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
ContainerX::accept(SBMLVisitor& v) const
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
ContainerX::setSBMLDocument(SBMLDocument* d)
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
ContainerX::connectToChild()
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
ContainerX::enablePackageInternal(const std::string& pkgURI,
                                  const std::string& pkgPrefix,
                                  bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  mFreds.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::getAttribute(const std::string& attributeName,
                         const char* value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this ContainerX's attribute "attributeName"
 * is set.
 */
bool
ContainerX::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::setAttribute(const std::string& attributeName, const char* value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this ContainerX.
 */
int
ContainerX::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this ContainerX.
 */
SBase*
ContainerX::createChildObject(const std::string& elementName)
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
 * Adds a new "elementName" object to this ContainerX.
 */
int
ContainerX::addChildObject(const std::string& elementName,
                           const SBase* element)
{
  if (elementName == "fred" && element->getTypeCode() == SBML_FRED)
  {
    return addFred((const Fred*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * ContainerX.
 */
SBase*
ContainerX::removeChildObject(const std::string& elementName,
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
 * Returns the number of "elementName" in this ContainerX.
 */
unsigned int
ContainerX::getNumObjects(const std::string& elementName)
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
 * Returns the nth object of "objectName" in this ContainerX.
 */
SBase*
ContainerX::getObject(const std::string& elementName, unsigned int index)
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
ContainerX::getElementBySId(const std::string& id)
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
ContainerX::getElementByMetaId(const std::string& metaid)
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
ContainerX::getAllElements(ElementFilter* filter)
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
ContainerX::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfFreds")
  {
    if (mFreds.size() != 0)
    {
      getErrorLog()->logPackageError("x", XContainerXAllowedElements,
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
 * Creates a new ContainerX_t using the given SBML Level, Version and
 * &ldquo;x&rdquo; package version.
 */
LIBSBML_EXTERN
ContainerX_t *
ContainerX_create(unsigned int level,
                  unsigned int version,
                  unsigned int pkgVersion)
{
  return new ContainerX(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ContainerX_t object.
 */
LIBSBML_EXTERN
ContainerX_t*
ContainerX_clone(const ContainerX_t* cx)
{
  if (cx != NULL)
  {
    return static_cast<ContainerX_t*>(cx->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ContainerX_t object.
 */
LIBSBML_EXTERN
void
ContainerX_free(ContainerX_t* cx)
{
  if (cx != NULL)
  {
    delete cx;
  }
}


/*
 * Returns a ListOf_t* containing Fred_t objects from this ContainerX_t.
 */
LIBSBML_EXTERN
ListOf_t*
ContainerX_getListOfFreds(ContainerX_t* cx)
{
  return (cx != NULL) ? cx->getListOfFreds() : NULL;
}


/*
 * Get a Fred_t from the ContainerX_t.
 */
LIBSBML_EXTERN
const Fred_t*
ContainerX_getFred(ContainerX_t* cx, unsigned int n)
{
  return (cx != NULL) ? cx->getFred(n) : NULL;
}


/*
 * Get a Fred_t from the ContainerX_t based on its identifier.
 */
LIBSBML_EXTERN
const Fred_t*
ContainerX_getFredById(ContainerX_t* cx, const char *sid)
{
  return (cx != NULL && sid != NULL) ? cx->getFred(sid) : NULL;
}


/*
 * Adds a copy of the given Fred_t to this ContainerX_t.
 */
LIBSBML_EXTERN
int
ContainerX_addFred(ContainerX_t* cx, const Fred_t* f)
{
  return (cx != NULL) ? cx->addFred(f) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Fred_t objects in this ContainerX_t.
 */
LIBSBML_EXTERN
unsigned int
ContainerX_getNumFreds(ContainerX_t* cx)
{
  return (cx != NULL) ? cx->getNumFreds() : SBML_INT_MAX;
}


/*
 * Creates a new Fred_t object, adds it to this ContainerX_t object and returns
 * the Fred_t object created.
 */
LIBSBML_EXTERN
Fred_t*
ContainerX_createFred(ContainerX_t* cx)
{
  return (cx != NULL) ? cx->createFred() : NULL;
}


/*
 * Removes the nth Fred_t from this ContainerX_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Fred_t*
ContainerX_removeFred(ContainerX_t* cx, unsigned int n)
{
  return (cx != NULL) ? cx->removeFred(n) : NULL;
}


/*
 * Removes the Fred_t from this ContainerX_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
Fred_t*
ContainerX_removeFredById(ContainerX_t* cx, const char* sid)
{
  return (cx != NULL && sid != NULL) ? cx->removeFred(sid) : NULL;
}


/*
 * Predicate returning @c 1 if all the required elements for this ContainerX_t
 * object have been set.
 */
LIBSBML_EXTERN
int
ContainerX_hasRequiredElements(const ContainerX_t * cx)
{
  return (cx != NULL) ? static_cast<int>(cx->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


