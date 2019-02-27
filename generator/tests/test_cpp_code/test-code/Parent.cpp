/**
 * @file Parent.cpp
 * @brief Implementation of the Parent class.
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
#include <sbml/packages/nasty/sbml/Parent.h>
#include <sbml/packages/nasty/validator/NastySBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Parent using the given SBML Level, Version and
 * &ldquo;nasty&rdquo; package version.
 */
Parent::Parent(unsigned int level,
               unsigned int version,
               unsigned int pkgVersion)
  : SBase(level, version)
  , mChildren (level, version, pkgVersion)
  , mSprogs (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new NastyPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new Parent using the given NastyPkgNamespaces object.
 */
Parent::Parent(NastyPkgNamespaces *nastyns)
  : SBase(nastyns)
  , mChildren (nastyns)
  , mSprogs (nastyns)
{
  setElementNamespace(nastyns->getURI());
  connectToChild();
  loadPlugins(nastyns);
}


/*
 * Copy constructor for Parent.
 */
Parent::Parent(const Parent& orig)
  : SBase( orig )
  , mChildren ( orig.mChildren )
  , mSprogs ( orig.mSprogs )
{
  connectToChild();
}


/*
 * Assignment operator for Parent.
 */
Parent&
Parent::operator=(const Parent& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mChildren = rhs.mChildren;
    mSprogs = rhs.mSprogs;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Parent object.
 */
Parent*
Parent::clone() const
{
  return new Parent(*this);
}


/*
 * Destructor for Parent.
 */
Parent::~Parent()
{
}


/*
 * Returns the ListOfChildren from this Parent.
 */
const ListOfChildren*
Parent::getListOfChildren() const
{
  return &mChildren;
}


/*
 * Returns the ListOfChildren from this Parent.
 */
ListOfChildren*
Parent::getListOfChildren()
{
  return &mChildren;
}


/*
 * Get a Child from the Parent.
 */
Child*
Parent::getChild(unsigned int n)
{
  return mChildren.get(n);
}


/*
 * Get a Child from the Parent.
 */
const Child*
Parent::getChild(unsigned int n) const
{
  return mChildren.get(n);
}


/*
 * Adds a copy of the given Child to this Parent.
 */
int
Parent::addChild(const Child* c)
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
    return mChildren.append(c);
  }
}


/*
 * Get the number of Child objects in this Parent.
 */
unsigned int
Parent::getNumChildren() const
{
  return mChildren.size();
}


/*
 * Creates a new Child object, adds it to this Parent object and returns the
 * Child object created.
 */
Child*
Parent::createChild()
{
  Child* c = NULL;

  try
  {
    NASTY_CREATE_NS(nastyns, getSBMLNamespaces());
    c = new Child(nastyns);
    delete nastyns;
  }
  catch (...)
  {
  }

  if (c != NULL)
  {
    mChildren.appendAndOwn(c);
  }

  return c;
}


/*
 * Removes the nth Child from this Parent and returns a pointer to it.
 */
Child*
Parent::removeChild(unsigned int n)
{
  return mChildren.remove(n);
}


/*
 * Returns the ListOfSprogs from this Parent.
 */
const ListOfSprogs*
Parent::getListOfSprogs() const
{
  return &mSprogs;
}


/*
 * Returns the ListOfSprogs from this Parent.
 */
ListOfSprogs*
Parent::getListOfSprogs()
{
  return &mSprogs;
}


/*
 * Get a Sprog from the Parent.
 */
Sprog*
Parent::getSprog(unsigned int n)
{
  return mSprogs.get(n);
}


/*
 * Get a Sprog from the Parent.
 */
const Sprog*
Parent::getSprog(unsigned int n) const
{
  return mSprogs.get(n);
}


/*
 * Adds a copy of the given Sprog to this Parent.
 */
