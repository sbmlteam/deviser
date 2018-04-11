/**
 * @file TwoatonceSBasePlugin.cpp
 * @brief Implementation of the TwoatonceSBasePlugin class.
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
#include <sbml/packages/twoatonce/extension/TwoatonceSBasePlugin.h>
#include <sbml/packages/twoatonce/validator/TwoatonceSBMLError.h>
#include <sbml/Model.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new TwoatonceSBasePlugin using the given URI, prefix and package
 * namespace.
 */
TwoatonceSBasePlugin::TwoatonceSBasePlugin(const std::string& uri,
                                           const std::string& prefix,
                                           TwoatoncePkgNamespaces* twoatoncens)
  : SBasePlugin(uri, prefix, twoatoncens)
  , mNormalClass (NULL)
  , mClassWithRequiredID (NULL)
{
  connectToChild();
}


/*
 * Copy constructor for TwoatonceSBasePlugin.
 */
TwoatonceSBasePlugin::TwoatonceSBasePlugin(const TwoatonceSBasePlugin& orig)
  : SBasePlugin( orig )
  , mNormalClass ( NULL )
  , mClassWithRequiredID ( NULL )
{
  if (orig.mNormalClass != NULL)
  {
    mNormalClass = orig.mNormalClass->clone();
  }

  if (orig.mClassWithRequiredID != NULL)
  {
    mClassWithRequiredID = orig.mClassWithRequiredID->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for TwoatonceSBasePlugin.
 */
TwoatonceSBasePlugin&
TwoatonceSBasePlugin::operator=(const TwoatonceSBasePlugin& rhs)
{
  if (&rhs != this)
  {
    SBasePlugin::operator=(rhs);
    delete mNormalClass;
    if (rhs.mNormalClass != NULL)
    {
      mNormalClass = rhs.mNormalClass->clone();
    }
    else
    {
      mNormalClass = NULL;
    }

    delete mClassWithRequiredID;
    if (rhs.mClassWithRequiredID != NULL)
    {
      mClassWithRequiredID = rhs.mClassWithRequiredID->clone();
    }
    else
    {
      mClassWithRequiredID = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this TwoatonceSBasePlugin object.
 */
TwoatonceSBasePlugin*
TwoatonceSBasePlugin::clone() const
{
  return new TwoatonceSBasePlugin(*this);
}


/*
 * Destructor for TwoatonceSBasePlugin.
 */
TwoatonceSBasePlugin::~TwoatonceSBasePlugin()
{
  delete mNormalClass;
  mNormalClass = NULL;
  delete mClassWithRequiredID;
  mClassWithRequiredID = NULL;
}


/*
 * Returns the value of the "normalClass" element of this TwoatonceSBasePlugin.
 */
const NormalClass*
TwoatonceSBasePlugin::getNormalClass() const
{
  return mNormalClass;
}


/*
 * Returns the value of the "normalClass" element of this TwoatonceSBasePlugin.
 */
NormalClass*
TwoatonceSBasePlugin::getNormalClass()
{
  return mNormalClass;
}


/*
 * Returns the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin.
 */
const ClassWithRequiredID*
TwoatonceSBasePlugin::getClassWithRequiredID() const
{
  return mClassWithRequiredID;
}


/*
 * Returns the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin.
 */
ClassWithRequiredID*
TwoatonceSBasePlugin::getClassWithRequiredID()
{
  return mClassWithRequiredID;
}


/*
 * Predicate returning @c true if this TwoatonceSBasePlugin's "normalClass"
 * element is set.
 */
bool
TwoatonceSBasePlugin::isSetNormalClass() const
{
  return (mNormalClass != NULL);
}


/*
 * Predicate returning @c true if this TwoatonceSBasePlugin's
 * "classWithRequiredID" element is set.
 */
bool
TwoatonceSBasePlugin::isSetClassWithRequiredID() const
{
  return (mClassWithRequiredID != NULL);
}


/*
 * Sets the value of the "normalClass" element of this TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::setNormalClass(const NormalClass* normalClass)
{
  if (normalClass == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (normalClass->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != normalClass->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != normalClass->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != normalClass->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mNormalClass;
    mNormalClass = static_cast<NormalClass*>(normalClass->clone());
    connectToChild();
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::setClassWithRequiredID(const ClassWithRequiredID*
  classWithRequiredID)
{
  if (classWithRequiredID == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (classWithRequiredID->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != classWithRequiredID->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != classWithRequiredID->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != classWithRequiredID->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    delete mClassWithRequiredID;
    mClassWithRequiredID =
      static_cast<ClassWithRequiredID*>(classWithRequiredID->clone());
    connectToChild();
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new NormalClass object, adds it to this TwoatonceSBasePlugin
 * object and returns the NormalClass object created.
 */
NormalClass*
TwoatonceSBasePlugin::createNormalClass()
{
  if (mNormalClass != NULL)
  {
    delete mNormalClass;
  }

  TWOATONCE_CREATE_NS(twoatoncens, getSBMLNamespaces());
  mNormalClass = new NormalClass(twoatoncens);

  mNormalClass->setSBMLDocument(this->getSBMLDocument());

  delete twoatoncens;

  connectToChild();

  return mNormalClass;
}


/*
 * Creates a new ClassWithRequiredID object, adds it to this
 * TwoatonceSBasePlugin object and returns the ClassWithRequiredID object
 * created.
 */
ClassWithRequiredID*
TwoatonceSBasePlugin::createClassWithRequiredID()
{
  if (mClassWithRequiredID != NULL)
  {
    delete mClassWithRequiredID;
  }

  TWOATONCE_CREATE_NS(twoatoncens, getSBMLNamespaces());
  mClassWithRequiredID = new ClassWithRequiredID(twoatoncens);

  mClassWithRequiredID->setSBMLDocument(this->getSBMLDocument());

  delete twoatoncens;

  connectToChild();

  return mClassWithRequiredID;
}


/*
 * Unsets the value of the "normalClass" element of this TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::unsetNormalClass()
{
  delete mNormalClass;
  mNormalClass = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::unsetClassWithRequiredID()
{
  delete mClassWithRequiredID;
  mClassWithRequiredID = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
TwoatonceSBasePlugin::writeElements(XMLOutputStream& stream) const
{
  if (isSetNormalClass() == true)
  {
    mNormalClass->write(stream);
  }

  if (isSetClassWithRequiredID() == true)
  {
    mClassWithRequiredID->write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
TwoatonceSBasePlugin::accept(SBMLVisitor& v) const
{
  const SBase* sb = static_cast<const SBase*>(this->getParentSBMLObject());
  v.visit(*sb);
  v.leave(*sb);

  if (mNormalClass != NULL)
  {
    mNormalClass->accept(v);
  }

  if (mClassWithRequiredID != NULL)
  {
    mClassWithRequiredID->accept(v);
  }

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
TwoatonceSBasePlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);

  if (mNormalClass != NULL)
  {
    mNormalClass->setSBMLDocument(d);
  }

  if (mClassWithRequiredID != NULL)
  {
    mClassWithRequiredID->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
TwoatonceSBasePlugin::connectToChild()
{
  connectToParent(getParentSBMLObject());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to parent element
 */
void
TwoatonceSBasePlugin::connectToParent(SBase* base)
{
  SBasePlugin::connectToParent(base);

  if (mNormalClass != NULL)
  {
    mNormalClass->connectToParent(base);
  }

  if (mClassWithRequiredID != NULL)
  {
    mClassWithRequiredID->connectToParent(base);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
TwoatonceSBasePlugin::enablePackageInternal(const std::string& pkgURI,
                                            const std::string& pkgPrefix,
                                            bool flag)
{
  if (isSetNormalClass())
  {
    mNormalClass->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }

  if (isSetClassWithRequiredID())
  {
    mClassWithRequiredID->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
TwoatonceSBasePlugin::updateSBMLNamespace(const std::string& package,
                                          unsigned int level,
                                          unsigned int version)
{
  if (mNormalClass != NULL)
  {
    mNormalClass->updateSBMLNamespace(package, level, version);
  }

  if (mClassWithRequiredID != NULL)
  {
    mClassWithRequiredID->updateSBMLNamespace(package, level, version);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::getAttribute(const std::string& attributeName,
                                   bool& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::getAttribute(const std::string& attributeName,
                                   int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::getAttribute(const std::string& attributeName,
                                   double& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::getAttribute(const std::string& attributeName,
                                   unsigned int& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::getAttribute(const std::string& attributeName,
                                   std::string& value) const
{
  int return_value = SBasePlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this TwoatonceSBasePlugin's attribute
 * "attributeName" is set.
 */
bool
TwoatonceSBasePlugin::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBasePlugin::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::setAttribute(const std::string& attributeName,
                                   bool value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::setAttribute(const std::string& attributeName,
                                   int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::setAttribute(const std::string& attributeName,
                                   double value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::setAttribute(const std::string& attributeName,
                                   unsigned int value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::setAttribute(const std::string& attributeName,
                                   const std::string& value)
{
  int return_value = SBasePlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::unsetAttribute(const std::string& attributeName)
{
  int value = SBasePlugin::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this
 * TwoatonceSBasePlugin.
 */
SBase*
TwoatonceSBasePlugin::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "normalClass")
  {
    return createNormalClass();
  }
  else if (elementName == "classWithRequiredID")
  {
    return createClassWithRequiredID();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this TwoatonceSBasePlugin.
 */
int
TwoatonceSBasePlugin::addChildObject(const std::string& elementName,
                                     const SBase* element)
{
  if (elementName == "normalClass" && element->getTypeCode() ==
    SBML_TWOATONCE_NORMALCLASS)
  {
    return setNormalClass((const NormalClass*)(element));
  }
  else if (elementName == "classWithRequiredID" && element->getTypeCode() ==
    SBML_TWOATONCE_CLASSWITHREQUIREDID)
  {
    return setClassWithRequiredID((const ClassWithRequiredID*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * TwoatonceSBasePlugin.
 */
SBase*
TwoatonceSBasePlugin::removeChildObject(const std::string& elementName,
                                        const std::string& id)
{
  if (elementName == "normalClass")
  {
    NormalClass * obj = getNormalClass();
    if (unsetNormalClass() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "classWithRequiredID")
  {
    ClassWithRequiredID * obj = getClassWithRequiredID();
    if (unsetClassWithRequiredID() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this TwoatonceSBasePlugin.
 */
unsigned int
TwoatonceSBasePlugin::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "normalClass")
  {
    if (isSetNormalClass())
    {
      return 1;
    }
  }
  else if (elementName == "classWithRequiredID")
  {
    if (isSetClassWithRequiredID())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this TwoatonceSBasePlugin.
 */
SBase*
TwoatonceSBasePlugin::getObject(const std::string& elementName,
                                unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "normalClass")
  {
    return getNormalClass();
  }
  else if (elementName == "classWithRequiredID")
  {
    return getClassWithRequiredID();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
TwoatonceSBasePlugin::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mNormalClass != NULL)
  {
    if (mNormalClass->getId() == id)
    {
      return mNormalClass;
    }

    obj = mNormalClass->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mClassWithRequiredID != NULL)
  {
    if (mClassWithRequiredID->getId() == id)
    {
      return mClassWithRequiredID;
    }

    obj = mClassWithRequiredID->getElementBySId(id);
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
TwoatonceSBasePlugin::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mNormalClass != NULL)
  {
    if (mNormalClass->getMetaId() == metaid)
    {
      return mNormalClass;
    }

    obj = mNormalClass->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mClassWithRequiredID != NULL)
  {
    if (mClassWithRequiredID->getMetaId() == metaid)
    {
      return mClassWithRequiredID;
    }

    obj = mClassWithRequiredID->getElementByMetaId(metaid);
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
TwoatonceSBasePlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mNormalClass, filter);
  ADD_FILTERED_POINTER(ret, sublist, mClassWithRequiredID, filter);


  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Append items from model (used in comp flattening)
 */
int
TwoatonceSBasePlugin::appendFrom(const Model* model)
{
  int ret = LIBSBML_OPERATION_SUCCESS;

  if (model == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  const TwoatonceSBasePlugin* plug = static_cast<const
    TwoatonceSBasePlugin*>(model->getPlugin(getPrefix()));

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
TwoatonceSBasePlugin::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();
  const XMLNamespaces& xmlns = stream.peek().getNamespaces();
  const std::string& prefix = stream.peek().getPrefix();

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ?
    xmlns.getPrefix(mURI) : mPrefix;

  TWOATONCE_CREATE_NS(twoatoncens, getSBMLNamespaces());

  if (prefix == targetPrefix)
  {
    if (name == "normalClass")
    {
      if (isSetNormalClass())
      {
        getErrorLog()->logPackageError("twoatonce",
          TwoatonceSBaseAllowedElements, getPackageVersion(), getLevel(),
            getVersion());
      }

      delete mNormalClass;
      mNormalClass = new NormalClass(twoatoncens);
      obj = mNormalClass;
    }
    else if (name == "classWithRequiredID")
    {
      if (isSetClassWithRequiredID())
      {
        getErrorLog()->logPackageError("twoatonce",
          TwoatonceSBaseAllowedElements, getPackageVersion(), getLevel(),
            getVersion());
      }

      delete mClassWithRequiredID;
      mClassWithRequiredID = new ClassWithRequiredID(twoatoncens);
      obj = mClassWithRequiredID;
    }
  }

  delete twoatoncens;

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Returns the value of the "normalClass" element of this
 * TwoatonceSBasePlugin_t.
 */
LIBSBML_EXTERN
const NormalClass_t*
TwoatonceSBasePlugin_getNormalClass(const TwoatonceSBasePlugin_t * tsbp)
{
  if (tsbp == NULL)
  {
    return NULL;
  }

  return (NormalClass_t*)(tsbp->getNormalClass());
}


/*
 * Returns the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin_t.
 */
LIBSBML_EXTERN
const ClassWithRequiredID_t*
TwoatonceSBasePlugin_getClassWithRequiredID(const TwoatonceSBasePlugin_t *
  tsbp)
{
  if (tsbp == NULL)
  {
    return NULL;
  }

  return (ClassWithRequiredID_t*)(tsbp->getClassWithRequiredID());
}


/*
 * Predicate returning @c 1 (true) if this TwoatonceSBasePlugin_t's
 * "normalClass" element is set.
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_isSetNormalClass(const TwoatonceSBasePlugin_t * tsbp)
{
  return (tsbp != NULL) ? static_cast<int>(tsbp->isSetNormalClass()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this TwoatonceSBasePlugin_t's
 * "classWithRequiredID" element is set.
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_isSetClassWithRequiredID(const TwoatonceSBasePlugin_t *
  tsbp)
{
  return (tsbp != NULL) ? static_cast<int>(tsbp->isSetClassWithRequiredID()) :
    0;
}


/*
 * Sets the value of the "normalClass" element of this TwoatonceSBasePlugin_t.
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_setNormalClass(TwoatonceSBasePlugin_t * tsbp,
                                    const NormalClass_t* normalClass)
{
  return (tsbp != NULL) ? tsbp->setNormalClass(normalClass) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin_t.
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_setClassWithRequiredID(TwoatonceSBasePlugin_t * tsbp,
                                            const ClassWithRequiredID_t*
                                              classWithRequiredID)
{
  return (tsbp != NULL) ? tsbp->setClassWithRequiredID(classWithRequiredID) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new NormalClass_t object, adds it to this TwoatonceSBasePlugin_t
 * object and returns the NormalClass_t object created.
 */
LIBSBML_EXTERN
NormalClass_t*
TwoatonceSBasePlugin_createNormalClass(TwoatonceSBasePlugin_t* tsbp)
{
  if (tsbp == NULL)
  {
    return NULL;
  }

  return (NormalClass_t*)(tsbp->createNormalClass());
}


/*
 * Creates a new ClassWithRequiredID_t object, adds it to this
 * TwoatonceSBasePlugin_t object and returns the ClassWithRequiredID_t object
 * created.
 */
LIBSBML_EXTERN
ClassWithRequiredID_t*
TwoatonceSBasePlugin_createClassWithRequiredID(TwoatonceSBasePlugin_t* tsbp)
{
  if (tsbp == NULL)
  {
    return NULL;
  }

  return (ClassWithRequiredID_t*)(tsbp->createClassWithRequiredID());
}


/*
 * Unsets the value of the "normalClass" element of this
 * TwoatonceSBasePlugin_t.
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_unsetNormalClass(TwoatonceSBasePlugin_t * tsbp)
{
  return (tsbp != NULL) ? tsbp->unsetNormalClass() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "classWithRequiredID" element of this
 * TwoatonceSBasePlugin_t.
 */
LIBSBML_EXTERN
int
TwoatonceSBasePlugin_unsetClassWithRequiredID(TwoatonceSBasePlugin_t * tsbp)
{
  return (tsbp != NULL) ? tsbp->unsetClassWithRequiredID() :
    LIBSBML_INVALID_OBJECT;
}




LIBSBML_CPP_NAMESPACE_END


