/**
 * @file Container.h
 * @brief Definition of the Container class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
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
 * @class Container
 * @sbmlbrief{test} TODO:Definition of the Container class.
 */


#ifndef Container_H__
#define Container_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>
#include <sbml/packages/test/sbml/ListOfMyLoTests.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Container : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  ListOfMyLoTests mMyLoTests;

  /** @endcond */

public:

  /**
   * Creates a new Container using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Container.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Container.
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * Container.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Container(unsigned int level = TestExtension::getDefaultLevel(),
            unsigned int version = TestExtension::getDefaultVersion(),
            unsigned int pkgVersion =
              TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new Container using the given TestPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param testns the TestPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Container(TestPkgNamespaces *testns);


  /**
   * Copy constructor for Container.
   *
   * @param orig the Container instance to copy.
   */
  Container(const Container& orig);


  /**
   * Assignment operator for Container.
   *
   * @param rhs the Container object whose values are to be used as the basis
   * of the assignment.
   */
  Container& operator=(const Container& rhs);


  /**
   * Creates and returns a deep copy of this Container object.
   *
   * @return a (deep) copy of this Container object.
   */
  virtual Container* clone() const;


  /**
   * Destructor for Container.
   */
  virtual ~Container();


  /**
   * Returns the ListOfMyLoTests from this Container.
   *
   * @return the ListOfMyLoTests from this Container.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see createMyLoTest()
   * @see getMyLoTest(const std::string& sid)
   * @see getMyLoTest(unsigned int n)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(const std::string& sid)
   * @see removeMyLoTest(unsigned int n)
   */
  const ListOfMyLoTests* getListOfMyLoTests() const;


  /**
   * Returns the ListOfMyLoTests from this Container.
   *
   * @return the ListOfMyLoTests from this Container.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see createMyLoTest()
   * @see getMyLoTest(const std::string& sid)
   * @see getMyLoTest(unsigned int n)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(const std::string& sid)
   * @see removeMyLoTest(unsigned int n)
   */
  ListOfMyLoTests* getListOfMyLoTests();


  /**
   * Get a MyLoTest from the Container.
   *
   * @param n an unsigned int representing the index of the MyLoTest to
   * retrieve.
   *
   * @return the nth MyLoTest in the ListOfMyLoTests within this Container.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see createMyLoTest()
   * @see getMyLoTest(const std::string& sid)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(const std::string& sid)
   * @see removeMyLoTest(unsigned int n)
   */
  MyLoTest* getMyLoTest(unsigned int n);


  /**
   * Get a MyLoTest from the Container.
   *
   * @param n an unsigned int representing the index of the MyLoTest to
   * retrieve.
   *
   * @return the nth MyLoTest in the ListOfMyLoTests within this Container.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see createMyLoTest()
   * @see getMyLoTest(const std::string& sid)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(const std::string& sid)
   * @see removeMyLoTest(unsigned int n)
   */
  const MyLoTest* getMyLoTest(unsigned int n) const;


  /**
   * Get a MyLoTest from the Container based on its identifier.
   *
   * @param sid a string representing the identifier of the MyLoTest to
   * retrieve.
   *
   * @return the MyLoTest in the ListOfMyLoTests within this Container with the
   * given @p sid or @c NULL if no such MyLoTest exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see createMyLoTest()
   * @see getMyLoTest(unsigned int n)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(const std::string& sid)
   * @see removeMyLoTest(unsigned int n)
   */
  MyLoTest* getMyLoTest(const std::string& sid);


  /**
   * Get a MyLoTest from the Container based on its identifier.
   *
   * @param sid a string representing the identifier of the MyLoTest to
   * retrieve.
   *
   * @return the MyLoTest in the ListOfMyLoTests within this Container with the
   * given @p sid or @c NULL if no such MyLoTest exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see createMyLoTest()
   * @see getMyLoTest(unsigned int n)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(const std::string& sid)
   * @see removeMyLoTest(unsigned int n)
   */
  const MyLoTest* getMyLoTest(const std::string& sid) const;


  /**
   * Adds a copy of the given MyLoTest to this Container.
   *
   * @param mlt the MyLoTest object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createMyLoTest()
   * @see getMyLoTest(const std::string& sid)
   * @see getMyLoTest(unsigned int n)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(const std::string& sid)
   * @see removeMyLoTest(unsigned int n)
   */
  int addMyLoTest(const MyLoTest* mlt);


  /**
   * Get the number of MyLoTest objects in this Container.
   *
   * @return the number of MyLoTest objects in this Container.
   *
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see createMyLoTest()
   * @see getMyLoTest(const std::string& sid)
   * @see getMyLoTest(unsigned int n)
   * @see removeMyLoTest(const std::string& sid)
   * @see removeMyLoTest(unsigned int n)
   */
  unsigned int getNumMyLoTests() const;


  /**
   * Creates a new MyLoTest object, adds it to this Container object and
   * returns the MyLoTest object created.
   *
   * @return a new MyLoTest object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see getMyLoTest(const std::string& sid)
   * @see getMyLoTest(unsigned int n)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(const std::string& sid)
   * @see removeMyLoTest(unsigned int n)
   */
  MyLoTest* createMyLoTest();


  /**
   * Removes the nth MyLoTest from this Container and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the MyLoTest to remove.
   *
   * @return a pointer to the nth MyLoTest in this Container.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see createMyLoTest()
   * @see getMyLoTest(const std::string& sid)
   * @see getMyLoTest(unsigned int n)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(const std::string& sid)
   */
  MyLoTest* removeMyLoTest(unsigned int n);


  /**
   * Removes the MyLoTest from this Container based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the MyLoTest to remove.
   *
   * @return the MyLoTest in this Container based on the identifier or NULL if
   * no such MyLoTest exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addMyLoTest(const MyLoTest* object)
   * @see createMyLoTest()
   * @see getMyLoTest(const std::string& sid)
   * @see getMyLoTest(unsigned int n)
   * @see getNumMyLoTests()
   * @see removeMyLoTest(unsigned int n)
   */
  MyLoTest* removeMyLoTest(const std::string& sid);


  /**
   * Returns the XML element name of this Container object.
   *
   * For Container, the XML element name is always @c "container".
   *
   * @return the name of this element, i.e. @c "container".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Container object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_TEST_CONTAINER, SBMLTestTypeCode_t}.
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
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Updates the namespaces when setLevelVersion is used
   */
  virtual void updateSBMLNamespace(const std::string& package,
                                   unsigned int level,
                                   unsigned int version);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this Container's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Container's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this Container.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates and returns an new "elementName" object in this Container.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this Container.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SBase* element);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * Container.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SBase* removeChildObject(const std::string& elementName,
                                   const std::string& id);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the number of "elementName" in this Container.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this Container.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SBase* getObject(const std::string& elementName, unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid. If no
   * such object is found this method returns @c NULL.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List* pointer of pointers to all SBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(ElementFilter * filter = NULL);


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(XMLInputStream& stream);

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Container_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Container_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Container_t.
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * Container_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
Container_t *
Container_create(unsigned int level,
                 unsigned int version,
                 unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Container_t object.
 *
 * @param c the Container_t structure.
 *
 * @return a (deep) copy of this Container_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
Container_t*
Container_clone(const Container_t* c);


/**
 * Frees this Container_t object.
 *
 * @param c the Container_t structure.
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
void
Container_free(Container_t* c);


/**
 * Returns a ListOf_t * containing MyLoTest_t objects from this Container_t.
 *
 * @param c the Container_t structure whose ListOfMyLoTests is sought.
 *
 * @return the ListOfMyLoTests from this Container_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Container_addMyLoTest()
 * @see Container_createMyLoTest()
 * @see Container_getMyLoTestById()
 * @see Container_getMyLoTest()
 * @see Container_getNumMyLoTests()
 * @see Container_removeMyLoTestById()
 * @see Container_removeMyLoTest()
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
ListOf_t*
Container_getListOfMyLoTests(Container_t* c);


/**
 * Get a MyLoTest_t from the Container_t.
 *
 * @param c the Container_t structure to search.
 *
 * @param n an unsigned int representing the index of the MyLoTest_t to
 * retrieve.
 *
 * @return the nth MyLoTest_t in the ListOfMyLoTests within this Container.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
MyLoTest_t*
Container_getMyLoTest(Container_t* c, unsigned int n);


/**
 * Get a MyLoTest_t from the Container_t based on its identifier.
 *
 * @param c the Container_t structure to search.
 *
 * @param sid a string representing the identifier of the MyLoTest_t to
 * retrieve.
 *
 * @return the MyLoTest_t in the ListOfMyLoTests within this Container with the
 * given @p sid or @c NULL if no such MyLoTest_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
MyLoTest_t*
Container_getMyLoTestById(Container_t* c, const char *sid);


/**
 * Adds a copy of the given MyLoTest_t to this Container_t.
 *
 * @param c the Container_t structure to which the MyLoTest_t should be added.
 *
 * @param mlt the MyLoTest_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
int
Container_addMyLoTest(Container_t* c, const MyLoTest_t* mlt);


/**
 * Get the number of MyLoTest_t objects in this Container_t.
 *
 * @param c the Container_t structure to query.
 *
 * @return the number of MyLoTest_t objects in this Container_t.
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
unsigned int
Container_getNumMyLoTests(Container_t* c);


/**
 * Creates a new MyLoTest_t object, adds it to this Container_t object and
 * returns the MyLoTest_t object created.
 *
 * @param c the Container_t structure to which the MyLoTest_t should be added.
 *
 * @return a new MyLoTest_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
MyLoTest_t*
Container_createMyLoTest(Container_t* c);


/**
 * Removes the nth MyLoTest_t from this Container_t and returns a pointer to
 * it.
 *
 * @param c the Container_t structure to search.
 *
 * @param n an unsigned int representing the index of the MyLoTest_t to remove.
 *
 * @return a pointer to the nth MyLoTest_t in this Container_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
MyLoTest_t*
Container_removeMyLoTest(Container_t* c, unsigned int n);


/**
 * Removes the MyLoTest_t from this Container_t based on its identifier and
 * returns a pointer to it.
 *
 * @param c the Container_t structure to search.
 *
 * @param sid a string representing the identifier of the MyLoTest_t to remove.
 *
 * @return the MyLoTest_t in this Container_t based on the identifier or NULL
 * if no such MyLoTest_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
MyLoTest_t*
Container_removeMyLoTestById(Container_t* c, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Container_H__ */


