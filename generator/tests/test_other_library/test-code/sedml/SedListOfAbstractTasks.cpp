/**
 * @file SedListOfAbstractTasks.cpp
 * @brief Implementation of the SedListOfAbstractTasks class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#include <sedml/SedListOfAbstractTasks.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedTask.h>
#include <sedml/SedRepeatedTask.h>
#include <sedml/SedParameterEstimationTask.h>
#include <sedml/SedSimpleRepeatedTask.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedListOfAbstractTasks using the given SEDML Level and @ p
 * version values.
 */
SedListOfAbstractTasks::SedListOfAbstractTasks(unsigned int level,
                                               unsigned int version)
  : SedListOf(level, version)
  , mElementName("abstractTask")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedListOfAbstractTasks using the given SedNamespaces object @p
 * sedmlns.
 */
SedListOfAbstractTasks::SedListOfAbstractTasks(SedNamespaces *sedmlns)
  : SedListOf(sedmlns)
  , mElementName("abstractTask")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedListOfAbstractTasks.
 */
SedListOfAbstractTasks::SedListOfAbstractTasks(const SedListOfAbstractTasks&
  orig)
  : SedListOf( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SedListOfAbstractTasks.
 */
SedListOfAbstractTasks&
SedListOfAbstractTasks::operator=(const SedListOfAbstractTasks& rhs)
{
  if (&rhs != this)
  {
    SedListOf::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedListOfAbstractTasks object.
 */
SedListOfAbstractTasks*
SedListOfAbstractTasks::clone() const
{
  return new SedListOfAbstractTasks(*this);
}


/*
 * Destructor for SedListOfAbstractTasks.
 */
SedListOfAbstractTasks::~SedListOfAbstractTasks()
{
}


/*
 * Get a SedAbstractTask from the SedListOfAbstractTasks.
 */
SedAbstractTask*
SedListOfAbstractTasks::get(unsigned int n)
{
  return static_cast<SedAbstractTask*>(SedListOf::get(n));
}


/*
 * Get a SedAbstractTask from the SedListOfAbstractTasks.
 */
const SedAbstractTask*
SedListOfAbstractTasks::get(unsigned int n) const
{
  return static_cast<const SedAbstractTask*>(SedListOf::get(n));
}


/*
 * Get a SedAbstractTask from the SedListOfAbstractTasks based on its
 * identifier.
 */
SedAbstractTask*
SedListOfAbstractTasks::get(const std::string& sid)
{
  return const_cast<SedAbstractTask*>(static_cast<const
    SedListOfAbstractTasks&>(*this).get(sid));
}


/*
 * Get a SedAbstractTask from the SedListOfAbstractTasks based on its
 * identifier.
 */
const SedAbstractTask*
SedListOfAbstractTasks::get(const std::string& sid) const
{
  vector<SedBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAbstractTask>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SedAbstractTask*>
    (*result);
}


/*
 * Removes the nth SedAbstractTask from this SedListOfAbstractTasks and returns
 * a pointer to it.
 */
SedAbstractTask*
SedListOfAbstractTasks::remove(unsigned int n)
{
  return static_cast<SedAbstractTask*>(SedListOf::remove(n));
}


/*
 * Removes the SedAbstractTask from this SedListOfAbstractTasks based on its
 * identifier and returns a pointer to it.
 */
SedAbstractTask*
SedListOfAbstractTasks::remove(const std::string& sid)
{
  SedBase* item = NULL;
  vector<SedBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(),
    SedIdEq<SedAbstractTask>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SedAbstractTask*> (item);
}


/*
 * Adds a copy of the given SedAbstractTask to this SedListOfAbstractTasks.
 */
int
SedListOfAbstractTasks::addAbstractTask(const SedAbstractTask* sat)
{
  if (sat == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sat->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sat->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sat->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sat)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sat);
  }
}


/*
 * Get the number of SedAbstractTask objects in this SedListOfAbstractTasks.
 */
unsigned int
SedListOfAbstractTasks::getNumAbstractTasks() const
{
  return size();
}


/*
 * Creates a new SedTask object, adds it to this SedListOfAbstractTasks object
 * and returns the SedTask object created.
 */
SedTask*
SedListOfAbstractTasks::createTask()
{
  SedTask* st = NULL;

  try
  {
    st = new SedTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (st != NULL)
  {
    appendAndOwn(st);
  }

  return st;
}


/*
 * Creates a new SedRepeatedTask object, adds it to this SedListOfAbstractTasks
 * object and returns the SedRepeatedTask object created.
 */
SedRepeatedTask*
SedListOfAbstractTasks::createRepeatedTask()
{
  SedRepeatedTask* srt = NULL;

  try
  {
    srt = new SedRepeatedTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (srt != NULL)
  {
    appendAndOwn(srt);
  }

  return srt;
}


/*
 * Creates a new SedParameterEstimationTask object, adds it to this
 * SedListOfAbstractTasks object and returns the SedParameterEstimationTask
 * object created.
 */
SedParameterEstimationTask*
SedListOfAbstractTasks::createParameterEstimationTask()
{
  SedParameterEstimationTask* spet = NULL;

  try
  {
    spet = new SedParameterEstimationTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (spet != NULL)
  {
    appendAndOwn(spet);
  }

  return spet;
}


/*
 * Creates a new SedSimpleRepeatedTask object, adds it to this
 * SedListOfAbstractTasks object and returns the SedSimpleRepeatedTask object
 * created.
 */
SedSimpleRepeatedTask*
SedListOfAbstractTasks::createSimpleRepeatedTask()
{
  SedSimpleRepeatedTask* ssrt = NULL;

  try
  {
    ssrt = new SedSimpleRepeatedTask(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (ssrt != NULL)
  {
    appendAndOwn(ssrt);
  }

  return ssrt;
}


/*
 * Returns the XML element name of this SedListOfAbstractTasks object.
 */
const std::string&
SedListOfAbstractTasks::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the XML name of this SedListOfAbstractTasks object.
 */
void
SedListOfAbstractTasks::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSEDML type code for this SedListOfAbstractTasks object.
 */
int
SedListOfAbstractTasks::getTypeCode() const
{
  return SEDML_LIST_OF;
}


/*
 * Returns the libSEDML type code for the SEDML objects contained in this
 * SedListOfAbstractTasks object.
 */
int
SedListOfAbstractTasks::getItemTypeCode() const
{
  return SEDML_SEDML_ABSTRACTTASK;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new SedAbstractTask in this SedListOfAbstractTasks
 */
SedBase*
SedListOfAbstractTasks::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SedBase* object = NULL;

  if (name == "abstractTask")
  {
    object = new SedAbstractTask(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "abstractTask")
  {
    object = new SedTask(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "abstractTask")
  {
    object = new SedRepeatedTask(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "abstractTask")
  {
    object = new SedParameterEstimationTask(getSedNamespaces());
    appendAndOwn(object);
  }

  if (name == "abstractTask")
  {
    object = new SedSimpleRepeatedTask(getSedNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the namespace for the Sedml package
 */
void
SedListOfAbstractTasks::writeXMLNS(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* thisxmlns =
      getNamespaces();
    if (thisxmlns && thisxmlns->hasURI(SEDML_XMLNS_L1V1))
    {
      xmlns.add(SEDML_XMLNS_L1V1, prefix);
    }
  }

  stream << xmlns;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * checks concrete types
 */
bool
SedListOfAbstractTasks::isValidTypeForList(SedBase* item)
{
  unsigned int tc = item->getTypeCode();

  return ((tc == SEDML_TASK) || (tc == SEDML_TASK_REPEATEDTASK) || (tc ==
    SEDML_TASK_PARAMETER_ESTIMATION) || (tc == SEDML_SIMPLEREPEATEDTASK));
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SedAbstractTask_t from the SedListOf_t.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfAbstractTasks_getAbstractTask(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfAbstractTasks*>(slo)->get(n);
}


/*
 * Get a SedAbstractTask_t from the SedListOf_t based on its identifier.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfAbstractTasks_getById(SedListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SedListOfAbstractTasks*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SedAbstractTask_t from this SedListOf_t and returns a
 * pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfAbstractTasks_remove(SedListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SedListOfAbstractTasks*>(slo)->remove(n);
}


/*
 * Removes the SedAbstractTask_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfAbstractTasks_removeById(SedListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast
    <SedListOfAbstractTasks*>(slo)->remove(sid) : NULL;
}




LIBSEDML_CPP_NAMESPACE_END


