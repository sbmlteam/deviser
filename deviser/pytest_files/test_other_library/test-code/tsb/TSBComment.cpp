/**
 * @file TSBComment.cpp
 * @brief Implementation of the TSBComment class.
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
#include <tsb/TSBComment.h>
#include <tsb/TSBListOfComments.h>
#include <xml/XMLInputStream.h>


using namespace std;



LIBTSB_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new TSBComment using the given TSB Level and @ p version values.
 */
TSBComment::TSBComment(unsigned int level, unsigned int version)
  : TSBBase(level, version)
  , mContributor ("")
  , mNumber (tsb_util_NaN())
  , mIsSetNumber (false)
  , mPoint ("")
{
  setTSBNamespacesAndOwn(new TSBNamespaces(level, version));
}


/*
 * Creates a new TSBComment using the given TSBNamespaces object @p tsbns.
 */
TSBComment::TSBComment(TSBNamespaces *tsbns)
  : TSBBase(tsbns)
  , mContributor ("")
  , mNumber (tsb_util_NaN())
  , mIsSetNumber (false)
  , mPoint ("")
{
  setElementNamespace(tsbns->getURI());
}


/*
 * Copy constructor for TSBComment.
 */
TSBComment::TSBComment(const TSBComment& orig)
  : TSBBase( orig )
  , mContributor ( orig.mContributor )
  , mNumber ( orig.mNumber )
  , mIsSetNumber ( orig.mIsSetNumber )
  , mPoint ( orig.mPoint )
{
}


/*
 * Assignment operator for TSBComment.
 */
