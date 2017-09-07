/**
 * @file ListOfChildren.h
 * @brief Definition of the ListOfChildren class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2017 jointly by the following organizations:
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
 * @class ListOfChildren
 * @sbmlbrief{nasty} TODO:Definition of the ListOfChildren class.
 */


#ifndef ListOfChildren_H__
#define ListOfChildren_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/nasty/common/nastyfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/ListOf.h>
#include <sbml/packages/nasty/extension/NastyExtension.h>
#include <sbml/packages/nasty/sbml/Child.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ListOfChildren : public ListOf
{

public:

  /**
   * Creates a new ListOfChildren using the given SBML Level, Version and
   * &ldquo;nasty&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ListOfChildren.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ListOfChildren.
   *
   * @param pkgVersion an unsigned int, the SBML Nasty Version to assign to
   * this ListOfChildren.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfChildren(unsigned int level = NastyExtension::getDefaultLevel(),
                 unsigned int version = NastyExtension::getDefaultVersion(),
                 unsigned int pkgVersion =
                   NastyExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfChildren using the given NastyPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param nastyns the NastyPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfChildren(NastyPkgNamespaces *nastyns);


  /**
   * Copy constructor for ListOfChildren.
   *
   * @param orig the ListOfChildren instance to copy.
   */
  ListOfChildren(const ListOfChildren& orig);


  /**
   * Assignment operator for ListOfChildren.
   *
   * @param rhs the ListOfChildren object whose values are to be used as the
   * basis of the assignment.
   */
  ListOfChildren& operator=(const ListOfChildren& rhs);


  /**
   * Creates and returns a deep copy of this ListOfChildren object.
   *
   * @return a (deep) copy of this ListOfChildren object.
   */
  virtual ListOfChildren* clone() const;


  /**
   * Destructor for ListOfChildren.
   */
  virtual ~ListOfChildren();


  /**
   * Get a Child from the ListOfChildren.
   *
   * @param n an unsigned int representing the index of the Child to retrieve.
   *
   * @return the nth Child in this ListOfChildren.
   *
   * @see size()
   */
  virtual Child* get(unsigned int n);


  /**
   * Get a Child from the ListOfChildren.
   *
   * @param n an unsigned int representing the index of the Child to retrieve.
   *
   * @return the nth Child in this ListOfChildren.
   *
   * @see size()
   */
  virtual const Child* get(unsigned int n) const;


  /**
   * Get a Child from the ListOfChildren based on its identifier.
   *
   * @param sid a string representing the identifier of the Child to retrieve.
   *
   * @return the Child in this ListOfChildren with the given id or NULL if no
   * such Child exists.
   *
   * @see size()
   */
  virtual Child* get(const std::string& sid);


  /**
   * Get a Child from the ListOfChildren based on its identifier.
   *
   * @param sid a string representing the identifier of the Child to retrieve.
   *
   * @return the Child in this ListOfChildren with the given id or NULL if no
   * such Child exists.
   *
   * @see size()
   */
  virtual const Child* get(const std::string& sid) const;


  /**
   * Removes the nth Child from this ListOfChildren and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the Child to remove.
   *
   * @return a pointer to the nth Child in this ListOfChildren.
   *
   * @see size()
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual Child* remove(unsigned int n);


  /**
   * Removes the Child from this ListOfChildren based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the Child to remove.
   *
   * @return the Child in this ListOfChildren based on the identifier or NULL
   * if no such Child exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual Child* remove(const std::string& sid);


  /**
   * Adds a copy of the given Child to this ListOfChildren.
   *
   * @param c the Child object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createChild()
   */
  int addChild(const Child* c);


  /**
   * Get the number of Child objects in this ListOfChildren.
   *
   * @return the number of Child objects in this ListOfChildren.
   */
  unsigned int getNumChildren() const;


  /**
   * Creates a new Child object, adds it to this ListOfChildren object and
   * returns the Child object created.
   *
   * @return a new Child object instance.
   *
   * @see addChild(const Child* c)
   */
  Child* createChild();


  /**
   * Returns the XML element name of this ListOfChildren object.
   *
   * For ListOfChildren, the XML element name is always @c "listOfChildren".
   *
   * @return the name of this element, i.e. @c "listOfChildren".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ListOfChildren object.
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
   * ListOfChildren object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML typecode for the objects contained in this
   * ListOfChildren:
   *
   * @sbmlconstant{SBML_NASTY_CHILD, SBMLNastyTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new Child in this ListOfChildren
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the namespace for the Nasty package
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
 * Get a Child_t from the ListOf_t.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the Child_t to retrieve.
 *
 * @return the nth Child_t in this ListOf_t.
 *
 * @memberof Child_t
 */
LIBSBML_EXTERN
const Child_t*
ListOfChildren_getChild(ListOf_t* lo, unsigned int n);


/**
 * Get a Child_t from the ListOf_t based on its identifier.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the Child_t to retrieve.
 *
 * @return the Child_t in this ListOf_t with the given id or NULL if no such
 * Child_t exists.
 *
 * @memberof Child_t
 */
LIBSBML_EXTERN
const Child_t*
ListOfChildren_getById(ListOf_t* lo, const char *sid);


/**
 * Removes the nth Child_t from this ListOf_t and returns a pointer to it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the Child_t to remove.
 *
 * @return a pointer to the nth Child_t in this ListOf_t.
 *
 * @memberof Child_t
 */
LIBSBML_EXTERN
Child_t*
ListOfChildren_remove(ListOf_t* lo, unsigned int n);


/**
 * Removes the Child_t from this ListOf_t based on its identifier and returns a
 * pointer to it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the Child_t to remove.
 *
 * @return the Child_t in this ListOf_t based on the identifier or NULL if no
 * such Child_t exists.
 *
 * @memberof Child_t
 */
LIBSBML_EXTERN
Child_t*
ListOfChildren_removeById(ListOf_t* lo, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ListOfChildren_H__ */