int
Parent::addSprog(const Sprog* s)
{
  if (s == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (s->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != s->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != s->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(s)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mSprogs.append(s);
  }
}


/*
 * Get the number of Sprog objects in this Parent.
 */
unsigned int
Parent::getNumSprogs() const
{
  return mSprogs.size();
}


/*
 * Creates a new Sprog object, adds it to this Parent object and returns the
 * Sprog object created.
 */
Sprog*
Parent::createSprog()
{
  Sprog* s = NULL;

  try
  {
    NASTY_CREATE_NS(nastyns, getSBMLNamespaces());
    s = new Sprog(nastyns);
    delete nastyns;
  }
  catch (...)
  {
  }

  if (s != NULL)
  {
    mSprogs.appendAndOwn(s);
  }

  return s;
}


/*
 * Removes the nth Sprog from this Parent and returns a pointer to it.
 */
Sprog*
Parent::removeSprog(unsigned int n)
{
  return mSprogs.remove(n);
}


/*
 * Returns the XML element name of this Parent object.
 */
const std::string&
Parent::getElementName() const
{
  static const string name = "parent";
  return name;
}


/*
 * Returns the libSBML type code for this Parent object.
 */
int
Parent::getTypeCode() const
{
  return SBML_NASTY_PARENT;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Parent::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (getNumChildren() > 0)
  {
    mChildren.write(stream);
  }

  if (getNumSprogs() > 0)
  {
    mSprogs.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Parent::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  mChildren.accept(v);

  mSprogs.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Parent::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  mChildren.setSBMLDocument(d);

  mSprogs.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Parent::connectToChild()
{
  SBase::connectToChild();

  mChildren.connectToParent(this);

  mSprogs.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Parent::enablePackageInternal(const std::string& pkgURI,
                              const std::string& pkgPrefix,
                              bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  mChildren.enablePackageInternal(pkgURI, pkgPrefix, flag);

  mSprogs.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
Parent::updateSBMLNamespace(const std::string& package,
                            unsigned int level,
                            unsigned int version)
{
  SBase::updateSBMLNamespace(package, level, version);

  mChildren.updateSBMLNamespace(package, level, version);

  mSprogs.updateSBMLNamespace(package, level, version);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::getAttribute(const std::string& attributeName,
                     unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::getAttribute(const std::string& attributeName,
                     std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Parent's attribute "attributeName" is
 * set.
 */
bool
Parent::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::setAttribute(const std::string& attributeName,
                     const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Parent.
 */
int
Parent::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this Parent.
 */
SBase*
Parent::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "child")
  {
    return createChild();
  }
  else if (elementName == "sprog")
  {
    return createSprog();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this Parent.
 */
int
Parent::addChildObject(const std::string& elementName, const SBase* element)
{
  if (elementName == "child" && element->getTypeCode() == SBML_NASTY_CHILD)
  {
    return addChild((const Child*)(element));
  }
  else if (elementName == "sprog" && element->getTypeCode() ==
    SBML_NASTY_SPROG)
  {
    return addSprog((const Sprog*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Parent.
 */
SBase*
Parent::removeChildObject(const std::string& elementName,
                          const std::string& id)
{
  if (elementName == "child")
  {
    for (unsigned int i = 0; i < getNumChildren(); i++)
    {
      if (getChild(i)->getId() == id)
      {
        return removeChild(i);
      }
    }
  }
  else if (elementName == "sprog")
  {
    for (unsigned int i = 0; i < getNumSprogs(); i++)
    {
      if (getSprog(i)->getId() == id)
      {
        return removeSprog(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this Parent.
 */
unsigned int
Parent::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "child")
  {
    return getNumChildren();
  }
  else if (elementName == "sprog")
  {
    return getNumSprogs();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this Parent.
 */
SBase*
Parent::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "child")
  {
    return getChild(index);
  }
  else if (elementName == "sprog")
  {
    return getSprog(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
Parent::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mChildren.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mSprogs.getElementBySId(id);

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
Parent::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mChildren.getMetaId() == metaid)
  {
    return &mChildren;
  }

  if (mSprogs.getMetaId() == metaid)
  {
    return &mSprogs;
  }

  obj = mChildren.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mSprogs.getElementByMetaId(metaid);

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
Parent::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mChildren, filter);
  ADD_FILTERED_LIST(ret, sublist, mSprogs, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
Parent::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfChildren")
  {
    if (mChildren.size() != 0)
    {
      getErrorLog()->logPackageError("nasty", NastyParentAllowedElements,
        getPackageVersion(), getLevel(), getVersion());
    }

    obj = &mChildren;
  }
  else if (name == "listOfSprogs")
  {
    if (mSprogs.size() != 0)
    {
      getErrorLog()->logPackageError("nasty", NastyParentAllowedElements,
        getPackageVersion(), getLevel(), getVersion());
    }

    obj = &mSprogs;
  }

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Parent_t using the given SBML Level, Version and
 * &ldquo;nasty&rdquo; package version.
 */
LIBSBML_EXTERN
Parent_t *
Parent_create(unsigned int level,
              unsigned int version,
              unsigned int pkgVersion)
{
  return new Parent(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Parent_t object.
 */
LIBSBML_EXTERN
Parent_t*
Parent_clone(const Parent_t* p)
{
  if (p != NULL)
  {
    return static_cast<Parent_t*>(p->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Parent_t object.
 */
LIBSBML_EXTERN
void
Parent_free(Parent_t* p)
{
  if (p != NULL)
  {
    delete p;
  }
}


/*
 * Returns a ListOf_t * containing Child_t objects from this Parent_t.
 */
LIBSBML_EXTERN
ListOf_t*
Parent_getListOfChildren(Parent_t* p)
{
  return (p != NULL) ? p->getListOfChildren() : NULL;
}


/*
 * Get a Child_t from the Parent_t.
 */
LIBSBML_EXTERN
Child_t*
Parent_getChild(Parent_t* p, unsigned int n)
{
  return (p != NULL) ? p->getChild(n) : NULL;
}


/*
 * Adds a copy of the given Child_t to this Parent_t.
 */
LIBSBML_EXTERN
int
Parent_addChild(Parent_t* p, const Child_t* c)
{
  return (p != NULL) ? p->addChild(c) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Child_t objects in this Parent_t.
 */
LIBSBML_EXTERN
unsigned int
Parent_getNumChildren(Parent_t* p)
{
  return (p != NULL) ? p->getNumChildren() : SBML_INT_MAX;
}


/*
 * Creates a new Child_t object, adds it to this Parent_t object and returns
 * the Child_t object created.
 */
LIBSBML_EXTERN
Child_t*
Parent_createChild(Parent_t* p)
{
  return (p != NULL) ? p->createChild() : NULL;
}


/*
 * Removes the nth Child_t from this Parent_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Child_t*
Parent_removeChild(Parent_t* p, unsigned int n)
{
  return (p != NULL) ? p->removeChild(n) : NULL;
}


/*
 * Returns a ListOf_t * containing Sprog_t objects from this Parent_t.
 */
LIBSBML_EXTERN
ListOf_t*
Parent_getListOfSprogs(Parent_t* p)
{
  return (p != NULL) ? p->getListOfSprogs() : NULL;
}


/*
 * Get a Sprog_t from the Parent_t.
 */
LIBSBML_EXTERN
Sprog_t*
Parent_getSprog(Parent_t* p, unsigned int n)
{
  return (p != NULL) ? p->getSprog(n) : NULL;
}


/*
 * Adds a copy of the given Sprog_t to this Parent_t.
 */
LIBSBML_EXTERN
int
Parent_addSprog(Parent_t* p, const Sprog_t* s)
{
  return (p != NULL) ? p->addSprog(s) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Sprog_t objects in this Parent_t.
 */
LIBSBML_EXTERN
unsigned int
Parent_getNumSprogs(Parent_t* p)
{
  return (p != NULL) ? p->getNumSprogs() : SBML_INT_MAX;
}


/*
 * Creates a new Sprog_t object, adds it to this Parent_t object and returns
 * the Sprog_t object created.
 */
LIBSBML_EXTERN
Sprog_t*
Parent_createSprog(Parent_t* p)
{
  return (p != NULL) ? p->createSprog() : NULL;
}


/*
 * Removes the nth Sprog_t from this Parent_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Sprog_t*
Parent_removeSprog(Parent_t* p, unsigned int n)
{
  return (p != NULL) ? p->removeSprog(n) : NULL;
}




LIBSBML_CPP_NAMESPACE_END


