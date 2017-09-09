/**
 * @file ListOfClassTwos.cpp
 * @brief Implementation of the ListOfClassTwos class.
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
#include <sbml/packages/test/sbml/ListOfClassTwos.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ListOfClassTwos using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
ListOfClassTwos::ListOfClassTwos(unsigned int level,
                                 unsigned int version,
                                 unsigned int pkgVersion)
  : ListOf(level, version)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ListOfClassTwos using the given TestPkgNamespaces object.
 */
ListOfClassTwos::ListOfClassTwos(TestPkgNamespaces *testns)
  : ListOf(testns)
{
  setElementNamespace(testns->getURI());
}


/*
 * Copy constructor for ListOfClassTwos.
 */
ListOfClassTwos::ListOfClassTwos(const ListOfClassTwos& orig)
  : ListOf( orig )
{
}


/*
 * Assignment operator for ListOfClassTwos.
 */
ListOfClassTwos&
ListOfClassTwos::operator=(const ListOfClassTwos& rhs)
{
  if (&rhs != this)
  {
    ListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ListOfClassTwos object.
 */
ListOfClassTwos*
ListOfClassTwos::clone() const
{
  return new ListOfClassTwos(*this);
}


/*
 * Destructor for ListOfClassTwos.
 */
ListOfClassTwos::~ListOfClassTwos()
{
}


/*
 * Get a ClassTwo from the ListOfClassTwos.
 */
ClassTwo*
ListOfClassTwos::get(unsigned int n)
{
  return static_cast<ClassTwo*>(ListOf::get(n));
}


/*
 * Get a ClassTwo from the ListOfClassTwos.
 */
const ClassTwo*
ListOfClassTwos::get(unsigned int n) const
{
  return static_cast<const ClassTwo*>(ListOf::get(n));
}


/*
 * Get a ClassTwo from the ListOfClassTwos based on its identifier.
 */
ClassTwo*
ListOfClassTwos::get(const std::string& sid)
{
  return const_cast<ClassTwo*>(static_cast<const
    ListOfClassTwos&>(*this).get(sid));
}


/*
 * Get a ClassTwo from the ListOfClassTwos based on its identifier.
 */
const ClassTwo*
ListOfClassTwos::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), IdEq<ClassTwo>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const ClassTwo*>
    (*result);
}


/*
 * Removes the nth ClassTwo from this ListOfClassTwos and returns a pointer to
 * it.
 */
ClassTwo*
ListOfClassTwos::remove(unsigned int n)
{
  return static_cast<ClassTwo*>(ListOf::remove(n));
}


/*
 * Removes the ClassTwo from this ListOfClassTwos based on its identifier and
 * returns a pointer to it.
 */
ClassTwo*
ListOfClassTwos::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), IdEq<ClassTwo>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <ClassTwo*> (item);
}


/*
 * Adds a copy of the given ClassTwo to this ListOfClassTwos.
 */
int
ListOfClassTwos::addClassTwo(const ClassTwo* ct)
{
  if (ct == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (ct->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != ct->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ct->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(ct)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(ct);
  }
}


/*
 * Get the number of ClassTwo objects in this ListOfClassTwos.
 */
unsigned int
ListOfClassTwos::getNumClassTwos() const
{
  return size();
}


/*
 * Creates a new ClassTwo object, adds it to this ListOfClassTwos object and
 * returns the ClassTwo object created.
 */
ClassTwo*
ListOfClassTwos::createClassTwo()
{
  ClassTwo* ct = NULL;

  try
  {
    TEST_CREATE_NS(testns, getSBMLNamespaces());
    ct = new ClassTwo(testns);
    delete testns;
  }
  catch (...)
  {
  }

  if (ct != NULL)
  {
    appendAndOwn(ct);
  }

  return ct;
}


/*
 * Returns the XML element name of this ListOfClassTwos object.
 */
const std::string&
ListOfClassTwos::getElementName() const
{
  static const string name = "listOfClassTwos";
  return name;
}


/*
 * Returns the libSBML type code for this ListOfClassTwos object.
 */
int
ListOfClassTwos::getTypeCode() const
{
  return SBML_LIST_OF;
}


/*
 * Returns the libSBML type code for the SBML objects contained in this
 * ListOfClassTwos object.
 */
int
ListOfClassTwos::getItemTypeCode() const
{
  return SBML_TEST_CLASSTWO;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new ClassTwo in this ListOfClassTwos
 */
SBase*
ListOfClassTwos::createObject(XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SBase* object = NULL;
  TEST_CREATE_NS(testns, getSBMLNamespaces());

  if (name == "classTwo")
  {
    object = new ClassTwo(testns);
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
ListOfClassTwos::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    const XMLNamespaces* thisxmlns = getNamespaces();
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
 * Get a ClassTwo_t from the ListOf_t.
 */
LIBSBML_EXTERN
ClassTwo_t*
ListOfClassTwos_getClassTwo(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfClassTwos*>(lo)->get(n);
}


/*
 * Get a ClassTwo_t from the ListOf_t based on its identifier.
 */
LIBSBML_EXTERN
ClassTwo_t*
ListOfClassTwos_getById(ListOf_t* lo, const char *sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfClassTwos*>(lo)->get(sid) : NULL;
}


/*
 * Removes the nth ClassTwo_t from this ListOf_t and returns a pointer to it.
 */
LIBSBML_EXTERN
ClassTwo_t*
ListOfClassTwos_remove(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfClassTwos*>(lo)->remove(n);
}


/*
 * Removes the ClassTwo_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
ClassTwo_t*
ListOfClassTwos_removeById(ListOf_t* lo, const char* sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfClassTwos*>(lo)->remove(sid) :
    NULL;
}




LIBSBML_CPP_NAMESPACE_END


