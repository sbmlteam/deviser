/**
 * @file VersSpeciesPlugin.cpp
 * @brief Implementation of the VersSpeciesPlugin class.
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
#include <sbml/packages/vers/extension/VersSpeciesPlugin.h>
#include <sbml/packages/vers/validator/VersSBMLError.h>
#include <sbml/util/ElementFilter.h>
#include <sbml/Model.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new VersSpeciesPlugin using the given uri, prefix and package
 * namespace.
 */
VersSpeciesPlugin::VersSpeciesPlugin(const std::string& uri,
                                     const std::string& prefix,
                                     VersPkgNamespaces* versns)
  : SBasePlugin(uri, prefix, versns)
  , mSpecies_att_v1 ("")
  , mString_plugin_att ("")
  , mSpecies_att_v2 ("")
  , mClassOne (NULL)
  , mClassTwo (NULL)
  , mAnothers (versns)
{
  connectToChild();
}


/*
 * Copy constructor for VersSpeciesPlugin.
 */
VersSpeciesPlugin::VersSpeciesPlugin(const VersSpeciesPlugin& orig)
  : SBasePlugin( orig )
  , mSpecies_att_v1 ( orig.mSpecies_att_v1 )
  , mString_plugin_att ( orig.mString_plugin_att )
  , mSpecies_att_v2 ( orig.mSpecies_att_v2 )
  , mClassOne ( NULL )
  , mClassTwo ( NULL )
  , mAnothers ( orig.mAnothers )
{
  if (orig.mClassOne != NULL)
  {
    mClassOne = orig.mClassOne->clone();
  }

  if (orig.mClassTwo != NULL)
  {
    mClassTwo = orig.mClassTwo->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for VersSpeciesPlugin.
 */
VersSpeciesPlugin&
VersSpeciesPlugin::operator=(const VersSpeciesPlugin& rhs)
{
  if (&rhs != this)
  {
    SBasePlugin::operator=(rhs);
    mSpecies_att_v1 = rhs.mSpecies_att_v1;
    mString_plugin_att = rhs.mString_plugin_att;
    mSpecies_att_v2 = rhs.mSpecies_att_v2;
    mAnothers = rhs.mAnothers;
    delete mClassOne;
    if (rhs.mClassOne != NULL)
    {
      mClassOne = rhs.mClassOne->clone();
    }
    else
    {
      mClassOne = NULL;
    }

    delete mClassTwo;
    if (rhs.mClassTwo != NULL)
    {
      mClassTwo = rhs.mClassTwo->clone();
    }
    else
    {
      mClassTwo = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this VersSpeciesPlugin object.
 */
VersSpeciesPlugin*
VersSpeciesPlugin::clone() const
{
  return new VersSpeciesPlugin(*this);
}


/*
 * Destructor for VersSpeciesPlugin.
 */
VersSpeciesPlugin::~VersSpeciesPlugin()
{
  delete mClassOne;
  mClassOne = NULL;
  delete mClassTwo;
  mClassTwo = NULL;
}


/*
 * Returns the value of the "species_att_v1" attribute of this
 * VersSpeciesPlugin.
 */
const std::string&
VersSpeciesPlugin::getSpecies_att_v1() const
{
  return mSpecies_att_v1;
}


/*
 * Returns the value of the "string_plugin_att" attribute of this
 * VersSpeciesPlugin.
 */
const std::string&
VersSpeciesPlugin::getString_plugin_att() const
{
  return mString_plugin_att;
}


/*
 * Returns the value of the "species_att_v2" attribute of this
 * VersSpeciesPlugin.
 */
const std::string&
VersSpeciesPlugin::getSpecies_att_v2() const
{
  return mSpecies_att_v2;
}


/*
 * Predicate returning @c true if this VersSpeciesPlugin's "species_att_v1"
 * attribute is set.
 */
bool
VersSpeciesPlugin::isSetSpecies_att_v1() const
{
  return (mSpecies_att_v1.empty() == false);
}


/*
 * Predicate returning @c true if this VersSpeciesPlugin's "string_plugin_att"
 * attribute is set.
 */
bool
VersSpeciesPlugin::isSetString_plugin_att() const
{
  return (mString_plugin_att.empty() == false);
}


/*
 * Predicate returning @c true if this VersSpeciesPlugin's "species_att_v2"
 * attribute is set.
 */
bool
VersSpeciesPlugin::isSetSpecies_att_v2() const
{
  return (mSpecies_att_v2.empty() == false);
}


/*
 * Sets the value of the "species_att_v1" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setSpecies_att_v1(const std::string& species_att_v1)
{
  if (!(SyntaxChecker::isValidInternalSId(species_att_v1)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mSpecies_att_v1 = species_att_v1;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "string_plugin_att" attribute of this
 * VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setString_plugin_att(const std::string& string_plugin_att)
{
  mString_plugin_att = string_plugin_att;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "species_att_v2" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setSpecies_att_v2(const std::string& species_att_v2)
{
  if (!(SyntaxChecker::isValidInternalSId(species_att_v2)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mSpecies_att_v2 = species_att_v2;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "species_att_v1" attribute of this
 * VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::unsetSpecies_att_v1()
{
  mSpecies_att_v1.erase();

  if (mSpecies_att_v1.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "string_plugin_att" attribute of this
 * VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::unsetString_plugin_att()
{
  mString_plugin_att.erase();

  if (mString_plugin_att.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "species_att_v2" attribute of this
 * VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::unsetSpecies_att_v2()
{
  mSpecies_att_v2.erase();

  if (mSpecies_att_v2.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "classOne" element of this VersSpeciesPlugin.
 */
const ClassOne*
VersSpeciesPlugin::getClassOne() const
{
  return mClassOne;
}


/*
 * Returns the value of the "classOne" element of this VersSpeciesPlugin.
 */
ClassOne*
VersSpeciesPlugin::getClassOne()
{
  return mClassOne;
}


/*
 * Returns the value of the "classTwo" element of this VersSpeciesPlugin.
 */
const ClassTwo*
VersSpeciesPlugin::getClassTwo() const
{
  return mClassTwo;
}


/*
 * Returns the value of the "classTwo" element of this VersSpeciesPlugin.
 */
ClassTwo*
VersSpeciesPlugin::getClassTwo()
{
  return mClassTwo;
}


/*
 * Predicate returning @c true if this VersSpeciesPlugin's "classOne" element
 * is set.
 */
bool
VersSpeciesPlugin::isSetClassOne() const
{
  return (mClassOne != NULL);
}


/*
 * Predicate returning @c true if this VersSpeciesPlugin's "classTwo" element
 * is set.
 */
bool
VersSpeciesPlugin::isSetClassTwo() const
{
  return (mClassTwo != NULL);
}


/*
 * Sets the value of the "classOne" element of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setClassOne(const ClassOne* classOne)
{
  if (classOne == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (classOne->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != classOne->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != classOne->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != classOne->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mClassOne;
    mClassOne = static_cast<ClassOne*>(classOne->clone());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "classTwo" element of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setClassTwo(const ClassTwo* classTwo)
{
  if (classTwo == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (classTwo->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != classTwo->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != classTwo->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != classTwo->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mClassTwo;
    mClassTwo = static_cast<ClassTwo*>(classTwo->clone());
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new ClassOne object, adds it to this VersSpeciesPlugin object and
 * returns the ClassOne object created.
 */
ClassOne*
VersSpeciesPlugin::createClassOne()
{
  if (mClassOne != NULL)
  {
    delete mClassOne;
  }

  VERS_CREATE_NS(versns, getSBMLNamespaces());
  mClassOne = new ClassOne(versns);

  mClassOne->setSBMLDocument(this->getSBMLDocument());

  delete versns;

  connectToChild();

  return mClassOne;
}


/*
 * Creates a new ClassTwo object, adds it to this VersSpeciesPlugin object and
 * returns the ClassTwo object created.
 */
ClassTwo*
VersSpeciesPlugin::createClassTwo()
{
  if (mClassTwo != NULL)
  {
    delete mClassTwo;
  }

  VERS_CREATE_NS(versns, getSBMLNamespaces());
  mClassTwo = new ClassTwo(versns);

  mClassTwo->setSBMLDocument(this->getSBMLDocument());

  delete versns;

  connectToChild();

  return mClassTwo;
}


/*
 * Unsets the value of the "classOne" element of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::unsetClassOne()
{
  delete mClassOne;
  mClassOne = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "classTwo" element of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::unsetClassTwo()
{
  delete mClassTwo;
  mClassTwo = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the ListOfAnothers from this VersSpeciesPlugin.
 */
const ListOfAnothers*
VersSpeciesPlugin::getListOfAnothers() const
{
  return &mAnothers;
}


/*
 * Returns the ListOfAnothers from this VersSpeciesPlugin.
 */
ListOfAnothers*
VersSpeciesPlugin::getListOfAnothers()
{
  return &mAnothers;
}


/*
 * Get an Another from the VersSpeciesPlugin.
 */
Another*
VersSpeciesPlugin::getAnother(unsigned int n)
{
  return static_cast< Another*>(mAnothers.get(n));
}


/*
 * Get an Another from the VersSpeciesPlugin.
 */
const Another*
VersSpeciesPlugin::getAnother(unsigned int n) const
{
  return static_cast<const Another*>(mAnothers.get(n));
}


/*
 * Get an Another from the VersSpeciesPlugin based on its identifier.
 */
Another*
VersSpeciesPlugin::getAnother(const std::string& sid)
{
  return static_cast< Another*>(mAnothers.get(sid));
}


/*
 * Get an Another from the VersSpeciesPlugin based on its identifier.
 */
const Another*
VersSpeciesPlugin::getAnother(const std::string& sid) const
{
  return static_cast<const Another*>(mAnothers.get(sid));
}


/*
 * Adds a copy of the given Another to this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::addAnother(const Another* a)
{
  if (a == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (a->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != a->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != a->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != a->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else if (a->isSetId() && (mAnothers.get(a->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mAnothers.append(a);
  }
}


/*
 * Get the number of Another objects in this VersSpeciesPlugin.
 */
unsigned int
VersSpeciesPlugin::getNumAnothers() const
{
  return mAnothers.size();
}


/*
 * Creates a new Another object, adds it to this VersSpeciesPlugin object and
 * returns the Another object created.
 */
Another*
VersSpeciesPlugin::createAnother()
{
  Another* a = NULL;

  try
  {
    VERS_CREATE_NS(versns, getSBMLNamespaces());
    a = new Another(versns);
    delete versns;
  }
  catch (...)
  {
  }

  if (a != NULL)
  {
    mAnothers.appendAndOwn(a);
  }

  return a;
}


/*
 * Removes the nth Another from this VersSpeciesPlugin and returns a pointer to
 * it.
 */
Another*
VersSpeciesPlugin::removeAnother(unsigned int n)
{
  return static_cast<Another*>(mAnothers.remove(n));
}


/*
 * Removes the Another from this VersSpeciesPlugin based on its identifier and
 * returns a pointer to it.
 */
Another*
VersSpeciesPlugin::removeAnother(const std::string& sid)
{
  return static_cast<Another*>(mAnothers.remove(sid));
}


/*
 * Predicate returning @c true if all the required attributes for this
 * VersSpeciesPlugin object have been set.
 */
bool
VersSpeciesPlugin::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * VersSpeciesPlugin object have been set.
 */
bool
VersSpeciesPlugin::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
VersSpeciesPlugin::writeElements(XMLOutputStream& stream) const
{
  if (isSetClassOne() == true)
  {
    mClassOne->write(stream);
  }

  if (isSetClassTwo() == true)
  {
    mClassTwo->write(stream);
  }

  if (getNumAnothers() > 0)
  {
    mAnothers.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
VersSpeciesPlugin::accept(SBMLVisitor& v) const
{
  const Species* s = static_cast<const Species*>(this->getParentSBMLObject());
  v.visit(*s);
  v.leave(*s);

  if (mClassOne != NULL)
  {
    mClassOne->accept(v);
  }

  if (mClassTwo != NULL)
  {
    mClassTwo->accept(v);
  }

  mAnothers.accept(v);

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
VersSpeciesPlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);

  if (mClassOne != NULL)
  {
    mClassOne->setSBMLDocument(d);
  }

  if (mClassTwo != NULL)
  {
    mClassTwo->setSBMLDocument(d);
  }

  mAnothers.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
VersSpeciesPlugin::connectToChild()
{
  connectToParent(getParentSBMLObject());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to parent element
 */
void
VersSpeciesPlugin::connectToParent(SBase* base)
{
  SBasePlugin::connectToParent(base);

  if (mClassOne != NULL)
  {
    mClassOne->connectToParent(base);
  }

  if (mClassTwo != NULL)
  {
    mClassTwo->connectToParent(base);
  }

  mAnothers.connectToParent(base);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
VersSpeciesPlugin::enablePackageInternal(const std::string& pkgURI,
                                         const std::string& pkgPrefix,
                                         bool flag)
{
  if (isSetClassOne())
  {
    mClassOne->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetClassTwo())
  {
    mClassTwo->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  mAnothers.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::getAttribute(const std::string& attributeName,
                                bool& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::getAttribute(const std::string& attributeName,
                                int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::getAttribute(const std::string& attributeName,
                                double& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::getAttribute(const std::string& attributeName,
                                unsigned int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::getAttribute(const std::string& attributeName,
                                std::string& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "species_att_v1")
  {
    value = getSpecies_att_v1();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "string_plugin_att")
  {
    value = getString_plugin_att();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "species_att_v2")
  {
    value = getSpecies_att_v2();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::getAttribute(const std::string& attributeName,
                                const char* value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "species_att_v1")
  {
    value = getSpecies_att_v1().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "string_plugin_att")
  {
    value = getString_plugin_att().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "species_att_v2")
  {
    value = getSpecies_att_v2().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this VersSpeciesPlugin's attribute
 * "attributeName" is set.
 */
bool
VersSpeciesPlugin::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBasePlugin::isSetAttribute(attributeName);

  if (attributeName == "species_att_v1")
  {
    value = isSetSpecies_att_v1();
  }
  else if (attributeName == "string_plugin_att")
  {
    value = isSetString_plugin_att();
  }
  else if (attributeName == "species_att_v2")
  {
    value = isSetSpecies_att_v2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setAttribute(const std::string& attributeName,
                                double value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setAttribute(const std::string& attributeName,
                                unsigned int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setAttribute(const std::string& attributeName,
                                const std::string& value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  if (attributeName == "species_att_v1")
  {
    return_value = setSpecies_att_v1(value);
  }
  else if (attributeName == "string_plugin_att")
  {
    return_value = setString_plugin_att(value);
  }
  else if (attributeName == "species_att_v2")
  {
    return_value = setSpecies_att_v2(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::setAttribute(const std::string& attributeName,
                                const char* value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  if (attributeName == "species_att_v1")
  {
    return_value = setSpecies_att_v1(value);
  }
  else if (attributeName == "string_plugin_att")
  {
    return_value = setString_plugin_att(value);
  }
  else if (attributeName == "species_att_v2")
  {
    return_value = setSpecies_att_v2(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this VersSpeciesPlugin.
 */
int
VersSpeciesPlugin::unsetAttribute(const std::string& attributeName)
{
  int value = SBasePlugin::unsetAttribute(attributeName);

  if (attributeName == "species_att_v1")
  {
    value = unsetSpecies_att_v1();
  }
  else if (attributeName == "string_plugin_att")
  {
    value = unsetString_plugin_att();
  }
  else if (attributeName == "species_att_v2")
  {
    value = unsetSpecies_att_v2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this VersSpeciesPlugin.
 */
SBase*
VersSpeciesPlugin::createObject(const std::string& elementName)
{
  SBasePlugin* obj = NULL;

  if (elementName == "classOne")
  {
    return createClassOne();
  }
  else if (elementName == "classTwo")
  {
    return createClassTwo();
  }
  else if (elementName == "another")
  {
    return createAnother();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this VersSpeciesPlugin.
 */
unsigned int
VersSpeciesPlugin::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "classOne")
  {
    if (isSetClassOne())
    {
      return 1;
    }
  }
  else if (elementName == "classTwo")
  {
    if (isSetClassTwo())
    {
      return 1;
    }
  }
  else if (elementName == "another")
  {
    return getNumAnothers();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this VersSpeciesPlugin.
 */
SBase*
VersSpeciesPlugin::getObject(const std::string& elementName,
                             unsigned int index)
{
  SBasePlugin* obj = NULL;

  if (elementName == "classOne")
  {
    return getClassOne();
  }
  else if (elementName == "classTwo")
  {
    return getClassTwo();
  }
  else if (elementName == "another")
  {
    return getAnother(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
VersSpeciesPlugin::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mClassOne != NULL)
  {
    if (mClassOne->getId() == id)
    {
      return mClassOne;
    }

    obj = mClassOne->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mClassTwo != NULL)
  {
    if (mClassTwo->getId() == id)
    {
      return mClassTwo;
    }

    obj = mClassTwo->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  obj = mAnothers.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
VersSpeciesPlugin::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mClassOne != NULL)
  {
    if (mClassOne->getMetaId() == metaid)
    {
      return mClassOne;
    }

    obj = mClassOne->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mClassTwo != NULL)
  {
    if (mClassTwo->getMetaId() == metaid)
    {
      return mClassTwo;
    }

    obj = mClassTwo->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mAnothers.getMetaId() == metaid)
  {
    return &mAnothers;
  }

  obj = mAnothers.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
VersSpeciesPlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mClassOne, filter);
  ADD_FILTERED_POINTER(ret, sublist, mClassTwo, filter);

  ADD_FILTERED_LIST(ret, sublist, mAnothers, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Append items from model (used in comp flattening)
 */
int
VersSpeciesPlugin::appendFrom(const Model* model)
{
  int ret = LIBSBML_OPERATION_SUCCESS;

  if (model == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  const VersSpeciesPlugin* plug = static_cast<const
    VersSpeciesPlugin*>(model->getPlugin(getPrefix()));

  if (plug == NULL)
  {
    return ret;
  }

  Model* parent = static_cast<Model*>(getParentSBMLObject());

  if (parent == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  ret = mAnothers.appendFrom(plug->getListOfAnothers());

  if (ret != LIBSBML_OPERATION_SUCCESS)
  {
    return ret;
  }

  return ret;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
VersSpeciesPlugin::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();
  const XMLNamespaces& xmlns = stream.peek().getNamespaces();
  const std::string& prefix = stream.peek().getPrefix();

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ?
    xmlns.getPrefix(mURI) : mPrefix;

  VERS_CREATE_NS(versns, getSBMLNamespaces());

  if (prefix == targetPrefix)
  {
    if (name == "classOne")
    {
      if (mClassOne != NULL)
      {
        getErrorLog()->logPackageError("vers", VersSpeciesAllowedElements,
          getPackageVersion(), getLevel(), getVersion());
      }

      mClassOne = new ClassOne(versns);
      obj = mClassOne;
    }
    else if (name == "classTwo")
    {
      if (mClassTwo != NULL)
      {
        getErrorLog()->logPackageError("vers", VersSpeciesAllowedElements,
          getPackageVersion(), getLevel(), getVersion());
      }

      mClassTwo = new ClassTwo(versns);
      obj = mClassTwo;
    }
    else if (name == "listOfAnothers")
    {
      if (mAnothers.size() != 0)
      {
        getErrorLog()->logPackageError("vers", VersSpeciesAllowedElements,
          getPackageVersion(), getLevel(), getVersion());
      }

      obj = &mAnothers;
      if (targetPrefix.empty())
      {
        mAnothers.getSBMLDocument()->enableDefaultNS(mURI, true);
      }
    }
  }

  delete versns;

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
VersSpeciesPlugin::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBasePlugin::addExpectedAttributes(attributes);

  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    attributes.add("species_att_v1");
    attributes.add("string_plugin_att");
  }
  else
  {
    attributes.add("species_att_v2");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
VersSpeciesPlugin::readAttributes(const XMLAttributes& attributes,
                                  const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBasePlugin::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("vers", VersSpeciesAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("vers", VersSpeciesAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == NotSchemaConformant)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(NotSchemaConformant);
      log->logPackageError("vers", VersSpeciesAllowedAttributes, pkgVersion,
        level, version, details);
    }
  }

  if (pkgVersion == 1)
  {
    readV1Attributes(attributes);
  }
  else
  {
    readV2Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
VersSpeciesPlugin::readV1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // species_att_v1 SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("species_att_v1", mSpecies_att_v1);

  if (assigned == true)
  {
    if (mSpecies_att_v1.empty() == true)
    {
      logEmptyString(mSpecies_att_v1, level, version, pkgVersion,
        "<VersSpeciesPlugin>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mSpecies_att_v1) == false)
    {
      log->logPackageError("vers",
        VersVersSpeciesPluginSpecies_att_v1MustBeSId, pkgVersion, level, version,
          "The attribute species_att_v1='" + mSpecies_att_v1 + "' does not conform "
            "to the syntax.");
    }
  }

  // 
  // string_plugin_att string (use = "optional" )
  // 

  assigned = attributes.readInto("string_plugin_att", mString_plugin_att);

  if (assigned == true)
  {
    if (mString_plugin_att.empty() == true)
    {
      logEmptyString(mString_plugin_att, level, version, pkgVersion,
        "<VersSpeciesPlugin>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
VersSpeciesPlugin::readV2Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // species_att_v2 SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("species_att_v2", mSpecies_att_v2);

  if (assigned == true)
  {
    if (mSpecies_att_v2.empty() == true)
    {
      logEmptyString(mSpecies_att_v2, level, version, pkgVersion,
        "<VersSpeciesPlugin>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mSpecies_att_v2) == false)
    {
      log->logPackageError("vers",
        VersVersSpeciesPluginSpecies_att_v2MustBeSId, pkgVersion, level, version,
          "The attribute species_att_v2='" + mSpecies_att_v2 + "' does not conform "
            "to the syntax.");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
VersSpeciesPlugin::writeAttributes(XMLOutputStream& stream) const
{
  SBasePlugin::writeAttributes(stream);

  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    writeV1Attributes(stream);
  }
  else
  {
    writeV2Attributes(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
VersSpeciesPlugin::writeV1Attributes(XMLOutputStream& stream) const
{
  if (isSetSpecies_att_v1() == true)
  {
    stream.writeAttribute("species_att_v1", getPrefix(), mSpecies_att_v1);
  }

  if (isSetString_plugin_att() == true)
  {
    stream.writeAttribute("string_plugin_att", getPrefix(),
      mString_plugin_att);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
VersSpeciesPlugin::writeV2Attributes(XMLOutputStream& stream) const
{
  if (isSetSpecies_att_v2() == true)
  {
    stream.writeAttribute("species_att_v2", getPrefix(), mSpecies_att_v2);
  }
}

/** @endcond */




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END


