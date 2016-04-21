/**
 * @file SedModel.cpp
 * @brief Implementation of the SedModel class.
 * @author DEVISER
 */
#include <sedml/SedModel.h>
#include <sedml/SedListOfModels.h>
#include <sbml/xml/XMLInputStream.h>

#include <sedml/SedAddXML.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedModel using the given SEDML Level and @ p version values.
 */
SedModel::SedModel(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mId ("")
  , mName ("")
  , mLanguage ("")
  , mSource ("")
  , mChanges (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedModel using the given SedNamespaces object @p sedmlns.
 */
SedModel::SedModel(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mId ("")
  , mName ("")
  , mLanguage ("")
  , mSource ("")
  , mChanges (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedModel.
 */
SedModel::SedModel(const SedModel& orig)
  : SedBase( orig )
  , mId ( orig.mId )
  , mName ( orig.mName )
  , mLanguage ( orig.mLanguage )
  , mSource ( orig.mSource )
  , mChanges ( orig.mChanges )
{
  connectToChild();
}


/*
 * Assignment operator for SedModel.
 */
SedModel&
SedModel::operator=(const SedModel& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mId = rhs.mId;
    mName = rhs.mName;
    mLanguage = rhs.mLanguage;
    mSource = rhs.mSource;
    mChanges = rhs.mChanges;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedModel object.
 */
SedModel*
SedModel::clone() const
{
  return new SedModel(*this);
}


/*
 * Destructor for SedModel.
 */
SedModel::~SedModel()
{
}


/*
 * Returns the value of the "id" attribute of this SedModel.
 */
const std::string&
SedModel::getId() const
{
  return mId;
}


/*
 * Returns the value of the "name" attribute of this SedModel.
 */
const std::string&
SedModel::getName() const
{
  return mName;
}


/*
 * Returns the value of the "language" attribute of this SedModel.
 */
const std::string&
SedModel::getLanguage() const
{
  return mLanguage;
}


/*
 * Returns the value of the "source" attribute of this SedModel.
 */
const std::string&
SedModel::getSource() const
{
  return mSource;
}


/*
 * Predicate returning @c true if this SedModel's "id" attribute is set.
 */
bool
SedModel::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this SedModel's "name" attribute is set.
 */
bool
SedModel::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Predicate returning @c true if this SedModel's "language" attribute is set.
 */
bool
SedModel::isSetLanguage() const
{
  return (mLanguage.empty() == false);
}


/*
 * Predicate returning @c true if this SedModel's "source" attribute is set.
 */
bool
SedModel::isSetSource() const
{
  return (mSource.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this SedModel.
 */
int
SedModel::setId(const std::string& id)
{
  mId = id;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "name" attribute of this SedModel.
 */
int
SedModel::setName(const std::string& name)
{
  mName = name;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "language" attribute of this SedModel.
 */
int
SedModel::setLanguage(const std::string& language)
{
  mLanguage = language;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "source" attribute of this SedModel.
 */
int
SedModel::setSource(const std::string& source)
{
  mSource = source;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this SedModel.
 */
int
SedModel::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "name" attribute of this SedModel.
 */
int
SedModel::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "language" attribute of this SedModel.
 */
int
SedModel::unsetLanguage()
{
  mLanguage.erase();

  if (mLanguage.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "source" attribute of this SedModel.
 */
int
SedModel::unsetSource()
{
  mSource.erase();

  if (mSource.empty() == true)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfChanges from this SedModel.
 */
const SedListOfChanges*
SedModel::getListOfChanges() const
{
  return &mChanges;
}


/*
 * Returns the SedListOfChanges from this SedModel.
 */
SedListOfChanges*
SedModel::getListOfChanges()
{
  return &mChanges;
}


/*
 * Get a SedChange from the SedModel.
 */
SedChange*
SedModel::getChange(unsigned int n)
{
  return mChanges.get(n);
}


/*
 * Get a SedChange from the SedModel.
 */
const SedChange*
SedModel::getChange(unsigned int n) const
{
  return mChanges.get(n);
}


/*
 * Adds a copy of the given SedChange to this SedModel.
 */
int
SedModel::addChange(const SedChange* sc)
{
  if (sc == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sc->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sc->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sc->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sc)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else
  {
    mChanges.append(sc);
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of SedChange objects in this SedModel.
 */
unsigned int
SedModel::getNumChanges() const
{
  return mChanges.size();
}


/*
 * Creates a new SedAddXML object, adds it to this SedModel object and returns
 * the SedAddXML object created.
 */
SedAddXML*
SedModel::createAddXML()
{
  SedAddXML* saxml = NULL;

  try
  {
    SEDML_CREATE_NS(sedmlns, getSedNamespaces());
    saxml = new SedAddXML(sedmlns);
    delete sedmlns;
  }
  catch (...)
  {
  }

  if (saxml != NULL)
  {
    mChanges.appendAndOwn(saxml);
  }

  return saxml;
}


/*
 * Removes the nth SedChange from this SedModel and returns a pointer to it.
 */
SedChange*
SedModel::removeChange(unsigned int n)
{
  return mChanges.remove(n);
}


/*
 * Returns the XML element name of this SedModel object.
 */
const std::string&
SedModel::getElementName() const
{
  static const string name = "model";
  return name;
}


/*
 * Returns the libSEDML type code for this SedModel object.
 */
int
SedModel::getTypeCode() const
{
  return SEDML_MODEL;
}


/*
 * Predicate returning @c true if all the required attributes for this SedModel
 * object have been set.
 */
bool
SedModel::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetSource() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SedModel
 * object have been set.
 */
bool
SedModel::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedModel::writeElements(XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (getNumChanges() > 0)
  {
    mChanges.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedModel::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedModel::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mChanges.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedModel::connectToChild()
{
  SedBase::connectToChild();

  mChanges.connectToParent(this);
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedModel::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mChanges.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedModel::createObject(XMLInputStream& stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfChanges")
  {
    if (mChanges.size() != 0)
    {
      getErrorLog()->logError(SedmlSedModelAllowedElements, getLevel(),
        getVersion());
    }

    obj = &mChanges;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedModel::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("name");

  attributes.add("language");

  attributes.add("source");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedModel::readAttributes(const XMLAttributes& attributes,
                         const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  if (static_cast<SedListOfModels*>(getParentSEDMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(UnknownCoreAttribute);
        log->logError(SedmlSedDocumentLOSedModelsAllowedAttributes, level,
          version, details);
      }
    }
  }

  SedBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logError(SedmlSedModelAllowedAttributes, level, version, details);
    }
  }

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<SedModel>");
    }
    else if (SyntaxChecker::isValidSEDMLSId(mId) == false)
    {
      logError(SedmlIdSyntaxRule, level, version, "The id '" + mId + "' does "
        "not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Sedml attribute 'id' is missing from the <SedModel> "
      "element.";
    log->logError(SedmlSedModelAllowedAttributes, level, version, message);
  }

  // 
  // name string (use = "optional" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<SedModel>");
    }
  }

  // 
  // language string (use = "optional" )
  // 

  assigned = attributes.readInto("language", mLanguage);

  if (assigned == true)
  {
    if (mLanguage.empty() == true)
    {
      logEmptyString(mLanguage, level, version, "<SedModel>");
    }
  }

  // 
  // source string (use = "required" )
  // 

  assigned = attributes.readInto("source", mSource);

  if (assigned == true)
  {
    if (mSource.empty() == true)
    {
      logEmptyString(mSource, level, version, "<SedModel>");
    }
  }
  else
  {
    std::string message = "Sedml attribute 'source' is missing from the "
      "<SedModel> element.";
    log->logError(SedmlSedModelAllowedAttributes, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedModel::writeAttributes(XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }

  if (isSetLanguage() == true)
  {
    stream.writeAttribute("language", getPrefix(), mLanguage);
  }

  if (isSetSource() == true)
  {
    stream.writeAttribute("source", getPrefix(), mSource);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedModel_t using the given SEDML Level and @ p version values.
 */
LIBSEDML_EXTERN
SedModel_t *
SedModel_create(unsigned int level, unsigned int version)
{
  return new SedModel(level, version);
}


/*
 * Creates and returns a deep copy of this SedModel_t object.
 */
LIBSEDML_EXTERN
SedModel_t*
SedModel_clone(const SedModel_t* sm)
{
  if (sm != NULL)
  {
    return static_cast<SedModel_t*>(sm->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedModel_t object.
 */
LIBSEDML_EXTERN
void
SedModel_free(SedModel_t* sm)
{
  if (sm != NULL)
  {
    delete sm;
  }
}


/*
 * Returns the value of the "id" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
const char *
SedModel_getId(const SedModel_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getId().empty() ? NULL : safe_strdup(sm->getId().c_str());
}


/*
 * Returns the value of the "name" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
const char *
SedModel_getName(const SedModel_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getName().empty() ? NULL : safe_strdup(sm->getName().c_str());
}


/*
 * Returns the value of the "language" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
const char *
SedModel_getLanguage(const SedModel_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getLanguage().empty() ? NULL :
    safe_strdup(sm->getLanguage().c_str());
}


/*
 * Returns the value of the "source" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
const char *
SedModel_getSource(const SedModel_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getSource().empty() ? NULL : safe_strdup(sm->getSource().c_str());
}


/*
 * Predicate returning @c 1 if this SedModel_t's "id" attribute is set.
 */
LIBSEDML_EXTERN
int
SedModel_isSetId(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 if this SedModel_t's "name" attribute is set.
 */
LIBSEDML_EXTERN
int
SedModel_isSetName(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetName()) : 0;
}


/*
 * Predicate returning @c 1 if this SedModel_t's "language" attribute is set.
 */
LIBSEDML_EXTERN
int
SedModel_isSetLanguage(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetLanguage()) : 0;
}


/*
 * Predicate returning @c 1 if this SedModel_t's "source" attribute is set.
 */
LIBSEDML_EXTERN
int
SedModel_isSetSource(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetSource()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_setId(SedModel_t * sm, const char * id)
{
  return (sm != NULL) ? sm->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "name" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_setName(SedModel_t * sm, const char * name)
{
  return (sm != NULL) ? sm->setName(name) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "language" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_setLanguage(SedModel_t * sm, const char * language)
{
  return (sm != NULL) ? sm->setLanguage(language) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "source" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_setSource(SedModel_t * sm, const char * source)
{
  return (sm != NULL) ? sm->setSource(source) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_unsetId(SedModel_t * sm)
{
  return (sm != NULL) ? sm->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_unsetName(SedModel_t * sm)
{
  return (sm != NULL) ? sm->unsetName() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "language" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_unsetLanguage(SedModel_t * sm)
{
  return (sm != NULL) ? sm->unsetLanguage() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "source" attribute of this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_unsetSource(SedModel_t * sm)
{
  return (sm != NULL) ? sm->unsetSource() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t* containing SedChange_t objects from this SedModel_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedModel_getListOfChanges(SedModel_t* sm)
{
  return (sm != NULL) ? sm->getListOfChanges() : NULL;
}


/*
 * Get a SedChange_t from the SedModel_t.
 */
LIBSEDML_EXTERN
const SedChange_t*
SedModel_getChange(SedModel_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->getChange(n) : NULL;
}


/*
 * Adds a copy of the given SedChange_t to this SedModel_t.
 */
LIBSEDML_EXTERN
int
SedModel_addChange(SedModel_t* sm, const SedChange_t* sc)
{
  return (sm != NULL) ? sm->addChange(sc) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedChange_t objects in this SedModel_t.
 */
LIBSEDML_EXTERN
unsigned int
SedModel_getNumChanges(SedModel_t* sm)
{
  return (sm != NULL) ? sm->getNumChanges() : SEDML_INT_MAX;
}


/*
 * Creates a new SedAddXML_t object, adds it to this SedModel_t object and
 * returns the SedAddXML_t object created.
 */
LIBSEDML_EXTERN
SedAddXML_t*
SedModel_createAddXML(SedModel_t* sm)
{
  return (sm != NULL) ? sm->createAddXML() : NULL;
}


/*
 * Removes the nth SedChange_t from this SedModel_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedChange_t*
SedModel_removeChange(SedModel_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->removeChange(n) : NULL;
}


/*
 * Predicate returning @c 1 if all the required attributes for this SedModel_t
 * object have been set.
 */
LIBSEDML_EXTERN
int
SedModel_hasRequiredAttributes(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this SedModel_t
 * object have been set.
 */
LIBSEDML_EXTERN
int
SedModel_hasRequiredElements(const SedModel_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


