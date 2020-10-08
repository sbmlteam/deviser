/**
 * @file CoreversmultipkgModelPlugin.cpp
 * @brief Implementation of the CoreversmultipkgModelPlugin class.
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
#include <sbml/packages/coreversmultipkg/extension/CoreversmultipkgModelPlugin.h>
#include <sbml/packages/coreversmultipkg/validator/CoreversmultipkgSBMLError.h>
#include <sbml/util/ElementFilter.h>
#include <sbml/Model.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new CoreversmultipkgModelPlugin using the given URI, prefix and
 * package namespace.
 */
CoreversmultipkgModelPlugin::CoreversmultipkgModelPlugin(
                                                         const std::string&
                                                           uri,
                                                         const std::string&
                                                           prefix,
                                                         CoreversmultipkgPkgNamespaces*
                                                           coreversmultipkgns)
  : SBasePlugin(uri, prefix, coreversmultipkgns)
  , mAttPlug (SBML_INT_MAX)
  , mIsSetAttPlug (false)
  , mAttPlug2 (SBML_INT_MAX)
  , mIsSetAttPlug2 (false)
  , mClassOneTwo (NULL)
  , mClassMult (NULL)
{
  connectToChild();
}


/*
 * Copy constructor for CoreversmultipkgModelPlugin.
 */
