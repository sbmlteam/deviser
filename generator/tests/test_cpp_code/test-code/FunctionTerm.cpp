/**
 * @file FunctionTerm.cpp
 * @brief Implementation of the FunctionTerm class.
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
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */
#include <sbml/packages/qual/sbml/FunctionTerm.h>
#include <sbml/packages/qual/sbml/ListOfFunctionTerms.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>
#include <sbml/math/MathML.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new FunctionTerm using the given SBML Level, Version and
 * &ldquo;qual&rdquo; package version.
 */
FunctionTerm::FunctionTerm(unsigned int level,
                           unsigned int version,
                           unsigned int pkgVersion)
  : SBase(level, version)
  , mResultLevel (SBML_INT_MAX)
  , mIsSetResultLevel (false)
  , mMath (NULL)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new FunctionTerm using the given QualPkgNamespaces object.
 */
FunctionTerm::FunctionTerm(QualPkgNamespaces *qualns)
  : SBase(qualns)
  , mResultLevel (SBML_INT_MAX)
  , mIsSetResultLevel (false)
  , mMath (NULL)
{
  setElementNamespace(qualns->getURI());
  connectToChild();
  loadPlugins(qualns);
}


/*
 * Copy constructor for FunctionTerm.
 */
FunctionTerm::FunctionTerm(const FunctionTerm& orig)
  : SBase( orig )
  , mResultLevel ( orig.mResultLevel )
  , mIsSetResultLevel ( orig.mIsSetResultLevel )
  , mMath ( NULL )
{
  if (orig.mMath != NULL)
  {
    mMath = orig.mMath->deepCopy();
  }

  connectToChild();
}


/*
 * Assignment operator for FunctionTerm.
 */
