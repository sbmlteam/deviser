/**
 * @file CompSBMLDocumentPlugin.cpp
 * @brief Implementation of the CompSBMLDocumentPlugin class.
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
#include <sbml/packages/comp/extension/CompSBMLDocumentPlugin.h>
#include <sbml/packages/comp/validator/CompSBMLError.h>
#include <sbml/util/ElementFilter.h>
#include <sbml/packages/comp/validator/CompConsistencyValidator.h>
#include <sbml/packages/comp/validator/CompIdentifierConsistencyValidator.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new CompSBMLDocumentPlugin using the given URI, prefix and package
 * namespace.
 */
CompSBMLDocumentPlugin::CompSBMLDocumentPlugin(const std::string& uri,
                                               const std::string& prefix,
                                               CompPkgNamespaces* compns)
  : SBMLDocumentPlugin(uri, prefix, compns)
  , mExternalModelDefinitions (compns)
  , mModelDefinitions (compns)
{
  connectToChild();
}


/*
 * Copy constructor for CompSBMLDocumentPlugin.
 */
CompSBMLDocumentPlugin::CompSBMLDocumentPlugin(const CompSBMLDocumentPlugin&
  orig)
  : SBMLDocumentPlugin( orig )
  , mExternalModelDefinitions ( orig.mExternalModelDefinitions )
  , mModelDefinitions ( orig.mModelDefinitions )
{
  connectToChild();
}


/*
 * Assignment operator for CompSBMLDocumentPlugin.
 */
