/**
 * @file ContainerX.h
 * @brief Definition of the ContainerX class.
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
 * @class ContainerX
 * @sbmlbrief{x} TODO:Definition of the ContainerX class.
 */


#ifndef ContainerX_H__
#define ContainerX_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/x/common/xfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/x/extension/XExtension.h>
#include <sbml/packages/x/sbml/ListOfFreds.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN ContainerX : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  ListOfFreds mFreds;

  /** @endcond */

public:

  /**
   * Creates a new ContainerX using the given SBML Level, Version and
   * &ldquo;x&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this ContainerX.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * ContainerX.
   *
   * @param pkgVersion an unsigned int, the SBML X Version to assign to this
   * ContainerX.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ContainerX(unsigned int level = XExtension::getDefaultLevel(),
             unsigned int version = XExtension::getDefaultVersion(),
             unsigned int pkgVersion = XExtension::getDefaultPackageVersion());


  /**
   * Creates a new ContainerX using the given XPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param xns the XPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  ContainerX(XPkgNamespaces *xns);


  /**
   * Copy constructor for ContainerX.
   *
   * @param orig the ContainerX instance to copy.
   */
  ContainerX(const ContainerX& orig);


  /**
   * Assignment operator for ContainerX.
   *
   * @param rhs the ContainerX object whose values are to be used as the basis
   * of the assignment.
   */
  ContainerX& operator=(const ContainerX& rhs);


  /**
   * Creates and returns a deep copy of this ContainerX object.
   *
   * @return a (deep) copy of this ContainerX object.
   */
  virtual ContainerX* clone() const;


  /**
   * Destructor for ContainerX.
   */
  virtual ~ContainerX();


  /**
   * Returns the ListOfFreds from this ContainerX.
   *
   * @return the ListOfFreds from this ContainerX.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFred(const Fred* object)
   * @see createFred()
   * @see getFred(const std::string& sid)
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   * @see removeFred(const std::string& sid)
   * @see removeFred(unsigned int n)
   */
  const ListOfFreds* getListOfFreds() const;


  /**
   * Returns the ListOfFreds from this ContainerX.
   *
   * @return the ListOfFreds from this ContainerX.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFred(const Fred* object)
   * @see createFred()
   * @see getFred(const std::string& sid)
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   * @see removeFred(const std::string& sid)
   * @see removeFred(unsigned int n)
   */
  ListOfFreds* getListOfFreds();


  /**
   * Get a Fred from the ContainerX.
   *
   * @param n an unsigned int representing the index of the Fred to retrieve.
   *
   * @return the nth Fred in the ListOfFreds within this ContainerX.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFred(const Fred* object)
   * @see createFred()
   * @see getFred(const std::string& sid)
   * @see getNumFreds()
   * @see removeFred(const std::string& sid)
   * @see removeFred(unsigned int n)
   */
  Fred* getFred(unsigned int n);


  /**
   * Get a Fred from the ContainerX.
   *
   * @param n an unsigned int representing the index of the Fred to retrieve.
   *
   * @return the nth Fred in the ListOfFreds within this ContainerX.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFred(const Fred* object)
   * @see createFred()
   * @see getFred(const std::string& sid)
   * @see getNumFreds()
   * @see removeFred(const std::string& sid)
   * @see removeFred(unsigned int n)
   */
  const Fred* getFred(unsigned int n) const;


  /**
   * Get a Fred from the ContainerX based on its identifier.
   *
   * @param sid a string representing the identifier of the Fred to retrieve.
   *
   * @return the Fred in the ListOfFreds within this ContainerX with the given
   * @p sid or @c NULL if no such Fred exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFred(const Fred* object)
   * @see createFred()
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   * @see removeFred(const std::string& sid)
   * @see removeFred(unsigned int n)
   */
  Fred* getFred(const std::string& sid);


  /**
   * Get a Fred from the ContainerX based on its identifier.
   *
   * @param sid a string representing the identifier of the Fred to retrieve.
   *
   * @return the Fred in the ListOfFreds within this ContainerX with the given
   * @p sid or @c NULL if no such Fred exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFred(const Fred* object)
   * @see createFred()
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   * @see removeFred(const std::string& sid)
   * @see removeFred(unsigned int n)
   */
  const Fred* getFred(const std::string& sid) const;


  /**
   * Adds a copy of the given Fred to this ContainerX.
   *
   * @param f the Fred object to add.
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
   * @see createFred()
   * @see getFred(const std::string& sid)
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   * @see removeFred(const std::string& sid)
   * @see removeFred(unsigned int n)
   */
  int addFred(const Fred* f);


  /**
   * Get the number of Fred objects in this ContainerX.
   *
   * @return the number of Fred objects in this ContainerX.
   *
   *
   * @see addFred(const Fred* object)
   * @see createFred()
   * @see getFred(const std::string& sid)
   * @see getFred(unsigned int n)
   * @see removeFred(const std::string& sid)
   * @see removeFred(unsigned int n)
   */
  unsigned int getNumFreds() const;


  /**
   * Creates a new Fred object, adds it to this ContainerX object and returns
   * the Fred object created.
   *
   * @return a new Fred object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFred(const Fred* object)
   * @see getFred(const std::string& sid)
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   * @see removeFred(const std::string& sid)
   * @see removeFred(unsigned int n)
   */
  Fred* createFred();


  /**
   * Removes the nth Fred from this ContainerX and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Fred to remove.
   *
   * @return a pointer to the nth Fred in this ContainerX.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addFred(const Fred* object)
   * @see createFred()
   * @see getFred(const std::string& sid)
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   * @see removeFred(const std::string& sid)
   */
  Fred* removeFred(unsigned int n);


  /**
   * Removes the Fred from this ContainerX based on its identifier and returns
   * a pointer to it.
   *
   * @param sid a string representing the identifier of the Fred to remove.
   *
   * @return the Fred in this ContainerX based on the identifier or NULL if no
   * such Fred exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addFred(const Fred* object)
   * @see createFred()
   * @see getFred(const std::string& sid)
   * @see getFred(unsigned int n)
   * @see getNumFreds()
   * @see removeFred(unsigned int n)
   */
  Fred* removeFred(const std::string& sid);


  /**
   * Returns the XML element name of this ContainerX object.
   *
   * For ContainerX, the XML element name is always @c "containerX".
   *
   * @return the name of this element, i.e. @c "containerX".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this ContainerX object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_X_CONTAINERX, SBMLXTypeCode_t}.
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




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this ContainerX.
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
   * Gets the value of the "attributeName" attribute of this ContainerX.
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
   * Gets the value of the "attributeName" attribute of this ContainerX.
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
   * Gets the value of the "attributeName" attribute of this ContainerX.
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
   * Gets the value of the "attributeName" attribute of this ContainerX.
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
   * Gets the value of the "attributeName" attribute of this ContainerX.
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
   * Predicate returning @c true if this ContainerX's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this ContainerX's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this ContainerX.
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
   * Sets the value of the "attributeName" attribute of this ContainerX.
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
   * Sets the value of the "attributeName" attribute of this ContainerX.
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
   * Sets the value of the "attributeName" attribute of this ContainerX.
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
   * Sets the value of the "attributeName" attribute of this ContainerX.
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
   * Sets the value of the "attributeName" attribute of this ContainerX.
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
   * Unsets the value of the "attributeName" attribute of this ContainerX.
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
   * Creates and returns an new "elementName" object in this ContainerX.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this ContainerX.
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
   * ContainerX.
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
   * Returns the number of "elementName" in this ContainerX.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this ContainerX.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int teh index of teh object to retrieve.
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
 * Creates a new ContainerX_t using the given SBML Level, Version and
 * &ldquo;x&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this ContainerX_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * ContainerX_t.
 *
 * @param pkgVersion an unsigned int, the SBML X Version to assign to this
 * ContainerX_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
ContainerX_t *
ContainerX_create(unsigned int level,
                  unsigned int version,
                  unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this ContainerX_t object.
 *
 * @param cx the ContainerX_t structure.
 *
 * @return a (deep) copy of this ContainerX_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
ContainerX_t*
ContainerX_clone(const ContainerX_t* cx);


/**
 * Frees this ContainerX_t object.
 *
 * @param cx the ContainerX_t structure.
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
void
ContainerX_free(ContainerX_t* cx);


/**
 * Returns a ListOf_t * containing Fred_t objects from this ContainerX_t.
 *
 * @param cx the ContainerX_t structure whose ListOfFreds is sought.
 *
 * @return the ListOfFreds from this ContainerX_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see ContainerX_addFred()
 * @see ContainerX_createFred()
 * @see ContainerX_getFredById()
 * @see ContainerX_getFred()
 * @see ContainerX_getNumFreds()
 * @see ContainerX_removeFredById()
 * @see ContainerX_removeFred()
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
ListOf_t*
ContainerX_getListOfFreds(ContainerX_t* cx);


/**
 * Get a Fred_t from the ContainerX_t.
 *
 * @param cx the ContainerX_t structure to search.
 *
 * @param n an unsigned int representing the index of the Fred_t to retrieve.
 *
 * @return the nth Fred_t in the ListOfFreds within this ContainerX.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
Fred_t*
ContainerX_getFred(ContainerX_t* cx, unsigned int n);


/**
 * Get a Fred_t from the ContainerX_t based on its identifier.
 *
 * @param cx the ContainerX_t structure to search.
 *
 * @param sid a string representing the identifier of the Fred_t to retrieve.
 *
 * @return the Fred_t in the ListOfFreds within this ContainerX with the given
 * @p sid or @c NULL if no such Fred_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
Fred_t*
ContainerX_getFredById(ContainerX_t* cx, const char *sid);


/**
 * Adds a copy of the given Fred_t to this ContainerX_t.
 *
 * @param cx the ContainerX_t structure to which the Fred_t should be added.
 *
 * @param f the Fred_t object to add.
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
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
int
ContainerX_addFred(ContainerX_t* cx, const Fred_t* f);


/**
 * Get the number of Fred_t objects in this ContainerX_t.
 *
 * @param cx the ContainerX_t structure to query.
 *
 * @return the number of Fred_t objects in this ContainerX_t.
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
unsigned int
ContainerX_getNumFreds(ContainerX_t* cx);


/**
 * Creates a new Fred_t object, adds it to this ContainerX_t object and returns
 * the Fred_t object created.
 *
 * @param cx the ContainerX_t structure to which the Fred_t should be added.
 *
 * @return a new Fred_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
Fred_t*
ContainerX_createFred(ContainerX_t* cx);


/**
 * Removes the nth Fred_t from this ContainerX_t and returns a pointer to it.
 *
 * @param cx the ContainerX_t structure to search.
 *
 * @param n an unsigned int representing the index of the Fred_t to remove.
 *
 * @return a pointer to the nth Fred_t in this ContainerX_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
Fred_t*
ContainerX_removeFred(ContainerX_t* cx, unsigned int n);


/**
 * Removes the Fred_t from this ContainerX_t based on its identifier and
 * returns a pointer to it.
 *
 * @param cx the ContainerX_t structure to search.
 *
 * @param sid a string representing the identifier of the Fred_t to remove.
 *
 * @return the Fred_t in this ContainerX_t based on the identifier or NULL if
 * no such Fred_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof ContainerX_t
 */
LIBSBML_EXTERN
Fred_t*
ContainerX_removeFredById(ContainerX_t* cx, const char* sid);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !ContainerX_H__ */


