/**
 * @file Fred.h
 * @brief Definition of the Fred class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
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

/**
 * <!-- ~ ~ ~ ~ ~ Start of common documentation strings ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * The following text is used as common documentation blocks copied multiple
 * times elsewhere in this file. The use of @class is a hack needed because
 * Doxygen's @copydetails command has limited functionality. Symbols
 * beginning with "doc_" are marked as ignored in our Doxygen configuration.
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ -->
 *
 *
 * @class doc_fred_kind
 *
 * @par
 * The attribute "kind" on a Fred object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 X specification, the following are the
 * allowable values for "kind":
 * <ul>
 * <li> @c "first", TODO:add description
 *
 * </ul>
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


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Fred : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  bool mBol;
  bool mIsSetBol;
  int mNum;
  bool mIsSetNum;
  std::string mStr;
  Kind_t mMyEnum;
  Other* mOther;
  Other* mOther1;
  Other* mMyOther;

  /** @endcond */

public:

  /**
   * Creates a new Fred using the given SBML Level, Version and &ldquo;x&rdquo;
   * package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Fred.
   *
   * @param version an unsigned int, the SBML Version to assign to this Fred.
   *
   * @param pkgVersion an unsigned int, the SBML X Version to assign to this
   * Fred.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Fred(unsigned int level = XExtension::getDefaultLevel(),
       unsigned int version = XExtension::getDefaultVersion(),
       unsigned int pkgVersion = XExtension::getDefaultPackageVersion());


  /**
   * Creates a new Fred using the given XPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param xns the XPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Fred(XPkgNamespaces *xns);


  /**
   * Copy constructor for Fred.
   *
   * @param orig the Fred instance to copy.
   */
  Fred(const Fred& orig);


  /**
   * Assignment operator for Fred.
   *
   * @param rhs the Fred object whose values are to be used as the basis of the
   * assignment.
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
   * Returns the value of the "identifier" attribute of this Fred.
   *
   * @return the value of the "identifier" attribute of this Fred as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "myBoolean" attribute of this Fred.
   *
   * @return the value of the "myBoolean" attribute of this Fred as a boolean.
   */
  bool getBol() const;


  /**
   * Returns the value of the "myNumber" attribute of this Fred.
   *
   * @return the value of the "myNumber" attribute of this Fred as a integer.
   */
  int getNum() const;


  /**
   * Returns the value of the "myString" attribute of this Fred.
   *
   * @return the value of the "myString" attribute of this Fred as a string.
   */
  const std::string& getStr() const;


  /**
   * Returns the value of the "myEnum" attribute of this Fred.
   *
   * @return the value of the "myEnum" attribute of this Fred as a Kind_t.
   *
   * @copydetails doc_fred_myEnum
   * @if clike The value is drawn from the enumeration @ref Kind_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{X_KIND_FIRST, Kind_t}
   * @li @sbmlconstant{X_KIND_INVALID, Kind_t}
   */
  Kind_t getMyEnum() const;


  /**
   * Returns the value of the "myEnum" attribute of this Fred.
   *
   * @return the value of the "myEnum" attribute of this Fred as a string.
   *
   * @copydetails doc_fred_myEnum
   * The possible values returned by this method are:
   * @li @c "first"
   * @li @c "invalid Kind value"
   */
  std::string getMyEnumAsString() const;


  /**
   * Predicate returning @c true if this Fred's "identifier" attribute is set.
   *
   * @return @c true if this Fred's "identifier" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this Fred's "myBoolean" attribute is set.
   *
   * @return @c true if this Fred's "myBoolean" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetBol() const;


  /**
   * Predicate returning @c true if this Fred's "myNumber" attribute is set.
   *
   * @return @c true if this Fred's "myNumber" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum() const;


  /**
   * Predicate returning @c true if this Fred's "myString" attribute is set.
   *
   * @return @c true if this Fred's "myString" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetStr() const;


  /**
   * Predicate returning @c true if this Fred's "myEnum" attribute is set.
   *
   * @return @c true if this Fred's "myEnum" attribute has been set, otherwise
   * @c false is returned.
   *
   * @copydetails doc_fred_myEnum
   */
  bool isSetMyEnum() const;


  /**
   * Sets the value of the "identifier" attribute of this Fred.
   *
   * @param id std::string& value of the "identifier" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * Calling this function with @p id = @c NULL or an empty string is
   * equivalent to calling unsetId().
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "myBoolean" attribute of this Fred.
   *
   * @param bol bool value of the "myBoolean" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBol(bool bol);


  /**
   * Sets the value of the "myNumber" attribute of this Fred.
   *
   * @param num int value of the "myNumber" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum(int num);


  /**
   * Sets the value of the "myString" attribute of this Fred.
   *
   * @param str std::string& value of the "myString" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p str = @c NULL or an empty string is
   * equivalent to calling unsetStr().
   */
  int setStr(const std::string& str);


  /**
   * Sets the value of the "myEnum" attribute of this Fred.
   *
   * @param kind @if clike Kind_t@else int@endif value of the "myEnum"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_fred_myEnum
   */
  int setMyEnum(const Kind_t kind);


  /**
   * Sets the value of the "myEnum" attribute of this Fred.
   *
   * @param kind std::string& of the "myEnum" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_fred_myEnum
   */
  int setMyEnum(const std::string& kind);


  /**
   * Unsets the value of the "identifier" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "myBoolean" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBol();


  /**
   * Unsets the value of the "myNumber" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum();


  /**
   * Unsets the value of the "myString" attribute of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStr();


  /**
   * Unsets the value of the "myEnum" attribute of this Fred.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_fred_myEnum
   */
  int unsetMyEnum();


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
   * Returns the value of the "myOther" element of this Fred.
   *
   * @return the value of the "myOther" element of this Fred as a Other*.
   */
  const Other* getMyOther() const;


  /**
   * Returns the value of the "myOther" element of this Fred.
   *
   * @return the value of the "myOther" element of this Fred as a Other*.
   */
  Other* getMyOther();


  /**
   * Predicate returning @c true if this Fred's "other" element is set.
   *
   * @return @c true if this Fred's "other" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetOther() const;


  /**
   * Predicate returning @c true if this Fred's "other1" element is set.
   *
   * @return @c true if this Fred's "other1" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetOther1() const;


  /**
   * Predicate returning @c true if this Fred's "myOther" element is set.
   *
   * @return @c true if this Fred's "myOther" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetMyOther() const;


  /**
   * Sets the value of the "other" element of this Fred.
   *
   * @param other Other* value of the "other" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
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
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setOther1(const Other* other1);


  /**
   * Sets the value of the "myOther" element of this Fred.
   *
   * @param other2 Other* value of the "myOther" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMyOther(const Other* other2);


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
  Other* createMyOther();


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
   * Unsets the value of the "myOther" element of this Fred.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMyOther();


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
   * @sbmlconstant{SBML_X_FRED, SBMLXTypeCode_t}.
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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Updates the namespaces when setLevelVersion is used
   */
  virtual void updateSBMLNamespace(const std::string& package,
                                   unsigned int level,
                                   unsigned int version);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Fred.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Fred.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Fred.
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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Fred.
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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Fred.
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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this Fred's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Fred's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Fred.
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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Fred.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Fred.
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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Fred.
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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Fred.
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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this Fred.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates and returns an new "elementName" object in this Fred.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this Fred.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SBase* element);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * Fred.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SBase* removeChildObject(const std::string& elementName,
                                   const std::string& id);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the number of "elementName" in this Fred.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this Fred.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SBase* getObject(const std::string& elementName, unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid. If no
   * such object is found this method returns @c NULL.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
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
 * @param level an unsigned int, the SBML Level to assign to this Fred_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this Fred_t.
 *
 * @param pkgVersion an unsigned int, the SBML X Version to assign to this
 * Fred_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Fred_t *
Fred_create(unsigned int level,
            unsigned int version,
            unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Fred_t object.
 *
 * @param f the Fred_t structure.
 *
 * @return a (deep) copy of this Fred_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Fred_t*
Fred_clone(const Fred_t* f);


/**
 * Frees this Fred_t object.
 *
 * @param f the Fred_t structure.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
void
Fred_free(Fred_t* f);


/**
 * Returns the value of the "identifier" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose identifier is sought.
 *
 * @return the value of the "identifier" attribute of this Fred_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
char *
Fred_getId(const Fred_t * f);


/**
 * Returns the value of the "myBoolean" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose myBoolean is sought.
 *
 * @return the value of the "myBoolean" attribute of this Fred_t as a boolean.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_getBol(const Fred_t * f);


/**
 * Returns the value of the "myNumber" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose myNumber is sought.
 *
 * @return the value of the "myNumber" attribute of this Fred_t as a integer.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_getNum(const Fred_t * f);


/**
 * Returns the value of the "myString" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose myString is sought.
 *
 * @return the value of the "myString" attribute of this Fred_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
char *
Fred_getStr(const Fred_t * f);


/**
 * Returns the value of the "myEnum" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose myEnum is sought.
 *
 * @return the value of the "myEnum" attribute of this Fred_t as a Kind_t.
 *
 * @copydetails doc_fred_myEnum
 * @if clike The value is drawn from the enumeration @ref Kind_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{X_KIND_FIRST, Kind_t}
 * @li @sbmlconstant{X_KIND_INVALID, Kind_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Kind_t
Fred_getMyEnum(const Fred_t * f);


/**
 * Returns the value of the "myEnum" attribute of this Fred_t.
 *
 * @param f the Fred_t structure whose myEnum is sought.
 *
 * @return the value of the "myEnum" attribute of this Fred_t as a const char
 * *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_fred_myEnum
 * The possible values returned by this method are:
 * @li @c "first"
 * @li @c "invalid Kind value"
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
char *
Fred_getMyEnumAsString(const Fred_t * f);


/**
 * Predicate returning @c 1 (true) if this Fred_t's "identifier" attribute is
 * set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 (true) if this Fred_t's "identifier" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetId(const Fred_t * f);


/**
 * Predicate returning @c 1 (true) if this Fred_t's "myBoolean" attribute is
 * set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 (true) if this Fred_t's "myBoolean" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetBol(const Fred_t * f);


/**
 * Predicate returning @c 1 (true) if this Fred_t's "myNumber" attribute is
 * set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 (true) if this Fred_t's "myNumber" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetNum(const Fred_t * f);


/**
 * Predicate returning @c 1 (true) if this Fred_t's "myString" attribute is
 * set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 (true) if this Fred_t's "myString" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetStr(const Fred_t * f);


/**
 * Predicate returning @c 1 (true) if this Fred_t's "myEnum" attribute is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 (true) if this Fred_t's "myEnum" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_fred_myEnum
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetMyEnum(const Fred_t * f);


/**
 * Sets the value of the "identifier" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param id const char * value of the "identifier" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling Fred_unsetId().
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setId(Fred_t * f, const char * id);


/**
 * Sets the value of the "myBoolean" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param bol int value of the "myBoolean" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setBol(Fred_t * f, int bol);


/**
 * Sets the value of the "myNumber" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param num int value of the "myNumber" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setNum(Fred_t * f, int num);


/**
 * Sets the value of the "myString" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param str const char * value of the "myString" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p str = @c NULL or an empty string is equivalent
 * to calling Fred_unsetStr().
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setStr(Fred_t * f, const char * str);


/**
 * Sets the value of the "myEnum" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param kind Kind_t value of the "myEnum" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_fred_myEnum
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setMyEnum(Fred_t * f, Kind_t kind);


/**
 * Sets the value of the "myEnum" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param kind const char * of the "myEnum" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_fred_myEnum
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setMyEnumAsString(Fred_t * f, const char * kind);


/**
 * Unsets the value of the "identifier" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetId(Fred_t * f);


/**
 * Unsets the value of the "myBoolean" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetBol(Fred_t * f);


/**
 * Unsets the value of the "myNumber" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetNum(Fred_t * f);


/**
 * Unsets the value of the "myString" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetStr(Fred_t * f);


/**
 * Unsets the value of the "myEnum" attribute of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_fred_myEnum
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetMyEnum(Fred_t * f);


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
 * Returns the value of the "myOther" element of this Fred_t.
 *
 * @param f the Fred_t structure whose myOther is sought.
 *
 * @return the value of the "myOther" element of this Fred_t as a Other*.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
const Other_t*
Fred_getMyOther(const Fred_t * f);


/**
 * Predicate returning @c 1 (true) if this Fred_t's "other" element is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 (true) if this Fred_t's "other" element has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetOther(const Fred_t * f);


/**
 * Predicate returning @c 1 (true) if this Fred_t's "other1" element is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 (true) if this Fred_t's "other1" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetOther1(const Fred_t * f);


/**
 * Predicate returning @c 1 (true) if this Fred_t's "myOther" element is set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 (true) if this Fred_t's "myOther" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_isSetMyOther(const Fred_t * f);


/**
 * Sets the value of the "other" element of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param other Other_t* value of the "other" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
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
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setOther1(Fred_t * f, const Other_t* other1);


/**
 * Sets the value of the "myOther" element of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @param other2 Other_t* value of the "myOther" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_setMyOther(Fred_t * f, const Other_t* other2);


/**
 * Creates a new Other_t object, adds it to this Fred_t object and returns the
 * Other_t object created.
 *
 * @param f the Fred_t structure to which the Other_t should be added.
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
 * @param f the Fred_t structure to which the Other_t should be added.
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
 * @param f the Fred_t structure to which the Other_t should be added.
 *
 * @return a new Other_t object instance.
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
Other_t*
Fred_createMyOther(Fred_t* f);


/**
 * Unsets the value of the "other" element of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
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
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetOther1(Fred_t * f);


/**
 * Unsets the value of the "myOther" element of this Fred_t.
 *
 * @param f the Fred_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Fred_t
 */
LIBSBML_EXTERN
int
Fred_unsetMyOther(Fred_t * f);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Fred_t object have been set.
 *
 * @param f the Fred_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * Fred_t have been set, otherwise @c 0 (false) is returned.
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


