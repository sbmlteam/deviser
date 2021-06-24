/**
 * @file ContainerY.h
 * @brief Definition of the ContainerY class.
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
 * @class ContainerY
 * @sbmlbrief{x} TODO:Definition of the ContainerY class.
 */


#ifndef ContainerY_H__
#define ContainerY_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/x/common/xfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/x/extension/XExtension.h>
#include <sbml/packages/x/sbml/ListOfFreds.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ContainerY : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  ListOfFreds mFreds;

  /** @endcond */

public:

  /**
   * Creates a new ContainerY using the given SBML Level, Version and
   * &ldquo;x&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this ContainerY.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ContainerY.
   *
   * @param pkgVersion an unsigned int, the SBML X Version to assign to this
   * ContainerY.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ContainerY(unsigned int level = XExtension::getDefaultLevel(),
             unsigned int version = XExtension::getDefaultVersion(),
             unsigned int pkgVersion = XExtension::getDefaultPackageVersion());


  /**
   * Creates a new ContainerY using the given XPkgNamespaces object.
   *
   * @param xns the XPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  ContainerY(XPkgNamespaces *xns);


  /**
   * Copy constructor for ContainerY.
   *
   * @param orig the ContainerY instance to copy.
   */
  ContainerY(const ContainerY& orig);


  /**
   * Assignment operator for ContainerY.
   *
   * @param rhs the ContainerY object whose values are to be used as the basis
   * of the assignment.
   */
  ContainerY& operator=(const ContainerY& rhs);


  /**
   * Creates and returns a deep copy of this ContainerY object.
   *
   * @return a (deep) copy of this ContainerY object.
   */
  virtual ContainerY* clone() const;


  /**
   * Destructor for ContainerY.
   */
  virtual ~ContainerY();


  /**
   * Returns the ListOfFreds from this ContainerY.
   *
   * @return the ListOfFreds from this ContainerY.
   */
  const ListOfFreds* getListOfFreds() const;


  /**
   * Returns the ListOfFreds from this ContainerY.
   *
   * @return the ListOfFreds from this ContainerY.
   */
  ListOfFreds* getListOfFreds();


  /**
   * Get a Fred from the ContainerY.
   *
   * @param n an unsigned int representing the index of the Fred to retrieve.
   *
   * @return the nth Fred in the ListOfFreds within this ContainerY.
   *
   * @see getNumFreds()
   */
  Fred* getFred(unsigned int n);


  /**
   * Get a Fred from the ContainerY.
   *
   * @param n an unsigned int representing the index of the Fred to retrieve.
   *
   * @return the nth Fred in the ListOfFreds within this ContainerY.
   *
   * @see getNumFreds()
   */
  const Fred* getFred(unsigned int n) const;


  /**
   * Get a Fred from the ContainerY based on its identifier.
   *
   * @param sid a string representing the identifier of the Fred to retrieve.
   *
   * @return the Fred in the ListOfFreds within this ContainerY with the given
   * id or NULL if no such Fred exists.
   *
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   */
  Fred* getFred(const std::string& sid);


  /**
   * Get a Fred from the ContainerY based on its identifier.
   *
   * @param sid a string representing the identifier of the Fred to retrieve.
   *
   * @return the Fred in the ListOfFreds within this ContainerY with the given
   * id or NULL if no such Fred exists.
   *
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   */
  const Fred* getFred(const std::string& sid) const;


  /**
   * Adds a copy of the given Fred to this ContainerY.
   *
   * @param f the Fred object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createFred()
   */
  int addFred(const Fred* f);


  /**
   * Get the number of Fred objects in this ContainerY.
   *
   * @return the number of Fred objects in this ContainerY.
   */
  unsigned int getNumFreds() const;


  /**
   * Creates a new Fred object, adds it to this ContainerY object and returns
   * the Fred object created.
   *
   * @return a new Fred object instance.
   *
   * @see addFred(const Fred* f)
   */
  Fred* createFred();


  /**
   * Removes the nth Fred from this ContainerY and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Fred to remove.
   *
   * @return a pointer to the nth Fred in this ContainerY.
   *
   * @see getNumFreds
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Fred* removeFred(unsigned int n);


  /**
   * Removes the Fred from this ContainerY based on its identifier and returns
   * a pointer to it.
   *
   * @param sid a string representing the identifier of the Fred to remove.
   *
   * @return the Fred in this ContainerY based on the identifier or NULL if no
   * such Fred exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Fred* removeFred(const std::string& sid);


  /**
   * Returns the XML element name of this ContainerY object.
   *
   * For ContainerY, the XML element name is always @c "containerY".
   *
   * @return the name of this element, i.e. @c "containerY".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ContainerY object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_X_CONTAINERX, SBMLXTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * ContainerY object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * ContainerY have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the ContainerY object are:
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




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this ContainerY.
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
   * Gets the value of the "attributeName" attribute of this ContainerY.
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
   * Gets the value of the "attributeName" attribute of this ContainerY.
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
   * Gets the value of the "attributeName" attribute of this ContainerY.
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
   * Gets the value of the "attributeName" attribute of this ContainerY.
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
   * Gets the value of the "attributeName" attribute of this ContainerY.
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
                           const char* value) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate returning @c true if this ContainerY's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this ContainerY's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ContainerY.
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
   * Sets the value of the "attributeName" attribute of this ContainerY.
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
   * Sets the value of the "attributeName" attribute of this ContainerY.
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
   * Sets the value of the "attributeName" attribute of this ContainerY.
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
   * Sets the value of the "attributeName" attribute of this ContainerY.
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
   * Sets the value of the "attributeName" attribute of this ContainerY.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, const char*
    value);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this ContainerY.
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
   * Creates and returns an new "elementName" object in this ContainerY.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this ContainerY.
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
   * ContainerY.
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
   * Returns the number of "elementName" in this ContainerY.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this ContainerY.
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
 * Creates a new ContainerY_t using the given SBML Level, Version and
 * &ldquo;x&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this ContainerY_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ContainerY_t.
 *
 * @param pkgVersion an unsigned int, the SBML X Version to assign to this
 * ContainerY_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
ContainerY_t *
ContainerY_create(unsigned int level = XExtension::getDefaultLevel(),
                  unsigned int version = XExtension::getDefaultVersion(),
                  unsigned int pkgVersion =
                    XExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this ContainerY_t object.
 *
 * @param cy the ContainerY_t structure.
 *
 * @return a (deep) copy of this ContainerY_t object.
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
ContainerY_t*
ContainerY_clone(const ContainerY_t* cy);


/**
 * Frees this ContainerY_t object.
 *
 * @param cy the ContainerY_t structure.
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
void
ContainerY_free(ContainerY_t* cy);


/**
 * Returns a ListOf_t* containing Fred_t objects from this ContainerY_t.
 *
 * @param cy the ContainerY_t structure whose "ListOfFreds" is sought.
 *
 * @return the "ListOfFreds" from this ContainerY_t as a ListOf_t *.
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
ListOf_t*
ContainerY_getListOfFreds(ContainerY_t* cy);


/**
 * Get a Fred_t from the ContainerY_t.
 *
 * @param cy the ContainerY_t structure to search.
 *
 * @param n an unsigned int representing the index of the Fred_t to retrieve.
 *
 * @return the nth Fred_t in the ListOfFreds within this ContainerY.
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
const Fred_t*
ContainerY_getFred(ContainerY_t* cy, unsigned int n);


/**
 * Get a Fred_t from the ContainerY_t based on its identifier.
 *
 * @param cy the ContainerY_t structure to search.
 *
 * @param sid a string representing the identifier of the Fred_t to retrieve.
 *
 * @return the Fred_t in the ListOfFreds within this ContainerY with the given
 * id or NULL if no such Fred_t exists.
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
const Fred_t*
ContainerY_getFredById(ContainerY_t* cy, const char *sid);


/**
 * Adds a copy of the given Fred_t to this ContainerY_t.
 *
 * @param cy the ContainerY_t structure to which the Fred_t should be added.
 *
 * @param f the Fred_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
int
ContainerY_addFred(ContainerY_t* cy, const Fred_t* f);


/**
 * Get the number of Fred_t objects in this ContainerY_t.
 *
 * @param cy the ContainerY_t structure to query.
 *
 * @return the number of Fred_t objects in this ContainerY_t.
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
unsigned int
ContainerY_getNumFreds(ContainerY_t* cy);


/**
 * Creates a new Fred_t object, adds it to this ContainerY_t object and returns
 * the Fred_t object created.
 *
 * @param cy the ContainerY_t structure to which the Fred_t should be added.
 *
 * @return a new Fred_t object instance.
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
Fred_t*
ContainerY_createFred(ContainerY_t* cy);


/**
 * Removes the nth Fred_t from this ContainerY_t and returns a pointer to it.
 *
 * @param cy the ContainerY_t structure to search.
 *
 * @param n an unsigned int representing the index of the Fred_t to remove.
 *
 * @return a pointer to the nth Fred_t in this ContainerY_t.
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
Fred_t*
ContainerY_removeFred(ContainerY_t* cy, unsigned int n);


/**
 * Removes the Fred_t from this ContainerY_t based on its identifier and
 * returns a pointer to it.
 *
 * @param cy the ContainerY_t structure to search.
 *
 * @param sid a string representing the identifier of the Fred_t to remove.
 *
 * @return the Fred_t in this ContainerY_t based on the identifier or NULL if
 * no such Fred_t exists.
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
Fred_t*
ContainerY_removeFredById(ContainerY_t* cy, const char* sid);


/**
 * Predicate returning @c 1 if all the required elements for this ContainerY_t
 * object have been set.
 *
 * @param cy the ContainerY_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this ContainerY_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the ContainerY_t object are:
 *
 * @memberof ContainerY_t
 */
LIBSBML_EXTERN
int
ContainerY_hasRequiredElements(const ContainerY_t * cy);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ContainerY_H__ */


