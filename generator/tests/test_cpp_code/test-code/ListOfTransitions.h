/**
 * @file ListOfTransitions.h
 * @brief Definition of ListOfTransitions.
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


#ifndef ListOfTransitions_H__
#define ListOfTransitions_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/qual/common/qualfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/ListOf.h>
#include <sbml/packages/qual/extension/QualExtension.h>
#include <sbml/packages/qual/sbml/Transition.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ListOfTransitions : public ListOf
{

public:

  /**
   * Creates a new ListOfTransitions using the given SBML Level, Version and
   * &ldquo;qual&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ListOfTransitions
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ListOfTransitions
   *
   * @param pkgVersion an unsigned int, the SBML Qual Version to assign to this
   * ListOfTransitions
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ListOfTransitions(unsigned int level = QualExtension::getDefaultLevel(),
                    unsigned int version = QualExtension::getDefaultVersion(),
                    unsigned int pkgVersion =
                      QualExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfTransitions using the given QualPkgNamespaces object.
   *
   * @param qualns the QualPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ListOfTransitions(QualPkgNamespaces *qualns);


  /**
   * Copy constructor for ListOfTransitions.
   *
   * @param orig; the ListOfTransitions instance to copy.
   */
  ListOfTransitions(const ListOfTransitions& orig);


  /**
   * Assignment operator for ListOfTransitions.
   *
   * @param rhs; the ListOfTransitions object whose values are to be used as
   * the basis of the assignment
   */
  ListOfTransitions& operator=(const ListOfTransitions& rhs);


  /**
   * Creates and returns a deep copy of this ListOfTransitions object.
   *
   * @return a (deep) copy of this ListOfTransitions object.
   */
  virtual ListOfTransitions* clone() const;


  /**
   * Destructor for ListOfTransitions.
   */
  virtual ~ListOfTransitions();


  /**
   * Get a Transition from the ListOfTransitions.
   *
   * @param n, an unsigned int representing the index of the Transition to
   * retrieve.
   *
   * @return the nth Transition in this ListOfTransitions.
   *
   * @see size()
   */
  virtual Transition* get(unsigned int n);


  /**
   * Get a Transition from the ListOfTransitions.
   *
   * @param n, an unsigned int representing the index of the Transition to
   * retrieve.
   *
   * @return the nth Transition in this ListOfTransitions.
   *
   * @see size()
   */
  virtual const Transition* get(unsigned int n) const;


  /**
   * Get a Transition from the ListOfTransitions based on its identifier.
   *
   * @param sid a string representing the identifier of the Transition to
   * retrieve.
   *
   * @return the Transition in this ListOfTransitions based on the identifier
   * or NULL if no such Transition exists.
   *
   * @see size()
   */
  virtual Transition* get(const std::string& sid);


  /**
   * Get a Transition from the ListOfTransitions based on its identifier.
   *
   * @param sid a string representing the identifier of the Transition to
   * retrieve.
   *
   * @return the Transition in this ListOfTransitions based on the identifier
   * or NULL if no such Transition exists.
   *
   * @see size()
   */
  virtual const Transition* get(const std::string& sid) const;


  /**
   * Removes the nth Transition from this ListOfTransitions and returns a
   * pointer to it.
   *
   * @param n, an unsigned int representing the index of the Transition to
   * remove.
   *
   * @return a pointer to the nth Transition in this ListOfTransitions.
   *
   * @see size()
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual Transition* remove(unsigned int n);


  /**
   * Removes the Transition from this ListOfTransitions based on its identifier
   * and returns a pointer to it.
   *
   * @param sid, a string representing the identifier of the Transition to
   * remove.
   *
   * @return the Transition in this ListOfTransitions based on the identifier
   * or NULL if no such Transition exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual Transition* remove(const std::string& sid);


  /**
   * Adds a copy of the given Transition to this ListOfTransitions.
   *
   * @param t, the Transition object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createTransition()
   */
  int addTransition(const Transition* t);


  /**
   * Get the number of Transition objects in this ListOfTransitions.
   *
   * @return the number of Transition objects in this ListOfTransitions.
   */
  unsigned int getNumTransitions() const;


  /**
   * Creates a new Transition object, adds it to this ListOfTransitions object
   * and returns the Transition object created.
   *
   * @return a new Transition object instance.
   *
   * @see addTransition(const Transition* t)
   */
  Transition* createTransition();


  /**
   * Returns the XML element name of this ListOfTransitions object.
   *
   * For ListOfTransitions, the XML element name is always @c
   * "listOfTransitions".
   *
   * @return the name of this element, i.e. @c "listOfTransitions".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML typcode of this ListOfTransitions object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_LIST_OF, SBMLTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSBML type code for the SBML objects contained in this
   * ListOfTransitions object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML typecode for the objects contained in this
   * ListOfTransitions:
   *
   * @sbmlconstant{SBML_QUAL_TRANSITION, SBMLQualTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode() const;


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new Transition in this ListOfTransitions
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the namespace for the Qual package
   */
  virtual void writeXMLNS(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a Transition_t from the ListOf_t.
 *
 * @param lo, the ListOf_t structure to search.
 *
 * @param n, an unsigned int representing the index of the Transition_t to
 * retrieve.
 *
 * @return the nth Transition_t in this ListOf_t.
 *
 * @memberof Transition_t
 */
LIBSBML_EXTERN
const Transition_t*
ListOfTransitions_getTransition(ListOf_t* lo, unsigned int n);


/**
 * Get a Transition_t from the ListOf_t based on its identifier.
 *
 * @param lo, the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the Transition_t to
 * retrieve.
 *
 * @return the Transition_t in this ListOf_t based on the identifier or NULL if
 * no such Transition_t exists.
 *
 * @memberof Transition_t
 */
LIBSBML_EXTERN
const Transition_t*
ListOfTransitions_getById(ListOf_t* lo, const char *sid);


/**
 * Removes the nth Transition_t from this ListOf_t and returns a pointer to it.
 *
 * @param lo, the ListOf_t structure to search.
 *
 * @param n, an unsigned int representing the index of the Transition_t to
 * remove.
 *
 * @return a pointer to the nth Transition_t in this ListOf_t.
 *
 * @memberof Transition_t
 */
LIBSBML_EXTERN
Transition_t*
ListOfTransitions_remove(ListOf_t* lo, unsigned int n);


/**
 * Removes the Transition_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param lo, the ListOf_t structure to search.
 *
 * @param sid, a string representing the identifier of the Transition_t to
 * remove.
 *
 * @return the Transition_t in this ListOf_t based on the identifier or NULL if
 * no such Transition_t exists.
 *
 * @memberof Transition_t
 */
LIBSBML_EXTERN
Transition_t*
ListOfTransitions_removeById(ListOf_t* lo, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ListOfTransitions_H__ */


