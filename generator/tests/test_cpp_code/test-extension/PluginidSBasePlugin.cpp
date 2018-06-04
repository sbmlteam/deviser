/**
 * @file PluginidSBasePlugin.cpp
 * @brief Implementation of the PluginidSBasePlugin class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
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
#include <sbml/packages/pluginid/extension/PluginidSBasePlugin.h>
#include <sbml/packages/pluginid/validator/PluginidSBMLError.h>
#include <sbml/util/ElementFilter.h>
#include <sbml/Model.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new PluginidSBasePlugin using the given URI, prefix and package
 * namespace.
 */
PluginidSBasePlugin::PluginidSBasePlugin(const std::string& uri,
                                         const std::string& prefix,
                                         PluginidPkgNamespaces* pluginidns)
  : SBasePlugin(uri, prefix, pluginidns)
  , mId ("")
  , mPlugAtt ("")
  , mOtherNormalClass (NULL)
{
  connectToChild();
}


/*
 * Copy constructor for PluginidSBasePlugin.
 */
PluginidSBasePlugin::PluginidSBasePlugin(const PluginidSBasePlugin& orig)
  : SBasePlugin( orig )
  , mId ( orig.mId )
  , mPlugAtt ( orig.mPlugAtt )
  , mOtherNormalClass ( NULL )
{
  if (orig.mOtherNormalClass != NULL)
  {
    mOtherNormalClass = orig.mOtherNormalClass->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for PluginidSBasePlugin.
 */
PluginidSBasePlugin&
PluginidSBasePlugin::operator=(const PluginidSBasePlugin& rhs)
{
  if (&rhs != this)
  {
    SBasePlugin::operator=(rhs);
    mId = rhs.mId;
    mPlugAtt = rhs.mPlugAtt;
    delete mOtherNormalClass;
    if (rhs.mOtherNormalClass != NULL)
    {
      mOtherNormalClass = rhs.mOtherNormalClass->clone();
    }
    else
    {
      mOtherNormalClass = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this PluginidSBasePlugin object.
 */
PluginidSBasePlugin*
PluginidSBasePlugin::clone() const
{
  return new PluginidSBasePlugin(*this);
}


/*
 * Destructor for PluginidSBasePlugin.
 */
PluginidSBasePlugin::~PluginidSBasePlugin()
{
  delete mOtherNormalClass;
  mOtherNormalClass = NULL;
}


/*
 * Returns the value of the "id" attribute of this PluginidSBasePlugin.
 */
const std::string&
PluginidSBasePlugin::getId() const
{
  return mId;
}


/*
 * Returns the value of the "plugAtt" attribute of this PluginidSBasePlugin.
 */
const std::string&
PluginidSBasePlugin::getPlugAtt() const
{
  return mPlugAtt;
}


/*
 * Predicate returning @c true if this PluginidSBasePlugin's "id" attribute is
 * set.
 */
bool
PluginidSBasePlugin::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this PluginidSBasePlugin's "plugAtt"
 * attribute is set.
 */
bool
PluginidSBasePlugin::isSetPlugAtt() const
{
  return (mPlugAtt.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "plugAtt" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::setPlugAtt(const std::string& plugAtt)
{
  mPlugAtt = plugAtt;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::unsetId()
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
 * Unsets the value of the "plugAtt" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::unsetPlugAtt()
{
  mPlugAtt.erase();

  if (mPlugAtt.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin.
 */
const OtherNormalClass*
PluginidSBasePlugin::getOtherNormalClass() const
{
  return mOtherNormalClass;
}


/*
 * Returns the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin.
 */
OtherNormalClass*
PluginidSBasePlugin::getOtherNormalClass()
{
  return mOtherNormalClass;
}


/*
 * Predicate returning @c true if this PluginidSBasePlugin's "otherNormalClass"
 * element is set.
 */
bool
PluginidSBasePlugin::isSetOtherNormalClass() const
{
  return (mOtherNormalClass != NULL);
}


/*
 * Sets the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::setOtherNormalClass(const OtherNormalClass*
  otherNormalClass)
{
  if (otherNormalClass == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (otherNormalClass->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != otherNormalClass->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != otherNormalClass->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != otherNormalClass->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mOtherNormalClass;
    mOtherNormalClass =
      static_cast<OtherNormalClass*>(otherNormalClass->clone());
    connectToChild();
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new OtherNormalClass object, adds it to this PluginidSBasePlugin
 * object and returns the OtherNormalClass object created.
 */
OtherNormalClass*
PluginidSBasePlugin::createOtherNormalClass()
{
  if (mOtherNormalClass != NULL)
  {
    delete mOtherNormalClass;
  }

  PLUGINID_CREATE_NS(pluginidns, getSBMLNamespaces());
  mOtherNormalClass = new OtherNormalClass(pluginidns);

  mOtherNormalClass->setSBMLDocument(this->getSBMLDocument());

  delete pluginidns;

  connectToChild();

  return mOtherNormalClass;
}


/*
 * Unsets the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::unsetOtherNormalClass()
{
  delete mOtherNormalClass;
  mOtherNormalClass = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * PluginidSBasePlugin object have been set.
 */
bool
PluginidSBasePlugin::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
PluginidSBasePlugin::writeElements(XMLOutputStream& stream) const
{
  if (isSetOtherNormalClass() == true)
  {
    mOtherNormalClass->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
PluginidSBasePlugin::accept(SBMLVisitor& v) const
{
  const SBase* sb = static_cast<const SBase*>(this->getParentSBMLObject());
  v.visit(*sb);
  v.leave(*sb);

  if (mOtherNormalClass != NULL)
  {
    mOtherNormalClass->accept(v);
  }

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
PluginidSBasePlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);

  if (mOtherNormalClass != NULL)
  {
    mOtherNormalClass->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
PluginidSBasePlugin::connectToChild()
{
  connectToParent(getParentSBMLObject());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to parent element
 */
void
PluginidSBasePlugin::connectToParent(SBase* base)
{
  SBasePlugin::connectToParent(base);

  if (mOtherNormalClass != NULL)
  {
    mOtherNormalClass->connectToParent(base);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
PluginidSBasePlugin::enablePackageInternal(const std::string& pkgURI,
                                           const std::string& pkgPrefix,
                                           bool flag)
{
  if (isSetOtherNormalClass())
  {
    mOtherNormalClass->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
PluginidSBasePlugin::updateSBMLNamespace(const std::string& package,
                                         unsigned int level,
                                         unsigned int version)
{
  SBasePlugin::updateSBMLNamespace(package, level, version);

  if (mOtherNormalClass != NULL)
  {
    mOtherNormalClass->updateSBMLNamespace(package, level, version);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::getAttribute(const std::string& attributeName,
                                  bool& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::getAttribute(const std::string& attributeName,
                                  int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::getAttribute(const std::string& attributeName,
                                  double& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::getAttribute(const std::string& attributeName,
                                  unsigned int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::getAttribute(const std::string& attributeName,
                                  std::string& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }
  else if (attributeName == "plugAtt")
  {
    value = getPlugAtt();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this PluginidSBasePlugin's attribute
 * "attributeName" is set.
 */
bool
PluginidSBasePlugin::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBasePlugin::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "plugAtt")
  {
    value = isSetPlugAtt();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::setAttribute(const std::string& attributeName,
                                  bool value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::setAttribute(const std::string& attributeName,
                                  double value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::setAttribute(const std::string& attributeName,
                                  unsigned int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::setAttribute(const std::string& attributeName,
                                  const std::string& value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "plugAtt")
  {
    return_value = setPlugAtt(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::unsetAttribute(const std::string& attributeName)
{
  int value = SBasePlugin::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "plugAtt")
  {
    value = unsetPlugAtt();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this PluginidSBasePlugin.
 */
SBase*
PluginidSBasePlugin::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "otherNormalClass")
  {
    return createOtherNormalClass();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this PluginidSBasePlugin.
 */
int
PluginidSBasePlugin::addChildObject(const std::string& elementName,
                                    const SBase* element)
{
  if (elementName == "otherNormalClass" && element->getTypeCode() ==
    SBML_PLUGINID_OTHERNORMALCLASS)
  {
    return setOtherNormalClass((const OtherNormalClass*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * PluginidSBasePlugin.
 */
SBase*
PluginidSBasePlugin::removeChildObject(const std::string& elementName,
                                       const std::string& id)
{
  if (elementName == "otherNormalClass")
  {
    OtherNormalClass * obj = getOtherNormalClass();
    if (unsetOtherNormalClass() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this PluginidSBasePlugin.
 */
unsigned int
PluginidSBasePlugin::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "otherNormalClass")
  {
    if (isSetOtherNormalClass())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this PluginidSBasePlugin.
 */
SBase*
PluginidSBasePlugin::getObject(const std::string& elementName,
                               unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "otherNormalClass")
  {
    return getOtherNormalClass();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
PluginidSBasePlugin::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mOtherNormalClass != NULL)
  {
    if (mOtherNormalClass->getId() == id)
    {
      return mOtherNormalClass;
    }

    obj = mOtherNormalClass->getElementBySId(id);
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
PluginidSBasePlugin::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mOtherNormalClass != NULL)
  {
    if (mOtherNormalClass->getMetaId() == metaid)
    {
      return mOtherNormalClass;
    }

    obj = mOtherNormalClass->getElementByMetaId(metaid);
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
PluginidSBasePlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mOtherNormalClass, filter);


  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Append items from model (used in comp flattening)
 */
int
PluginidSBasePlugin::appendFrom(const Model* model)
{
  int ret = LIBSBML_OPERATION_SUCCESS;

  if (model == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  const PluginidSBasePlugin* plug = static_cast<const
    PluginidSBasePlugin*>(model->getPlugin(getPrefix()));

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
PluginidSBasePlugin::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();
  const XMLNamespaces& xmlns = stream.peek().getNamespaces();
  const std::string& prefix = stream.peek().getPrefix();

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ?
    xmlns.getPrefix(mURI) : mPrefix;

  PLUGINID_CREATE_NS(pluginidns, getSBMLNamespaces());

  if (prefix == targetPrefix)
  {
    if (name == "otherNormalClass")
    {
      if (isSetOtherNormalClass())
      {
        getErrorLog()->logPackageError("pluginid",
          PluginidSBaseAllowedElements, getPackageVersion(), getLevel(),
            getVersion());
      }

      delete mOtherNormalClass;
      mOtherNormalClass = new OtherNormalClass(pluginidns);
      obj = mOtherNormalClass;
    }
  }

  delete pluginidns;

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
PluginidSBasePlugin::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBasePlugin::addExpectedAttributes(attributes);

  unsigned int level = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && coreVersion == 1 && pkgVersion == 1)
  {
    attributes.add("id");
    attributes.add("plugAtt");
  }

  if (level == 3 && coreVersion == 2 && pkgVersion == 1)
  {
    attributes.add("plugAtt");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
PluginidSBasePlugin::readAttributes(const XMLAttributes& attributes,
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
        log->logPackageError("pluginid", PluginidSBaseAllowedAttributes,
          pkgVersion, level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("pluginid", PluginidSBaseAllowedAttributes,
          pkgVersion, level, version, details);
      }
      else if (log->getError(n)->getErrorId() == NotSchemaConformant)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(NotSchemaConformant);
        log->logPackageError("pluginid", PluginidSBaseAllowedAttributes,
          pkgVersion, level, version, details);
      }
    }
  }

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    readL3V1V1Attributes(attributes);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    readL3V2V1Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
PluginidSBasePlugin::readL3V1V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();

  // 
  // id SId (use = "required" )
  // 

  XMLTriple tripleID("id", mURI, getPrefix());
  assigned = attributes.readInto(tripleID, mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, pkgVersion, "<PluginidSBasePlugin>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("pluginid", PluginidIdSyntaxRule, pkgVersion, level,
        version, "The pluginid:id on the <" +
          getParentSBMLObject()->getElementName() + "> is '" + mId + "', which does "
            "not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Pluginid attribute 'id' is missing from the "
      "<PluginidSBasePlugin> element.";
    log->logPackageError("pluginid", PluginidSBaseAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // plugAtt string (use = "optional" )
  // 

  assigned = attributes.readInto("plugAtt", mPlugAtt);

  if (assigned == true)
  {
    if (mPlugAtt.empty() == true)
    {
      logEmptyString(mPlugAtt, level, version, pkgVersion,
        "<PluginidSBasePlugin>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
PluginidSBasePlugin::readL3V2V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, pkgVersion, "<PluginidSBasePlugin>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("pluginid", PluginidIdSyntaxRule, pkgVersion, level,
        version, "The pluginid:id on the <" +
          getParentSBMLObject()->getElementName() + "> is '" + mId + "', which does "
            "not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Pluginid attribute 'id' is missing from the "
      "<PluginidSBasePlugin> element.";
    log->logPackageError("pluginid", PluginidSBaseAllowedAttributes,
      pkgVersion, level, version, message);
  }

  // 
  // plugAtt string (use = "optional" )
  // 

  assigned = attributes.readInto("plugAtt", mPlugAtt);

  if (assigned == true)
  {
    if (mPlugAtt.empty() == true)
    {
      logEmptyString(mPlugAtt, level, version, pkgVersion,
        "<PluginidSBasePlugin>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
PluginidSBasePlugin::writeAttributes(XMLOutputStream& stream) const
{
  SBasePlugin::writeAttributes(stream);

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    writeL3V1V1Attributes(stream);
  }

  if (level == 3 && version == 2 && pkgVersion == 1)
  {
    writeL3V2V1Attributes(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
PluginidSBasePlugin::writeL3V1V1Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetPlugAtt() == true)
  {
    stream.writeAttribute("plugAtt", getPrefix(), mPlugAtt);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
PluginidSBasePlugin::writeL3V2V1Attributes(XMLOutputStream& stream) const
{
  if (isSetPlugAtt() == true)
  {
    stream.writeAttribute("plugAtt", getPrefix(), mPlugAtt);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Returns the value of the "id" attribute of this PluginidSBasePlugin_t.
 */
LIBSBML_EXTERN
char *
PluginidSBasePlugin_getId(const PluginidSBasePlugin_t * psbp)
{
  if (psbp == NULL)
  {
    return NULL;
  }

  return psbp->getId().empty() ? NULL : safe_strdup(psbp->getId().c_str());
}


/*
 * Returns the value of the "plugAtt" attribute of this PluginidSBasePlugin_t.
 */
LIBSBML_EXTERN
char *
PluginidSBasePlugin_getPlugAtt(const PluginidSBasePlugin_t * psbp)
{
  if (psbp == NULL)
  {
    return NULL;
  }

  return psbp->getPlugAtt().empty() ? NULL :
    safe_strdup(psbp->getPlugAtt().c_str());
}


/*
 * Predicate returning @c 1 (true) if this PluginidSBasePlugin_t's "id"
 * attribute is set.
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_isSetId(const PluginidSBasePlugin_t * psbp)
{
  return (psbp != NULL) ? static_cast<int>(psbp->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this PluginidSBasePlugin_t's "plugAtt"
 * attribute is set.
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_isSetPlugAtt(const PluginidSBasePlugin_t * psbp)
{
  return (psbp != NULL) ? static_cast<int>(psbp->isSetPlugAtt()) : 0;
}


/*
 * Sets the value of the "id" attribute of this PluginidSBasePlugin_t.
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_setId(PluginidSBasePlugin_t * psbp, const char * id)
{
  return (psbp != NULL) ? psbp->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "plugAtt" attribute of this PluginidSBasePlugin_t.
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_setPlugAtt(PluginidSBasePlugin_t * psbp,
                               const char * plugAtt)
{
  return (psbp != NULL) ? psbp->setPlugAtt(plugAtt) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this PluginidSBasePlugin_t.
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_unsetId(PluginidSBasePlugin_t * psbp)
{
  return (psbp != NULL) ? psbp->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "plugAtt" attribute of this PluginidSBasePlugin_t.
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_unsetPlugAtt(PluginidSBasePlugin_t * psbp)
{
  return (psbp != NULL) ? psbp->unsetPlugAtt() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin_t.
 */
LIBSBML_EXTERN
const OtherNormalClass_t*
PluginidSBasePlugin_getOtherNormalClass(const PluginidSBasePlugin_t * psbp)
{
  if (psbp == NULL)
  {
    return NULL;
  }

  return (OtherNormalClass_t*)(psbp->getOtherNormalClass());
}


/*
 * Predicate returning @c 1 (true) if this PluginidSBasePlugin_t's
 * "otherNormalClass" element is set.
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_isSetOtherNormalClass(const PluginidSBasePlugin_t * psbp)
{
  return (psbp != NULL) ? static_cast<int>(psbp->isSetOtherNormalClass()) : 0;
}


/*
 * Sets the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin_t.
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_setOtherNormalClass(PluginidSBasePlugin_t * psbp,
                                        const OtherNormalClass_t*
                                          otherNormalClass)
{
  return (psbp != NULL) ? psbp->setOtherNormalClass(otherNormalClass) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new OtherNormalClass_t object, adds it to this
 * PluginidSBasePlugin_t object and returns the OtherNormalClass_t object
 * created.
 */
LIBSBML_EXTERN
OtherNormalClass_t*
PluginidSBasePlugin_createOtherNormalClass(PluginidSBasePlugin_t* psbp)
{
  if (psbp == NULL)
  {
    return NULL;
  }

  return (OtherNormalClass_t*)(psbp->createOtherNormalClass());
}


/*
 * Unsets the value of the "otherNormalClass" element of this
 * PluginidSBasePlugin_t.
 */
LIBSBML_EXTERN
int
PluginidSBasePlugin_unsetOtherNormalClass(PluginidSBasePlugin_t * psbp)
{
  return (psbp != NULL) ? psbp->unsetOtherNormalClass() :
    LIBSBML_INVALID_OBJECT;
}




LIBSBML_CPP_NAMESPACE_END