CoreversmultipkgModelPlugin::CoreversmultipkgModelPlugin(const
  CoreversmultipkgModelPlugin& orig)
  : SBasePlugin( orig )
  , mAttPlug ( orig.mAttPlug )
  , mIsSetAttPlug ( orig.mIsSetAttPlug )
  , mAttPlug2 ( orig.mAttPlug2 )
  , mIsSetAttPlug2 ( orig.mIsSetAttPlug2 )
  , mClassOneTwo ( NULL )
  , mClassMult ( NULL )
{
  if (orig.mClassOneTwo != NULL)
  {
    mClassOneTwo = orig.mClassOneTwo->clone();
  }

  if (orig.mClassMult != NULL)
  {
    mClassMult = orig.mClassMult->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for CoreversmultipkgModelPlugin.
 */
CoreversmultipkgModelPlugin&
CoreversmultipkgModelPlugin::operator=(const CoreversmultipkgModelPlugin& rhs)
{
  if (&rhs != this)
  {
    SBasePlugin::operator=(rhs);
    mAttPlug = rhs.mAttPlug;
    mIsSetAttPlug = rhs.mIsSetAttPlug;
    mAttPlug2 = rhs.mAttPlug2;
    mIsSetAttPlug2 = rhs.mIsSetAttPlug2;
    delete mClassOneTwo;
    if (rhs.mClassOneTwo != NULL)
    {
      mClassOneTwo = rhs.mClassOneTwo->clone();
    }
    else
    {
      mClassOneTwo = NULL;
    }

    delete mClassMult;
    if (rhs.mClassMult != NULL)
    {
      mClassMult = rhs.mClassMult->clone();
    }
    else
    {
      mClassMult = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this CoreversmultipkgModelPlugin object.
 */
CoreversmultipkgModelPlugin*
CoreversmultipkgModelPlugin::clone() const
{
  return new CoreversmultipkgModelPlugin(*this);
}


/*
 * Destructor for CoreversmultipkgModelPlugin.
 */
CoreversmultipkgModelPlugin::~CoreversmultipkgModelPlugin()
{
  delete mClassOneTwo;
  mClassOneTwo = NULL;
  delete mClassMult;
  mClassMult = NULL;
}


/*
 * Returns the value of the "attPlug" attribute of this
 * CoreversmultipkgModelPlugin.
 */
unsigned int
CoreversmultipkgModelPlugin::getAttPlug() const
{
  return mAttPlug;
}


/*
 * Returns the value of the "attPlug2" attribute of this
 * CoreversmultipkgModelPlugin.
 */
unsigned int
CoreversmultipkgModelPlugin::getAttPlug2() const
{
  return mAttPlug2;
}


/*
 * Predicate returning @c true if this CoreversmultipkgModelPlugin's "attPlug"
 * attribute is set.
 */
bool
CoreversmultipkgModelPlugin::isSetAttPlug() const
{
  return mIsSetAttPlug;
}


/*
 * Predicate returning @c true if this CoreversmultipkgModelPlugin's "attPlug2"
 * attribute is set.
 */
bool
CoreversmultipkgModelPlugin::isSetAttPlug2() const
{
  return mIsSetAttPlug2;
}


/*
 * Sets the value of the "attPlug" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::setAttPlug(unsigned int attPlug)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (coreLevel == 3 && coreVersion == 1 && pkgVersion == 2)
  {
    mAttPlug = attPlug;
    mIsSetAttPlug = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    mAttPlug = attPlug;
    mIsSetAttPlug = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "attPlug2" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::setAttPlug2(unsigned int attPlug2)
{
  unsigned int coreLevel = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if ((coreLevel == 3 && coreVersion == 2 && pkgVersion == 1) || (coreLevel ==
    3 && coreVersion == 2 && pkgVersion == 2) || (coreLevel == 4 && coreVersion
      == 1 && pkgVersion == 1))
  {
    mAttPlug2 = attPlug2;
    mIsSetAttPlug2 = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    mAttPlug2 = attPlug2;
    mIsSetAttPlug2 = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Unsets the value of the "attPlug" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::unsetAttPlug()
{
  mAttPlug = SBML_INT_MAX;
  mIsSetAttPlug = false;

  if (isSetAttPlug() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "attPlug2" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::unsetAttPlug2()
{
  mAttPlug2 = SBML_INT_MAX;
  mIsSetAttPlug2 = false;

  if (isSetAttPlug2() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "classOneTwo" element of this
 * CoreversmultipkgModelPlugin.
 */
const ClassOneTwo*
CoreversmultipkgModelPlugin::getClassOneTwo() const
{
  return mClassOneTwo;
}


/*
 * Returns the value of the "classOneTwo" element of this
 * CoreversmultipkgModelPlugin.
 */
ClassOneTwo*
CoreversmultipkgModelPlugin::getClassOneTwo()
{
  return mClassOneTwo;
}


/*
 * Returns the value of the "classMult" element of this
 * CoreversmultipkgModelPlugin.
 */
const ClassMult*
CoreversmultipkgModelPlugin::getClassMult() const
{
  return mClassMult;
}


/*
 * Returns the value of the "classMult" element of this
 * CoreversmultipkgModelPlugin.
 */
ClassMult*
CoreversmultipkgModelPlugin::getClassMult()
{
  return mClassMult;
}


/*
 * Predicate returning @c true if this CoreversmultipkgModelPlugin's
 * "classOneTwo" element is set.
 */
bool
CoreversmultipkgModelPlugin::isSetClassOneTwo() const
{
  return (mClassOneTwo != NULL);
}


/*
 * Predicate returning @c true if this CoreversmultipkgModelPlugin's
 * "classMult" element is set.
 */
bool
CoreversmultipkgModelPlugin::isSetClassMult() const
{
  return (mClassMult != NULL);
}


/*
 * Sets the value of the "classOneTwo" element of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::setClassOneTwo(const ClassOneTwo* classOneTwo)
{
  if (classOneTwo == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (classOneTwo->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != classOneTwo->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != classOneTwo->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != classOneTwo->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mClassOneTwo;
    mClassOneTwo = static_cast<ClassOneTwo*>(classOneTwo->clone());
    connectToChild();
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "classMult" element of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::setClassMult(const ClassMult* classMult)
{
  if (classMult == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (classMult->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != classMult->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != classMult->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != classMult->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mClassMult;
    mClassMult = static_cast<ClassMult*>(classMult->clone());
    connectToChild();
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new ClassOneTwo object, adds it to this
 * CoreversmultipkgModelPlugin object and returns the ClassOneTwo object
 * created.
 */
ClassOneTwo*
CoreversmultipkgModelPlugin::createClassOneTwo()
{
  if (mClassOneTwo != NULL)
  {
    delete mClassOneTwo;
  }

  COREVERSMULTIPKG_CREATE_NS(coreversmultipkgns, getSBMLNamespaces());
  mClassOneTwo = new ClassOneTwo(coreversmultipkgns);

  mClassOneTwo->setSBMLDocument(this->getSBMLDocument());

  delete coreversmultipkgns;

  connectToChild();

  return mClassOneTwo;
}


/*
 * Creates a new ClassMult object, adds it to this CoreversmultipkgModelPlugin
 * object and returns the ClassMult object created.
 */
ClassMult*
CoreversmultipkgModelPlugin::createClassMult()
{
  if (mClassMult != NULL)
  {
    delete mClassMult;
  }

  COREVERSMULTIPKG_CREATE_NS(coreversmultipkgns, getSBMLNamespaces());
  mClassMult = new ClassMult(coreversmultipkgns);

  mClassMult->setSBMLDocument(this->getSBMLDocument());

  delete coreversmultipkgns;

  connectToChild();

  return mClassMult;
}


/*
 * Unsets the value of the "classOneTwo" element of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::unsetClassOneTwo()
{
  delete mClassOneTwo;
  mClassOneTwo = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "classMult" element of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::unsetClassMult()
{
  delete mClassMult;
  mClassMult = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * CoreversmultipkgModelPlugin object have been set.
 */
bool
CoreversmultipkgModelPlugin::hasRequiredAttributes() const
{
  bool allPresent = true;

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 2 && pkgVersion == 2)
  {
    if (isSetAttPlug2() == false)
    {
      allPresent = false;
    }
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
CoreversmultipkgModelPlugin::writeElements(XMLOutputStream& stream) const
{
  if (isSetClassOneTwo() == true)
  {
    mClassOneTwo->write(stream);
  }

  if (isSetClassMult() == true)
  {
    mClassMult->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
CoreversmultipkgModelPlugin::accept(SBMLVisitor& v) const
{
  const Model* m = static_cast<const Model*>(this->getParentSBMLObject());
  v.visit(*m);
  v.leave(*m);

  if (mClassOneTwo != NULL)
  {
    mClassOneTwo->accept(v);
  }

  if (mClassMult != NULL)
  {
    mClassMult->accept(v);
  }

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
CoreversmultipkgModelPlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);

  if (mClassOneTwo != NULL)
  {
    mClassOneTwo->setSBMLDocument(d);
  }

  if (mClassMult != NULL)
  {
    mClassMult->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
CoreversmultipkgModelPlugin::connectToChild()
{
  connectToParent(getParentSBMLObject());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to parent element
 */
void
CoreversmultipkgModelPlugin::connectToParent(SBase* base)
{
  SBasePlugin::connectToParent(base);

  if (mClassOneTwo != NULL)
  {
    mClassOneTwo->connectToParent(base);
  }

  if (mClassMult != NULL)
  {
    mClassMult->connectToParent(base);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
CoreversmultipkgModelPlugin::enablePackageInternal(const std::string& pkgURI,
                                                   const std::string&
                                                     pkgPrefix,
                                                   bool flag)
{
  if (isSetClassOneTwo())
  {
    mClassOneTwo->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetClassMult())
  {
    mClassMult->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
CoreversmultipkgModelPlugin::updateSBMLNamespace(const std::string& package,
                                                 unsigned int level,
                                                 unsigned int version)
{
  SBasePlugin::updateSBMLNamespace(package, level, version);

  if (mClassOneTwo != NULL)
  {
    mClassOneTwo->updateSBMLNamespace(package, level, version);
  }

  if (mClassMult != NULL)
  {
    mClassMult->updateSBMLNamespace(package, level, version);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::getAttribute(const std::string& attributeName,
                                          bool& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::getAttribute(const std::string& attributeName,
                                          int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::getAttribute(const std::string& attributeName,
                                          double& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::getAttribute(const std::string& attributeName,
                                          unsigned int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "attPlug")
  {
    value = getAttPlug();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "attPlug2")
  {
    value = getAttPlug2();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::getAttribute(const std::string& attributeName,
                                          std::string& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this CoreversmultipkgModelPlugin's attribute
 * "attributeName" is set.
 */
bool
CoreversmultipkgModelPlugin::isSetAttribute(const std::string& attributeName)
  const
{
  bool value = SBasePlugin::isSetAttribute(attributeName);

  if (attributeName == "attPlug")
  {
    value = isSetAttPlug();
  }
  else if (attributeName == "attPlug2")
  {
    value = isSetAttPlug2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::setAttribute(const std::string& attributeName,
                                          bool value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::setAttribute(const std::string& attributeName,
                                          int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::setAttribute(const std::string& attributeName,
                                          double value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::setAttribute(const std::string& attributeName,
                                          unsigned int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  if (attributeName == "attPlug")
  {
    return_value = setAttPlug(value);
  }
  else if (attributeName == "attPlug2")
  {
    return_value = setAttPlug2(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::setAttribute(const std::string& attributeName,
                                          const std::string& value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::unsetAttribute(const std::string& attributeName)
{
  int value = SBasePlugin::unsetAttribute(attributeName);

  if (attributeName == "attPlug")
  {
    value = unsetAttPlug();
  }
  else if (attributeName == "attPlug2")
  {
    value = unsetAttPlug2();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this
 * CoreversmultipkgModelPlugin.
 */
SBase*
CoreversmultipkgModelPlugin::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "classOneTwo")
  {
    return createClassOneTwo();
  }
  else if (elementName == "classMult")
  {
    return createClassMult();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this CoreversmultipkgModelPlugin.
 */
int
CoreversmultipkgModelPlugin::addChildObject(const std::string& elementName,
                                            const SBase* element)
{
  if (elementName == "classOneTwo" && element->getTypeCode() ==
    SBML_COREVERS_CLASSONETWO)
  {
    return setClassOneTwo((const ClassOneTwo*)(element));
  }
  else if (elementName == "classMult" && element->getTypeCode() ==
    SBML_COREVERS_CLASSONETWO)
  {
    return setClassMult((const ClassMult*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * CoreversmultipkgModelPlugin.
 */
SBase*
CoreversmultipkgModelPlugin::removeChildObject(const std::string& elementName,
                                               const std::string& id)
{
  if (elementName == "classOneTwo")
  {
    ClassOneTwo * obj = mClassOneTwo;
    mClassOneTwo = NULL; return obj;
  }
  else if (elementName == "classMult")
  {
    ClassMult * obj = mClassMult;
    mClassMult = NULL; return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this CoreversmultipkgModelPlugin.
 */
unsigned int
CoreversmultipkgModelPlugin::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "classOneTwo")
  {
    if (isSetClassOneTwo())
    {
      return 1;
    }
  }
  else if (elementName == "classMult")
  {
    if (isSetClassMult())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this CoreversmultipkgModelPlugin.
 */
SBase*
CoreversmultipkgModelPlugin::getObject(const std::string& elementName,
                                       unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "classOneTwo")
  {
    return getClassOneTwo();
  }
  else if (elementName == "classMult")
  {
    return getClassMult();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
CoreversmultipkgModelPlugin::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mClassOneTwo != NULL)
  {
    if (mClassOneTwo->getId() == id)
    {
      return mClassOneTwo;
    }

    obj = mClassOneTwo->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mClassMult != NULL)
  {
    if (mClassMult->getId() == id)
    {
      return mClassMult;
    }

    obj = mClassMult->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
CoreversmultipkgModelPlugin::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mClassOneTwo != NULL)
  {
    if (mClassOneTwo->getMetaId() == metaid)
    {
      return mClassOneTwo;
    }

    obj = mClassOneTwo->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mClassMult != NULL)
  {
    if (mClassMult->getMetaId() == metaid)
    {
      return mClassMult;
    }

    obj = mClassMult->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
CoreversmultipkgModelPlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mClassOneTwo, filter);
  ADD_FILTERED_POINTER(ret, sublist, mClassMult, filter);


  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Append items from model (used in comp flattening)
 */
int
CoreversmultipkgModelPlugin::appendFrom(const Model* model)
{
  int ret = LIBSBML_OPERATION_SUCCESS;

  if (model == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  const CoreversmultipkgModelPlugin* plug = static_cast<const
    CoreversmultipkgModelPlugin*>(model->getPlugin(getPrefix()));

  if (plug == NULL)
  {
    return ret;
  }

  Model* parent = static_cast<Model*>(getParentSBMLObject());

  if (parent == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  return ret;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
CoreversmultipkgModelPlugin::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();
  const XMLNamespaces& xmlns = stream.peek().getNamespaces();
  const std::string& prefix = stream.peek().getPrefix();

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ?
    xmlns.getPrefix(mURI) : mPrefix;

  COREVERSMULTIPKG_CREATE_NS(coreversmultipkgns, getSBMLNamespaces());

  if (prefix == targetPrefix)
  {
    if (name == "classOneTwo")
    {
      if (getErrorLog() && isSetClassOneTwo())
      {
        getErrorLog()->logPackageError("coreversmultipkg",
          CoreversmultipkgModelAllowedElements, getPackageVersion(), getLevel(),
            getVersion(), "", getLine(), getColumn());
      }

      delete mClassOneTwo;
      mClassOneTwo = new ClassOneTwo(coreversmultipkgns);
      obj = mClassOneTwo;
    }
    else if (name == "classMult")
    {
      if (getErrorLog() && isSetClassMult())
      {
        getErrorLog()->logPackageError("coreversmultipkg",
          CoreversmultipkgModelAllowedElements, getPackageVersion(), getLevel(),
            getVersion(), "", getLine(), getColumn());
      }

      delete mClassMult;
      mClassMult = new ClassMult(coreversmultipkgns);
      obj = mClassMult;
    }
  }

  delete coreversmultipkgns;

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
CoreversmultipkgModelPlugin::addExpectedAttributes(ExpectedAttributes&
  attributes)
{
  SBasePlugin::addExpectedAttributes(attributes);

  unsigned int level = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && coreVersion == 1 && pkgVersion == 2)
  {
    attributes.add("attPlug");
  }

  if (level == 3 && coreVersion == 2 && pkgVersion == 1)
  {
    attributes.add("attPlug2");
  }

  if (level == 3 && coreVersion == 2 && pkgVersion == 2)
  {
    attributes.add("attPlug2");
  }

  if (level == 4 && coreVersion == 1 && pkgVersion == 1)
  {
    attributes.add("attPlug2");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
CoreversmultipkgModelPlugin::readAttributes(const XMLAttributes& attributes,
                                            const ExpectedAttributes&
                                              expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBasePlugin::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("coreversmultipkg",
          CoreversmultipkgModelAllowedAttributes, pkgVersion, level, version,
            details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("coreversmultipkg",
          CoreversmultipkgModelAllowedAttributes, pkgVersion, level, version,
            details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == NotSchemaConformant)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(NotSchemaConformant);
        log->logPackageError("coreversmultipkg",
          CoreversmultipkgModelAllowedAttributes, pkgVersion, level, version,
            details, getLine(), getColumn());
      }
    }
  }

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    readL3V1V2Attributes(attributes);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    readL3V2V1Attributes(attributes);
  }

  if (level == 3 && version == 2 && pkgVersion == 2)
  {
    readL3V2V2Attributes(attributes);
  }

  if (level == 4 && version == 1 && pkgVersion == 1)
  {
    readL4V1V1Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
CoreversmultipkgModelPlugin::readL3V1V2Attributes(const XMLAttributes&
  attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // attPlug uint (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetAttPlug = attributes.readInto("attPlug", mAttPlug);

  if ( mIsSetAttPlug == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Coreversmultipkg attribute 'attPlug' from the "
        "<CoreversmultipkgModelPlugin> element must be an integer.";
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgModelAttPlugMustBeNonNegativeInteger, pkgVersion, level,
          version, message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
CoreversmultipkgModelPlugin::readL3V2V1Attributes(const XMLAttributes&
  attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // attPlug2 uint (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetAttPlug2 = attributes.readInto("attPlug2", mAttPlug2);

  if ( mIsSetAttPlug2 == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Coreversmultipkg attribute 'attPlug2' from the "
        "<CoreversmultipkgModelPlugin> element must be an integer.";
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgModelAttPlug2MustBeNonNegativeInteger, pkgVersion, level,
          version, message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
CoreversmultipkgModelPlugin::readL3V2V2Attributes(const XMLAttributes&
  attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // attPlug2 uint (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetAttPlug2 = attributes.readInto("attPlug2", mAttPlug2);

  if ( mIsSetAttPlug2 == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Coreversmultipkg attribute 'attPlug2' from the "
        "<CoreversmultipkgModelPlugin> element must be an integer.";
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgModelAttPlug2MustBeNonNegativeInteger, pkgVersion, level,
          version, message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Coreversmultipkg attribute 'attPlug2' is missing "
        "from the <Model> element.";
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgModelAllowedAttributes, pkgVersion, level, version,
          message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
CoreversmultipkgModelPlugin::readL4V1V1Attributes(const XMLAttributes&
  attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // attPlug2 uint (use = "optional" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetAttPlug2 = attributes.readInto("attPlug2", mAttPlug2);

  if ( mIsSetAttPlug2 == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Coreversmultipkg attribute 'attPlug2' from the "
        "<CoreversmultipkgModelPlugin> element must be an integer.";
      log->logPackageError("coreversmultipkg",
        CoreversmultipkgModelAttPlug2MustBeNonNegativeInteger, pkgVersion, level,
          version, message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
CoreversmultipkgModelPlugin::writeAttributes(XMLOutputStream& stream) const
{
  SBasePlugin::writeAttributes(stream);

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    writeL3V1V2Attributes(stream);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    writeL3V2V1Attributes(stream);
  }

  if (level == 3 && version == 2 && pkgVersion == 2)
  {
    writeL3V2V2Attributes(stream);
  }

  if (level == 4 && version == 1 && pkgVersion == 1)
  {
    writeL4V1V1Attributes(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
CoreversmultipkgModelPlugin::writeL3V1V2Attributes(XMLOutputStream& stream)
  const
{
  if (isSetAttPlug() == true)
  {
    stream.writeAttribute("attPlug", getPrefix(), mAttPlug);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
CoreversmultipkgModelPlugin::writeL3V2V1Attributes(XMLOutputStream& stream)
  const
{
  if (isSetAttPlug2() == true)
  {
    stream.writeAttribute("attPlug2", getPrefix(), mAttPlug2);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
CoreversmultipkgModelPlugin::writeL3V2V2Attributes(XMLOutputStream& stream)
  const
{
  if (isSetAttPlug2() == true)
  {
    stream.writeAttribute("attPlug2", getPrefix(), mAttPlug2);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
CoreversmultipkgModelPlugin::writeL4V1V1Attributes(XMLOutputStream& stream)
  const
{
  if (isSetAttPlug2() == true)
  {
    stream.writeAttribute("attPlug2", getPrefix(), mAttPlug2);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Returns the value of the "attPlug" attribute of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
unsigned int
CoreversmultipkgModelPlugin_getAttPlug(const CoreversmultipkgModelPlugin_t *
  cmp)
{
  return (cmp != NULL) ? cmp->getAttPlug() : SBML_INT_MAX;
}


/*
 * Returns the value of the "attPlug2" attribute of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
unsigned int
CoreversmultipkgModelPlugin_getAttPlug2(const CoreversmultipkgModelPlugin_t *
  cmp)
{
  return (cmp != NULL) ? cmp->getAttPlug2() : SBML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this CoreversmultipkgModelPlugin_t's
 * "attPlug" attribute is set.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_isSetAttPlug(const CoreversmultipkgModelPlugin_t *
  cmp)
{
  return (cmp != NULL) ? static_cast<int>(cmp->isSetAttPlug()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this CoreversmultipkgModelPlugin_t's
 * "attPlug2" attribute is set.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_isSetAttPlug2(const CoreversmultipkgModelPlugin_t *
  cmp)
{
  return (cmp != NULL) ? static_cast<int>(cmp->isSetAttPlug2()) : 0;
}


/*
 * Sets the value of the "attPlug" attribute of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_setAttPlug(CoreversmultipkgModelPlugin_t * cmp,
                                       unsigned int attPlug)
{
  return (cmp != NULL) ? cmp->setAttPlug(attPlug) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "attPlug2" attribute of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_setAttPlug2(CoreversmultipkgModelPlugin_t * cmp,
                                        unsigned int attPlug2)
{
  return (cmp != NULL) ? cmp->setAttPlug2(attPlug2) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "attPlug" attribute of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_unsetAttPlug(CoreversmultipkgModelPlugin_t * cmp)
{
  return (cmp != NULL) ? cmp->unsetAttPlug() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "attPlug2" attribute of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_unsetAttPlug2(CoreversmultipkgModelPlugin_t * cmp)
{
  return (cmp != NULL) ? cmp->unsetAttPlug2() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "classOneTwo" element of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
const ClassOneTwo_t*
CoreversmultipkgModelPlugin_getClassOneTwo(const CoreversmultipkgModelPlugin_t
  * cmp)
{
  if (cmp == NULL)
  {
    return NULL;
  }

  return (ClassOneTwo_t*)(cmp->getClassOneTwo());
}


/*
 * Returns the value of the "classMult" element of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
const ClassMult_t*
CoreversmultipkgModelPlugin_getClassMult(const CoreversmultipkgModelPlugin_t *
  cmp)
{
  if (cmp == NULL)
  {
    return NULL;
  }

  return (ClassMult_t*)(cmp->getClassMult());
}


/*
 * Predicate returning @c 1 (true) if this CoreversmultipkgModelPlugin_t's
 * "classOneTwo" element is set.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_isSetClassOneTwo(const
  CoreversmultipkgModelPlugin_t * cmp)
{
  return (cmp != NULL) ? static_cast<int>(cmp->isSetClassOneTwo()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this CoreversmultipkgModelPlugin_t's
 * "classMult" element is set.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_isSetClassMult(const CoreversmultipkgModelPlugin_t
  * cmp)
{
  return (cmp != NULL) ? static_cast<int>(cmp->isSetClassMult()) : 0;
}


/*
 * Sets the value of the "classOneTwo" element of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_setClassOneTwo(CoreversmultipkgModelPlugin_t * cmp,
                                           const ClassOneTwo_t* classOneTwo)
{
  return (cmp != NULL) ? cmp->setClassOneTwo(classOneTwo) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "classMult" element of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_setClassMult(CoreversmultipkgModelPlugin_t * cmp,
                                         const ClassMult_t* classMult)
{
  return (cmp != NULL) ? cmp->setClassMult(classMult) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new ClassOneTwo_t object, adds it to this
 * CoreversmultipkgModelPlugin_t object and returns the ClassOneTwo_t object
 * created.
 */
LIBSBML_EXTERN
ClassOneTwo_t*
CoreversmultipkgModelPlugin_createClassOneTwo(CoreversmultipkgModelPlugin_t*
  cmp)
{
  if (cmp == NULL)
  {
    return NULL;
  }

  return (ClassOneTwo_t*)(cmp->createClassOneTwo());
}


/*
 * Creates a new ClassMult_t object, adds it to this
 * CoreversmultipkgModelPlugin_t object and returns the ClassMult_t object
 * created.
 */
LIBSBML_EXTERN
ClassMult_t*
CoreversmultipkgModelPlugin_createClassMult(CoreversmultipkgModelPlugin_t* cmp)
{
  if (cmp == NULL)
  {
    return NULL;
  }

  return (ClassMult_t*)(cmp->createClassMult());
}


/*
 * Unsets the value of the "classOneTwo" element of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_unsetClassOneTwo(CoreversmultipkgModelPlugin_t *
  cmp)
{
  return (cmp != NULL) ? cmp->unsetClassOneTwo() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "classMult" element of this
 * CoreversmultipkgModelPlugin_t.
 */
LIBSBML_EXTERN
int
CoreversmultipkgModelPlugin_unsetClassMult(CoreversmultipkgModelPlugin_t * cmp)
{
  return (cmp != NULL) ? cmp->unsetClassMult() : LIBSBML_INVALID_OBJECT;
}




LIBSBML_CPP_NAMESPACE_END


