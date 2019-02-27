/**
 * @file MyLoTest.cpp
 * @brief Implementation of the MyLoTest class.
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
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#include <sbml/packages/test/sbml/MyLoTest.h>
#include <sbml/packages/test/sbml/ListOfMyLoTests.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new MyLoTest using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
MyLoTest::MyLoTest(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
  : SBase(level, version)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new MyLoTest using the given TestPkgNamespaces object.
 */
MyLoTest::MyLoTest(TestPkgNamespaces *testns)
  : SBase(testns)
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for MyLoTest.
 */
MyLoTest::MyLoTest(const MyLoTest& orig)
  : SBase( orig )
{
}


/*
 * Assignment operator for MyLoTest.
 */
MyLoTest&
MyLoTest::operator=(const MyLoTest& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this MyLoTest object.
 */
MyLoTest*
MyLoTest::clone() const
{
  return new MyLoTest(*this);
}


/*
 * Destructor for MyLoTest.
 */
MyLoTest::~MyLoTest()
{
}


/*
 * Returns the value of the "id" attribute of this MyLoTest.
 */
const std::string&
MyLoTest::getId() const
{
  return mId;
}


/*
 * Predicate returning @c true if this MyLoTest's "id" attribute is set.
 */
bool
MyLoTest::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this MyLoTest.
 */
int
MyLoTest::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Unsets the value of the "id" attribute of this MyLoTest.
 */
int
MyLoTest::unsetId()
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
 * Returns the XML element name of this MyLoTest object.
 */
const std::string&
MyLoTest::getElementName() const
{
  static const string name = "myLoTest";
  return name;
}


/*
 * Returns the libSBML type code for this MyLoTest object.
 */
int
MyLoTest::getTypeCode() const
{
  return TEST_LO_TEST;
}


/*
 * Predicate returning @c true if all the required attributes for this MyLoTest
 * object have been set.
 */
bool
MyLoTest::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
MyLoTest::writeElements(XMLOutputStream& stream) const
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
MyLoTest::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
MyLoTest::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
MyLoTest::enablePackageInternal(const std::string& pkgURI,
                                const std::string& pkgPrefix,
                                bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::getAttribute(const std::string& attributeName,
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
 * Predicate returning @c true if this MyLoTest's attribute "attributeName" is
 * set.
 */
bool
MyLoTest::isSetAttribute(const std::string& attributeName) const
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
 * Sets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::setAttribute(const std::string& attributeName,
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
 * Unsets the value of the "attributeName" attribute of this MyLoTest.
 */
int
MyLoTest::unsetAttribute(const std::string& attributeName)
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
MyLoTest::addExpectedAttributes(ExpectedAttributes& attributes)
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
MyLoTest::readAttributes(const XMLAttributes& attributes,
                         const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (log && getParentSBMLObject() &&
    static_cast<ListOfMyLoTests*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("test", TestContainerLOMyLoTestsAllowedAttributes,
          pkgVersion, level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("test",
          TestContainerLOMyLoTestsAllowedCoreAttributes, pkgVersion, level,
            version, details);
      }
    }
  }

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
        log->logPackageError("test", TestMyLoTestAllowedAttributes, pkgVersion,
          level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("test", TestMyLoTestAllowedCoreAttributes,
          pkgVersion, level, version, details);
      }
    }
  }

  // 
  // id SId (use = "optional" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<MyLoTest>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("test", TestIdSyntaxRule, pkgVersion, level,
        version, "The id on the <" + getElementName() + "> is '" + mId + "', "
          "which does not conform to the syntax.", getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
MyLoTest::writeAttributes(XMLOutputStream& stream) const
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
 * Creates a new MyLoTest_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
MyLoTest_t *
MyLoTest_create(unsigned int level,
                unsigned int version,
                unsigned int pkgVersion)
{
  return new MyLoTest(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this MyLoTest_t object.
 */
LIBSBML_EXTERN
MyLoTest_t*
MyLoTest_clone(const MyLoTest_t* mlt)
{
  if (mlt != NULL)
  {
    return static_cast<MyLoTest_t*>(mlt->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this MyLoTest_t object.
 */
LIBSBML_EXTERN
void
MyLoTest_free(MyLoTest_t* mlt)
{
  if (mlt != NULL)
  {
    delete mlt;
  }
}


/*
 * Returns the value of the "id" attribute of this MyLoTest_t.
 */
LIBSBML_EXTERN
char *
MyLoTest_getId(const MyLoTest_t * mlt)
{
  if (mlt == NULL)
  {
    return NULL;
  }

  return mlt->getId().empty() ? NULL : safe_strdup(mlt->getId().c_str());
}


/*
 * Predicate returning @c 1 (true) if this MyLoTest_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
MyLoTest_isSetId(const MyLoTest_t * mlt)
{
  return (mlt != NULL) ? static_cast<int>(mlt->isSetId()) : 0;
}


/*
 * Sets the value of the "id" attribute of this MyLoTest_t.
 */
LIBSBML_EXTERN
int
MyLoTest_setId(MyLoTest_t * mlt, const char * id)
{
  return (mlt != NULL) ? mlt->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this MyLoTest_t.
 */
LIBSBML_EXTERN
int
MyLoTest_unsetId(MyLoTest_t * mlt)
{
  return (mlt != NULL) ? mlt->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * MyLoTest_t object have been set.
 */
LIBSBML_EXTERN
int
MyLoTest_hasRequiredAttributes(const MyLoTest_t * mlt)
{
  return (mlt != NULL) ? static_cast<int>(mlt->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


