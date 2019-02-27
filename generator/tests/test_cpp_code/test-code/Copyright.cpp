/**
 * @file Copyright.cpp
 * @brief Implementation of the Copyright class.
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
 * This file is part of SOMETHING.
 * 

 * Copyright (C) 2013-2016 jointly by the following organizations:
 * 1. Abcdefg
 * 2. Hijklmonp
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#include <sbml/packages/test/sbml/Copyright.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Copyright using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
Copyright::Copyright(unsigned int level,
                     unsigned int version,
                     unsigned int pkgVersion)
  : SBase(level, version)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new Copyright using the given TestPkgNamespaces object.
 */
Copyright::Copyright(TestPkgNamespaces *testns)
  : SBase(testns)
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for Copyright.
 */
Copyright::Copyright(const Copyright& orig)
  : SBase( orig )
{
}


/*
 * Assignment operator for Copyright.
 */
Copyright&
Copyright::operator=(const Copyright& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Copyright object.
 */
Copyright*
Copyright::clone() const
{
  return new Copyright(*this);
}


/*
 * Destructor for Copyright.
 */
Copyright::~Copyright()
{
}


/*
 * Returns the value of the "id" attribute of this Copyright.
 */
const std::string&
Copyright::getId() const
{
  return mId;
}


/*
 * Predicate returning @c true if this Copyright's "id" attribute is set.
 */
bool
Copyright::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this Copyright.
 */
int
Copyright::setId(const std::string& id)
{
  mId = id;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this Copyright.
 */
int
Copyright::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this Copyright object.
 */
const std::string&
Copyright::getElementName() const
{
  static const string name = "copyright";
  return name;
}


/*
 * Returns the libSBML type code for this Copyright object.
 */
int
Copyright::getTypeCode() const
{
  return SBML_TEST_MYBASE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * Copyright object have been set.
 */
bool
Copyright::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Copyright::writeElements(XMLOutputStream& stream) const
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
Copyright::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Copyright::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Copyright::enablePackageInternal(const std::string& pkgURI,
                                 const std::string& pkgPrefix,
                                 bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Copyright's attribute "attributeName" is
 * set.
 */
bool
Copyright::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Copyright.
 */
int
Copyright::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
Copyright::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Copyright::readAttributes(const XMLAttributes& attributes,
                          const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("test", TestCopyrightAllowedAttributes,
          pkgVersion, level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("test", TestCopyrightAllowedCoreAttributes,
          pkgVersion, level, version, details);
      }
    }
  }

  // 
  // id string (use = "optional" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<Copyright>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Copyright::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Copyright_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
Copyright_t *
Copyright_create(unsigned int level,
                 unsigned int version,
                 unsigned int pkgVersion)
{
  return new Copyright(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Copyright_t object.
 */
LIBSBML_EXTERN
Copyright_t*
Copyright_clone(const Copyright_t* c)
{
  if (c != NULL)
  {
    return static_cast<Copyright_t*>(c->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Copyright_t object.
 */
LIBSBML_EXTERN
void
Copyright_free(Copyright_t* c)
{
  if (c != NULL)
  {
    delete c;
  }
}


/*
 * Returns the value of the "id" attribute of this Copyright_t.
 */
LIBSBML_EXTERN
char *
Copyright_getId(const Copyright_t * c)
{
  if (c == NULL)
  {
    return NULL;
  }

  return c->getId().empty() ? NULL : safe_strdup(c->getId().c_str());
}


/*
 * Predicate returning @c 1 (true) if this Copyright_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
Copyright_isSetId(const Copyright_t * c)
{
  return (c != NULL) ? static_cast<int>(c->isSetId()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Copyright_t.
 */
LIBSBML_EXTERN
int
Copyright_setId(Copyright_t * c, const char * id)
{
  return (c != NULL) ? c->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Copyright_t.
 */
LIBSBML_EXTERN
int
Copyright_unsetId(Copyright_t * c)
{
  return (c != NULL) ? c->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Copyright_t object have been set.
 */
LIBSBML_EXTERN
int
Copyright_hasRequiredAttributes(const Copyright_t * c)
{
  return (c != NULL) ? static_cast<int>(c->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


