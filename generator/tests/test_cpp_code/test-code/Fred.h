/**
 * @file Fred.h
 * @brief Definition of the Fred class.
 * @author SBMLTeam
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
#include <sbml/packages/x/sbml/Other.h>
#include <sbml/packages/x/sbml/Other.h>
#include <sbml/packages/x/sbml/Other.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Fred : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  bool mBol;
  bool mIsSetBol;
  int mNum;
  bool mIsSetNum;
  std::string mStr;
  Kind_t mKind;
  Other* mOther;
  Other* mOther1;
  Other* mOther2;

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
   * Returns the value of the "bol" attribute of this Fred.
   *
   * @return the value of the "bol" attribute of this Fred as a boolean.
   */
  bool getBol() const;


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
   * Predicate returning @c true if this Fred's "bol" attribute is set.
   *
   * @return @c true if this Fred's "bol" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetBol() const;


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
   * Sets the value of the "bol" attribute of this Fred.
   *
   * @param bol bool value of the "bol" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBol(bool bol);


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
   * Unsets the value of the "bol" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBol();


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
   * Returns the value of the "other" element of this Fred.
   *
   * @return the value of the "other" element of this Fred as a Other*.
   */
  const Other* getOther() const;


  /**
   * Returns the value of the "other" element of this Fred.
   *
   * @return the value of the "other" element of this Fred as a Other*.
   */
  Other* getOther();


  /**
   * Returns the value of the "other1" element of this Fred.
   *
   * @return the value of the "other1" element of this Fred as a Other*.
   */
  const Other* getOther1() const;


  /**
   * Returns the value of the "other1" element of this Fred.
   *
   * @return the value of the "other1" element of this Fred as a Other*.
   */
  Other* getOther1();


  /**
   * Returns the value of the "other2" element of this Fred.
   *
   * @return the value of the "other2" element of this Fred as a Other*.
   */
  const Other* getOther2() const;


  /**
   * Returns the value of the "other2" element of this Fred.
   *
   * @return the value of the "other2" element of this Fred as a Other*.
   */
  Other* getOther2();


  /**
   * Predicate returning @c true if this Fred's "other" element is set.
   *
   * @return @c true if this Fred's "other" element has been set, otherwise @c
   * false is returned.
   */
  bool isSetOther() const;


  /**
   * Predicate returning @c true if this Fred's "other1" element is set.
   *
   * @return @c true if this Fred's "other1" element has been set, otherwise @c
   * false is returned.
   */
  bool isSetOther1() const;


  /**
   * Predicate returning @c true if this Fred's "other2" element is set.
   *
   * @return @c true if this Fred's "other2" element has been set, otherwise @c
   * false is returned.
   */
  bool isSetOther2() const;


  /**
   * Sets the value of the "other" element of this Fred.
   *
   * @param other Other* value of the "other" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOther(const Other* other);


  /**
   * Sets the value of the "other1" element of this Fred.
   *
   * @param other1 Other* value of the "other1" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOther1(const Other* other1);


  /**
   * Sets the value of the "other2" element of this Fred.
   *
   * @param other2 Other* value of the "other2" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOther2(const Other* other2);


  /**
   * Creates a new Other object, adds it to this Fred object and returns the
   * Other object created.
   *
   * @return a new Other object instance.
   */
  Other* createOther();


  /**
   * Creates a new Other object, adds it to this Fred object and returns the
   * Other object created.
   *
   * @return a new Other object instance.
   */
  Other* createOther1();


  /**
   * Creates a new Other object, adds it to this Fred object and returns the
   * Other object created.
   *
   * @return a new Other object instance.
   */
  Other* createOther2();


  /**
   * Unsets the value of the "other" element of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOther();


  /**
   * Unsets the value of the "other1" element of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOther1();


  /**
   * Unsets the value of the "other2" element of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetOther2();


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


  /**
   * Predicate returning @c true if all the required elements for this Fred
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this Fred
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Fred object are:
   */
  virtual bool hasRequiredElements() const;



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
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * filter, an ElementFilter that may impose restrictions on the objects to be
   * retrieved.
   *
   * @return a List* pointer of pointers to all SBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(ElementFilter * filter = NULL);


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



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
 * Returns the value of the "bol" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose bol is sought.
 *
 * @return the value of the "bol" attribute of this Fred_t as a boolean.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_getBol(const Fred_t * f);


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
 * Predicate returning @c 1 if this Fred_t's "bol" attribute is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 if this Fred_t's "bol" attribute has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetBol(const Fred_t * f);


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
 * Sets the value of the "bol" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param bol int value of the "bol" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setBol(Fred_t * f, int bol);


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
 * Unsets the value of the "bol" attribute of this Fred_t.
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
Fred_unsetBol(Fred_t * f);


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
 * Returns the value of the "other" element of this Fred_t.
 *
 * @param f the Fred_t structure whose other is sought.
 *
 * @return the value of the "other" element of this Fred_t as a Other*.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