CompSBMLDocumentPlugin&
CompSBMLDocumentPlugin::operator=(const CompSBMLDocumentPlugin& rhs)
{
  if (&rhs != this)
  {
    SBMLDocumentPlugin::operator=(rhs);
    mExternalModelDefinitions = rhs.mExternalModelDefinitions;
    mModelDefinitions = rhs.mModelDefinitions;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this CompSBMLDocumentPlugin object.
 */
CompSBMLDocumentPlugin*
CompSBMLDocumentPlugin::clone() const
{
  return new CompSBMLDocumentPlugin(*this);
}


/*
 * Destructor for CompSBMLDocumentPlugin.
 */
CompSBMLDocumentPlugin::~CompSBMLDocumentPlugin()
{
}


/*
 * Returns the ListOfExternalModelDefinitions from this CompSBMLDocumentPlugin.
 */
const ListOfExternalModelDefinitions*
CompSBMLDocumentPlugin::getListOfExternalModelDefinitions() const
{
  return &mExternalModelDefinitions;
}


/*
 * Returns the ListOfExternalModelDefinitions from this CompSBMLDocumentPlugin.
 */
ListOfExternalModelDefinitions*
CompSBMLDocumentPlugin::getListOfExternalModelDefinitions()
{
  return &mExternalModelDefinitions;
}


/*
 * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin.
 */
ExternalModelDefinition*
CompSBMLDocumentPlugin::getExternalModelDefinition(unsigned int n)
{
  return static_cast<
    ExternalModelDefinition*>(mExternalModelDefinitions.get(n));
}


/*
 * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin.
 */
const ExternalModelDefinition*
CompSBMLDocumentPlugin::getExternalModelDefinition(unsigned int n) const
{
  return static_cast<const
    ExternalModelDefinition*>(mExternalModelDefinitions.get(n));
}


/*
 * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin based on its
 * identifier.
 */
ExternalModelDefinition*
CompSBMLDocumentPlugin::getExternalModelDefinition(const std::string& sid)
{
  return static_cast<
    ExternalModelDefinition*>(mExternalModelDefinitions.get(sid));
}


/*
 * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin based on its
 * identifier.
 */
const ExternalModelDefinition*
CompSBMLDocumentPlugin::getExternalModelDefinition(const std::string& sid)
  const
{
  return static_cast<const
    ExternalModelDefinition*>(mExternalModelDefinitions.get(sid));
}


/*
 * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin based on the
 * ModelRef to which it refers.
 */
const ExternalModelDefinition*
CompSBMLDocumentPlugin::getExternalModelDefinitionByModelRef(const std::string&
  sid) const
{
  return mExternalModelDefinitions.getByModelRef(sid);
}


/*
 * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin based on the
 * ModelRef to which it refers.
 */
ExternalModelDefinition*
CompSBMLDocumentPlugin::getExternalModelDefinitionByModelRef(const std::string&
  sid)
{
  return mExternalModelDefinitions.getByModelRef(sid);
}


/*
 * Adds a copy of the given ExternalModelDefinition to this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::addExternalModelDefinition(const
  ExternalModelDefinition* emd)
{
  if (emd == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (emd->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != emd->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != emd->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != emd->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else if (emd->isSetId() && (mExternalModelDefinitions.get(emd->getId())) !=
    NULL)
  {
    return LIBSBML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mExternalModelDefinitions.append(emd);
  }
}


/*
 * Get the number of ExternalModelDefinition objects in this
 * CompSBMLDocumentPlugin.
 */
unsigned int
CompSBMLDocumentPlugin::getNumExternalModelDefinitions() const
{
  return mExternalModelDefinitions.size();
}


/*
 * Creates a new ExternalModelDefinition object, adds it to this
 * CompSBMLDocumentPlugin object and returns the ExternalModelDefinition object
 * created.
 */
ExternalModelDefinition*
CompSBMLDocumentPlugin::createExternalModelDefinition()
{
  ExternalModelDefinition* emd = NULL;

  try
  {
    COMP_CREATE_NS(compns, getSBMLNamespaces());
    emd = new ExternalModelDefinition(compns);
    delete compns;
  }
  catch (...)
  {
  }

  if (emd != NULL)
  {
    mExternalModelDefinitions.appendAndOwn(emd);
  }

  return emd;
}


/*
 * Removes the nth ExternalModelDefinition from this CompSBMLDocumentPlugin and
 * returns a pointer to it.
 */
ExternalModelDefinition*
CompSBMLDocumentPlugin::removeExternalModelDefinition(unsigned int n)
{
  return static_cast<ExternalModelDefinition*>(mExternalModelDefinitions.remove(n));
}


/*
 * Removes the ExternalModelDefinition from this CompSBMLDocumentPlugin based
 * on its identifier and returns a pointer to it.
 */
ExternalModelDefinition*
CompSBMLDocumentPlugin::removeExternalModelDefinition(const std::string& sid)
{
  return static_cast<ExternalModelDefinition*>(mExternalModelDefinitions.remove(sid));
}


/*
 * Returns the ListOfModelDefinitions from this CompSBMLDocumentPlugin.
 */
const ListOfModelDefinitions*
CompSBMLDocumentPlugin::getListOfModelDefinitions() const
{
  return &mModelDefinitions;
}


/*
 * Returns the ListOfModelDefinitions from this CompSBMLDocumentPlugin.
 */
ListOfModelDefinitions*
CompSBMLDocumentPlugin::getListOfModelDefinitions()
{
  return &mModelDefinitions;
}


/*
 * Get a ModelDefinition from the CompSBMLDocumentPlugin.
 */
ModelDefinition*
CompSBMLDocumentPlugin::getModelDefinition(unsigned int n)
{
  return static_cast< ModelDefinition*>(mModelDefinitions.get(n));
}


/*
 * Get a ModelDefinition from the CompSBMLDocumentPlugin.
 */
const ModelDefinition*
CompSBMLDocumentPlugin::getModelDefinition(unsigned int n) const
{
  return static_cast<const ModelDefinition*>(mModelDefinitions.get(n));
}


/*
 * Adds a copy of the given ModelDefinition to this CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::addModelDefinition(const ModelDefinition* md)
{
  if (md == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (md->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != md->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != md->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (getPackageVersion() != md->getPackageVersion())
  {
    return LIBSBML_PKG_VERSION_MISMATCH;
  }
  else
  {
    return mModelDefinitions.append(md);
  }
}


/*
 * Get the number of ModelDefinition objects in this CompSBMLDocumentPlugin.
 */
unsigned int
CompSBMLDocumentPlugin::getNumModelDefinitions() const
{
  return mModelDefinitions.size();
}


/*
 * Creates a new ModelDefinition object, adds it to this CompSBMLDocumentPlugin
 * object and returns the ModelDefinition object created.
 */
ModelDefinition*
CompSBMLDocumentPlugin::createModelDefinition()
{
  ModelDefinition* md = NULL;

  try
  {
    COMP_CREATE_NS(compns, getSBMLNamespaces());
    md = new ModelDefinition(compns);
    delete compns;
  }
  catch (...)
  {
  }

  if (md != NULL)
  {
    mModelDefinitions.appendAndOwn(md);
  }

  return md;
}


/*
 * Removes the nth ModelDefinition from this CompSBMLDocumentPlugin and returns
 * a pointer to it.
 */
ModelDefinition*
CompSBMLDocumentPlugin::removeModelDefinition(unsigned int n)
{
  return static_cast<ModelDefinition*>(mModelDefinitions.remove(n));
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
CompSBMLDocumentPlugin::writeElements(XMLOutputStream& stream) const
{
  if (getNumExternalModelDefinitions() > 0)
  {
    mExternalModelDefinitions.write(stream);
  }

  if (getNumModelDefinitions() > 0)
  {
    mModelDefinitions.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
CompSBMLDocumentPlugin::accept(SBMLVisitor& v) const
{
  const SBMLDocument* sbmld = static_cast<const
    SBMLDocument*>(this->getParentSBMLObject());
  v.visit(*sbmld);
  v.leave(*sbmld);

  mExternalModelDefinitions.accept(v);

  mModelDefinitions.accept(v);

  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
CompSBMLDocumentPlugin::setSBMLDocument(SBMLDocument* d)
{
  SBMLDocumentPlugin::setSBMLDocument(d);

  mExternalModelDefinitions.setSBMLDocument(d);

  mModelDefinitions.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
CompSBMLDocumentPlugin::connectToChild()
{
  connectToParent(getParentSBMLObject());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to parent element
 */
void
CompSBMLDocumentPlugin::connectToParent(SBase* base)
{
  SBMLDocumentPlugin::connectToParent(base);

  mExternalModelDefinitions.connectToParent(base);

  mModelDefinitions.connectToParent(base);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
CompSBMLDocumentPlugin::enablePackageInternal(const std::string& pkgURI,
                                              const std::string& pkgPrefix,
                                              bool flag)
{
  mExternalModelDefinitions.enablePackageInternal(pkgURI, pkgPrefix, flag);

  mModelDefinitions.enablePackageInternal(pkgURI, pkgPrefix, flag);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
CompSBMLDocumentPlugin::updateSBMLNamespace(const std::string& package,
                                            unsigned int level,
                                            unsigned int version)
{
  SBMLDocumentPlugin::updateSBMLNamespace(package, level, version);

  mExternalModelDefinitions.updateSBMLNamespace(package, level, version);

  mModelDefinitions.updateSBMLNamespace(package, level, version);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate indicating whether 'comp' flattening has been implemented for the
 * Comp package.
 */
bool
CompSBMLDocumentPlugin::isCompFlatteningImplemented() const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Calls check consistency for any relevant Comp validators.
 */
unsigned int
CompSBMLDocumentPlugin::checkConsistency()
{
  unsigned int nerrors = 0;
  unsigned int total_errors = 0;

  SBMLDocument* doc = static_cast<SBMLDocument*>(this->getParentSBMLObject());
  SBMLErrorLog* log = doc->getErrorLog();

  unsigned char applicableValidators = doc->getApplicableValidators();
  bool id = ((applicableValidators & 0x01) ==0x01);
  bool core = ((applicableValidators & 0x02) ==0x02);

  CompIdentifierConsistencyValidator id_validator;
  CompConsistencyValidator core_validator;

  if (id)
  {
    id_validator.init();
    nerrors = id_validator.validate(*doc);
    total_errors += nerrors;
    if (nerrors > 0)
    {
      log->add(id_validator.getFailures());
      if (log->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) > 0)
      {
        return total_errors;
      }
    }
  }

  if (core)
  {
    core_validator.init();
    nerrors = core_validator.validate(*doc);
    total_errors += nerrors;
    if (nerrors > 0)
    {
      log->add(core_validator.getFailures());
      if (log->getNumFailsWithSeverity(LIBSBML_SEV_ERROR) > 0)
      {
        return total_errors;
      }
    }
  }

  return total_errors;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the Comp attributes in the top-level element.
 */
void
CompSBMLDocumentPlugin::readAttributes(const XMLAttributes& attributes,
                                       const ExpectedAttributes&
                                         expectedAttributes)
{
  if (getSBMLDocument() != NULL && getSBMLDocument()->getLevel() < 3)
  {
    return;
  }

  SBMLErrorLog* log = getErrorLog();
  unsigned int numErrs = log->getNumErrors();
  XMLTriple tripleReqd("required", mURI, getPrefix());
  bool assigned = attributes.readInto(tripleReqd, mRequired);

  if (assigned == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logPackageError("comp", CompAttributeRequiredMustBeBoolean,
        getPackageVersion(), getLevel(), getVersion());
    }
    else
    {
      log->logPackageError("comp", CompAttributeRequiredMissing,
        getPackageVersion(), getLevel(), getVersion());
    }
  }
  else
  {
    mIsSetRequired = true;
    if (mRequired != true)
    {
      log->logPackageError("comp", CompAttributeRequiredMustHaveValue,
        getPackageVersion(), getLevel(), getVersion());
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::getAttribute(const std::string& attributeName,
                                     bool& value) const
{
  int return_value = SBMLDocumentPlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::getAttribute(const std::string& attributeName,
                                     int& value) const
{
  int return_value = SBMLDocumentPlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::getAttribute(const std::string& attributeName,
                                     double& value) const
{
  int return_value = SBMLDocumentPlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::getAttribute(const std::string& attributeName,
                                     unsigned int& value) const
{
  int return_value = SBMLDocumentPlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::getAttribute(const std::string& attributeName,
                                     std::string& value) const
{
  int return_value = SBMLDocumentPlugin::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this CompSBMLDocumentPlugin's attribute
 * "attributeName" is set.
 */
bool
CompSBMLDocumentPlugin::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBMLDocumentPlugin::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::setAttribute(const std::string& attributeName,
                                     bool value)
{
  int return_value = SBMLDocumentPlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::setAttribute(const std::string& attributeName,
                                     int value)
{
  int return_value = SBMLDocumentPlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::setAttribute(const std::string& attributeName,
                                     double value)
{
  int return_value = SBMLDocumentPlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::setAttribute(const std::string& attributeName,
                                     unsigned int value)
{
  int return_value = SBMLDocumentPlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::setAttribute(const std::string& attributeName,
                                     const std::string& value)
{
  int return_value = SBMLDocumentPlugin::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this
 * CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::unsetAttribute(const std::string& attributeName)
{
  int value = SBMLDocumentPlugin::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this
 * CompSBMLDocumentPlugin.
 */
SBase*
CompSBMLDocumentPlugin::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "externalModelDefinition")
  {
    return createExternalModelDefinition();
  }
  else if (elementName == "modelDefinition")
  {
    return createModelDefinition();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this CompSBMLDocumentPlugin.
 */
int
CompSBMLDocumentPlugin::addChildObject(const std::string& elementName,
                                       const SBase* element)
{
  if (elementName == "externalModelDefinition" && element->getTypeCode() ==
    SBML_COMP_EXTERNALMODELDEFINITION)
  {
    return addExternalModelDefinition((const
      ExternalModelDefinition*)(element));
  }
  else if (elementName == "modelDefinition" && element->getTypeCode() ==
    SBML_COMP_MODELDEFINITION)
  {
    return addModelDefinition((const ModelDefinition*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * CompSBMLDocumentPlugin.
 */
SBase*
CompSBMLDocumentPlugin::removeChildObject(const std::string& elementName,
                                          const std::string& id)
{
  if (elementName == "externalModelDefinition")
  {
    return removeExternalModelDefinition(id);
  }
  else if (elementName == "modelDefinition")
  {
    for (unsigned int i = 0; i < getNumModelDefinitions(); i++)
    {
      if (getModelDefinition(i)->getId() == id)
      {
        return removeModelDefinition(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this CompSBMLDocumentPlugin.
 */
unsigned int
CompSBMLDocumentPlugin::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "externalModelDefinition")
  {
    return getNumExternalModelDefinitions();
  }
  else if (elementName == "modelDefinition")
  {
    return getNumModelDefinitions();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this CompSBMLDocumentPlugin.
 */
SBase*
CompSBMLDocumentPlugin::getObject(const std::string& elementName,
                                  unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "externalModelDefinition")
  {
    return getExternalModelDefinition(index);
  }
  else if (elementName == "modelDefinition")
  {
    return getModelDefinition(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
CompSBMLDocumentPlugin::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  obj = mExternalModelDefinitions.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mModelDefinitions.getElementBySId(id);

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
CompSBMLDocumentPlugin::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mExternalModelDefinitions.getMetaId() == metaid)
  {
    return &mExternalModelDefinitions;
  }

  if (mModelDefinitions.getMetaId() == metaid)
  {
    return &mModelDefinitions;
  }

  obj = mExternalModelDefinitions.getElementByMetaId(metaid);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mModelDefinitions.getElementByMetaId(metaid);

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
CompSBMLDocumentPlugin::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;


  ADD_FILTERED_LIST(ret, sublist, mExternalModelDefinitions, filter);
  ADD_FILTERED_LIST(ret, sublist, mModelDefinitions, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Append items from model (used in comp flattening)
 */
int
CompSBMLDocumentPlugin::appendFrom(const Model* model)
{
  int ret = LIBSBML_OPERATION_SUCCESS;

  if (model == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  const CompSBMLDocumentPlugin* plug = static_cast<const
    CompSBMLDocumentPlugin*>(model->getPlugin(getPrefix()));

  if (plug == NULL)
  {
    return ret;
  }

  Model* parent = static_cast<Model*>(getParentSBMLObject());

  if (parent == NULL)
  {
    return LIBSBML_INVALID_OBJECT;
  }

  ret = mExternalModelDefinitions.appendFrom(plug->getListOfExternalModelDefinitions());

  if (ret != LIBSBML_OPERATION_SUCCESS)
  {
    return ret;
  }

  ret = mModelDefinitions.appendFrom(plug->getListOfModelDefinitions());

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
CompSBMLDocumentPlugin::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();
  const XMLNamespaces& xmlns = stream.peek().getNamespaces();
  const std::string& prefix = stream.peek().getPrefix();

  const std::string& targetPrefix = (xmlns.hasURI(mURI)) ?
    xmlns.getPrefix(mURI) : mPrefix;

  if (prefix == targetPrefix)
  {
    if (name == "listOfExternalModelDefinitions")
    {
      if (mExternalModelDefinitions.size() != 0)
      {
        getErrorLog()->logPackageError("comp", CompSBMLDocumentAllowedElements,
          getPackageVersion(), getLevel(), getVersion(), "", getLine(),
            getColumn());
      }

      obj = &mExternalModelDefinitions;
      if (targetPrefix.empty())
      {
        mExternalModelDefinitions.getSBMLDocument()->enableDefaultNS(mURI,
          true);
      }
    }
    else if (name == "listOfModelDefinitions")
    {
      if (mModelDefinitions.size() != 0)
      {
        getErrorLog()->logPackageError("comp", CompSBMLDocumentAllowedElements,
          getPackageVersion(), getLevel(), getVersion(), "", getLine(),
            getColumn());
      }

      obj = &mModelDefinitions;
      if (targetPrefix.empty())
      {
        mModelDefinitions.getSBMLDocument()->enableDefaultNS(mURI, true);
      }
    }
  }

  connectToChild();

  return obj;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Returns a ListOf_t * containing ExternalModelDefinition_t objects from this
 * CompSBMLDocumentPlugin_t.
 */
LIBSBML_EXTERN
ListOf_t*
CompSBMLDocumentPlugin_getListOfExternalModelDefinitions(CompSBMLDocumentPlugin_t*
  csbmldp)
{
  return (csbmldp != NULL) ? csbmldp->getListOfExternalModelDefinitions() :
    NULL;
}


/*
 * Get an ExternalModelDefinition_t from the CompSBMLDocumentPlugin_t.
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_getExternalModelDefinition(
                                                  CompSBMLDocumentPlugin_t*
                                                    csbmldp,
                                                  unsigned int n)
{
  return (csbmldp != NULL) ? csbmldp->getExternalModelDefinition(n) : NULL;
}


/*
 * Get an ExternalModelDefinition_t from the CompSBMLDocumentPlugin_t based on
 * its identifier.
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_getExternalModelDefinitionById(
                                                      CompSBMLDocumentPlugin_t*
                                                        csbmldp,
                                                      const char *sid)
{
  return (csbmldp != NULL && sid != NULL) ?
    csbmldp->getExternalModelDefinition(sid) : NULL;
}


/*
 * Get an ExternalModelDefinition_t from the CompSBMLDocumentPlugin_t based on
 * the ModelRef to which it refers.
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_getExternalModelDefinitionByModelRef(
                                                            CompSBMLDocumentPlugin_t*
                                                              csbmldp,
                                                            const char *sid)
{
  return (csbmldp != NULL && sid != NULL) ?
    csbmldp->getExternalModelDefinitionByModelRef(sid) : NULL;
}


/*
 * Adds a copy of the given ExternalModelDefinition_t to this
 * CompSBMLDocumentPlugin_t.
 */
LIBSBML_EXTERN
int
CompSBMLDocumentPlugin_addExternalModelDefinition(
                                                  CompSBMLDocumentPlugin_t*
                                                    csbmldp,
                                                  const ExternalModelDefinition_t*
                                                    emd)
{
  return (csbmldp != NULL) ? csbmldp->addExternalModelDefinition(emd) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of ExternalModelDefinition_t objects in this
 * CompSBMLDocumentPlugin_t.
 */
LIBSBML_EXTERN
unsigned int
CompSBMLDocumentPlugin_getNumExternalModelDefinitions(CompSBMLDocumentPlugin_t*
  csbmldp)
{
  return (csbmldp != NULL) ? csbmldp->getNumExternalModelDefinitions() :
    SBML_INT_MAX;
}


/*
 * Creates a new ExternalModelDefinition_t object, adds it to this
 * CompSBMLDocumentPlugin_t object and returns the ExternalModelDefinition_t
 * object created.
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_createExternalModelDefinition(CompSBMLDocumentPlugin_t*
  csbmldp)
{
  return (csbmldp != NULL) ? csbmldp->createExternalModelDefinition() : NULL;
}


/*
 * Removes the nth ExternalModelDefinition_t from this CompSBMLDocumentPlugin_t
 * and returns a pointer to it.
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_removeExternalModelDefinition(
                                                     CompSBMLDocumentPlugin_t*
                                                       csbmldp,
                                                     unsigned int n)
{
  return (csbmldp != NULL) ? csbmldp->removeExternalModelDefinition(n) : NULL;
}


/*
 * Removes the ExternalModelDefinition_t from this CompSBMLDocumentPlugin_t
 * based on its identifier and returns a pointer to it.
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_removeExternalModelDefinitionById(
                                                         CompSBMLDocumentPlugin_t*
                                                           csbmldp,
                                                         const char* sid)
{
  return (csbmldp != NULL && sid != NULL) ?
    csbmldp->removeExternalModelDefinition(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing ModelDefinition_t objects from this
 * CompSBMLDocumentPlugin_t.
 */
LIBSBML_EXTERN
ListOf_t*
CompSBMLDocumentPlugin_getListOfModelDefinitions(CompSBMLDocumentPlugin_t*
  csbmldp)
{
  return (csbmldp != NULL) ? csbmldp->getListOfModelDefinitions() : NULL;
}


/*
 * Get a ModelDefinition_t from the CompSBMLDocumentPlugin_t.
 */
LIBSBML_EXTERN
ModelDefinition_t*
CompSBMLDocumentPlugin_getModelDefinition(CompSBMLDocumentPlugin_t* csbmldp,
                                          unsigned int n)
{
  return (csbmldp != NULL) ? csbmldp->getModelDefinition(n) : NULL;
}


/*
 * Adds a copy of the given ModelDefinition_t to this CompSBMLDocumentPlugin_t.
 */
LIBSBML_EXTERN
int
CompSBMLDocumentPlugin_addModelDefinition(CompSBMLDocumentPlugin_t* csbmldp,
                                          const ModelDefinition_t* md)
{
  return (csbmldp != NULL) ? csbmldp->addModelDefinition(md) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of ModelDefinition_t objects in this
 * CompSBMLDocumentPlugin_t.
 */
LIBSBML_EXTERN
unsigned int
CompSBMLDocumentPlugin_getNumModelDefinitions(CompSBMLDocumentPlugin_t*
  csbmldp)
{
  return (csbmldp != NULL) ? csbmldp->getNumModelDefinitions() : SBML_INT_MAX;
}


/*
 * Creates a new ModelDefinition_t object, adds it to this
 * CompSBMLDocumentPlugin_t object and returns the ModelDefinition_t object
 * created.
 */
LIBSBML_EXTERN
ModelDefinition_t*
CompSBMLDocumentPlugin_createModelDefinition(CompSBMLDocumentPlugin_t* csbmldp)
{
  return (csbmldp != NULL) ? csbmldp->createModelDefinition() : NULL;
}


/*
 * Removes the nth ModelDefinition_t from this CompSBMLDocumentPlugin_t and
 * returns a pointer to it.
 */
LIBSBML_EXTERN
ModelDefinition_t*
CompSBMLDocumentPlugin_removeModelDefinition(CompSBMLDocumentPlugin_t* csbmldp,
                                             unsigned int n)
{
  return (csbmldp != NULL) ? csbmldp->removeModelDefinition(n) : NULL;
}




LIBSBML_CPP_NAMESPACE_END


