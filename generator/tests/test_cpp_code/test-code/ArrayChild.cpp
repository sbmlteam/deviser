/**
 * @file ArrayChild.cpp
 * @brief Implementation of the ArrayChild class.
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
#include <sbml/packages/test/sbml/ArrayChild.h>
#include <sbml/packages/test/validator/TestSBMLError.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new ArrayChild using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
ArrayChild::ArrayChild(unsigned int level,
                       unsigned int version,
                       unsigned int pkgVersion)
  : SBase(level, version)
  , mUnit (NULL)
  , mNumber (NULL)
{
  setSBMLNamespacesAndOwn(new TestPkgNamespaces(level, version, pkgVersion));
  connectToChild();
}


/*
 * Creates a new ArrayChild using the given TestPkgNamespaces object.
 */
ArrayChild::ArrayChild(TestPkgNamespaces *testns)
  : SBase(testns)
  , mUnit (NULL)
  , mNumber (NULL)
{
  setElementNamespace(testns->getURI());
  connectToChild();
  loadPlugins(testns);
}


/*
 * Copy constructor for ArrayChild.
 */
ArrayChild::ArrayChild(const ArrayChild& orig)
  : SBase( orig )
  , mUnit ( NULL )
  , mNumber ( NULL )
{
  setNumber(orig.mNumber, orig.mNumberLength);

  if (orig.mUnit != NULL)
  {
    mUnit = orig.mUnit->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for ArrayChild.
 */
ArrayChild&
ArrayChild::operator=(const ArrayChild& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mNumber = NULL;
    setNumber(rhs.mNumber, rhs.mNumberLength);
    delete mUnit;
    if (rhs.mUnit != NULL)
    {
      mUnit = rhs.mUnit->clone();
    }
    else
    {
      mUnit = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this ArrayChild object.
 */
ArrayChild*
ArrayChild::clone() const
{
  return new ArrayChild(*this);
}


/*
 * Destructor for ArrayChild.
 */
ArrayChild::~ArrayChild()
{
  if (mNumber != NULL)
  {
    delete [] mNumber;
  }

  mNumber = NULL;

  delete mUnit;
  mUnit = NULL;
}


/*
 * Returns the value of the "number" attribute of this ArrayChild.
 */
void
ArrayChild::getNumber(double* outArray) const
{
  if (outArray == NULL || mNumber == NULL)
  {
    return;
  }

  memcpy(outArray, mNumber, sizeof(double)*mNumberLength);
}


/*
 * Predicate returning @c true if this ArrayChild's "number" attribute is set.
 */
bool
ArrayChild::isSetNumber() const
{
  return (mNumber != NULL);
}


/*
 * Sets the value of the "number" attribute of this ArrayChild.
 */
int
ArrayChild::setNumber(double* inArray, int arrayLength)
{
  if (inArray == NULL)
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }

  if (mNumber != NULL)
  {
    delete[] mNumber;
  }

  mNumber = new double[arrayLength];
  memcpy(mNumber, inArray, sizeof(double)*arrayLength);
  mIsSetNumberLength = true;
  mNumberLength = arrayLength;

  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "number" attribute of this ArrayChild.
 */
int
ArrayChild::unsetNumber()
{
  if (mNumber != NULL)
  {
    delete[] mNumber;
  }

  mNumber = NULL;

  return unsetNumberLength();
}


/*
 * Returns the value of the "unit" element of this ArrayChild.
 */
const Unit*
ArrayChild::getUnit() const
{
  return mUnit;
}


/*
 * Returns the value of the "unit" element of this ArrayChild.
 */
Unit*
ArrayChild::getUnit()
{
  return mUnit;
}


/*
 * Predicate returning @c true if this ArrayChild's "unit" element is set.
 */
bool
ArrayChild::isSetUnit() const
{
  return (mUnit != NULL);
}


/*
 * Sets the value of the "unit" element of this ArrayChild.
 */
int
ArrayChild::setUnit(const Unit* unit)
{
  if (mUnit == unit)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (unit == NULL)
  {
    delete mUnit;
    mUnit = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mUnit;
    mUnit = (unit != NULL) ? unit->clone() : NULL;
    if (mUnit != NULL)
    {
      mUnit->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new Unit object, adds it to this ArrayChild object and returns the
 * Unit object created.
 */
Unit*
ArrayChild::createUnit()
{
  if (mUnit != NULL)
  {
    delete mUnit;
  }

  TEST_CREATE_NS(testns, getSBMLNamespaces());
  mUnit = new Unit(testns);

  delete testns;

  connectToChild();

  return mUnit;
}


/*
 * Unsets the value of the "unit" element of this ArrayChild.
 */
int
ArrayChild::unsetUnit()
{
  delete mUnit;
  mUnit = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this ArrayChild object.
 */
const std::string&
ArrayChild::getElementName() const
{
  static const string name = "arrayChild";
  return name;
}


/*
 * Returns the libSBML type code for this ArrayChild object.
 */
int
ArrayChild::getTypeCode() const
{
  return SBML_TEST_ARRAYCHILD;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * ArrayChild object have been set.
 */
bool
ArrayChild::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this ArrayChild
 * object have been set.
 */
bool
ArrayChild::hasRequiredElements() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
ArrayChild::writeElements(XMLOutputStream& stream) const
{
  SBase::writeElements(stream);

  if (isSetUnit() == true)
  {
    mUnit->write(stream);
  }

  SBase::writeExtensionElements(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
ArrayChild::accept(SBMLVisitor& v) const
{
  v.visit(*this);

  if (mUnit != NULL)
  {
    mUnit->accept(v);
  }

  v.leave(*this);
  return true;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
ArrayChild::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  if (mUnit != NULL)
  {
    mUnit->setSBMLDocument(d);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * used to write arrays
 */
void
ArrayChild::write(XMLOutputStream& stream) const
{
  stream.startElement(getElementName(), getPrefix());
  writeAttributes(stream);

  if (isSetNumber())
  {
    for (int i = 0; i < mNumberLength; ++i)
    {
      stream << (double)mNumber[i] << " ";
    }
  }

  stream.endElement(getElementName(), getPrefix());
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
ArrayChild::connectToChild()
{
  SBase::connectToChild();

  if (mUnit != NULL)
  {
    mUnit->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Enables/disables the given package with this element
 */
void
ArrayChild::enablePackageInternal(const std::string& pkgURI,
                                  const std::string& pkgPrefix,
                                  bool flag)
{
  SBase::enablePackageInternal(pkgURI, pkgPrefix, flag);

  if (isSetUnit())
  {
    mUnit->enablePackageInternal(pkgURI, pkgPrefix, flag);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::getAttribute(const std::string& attributeName,
                         const char* value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this ArrayChild's attribute "attributeName"
 * is set.
 */
bool
ArrayChild::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "number")
  {
    value = isSetNumber();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::setAttribute(const std::string& attributeName, const char* value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this ArrayChild.
 */
int
ArrayChild::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "number")
  {
    value = unsetNumber();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this ArrayChild.
 */
SBase*
ArrayChild::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "unit")
  {
    return createUnit();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this ArrayChild.
 */
int
ArrayChild::addChildObject(const std::string& elementName,
                           const SBase* element)
{
  if (elementName == "unit" && element->getTypeCode() == SBML_UNIT)
  {
    return setUnit((const Unit*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * ArrayChild.
 */
SBase*
ArrayChild::removeChildObject(const std::string& elementName,
                              const std::string& id)
{
  if (elementName == "unit")
  {
    Unit * obj = getUnit;
    if (unsetUnit() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this ArrayChild.
 */
unsigned int
ArrayChild::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "unit")
  {
    if (isSetUnit())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this ArrayChild.
 */
SBase*
ArrayChild::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "unit")
  {
    return getUnit();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
ArrayChild::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mUnit != NULL)
  {
    if (mUnit->getId() == id)
    {
      return mUnit;
    }

    obj = mUnit->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns the first child element that has the given @p metaid, or @c NULL if
 * no such object is found.
 */
SBase*
ArrayChild::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mUnit != NULL)
  {
    if (mUnit->getMetaId() == metaid)
    {
      return mUnit;
    }

    obj = mUnit->getElementByMetaId(metaid);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}


/*
 * Returns a List of all child SBase objects, including those nested to an
 * arbitrary depth.
 */
List*
ArrayChild::getAllElements(ElementFilter* filter)
{
  List* ret = new List();
  List* sublist = NULL;

  ADD_FILTERED_POINTER(ret, sublist, mUnit, filter);


  ADD_FILTERED_FROM_PLUGIN(ret, sublist, filter);

  return ret;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
ArrayChild::createObject(XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  TEST_CREATE_NS(testns, getSBMLNamespaces());

  if (prefix == targetPrefix)
  {
    if (name == "unit")
    {
      if (isSetUnit())
      {
        getErrorLog()->logPackageError("test", TestArrayChildAllowedElements,
          getPackageVersion(), getLevel(), getVersion());
      }

      mUnit = new Unit(testns);
      obj = mUnit;
    }
  }

  delete testns;

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
ArrayChild::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
ArrayChild::readAttributes(const XMLAttributes& attributes,
                           const ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int pkgVersion = getPackageVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  SBase::readAttributes(attributes, expectedAttributes);
  numErrs = log->getNumErrors();

  for (int n = numErrs-1; n >= 0; n--)
  {
    if (log->getError(n)->getErrorId() == UnknownPackageAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownPackageAttribute);
      log->logPackageError("test", TestArrayChildAllowedAttributes, pkgVersion,
        level, version, details);
    }
    else if (log->getError(n)->getErrorId() == UnknownCoreAttribute)
    {
      const std::string details = log->getError(n)->getMessage();
      log->remove(UnknownCoreAttribute);
      log->logPackageError("test", TestArrayChildAllowedCoreAttributes,
        pkgVersion, level, version, details);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
ArrayChild::writeAttributes(XMLOutputStream& stream) const
{
  SBase::writeAttributes(stream);

  SBase::writeExtensionAttributes(stream);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the array data as a text element
 */
void
ArrayChild::setElementText(const std::string& text)
{
  stringstream strStream(text);
  double val;
  vector<double> valuesVector;

  while (strStream >> val)
  {
    valuesVector.push_back(val);
  }

  unsigned int length = (unsigned int)valuesVector.size();

  if (length > 0)
  {
    double* data = new double[length];
    for (unsigned int i = 0; i < length; ++i)
    {
      data[i] = valuesVector.at(i);
    }

    setNumber(data, length);
    delete[] data;
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new ArrayChild_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 */
LIBSBML_EXTERN
ArrayChild_t *
ArrayChild_create(unsigned int level,
                  unsigned int version,
                  unsigned int pkgVersion)
{
  return new ArrayChild(level, version, pkgVersion);
}


/*
 * Creates and returns a deep copy of this ArrayChild_t object.
 */
LIBSBML_EXTERN
ArrayChild_t*
ArrayChild_clone(const ArrayChild_t* ac)
{
  if (ac != NULL)
  {
    return static_cast<ArrayChild_t*>(ac->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this ArrayChild_t object.
 */
LIBSBML_EXTERN
void
ArrayChild_free(ArrayChild_t* ac)
{
  if (ac != NULL)
  {
    delete ac;
  }
}


/*
 * Predicate returning @c 1 if this ArrayChild_t's "number" attribute is set.
 */
LIBSBML_EXTERN
int
ArrayChild_isSetNumber(const ArrayChild_t * ac)
{
  return (ac != NULL) ? static_cast<int>(ac->isSetNumber()) : 0;
}


/*
 * Sets the value of the "number" attribute of this ArrayChild_t.
 */
LIBSBML_EXTERN
int
ArrayChild_setNumber(ArrayChild_t* ac, double* number, int arrayLength)
{
  return (ac != NULL) ? ac->setNumber(number, arrayLength) :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "number" attribute of this ArrayChild_t.
 */
LIBSBML_EXTERN
int
ArrayChild_unsetNumber(ArrayChild_t * ac)
{
  return (ac != NULL) ? ac->unsetNumber() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "unit" element of this ArrayChild_t.
 */
LIBSBML_EXTERN
const Unit_t*
ArrayChild_getUnit(const ArrayChild_t * ac)
{
  if (ac == NULL)
  {
    return NULL;
  }

  return (Unit_t*)(ac->getUnit());
}


/*
 * Predicate returning @c 1 if this ArrayChild_t's "unit" element is set.
 */
LIBSBML_EXTERN
int
ArrayChild_isSetUnit(const ArrayChild_t * ac)
{
  return (ac != NULL) ? static_cast<int>(ac->isSetUnit()) : 0;
}


/*
 * Sets the value of the "unit" element of this ArrayChild_t.
 */
LIBSBML_EXTERN
int
ArrayChild_setUnit(ArrayChild_t * ac, const Unit_t* unit)
{
  return (ac != NULL) ? ac->setUnit(unit) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new Unit_t object, adds it to this ArrayChild_t object and returns
 * the Unit_t object created.
 */
LIBSBML_EXTERN
Unit_t*
ArrayChild_createUnit(ArrayChild_t* ac)
{
  if (ac == NULL)
  {
    return NULL;
  }

  return (Unit_t*)(ac->createUnit());
}


/*
 * Unsets the value of the "unit" element of this ArrayChild_t.
 */
LIBSBML_EXTERN
int
ArrayChild_unsetUnit(ArrayChild_t * ac)
{
  return (ac != NULL) ? ac->unsetUnit() : LIBSBML_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 if all the required attributes for this
 * ArrayChild_t object have been set.
 */
LIBSBML_EXTERN
int
ArrayChild_hasRequiredAttributes(const ArrayChild_t * ac)
{
  return (ac != NULL) ? static_cast<int>(ac->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 if all the required elements for this ArrayChild_t
 * object have been set.
 */
LIBSBML_EXTERN
int
ArrayChild_hasRequiredElements(const ArrayChild_t * ac)
{
  return (ac != NULL) ? static_cast<int>(ac->hasRequiredElements()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


