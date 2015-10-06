/**
 * @file: VersModelPlugin.cpp
 * @brief: Implementation of VersModelPlugin.
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
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
#include <sbml/packages/vers/extension/VersModelPlugin.h>
#include <sbml/packages/vers/validator/VersSBMLError.h>
#include <sbml/Model.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new VersModelPlugin using the given uri, prefix and package
 * namespace.
 */
VersModelPlugin::VersModelPlugin(const std::string& uri,
                                 const std::string& prefix,
                                 VersPkgNamespaces* versns)
  : SBasePlugin(uri, prefix, versns)
  , mVersion (SBML_INT_MAX)
  , mIsSetVersion (false)
  , mVersion2 (SBML_INT_MAX)
  , mIsSetVersion2 (false)
  , mClassOne (NULL)
{
  connectToChild();
}


/*
 * Copy constructor for VersModelPlugin.
 */
VersModelPlugin::VersModelPlugin(const VersModelPlugin& orig)
  : SBasePlugin( orig )
  , mVersion ( orig.mVersion )
  , mIsSetVersion ( orig.mIsSetVersion )
  , mVersion2 ( orig.mVersion2 )
  , mIsSetVersion2 ( orig.mIsSetVersion2 )
  , mClassOne ( NULL )
{
  if (orig.mClassOne != NULL)
  {
    mClassOne = orig.mClassOne->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for VersModelPlugin.
 */
VersModelPlugin&
VersModelPlugin::operator=(const VersModelPlugin& rhs)
{
  if (&rhs != this)
  {
    SBasePlugin::operator=(rhs);
    mVersion = rhs.mVersion;
    mIsSetVersion = rhs.mIsSetVersion;
    mVersion2 = rhs.mVersion2;
    mIsSetVersion2 = rhs.mIsSetVersion2;
    delete mClassOne;
    if (rhs.mClassOne != NULL)
    {
      mClassOne = rhs.mClassOne->clone();
    }
    else
    {
      mClassOne = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this VersModelPlugin object.
 */
VersModelPlugin*
VersModelPlugin::clone() const
{
  return new VersModelPlugin(*this);
}


/*
 * Destructor for VersModelPlugin.
 */
VersModelPlugin::~VersModelPlugin()
{
  delete mClassOne;
  mClassOne = NULL;
}


/*
 * Returns the value of the "version" attribute of this VersModelPlugin.
 */
unsigned int
VersModelPlugin::getVersion() const
{
  return mVersion;
}


/*
 * Returns the value of the "version2" attribute of this VersModelPlugin.
 */
unsigned int
VersModelPlugin::getVersion2() const
{
  return mVersion2;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * VersModelPlugin's "version" attribute has been set.
 */
bool
VersModelPlugin::isSetVersion() const
{
  return mIsSetVersion;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * VersModelPlugin's "version2" attribute has been set.
 */
bool
VersModelPlugin::isSetVersion2() const
{
  return mIsSetVersion2;
}


/*
 * Sets the value of the "version" attribute of this VersModelPlugin.
 */
int
VersModelPlugin::setVersion(unsigned int version)
{
  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    mVersion = version;
    mIsSetVersion = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    mVersion = version;
    mIsSetVersion = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
}


/*
 * Sets the value of the "version2" attribute of this VersModelPlugin.
 */
int
VersModelPlugin::setVersion2(unsigned int version2)
{
  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    mVersion2 = version2;
    mIsSetVersion2 = false;
    return LIBSBML_UNEXPECTED_ATTRIBUTE;
  }
  else
  {
    mVersion2 = version2;
    mIsSetVersion2 = true;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "version" attribute of this VersModelPlugin.
 */
int
VersModelPlugin::unsetVersion()
{
  mVersion = SBML_INT_MAX;
  mIsSetVersion = false;

  if (isSetVersion() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "version2" attribute of this VersModelPlugin.
 */
int
VersModelPlugin::unsetVersion2()
{
  mVersion2 = SBML_INT_MAX;
  mIsSetVersion2 = false;

  if (isSetVersion2() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "classOne" element of this VersModelPlugin.
 */
const ClassOne*
VersModelPlugin::getClassOne() const
{
  return mClassOne;
}


/*
 * Returns the value of the "classOne" element of this VersModelPlugin.
 */
ClassOne*
VersModelPlugin::getClassOne()
{
  return mClassOne;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * VersModelPlugin's "classOne" element has been set.
 */
bool
VersModelPlugin::isSetClassOne() const
{
  return (mClassOne != NULL);
}


/*
 * Sets the value of the "classOne" element of this VersModelPlugin.
 */
int
VersModelPlugin::setClassOne(const ClassOne* classOne)
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
 * Creates a new ClassOne object, adds it to this VersModelPlugin object and
 * returns the ClassOne object created.
 */
ClassOne*
VersModelPlugin::createClassOne()
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
 * Unsets the value of the "classOne" element of this VersModelPlugin.
 */
int
VersModelPlugin::unsetClassOne()
{
  delete mClassOne;
  mClassOne = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * VersModelPlugin object have been set.
 */
bool
VersModelPlugin::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * VersModelPlugin object have been set.
 */
bool
VersModelPlugin::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
VersModelPlugin::writeElements(XMLOutputStream& stream) const
{
  if (isSetClassOne() == true)
  {
    mClassOne->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
VersModelPlugin::accept(SBMLVisitor& v) const
{
  const Model* m = static_cast<const Model*>(this->getParentSBMLObject());
  v.visit(*m);
  v.leave(*m);

  if (mClassOne != NULL)
  {
    mClassOne->accept(v);
  }

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
VersModelPlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);

  if (mClassOne != NULL)
  {
    mClassOne->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
VersModelPlugin::connectToChild()
{
  connectToParent(getParentSBMLObject());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to parent element
 */
void
VersModelPlugin::connectToParent(SBase* base)
{
  SBasePlugin::connectToParent(base);

  if (mClassOne != NULL)
  {
    mClassOne->connectToParent(base);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
VersModelPlugin::enablePackageInternal(const std::string& pkgURI,
                                       const std::string& pkgPrefix,
                                       bool flag)
{
  if (isSetClassOne())
  {
    mClassOne->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
VersModelPlugin::getElementBySId(const std::string& id)
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

  return obj;
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
VersModelPlugin::getElementByMetaId(const std::string& metaid)
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

  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
VersModelPlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mClassOne, filter);


  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Append items from model (used in comp flattening)
 */
int
VersModelPlugin::appendFrom(const Model* model)
{
  int ret = LIBSBML_OPERATION_SUCCESS;

  if (model == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  const VersModelPlugin* plug = static_cast<const
    VersModelPlugin*>(model->getPlugin(getPrefix()));

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
VersModelPlugin::createObject(XMLInputStream& stream)
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
      if (isSetClassOne())
      {
        getErrorLog()->logPackageError("vers", VersModelAllowedElements,
          getPackageVersion(), getLevel(), getVersion());
      }

      mClassOne = new ClassOne(versns);
      obj = mClassOne;
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
VersModelPlugin::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBasePlugin::addExpectedAttributes(attributes);

  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    attributes.add("version");
  }
  else
  {
    attributes.add("version2");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
VersModelPlugin::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("vers", VersModelAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("vers", VersModelAllowedAttributes, pkgVersion,
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
VersModelPlugin::readV1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // version uint (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetVersion = attributes.readInto("version", mVersion);

  if ( mIsSetVersion == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Vers attribute 'version' from the "
        "<VersModelPlugin> element must be an integer.";
      log->logPackageError("vers", VersVersModelPluginVersionMustBeUnInteger,
        pkgVersion, level, version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
VersModelPlugin::readV2Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;

  // 
  // version2 uint (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetVersion2 = attributes.readInto("version2", mVersion2);

  if ( mIsSetVersion2 == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Vers attribute 'version2' from the "
        "<VersModelPlugin> element must be an integer.";
      log->logPackageError("vers", VersVersModelPluginVersion2MustBeUnInteger,
        pkgVersion, level, version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
VersModelPlugin::writeAttributes(XMLOutputStream& stream) const
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
VersModelPlugin::writeV1Attributes(XMLOutputStream& stream) const
{
  if (isSetVersion() == true)
  {
    stream.writeAttribute("version", getPrefix(), mVersion);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
VersModelPlugin::writeV2Attributes(XMLOutputStream& stream) const
{
  if (isSetVersion2() == true)
  {
    stream.writeAttribute("version2", getPrefix(), mVersion2);
  }
}

/** @endcond */




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END


