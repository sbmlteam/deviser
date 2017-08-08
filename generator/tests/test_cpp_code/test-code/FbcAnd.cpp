/**
 * @file FbcAnd.cpp
 * @brief Implementation of the FbcAnd class.
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
#include <sbml/packages/fbc/sbml/FbcAnd.h>
#include <sbml/packages/fbc/validator/FbcSBMLError.h>
#include <sbml/util/ElementFilter.h>

#include <sbml/packages/fbc/sbml/FbcAnd.h>
#include <sbml/packages/fbc/sbml/FbcOr.h>
#include <sbml/packages/fbc/sbml/GeneProductRef.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new FbcAnd using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 */
FbcAnd::FbcAnd(unsigned int level,
               unsigned int version,
               unsigned int pkgVersion)
  : Association(level, version)
  , mAssociations (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new FbcPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new FbcAnd using the given FbcPkgNamespaces object.
 */
FbcAnd::FbcAnd(FbcPkgNamespaces *fbcns)
  : Association(fbcns)
  , mAssociations (fbcns)
{
  setElementNamespace(fbcns->getURI());
  connectToChild();
  loadPlugins(fbcns);
}


/*
 * Copy constructor for FbcAnd.
 */
FbcAnd::FbcAnd(const FbcAnd& orig)
  : Association( orig )
  , mAssociations ( orig.mAssociations )
{
  connectToChild();
}


/*
 * Assignment operator for FbcAnd.
 */
FbcAnd&
FbcAnd::operator=(const FbcAnd& rhs)
{
  if (&rhs != this)
  {
    Association::operator=(rhs);
    mAssociations = rhs.mAssociations;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this FbcAnd object.
 */
FbcAnd*
FbcAnd::clone() const
{
  return new FbcAnd(*this);
}


/*
 * Destructor for FbcAnd.
 */
FbcAnd::~FbcAnd()
{
}


/*
 * Returns the ListOfAssociations from this FbcAnd.
 */
const ListOfAssociations*
FbcAnd::getListOfAssociations() const
{
  return &mAssociations;
}


/*
 * Returns the ListOfAssociations from this FbcAnd.
 */
ListOfAssociations*
FbcAnd::getListOfAssociations()
{
  return &mAssociations;
}


/*
 * Get an Association from the FbcAnd.
 */
Association*
FbcAnd::getAssociation(unsigned int n)
{
  return mAssociations.get(n);
}


/*
 * Get an Association from the FbcAnd.
 */
const Association*
FbcAnd::getAssociation(unsigned int n) const
{
  return mAssociations.get(n);
}


/*
 * Adds a copy of the given Association to this FbcAnd.
 */
int
FbcAnd::addAssociation(const Association* a)
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
  else
  {
    return mAssociations.append(a);
  }
}


/*
 * Get the number of Association objects in this FbcAnd.
 */
unsigned int
FbcAnd::getNumAssociations() const
{
  return mAssociations.size();
}


/*
 * Creates a new FbcAnd object, adds it to this FbcAnd object and returns the
 * FbcAnd object created.
 */
FbcAnd*
FbcAnd::createAnd()
{
  FbcAnd* fa = NULL;

  try
  {
    FBC_CREATE_NS_WITH_VERSION(fbcns, getSBMLNamespaces(),
      getPackageVersion());
    fa = new FbcAnd(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (fa != NULL)
  {
    mAssociations.appendAndOwn(fa);
  }

  return fa;
}


/*
 * Creates a new FbcOr object, adds it to this FbcAnd object and returns the
 * FbcOr object created.
 */
FbcOr*
FbcAnd::createOr()
{
  FbcOr* fo = NULL;

  try
  {
    FBC_CREATE_NS_WITH_VERSION(fbcns, getSBMLNamespaces(),
      getPackageVersion());
    fo = new FbcOr(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (fo != NULL)
  {
    mAssociations.appendAndOwn(fo);
  }

  return fo;
}


/*
 * Creates a new GeneProductRef object, adds it to this FbcAnd object and
 * returns the GeneProductRef object created.
 */
GeneProductRef*
FbcAnd::createGeneProductRef()
{
  GeneProductRef* gpr = NULL;

  try
  {
    FBC_CREATE_NS_WITH_VERSION(fbcns, getSBMLNamespaces(),
      getPackageVersion());
    gpr = new GeneProductRef(fbcns);
    delete fbcns;
  }
  catch (...)
  {
  }

  if (gpr != NULL)
  {
    mAssociations.appendAndOwn(gpr);
  }

  return gpr;
}


/*
 * Removes the nth Association from this FbcAnd and returns a pointer to it.
 */
Association*
FbcAnd::removeAssociation(unsigned int n)
{
  return mAssociations.remove(n);
}


/*
 * Returns the XML element name of this FbcAnd object.
 */
const std::string&
FbcAnd::getElementName() const
{
  static const string name = "and";
  return name;
}


/*
 * Returns the libSBML type code for this FbcAnd object.
 */
int
FbcAnd::getTypeCode() const
{
  return SBML_FBC_AND;
}


/*
 * Predicate returning @c true if all the required attributes for this FbcAnd
 * object have been set.
 */
bool
FbcAnd::hasRequiredAttributes() const
{
  bool allPresent = Association::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this FbcAnd
 * object have been set.
 */
bool
FbcAnd::hasRequiredElements() const
{
  bool allPresent = Association::hasRequiredElements();

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
FbcAnd::writeElements(XMLOutputStream& stream) const
{
  Association::writeElements(stream);

  for (unsigned int i = 0; i < getNumAssociations(); i++)
  {
    getAssociation(i)->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
FbcAnd::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  mAssociations.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
FbcAnd::setSBMLDocument(SBMLDocument* d)
{
  Association::setSBMLDocument(d);

  mAssociations.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
FbcAnd::connectToChild()
{
  Association::connectToChild();

  mAssociations.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
FbcAnd::enablePackageInternal(const std::string& pkgURI,
                              const std::string& pkgPrefix,
                              bool flag)
{
  Association::enablePackageInternal(pkgURI, pkgPrefix, flag);

  mAssociations.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = Association::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = Association::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = Association::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::getAttribute(const std::string& attributeName,
                     unsigned int& value) const
{
  int return_value = Association::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::getAttribute(const std::string& attributeName,
                     std::string& value) const
{
  int return_value = Association::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::getAttribute(const std::string& attributeName,
                     const char* value) const
{
  int return_value = Association::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this FbcAnd's attribute "attributeName" is
 * set.
 */
bool
FbcAnd::isSetAttribute(const std::string& attributeName) const
{
  bool value = Association::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = Association::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::setAttribute(const std::string& attributeName, int value)
{
  int return_value = Association::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::setAttribute(const std::string& attributeName, double value)
{
  int return_value = Association::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = Association::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::setAttribute(const std::string& attributeName,
                     const std::string& value)
{
  int return_value = Association::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::setAttribute(const std::string& attributeName, const char* value)
{
  int return_value = Association::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this FbcAnd.
 */
int
FbcAnd::unsetAttribute(const std::string& attributeName)
{
  int value = Association::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this FbcAnd.
 */
SBase*
FbcAnd::createChildObject(const std::string& elementName)
{
  Association* obj = NULL;

  if (elementName == "and")
  {
    return createAnd();
  }
  else if (elementName == "or")
  {
    return createOr();
  }
  else if (elementName == "geneProductRef")
  {
    return createGeneProductRef();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this FbcAnd.
 */
int
FbcAnd::addChildObject(const std::string& elementName, const SBase* element)
{
  if (elementName == "association" && element->getTypeCode() ==
    SBML_FBC_ASSOCIATION)
  {
    return addAssociation((const Association*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * FbcAnd.
 */
SBase*
FbcAnd::removeChildObject(const std::string& elementName,
                          const std::string& id)
{
  if (elementName == "association")
  {
    return removeAssociation(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this FbcAnd.
 */
unsigned int
FbcAnd::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "association")
  {
    return getNumAssociations();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this FbcAnd.
 */
SBase*
FbcAnd::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "association")
  {
    return getAssociation(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
FbcAnd::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mAssociations.getElementBySId(id);

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
FbcAnd::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mAssociations.getMetaId() == metaid)
  {
    return &mAssociations;
  }

  obj = mAssociations.getElementByMetaId(metaid);

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
FbcAnd::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mAssociations, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
FbcAnd::createObject(XMLInputStream& stream)
{
  SBase* obj = Association::createObject(stream);

  const std::string& name = stream.peek().getName();

  obj = mAssociations.createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
FbcAnd::addExpectedAttributes(ExpectedAttributes& attributes)
{
  Association::addExpectedAttributes(attributes);

  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
  }
  else
  {
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
FbcAnd::readAttributes(const XMLAttributes& attributes,
                       const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  Association::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("fbc", FbcFbcAndAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("fbc", FbcFbcAndAllowedCoreAttributes, pkgVersion,
        level, version, details);
    }
  }

  if (pkgVersion == 1)
  {
    readV1Attributes(attributes);
  }
  else
  {
    readV2Attributes(attributes);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
FbcAnd::readV1Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
FbcAnd::readV2Attributes(const XMLAttributes& attributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  bool assigned = false;
  unsigned int pkgVersion = getPackageVersion();
  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
FbcAnd::writeAttributes(XMLOutputStream& stream) const
{
  Association::writeAttributes(stream);

  unsigned int pkgVersion = getPackageVersion();

  if (pkgVersion == 1)
  {
    writeV1Attributes(stream);
  }
  else
  {
    writeV2Attributes(stream);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
FbcAnd::writeV1Attributes(XMLOutputStream& stream) const
{
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
FbcAnd::writeV2Attributes(XMLOutputStream& stream) const
{
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new FbcAnd_t using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 */
LIBSBML_EXTERN
FbcAnd_t *
FbcAnd_create(unsigned int level,
              unsigned int version,
              unsigned int pkgVersion)
{
  return new FbcAnd(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this FbcAnd_t object.
 */
LIBSBML_EXTERN
FbcAnd_t*
FbcAnd_clone(const FbcAnd_t* fa)
{
  if (fa != NULL)
  {
    return static_cast<FbcAnd_t*>(fa->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this FbcAnd_t object.
 */
LIBSBML_EXTERN
void
FbcAnd_free(FbcAnd_t* fa)
{
  if (fa != NULL)
  {
    delete fa;
  }
}


/*
 * Returns a ListOf_t* containing Association_t objects from this FbcAnd_t.
 */
LIBSBML_EXTERN
ListOf_t*
FbcAnd_getListOfAssociations(FbcAnd_t* fa)
{
  return (fa != NULL) ? fa->getListOfAssociations() : NULL;
}


/*
 * Get an Association_t from the FbcAnd_t.
 */
LIBSBML_EXTERN
const Association_t*
FbcAnd_getAssociation(FbcAnd_t* fa, unsigned int n)
{
  return (fa != NULL) ? fa->getAssociation(n) : NULL;
}


/*
 * Adds a copy of the given Association_t to this FbcAnd_t.
 */
LIBSBML_EXTERN
int
FbcAnd_addAssociation(FbcAnd_t* fa, const Association_t* a)
{
  return (fa != NULL) ? fa->addAssociation(a) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Association_t objects in this FbcAnd_t.
 */
LIBSBML_EXTERN
unsigned int
FbcAnd_getNumAssociations(FbcAnd_t* fa)
{
  return (fa != NULL) ? fa->getNumAssociations() : SBML_INT_MAX;
}


/*
 * Creates a new FbcAnd_t object, adds it to this FbcAnd_t object and returns
 * the FbcAnd_t object created.
 */
LIBSBML_EXTERN
FbcAnd_t*
FbcAnd_createAnd(FbcAnd_t* fa)
{
  return (fa != NULL) ? fa->createAnd() : NULL;
}


/*
 * Creates a new FbcOr_t object, adds it to this FbcAnd_t object and returns
 * the FbcOr_t object created.
 */
LIBSBML_EXTERN
FbcOr_t*
FbcAnd_createOr(FbcAnd_t* fa)
{
  return (fa != NULL) ? fa->createOr() : NULL;
}


/*
 * Creates a new GeneProductRef_t object, adds it to this FbcAnd_t object and
 * returns the GeneProductRef_t object created.
 */
LIBSBML_EXTERN
GeneProductRef_t*
FbcAnd_createGeneProductRef(FbcAnd_t* fa)
{
  return (fa != NULL) ? fa->createGeneProductRef() : NULL;
}


/*
 * Removes the nth Association_t from this FbcAnd_t and returns a pointer to
 * it.
 */
LIBSBML_EXTERN
Association_t*
FbcAnd_removeAssociation(FbcAnd_t* fa, unsigned int n)
{
  return (fa != NULL) ? fa->removeAssociation(n) : NULL;
}


/*
 * Predicate returning @c 1 if all the required attributes for this FbcAnd_t
 * object have been set.
 */
LIBSBML_EXTERN
int
FbcAnd_hasRequiredAttributes(const FbcAnd_t * fa)
{
  return (fa != NULL) ? static_cast<int>(fa->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this FbcAnd_t
 * object have been set.
 */
LIBSBML_EXTERN
int
FbcAnd_hasRequiredElements(const FbcAnd_t * fa)
{
  return (fa != NULL) ? static_cast<int>(fa->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


