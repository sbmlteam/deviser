/**
 * @file CategoricalDistribution.h
 * @brief Definition of the CategoricalDistribution class.
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
 * @class CategoricalDistribution
 * @sbmlbrief{distrib} TODO:Definition of the CategoricalDistribution class.
 */


#ifndef CategoricalDistribution_H__
#define CategoricalDistribution_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/distrib/sbml/CategoricalUnivariateDistribution.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/ListOfCategories.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN CategoricalDistribution : public
  CategoricalUnivariateDistribution
{
protected:

  /** @cond doxygenLibsbmlInternal */

  ListOfCategories mCategories;

  /** @endcond */

public:

  /**
   * Creates a new CategoricalDistribution using the given SBML Level, Version
   * and &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * CategoricalDistribution.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * CategoricalDistribution.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this CategoricalDistribution.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  CategoricalDistribution(
                          unsigned int level =
                            DistribExtension::getDefaultLevel(),
                          unsigned int version =
                            DistribExtension::getDefaultVersion(),
                          unsigned int pkgVersion =
                            DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new CategoricalDistribution using the given DistribPkgNamespaces
   * object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  CategoricalDistribution(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for CategoricalDistribution.
   *
   * @param orig the CategoricalDistribution instance to copy.
   */
  CategoricalDistribution(const CategoricalDistribution& orig);


  /**
   * Assignment operator for CategoricalDistribution.
   *
   * @param rhs the CategoricalDistribution object whose values are to be used
   * as the basis of the assignment.
   */
  CategoricalDistribution& operator=(const CategoricalDistribution& rhs);


  /**
   * Creates and returns a deep copy of this CategoricalDistribution object.
   *
   * @return a (deep) copy of this CategoricalDistribution object.
   */
  virtual CategoricalDistribution* clone() const;


  /**
   * Destructor for CategoricalDistribution.
   */
  virtual ~CategoricalDistribution();


  /**
   * Returns the ListOfCategories from this CategoricalDistribution.
   *
   * @return the ListOfCategories from this CategoricalDistribution.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCategory(const Category* object)
   * @see createCategory()
   * @see getCategory(const std::string& sid)
   * @see getCategory(unsigned int n)
   * @see getNumCategories()
   * @see removeCategory(const std::string& sid)
   * @see removeCategory(unsigned int n)
   */
  const ListOfCategories* getListOfCategories() const;


  /**
   * Returns the ListOfCategories from this CategoricalDistribution.
   *
   * @return the ListOfCategories from this CategoricalDistribution.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCategory(const Category* object)
   * @see createCategory()
   * @see getCategory(const std::string& sid)
   * @see getCategory(unsigned int n)
   * @see getNumCategories()
   * @see removeCategory(const std::string& sid)
   * @see removeCategory(unsigned int n)
   */
  ListOfCategories* getListOfCategories();


  /**
   * Get a Category from the CategoricalDistribution.
   *
   * @param n an unsigned int representing the index of the Category to
   * retrieve.
   *
   * @return the nth Category in the ListOfCategories within this
   * CategoricalDistribution.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCategory(const Category* object)
   * @see createCategory()
   * @see getCategory(const std::string& sid)
   * @see getNumCategories()
   * @see removeCategory(const std::string& sid)
   * @see removeCategory(unsigned int n)
   */
  Category* getCategory(unsigned int n);


  /**
   * Get a Category from the CategoricalDistribution.
   *
   * @param n an unsigned int representing the index of the Category to
   * retrieve.
   *
   * @return the nth Category in the ListOfCategories within this
   * CategoricalDistribution.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCategory(const Category* object)
   * @see createCategory()
   * @see getCategory(const std::string& sid)
   * @see getNumCategories()
   * @see removeCategory(const std::string& sid)
   * @see removeCategory(unsigned int n)
   */
  const Category* getCategory(unsigned int n) const;


  /**
   * Adds a copy of the given Category to this CategoricalDistribution.
   *
   * @param c the Category object to add.
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
   * @see createCategory()
   * @see getCategory(const std::string& sid)
   * @see getCategory(unsigned int n)
   * @see getNumCategories()
   * @see removeCategory(const std::string& sid)
   * @see removeCategory(unsigned int n)
   */
  int addCategory(const Category* c);


  /**
   * Get the number of Category objects in this CategoricalDistribution.
   *
   * @return the number of Category objects in this CategoricalDistribution.
   *
   *
   * @see addCategory(const Category* object)
   * @see createCategory()
   * @see getCategory(const std::string& sid)
   * @see getCategory(unsigned int n)
   * @see removeCategory(const std::string& sid)
   * @see removeCategory(unsigned int n)
   */
  unsigned int getNumCategories() const;


  /**
   * Creates a new Category object, adds it to this CategoricalDistribution
   * object and returns the Category object created.
   *
   * @return a new Category object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addCategory(const Category* object)
   * @see getCategory(const std::string& sid)
   * @see getCategory(unsigned int n)
   * @see getNumCategories()
   * @see removeCategory(const std::string& sid)
   * @see removeCategory(unsigned int n)
   */
  Category* createCategory();


  /**
   * Removes the nth Category from this CategoricalDistribution and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the Category to remove.
   *
   * @return a pointer to the nth Category in this CategoricalDistribution.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addCategory(const Category* object)
   * @see createCategory()
   * @see getCategory(const std::string& sid)
   * @see getCategory(unsigned int n)
   * @see getNumCategories()
   * @see removeCategory(const std::string& sid)
   */
  Category* removeCategory(unsigned int n);


  /**
   * Returns the XML element name of this CategoricalDistribution object.
   *
   * For CategoricalDistribution, the XML element name is always
   * @c "categoricalDistribution".
   *
   * @return the name of this element, i.e. @c "categoricalDistribution".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this CategoricalDistribution object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_DISTRIB_CATEGORICALDISTRIBUTION, SBMLDistribTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * CategoricalDistribution object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * CategoricalDistribution have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * CategoricalDistribution object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * CategoricalDistribution have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the CategoricalDistribution object are:
   * @li "category"
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
   * Gets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Gets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Gets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Gets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Gets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Gets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Predicate returning @c true if this CategoricalDistribution's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this CategoricalDistribution's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Sets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Sets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Sets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Sets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Sets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Unsets the value of the "attributeName" attribute of this
   * CategoricalDistribution.
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
   * Creates and returns an new "elementName" object in this
   * CategoricalDistribution.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this CategoricalDistribution.
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
   * CategoricalDistribution.
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
   * Returns the number of "elementName" in this CategoricalDistribution.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this CategoricalDistribution.
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


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new CategoricalDistribution_t using the given SBML Level, Version
 * and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * CategoricalDistribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * CategoricalDistribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this CategoricalDistribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
CategoricalDistribution_t *
CategoricalDistribution_create(unsigned int level,
                               unsigned int version,
                               unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this CategoricalDistribution_t object.
 *
 * @param cd the CategoricalDistribution_t structure.
 *
 * @return a (deep) copy of this CategoricalDistribution_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
CategoricalDistribution_t*
CategoricalDistribution_clone(const CategoricalDistribution_t* cd);


/**
 * Frees this CategoricalDistribution_t object.
 *
 * @param cd the CategoricalDistribution_t structure.
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
void
CategoricalDistribution_free(CategoricalDistribution_t* cd);


/**
 * Returns a ListOf_t * containing Category_t objects from this
 * CategoricalDistribution_t.
 *
 * @param cd the CategoricalDistribution_t structure whose ListOfCategories is
 * sought.
 *
 * @return the ListOfCategories from this CategoricalDistribution_t as a
 * ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see CategoricalDistribution_addCategory(const Category_t* object)
 * @see CategoricalDistribution_createCategory()
 * @see CategoricalDistribution_getCategoryById(const std::string& sid)
 * @see CategoricalDistribution_getCategory(unsigned int n)
 * @see CategoricalDistribution_getNumCategories()
 * @see CategoricalDistribution_removeCategoryById(const std::string& sid)
 * @see CategoricalDistribution_removeCategory(unsigned int n)
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
ListOf_t*
CategoricalDistribution_getListOfCategories(CategoricalDistribution_t* cd);


/**
 * Get a Category_t from the CategoricalDistribution_t.
 *
 * @param cd the CategoricalDistribution_t structure to search.
 *
 * @param n an unsigned int representing the index of the Category_t to
 * retrieve.
 *
 * @return the nth Category_t in the ListOfCategories within this
 * CategoricalDistribution.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
Category_t*
CategoricalDistribution_getCategory(CategoricalDistribution_t* cd,
                                    unsigned int n);


/**
 * Adds a copy of the given Category_t to this CategoricalDistribution_t.
 *
 * @param cd the CategoricalDistribution_t structure to which the Category_t
 * should be added.
 *
 * @param c the Category_t object to add.
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
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
int
CategoricalDistribution_addCategory(CategoricalDistribution_t* cd,
                                    const Category_t* c);


/**
 * Get the number of Category_t objects in this CategoricalDistribution_t.
 *
 * @param cd the CategoricalDistribution_t structure to query.
 *
 * @return the number of Category_t objects in this CategoricalDistribution_t.
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
unsigned int
CategoricalDistribution_getNumCategories(CategoricalDistribution_t* cd);


/**
 * Creates a new Category_t object, adds it to this CategoricalDistribution_t
 * object and returns the Category_t object created.
 *
 * @param cd the CategoricalDistribution_t structure to which the Category_t
 * should be added.
 *
 * @return a new Category_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
Category_t*
CategoricalDistribution_createCategory(CategoricalDistribution_t* cd);


/**
 * Removes the nth Category_t from this CategoricalDistribution_t and returns a
 * pointer to it.
 *
 * @param cd the CategoricalDistribution_t structure to search.
 *
 * @param n an unsigned int representing the index of the Category_t to remove.
 *
 * @return a pointer to the nth Category_t in this CategoricalDistribution_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
Category_t*
CategoricalDistribution_removeCategory(CategoricalDistribution_t* cd,
                                       unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * CategoricalDistribution_t object have been set.
 *
 * @param cd the CategoricalDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * CategoricalDistribution_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
int
CategoricalDistribution_hasRequiredAttributes(const CategoricalDistribution_t *
  cd);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * CategoricalDistribution_t object have been set.
 *
 * @param cd the CategoricalDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * CategoricalDistribution_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the CategoricalDistribution_t object are:
 * @li "category"
 *
 * @memberof CategoricalDistribution_t
 */
LIBSBML_EXTERN
int
CategoricalDistribution_hasRequiredElements(const CategoricalDistribution_t *
  cd);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !CategoricalDistribution_H__ */


