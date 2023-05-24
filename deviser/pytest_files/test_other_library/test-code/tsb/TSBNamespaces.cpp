/**
 * @file TSBNamespaces.cpp
 * @brief Implementation of the TSBNamespaces class.
 * @author DEVISER
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


#include <tsb/TSBNamespaces.h>
#include <sstream>
#include <tsb/common/common.h>
#include <iostream>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */


LIBTSB_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibtsbInternal */
void 
TSBNamespaces::initTSBNamespace()
{
  mNamespaces = new XMLNamespaces();

  switch (mLevel)
  {
  case 1:
  default:
    switch (mVersion)
    {
    case 1:
    default:
      mNamespaces->add(TSB_XMLNS_L1V1);
      break;
    }
    break;
  }

  if (mNamespaces->getLength() == 0)
  {
    mLevel = TSB_INT_MAX;
    mVersion = TSB_INT_MAX;
    delete mNamespaces;
    mNamespaces = NULL;
  }
}
/** @endcond */


TSBNamespaces::TSBNamespaces(unsigned int level, unsigned int version)
 : mLevel(level)
  ,mVersion(version)
{
  initTSBNamespace();
}


TSBNamespaces::~TSBNamespaces()
{
  if (mNamespaces != NULL)
    delete mNamespaces;
}


/*
 * Copy constructor; creates a copy of a TSBNamespaces.
 */
TSBNamespaces::TSBNamespaces(const TSBNamespaces& orig)
 : mLevel(orig.mLevel)
 , mVersion(orig.mVersion)
 , mNamespaces(NULL)
{
  if(orig.mNamespaces != NULL)
    this->mNamespaces = 
          new XMLNamespaces(*const_cast<TSBNamespaces&>(orig).mNamespaces);
}


const List * 
TSBNamespaces::getSupportedNamespaces()
{
  List *result = new List();
  result->add(new TSBNamespaces(1,1));
  return result;
}


void 
TSBNamespaces::freeTSBNamespaces(List * supportedNS)
{
  if (supportedNS == NULL) return;
  for (unsigned int i = 0; i < supportedNS->getSize(); i++)
  {
    delete (TSBNamespaces*)supportedNS->get(i);
  }
  delete supportedNS;
}

/*
 * Assignment operator for TSBNamespaces.
 */
TSBNamespaces&
TSBNamespaces::operator=(const TSBNamespaces& rhs)
{
  if (&rhs != this)
  {
    mLevel   = rhs.mLevel;
    mVersion = rhs.mVersion;
    delete this->mNamespaces;
    if(rhs.mNamespaces != NULL)
      this->mNamespaces = 
            new XMLNamespaces(*const_cast<TSBNamespaces&>(rhs).mNamespaces);
    else
      this->mNamespaces = NULL;
  }

  return *this;
}



/*
 * Creates and returns a deep copy of this TSBNamespaces.
 */
TSBNamespaces *
TSBNamespaces::clone () const
{
  return new TSBNamespaces(*this);
}


std::string 
TSBNamespaces::getTSBNamespaceURI(unsigned int level,
                                 unsigned int version)
{
  std::string uri = "";
  switch (level)
  {
  case 1:
  default:
    switch (version)
    {
    case 1:
    default:
      uri = TSB_XMLNS_L1V1;
      break;
    }
    break;
  }
  return uri;
}


std::string
TSBNamespaces::getURI() const
{
  return getTSBNamespaceURI(mLevel,mVersion);
}


unsigned int 
TSBNamespaces::getLevel()
{
  return mLevel;
}


unsigned int 
TSBNamespaces::getLevel() const
{
  return mLevel;
}


unsigned int 
TSBNamespaces::getVersion()
{
  return mVersion;
}


unsigned int 
TSBNamespaces::getVersion() const
{
  return mVersion;
}


XMLNamespaces * 
TSBNamespaces::getNamespaces()
{
  return mNamespaces;
}


const XMLNamespaces * 
TSBNamespaces::getNamespaces() const
{
  return mNamespaces;
}


int
TSBNamespaces::addNamespaces(const XMLNamespaces * xmlns)
{
  int success = LIBTSB_OPERATION_SUCCESS;

  if (xmlns == NULL)
    return LIBTSB_INVALID_OBJECT;

  if (!mNamespaces) 
  {
    initTSBNamespace();
  }

  /* check whether the namespace already exists
   * add if it does not
   */
  for (int i = 0; i < xmlns->getLength(); i++)
  {
    if (mNamespaces != NULL && !(mNamespaces->hasNS(xmlns->getURI(i), xmlns->getPrefix(i))))
    {
      success = mNamespaces->add(xmlns->getURI(i), xmlns->getPrefix(i));
    }
  }

  return success;
}


int
TSBNamespaces::addNamespace(const std::string &uri, const std::string &prefix)
{
  if (!mNamespaces) 
  {
    initTSBNamespace();
  }

  return mNamespaces != NULL ? mNamespaces->add(uri, prefix) : LIBTSB_INVALID_OBJECT;
}


