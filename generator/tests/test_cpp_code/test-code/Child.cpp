/**
 * @file Child.cpp
 * @brief Implementation of the Child class.
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
#include <sbml/packages/nasty/sbml/Child.h>
#include <sbml/packages/nasty/sbml/ListOfChildren.h>
#include <sbml/packages/nasty/validator/NastySBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Child using the given SBML Level, Version and
 * &ldquo;nasty&rdquo; package version.
 */
Child::Child(unsigned int level,
             unsigned int version,
             unsigned int pkgVersion)
  : SBase(level, version)
{
  setSBMLNamespacesAndOwn(new NastyPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new Child using the given NastyPkgNamespaces object.
 */
Child::Child(NastyPkgNamespaces *nastyns)
  : SBase(nastyns)
{
  setElementNamespace(nastyns->getURI());
  loadPlugins(nastyns);
}


/*
 * Copy constructor for Child.
 */
Child::Child(const Child& orig)
  : SBase( orig )
{
}


/*
 * Assignment operator for Child.
 */
Child&
Child::operator=(const Child& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Child object.
 */
Child*
Child::clone() const
{
  return new Child(*this);
}


/*
 * Destructor for Child.
 */
Child::~Child()
{
}


/*
 * Returns the XML element name of this Child object.
 */
const std::string&
Child::getElementName() const
{
  static const string name = "child";
  return name;
}


/*
 * Returns the libSBML type code for this Child object.
 */
int
Child::getTypeCode() const
{
  return SBML_NASTY_CHILD;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Child::writeElements(XMLOutputStream& stream) const
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
Child::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Child::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Child::enablePackageInternal(const std::string& pkgURI,
                             const std::string& pkgPrefix,
                             bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Child_t using the given SBML Level, Version and
 * &ldquo;nasty&rdquo; package version.
 */
LIBSBML_EXTERN
Child_t *
Child_create(unsigned int level,
             unsigned int version,
             unsigned int pkgVersion)
{
  return new Child(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Child_t object.
 */
LIBSBML_EXTERN
Child_t*
Child_clone(const Child_t* c)
{
  if (c != NULL)
  {
    return static_cast<Child_t*>(c->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Child_t object.
 */
LIBSBML_EXTERN
void
Child_free(Child_t* c)
{
  if (c != NULL)
  {
    delete c;
  }
}




LIBSBML_CPP_NAMESPACE_END


