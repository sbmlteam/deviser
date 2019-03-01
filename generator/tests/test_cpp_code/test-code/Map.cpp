/**
 * @file Map.cpp
 * @brief Implementation of the Map class.
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
#include <sbgn/Map.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Map using the given SBGN Level and @ p version values.
 */
Map::Map(unsigned int level, unsigned int version)
  : SBase(level, version)
  , mLanguage (SBGNML_LANGUAGE_INVALID)
  , mBBox (NULL)
  , mGlyphs (level, version)
  , mArcs (level, version)
  , mArcGroups (level, version)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new Map using the given SbgnNamespaces object @p sbgnns.
 */
Map::Map(SbgnNamespaces *sbgnns)
  : SBase(sbgnns)
  , mLanguage (SBGNML_LANGUAGE_INVALID)
  , mBBox (NULL)
  , mGlyphs (sbgnns)
  , mArcs (sbgnns)
  , mArcGroups (sbgnns)
{
  setElementNamespace(sbgnns->getURI());
  connectToChild();
}


/*
 * Copy constructor for Map.
 */
Map::Map(const Map& orig)
  : SBase( orig )
  , mLanguage ( orig.mLanguage )
  , mBBox ( NULL )
  , mGlyphs ( orig.mGlyphs )
  , mArcs ( orig.mArcs )
  , mArcGroups ( orig.mArcGroups )
{
  if (orig.mBBox != NULL)
  {
    mBBox = orig.mBBox->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Map.
 */
Map&
Map::operator=(const Map& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mLanguage = rhs.mLanguage;
    mGlyphs = rhs.mGlyphs;
    mArcs = rhs.mArcs;
    mArcGroups = rhs.mArcGroups;
    delete mBBox;
    if (rhs.mBBox != NULL)
    {
      mBBox = rhs.mBBox->clone();
    }
    else
    {
      mBBox = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Map object.
 */
Map*
Map::clone() const
{
  return new Map(*this);
}


/*
 * Destructor for Map.
 */
Map::~Map()
{
  delete mBBox;
  mBBox = NULL;
}


/*
 * Returns the value of the "id" attribute of this Map.
 */
const std::string&
Map::getId() const
{
  return mId;
}


/*
 * Returns the value of the "language" attribute of this Map.
 */
Language_t
Map::getLanguage() const
{
  return mLanguage;
}


/*
 * Returns the value of the "language" attribute of this Map.
 */
std::string
Map::getLanguageAsString() const
{
  std::string code_str = Language_toString(mLanguage);
  return code_str;
}


/*
 * Predicate returning @c true if this Map's "id" attribute is set.
 */
bool
Map::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this Map's "language" attribute is set.
 */
bool
Map::isSetLanguage() const
{
  return (mLanguage != SBGNML_LANGUAGE_INVALID);
}


/*
 * Sets the value of the "id" attribute of this Map.
 */
int
Map::setId(const std::string& id)
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
 * Sets the value of the "language" attribute of this Map.
 */
int
Map::setLanguage(const Language_t language)
{
  if (Language_isValid(language) == 0)
  {
    mLanguage = SBGNML_LANGUAGE_INVALID;
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mLanguage = language;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "language" attribute of this Map.
 */
int
Map::setLanguage(const std::string& language)
{
  mLanguage = Language_fromString(language.c_str());

  if (mLanguage == SBGNML_LANGUAGE_INVALID)
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this Map.
 */
int
Map::unsetId()
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
 * Unsets the value of the "language" attribute of this Map.
 */
int
Map::unsetLanguage()
{
  mLanguage = SBGNML_LANGUAGE_INVALID;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the value of the "bbox" element of this Map.
 */
const BBox*
Map::getBBox() const
{
  return mBBox;
}


/*
 * Returns the value of the "bbox" element of this Map.
 */
BBox*
Map::getBBox()
{
  return mBBox;
}


/*
 * Predicate returning @c true if this Map's "bbox" element is set.
 */
bool
Map::isSetBBox() const
{
  return (mBBox != NULL);
}


/*
 * Sets the value of the "bbox" element of this Map.
 */
int
Map::setBBox(const BBox* bbox)
{
  if (mBBox == bbox)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (bbox == NULL)
  {
    delete mBBox;
    mBBox = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mBBox;
    mBBox = (bbox != NULL) ? bbox->clone() : NULL;
    if (mBBox != NULL)
    {
      mBBox->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new BBox object, adds it to this Map object and returns the BBox
 * object created.
 */
BBox*
Map::createBBox()
{
  if (mBBox != NULL)
  {
    delete mBBox;
  }

  mBBox = new BBox(getSbgnNamespaces());

  connectToChild();

  return mBBox;
}


/*
 * Unsets the value of the "bbox" element of this Map.
 */
int
Map::unsetBBox()
{
  delete mBBox;
  mBBox = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the SbgnListOfGlyphs from this Map.
 */
const SbgnListOfGlyphs*
Map::getListOfGlyphs() const
{
  return &mGlyphs;
}


/*
 * Returns the SbgnListOfGlyphs from this Map.
 */
SbgnListOfGlyphs*
Map::getListOfGlyphs()
{
  return &mGlyphs;
}


/*
 * Get a Glyph from the Map.
 */
Glyph*
Map::getGlyph(unsigned int n)
{
  return mGlyphs.get(n);
}


/*
 * Get a Glyph from the Map.
 */
const Glyph*
Map::getGlyph(unsigned int n) const
{
  return mGlyphs.get(n);
}


/*
 * Get a Glyph from the Map based on its identifier.
 */
Glyph*
Map::getGlyph(const std::string& sid)
{
  return mGlyphs.get(sid);
}


/*
 * Get a Glyph from the Map based on its identifier.
 */
const Glyph*
Map::getGlyph(const std::string& sid) const
{
  return mGlyphs.get(sid);
}


/*
 * Adds a copy of the given Glyph to this Map.
 */
int
Map::addGlyph(const Glyph* g)
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
 * Get the number of Glyph objects in this Map.
 */
unsigned int
Map::getNumGlyphs() const
{
  return mGlyphs.size();
}


/*
 * Creates a new Glyph object, adds it to this Map object and returns the Glyph
 * object created.
 */
Glyph*
Map::createGlyph()
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
 * Removes the nth Glyph from this Map and returns a pointer to it.
 */
Glyph*
Map::removeGlyph(unsigned int n)
{
  return mGlyphs.remove(n);
}


/*
 * Removes the Glyph from this Map based on its identifier and returns a
 * pointer to it.
 */
Glyph*
Map::removeGlyph(const std::string& sid)
{
  return mGlyphs.remove(sid);
}


/*
 * Returns the SbgnListOfArcs from this Map.
 */
const SbgnListOfArcs*
Map::getListOfArcs() const
{
  return &mArcs;
}


/*
 * Returns the SbgnListOfArcs from this Map.
 */
SbgnListOfArcs*
Map::getListOfArcs()
{
  return &mArcs;
}


/*
 * Get an Arc from the Map.
 */
Arc*
Map::getArc(unsigned int n)
{
  return mArcs.get(n);
}


/*
 * Get an Arc from the Map.
 */
const Arc*
Map::getArc(unsigned int n) const
{
  return mArcs.get(n);
}


/*
 * Get an Arc from the Map based on its identifier.
 */
Arc*
Map::getArc(const std::string& sid)
{
  return mArcs.get(sid);
}


/*
 * Get an Arc from the Map based on its identifier.
 */
const Arc*
Map::getArc(const std::string& sid) const
{
  return mArcs.get(sid);
}


/*
 * Adds a copy of the given Arc to this Map.
 */
int
Map::addArc(const Arc* a)
{
  if (a == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (a->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != a->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != a->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(a)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else if (a->isSetId() && (mArcs.get(a->getId())) != NULL)
  {
    return LIBSBGN_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mArcs.append(a);
  }
}


/*
 * Get the number of Arc objects in this Map.
 */
unsigned int
Map::getNumArcs() const
{
  return mArcs.size();
}


/*
 * Creates a new Arc object, adds it to this Map object and returns the Arc
 * object created.
 */
Arc*
Map::createArc()
{
  Arc* a = NULL;

  try
  {
    a = new Arc(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (a != NULL)
  {
    mArcs.appendAndOwn(a);
  }

  return a;
}


/*
 * Removes the nth Arc from this Map and returns a pointer to it.
 */
Arc*
Map::removeArc(unsigned int n)
{
  return mArcs.remove(n);
}


/*
 * Removes the Arc from this Map based on its identifier and returns a pointer
 * to it.
 */
Arc*
Map::removeArc(const std::string& sid)
{
  return mArcs.remove(sid);
}


/*
 * Returns the SbgnListOfArcGroups from this Map.
 */
const SbgnListOfArcGroups*
Map::getListOfArcGroups() const
{
  return &mArcGroups;
}


/*
 * Returns the SbgnListOfArcGroups from this Map.
 */
SbgnListOfArcGroups*
Map::getListOfArcGroups()
{
  return &mArcGroups;
}


/*
 * Get an ArcGroup from the Map.
 */
ArcGroup*
Map::getArcGroup(unsigned int n)
{
  return mArcGroups.get(n);
}


/*
 * Get an ArcGroup from the Map.
 */
const ArcGroup*
Map::getArcGroup(unsigned int n) const
{
  return mArcGroups.get(n);
}


/*
 * Adds a copy of the given ArcGroup to this Map.
 */
int
Map::addArcGroup(const ArcGroup* ag)
{
  if (ag == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (ag->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != ag->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != ag->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(ag)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return mArcGroups.append(ag);
  }
}


/*
 * Get the number of ArcGroup objects in this Map.
 */
unsigned int
Map::getNumArcGroups() const
{
  return mArcGroups.size();
}


/*
 * Creates a new ArcGroup object, adds it to this Map object and returns the
 * ArcGroup object created.
 */
ArcGroup*
Map::createArcGroup()
{
  ArcGroup* ag = NULL;

  try
  {
    ag = new ArcGroup(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (ag != NULL)
  {
    mArcGroups.appendAndOwn(ag);
  }

  return ag;
}


/*
 * Removes the nth ArcGroup from this Map and returns a pointer to it.
 */
ArcGroup*
Map::removeArcGroup(unsigned int n)
{
  return mArcGroups.remove(n);
}


/*
 * Returns the XML element name of this Map object.
 */
const std::string&
Map::getElementName() const
{
  static const string name = "map";
  return name;
}


/*
 * Returns the libSBGN type code for this Map object.
 */
int
Map::getTypeCode() const
{
  return SBGN_SBGNML_MAP;
}


/*
 * Predicate returning @c true if all the required attributes for this Map
 * object have been set.
 */
bool
Map::hasRequiredAttributes() const
{
  bool allPresent = SBase::hasRequiredAttributes();

  if (isSetLanguage() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this Map object
 * have been set.
 */
bool
Map::hasRequiredElements() const
{
  bool allPresent = SBase::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Write any contained elements
 */
void
Map::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeElements(stream);

  if (isSetBBox() == true)
  {
    mBBox->write(stream);
  }

  for (unsigned int i = 0; i < getNumGlyphs(); i++)
  {
    getGlyph(i)->write(stream);
  }

  for (unsigned int i = 0; i < getNumArcs(); i++)
  {
    getArc(i)->write(stream);
  }

  for (unsigned int i = 0; i < getNumArcGroups(); i++)
  {
    getArcGroup(i)->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
Map::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
Map::setSbgnDocument(SbgnDocument* d)
{
  SBase::setSbgnDocument(d);

  if (mBBox != NULL)
  {
    mBBox->setSbgnDocument(d);
  }

  mGlyphs.setSbgnDocument(d);

  mArcs.setSbgnDocument(d);

  mArcGroups.setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
Map::connectToChild()
{
  SBase::connectToChild();

  if (mBBox != NULL)
  {
    mBBox->connectToParent(this);
  }

  mGlyphs.connectToParent(this);

  mArcs.connectToParent(this);

  mArcGroups.connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Map.
 */
int
Map::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Map.
 */
int
Map::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Map.
 */
int
Map::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Map.
 */
int
Map::getAttribute(const std::string& attributeName, unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Map.
 */
int
Map::getAttribute(const std::string& attributeName, std::string& value) const
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
  else if (attributeName == "language")
  {
    value = getLanguageAsString();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this Map's attribute "attributeName" is set.
 */
bool
Map::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "language")
  {
    value = isSetLanguage();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Map.
 */
int
Map::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Map.
 */
int
Map::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Map.
 */
int
Map::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Map.
 */
int
Map::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Map.
 */
int
Map::setAttribute(const std::string& attributeName, const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "language")
  {
    return_value = setLanguage(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Map.
 */
int
Map::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "language")
  {
    value = unsetLanguage();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this Map.
 */
SbgnBase*
Map::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "bbox")
  {
    return createBBox();
  }
  else if (elementName == "glyph")
  {
    return createGlyph();
  }
  else if (elementName == "arc")
  {
    return createArc();
  }
  else if (elementName == "arcgroup")
  {
    return createArcGroup();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this Map.
 */
int
Map::addChildObject(const std::string& elementName, const SbgnBase* element)
{
  if (elementName == "bbox" && element->getTypeCode() == SBGN_SBGNML_BBOX)
  {
    return setBBox((const BBox*)(element));
  }
  else if (elementName == "glyph" && element->getTypeCode() ==
    SBGN_SBGNML_GLYPH)
  {
    return addGlyph((const Glyph*)(element));
  }
  else if (elementName == "arc" && element->getTypeCode() == SBGN_SBGNML_ARC)
  {
    return addArc((const Arc*)(element));
  }
  else if (elementName == "arcgroup" && element->getTypeCode() ==
    SBGN_SBGNML_ARCGROUP)
  {
    return addArcGroup((const ArcGroup*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Map.
 */
SbgnBase*
Map::removeChildObject(const std::string& elementName, const std::string& id)
{
  if (elementName == "bbox")
  {
    BBox * obj = getBBox();
    if (unsetBBox() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "glyph")
  {
    return removeGlyph(id);
  }
  else if (elementName == "arc")
  {
    return removeArc(id);
  }
  else if (elementName == "arcgroup")
  {
    for (unsigned int i = 0; i < getNumArcGroups(); i++)
    {
      if (getArcGroup(i)->getId() == id)
      {
        return removeArcGroup(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this Map.
 */
unsigned int
Map::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "bbox")
  {
    if (isSetBBox())
    {
      return 1;
    }
  }
  else if (elementName == "glyph")
  {
    return getNumGlyphs();
  }
  else if (elementName == "arc")
  {
    return getNumArcs();
  }
  else if (elementName == "arcgroup")
  {
    return getNumArcGroups();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this Map.
 */
SbgnBase*
Map::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "bbox")
  {
    return getBBox();
  }
  else if (elementName == "glyph")
  {
    return getGlyph(index);
  }
  else if (elementName == "arc")
  {
    return getArc(index);
  }
  else if (elementName == "arcgroup")
  {
    return getArcGroup(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
Map::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  if (mBBox != NULL)
  {
    if (mBBox->getId() == id)
    {
      return mBBox;
    }

    obj = mBBox->getElementBySId(id);
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

  if (mArcs.getId() == id)
  {
    return &mArcs;
  }

  obj = mArcs.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mArcGroups.getElementBySId(id);

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
Map::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SbgnBase* obj = SBase::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "bbox")
  {
    if (isSetBBox())
    {
      getErrorLog()->logError(SbgnmlMapAllowedElements, getLevel(),
        getVersion());
    }

    delete mBBox;
    mBBox = new BBox(getSbgnNamespaces());
    obj = mBBox;
  }
  else if (name == "glyph")
  {
    obj = mGlyphs.createObject(stream);
  }
  else if (name == "arc")
  {
    obj = mArcs.createObject(stream);
  }
  else if (name == "arcgroup")
  {
    obj = mArcGroups.createObject(stream);
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
Map::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes&
  attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("language");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Map::readAttributes(
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
        log->logError(SbgnmlMapAllowedAttributes, level, version, details);
      }
    }
  }

  // 
  // id ID (use = "optional" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<Map>");
    }
    else if (SyntaxChecker::isValidXMLID(mId) == false)
    {
      logError(SbgnmlMapIdMustBeID, level, version, "The attribute id='" + mId
        + "' does not conform to the syntax.");
    }
  }

  // 
  // language enum (use = "required" )
  // 

  std::string language;
  assigned = attributes.readInto("language", language);

  if (assigned == true)
  {
    if (language.empty() == true)
    {
      logEmptyString(language, level, version, "<Map>");
    }
    else
    {
      mLanguage = Language_fromString(language.c_str());

      if (Language_isValid(mLanguage) == 0)
      {
        std::string msg = "The language on the <Map> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + language + "', which is not a valid option.";

        log->logError(SbgnmlMapLanguageMustBeLanguageEnum, level, version,
          msg);
      }
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'language' is missing.";
    log->logError(SbgnmlMapAllowedAttributes, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
Map::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetLanguage() == true)
  {
    stream.writeAttribute("language", getPrefix(),
      Language_toString(mLanguage));
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Map_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
Map_t *
Map_create(unsigned int level, unsigned int version)
{
  return new Map(level, version);
}


/*
 * Creates and returns a deep copy of this Map_t object.
 */
LIBSBGN_EXTERN
Map_t*
Map_clone(const Map_t* m)
{
  if (m != NULL)
  {
    return static_cast<Map_t*>(m->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Map_t object.
 */
LIBSBGN_EXTERN
void
Map_free(Map_t* m)
{
  if (m != NULL)
  {
    delete m;
  }
}


/*
 * Returns the value of the "id" attribute of this Map_t.
 */
LIBSBGN_EXTERN
char *
Map_getId(const Map_t * m)
{
  if (m == NULL)
  {
    return NULL;
  }

  return m->getId().empty() ? NULL : safe_strdup(m->getId().c_str());
}


/*
 * Returns the value of the "language" attribute of this Map_t.
 */
LIBSBGN_EXTERN
Language_t
Map_getLanguage(const Map_t * m)
{
  if (m == NULL)
  {
    return SBGNML_LANGUAGE_INVALID;
  }

  return m->getLanguage();
}


/*
 * Returns the value of the "language" attribute of this Map_t.
 */
LIBSBGN_EXTERN
char *
Map_getLanguageAsString(const Map_t * m)
{
  return (char*)(Language_toString(m->getLanguage()));
}


/*
 * Predicate returning @c 1 (true) if this Map_t's "id" attribute is set.
 */
LIBSBGN_EXTERN
int
Map_isSetId(const Map_t * m)
{
  return (m != NULL) ? static_cast<int>(m->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Map_t's "language" attribute is set.
 */
LIBSBGN_EXTERN
int
Map_isSetLanguage(const Map_t * m)
{
  return (m != NULL) ? static_cast<int>(m->isSetLanguage()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Map_t.
 */
LIBSBGN_EXTERN
int
Map_setId(Map_t * m, const char * id)
{
  return (m != NULL) ? m->setId(id) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "language" attribute of this Map_t.
 */
LIBSBGN_EXTERN
int
Map_setLanguage(Map_t * m, Language_t language)
{
  return (m != NULL) ? m->setLanguage(language) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "language" attribute of this Map_t.
 */
LIBSBGN_EXTERN
int
Map_setLanguageAsString(Map_t * m, const char * language)
{
  return (m != NULL) ? m->setLanguage(language): LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Map_t.
 */
LIBSBGN_EXTERN
int
Map_unsetId(Map_t * m)
{
  return (m != NULL) ? m->unsetId() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "language" attribute of this Map_t.
 */
LIBSBGN_EXTERN
int
Map_unsetLanguage(Map_t * m)
{
  return (m != NULL) ? m->unsetLanguage() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns the value of the "bbox" element of this Map_t.
 */
LIBSBGN_EXTERN
const BBox_t*
Map_getBBox(const Map_t * m)
{
  if (m == NULL)
  {
    return NULL;
  }

  return (BBox_t*)(m->getBBox());
}


/*
 * Predicate returning @c 1 (true) if this Map_t's "bbox" element is set.
 */
LIBSBGN_EXTERN
int
Map_isSetBBox(const Map_t * m)
{
  return (m != NULL) ? static_cast<int>(m->isSetBBox()) : 0;
}


/*
 * Sets the value of the "bbox" element of this Map_t.
 */
LIBSBGN_EXTERN
int
Map_setBBox(Map_t * m, const BBox_t* bbox)
{
  return (m != NULL) ? m->setBBox(bbox) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Creates a new BBox_t object, adds it to this Map_t object and returns the
 * BBox_t object created.
 */
LIBSBGN_EXTERN
BBox_t*
Map_createBBox(Map_t* m)
{
  if (m == NULL)
  {
    return NULL;
  }

  return (BBox_t*)(m->createBBox());
}


/*
 * Unsets the value of the "bbox" element of this Map_t.
 */
LIBSBGN_EXTERN
int
Map_unsetBBox(Map_t * m)
{
  return (m != NULL) ? m->unsetBBox() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing Glyph_t objects from this Map_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Map_getListOfGlyphs(Map_t* m)
{
  return (m != NULL) ? m->getListOfGlyphs() : NULL;
}


/*
 * Get a Glyph_t from the Map_t.
 */
LIBSBGN_EXTERN
Glyph_t*
Map_getGlyph(Map_t* m, unsigned int n)
{
  return (m != NULL) ? m->getGlyph(n) : NULL;
}


/*
 * Get a Glyph_t from the Map_t based on its identifier.
 */
LIBSBGN_EXTERN
Glyph_t*
Map_getGlyphById(Map_t* m, const char *sid)
{
  return (m != NULL && sid != NULL) ? m->getGlyph(sid) : NULL;
}


/*
 * Adds a copy of the given Glyph_t to this Map_t.
 */
LIBSBGN_EXTERN
int
Map_addGlyph(Map_t* m, const Glyph_t* g)
{
  return (m != NULL) ? m->addGlyph(g) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of Glyph_t objects in this Map_t.
 */
LIBSBGN_EXTERN
unsigned int
Map_getNumGlyphs(Map_t* m)
{
  return (m != NULL) ? m->getNumGlyphs() : SBGN_INT_MAX;
}


/*
 * Creates a new Glyph_t object, adds it to this Map_t object and returns the
 * Glyph_t object created.
 */
LIBSBGN_EXTERN
Glyph_t*
Map_createGlyph(Map_t* m)
{
  return (m != NULL) ? m->createGlyph() : NULL;
}


/*
 * Removes the nth Glyph_t from this Map_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
Glyph_t*
Map_removeGlyph(Map_t* m, unsigned int n)
{
  return (m != NULL) ? m->removeGlyph(n) : NULL;
}


/*
 * Removes the Glyph_t from this Map_t based on its identifier and returns a
 * pointer to it.
 */
LIBSBGN_EXTERN
Glyph_t*
Map_removeGlyphById(Map_t* m, const char* sid)
{
  return (m != NULL && sid != NULL) ? m->removeGlyph(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing Arc_t objects from this Map_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Map_getListOfArcs(Map_t* m)
{
  return (m != NULL) ? m->getListOfArcs() : NULL;
}


/*
 * Get an Arc_t from the Map_t.
 */
LIBSBGN_EXTERN
Arc_t*
Map_getArc(Map_t* m, unsigned int n)
{
  return (m != NULL) ? m->getArc(n) : NULL;
}


/*
 * Get an Arc_t from the Map_t based on its identifier.
 */
LIBSBGN_EXTERN
Arc_t*
Map_getArcById(Map_t* m, const char *sid)
{
  return (m != NULL && sid != NULL) ? m->getArc(sid) : NULL;
}


/*
 * Adds a copy of the given Arc_t to this Map_t.
 */
LIBSBGN_EXTERN
int
Map_addArc(Map_t* m, const Arc_t* a)
{
  return (m != NULL) ? m->addArc(a) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of Arc_t objects in this Map_t.
 */
LIBSBGN_EXTERN
unsigned int
Map_getNumArcs(Map_t* m)
{
  return (m != NULL) ? m->getNumArcs() : SBGN_INT_MAX;
}


/*
 * Creates a new Arc_t object, adds it to this Map_t object and returns the
 * Arc_t object created.
 */
LIBSBGN_EXTERN
Arc_t*
Map_createArc(Map_t* m)
{
  return (m != NULL) ? m->createArc() : NULL;
}


/*
 * Removes the nth Arc_t from this Map_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
Arc_t*
Map_removeArc(Map_t* m, unsigned int n)
{
  return (m != NULL) ? m->removeArc(n) : NULL;
}


/*
 * Removes the Arc_t from this Map_t based on its identifier and returns a
 * pointer to it.
 */
LIBSBGN_EXTERN
Arc_t*
Map_removeArcById(Map_t* m, const char* sid)
{
  return (m != NULL && sid != NULL) ? m->removeArc(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing ArcGroup_t objects from this Map_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Map_getListOfArcGroups(Map_t* m)
{
  return (m != NULL) ? m->getListOfArcGroups() : NULL;
}


/*
 * Get an ArcGroup_t from the Map_t.
 */
LIBSBGN_EXTERN
ArcGroup_t*
Map_getArcGroup(Map_t* m, unsigned int n)
{
  return (m != NULL) ? m->getArcGroup(n) : NULL;
}


/*
 * Adds a copy of the given ArcGroup_t to this Map_t.
 */
LIBSBGN_EXTERN
int
Map_addArcGroup(Map_t* m, const ArcGroup_t* ag)
{
  return (m != NULL) ? m->addArcGroup(ag) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of ArcGroup_t objects in this Map_t.
 */
LIBSBGN_EXTERN
unsigned int
Map_getNumArcGroups(Map_t* m)
{
  return (m != NULL) ? m->getNumArcGroups() : SBGN_INT_MAX;
}


/*
 * Creates a new ArcGroup_t object, adds it to this Map_t object and returns
 * the ArcGroup_t object created.
 */
LIBSBGN_EXTERN
ArcGroup_t*
Map_createArcGroup(Map_t* m)
{
  return (m != NULL) ? m->createArcGroup() : NULL;
}


/*
 * Removes the nth ArcGroup_t from this Map_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
ArcGroup_t*
Map_removeArcGroup(Map_t* m, unsigned int n)
{
  return (m != NULL) ? m->removeArcGroup(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Map_t object have been set.
 */
LIBSBGN_EXTERN
int
Map_hasRequiredAttributes(const Map_t * m)
{
  return (m != NULL) ? static_cast<int>(m->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this Map_t
 * object have been set.
 */
LIBSBGN_EXTERN
int
Map_hasRequiredElements(const Map_t * m)
{
  return (m != NULL) ? static_cast<int>(m->hasRequiredElements()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END


