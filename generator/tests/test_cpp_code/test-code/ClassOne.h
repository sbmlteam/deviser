/**
 * @file: ClassOne.h
 * @brief: Definition of ClassOne.
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
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


#ifndef ClassOne_H__
#define ClassOne_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/vers/common/versfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/vers/extension/VersExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ClassOne : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  bool mAtt1;
  bool mIsSetAtt1;
  std::string mId;
  bool mAtt2;
  bool mIsSetAtt2;

  /** @endcond */

public:

  /**
   * Creates a new ClassOne using the given SBML @p level, @ p version and
   * package version values.
   *
   * @param level an unsigned int, the SBML Level to assign to this ClassOne
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ClassOne
   *
   * @param pkgVersion an unsigned int, the SBML Vers Version to assign to this
   * ClassOne
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ClassOne(unsigned int level = VersExtension::getDefaultLevel(),
           unsigned int version = VersExtension::getDefaultVersion(),
           unsigned int pkgVersion =
             VersExtension::getDefaultPackageVersion());


  /**
   * Creates a new ClassOne using the given VersPkgNamespaces object.
   *
   * @param versns the VersPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ClassOne(VersPkgNamespaces *versns);


  /**
   * Copy constructor for ClassOne.
   *
   * @param orig; the ClassOne instance to copy.
   */
  ClassOne(const ClassOne& orig);


  /**
   * Assignment operator for ClassOne.
   *
   * @param rhs; the ClassOne object whose values are to be used as the basis
   * of the assignment
   */
  ClassOne& operator=(const ClassOne& rhs);


  /**
   * Creates and returns a deep copy of this ClassOne object.
   *
   * @return a (deep) copy of this ClassOne object.
   */
  virtual ClassOne* clone() const;


  /**
   * Destructor for ClassOne.
   */
  virtual ~ClassOne();


  /**
   * Returns the value of the "id" attribute of this ClassOne.
   *
   * @return the value of the "id" attribute of this ClassOne as a string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "att1" attribute of this ClassOne.
   *
   * @return the value of the "att1" attribute of this ClassOne as a boolean.
   */
  bool getAtt1() const;


  /**
   * Returns the value of the "att2" attribute of this ClassOne.
   *
   * @return the value of the "att2" attribute of this ClassOne as a boolean.
   */
  bool getAtt2() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * ClassOne's "id" attribute has been set.
   *
   * @return @c true if this ClassOne's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * ClassOne's "att1" attribute has been set.
   *
   * @return @c true if this ClassOne's "att1" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetAtt1() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * ClassOne's "att2" attribute has been set.
   *
   * @return @c true if this ClassOne's "att2" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetAtt2() const;


  /**
   * Sets the value of the "id" attribute of this ClassOne.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setId(const std::string& id);


  /**
   * Sets the value of the "att1" attribute of this ClassOne.
   *
   * @param att1 bool value of the "att1" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAtt1(bool att1);


  /**
   * Sets the value of the "att2" attribute of this ClassOne.
   *
   * @param att2 bool value of the "att2" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAtt2(bool att2);


  /**
   * Unsets the value of the "id" attribute of this ClassOne.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "att1" attribute of this ClassOne.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAtt1();


  /**
   * Unsets the value of the "att2" attribute of this ClassOne.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAtt2();


  /**
   * Returns the XML name of this ClassOne object.
   *
   * @return the name of this element; that is "classOne".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML typcode of this ClassOne object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{CLASS_ONE, SBMLVersTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * ClassOne object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * ClassOne have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the ClassOne object are:
   * @li "id"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Accepts the given SBMLVisitor
   */
  virtual bool accept(SBMLVisitor& v) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the parent SBMLDocument
   */
  virtual void setSBMLDocument(SBMLDocument* d);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readV1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readV2Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeV1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeV2Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new ClassOne_t using the given SBML @p level, @ p version and
 * package version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this ClassOne_t
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ClassOne_t
 *
 * @param pkgVersion an unsigned int, the SBML Vers Version to assign to this
 * ClassOne_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
