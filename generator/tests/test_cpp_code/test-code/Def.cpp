/**
 * @file Def.cpp
 * @brief Implementation of the Def class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2017 jointly by the following organizations:
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
 * This file is part of SOMETHING.
 * 

 * Copyright (C) 2013-2016 jointly by the following organizations:
 * 1. Abcdefg
 * 2. Hijklmonp
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#include <sbml/packages/copy/sbml/Def.h>
#include <sbml/packages/copy/validator/CopySBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Def using the given SBML Level, Version and &ldquo;copy&rdquo;
 * package version.
 */
Def::Def(unsigned int level, unsigned int version, unsigned int pkgVersion)
  : SBase(level, version)
  , mLetter ("")
  , mMess (NULL)
{
  setSBMLNamespacesAndOwn(new CopyPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new Def using the given CopyPkgNamespaces object.
 */
Def::Def(CopyPkgNamespaces *copyns)
  : SBase(copyns)
  , mLetter ("")
  , mMess (NULL)
{
  setElementNamespace(copyns->getURI());
  connectToChild();
  loadPlugins(copyns);
}


/*
 * Copy constructor for Def.
 */
Def::Def(const Def& orig)
  : SBase( orig )
  , mLetter ( orig.mLetter )
  , mMess ( NULL )
{
  if (orig.mMess != NULL)
  {
    mMess = orig.mMess->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Def.
 */
Def&
Def::operator=(const Def& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mLetter = rhs.mLetter;
    delete mMess;
    if (rhs.mMess != NULL)
    {
      mMess = rhs.mMess->clone();
    }
    else
    {
      mMess = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Def object.
 */
Def*
Def::clone() const
{
  return new Def(*this);
}


/*
 * Destructor for Def.
 */
Def::~Def()
{
  delete mMess;
  mMess = NULL;
}


/*
 * Returns the value of the "letter" attribute of this Def.
 */
const std::string&
Def::getLetter() const
{
  return mLetter;
}


/*
 * Predicate returning @c true if this Def's "letter" attribute is set.
 */
bool
Def::isSetLetter() const
{
  return (mLetter.empty() == false);
}


/*
 * Sets the value of the "letter" attribute of this Def.
 */
int
Def::setLetter(const std::string& letter)
{
  mLetter = letter;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "letter" attribute of this Def.
 */
int
Def::unsetLetter()
{
  mLetter.erase();

  if (mLetter.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "mess" element of this Def.
 */
const XMLNode*
Def::getMess() const
{
  return mMess;
}


/*
 * Returns the value of the "mess" element of this Def.
 */
XMLNode*
Def::getMess()
{
  return mMess;
}


/*
 * Predicate returning @c true if this Def's "mess" element is set.
 */
bool
Def::isSetMess() const
{
  return (mMess != NULL);
}


/*
 * Sets the value of the "mess" element of this Def.
 */
int
Def::setMess(const XMLNode* mess)
{
  if (mMess == mess)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (mess == NULL)
  {
    delete mMess;
    mMess = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mMess;
    mMess = (mess != NULL) ? mess->clone() : NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "mess" element of this Def.
 */
int
Def::unsetMess()
{
  delete mMess;
  mMess = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this Def object.
 */
const std::string&
Def::getElementName() const
{
  static const string name = "def";
  return name;
}


/*
 * Returns the libSBML type code for this Def object.
 */
int
Def::getTypeCode() const
{
  return SBML_COPY_ABC;
}


/*
 * Predicate returning @c true if all the required attributes for this Def
 * object have been set.
 */
bool
Def::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this Def object
 * have been set.
 */
bool
Def::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Def::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetMess() == true)
  {
    stream.startElement("mess");
    stream << *mMess;
    stream.endElement("mess");
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Def::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Def::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Def::connectToChild()
{
  SBase::connectToChild();
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Def::enablePackageInternal(const std::string& pkgURI,
                           const std::string& pkgPrefix,
                           bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Def.
 */
int
Def::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Def.
 */
int
Def::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Def.
 */
int
Def::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Def.
 */
int
Def::getAttribute(const std::string& attributeName, unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Def.
 */
int
Def::getAttribute(const std::string& attributeName, std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "letter")
  {
    value = getLetter();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Def.
 */
int
Def::getAttribute(const std::string& attributeName, const char* value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "letter")
  {
    value = getLetter().c_str();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Def's attribute "attributeName" is set.
 */
bool
Def::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "letter")
  {
    value = isSetLetter();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Def.
 */
int
Def::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Def.
 */
int
Def::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Def.
 */
int
Def::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Def.
 */
int
Def::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Def.
 */
int
Def::setAttribute(const std::string& attributeName, const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "letter")
  {
    return_value = setLetter(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Def.
 */
int
Def::setAttribute(const std::string& attributeName, const char* value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "letter")
  {
    return_value = setLetter(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Def.
 */
int
Def::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "letter")
  {
    value = unsetLetter();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
Def::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("letter");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Def::readAttributes(const XMLAttributes& attributes,
                    const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("copy", CopyDefAllowedAttributes, pkgVersion, level,
        version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("copy", CopyDefAllowedCoreAttributes, pkgVersion,
        level, version, details);
    }
  }

  // 
  // letter string (use = "optional" )
  // 

  assigned = attributes.readInto("letter", mLetter);

  if (assigned == true)
  {
    if (mLetter.empty() == true)
    {
      logEmptyString(mLetter, level, version, "<Def>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
Def::readOtherXML(XMLInputStream& stream)
{
  bool read = false;
  const string& name = stream.peek().getName();

  if (name == "mess")
  {
    const XMLToken& token = stream.next();
    stream.skipText();
    delete mMess;
    XMLNode* xml = new XMLNode(stream);
    mMess = new XMLNode(*(static_cast<XMLToken*>(xml)));
    stream.skipPastEnd(token);
    delete xml;
    read = true;
  }

  if (SBase::readOtherXML(stream))
  {
    read = true;
  }

  return read;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Def::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetLetter() == true)
  {
    stream.writeAttribute("letter", getPrefix(), mLetter);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Def_t using the given SBML Level, Version and
 * &ldquo;copy&rdquo; package version.
 */
LIBSBML_EXTERN
Def_t *
Def_create(unsigned int level, unsigned int version, unsigned int pkgVersion)
{
  return new Def(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Def_t object.
 */
LIBSBML_EXTERN
Def_t*
Def_clone(const Def_t* d)
{
  if (d != NULL)
  {
    return static_cast<Def_t*>(d->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Def_t object.
 */
LIBSBML_EXTERN
void
Def_free(Def_t* d)
{
  if (d != NULL)
  {
    delete d;
  }
}


/*
 * Returns the value of the "letter" attribute of this Def_t.
 */
LIBSBML_EXTERN
const char *
Def_getLetter(const Def_t * d)
{
  if (d == NULL)
  {
    return NULL;
  }

  return d->getLetter().empty() ? NULL : safe_strdup(d->getLetter().c_str());
}


/*
 * Predicate returning @c 1 (true) if this Def_t's "letter" attribute is set.
 */
LIBSBML_EXTERN
int
Def_isSetLetter(const Def_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isSetLetter()) : 0;
}


/*
 * Sets the value of the "letter" attribute of this Def_t.
 */
LIBSBML_EXTERN
int
Def_setLetter(Def_t * d, const char * letter)
{
  return (d != NULL) ? d->setLetter(letter) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "letter" attribute of this Def_t.
 */
LIBSBML_EXTERN
int
Def_unsetLetter(Def_t * d)
{
  return (d != NULL) ? d->unsetLetter() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "mess" element of this Def_t.
 */
LIBSBML_EXTERN
const XMLNode_t*
Def_getMess(const Def_t * d)
{
  if (d == NULL)
  {
    return NULL;
  }

  return (XMLNode_t*)(d->getMess());
}


/*
 * Predicate returning @c 1 (true) if this Def_t's "mess" element is set.
 */
LIBSBML_EXTERN
int
Def_isSetMess(const Def_t * d)
{
  return (d != NULL) ? static_cast<int>(d->isSetMess()) : 0;
}


/*
 * Sets the value of the "mess" element of this Def_t.
 */
LIBSBML_EXTERN
int
Def_setMess(Def_t * d, const XMLNode_t* mess)
{
  return (d != NULL) ? d->setMess(mess) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "mess" element of this Def_t.
 */
LIBSBML_EXTERN
int
Def_unsetMess(Def_t * d)
{
  return (d != NULL) ? d->unsetMess() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this Def_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Def_hasRequiredAttributes(const Def_t * d)
{
  return (d != NULL) ? static_cast<int>(d->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this Def_t object
 * have been set.
 */
LIBSBML_EXTERN
int
Def_hasRequiredElements(const Def_t * d)
{
  return (d != NULL) ? static_cast<int>(d->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


