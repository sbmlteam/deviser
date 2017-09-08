/**
 * @file ListOfMyLoTests.h
 * @brief Definition of the ListOfMyLoTests class.
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
 * @class ListOfMyLoTests
 * @sbmlbrief{test} TODO:Definition of the ListOfMyLoTests class.
 */


#ifndef ListOfMyLoTests_H__
#define ListOfMyLoTests_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/ListOf.h>
#include <sbml/packages/test/extension/TestExtension.h>
#include <sbml/packages/test/sbml/MyLoTest.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ListOfMyLoTests : public ListOf
{
protected:

  /** @cond doxygenLibsbmlInternal */


  /** @endcond */

public:

  /**
   * Creates a new ListOfMyLoTests using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * ListOfMyLoTests.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ListOfMyLoTests.
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * ListOfMyLoTests.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfMyLoTests(unsigned int level = TestExtension::getDefaultLevel(),
                  unsigned int version = TestExtension::getDefaultVersion(),
                  unsigned int pkgVersion =
                    TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new ListOfMyLoTests using the given TestPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param testns the TestPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ListOfMyLoTests(TestPkgNamespaces *testns);


  /**
   * Copy constructor for ListOfMyLoTests.
   *
   * @param orig the ListOfMyLoTests instance to copy.
   */
  ListOfMyLoTests(const ListOfMyLoTests& orig);


  /**
   * Assignment operator for ListOfMyLoTests.
   *
   * @param rhs the ListOfMyLoTests object whose values are to be used as the
   * basis of the assignment.
   */
  ListOfMyLoTests& operator=(const ListOfMyLoTests& rhs);


  /**
   * Creates and returns a deep copy of this ListOfMyLoTests object.
   *
   * @return a (deep) copy of this ListOfMyLoTests object.
   */
  virtual ListOfMyLoTests* clone() const;


  /**
   * Destructor for ListOfMyLoTests.
   */
  virtual ~ListOfMyLoTests();


  /**
   * Returns the value of the "id" attribute of this ListOfMyLoTests.
   *
   * @return the value of the "id" attribute of this ListOfMyLoTests as a
   * string.
   */
  virtual const std::string& getId() const;


  /**
   * Predicate returning @c true if this ListOfMyLoTests's "id" attribute is
   * set.
   *
   * @return @c true if this ListOfMyLoTests's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Sets the value of the "id" attribute of this ListOfMyLoTests.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  virtual int setId(const std::string& id);


  /**
   * Unsets the value of the "id" attribute of this ListOfMyLoTests.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Get a MyLoTest from the ListOfMyLoTests.
   *
   * @param n an unsigned int representing the index of the MyLoTest to
   * retrieve.
   *
   * @return the nth MyLoTest in this ListOfMyLoTests.
   *
   * @see size()
   */
  virtual MyLoTest* get(unsigned int n);


  /**
   * Get a MyLoTest from the ListOfMyLoTests.
   *
   * @param n an unsigned int representing the index of the MyLoTest to
   * retrieve.
   *
   * @return the nth MyLoTest in this ListOfMyLoTests.
   *
   * @see size()
   */
  virtual const MyLoTest* get(unsigned int n) const;


  /**
   * Get a MyLoTest from the ListOfMyLoTests based on its identifier.
   *
   * @param sid a string representing the identifier of the MyLoTest to
   * retrieve.
   *
   * @return the MyLoTest in this ListOfMyLoTests with the given id or NULL if
   * no such MyLoTest exists.
   *
   * @see size()
   */
  virtual MyLoTest* get(const std::string& sid);


  /**
   * Get a MyLoTest from the ListOfMyLoTests based on its identifier.
   *
   * @param sid a string representing the identifier of the MyLoTest to
   * retrieve.
   *
   * @return the MyLoTest in this ListOfMyLoTests with the given id or NULL if
   * no such MyLoTest exists.
   *
   * @see size()
   */
  virtual const MyLoTest* get(const std::string& sid) const;


  /**
   * Removes the nth MyLoTest from this ListOfMyLoTests and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the MyLoTest to remove.
   *
   * @return a pointer to the nth MyLoTest in this ListOfMyLoTests.
   *
   * @see size()
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual MyLoTest* remove(unsigned int n);


  /**
   * Removes the MyLoTest from this ListOfMyLoTests based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the MyLoTest to remove.
   *
   * @return the MyLoTest in this ListOfMyLoTests based on the identifier or
   * NULL if no such MyLoTest exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  virtual MyLoTest* remove(const std::string& sid);


  /**
   * Adds a copy of the given MyLoTest to this ListOfMyLoTests.
   *
   * @param mlt the MyLoTest object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createMyLoTest()
   */
  int addMyLoTest(const MyLoTest* mlt);


  /**
   * Get the number of MyLoTest objects in this ListOfMyLoTests.
   *
   * @return the number of MyLoTest objects in this ListOfMyLoTests.
   */
  unsigned int getNumMyLoTests() const;


  /**
   * Creates a new MyLoTest object, adds it to this ListOfMyLoTests object and
   * returns the MyLoTest object created.
   *
   * @return a new MyLoTest object instance.
   *
   * @see addMyLoTest(const MyLoTest* mlt)
   */
  MyLoTest* createMyLoTest();


  /**
   * Returns the XML element name of this ListOfMyLoTests object.
   *
   * For ListOfMyLoTests, the XML element name is always @c "listOfMyLoTests".
   *
   * @return the name of this element, i.e. @c "listOfMyLoTests".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ListOfMyLoTests object.
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
   * ListOfMyLoTests object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML typecode for the objects contained in this
   * ListOfMyLoTests:
   *
   * @sbmlconstant{TEST_LO_TEST, SBMLTestTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * ListOfMyLoTests object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * ListOfMyLoTests have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new MyLoTest in this ListOfMyLoTests
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
 * Returns the value of the "id" attribute of this ListOf_t.
 *
 * @param lo the ListOf_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this ListOf_t as a pointer to a
 * string.
 *
 * @memberof ListOfMyLoTests_t
 */
LIBSBML_EXTERN
const char *
ListOfMyLoTests_getId(const ListOf_t * lo);


/**
 * Predicate returning @c 1 (true) if this ListOf_t's "id" attribute is set.
 *
 * @param lo the ListOf_t structure.
 *
 * @return @c 1 (true) if this ListOf_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof ListOfMyLoTests_t
 */
LIBSBML_EXTERN
int
ListOfMyLoTests_isSetId(const ListOf_t * lo);


/**
 * Sets the value of the "id" attribute of this ListOf_t.
 *
 * @param lo the ListOf_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ListOfMyLoTests_t
 */
LIBSBML_EXTERN
int
ListOfMyLoTests_setId(ListOf_t * lo, const char * id);


/**
 * Unsets the value of the "id" attribute of this ListOf_t.
 *
 * @param lo the ListOf_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ListOfMyLoTests_t
 */
LIBSBML_EXTERN
int
ListOfMyLoTests_unsetId(ListOf_t * lo);


/**
 * Get a MyLoTest_t from the ListOf_t.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the MyLoTest_t to
 * retrieve.
 *
 * @return the nth MyLoTest_t in this ListOf_t.
 *
 * @memberof ListOfMyLoTests_t
 */
LIBSBML_EXTERN
const MyLoTest_t*
ListOfMyLoTests_getMyLoTest(ListOf_t* lo, unsigned int n);


/**
 * Get a MyLoTest_t from the ListOf_t based on its identifier.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the MyLoTest_t to
 * retrieve.
 *
 * @return the MyLoTest_t in this ListOf_t with the given id or NULL if no such
 * MyLoTest_t exists.
 *
 * @memberof ListOfMyLoTests_t
 */
LIBSBML_EXTERN
const MyLoTest_t*
ListOfMyLoTests_getById(ListOf_t* lo, const char *sid);


/**
 * Removes the nth MyLoTest_t from this ListOf_t and returns a pointer to it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the MyLoTest_t to remove.
 *
 * @return a pointer to the nth MyLoTest_t in this ListOf_t.
 *
 * @memberof ListOfMyLoTests_t
 */
LIBSBML_EXTERN
MyLoTest_t*
ListOfMyLoTests_remove(ListOf_t* lo, unsigned int n);


/**
 * Removes the MyLoTest_t from this ListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param lo the ListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the MyLoTest_t to remove.
 *
 * @return the MyLoTest_t in this ListOf_t based on the identifier or NULL if
 * no such MyLoTest_t exists.
 *
 * @memberof ListOfMyLoTests_t
 */
LIBSBML_EXTERN
MyLoTest_t*
ListOfMyLoTests_removeById(ListOf_t* lo, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ListOfMyLoTests_H__ */


