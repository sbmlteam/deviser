/**
 * @file Parent.h
 * @brief Definition of the Parent class.
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
 * @class Parent
 * @sbmlbrief{nasty} TODO:Definition of the Parent class.
 */


#ifndef Parent_H__
#define Parent_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/nasty/common/nastyfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/nasty/extension/NastyExtension.h>
#include <sbml/packages/nasty/sbml/ListOfChildren.h>
#include <sbml/packages/nasty/sbml/ListOfSprogs.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Parent : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  ListOfChildren mChildren;
  ListOfSprogs mSprogs;

  /** @endcond */

public:

  /**
   * Creates a new Parent using the given SBML Level, Version and
   * &ldquo;nasty&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Parent.
   *
   * @param version an unsigned int, the SBML Version to assign to this Parent.
   *
   * @param pkgVersion an unsigned int, the SBML Nasty Version to assign to
   * this Parent.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Parent(unsigned int level = NastyExtension::getDefaultLevel(),
         unsigned int version = NastyExtension::getDefaultVersion(),
         unsigned int pkgVersion = NastyExtension::getDefaultPackageVersion());


  /**
   * Creates a new Parent using the given NastyPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param nastyns the NastyPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Parent(NastyPkgNamespaces *nastyns);


  /**
   * Copy constructor for Parent.
   *
   * @param orig the Parent instance to copy.
   */
  Parent(const Parent& orig);


  /**
   * Assignment operator for Parent.
   *
   * @param rhs the Parent object whose values are to be used as the basis of
   * the assignment.
   */
  Parent& operator=(const Parent& rhs);


  /**
   * Creates and returns a deep copy of this Parent object.
   *
   * @return a (deep) copy of this Parent object.
   */
  virtual Parent* clone() const;


  /**
   * Destructor for Parent.
   */
  virtual ~Parent();


  /**
   * Returns the ListOfChildren from this Parent.
   *
   * @return the ListOfChildren from this Parent.
   */
  const ListOfChildren* getListOfChildren() const;


  /**
   * Returns the ListOfChildren from this Parent.
   *
   * @return the ListOfChildren from this Parent.
   */
  ListOfChildren* getListOfChildren();


  /**
   * Get a Child from the Parent.
   *
   * @param n an unsigned int representing the index of the Child to retrieve.
   *
   * @return the nth Child in the ListOfChildren within this Parent.
   *
   * @see getNumChildren()
   */
  Child* getChild(unsigned int n);


  /**
   * Get a Child from the Parent.
   *
   * @param n an unsigned int representing the index of the Child to retrieve.
   *
   * @return the nth Child in the ListOfChildren within this Parent.
   *
   * @see getNumChildren()
   */
  const Child* getChild(unsigned int n) const;


  /**
   * Adds a copy of the given Child to this Parent.
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
   * Get the number of Child objects in this Parent.
   *
   * @return the number of Child objects in this Parent.
   */
  unsigned int getNumChildren() const;


  /**
   * Creates a new Child object, adds it to this Parent object and returns the
   * Child object created.
   *
   * @return a new Child object instance.
   *
   * @see addChild(const Child* c)
   */
  Child* createChild();


  /**
   * Removes the nth Child from this Parent and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Child to remove.
   *
   * @return a pointer to the nth Child in this Parent.
   *
   * @see getNumChildren
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Child* removeChild(unsigned int n);


  /**
   * Returns the ListOfSprogs from this Parent.
   *
   * @return the ListOfSprogs from this Parent.
   */
  const ListOfSprogs* getListOfSprogs() const;


  /**
   * Returns the ListOfSprogs from this Parent.
   *
   * @return the ListOfSprogs from this Parent.
   */
  ListOfSprogs* getListOfSprogs();


  /**
   * Get a Sprog from the Parent.
   *
   * @param n an unsigned int representing the index of the Sprog to retrieve.
   *
   * @return the nth Sprog in the ListOfSprogs within this Parent.
   *
   * @see getNumSprogs()
   */
  Sprog* getSprog(unsigned int n);


  /**
   * Get a Sprog from the Parent.
   *
   * @param n an unsigned int representing the index of the Sprog to retrieve.
   *
   * @return the nth Sprog in the ListOfSprogs within this Parent.
   *
   * @see getNumSprogs()
   */
  const Sprog* getSprog(unsigned int n) const;


  /**
   * Adds a copy of the given Sprog to this Parent.
   *
   * @param s the Sprog object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createSprog()
   */
  int addSprog(const Sprog* s);


  /**
   * Get the number of Sprog objects in this Parent.
   *
   * @return the number of Sprog objects in this Parent.
   */
  unsigned int getNumSprogs() const;


  /**
   * Creates a new Sprog object, adds it to this Parent object and returns the
   * Sprog object created.
   *
   * @return a new Sprog object instance.
   *
   * @see addSprog(const Sprog* s)
   */
  Sprog* createSprog();


  /**
   * Removes the nth Sprog from this Parent and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Sprog to remove.
   *
   * @return a pointer to the nth Sprog in this Parent.
   *
   * @see getNumSprogs
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  Sprog* removeSprog(unsigned int n);


  /**
   * Returns the XML element name of this Parent object.
   *
   * For Parent, the XML element name is always @c "parent".
   *
   * @return the name of this element, i.e. @c "parent".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Parent object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_NASTY_PARENT, SBMLNastyTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required elements for this Parent
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this Parent
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Parent object are:
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
   * Gets the value of the "attributeName" attribute of this Parent.
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
   * Gets the value of the "attributeName" attribute of this Parent.
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
   * Gets the value of the "attributeName" attribute of this Parent.
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
   * Gets the value of the "attributeName" attribute of this Parent.
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
   * Gets the value of the "attributeName" attribute of this Parent.
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
   * Gets the value of the "attributeName" attribute of this Parent.
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
   * Predicate returning @c true if this Parent's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Parent's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Parent.
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
   * Sets the value of the "attributeName" attribute of this Parent.
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
   * Sets the value of the "attributeName" attribute of this Parent.
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
   * Sets the value of the "attributeName" attribute of this Parent.
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
   * Sets the value of the "attributeName" attribute of this Parent.
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
   * Sets the value of the "attributeName" attribute of this Parent.
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
   * Unsets the value of the "attributeName" attribute of this Parent.
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
   * Creates and returns an new "elementName" object in this Parent.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this Parent.
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
   * Parent.
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
   * Returns the number of "elementName" in this Parent.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this Parent.
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
 * Creates a new Parent_t using the given SBML Level, Version and
 * &ldquo;nasty&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Parent_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this Parent_t.
 *
 * @param pkgVersion an unsigned int, the SBML Nasty Version to assign to this
 * Parent_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
Parent_t *
Parent_create(unsigned int level,
              unsigned int version,
              unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Parent_t object.
 *
 * @param p the Parent_t structure.
 *
 * @return a (deep) copy of this Parent_t object.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
Parent_t*
Parent_clone(const Parent_t* p);


/**
 * Frees this Parent_t object.
 *
 * @param p the Parent_t structure.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
void
Parent_free(Parent_t* p);


/**
 * Returns a ListOf_t* containing Child_t objects from this Parent_t.
 *
 * @param p the Parent_t structure whose "ListOfChildren" is sought.
 *
 * @return the "ListOfChildren" from this Parent_t as a ListOf_t *.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
ListOf_t*
Parent_getListOfChildren(Parent_t* p);


/**
 * Get a Child_t from the Parent_t.
 *
 * @param p the Parent_t structure to search.
 *
 * @param n an unsigned int representing the index of the Child_t to retrieve.
 *
 * @return the nth Child_t in the ListOfChildren within this Parent.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
Child_t*
Parent_getChild(Parent_t* p, unsigned int n);


/**
 * Adds a copy of the given Child_t to this Parent_t.
 *
 * @param p the Parent_t structure to which the Child_t should be added.
 *
 * @param c the Child_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
int
Parent_addChild(Parent_t* p, const Child_t* c);


/**
 * Get the number of Child_t objects in this Parent_t.
 *
 * @param p the Parent_t structure to query.
 *
 * @return the number of Child_t objects in this Parent_t.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
unsigned int
Parent_getNumChildren(Parent_t* p);


/**
 * Creates a new Child_t object, adds it to this Parent_t object and returns
 * the Child_t object created.
 *
 * @param p the Parent_t structure to which the Child_t should be added.
 *
 * @return a new Child_t object instance.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
Child_t*
Parent_createChild(Parent_t* p);


/**
 * Removes the nth Child_t from this Parent_t and returns a pointer to it.
 *
 * @param p the Parent_t structure to search.
 *
 * @param n an unsigned int representing the index of the Child_t to remove.
 *
 * @return a pointer to the nth Child_t in this Parent_t.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
Child_t*
Parent_removeChild(Parent_t* p, unsigned int n);


/**
 * Returns a ListOf_t* containing Sprog_t objects from this Parent_t.
 *
 * @param p the Parent_t structure whose "ListOfSprogs" is sought.
 *
 * @return the "ListOfSprogs" from this Parent_t as a ListOf_t *.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
ListOf_t*
Parent_getListOfSprogs(Parent_t* p);


/**
 * Get a Sprog_t from the Parent_t.
 *
 * @param p the Parent_t structure to search.
 *
 * @param n an unsigned int representing the index of the Sprog_t to retrieve.
 *
 * @return the nth Sprog_t in the ListOfSprogs within this Parent.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
Sprog_t*
Parent_getSprog(Parent_t* p, unsigned int n);


/**
 * Adds a copy of the given Sprog_t to this Parent_t.
 *
 * @param p the Parent_t structure to which the Sprog_t should be added.
 *
 * @param s the Sprog_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
int
Parent_addSprog(Parent_t* p, const Sprog_t* s);


/**
 * Get the number of Sprog_t objects in this Parent_t.
 *
 * @param p the Parent_t structure to query.
 *
 * @return the number of Sprog_t objects in this Parent_t.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
unsigned int
Parent_getNumSprogs(Parent_t* p);


/**
 * Creates a new Sprog_t object, adds it to this Parent_t object and returns
 * the Sprog_t object created.
 *
 * @param p the Parent_t structure to which the Sprog_t should be added.
 *
 * @return a new Sprog_t object instance.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
Sprog_t*
Parent_createSprog(Parent_t* p);


/**
 * Removes the nth Sprog_t from this Parent_t and returns a pointer to it.
 *
 * @param p the Parent_t structure to search.
 *
 * @param n an unsigned int representing the index of the Sprog_t to remove.
 *
 * @return a pointer to the nth Sprog_t in this Parent_t.
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
Sprog_t*
Parent_removeSprog(Parent_t* p, unsigned int n);


/**
 * Predicate returning @c 1 if all the required elements for this Parent_t
 * object have been set.
 *
 * @param p the Parent_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this Parent_t
 * have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the Parent_t object are:
 *
 * @memberof Parent_t
 */
LIBSBML_EXTERN
int
Parent_hasRequiredElements(const Parent_t * p);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Parent_H__ */


