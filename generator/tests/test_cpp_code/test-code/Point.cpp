/**
 * @file Point.cpp
 * @brief Implementation of the Point class.
 * @author DEVISER
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
#include <sbgn/Point.h>
#include <sbgn/SbgnListOfPoints.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Point using the given SBGN Level and @ p version values.
 */
Point::Point(unsigned int level, unsigned int version)
  : SBase(level, version)
  , mX (util_NaN())
  , mIsSetX (false)
  , mY (util_NaN())
  , mIsSetY (false)
  , mPoints (new SbgnListOfPoints (level, version))
  , mElementName("point")
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new Point using the given SbgnNamespaces object @p sbgnns.
 */
Point::Point(SbgnNamespaces *sbgnns)
  : SBase(sbgnns)
  , mX (util_NaN())
  , mIsSetX (false)
  , mY (util_NaN())
  , mIsSetY (false)
  , mPoints (new SbgnListOfPoints (sbgnns))
  , mElementName("point")
{
  setElementNamespace(sbgnns->getURI());
  connectToChild();
}


/*
 * Copy constructor for Point.
 */
Point::Point(const Point& orig)
  : SBase( orig )
  , mX ( orig.mX )
  , mIsSetX ( orig.mIsSetX )
  , mY ( orig.mY )
  , mIsSetY ( orig.mIsSetY )
  , mPoints ( NULL )
  , mElementName ( orig.mElementName )
{
  if (orig.mPoints != NULL)
  {
    mPoints = orig.mPoints->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Point.
 */
Point&
Point::operator=(const Point& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mX = rhs.mX;
    mIsSetX = rhs.mIsSetX;
    mY = rhs.mY;
    mIsSetY = rhs.mIsSetY;
    mElementName = rhs.mElementName;
    delete mPoints;
    if (rhs.mPoints != NULL)
    {
      mPoints = rhs.mPoints->clone();
    }
    else
    {
      mPoints = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Point object.
 */
Point*
Point::clone() const
{
  return new Point(*this);
}


/*
 * Destructor for Point.
 */
Point::~Point()
{
  delete mPoints;
  mPoints = NULL;
}


/*
 * Returns the value of the "x" attribute of this Point.
 */
double
Point::getX() const
{
  return mX;
}


/*
 * Returns the value of the "y" attribute of this Point.
 */
double
Point::getY() const
{
  return mY;
}


/*
 * Predicate returning @c true if this Point's "x" attribute is set.
 */
bool
Point::isSetX() const
{
  return mIsSetX;
}


/*
 * Predicate returning @c true if this Point's "y" attribute is set.
 */
bool
Point::isSetY() const
{
  return mIsSetY;
}


/*
 * Sets the value of the "x" attribute of this Point.
 */
int
Point::setX(double x)
{
  mX = x;
  mIsSetX = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "y" attribute of this Point.
 */
int
Point::setY(double y)
{
  mY = y;
  mIsSetY = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "x" attribute of this Point.
 */
int
Point::unsetX()
{
  mX = util_NaN();
  mIsSetX = false;

  if (isSetX() == false)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "y" attribute of this Point.
 */
int
Point::unsetY()
{
  mY = util_NaN();
  mIsSetY = false;

  if (isSetY() == false)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the SbgnListOfPoints * from this Point.
 */
const SbgnListOfPoints *
Point::getListOfPoints() const
{
  return mPoints;
}


/*
 * Returns the SbgnListOfPoints * from this Point.
 */
SbgnListOfPoints *
Point::getListOfPoints()
{
  return mPoints;
}


/*
 * Get a Point from the Point.
 */
Point*
Point::getPoint(unsigned int n)
{
  return mPoints->get(n);
}


/*
 * Get a Point from the Point.
 */
const Point*
Point::getPoint(unsigned int n) const
{
  return mPoints->get(n);
}


/*
 * Adds a copy of the given Point to this Point.
 */
int
Point::addPoint(const Point* p1)
{
  if (p1 == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (p1->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != p1->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != p1->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(p1)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return mPoints->append(p1);
  }
}


/*
 * Get the number of Point objects in this Point.
 */
unsigned int
Point::getNumPoints() const
{
  return mPoints->size();
}


/*
 * Creates a new Point object, adds it to this Point object and returns the
 * Point object created.
 */
Point*
Point::createPoint()
{
  Point* p1 = NULL;

  try
  {
    p1 = new Point(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (p1 != NULL)
  {
    mPoints->appendAndOwn(p1);
  }

  return p1;
}


/*
 * Removes the nth Point from this Point and returns a pointer to it.
 */
Point*
Point::removePoint(unsigned int n)
{
  return mPoints->remove(n);
}


/*
 * Returns the XML element name of this Point object.
 */
const std::string&
Point::getElementName() const
{
  return mElementName;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the XML name of this Point object.
 */
void
Point::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBGN type code for this Point object.
 */
int
Point::getTypeCode() const
{
  return SBGN_SBGNML_POINT;
}


/*
 * Predicate returning @c true if all the required attributes for this Point
 * object have been set.
 */
bool
Point::hasRequiredAttributes() const
{
  bool allPresent = SBase::hasRequiredAttributes();

  if (isSetX() == false)
  {
    allPresent = false;
  }

  if (isSetY() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this Point
 * object have been set.
 */
bool
Point::hasRequiredElements() const
{
  bool allPresent = SBase::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Write any contained elements
 */
void
Point::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeElements(stream);

  for (unsigned int i = 0; i < getNumPoints(); i++)
  {
    getPoint(i)->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
Point::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
Point::setSbgnDocument(SbgnDocument* d)
{
  SBase::setSbgnDocument(d);

  mPoints->setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
Point::connectToChild()
{
  SBase::connectToChild();

  mPoints->connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Point.
 */
int
Point::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Point.
 */
int
Point::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Point.
 */
int
Point::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBGN_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "x")
  {
    value = getX();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "y")
  {
    value = getY();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Point.
 */
int
Point::getAttribute(const std::string& attributeName,
                    unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Point.
 */
int
Point::getAttribute(const std::string& attributeName,
                    std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this Point's attribute "attributeName" is
 * set.
 */
bool
Point::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "x")
  {
    value = isSetX();
  }
  else if (attributeName == "y")
  {
    value = isSetY();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Point.
 */
int
Point::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Point.
 */
int
Point::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Point.
 */
int
Point::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "x")
  {
    return_value = setX(value);
  }
  else if (attributeName == "y")
  {
    return_value = setY(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Point.
 */
int
Point::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Point.
 */
int
Point::setAttribute(const std::string& attributeName,
                    const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Point.
 */
int
Point::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "x")
  {
    value = unsetX();
  }
  else if (attributeName == "y")
  {
    value = unsetY();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this Point.
 */
SbgnBase*
Point::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "point")
  {
    return createPoint();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this Point.
 */
int
Point::addChildObject(const std::string& elementName, const SbgnBase* element)
{
  if (elementName == "point" && element->getTypeCode() == SBGN_SBGNML_POINT)
  {
    return addPoint((const Point*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Point.
 */
SbgnBase*
Point::removeChildObject(const std::string& elementName,
                         const std::string& id)
{
  if (elementName == "point")
  {
    for (unsigned int i = 0; i < getNumPoints(); i++)
    {
      if (getPoint(i)->getId() == id)
      {
        return removePoint(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this Point.
 */
unsigned int
Point::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "point")
  {
    return getNumPoints();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this Point.
 */
SbgnBase*
Point::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "point")
  {
    return getPoint(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
Point::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  obj = mPoints->getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SbgnBase*
Point::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SbgnBase* obj = SBase::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "point")
  {
    obj = mPoints->createObject(stream);
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds the expected attributes for this element
 */
void
Point::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("x");

  attributes.add("y");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Point::readAttributes(
                      const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes&
                        attributes,
                      const LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes&
                        expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SbgnErrorLog* log = getErrorLog();

  if (log && getParentSbgnObject() &&
    static_cast<SbgnListOfPoints*>(getParentSbgnObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SbgnUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SbgnUnknownCoreAttribute);
        log->logError(SbgnmlArcLOPointsAllowedCoreAttributes, level, version,
          details);
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SbgnUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SbgnUnknownCoreAttribute);
        log->logError(SbgnmlPointAllowedAttributes, level, version, details);
      }
    }
  }

  // 
  // x double (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetX = attributes.readInto("x", mX);

  if ( mIsSetX == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sbgnml attribute 'x' from the <Point> element must "
        "be an integer.";
      log->logError(SbgnmlPointXMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'x' is missing from the <Point> "
        "element.";
      log->logError(SbgnmlPointAllowedAttributes, level, version, message);
    }
  }

  // 
  // y double (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetY = attributes.readInto("y", mY);

  if ( mIsSetY == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sbgnml attribute 'y' from the <Point> element must "
        "be an integer.";
      log->logError(SbgnmlPointYMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'y' is missing from the <Point> "
        "element.";
      log->logError(SbgnmlPointAllowedAttributes, level, version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
Point::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeAttributes(stream);

  if (isSetX() == true)
  {
    stream.writeAttribute("x", getPrefix(), mX);
  }

  if (isSetY() == true)
  {
    stream.writeAttribute("y", getPrefix(), mY);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Point_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
Point_t *
Point_create(unsigned int level, unsigned int version)
{
  return new Point(level, version);
}


/*
 * Creates and returns a deep copy of this Point_t object.
 */
LIBSBGN_EXTERN
Point_t*
Point_clone(const Point_t* p)
{
  if (p != NULL)
  {
    return static_cast<Point_t*>(p->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Point_t object.
 */
LIBSBGN_EXTERN
void
Point_free(Point_t* p)
{
  if (p != NULL)
  {
    delete p;
  }
}


/*
 * Returns the value of the "x" attribute of this Point_t.
 */
LIBSBGN_EXTERN
double
Point_getX(const Point_t * p)
{
  return (p != NULL) ? p->getX() : util_NaN();
}


/*
 * Returns the value of the "y" attribute of this Point_t.
 */
LIBSBGN_EXTERN
double
Point_getY(const Point_t * p)
{
  return (p != NULL) ? p->getY() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this Point_t's "x" attribute is set.
 */
LIBSBGN_EXTERN
int
Point_isSetX(const Point_t * p)
{
  return (p != NULL) ? static_cast<int>(p->isSetX()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Point_t's "y" attribute is set.
 */
LIBSBGN_EXTERN
int
Point_isSetY(const Point_t * p)
{
  return (p != NULL) ? static_cast<int>(p->isSetY()) : 0;
}


/*
 * Sets the value of the "x" attribute of this Point_t.
 */
LIBSBGN_EXTERN
int
Point_setX(Point_t * p, double x)
{
  return (p != NULL) ? p->setX(x) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "y" attribute of this Point_t.
 */
LIBSBGN_EXTERN
int
Point_setY(Point_t * p, double y)
{
  return (p != NULL) ? p->setY(y) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "x" attribute of this Point_t.
 */
LIBSBGN_EXTERN
int
Point_unsetX(Point_t * p)
{
  return (p != NULL) ? p->unsetX() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "y" attribute of this Point_t.
 */
LIBSBGN_EXTERN
int
Point_unsetY(Point_t * p)
{
  return (p != NULL) ? p->unsetY() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing Point_t objects from this Point_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Point_getListOfPoints(Point_t* p)
{
  return (p != NULL) ? p->getListOfPoints() : NULL;
}


/*
 * Get a Point_t from the Point_t.
 */
LIBSBGN_EXTERN
Point_t*
Point_getPoint(Point_t* p, unsigned int n)
{
  return (p != NULL) ? p->getPoint(n) : NULL;
}


/*
 * Adds a copy of the given Point_t to this Point_t.
 */
LIBSBGN_EXTERN
int
Point_addPoint(Point_t* p, const Point_t* p1)
{
  return (p != NULL) ? p->addPoint(p1) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of Point_t objects in this Point_t.
 */
LIBSBGN_EXTERN
unsigned int
Point_getNumPoints(Point_t* p)
{
  return (p != NULL) ? p->getNumPoints() : SBGN_INT_MAX;
}


/*
 * Creates a new Point_t object, adds it to this Point_t object and returns the
 * Point_t object created.
 */
LIBSBGN_EXTERN
Point_t*
Point_createPoint(Point_t* p)
{
  return (p != NULL) ? p->createPoint() : NULL;
}


/*
 * Removes the nth Point_t from this Point_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
Point_t*
Point_removePoint(Point_t* p, unsigned int n)
{
  return (p != NULL) ? p->removePoint(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Point_t object have been set.
 */
LIBSBGN_EXTERN
int
Point_hasRequiredAttributes(const Point_t * p)
{
  return (p != NULL) ? static_cast<int>(p->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * Point_t object have been set.
 */
LIBSBGN_EXTERN
int
Point_hasRequiredElements(const Point_t * p)
{
  return (p != NULL) ? static_cast<int>(p->hasRequiredElements()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END


