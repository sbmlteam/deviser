/**
 * @file ModifierSpeciesReference.cpp
 * @brief Implementation of the ModifierSpeciesReference class.
 * @author DEVISER
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
#include <sbml/ModifierSpeciesReference.h>
#include <sbml/SBMLListOfModifierSpeciesReferences.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ModifierSpeciesReference using the given SBML Level and @ p
 * version values.
 */
ModifierSpeciesReference::ModifierSpeciesReference(unsigned int level,
                                                   unsigned int version)
  : SimpleSpeciesReference(level, version)
  , mElementName("modifierSpeciesReference")
{
  setSBMLNamespacesAndOwn(new SBMLNamespaces(level, version));
}


/*
 * Creates a new ModifierSpeciesReference using the given SBMLNamespaces object
 * @p sbmlns.
 */
ModifierSpeciesReference::ModifierSpeciesReference(SBMLNamespaces *sbmlns)
  : SimpleSpeciesReference(sbmlns)
  , mElementName("modifierSpeciesReference")
{
  setElementNamespace(sbmlns->getURI());
}


/*
 * Copy constructor for ModifierSpeciesReference.
 */
ModifierSpeciesReference::ModifierSpeciesReference(const
  ModifierSpeciesReference& orig)
  : SimpleSpeciesReference( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for ModifierSpeciesReference.
 */
ModifierSpeciesReference&
ModifierSpeciesReference::operator=(const ModifierSpeciesReference& rhs)
{
  if (&rhs != this)
  {
    SimpleSpeciesReference::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ModifierSpeciesReference object.
 */
ModifierSpeciesReference*
ModifierSpeciesReference::clone() const
{
  return new ModifierSpeciesReference(*this);
}


/*
 * Destructor for ModifierSpeciesReference.
 */
ModifierSpeciesReference::~ModifierSpeciesReference()
{
}


/*
 * Returns the XML element name of this ModifierSpeciesReference object.
 */
const std::string&
ModifierSpeciesReference::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the XML name of this ModifierSpeciesReference object.
 */
void
ModifierSpeciesReference::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBML type code for this ModifierSpeciesReference object.
 */
int
ModifierSpeciesReference::getTypeCode() const
{
  return CORE_MODIFIERSPECIESREFERENCE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * ModifierSpeciesReference object have been set.
 */
bool
ModifierSpeciesReference::hasRequiredAttributes() const
{
  bool allPresent = SimpleSpeciesReference::hasRequiredAttributes();

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
ModifierSpeciesReference::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SimpleSpeciesReference::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
ModifierSpeciesReference::accept(SBMLVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
ModifierSpeciesReference::setSBMLDocument(SBMLDocument* d)
{
  SimpleSpeciesReference::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::getAttribute(const std::string& attributeName,
                                       bool& value) const
{
  int return_value = SimpleSpeciesReference::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::getAttribute(const std::string& attributeName,
                                       int& value) const
{
  int return_value = SimpleSpeciesReference::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::getAttribute(const std::string& attributeName,
                                       double& value) const
{
  int return_value = SimpleSpeciesReference::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::getAttribute(const std::string& attributeName,
                                       unsigned int& value) const
{
  int return_value = SimpleSpeciesReference::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::getAttribute(const std::string& attributeName,
                                       std::string& value) const
{
  int return_value = SimpleSpeciesReference::getAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this ModifierSpeciesReference's attribute
 * "attributeName" is set.
 */
bool
ModifierSpeciesReference::isSetAttribute(const std::string& attributeName)
  const
{
  bool value = SimpleSpeciesReference::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::setAttribute(const std::string& attributeName,
                                       bool value)
{
  int return_value = SimpleSpeciesReference::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::setAttribute(const std::string& attributeName,
                                       int value)
{
  int return_value = SimpleSpeciesReference::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::setAttribute(const std::string& attributeName,
                                       double value)
{
  int return_value = SimpleSpeciesReference::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::setAttribute(const std::string& attributeName,
                                       unsigned int value)
{
  int return_value = SimpleSpeciesReference::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::setAttribute(const std::string& attributeName,
                                       const std::string& value)
{
  int return_value = SimpleSpeciesReference::setAttribute(attributeName,
    value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * ModifierSpeciesReference.
 */
int
ModifierSpeciesReference::unsetAttribute(const std::string& attributeName)
{
  int value = SimpleSpeciesReference::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
ModifierSpeciesReference::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  SBase* obj = SimpleSpeciesReference::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
ModifierSpeciesReference::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SimpleSpeciesReference::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ModifierSpeciesReference::readAttributes(
                                         const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                           XMLAttributes& attributes,
                                         const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                           ExpectedAttributes&
                                             expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (log && getParentSBMLObject() && static_cast<SBMLListOfModifierSpeciesReferences*>(getParentSBMLObject())->size()
    < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SBMLUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SBMLUnknownCoreAttribute);
        log->logError(CoreReactionLOModifierSpeciesReferencesAllowedCoreAttributes,
          level, version, details);
      }
    }
  }

  SimpleSpeciesReference::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SBMLUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SBMLUnknownCoreAttribute);
        log->logError(CoreModifierSpeciesReferenceAllowedAttributes, level,
          version, details);
      }
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ModifierSpeciesReference::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SimpleSpeciesReference::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ModifierSpeciesReference_t using the given SBML Level and @ p
 * version values.
 */
LIBSBML_EXTERN
ModifierSpeciesReference_t *
ModifierSpeciesReference_create(unsigned int level, unsigned int version)
{
  return new ModifierSpeciesReference(level, version);
}


/*
 * Creates and returns a deep copy of this ModifierSpeciesReference_t object.
 */
LIBSBML_EXTERN
ModifierSpeciesReference_t*
ModifierSpeciesReference_clone(const ModifierSpeciesReference_t* msr)
{
  if (msr != NULL)
  {
    return static_cast<ModifierSpeciesReference_t*>(msr->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ModifierSpeciesReference_t object.
 */
LIBSBML_EXTERN
void
ModifierSpeciesReference_free(ModifierSpeciesReference_t* msr)
{
  if (msr != NULL)
  {
    delete msr;
  }
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * ModifierSpeciesReference_t object have been set.
 */
LIBSBML_EXTERN
int
ModifierSpeciesReference_hasRequiredAttributes(const ModifierSpeciesReference_t
  * msr)
{
  return (msr != NULL) ? static_cast<int>(msr->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


