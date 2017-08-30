/**
 * @file Compartment.cpp
 * @brief Implementation of the Compartment class.
 * @author DEVISER
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
#include <sbml/Compartment.h>
#include <sbml/SBMLListOfCompartments.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Compartment using the given SBML Level and @ p version values.
 */
Compartment::Compartment(unsigned int level, unsigned int version)
  : SBase(level, version)
  , mSize (util_NaN())
  , mIsSetSize (false)
  , mVolume (util_NaN())
  , mIsSetVolume (false)
  , mUnits ("")
  , mSpatialDimensions (SBML_INT_MAX)
  , mIsSetSpatialDimensions (false)
  , mConstant (false)
  , mIsSetConstant (false)
  , mOutside ("")
  , mCompartmentType ("")
{
  setSBMLNamespacesAndOwn(new SBMLNamespaces(level, version));
}


/*
 * Creates a new Compartment using the given SBMLNamespaces object @p sbmlns.
 */
Compartment::Compartment(SBMLNamespaces *sbmlns)
  : SBase(sbmlns)
  , mSize (util_NaN())
  , mIsSetSize (false)
  , mVolume (util_NaN())
  , mIsSetVolume (false)
  , mUnits ("")
  , mSpatialDimensions (SBML_INT_MAX)
  , mIsSetSpatialDimensions (false)
  , mConstant (false)
  , mIsSetConstant (false)
  , mOutside ("")
  , mCompartmentType ("")
{
  setElementNamespace(sbmlns->getURI());
}


/*
 * Copy constructor for Compartment.
 */
Compartment::Compartment(const Compartment& orig)
  : SBase( orig )
  , mSize ( orig.mSize )
  , mIsSetSize ( orig.mIsSetSize )
  , mVolume ( orig.mVolume )
  , mIsSetVolume ( orig.mIsSetVolume )
  , mUnits ( orig.mUnits )
  , mSpatialDimensions ( orig.mSpatialDimensions )
  , mIsSetSpatialDimensions ( orig.mIsSetSpatialDimensions )
  , mConstant ( orig.mConstant )
  , mIsSetConstant ( orig.mIsSetConstant )
  , mOutside ( orig.mOutside )
  , mCompartmentType ( orig.mCompartmentType )
{
}


/*
 * Assignment operator for Compartment.
 */
