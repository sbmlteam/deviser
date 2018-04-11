/**
 * @file ArrayChild.h
 * @brief Definition of the ArrayChild class.
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
 * @class ArrayChild
 * @sbmlbrief{test} TODO:Definition of the ArrayChild class.
 */


#ifndef ArrayChild_H__
#define ArrayChild_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/test/common/testfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/test/extension/TestExtension.h>
#include <sbml/packages/test/sbml/Unit.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ArrayChild : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  Unit* mUnit;
  double* mNumber;

  /** @endcond */

public:

  /**
   * Creates a new ArrayChild using the given SBML Level, Version and
   * &ldquo;test&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this ArrayChild.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ArrayChild.
   *
   * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
   * ArrayChild.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ArrayChild(unsigned int level = TestExtension::getDefaultLevel(),
             unsigned int version = TestExtension::getDefaultVersion(),
             unsigned int pkgVersion =
               TestExtension::getDefaultPackageVersion());


  /**
   * Creates a new ArrayChild using the given TestPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param testns the TestPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ArrayChild(TestPkgNamespaces *testns);


  /**
   * Copy constructor for ArrayChild.
   *
   * @param orig the ArrayChild instance to copy.
   */
  ArrayChild(const ArrayChild& orig);


  /**
   * Assignment operator for ArrayChild.
   *
   * @param rhs the ArrayChild object whose values are to be used as the basis
   * of the assignment.
   */
  ArrayChild& operator=(const ArrayChild& rhs);


  /**
   * Creates and returns a deep copy of this ArrayChild object.
   *
   * @return a (deep) copy of this ArrayChild object.
   */
  virtual ArrayChild* clone() const;


  /**
   * Destructor for ArrayChild.
   */
  virtual ~ArrayChild();


  /**
   * Returns the value of the "number" attribute of this ArrayChild.
   *
   * @param outArray double* array that will be used to return the value of the
   * "number" attribute of this ArrayChild.
   *
   * @note the value of the "number" attribute of this ArrayChild is returned
   * in the argument array.
   */
  void getNumber(double* outArray) const;


  /**
   * Predicate returning @c true if this ArrayChild's "number" attribute is
   * set.
   *
   * @return @c true if this ArrayChild's "number" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetNumber() const;


  /**
   * Sets the value of the "number" attribute of this ArrayChild.
   *
   * @param inArray double* array value of the "number" attribute to be set.
   *
   * @param arrayLength int value for the length of the "number" attribute to
   * be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setNumber(double* inArray, int arrayLength);


  /**
   * Unsets the value of the "number" attribute of this ArrayChild.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetNumber();


  /**
   * Returns the value of the "unit" element of this ArrayChild.
   *
   * @return the value of the "unit" element of this ArrayChild as a Unit*.
   */
  const Unit* getUnit() const;


  /**
   * Returns the value of the "unit" element of this ArrayChild.
   *
   * @return the value of the "unit" element of this ArrayChild as a Unit*.
   */
  Unit* getUnit();


  /**
   * Predicate returning @c true if this ArrayChild's "unit" element is set.
   *
   * @return @c true if this ArrayChild's "unit" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetUnit() const;


  /**
   * Sets the value of the "unit" element of this ArrayChild.
   *
   * @param unit Unit* value of the "unit" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUnit(const Unit* unit);


  /**
   * Creates a new Unit object, adds it to this ArrayChild object and returns
   * the Unit object created.
   *
   * @return a new Unit object instance.
   */
  Unit* createUnit();


  /**
   * Unsets the value of the "unit" element of this ArrayChild.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUnit();


  /**
   * Returns the XML element name of this ArrayChild object.
   *
   * For ArrayChild, the XML element name is always @c "arrayChild".
   *
   * @return the name of this element, i.e. @c "arrayChild".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ArrayChild object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_TEST_ARRAYCHILD, SBMLTestTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * ArrayChild object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * ArrayChild have been set, otherwise @c false is returned.
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
   * used to write arrays
   */
  virtual void write(XMLOutputStream& stream) const;

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
   * Gets the value of the "attributeName" attribute of this ArrayChild.
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
   * Gets the value of the "attributeName" attribute of this ArrayChild.
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
   * Gets the value of the "attributeName" attribute of this ArrayChild.
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
   * Gets the value of the "attributeName" attribute of this ArrayChild.
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
   * Gets the value of the "attributeName" attribute of this ArrayChild.
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
   * Predicate returning @c true if this ArrayChild's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this ArrayChild's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ArrayChild.
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
   * Sets the value of the "attributeName" attribute of this ArrayChild.
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
   * Sets the value of the "attributeName" attribute of this ArrayChild.
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
   * Sets the value of the "attributeName" attribute of this ArrayChild.
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
   * Sets the value of the "attributeName" attribute of this ArrayChild.
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
   * Unsets the value of the "attributeName" attribute of this ArrayChild.
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
   * Creates and returns an new "elementName" object in this ArrayChild.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this ArrayChild.
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
   * ArrayChild.
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
   * Returns the number of "elementName" in this ArrayChild.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this ArrayChild.
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
   * Writes the array data as a text element
   */
  virtual void setElementText(const std::string& text);

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new ArrayChild_t using the given SBML Level, Version and
 * &ldquo;test&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this ArrayChild_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ArrayChild_t.
 *
 * @param pkgVersion an unsigned int, the SBML Test Version to assign to this
 * ArrayChild_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
