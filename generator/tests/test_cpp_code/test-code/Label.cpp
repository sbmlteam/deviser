/**
 * @file Label.cpp
 * @brief Implementation of the Label class.
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
#include <sbgn/Label.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Label using the given SBGN Level and @ p version values.
 */
Label::Label(unsigned int level, unsigned int version)
  : SBase(level, version)
  , mText ("")
  , mBBox (NULL)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new Label using the given SbgnNamespaces object @p sbgnns.
 */
Label::Label(SbgnNamespaces *sbgnns)
  : SBase(sbgnns)
  , mText ("")
  , mBBox (NULL)
{
  setElementNamespace(sbgnns->getURI());
  connectToChild();
}


/*
 * Copy constructor for Label.
 */
Label::Label(const Label& orig)
  : SBase( orig )
  , mText ( orig.mText )
  , mBBox ( NULL )
{
  if (orig.mBBox != NULL)
  {
    mBBox = orig.mBBox->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Label.
 */
Label&
Label::operator=(const Label& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mText = rhs.mText;
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
 * Creates and returns a deep copy of this Label object.
 */
Label*
Label::clone() const
{
  return new Label(*this);
}


/*
 * Destructor for Label.
 */
Label::~Label()
{
  delete mBBox;
  mBBox = NULL;
}


/*
 * Returns the value of the "id" attribute of this Label.
 */
const std::string&
Label::getId() const
{
  return mId;
}


/*
 * Returns the value of the "text" attribute of this Label.
 */
const std::string&
Label::getText() const
{
  return mText;
}


/*
 * Predicate returning @c true if this Label's "id" attribute is set.
 */
bool
Label::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this Label's "text" attribute is set.
 */
bool
Label::isSetText() const
{
  return (mText.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this Label.
 */
int
Label::setId(const std::string& id)
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
 * Sets the value of the "text" attribute of this Label.
 */
int
Label::setText(const std::string& text)
{
  mText = text;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this Label.
 */
int
Label::unsetId()
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
 * Unsets the value of the "text" attribute of this Label.
 */
int
Label::unsetText()
{
  mText.erase();

  if (mText.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "bbox" element of this Label.
 */
const BBox*
Label::getBBox() const
{
  return mBBox;
}


/*
 * Returns the value of the "bbox" element of this Label.
 */
BBox*
Label::getBBox()
{
  return mBBox;
}


/*
 * Predicate returning @c true if this Label's "bbox" element is set.
 */
bool
Label::isSetBBox() const
{
  return (mBBox != NULL);
}


/*
 * Sets the value of the "bbox" element of this Label.
 */
int
Label::setBBox(const BBox* bbox)
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
 * Creates a new BBox object, adds it to this Label object and returns the BBox
 * object created.
 */
BBox*
Label::createBBox()
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
 * Unsets the value of the "bbox" element of this Label.
 */
int
Label::unsetBBox()
{
  delete mBBox;
  mBBox = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this Label object.
 */
const std::string&
Label::getElementName() const
{
  static const string name = "label";
  return name;
}


/*
 * Returns the libSBGN type code for this Label object.
 */
int
Label::getTypeCode() const
{
  return SBGN_SBGNML_LABEL;
}


/*
 * Predicate returning @c true if all the required attributes for this Label
 * object have been set.
 */
bool
Label::hasRequiredAttributes() const
{
  bool allPresent = SBase::hasRequiredAttributes();

  if (isSetText() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this Label
 * object have been set.
 */
bool
Label::hasRequiredElements() const
{
  bool allPresent = SBase::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Write any contained elements
 */
void
Label::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeElements(stream);

  if (isSetBBox() == true)
  {
    mBBox->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
Label::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
Label::setSbgnDocument(SbgnDocument* d)
{
  SBase::setSbgnDocument(d);

  if (mBBox != NULL)
  {
    mBBox->setSbgnDocument(d);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
Label::connectToChild()
{
  SBase::connectToChild();

  if (mBBox != NULL)
  {
    mBBox->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Label.
 */
int
Label::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Label.
 */
int
Label::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Label.
 */
int
Label::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Label.
 */
int
Label::getAttribute(const std::string& attributeName,
                    unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this Label.
 */
int
Label::getAttribute(const std::string& attributeName,
                    std::string& value) const
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
  else if (attributeName == "text")
  {
    value = getText();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this Label's attribute "attributeName" is
 * set.
 */
bool
Label::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "text")
  {
    value = isSetText();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Label.
 */
int
Label::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Label.
 */
int
Label::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Label.
 */
int
Label::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Label.
 */
int
Label::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this Label.
 */
int
Label::setAttribute(const std::string& attributeName,
                    const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "text")
  {
    return_value = setText(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Label.
 */
int
Label::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "text")
  {
    value = unsetText();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this Label.
 */
SbgnBase*
Label::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "bbox")
  {
    return createBBox();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this Label.
 */
int
Label::addChildObject(const std::string& elementName, const SbgnBase* element)
{
  if (elementName == "bbox" && element->getTypeCode() == SBGN_SBGNML_BBOX)
  {
    return setBBox((const BBox*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Label.
 */
SbgnBase*
Label::removeChildObject(const std::string& elementName,
                         const std::string& id)
{
  if (elementName == "bbox")
  {
    BBox * obj = getBBox();
    if (unsetBBox() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this Label.
 */
unsigned int
Label::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "bbox")
  {
    if (isSetBBox())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this Label.
 */
SbgnBase*
Label::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "bbox")
  {
    return getBBox();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
Label::getElementBySId(const std::string& id)
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

  return obj;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SbgnBase*
Label::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SbgnBase* obj = SBase::createObject(stream);

  const std::string& name = stream.peek().getName();

  if (name == "bbox")
  {
    if (isSetBBox())
    {
      getErrorLog()->logError(SbgnmlLabelAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    delete mBBox;
    mBBox = new BBox(getSbgnNamespaces());
    obj = mBBox;
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
Label::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("text");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Label::readAttributes(
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
        log->logError(SbgnmlLabelAllowedAttributes, level, version, details,
          getLine(), getColumn());
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
      logEmptyString(mId, level, version, "<Label>");
    }
    else if (SyntaxChecker::isValidXMLID(mId) == false)
    {
      logError(SbgnmlLabelIdMustBeID, level, version, "The attribute id='" +
        mId + "' does not conform to the syntax.", getLine(), getColumn());
    }
  }

  // 
  // text string (use = "required" )
  // 

  assigned = attributes.readInto("text", mText);

  if (assigned == true)
  {
    if (mText.empty() == true)
    {
      logEmptyString(mText, level, version, "<Label>");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'text' is missing from the <Label> "
      "element.";
    log->logError(SbgnmlLabelAllowedAttributes, level, version, message,
      getLine(), getColumn());
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
Label::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetText() == true)
  {
    stream.writeAttribute("text", getPrefix(), mText);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Label_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
Label_t *
Label_create(unsigned int level, unsigned int version)
{
  return new Label(level, version);
}


/*
 * Creates and returns a deep copy of this Label_t object.
 */
LIBSBGN_EXTERN
Label_t*
Label_clone(const Label_t* l)
{
  if (l != NULL)
  {
    return static_cast<Label_t*>(l->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Label_t object.
 */
LIBSBGN_EXTERN
void
Label_free(Label_t* l)
{
  if (l != NULL)
  {
    delete l;
  }
}


/*
 * Returns the value of the "id" attribute of this Label_t.
 */
LIBSBGN_EXTERN
char *
Label_getId(const Label_t * l)
{
  if (l == NULL)
  {
    return NULL;
  }

  return l->getId().empty() ? NULL : safe_strdup(l->getId().c_str());
}


/*
 * Returns the value of the "text" attribute of this Label_t.
 */
LIBSBGN_EXTERN
char *
Label_getText(const Label_t * l)
{
  if (l == NULL)
  {
    return NULL;
  }

  return l->getText().empty() ? NULL : safe_strdup(l->getText().c_str());
}


/*
 * Predicate returning @c 1 (true) if this Label_t's "id" attribute is set.
 */
LIBSBGN_EXTERN
int
Label_isSetId(const Label_t * l)
{
  return (l != NULL) ? static_cast<int>(l->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Label_t's "text" attribute is set.
 */
LIBSBGN_EXTERN
int
Label_isSetText(const Label_t * l)
{
  return (l != NULL) ? static_cast<int>(l->isSetText()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Label_t.
 */
LIBSBGN_EXTERN
int
Label_setId(Label_t * l, const char * id)
{
  return (l != NULL) ? l->setId(id) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "text" attribute of this Label_t.
 */
LIBSBGN_EXTERN
int
Label_setText(Label_t * l, const char * text)
{
  return (l != NULL) ? l->setText(text) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Label_t.
 */
LIBSBGN_EXTERN
int
Label_unsetId(Label_t * l)
{
  return (l != NULL) ? l->unsetId() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "text" attribute of this Label_t.
 */
LIBSBGN_EXTERN
int
Label_unsetText(Label_t * l)
{
  return (l != NULL) ? l->unsetText() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns the value of the "bbox" element of this Label_t.
 */
LIBSBGN_EXTERN
const BBox_t*
Label_getBBox(const Label_t * l)
{
  if (l == NULL)
  {
    return NULL;
  }

  return (BBox_t*)(l->getBBox());
}


/*
 * Predicate returning @c 1 (true) if this Label_t's "bbox" element is set.
 */
LIBSBGN_EXTERN
int
Label_isSetBBox(const Label_t * l)
{
  return (l != NULL) ? static_cast<int>(l->isSetBBox()) : 0;
}


/*
 * Sets the value of the "bbox" element of this Label_t.
 */
LIBSBGN_EXTERN
int
Label_setBBox(Label_t * l, const BBox_t* bbox)
{
  return (l != NULL) ? l->setBBox(bbox) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Creates a new BBox_t object, adds it to this Label_t object and returns the
 * BBox_t object created.
 */
LIBSBGN_EXTERN
BBox_t*
Label_createBBox(Label_t* l)
{
  if (l == NULL)
  {
    return NULL;
  }

  return (BBox_t*)(l->createBBox());
}


/*
 * Unsets the value of the "bbox" element of this Label_t.
 */
LIBSBGN_EXTERN
int
Label_unsetBBox(Label_t * l)
{
  return (l != NULL) ? l->unsetBBox() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Label_t object have been set.
 */
LIBSBGN_EXTERN
int
Label_hasRequiredAttributes(const Label_t * l)
{
  return (l != NULL) ? static_cast<int>(l->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * Label_t object have been set.
 */
LIBSBGN_EXTERN
int
Label_hasRequiredElements(const Label_t * l)
{
  return (l != NULL) ? static_cast<int>(l->hasRequiredElements()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END


