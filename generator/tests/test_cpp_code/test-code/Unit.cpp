/**
 * @file Unit.cpp
 * @brief Implementation of the Unit class.
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
#include <sbml/packages/test/sbml/Unit.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Unit using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
Unit::Unit(unsigned int level, unsigned int version, unsigned int pkgVersion)
  : SBase(level, version)
  , mUnit ("")
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new Unit using the given TestPkgNamespaces object.
 */
Unit::Unit(TestPkgNamespaces *testns)
  : SBase(testns)
  , mUnit ("")
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for Unit.
 */
Unit::Unit(const Unit& orig)
  : SBase( orig )
  , mUnit ( orig.mUnit )
{
}


/*
 * Assignment operator for Unit.
 */
Unit&
Unit::operator=(const Unit& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mUnit = rhs.mUnit;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Unit object.
 */
Unit*
Unit::clone() const
{
  return new Unit(*this);
}


/*
 * Destructor for Unit.
 */
Unit::~Unit()
{
}


/*
 * Returns the value of the "unit" attribute of this Unit.
 */
const std::string&
Unit::getUnit() const
{
  return mUnit;
}


/*
 * Predicate returning @c true if this Unit's "unit" attribute is set.
 */
bool
Unit::isSetUnit() const
{
  return (mUnit.empty() == false);
}


/*
 * Sets the value of the "unit" attribute of this Unit.
 */
int
Unit::setUnit(const std::string& unit)
{
  if (!(SyntaxChecker::isValidInternalUnitSId(unit)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mUnit = unit;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "unit" attribute of this Unit.
 */
int
Unit::unsetUnit()
{
  mUnit.erase();

  if (mUnit.empty() == true)
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
Unit::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetUnit() && mUnit == oldid)
  {
    setUnit(newid);
  }
}


/*
 * Returns the XML element name of this Unit object.
 */
const std::string&
Unit::getElementName() const
{
  static const string name = "unit";
  return name;
}


/*
 * Returns the libSBML type code for this Unit object.
 */
int
Unit::getTypeCode() const
{
  return SBML_TEST_UNIT;
}


/*
 * Predicate returning @c true if all the required attributes for this Unit
 * object have been set.
 */
bool
Unit::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Unit::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Unit::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Unit::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Unit::enablePackageInternal(const std::string& pkgURI,
                            const std::string& pkgPrefix,
                            bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
Unit::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("unit");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Unit::readAttributes(const XMLAttributes& attributes,
                     const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("test", TestUnitAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("test", TestUnitAllowedCoreAttributes, pkgVersion,
        level, version, details);
    }
  }

  // 
  // unit UnitSIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("unit", mUnit);

  if (assigned == true)
  {
    if (mUnit.empty() == true)
    {
      logEmptyString(mUnit, level, version, "<Unit>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mUnit) == false)
    {
      logError(InvalidIdSyntax, level, version, "The attribute unit='" + mUnit
        + "' does not conform to the syntax.");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Unit::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetUnit() == true)
  {
    stream.writeAttribute("unit", getPrefix(), mUnit);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Unit_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
Unit_t *
Unit_create(unsigned int level, unsigned int version, unsigned int pkgVersion)
{
  return new Unit(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Unit_t object.
 */
LIBSBML_EXTERN
Unit_t*
Unit_clone(const Unit_t* u)
{
  if (u != NULL)
  {
    return static_cast<Unit_t*>(u->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Unit_t object.
 */
LIBSBML_EXTERN
void
Unit_free(Unit_t* u)
{
  if (u != NULL)
  {
    delete u;
  }
}


/*
 * Returns the value of the "unit" attribute of this Unit_t.
 */
LIBSBML_EXTERN
const char *
Unit_getUnit(const Unit_t * u)
{
  if (u == NULL)
  {
    return NULL;
  }

  return u->getUnit().empty() ? NULL : safe_strdup(u->getUnit().c_str());
}


/*
 * Predicate returning @c 1 if this Unit_t's "unit" attribute is set.
 */
LIBSBML_EXTERN
int
Unit_isSetUnit(const Unit_t * u)
{
  return (u != NULL) ? static_cast<int>(u->isSetUnit()) : 0;
}


/*
 * Sets the value of the "unit" attribute of this Unit_t.
 */
LIBSBML_EXTERN
int
Unit_setUnit(Unit_t * u, const char * unit)
{
  return (u != NULL) ? u->setUnit(unit) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "unit" attribute of this Unit_t.
 */
LIBSBML_EXTERN
int
Unit_unsetUnit(Unit_t * u)
{
  return (u != NULL) ? u->unsetUnit() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this Unit_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Unit_hasRequiredAttributes(const Unit_t * u)
{
  return (u != NULL) ? static_cast<int>(u->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


