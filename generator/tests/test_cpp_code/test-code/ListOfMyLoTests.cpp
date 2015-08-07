/**
 * @file: ListOfMyLoTests.cpp
 * @brief: Implementation of ListOfMyLoTests.
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
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
#include <sbml/packages/test/sbml/ListOfMyLoTests.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ListOfMyLoTests using the given SBML @p level, @ p version and
 * package version values.
 */
ListOfMyLoTests::ListOfMyLoTests(unsigned int level,
                                 unsigned int version,
                                 unsigned int pkgVersion)
  : ListOf(level, version)
  , mId ("")
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ListOfMyLoTests using the given TestPkgNamespaces object.
 */
ListOfMyLoTests::ListOfMyLoTests(TestPkgNamespaces *testns)
  : ListOf(testns)
  , mId ("")
{
  setElementNamespace(testns->getURI());
}


/*
 * Copy constructor for ListOfMyLoTests.
 */
ListOfMyLoTests::ListOfMyLoTests(const ListOfMyLoTests& orig)
  : ListOf( orig )
  , mId ( orig.mId )
{
}


/*
 * Assignment operator for ListOfMyLoTests.
 */
ListOfMyLoTests&
ListOfMyLoTests::operator=(const ListOfMyLoTests& rhs)
{
  if (&rhs != this)
  {
    ListOf::operator=(rhs);
    mId = rhs.mId;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ListOfMyLoTests object.
 */
ListOfMyLoTests*
ListOfMyLoTests::clone() const
{
  return new ListOfMyLoTests(*this);
}


/*
 * Destructor for ListOfMyLoTests.
 */
ListOfMyLoTests::~ListOfMyLoTests()
{
}


/*
 * Returns the value of the "id" attribute of this ListOfMyLoTests.
 */
const std::string&
ListOfMyLoTests::getId() const
{
  return mId;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * ListOfMyLoTests's "id" attribute has been set.
 */
bool
ListOfMyLoTests::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this ListOfMyLoTests.
 */
int
ListOfMyLoTests::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Unsets the value of the "id" attribute of this ListOfMyLoTests.
 */
int
ListOfMyLoTests::unsetId()
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
 * Get a MyLoTest from the ListOfMyLoTests.
 */
MyLoTest*
ListOfMyLoTests::get(unsigned int n)
{
  return static_cast<MyLoTest*>(ListOf::get(n));
}


/*
 * Get a MyLoTest from the ListOfMyLoTests.
 */
const MyLoTest*
ListOfMyLoTests::get(unsigned int n) const
{
  return static_cast<const MyLoTest*>(ListOf::get(n));
}


/*
 * Get a MyLoTest from the ListOfMyLoTests based on its identifier.
 */
MyLoTest*
ListOfMyLoTests::get(const std::string& sid)
{
  return const_cast<MyLoTest*>(static_cast<const
    ListOfMyLoTests&>(*this).get(sid));
}


/*
 * Get a MyLoTest from the ListOfMyLoTests based on its identifier.
 */
const MyLoTest*
ListOfMyLoTests::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), IdEq<MyLoTest>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const MyLoTest*>
    (*result);
}


/*
 * Removes the nth MyLoTest from this ListOfMyLoTests and returns a pointer to
 * it.
 */
MyLoTest*
ListOfMyLoTests::remove(unsigned int n)
{
  return static_cast<MyLoTest*>(ListOf::remove(n));
}


/*
 * Removes the MyLoTest from this ListOfMyLoTests based on its identifier and
 * returns a pointer to it.
 */
MyLoTest*
ListOfMyLoTests::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), IdEq<MyLoTest>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <MyLoTest*> (item);
}


/*
 * Adds a copy of the given MyLoTest to this ListOfMyLoTests.
 */
int
ListOfMyLoTests::addMyLoTest(const MyLoTest* mlt)
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
    append(mlt);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of MyLoTest objects in this ListOfMyLoTests.
 */
unsigned int
ListOfMyLoTests::getNumMyLoTests() const
{
  return size();
}


/*
 * Creates a new MyLoTest object, adds it to this ListOfMyLoTests object and
 * returns the MyLoTest object created.
 */
MyLoTest*
ListOfMyLoTests::createMyLoTest()
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
    appendAndOwn(mlt);
  }

  return mlt;
}


/*
 * Returns the XML name of this ListOfMyLoTests object.
 */
const std::string&
ListOfMyLoTests::getElementName() const
{
  static const string name = "listOfMyLoTests";
  return name;
}


/*
 * Returns the libSBML typcode of this ListOfMyLoTests object.
 */
int
ListOfMyLoTests::getTypeCode() const
{
  return SBML_LIST_OF;
}


/*
 * Returns the libSBML type code for the SBML objects contained in this
 * ListOfMyLoTests object.
 */
int
ListOfMyLoTests::getItemTypeCode() const
{
  return TEST_LO_TEST;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * ListOfMyLoTests object have been set.
 */
bool
ListOfMyLoTests::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new MyLoTest in this ListOfMyLoTests
 */
SBase*
ListOfMyLoTests::createObject(XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SBase* object = NULL;
  TEST_CREATE_NS(testns, getSBMLNamespaces());

  if (name == "myLoTest")
  {
    object = new MyLoTest(testns);
    appendAndOwn(object);
  }

  delete testns;
  return object;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the namespace for the Test package
 */
void
ListOfMyLoTests::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    XMLNamespaces* thisxmlns = getNamespaces();
    if (thisxmlns && thisxmlns->hasURI(TestExtension::getXmlnsL3V1V1()))
    {
      xmlns.add(TestExtension::getXmlnsL3V1V1(), prefix);
    }
  }

  stream << xmlns;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Returns the value of the "id" attribute of this ListOf_t.
 */
LIBSBML_EXTERN
const char *
ListOfMyLoTests_getId(const ListOf_t * lo)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return lo->getId().empty() ? NULL : safe_strdup(lo->getId().c_str());
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this ListOf_t's "id"
 * attribute has been set.
 */
LIBSBML_EXTERN
int
ListOfMyLoTests_isSetId(const ListOf_t * lo)
{
  return (lo != NULL) ? static_cast<int>(lo->isSetId()) : 0;
}


/*
 * Sets the value of the "id" attribute of this ListOf_t.
 */
LIBSBML_EXTERN
int
ListOfMyLoTests_setId(ListOf_t * lo, const char * id)
{
  return (lo != NULL) ? lo->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this ListOf_t.
 */
LIBSBML_EXTERN
int
ListOfMyLoTests_unsetId(ListOf_t * lo)
{
  return (lo != NULL) ? lo->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Get a MyLoTest_t from the ListOf_t.
 */
LIBSBML_EXTERN
const MyLoTest_t*
ListOfMyLoTests_getMyLoTest(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfMyLoTests*>(lo)->get(n);
}


/*
 * Get a MyLoTest_t from the ListOf_t based on its identifier.
 */
LIBSBML_EXTERN
const MyLoTest_t*
ListOfMyLoTests_getById(ListOf_t* lo, const char *sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfMyLoTests*>(lo)->get(sid) : NULL;
}


/*
 * Removes the nth MyLoTest_t from this ListOf_t and returns a pointer to it.
 */
LIBSBML_EXTERN
MyLoTest_t*
ListOfMyLoTests_remove(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfMyLoTests*>(lo)->remove(n);
}


/*
 * Removes the MyLoTest_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
MyLoTest_t*
ListOfMyLoTests_removeById(ListOf_t* lo, const char* sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfMyLoTests*>(lo)->remove(sid) :
    NULL;
}




LIBSBML_CPP_NAMESPACE_END


