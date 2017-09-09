/**
 * @file ListOfClassTwos.h
 * @brief Definition of the ListOfClassTwos class.
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
 * @class ListOfClassTwos
 * @sbmlbrief{test} TODO:Definition of the ListOfClassTwos class.
 */


#ifndef ListOfClassTwos_H__
#define ListOfClassTwos_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/ListOf.h>
#include <sbml/packages/test/extension/TestExtension.h>
#include <sbml/packages/test/sbml/ClassTwo.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ListOfClassTwos : public ListOf
{

public:

  /**
   * Creates a new ListOfClassTwos using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ListOfClassTwos.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ListOfClassTwos.
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * ListOfClassTwos.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfClassTwos(unsigned int level = TestExtension::getDefaultLevel(),
                  unsigned int version = TestExtension::getDefaultVersion(),
                  unsigned int pkgVersion =
                    TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfClassTwos using the given TestPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param testns the TestPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfClassTwos(TestPkgNamespaces *testns);


  /**
   * Copy constructor for ListOfClassTwos.
   *
   * @param orig the ListOfClassTwos instance to copy.
   */
  ListOfClassTwos(const ListOfClassTwos& orig);


  /**
   * Assignment operator for ListOfClassTwos.
   *
   * @param rhs the ListOfClassTwos object whose values are to be used as the
   * basis of the assignment.
   */
  ListOfClassTwos& operator=(const ListOfClassTwos& rhs);


  /**
   * Creates and returns a deep copy of this ListOfClassTwos object.
   *
   * @return a (deep) copy of this ListOfClassTwos object.
   */
  virtual ListOfClassTwos* clone() const;


  /**
   * Destructor for ListOfClassTwos.
   */
  virtual ~ListOfClassTwos();


  /**
   * Get a ClassTwo from the ListOfClassTwos.
   *
   * @param n an unsigned int representing the index of the ClassTwo to
   * retrieve.
   *
   * @return the nth ClassTwo in this ListOfClassTwos.
   *
   * @see size()
   */
  virtual ClassTwo* get(unsigned int n);


  /**
   * Get a ClassTwo from the ListOfClassTwos.
   *
   * @param n an unsigned int representing the index of the ClassTwo to
   * retrieve.
   *
   * @return the nth ClassTwo in this ListOfClassTwos.
   *
   * @see size()
   */
  virtual const ClassTwo* get(unsigned int n) const;


  /**
   * Get a ClassTwo from the ListOfClassTwos based on its identifier.
   *
   * @param sid a string representing the identifier of the ClassTwo to
   * retrieve.
   *
   * @return the ClassTwo in this ListOfClassTwos with the given id or NULL if
   * no such ClassTwo exists.
   *
   * @see size()
   */
  virtual ClassTwo* get(const std::string& sid);


  /**
   * Get a ClassTwo from the ListOfClassTwos based on its identifier.
   *
   * @param sid a string representing the identifier of the ClassTwo to
   * retrieve.
   *
   * @return the ClassTwo in this ListOfClassTwos with the given id or NULL if
   * no such ClassTwo exists.
   *
   * @see size()
   */
  virtual const ClassTwo* get(const std::string& sid) const;


  /**
   * Removes the nth ClassTwo from this ListOfClassTwos and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the ClassTwo to remove.
   *
   * @return a pointer to the nth ClassTwo in this ListOfClassTwos.
   *
   * @see size()
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual ClassTwo* remove(unsigned int n);


  /**
   * Removes the ClassTwo from this ListOfClassTwos based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the ClassTwo to remove.
   *
   * @return the ClassTwo in this ListOfClassTwos based on the identifier or
   * NULL if no such ClassTwo exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual ClassTwo* remove(const std::string& sid);


  /**
   * Adds a copy of the given ClassTwo to this ListOfClassTwos.
   *
   * @param ct the ClassTwo object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createClassTwo()
   */
  int addClassTwo(const ClassTwo* ct);


  /**
   * Get the number of ClassTwo objects in this ListOfClassTwos.
   *
   * @return the number of ClassTwo objects in this ListOfClassTwos.
   */
  unsigned int getNumClassTwos() const;


  /**
   * Creates a new ClassTwo object, adds it to this ListOfClassTwos object and
   * returns the ClassTwo object created.
   *
   * @return a new ClassTwo object instance.
   *
   * @see addClassTwo(const ClassTwo* ct)
   */
  ClassTwo* createClassTwo();


  /**
   * Returns the XML element name of this ListOfClassTwos object.
   *
   * For ListOfClassTwos, the XML element name is always @c "listOfClassTwos".
   *
   * @return the name of this element, i.e. @c "listOfClassTwos".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ListOfClassTwos object.
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
   * ListOfClassTwos object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML typecode for the objects contained in this
   * ListOfClassTwos:
   *
   * @sbmlconstant{SBML_TEST_CLASSTWO, SBMLTestTypeCode_t}
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
   * Creates a new ClassTwo in this ListOfClassTwos
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the namespace for the Test package
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
 * Get a ClassTwo_t from the ListOf_t.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the ClassTwo_t to
 * retrieve.
 *
 * @return the nth ClassTwo_t in this ListOf_t.
 *
 * @memberof ListOfClassTwos_t
 */
LIBSBML_EXTERN
ClassTwo_t*
ListOfClassTwos_getClassTwo(ListOf_t* lo, unsigned int n);


/**
 * Get a ClassTwo_t from the ListOf_t based on its identifier.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the ClassTwo_t to
 * retrieve.
 *
 * @return the ClassTwo_t in this ListOf_t with the given id or NULL if no such
 * ClassTwo_t exists.
 *
 * @memberof ListOfClassTwos_t
 */
LIBSBML_EXTERN
ClassTwo_t*
ListOfClassTwos_getById(ListOf_t* lo, const char *sid);


/**
 * Removes the nth ClassTwo_t from this ListOf_t and returns a pointer to it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the ClassTwo_t to remove.
 *
 * @return a pointer to the nth ClassTwo_t in this ListOf_t.
 *
 * @memberof ListOfClassTwos_t
 */
LIBSBML_EXTERN
ClassTwo_t*
ListOfClassTwos_remove(ListOf_t* lo, unsigned int n);


/**
 * Removes the ClassTwo_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the ClassTwo_t to remove.
 *
 * @return the ClassTwo_t in this ListOf_t based on the identifier or NULL if
 * no such ClassTwo_t exists.
 *
 * @memberof ListOfClassTwos_t
 */
LIBSBML_EXTERN
ClassTwo_t*
ListOfClassTwos_removeById(ListOf_t* lo, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ListOfClassTwos_H__ */


