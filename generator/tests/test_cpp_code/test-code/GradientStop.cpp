/**
 * @file GradientStop.cpp
 * @brief Implementation of the GradientStop class.
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
#include <sbml/packages/render/sbml/GradientStop.h>
#include <sbml/packages/render/sbml/ListOfGradientStops.h>
#include <sbml/packages/render/validator/RenderSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new GradientStop using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 */
GradientStop::GradientStop(unsigned int level,
                           unsigned int version,
                           unsigned int pkgVersion)
  : SBase(level, version)
  , mOffset (NULL)
  , mStopColor ("")
  , mElementName("stop")
{
  setSBMLNamespacesAndOwn(new RenderPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new GradientStop using the given RenderPkgNamespaces object.
 */
GradientStop::GradientStop(RenderPkgNamespaces *renderns)
  : SBase(renderns)
  , mOffset (NULL)
  , mStopColor ("")
  , mElementName("stop")
{
  setElementNamespace(renderns->getURI());
  connectToChild();
  loadPlugins(renderns);
}


/*
 * Copy constructor for GradientStop.
 */
GradientStop::GradientStop(const GradientStop& orig)
  : SBase( orig )
  , mOffset ( NULL )
  , mStopColor ( orig.mStopColor )
  , mElementName ( orig.mElementName )
{
  if (orig.mOffset != NULL)
  {
    mOffset = orig.mOffset->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for GradientStop.
 */
GradientStop&
GradientStop::operator=(const GradientStop& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mStopColor = rhs.mStopColor;
    mElementName = rhs.mElementName;
    delete mOffset;
    if (rhs.mOffset != NULL)
    {
      mOffset = rhs.mOffset->clone();
    }
    else
    {
      mOffset = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this GradientStop object.
 */
GradientStop*
GradientStop::clone() const
{
  return new GradientStop(*this);
}


/*
 * Destructor for GradientStop.
 */
GradientStop::~GradientStop()
{
  delete mOffset;
  mOffset = NULL;
}


/*
 * Returns the value of the "stop-color" attribute of this GradientStop.
 */
const std::string&
GradientStop::getStopColor() const
{
  return mStopColor;
}


/*
 * Predicate returning @c true if this GradientStop's "stop-color" attribute is
 * set.
 */
bool
GradientStop::isSetStopColor() const
{
  return (mStopColor.empty() == false);
}


/*
 * Sets the value of the "stop-color" attribute of this GradientStop.
 */
int
GradientStop::setStopColor(const std::string& stopColor)
{
  mStopColor = stopColor;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "stop-color" attribute of this GradientStop.
 */
int
GradientStop::unsetStopColor()
{
  mStopColor.erase();

  if (mStopColor.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "offset" element of this GradientStop.
 */
const RelAbsVector*
GradientStop::getOffset() const
{
  return mOffset;
}


/*
 * Returns the value of the "offset" element of this GradientStop.
 */
RelAbsVector*
GradientStop::getOffset()
{
  return mOffset;
}


/*
 * Predicate returning @c true if this GradientStop's "offset" element is set.
 */
bool
GradientStop::isSetOffset() const
{
  return (mOffset != NULL);
}


/*
 * Sets the value of the "offset" element of this GradientStop.
 */
int
GradientStop::setOffset(const RelAbsVector* offset)
{
  if (mOffset == offset)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (offset == NULL)
  {
    delete mOffset;
    mOffset = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mOffset;
    mOffset = (offset != NULL) ? offset->clone() : NULL;
    if (mOffset != NULL)
    {
      mOffset->setElementName("offset");
      mOffset->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new RelAbsVector object, adds it to this GradientStop object and
 * returns the RelAbsVector object created.
 */
RelAbsVector*
GradientStop::createOffset()
{
  if (mOffset != NULL)
  {
    delete mOffset;
  }

  RENDER_CREATE_NS(renderns, getSBMLNamespaces());
  mOffset = new RelAbsVector(renderns);

  mOffset->setElementName("offset");

  delete renderns;

  connectToChild();

  return mOffset;
}


/*
 * Unsets the value of the "offset" element of this GradientStop.
 */
int
GradientStop::unsetOffset()
{
  delete mOffset;
  mOffset = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this GradientStop object.
 */
const std::string&
GradientStop::getElementName() const
{
  return mElementName;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the XML name of this GradientStop object.
 */
void
GradientStop::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBML type code for this GradientStop object.
 */
int
GradientStop::getTypeCode() const
{
  return SBML_RENDER_GRADIENT_STOP;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * GradientStop object have been set.
 */
bool
GradientStop::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetStopColor() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * GradientStop object have been set.
 */
bool
GradientStop::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetOffset() == false)
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
GradientStop::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetOffset() == true)
  {
    mOffset->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
GradientStop::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mOffset != NULL)
  {
    mOffset->accept(v);
  }

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
GradientStop::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  if (mOffset != NULL)
  {
    mOffset->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
GradientStop::connectToChild()
{
  SBase::connectToChild();

  if (mOffset != NULL)
  {
    mOffset->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
GradientStop::enablePackageInternal(const std::string& pkgURI,
                                    const std::string& pkgPrefix,
                                    bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetOffset())
  {
    mOffset->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "stop-color")
  {
    value = getStopColor();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this GradientStop's attribute "attributeName"
 * is set.
 */
bool
GradientStop::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "stop-color")
  {
    value = isSetStopColor();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "stop-color")
  {
    return_value = setStopColor(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this GradientStop.
 */
int
GradientStop::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "stop-color")
  {
    value = unsetStopColor();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this GradientStop.
 */
SBase*
GradientStop::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "offset")
  {
    return createOffset();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this GradientStop.
 */
int
GradientStop::addChildObject(const std::string& elementName,
                             const SBase* element)
{
  if (elementName == "offset" && element->getTypeCode() ==
    SBML_RENDER_RELABSVECTOR)
  {
    return setOffset((const RelAbsVector*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * GradientStop.
 */
SBase*
GradientStop::removeChildObject(const std::string& elementName,
                                const std::string& id)
{
  if (elementName == "offset")
  {
    RelAbsVector * obj = getOffset();
    if (unsetOffset() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this GradientStop.
 */
unsigned int
GradientStop::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "offset")
  {
    if (isSetOffset())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this GradientStop.
 */
SBase*
GradientStop::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "offset")
  {
    return getOffset();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
GradientStop::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mOffset != NULL)
  {
    if (mOffset->getId() == id)
    {
      return mOffset;
    }

    obj = mOffset->getElementBySId(id);
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
GradientStop::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mOffset != NULL)
  {
    if (mOffset->getMetaId() == metaid)
    {
      return mOffset;
    }

    obj = mOffset->getElementByMetaId(metaid);
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
GradientStop::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mOffset, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
GradientStop::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  RENDER_CREATE_NS(renderns, getSBMLNamespaces());

  if (name == "offset")
  {
    if (isSetOffset())
    {
      getErrorLog()->logPackageError("render",
        RenderGradientStopAllowedAttributes, getPackageVersion(), getLevel(),
          getVersion());
    }

    delete mOffset;
    mOffset = new RelAbsVector(renderns);
    mOffset->setElementName(name);
    obj = mOffset;
  }

  delete renderns;

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
GradientStop::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("stop-color");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
GradientStop::readAttributes(const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (static_cast<ListOfGradientStops*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("render",
          RenderGradientBaseLOGradientStopsAllowedAttributes, pkgVersion, level,
            version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("render",
          RenderGradientBaseLOGradientStopsAllowedCoreAttributes, pkgVersion,
            level, version, details);
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("render", RenderGradientStopAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("render", RenderGradientStopAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  // 
  // stop-color string (use = "required" )
  // 

  assigned = attributes.readInto("stop-color", mStopColor);

  if (assigned == true)
  {
    if (mStopColor.empty() == true)
    {
      logEmptyString(mStopColor, level, version, "<GradientStop>");
    }
  }
  else
  {
    std::string message = "Render attribute 'stop-color' is missing from the "
      "<GradientStop> element.";
    log->logPackageError("render", RenderGradientStopAllowedAttributes,
      pkgVersion, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
GradientStop::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetStopColor() == true)
  {
    stream.writeAttribute("stop-color", getPrefix(), mStopColor);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new GradientStop_t using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 */
LIBSBML_EXTERN
GradientStop_t *
GradientStop_create(unsigned int level,
                    unsigned int version,
                    unsigned int pkgVersion)
{
  return new GradientStop(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this GradientStop_t object.
 */
LIBSBML_EXTERN
GradientStop_t*
GradientStop_clone(const GradientStop_t* gs)
{
  if (gs != NULL)
  {
    return static_cast<GradientStop_t*>(gs->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this GradientStop_t object.
 */
LIBSBML_EXTERN
void
GradientStop_free(GradientStop_t* gs)
{
  if (gs != NULL)
  {
    delete gs;
  }
}


/*
 * Returns the value of the "stop-color" attribute of this GradientStop_t.
 */
LIBSBML_EXTERN
char *
GradientStop_getStopColor(const GradientStop_t * gs)
{
  if (gs == NULL)
  {
    return NULL;
  }

  return gs->getStopColor().empty() ? NULL :
    safe_strdup(gs->getStopColor().c_str());
}


/*
 * Predicate returning @c 1 (true) if this GradientStop_t's "stop-color"
 * attribute is set.
 */
LIBSBML_EXTERN
int
GradientStop_isSetStopColor(const GradientStop_t * gs)
{
  return (gs != NULL) ? static_cast<int>(gs->isSetStopColor()) : 0;
}


/*
 * Sets the value of the "stop-color" attribute of this GradientStop_t.
 */
LIBSBML_EXTERN
int
GradientStop_setStopColor(GradientStop_t * gs, const char * stopColor)
{
  return (gs != NULL) ? gs->setStopColor(stopColor) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "stop-color" attribute of this GradientStop_t.
 */
LIBSBML_EXTERN
int
GradientStop_unsetStopColor(GradientStop_t * gs)
{
  return (gs != NULL) ? gs->unsetStopColor() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "offset" element of this GradientStop_t.
 */
LIBSBML_EXTERN
const RelAbsVector_t*
GradientStop_getOffset(const GradientStop_t * gs)
{
  if (gs == NULL)
  {
    return NULL;
  }

  return (RelAbsVector_t*)(gs->getOffset());
}


/*
 * Predicate returning @c 1 (true) if this GradientStop_t's "offset" element is
 * set.
 */
LIBSBML_EXTERN
int
GradientStop_isSetOffset(const GradientStop_t * gs)
{
  return (gs != NULL) ? static_cast<int>(gs->isSetOffset()) : 0;
}


/*
 * Sets the value of the "offset" element of this GradientStop_t.
 */
LIBSBML_EXTERN
int
GradientStop_setOffset(GradientStop_t * gs, const RelAbsVector_t* offset)
{
  return (gs != NULL) ? gs->setOffset(offset) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new RelAbsVector_t object, adds it to this GradientStop_t object
 * and returns the RelAbsVector_t object created.
 */
LIBSBML_EXTERN
RelAbsVector_t*
GradientStop_createOffset(GradientStop_t* gs)
{
  if (gs == NULL)
  {
    return NULL;
  }

  return (RelAbsVector_t*)(gs->createOffset());
}


/*
 * Unsets the value of the "offset" element of this GradientStop_t.
 */
LIBSBML_EXTERN
int
GradientStop_unsetOffset(GradientStop_t * gs)
{
  return (gs != NULL) ? gs->unsetOffset() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * GradientStop_t object have been set.
 */
LIBSBML_EXTERN
int
GradientStop_hasRequiredAttributes(const GradientStop_t * gs)
{
  return (gs != NULL) ? static_cast<int>(gs->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * GradientStop_t object have been set.
 */
LIBSBML_EXTERN
int
GradientStop_hasRequiredElements(const GradientStop_t * gs)
{
  return (gs != NULL) ? static_cast<int>(gs->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