const Other_t*
Fred_getOther(const Fred_t * f);


/**
 * Returns the value of the "other1" element of this Fred_t.
 *
 * @param f the Fred_t structure whose other1 is sought.
 *
 * @return the value of the "other1" element of this Fred_t as a Other*.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
const Other_t*
Fred_getOther1(const Fred_t * f);


/**
 * Returns the value of the "other2" element of this Fred_t.
 *
 * @param f the Fred_t structure whose other2 is sought.
 *
 * @return the value of the "other2" element of this Fred_t as a Other*.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
const Other_t*
Fred_getOther2(const Fred_t * f);


/**
 * Predicate returning @c 1 if this Fred_t's "other" element is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 if this Fred_t's "other" element has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetOther(const Fred_t * f);


/**
 * Predicate returning @c 1 if this Fred_t's "other1" element is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 if this Fred_t's "other1" element has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetOther1(const Fred_t * f);


/**
 * Predicate returning @c 1 if this Fred_t's "other2" element is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 if this Fred_t's "other2" element has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetOther2(const Fred_t * f);


/**
 * Sets the value of the "other" element of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param other Other_t* value of the "other" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setOther(Fred_t * f, const Other_t* other);


/**
 * Sets the value of the "other1" element of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param other1 Other_t* value of the "other1" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setOther1(Fred_t * f, const Other_t* other1);


/**
 * Sets the value of the "other2" element of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param other2 Other_t* value of the "other2" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setOther2(Fred_t * f, const Other_t* other2);


/**
 * Creates a new Other_t object, adds it to this Fred_t object and returns the
 * Other_t object created.
 *
 * @param f, the Fred_t structure to which the Other_t should be added.
 *
 * @return a new Other_t object instance.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Other_t*
Fred_createOther(Fred_t* f);


/**
 * Creates a new Other_t object, adds it to this Fred_t object and returns the
 * Other_t object created.
 *
 * @param f, the Fred_t structure to which the Other_t should be added.
 *
 * @return a new Other_t object instance.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Other_t*
Fred_createOther1(Fred_t* f);


/**
 * Creates a new Other_t object, adds it to this Fred_t object and returns the
 * Other_t object created.
 *
 * @param f, the Fred_t structure to which the Other_t should be added.
 *
 * @return a new Other_t object instance.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Other_t*
Fred_createOther2(Fred_t* f);


/**
 * Unsets the value of the "other" element of this Fred_t.
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
Fred_unsetOther(Fred_t * f);


/**
 * Unsets the value of the "other1" element of this Fred_t.
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
Fred_unsetOther1(Fred_t * f);


/**
 * Unsets the value of the "other2" element of this Fred_t.
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
Fred_unsetOther2(Fred_t * f);


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


/**
 * Predicate returning @c 1 if all the required elements for this Fred_t object
 * have been set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this Fred_t have
 * been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the Fred_t object are:
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_hasRequiredElements(const Fred_t * f);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Fred_H__ */


