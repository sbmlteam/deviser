/**
 * @file QualModelPlugin.cpp
 * @brief Implementation of the QualModelPlugin class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
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
#include <sbml/packages/qual/extension/QualModelPlugin.h>
#include <sbml/packages/qual/validator/QualSBMLError.h>
#include <sbml/util/ElementFilter.h>
#include <sbml/Model.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new QualModelPlugin using the given uri, prefix and package
 * namespace.
 */
QualModelPlugin::QualModelPlugin(const std::string& uri,
                                 const std::string& prefix,
                                 QualPkgNamespaces* qualns)
  : SBasePlugin(uri, prefix, qualns)
  , mQualitativeSpecies (qualns)
  , mTransitions (qualns)
{
  connectToChild();
}


/*
 * Copy constructor for QualModelPlugin.
 */
QualModelPlugin::QualModelPlugin(const QualModelPlugin& orig)
  : SBasePlugin( orig )
  , mQualitativeSpecies ( orig.mQualitativeSpecies )
  , mTransitions ( orig.mTransitions )
{
  connectToChild();
}


/*
 * Assignment operator for QualModelPlugin.
 */
QualModelPlugin&
QualModelPlugin::operator=(const QualModelPlugin& rhs)
{
  if (&rhs != this)
  {
    SBasePlugin::operator=(rhs);
    mQualitativeSpecies = rhs.mQualitativeSpecies;
    mTransitions = rhs.mTransitions;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this QualModelPlugin object.
 */
QualModelPlugin*
QualModelPlugin::clone() const
{
  return new QualModelPlugin(*this);
}


/*
 * Destructor for QualModelPlugin.
 */
QualModelPlugin::~QualModelPlugin()
{
}


/*
 * Returns the ListOfQualitativeSpecies from this QualModelPlugin.
 */
const ListOfQualitativeSpecies*
QualModelPlugin::getListOfQualitativeSpecies() const
{
  return &mQualitativeSpecies;
}


/*
 * Returns the ListOfQualitativeSpecies from this QualModelPlugin.
 */
ListOfQualitativeSpecies*
QualModelPlugin::getListOfQualitativeSpecies()
{
  return &mQualitativeSpecies;
}


/*
 * Get a QualitativeSpecies from the QualModelPlugin.
 */
QualitativeSpecies*
QualModelPlugin::getQualitativeSpecies(unsigned int n)
{
  return static_cast< QualitativeSpecies*>(mQualitativeSpecies.get(n));
}


/*
 * Get a QualitativeSpecies from the QualModelPlugin.
 */
const QualitativeSpecies*
QualModelPlugin::getQualitativeSpecies(unsigned int n) const
{
  return static_cast<const QualitativeSpecies*>(mQualitativeSpecies.get(n));
}


/*
 * Get a QualitativeSpecies from the QualModelPlugin based on its identifier.
 */
QualitativeSpecies*
QualModelPlugin::getQualitativeSpecies(const std::string& sid)
{
  return static_cast< QualitativeSpecies*>(mQualitativeSpecies.get(sid));
}


/*
 * Get a QualitativeSpecies from the QualModelPlugin based on its identifier.
 */
const QualitativeSpecies*
QualModelPlugin::getQualitativeSpecies(const std::string& sid) const
{
  return static_cast<const QualitativeSpecies*>(mQualitativeSpecies.get(sid));
}


/*
 * Get a QualitativeSpecies from the QualModelPlugin based on the Compartment
 * to which it refers.
 */
const QualitativeSpecies*
QualModelPlugin::getQualitativeSpeciesByCompartment(const std::string& sid)
  const
{
  return mQualitativeSpecies.getByCompartment(sid);
}


/*
 * Get a QualitativeSpecies from the QualModelPlugin based on the Compartment
 * to which it refers.
 */
QualitativeSpecies*
QualModelPlugin::getQualitativeSpeciesByCompartment(const std::string& sid)
{
  return mQualitativeSpecies.getByCompartment(sid);
}


/*
 * Adds a copy of the given QualitativeSpecies to this QualModelPlugin.
 */
int
QualModelPlugin::addQualitativeSpecies(const QualitativeSpecies* qs)
{
  if (qs == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (qs->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != qs->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != qs->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != qs->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else if (qs->isSetId() && (mQualitativeSpecies.get(qs->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    mQualitativeSpecies.append(qs);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of QualitativeSpecies objects in this QualModelPlugin.
 */
unsigned int
QualModelPlugin::getNumQualitativeSpecies() const
{
  return mQualitativeSpecies.size();
}


/*
 * Creates a new QualitativeSpecies object, adds it to this QualModelPlugin
 * object and returns the QualitativeSpecies object created.
 */
QualitativeSpecies*
QualModelPlugin::createQualitativeSpecies()
{
  QualitativeSpecies* qs = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    qs = new QualitativeSpecies(qualns);
    delete qualns;
  }
  catch (...)
  {
  }

  if (qs != NULL)
  {
    mQualitativeSpecies.appendAndOwn(qs);
  }

  return qs;
}


/*
 * Removes the nth QualitativeSpecies from this QualModelPlugin and returns a
 * pointer to it.
 */
QualitativeSpecies*
QualModelPlugin::removeQualitativeSpecies(unsigned int n)
{
  return static_cast<QualitativeSpecies*>(mQualitativeSpecies.remove(n));
}


/*
 * Removes the QualitativeSpecies from this QualModelPlugin based on its
 * identifier and returns a pointer to it.
 */
QualitativeSpecies*
QualModelPlugin::removeQualitativeSpecies(const std::string& sid)
{
  return static_cast<QualitativeSpecies*>(mQualitativeSpecies.remove(sid));
}


/*
 * Returns the ListOfTransitions from this QualModelPlugin.
 */
const ListOfTransitions*
QualModelPlugin::getListOfTransitions() const
{
  return &mTransitions;
}


/*
 * Returns the ListOfTransitions from this QualModelPlugin.
 */
ListOfTransitions*
QualModelPlugin::getListOfTransitions()
{
  return &mTransitions;
}


/*
 * Get a Transition from the QualModelPlugin.
 */
Transition*
QualModelPlugin::getTransition(unsigned int n)
{
  return static_cast< Transition*>(mTransitions.get(n));
}


/*
 * Get a Transition from the QualModelPlugin.
 */
const Transition*
QualModelPlugin::getTransition(unsigned int n) const
{
  return static_cast<const Transition*>(mTransitions.get(n));
}


/*
 * Get a Transition from the QualModelPlugin based on its identifier.
 */
Transition*
QualModelPlugin::getTransition(const std::string& sid)
{
  return static_cast< Transition*>(mTransitions.get(sid));
}


/*
 * Get a Transition from the QualModelPlugin based on its identifier.
 */
const Transition*
QualModelPlugin::getTransition(const std::string& sid) const
{
  return static_cast<const Transition*>(mTransitions.get(sid));
}


/*
 * Adds a copy of the given Transition to this QualModelPlugin.
 */
int
QualModelPlugin::addTransition(const Transition* t)
{
  if (t == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (t->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (t->hasRequiredElements() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != t->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != t->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != t->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else if (t->isSetId() && (mTransitions.get(t->getId())) != NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    mTransitions.append(t);
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of Transition objects in this QualModelPlugin.
 */
unsigned int
QualModelPlugin::getNumTransitions() const
{
  return mTransitions.size();
}


/*
 * Creates a new Transition object, adds it to this QualModelPlugin object and
 * returns the Transition object created.
 */
Transition*
QualModelPlugin::createTransition()
{
  Transition* t = NULL;

  try
  {
    QUAL_CREATE_NS(qualns, getSBMLNamespaces());
    t = new Transition(qualns);
    delete qualns;
  }
  catch (...)
  {
  }

  if (t != NULL)
  {
    mTransitions.appendAndOwn(t);
  }

  return t;
}


/*
 * Removes the nth Transition from this QualModelPlugin and returns a pointer
 * to it.
 */
Transition*
QualModelPlugin::removeTransition(unsigned int n)
{
  return static_cast<Transition*>(mTransitions.remove(n));
}


/*
 * Removes the Transition from this QualModelPlugin based on its identifier and
 * returns a pointer to it.
 */
Transition*
QualModelPlugin::removeTransition(const std::string& sid)
{
  return static_cast<Transition*>(mTransitions.remove(sid));
}


/*
 * Predicate returning @c true if all the required elements for this
 * QualModelPlugin object have been set.
 */
bool
QualModelPlugin::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
QualModelPlugin::writeElements(XMLOutputStream& stream) const
{
  if (getNumQualitativeSpecies() > 0)
  {
    mQualitativeSpecies.write(stream);
  }

  if (getNumTransitions() > 0)
  {
    mTransitions.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
QualModelPlugin::accept(SBMLVisitor& v) const
{
  const Model* m = static_cast<const Model*>(this->getParentSBMLObject());
  v.visit(*m);
  v.leave(*m);

  mQualitativeSpecies.accept(v);

  mTransitions.accept(v);

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
QualModelPlugin::setSBMLDocument(SBMLDocument* d)
{
  SBasePlugin::setSBMLDocument(d);

  mQualitativeSpecies.setSBMLDocument(d);

  mTransitions.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
QualModelPlugin::connectToChild()
{
  connectToParent(getParentSBMLObject());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to parent element
 */
void
QualModelPlugin::connectToParent(SBase* base)
{
  SBasePlugin::connectToParent(base);

  mQualitativeSpecies.connectToParent(base);

  mTransitions.connectToParent(base);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
QualModelPlugin::enablePackageInternal(const std::string& pkgURI,
                                       const std::string& pkgPrefix,
                                       bool flag)
{
  mQualitativeSpecies.enablePackageInternal(pkgURI, pkgPrefix, flag);

  mTransitions.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
QualModelPlugin::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mQualitativeSpecies.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mTransitions.getElementBySId(id);

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
QualModelPlugin::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mQualitativeSpecies.getMetaId() == metaid)
  {
    return &mQualitativeSpecies;
  }

  if (mTransitions.getMetaId() == metaid)
  {
    return &mTransitions;
  }

  obj = mQualitativeSpecies.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mTransitions.getElementByMetaId(metaid);

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
QualModelPlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mQualitativeSpecies, filter);
  ADD_FILTERED_LIST(ret, sublist, mTransitions, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Append items from model (used in comp flattening)
 */
int
QualModelPlugin::appendFrom(const Model* model)
{
  int ret = LIBSBML_OPERATION_SUCCESS;

  if (model == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  const QualModelPlugin* plug = static_cast<const
    QualModelPlugin*>(model->getPlugin(getPrefix()));

  if (plug == NULL)
  {
    return ret;
  }

  Model* parent = static_cast<Model*>(getParentSBMLObject());

  if (parent == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  ret = mQualitativeSpecies.appendFrom(plug->getListOfQualitativeSpecies());

  if (ret != LIBSBML_OPERATION_SUCCESS)
  {
    return ret;
  }

  ret = mTransitions.appendFrom(plug->getListOfTransitions());

  if (ret != LIBSBML_OPERATION_SUCCESS)
  {
    return ret;
  }

  return ret;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
QualModelPlugin::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();
  const XMLNamespaces& xmlns = stream.peek().getNamespaces();
  const std::string& prefix = stream.peek().getPrefix();

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ?
    xmlns.getPrefix(mURI) : mPrefix;

  if (prefix == targetPrefix)
  {
    if (name == "listOfQualitativeSpecies")
    {
      if (mQualitativeSpecies.size() != 0)
      {
        getErrorLog()->logPackageError("qual", QualModelAllowedElements,
          getPackageVersion(), getLevel(), getVersion());
      }

      obj = &mQualitativeSpecies;
      if (targetPrefix.empty())
      {
        mQualitativeSpecies.getSBMLDocument()->enableDefaultNS(mURI, true);
      }
    }
    else if (name == "listOfTransitions")
    {
      if (mTransitions.size() != 0)
      {
        getErrorLog()->logPackageError("qual", QualModelAllowedElements,
          getPackageVersion(), getLevel(), getVersion());
      }

      obj = &mTransitions;
      if (targetPrefix.empty())
      {
        mTransitions.getSBMLDocument()->enableDefaultNS(mURI, true);
      }
    }
  }

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */




LIBSBML_CPP_NAMESPACE_END