Compartment&
Compartment::operator=(const Compartment& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mSize = rhs.mSize;
    mIsSetSize = rhs.mIsSetSize;
    mVolume = rhs.mVolume;
    mIsSetVolume = rhs.mIsSetVolume;
    mUnits = rhs.mUnits;
    mSpatialDimensions = rhs.mSpatialDimensions;
    mIsSetSpatialDimensions = rhs.mIsSetSpatialDimensions;
    mConstant = rhs.mConstant;
    mIsSetConstant = rhs.mIsSetConstant;
    mOutside = rhs.mOutside;
    mCompartmentType = rhs.mCompartmentType;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Compartment object.
 */
Compartment*
Compartment::clone() const
{
  return new Compartment(*this);
}


/*
 * Destructor for Compartment.
 */
Compartment::~Compartment()
{
}


/*
 * Returns the value of the "size" attribute of this Compartment.
 */
double
Compartment::getSize() const
{
  return mSize;
}


/*
 * Returns the value of the "volume" attribute of this Compartment.
 */
double
Compartment::getVolume() const
{
  return mVolume;
}


/*
 * Returns the value of the "units" attribute of this Compartment.
 */
const std::string&
Compartment::getUnits() const
{
  return mUnits;
}


/*
 * Returns the value of the "spatialDimensions" attribute of this Compartment.
 */
unsigned int
Compartment::getSpatialDimensions() const
{
  return mSpatialDimensions;
}


/*
 * Returns the value of the "constant" attribute of this Compartment.
 */
bool
Compartment::getConstant() const
{
  return mConstant;
}


/*
 * Returns the value of the "outside" attribute of this Compartment.
 */
const std::string&
Compartment::getOutside() const
{
  return mOutside;
}


/*
 * Returns the value of the "compartmentType" attribute of this Compartment.
 */
const std::string&
Compartment::getCompartmentType() const
{
  return mCompartmentType;
}


/*
 * Predicate returning @c true if this Compartment's "size" attribute is set.
 */
bool
Compartment::isSetSize() const
{
  return mIsSetSize;
}


/*
 * Predicate returning @c true if this Compartment's "volume" attribute is set.
 */
bool
Compartment::isSetVolume() const
{
  return mIsSetVolume;
}


/*
 * Predicate returning @c true if this Compartment's "units" attribute is set.
 */
bool
Compartment::isSetUnits() const
{
  return (mUnits.empty() == false);
}


/*
 * Predicate returning @c true if this Compartment's "spatialDimensions"
 * attribute is set.
 */
bool
Compartment::isSetSpatialDimensions() const
{
  return mIsSetSpatialDimensions;
}


/*
 * Predicate returning @c true if this Compartment's "constant" attribute is
 * set.
 */
bool
Compartment::isSetConstant() const
{
  return mIsSetConstant;
}


/*
 * Predicate returning @c true if this Compartment's "outside" attribute is
 * set.
 */
bool
Compartment::isSetOutside() const
{
  return (mOutside.empty() == false);
}


/*
 * Predicate returning @c true if this Compartment's "compartmentType"
 * attribute is set.
 */
bool
Compartment::isSetCompartmentType() const
{
  return (mCompartmentType.empty() == false);
}


/*
 * Sets the value of the "size" attribute of this Compartment.
 */
int
Compartment::setSize(double size)
{
  mSize = size;
  mIsSetSize = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "volume" attribute of this Compartment.
 */
int
Compartment::setVolume(double volume)
{
  mVolume = volume;
  mIsSetVolume = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "units" attribute of this Compartment.
 */
int
Compartment::setUnits(const std::string& units)
{
  if (!(SyntaxChecker::isValidInternalUnitSId(units)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mUnits = units;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "spatialDimensions" attribute of this Compartment.
 */
int
Compartment::setSpatialDimensions(unsigned int spatialDimensions)
{
  mSpatialDimensions = spatialDimensions;
  mIsSetSpatialDimensions = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "constant" attribute of this Compartment.
 */
int
Compartment::setConstant(bool constant)
{
  mConstant = constant;
  mIsSetConstant = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "outside" attribute of this Compartment.
 */
int
Compartment::setOutside(const std::string& outside)
{
  if (!(SyntaxChecker::isValidInternalSId(outside)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mOutside = outside;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "compartmentType" attribute of this Compartment.
 */
int
Compartment::setCompartmentType(const std::string& compartmentType)
{
  if (!(SyntaxChecker::isValidInternalSId(compartmentType)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mCompartmentType = compartmentType;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "size" attribute of this Compartment.
 */
int
Compartment::unsetSize()
{
  mSize = util_NaN();
  mIsSetSize = false;

  if (isSetSize() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "volume" attribute of this Compartment.
 */
int
Compartment::unsetVolume()
{
  mVolume = util_NaN();
  mIsSetVolume = false;

  if (isSetVolume() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "units" attribute of this Compartment.
 */
int
Compartment::unsetUnits()
{
  mUnits.erase();

  if (mUnits.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "spatialDimensions" attribute of this Compartment.
 */
int
Compartment::unsetSpatialDimensions()
{
  mSpatialDimensions = SBML_INT_MAX;
  mIsSetSpatialDimensions = false;

  if (isSetSpatialDimensions() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "constant" attribute of this Compartment.
 */
int
Compartment::unsetConstant()
{
  mConstant = false;
  mIsSetConstant = false;

  if (isSetConstant() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "outside" attribute of this Compartment.
 */
int
Compartment::unsetOutside()
{
  mOutside.erase();

  if (mOutside.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "compartmentType" attribute of this Compartment.
 */
int
Compartment::unsetCompartmentType()
{
  mCompartmentType.erase();

  if (mCompartmentType.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * @copydoc doc_renamesidref_common
 */
void
Compartment::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetOutside() && mOutside == oldid)
  {
    setOutside(newid);
  }

  if (isSetCompartmentType() && mCompartmentType == oldid)
  {
    setCompartmentType(newid);
  }

  if (isSetUnits() && mUnits == oldid)
  {
    setUnits(newid);
  }
}


/*
 * Returns the XML element name of this Compartment object.
 */
const std::string&
Compartment::getElementName() const
{
  static const string name = "";
  return name;
}


/*
 * Returns the libSBML type code for this Compartment object.
 */
int
Compartment::getTypeCode() const
{
  return CORE_COMPARTMENT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * Compartment object have been set.
 */
bool
Compartment::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetConstant() == false)
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
Compartment::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Compartment::accept(SBMLVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Compartment::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "constant")
  {
    value = getConstant();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "size")
  {
    value = getSize();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "volume")
  {
    value = getVolume();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "spatialDimensions")
  {
    value = getSpatialDimensions();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::getAttribute(const std::string& attributeName,
                          std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "units")
  {
    value = getUnits();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "outside")
  {
    value = getOutside();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "compartmentType")
  {
    value = getCompartmentType();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::getAttribute(const std::string& attributeName,
                          const char* value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "units")
  {
    value = getUnits().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "outside")
  {
    value = getOutside().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "compartmentType")
  {
    value = getCompartmentType().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Compartment's attribute "attributeName"
 * is set.
 */
bool
Compartment::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "size")
  {
    value = isSetSize();
  }
  else if (attributeName == "volume")
  {
    value = isSetVolume();
  }
  else if (attributeName == "units")
  {
    value = isSetUnits();
  }
  else if (attributeName == "spatialDimensions")
  {
    value = isSetSpatialDimensions();
  }
  else if (attributeName == "constant")
  {
    value = isSetConstant();
  }
  else if (attributeName == "outside")
  {
    value = isSetOutside();
  }
  else if (attributeName == "compartmentType")
  {
    value = isSetCompartmentType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "constant")
  {
    return_value = setConstant(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "size")
  {
    return_value = setSize(value);
  }
  else if (attributeName == "volume")
  {
    return_value = setVolume(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "spatialDimensions")
  {
    return_value = setSpatialDimensions(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "units")
  {
    return_value = setUnits(value);
  }
  else if (attributeName == "outside")
  {
    return_value = setOutside(value);
  }
  else if (attributeName == "compartmentType")
  {
    return_value = setCompartmentType(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::setAttribute(const std::string& attributeName, const char* value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "units")
  {
    return_value = setUnits(value);
  }
  else if (attributeName == "outside")
  {
    return_value = setOutside(value);
  }
  else if (attributeName == "compartmentType")
  {
    return_value = setCompartmentType(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Compartment.
 */
int
Compartment::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "size")
  {
    value = unsetSize();
  }
  else if (attributeName == "volume")
  {
    value = unsetVolume();
  }
  else if (attributeName == "units")
  {
    value = unsetUnits();
  }
  else if (attributeName == "spatialDimensions")
  {
    value = unsetSpatialDimensions();
  }
  else if (attributeName == "constant")
  {
    value = unsetConstant();
  }
  else if (attributeName == "outside")
  {
    value = unsetOutside();
  }
  else if (attributeName == "compartmentType")
  {
    value = unsetCompartmentType();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
Compartment::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("size");

  attributes.add("volume");

  attributes.add("units");

  attributes.add("spatialDimensions");

  attributes.add("constant");

  attributes.add("outside");

  attributes.add("compartmentType");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Compartment::readAttributes(
                            const LIBSBML_CPP_NAMESPACE_QUALIFIER
                              XMLAttributes& attributes,
                            const LIBSBML_CPP_NAMESPACE_QUALIFIER
                              ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (static_cast<SBMLListOfCompartments*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SBMLUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SBMLUnknownCoreAttribute);
        log->logError(CoreModelLOCompartmentsAllowedCoreAttributes, level,
          version, details);
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == SBMLUnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(SBMLUnknownCoreAttribute);
      log->logError(CoreCompartmentAllowedAttributes, level, version, details);
    }
  }

  // 
  // size double (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetSize = attributes.readInto("size", mSize);

  if ( mIsSetSize == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Core attribute 'size' from the <Compartment> "
        "element must be an integer.";
      log->logError(CoreCompartmentSizeMustBeDouble, level, version, message);
    }
  }

  // 
  // volume double (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetVolume = attributes.readInto("volume", mVolume);

  if ( mIsSetVolume == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Core attribute 'volume' from the <Compartment> "
        "element must be an integer.";
      log->logError(CoreCompartmentVolumeMustBeDouble, level, version,
        message);
    }
  }

  // 
  // units UnitSIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("units", mUnits);

  if (assigned == true)
  {
    if (mUnits.empty() == true)
    {
      logEmptyString(mUnits, level, version, "<Compartment>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mUnits) == false)
    {
      logError(CoreCompartmentUnitsMustBeUnitSId, level, version, "The "
        "attribute units='" + mUnits + "' does not conform to the syntax.");
    }
  }

  // 
  // spatialDimensions uint (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetSpatialDimensions = attributes.readInto("spatialDimensions",
    mSpatialDimensions);

  if ( mIsSetSpatialDimensions == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Core attribute 'spatialDimensions' from the "
        "<Compartment> element must be an integer.";
      log->logError(CoreCompartmentSpatialDimensionsMustBeNonNegativeInteger,
        level, version, message);
    }
  }

  // 
  // constant bool (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetConstant = attributes.readInto("constant", mConstant);

  if (mIsSetConstant == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(CoreCompartmentConstantMustBeBoolean, level, version);
    }
    else
    {
      std::string message = "Core attribute 'constant' is missing from the "
        "<Compartment> element.";
      log->logError(CoreCompartmentAllowedAttributes, level, version, message);
    }
  }

  // 
  // outside SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("outside", mOutside);

  if (assigned == true)
  {
    if (mOutside.empty() == true)
    {
      logEmptyString(mOutside, level, version, "<Compartment>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mOutside) == false)
    {
      logError(CoreCompartmentOutsideMustBeCompartment, level, version, "The "
        "attribute outside='" + mOutside + "' does not conform to the syntax.");
    }
  }

  // 
  // compartmentType SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("compartmentType", mCompartmentType);

  if (assigned == true)
  {
    if (mCompartmentType.empty() == true)
    {
      logEmptyString(mCompartmentType, level, version, "<Compartment>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mCompartmentType) == false)
    {
      logError(CoreCompartmentCompartmentTypeMustBeCompartmentType, level,
        version, "The attribute compartmentType='" + mCompartmentType + "' does "
          "not conform to the syntax.");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Compartment::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SBase::writeAttributes(stream);

  if (isSetSize() == true)
  {
    stream.writeAttribute("size", getPrefix(), mSize);
  }

  if (isSetVolume() == true)
  {
    stream.writeAttribute("volume", getPrefix(), mVolume);
  }

  if (isSetUnits() == true)
  {
    stream.writeAttribute("units", getPrefix(), mUnits);
  }

  if (isSetSpatialDimensions() == true)
  {
    stream.writeAttribute("spatialDimensions", getPrefix(),
      mSpatialDimensions);
  }

  if (isSetConstant() == true)
  {
    stream.writeAttribute("constant", getPrefix(), mConstant);
  }

  if (isSetOutside() == true)
  {
    stream.writeAttribute("outside", getPrefix(), mOutside);
  }

  if (isSetCompartmentType() == true)
  {
    stream.writeAttribute("compartmentType", getPrefix(), mCompartmentType);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Compartment_t using the given SBML Level and @ p version
 * values.
 */
LIBSBML_EXTERN
Compartment_t *
Compartment_create(unsigned int level, unsigned int version)
{
  return new Compartment(level, version);
}


/*
 * Creates and returns a deep copy of this Compartment_t object.
 */
LIBSBML_EXTERN
Compartment_t*
Compartment_clone(const Compartment_t* c)
{
  if (c != NULL)
  {
    return static_cast<Compartment_t*>(c->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Compartment_t object.
 */
LIBSBML_EXTERN
void
Compartment_free(Compartment_t* c)
{
  if (c != NULL)
  {
    delete c;
  }
}


/*
 * Returns the value of the "size" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
double
Compartment_getSize(const Compartment_t * c)
{
  return (c != NULL) ? c->getSize() : util_NaN();
}


/*
 * Returns the value of the "volume" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
double
Compartment_getVolume(const Compartment_t * c)
{
  return (c != NULL) ? c->getVolume() : util_NaN();
}


/*
 * Returns the value of the "units" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
const char *
Compartment_getUnits(const Compartment_t * c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return c->getUnits().empty() ? NULL : safe_strdup(c->getUnits().c_str());
}


/*
 * Returns the value of the "spatialDimensions" attribute of this
 * Compartment_t.
 */
LIBSBML_EXTERN
unsigned int
Compartment_getSpatialDimensions(const Compartment_t * c)
{
  return (c != NULL) ? c->getSpatialDimensions() : SBML_INT_MAX;
}


/*
 * Returns the value of the "constant" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_getConstant(const Compartment_t * c)
{
  return (c != NULL) ? static_cast<int>(c->getConstant()) : 0;
}


/*
 * Returns the value of the "outside" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
const char *
Compartment_getOutside(const Compartment_t * c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return c->getOutside().empty() ? NULL : safe_strdup(c->getOutside().c_str());
}


/*
 * Returns the value of the "compartmentType" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
const char *
Compartment_getCompartmentType(const Compartment_t * c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return c->getCompartmentType().empty() ? NULL :
    safe_strdup(c->getCompartmentType().c_str());
}


/*
 * Predicate returning @c 1 if this Compartment_t's "size" attribute is set.
 */
LIBSBML_EXTERN
int
Compartment_isSetSize(const Compartment_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetSize()) : 0;
}


/*
 * Predicate returning @c 1 if this Compartment_t's "volume" attribute is set.
 */
LIBSBML_EXTERN
int
Compartment_isSetVolume(const Compartment_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetVolume()) : 0;
}


/*
 * Predicate returning @c 1 if this Compartment_t's "units" attribute is set.
 */
LIBSBML_EXTERN
int
Compartment_isSetUnits(const Compartment_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetUnits()) : 0;
}


/*
 * Predicate returning @c 1 if this Compartment_t's "spatialDimensions"
 * attribute is set.
 */
LIBSBML_EXTERN
int
Compartment_isSetSpatialDimensions(const Compartment_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetSpatialDimensions()) : 0;
}


/*
 * Predicate returning @c 1 if this Compartment_t's "constant" attribute is
 * set.
 */
LIBSBML_EXTERN
int
Compartment_isSetConstant(const Compartment_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetConstant()) : 0;
}


/*
 * Predicate returning @c 1 if this Compartment_t's "outside" attribute is set.
 */
LIBSBML_EXTERN
int
Compartment_isSetOutside(const Compartment_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetOutside()) : 0;
}


/*
 * Predicate returning @c 1 if this Compartment_t's "compartmentType" attribute
 * is set.
 */
LIBSBML_EXTERN
int
Compartment_isSetCompartmentType(const Compartment_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetCompartmentType()) : 0;
}


/*
 * Sets the value of the "size" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_setSize(Compartment_t * c, double size)
{
  return (c != NULL) ? c->setSize(size) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "volume" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_setVolume(Compartment_t * c, double volume)
{
  return (c != NULL) ? c->setVolume(volume) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "units" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_setUnits(Compartment_t * c, const char * units)
{
  return (c != NULL) ? c->setUnits(units) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "spatialDimensions" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_setSpatialDimensions(Compartment_t * c,
                                 unsigned int spatialDimensions)
{
  return (c != NULL) ? c->setSpatialDimensions(spatialDimensions) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "constant" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_setConstant(Compartment_t * c, int constant)
{
  return (c != NULL) ? c->setConstant(constant) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "outside" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_setOutside(Compartment_t * c, const char * outside)
{
  return (c != NULL) ? c->setOutside(outside) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "compartmentType" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_setCompartmentType(Compartment_t * c,
                               const char * compartmentType)
{
  return (c != NULL) ? c->setCompartmentType(compartmentType) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "size" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_unsetSize(Compartment_t * c)
{
  return (c != NULL) ? c->unsetSize() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "volume" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_unsetVolume(Compartment_t * c)
{
  return (c != NULL) ? c->unsetVolume() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "units" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_unsetUnits(Compartment_t * c)
{
  return (c != NULL) ? c->unsetUnits() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "spatialDimensions" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_unsetSpatialDimensions(Compartment_t * c)
{
  return (c != NULL) ? c->unsetSpatialDimensions() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "constant" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_unsetConstant(Compartment_t * c)
{
  return (c != NULL) ? c->unsetConstant() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "outside" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_unsetOutside(Compartment_t * c)
{
  return (c != NULL) ? c->unsetOutside() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "compartmentType" attribute of this Compartment_t.
 */
LIBSBML_EXTERN
int
Compartment_unsetCompartmentType(Compartment_t * c)
{
  return (c != NULL) ? c->unsetCompartmentType() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * Compartment_t object have been set.
 */
LIBSBML_EXTERN
int
Compartment_hasRequiredAttributes(const Compartment_t * c)
{
  return (c != NULL) ? static_cast<int>(c->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


