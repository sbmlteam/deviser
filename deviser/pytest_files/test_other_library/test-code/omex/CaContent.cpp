/**
 * @file CaContent.cpp
 * @brief Implementation of the CaContent class.
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
#include <omex/CaContent.h>
#include <omex/CaListOfContents.h>
#include <xml/XMLInputStream.h>


using namespace std;



LIBCOMBINE_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new CaContent using the given OMEX Level and @ p version values.
 */
CaContent::CaContent(unsigned int level, unsigned int version)
  : CaBase(level, version)
  , mLocation ("")
  , mFormat ("")
  , mMaster (false)
  , mIsSetMaster (false)
{
  setCaNamespacesAndOwn(new CaNamespaces(level, version));
}


/*
 * Creates a new CaContent using the given CaNamespaces object @p omexns.
 */
CaContent::CaContent(CaNamespaces *omexns)
  : CaBase(omexns)
  , mLocation ("")
  , mFormat ("")
  , mMaster (false)
  , mIsSetMaster (false)
{
  setElementNamespace(omexns->getURI());
}


/*
 * Copy constructor for CaContent.
 */
CaContent::CaContent(const CaContent& orig)
  : CaBase( orig )
  , mLocation ( orig.mLocation )
  , mFormat ( orig.mFormat )
  , mMaster ( orig.mMaster )
  , mIsSetMaster ( orig.mIsSetMaster )
{
}


/*
 * Assignment operator for CaContent.
 */
