/**
 * @file: MyLoTest.h
 * @brief: Definition of MyLoTest.
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


#ifndef MyLoTest_H__
#define MyLoTest_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN MyLoTest : public SBase
{

public:

  /**
   * Creates a new MyLoTest using the given SBML @p level, @ p version and
   * package version values.
   *
   * @param level an unsigned int, the SBML Level to assign to this MyLoTest
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * MyLoTest
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * MyLoTest
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MyLoTest(unsigned int level = TestExtension::getDefaultLevel(),
           unsigned int version = TestExtension::getDefaultVersion(),
           unsigned int pkgVersion =
           TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new MyLoTest using the given TestPkgNamespaces object.
   *
   * @param testns the TestPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  MyLoTest(TestPkgNamespaces *testns);


  /**
   * Copy constructor for MyLoTest.
   *
   * @param orig; the MyLoTest instance to copy.
   */
  MyLoTest(const MyLoTest& orig);


  /**
   * Assignment operator for MyLoTest.
   *
   * @param rhs; the MyLoTest object whose values are to be used as the basis
   * of the assignment
   */
  MyLoTest& operator=(const MyLoTest& rhs);


  /**
   * Creates and returns a deep copy of this MyLoTest object.
   *
   * @return a (deep) copy of this MyLoTest object.
   */
  virtual MyLoTest* clone() const;


  /**
   * Destructor for MyLoTest.
   */
  virtual ~MyLoTest();


  /**
   * Returns the XML name of this MyLoTest object.
   *
   * @return the name of this element; that is "myLoTest".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML typcode of this MyLoTest object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{TEST_LO_TEST, SBMLTestTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;



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
 * Creates a new MyLoTest_t using the given SBML @p level, @ p version and
 * package version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this MyLoTest_t
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * MyLoTest_t
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * MyLoTest_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof MyLoTest_t
 */
LIBSBML_EXTERN
MyLoTest_t *
MyLoTest_create(unsigned int level = TestExtension::getDefaultLevel(),
                unsigned int version = TestExtension::getDefaultVersion(),
                unsigned int pkgVersion =
                TestExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this MyLoTest_t object.
 *
 * @param mlt; the MyLoTest_t structure
 *
 * @return a (deep) copy of this MyLoTest_t object.
 *
 * @memberof MyLoTest_t
 */
LIBSBML_EXTERN
MyLoTest_t*
MyLoTest_clone(const MyLoTest_t* mlt);


/**
 * Frees this MyLoTest_t object.
 *
 * @param mlt; the MyLoTest_t structure
 *
 * @memberof MyLoTest_t
 */
LIBSBML_EXTERN
void
MyLoTest_free(MyLoTest_t* mlt);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !MyLoTest_H__ */


