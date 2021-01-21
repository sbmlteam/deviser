/**
 * @file BBB.cpp
 * @brief Implementation of the BBB class.
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
#include <sbml/packages/vers/sbml/BBB.h>
#include <sbml/packages/vers/validator/VersSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new BBB using the given SBML Level, Version and &ldquo;vers&rdquo;
 * package version.
 */
BBB::BBB(unsigned int level, unsigned int version, unsigned int pkgVersion)
  : SBase(level, version)
  , mAnothers (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new VersPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new BBB using the given VersPkgNamespaces object.
 */
BBB::BBB(VersPkgNamespaces *versns)
  : SBase(versns)
  , mAnothers (versns)
{
  setElementNamespace(versns->getURI());
  connectToChild();
  loadPlugins(versns);
}


/*
 * Copy constructor for BBB.
 */
BBB::BBB(const BBB& orig)
  : SBase( orig )
  , mAnothers ( orig.mAnothers )
{
  connectToChild();
}


/*
 * Assignment operator for BBB.
 */
BBB&
BBB::operator=(const BBB& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mAnothers = rhs.mAnothers;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this BBB object.
 */
BBB*
BBB::clone() const
{
  return new BBB(*this);
}


/*
 * Destructor for BBB.
 */
BBB::~BBB()
{
}


/*
 * Returns the value of the "id" attribute of this BBB.
 */
const std::string&
BBB::getId() const
{
  return mId;
}


/*
 * Predicate returning @c true if this BBB's "id" attribute is set.
 */
bool
BBB::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this BBB.
 */
int
BBB::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Unsets the value of the "id" attribute of this BBB.
 */
int
BBB::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the ListOfAnothers from this BBB.
 */
const ListOfAnothers*
BBB::getListOfAnothers() const
{
  return &mAnothers;
}


/*
 * Returns the ListOfAnothers from this BBB.
 */
ListOfAnothers*
BBB::getListOfAnothers()
{
  return &mAnothers;
}


/*
 * Get an Another from the BBB.
 */
Another*
BBB::getAnother(unsigned int n)
{
  return mAnothers.get(n);
}


/*
 * Get an Another from the BBB.
 */
const Another*
BBB::getAnother(unsigned int n) const
{
  return mAnothers.get(n);
}


/*
 * Get an Another from the BBB based on its identifier.
 */
Another*
BBB::getAnother(const std::string& sid)
{
  return mAnothers.get(sid);
}


/*
 * Get an Another from the BBB based on its identifier.
 */
const Another*
BBB::getAnother(const std::string& sid) const
{
  return mAnothers.get(sid);
}


/*
 * Adds a copy of the given Another to this BBB.
 */
int
BBB::addAnother(const Another* a)
{
  if (a == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (a->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != a->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != a->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(a)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (a->isSetId() && (mAnothers.get(a->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mAnothers.append(a);
  }
}


/*
 * Get the number of Another objects in this BBB.
 */
unsigned int
BBB::getNumAnothers() const
{
  return mAnothers.size();
}


/*
 * Creates a new Another object, adds it to this BBB object and returns the
 * Another object created.
 */
Another*
BBB::createAnother()
{
  Another* a = NULL;

  try
  {
    VERS_CREATE_NS_WITH_VERSION(versns, getSBMLNamespaces(),
      getPackageVersion());
    a = new Another(versns);
    delete versns;
  }
  catch (...)
  {
  }

  if (a != NULL)
  {
    mAnothers.appendAndOwn(a);
  }

  return a;
}


/*
 * Removes the nth Another from this BBB and returns a pointer to it.
 */
Another*
BBB::removeAnother(unsigned int n)
{
  return mAnothers.remove(n);
}


/*
 * Removes the Another from this BBB based on its identifier and returns a
 * pointer to it.
 */
Another*
BBB::removeAnother(const std::string& sid)
{
  return mAnothers.remove(sid);
}


/*
 * Returns the XML element name of this BBB object.
 */
const std::string&
BBB::getElementName() const
{
  static const string name = "bBB";
  return name;
}


/*
 * Returns the libSBML type code for this BBB object.
 */
int
BBB::getTypeCode() const
{
  return CLASS_B;
}


/*
 * Predicate returning @c true if all the required attributes for this BBB
 * object have been set.
 */
bool
BBB::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
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
BBB::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (getNumAnothers() > 0)
  {
    mAnothers.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
BBB::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  mAnothers.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
BBB::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  mAnothers.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
BBB::connectToChild()
{
  SBase::connectToChild();

  mAnothers.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
BBB::enablePackageInternal(const std::string& pkgURI,
                           const std::string& pkgPrefix,
                           bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  mAnothers.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
BBB::updateSBMLNamespace(const std::string& package,
                         unsigned int level,
                         unsigned int version)
{
  SBase::updateSBMLNamespace(package, level, version);

  mAnothers.updateSBMLNamespace(package, level, version);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::getAttribute(const std::string& attributeName, unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::getAttribute(const std::string& attributeName, std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this BBB's attribute "attributeName" is set.
 */
bool
BBB::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::setAttribute(const std::string& attributeName, const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this BBB.
 */
int
BBB::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this BBB.
 */
SBase*
BBB::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "another")
  {
    return createAnother();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this BBB.
 */
int
BBB::addChildObject(const std::string& elementName, const SBase* element)
{
  if (elementName == "another" && element->getTypeCode() == CLASS_A)
  {
    return addAnother((const Another*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * BBB.
 */
SBase*
BBB::removeChildObject(const std::string& elementName, const std::string& id)
{
  if (elementName == "another")
  {
    return removeAnother(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this BBB.
 */
unsigned int
BBB::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "another")
  {
    return getNumAnothers();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this BBB.
 */
SBase*
BBB::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "another")
  {
    return getAnother(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
BBB::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mAnothers.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
BBB::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mAnothers.getMetaId() == metaid)
  {
    return &mAnothers;
  }

  obj = mAnothers.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
BBB::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mAnothers, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
BBB::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfAnothers")
  {
    if (getErrorLog() && mAnothers.size() != 0)
    {
      getErrorLog()->logPackageError("vers", VersBBBAllowedElements,
        getPackageVersion(), getLevel(), getVersion(), "", getLine(),
          getColumn());
    }

    obj = &mAnothers;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
BBB::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  unsigned int level = getLevel();
  unsigned int coreVersion = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && coreVersion == 1 && pkgVersion == 1)
  {
    attributes.add("id");
  }

  if (level == 3 && coreVersion == 1 && pkgVersion == 2)
  {
    attributes.add("id");
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
BBB::readAttributes(const XMLAttributes& attributes,
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
        log->logPackageError("vers", VersBBBAllowedAttributes, pkgVersion,
          level, version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("vers", VersBBBAllowedCoreAttributes, pkgVersion,
          level, version, details, getLine(), getColumn());
      }
    }
  }

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    readL3V1V1Attributes(attributes);
  }

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    readL3V1V2Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
BBB::readL3V1V1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();

  // 
  // id SId (use = "required" )
  // 

  XMLTriple tripleID("id", mURI, getPrefix());
  assigned = attributes.readInto(tripleID, mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<BBB>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("vers", VersIdSyntaxRule, pkgVersion, level,
        version, "The id on the <" + getElementName() + "> is '" + mId + "', "
          "which does not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Vers attribute 'id' is missing from the <BBB> "
        "element.";
      log->logPackageError("vers", VersBBBAllowedAttributes, pkgVersion, level,
        version, message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
BBB::readL3V1V2Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();

  // 
  // id SId (use = "required" )
  // 

  XMLTriple tripleID("id", mURI, getPrefix());
  assigned = attributes.readInto(tripleID, mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<BBB>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      log->logPackageError("vers", VersIdSyntaxRule, pkgVersion, level,
        version, "The id on the <" + getElementName() + "> is '" + mId + "', "
          "which does not conform to the syntax.", getLine(), getColumn());
    }
  }
  else
  {
    if (log)
    {
      std::string message = "Vers attribute 'id' is missing from the <BBB> "
        "element.";
      log->logPackageError("vers", VersBBBAllowedAttributes, pkgVersion, level,
        version, message, getLine(), getColumn());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
BBB::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();

  if (level == 3 && version == 1 && pkgVersion == 1)
  {
    writeL3V1V1Attributes(stream);
  }

  if (level == 3 && version == 1 && pkgVersion == 2)
  {
    writeL3V1V2Attributes(stream);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
BBB::writeL3V1V1Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
BBB::writeL3V1V2Attributes(XMLOutputStream& stream) const
{
  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new BBB_t using the given SBML Level, Version and
 * &ldquo;vers&rdquo; package version.
 */
LIBSBML_EXTERN
BBB_t *
BBB_create(unsigned int level, unsigned int version, unsigned int pkgVersion)
{
  return new BBB(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this BBB_t object.
 */
LIBSBML_EXTERN
BBB_t*
BBB_clone(const BBB_t* bbb)
{
  if (bbb != NULL)
  {
    return static_cast<BBB_t*>(bbb->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this BBB_t object.
 */
LIBSBML_EXTERN
void
BBB_free(BBB_t* bbb)
{
  if (bbb != NULL)
  {
    delete bbb;
  }
}


/*
 * Returns the value of the "id" attribute of this BBB_t.
 */
LIBSBML_EXTERN
char *
BBB_getId(const BBB_t * bbb)
{
  if (bbb == NULL)
  {
    return NULL;
  }

  return bbb->getId().empty() ? NULL : safe_strdup(bbb->getId().c_str());
}


/*
 * Predicate returning @c 1 (true) if this BBB_t's "id" attribute is set.
 */
LIBSBML_EXTERN
int
BBB_isSetId(const BBB_t * bbb)
{
  return (bbb != NULL) ? static_cast<int>(bbb->isSetId()) : 0;
}


/*
 * Sets the value of the "id" attribute of this BBB_t.
 */
LIBSBML_EXTERN
int
BBB_setId(BBB_t * bbb, const char * id)
{
  return (bbb != NULL) ? bbb->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this BBB_t.
 */
LIBSBML_EXTERN
int
BBB_unsetId(BBB_t * bbb)
{
  return (bbb != NULL) ? bbb->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing Another_t objects from this BBB_t.
 */
LIBSBML_EXTERN
ListOf_t*
BBB_getListOfAnothers(BBB_t* bbb)
{
  return (bbb != NULL) ? bbb->getListOfAnothers() : NULL;
}


/*
 * Get an Another_t from the BBB_t.
 */
LIBSBML_EXTERN
Another_t*
BBB_getAnother(BBB_t* bbb, unsigned int n)
{
  return (bbb != NULL) ? bbb->getAnother(n) : NULL;
}


/*
 * Get an Another_t from the BBB_t based on its identifier.
 */
LIBSBML_EXTERN
Another_t*
BBB_getAnotherById(BBB_t* bbb, const char *sid)
{
  return (bbb != NULL && sid != NULL) ? bbb->getAnother(sid) : NULL;
}


/*
 * Adds a copy of the given Another_t to this BBB_t.
 */
LIBSBML_EXTERN
int
BBB_addAnother(BBB_t* bbb, const Another_t* a)
{
  return (bbb != NULL) ? bbb->addAnother(a) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Another_t objects in this BBB_t.
 */
LIBSBML_EXTERN
unsigned int
BBB_getNumAnothers(BBB_t* bbb)
{
  return (bbb != NULL) ? bbb->getNumAnothers() : SBML_INT_MAX;
}


/*
 * Creates a new Another_t object, adds it to this BBB_t object and returns the
 * Another_t object created.
 */
LIBSBML_EXTERN
Another_t*
BBB_createAnother(BBB_t* bbb)
{
  return (bbb != NULL) ? bbb->createAnother() : NULL;
}


/*
 * Removes the nth Another_t from this BBB_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Another_t*
BBB_removeAnother(BBB_t* bbb, unsigned int n)
{
  return (bbb != NULL) ? bbb->removeAnother(n) : NULL;
}


/*
 * Removes the Another_t from this BBB_t based on its identifier and returns a
 * pointer to it.
 */
LIBSBML_EXTERN
Another_t*
BBB_removeAnotherById(BBB_t* bbb, const char* sid)
{
  return (bbb != NULL && sid != NULL) ? bbb->removeAnother(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * BBB_t object have been set.
 */
LIBSBML_EXTERN
int
BBB_hasRequiredAttributes(const BBB_t * bbb)
{
  return (bbb != NULL) ? static_cast<int>(bbb->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


