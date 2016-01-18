/**
 * @file Fred.h
 * @brief Definition of the Fred class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2015 jointly by the following organizations:
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
 * @class Fred
 * @sbmlbrief{x} TODO:Definition of the Fred class.
 */


#ifndef Fred_H__
#define Fred_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/x/common/xfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/x/extension/XExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Fred : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  bool mBool;
  bool mIsSetBool;
  int mNum;
  bool mIsSetNum;
  std::string mStr;
  Kind_t mKind;

  /** @endcond */

public:

  /**
   * Creates a new Fred using the given SBML Level, Version and &ldquo;x&rdquo;
   * package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Fred
   *
   * @param version an unsigned int, the SBML Version to assign to this Fred
   *
   * @param pkgVersion an unsigned int, the SBML X Version to assign to this
   * Fred
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Fred(unsigned int level = XExtension::getDefaultLevel(),
       unsigned int version = XExtension::getDefaultVersion(),
       unsigned int pkgVersion = XExtension::getDefaultPackageVersion());


  /**
   * Creates a new Fred using the given XPkgNamespaces object.
   *
   * @param xns the XPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Fred(XPkgNamespaces *xns);


  /**
   * Copy constructor for Fred.
   *
   * @param orig; the Fred instance to copy.
   */
  Fred(const Fred& orig);


  /**
   * Assignment operator for Fred.
   *
   * @param rhs; the Fred object whose values are to be used as the basis of
   * the assignment
   */
  Fred& operator=(const Fred& rhs);


  /**
   * Creates and returns a deep copy of this Fred object.
   *
   * @return a (deep) copy of this Fred object.
   */
  virtual Fred* clone() const;


  /**
   * Destructor for Fred.
   */
  virtual ~Fred();


  /**
   * Returns the value of the "id" attribute of this Fred.
   *
   * @return the value of the "id" attribute of this Fred as a string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "bool" attribute of this Fred.
   *
   * @return the value of the "bool" attribute of this Fred as a boolean.
   */
  bool getBool() const;


  /**
   * Returns the value of the "num" attribute of this Fred.
   *
   * @return the value of the "num" attribute of this Fred as a integer.
   */
  int getNum() const;


  /**
   * Returns the value of the "str" attribute of this Fred.
   *
   * @return the value of the "str" attribute of this Fred as a string.
   */
  const std::string& getStr() const;


  /**
   * Returns the value of the "kind" attribute of this Fred.
   *
   * @return the value of the "kind" attribute of this Fred as a Kind_t.
   */
  Kind_t getKind() const;


  /**
   * Returns the value of the "kind" attribute of this Fred.
   *
   * @return the value of the "kind" attribute of this Fred as a string.
   */
  const std::string& getKindAsString() const;


  /**
   * Predicate returning @c true if this Fred's "id" attribute is set.
   *
   * @return @c true if this Fred's "id" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true if this Fred's "bool" attribute is set.
   *
   * @return @c true if this Fred's "bool" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetBool() const;


  /**
   * Predicate returning @c true if this Fred's "num" attribute is set.
   *
   * @return @c true if this Fred's "num" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetNum() const;


  /**
   * Predicate returning @c true if this Fred's "str" attribute is set.
   *
   * @return @c true if this Fred's "str" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetStr() const;


  /**
   * Predicate returning @c true if this Fred's "kind" attribute is set.
   *
   * @return @c true if this Fred's "kind" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetKind() const;


  /**
   * Sets the value of the "id" attribute of this Fred.
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
   * Sets the value of the "bool" attribute of this Fred.
   *
   * @param bool bool value of the "bool" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBool(bool bool);


  /**
   * Sets the value of the "num" attribute of this Fred.
   *
   * @param num int value of the "num" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum(int num);


  /**
   * Sets the value of the "str" attribute of this Fred.
   *
   * @param str std::string& value of the "str" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStr(const std::string& str);


  /**
   * Sets the value of the "kind" attribute of this Fred.
   *
   * @param kind Kind_t value of the "kind" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setKind(const Kind_t kind);


  /**
   * Sets the value of the "kind" attribute of this Fred.
   *
   * @param kind std::string& of the "kind" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setKind(const std::string& kind);


  /**
   * Unsets the value of the "id" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "bool" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBool();


  /**
   * Unsets the value of the "num" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum();


  /**
   * Unsets the value of the "str" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStr();


  /**
   * Unsets the value of the "kind" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetKind();


  /**
   * Returns the XML element name of this Fred object.
   *
   * For Fred, the XML element name is always @c "fred".
   *
   * @return the name of this element, i.e. @c "fred".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Fred object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_X_FRED, SBMLXTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this Fred
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this Fred
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Fred object are:
   * @li "identifier"
   * @li "myNumber"
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
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Fred_t using the given SBML Level, Version and &ldquo;x&rdquo;
 * package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Fred_t
 *
 * @param version an unsigned int, the SBML Version to assign to this Fred_t
 *
 * @param pkgVersion an unsigned int, the SBML X Version to assign to this
 * Fred_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Fred_t *
Fred_create(unsigned int level = XExtension::getDefaultLevel(),
            unsigned int version = XExtension::getDefaultVersion(),
            unsigned int pkgVersion = XExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this Fred_t object.
 *
 * @param f; the Fred_t structure
 *
 * @return a (deep) copy of this Fred_t object.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Fred_t*
Fred_clone(const Fred_t* f);


/**
 * Frees this Fred_t object.
 *
 * @param f; the Fred_t structure
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
void
Fred_free(Fred_t* f);


/**
 * Returns the value of the "id" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this Fred_t as a pointer to a
 * string.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
const char *
Fred_getId(const Fred_t * f);


/**
 * Returns the value of the "bool" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose bool is sought.
 *
 * @return the value of the "bool" attribute of this Fred_t as a boolean.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_getBool(const Fred_t * f);


/**
 * Returns the value of the "num" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose num is sought.
 *
 * @return the value of the "num" attribute of this Fred_t as a integer.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_getNum(const Fred_t * f);


/**
 * Returns the value of the "str" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose str is sought.
 *
 * @return the value of the "str" attribute of this Fred_t as a pointer to a
 * string.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
const char *
Fred_getStr(const Fred_t * f);


/**
 * Returns the value of the "kind" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose kind is sought.
 *
 * @return the value of the "kind" attribute of this Fred_t as a Kind_t.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Kind_t
Fred_getKind(const Fred_t * f);


/**
 * Returns the value of the "kind" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose kind is sought.
 *
 * @return the value of the "kind" attribute of this Fred_t as a const char *.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
const char *
Fred_getKindAsString(const Fred_t * f);


/**
 * Predicate returning @c 1 if this Fred_t's "id" attribute is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 if this Fred_t's "id" attribute has been set, otherwise @c 0 is
 * returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetId(const Fred_t * f);


/**
 * Predicate returning @c 1 if this Fred_t's "bool" attribute is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 if this Fred_t's "bool" attribute has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetBool(const Fred_t * f);


/**
 * Predicate returning @c 1 if this Fred_t's "num" attribute is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 if this Fred_t's "num" attribute has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetNum(const Fred_t * f);


/**
 * Predicate returning @c 1 if this Fred_t's "str" attribute is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 if this Fred_t's "str" attribute has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetStr(const Fred_t * f);


/**
 * Predicate returning @c 1 if this Fred_t's "kind" attribute is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 if this Fred_t's "kind" attribute has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetKind(const Fred_t * f);


/**
 * Sets the value of the "id" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setId(Fred_t * f, const char * id);


/**
 * Sets the value of the "bool" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param bool int value of the "bool" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setBool(Fred_t * f, int bool);


/**
 * Sets the value of the "num" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param num int value of the "num" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setNum(Fred_t * f, int num);


/**
 * Sets the value of the "str" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param str const char * value of the "str" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setStr(Fred_t * f, const char * str);


/**
 * Sets the value of the "kind" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param kind Kind_t value of the "kind" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setKind(Fred_t * f, Kind_t kind);


/**
 * Sets the value of the "kind" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param kind const char * of the "kind" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setKindAsString(Fred_t * f, const char * kind);


/**
 * Unsets the value of the "id" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetId(Fred_t * f);


/**
 * Unsets the value of the "bool" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetBool(Fred_t * f);


/**
 * Unsets the value of the "num" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetNum(Fred_t * f);


/**
 * Unsets the value of the "str" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetStr(Fred_t * f);


/**
 * Unsets the value of the "kind" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetKind(Fred_t * f);


/**
 * Predicate returning @c 1 if all the required attributes for this Fred_t
 * object have been set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this Fred_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the Fred_t object are:
 * @li "identifier"
 * @li "myNumber"
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_hasRequiredAttributes(const Fred_t * f);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Fred_H__ */


