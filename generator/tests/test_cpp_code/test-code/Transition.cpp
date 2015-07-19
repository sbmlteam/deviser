/**
 * @file: Transition.cpp
 * @brief: Implementation of Transition.
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
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
#include <sbml/packages/qual/sbml/Transition.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Transition using the given SBML @p level, @ p version and
 * package version values.
 */
Transition::Transition(unsigned int level,
                       unsigned int version,
                       unsigned int pkgVersion)
  : SBase(level, version)
  , mId ("")
  , mName ("")
  , mInputs (NULL)
  , mOutputs (NULL)
  , mFunctionTerms (NULL)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new Transition using the given QualPkgNamespaces object.
 */
Transition::Transition(QualPkgNamespaces *qualns)
  : SBase(qualns)
  , mId ("")
  , mName ("")
  , mInputs (NULL)
  , mOutputs (NULL)
  , mFunctionTerms (NULL)
{
  setElementNamespace(qualns->getURI());
  connectToChild();
  loadPlugins(qualns);
}


/*
 * Copy constructor for Transition.
 */
Transition::Transition(const Transition& orig)
  : SBase( orig )
  , mId ( orig.mId )
  , mName ( orig.mName )
  , mInputs ( orig.mInputs )
  , mOutputs ( orig.mOutputs )
  , mFunctionTerms ( orig.mFunctionTerms )
{
  connectToChild();
}


/*
 * Assignment operator for Transition.
 */
