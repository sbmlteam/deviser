/**
 * @file MyBase.cpp
 * @brief Implementation of the MyBase class.
 * @author SBMLTeam
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
#include <sbml/packages/test/sbml/MyBase.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new MyBase using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
MyBase::MyBase(unsigned int level,
               unsigned int version,
               unsigned int pkgVersion)
  : SBase(level, version)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new MyBase using the given TestPkgNamespaces object.
 */
MyBase::MyBase(TestPkgNamespaces *testns)
  : SBase(testns)
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for MyBase.
 */
MyBase::MyBase(const MyBase& orig)
  : SBase( orig )
{
}


/*
 * Assignment operator for MyBase.
 */
MyBase&
MyBase::operator=(const MyBase& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this MyBase object.
 */
MyBase*
MyBase::clone() const
{
  return new MyBase(*this);
}


/*
 * Destructor for MyBase.
 */
MyBase::~MyBase()
{
}


/*
 * Returns the value of the "id" attribute of this MyBase.
 */
const std::string&
MyBase::getId() const
{
  return mId;
}


/*
 * Predicate returning @c true if this MyBase's "id" attribute is set.
 */
bool
MyBase::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this MyBase.
 */
int
MyBase::setId(const std::string& id)
{
  mId = id;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this MyBase.
 */
int
MyBase::unsetId()
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
 * Returns the XML element name of this MyBase object.
 */
const std::string&
MyBase::getElementName() const
{
  static const string name = "myBase";
  return name;
}


/*
 * Returns the libSBML type code for this MyBase object.
 */
int
MyBase::getTypeCode() const
{
  return SBML_TEST_MYBASE;
}


/*
 * Predicate returning @c true if all the required attributes for this MyBase
 * object have been set.
 */
bool
MyBase::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
MyBase::writeElements(XMLOutputStream& stream) const
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
MyBase::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
MyBase::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
MyBase::enablePackageInternal(const std::string& pkgURI,
                              const std::string& pkgPrefix,
                              bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::getAttribute(const std::string& attributeName,
                     unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::getAttribute(const std::string& attributeName,
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
 * Gets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::getAttribute(const std::string& attributeName,
                     const char* value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this MyBase's attribute "attributeName" is
 * set.
 */
bool
MyBase::isSetAttribute(const std::string& attributeName) const
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
 * Sets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::setAttribute(const std::string& attributeName,
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
 * Sets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::setAttribute(const std::string& attributeName, const char* value)
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
 * Unsets the value of the "attributeName" attribute of this MyBase.
 */
int
MyBase::unsetAttribute(const std::string& attributeName)
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
MyBase::addExpectedAttributes(ExpectedAttributes& attributes)
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
MyBase::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("test", TestMyBaseAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("test", TestMyBaseAllowedCoreAttributes, pkgVersion,
        level, version, details);
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
      logEmptyString(mId, level, version, "<MyBase>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
MyBase::writeAttributes(XMLOutputStream& stream) const
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
 * Creates a new MyBase_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
MyBase_t *
MyBase_create(unsigned int level,
              unsigned int version,
              unsigned int pkgVersion)
{
  return new MyBase(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this MyBase_t object.
 */
LIBSBML_EXTERN
MyBase_t*
MyBase_clone(const MyBase_t* mb)
{
  if (mb != NULL)
  {
    return static_cast<MyBase_t*>(mb->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this MyBase_t object.
 */
LIBSBML_EXTERN
void
MyBase_free(MyBase_t* mb)
{
  if (mb != NULL)
  {
    delete mb;
  }
}


/*
 * Returns the value of the "id" attribute of this MyBase_t.
 */
LIBSBML_EXTERN
const char *
MyBase_getId(const MyBase_t * mb)
{
  if (mb == NULL)
  {
    return NULL;
  }

  return mb->getId().empty() ? NULL : safe_strdup(mb->getId().c_str());
}


/*
 * Predicate returning @c 1 (true) if this MyBase_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
MyBase_isSetId(const MyBase_t * mb)
{
  return (mb != NULL) ? static_cast<int>(mb->isSetId()) : 0;
}


/*
 * Sets the value of the "id" attribute of this MyBase_t.
 */
LIBSBML_EXTERN
int
MyBase_setId(MyBase_t * mb, const char * id)
{
  return (mb != NULL) ? mb->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this MyBase_t.
 */
LIBSBML_EXTERN
int
MyBase_unsetId(MyBase_t * mb)
{
  return (mb != NULL) ? mb->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this MyBase_t
 * object have been set.
 */
LIBSBML_EXTERN
int
MyBase_hasRequiredAttributes(const MyBase_t * mb)
{
  return (mb != NULL) ? static_cast<int>(mb->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