int
TSBNamespaces::removeNamespace(const std::string &uri)
{
  if (!mNamespaces) 
  {
    initTSBNamespace();
  }

  return mNamespaces != NULL ? mNamespaces->remove(mNamespaces->getIndex(uri)) : LIBTSB_INVALID_OBJECT;
}


/*
 * Predicate returning @c true if the given
 * URL is one of TSB XML namespaces.
 */
bool 
TSBNamespaces::isTSBNamespace(const std::string& uri)
{
  if (uri == TSB_XMLNS_L1V1)   return true;

  return false;
}

bool 
TSBNamespaces::isValidCombination()
{
  bool valid = true;
  bool tsbDeclared = false;
  std::string declaredURI("");
  unsigned int version = getVersion();
  XMLNamespaces *xmlns = getNamespaces();

  if (xmlns != NULL)
  {
    int numNS = 0;

    if (xmlns->hasURI(TSB_XMLNS_L1V1))
    {
      ++numNS;
      declaredURI.assign(TSB_XMLNS_L1V1);
    }

    // checks if the TSB Namespace is explicitly defined.
    for (int i=0; i < xmlns->getLength(); i++)
    {
      if (!declaredURI.empty() && 
                      xmlns->getURI(i) == declaredURI)
      {
        tsbDeclared = true;
        break;
      }
    }
  }


  switch (getLevel())
  {
    case 1:
     switch (version)
      {
        case 1:
          // the namespaces contains the tsb namespaces
          // check it is the correct ns for the level/version
          if (tsbDeclared)
          {
            if (declaredURI != string(TSB_XMLNS_L1V1))
            {
              valid = false;
            }
          }
          break;
        default:
          valid = false;
          break;
        }
      break;
    default:
      valid = false;
      break;
  }

  return valid;
}


/** @cond doxygenLibtsbInternal */
void 
TSBNamespaces::setLevel(unsigned int level)
{
  mLevel = level;
}


void 
TSBNamespaces::setVersion(unsigned int version)
{
  mVersion = version;
}


void 
TSBNamespaces::setNamespaces(XMLNamespaces * xmlns)
{
  delete mNamespaces;
  if (xmlns != NULL)
    mNamespaces = xmlns->clone();
  else
    mNamespaces = NULL;
}
/** @endcond */

#endif /* __cplusplus */


/** @cond doxygenIgnored */

LIBTSB_EXTERN
TSBNamespaces_t *
TSBNamespaces_create(unsigned int level, unsigned int version)
{
  return new TSBNamespaces(level, version);
}


LIBTSB_EXTERN
void
TSBNamespaces_free(TSBNamespaces_t* ns)
{
  if (ns == NULL) return;
  delete static_cast<TSBNamespaces*>(ns);
}


LIBTSB_EXTERN
unsigned int
TSBNamespaces_getLevel(TSBNamespaces_t *tsbns)
{
  return (tsbns != NULL) ? tsbns->getLevel() : TSB_INT_MAX;
}


LIBTSB_EXTERN
unsigned int
TSBNamespaces_getVersion(TSBNamespaces_t *tsbns)
{
  return (tsbns != NULL) ? tsbns->getVersion() : TSB_INT_MAX;
}


LIBTSB_EXTERN
XMLNamespaces_t *
TSBNamespaces_getNamespaces(TSBNamespaces_t *tsbns)
{
  return (tsbns != NULL) ? tsbns->getNamespaces() : NULL;
}


LIBTSB_EXTERN
char *
TSBNamespaces_getTSBNamespaceURI(unsigned int level, unsigned int version)
{
  return tsb_safe_strdup(TSBNamespaces::getTSBNamespaceURI(level, version).c_str());
}


LIBTSB_EXTERN
int
TSBNamespaces_addNamespaces(TSBNamespaces_t *tsbns,
                             const XMLNamespaces_t * xmlns)
{
  if (tsbns != NULL)
    return tsbns->addNamespaces(xmlns);
  else
    return LIBTSB_INVALID_OBJECT;
}

LIBTSB_EXTERN
TSBNamespaces_t **
TSBNamespaces_getSupportedNamespaces(int *length)
{
  if (length == NULL) return NULL;
   const List* supported = TSBNamespaces::getSupportedNamespaces();
  
   *length = (int) supported->getSize();
  TSBNamespaces_t ** result = (TSBNamespaces_t**)malloc(sizeof(TSBNamespaces_t*)*((unsigned long)*length));
  memset(result, 0, sizeof(TSBNamespaces_t*)*((unsigned long)*length));
  for (int i = 0; i < *length; i++)
  {
    result[i] = ((TSBNamespaces*)supported->get((unsigned int)i))->clone();
  }
  TSBNamespaces::freeTSBNamespaces(const_cast<List*>(supported));
  return result;
}
/** @endcond */

LIBTSB_CPP_NAMESPACE_END

