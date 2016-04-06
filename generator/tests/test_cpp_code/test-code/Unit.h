/**
 * @file Unit.h
 * @brief Definition of the Unit class.
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
 * @class Unit
 * @sbmlbrief{test} TODO:Definition of the Unit class.
 */


#ifndef Unit_H__
#define Unit_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Unit : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mUnit;

  /** @endcond */

public:

  /**
   * Creates a new Unit using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Unit.
   *
   * @param version an unsigned int, the SBML Version to assign to this Unit.
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * Unit.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Unit(unsigned int level = TestExtension::getDefaultLevel(),
       unsigned int version = TestExtension::getDefaultVersion(),
       unsigned int pkgVersion = TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new Unit using the given TestPkgNamespaces object.
   *
   * @param testns the TestPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Unit(TestPkgNamespaces *testns);


  /**
   * Copy constructor for Unit.
   *
   * @param orig the Unit instance to copy.
   */
  Unit(const Unit& orig);


  /**
   * Assignment operator for Unit.
   *
   * @param rhs the Unit object whose values are to be used as the basis of the
   * assignment.
   */
  Unit& operator=(const Unit& rhs);


  /**
   * Creates and returns a deep copy of this Unit object.
   *
   * @return a (deep) copy of this Unit object.
   */
  virtual Unit* clone() const;


  /**
   * Destructor for Unit.
   */
  virtual ~Unit();


  /**
   * Returns the value of the "unit" attribute of this Unit.
   *
   * @return the value of the "unit" attribute of this Unit as a string.
   */
  const std::string& getUnit() const;


  /**
   * Predicate returning @c true if this Unit's "unit" attribute is set.
   *
   * @return @c true if this Unit's "unit" attribute has been set, otherwise @c
   * false is returned.
   */
  bool isSetUnit() const;


  /**
   * Sets the value of the "unit" attribute of this Unit.
   *
   * @param unit std::string& value of the "unit" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUnit(const std::string& unit);


  /**
   * Unsets the value of the "unit" attribute of this Unit.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUnit();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this Unit object.
   *
   * For Unit, the XML element name is always @c "unit".
   *
   * @return the name of this element, i.e. @c "unit".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Unit object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_TEST_UNIT, SBMLTestTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this Unit
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this Unit
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Unit object are:
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
 * Creates a new Unit_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Unit_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this Unit_t.
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * Unit_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof Unit_t
 */
LIBSBML_EXTERN
Unit_t *
Unit_create(unsigned int level = TestExtension::getDefaultLevel(),
            unsigned int version = TestExtension::getDefaultVersion(),
            unsigned int pkgVersion =
              TestExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this Unit_t object.
 *
 * @param u the Unit_t structure.
 *
 * @return a (deep) copy of this Unit_t object.
 *
 * @memberof Unit_t
 */
LIBSBML_EXTERN
Unit_t*
Unit_clone(const Unit_t* u);


/**
 * Frees this Unit_t object.
 *
 * @param u the Unit_t structure.
 *
 * @memberof Unit_t
 */
LIBSBML_EXTERN
void
Unit_free(Unit_t* u);


/**
 * Returns the value of the "unit" attribute of this Unit_t.
 *
 * @param u the Unit_t structure whose unit is sought.
 *
 * @return the value of the "unit" attribute of this Unit_t as a pointer to a
 * string.
 *
 * @memberof Unit_t
 */
LIBSBML_EXTERN
const char *
Unit_getUnit(const Unit_t * u);


/**
 * Predicate returning @c 1 if this Unit_t's "unit" attribute is set.
 *
 * @param u the Unit_t structure.
 *
 * @return @c 1 if this Unit_t's "unit" attribute has been set, otherwise @c 0
 * is returned.
 *
 * @memberof Unit_t
 */
LIBSBML_EXTERN
int
Unit_isSetUnit(const Unit_t * u);


/**
 * Sets the value of the "unit" attribute of this Unit_t.
 *
 * @param u the Unit_t structure.
 *
 * @param unit const char * value of the "unit" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof Unit_t
 */
LIBSBML_EXTERN
int
Unit_setUnit(Unit_t * u, const char * unit);


/**
 * Unsets the value of the "unit" attribute of this Unit_t.
 *
 * @param u the Unit_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Unit_t
 */
LIBSBML_EXTERN
int
Unit_unsetUnit(Unit_t * u);


/**
 * Predicate returning @c 1 if all the required attributes for this Unit_t
 * object have been set.
 *
 * @param u the Unit_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this Unit_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required attributes for the Unit_t object are:
 *
 * @memberof Unit_t
 */
LIBSBML_EXTERN
int
Unit_hasRequiredAttributes(const Unit_t * u);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Unit_H__ */


