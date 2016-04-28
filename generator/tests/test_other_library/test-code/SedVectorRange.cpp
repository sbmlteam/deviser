/**
 * @file SedVectorRange.cpp
 * @brief Implementation of the SedVectorRange class.
 * @author DEVISER
 */
#include <sedml/SedVectorRange.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSEDML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SedVectorRange using the given SEDML Level and @ p version
 * values.
 */
SedVectorRange::SedVectorRange(unsigned int level, unsigned int version)
  : SedRange(level, version)
  , mValue ()
{
  setSedNamespacesAndOwn(new SedNamespaces(level, version));
}


/*
 * Creates a new SedVectorRange using the given SedNamespaces object @p
 * sedmlns.
 */
SedVectorRange::SedVectorRange(SedNamespaces *sedmlns)
  : SedRange(sedmlns)
  , mValue ()
{
  setElementNamespace(sedmlns->getURI());
}


/*
 * Copy constructor for SedVectorRange.
 */
SedVectorRange::SedVectorRange(const SedVectorRange& orig)
  : SedRange( orig )
  , mValue ( orig.mValue )
{
}


/*
 * Assignment operator for SedVectorRange.
 */
SedVectorRange&
SedVectorRange::operator=(const SedVectorRange& rhs)
{
  if (&rhs != this)
  {
    SedRange::operator=(rhs);
    mValue = rhs.mValue;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SedVectorRange object.
 */
SedVectorRange*
SedVectorRange::clone() const
{
  return new SedVectorRange(*this);
}


/*
 * Destructor for SedVectorRange.
 */
SedVectorRange::~SedVectorRange()
{
}


/*
 * Returns the value of the "value" attribute of this SedVectorRange.
 */
const std::vector<double>&
SedVectorRange::getValue() const
{
  return mValue;
}


/*
 * Predicate returning @c true if this SedVectorRange's "value" attribute is
 * set.
 */
bool
SedVectorRange::hasValues() const
{
  return mValue.size() > 0;
}


/*
 * Return the number of elements in this SedVectorRange's "value" attribute.
 */
unsigned int
SedVectorRange::getNumValues() const
{
  return (unsigned int)(mValue.size());
}


/*
 * Sets the value of the "value" attribute of this SedVectorRange.
 */
int
SedVectorRange::setValue(const std::vector<double>& value)
{
  mValue = value;
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Adds another value to the "value" attribute of this SedVectorRange.
 */
int
SedVectorRange::addValue(double value)
{
  mValue.push_back(value);
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Clears the "value" element of this SedVectorRange.
 */
int
SedVectorRange::clearValues()
{
  mValue.clear();
  return LIBSEDML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this SedVectorRange object.
 */
const std::string&
SedVectorRange::getElementName() const
{
  static const string name = "vectorRange";
  return name;
}


/*
 * Returns the libSEDML type code for this SedVectorRange object.
 */
int
SedVectorRange::getTypeCode() const
{
  return SEDML_RANGE_VECTORRANGE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SedVectorRange object have been set.
 */
bool
SedVectorRange::hasRequiredAttributes() const
{
  bool allPresent = SedRange::hasRequiredAttributes();

  return allPresent;
}



/** @cond doxygenLibSEDMLInternal */

/*
 * Write any contained elements
 */
void
SedVectorRange::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SedRange::writeElements(stream);

  if (hasValues())
  {
    for (std::vector<double>::const_iterator it = mValue.begin(); it !=
      mValue.end(); ++it)
    {
      stream.startElement("value");
      stream.setAutoIndent(false);
      stream << " " << *it << " ";
      stream.endElement("value");
      stream.setAutoIndent(true);
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Accepts the given SedVisitor
 */
bool
SedVectorRange::accept(SedVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Sets the parent SedDocument
 */
void
SedVectorRange::setSedDocument(SedDocument* d)
{
  SedRange::setSedDocument(d);
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SedBase*
SedVectorRange::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SedBase* obj = SedRange::createObject(stream);

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Adds the expected attributes for this element
 */
void
SedVectorRange::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SedRange::addExpectedAttributes(attributes);

  attributes.add("value");
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SedVectorRange::readAttributes(
                               const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                 XMLAttributes& attributes,
                               const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                 ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SedErrorLog* log = getErrorLog();

  SedRange::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logError(SedmlSedVectorRangeAllowedAttributes, level, version,
        details);
    }
  }
}

/** @endcond */



/** @cond doxygenLibSEDMLInternal */

/*
 * Reads other XML such as math/notes etc.
 */
bool
SedVectorRange::readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  bool read = false;

  while (stream.peek().getName() == "value")
  {
    stream.next();
    stringstream text;
    while (stream.isGood() && stream.peek().isText())
    {
      text << stream.next().getCharacters();
    }

    double value;
    text >> value;
    if (!text.fail())
    {
      mValue.push_back(value);
    }

    stream.next();
    read = true;
  }

  if (SedRange::readOtherXML(stream))
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
SedVectorRange::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLOutputStream& stream) const
{
  SedRange::writeAttributes(stream);
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SedVectorRange_t using the given SEDML Level and @ p version
 * values.
 */
LIBSEDML_EXTERN
SedVectorRange_t *
SedVectorRange_create(unsigned int level, unsigned int version)
{
  return new SedVectorRange(level, version);
}


/*
 * Creates and returns a deep copy of this SedVectorRange_t object.
 */
LIBSEDML_EXTERN
SedVectorRange_t*
SedVectorRange_clone(const SedVectorRange_t* svr)
{
  if (svr != NULL)
  {
    return static_cast<SedVectorRange_t*>(svr->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SedVectorRange_t object.
 */
LIBSEDML_EXTERN
void
SedVectorRange_free(SedVectorRange_t* svr)
{
  if (svr != NULL)
  {
    delete svr;
  }
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * SedVectorRange_t object have been set.
 */
LIBSEDML_EXTERN
int
SedVectorRange_hasRequiredAttributes(const SedVectorRange_t * svr)
{
  return (svr != NULL) ? static_cast<int>(svr->hasRequiredAttributes()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