ArrayChild_t *
ArrayChild_create(unsigned int level,
                  unsigned int version,
                  unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this ArrayChild_t object.
 *
 * @param ac the ArrayChild_t structure.
 *
 * @return a (deep) copy of this ArrayChild_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
ArrayChild_t*
ArrayChild_clone(const ArrayChild_t* ac);


/**
 * Frees this ArrayChild_t object.
 *
 * @param ac the ArrayChild_t structure.
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
void
ArrayChild_free(ArrayChild_t* ac);


/**
 * Predicate returning @c 1 (true) if this ArrayChild_t's "number" attribute is
 * set.
 *
 * @param ac the ArrayChild_t structure.
 *
 * @return @c 1 (true) if this ArrayChild_t's "number" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
int
ArrayChild_isSetNumber(const ArrayChild_t * ac);


/**
 * Sets the value of the "number" attribute of this ArrayChild_t.
 *
 * @param ac the ArrayChild_t structure.
 *
 * @param number pointer value of the "number" attribute to be set.
 *
 * @param arrayLength int value for the length of the "number" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
int
ArrayChild_setNumber(ArrayChild_t* ac, double* number, int arrayLength);


/**
 * Unsets the value of the "number" attribute of this ArrayChild_t.
 *
 * @param ac the ArrayChild_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
int
ArrayChild_unsetNumber(ArrayChild_t * ac);


/**
 * Returns the value of the "unit" element of this ArrayChild_t.
 *
 * @param ac the ArrayChild_t structure whose unit is sought.
 *
 * @return the value of the "unit" element of this ArrayChild_t as a Unit*.
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
const Unit_t*
ArrayChild_getUnit(const ArrayChild_t * ac);


/**
 * Predicate returning @c 1 (true) if this ArrayChild_t's "unit" element is
 * set.
 *
 * @param ac the ArrayChild_t structure.
 *
 * @return @c 1 (true) if this ArrayChild_t's "unit" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
int
ArrayChild_isSetUnit(const ArrayChild_t * ac);


/**
 * Sets the value of the "unit" element of this ArrayChild_t.
 *
 * @param ac the ArrayChild_t structure.
 *
 * @param unit Unit_t* value of the "unit" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
int
ArrayChild_setUnit(ArrayChild_t * ac, const Unit_t* unit);


/**
 * Creates a new Unit_t object, adds it to this ArrayChild_t object and returns
 * the Unit_t object created.
 *
 * @param ac the ArrayChild_t structure to which the Unit_t should be added.
 *
 * @return a new Unit_t object instance.
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
Unit_t*
ArrayChild_createUnit(ArrayChild_t* ac);


/**
 * Unsets the value of the "unit" element of this ArrayChild_t.
 *
 * @param ac the ArrayChild_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
int
ArrayChild_unsetUnit(ArrayChild_t * ac);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * ArrayChild_t object have been set.
 *
 * @param ac the ArrayChild_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * ArrayChild_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof ArrayChild_t
 */
LIBSBML_EXTERN
int
ArrayChild_hasRequiredAttributes(const ArrayChild_t * ac);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ArrayChild_H__ */


