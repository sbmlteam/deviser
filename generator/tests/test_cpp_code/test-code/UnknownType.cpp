/**
 * @file UnknownType.cpp
 * @brief Implementation of the UnknownType class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
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
#include <sbml/packages/test/sbml/UnknownType.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new UnknownType using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
UnknownType::UnknownType(unsigned int level,
                         unsigned int version,
                         unsigned int pkgVersion)
  : SBase(level, version)
  , mAttribue (FIXME_fred)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new UnknownType using the given TestPkgNamespaces object.
 */
UnknownType::UnknownType(TestPkgNamespaces *testns)
  : SBase(testns)
  , mAttribue (FIXME_fred)
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for UnknownType.
 */
UnknownType::UnknownType(const UnknownType& orig)
  : SBase( orig )
  , mAttribue ( orig.mAttribue )
{
}


/*
 * Assignment operator for UnknownType.
 */
UnknownType&
UnknownType::operator=(const UnknownType& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mAttribue = rhs.mAttribue;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this UnknownType object.
 */
UnknownType*
UnknownType::clone() const
{
  return new UnknownType(*this);
}


/*
 * Destructor for UnknownType.
 */
UnknownType::~UnknownType()
{
}


/*
 * Returns the value of the "attribue" attribute of this UnknownType.
 */
FIXME_fred
UnknownType::getAttribue() const
{
  return mAttribue;
}


/*
 * Predicate returning @c true if this UnknownType's "attribue" attribute is
 * set.
 */
bool
UnknownType::isSetAttribue() const
{
  ;
}


/*
 * Sets the value of the "attribue" attribute of this UnknownType.
 */
int
UnknownType::setAttribue(FIXME_fred attribue)
{
}


/*
 * Unsets the value of the "attribue" attribute of this UnknownType.
 */
int
UnknownType::unsetAttribue()
{
  TO DO;
}


/*
 * Returns the XML element name of this UnknownType object.
 */
const std::string&
UnknownType::getElementName() const
{
  static const string name = "unknownType";
  return name;
}


/*
 * Returns the libSBML type code for this UnknownType object.
 */
int
UnknownType::getTypeCode() const
{
  return SBML_TEST_UNIT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * UnknownType object have been set.
 */
bool
UnknownType::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
UnknownType::writeElements(XMLOutputStream& stream) const
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
UnknownType::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
UnknownType::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
UnknownType::enablePackageInternal(const std::string& pkgURI,
                                   const std::string& pkgPrefix,
                                   bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::getAttribute(const std::string& attributeName,
                          std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::getAttribute(const std::string& attributeName,
                          const char* value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this UnknownType's attribute "attributeName"
 * is set.
 */
bool
UnknownType::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "attribue")
  {
    value = isSetAttribue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::setAttribute(const std::string& attributeName, const char* value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this UnknownType.
 */
int
UnknownType::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "attribue")
  {
    value = unsetAttribue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
UnknownType::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("attribue");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
UnknownType::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("test", TestUnknownTypeAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("test", TestUnknownTypeAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  // 
  // attribue fred (use = "optional" )
  // 

  assigned = attributes.readInto("attribue", mAttribue);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
UnknownType::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetAttribue() == true)
  {
    stream.writeAttribute("attribue", getPrefix(), mAttribue);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new UnknownType_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
UnknownType_t *
UnknownType_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
{
  return new UnknownType(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this UnknownType_t object.
 */
LIBSBML_EXTERN
UnknownType_t*
UnknownType_clone(const UnknownType_t* ut)
{
  if (ut != NULL)
  {
    return static_cast<UnknownType_t*>(ut->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this UnknownType_t object.
 */
LIBSBML_EXTERN
void
UnknownType_free(UnknownType_t* ut)
{
  if (ut != NULL)
  {
    delete ut;
  }
}


/*
 * Returns the value of the "attribue" attribute of this UnknownType_t.
 */
LIBSBML_EXTERN
FIXME_fred
UnknownType_getAttribue(const UnknownType_t * ut)
{
  if (ut == NULL)
  {
    return NULL;
  }

  return ut->getAttribue().empty() ? NULL :
    safe_strdup(ut->getAttribue().c_str());
}


/*
 * Predicate returning @c 1 if this UnknownType_t's "attribue" attribute is
 * set.
 */
LIBSBML_EXTERN
int
UnknownType_isSetAttribue(const UnknownType_t * ut)
{
  return (ut != NULL) ? static_cast<int>(ut->isSetAttribue()) : 0;
}


/*
 * Sets the value of the "attribue" attribute of this UnknownType_t.
 */
LIBSBML_EXTERN
int
UnknownType_setAttribue(UnknownType_t * ut, FIXME_fred attribue)
{
  return (ut != NULL) ? ut->setAttribue(attribue) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "attribue" attribute of this UnknownType_t.
 */
LIBSBML_EXTERN
int
UnknownType_unsetAttribue(UnknownType_t * ut)
{
  return (ut != NULL) ? ut->unsetAttribue() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * UnknownType_t object have been set.
 */
LIBSBML_EXTERN
int
UnknownType_hasRequiredAttributes(const UnknownType_t * ut)
{
  return (ut != NULL) ? static_cast<int>(ut->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