FunctionTerm&
FunctionTerm::operator=(const FunctionTerm& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mResultLevel = rhs.mResultLevel;
    mIsSetResultLevel = rhs.mIsSetResultLevel;
    delete mMath;
    if (rhs.mMath != NULL)
    {
      mMath = rhs.mMath->deepCopy();
    }
    else
    {
      mMath = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this FunctionTerm object.
 */
FunctionTerm*
FunctionTerm::clone() const
{
  return new FunctionTerm(*this);
}


/*
 * Destructor for FunctionTerm.
 */
FunctionTerm::~FunctionTerm()
{
  delete mMath;
  mMath = NULL;
}


/*
 * Returns the value of the "resultLevel" attribute of this FunctionTerm.
 */
unsigned int
FunctionTerm::getResultLevel() const
{
  return mResultLevel;
}


/*
 * Predicate returning @c true if this FunctionTerm's "resultLevel" attribute
 * is set.
 */
bool
FunctionTerm::isSetResultLevel() const
{
  return mIsSetResultLevel;
}


/*
 * Sets the value of the "resultLevel" attribute of this FunctionTerm.
 */
int
FunctionTerm::setResultLevel(unsigned int resultLevel)
{
  mResultLevel = resultLevel;
  mIsSetResultLevel = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "resultLevel" attribute of this FunctionTerm.
 */
int
FunctionTerm::unsetResultLevel()
{
  mResultLevel = SBML_INT_MAX;
  mIsSetResultLevel = false;

  if (isSetResultLevel() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "math" element of this FunctionTerm.
 */
const ASTNode*
FunctionTerm::getMath() const
{
  return mMath;
}


/*
 * Returns the value of the "math" element of this FunctionTerm.
 */
ASTNode*
FunctionTerm::getMath()
{
  return mMath;
}


/*
 * Predicate returning @c true if this FunctionTerm's "math" element is set.
 */
bool
FunctionTerm::isSetMath() const
{
  return (mMath != NULL);
}


/*
 * Sets the value of the "math" element of this FunctionTerm.
 */
int
FunctionTerm::setMath(const ASTNode* math)
{
  if (mMath == math)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (math == NULL)
  {
    delete mMath;
    mMath = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (!(math->isWellFormedASTNode()))
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else
  {
    delete mMath;
    mMath = (math != NULL) ? math->deepCopy() : NULL;
    if (mMath != NULL)
    {
      mMath->setParentSBMLObject(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "math" element of this FunctionTerm.
 */
int
FunctionTerm::unsetMath()
{
  delete mMath;
  mMath = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * @copydoc doc_renamesidref_common
 */
void
FunctionTerm::renameSIdRefs(const std::string& oldid,
                            const std::string& newid)
{
  if (isSetMath())
  {
    mMath->renameSIdRefs(oldid, newid);
  }
}


/*
 * Returns the XML element name of this FunctionTerm object.
 */
const std::string&
FunctionTerm::getElementName() const
{
  static const string name = "functionTerm";
  return name;
}


/*
 * Returns the libSBML type code for this FunctionTerm object.
 */
int
FunctionTerm::getTypeCode() const
{
  return SBML_QUAL_FUNCTION_TERM;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * FunctionTerm object have been set.
 */
bool
FunctionTerm::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetResultLevel() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * FunctionTerm object have been set.
 */
bool
FunctionTerm::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetMath() == false)
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
FunctionTerm::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetMath() == true)
  {
    writeMathML(getMath(), stream, getSBMLNamespaces());
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
FunctionTerm::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
FunctionTerm::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
FunctionTerm::connectToChild()
{
  SBase::connectToChild();
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
FunctionTerm::enablePackageInternal(const std::string& pkgURI,
                                    const std::string& pkgPrefix,
                                    bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "resultLevel")
  {
    value = getResultLevel();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::getAttribute(const std::string& attributeName,
                           const char* value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this FunctionTerm's attribute "attributeName"
 * is set.
 */
bool
FunctionTerm::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "resultLevel")
  {
    value = isSetResultLevel();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "resultLevel")
  {
    return_value = setResultLevel(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::setAttribute(const std::string& attributeName,
                           const char* value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this FunctionTerm.
 */
int
FunctionTerm::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "resultLevel")
  {
    value = unsetResultLevel();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
FunctionTerm::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("resultLevel");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
FunctionTerm::readAttributes(const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (static_cast<ListOfFunctionTerms*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("qual",
          QualTransitionLOFunctionTermsAllowedAttributes, pkgVersion, level,
            version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("qual",
          QualTransitionLOFunctionTermsAllowedCoreAttributes, pkgVersion, level,
            version, details);
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
      log->logPackageError("qual", QualFunctionTermAllowedAttributes,
        pkgVersion, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("qual", QualFunctionTermAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }

  // 
  // resultLevel uint (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetResultLevel = attributes.readInto("resultLevel", mResultLevel);

  if ( mIsSetResultLevel == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Qual attribute 'resultLevel' from the "
        "<FunctionTerm> element must be an integer.";
      log->logPackageError("qual",
        QualFunctionTermResultLevelMustBeNonNegativeInteger, pkgVersion, level,
          version, message);
    }
    else
    {
      std::string message = "Qual attribute 'resultLevel' is missing from the "
        "<FunctionTerm> element.";
      log->logPackageError("qual", QualFunctionTermAllowedAttributes,
        pkgVersion, level, version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
FunctionTerm::readOtherXML(XMLInputStream& stream)
{
  bool read = false;
  const string& name = stream.peek().getName();

  if (name == "math")
  {
    const XMLToken elem = stream.peek();
    const std::string prefix = checkMathMLNamespace(elem);
    if (stream.getSBMLNamespaces() == NULL)
    {
      stream.setSBMLNamespaces(new SBMLNamespaces(getLevel(), getVersion()));
    }

    delete mMath;
    mMath = readMathML(stream, prefix);
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
FunctionTerm::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetResultLevel() == true)
  {
    stream.writeAttribute("resultLevel", getPrefix(), mResultLevel);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new FunctionTerm_t using the given SBML Level, Version and
 * &ldquo;qual&rdquo; package version.
 */
LIBSBML_EXTERN
FunctionTerm_t *
FunctionTerm_create(unsigned int level,
                    unsigned int version,
                    unsigned int pkgVersion)
{
  return new FunctionTerm(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this FunctionTerm_t object.
 */
LIBSBML_EXTERN
FunctionTerm_t*
FunctionTerm_clone(const FunctionTerm_t* ft)
{
  if (ft != NULL)
  {
    return static_cast<FunctionTerm_t*>(ft->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this FunctionTerm_t object.
 */
LIBSBML_EXTERN
void
FunctionTerm_free(FunctionTerm_t* ft)
{
  if (ft != NULL)
  {
    delete ft;
  }
}


/*
 * Returns the value of the "resultLevel" attribute of this FunctionTerm_t.
 */
LIBSBML_EXTERN
unsigned int
FunctionTerm_getResultLevel(const FunctionTerm_t * ft)
{
  return (ft != NULL) ? ft->getResultLevel() : SBML_INT_MAX;
}


/*
 * Predicate returning @c 1 (true) if this FunctionTerm_t's "resultLevel"
 * attribute is set.
 */
LIBSBML_EXTERN
int
FunctionTerm_isSetResultLevel(const FunctionTerm_t * ft)
{
  return (ft != NULL) ? static_cast<int>(ft->isSetResultLevel()) : 0;
}


/*
 * Sets the value of the "resultLevel" attribute of this FunctionTerm_t.
 */
LIBSBML_EXTERN
int
FunctionTerm_setResultLevel(FunctionTerm_t * ft, unsigned int resultLevel)
{
  return (ft != NULL) ? ft->setResultLevel(resultLevel) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "resultLevel" attribute of this FunctionTerm_t.
 */
LIBSBML_EXTERN
int
FunctionTerm_unsetResultLevel(FunctionTerm_t * ft)
{
  return (ft != NULL) ? ft->unsetResultLevel() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "math" element of this FunctionTerm_t.
 */
LIBSBML_EXTERN
const ASTNode_t*
FunctionTerm_getMath(const FunctionTerm_t * ft)
{
  if (ft == NULL)
  {
    return NULL;
  }

  return (ASTNode_t*)(ft->getMath());
}


/*
 * Predicate returning @c 1 (true) if this FunctionTerm_t's "math" element is
 * set.
 */
LIBSBML_EXTERN
int
FunctionTerm_isSetMath(const FunctionTerm_t * ft)
{
  return (ft != NULL) ? static_cast<int>(ft->isSetMath()) : 0;
}


/*
 * Sets the value of the "math" element of this FunctionTerm_t.
 */
LIBSBML_EXTERN
int
FunctionTerm_setMath(FunctionTerm_t * ft, const ASTNode_t* math)
{
  return (ft != NULL) ? ft->setMath(math) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "math" element of this FunctionTerm_t.
 */
LIBSBML_EXTERN
int
FunctionTerm_unsetMath(FunctionTerm_t * ft)
{
  return (ft != NULL) ? ft->unsetMath() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * FunctionTerm_t object have been set.
 */
LIBSBML_EXTERN
int
FunctionTerm_hasRequiredAttributes(const FunctionTerm_t * ft)
{
  return (ft != NULL) ? static_cast<int>(ft->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this
 * FunctionTerm_t object have been set.
 */
LIBSBML_EXTERN
int
FunctionTerm_hasRequiredElements(const FunctionTerm_t * ft)
{
  return (ft != NULL) ? static_cast<int>(ft->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


