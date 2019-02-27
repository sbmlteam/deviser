/**
 * @file ListOfOutputs.cpp
 * @brief Implementation of the ListOfOutputs class.
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
#include <sbml/packages/qual/sbml/ListOfOutputs.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ListOfOutputs using the given SBML Level, Version and
 * &ldquo;qual&rdquo; package version.
 */
ListOfOutputs::ListOfOutputs(unsigned int level,
                             unsigned int version,
                             unsigned int pkgVersion)
  : ListOf(level, version)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ListOfOutputs using the given QualPkgNamespaces object.
 */
ListOfOutputs::ListOfOutputs(QualPkgNamespaces *qualns)
  : ListOf(qualns)
{
  setElementNamespace(qualns->getURI());
}


/*
 * Copy constructor for ListOfOutputs.
 */
ListOfOutputs::ListOfOutputs(const ListOfOutputs& orig)
  : ListOf( orig )
{
}


/*
 * Assignment operator for ListOfOutputs.
 */
ListOfOutputs&
ListOfOutputs::operator=(const ListOfOutputs& rhs)
{
  if (&rhs != this)
  {
    ListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ListOfOutputs object.
 */
ListOfOutputs*
ListOfOutputs::clone() const
{
  return new ListOfOutputs(*this);
}


/*
 * Destructor for ListOfOutputs.
 */
ListOfOutputs::~ListOfOutputs()
{
}


/*
 * Get an Output from the ListOfOutputs.
 */
Output*
ListOfOutputs::get(unsigned int n)
{
  return static_cast<Output*>(ListOf::get(n));
}


/*
 * Get an Output from the ListOfOutputs.
 */
const Output*
ListOfOutputs::get(unsigned int n) const
{
  return static_cast<const Output*>(ListOf::get(n));
}


/*
 * Get an Output from the ListOfOutputs based on its identifier.
 */
Output*
ListOfOutputs::get(const std::string& sid)
{
  return const_cast<Output*>(static_cast<const
    ListOfOutputs&>(*this).get(sid));
}


/*
 * Get an Output from the ListOfOutputs based on its identifier.
 */
const Output*
ListOfOutputs::get(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), IdEq<Output>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const Output*> (*result);
}


/*
 * Removes the nth Output from this ListOfOutputs and returns a pointer to it.
 */
Output*
ListOfOutputs::remove(unsigned int n)
{
  return static_cast<Output*>(ListOf::remove(n));
}


/*
 * Removes the Output from this ListOfOutputs based on its identifier and
 * returns a pointer to it.
 */
Output*
ListOfOutputs::remove(const std::string& sid)
{
  SBase* item = NULL;
  vector<SBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), IdEq<Output>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <Output*> (item);
}


/*
 * Adds a copy of the given Output to this ListOfOutputs.
 */
int
ListOfOutputs::addOutput(const Output* o)
{
  if (o == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (o->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != o->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != o->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(o)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(o);
  }
}


/*
 * Get the number of Output objects in this ListOfOutputs.
 */
unsigned int
ListOfOutputs::getNumOutputs() const
{
  return size();
}


/*
 * Creates a new Output object, adds it to this ListOfOutputs object and
 * returns the Output object created.
 */
Output*
ListOfOutputs::createOutput()
{
  Output* o = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    o = new Output(qualns);
    delete qualns;
  }
  catch (...)
  {
  }

  if (o != NULL)
  {
    appendAndOwn(o);
  }

  return o;
}


/*
 * Used by ListOfOutputs::get() to lookup an Output based on its
 * QualitativeSpecies.
 */
struct IdEqQS : public std::unary_function<SBase*, bool>
{
  const string& id;
   
  IdEqQS (const string& id) : id(id) { }
  bool operator() (SBase* sb)
  {
  return (static_cast<Output*>(sb)->getQualitativeSpecies() == id);
  }
};


/*
 * Get an Output from the ListOfOutputs based on the QualitativeSpecies to
 * which it refers.
 */
const Output*
ListOfOutputs::getByQualitativeSpecies(const std::string& sid) const
{
  vector<SBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), IdEqQS(sid));
  return (result == mItems.end()) ? 0 : static_cast <const Output*> (*result);
}


/*
 * Get an Output from the ListOfOutputs based on the QualitativeSpecies to
 * which it refers.
 */
Output*
ListOfOutputs::getByQualitativeSpecies(const std::string& sid)
{
  return const_cast<Output*>(static_cast<const
    ListOfOutputs&>(*this).getByQualitativeSpecies(sid));
}


/*
 * Returns the XML element name of this ListOfOutputs object.
 */
const std::string&
ListOfOutputs::getElementName() const
{
  static const string name = "listOfOutputs";
  return name;
}


/*
 * Returns the libSBML type code for this ListOfOutputs object.
 */
int
ListOfOutputs::getTypeCode() const
{
  return SBML_LIST_OF;
}


/*
 * Returns the libSBML type code for the SBML objects contained in this
 * ListOfOutputs object.
 */
int
ListOfOutputs::getItemTypeCode() const
{
  return SBML_QUAL_OUTPUT;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new Output in this ListOfOutputs
 */
SBase*
ListOfOutputs::createObject(XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SBase* object = NULL;
  QUAL_CREATE_NS(qualns, getSBMLNamespaces());

  if (name == "output")
  {
    object = new Output(qualns);
    appendAndOwn(object);
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
ListOfOutputs::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    const XMLNamespaces* thisxmlns = getNamespaces();
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
 * Get an Output_t from the ListOf_t.
 */
LIBSBML_EXTERN
Output_t*
ListOfOutputs_getOutput(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfOutputs*>(lo)->get(n);
}


/*
 * Get an Output_t from the ListOf_t based on its identifier.
 */
LIBSBML_EXTERN
Output_t*
ListOfOutputs_getById(ListOf_t* lo, const char *sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfOutputs*>(lo)->get(sid) : NULL;
}


/*
 * Removes the nth Output_t from this ListOf_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Output_t*
ListOfOutputs_remove(ListOf_t* lo, unsigned int n)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return static_cast <ListOfOutputs*>(lo)->remove(n);
}


/*
 * Removes the Output_t from this ListOf_t based on its identifier and returns
 * a pointer to it.
 */
LIBSBML_EXTERN
Output_t*
ListOfOutputs_removeById(ListOf_t* lo, const char* sid)
{
  if (lo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <ListOfOutputs*>(lo)->remove(sid) : NULL;
}




LIBSBML_CPP_NAMESPACE_END


