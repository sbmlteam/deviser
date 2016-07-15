/**
 * @file SedRepeatedTask.cpp
 * @brief Implementation of the SedRepeatedTask class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2016, Frank T. Bergmann
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
#include <sedml/SedRepeatedTask.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedRepeatedTask using the given SEDML Level and @ p version
 * values.
 */
SedRepeatedTask::SedRepeatedTask(unsigned int level, unsigned int version)
  : SedTask(level, version)
  , mRangeId ("")
  , mResetModel (false)
  , mIsSetResetModel (false)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedRepeatedTask using the given SedNamespaces object @p
 * sedmlns.
 */
SedRepeatedTask::SedRepeatedTask(SedNamespaces *sedmlns)
  : SedTask(sedmlns)
  , mRangeId ("")
  , mResetModel (false)
  , mIsSetResetModel (false)
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedRepeatedTask.
 */
SedRepeatedTask::SedRepeatedTask(const SedRepeatedTask& orig)
  : SedTask( orig )
  , mRangeId ( orig.mRangeId )
  , mResetModel ( orig.mResetModel )
  , mIsSetResetModel ( orig.mIsSetResetModel )
{
}


/*
 * Assignment operator for SedRepeatedTask.
 */
SedRepeatedTask&
SedRepeatedTask::operator=(const SedRepeatedTask& rhs)
{
  if (&rhs != this)
  {
    SedTask::operator=(rhs);
    mRangeId = rhs.mRangeId;
    mResetModel = rhs.mResetModel;
    mIsSetResetModel = rhs.mIsSetResetModel;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedRepeatedTask object.
 */
SedRepeatedTask*
SedRepeatedTask::clone() const
{
  return new SedRepeatedTask(*this);
}


/*
 * Destructor for SedRepeatedTask.
 */
SedRepeatedTask::~SedRepeatedTask()
{
}


/*
 * Returns the value of the "rangeId" attribute of this SedRepeatedTask.
 */
const std::string&
SedRepeatedTask::getRangeId() const
{
  return mRangeId;
}


/*
 * Returns the value of the "resetModel" attribute of this SedRepeatedTask.
 */
bool
SedRepeatedTask::getResetModel() const
{
  return mResetModel;
}


/*
 * Predicate returning @c true if this SedRepeatedTask's "rangeId" attribute is
 * set.
 */
bool
SedRepeatedTask::isSetRangeId() const
{
  return (mRangeId.empty() == false);
}


/*
 * Predicate returning @c true if this SedRepeatedTask's "resetModel" attribute
 * is set.
 */
bool
SedRepeatedTask::isSetResetModel() const
{
  return mIsSetResetModel;
}


/*
 * Sets the value of the "rangeId" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setRangeId(const std::string& rangeId)
{
  if (!(SyntaxChecker::isValidInternalSId(rangeId)))
  {
    return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mRangeId = rangeId;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "resetModel" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::setResetModel(bool resetModel)
{
  mResetModel = resetModel;
  mIsSetResetModel = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "rangeId" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::unsetRangeId()
{
  mRangeId.erase();

  if (mRangeId.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "resetModel" attribute of this SedRepeatedTask.
 */
int
SedRepeatedTask::unsetResetModel()
{
  mResetModel = false;
  mIsSetResetModel = false;

  if (isSetResetModel() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SedRepeatedTask::renameSIdRefs(const std::string& oldid,
                               const std::string& newid)
{
  if (isSetRangeId() && mRangeId == oldid)
  {
    setRangeId(newid);
  }
}


/*
 * Returns the XML element name of this SedRepeatedTask object.
 */
const std::string&
SedRepeatedTask::getElementName() const
{
  static const string name = "repeatedTask";
  return name;
}


/*
 * Returns the libSEDML type code for this SedRepeatedTask object.
 */
int
SedRepeatedTask::getTypeCode() const
{
  return SEDML_TASK_REPEATEDTASK;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedRepeatedTask object have been set.
 */
bool
SedRepeatedTask::hasRequiredAttributes() const
{
  bool allPresent = SedTask::hasRequiredAttributes();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedRepeatedTask::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedTask::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedRepeatedTask::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedRepeatedTask::setSedDocument(SedDocument* d)
{
  SedTask::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedRepeatedTask::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedTask::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedRepeatedTask::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedTask::addExpectedAttributes(attributes);

  attributes.add("range");

  attributes.add("resetModel");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedRepeatedTask::readAttributes(
                                const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                  XMLAttributes& attributes,
                                const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                  ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedTask::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == SedUnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(SedUnknownCoreAttribute);
      log->logError(SedmlSedRepeatedTaskAllowedAttributes, level, version,
        details);
    }
  }

  // 
  // range SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("range", mRangeId);

  if (assigned == true)
  {
    if (mRangeId.empty() == true)
    {
      logEmptyString(mRangeId, level, version, "<SedRepeatedTask>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mRangeId) == false)
    {
      logError(SedmlRepeatedTaskRangeIdMustBeRange, level, version, "The "
        "attribute range='" + mRangeId + "' does not conform to the syntax.");
    }
  }

  // 
  // resetModel bool (use = "optional" )
  // 

  mIsSetResetModel = attributes.readInto("resetModel", mResetModel);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedRepeatedTask::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedTask::writeAttributes(stream);

  if (isSetRangeId() == true)
  {
    stream.writeAttribute("range", getPrefix(), mRangeId);
  }

  if (isSetResetModel() == true)
  {
    stream.writeAttribute("resetModel", getPrefix(), mResetModel);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedRepeatedTask_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedRepeatedTask_t *
SedRepeatedTask_create(unsigned int level, unsigned int version)
{
  return new SedRepeatedTask(level, version);
}


/*
 * Creates and returns a deep copy of this SedRepeatedTask_t object.
 */
LIBSEDML_EXTERN
SedRepeatedTask_t*
SedRepeatedTask_clone(const SedRepeatedTask_t* srt)
{
  if (srt != NULL)
  {
    return static_cast<SedRepeatedTask_t*>(srt->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedRepeatedTask_t object.
 */
LIBSEDML_EXTERN
void
SedRepeatedTask_free(SedRepeatedTask_t* srt)
{
  if (srt != NULL)
  {
    delete srt;
  }
}


/*
 * Returns the value of the "rangeId" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
const char *
SedRepeatedTask_getRangeId(const SedRepeatedTask_t * srt)
{
  if (srt == NULL)
  {
    return NULL;
  }

  return srt->getRangeId().empty() ? NULL :
    safe_strdup(srt->getRangeId().c_str());
}


/*
 * Returns the value of the "resetModel" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_getResetModel(const SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? static_cast<int>(srt->getResetModel()) : 0;
}


/*
 * Predicate returning @c 1 if this SedRepeatedTask_t's "rangeId" attribute is
 * set.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetRangeId(const SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? static_cast<int>(srt->isSetRangeId()) : 0;
}


/*
 * Predicate returning @c 1 if this SedRepeatedTask_t's "resetModel" attribute
 * is set.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_isSetResetModel(const SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? static_cast<int>(srt->isSetResetModel()) : 0;
}


/*
 * Sets the value of the "rangeId" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setRangeId(SedRepeatedTask_t * srt, const char * rangeId)
{
  return (srt != NULL) ? srt->setRangeId(rangeId) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "resetModel" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_setResetModel(SedRepeatedTask_t * srt, int resetModel)
{
  return (srt != NULL) ? srt->setResetModel(resetModel) :
    LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "rangeId" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetRangeId(SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? srt->unsetRangeId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "resetModel" attribute of this SedRepeatedTask_t.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_unsetResetModel(SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? srt->unsetResetModel() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * SedRepeatedTask_t object have been set.
 */
LIBSEDML_EXTERN
int
SedRepeatedTask_hasRequiredAttributes(const SedRepeatedTask_t * srt)
{
  return (srt != NULL) ? static_cast<int>(srt->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


