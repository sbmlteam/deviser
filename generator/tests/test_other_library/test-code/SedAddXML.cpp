/**
 * @file SedAddXML.cpp
 * @brief Implementation of the SedAddXML class.
 * @author DEVISER
 */
#include <sedml/SedAddXML.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedAddXML using the given SEDML Level and @ p version values.
 */
SedAddXML::SedAddXML(unsigned int level, unsigned int version)
  : SedChange(level, version)
  , mNewXML (NULL)
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SedAddXML using the given SedNamespaces object @p sedmlns.
 */
SedAddXML::SedAddXML(SedNamespaces *sedmlns)
  : SedChange(sedmlns)
  , mNewXML (NULL)
{
  setElementNamespace(sedmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SedAddXML.
 */
SedAddXML::SedAddXML(const SedAddXML& orig)
  : SedChange( orig )
  , mNewXML ( NULL )
{
  if (orig.mNewXML != NULL)
  {
    mNewXML = orig.mNewXML->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SedAddXML.
 */
SedAddXML&
SedAddXML::operator=(const SedAddXML& rhs)
{
  if (&rhs != this)
  {
    SedChange::operator=(rhs);
    delete mNewXML;
    if (rhs.mNewXML != NULL)
    {
      mNewXML = rhs.mNewXML->clone();
    }
    else
    {
      mNewXML = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedAddXML object.
 */
SedAddXML*
SedAddXML::clone() const
{
  return new SedAddXML(*this);
}


/*
 * Destructor for SedAddXML.
 */
SedAddXML::~SedAddXML()
{
  delete mNewXML;
  mNewXML = NULL;
}


/*
 * Returns the value of the "newXML" element of this SedAddXML.
 */
const XMLNode*
SedAddXML::getNewXML() const
{
  return mNewXML;
}


/*
 * Returns the value of the "newXML" element of this SedAddXML.
 */
XMLNode*
SedAddXML::getNewXML()
{
  return mNewXML;
}


/*
 * Predicate returning @c true if this SedAddXML's "newXML" element is set.
 */
bool
SedAddXML::isSetNewXML() const
{
  return (mNewXML != NULL);
}


/*
 * Sets the value of the "newXML" element of this SedAddXML.
 */
int
SedAddXML::setNewXML(const XMLNode* newXML)
{
  if (mNewXML == newXML)
  {
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else if (newXML == NULL)
  {
    delete mNewXML;
    mNewXML = NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
  else
  {
    delete mNewXML;
    mNewXML = (newXML != NULL) ? newXML->clone() : NULL;
    return LIBSEDML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "newXML" element of this SedAddXML.
 */
int
SedAddXML::unsetNewXML()
{
  delete mNewXML;
  mNewXML = NULL;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this SedAddXML object.
 */
const std::string&
SedAddXML::getElementName() const
{
  static const string name = "addXML";
  return name;
}


/*
 * Returns the libSEDML type code for this SedAddXML object.
 */
int
SedAddXML::getTypeCode() const
{
  return SEDML_ADDXML;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedAddXML object have been set.
 */
bool
SedAddXML::hasRequiredAttributes() const
{
  bool allPresent = SedChange::hasRequiredAttributes();

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SedAddXML
 * object have been set.
 */
bool
SedAddXML::hasRequiredElements() const
{
  bool allPresent = SedChange::hasRequiredElements();

  if (isSetNewXML() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedAddXML::writeElements(XMLOutputStream& stream) const
{
  SedChange::writeElements(stream);

  if (isSetNewXML() == true)
  {
    stream.startElement("newXML");
    stream << *mNewXML;
    stream.endElement("newXML");
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedAddXML::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedAddXML::setSedDocument(SedDocument* d)
{
  SedChange::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Connects to child elements
 */
void
SedAddXML::connectToChild()
{
  SedChange::connectToChild();
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedAddXML::createObject(XMLInputStream& stream)
{
  SedBase* obj = SedChange::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedAddXML::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedChange::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedAddXML::readAttributes(const XMLAttributes& attributes,
                          const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedChange::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logError(SedmlSedAddXMLAllowedAttributes, level, version, details);
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
SedAddXML::readOtherXML(XMLInputStream& stream)
{
  bool read = false;
  const string& name = stream.peek().getName();

  if (name == "newXML")
  {
    const XMLToken& token = stream.next();
    stream.skipText();
    delete mNewXML;
    XMLNode* xml = new XMLNode(stream);
    mNewXML = new XMLNode(*(static_cast<XMLToken*>(xml)));
    stream.skipPastEnd(token);
    delete xml;
    read = true;
  }

  if (SedChange::readOtherXML(stream))
  {
    read = true;
  }

  return read;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
SedAddXML::writeAttributes(XMLOutputStream& stream) const
{
  SedChange::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedAddXML_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedAddXML_t *
SedAddXML_create(unsigned int level, unsigned int version)
{
  return new SedAddXML(level, version);
}


/*
 * Creates and returns a deep copy of this SedAddXML_t object.
 */
LIBSEDML_EXTERN
SedAddXML_t*
SedAddXML_clone(const SedAddXML_t* saxml)
{
  if (saxml != NULL)
  {
    return static_cast<SedAddXML_t*>(saxml->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedAddXML_t object.
 */
LIBSEDML_EXTERN
void
SedAddXML_free(SedAddXML_t* saxml)
{
  if (saxml != NULL)
  {
    delete saxml;
  }
}


/*
 * Returns the value of the "newXML" element of this SedAddXML_t.
 */
LIBSEDML_EXTERN
const XMLNode_t*
SedAddXML_getNewXML(const SedAddXML_t * saxml)
{
  if (saxml == NULL)
  {
    return NULL;
  }

  return (XMLNode_t*)(saxml->getNewXML());
}


/*
 * Predicate returning @c 1 if this SedAddXML_t's "newXML" element is set.
 */
LIBSEDML_EXTERN
int
SedAddXML_isSetNewXML(const SedAddXML_t * saxml)
{
  return (saxml != NULL) ? static_cast<int>(saxml->isSetNewXML()) : 0;
}


/*
 * Sets the value of the "newXML" element of this SedAddXML_t.
 */
LIBSEDML_EXTERN
int
SedAddXML_setNewXML(SedAddXML_t * saxml, const XMLNode_t* newXML)
{
  return (saxml != NULL) ? saxml->setNewXML(newXML) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "newXML" element of this SedAddXML_t.
 */
LIBSEDML_EXTERN
int
SedAddXML_unsetNewXML(SedAddXML_t * saxml)
{
  return (saxml != NULL) ? saxml->unsetNewXML() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this SedAddXML_t
 * object have been set.
 */
LIBSEDML_EXTERN
int
SedAddXML_hasRequiredAttributes(const SedAddXML_t * saxml)
{
  return (saxml != NULL) ? static_cast<int>(saxml->hasRequiredAttributes()) :
    0;
}


/*
 * Predicate returning @c 1 if all the required elements for this SedAddXML_t
 * object have been set.
 */
LIBSEDML_EXTERN
int
SedAddXML_hasRequiredElements(const SedAddXML_t * saxml)
{
  return (saxml != NULL) ? static_cast<int>(saxml->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


