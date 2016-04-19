/**
 * @file SedDocument.cpp
 * @brief Implementation of the SedDocument class.
 * @author DEVISER
 */
#include <sedml/SedDocument.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedDocument using the given SEDML Level and @ p version
 * values.
 */
SedDocument::SedDocument(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mLevel (SEDML_INT_MAX)
  , mIsSetLevel (false)
  , mVersion (SEDML_INT_MAX)
  , mIsSetVersion (false)
  , mModels (level, version)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  setLevel(level);
  setVersion(version);
  setSedDocument(this);
  connectToChild();
}


/*
 * Creates a new SedDocument using the given SedNamespaces object @p sedmlns.
 */
SedDocument::SedDocument(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mLevel (SEDML_INT_MAX)
  , mIsSetLevel (false)
  , mVersion (SEDML_INT_MAX)
  , mIsSetVersion (false)
  , mModels (sedmlns)
{
  setElementNamespace(sedmlns->getURI());
  setLevel(sedmlns->getLevel());
  setVersion(sedmlns->getVersion());
  setSedDocument(this);
  connectToChild();
}


/*
 * Copy constructor for SedDocument.
 */
SedDocument::SedDocument(const SedDocument& orig)
  : SedBase( orig )
  , mLevel ( orig.mLevel )
  , mIsSetLevel ( orig.mIsSetLevel )
  , mVersion ( orig.mVersion )
  , mIsSetVersion ( orig.mIsSetVersion )
  , mModels ( orig.mModels )
{
  setSedDocument(this);

  connectToChild();
}


/*
 * Assignment operator for SedDocument.
 */
SedDocument&
SedDocument::operator=(const SedDocument& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mLevel = rhs.mLevel;
    mIsSetLevel = rhs.mIsSetLevel;
    mVersion = rhs.mVersion;
    mIsSetVersion = rhs.mIsSetVersion;
    mModels = rhs.mModels;
    connectToChild();
    setSedDocument(this);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedDocument object.
 */
SedDocument*
SedDocument::clone() const
{
  return new SedDocument(*this);
}


/*
 * Destructor for SedDocument.
 */
SedDocument::~SedDocument()
{
}


/*
 * Returns the value of the "level" attribute of this SedDocument.
 */
int
SedDocument::getLevel() const
{
  return mLevel;
}


/*
 * Returns the value of the "version" attribute of this SedDocument.
 */
int
SedDocument::getVersion() const
{
  return mVersion;
}


/*
 * Predicate returning @c true if this SedDocument's "level" attribute is set.
 */
bool
SedDocument::isSetLevel() const
{
  return mIsSetLevel;
}


/*
 * Predicate returning @c true if this SedDocument's "version" attribute is
 * set.
 */
bool
SedDocument::isSetVersion() const
{
  return mIsSetVersion;
}


/*
 * Sets the value of the "level" attribute of this SedDocument.
 */
int
SedDocument::setLevel(int level)
{
  mLevel = level;
  mIsSetLevel = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "version" attribute of this SedDocument.
 */
int
SedDocument::setVersion(int version)
{
  mVersion = version;
  mIsSetVersion = true;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "level" attribute of this SedDocument.
 */
int
SedDocument::unsetLevel()
{
  mLevel = SEDML_INT_MAX;
  mIsSetLevel = false;

  if (isSetLevel() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "version" attribute of this SedDocument.
 */
int
SedDocument::unsetVersion()
{
  mVersion = SEDML_INT_MAX;
  mIsSetVersion = false;

  if (isSetVersion() == false)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSEDML_OPERATION_FAILED;
  }
}


/*
 * Returns the SedListOfModels from this SedDocument.
 */
const SedListOfModels*
SedDocument::getListOfModels() const
{
  return &mModels;
}


/*
 * Returns the SedListOfModels from this SedDocument.
 */
SedListOfModels*
SedDocument::getListOfModels()
{
  return &mModels;
}


/*
 * Get a SedModel from the SedDocument.
 */
SedModel*
SedDocument::getModel(unsigned int n)
{
  return mModels.get(n);
}


/*
 * Get a SedModel from the SedDocument.
 */
const SedModel*
SedDocument::getModel(unsigned int n) const
{
  return mModels.get(n);
}


/*
 * Get a SedModel from the SedDocument based on its identifier.
 */
SedModel*
SedDocument::getModel(const std::string& sid)
{
  return mModels.get(sid);
}


/*
 * Get a SedModel from the SedDocument based on its identifier.
 */
const SedModel*
SedDocument::getModel(const std::string& sid) const
{
  return mModels.get(sid);
}


/*
 * Adds a copy of the given SedModel to this SedDocument.
 */
int
SedDocument::addModel(const SedModel* sm)
{
  if (sm == NULL)
  {
    return LIBSEDML_OPERATION_FAILED;
  }
  else if (sm->hasRequiredAttributes() == false)
  {
    return LIBSEDML_INVALID_OBJECT;
  }
  else if (getLevel() != sm->getLevel())
  {
    return LIBSEDML_LEVEL_MISMATCH;
  }
  else if (getVersion() != sm->getVersion())
  {
    return LIBSEDML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSedNamespacesForAddition(static_cast<const
    SedBase*>(sm)) == false)
  {
    return LIBSEDML_NAMESPACES_MISMATCH;
  }
  else if (sm->isSetId() && (mModels.get(sm->getId())) != NULL)
  {
    return LIBSEDML_DUPLICATE_OBJECT_ID;
  }
  else
  {
    mModels.append(sm);
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Get the number of SedModel objects in this SedDocument.
 */
unsigned int
SedDocument::getNumModels() const
{
  return mModels.size();
}


/*
 * Creates a new SedModel object, adds it to this SedDocument object and
 * returns the SedModel object created.
 */
SedModel*
SedDocument::createModel()
{
  SedModel* sm = NULL;

  try
  {
    sm = new SedModel(getSedNamespaces());
  }
  catch (...)
  {
  }

  if (sm != NULL)
  {
    mModels.appendAndOwn(sm);
  }

  return sm;
}


/*
 * Removes the nth SedModel from this SedDocument and returns a pointer to it.
 */
SedModel*
SedDocument::removeModel(unsigned int n)
{
  return mModels.remove(n);
}


/*
 * Removes the SedModel from this SedDocument based on its identifier and
 * returns a pointer to it.
 */
SedModel*
SedDocument::removeModel(const std::string& sid)
{
  return mModels.remove(sid);
}


/*
 * Returns the XML element name of this SedDocument object.
 */
const std::string&
SedDocument::getElementName() const
{
  static const string name = "sedML";
  return name;
}


/*
 * Returns the libSEDML type code for this SedDocument object.
 */
int
SedDocument::getTypeCode() const
{
  return SEDML_DOCUMENT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedDocument object have been set.
 */
bool
SedDocument::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetLevel() == false)
  {
    allPresent = false;
  }

  if (isSetVersion() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SedDocument object have been set.
 */
bool
SedDocument::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedDocument::writeElements(XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);

  if (getNumModels() > 0)
  {
    mModels.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedDocument::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedDocument::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);

  mModels.setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedDocument::connectToChild()
{
  SedBase::connectToChild();

  mModels.connectToParent(this);
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SedBase*
SedDocument::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SedBase* obj = NULL;

  obj = mModels.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns the value of the "Namespaces" element of this SedDocument.
 */
const XMLNamespaces*
SedDocument::getNamespaces() const
{
  return mSedNamespaces->getNamespaces();
}


/*
 * Returns the value of the "Namespaces" element of this SedDocument.
 */
XMLNamespaces*
SedDocument::getNamespaces()
{
  return mSedNamespaces->getNamespaces();
}


/*
 * Returns the value of the "SedErrorLog" element of this SedDocument.
 */
const SedErrorLog*
SedDocument::getErrorLog() const
{
  return &mErrorLog;
}


/*
 * Returns the value of the "SedErrorLog" element of this SedDocument.
 */
SedErrorLog*
SedDocument::getErrorLog()
{
  return &mErrorLog;
}


/*
 * Get a SedError from the SedDocument.
 */
SedError*
SedDocument::getError(unsigned int n)
{
  return const_cast<SedError*>(mErrorLog.getError(n));
}


/*
 * Get a SedError from the SedDocument.
 */
const SedError*
SedDocument::getError(unsigned int n) const
{
  return mErrorLog.getError(n);
}


/*
 * Get the number of SedError objects in this SedDocument.
 */
unsigned int
SedDocument::getNumErrors() const
{
  return mErrorLog.getNumErrors();
}


/*
 * Get the number of SedError objects in this SedDocument with the given
 * severity.
 */
unsigned int
SedDocument::getNumErrors(unsigned int severity) const
{
  return getErrorLog()->getNumFailsWithSeverity(severity);
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedDocument::createObject(XMLInputStream& stream)
{
  SedBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "listOfModels")
  {
    if (mModels.size() != 0)
    {
      getErrorLog()->logError(SedmlSedDocumentAllowedElements, getLevel(),
        getVersion());
    }

    obj = &mModels;
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
SedDocument::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("level");

  attributes.add("version");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedDocument::readAttributes(const XMLAttributes& attributes,
                            const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logError(SedmlSedDocumentAllowedAttributes, level, version,
        details);
    }
  }

  // 
  // level int (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetLevel = attributes.readInto("level", mLevel);

  if ( mIsSetLevel == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'level' from the <SedDocument> "
        "element must be an integer.";
      log->logError(SedmlSedDocumentLevelMustBeInteger, level, version,
        message);
    }
    else
    {
      std::string message = "Sedml attribute 'level' is missing from the "
        "<SedDocument> element.";
      log->logError(SedmlSedDocumentAllowedAttributes, level, version,
        message);
    }
  }

  // 
  // version int (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetVersion = attributes.readInto("version", mVersion);

  if ( mIsSetVersion == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sedml attribute 'version' from the <SedDocument> "
        "element must be an integer.";
      log->logError(SedmlSedDocumentVersionMustBeInteger, level, version,
        message);
    }
    else
    {
      std::string message = "Sedml attribute 'version' is missing from the "
        "<SedDocument> element.";
      log->logError(SedmlSedDocumentAllowedAttributes, level, version,
        message);
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedDocument::writeAttributes(XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetLevel() == true)
  {
    stream.writeAttribute("level", getPrefix(), mLevel);
  }

  if (isSetVersion() == true)
  {
    stream.writeAttribute("version", getPrefix(), mVersion);
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the namespace for the Sedml package
 */
void
SedDocument::writeXMLNS(XMLOutputStream& stream) const
{
  XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    const XMLNamespaces* thisxmlns = getNamespaces();
    if (thisxmlns && thisxmlns->hasURI(SEDML_XMLNS_L1V1))
    {
      xmlns.add(SEDML_XMLNS_L1V1, prefix);
    }
  }

  stream << xmlns;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedDocument_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedDocument_t *
SedDocument_create(unsigned int level, unsigned int version)
{
  return new SedDocument(level, version);
}


/*
 * Creates and returns a deep copy of this SedDocument_t object.
 */
LIBSEDML_EXTERN
SedDocument_t*
SedDocument_clone(const SedDocument_t* sd)
{
  if (sd != NULL)
  {
    return static_cast<SedDocument_t*>(sd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedDocument_t object.
 */
LIBSEDML_EXTERN
void
SedDocument_free(SedDocument_t* sd)
{
  if (sd != NULL)
  {
    delete sd;
  }
}


/*
 * Returns the value of the "level" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_getLevel(const SedDocument_t * sd)
{
  return (sd != NULL) ? sd->getLevel() : SEDML_INT_MAX;
}


/*
 * Returns the value of the "version" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_getVersion(const SedDocument_t * sd)
{
  return (sd != NULL) ? sd->getVersion() : SEDML_INT_MAX;
}


/*
 * Predicate returning @c 1 if this SedDocument_t's "level" attribute is set.
 */
LIBSEDML_EXTERN
int
SedDocument_isSetLevel(const SedDocument_t * sd)
{
  return (sd != NULL) ? static_cast<int>(sd->isSetLevel()) : 0;
}


/*
 * Predicate returning @c 1 if this SedDocument_t's "version" attribute is set.
 */
LIBSEDML_EXTERN
int
SedDocument_isSetVersion(const SedDocument_t * sd)
{
  return (sd != NULL) ? static_cast<int>(sd->isSetVersion()) : 0;
}


/*
 * Sets the value of the "level" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_setLevel(SedDocument_t * sd, int level)
{
  return (sd != NULL) ? sd->setLevel(level) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Sets the value of the "version" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_setVersion(SedDocument_t * sd, int version)
{
  return (sd != NULL) ? sd->setVersion(version) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "level" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_unsetLevel(SedDocument_t * sd)
{
  return (sd != NULL) ? sd->unsetLevel() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "version" attribute of this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_unsetVersion(SedDocument_t * sd)
{
  return (sd != NULL) ? sd->unsetVersion() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t* containing SedModel_t objects from this SedDocument_t.
 */
LIBSEDML_EXTERN
SedListOf_t*
SedDocument_getListOfModels(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getListOfModels() : NULL;
}


/*
 * Get a SedModel_t from the SedDocument_t.
 */
LIBSEDML_EXTERN
const SedModel_t*
SedDocument_getModel(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->getModel(n) : NULL;
}


/*
 * Get a SedModel_t from the SedDocument_t based on its identifier.
 */
LIBSEDML_EXTERN
const SedModel_t*
SedDocument_getModelById(SedDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getModel(sid) : NULL;
}


/*
 * Adds a copy of the given SedModel_t to this SedDocument_t.
 */
LIBSEDML_EXTERN
int
SedDocument_addModel(SedDocument_t* sd, const SedModel_t* sm)
{
  return (sd != NULL) ? sd->addModel(sm) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Get the number of SedModel_t objects in this SedDocument_t.
 */
LIBSEDML_EXTERN
unsigned int
SedDocument_getNumModels(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->getNumModels() : SEDML_INT_MAX;
}


/*
 * Creates a new SedModel_t object, adds it to this SedDocument_t object and
 * returns the SedModel_t object created.
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_createModel(SedDocument_t* sd)
{
  return (sd != NULL) ? sd->createModel() : NULL;
}


/*
 * Removes the nth SedModel_t from this SedDocument_t and returns a pointer to
 * it.
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_removeModel(SedDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->removeModel(n) : NULL;
}


/*
 * Removes the SedModel_t from this SedDocument_t based on its identifier and
 * returns a pointer to it.
 */
LIBSEDML_EXTERN
SedModel_t*
SedDocument_removeModelById(SedDocument_t* sd, const char* sid)
{
  return (sd != NULL && sid != NULL) ? sd->removeModel(sid) : NULL;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * SedDocument_t object have been set.
 */
LIBSEDML_EXTERN
int
SedDocument_hasRequiredAttributes(const SedDocument_t * sd)
{
  return (sd != NULL) ? static_cast<int>(sd->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this SedDocument_t
 * object have been set.
 */
LIBSEDML_EXTERN
int
SedDocument_hasRequiredElements(const SedDocument_t * sd)
{
  return (sd != NULL) ? static_cast<int>(sd->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


