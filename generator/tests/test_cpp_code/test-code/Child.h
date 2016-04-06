/**
 * @file Child.h
 * @brief Definition of the Child class.
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
 * @class Child
 * @sbmlbrief{nasty} TODO:Definition of the Child class.
 */


#ifndef Child_H__
#define Child_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/nasty/common/nastyfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/nasty/extension/NastyExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Child : public SBase
{

public:

  /**
   * Creates a new Child using the given SBML Level, Version and
   * &ldquo;nasty&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Child.
   *
   * @param version an unsigned int, the SBML Version to assign to this Child.
   *
   * @param pkgVersion an unsigned int, the SBML Nasty Version to assign to
   * this Child.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Child(unsigned int level = NastyExtension::getDefaultLevel(),
        unsigned int version = NastyExtension::getDefaultVersion(),
        unsigned int pkgVersion = NastyExtension::getDefaultPackageVersion());


  /**
   * Creates a new Child using the given NastyPkgNamespaces object.
   *
   * @param nastyns the NastyPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Child(NastyPkgNamespaces *nastyns);


  /**
   * Copy constructor for Child.
   *
   * @param orig the Child instance to copy.
   */
  Child(const Child& orig);


  /**
   * Assignment operator for Child.
   *
   * @param rhs the Child object whose values are to be used as the basis of
   * the assignment.
   */
  Child& operator=(const Child& rhs);


  /**
   * Creates and returns a deep copy of this Child object.
   *
   * @return a (deep) copy of this Child object.
   */
  virtual Child* clone() const;


  /**
   * Destructor for Child.
   */
  virtual ~Child();


  /**
   * Returns the XML element name of this Child object.
   *
   * For Child, the XML element name is always @c "child".
   *
   * @return the name of this element, i.e. @c "child".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Child object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_NASTY_CHILD, SBMLNastyTypeCode_t}
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
 * Creates a new Child_t using the given SBML Level, Version and
 * &ldquo;nasty&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Child_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this Child_t.
 *
 * @param pkgVersion an unsigned int, the SBML Nasty Version to assign to this
 * Child_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof Child_t
 */
LIBSBML_EXTERN
Child_t *
Child_create(unsigned int level = NastyExtension::getDefaultLevel(),
             unsigned int version = NastyExtension::getDefaultVersion(),
             unsigned int pkgVersion =
               NastyExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this Child_t object.
 *
 * @param c the Child_t structure.
 *
 * @return a (deep) copy of this Child_t object.
 *
 * @memberof Child_t
 */
LIBSBML_EXTERN
Child_t*
Child_clone(const Child_t* c);


/**
 * Frees this Child_t object.
 *
 * @param c the Child_t structure.
 *
 * @memberof Child_t
 */
LIBSBML_EXTERN
void
Child_free(Child_t* c);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Child_H__ */


