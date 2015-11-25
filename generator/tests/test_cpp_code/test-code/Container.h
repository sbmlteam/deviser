/**
 * @file Container.h
 * @brief Definition of Container.
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
   * @param level an unsigned int, the SBML Level to assign to this Container
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Container
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * Container
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Container(unsigned int level = TestExtension::getDefaultLevel(),
            unsigned int version = TestExtension::getDefaultVersion(),
            unsigned int pkgVersion =
              TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new Container using the given TestPkgNamespaces object.
   *
   * @param testns the TestPkgNamespaces object
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  Container(TestPkgNamespaces *testns);


  /**
   * Copy constructor for Container.
   *
   * @param orig; the Container instance to copy.
   */
  Container(const Container& orig);


  /**
   * Assignment operator for Container.
   *
   * @param rhs; the Container object whose values are to be used as the basis
   * of the assignment
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
   */
  const ListOfMyLoTests* getListOfMyLoTests() const;


  /**
   * Returns the ListOfMyLoTests from this Container.
   *
   * @return the ListOfMyLoTests from this Container.
   */
  ListOfMyLoTests* getListOfMyLoTests();


  /**
   * Get a MyLoTest from the Container.
   *
   * @param n, an unsigned int representing the index of the MyLoTest to
   * retrieve.
   *
   * @return the nth MyLoTest in this Container.
   *
   * @see getNumMyLoTests
   */
  MyLoTest* getMyLoTest(unsigned int n);


  /**
   * Get a MyLoTest from the Container.
   *
   * @param n, an unsigned int representing the index of the MyLoTest to
   * retrieve.
   *
   * @return the nth MyLoTest in this Container.
   *
   * @see getNumMyLoTests
   */
  const MyLoTest* getMyLoTest(unsigned int n) const;


  /**
   * Adds a copy of the given MyLoTest to this Container.
   *
   * @param mlt, the MyLoTest object to add.
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
   * Get the number of MyLoTest objects in this Container.
   *
   * @return the number of MyLoTest objects in this Container.
   */
  unsigned int getNumMyLoTests() const;


  /**
   * Creates a new MyLoTest object, adds it to this Container object and
   * returns the MyLoTest object created.
   *
   * @return a new MyLoTest object instance.
   *
   * @see addMyLoTest(const MyLoTest* mlt)
   */
  MyLoTest* createMyLoTest();


  /**
   * Removes the nth MyLoTest from this Container and returns a pointer to it.
   *
   * @param n, an unsigned int representing the index of the MyLoTest to
   * remove.
   *
   * @return a pointer to the nth MyLoTest in this Container.
   *
   * @see getNumMyLoTests
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  MyLoTest* removeMyLoTest(unsigned int n);


  /**
   * Returns the XML name of this Container object.
   *
   * @return the name of this element; that is "container".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML typcode of this Container object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_TEST_CONTAINER, SBMLTestTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * Container object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * Container have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Container object are:
   */
  virtual bool hasRequiredElements() const;



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


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p id.
   */
  virtual SBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element that has the given @p metaid, or @c NULL
   * if no such object is found.
   *
   * @param metaid a string representing the metaid attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SBase element with the given @p metaid.
   */
  virtual SBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SBase objects, including those nested to an
   * arbitrary depth.
   *
   * filter, an ElementFilter that may impose restrictions on the objects to be
   * retrieved.
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
 * @param level an unsigned int, the SBML Level to assign to this Container_t
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Container_t
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * Container_t
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
Container_t *
Container_create(unsigned int level = TestExtension::getDefaultLevel(),
                 unsigned int version = TestExtension::getDefaultVersion(),
                 unsigned int pkgVersion =
                   TestExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this Container_t object.
 *
 * @param c; the Container_t structure
 *
 * @return a (deep) copy of this Container_t object.
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
Container_t*
Container_clone(const Container_t* c);


/**
 * Frees this Container_t object.
 *
 * @param c; the Container_t structure
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
void
Container_free(Container_t* c);


/**
 * Returns a ListOf_t* containing MyLoTest_t objects from this Container_t.
 *
 * @param c the Container_t structure whose "ListOfMyLoTests" is sought.
 *
 * @return the "ListOfMyLoTests" from this Container_t as a ListOf_t *.
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
ListOf_t*
Container_getListOfMyLoTests(Container_t* c);


/**
 * Get a MyLoTest_t from the Container_t.
 *
 * @param c, the Container_t structure to search.
 *
 * @param n, an unsigned int representing the index of the MyLoTest_t to
 * retrieve.
 *
 * @return the nth MyLoTest_t in this Container_t.
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
const MyLoTest_t*
Container_getMyLoTest(Container_t* c, unsigned int n);


/**
 * Adds a copy of the given MyLoTest_t to this Container_t.
 *
 * @param c, the Container_t structure to which the MyLoTest_t should be added.
 *
 * @param mlt, the MyLoTest_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
int
Container_addMyLoTest(Container_t* c, const MyLoTest_t* mlt);


/**
 * Get the number of MyLoTest_t objects in this Container_t.
 *
 * @param c, the Container_t structure to query.
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
 * @param c, the Container_t structure to which the MyLoTest_t should be added.
 *
 * @return a new MyLoTest_t object instance.
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
 * @param c, the Container_t structure to search.
 *
 * @param n, an unsigned int representing the index of the MyLoTest_t to
 * remove.
 *
 * @return a pointer to the nth MyLoTest_t in this Container_t.
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
MyLoTest_t*
Container_removeMyLoTest(Container_t* c, unsigned int n);


/**
 * Predicate returning @c 1 if all the required elements for this Container_t
 * object have been set.
 *
 * @param c the Container_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this Container_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the Container_t object are:
 *
 * @memberof Container_t
 */
LIBSBML_EXTERN
int
Container_hasRequiredElements(const Container_t * c);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Container_H__ */