CaContent&
CaContent::operator=(const CaContent& rhs)
{
  if (&rhs != this)
  {
    CaBase::operator=(rhs);
    mLocation = rhs.mLocation;
    mFormat = rhs.mFormat;
    mMaster = rhs.mMaster;
    mIsSetMaster = rhs.mIsSetMaster;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this CaContent object.
 */
CaContent*
CaContent::clone() const
{
  return new CaContent(*this);
}


/*
 * Destructor for CaContent.
 */
CaContent::~CaContent()
{
}


/*
 * Returns the value of the "location" attribute of this CaContent.
 */
const std::string&
CaContent::getLocation() const
{
  return mLocation;
}


/*
 * Returns the value of the "format" attribute of this CaContent.
 */
const std::string&
CaContent::getFormat() const
{
  return mFormat;
}


/*
 * Returns the value of the "master" attribute of this CaContent.
 */
bool
CaContent::getMaster() const
{
  return mMaster;
}


/*
 * Predicate returning @c true if this CaContent's "location" attribute is set.
 */
bool
CaContent::isSetLocation() const
{
  return (mLocation.empty() == false);
}


/*
 * Predicate returning @c true if this CaContent's "format" attribute is set.
 */
bool
CaContent::isSetFormat() const
{
  return (mFormat.empty() == false);
}


/*
 * Predicate returning @c true if this CaContent's "master" attribute is set.
 */
bool
CaContent::isSetMaster() const
{
  return mIsSetMaster;
}


/*
 * Sets the value of the "location" attribute of this CaContent.
 */
int
CaContent::setLocation(const std::string& location)
{
  mLocation = location;
  return LIBCOMBINE_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "format" attribute of this CaContent.
 */
int
CaContent::setFormat(const std::string& format)
{
  mFormat = format;
  return LIBCOMBINE_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "master" attribute of this CaContent.
 */
int
CaContent::setMaster(bool master)
{
  mMaster = master;
  mIsSetMaster = true;
  return LIBCOMBINE_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "location" attribute of this CaContent.
 */
int
CaContent::unsetLocation()
{
  mLocation.erase();

  if (mLocation.empty() == true)
  {
    return LIBCOMBINE_OPERATION_SUCCESS;
  }
  else
  {
    return LIBCOMBINE_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "format" attribute of this CaContent.
 */
int
CaContent::unsetFormat()
{
  mFormat.erase();

  if (mFormat.empty() == true)
  {
    return LIBCOMBINE_OPERATION_SUCCESS;
  }
  else
  {
    return LIBCOMBINE_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "master" attribute of this CaContent.
 */
int
CaContent::unsetMaster()
{
  mMaster = false;
  mIsSetMaster = false;

  if (isSetMaster() == false)
  {
    return LIBCOMBINE_OPERATION_SUCCESS;
  }
  else
  {
    return LIBCOMBINE_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this CaContent object.
 */
const std::string&
CaContent::getElementName() const
{
  static const string name = "content";
  return name;
}


/*
 * Returns the libCombine type code for this CaContent object.
 */
int
CaContent::getTypeCode() const
{
  return LIB_COMBINE_CONTENT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * CaContent object have been set.
 */
bool
CaContent::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetLocation() == false)
  {
    allPresent = false;
  }

  if (isSetFormat() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenlibCombineInternal */

/*
 * Write any contained elements
 */
void
CaContent::writeElements(XMLOutputStream& stream) const
{
  CaBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Accepts the given CaVisitor
 */
bool
CaContent::accept(CaVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Sets the parent CaOmexManifest
 */
void
CaContent::setCaOmexManifest(CaOmexManifest* d)
{
  CaBase::setCaOmexManifest(d);
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Gets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = CaBase::getAttribute(attributeName, value);

  if (return_value == LIBCOMBINE_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "master")
  {
    value = getMaster();
    return_value = LIBCOMBINE_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Gets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = CaBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Gets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = CaBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Gets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = CaBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Gets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = CaBase::getAttribute(attributeName, value);

  if (return_value == LIBCOMBINE_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "location")
  {
    value = getLocation();
    return_value = LIBCOMBINE_OPERATION_SUCCESS;
  }
  else if (attributeName == "format")
  {
    value = getFormat();
    return_value = LIBCOMBINE_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Predicate returning @c true if this CaContent's attribute "attributeName" is
 * set.
 */
bool
CaContent::isSetAttribute(const std::string& attributeName) const
{
  bool value = CaBase::isSetAttribute(attributeName);

  if (attributeName == "location")
  {
    value = isSetLocation();
  }
  else if (attributeName == "format")
  {
    value = isSetFormat();
  }
  else if (attributeName == "master")
  {
    value = isSetMaster();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Sets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = CaBase::setAttribute(attributeName, value);

  if (attributeName == "master")
  {
    return_value = setMaster(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Sets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::setAttribute(const std::string& attributeName, int value)
{
  int return_value = CaBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Sets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::setAttribute(const std::string& attributeName, double value)
{
  int return_value = CaBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Sets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = CaBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Sets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = CaBase::setAttribute(attributeName, value);

  if (attributeName == "location")
  {
    return_value = setLocation(value);
  }
  else if (attributeName == "format")
  {
    return_value = setFormat(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Unsets the value of the "attributeName" attribute of this CaContent.
 */
int
CaContent::unsetAttribute(const std::string& attributeName)
{
  int value = CaBase::unsetAttribute(attributeName);

  if (attributeName == "location")
  {
    value = unsetLocation();
  }
  else if (attributeName == "format")
  {
    value = unsetFormat();
  }
  else if (attributeName == "master")
  {
    value = unsetMaster();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Adds the expected attributes for this element
 */
void
CaContent::addExpectedAttributes(ExpectedAttributes& attributes)
{
  CaBase::addExpectedAttributes(attributes);

  attributes.add("location");

  attributes.add("format");

  attributes.add("master");
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
CaContent::readAttributes(const XMLAttributes& attributes,
                          const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  CaErrorLog* log = getErrorLog();

  if (log && getParentCaObject() &&
    static_cast<CaListOfContents*>(getParentCaObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == CaUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(CaUnknownCoreAttribute);
        log->logError(CombineOmexManifestLOContentsAllowedCoreAttributes,
          level, version, details, getLine(), getColumn());
      }
    }
  }

  CaBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == CaUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(CaUnknownCoreAttribute);
        log->logError(CombineContentAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // location string (use = "required" )
  // 

  assigned = attributes.readInto("location", mLocation);

  if (assigned == true)
  {
    if (mLocation.empty() == true)
    {
      logEmptyString(mLocation, level, version, "<CaContent>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Combine attribute 'location' is missing from the "
        "<CaContent> element.";
      log->logError(CombineContentAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // format string (use = "required" )
  // 

  assigned = attributes.readInto("format", mFormat);

  if (assigned == true)
  {
    if (mFormat.empty() == true)
    {
      logEmptyString(mFormat, level, version, "<CaContent>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Combine attribute 'format' is missing from the "
        "<CaContent> element.";
      log->logError(CombineContentAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // master bool (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetMaster = attributes.readInto("master", mMaster);

  if (mIsSetMaster == false)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(CombineContentMasterMustBeBoolean, level, version);
    }
  }
}

/** @endcond */



/** @cond doxygenlibCombineInternal */

/*
 * Writes the attributes to the stream
 */
void
CaContent::writeAttributes(XMLOutputStream& stream) const
{
  CaBase::writeAttributes(stream);

  if (isSetLocation() == true)
  {
    stream.writeAttribute("location", getPrefix(), mLocation);
  }

  if (isSetFormat() == true)
  {
    stream.writeAttribute("format", getPrefix(), mFormat);
  }

  if (isSetMaster() == true)
  {
    stream.writeAttribute("master", getPrefix(), mMaster);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new CaContent_t using the given OMEX Level and @ p version values.
 */
LIBCOMBINE_EXTERN
CaContent_t *
CaContent_create(unsigned int level, unsigned int version)
{
  return new CaContent(level, version);
}


/*
 * Creates and returns a deep copy of this CaContent_t object.
 */
LIBCOMBINE_EXTERN
CaContent_t*
CaContent_clone(const CaContent_t* cc)
{
  if (cc != NULL)
  {
    return static_cast<CaContent_t*>(cc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this CaContent_t object.
 */
LIBCOMBINE_EXTERN
void
CaContent_free(CaContent_t* cc)
{
  if (cc != NULL)
  {
    delete cc;
  }
}


/*
 * Returns the value of the "location" attribute of this CaContent_t.
 */
LIBCOMBINE_EXTERN
char *
CaContent_getLocation(const CaContent_t * cc)
{
  if (cc == NULL)
  {
    return NULL;
  }

  return cc->getLocation().empty() ? NULL :
    omex_safe_strdup(cc->getLocation().c_str());
}


/*
 * Returns the value of the "format" attribute of this CaContent_t.
 */
LIBCOMBINE_EXTERN
char *
CaContent_getFormat(const CaContent_t * cc)
{
  if (cc == NULL)
  {
    return NULL;
  }

  return cc->getFormat().empty() ? NULL :
    omex_safe_strdup(cc->getFormat().c_str());
}


/*
 * Returns the value of the "master" attribute of this CaContent_t.
 */
LIBCOMBINE_EXTERN
int
CaContent_getMaster(const CaContent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->getMaster()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this CaContent_t's "location" attribute
 * is set.
 */
LIBCOMBINE_EXTERN
int
CaContent_isSetLocation(const CaContent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->isSetLocation()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this CaContent_t's "format" attribute is
 * set.
 */
LIBCOMBINE_EXTERN
int
CaContent_isSetFormat(const CaContent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->isSetFormat()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this CaContent_t's "master" attribute is
 * set.
 */
LIBCOMBINE_EXTERN
int
CaContent_isSetMaster(const CaContent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->isSetMaster()) : 0;
}


/*
 * Sets the value of the "location" attribute of this CaContent_t.
 */
LIBCOMBINE_EXTERN
int
CaContent_setLocation(CaContent_t * cc, const char * location)
{
  return (cc != NULL) ? cc->setLocation(location) : LIBCOMBINE_INVALID_OBJECT;
}


/*
 * Sets the value of the "format" attribute of this CaContent_t.
 */
LIBCOMBINE_EXTERN
int
CaContent_setFormat(CaContent_t * cc, const char * format)
{
  return (cc != NULL) ? cc->setFormat(format) : LIBCOMBINE_INVALID_OBJECT;
}


/*
 * Sets the value of the "master" attribute of this CaContent_t.
 */
LIBCOMBINE_EXTERN
int
CaContent_setMaster(CaContent_t * cc, int master)
{
  return (cc != NULL) ? cc->setMaster(master) : LIBCOMBINE_INVALID_OBJECT;
}


/*
 * Unsets the value of the "location" attribute of this CaContent_t.
 */
LIBCOMBINE_EXTERN
int
CaContent_unsetLocation(CaContent_t * cc)
{
  return (cc != NULL) ? cc->unsetLocation() : LIBCOMBINE_INVALID_OBJECT;
}


/*
 * Unsets the value of the "format" attribute of this CaContent_t.
 */
LIBCOMBINE_EXTERN
int
CaContent_unsetFormat(CaContent_t * cc)
{
  return (cc != NULL) ? cc->unsetFormat() : LIBCOMBINE_INVALID_OBJECT;
}


/*
 * Unsets the value of the "master" attribute of this CaContent_t.
 */
LIBCOMBINE_EXTERN
int
CaContent_unsetMaster(CaContent_t * cc)
{
  return (cc != NULL) ? cc->unsetMaster() : LIBCOMBINE_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * CaContent_t object have been set.
 */
LIBCOMBINE_EXTERN
int
CaContent_hasRequiredAttributes(const CaContent_t * cc)
{
  return (cc != NULL) ? static_cast<int>(cc->hasRequiredAttributes()) : 0;
}




LIBCOMBINE_CPP_NAMESPACE_END


