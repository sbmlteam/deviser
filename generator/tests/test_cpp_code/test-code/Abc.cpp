/**
 * @file Abc.cpp
 * @brief Implementation of the Abc class.
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
#include <sbml/packages/copy/sbml/Abc.h>
#include <sbml/packages/copy/validator/CopySBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Abc using the given SBML Level, Version and &ldquo;copy&rdquo;
 * package version.
 */
Abc::Abc(unsigned int level, unsigned int version, unsigned int pkgVersion)
  : SBase(level, version)
  , mLetter ("")
{
  setSBMLNamespacesAndOwn(new CopyPkgNamespaces(level, version, pkgVersion));
}


/*
 * Creates a new Abc using the given CopyPkgNamespaces object.
 */
Abc::Abc(CopyPkgNamespaces *copyns)
  : SBase(copyns)
  , mLetter ("")
{
  setElementNamespace(copyns->getURI());
  loadPlugins(copyns);
}


/*
 * Copy constructor for Abc.
 */
Abc::Abc(const Abc& orig)
  : SBase( orig )
  , mLetter ( orig.mLetter )
{
}


/*
 * Assignment operator for Abc.
 */
Abc&
Abc::operator=(const Abc& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mLetter = rhs.mLetter;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Abc object.
 */
Abc*
Abc::clone() const
{
  return new Abc(*this);
}


/*
 * Destructor for Abc.
 */
Abc::~Abc()
{
}


/*
 * Returns the value of the "letter" attribute of this Abc.
 */
const std::string&
Abc::getLetter() const
{
  return mLetter;
}


/*
 * Predicate returning @c true if this Abc's "letter" attribute is set.
 */
bool
Abc::isSetLetter() const
{
  return (mLetter.empty() == false);
}


/*
 * Sets the value of the "letter" attribute of this Abc.
 */
int
Abc::setLetter(const std::string& letter)
{
  mLetter = letter;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "letter" attribute of this Abc.
 */
int
Abc::unsetLetter()
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
 * Returns the XML element name of this Abc object.
 */
const std::string&
Abc::getElementName() const
{
  static const string name = "abc";
  return name;
}


/*
 * Returns the libSBML type code for this Abc object.
 */
int
Abc::getTypeCode() const
{
  return SBML_COPY_ABC;
}


/*
 * Predicate returning @c true if all the required attributes for this Abc
 * object have been set.
 */
bool
Abc::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Abc::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Abc::accept(SBMLVisitor& v) const
{
  return v.visit(*this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Abc::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Abc::enablePackageInternal(const std::string& pkgURI,
                           const std::string& pkgPrefix,
                           bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::getAttribute(const std::string& attributeName, unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::getAttribute(const std::string& attributeName, std::string& value) const
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
 * Gets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::getAttribute(const std::string& attributeName, const char* value) const
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
 * Predicate returning @c true if this Abc's attribute "attributeName" is set.
 */
bool
Abc::isSetAttribute(const std::string& attributeName) const
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
 * Sets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::setAttribute(const std::string& attributeName, const std::string& value)
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
 * Sets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::setAttribute(const std::string& attributeName, const char* value)
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
 * Unsets the value of the "attributeName" attribute of this Abc.
 */
int
Abc::unsetAttribute(const std::string& attributeName)
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
Abc::addExpectedAttributes(ExpectedAttributes& attributes)
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
Abc::readAttributes(const XMLAttributes& attributes,
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
      log->logPackageError("copy", CopyAbcAllowedAttributes, pkgVersion, level,
        version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("copy", CopyAbcAllowedCoreAttributes, pkgVersion,
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
      logEmptyString(mLetter, level, version, "<Abc>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Abc::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetLetter() == true)
  {
    stream.writeAttribute("letter", getPrefix(), mLetter);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */


void 
GroupsModelPlugin::copyInformationToNestedLists()
{
  bool change = true;
  while (change) 
  {
    change = false;
    
    for (unsigned int lnum = 0; lnum < getNumGroups(); lnum++) 
    {
      Group* group = getGroup(lnum);
      ListOf* listofmembers = group->getListOfMembers();
      
      for (unsigned int mnum = 0; mnum < group->getNumMembers(); mnum++) 
      {
        Member* member = group->getMember(mnum);
        SBase* referent = NULL;
        
        if (member->isSetIdRef()) 
        {
          referent = getElementBySId(member->getIdRef());
        }
        
        if (referent == NULL && member->isSetMetaIdRef()) 
        {
          referent = getElementByMetaId(member->getMetaIdRef());
        }
        
        if (referent != NULL && referent->getTypeCode() == SBML_LIST_OF) 
        {
          ListOf* list = static_cast<ListOf*>(referent);
          
          if (list->getItemTypeCode() == SBML_GROUPS_MEMBER) 
          {
            if (!referent->isSetSBOTerm()) 
            {
              if (listofmembers->isSetSBOTerm()) 
              {
                referent->setSBOTerm(listofmembers->getSBOTerm());
                change = true;
              }
            }
            
            if (!referent->isSetNotes()) 
            {
              if (listofmembers->isSetNotes()) 
              {
                referent->setNotes(listofmembers->getNotes());
                change = true;
              }
            }
            
            if (!referent->isSetAnnotation()) 
            {
              if (listofmembers->isSetAnnotation()) 
              {
                referent->setAnnotation(listofmembers->getAnnotation());
                change = true;
              }
            }
          }
        }
      }
    }
  }
}



#endif /* __cplusplus */


/*
 * Creates a new Abc_t using the given SBML Level, Version and
 * &ldquo;copy&rdquo; package version.
 */
LIBSBML_EXTERN
Abc_t *
Abc_create(unsigned int level, unsigned int version, unsigned int pkgVersion)
{
  return new Abc(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Abc_t object.
 */
LIBSBML_EXTERN
Abc_t*
Abc_clone(const Abc_t* a)
{
  if (a != NULL)
  {
    return static_cast<Abc_t*>(a->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Abc_t object.
 */
LIBSBML_EXTERN
void
Abc_free(Abc_t* a)
{
  if (a != NULL)
  {
    delete a;
  }
}


/*
 * Returns the value of the "letter" attribute of this Abc_t.
 */
LIBSBML_EXTERN
const char *
Abc_getLetter(const Abc_t * a)
{
  if (a == NULL)
  {
    return NULL;
  }

  return a->getLetter().empty() ? NULL : safe_strdup(a->getLetter().c_str());
}


/*
 * Predicate returning @c 1 (true) if this Abc_t's "letter" attribute is set.
 */
LIBSBML_EXTERN
int
Abc_isSetLetter(const Abc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->isSetLetter()) : 0;
}


/*
 * Sets the value of the "letter" attribute of this Abc_t.
 */
LIBSBML_EXTERN
int
Abc_setLetter(Abc_t * a, const char * letter)
{
  return (a != NULL) ? a->setLetter(letter) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "letter" attribute of this Abc_t.
 */
LIBSBML_EXTERN
int
Abc_unsetLetter(Abc_t * a)
{
  return (a != NULL) ? a->unsetLetter() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this Abc_t
 * object have been set.
 */
LIBSBML_EXTERN
int
Abc_hasRequiredAttributes(const Abc_t * a)
{
  return (a != NULL) ? static_cast<int>(a->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


