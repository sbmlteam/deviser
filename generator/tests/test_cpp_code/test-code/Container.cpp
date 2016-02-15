/**
 * @file Container.cpp
 * @brief Implementation of the Container class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
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
#include <sbml/packages/test/sbml/Container.h>
#include <sbml/packages/test/validator/TestSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Container using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
Container::Container(unsigned int level,
                     unsigned int version,
                     unsigned int pkgVersion)
  : SBase(level, version)
  , mMyLoTests (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new Container using the given TestPkgNamespaces object.
 */
Container::Container(TestPkgNamespaces *testns)
  : SBase(testns)
  , mMyLoTests (testns)
{
  setElementNamespace(testns->getURI());
  connectToChild();
  loadPlugins(testns);
}


/*
 * Copy constructor for Container.
 */
Container::Container(const Container& orig)
  : SBase( orig )
  , mMyLoTests ( orig.mMyLoTests )
{
  connectToChild();
}


/*
 * Assignment operator for Container.
 */
Container&
Container::operator=(const Container& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mMyLoTests = rhs.mMyLoTests;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Container object.
 */
Container*
Container::clone() const
{
  return new Container(*this);
}


/*
 * Destructor for Container.
 */
Container::~Container()
{
}


/*
 * Returns the ListOfMyLoTests from this Container.
 */
const ListOfMyLoTests*
Container::getListOfMyLoTests() const
{
  return &mMyLoTests;
}


/*
 * Returns the ListOfMyLoTests from this Container.
 */
ListOfMyLoTests*
Container::getListOfMyLoTests()
{
  return &mMyLoTests;
}


/*
 * Get a MyLoTest from the Container.
 */
MyLoTest*
Container::getMyLoTest(unsigned int n)
{
  return mMyLoTests.get(n);
}


/*
 * Get a MyLoTest from the Container.
 */
const MyLoTest*
Container::getMyLoTest(unsigned int n) const
{
  return mMyLoTests.get(n);
}


/*
 * Adds a copy of the given MyLoTest to this Container.
 */
int
Container::addMyLoTest(const MyLoTest* mlt)
{
  if (mlt == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (mlt->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != mlt->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != mlt->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(mlt)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    mMyLoTests.append(mlt);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of MyLoTest objects in this Container.
 */
unsigned int
Container::getNumMyLoTests() const
{
  return mMyLoTests.size();
}


/*
 * Creates a new MyLoTest object, adds it to this Container object and returns
 * the MyLoTest object created.
 */
MyLoTest*
Container::createMyLoTest()
{
  MyLoTest* mlt = NULL;

  try
  {
    TEST_CREATE_NS(testns, getSBMLNamespaces());
    mlt = new MyLoTest(testns);
    delete testns;
  }
  catch (...)
  {
  }

  if (mlt != NULL)
  {
    mMyLoTests.appendAndOwn(mlt);
  }

  return mlt;
}


/*
 * Removes the nth MyLoTest from this Container and returns a pointer to it.
 */
MyLoTest*
Container::removeMyLoTest(unsigned int n)
{
  return mMyLoTests.remove(n);
}


/*
 * Returns the XML element name of this Container object.
 */
const std::string&
Container::getElementName() const
{
  static const string name = "container";
  return name;
}


/*
 * Returns the libSBML type code for this Container object.
 */
int
Container::getTypeCode() const
{
  return SBML_TEST_CONTAINER;
}


/*
 * Predicate returning @c true if all the required elements for this Container
 * object have been set.
 */
bool
Container::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Container::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (getNumMyLoTests() > 0)
  {
    mMyLoTests.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Container::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  mMyLoTests.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Container::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  mMyLoTests.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Container::connectToChild()
{
  SBase::connectToChild();

  mMyLoTests.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Container::enablePackageInternal(const std::string& pkgURI,
                                 const std::string& pkgPrefix,
                                 bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  mMyLoTests.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
Container::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mMyLoTests.getElementBySId(id);

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
Container::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mMyLoTests.getMetaId() == metaid)
  {
    return &mMyLoTests;
  }

  obj = mMyLoTests.getElementByMetaId(metaid);

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
Container::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mMyLoTests, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
Container::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfMyLoTests")
  {
    if (mMyLoTests.size() != 0)
    {
      getErrorLog()->logPackageError("test", TestContainerAllowedElements,
        getPackageVersion(), getLevel(), getVersion());
    }

    obj = &mMyLoTests;
  }

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Container_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
Container_t *
Container_create(unsigned int level,
                 unsigned int version,
                 unsigned int pkgVersion)
{
  return new Container(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Container_t object.
 */
LIBSBML_EXTERN
Container_t*
Container_clone(const Container_t* c)
{
  if (c != NULL)
  {
    return static_cast<Container_t*>(c->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Container_t object.
 */
LIBSBML_EXTERN
void
Container_free(Container_t* c)
{
  if (c != NULL)
  {
    delete c;
  }
}


/*
 * Returns a ListOf_t* containing MyLoTest_t objects from this Container_t.
 */
LIBSBML_EXTERN
ListOf_t*
Container_getListOfMyLoTests(Container_t* c)
{
  return (c != NULL) ? c->getListOfMyLoTests() : NULL;
}


/*
 * Get a MyLoTest_t from the Container_t.
 */
LIBSBML_EXTERN
const MyLoTest_t*
Container_getMyLoTest(Container_t* c, unsigned int n)
{
  return (c != NULL) ? c->getMyLoTest(n) : NULL;
}


/*
 * Adds a copy of the given MyLoTest_t to this Container_t.
 */
LIBSBML_EXTERN
int
Container_addMyLoTest(Container_t* c, const MyLoTest_t* mlt)
{
  return (c != NULL) ? c->addMyLoTest(mlt) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of MyLoTest_t objects in this Container_t.
 */
LIBSBML_EXTERN
unsigned int
Container_getNumMyLoTests(Container_t* c)
{
  return (c != NULL) ? c->getNumMyLoTests() : SBML_INT_MAX;
}


/*
 * Creates a new MyLoTest_t object, adds it to this Container_t object and
 * returns the MyLoTest_t object created.
 */
LIBSBML_EXTERN
MyLoTest_t*
Container_createMyLoTest(Container_t* c)
{
  return (c != NULL) ? c->createMyLoTest() : NULL;
}


/*
 * Removes the nth MyLoTest_t from this Container_t and returns a pointer to
 * it.
 */
LIBSBML_EXTERN
MyLoTest_t*
Container_removeMyLoTest(Container_t* c, unsigned int n)
{
  return (c != NULL) ? c->removeMyLoTest(n) : NULL;
}


/*
 * Predicate returning @c 1 if all the required elements for this Container_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Container_hasRequiredElements(const Container_t * c)
{
  return (c != NULL) ? static_cast<int>(c->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


