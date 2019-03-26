/**
 * @file Arc.cpp
 * @brief Implementation of the Arc class.
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
#include <sbgn/Arc.h>
#include <sbgn/SbgnListOfArcs.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Arc using the given SBGN Level and @ p version values.
 */
Arc::Arc(unsigned int level, unsigned int version)
  : SBase(level, version)
  , mClazz ("")
  , mSource ("")
  , mTarget ("")
  , mGlyphs (level, version)
  , mStart (NULL)
  , mPoints (level, version)
  , mEnd (NULL)
  , mPorts (level, version)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  mPoints.setElementName("next");
  connectToChild();
}


/*
 * Creates a new Arc using the given SbgnNamespaces object @p sbgnns.
 */
Arc::Arc(SbgnNamespaces *sbgnns)
  : SBase(sbgnns)
  , mClazz ("")
  , mSource ("")
  , mTarget ("")
  , mGlyphs (sbgnns)
  , mStart (NULL)
  , mPoints (sbgnns)
  , mEnd (NULL)
  , mPorts (sbgnns)
{
  setElementNamespace(sbgnns->getURI());
  mPoints.setElementName("next");
  connectToChild();
}


/*
 * Copy constructor for Arc.
 */
Arc::Arc(const Arc& orig)
  : SBase( orig )
  , mClazz ( orig.mClazz )
  , mSource ( orig.mSource )
  , mTarget ( orig.mTarget )
  , mGlyphs ( orig.mGlyphs )
  , mStart ( NULL )
  , mPoints ( orig.mPoints )
  , mEnd ( NULL )
  , mPorts ( orig.mPorts )
{
  if (orig.mStart != NULL)
  {
    mStart = orig.mStart->clone();
  }

  if (orig.mEnd != NULL)
  {
    mEnd = orig.mEnd->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Arc.
 */
Arc&
Arc::operator=(const Arc& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mClazz = rhs.mClazz;
    mSource = rhs.mSource;
    mTarget = rhs.mTarget;
    mGlyphs = rhs.mGlyphs;
    mPoints = rhs.mPoints;
    mPorts = rhs.mPorts;
    delete mStart;
    if (rhs.mStart != NULL)
    {
      mStart = rhs.mStart->clone();
    }
    else
    {
      mStart = NULL;
    }

    delete mEnd;
    if (rhs.mEnd != NULL)
    {
      mEnd = rhs.mEnd->clone();
    }
    else
    {
      mEnd = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Arc object.
 */
Arc*
Arc::clone() const
{
  return new Arc(*this);
}


/*
 * Destructor for Arc.
 */
Arc::~Arc()
{
  delete mStart;
  mStart = NULL;
  delete mEnd;
  mEnd = NULL;
}


/*
 * Returns the value of the "id" attribute of this Arc.
 */
const std::string&
Arc::getId() const
{
  return mId;
}


/*
 * Returns the value of the "class" attribute of this Arc.
 */
const std::string&
Arc::getClazz() const
{
  return mClazz;
}


/*
 * Returns the value of the "source" attribute of this Arc.
 */
const std::string&
Arc::getSource() const
{
  return mSource;
}


/*
 * Returns the value of the "target" attribute of this Arc.
 */
const std::string&
Arc::getTarget() const
{
  return mTarget;
}


/*
 * Predicate returning @c true if this Arc's "id" attribute is set.
 */
bool
Arc::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this Arc's "class" attribute is set.
 */
bool
Arc::isSetClazz() const
{
  return (mClazz.empty() == false);
}


/*
 * Predicate returning @c true if this Arc's "source" attribute is set.
 */
bool
Arc::isSetSource() const
{
  return (mSource.empty() == false);
}


/*
 * Predicate returning @c true if this Arc's "target" attribute is set.
 */
bool
Arc::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this Arc.
 */
int
Arc::setId(const std::string& id)
{
  if (!(SyntaxChecker::isValidXMLID(id)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mId = id;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "class" attribute of this Arc.
 */
int
Arc::setClazz(const std::string& clazz)
{
  mClazz = clazz;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "source" attribute of this Arc.
 */
int
Arc::setSource(const std::string& source)
{
  if (!(SyntaxChecker::isValidXMLID(source)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mSource = source;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "target" attribute of this Arc.
 */
int
Arc::setTarget(const std::string& target)
{
  if (!(SyntaxChecker::isValidXMLID(target)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTarget = target;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "id" attribute of this Arc.
 */
int
Arc::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "class" attribute of this Arc.
 */
int
Arc::unsetClazz()
{
  mClazz.erase();

  if (mClazz.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "source" attribute of this Arc.
 */
int
Arc::unsetSource()
{
  mSource.erase();

  if (mSource.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "target" attribute of this Arc.
 */
int
Arc::unsetTarget()
{
  mTarget.erase();

  if (mTarget.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "start" element of this Arc.
 */
const Point*
Arc::getStart() const
{
  return mStart;
}


/*
 * Returns the value of the "start" element of this Arc.
 */
Point*
Arc::getStart()
{
  return mStart;
}


/*
 * Returns the value of the "end" element of this Arc.
 */
const Point*
Arc::getEnd() const
{
  return mEnd;
}


/*
 * Returns the value of the "end" element of this Arc.
 */
Point*
Arc::getEnd()
{
  return mEnd;
}


/*
 * Predicate returning @c true if this Arc's "start" element is set.
 */
bool
Arc::isSetStart() const
{
  return (mStart != NULL);
}


/*
 * Predicate returning @c true if this Arc's "end" element is set.
 */
bool
Arc::isSetEnd() const
{
  return (mEnd != NULL);
}


/*
 * Sets the value of the "start" element of this Arc.
 */
int
Arc::setStart(const Point* start)
{
  if (mStart == start)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (start == NULL)
  {
    delete mStart;
    mStart = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mStart;
    mStart = (start != NULL) ? start->clone() : NULL;
    if (mStart != NULL)
    {
      mStart->setElementName("start");
      mStart->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "end" element of this Arc.
 */
int
Arc::setEnd(const Point* end)
{
  if (mEnd == end)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (end == NULL)
  {
    delete mEnd;
    mEnd = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mEnd;
    mEnd = (end != NULL) ? end->clone() : NULL;
    if (mEnd != NULL)
    {
      mEnd->setElementName("end");
      mEnd->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new Point object, adds it to this Arc object and returns the Point
 * object created.
 */
Point*
Arc::createStart()
{
  if (mStart != NULL)
  {
    delete mStart;
  }

  mStart = new Point(getSbgnNamespaces());

  mStart->setElementName("start");

  connectToChild();

  return mStart;
}


/*
 * Creates a new Point object, adds it to this Arc object and returns the Point
 * object created.
 */
Point*
Arc::createEnd()
{
  if (mEnd != NULL)
  {
    delete mEnd;
  }

  mEnd = new Point(getSbgnNamespaces());

  mEnd->setElementName("end");

  connectToChild();

  return mEnd;
}


/*
 * Unsets the value of the "start" element of this Arc.
 */
int
Arc::unsetStart()
{
  delete mStart;
  mStart = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "end" element of this Arc.
 */
int
Arc::unsetEnd()
{
  delete mEnd;
  mEnd = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the SbgnListOfGlyphs from this Arc.
 */
const SbgnListOfGlyphs*
Arc::getListOfGlyphs() const
{
  return &mGlyphs;
}


/*
 * Returns the SbgnListOfGlyphs from this Arc.
 */
SbgnListOfGlyphs*
Arc::getListOfGlyphs()
{
  return &mGlyphs;
}


/*
 * Get a Glyph from the Arc.
 */
Glyph*
Arc::getGlyph(unsigned int n)
{
  return mGlyphs.get(n);
}


/*
 * Get a Glyph from the Arc.
 */
const Glyph*
Arc::getGlyph(unsigned int n) const
{
  return mGlyphs.get(n);
}


/*
 * Get a Glyph from the Arc based on its identifier.
 */
Glyph*
Arc::getGlyph(const std::string& sid)
{
  return mGlyphs.get(sid);
}


/*
 * Get a Glyph from the Arc based on its identifier.
 */
const Glyph*
Arc::getGlyph(const std::string& sid) const
{
  return mGlyphs.get(sid);
}


/*
 * Adds a copy of the given Glyph to this Arc.
 */
int
Arc::addGlyph(const Glyph* g)
{
  if (g == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (g->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != g->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != g->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(g)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else if (g->isSetId() && (mGlyphs.get(g->getId())) != NULL)
  {
    return LIBSBGN_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mGlyphs.append(g);
  }
}


/*
 * Get the number of Glyph objects in this Arc.
 */
unsigned int
Arc::getNumGlyphs() const
{
  return mGlyphs.size();
}


/*
 * Creates a new Glyph object, adds it to this Arc object and returns the Glyph
 * object created.
 */
Glyph*
Arc::createGlyph()
{
  Glyph* g = NULL;

  try
  {
    g = new Glyph(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (g != NULL)
  {
    mGlyphs.appendAndOwn(g);
  }

  return g;
}


/*
 * Removes the nth Glyph from this Arc and returns a pointer to it.
 */
Glyph*
Arc::removeGlyph(unsigned int n)
{
  return mGlyphs.remove(n);
}


/*
 * Removes the Glyph from this Arc based on its identifier and returns a
 * pointer to it.
 */
Glyph*
Arc::removeGlyph(const std::string& sid)
{
  return mGlyphs.remove(sid);
}


/*
 * Returns the SbgnListOfPoints from this Arc.
 */
const SbgnListOfPoints*
Arc::getListOfNexts() const
{
  return &mPoints;
}


/*
 * Returns the SbgnListOfPoints from this Arc.
 */
SbgnListOfPoints*
Arc::getListOfNexts()
{
  return &mPoints;
}


/*
 * Get a Point from the Arc.
 */
Point*
Arc::getNext(unsigned int n)
{
  return mPoints.get(n);
}


/*
 * Get a Point from the Arc.
 */
const Point*
Arc::getNext(unsigned int n) const
{
  return mPoints.get(n);
}


/*
 * Adds a copy of the given Point to this Arc.
 */
int
Arc::addNext(const Point* p)
{
  if (p == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (p->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != p->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != p->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(p)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return mPoints.append(p);
  }
}


/*
 * Get the number of Point objects in this Arc.
 */
unsigned int
Arc::getNumNexts() const
{
  return mPoints.size();
}


/*
 * Creates a new Point object, adds it to this Arc object and returns the Point
 * object created.
 */
Point*
Arc::createNext()
{
  Point* p = NULL;

  try
  {
    p = new Point(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (p != NULL)
  {
    p->setElementName("next");
    mPoints.appendAndOwn(p);
  }

  return p;
}


/*
 * Removes the nth Point from this Arc and returns a pointer to it.
 */
Point*
Arc::removeNext(unsigned int n)
{
  return mPoints.remove(n);
}


/*
 * Returns the SbgnListOfPorts from this Arc.
 */
const SbgnListOfPorts*
Arc::getListOfPorts() const
{
  return &mPorts;
}


/*
 * Returns the SbgnListOfPorts from this Arc.
 */
SbgnListOfPorts*
Arc::getListOfPorts()
{
  return &mPorts;
}


/*
 * Get a Port from the Arc.
 */
Port*
Arc::getPort(unsigned int n)
{
  return mPorts.get(n);
}


/*
 * Get a Port from the Arc.
 */
const Port*
Arc::getPort(unsigned int n) const
{
  return mPorts.get(n);
}


/*
 * Get a Port from the Arc based on its identifier.
 */
Port*
Arc::getPort(const std::string& sid)
{
  return mPorts.get(sid);
}


/*
 * Get a Port from the Arc based on its identifier.
 */
const Port*
Arc::getPort(const std::string& sid) const
{
  return mPorts.get(sid);
}


/*
 * Adds a copy of the given Port to this Arc.
 */
int
Arc::addPort(const Port* p)
{
  if (p == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (p->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != p->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != p->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(p)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else if (p->isSetId() && (mPorts.get(p->getId())) != NULL)
  {
    return LIBSBGN_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mPorts.append(p);
  }
}


/*
 * Get the number of Port objects in this Arc.
 */
unsigned int
Arc::getNumPorts() const
{
  return mPorts.size();
}


/*
 * Creates a new Port object, adds it to this Arc object and returns the Port
 * object created.
 */
Port*
Arc::createPort()
{
  Port* p = NULL;

  try
  {
    p = new Port(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (p != NULL)
  {
    mPorts.appendAndOwn(p);
  }

  return p;
}


/*
 * Removes the nth Port from this Arc and returns a pointer to it.
 */
Port*
Arc::removePort(unsigned int n)
{
  return mPorts.remove(n);
}


/*
 * Removes the Port from this Arc based on its identifier and returns a pointer
 * to it.
 */
Port*
Arc::removePort(const std::string& sid)
{
  return mPorts.remove(sid);
}


/*
 * Returns the XML element name of this Arc object.
 */
const std::string&
Arc::getElementName() const
{
  static const string name = "arc";
  return name;
}


/*
 * Returns the libSBGN type code for this Arc object.
 */
int
Arc::getTypeCode() const
{
  return SBGN_SBGNML_ARC;
}


/*
 * Predicate returning @c true if all the required attributes for this Arc
 * object have been set.
 */
bool
Arc::hasRequiredAttributes() const
{
  bool allPresent = SBase::hasRequiredAttributes();

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetClazz() == false)
  {
    allPresent = false;
  }

  if (isSetSource() == false)
  {
    allPresent = false;
  }

  if (isSetTarget() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this Arc object
 * have been set.
 */
bool
Arc::hasRequiredElements() const
{
  bool allPresent = SBase::hasRequiredElements();

  if (isSetStart() == false)
  {
    allPresent = false;
  }

  if (isSetEnd() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Write any contained elements
 */
void
Arc::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeElements(stream);

  if (isSetStart() == true)
  {
    mStart->write(stream);
  }

  if (isSetEnd() == true)
  {
    mEnd->write(stream);
  }

  for (unsigned int i = 0; i < getNumGlyphs(); i++)
  {
    getGlyph(i)->write(stream);
  }

  for (unsigned int i = 0; i < getNumNexts(); i++)
  {
    getNext(i)->write(stream);
  }

  for (unsigned int i = 0; i < getNumPorts(); i++)
  {
    getPort(i)->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
Arc::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
Arc::setSbgnDocument(SbgnDocument* d)
{
  SBase::setSbgnDocument(d);

  if (mStart != NULL)
  {
    mStart->setSbgnDocument(d);
  }

  if (mEnd != NULL)
  {
    mEnd->setSbgnDocument(d);
  }

  mGlyphs.setSbgnDocument(d);

  mPoints.setSbgnDocument(d);

  mPorts.setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
Arc::connectToChild()
{
  SBase::connectToChild();

  if (mStart != NULL)
  {
    mStart->connectToParent(this);
  }

  if (mEnd != NULL)
  {
    mEnd->connectToParent(this);
  }

  mGlyphs.connectToParent(this);

  mPoints.connectToParent(this);

  mPorts.connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::getAttribute(const std::string& attributeName, unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::getAttribute(const std::string& attributeName, std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBGN_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "class")
  {
    value = getClazz();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "source")
  {
    value = getSource();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this Arc's attribute "attributeName" is set.
 */
bool
Arc::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "class")
  {
    value = isSetClazz();
  }
  else if (attributeName == "source")
  {
    value = isSetSource();
  }
  else if (attributeName == "target")
  {
    value = isSetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::setAttribute(const std::string& attributeName, const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "class")
  {
    return_value = setClazz(value);
  }
  else if (attributeName == "source")
  {
    return_value = setSource(value);
  }
  else if (attributeName == "target")
  {
    return_value = setTarget(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Arc.
 */
int
Arc::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "class")
  {
    value = unsetClazz();
  }
  else if (attributeName == "source")
  {
    value = unsetSource();
  }
  else if (attributeName == "target")
  {
    value = unsetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this Arc.
 */
SbgnBase*
Arc::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "start")
  {
    return createStart();
  }
  else if (elementName == "end")
  {
    return createEnd();
  }
  else if (elementName == "glyph")
  {
    return createGlyph();
  }
  else if (elementName == "next")
  {
    return createNext();
  }
  else if (elementName == "port")
  {
    return createPort();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this Arc.
 */
int
Arc::addChildObject(const std::string& elementName, const SbgnBase* element)
{
  if (elementName == "start" && element->getTypeCode() == SBGN_SBGNML_POINT)
  {
    return setStart((const Point*)(element));
  }
  else if (elementName == "end" && element->getTypeCode() == SBGN_SBGNML_POINT)
  {
    return setEnd((const Point*)(element));
  }
  else if (elementName == "glyph" && element->getTypeCode() ==
    SBGN_SBGNML_GLYPH)
  {
    return addGlyph((const Glyph*)(element));
  }
  else if (elementName == "next" && element->getTypeCode() ==
    SBGN_SBGNML_POINT)
  {
    return addNext((const Point*)(element));
  }
  else if (elementName == "port" && element->getTypeCode() == SBGN_SBGNML_PORT)
  {
    return addPort((const Port*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Arc.
 */
SbgnBase*
Arc::removeChildObject(const std::string& elementName, const std::string& id)
{
  if (elementName == "start")
  {
    Point * obj = getStart();
    if (unsetStart() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "end")
  {
    Point * obj = getEnd();
    if (unsetEnd() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "glyph")
  {
    return removeGlyph(id);
  }
  else if (elementName == "next")
  {
    for (unsigned int i = 0; i < getNumNexts(); i++)
    {
      if (getNext(i)->getId() == id)
      {
        return removeNext(i);
      }
    }
  }
  else if (elementName == "port")
  {
    return removePort(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this Arc.
 */
unsigned int
Arc::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "start")
  {
    if (isSetStart())
    {
      return 1;
    }
  }
  else if (elementName == "end")
  {
    if (isSetEnd())
    {
      return 1;
    }
  }
  else if (elementName == "glyph")
  {
    return getNumGlyphs();
  }
  else if (elementName == "next")
  {
    return getNumNexts();
  }
  else if (elementName == "port")
  {
    return getNumPorts();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this Arc.
 */
SbgnBase*
Arc::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "start")
  {
    return getStart();
  }
  else if (elementName == "end")
  {
    return getEnd();
  }
  else if (elementName == "glyph")
  {
    return getGlyph(index);
  }
  else if (elementName == "next")
  {
    return getNext(index);
  }
  else if (elementName == "port")
  {
    return getPort(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
Arc::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  if (mStart != NULL)
  {
    if (mStart->getId() == id)
    {
      return mStart;
    }

    obj = mStart->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mEnd != NULL)
  {
    if (mEnd->getId() == id)
    {
      return mEnd;
    }

    obj = mEnd->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mGlyphs.getId() == id)
  {
    return &mGlyphs;
  }

  obj = mGlyphs.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mPoints.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  if (mPorts.getId() == id)
  {
    return &mPorts;
  }

  obj = mPorts.getElementBySId(id);

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
Arc::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SbgnBase* obj = SBase::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "start")
  {
    if (isSetStart())
    {
      getErrorLog()->logError(SbgnmlArcAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mStart;
    mStart = new Point(getSbgnNamespaces());
    mStart->setElementName(name);
    obj = mStart;
  }
  else if (name == "end")
  {
    if (isSetEnd())
    {
      getErrorLog()->logError(SbgnmlArcAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mEnd;
    mEnd = new Point(getSbgnNamespaces());
    mEnd->setElementName(name);
    obj = mEnd;
  }
  else if (name == "glyph")
  {
    obj = mGlyphs.createObject(stream);
  }
  else if (name == "next")
  {
    obj = mPoints.createObject(stream);
  }
  else if (name == "port")
  {
    obj = mPorts.createObject(stream);
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
Arc::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes&
  attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("class");

  attributes.add("source");

  attributes.add("target");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Arc::readAttributes(
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
    static_cast<SbgnListOfArcs*>(getParentSbgnObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SbgnUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SbgnUnknownCoreAttribute);
        log->logError(SbgnmlMapLOArcsAllowedCoreAttributes, level, version,
          details, getLine(), getColumn());
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
        log->logError(SbgnmlArcAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // id ID (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<Arc>");
    }
    else if (SyntaxChecker::isValidXMLID(mId) == false)
    {
      logError(SbgnmlArcIdMustBeID, level, version, "The attribute id='" + mId
        + "' does not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'id' is missing from the <Arc> "
      "element.";
    log->logError(SbgnmlArcAllowedAttributes, level, version, message,
      getLine(), getColumn());
  }

  // 
  // class string (use = "required" )
  // 

  assigned = attributes.readInto("class", mClazz);

  if (assigned == true)
  {
    if (mClazz.empty() == true)
    {
      logEmptyString(mClazz, level, version, "<Arc>");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'class' is missing from the <Arc> "
      "element.";
    log->logError(SbgnmlArcAllowedAttributes, level, version, message,
      getLine(), getColumn());
  }

  // 
  // source IDREF (use = "required" )
  // 

  assigned = attributes.readInto("source", mSource);

  if (assigned == true)
  {
    if (mSource.empty() == true)
    {
      logEmptyString(mSource, level, version, "<Arc>");
    }
    else if (SyntaxChecker::isValidXMLID(mSource) == false)
    {
      std::string msg = "The source attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mSource + "', which does not conform to the syntax.";
      logError(SbgnmlArcSourceMustBeID, level, version, msg, getLine(),
        getColumn());
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'source' is missing from the <Arc> "
      "element.";
    log->logError(SbgnmlArcAllowedAttributes, level, version, message,
      getLine(), getColumn());
  }

  // 
  // target IDREF (use = "required" )
  // 

  assigned = attributes.readInto("target", mTarget);

  if (assigned == true)
  {
    if (mTarget.empty() == true)
    {
      logEmptyString(mTarget, level, version, "<Arc>");
    }
    else if (SyntaxChecker::isValidXMLID(mTarget) == false)
    {
      std::string msg = "The target attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mTarget + "', which does not conform to the syntax.";
      logError(SbgnmlArcTargetMustBeID, level, version, msg, getLine(),
        getColumn());
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'target' is missing from the <Arc> "
      "element.";
    log->logError(SbgnmlArcAllowedAttributes, level, version, message,
      getLine(), getColumn());
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
Arc::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetClazz() == true)
  {
    stream.writeAttribute("class", getPrefix(), mClazz);
  }

  if (isSetSource() == true)
  {
    stream.writeAttribute("source", getPrefix(), mSource);
  }

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Arc_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
Arc_t *
Arc_create(unsigned int level, unsigned int version)
{
  return new Arc(level, version);
}


/*
 * Creates and returns a deep copy of this Arc_t object.
 */
LIBSBGN_EXTERN
Arc_t*
Arc_clone(const Arc_t* a)
{
  if (a != NULL)
  {
    return static_cast<Arc_t*>(a->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Arc_t object.
 */
LIBSBGN_EXTERN
void
Arc_free(Arc_t* a)
{
  if (a != NULL)
  {
    delete a;
  }
}


/*
 * Returns the value of the "id" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
char *
Arc_getId(const Arc_t * a)
{
  if (a == NULL)
  {
    return NULL;
  }

  return a->getId().empty() ? NULL : safe_strdup(a->getId().c_str());
}


/*
 * Returns the value of the "class" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
char *
Arc_getClazz(const Arc_t * a)
{
  if (a == NULL)
  {
    return NULL;
  }

  return a->getClazz().empty() ? NULL : safe_strdup(a->getClazz().c_str());
}


/*
 * Returns the value of the "source" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
char *
Arc_getSource(const Arc_t * a)
{
  if (a == NULL)
  {
    return NULL;
  }

  return a->getSource().empty() ? NULL : safe_strdup(a->getSource().c_str());
}


/*
 * Returns the value of the "target" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
char *
Arc_getTarget(const Arc_t * a)
{
  if (a == NULL)
  {
    return NULL;
  }

  return a->getTarget().empty() ? NULL : safe_strdup(a->getTarget().c_str());
}


/*
 * Predicate returning @c 1 (true) if this Arc_t's "id" attribute is set.
 */
LIBSBGN_EXTERN
int
Arc_isSetId(const Arc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Arc_t's "class" attribute is set.
 */
LIBSBGN_EXTERN
int
Arc_isSetClazz(const Arc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isSetClazz()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Arc_t's "source" attribute is set.
 */
LIBSBGN_EXTERN
int
Arc_isSetSource(const Arc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isSetSource()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Arc_t's "target" attribute is set.
 */
LIBSBGN_EXTERN
int
Arc_isSetTarget(const Arc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isSetTarget()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_setId(Arc_t * a, const char * id)
{
  return (a != NULL) ? a->setId(id) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "class" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_setClazz(Arc_t * a, const char * clazz)
{
  return (a != NULL) ? a->setClazz(clazz) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "source" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_setSource(Arc_t * a, const char * source)
{
  return (a != NULL) ? a->setSource(source) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "target" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_setTarget(Arc_t * a, const char * target)
{
  return (a != NULL) ? a->setTarget(target) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_unsetId(Arc_t * a)
{
  return (a != NULL) ? a->unsetId() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "class" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_unsetClazz(Arc_t * a)
{
  return (a != NULL) ? a->unsetClazz() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "source" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_unsetSource(Arc_t * a)
{
  return (a != NULL) ? a->unsetSource() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_unsetTarget(Arc_t * a)
{
  return (a != NULL) ? a->unsetTarget() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns the value of the "start" element of this Arc_t.
 */
LIBSBGN_EXTERN
const Point_t*
Arc_getStart(const Arc_t * a)
{
  if (a == NULL)
  {
    return NULL;
  }

  return (Point_t*)(a->getStart());
}


/*
 * Returns the value of the "end" element of this Arc_t.
 */
LIBSBGN_EXTERN
const Point_t*
Arc_getEnd(const Arc_t * a)
{
  if (a == NULL)
  {
    return NULL;
  }

  return (Point_t*)(a->getEnd());
}


/*
 * Predicate returning @c 1 (true) if this Arc_t's "start" element is set.
 */
LIBSBGN_EXTERN
int
Arc_isSetStart(const Arc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isSetStart()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Arc_t's "end" element is set.
 */
LIBSBGN_EXTERN
int
Arc_isSetEnd(const Arc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isSetEnd()) : 0;
}


/*
 * Sets the value of the "start" element of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_setStart(Arc_t * a, const Point_t* start)
{
  return (a != NULL) ? a->setStart(start) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "end" element of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_setEnd(Arc_t * a, const Point_t* end)
{
  return (a != NULL) ? a->setEnd(end) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Creates a new Point_t object, adds it to this Arc_t object and returns the
 * Point_t object created.
 */
LIBSBGN_EXTERN
Point_t*
Arc_createStart(Arc_t* a)
{
  if (a == NULL)
  {
    return NULL;
  }

  return (Point_t*)(a->createStart());
}


/*
 * Creates a new Point_t object, adds it to this Arc_t object and returns the
 * Point_t object created.
 */
LIBSBGN_EXTERN
Point_t*
Arc_createEnd(Arc_t* a)
{
  if (a == NULL)
  {
    return NULL;
  }

  return (Point_t*)(a->createEnd());
}


/*
 * Unsets the value of the "start" element of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_unsetStart(Arc_t * a)
{
  return (a != NULL) ? a->unsetStart() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "end" element of this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_unsetEnd(Arc_t * a)
{
  return (a != NULL) ? a->unsetEnd() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing Glyph_t objects from this Arc_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Arc_getListOfGlyphs(Arc_t* a)
{
  return (a != NULL) ? a->getListOfGlyphs() : NULL;
}


/*
 * Get a Glyph_t from the Arc_t.
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_getGlyph(Arc_t* a, unsigned int n)
{
  return (a != NULL) ? a->getGlyph(n) : NULL;
}


/*
 * Get a Glyph_t from the Arc_t based on its identifier.
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_getGlyphById(Arc_t* a, const char *sid)
{
  return (a != NULL && sid != NULL) ? a->getGlyph(sid) : NULL;
}


/*
 * Adds a copy of the given Glyph_t to this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_addGlyph(Arc_t* a, const Glyph_t* g)
{
  return (a != NULL) ? a->addGlyph(g) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of Glyph_t objects in this Arc_t.
 */
LIBSBGN_EXTERN
unsigned int
Arc_getNumGlyphs(Arc_t* a)
{
  return (a != NULL) ? a->getNumGlyphs() : SBGN_INT_MAX;
}


/*
 * Creates a new Glyph_t object, adds it to this Arc_t object and returns the
 * Glyph_t object created.
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_createGlyph(Arc_t* a)
{
  return (a != NULL) ? a->createGlyph() : NULL;
}


/*
 * Removes the nth Glyph_t from this Arc_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_removeGlyph(Arc_t* a, unsigned int n)
{
  return (a != NULL) ? a->removeGlyph(n) : NULL;
}


/*
 * Removes the Glyph_t from this Arc_t based on its identifier and returns a
 * pointer to it.
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_removeGlyphById(Arc_t* a, const char* sid)
{
  return (a != NULL && sid != NULL) ? a->removeGlyph(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing Point_t objects from this Arc_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Arc_getListOfNexts(Arc_t* a)
{
  return (a != NULL) ? a->getListOfNexts() : NULL;
}


/*
 * Get a Point_t from the Arc_t.
 */
LIBSBGN_EXTERN
Point_t*
Arc_getNext(Arc_t* a, unsigned int n)
{
  return (a != NULL) ? a->getNext(n) : NULL;
}


/*
 * Adds a copy of the given Point_t to this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_addNext(Arc_t* a, const Point_t* p)
{
  return (a != NULL) ? a->addNext(p) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of Point_t objects in this Arc_t.
 */
LIBSBGN_EXTERN
unsigned int
Arc_getNumNexts(Arc_t* a)
{
  return (a != NULL) ? a->getNumNexts() : SBGN_INT_MAX;
}


/*
 * Creates a new Point_t object, adds it to this Arc_t object and returns the
 * Point_t object created.
 */
LIBSBGN_EXTERN
Point_t*
Arc_createNext(Arc_t* a)
{
  return (a != NULL) ? a->createNext() : NULL;
}


/*
 * Removes the nth Point_t from this Arc_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
Point_t*
Arc_removeNext(Arc_t* a, unsigned int n)
{
  return (a != NULL) ? a->removeNext(n) : NULL;
}


/*
 * Returns a ListOf_t * containing Port_t objects from this Arc_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Arc_getListOfPorts(Arc_t* a)
{
  return (a != NULL) ? a->getListOfPorts() : NULL;
}


/*
 * Get a Port_t from the Arc_t.
 */
LIBSBGN_EXTERN
Port_t*
Arc_getPort(Arc_t* a, unsigned int n)
{
  return (a != NULL) ? a->getPort(n) : NULL;
}


/*
 * Get a Port_t from the Arc_t based on its identifier.
 */
LIBSBGN_EXTERN
Port_t*
Arc_getPortById(Arc_t* a, const char *sid)
{
  return (a != NULL && sid != NULL) ? a->getPort(sid) : NULL;
}


/*
 * Adds a copy of the given Port_t to this Arc_t.
 */
LIBSBGN_EXTERN
int
Arc_addPort(Arc_t* a, const Port_t* p)
{
  return (a != NULL) ? a->addPort(p) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of Port_t objects in this Arc_t.
 */
LIBSBGN_EXTERN
unsigned int
Arc_getNumPorts(Arc_t* a)
{
  return (a != NULL) ? a->getNumPorts() : SBGN_INT_MAX;
}


/*
 * Creates a new Port_t object, adds it to this Arc_t object and returns the
 * Port_t object created.
 */
LIBSBGN_EXTERN
Port_t*
Arc_createPort(Arc_t* a)
{
  return (a != NULL) ? a->createPort() : NULL;
}


/*
 * Removes the nth Port_t from this Arc_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
Port_t*
Arc_removePort(Arc_t* a, unsigned int n)
{
  return (a != NULL) ? a->removePort(n) : NULL;
}


/*
 * Removes the Port_t from this Arc_t based on its identifier and returns a
 * pointer to it.
 */
LIBSBGN_EXTERN
Port_t*
Arc_removePortById(Arc_t* a, const char* sid)
{
  return (a != NULL && sid != NULL) ? a->removePort(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Arc_t object have been set.
 */
LIBSBGN_EXTERN
int
Arc_hasRequiredAttributes(const Arc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this Arc_t
 * object have been set.
 */
LIBSBGN_EXTERN
int
Arc_hasRequiredElements(const Arc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->hasRequiredElements()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END


