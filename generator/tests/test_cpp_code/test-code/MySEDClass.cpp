/**
 * @file: MySEDClass.cpp
 * @brief: Implementation of MySEDClass.
 * @author: DEVISER
 */
#include <sedml/MySEDClass.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new MySEDClass using the given SEDML @p level and @ p version
 * values.
 */
MySEDClass::MySEDClass(unsigned int level, unsigned int version)
  : SedBase(level, version)
  , mId ("")
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new MySEDClass using the given SedNamespaces object @p sedmlns.
 */
MySEDClass::MySEDClass(SedNamespaces *sedmlns)
  : SedBase(sedmlns)
  , mId ("")
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for MySEDClass.
 */
MySEDClass::MySEDClass(const MySEDClass& orig)
  : SedBase( orig )
  , mId ( orig.mId )
{
}


/*
 * Assignment operator for MySEDClass.
 */
MySEDClass&
MySEDClass::operator=(const MySEDClass& rhs)
{
  if (&rhs != this)
  {
    SedBase::operator=(rhs);
    mId = rhs.mId;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this MySEDClass object.
 */
MySEDClass*
MySEDClass::clone() const
{
  return new MySEDClass(*this);
}


/*
 * Destructor for MySEDClass.
 */
MySEDClass::~MySEDClass()
{
}


/*
 * Returns the value of the "id" attribute of this MySEDClass.
 */
const std::string&
MySEDClass::getId() const
{
  return mId;
}


/*
 * Predicate returning @c true or @c false depending on whether this
 * MySEDClass's "id" attribute has been set.
 */
bool
MySEDClass::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this MySEDClass.
 */
int
MySEDClass::setId(const std::string& id)
{
  mId = id;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this MySEDClass.
 */
int
MySEDClass::unsetId()
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
 * Returns the XML name of this MySEDClass object.
 */
const std::string&
MySEDClass::getElementName() const
{
  static const string name = "fred";
  return name;
}


/*
 * Returns the libSEDML typcode of this MySEDClass object.
 */
int
MySEDClass::getTypeCode() const
{
  return MY_TEST_TYPE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * MySEDClass object have been set.
 */
bool
MySEDClass::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
MySEDClass::writeElements(XMLOutputStream& stream) const
{
  SedBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
MySEDClass::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
MySEDClass::setSedDocument(SedDocument* d)
{
  SedBase::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
MySEDClass::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SedBase::addExpectedAttributes(attributes);

  attributes.add("id");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
MySEDClass::readAttributes(const XMLAttributes& attributes,
                           const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SEDMLErrorLog* log = getErrorLog();

  SedBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logError(TestMySEDClassAllowedAttributes, level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logError(TestMySEDClassAllowedCoreAttributes, level, version,
        details);
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
      logEmptyString(mId, level, version, "<MySEDClass>");
    }
    else if (SyntaxChecker::isValidSEDMLSId(mId) == false)
    {
      logError(InvalidIdSyntax, level, version, "The id '" + mId + "' does not "
        "conform to the syntax.");
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Writes the attributes to the stream
 */
void
MySEDClass::writeAttributes(XMLOutputStream& stream) const
{
  SedBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new MySEDClass_t using the given SEDML @p level and @ p version
 * values.
 */
LIBSEDML_EXTERN
MySEDClass_t *
MySEDClass_create(unsigned int level, unsigned int version)
{
  return new MySEDClass(level, version);
}


/*
 * Creates and returns a deep copy of this MySEDClass_t object.
 */
LIBSEDML_EXTERN
MySEDClass_t*
MySEDClass_clone(const MySEDClass_t* msedc)
{
  if (msedc != NULL)
  {
    return static_cast<MySEDClass_t*>(msedc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this MySEDClass_t object.
 */
LIBSEDML_EXTERN
void
MySEDClass_free(MySEDClass_t* msedc)
{
  if (msedc != NULL)
  {
    delete msedc;
  }
}


/*
 * Returns the value of the "id" attribute of this MySEDClass_t.
 */
LIBSEDML_EXTERN
const char *
MySEDClass_getId(const MySEDClass_t * msedc)
{
  if (msedc == NULL)
  {
    return NULL;
  }

  return msedc->getId().empty() ? NULL : safe_strdup(msedc->getId().c_str());
}


/*
 * Predicate returning @c 1 or @c 0 depending on whether this MySEDClass_t's
 * "id" attribute has been set.
 */
LIBSEDML_EXTERN
int
MySEDClass_isSetId(const MySEDClass_t * msedc)
{
  return (msedc != NULL) ? static_cast<int>(msedc->isSetId()) : 0;
}


/*
 * Sets the value of the "id" attribute of this MySEDClass_t.
 */
LIBSEDML_EXTERN
int
MySEDClass_setId(MySEDClass_t * msedc, const char * id)
{
  return (msedc != NULL) ? msedc->setId(id) : LIBSEDML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this MySEDClass_t.
 */
LIBSEDML_EXTERN
int
MySEDClass_unsetId(MySEDClass_t * msedc)
{
  return (msedc != NULL) ? msedc->unsetId() : LIBSEDML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * MySEDClass_t object have been set.
 */
LIBSEDML_EXTERN
int
MySEDClass_hasRequiredAttributes(const MySEDClass_t * msedc)
{
  return (msedc != NULL) ? static_cast<int>(msedc->hasRequiredAttributes()) :
    0;
}




LIBSEDML_CPP_NAMESPACE_END


