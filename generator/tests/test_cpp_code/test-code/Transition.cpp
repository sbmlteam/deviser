/**
 * @file Transition.cpp
 * @brief Implementation of the Transition class.
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
#include <sbml/packages/qual/sbml/Transition.h>
#include <sbml/packages/qual/sbml/ListOfTransitions.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>
#include <sbml/util/ElementFilter.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Transition using the given SBML Level, Version and
 * &ldquo;qual&rdquo; package version.
 */
Transition::Transition(unsigned int level,
                       unsigned int version,
                       unsigned int pkgVersion)
  : SBase(level, version)
  , mInputs (level, version, pkgVersion)
  , mOutputs (level, version, pkgVersion)
  , mFunctionTerms (level, version, pkgVersion)
{
  setSBMLNamespacesAndOwn(new QualPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new Transition using the given QualPkgNamespaces object.
 */
Transition::Transition(QualPkgNamespaces *qualns)
  : SBase(qualns)
  , mInputs (qualns)
  , mOutputs (qualns)
  , mFunctionTerms (qualns)
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
 * Predicate returning @c true if this Transition's "id" attribute is set.
 */
bool
Transition::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this Transition's "name" attribute is set.
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
  else if (i->isSetId() && (mInputs.get(i->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mInputs.append(i);
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
  else if (o->isSetId() && (mOutputs.get(o->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mOutputs.append(o);
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
  else if (ft->hasRequiredElements() == false)
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
    return mFunctionTerms.append(ft);
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
 * Returns the value of the "defaultTerm" element of this Transition.
 */
const DefaultTerm*
Transition::getDefaultTerm() const
{
  return mDefaultTerm;
}


/*
 * Returns the value of the "defaultTerm" element of this Transition.
 */
DefaultTerm*
Transition::getDefaultTerm()
{
  return mDefaultTerm;
}


/*
 * Predicate returning @c true if this Transition's "defaultTerm" element is
 * set.
 */
bool
Transition::isSetDefaultTerm() const
{
  return (mDefaultTerm != NULL);
}


/*
 * Sets the value of the "defaultTerm" element of this Transition.
 */
int
Transition::setDefaultTerm(const DefaultTerm* defaultTerm)
{
  if (mDefaultTerm == defaultTerm)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (defaultTerm == NULL)
  {
    delete mDefaultTerm;
    mDefaultTerm = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mDefaultTerm;
    mDefaultTerm = (defaultTerm != NULL) ? defaultTerm->clone() : NULL;
    if (mDefaultTerm != NULL)
    {
      mDefaultTerm->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new DefaultTerm object, adds it to this Transition object and
 * returns the DefaultTerm object created.
 */
DefaultTerm*
Transition::createDefaultTerm()
{
}


/*
 * Unsets the value of the "defaultTerm" element of this Transition.
 */
int
Transition::unsetDefaultTerm()
{
  delete mDefaultTerm;
  mDefaultTerm = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this Transition object.
 */
const std::string&
Transition::getElementName() const
{
  static const string name = "transition";
  return name;
}


/*
 * Returns the libSBML type code for this Transition object.
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



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
Transition::updateSBMLNamespace(const std::string& package,
                                unsigned int level,
                                unsigned int version)
{
  SBase::updateSBMLNamespace(package, level, version);

  mInputs.updateSBMLNamespace(package, level, version);

  mOutputs.updateSBMLNamespace(package, level, version);

  mFunctionTerms.updateSBMLNamespace(package, level, version);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::getAttribute(const std::string& attributeName,
                         std::string& value) const
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
  else if (attributeName == "name")
  {
    value = getName();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Transition's attribute "attributeName"
 * is set.
 */
bool
Transition::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "name")
  {
    value = isSetName();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "name")
  {
    return_value = setName(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Transition.
 */
int
Transition::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "name")
  {
    value = unsetName();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this Transition.
 */
SBase*
Transition::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "input")
  {
    return createInput();
  }
  else if (elementName == "output")
  {
    return createOutput();
  }
  else if (elementName == "functionTerm")
  {
    return createFunctionTerm();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this Transition.
 */
int
Transition::addChildObject(const std::string& elementName,
                           const SBase* element)
{
  if (elementName == "input" && element->getTypeCode() == SBML_QUAL_INPUT)
  {
    return addInput((const Input*)(element));
  }
  else if (elementName == "output" && element->getTypeCode() ==
    SBML_QUAL_OUTPUT)
  {
    return addOutput((const Output*)(element));
  }
  else if (elementName == "functionTerm" && element->getTypeCode() ==
    SBML_QUAL_FUNCTION_TERM)
  {
    return addFunctionTerm((const FunctionTerm*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Transition.
 */
SBase*
Transition::removeChildObject(const std::string& elementName,
                              const std::string& id)
{
  if (elementName == "input")
  {
    return removeInput(id);
  }
  else if (elementName == "output")
  {
    return removeOutput(id);
  }
  else if (elementName == "functionTerm")
  {
    for (unsigned int i = 0; i < getNumFunctionTerms(); i++)
    {
      if (getFunctionTerm(i)->getId() == id)
      {
        return removeFunctionTerm(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this Transition.
 */
unsigned int
Transition::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "input")
  {
    return getNumInputs();
  }
  else if (elementName == "output")
  {
    return getNumOutputs();
  }
  else if (elementName == "functionTerm")
  {
    return getNumFunctionTerms();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this Transition.
 */
SBase*
Transition::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "input")
  {
    return getInput(index);
  }
  else if (elementName == "output")
  {
    return getOutput(index);
  }
  else if (elementName == "functionTerm")
  {
    return getFunctionTerm(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
Transition::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mInputs.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mOutputs.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mFunctionTerms.getElementBySId(id);

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
Transition::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mInputs.getMetaId() == metaid)
  {
    return &mInputs;
  }

  if (mOutputs.getMetaId() == metaid)
  {
    return &mOutputs;
  }

  if (mFunctionTerms.getMetaId() == metaid)
  {
    return &mFunctionTerms;
  }

  obj = mInputs.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mOutputs.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mFunctionTerms.getElementByMetaId(metaid);

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
Transition::getAllElements(ElementFilter* filter)
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
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfInputs")
  {
    if (mInputs.size() != 0)
    {
      getErrorLog()->logPackageError("qual", QualTransitionAllowedElements,
        getPackageVersion(), getLevel(), getVersion());
    }

    obj = &mInputs;
  }
  else if (name == "listOfOutputs")
  {
    if (mOutputs.size() != 0)
    {
      getErrorLog()->logPackageError("qual", QualTransitionAllowedElements,
        getPackageVersion(), getLevel(), getVersion());
    }

    obj = &mOutputs;
  }
  else if (name == "listOfFunctionTerms")
  {
    if (mFunctionTerms.size() != 0)
    {
      getErrorLog()->logPackageError("qual", QualTransitionAllowedElements,
        getPackageVersion(), getLevel(), getVersion());
    }

    obj = &mFunctionTerms;
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
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (log && getParentSBMLObject() &&
    static_cast<ListOfTransitions*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownPackageAttribute);
        log->logPackageError("qual", QualModelLOTransitionsAllowedAttributes,
          pkgVersion, level, version, details);
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("qual",
          QualModelLOTransitionsAllowedCoreAttributes, pkgVersion, level,
            version, details);
      }
    }
  }

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
        log->logPackageError("qual", QualTransitionAllowedAttributes,
          pkgVersion, level, version, details, getLine(), getColumn());
      }
      else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logPackageError("qual", QualTransitionAllowedCoreAttributes,
          pkgVersion, level, version, details, getLine(), getColumn());
      }
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
      log->logPackageError("qual", QualIdSyntaxRule, pkgVersion, level,
        version, "The id on the <" + getElementName() + "> is '" + mId + "', "
          "which does not conform to the syntax.", getLine(), getColumn());
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


/*
 * Creates a new Transition_t using the given SBML Level, Version and
 * &ldquo;qual&rdquo; package version.
 */
LIBSBML_EXTERN
Transition_t *
Transition_create(unsigned int level,
                  unsigned int version,
                  unsigned int pkgVersion)
{
  return new Transition(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this Transition_t object.
 */
LIBSBML_EXTERN
Transition_t*
Transition_clone(const Transition_t* t)
{
  if (t != NULL)
  {
    return static_cast<Transition_t*>(t->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Transition_t object.
 */
LIBSBML_EXTERN
void
Transition_free(Transition_t* t)
{
  if (t != NULL)
  {
    delete t;
  }
}


/*
 * Returns the value of the "id" attribute of this Transition_t.
 */
LIBSBML_EXTERN
char *
Transition_getId(const Transition_t * t)
{
  if (t == NULL)
  {
    return NULL;
  }

  return t->getId().empty() ? NULL : safe_strdup(t->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this Transition_t.
 */
LIBSBML_EXTERN
char *
Transition_getName(const Transition_t * t)
{
  if (t == NULL)
  {
    return NULL;
  }

  return t->getName().empty() ? NULL : safe_strdup(t->getName().c_str());
}


/*
 * Predicate returning @c 1 (true) if this Transition_t's "id" attribute is
 * set.
 */
LIBSBML_EXTERN
int
Transition_isSetId(const Transition_t * t)
{
  return (t != NULL) ? static_cast<int>(t->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Transition_t's "name" attribute is
 * set.
 */
LIBSBML_EXTERN
int
Transition_isSetName(const Transition_t * t)
{
  return (t != NULL) ? static_cast<int>(t->isSetName()) : 0;
}


/*
 * Sets the value of the "id" attribute of this Transition_t.
 */
LIBSBML_EXTERN
int
Transition_setId(Transition_t * t, const char * id)
{
  return (t != NULL) ? t->setId(id) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this Transition_t.
 */
LIBSBML_EXTERN
int
Transition_setName(Transition_t * t, const char * name)
{
  return (t != NULL) ? t->setName(name) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this Transition_t.
 */
LIBSBML_EXTERN
int
Transition_unsetId(Transition_t * t)
{
  return (t != NULL) ? t->unsetId() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this Transition_t.
 */
LIBSBML_EXTERN
int
Transition_unsetName(Transition_t * t)
{
  return (t != NULL) ? t->unsetName() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing Input_t objects from this Transition_t.
 */
LIBSBML_EXTERN
ListOf_t*
Transition_getListOfInputs(Transition_t* t)
{
  return (t != NULL) ? t->getListOfInputs() : NULL;
}


/*
 * Get an Input_t from the Transition_t.
 */
LIBSBML_EXTERN
Input_t*
Transition_getInput(Transition_t* t, unsigned int n)
{
  return (t != NULL) ? t->getInput(n) : NULL;
}


/*
 * Get an Input_t from the Transition_t based on its identifier.
 */
LIBSBML_EXTERN
Input_t*
Transition_getInputById(Transition_t* t, const char *sid)
{
  return (t != NULL && sid != NULL) ? t->getInput(sid) : NULL;
}


/*
 * Get an Input_t from the Transition_t based on the QualitativeSpecies to
 * which it refers.
 */
LIBSBML_EXTERN
Input_t*
Transition_getInputByQualitativeSpecies(Transition_t* t, const char *sid)
{
  return (t != NULL && sid != NULL) ? t->getInputByQualitativeSpecies(sid) :
    NULL;
}


/*
 * Adds a copy of the given Input_t to this Transition_t.
 */
LIBSBML_EXTERN
int
Transition_addInput(Transition_t* t, const Input_t* i)
{
  return (t != NULL) ? t->addInput(i) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Input_t objects in this Transition_t.
 */
LIBSBML_EXTERN
unsigned int
Transition_getNumInputs(Transition_t* t)
{
  return (t != NULL) ? t->getNumInputs() : SBML_INT_MAX;
}


/*
 * Creates a new Input_t object, adds it to this Transition_t object and
 * returns the Input_t object created.
 */
LIBSBML_EXTERN
Input_t*
Transition_createInput(Transition_t* t)
{
  return (t != NULL) ? t->createInput() : NULL;
}


/*
 * Removes the nth Input_t from this Transition_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Input_t*
Transition_removeInput(Transition_t* t, unsigned int n)
{
  return (t != NULL) ? t->removeInput(n) : NULL;
}


/*
 * Removes the Input_t from this Transition_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
Input_t*
Transition_removeInputById(Transition_t* t, const char* sid)
{
  return (t != NULL && sid != NULL) ? t->removeInput(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing Output_t objects from this Transition_t.
 */
LIBSBML_EXTERN
ListOf_t*
Transition_getListOfOutputs(Transition_t* t)
{
  return (t != NULL) ? t->getListOfOutputs() : NULL;
}


/*
 * Get an Output_t from the Transition_t.
 */
LIBSBML_EXTERN
Output_t*
Transition_getOutput(Transition_t* t, unsigned int n)
{
  return (t != NULL) ? t->getOutput(n) : NULL;
}


/*
 * Get an Output_t from the Transition_t based on its identifier.
 */
LIBSBML_EXTERN
Output_t*
Transition_getOutputById(Transition_t* t, const char *sid)
{
  return (t != NULL && sid != NULL) ? t->getOutput(sid) : NULL;
}


/*
 * Get an Output_t from the Transition_t based on the QualitativeSpecies to
 * which it refers.
 */
LIBSBML_EXTERN
Output_t*
Transition_getOutputByQualitativeSpecies(Transition_t* t, const char *sid)
{
  return (t != NULL && sid != NULL) ? t->getOutputByQualitativeSpecies(sid) :
    NULL;
}


/*
 * Adds a copy of the given Output_t to this Transition_t.
 */
LIBSBML_EXTERN
int
Transition_addOutput(Transition_t* t, const Output_t* o)
{
  return (t != NULL) ? t->addOutput(o) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of Output_t objects in this Transition_t.
 */
LIBSBML_EXTERN
unsigned int
Transition_getNumOutputs(Transition_t* t)
{
  return (t != NULL) ? t->getNumOutputs() : SBML_INT_MAX;
}


/*
 * Creates a new Output_t object, adds it to this Transition_t object and
 * returns the Output_t object created.
 */
LIBSBML_EXTERN
Output_t*
Transition_createOutput(Transition_t* t)
{
  return (t != NULL) ? t->createOutput() : NULL;
}


/*
 * Removes the nth Output_t from this Transition_t and returns a pointer to it.
 */
LIBSBML_EXTERN
Output_t*
Transition_removeOutput(Transition_t* t, unsigned int n)
{
  return (t != NULL) ? t->removeOutput(n) : NULL;
}


/*
 * Removes the Output_t from this Transition_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
Output_t*
Transition_removeOutputById(Transition_t* t, const char* sid)
{
  return (t != NULL && sid != NULL) ? t->removeOutput(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing FunctionTerm_t objects from this
 * Transition_t.
 */
LIBSBML_EXTERN
ListOf_t*
Transition_getListOfFunctionTerms(Transition_t* t)
{
  return (t != NULL) ? t->getListOfFunctionTerms() : NULL;
}


/*
 * Get a FunctionTerm_t from the Transition_t.
 */
LIBSBML_EXTERN
FunctionTerm_t*
Transition_getFunctionTerm(Transition_t* t, unsigned int n)
{
  return (t != NULL) ? t->getFunctionTerm(n) : NULL;
}


/*
 * Adds a copy of the given FunctionTerm_t to this Transition_t.
 */
LIBSBML_EXTERN
int
Transition_addFunctionTerm(Transition_t* t, const FunctionTerm_t* ft)
{
  return (t != NULL) ? t->addFunctionTerm(ft) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of FunctionTerm_t objects in this Transition_t.
 */
LIBSBML_EXTERN
unsigned int
Transition_getNumFunctionTerms(Transition_t* t)
{
  return (t != NULL) ? t->getNumFunctionTerms() : SBML_INT_MAX;
}


/*
 * Creates a new FunctionTerm_t object, adds it to this Transition_t object and
 * returns the FunctionTerm_t object created.
 */
LIBSBML_EXTERN
FunctionTerm_t*
Transition_createFunctionTerm(Transition_t* t)
{
  return (t != NULL) ? t->createFunctionTerm() : NULL;
}


/*
 * Removes the nth FunctionTerm_t from this Transition_t and returns a pointer
 * to it.
 */
LIBSBML_EXTERN
FunctionTerm_t*
Transition_removeFunctionTerm(Transition_t* t, unsigned int n)
{
  return (t != NULL) ? t->removeFunctionTerm(n) : NULL;
}


/*
 * Returns the value of the "defaultTerm" element of this Transition_t.
 */
LIBSBML_EXTERN
const DefaultTerm_t *
Transition_getDefaultTerm(const Transition_t * t)
{
  if (t == NULL)
  {
    return NULL;
  }

  return (DefaultTerm_t *)(t->getDefaultTerm());
}


/*
 * Predicate returning @c 1 (true) if this Transition_t's "defaultTerm" element
 * is set.
 */
LIBSBML_EXTERN
int
Transition_isSetDefaultTerm(const Transition_t * t)
{
  return (t != NULL) ? static_cast<int>(t->isSetDefaultTerm()) : 0;
}


/*
 * Sets the value of the "defaultTerm" element of this Transition_t.
 */
LIBSBML_EXTERN
int
Transition_setDefaultTerm(Transition_t * t, const DefaultTerm_t * defaultTerm)
{
  return (t != NULL) ? t->setDefaultTerm(defaultTerm) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new DefaultTerm_t object, adds it to this Transition_t object and
 * returns the DefaultTerm_t object created.
 */
LIBSBML_EXTERN
DefaultTerm_t *
Transition_createDefaultTerm(Transition_t* t)
{
}


/*
 * Unsets the value of the "defaultTerm" element of this Transition_t.
 */
LIBSBML_EXTERN
int
Transition_unsetDefaultTerm(Transition_t * t)
{
  return (t != NULL) ? t->unsetDefaultTerm() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Transition_t object have been set.
 */
LIBSBML_EXTERN
int
Transition_hasRequiredAttributes(const Transition_t * t)
{
  return (t != NULL) ? static_cast<int>(t->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * Transition_t object have been set.
 */
LIBSBML_EXTERN
int
Transition_hasRequiredElements(const Transition_t * t)
{
  return (t != NULL) ? static_cast<int>(t->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


