/**
 * @file MyLoTest.cpp
 * @brief Implementation of MyLoTest.
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




LIBSBML_CPP_NAMESPACE_END


