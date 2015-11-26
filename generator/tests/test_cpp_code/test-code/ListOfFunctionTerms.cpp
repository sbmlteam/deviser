/**
 * @file ListOfFunctionTerms.cpp
 * @brief Implementation of ListOfFunctionTerms.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2015 jointly by the following organizations:
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
#include <sbml/packages/qual/sbml/ListOfFunctionTerms.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>
#include <sbml/math/MathML.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ListOfFunctionTerms using the given SBML Level, Version and
 * &ldquo;qual&rdquo; package version.
 */
ListOfFunctionTerms::ListOfFunctionTerms(unsigned int level,
                                         unsigned int version,
                                         unsigned int pkgVersion)
  : ListOf(level, version)
  , mDefaultTerm (NULL)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new ListOfFunctionTerms using the given QualPkgNamespaces object.
 */
ListOfFunctionTerms::ListOfFunctionTerms(QualPkgNamespaces *qualns)
  : ListOf(qualns)
  , mDefaultTerm (NULL)
{
  setElementNamespace(qualns->getURI());
  connectToChild();
}


/*
 * Copy constructor for ListOfFunctionTerms.
 */
ListOfFunctionTerms::ListOfFunctionTerms(const ListOfFunctionTerms& orig)
  : ListOf( orig )
  , mDefaultTerm ( NULL )
{
  if (orig.mDefaultTerm != NULL)
  {
    mDefaultTerm = orig.mDefaultTerm->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for ListOfFunctionTerms.
 */
ListOfFunctionTerms&
ListOfFunctionTerms::operator=(const ListOfFunctionTerms& rhs)
{
  if (&rhs != this)
  {
    ListOf::operator=(rhs);
    delete mDefaultTerm;
    if (rhs.mDefaultTerm != NULL)
    {
      mDefaultTerm = rhs.mDefaultTerm->clone();
    }
    else
    {
      mDefaultTerm = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ListOfFunctionTerms object.
 */
ListOfFunctionTerms*
ListOfFunctionTerms::clone() const
{
  return new ListOfFunctionTerms(*this);
}


/*
 * Destructor for ListOfFunctionTerms.
 */
ListOfFunctionTerms::~ListOfFunctionTerms()
{
  delete mDefaultTerm;
  mDefaultTerm = NULL;
}


/*
 * Returns the value of the "defaultTerm" element of this ListOfFunctionTerms.
 */
const DefaultTerm*
ListOfFunctionTerms::getDefaultTerm() const
{
  return mDefaultTerm;
}


/*
 * Returns the value of the "defaultTerm" element of this ListOfFunctionTerms.
 */
DefaultTerm*
ListOfFunctionTerms::getDefaultTerm()
{
  return mDefaultTerm;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * ListOfFunctionTerms's "defaultTerm" element has been set.
 */
bool
ListOfFunctionTerms::isSetDefaultTerm() const
{
  return (mDefaultTerm != NULL);
}


/*
 * Sets the value of the "defaultTerm" element of this ListOfFunctionTerms.
 */
int
ListOfFunctionTerms::setDefaultTerm(const DefaultTerm* defaultTerm)
{
  if (mDefaultTerm == defaultTerm)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (defaultTerm == NULL)
  {
    delete mDefaultTerm;
    mDefaultTerm = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mDefaultTerm;
    mDefaultTerm = (defaultTerm != NULL) ? defaultTerm->clone() : NULL;
    if (mDefaultTerm != NULL)
    {
      mDefaultTerm->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new DefaultTerm object, adds it to this ListOfFunctionTerms object
 * and returns the DefaultTerm object created.
 */
DefaultTerm*
ListOfFunctionTerms::createDefaultTerm()
{
  if (mDefaultTerm != NULL)
  {
    delete mDefaultTerm;
  }

  QUAL_CREATE_NS(qualns, getSBMLNamespaces());
  mDefaultTerm = new DefaultTerm(qualns);

  delete qualns;

  connectToChild();

  return mDefaultTerm;
}


/*
 * Unsets the value of the "defaultTerm" element of this ListOfFunctionTerms.
 */
int
ListOfFunctionTerms::unsetDefaultTerm()
{
  delete mDefaultTerm;
  mDefaultTerm = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Get a FunctionTerm from the ListOfFunctionTerms.
 */
FunctionTerm*
ListOfFunctionTerms::get(unsigned int n)
{
  return static_cast<FunctionTerm*>(ListOf::get(n));
}


/*
 * Get a FunctionTerm from the ListOfFunctionTerms.
 */
const FunctionTerm*
ListOfFunctionTerms::get(unsigned int n) const
{
  return static_cast<const FunctionTerm*>(ListOf::get(n));
}


/*
 * Get a FunctionTerm from the ListOfFunctionTerms based on its identifier.
 */
FunctionTerm*
ListOfFunctionTerms::get(const std::string& sid)
{
  return const_cast<FunctionTerm*>(static_cast<const
    ListOfFunctionTerms&>(*this).get(sid));
}


/*
 * Get a FunctionTerm from the ListOfFunctionTerms based on its identifier.
 */
const FunctionTerm*
ListOfFunctionTerms::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), IdEq<FunctionTerm>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const FunctionTerm*>
    (*result);
}


/*
 * Removes the nth FunctionTerm from this ListOfFunctionTerms and returns a
 * pointer to it.
 */
FunctionTerm*
ListOfFunctionTerms::remove(unsigned int n)
{
  return static_cast<FunctionTerm*>(ListOf::remove(n));
}


/*
 * Removes the FunctionTerm from this ListOfFunctionTerms based on its
 * identifier and returns a pointer to it.
 */
FunctionTerm*
ListOfFunctionTerms::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), IdEq<FunctionTerm>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <FunctionTerm*> (item);
}


/*
 * Adds a copy of the given FunctionTerm to this ListOfFunctionTerms.
 */
int
ListOfFunctionTerms::addFunctionTerm(const FunctionTerm* ft)
{
  if (ft == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (ft->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != ft->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ft->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(ft)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    append(ft);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of FunctionTerm objects in this ListOfFunctionTerms.
 */
unsigned int
ListOfFunctionTerms::getNumFunctionTerms() const
{
  return size();
}


/*
 * Creates a new FunctionTerm object, adds it to this ListOfFunctionTerms
 * object and returns the FunctionTerm object created.
 */
FunctionTerm*
ListOfFunctionTerms::createFunctionTerm()
{
  FunctionTerm* ft = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    ft = new FunctionTerm(qualns);
    delete qualns;
  }
  catch (...)
  {
  }

  if (ft != NULL)
  {
    appendAndOwn(ft);
  }

  return ft;
}


/*
 * Returns the XML element name of this ListOfFunctionTerms object.
 */
const std::string&
ListOfFunctionTerms::getElementName() const
{
  static const string name = "listOfFunctionTerms";
  return name;
}


/*
 * Returns the libSBML type code for this ListOfFunctionTerms object.
 */
int
ListOfFunctionTerms::getTypeCode() const
{
  return SBML_LIST_OF;
}


/*
 * Returns the libSBML type code for the SBML objects contained in this
 * ListOfFunctionTerms object.
 */
int
ListOfFunctionTerms::getItemTypeCode() const
{
  return SBML_QUAL_FUNCTION_TERM;
}


/*
 * Predicate returning @c true if all the required elements for this
 * ListOfFunctionTerms object have been set.
 */
bool
ListOfFunctionTerms::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetDefaultTerm() == false)
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
ListOfFunctionTerms::writeElements(XMLOutputStream& stream) const
{
  ListOf::writeElements(stream);

  if (isSetDefaultTerm() == true)
  {
    mDefaultTerm->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
ListOfFunctionTerms::connectToChild()
{
  ListOf::connectToChild();

  if (mDefaultTerm != NULL)
  {
    mDefaultTerm->connectToParent(this);
  }
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
ListOfFunctionTerms::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mDefaultTerm != NULL)
  {
    if (mDefaultTerm->getId() == id)
    {
      return mDefaultTerm;
    }

    obj = mDefaultTerm->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return ListOf::getElementBySId(id);
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
ListOfFunctionTerms::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mDefaultTerm != NULL)
  {
    if (mDefaultTerm->getMetaId() == metaid)
    {
      return mDefaultTerm;
    }

    obj = mDefaultTerm->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return ListOf::getElementByMetaId(metaid);
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
ListOfFunctionTerms::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = ListOf::getAllElements(filter);

  ADD_FILTERED_POINTER(ret, sublist, mDefaultTerm, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new FunctionTerm in this ListOfFunctionTerms
 */
SBase*
ListOfFunctionTerms::createObject(XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SBase* object = NULL;
  QUAL_CREATE_NS(qualns, getSBMLNamespaces());

  if (name == "functionTerm")
  {
    object = new FunctionTerm(qualns);
    appendAndOwn(object);
  }

  if (name == "defaultTerm")
  {
    DefaultTerm newDT(qualns);
    setDefaultTerm(&newDT);
    object = getDefaultTerm();
  }

  delete qualns;
  return object;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the namespace for the Qual package
 */
void
ListOfFunctionTerms::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    XMLNamespaces* thisxmlns = getNamespaces();
    if (thisxmlns && thisxmlns->hasURI(QualExtension::getXmlnsL3V1V1()))
    {
      xmlns.add(QualExtension::getXmlnsL3V1V1(), prefix);
    }
  }

  stream << xmlns;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a FunctionTerm_t from the ListOf_t.
 */
LIBSBML_EXTERN
const FunctionTerm_t*
ListOfFunctionTerms_getFunctionTerm(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfFunctionTerms*>(lo)->get(n);
}


/*
 * Get a FunctionTerm_t from the ListOf_t based on its identifier.
 */
LIBSBML_EXTERN
const FunctionTerm_t*
ListOfFunctionTerms_getById(ListOf_t* lo, const char *sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfFunctionTerms*>(lo)->get(sid) :
    NULL;
}


/*
 * Removes the nth FunctionTerm_t from this ListOf_t and returns a pointer to
 * it.
 */
LIBSBML_EXTERN
FunctionTerm_t*
ListOfFunctionTerms_remove(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfFunctionTerms*>(lo)->remove(n);
}


/*
 * Removes the FunctionTerm_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
FunctionTerm_t*
ListOfFunctionTerms_removeById(ListOf_t* lo, const char* sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfFunctionTerms*>(lo)->remove(sid) :
    NULL;
}




LIBSBML_CPP_NAMESPACE_END


