/**
 * @file: MyTestClass.h
 * @brief: Definition of MyTestClass.
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


#ifndef MyTestClass_H__
#define MyTestClass_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN MyTestClass : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;
  std::string mName;
  unsigned int mNum;
  bool mIsSetNum;
  unsigned int mNum2;
  bool mIsSetNum2;
  int mNum3;
  bool mIsSetNum3;
  double mNum1;
  bool mIsSetNum1;
  bool mTrue;
  bool mIsSetTrue;
  bool mFalse;
  bool mIsSetFalse;
  std::string mUnit;
  std::string mRef1;
  std::string mRef2;
  std::string mRefUnit;
  std::string mCorrectId;

  /** @endcond */

public:

  /**
   * Creates a new MyTestClass using the given SBML @p level, @ p version and
   * package version values.
   *
   * @param level an unsigned int, the SBML Level to assign to this MyTestClass
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * MyTestClass
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * MyTestClass
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MyTestClass(unsigned int level = TestExtension::getDefaultLevel(),
              unsigned int version = TestExtension::getDefaultVersion(),
              unsigned int pkgVersion =
              TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new MyTestClass using the given TestPkgNamespaces object.
   *
   * @param testns the TestPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MyTestClass(TestPkgNamespaces *testns);


  /**
   * Copy constructor for MyTestClass.
   *
   * @param orig; the MyTestClass instance to copy.
   */
  MyTestClass(const MyTestClass& orig);


  /**
   * Assignment operator for MyTestClass.
   *
   * @param rhs; the MyTestClass object whose values are to be used as the
   * basis of the assignment
   */
  MyTestClass& operator=(const MyTestClass& rhs);


  /**
   * Creates and returns a deep copy of this MyTestClass object.
   *
   * @return a (deep) copy of this MyTestClass object.
   */
  virtual MyTestClass* clone() const;


  /**
   * Destructor for MyTestClass.
   */
  virtual ~MyTestClass();


  /**
   * Returns the value of the "id" attribute of this MyTestClass.
   *
   * @return the value of the "id" attribute of this MyTestClass as a string.
   */
  const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this MyTestClass.
   *
   * @return the value of the "name" attribute of this MyTestClass as a string.
   */
  const std::string& getName() const;


  /**
   * Returns the value of the "num" attribute of this MyTestClass.
   *
   * @return the value of the "num" attribute of this MyTestClass as a unsigned
   * integer.
   */
  unsigned int getNum() const;


  /**
   * Returns the value of the "num2" attribute of this MyTestClass.
   *
   * @return the value of the "num2" attribute of this MyTestClass as a
   * unsigned integer.
   */
  unsigned int getNum2() const;


  /**
   * Returns the value of the "num3" attribute of this MyTestClass.
   *
   * @return the value of the "num3" attribute of this MyTestClass as a
   * integer.
   */
  int getNum3() const;


  /**
   * Returns the value of the "num1" attribute of this MyTestClass.
   *
   * @return the value of the "num1" attribute of this MyTestClass as a double.
   */
  double getNum1() const;


  /**
   * Returns the value of the "true" attribute of this MyTestClass.
   *
   * @return the value of the "true" attribute of this MyTestClass as a
   * boolean.
   */
  bool getTrue() const;


  /**
   * Returns the value of the "false" attribute of this MyTestClass.
   *
   * @return the value of the "false" attribute of this MyTestClass as a
   * boolean.
   */
  bool getFalse() const;


  /**
   * Returns the value of the "unit" attribute of this MyTestClass.
   *
   * @return the value of the "unit" attribute of this MyTestClass as a string.
   */
  const std::string& getUnit() const;


  /**
   * Returns the value of the "ref1" attribute of this MyTestClass.
   *
   * @return the value of the "ref1" attribute of this MyTestClass as a string.
   */
  const std::string& getRef1() const;


  /**
   * Returns the value of the "ref2" attribute of this MyTestClass.
   *
   * @return the value of the "ref2" attribute of this MyTestClass as a string.
   */
  const std::string& getRef2() const;


  /**
   * Returns the value of the "refUnit" attribute of this MyTestClass.
   *
   * @return the value of the "refUnit" attribute of this MyTestClass as a
   * string.
   */
  const std::string& getRefUnit() const;


  /**
   * Returns the value of the "correctId" attribute of this MyTestClass.
   *
   * @return the value of the "correctId" attribute of this MyTestClass as a
   * string.
   */
  const std::string& getCorrectId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "id" attribute has been set.
   *
   * @return @c true if this MyTestClass's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "name" attribute has been set.
   *
   * @return @c true if this MyTestClass's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetName() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "num" attribute has been set.
   *
   * @return @c true if this MyTestClass's "num" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "num2" attribute has been set.
   *
   * @return @c true if this MyTestClass's "num2" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum2() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "num3" attribute has been set.
   *
   * @return @c true if this MyTestClass's "num3" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum3() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "num1" attribute has been set.
   *
   * @return @c true if this MyTestClass's "num1" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNum1() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "true" attribute has been set.
   *
   * @return @c true if this MyTestClass's "true" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTrue() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "false" attribute has been set.
   *
   * @return @c true if this MyTestClass's "false" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetFalse() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "unit" attribute has been set.
   *
   * @return @c true if this MyTestClass's "unit" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetUnit() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "ref1" attribute has been set.
   *
   * @return @c true if this MyTestClass's "ref1" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRef1() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "ref2" attribute has been set.
   *
   * @return @c true if this MyTestClass's "ref2" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRef2() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "refUnit" attribute has been set.
   *
   * @return @c true if this MyTestClass's "refUnit" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRefUnit() const;


  /**
   * Predicate returning @c true or @c false depending on whether this
   * MyTestClass's "correctId" attribute has been set.
   *
   * @return @c true if this MyTestClass's "correctId" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetCorrectId() const;


  /**
   * Sets the value of the "id" attribute of this MyTestClass.
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
   * Sets the value of the "name" attribute of this MyTestClass.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setName(const std::string& name);


  /**
   * Sets the value of the "num" attribute of this MyTestClass.
   *
   * @param num unsigned int value of the "num" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum(unsigned int num);


  /**
   * Sets the value of the "num2" attribute of this MyTestClass.
   *
   * @param num2 unsigned int value of the "num2" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum2(unsigned int num2);


  /**
   * Sets the value of the "num3" attribute of this MyTestClass.
   *
   * @param num3 int value of the "num3" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum3(int num3);


  /**
   * Sets the value of the "num1" attribute of this MyTestClass.
   *
   * @param num1 double value of the "num1" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNum1(double num1);


  /**
   * Sets the value of the "true" attribute of this MyTestClass.
   *
   * @param true bool value of the "true" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTrue(bool true);


  /**
   * Sets the value of the "false" attribute of this MyTestClass.
   *
   * @param false bool value of the "false" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setFalse(bool false);


  /**
   * Sets the value of the "unit" attribute of this MyTestClass.
   *
   * @param unit std::string& value of the "unit" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUnit(const std::string& unit);


  /**
   * Sets the value of the "ref1" attribute of this MyTestClass.
   *
   * @param ref1 std::string& value of the "ref1" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRef1(const std::string& ref1);


  /**
   * Sets the value of the "ref2" attribute of this MyTestClass.
   *
   * @param ref2 std::string& value of the "ref2" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRef2(const std::string& ref2);


  /**
   * Sets the value of the "refUnit" attribute of this MyTestClass.
   *
   * @param refUnit std::string& value of the "refUnit" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRefUnit(const std::string& refUnit);


  /**
   * Sets the value of the "correctId" attribute of this MyTestClass.
   *
   * @param correctId std::string& value of the "correctId" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCorrectId(const std::string& correctId);


  /**
   * Unsets the value of the "id" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Unsets the value of the "name" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetName();


  /**
   * Unsets the value of the "num" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum();


  /**
   * Unsets the value of the "num2" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum2();


  /**
   * Unsets the value of the "num3" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum3();


  /**
   * Unsets the value of the "num1" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNum1();


  /**
   * Unsets the value of the "true" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTrue();


  /**
   * Unsets the value of the "false" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetFalse();


  /**
   * Unsets the value of the "unit" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUnit();


  /**
   * Unsets the value of the "ref1" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRef1();


  /**
   * Unsets the value of the "ref2" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRef2();


  /**
   * Unsets the value of the "refUnit" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRefUnit();


  /**
   * Unsets the value of the "correctId" attribute of this MyTestClass.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCorrectId();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML name of this MyTestClass object.
   *
   * @return the name of this element; that is "myTestClass".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML typcode of this MyTestClass object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{MY_TEST_TYPE, SBMLTestTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * MyTestClass object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * MyTestClass have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the MyTestClass object are:
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
 * Creates a new MyTestClass_t using the given SBML @p level, @ p version and
 * package version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this MyTestClass_t
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * MyTestClass_t
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * MyTestClass_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
MyTestClass_t *
MyTestClass_create(unsigned int level = TestExtension::getDefaultLevel(),
                   unsigned int version = TestExtension::getDefaultVersion(),
                   unsigned int pkgVersion =
                   TestExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this MyTestClass_t object.
 *
 * @param mtc; the MyTestClass_t structure
 *
 * @return a (deep) copy of this MyTestClass_t object.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
MyTestClass_t*
MyTestClass_clone(const MyTestClass_t* mtc);


/**
 * Frees this MyTestClass_t object.
 *
 * @param mtc; the MyTestClass_t structure
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
void
MyTestClass_free(MyTestClass_t* mtc);


/**
 * Returns the value of the "id" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this MyTestClass_t as a pointer
 * to a string.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
const char *
MyTestClass_getId(const MyTestClass_t * mtc);


/**
 * Returns the value of the "name" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this MyTestClass_t as a pointer
 * to a string.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
const char *
MyTestClass_getName(const MyTestClass_t * mtc);


/**
 * Returns the value of the "num" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose num is sought.
 *
 * @return the value of the "num" attribute of this MyTestClass_t as a unsigned
 * integer.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
unsigned int
MyTestClass_getNum(const MyTestClass_t * mtc);


/**
 * Returns the value of the "num2" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose num2 is sought.
 *
 * @return the value of the "num2" attribute of this MyTestClass_t as a
 * unsigned integer.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
unsigned int
MyTestClass_getNum2(const MyTestClass_t * mtc);


/**
 * Returns the value of the "num3" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose num3 is sought.
 *
 * @return the value of the "num3" attribute of this MyTestClass_t as a
 * integer.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_getNum3(const MyTestClass_t * mtc);


/**
 * Returns the value of the "num1" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose num1 is sought.
 *
 * @return the value of the "num1" attribute of this MyTestClass_t as a double.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
double
MyTestClass_getNum1(const MyTestClass_t * mtc);


/**
 * Returns the value of the "true" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose true is sought.
 *
 * @return the value of the "true" attribute of this MyTestClass_t as a
 * boolean.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_getTrue(const MyTestClass_t * mtc);


/**
 * Returns the value of the "false" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose false is sought.
 *
 * @return the value of the "false" attribute of this MyTestClass_t as a
 * boolean.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_getFalse(const MyTestClass_t * mtc);


/**
 * Returns the value of the "unit" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose unit is sought.
 *
 * @return the value of the "unit" attribute of this MyTestClass_t as a pointer
 * to a string.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
const char *
MyTestClass_getUnit(const MyTestClass_t * mtc);


/**
 * Returns the value of the "ref1" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose ref1 is sought.
 *
 * @return the value of the "ref1" attribute of this MyTestClass_t as a pointer
 * to a string.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
const char *
MyTestClass_getRef1(const MyTestClass_t * mtc);


/**
 * Returns the value of the "ref2" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose ref2 is sought.
 *
 * @return the value of the "ref2" attribute of this MyTestClass_t as a pointer
 * to a string.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
const char *
MyTestClass_getRef2(const MyTestClass_t * mtc);


/**
 * Returns the value of the "refUnit" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose refUnit is sought.
 *
 * @return the value of the "refUnit" attribute of this MyTestClass_t as a
 * pointer to a string.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
const char *
MyTestClass_getRefUnit(const MyTestClass_t * mtc);


/**
 * Returns the value of the "correctId" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure whose correctId is sought.
 *
 * @return the value of the "correctId" attribute of this MyTestClass_t as a
 * pointer to a string.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
const char *
MyTestClass_getCorrectId(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "id" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "id" attribute has been set, otherwise
 * @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetId(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "name" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "name" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetName(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "num" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "num" attribute has been set, otherwise
 * @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetNum(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "num2" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "num2" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetNum2(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "num3" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "num3" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetNum3(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "num1" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "num1" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetNum1(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "true" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "true" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetTrue(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "false" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "false" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetFalse(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "unit" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "unit" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetUnit(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "ref1" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "ref1" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetRef1(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "ref2" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "ref2" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetRef2(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "refUnit" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "refUnit" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetRefUnit(const MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyTestClass_t's
 * "correctId" attribute has been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 if this MyTestClass_t's "correctId" attribute has been set,
 * otherwise @c 0 is returned.
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_isSetCorrectId(const MyTestClass_t * mtc);


/**
 * Sets the value of the "id" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setId(MyTestClass_t * mtc, const char * id);


/**
 * Sets the value of the "name" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setName(MyTestClass_t * mtc, const char * name);


/**
 * Sets the value of the "num" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param num unsigned int value of the "num" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setNum(MyTestClass_t * mtc, unsigned int num);


/**
 * Sets the value of the "num2" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param num2 unsigned int value of the "num2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setNum2(MyTestClass_t * mtc, unsigned int num2);


/**
 * Sets the value of the "num3" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param num3 int value of the "num3" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setNum3(MyTestClass_t * mtc, int num3);


/**
 * Sets the value of the "num1" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param num1 double value of the "num1" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setNum1(MyTestClass_t * mtc, double num1);


/**
 * Sets the value of the "true" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param true int value of the "true" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setTrue(MyTestClass_t * mtc, int true);


/**
 * Sets the value of the "false" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param false int value of the "false" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setFalse(MyTestClass_t * mtc, int false);


/**
 * Sets the value of the "unit" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param unit const char * value of the "unit" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setUnit(MyTestClass_t * mtc, const char * unit);


/**
 * Sets the value of the "ref1" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param ref1 const char * value of the "ref1" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setRef1(MyTestClass_t * mtc, const char * ref1);


/**
 * Sets the value of the "ref2" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param ref2 const char * value of the "ref2" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setRef2(MyTestClass_t * mtc, const char * ref2);


/**
 * Sets the value of the "refUnit" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param refUnit const char * value of the "refUnit" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setRefUnit(MyTestClass_t * mtc, const char * refUnit);


/**
 * Sets the value of the "correctId" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @param correctId const char * value of the "correctId" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_setCorrectId(MyTestClass_t * mtc, const char * correctId);


/**
 * Unsets the value of the "id" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetId(MyTestClass_t * mtc);


/**
 * Unsets the value of the "name" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetName(MyTestClass_t * mtc);


/**
 * Unsets the value of the "num" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetNum(MyTestClass_t * mtc);


/**
 * Unsets the value of the "num2" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetNum2(MyTestClass_t * mtc);


/**
 * Unsets the value of the "num3" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetNum3(MyTestClass_t * mtc);


/**
 * Unsets the value of the "num1" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetNum1(MyTestClass_t * mtc);


/**
 * Unsets the value of the "true" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetTrue(MyTestClass_t * mtc);


/**
 * Unsets the value of the "false" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetFalse(MyTestClass_t * mtc);


/**
 * Unsets the value of the "unit" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetUnit(MyTestClass_t * mtc);


/**
 * Unsets the value of the "ref1" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetRef1(MyTestClass_t * mtc);


/**
 * Unsets the value of the "ref2" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetRef2(MyTestClass_t * mtc);


/**
 * Unsets the value of the "refUnit" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetRefUnit(MyTestClass_t * mtc);


/**
 * Unsets the value of the "correctId" attribute of this MyTestClass_t.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_unsetCorrectId(MyTestClass_t * mtc);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * MyTestClass_t object have been set.
 *
 * @param mtc the MyTestClass_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * MyTestClass_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the MyTestClass_t object are:
 *
 * @memberof MyTestClass_t
 */
LIBSBML_EXTERN
int
MyTestClass_hasRequiredAttributes(const MyTestClass_t * mtc);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !MyTestClass_H__ */


