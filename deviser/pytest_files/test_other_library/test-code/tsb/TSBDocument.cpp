/**
 * @file TSBDocument.cpp
 * @brief Implementation of the TSBDocument class.
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
#include <tsb/TSBDocument.h>
#include <xml/XMLInputStream.h>


using namespace std;



LIBTSB_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new TSBDocument using the given TSB Level and @ p version values.
 */
TSBDocument::TSBDocument(unsigned int level, unsigned int version)
  : TSBBase(level, version)
  , mLevel (TSB_INT_MAX)
  , mIsSetLevel (false)
  , mVersion (TSB_INT_MAX)
  , mIsSetVersion (false)
  , mComments (level, version)
{
  setTSBNamespacesAndOwn(new TSBNamespaces(level, version));
  setLevel(level);
  setVersion(version);
  setTSBDocument(this);
  connectToChild();
}


/*
 * Creates a new TSBDocument using the given TSBNamespaces object @p tsbns.
 */
TSBDocument::TSBDocument(TSBNamespaces *tsbns)
  : TSBBase(tsbns)
  , mLevel (TSB_INT_MAX)
  , mIsSetLevel (false)
  , mVersion (TSB_INT_MAX)
  , mIsSetVersion (false)
  , mComments (tsbns)
{
  setElementNamespace(tsbns->getURI());
  setLevel(tsbns->getLevel());
  setVersion(tsbns->getVersion());
  setTSBDocument(this);
  connectToChild();
}


/*
 * Copy constructor for TSBDocument.
 */
TSBDocument::TSBDocument(const TSBDocument& orig)
  : TSBBase( orig )
  , mLevel ( orig.mLevel )
  , mIsSetLevel ( orig.mIsSetLevel )
  , mVersion ( orig.mVersion )
  , mIsSetVersion ( orig.mIsSetVersion )
  , mComments ( orig.mComments )
{
  setTSBDocument(this);

  connectToChild();
}


/*
 * Assignment operator for TSBDocument.
 */
