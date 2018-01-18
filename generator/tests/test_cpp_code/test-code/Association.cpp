/**
 * @file Association.cpp
 * @brief Implementation of the Association class.
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
#include <sbml/packages/fbc/sbml/Association.h>
#include <sbml/packages/fbc/sbml/ListOfAssociations.h>
#include <sbml/packages/fbc/validator/FbcSBMLError.h>

#include <sbml/packages/fbc/sbml/FbcAnd.h>
#include <sbml/packages/fbc/sbml/FbcOr.h>
#include <sbml/packages/fbc/sbml/GeneProductRef.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Association using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 */
Association::Association(unsigned int level,
                         unsigned int version,
                         unsigned int pkgVersion)
  : SBase(level, version)
{
  setSBMLNamespacesAndOwn(new FbcPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new Association using the given FbcPkgNamespaces object.
 */
Association::Association(FbcPkgNamespaces *fbcns)
  : SBase(fbcns)
{
  setElementNamespace(fbcns->getURI());
  loadPlugins(fbcns);
}


/*
 * Copy constructor for Association.
 */
Association::Association(const Association& orig)
  : SBase( orig )
{
}


/*
 * Assignment operator for Association.
 */
Association&
Association::operator=(const Association& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Association object.
 */
Association*
Association::clone() const
{
  return new Association(*this);
}


/*
 * Destructor for Association.
 */
Association::~Association()
{
}


/*
 * Predicate returning @c true if this abstract "Association" is of type FbcAnd
 */
bool
Association::isFbcAnd() const
{
  return dynamic_cast<const FbcAnd*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Association" is of type FbcOr
 */
bool
Association::isFbcOr() const
{
  return dynamic_cast<const FbcOr*>(this) != NULL;
}


/*
 * Predicate returning @c true if this abstract "Association" is of type
 * GeneProductRef
 */
bool
Association::isGeneProductRef() const
{
  return dynamic_cast<const GeneProductRef*>(this) != NULL;
}


/*
 * Returns the XML element name of this Association object.
 */
const std::string&
Association::getElementName() const
{
  static const string name = "association";
  return name;
}


/*
 * Returns the libSBML type code for this Association object.
 */
int
Association::getTypeCode() const
{
  return SBML_FBC_ASSOCIATION;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Association::writeElements(XMLOutputStream& stream) const
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
Association::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Association::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Association::enablePackageInternal(const std::string& pkgURI,
                                   const std::string& pkgPrefix,
                                   bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Association.
 */
int
Association::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Association.
 */
int
Association::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Association.
 */
int
Association::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Association.
 */
int
Association::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Association.
 */
int
Association::getAttribute(const std::string& attributeName,
                          std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Association's attribute "attributeName"
 * is set.
 */
bool
Association::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Association.
 */
int
Association::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Association.
 */
int
Association::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Association.
 */
int
Association::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Association.
 */
int
Association::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Association.
 */
int
Association::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Association.
 */
int
Association::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new FbcAnd (Association_t) using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 */
LIBSBML_EXTERN
Association_t *
Association_createFbcAnd(unsigned int level,
                         unsigned int version,
                         unsigned int pkgVersion)
{
  return new FbcAnd(level, version, pkgVersion);
}


/*
 * Creates a new FbcOr (Association_t) using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 */
LIBSBML_EXTERN
Association_t *
Association_createFbcOr(unsigned int level,
                        unsigned int version,
                        unsigned int pkgVersion)
{
  return new FbcOr(level, version, pkgVersion);
}


/*
 * Creates a new GeneProductRef (Association_t) using the given SBML Level,
 * Version and &ldquo;fbc&rdquo; package version.
 */
LIBSBML_EXTERN
Association_t *
Association_createGeneProductRef(unsigned int level,
                                 unsigned int version,
                                 unsigned int pkgVersion)
{
  return new GeneProductRef(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Association_t object.
 */
LIBSBML_EXTERN
Association_t*
Association_clone(const Association_t* a)
{
  if (a != NULL)
  {
    return static_cast<Association_t*>(a->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Association_t object.
 */
LIBSBML_EXTERN
void
Association_free(Association_t* a)
{
  if (a != NULL)
  {
    delete a;
  }
}


/*
 * Predicate returning @c 1 if this Association_t is of type FbcAnd_t
 */
LIBSBML_EXTERN
int
Association_isFbcAnd(const Association_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isFbcAnd()) : 0;
}


/*
 * Predicate returning @c 1 if this Association_t is of type FbcOr_t
 */
LIBSBML_EXTERN
int
Association_isFbcOr(const Association_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isFbcOr()) : 0;
}


/*
 * Predicate returning @c 1 if this Association_t is of type GeneProductRef_t
 */
LIBSBML_EXTERN
int
Association_isGeneProductRef(const Association_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isGeneProductRef()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