Transition&
Transition::operator=(const Transition& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mId = rhs.mId;
    mName = rhs.mName;
    mInputs = rhs.mInputs;
    mOutputs = rhs.mOutputs;
    mFunctionTerms = rhs.mFunctionTerms;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Transition object.
 */
Transition*
Transition::clone() const
{
  return new Transition(*this);
}


/*
 * Destructor for Transition.
 */
Transition::~Transition()
{
}


/*
 * Returns the value of the "id" attribute of this Transition.
 */
const std::string&
Transition::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this Transition.
 */
const std::string&
Transition::getName() const
{
  return mName;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * Transition's "id" attribute has been set.
 */
bool
Transition::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * Transition's "name" attribute has been set.
 */
bool
Transition::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this Transition.
 */
int
Transition::setId(const std::string& id)
{
  return SyntaxChecker::checkAndSetSId(id, mId);
}


/*
 * Sets the value of the "name" attribute of this Transition.
 */
int
Transition::setName(const std::string& name)
{
  mName = name;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this Transition.
 */
int
Transition::unsetId()
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
 * Unsets the value of the "name" attribute of this Transition.
 */
int
Transition::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the ListOfInputs from this Transition.
 */
const ListOfInputs*
Transition::getListOfInputs() const
{
  return &mInputs;
}


/*
 * Returns the ListOfInputs from this Transition.
 */
ListOfInputs*
Transition::getListOfInputs()
{
  return &mInputs;
}


/*
 * Get an Input from the Transition.
 */
Input*
Transition::getInput(unsigned int n)
{
  return mInputs.get(n);
}


/*
 * Get an Input from the Transition.
 */
const Input*
Transition::getInput(unsigned int n) const
{
  return mInputs.get(n);
}


/*
 * Get an Input from the Transition based on its identifier.
 */
Input*
Transition::getInput(const std::string& sid)
{
  return mInputs.get(sid);
}


/*
 * Get an Input from the Transition based on its identifier.
 */
const Input*
Transition::getInput(const std::string& sid) const
{
  return mInputs.get(sid);
}


/*
 * Get an Input from the Transition based on the QualitativeSpecies to which it
 * refers.
 */
const Input*
Transition::getInputByQualitativeSpecies(const std::string& sid) const
{
  return mInputs.getByQualitativeSpecies(sid);
}


/*
 * Get an Input from the Transition based on the QualitativeSpecies to which it
 * refers.
 */
Input*
Transition::getInputByQualitativeSpecies(const std::string& sid)
{
  return mInputs.getByQualitativeSpecies(sid);
}


/*
 * Adds a copy of the given Input to this Transition.
 */
int
Transition::addInput(const Input* i)
{
  if (i == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (i->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != i->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != i->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(i)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (i->isSetId() && (mInputs->get(i->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    mInputs.append(i);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of Input objects in this Transition.
 */
unsigned int
Transition::getNumInputs() const
{
  return mInputs.size();
}


/*
 * Creates a new Input object, adds it to this Transition object and returns
 * the Input object created.
 */
Input*
Transition::createInput()
{
  Input* i = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    i = new Input(qualns);
    delete qualns;
  }
  catch (...)
  {
  }

  if (i != NULL)
  {
    mInputs.appendAndOwn(i);
  }

  return i;
}


/*
 * Removes the nth Input from this Transition and returns a pointer to it.
 */
Input*
Transition::removeInput(unsigned int n)
{
  return mInputs.remove(n);
}


/*
 * Removes the Input from this Transition based on its identifier and returns a
 * pointer to it.
 */
Input*
Transition::removeInput(const std::string& sid)
{
  return mInputs.remove(sid);
}


/*
 * Returns the ListOfOutputs from this Transition.
 */
const ListOfOutputs*
Transition::getListOfOutputs() const
{
  return &mOutputs;
}


/*
 * Returns the ListOfOutputs from this Transition.
 */
ListOfOutputs*
Transition::getListOfOutputs()
{
  return &mOutputs;
}


/*
 * Get an Output from the Transition.
 */
Output*
Transition::getOutput(unsigned int n)
{
  return mOutputs.get(n);
}


/*
 * Get an Output from the Transition.
 */
const Output*
Transition::getOutput(unsigned int n) const
{
  return mOutputs.get(n);
}


/*
 * Get an Output from the Transition based on its identifier.
 */
Output*
Transition::getOutput(const std::string& sid)
{
  return mOutputs.get(sid);
}


/*
 * Get an Output from the Transition based on its identifier.
 */
const Output*
Transition::getOutput(const std::string& sid) const
{
  return mOutputs.get(sid);
}


/*
 * Get an Output from the Transition based on the QualitativeSpecies to which
 * it refers.
 */
const Output*
Transition::getOutputByQualitativeSpecies(const std::string& sid) const
{
  return mOutputs.getByQualitativeSpecies(sid);
}


/*
 * Get an Output from the Transition based on the QualitativeSpecies to which
 * it refers.
 */
Output*
Transition::getOutputByQualitativeSpecies(const std::string& sid)
{
  return mOutputs.getByQualitativeSpecies(sid);
}


/*
 * Adds a copy of the given Output to this Transition.
 */
int
Transition::addOutput(const Output* o)
{
  if (o == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (o->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != o->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != o->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(o)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else if (o->isSetId() && (mOutputs->get(o->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    mOutputs.append(o);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of Output objects in this Transition.
 */
unsigned int
Transition::getNumOutputs() const
{
  return mOutputs.size();
}


/*
 * Creates a new Output object, adds it to this Transition object and returns
 * the Output object created.
 */
Output*
Transition::createOutput()
{
  Output* o = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    o = new Output(qualns);
    delete qualns;
  }
  catch (...)
  {
  }

  if (o != NULL)
  {
    mOutputs.appendAndOwn(o);
  }

  return o;
}


/*
 * Removes the nth Output from this Transition and returns a pointer to it.
 */
Output*
Transition::removeOutput(unsigned int n)
{
  return mOutputs.remove(n);
}


/*
 * Removes the Output from this Transition based on its identifier and returns
 * a pointer to it.
 */
Output*
Transition::removeOutput(const std::string& sid)
{
  return mOutputs.remove(sid);
}


/*
 * Returns the ListOfFunctionTerms from this Transition.
 */
const ListOfFunctionTerms*
Transition::getListOfFunctionTerms() const
{
  return &mFunctionTerms;
}


/*
 * Returns the ListOfFunctionTerms from this Transition.
 */
ListOfFunctionTerms*
Transition::getListOfFunctionTerms()
{
  return &mFunctionTerms;
}


/*
 * Get a FunctionTerm from the Transition.
 */
FunctionTerm*
Transition::getFunctionTerm(unsigned int n)
{
  return mFunctionTerms.get(n);
}


/*
 * Get a FunctionTerm from the Transition.
 */
const FunctionTerm*
Transition::getFunctionTerm(unsigned int n) const
{
  return mFunctionTerms.get(n);
}


/*
 * Adds a copy of the given FunctionTerm to this Transition.
 */
int
Transition::addFunctionTerm(const FunctionTerm* ft)
{
  if (ft == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (ft->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != ft->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ft->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(ft)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    mFunctionTerms.append(ft);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of FunctionTerm objects in this Transition.
 */
unsigned int
Transition::getNumFunctionTerms() const
{
  return mFunctionTerms.size();
}


/*
 * Creates a new FunctionTerm object, adds it to this Transition object and
 * returns the FunctionTerm object created.
 */
FunctionTerm*
Transition::createFunctionTerm()
{
  FunctionTerm* ft = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    ft = new FunctionTerm(qualns);
    delete qualns;
  }
  catch (...)
  {
  }

  if (ft != NULL)
  {
    mFunctionTerms.appendAndOwn(ft);
  }

  return ft;
}


/*
 * Removes the nth FunctionTerm from this Transition and returns a pointer to
 * it.
 */
FunctionTerm*
Transition::removeFunctionTerm(unsigned int n)
{
  return mFunctionTerms.remove(n);
}


/*
 * Returns the XML name of this Transition object.
 */
const std::string&
Transition::getElementName() const
{
  static const string name = "transition";
  return name;
}


/*
 * Returns the libSBML typcode of this Transition object.
 */
int
Transition::getTypeCode() const
{
  return SBML_QUAL_TRANSITION;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * Transition object have been set.
 */
bool
Transition::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this Transition
 * object have been set.
 */
bool
Transition::hasRequiredElements() const
{
  bool allPresent = true;

  if (getNumFunctionTerms() == 0)
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
Transition::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (getNumInputs() > 0)
  {
    mInputs.write(stream);
  }

  if (getNumOutputs() > 0)
  {
    mOutputs.write(stream);
  }

  if (getNumFunctionTerms() > 0)
  {
    mFunctionTerms.write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Transition::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  mInputs.accept(v);

  mOutputs.accept(v);

  mFunctionTerms.accept(v);

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Transition::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  mInputs.setSBMLDocument(d);

  mOutputs.setSBMLDocument(d);

  mFunctionTerms.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Transition::connectToChild()
{
  SBase::connectToChild();

  mInputs.connectToParent(this);

  mOutputs.connectToParent(this);

  mFunctionTerms.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
Transition::enablePackageInternal(const std::string& pkgURI,
                                  const std::string& pkgPrefix,
                                  bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  mInputs.enablePackageInternal(pkgURI, pkgPrefix, flag);

  mOutputs.enablePackageInternal(pkgURI, pkgPrefix, flag);

  mFunctionTerms.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
Transition::getElementBySId(const std::string& id)
{
  if (id.empty()) return NULL;
  SBase* obj = mInputs.getElementBySId(id);
  if (obj != NULL) {
    return obj;
  }
  obj = mOutputs.getElementBySId(id);
  if (obj != NULL) {
    return obj;
  }
  obj = mFunctionTerms.getElementBySId(id);
  return obj;
}




/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
Transition::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty()) return NULL;

  if (mInputs.getMetaId() == metaid) return &mInputs;
  if (mOutputs.getMetaId() == metaid) return &mOutputs;
  if (mFunctionTerms.getMetaId() == metaid) return &mFunctionTerms;
  
  if (mFunctionTerms.isSetDefaultTerm() == true &&
    mFunctionTerms.getDefaultTerm()->getMetaId() == metaid)
  {
    return mFunctionTerms.getDefaultTerm();
  }

  SBase* obj = mInputs.getElementByMetaId(metaid);
  if (obj != NULL) {
    return obj;
  }
  obj = mOutputs.getElementByMetaId(metaid);
  if (obj != NULL) {
    return obj;
  }
  obj = mFunctionTerms.getElementByMetaId(metaid);
  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
Transition::getAllElements(ElementFilter * filter = NULL)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_LIST(ret, sublist, mInputs, filter);
  ADD_FILTERED_LIST(ret, sublist, mOutputs, filter);
  ADD_FILTERED_LIST(ret, sublist, mFunctionTerms, filter);

  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}


/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
Transition::createObject(XMLInputStream& stream)
{
  SBase* object = NULL;

  const string& name = stream.peek().getName();

  if (name == "listOfInputs")
  {
    if (mInputs.size() != 0)
    {
      getErrorLog()->logPackageError("qual", QualTransitionLOElements, 
        getPackageVersion(), getLevel(), getVersion());
    }
      
    object = &mInputs;
  }
  else if (name == "listOfOutputs")
  {
    if (mOutputs.size() != 0)
    {
      getErrorLog()->logPackageError("qual", QualTransitionLOElements, 
        getPackageVersion(), getLevel(), getVersion());
    }
      
    object = &mOutputs;
  }
  else if (name == "listOfFunctionTerms")
  {
    object = &mFunctionTerms;
  }


  return object;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
Transition::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("name");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Transition::readAttributes(const XMLAttributes& attributes,
                           const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (static_cast<ListOfTransitions*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->geErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("qual", QualLOTransitionAllowedAttributes,
          getPackageVersion(), level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("qual", QualLOTransitionAllowedAttributes,
          getPackageVersion(), level, version, details);
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->geErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("qual", QualTransitionAllowedAttributes,
        getPackageVersion(), level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("qual", QualTransitionAllowedAttributes,
        getPackageVersion(), level, version, details);
    }
  }

  // 
  // id SId (use = "optional" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<Transition>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(InvalidIdSyntax, level, version, "The id '" + mId + "' does not
        conform to the syntax.");
    }
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<Transition>");
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Transition::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */



LIBSBML_CPP_NAMESPACE_END