TSBDocument&
TSBDocument::operator=(const TSBDocument& rhs)
{
  if (&rhs != this)
  {
    TSBBase::operator=(rhs);
    mLevel = rhs.mLevel;
    mIsSetLevel = rhs.mIsSetLevel;
    mVersion = rhs.mVersion;
    mIsSetVersion = rhs.mIsSetVersion;
    mComments = rhs.mComments;
    connectToChild();
    setTSBDocument(this);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this TSBDocument object.
 */
TSBDocument*
TSBDocument::clone() const
{
  return new TSBDocument(*this);
}


/*
 * Destructor for TSBDocument.
 */
TSBDocument::~TSBDocument()
{
}


/*
 * Returns the value of the "level" attribute of this TSBDocument.
 */
unsigned int
TSBDocument::getLevel() const
{
  return mLevel;
}


/*
 * Returns the value of the "version" attribute of this TSBDocument.
 */
unsigned int
TSBDocument::getVersion() const
{
  return mVersion;
}


/*
 * Predicate returning @c true if this TSBDocument's "level" attribute is set.
 */
bool
TSBDocument::isSetLevel() const
{
  return mIsSetLevel;
}


/*
 * Predicate returning @c true if this TSBDocument's "version" attribute is
 * set.
 */
bool
TSBDocument::isSetVersion() const
{
  return mIsSetVersion;
}


/*
 * Sets the value of the "level" attribute of this TSBDocument.
 */
int
TSBDocument::setLevel(unsigned int level)
{
  mLevel = level;
  mIsSetLevel = true;

  if (mIsSetVersion)
  {
    setTSBNamespacesAndOwn(new TSBNamespaces(level, mVersion));
  }

  return LIBTSB_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "version" attribute of this TSBDocument.
 */
int
TSBDocument::setVersion(unsigned int version)
{
  mVersion = version;
  mIsSetVersion = true;

  if (mIsSetLevel)
  {
    setTSBNamespacesAndOwn(new TSBNamespaces(mLevel, version));
  }

  return LIBTSB_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "level" attribute of this TSBDocument.
 */
int
TSBDocument::unsetLevel()
{
  mLevel = TSB_INT_MAX;
  mIsSetLevel = false;

  if (isSetLevel() == false)
  {
    return LIBTSB_OPERATION_SUCCESS;
  }
  else
  {
    return LIBTSB_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "version" attribute of this TSBDocument.
 */
int
TSBDocument::unsetVersion()
{
  mVersion = TSB_INT_MAX;
  mIsSetVersion = false;

  if (isSetVersion() == false)
  {
    return LIBTSB_OPERATION_SUCCESS;
  }
  else
  {
    return LIBTSB_OPERATION_FAILED;
  }
}


/*
 * Returns the TSBListOfComments from this TSBDocument.
 */
const TSBListOfComments*
TSBDocument::getListOfComments() const
{
  return &mComments;
}


/*
 * Returns the TSBListOfComments from this TSBDocument.
 */
TSBListOfComments*
TSBDocument::getListOfComments()
{
  return &mComments;
}


/*
 * Get a TSBComment from the TSBDocument.
 */
TSBComment*
TSBDocument::getComment(unsigned int n)
{
  return mComments.get(n);
}


/*
 * Get a TSBComment from the TSBDocument.
 */
const TSBComment*
TSBDocument::getComment(unsigned int n) const
{
  return mComments.get(n);
}


/*
 * Adds a copy of the given TSBComment to this TSBDocument.
 */
int
TSBDocument::addComment(const TSBComment* tsbc)
{
  if (tsbc == NULL)
  {
    return LIBTSB_OPERATION_FAILED;
  }
  else if (tsbc->hasRequiredAttributes() == false)
  {
    return LIBTSB_INVALID_OBJECT;
  }
  else if (getLevel() != tsbc->getLevel())
  {
    return LIBTSB_LEVEL_MISMATCH;
  }
  else if (getVersion() != tsbc->getVersion())
  {
    return LIBTSB_VERSION_MISMATCH;
  }
  else if (matchesRequiredTSBNamespacesForAddition(static_cast<const
    TSBBase*>(tsbc)) == false)
  {
    return LIBTSB_NAMESPACES_MISMATCH;
  }
  else
  {
    return mComments.append(tsbc);
  }
}


/*
 * Get the number of TSBComment objects in this TSBDocument.
 */
unsigned int
TSBDocument::getNumComments() const
{
  return mComments.size();
}


/*
 * Creates a new TSBComment object, adds it to this TSBDocument object and
 * returns the TSBComment object created.
 */
TSBComment*
TSBDocument::createComment()
{
  TSBComment* tsbc = NULL;

  try
  {
    tsbc = new TSBComment(getTSBNamespaces());
  }
  catch (...)
  {
  }

  if (tsbc != NULL)
  {
    mComments.appendAndOwn(tsbc);
  }

  return tsbc;
}


/*
 * Removes the nth TSBComment from this TSBDocument and returns a pointer to
 * it.
 */
TSBComment*
TSBDocument::removeComment(unsigned int n)
{
  return mComments.remove(n);
}


/*
 * Returns the XML element name of this TSBDocument object.
 */
const std::string&
TSBDocument::getElementName() const
{
  static const string name = "tsb";
  return name;
}


/*
 * Returns the libTSB type code for this TSBDocument object.
 */
int
TSBDocument::getTypeCode() const
{
  return TSB_DOCUMENT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * TSBDocument object have been set.
 */
bool
TSBDocument::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetLevel() == false)
  {
    allPresent = false;
  }

  if (isSetVersion() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenlibTSBInternal */

/*
 * Write any contained elements
 */
void
TSBDocument::writeElements( XMLOutputStream&
  stream) const
{
  TSBBase::writeElements(stream);

  if (getNumComments() > 0)
  {
    mComments.write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Accepts the given TSBVisitor
 */
bool
TSBDocument::accept(TSBVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the parent TSBDocument
 */
void
TSBDocument::setTSBDocument(TSBDocument* d)
{
  TSBBase::setTSBDocument(d);

  mComments.setTSBDocument(d);
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Connects to child elements
 */
void
TSBDocument::connectToChild()
{
  TSBBase::connectToChild();

  mComments.connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  if (return_value == LIBTSB_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "level")
  {
    value = getLevel();
    return_value = LIBTSB_OPERATION_SUCCESS;
  }
  else if (attributeName == "version")
  {
    value = getVersion();
    return_value = LIBTSB_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::getAttribute(const std::string& attributeName,
                          std::string& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Predicate returning @c true if this TSBDocument's attribute "attributeName"
 * is set.
 */
bool
TSBDocument::isSetAttribute(const std::string& attributeName) const
{
  bool value = TSBBase::isSetAttribute(attributeName);

  if (attributeName == "level")
  {
    value = isSetLevel();
  }
  else if (attributeName == "version")
  {
    value = isSetVersion();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::setAttribute(const std::string& attributeName, int value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::setAttribute(const std::string& attributeName, double value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  if (attributeName == "level")
  {
    return_value = setLevel(value);
  }
  else if (attributeName == "version")
  {
    return_value = setVersion(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Unsets the value of the "attributeName" attribute of this TSBDocument.
 */
int
TSBDocument::unsetAttribute(const std::string& attributeName)
{
  int value = TSBBase::unsetAttribute(attributeName);

  if (attributeName == "level")
  {
    value = unsetLevel();
  }
  else if (attributeName == "version")
  {
    value = unsetVersion();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Creates and returns an new "elementName" object in this TSBDocument.
 */
TSBBase*
TSBDocument::createChildObject(const std::string& elementName)
{
  TSBBase* obj = NULL;

  if (elementName == "comment")
  {
    return createComment();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Adds a new "elementName" object to this TSBDocument.
 */
int
TSBDocument::addChildObject(const std::string& elementName,
                            const TSBBase* element)
{
  if (elementName == "comment" && element->getTypeCode() == TSB_COMMENT)
  {
    return addComment((const TSBComment*)(element));
  }

  return LIBTSB_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * TSBDocument.
 */
TSBBase*
TSBDocument::removeChildObject(const std::string& elementName,
                               const std::string& id)
{
  if (elementName == "comment")
  {
    for (unsigned int i = 0; i < getNumComments(); i++)
    {
      if (getComment(i)->getId() == id)
      {
        return removeComment(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Returns the number of "elementName" in this TSBDocument.
 */
unsigned int
TSBDocument::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "comment")
  {
    return getNumComments();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Returns the nth object of "objectName" in this TSBDocument.
 */
TSBBase*
TSBDocument::getObject(const std::string& elementName, unsigned int index)
{
  TSBBase* obj = NULL;

  if (elementName == "comment")
  {
    return getComment(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
TSBBase*
TSBDocument::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  TSBBase* obj = NULL;

  obj = mComments.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns the value of the "Namespaces" element of this TSBDocument.
 */
const  XMLNamespaces*
TSBDocument::getNamespaces() const
{
  return mTSBNamespaces->getNamespaces();
}


/*
 * Returns the value of the "Namespaces" element of this TSBDocument.
 */
 XMLNamespaces*
TSBDocument::getNamespaces()
{
  return mTSBNamespaces->getNamespaces();
}


/*
 * Returns the value of the "TSBErrorLog" element of this TSBDocument.
 */
const TSBErrorLog*
TSBDocument::getErrorLog() const
{
  return &mErrorLog;
}


/*
 * Returns the value of the "TSBErrorLog" element of this TSBDocument.
 */
TSBErrorLog*
TSBDocument::getErrorLog()
{
  return &mErrorLog;
}


/*
 * Get a TSBError from the TSBDocument.
 */
TSBError*
TSBDocument::getError(unsigned int n)
{
  return const_cast<TSBError*>(mErrorLog.getError(n));
}


/*
 * Get a TSBError from the TSBDocument.
 */
const TSBError*
TSBDocument::getError(unsigned int n) const
{
  return mErrorLog.getError(n);
}


/*
 * Get the number of TSBError objects in this TSBDocument.
 */
unsigned int
TSBDocument::getNumErrors() const
{
  return mErrorLog.getNumErrors();
}


/*
 * Get the number of TSBError objects in this TSBDocument with the given
 * severity.
 */
unsigned int
TSBDocument::getNumErrors(unsigned int severity) const
{
  return getErrorLog()->getNumFailsWithSeverity(severity);
}



/** @cond doxygenlibTSBInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
TSBBase*
TSBDocument::createObject( XMLInputStream&
  stream)
{
  TSBBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfComments")
  {
    if (getErrorLog() && mComments.size() != 0)
    {
      getErrorLog()->logError(TsbDocumentAllowedElements, getLevel(),
        getVersion(), "", getLine(), getColumn());
    }

    obj = &mComments;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Adds the expected attributes for this element
 */
void
TSBDocument::addExpectedAttributes(
  ExpectedAttributes& attributes)
{
  TSBBase::addExpectedAttributes(attributes);

  attributes.add("level");

  attributes.add("version");
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
TSBDocument::readAttributes(
                            const 
                              XMLAttributes& attributes,
                            const 
                              ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  TSBErrorLog* log = getErrorLog();

  TSBBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == TSBUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(TSBUnknownCoreAttribute);
        log->logError(TsbDocumentAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // level uint (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetLevel = attributes.readInto("level", mLevel);

  if ( mIsSetLevel == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Tsb attribute 'level' from the <TSBDocument> "
        "element must be an integer.";
      log->logError(TsbDocumentLevelMustBeNonNegativeInteger, level, version,
        message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Tsb attribute 'level' is missing from the "
        "<TSBDocument> element.";
      log->logError(TsbDocumentAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // version uint (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetVersion = attributes.readInto("version", mVersion);

  if ( mIsSetVersion == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Tsb attribute 'version' from the <TSBDocument> "
        "element must be an integer.";
      log->logError(TsbDocumentVersionMustBeNonNegativeInteger, level, version,
        message, getLine(), getColumn());
    }
    else
    {
      std::string message = "Tsb attribute 'version' is missing from the "
        "<TSBDocument> element.";
      log->logError(TsbDocumentAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Writes the attributes to the stream
 */
void
TSBDocument::writeAttributes( XMLOutputStream&
  stream) const
{
  TSBBase::writeAttributes(stream);

  if (isSetLevel() == true)
  {
    stream.writeAttribute("level", getPrefix(), mLevel);
  }

  if (isSetVersion() == true)
  {
    stream.writeAttribute("version", getPrefix(), mVersion);
  }
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Writes the namespace for the Tsb package
 */
void
TSBDocument::writeXMLNS( XMLOutputStream&
  stream) const
{
   XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    const  XMLNamespaces* thisxmlns =
      getNamespaces();
    if (thisxmlns && thisxmlns->hasURI(TSB_XMLNS_L1V1))
    {
      xmlns.add(TSB_XMLNS_L1V1, prefix);
    }
  }

  stream << xmlns;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new TSBDocument_t using the given TSB Level and @ p version
 * values.
 */
LIBTSB_EXTERN
TSBDocument_t *
TSBDocument_create(unsigned int level, unsigned int version)
{
  return new TSBDocument(level, version);
}


/*
 * Creates and returns a deep copy of this TSBDocument_t object.
 */
LIBTSB_EXTERN
TSBDocument_t*
TSBDocument_clone(const TSBDocument_t* tsbd)
{
  if (tsbd != NULL)
  {
    return static_cast<TSBDocument_t*>(tsbd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this TSBDocument_t object.
 */
LIBTSB_EXTERN
void
TSBDocument_free(TSBDocument_t* tsbd)
{
  if (tsbd != NULL)
  {
    delete tsbd;
  }
}


/*
 * Returns the value of the "level" attribute of this TSBDocument_t.
 */
LIBTSB_EXTERN
unsigned int
TSBDocument_getLevel(const TSBDocument_t * tsbd)
{
  return (tsbd != NULL) ? tsbd->getLevel() : TSB_INT_MAX;
}


/*
 * Returns the value of the "version" attribute of this TSBDocument_t.
 */
LIBTSB_EXTERN
unsigned int
TSBDocument_getVersion(const TSBDocument_t * tsbd)
{
  return (tsbd != NULL) ? tsbd->getVersion() : TSB_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this TSBDocument_t's "level" attribute is
 * set.
 */
LIBTSB_EXTERN
int
TSBDocument_isSetLevel(const TSBDocument_t * tsbd)
{
  return (tsbd != NULL) ? static_cast<int>(tsbd->isSetLevel()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this TSBDocument_t's "version" attribute
 * is set.
 */
LIBTSB_EXTERN
int
TSBDocument_isSetVersion(const TSBDocument_t * tsbd)
{
  return (tsbd != NULL) ? static_cast<int>(tsbd->isSetVersion()) : 0;
}


/*
 * Sets the value of the "level" attribute of this TSBDocument_t.
 */
LIBTSB_EXTERN
int
TSBDocument_setLevel(TSBDocument_t * tsbd, unsigned int level)
{
  return (tsbd != NULL) ? tsbd->setLevel(level) : LIBTSB_INVALID_OBJECT;
}


/*
 * Sets the value of the "version" attribute of this TSBDocument_t.
 */
LIBTSB_EXTERN
int
TSBDocument_setVersion(TSBDocument_t * tsbd, unsigned int version)
{
  return (tsbd != NULL) ? tsbd->setVersion(version) : LIBTSB_INVALID_OBJECT;
}


/*
 * Unsets the value of the "level" attribute of this TSBDocument_t.
 */
LIBTSB_EXTERN
int
TSBDocument_unsetLevel(TSBDocument_t * tsbd)
{
  return (tsbd != NULL) ? tsbd->unsetLevel() : LIBTSB_INVALID_OBJECT;
}


/*
 * Unsets the value of the "version" attribute of this TSBDocument_t.
 */
LIBTSB_EXTERN
int
TSBDocument_unsetVersion(TSBDocument_t * tsbd)
{
  return (tsbd != NULL) ? tsbd->unsetVersion() : LIBTSB_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing TSBComment_t objects from this
 * TSBDocument_t.
 */
LIBTSB_EXTERN
TSBListOf_t*
TSBDocument_getListOfComments(TSBDocument_t* tsbd)
{
  return (tsbd != NULL) ? tsbd->getListOfComments() : NULL;
}


/*
 * Get a TSBComment_t from the TSBDocument_t.
 */
LIBTSB_EXTERN
TSBComment_t*
TSBDocument_getComment(TSBDocument_t* tsbd, unsigned int n)
{
  return (tsbd != NULL) ? tsbd->getComment(n) : NULL;
}


/*
 * Adds a copy of the given TSBComment_t to this TSBDocument_t.
 */
LIBTSB_EXTERN
int
TSBDocument_addComment(TSBDocument_t* tsbd, const TSBComment_t* tsbc)
{
  return (tsbd != NULL) ? tsbd->addComment(tsbc) : LIBTSB_INVALID_OBJECT;
}


/*
 * Get the number of TSBComment_t objects in this TSBDocument_t.
 */
LIBTSB_EXTERN
unsigned int
TSBDocument_getNumComments(TSBDocument_t* tsbd)
{
  return (tsbd != NULL) ? tsbd->getNumComments() : TSB_INT_MAX;
}


/*
 * Creates a new TSBComment_t object, adds it to this TSBDocument_t object and
 * returns the TSBComment_t object created.
 */
LIBTSB_EXTERN
TSBComment_t*
TSBDocument_createComment(TSBDocument_t* tsbd)
{
  return (tsbd != NULL) ? tsbd->createComment() : NULL;
}


/*
 * Removes the nth TSBComment_t from this TSBDocument_t and returns a pointer
 * to it.
 */
LIBTSB_EXTERN
TSBComment_t*
TSBDocument_removeComment(TSBDocument_t* tsbd, unsigned int n)
{
  return (tsbd != NULL) ? tsbd->removeComment(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * TSBDocument_t object have been set.
 */
LIBTSB_EXTERN
int
TSBDocument_hasRequiredAttributes(const TSBDocument_t * tsbd)
{
  return (tsbd != NULL) ? static_cast<int>(tsbd->hasRequiredAttributes()) : 0;
}




LIBTSB_CPP_NAMESPACE_END


