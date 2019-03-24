/**
 * @file DefaultValues.cpp
 * @brief Implementation of the DefaultValues class.
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
#include <sbml/packages/render/sbml/DefaultValues.h>
#include <sbml/packages/render/validator/RenderSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new DefaultValues using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 */
DefaultValues::DefaultValues(unsigned int level,
                             unsigned int version,
                             unsigned int pkgVersion)
  : SBase(level, version)
  , mStrokeWidth (util_NaN())
  , mIsSetStrokeWidth (false)
  , mFontSize (NULL)
  , mStartHead ("")
{
  setSBMLNamespacesAndOwn(new RenderPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new DefaultValues using the given RenderPkgNamespaces object.
 */
DefaultValues::DefaultValues(RenderPkgNamespaces *renderns)
  : SBase(renderns)
  , mStrokeWidth (util_NaN())
  , mIsSetStrokeWidth (false)
  , mFontSize (NULL)
  , mStartHead ("")
{
  setElementNamespace(renderns->getURI());
  connectToChild();
  loadPlugins(renderns);
}


/*
 * Copy constructor for DefaultValues.
 */
DefaultValues::DefaultValues(const DefaultValues& orig)
  : SBase( orig )
  , mStrokeWidth ( orig.mStrokeWidth )
  , mIsSetStrokeWidth ( orig.mIsSetStrokeWidth )
  , mFontSize ( NULL )
  , mStartHead ( orig.mStartHead )
{
  if (orig.mFontSize != NULL)
  {
    mFontSize = orig.mFontSize->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for DefaultValues.
 */
DefaultValues&
DefaultValues::operator=(const DefaultValues& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mStrokeWidth = rhs.mStrokeWidth;
    mIsSetStrokeWidth = rhs.mIsSetStrokeWidth;
    mStartHead = rhs.mStartHead;
    delete mFontSize;
    if (rhs.mFontSize != NULL)
    {
      mFontSize = rhs.mFontSize->clone();
    }
    else
    {
      mFontSize = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this DefaultValues object.
 */
DefaultValues*
DefaultValues::clone() const
{
  return new DefaultValues(*this);
}


/*
 * Destructor for DefaultValues.
 */
DefaultValues::~DefaultValues()
{
  delete mFontSize;
  mFontSize = NULL;
}


/*
 * Returns the value of the "stroke-width" attribute of this DefaultValues.
 */
double
DefaultValues::getStrokeWidth() const
{
  return mStrokeWidth;
}


/*
 * Returns the value of the "startHead" attribute of this DefaultValues.
 */
const std::string&
DefaultValues::getStartHead() const
{
  return mStartHead;
}


/*
 * Predicate returning @c true if this DefaultValues's "stroke-width" attribute
 * is set.
 */
bool
DefaultValues::isSetStrokeWidth() const
{
  return mIsSetStrokeWidth;
}


/*
 * Predicate returning @c true if this DefaultValues's "startHead" attribute is
 * set.
 */
bool
DefaultValues::isSetStartHead() const
{
  return (mStartHead.empty() == false);
}


/*
 * Sets the value of the "stroke-width" attribute of this DefaultValues.
 */
int
DefaultValues::setStrokeWidth(double strokeWidth)
{
  mStrokeWidth = strokeWidth;
  mIsSetStrokeWidth = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "startHead" attribute of this DefaultValues.
 */
int
DefaultValues::setStartHead(const std::string& startHead)
{
  if (!(SyntaxChecker::isValidInternalSId(startHead)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mStartHead = startHead;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "stroke-width" attribute of this DefaultValues.
 */
int
DefaultValues::unsetStrokeWidth()
{
  mStrokeWidth = util_NaN();
  mIsSetStrokeWidth = false;

  if (isSetStrokeWidth() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "startHead" attribute of this DefaultValues.
 */
int
DefaultValues::unsetStartHead()
{
  mStartHead.erase();

  if (mStartHead.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "font-size" element of this DefaultValues.
 */
const RelAbsVector*
DefaultValues::getFontSize() const
{
  return mFontSize;
}


/*
 * Returns the value of the "font-size" element of this DefaultValues.
 */
RelAbsVector*
DefaultValues::getFontSize()
{
  return mFontSize;
}


/*
 * Predicate returning @c true if this DefaultValues's "font-size" element is
 * set.
 */
bool
DefaultValues::isSetFontSize() const
{
  return (mFontSize != NULL);
}


/*
 * Sets the value of the "font-size" element of this DefaultValues.
 */
int
DefaultValues::setFontSize(const RelAbsVector* fontSize)
{
  if (mFontSize == fontSize)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (fontSize == NULL)
  {
    delete mFontSize;
    mFontSize = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mFontSize;
    mFontSize = (fontSize != NULL) ? fontSize->clone() : NULL;
    if (mFontSize != NULL)
    {
      mFontSize->setElementName("fontSize");
      mFontSize->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new RelAbsVector object, adds it to this DefaultValues object and
 * returns the RelAbsVector object created.
 */
RelAbsVector*
DefaultValues::createFontSize()
{
  if (mFontSize != NULL)
  {
    delete mFontSize;
  }

  RENDER_CREATE_NS(renderns, getSBMLNamespaces());
  mFontSize = new RelAbsVector(renderns);

  mFontSize->setElementName("font-size");

  delete renderns;

  connectToChild();

  return mFontSize;
}


/*
 * Unsets the value of the "font-size" element of this DefaultValues.
 */
int
DefaultValues::unsetFontSize()
{
  delete mFontSize;
  mFontSize = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * @copydoc doc_renamesidref_common
 */
void
DefaultValues::renameSIdRefs(const std::string& oldid,
                             const std::string& newid)
{
  if (isSetStartHead() && mStartHead == oldid)
  {
    setStartHead(newid);
  }
}


/*
 * Returns the XML element name of this DefaultValues object.
 */
const std::string&
DefaultValues::getElementName() const
{
  static const string name = "defaultValues";
  return name;
}


/*
 * Returns the libSBML type code for this DefaultValues object.
 */
int
DefaultValues::getTypeCode() const
{
  return SBML_RENDER_DEFAULTS;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * DefaultValues object have been set.
 */
bool
DefaultValues::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
DefaultValues::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetFontSize() == true)
  {
    mFontSize->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
DefaultValues::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mFontSize != NULL)
  {
    mFontSize->accept(v);
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
DefaultValues::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  if (mFontSize != NULL)
  {
    mFontSize->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
DefaultValues::connectToChild()
{
  SBase::connectToChild();

  if (mFontSize != NULL)
  {
    mFontSize->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
DefaultValues::enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetFontSize())
  {
    mFontSize->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
DefaultValues::updateSBMLNamespace(const std::string& package,
                                   unsigned int level,
                                   unsigned int version)
{
  SBase::updateSBMLNamespace(package, level, version);

  if (mFontSize != NULL)
  {
    mFontSize->updateSBMLNamespace(package, level, version);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::getAttribute(const std::string& attributeName,
                            bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::getAttribute(const std::string& attributeName,
                            int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::getAttribute(const std::string& attributeName,
                            double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "stroke-width")
  {
    value = getStrokeWidth();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::getAttribute(const std::string& attributeName,
                            unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::getAttribute(const std::string& attributeName,
                            std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "startHead")
  {
    value = getStartHead();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this DefaultValues's attribute
 * "attributeName" is set.
 */
bool
DefaultValues::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "stroke-width")
  {
    value = isSetStrokeWidth();
  }
  else if (attributeName == "startHead")
  {
    value = isSetStartHead();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "stroke-width")
  {
    return_value = setStrokeWidth(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::setAttribute(const std::string& attributeName,
                            unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::setAttribute(const std::string& attributeName,
                            const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "startHead")
  {
    return_value = setStartHead(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this DefaultValues.
 */
int
DefaultValues::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "stroke-width")
  {
    value = unsetStrokeWidth();
  }
  else if (attributeName == "startHead")
  {
    value = unsetStartHead();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this DefaultValues.
 */
SBase*
DefaultValues::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "font-size")
  {
    return createFontSize();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this DefaultValues.
 */
int
DefaultValues::addChildObject(const std::string& elementName,
                              const SBase* element)
{
  if (elementName == "font-size" && element->getTypeCode() ==
    SBML_RENDER_RELABSVECTOR)
  {
    return setFontSize((const RelAbsVector*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * DefaultValues.
 */
SBase*
DefaultValues::removeChildObject(const std::string& elementName,
                                 const std::string& id)
{
  if (elementName == "font-size")
  {
    RelAbsVector * obj = getFontSize();
    if (unsetFontSize() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this DefaultValues.
 */
unsigned int
DefaultValues::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "font-size")
  {
    if (isSetFontSize())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this DefaultValues.
 */
SBase*
DefaultValues::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "font-size")
  {
    return getFontSize();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
DefaultValues::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mFontSize != NULL)
  {
    if (mFontSize->getId() == id)
    {
      return mFontSize;
    }

    obj = mFontSize->getElementBySId(id);
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
DefaultValues::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mFontSize != NULL)
  {
    if (mFontSize->getMetaId() == metaid)
    {
      return mFontSize;
    }

    obj = mFontSize->getElementByMetaId(metaid);
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
DefaultValues::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mFontSize, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
DefaultValues::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  RENDER_CREATE_NS(renderns, getSBMLNamespaces());

  if (name == "font-size")
  {
    if (isSetFontSize())
    {
      getErrorLog()->logPackageError("render",
        RenderDefaultValuesAllowedAttributes, getPackageVersion(), getLevel(),
          getVersion(), "", getLine(), getColumn());
    }

    delete mFontSize;
    mFontSize = new RelAbsVector(renderns);
    mFontSize->setElementName(name);
    obj = mFontSize;
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
DefaultValues::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("stroke-width");

  attributes.add("startHead");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
DefaultValues::readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("render", RenderDefaultValuesAllowedAttributes,
          pkgVersion, level, version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("render",
          RenderDefaultValuesAllowedCoreAttributes, pkgVersion, level, version,
            details, getLine(), getColumn());
      }
    }
  }

  // 
  // stroke-width double (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetStrokeWidth = attributes.readInto("stroke-width", mStrokeWidth);

  if ( mIsSetStrokeWidth == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Render attribute 'stroke-width' from the "
        "<DefaultValues> element must be an integer.";
      log->logPackageError("render",
        RenderDefaultValuesStrokeWidthMustBeDouble, pkgVersion, level, version,
          message);
    }
  }

  // 
  // startHead SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("startHead", mStartHead);

  if (assigned == true)
  {
    if (mStartHead.empty() == true)
    {
      logEmptyString(mStartHead, level, version, "<DefaultValues>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mStartHead) == false)
    {
      std::string msg = "The startHead attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mStartHead + "', which does not conform to the syntax.";
      log->logPackageError("render",
        RenderDefaultValuesStartHeadMustBeLineEnding, pkgVersion, level, version,
          msg, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
DefaultValues::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetStrokeWidth() == true)
  {
    stream.writeAttribute("stroke-width", getPrefix(), mStrokeWidth);
  }

  if (isSetStartHead() == true)
  {
    stream.writeAttribute("startHead", getPrefix(), mStartHead);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new DefaultValues_t using the given SBML Level, Version and
 * &ldquo;render&rdquo; package version.
 */
LIBSBML_EXTERN
DefaultValues_t *
DefaultValues_create(unsigned int level,
                     unsigned int version,
                     unsigned int pkgVersion)
{
  return new DefaultValues(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this DefaultValues_t object.
 */
LIBSBML_EXTERN
DefaultValues_t*
DefaultValues_clone(const DefaultValues_t* dv)
{
  if (dv != NULL)
  {
    return static_cast<DefaultValues_t*>(dv->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this DefaultValues_t object.
 */
LIBSBML_EXTERN
void
DefaultValues_free(DefaultValues_t* dv)
{
  if (dv != NULL)
  {
    delete dv;
  }
}


/*
 * Returns the value of the "stroke-width" attribute of this DefaultValues_t.
 */
LIBSBML_EXTERN
double
DefaultValues_getStrokeWidth(const DefaultValues_t * dv)
{
  return (dv != NULL) ? dv->getStrokeWidth() : util_NaN();
}


/*
 * Returns the value of the "startHead" attribute of this DefaultValues_t.
 */
LIBSBML_EXTERN
char *
DefaultValues_getStartHead(const DefaultValues_t * dv)
{
  if (dv == NULL)
  {
    return NULL;
  }

  return dv->getStartHead().empty() ? NULL :
    safe_strdup(dv->getStartHead().c_str());
}


/*
 * Predicate returning @c 1 (true) if this DefaultValues_t's "stroke-width"
 * attribute is set.
 */
LIBSBML_EXTERN
int
DefaultValues_isSetStrokeWidth(const DefaultValues_t * dv)
{
  return (dv != NULL) ? static_cast<int>(dv->isSetStrokeWidth()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this DefaultValues_t's "startHead"
 * attribute is set.
 */
LIBSBML_EXTERN
int
DefaultValues_isSetStartHead(const DefaultValues_t * dv)
{
  return (dv != NULL) ? static_cast<int>(dv->isSetStartHead()) : 0;
}


/*
 * Sets the value of the "stroke-width" attribute of this DefaultValues_t.
 */
LIBSBML_EXTERN
int
DefaultValues_setStrokeWidth(DefaultValues_t * dv, double strokeWidth)
{
  return (dv != NULL) ? dv->setStrokeWidth(strokeWidth) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "startHead" attribute of this DefaultValues_t.
 */
LIBSBML_EXTERN
int
DefaultValues_setStartHead(DefaultValues_t * dv, const char * startHead)
{
  return (dv != NULL) ? dv->setStartHead(startHead) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "stroke-width" attribute of this DefaultValues_t.
 */
LIBSBML_EXTERN
int
DefaultValues_unsetStrokeWidth(DefaultValues_t * dv)
{
  return (dv != NULL) ? dv->unsetStrokeWidth() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "startHead" attribute of this DefaultValues_t.
 */
LIBSBML_EXTERN
int
DefaultValues_unsetStartHead(DefaultValues_t * dv)
{
  return (dv != NULL) ? dv->unsetStartHead() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "font-size" element of this DefaultValues_t.
 */
LIBSBML_EXTERN
const RelAbsVector_t*
DefaultValues_getFontSize(const DefaultValues_t * dv)
{
  if (dv == NULL)
  {
    return NULL;
  }

  return (RelAbsVector_t*)(dv->getFontSize());
}


/*
 * Predicate returning @c 1 (true) if this DefaultValues_t's "font-size"
 * element is set.
 */
LIBSBML_EXTERN
int
DefaultValues_isSetFontSize(const DefaultValues_t * dv)
{
  return (dv != NULL) ? static_cast<int>(dv->isSetFontSize()) : 0;
}


/*
 * Sets the value of the "font-size" element of this DefaultValues_t.
 */
LIBSBML_EXTERN
int
DefaultValues_setFontSize(DefaultValues_t * dv,
                          const RelAbsVector_t* fontSize)
{
  return (dv != NULL) ? dv->setFontSize(fontSize) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new RelAbsVector_t object, adds it to this DefaultValues_t object
 * and returns the RelAbsVector_t object created.
 */
LIBSBML_EXTERN
RelAbsVector_t*
DefaultValues_createFontSize(DefaultValues_t* dv)
{
  if (dv == NULL)
  {
    return NULL;
  }

  return (RelAbsVector_t*)(dv->createFontSize());
}


/*
 * Unsets the value of the "font-size" element of this DefaultValues_t.
 */
LIBSBML_EXTERN
int
DefaultValues_unsetFontSize(DefaultValues_t * dv)
{
  return (dv != NULL) ? dv->unsetFontSize() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * DefaultValues_t object have been set.
 */
LIBSBML_EXTERN
int
DefaultValues_hasRequiredAttributes(const DefaultValues_t * dv)
{
  return (dv != NULL) ? static_cast<int>(dv->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


