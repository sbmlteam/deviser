/**
 * @file MyBase.h
 * @brief Definition of MyBase.
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
 */


#ifndef MyBase_H__
#define MyBase_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/test/extension/TestExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN MyBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mId;

  /** @endcond */

public:

  /**
   * Creates a new MyBase using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this MyBase
   *
   * @param version an unsigned int, the SBML Version to assign to this MyBase
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * MyBase
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MyBase(unsigned int level = TestExtension::getDefaultLevel(),
         unsigned int version = TestExtension::getDefaultVersion(),
         unsigned int pkgVersion = TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new MyBase using the given TestPkgNamespaces object.
   *
   * @param testns the TestPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MyBase(TestPkgNamespaces *testns);


  /**
   * Copy constructor for MyBase.
   *
   * @param orig; the MyBase instance to copy.
   */
  MyBase(const MyBase& orig);


  /**
   * Assignment operator for MyBase.
   *
   * @param rhs; the MyBase object whose values are to be used as the basis of
   * the assignment
   */
  MyBase& operator=(const MyBase& rhs);


  /**
   * Creates and returns a deep copy of this MyBase object.
   *
   * @return a (deep) copy of this MyBase object.
   */
  virtual MyBase* clone() const;


  /**
   * Destructor for MyBase.
   */
  virtual ~MyBase();


  /**
   * Returns the value of the "id" attribute of this MyBase.
   *
   * @return the value of the "id" attribute of this MyBase as a string.
   */
  const std::string& getId() const;


  /**
   * Predicate returning @c true or @c false depending on whether this MyBase's
   * "id" attribute has been set.
   *
   * @return @c true if this MyBase's "id" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this MyBase.
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
   * Unsets the value of the "id" attribute of this MyBase.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetId();


  /**
   * Returns the XML name of this MyBase object.
   *
   * @return the name of this element; that is "myBase".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML typcode of this MyBase object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_TEST_MYBASE, SBMLTestTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this MyBase
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * MyBase have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the MyBase object are:
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
 * Creates a new MyBase_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this MyBase_t
 *
 * @param version an unsigned int, the SBML Version to assign to this MyBase_t
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * MyBase_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof MyBase_t
 */
LIBSBML_EXTERN
MyBase_t *
MyBase_create(unsigned int level = TestExtension::getDefaultLevel(),
              unsigned int version = TestExtension::getDefaultVersion(),
              unsigned int pkgVersion =
                TestExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this MyBase_t object.
 *
 * @param mb; the MyBase_t structure
 *
 * @return a (deep) copy of this MyBase_t object.
 *
 * @memberof MyBase_t
 */
LIBSBML_EXTERN
MyBase_t*
MyBase_clone(const MyBase_t* mb);


/**
 * Frees this MyBase_t object.
 *
 * @param mb; the MyBase_t structure
 *
 * @memberof MyBase_t
 */
LIBSBML_EXTERN
void
MyBase_free(MyBase_t* mb);


/**
 * Returns the value of the "id" attribute of this MyBase_t.
 *
 * @param mb the MyBase_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this MyBase_t as a pointer to a
 * string.
 *
 * @memberof MyBase_t
 */
LIBSBML_EXTERN
const char *
MyBase_getId(const MyBase_t * mb);


/**
 * Predicate returning @c 1 or @c 0 depending on whether this MyBase_t's "id"
 * attribute has been set.
 *
 * @param mb the MyBase_t structure.
 *
 * @return @c 1 if this MyBase_t's "id" attribute has been set, otherwise @c 0
 * is returned.
 *
 * @memberof MyBase_t
 */
LIBSBML_EXTERN
int
MyBase_isSetId(const MyBase_t * mb);


/**
 * Sets the value of the "id" attribute of this MyBase_t.
 *
 * @param mb the MyBase_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant {LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof MyBase_t
 */
LIBSBML_EXTERN
int
MyBase_setId(MyBase_t * mb, const char * id);


/**
 * Unsets the value of the "id" attribute of this MyBase_t.
 *
 * @param mb the MyBase_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof MyBase_t
 */
LIBSBML_EXTERN
int
MyBase_unsetId(MyBase_t * mb);


/**
 * Predicate returning @c 1 if all the required attributes for this MyBase_t
 * object have been set.
 *
 * @param mb the MyBase_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this MyBase_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the MyBase_t object are:
 *
 * @memberof MyBase_t
 */
LIBSBML_EXTERN
int
MyBase_hasRequiredAttributes(const MyBase_t * mb);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !MyBase_H__ */