TSBComment&
TSBComment::operator=(const TSBComment& rhs)
{
  if (&rhs != this)
  {
    TSBBase::operator=(rhs);
    mContributor = rhs.mContributor;
    mNumber = rhs.mNumber;
    mIsSetNumber = rhs.mIsSetNumber;
    mPoint = rhs.mPoint;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this TSBComment object.
 */
TSBComment*
TSBComment::clone() const
{
  return new TSBComment(*this);
}


/*
 * Destructor for TSBComment.
 */
TSBComment::~TSBComment()
{
}


/*
 * Returns the value of the "contributor" attribute of this TSBComment.
 */
const std::string&
TSBComment::getContributor() const
{
  return mContributor;
}


/*
 * Returns the value of the "number" attribute of this TSBComment.
 */
double
TSBComment::getNumber() const
{
  return mNumber;
}


/*
 * Returns the value of the "point" attribute of this TSBComment.
 */
const std::string&
TSBComment::getPoint() const
{
  return mPoint;
}


/*
 * Predicate returning @c true if this TSBComment's "contributor" attribute is
 * set.
 */
bool
TSBComment::isSetContributor() const
{
  return (mContributor.empty() == false);
}


/*
 * Predicate returning @c true if this TSBComment's "number" attribute is set.
 */
bool
TSBComment::isSetNumber() const
{
  return mIsSetNumber;
}


/*
 * Predicate returning @c true if this TSBComment's "point" attribute is set.
 */
bool
TSBComment::isSetPoint() const
{
  return (mPoint.empty() == false);
}


/*
 * Sets the value of the "contributor" attribute of this TSBComment.
 */
int
TSBComment::setContributor(const std::string& contributor)
{
  mContributor = contributor;
  return LIBTSB_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "number" attribute of this TSBComment.
 */
int
TSBComment::setNumber(double number)
{
  mNumber = number;
  mIsSetNumber = true;
  return LIBTSB_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "point" attribute of this TSBComment.
 */
int
TSBComment::setPoint(const std::string& point)
{
  mPoint = point;
  return LIBTSB_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "contributor" attribute of this TSBComment.
 */
int
TSBComment::unsetContributor()
{
  mContributor.erase();

  if (mContributor.empty() == true)
  {
    return LIBTSB_OPERATION_SUCCESS;
  }
  else
  {
    return LIBTSB_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "number" attribute of this TSBComment.
 */
int
TSBComment::unsetNumber()
{
  mNumber = tsb_util_NaN();
  mIsSetNumber = false;

  if (isSetNumber() == false)
  {
    return LIBTSB_OPERATION_SUCCESS;
  }
  else
  {
    return LIBTSB_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "point" attribute of this TSBComment.
 */
int
TSBComment::unsetPoint()
{
  mPoint.erase();

  if (mPoint.empty() == true)
  {
    return LIBTSB_OPERATION_SUCCESS;
  }
  else
  {
    return LIBTSB_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this TSBComment object.
 */
const std::string&
TSBComment::getElementName() const
{
  static const string name = "comment";
  return name;
}


/*
 * Returns the libTSB type code for this TSBComment object.
 */
int
TSBComment::getTypeCode() const
{
  return TSB_COMMENT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * TSBComment object have been set.
 */
bool
TSBComment::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetContributor() == false)
  {
    allPresent = false;
  }

  if (isSetNumber() == false)
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
TSBComment::writeElements(XMLOutputStream& stream) const
{
  TSBBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Accepts the given TSBVisitor
 */
bool
TSBComment::accept(TSBVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the parent TSBDocument
 */
void
TSBComment::setTSBDocument(TSBDocument* d)
{
  TSBBase::setTSBDocument(d);
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  if (return_value == LIBTSB_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "number")
  {
    value = getNumber();
    return_value = LIBTSB_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Gets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = TSBBase::getAttribute(attributeName, value);

  if (return_value == LIBTSB_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "contributor")
  {
    value = getContributor();
    return_value = LIBTSB_OPERATION_SUCCESS;
  }
  else if (attributeName == "point")
  {
    value = getPoint();
    return_value = LIBTSB_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Predicate returning @c true if this TSBComment's attribute "attributeName"
 * is set.
 */
bool
TSBComment::isSetAttribute(const std::string& attributeName) const
{
  bool value = TSBBase::isSetAttribute(attributeName);

  if (attributeName == "contributor")
  {
    value = isSetContributor();
  }
  else if (attributeName == "number")
  {
    value = isSetNumber();
  }
  else if (attributeName == "point")
  {
    value = isSetPoint();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::setAttribute(const std::string& attributeName, int value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::setAttribute(const std::string& attributeName, double value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  if (attributeName == "number")
  {
    return_value = setNumber(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Sets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = TSBBase::setAttribute(attributeName, value);

  if (attributeName == "contributor")
  {
    return_value = setContributor(value);
  }
  else if (attributeName == "point")
  {
    return_value = setPoint(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Unsets the value of the "attributeName" attribute of this TSBComment.
 */
int
TSBComment::unsetAttribute(const std::string& attributeName)
{
  int value = TSBBase::unsetAttribute(attributeName);

  if (attributeName == "contributor")
  {
    value = unsetContributor();
  }
  else if (attributeName == "number")
  {
    value = unsetNumber();
  }
  else if (attributeName == "point")
  {
    value = unsetPoint();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Adds the expected attributes for this element
 */
void
TSBComment::addExpectedAttributes(ExpectedAttributes& attributes)
{
  TSBBase::addExpectedAttributes(attributes);

  attributes.add("contributor");

  attributes.add("number");

  attributes.add("point");
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
TSBComment::readAttributes(const XMLAttributes& attributes,
                           const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  TSBErrorLog* log = getErrorLog();

  if (log && getParentTSBObject() &&
    static_cast<TSBListOfComments*>(getParentTSBObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == TSBUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(TSBUnknownCoreAttribute);
        log->logError(TsbDocumentLOCommentsAllowedCoreAttributes, level,
          version, details, getLine(), getColumn());
      }
    }
  }

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
        log->logError(TsbCommentAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // contributor string (use = "required" )
  // 

  assigned = attributes.readInto("contributor", mContributor);

  if (assigned == true)
  {
    if (mContributor.empty() == true)
    {
      logEmptyString(mContributor, level, version, "<TSBComment>");
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Tsb attribute 'contributor' is missing from the "
        "<TSBComment> element.";
      log->logError(TsbCommentAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // number double (use = "required" )
  // 

  numErrs = log ? log->getNumErrors() : 0;
  mIsSetNumber = attributes.readInto("number", mNumber);

  if ( mIsSetNumber == false && log)
  {
    if (log && log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Tsb attribute 'number' from the <TSBComment> "
        "element must be an integer.";
      log->logError(TsbCommentNumberMustBeDouble, level, version, message,
        getLine(), getColumn());
    }
    else
    {
      std::string message = "Tsb attribute 'number' is missing from the "
        "<TSBComment> element.";
      log->logError(TsbCommentAllowedAttributes, level, version, message,
        getLine(), getColumn());
    }
  }

  // 
  // point string (use = "optional" )
  // 

  assigned = attributes.readInto("point", mPoint);

  if (assigned == true)
  {
    if (mPoint.empty() == true)
    {
      logEmptyString(mPoint, level, version, "<TSBComment>");
    }
  }
}

/** @endcond */



/** @cond doxygenlibTSBInternal */

/*
 * Writes the attributes to the stream
 */
void
TSBComment::writeAttributes(XMLOutputStream& stream) const
{
  TSBBase::writeAttributes(stream);

  if (isSetContributor() == true)
  {
    stream.writeAttribute("contributor", getPrefix(), mContributor);
  }

  if (isSetNumber() == true)
  {
    stream.writeAttribute("number", getPrefix(), mNumber);
  }

  if (isSetPoint() == true)
  {
    stream.writeAttribute("point", getPrefix(), mPoint);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new TSBComment_t using the given TSB Level and @ p version values.
 */
LIBTSB_EXTERN
TSBComment_t *
TSBComment_create(unsigned int level, unsigned int version)
{
  return new TSBComment(level, version);
}


/*
 * Creates and returns a deep copy of this TSBComment_t object.
 */
LIBTSB_EXTERN
TSBComment_t*
TSBComment_clone(const TSBComment_t* tsbc)
{
  if (tsbc != NULL)
  {
    return static_cast<TSBComment_t*>(tsbc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this TSBComment_t object.
 */
LIBTSB_EXTERN
void
TSBComment_free(TSBComment_t* tsbc)
{
  if (tsbc != NULL)
  {
    delete tsbc;
  }
}


/*
 * Returns the value of the "contributor" attribute of this TSBComment_t.
 */
LIBTSB_EXTERN
char *
TSBComment_getContributor(const TSBComment_t * tsbc)
{
  if (tsbc == NULL)
  {
    return NULL;
  }

  return tsbc->getContributor().empty() ? NULL :
    tsb_safe_strdup(tsbc->getContributor().c_str());
}


/*
 * Returns the value of the "number" attribute of this TSBComment_t.
 */
LIBTSB_EXTERN
double
TSBComment_getNumber(const TSBComment_t * tsbc)
{
  return (tsbc != NULL) ? tsbc->getNumber() : tsb_util_NaN();
}


/*
 * Returns the value of the "point" attribute of this TSBComment_t.
 */
LIBTSB_EXTERN
char *
TSBComment_getPoint(const TSBComment_t * tsbc)
{
  if (tsbc == NULL)
  {
    return NULL;
  }

  return tsbc->getPoint().empty() ? NULL :
    tsb_safe_strdup(tsbc->getPoint().c_str());
}


/*
 * Predicate returning @c 1 (true) if this TSBComment_t's "contributor"
 * attribute is set.
 */
LIBTSB_EXTERN
int
TSBComment_isSetContributor(const TSBComment_t * tsbc)
{
  return (tsbc != NULL) ? static_cast<int>(tsbc->isSetContributor()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this TSBComment_t's "number" attribute is
 * set.
 */
LIBTSB_EXTERN
int
TSBComment_isSetNumber(const TSBComment_t * tsbc)
{
  return (tsbc != NULL) ? static_cast<int>(tsbc->isSetNumber()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this TSBComment_t's "point" attribute is
 * set.
 */
LIBTSB_EXTERN
int
TSBComment_isSetPoint(const TSBComment_t * tsbc)
{
  return (tsbc != NULL) ? static_cast<int>(tsbc->isSetPoint()) : 0;
}


/*
 * Sets the value of the "contributor" attribute of this TSBComment_t.
 */
LIBTSB_EXTERN
int
TSBComment_setContributor(TSBComment_t * tsbc, const char * contributor)
{
  return (tsbc != NULL) ? tsbc->setContributor(contributor) :
    LIBTSB_INVALID_OBJECT;
}


/*
 * Sets the value of the "number" attribute of this TSBComment_t.
 */
LIBTSB_EXTERN
int
TSBComment_setNumber(TSBComment_t * tsbc, double number)
{
  return (tsbc != NULL) ? tsbc->setNumber(number) : LIBTSB_INVALID_OBJECT;
}


/*
 * Sets the value of the "point" attribute of this TSBComment_t.
 */
LIBTSB_EXTERN
int
TSBComment_setPoint(TSBComment_t * tsbc, const char * point)
{
  return (tsbc != NULL) ? tsbc->setPoint(point) : LIBTSB_INVALID_OBJECT;
}


/*
 * Unsets the value of the "contributor" attribute of this TSBComment_t.
 */
LIBTSB_EXTERN
int
TSBComment_unsetContributor(TSBComment_t * tsbc)
{
  return (tsbc != NULL) ? tsbc->unsetContributor() : LIBTSB_INVALID_OBJECT;
}


/*
 * Unsets the value of the "number" attribute of this TSBComment_t.
 */
LIBTSB_EXTERN
int
TSBComment_unsetNumber(TSBComment_t * tsbc)
{
  return (tsbc != NULL) ? tsbc->unsetNumber() : LIBTSB_INVALID_OBJECT;
}


/*
 * Unsets the value of the "point" attribute of this TSBComment_t.
 */
LIBTSB_EXTERN
int
TSBComment_unsetPoint(TSBComment_t * tsbc)
{
  return (tsbc != NULL) ? tsbc->unsetPoint() : LIBTSB_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * TSBComment_t object have been set.
 */
LIBTSB_EXTERN
int
TSBComment_hasRequiredAttributes(const TSBComment_t * tsbc)
{
  return (tsbc != NULL) ? static_cast<int>(tsbc->hasRequiredAttributes()) : 0;
}




LIBTSB_CPP_NAMESPACE_END


