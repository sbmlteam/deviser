/**
 * @file Compartment.h
 * @brief Definition of the Compartment class.
 * @author DEVISER
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
 *
 * @class Compartment
 * @sbmlbrief{core} TODO:Definition of the Compartment class.
 */


#ifndef Compartment_H__
#define Compartment_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Compartment : public SBase
{
protected:

  /** @cond doxygenLibSBMLInternal */

  double mSize;
  bool mIsSetSize;
  double mVolume;
  bool mIsSetVolume;
  std::string mUnits;
  unsigned int mSpatialDimensions;
  bool mIsSetSpatialDimensions;
  bool mConstant;
  bool mIsSetConstant;
  std::string mOutside;
  std::string mCompartmentType;

  /** @endcond */

public:

  /**
   * Creates a new Compartment using the given SBML Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * Compartment.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Compartment.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Compartment(unsigned int level = SBML_DEFAULT_LEVEL,
              unsigned int version = SBML_DEFAULT_VERSION);


  /**
   * Creates a new Compartment using the given SBMLNamespaces object @p sbmlns.
   *
   * @param sbmlns the SBMLNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Compartment(SBMLNamespaces *sbmlns);


  /**
   * Copy constructor for Compartment.
   *
   * @param orig the Compartment instance to copy.
   */
  Compartment(const Compartment& orig);


  /**
   * Assignment operator for Compartment.
   *
   * @param rhs the Compartment object whose values are to be used as the basis
   * of the assignment.
   */
  Compartment& operator=(const Compartment& rhs);


  /**
   * Creates and returns a deep copy of this Compartment object.
   *
   * @return a (deep) copy of this Compartment object.
   */
  virtual Compartment* clone() const;


  /**
   * Destructor for Compartment.
   */
  virtual ~Compartment();


  /**
   * Returns the value of the "size" attribute of this Compartment.
   *
   * @return the value of the "size" attribute of this Compartment as a double.
   */
  double getSize() const;


  /**
   * Returns the value of the "volume" attribute of this Compartment.
   *
   * @return the value of the "volume" attribute of this Compartment as a
   * double.
   */
  double getVolume() const;


  /**
   * Returns the value of the "units" attribute of this Compartment.
   *
   * @return the value of the "units" attribute of this Compartment as a
   * string.
   */
  const std::string& getUnits() const;


  /**
   * Returns the value of the "spatialDimensions" attribute of this
   * Compartment.
   *
   * @return the value of the "spatialDimensions" attribute of this Compartment
   * as a unsigned integer.
   */
  unsigned int getSpatialDimensions() const;


  /**
   * Returns the value of the "constant" attribute of this Compartment.
   *
   * @return the value of the "constant" attribute of this Compartment as a
   * boolean.
   */
  bool getConstant() const;


  /**
   * Returns the value of the "outside" attribute of this Compartment.
   *
   * @return the value of the "outside" attribute of this Compartment as a
   * string.
   */
  const std::string& getOutside() const;


  /**
   * Returns the value of the "compartmentType" attribute of this Compartment.
   *
   * @return the value of the "compartmentType" attribute of this Compartment
   * as a string.
   */
  const std::string& getCompartmentType() const;


  /**
   * Predicate returning @c true if this Compartment's "size" attribute is set.
   *
   * @return @c true if this Compartment's "size" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetSize() const;


  /**
   * Predicate returning @c true if this Compartment's "volume" attribute is
   * set.
   *
   * @return @c true if this Compartment's "volume" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetVolume() const;


  /**
   * Predicate returning @c true if this Compartment's "units" attribute is
   * set.
   *
   * @return @c true if this Compartment's "units" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetUnits() const;


  /**
   * Predicate returning @c true if this Compartment's "spatialDimensions"
   * attribute is set.
   *
   * @return @c true if this Compartment's "spatialDimensions" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetSpatialDimensions() const;


  /**
   * Predicate returning @c true if this Compartment's "constant" attribute is
   * set.
   *
   * @return @c true if this Compartment's "constant" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetConstant() const;


  /**
   * Predicate returning @c true if this Compartment's "outside" attribute is
   * set.
   *
   * @return @c true if this Compartment's "outside" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetOutside() const;


  /**
   * Predicate returning @c true if this Compartment's "compartmentType"
   * attribute is set.
   *
   * @return @c true if this Compartment's "compartmentType" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetCompartmentType() const;


  /**
   * Sets the value of the "size" attribute of this Compartment.
   *
   * @param size double value of the "size" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setSize(double size);


  /**
   * Sets the value of the "volume" attribute of this Compartment.
   *
   * @param volume double value of the "volume" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setVolume(double volume);


  /**
   * Sets the value of the "units" attribute of this Compartment.
   *
   * @param units std::string& value of the "units" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUnits(const std::string& units);


  /**
   * Sets the value of the "spatialDimensions" attribute of this Compartment.
   *
   * @param spatialDimensions unsigned int value of the "spatialDimensions"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setSpatialDimensions(unsigned int spatialDimensions);


  /**
   * Sets the value of the "constant" attribute of this Compartment.
   *
   * @param constant bool value of the "constant" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setConstant(bool constant);


  /**
   * Sets the value of the "outside" attribute of this Compartment.
   *
   * @param outside std::string& value of the "outside" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOutside(const std::string& outside);


  /**
   * Sets the value of the "compartmentType" attribute of this Compartment.
   *
   * @param compartmentType std::string& value of the "compartmentType"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCompartmentType(const std::string& compartmentType);


  /**
   * Unsets the value of the "size" attribute of this Compartment.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSize();


  /**
   * Unsets the value of the "volume" attribute of this Compartment.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetVolume();


  /**
   * Unsets the value of the "units" attribute of this Compartment.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUnits();


  /**
   * Unsets the value of the "spatialDimensions" attribute of this Compartment.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSpatialDimensions();


  /**
   * Unsets the value of the "constant" attribute of this Compartment.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetConstant();


  /**
   * Unsets the value of the "outside" attribute of this Compartment.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOutside();


  /**
   * Unsets the value of the "compartmentType" attribute of this Compartment.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCompartmentType();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this Compartment object.
   *
   * For Compartment, the XML element name is always @c "".
   *
   * @return the name of this element, i.e. @c "".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Compartment object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{CORE_COMPARTMENT, SBMLCoreTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * Compartment object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * Compartment have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Compartment object are:
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibSBMLInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Sets the parent SBMLDocument
   */
  virtual void setSBMLDocument(SBMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value);
    const

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Predicate returning @c true if this Compartment's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Compartment's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this Compartment.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */


protected:


  /** @cond doxygenLibSBMLInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibSBMLInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Compartment_t using the given SBML Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Compartment_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Compartment_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
Compartment_t *
Compartment_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this Compartment_t object.
 *
 * @param c the Compartment_t structure.
 *
 * @return a (deep) copy of this Compartment_t object.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
Compartment_t*
Compartment_clone(const Compartment_t* c);


/**
 * Frees this Compartment_t object.
 *
 * @param c the Compartment_t structure.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
void
Compartment_free(Compartment_t* c);


/**
 * Returns the value of the "size" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure whose size is sought.
 *
 * @return the value of the "size" attribute of this Compartment_t as a double.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
double
Compartment_getSize(const Compartment_t * c);


/**
 * Returns the value of the "volume" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure whose volume is sought.
 *
 * @return the value of the "volume" attribute of this Compartment_t as a
 * double.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
double
Compartment_getVolume(const Compartment_t * c);


/**
 * Returns the value of the "units" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure whose units is sought.
 *
 * @return the value of the "units" attribute of this Compartment_t as a
 * pointer to a string.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
const char *
Compartment_getUnits(const Compartment_t * c);


/**
 * Returns the value of the "spatialDimensions" attribute of this
 * Compartment_t.
 *
 * @param c the Compartment_t structure whose spatialDimensions is sought.
 *
 * @return the value of the "spatialDimensions" attribute of this Compartment_t
 * as a unsigned integer.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
unsigned int
Compartment_getSpatialDimensions(const Compartment_t * c);


/**
 * Returns the value of the "constant" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure whose constant is sought.
 *
 * @return the value of the "constant" attribute of this Compartment_t as a
 * boolean.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_getConstant(const Compartment_t * c);


/**
 * Returns the value of the "outside" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure whose outside is sought.
 *
 * @return the value of the "outside" attribute of this Compartment_t as a
 * pointer to a string.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
const char *
Compartment_getOutside(const Compartment_t * c);


/**
 * Returns the value of the "compartmentType" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure whose compartmentType is sought.
 *
 * @return the value of the "compartmentType" attribute of this Compartment_t
 * as a pointer to a string.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
const char *
Compartment_getCompartmentType(const Compartment_t * c);


/**
 * Predicate returning @c 1 if this Compartment_t's "size" attribute is set.
 *
 * @param c the Compartment_t structure.
 *
 * @return @c 1 if this Compartment_t's "size" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_isSetSize(const Compartment_t * c);


/**
 * Predicate returning @c 1 if this Compartment_t's "volume" attribute is set.
 *
 * @param c the Compartment_t structure.
 *
 * @return @c 1 if this Compartment_t's "volume" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_isSetVolume(const Compartment_t * c);


/**
 * Predicate returning @c 1 if this Compartment_t's "units" attribute is set.
 *
 * @param c the Compartment_t structure.
 *
 * @return @c 1 if this Compartment_t's "units" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_isSetUnits(const Compartment_t * c);


/**
 * Predicate returning @c 1 if this Compartment_t's "spatialDimensions"
 * attribute is set.
 *
 * @param c the Compartment_t structure.
 *
 * @return @c 1 if this Compartment_t's "spatialDimensions" attribute has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_isSetSpatialDimensions(const Compartment_t * c);


/**
 * Predicate returning @c 1 if this Compartment_t's "constant" attribute is
 * set.
 *
 * @param c the Compartment_t structure.
 *
 * @return @c 1 if this Compartment_t's "constant" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_isSetConstant(const Compartment_t * c);


/**
 * Predicate returning @c 1 if this Compartment_t's "outside" attribute is set.
 *
 * @param c the Compartment_t structure.
 *
 * @return @c 1 if this Compartment_t's "outside" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_isSetOutside(const Compartment_t * c);


/**
 * Predicate returning @c 1 if this Compartment_t's "compartmentType" attribute
 * is set.
 *
 * @param c the Compartment_t structure.
 *
 * @return @c 1 if this Compartment_t's "compartmentType" attribute has been
 * set, otherwise @c 0 is returned.
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_isSetCompartmentType(const Compartment_t * c);


/**
 * Sets the value of the "size" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @param size double value of the "size" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_setSize(Compartment_t * c, double size);


/**
 * Sets the value of the "volume" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @param volume double value of the "volume" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_setVolume(Compartment_t * c, double volume);


/**
 * Sets the value of the "units" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @param units const char * value of the "units" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_setUnits(Compartment_t * c, const char * units);


/**
 * Sets the value of the "spatialDimensions" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @param spatialDimensions unsigned int value of the "spatialDimensions"
 * attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_setSpatialDimensions(Compartment_t * c,
                                 unsigned int spatialDimensions);


/**
 * Sets the value of the "constant" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @param constant int value of the "constant" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_setConstant(Compartment_t * c, int constant);


/**
 * Sets the value of the "outside" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @param outside const char * value of the "outside" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_setOutside(Compartment_t * c, const char * outside);


/**
 * Sets the value of the "compartmentType" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @param compartmentType const char * value of the "compartmentType" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_setCompartmentType(Compartment_t * c,
                               const char * compartmentType);


/**
 * Unsets the value of the "size" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_unsetSize(Compartment_t * c);


/**
 * Unsets the value of the "volume" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_unsetVolume(Compartment_t * c);


/**
 * Unsets the value of the "units" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_unsetUnits(Compartment_t * c);


/**
 * Unsets the value of the "spatialDimensions" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_unsetSpatialDimensions(Compartment_t * c);


/**
 * Unsets the value of the "constant" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_unsetConstant(Compartment_t * c);


/**
 * Unsets the value of the "outside" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_unsetOutside(Compartment_t * c);


/**
 * Unsets the value of the "compartmentType" attribute of this Compartment_t.
 *
 * @param c the Compartment_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_unsetCompartmentType(Compartment_t * c);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * Compartment_t object have been set.
 *
 * @param c the Compartment_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * Compartment_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the Compartment_t object are:
 *
 * @memberof Compartment_t
 */
LIBSBML_EXTERN
int
Compartment_hasRequiredAttributes(const Compartment_t * c);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Compartment_H__ */


