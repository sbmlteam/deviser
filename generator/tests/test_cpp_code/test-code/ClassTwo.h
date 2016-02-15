/**
 * @file ClassTwo.h
 * @brief Definition of the ClassTwo class.
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
 * @class ClassTwo
 * @sbmlbrief{test} TODO:Definition of the ClassTwo class.
 */


#ifndef ClassTwo_H__
#define ClassTwo_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ClassTwo : public SBase
{

public:

  /**
   * Creates a new ClassTwo using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this ClassTwo
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ClassTwo
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * ClassTwo
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ClassTwo(unsigned int level = TestExtension::getDefaultLevel(),
           unsigned int version = TestExtension::getDefaultVersion(),
           unsigned int pkgVersion =
             TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new ClassTwo using the given TestPkgNamespaces object.
   *
   * @param testns the TestPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ClassTwo(TestPkgNamespaces *testns);


  /**
   * Copy constructor for ClassTwo.
   *
   * @param orig; the ClassTwo instance to copy.
   */
  ClassTwo(const ClassTwo& orig);


  /**
   * Assignment operator for ClassTwo.
   *
   * @param rhs; the ClassTwo object whose values are to be used as the basis
   * of the assignment
   */
  ClassTwo& operator=(const ClassTwo& rhs);


  /**
   * Creates and returns a deep copy of this ClassTwo object.
   *
   * @return a (deep) copy of this ClassTwo object.
   */
  virtual ClassTwo* clone() const;


  /**
   * Destructor for ClassTwo.
   */
  virtual ~ClassTwo();


  /**
   * Returns the XML element name of this ClassTwo object.
   *
   * For ClassTwo, the XML element name is always @c "classTwo".
   *
   * @return the name of this element, i.e. @c "classTwo".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ClassTwo object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_TEST_CLASSTWO, SBMLTestTypeCode_t}
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

};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new ClassTwo_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this ClassTwo_t
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ClassTwo_t
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * ClassTwo_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof ClassTwo_t
 */
LIBSBML_EXTERN
ClassTwo_t *
ClassTwo_create(unsigned int level = TestExtension::getDefaultLevel(),
                unsigned int version = TestExtension::getDefaultVersion(),
                unsigned int pkgVersion =
                  TestExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this ClassTwo_t object.
 *
 * @param ct; the ClassTwo_t structure
 *
 * @return a (deep) copy of this ClassTwo_t object.
 *
 * @memberof ClassTwo_t
 */
LIBSBML_EXTERN
ClassTwo_t*
ClassTwo_clone(const ClassTwo_t* ct);


/**
 * Frees this ClassTwo_t object.
 *
 * @param ct; the ClassTwo_t structure
 *
 * @memberof ClassTwo_t
 */
LIBSBML_EXTERN
void
ClassTwo_free(ClassTwo_t* ct);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ClassTwo_H__ */