ClassOne_t *
ClassOne_create(unsigned int level = VersExtension::getDefaultLevel(),
                unsigned int version = VersExtension::getDefaultVersion(),
                unsigned int pkgVersion =
                  VersExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this ClassOne_t object.
 *
 * @param co; the ClassOne_t structure
 *
 * @return a (deep) copy of this ClassOne_t object.
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
ClassOne_t*
ClassOne_clone(const ClassOne_t* co);


/**
 * Frees this ClassOne_t object.
 *
 * @param co; the ClassOne_t structure
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
void
ClassOne_free(ClassOne_t* co);


/**
 * Returns the value of the "id" attribute of this ClassOne_t.
 *
 * @param co the ClassOne_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this ClassOne_t as a pointer to a
 * string.
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
const char *
ClassOne_getId(const ClassOne_t * co);


/**
 * Returns the value of the "att1" attribute of this ClassOne_t.
 *
 * @param co the ClassOne_t structure whose att1 is sought.
 *
 * @return the value of the "att1" attribute of this ClassOne_t as a boolean.
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_getAtt1(const ClassOne_t * co);


/**
 * Returns the value of the "att2" attribute of this ClassOne_t.
 *
 * @param co the ClassOne_t structure whose att2 is sought.
 *
 * @return the value of the "att2" attribute of this ClassOne_t as a boolean.
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_getAtt2(const ClassOne_t * co);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this ClassOne_t's "id"
 * attribute has been set.
 *
 * @param co the ClassOne_t structure.
 *
 * @return @c 1 if this ClassOne_t's "id" attribute has been set, otherwise @c
 * 0 is returned.
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_isSetId(const ClassOne_t * co);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this ClassOne_t's
 * "att1" attribute has been set.
 *
 * @param co the ClassOne_t structure.
 *
 * @return @c 1 if this ClassOne_t's "att1" attribute has been set, otherwise
 * @c 0 is returned.
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_isSetAtt1(const ClassOne_t * co);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this ClassOne_t's
 * "att2" attribute has been set.
 *
 * @param co the ClassOne_t structure.
 *
 * @return @c 1 if this ClassOne_t's "att2" attribute has been set, otherwise
 * @c 0 is returned.
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_isSetAtt2(const ClassOne_t * co);


/**
 * Sets the value of the "id" attribute of this ClassOne_t.
 *
 * @param co the ClassOne_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_setId(ClassOne_t * co, const char * id);


/**
 * Sets the value of the "att1" attribute of this ClassOne_t.
 *
 * @param co the ClassOne_t structure.
 *
 * @param att1 int value of the "att1" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_setAtt1(ClassOne_t * co, int att1);


/**
 * Sets the value of the "att2" attribute of this ClassOne_t.
 *
 * @param co the ClassOne_t structure.
 *
 * @param att2 int value of the "att2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_setAtt2(ClassOne_t * co, int att2);


/**
 * Unsets the value of the "id" attribute of this ClassOne_t.
 *
 * @param co the ClassOne_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_unsetId(ClassOne_t * co);


/**
 * Unsets the value of the "att1" attribute of this ClassOne_t.
 *
 * @param co the ClassOne_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_unsetAtt1(ClassOne_t * co);


/**
 * Unsets the value of the "att2" attribute of this ClassOne_t.
 *
 * @param co the ClassOne_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_unsetAtt2(ClassOne_t * co);


/**
 * Predicate returning @c 1 if all the required attributes for this ClassOne_t
 * object have been set.
 *
 * @param co the ClassOne_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this ClassOne_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the ClassOne_t object are:
 * @li "id"
 *
 * @memberof ClassOne_t
 */
LIBSBML_EXTERN
int
ClassOne_hasRequiredAttributes(const ClassOne_t * co);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ClassOne_H__ */


