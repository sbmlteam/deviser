/**
 * @file ClassTwo.cpp
 * @brief Implementation of the ClassTwo class.
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
#include <sbml/packages/test/sbml/ClassTwo.h>
#include <sbml/packages/test/sbml/ListOfClassTwos.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ClassTwo using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
ClassTwo::ClassTwo(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion)
  : SBase(level, version)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new ClassTwo using the given TestPkgNamespaces object.
 */
ClassTwo::ClassTwo(TestPkgNamespaces *testns)
  : SBase(testns)
{
  setElementNamespace(testns->getURI());
  loadPlugins(testns);
}


/*
 * Copy constructor for ClassTwo.
 */
ClassTwo::ClassTwo(const ClassTwo& orig)
  : SBase( orig )
{
}


/*
 * Assignment operator for ClassTwo.
 */
ClassTwo&
ClassTwo::operator=(const ClassTwo& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ClassTwo object.
 */
ClassTwo*
ClassTwo::clone() const
{
  return new ClassTwo(*this);
}


/*
 * Destructor for ClassTwo.
 */
ClassTwo::~ClassTwo()
{
}


/*
 * Returns the XML element name of this ClassTwo object.
 */
const std::string&
ClassTwo::getElementName() const
{
  static const string name = "classTwo";
  return name;
}


/*
 * Returns the libSBML type code for this ClassTwo object.
 */
int
ClassTwo::getTypeCode() const
{
  return SBML_TEST_CLASSTWO;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
ClassTwo::writeElements(XMLOutputStream& stream) const
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
ClassTwo::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
ClassTwo::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
ClassTwo::enablePackageInternal(const std::string& pkgURI,
                                const std::string& pkgPrefix,
                                bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::getAttribute(const std::string& attributeName,
                       std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this ClassTwo's attribute "attributeName" is
 * set.
 */
bool
ClassTwo::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this ClassTwo.
 */
int
ClassTwo::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ClassTwo_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
ClassTwo_t *
ClassTwo_create(unsigned int level,
                unsigned int version,
                unsigned int pkgVersion)
{
  return new ClassTwo(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ClassTwo_t object.
 */
LIBSBML_EXTERN
ClassTwo_t*
ClassTwo_clone(const ClassTwo_t* ct)
{
  if (ct != NULL)
  {
    return static_cast<ClassTwo_t*>(ct->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ClassTwo_t object.
 */
LIBSBML_EXTERN
void
ClassTwo_free(ClassTwo_t* ct)
{
  if (ct != NULL)
  {
    delete ct;
  }
}




LIBSBML_CPP_NAMESPACE_END


