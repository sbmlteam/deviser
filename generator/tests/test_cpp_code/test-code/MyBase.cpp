/**
 * @file MyBase.cpp
 * @brief Implementation of MyBase.
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
  : mId ("")
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new MyBase using the given TestPkgNamespaces object.
 */
MyBase::MyBase(TestPkgNamespaces *testns)
  : mId ("")
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for MyBase.
 */
MyBase::MyBase(const MyBase& orig)
  : mId ( orig.mId )
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
    mId = rhs.mId;
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
 * Predicate returning @c true or @c false depending on whether this MyBase's
 * "id" attribute has been set.
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
 * Returns the XML name of this MyBase object.
 */
const std::string&
MyBase::getElementName() const
{
  static const string name = "myBase";
  return name;
}


/*
 * Returns the libSBML typcode of this MyBase object.
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
  bool allPresent = None::hasRequiredAttributes();

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
MyBase::writeElements(XMLOutputStream& stream) const
{
  None::writeElements(stream);

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
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
MyBase::addExpectedAttributes(ExpectedAttributes& attributes)
{
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
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }
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
 * Predicate returning @c 1 or @c 0 depending on whether this MyBase_t's "id"
 * attribute has been set.
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


