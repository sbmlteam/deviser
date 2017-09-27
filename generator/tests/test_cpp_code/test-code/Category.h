/**
 * @file Category.h
 * @brief Definition of the Category class.
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
 * @class Category
 * @sbmlbrief{distrib} TODO:Definition of the Category class.
 */


#ifndef Category_H__
#define Category_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/UncertValue.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Category : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  unsigned int mRank;
  bool mIsSetRank;
  UncertValue* mProbability;
  UncertValue* mValue;

  /** @endcond */

public:

  /**
   * Creates a new Category using the given SBML Level, Version and
   * &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Category.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Category.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this Category.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Category(unsigned int level = DistribExtension::getDefaultLevel(),
           unsigned int version = DistribExtension::getDefaultVersion(),
           unsigned int pkgVersion =
             DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new Category using the given DistribPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Category(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for Category.
   *
   * @param orig the Category instance to copy.
   */
  Category(const Category& orig);


  /**
   * Assignment operator for Category.
   *
   * @param rhs the Category object whose values are to be used as the basis of
   * the assignment.
   */
  Category& operator=(const Category& rhs);


  /**
   * Creates and returns a deep copy of this Category object.
   *
   * @return a (deep) copy of this Category object.
   */
  virtual Category* clone() const;


  /**
   * Destructor for Category.
   */
  virtual ~Category();


  /**
   * Returns the value of the "rank" attribute of this Category.
   *
   * @return the value of the "rank" attribute of this Category as a unsigned
   * integer.
   */
  unsigned int getRank() const;


  /**
   * Predicate returning @c true if this Category's "rank" attribute is set.
   *
   * @return @c true if this Category's "rank" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetRank() const;


  /**
   * Sets the value of the "rank" attribute of this Category.
   *
   * @param rank unsigned int value of the "rank" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setRank(unsigned int rank);


  /**
   * Unsets the value of the "rank" attribute of this Category.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetRank();


  /**
   * Returns the value of the "probability" element of this Category.
   *
   * @return the value of the "probability" element of this Category as a
   * UncertValue*.
   */
  const UncertValue* getProbability() const;


  /**
   * Returns the value of the "probability" element of this Category.
   *
   * @return the value of the "probability" element of this Category as a
   * UncertValue*.
   */
  UncertValue* getProbability();


  /**
   * Returns the value of the "value" element of this Category.
   *
   * @return the value of the "value" element of this Category as a
   * UncertValue*.
   */
  const UncertValue* getValue() const;


  /**
   * Returns the value of the "value" element of this Category.
   *
   * @return the value of the "value" element of this Category as a
   * UncertValue*.
   */
  UncertValue* getValue();


  /**
   * Predicate returning @c true if this Category's "probability" element is
   * set.
   *
   * @return @c true if this Category's "probability" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetProbability() const;


  /**
   * Predicate returning @c true if this Category's "value" element is set.
   *
   * @return @c true if this Category's "value" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetValue() const;


  /**
   * Sets the value of the "probability" element of this Category.
   *
   * @param probability UncertValue* value of the "probability" element to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setProbability(const UncertValue* probability);


  /**
   * Sets the value of the "value" element of this Category.
   *
   * @param value UncertValue* value of the "value" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setValue(const UncertValue* value);


  /**
   * Creates a new UncertValue object, adds it to this Category object and
   * returns the UncertValue object created.
   *
   * @return a new UncertValue object instance.
   */
  UncertValue* createProbability();


  /**
   * Creates a new UncertValue object, adds it to this Category object and
   * returns the UncertValue object created.
   *
   * @return a new UncertValue object instance.
   */
  UncertValue* createValue();


  /**
   * Unsets the value of the "probability" element of this Category.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetProbability();


  /**
   * Unsets the value of the "value" element of this Category.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetValue();


  /**
   * Returns the XML element name of this Category object.
   *
   * For Category, the XML element name is always @c "category".
   *
   * @return the name of this element, i.e. @c "category".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Category object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_DISTRIB_CATEGORY, SBMLDistribTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * Category object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * Category have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this Category
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * Category have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Category object are:
   * @li "value"
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
   * Gets the value of the "attributeName" attribute of this Category.
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
   * Gets the value of the "attributeName" attribute of this Category.
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
   * Gets the value of the "attributeName" attribute of this Category.
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
   * Gets the value of the "attributeName" attribute of this Category.
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
   * Gets the value of the "attributeName" attribute of this Category.
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
   * Gets the value of the "attributeName" attribute of this Category.
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
   * Predicate returning @c true if this Category's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Category's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Category.
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
   * Sets the value of the "attributeName" attribute of this Category.
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
   * Sets the value of the "attributeName" attribute of this Category.
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
   * Sets the value of the "attributeName" attribute of this Category.
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
   * Sets the value of the "attributeName" attribute of this Category.
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
   * Sets the value of the "attributeName" attribute of this Category.
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
   * Unsets the value of the "attributeName" attribute of this Category.
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
   * Creates and returns an new "elementName" object in this Category.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this Category.
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
   * Category.
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
   * Returns the number of "elementName" in this Category.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this Category.
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
 * Creates a new Category_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Category_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Category_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Category_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
Category_t *
Category_create(unsigned int level,
                unsigned int version,
                unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Category_t object.
 *
 * @param c the Category_t structure.
 *
 * @return a (deep) copy of this Category_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
Category_t*
Category_clone(const Category_t* c);


/**
 * Frees this Category_t object.
 *
 * @param c the Category_t structure.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
void
Category_free(Category_t* c);


/**
 * Returns the value of the "rank" attribute of this Category_t.
 *
 * @param c the Category_t structure whose rank is sought.
 *
 * @return the value of the "rank" attribute of this Category_t as a unsigned
 * integer.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
unsigned int
Category_getRank(const Category_t * c);


/**
 * Predicate returning @c 1 (true) if this Category_t's "rank" attribute is
 * set.
 *
 * @param c the Category_t structure.
 *
 * @return @c 1 (true) if this Category_t's "rank" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_isSetRank(const Category_t * c);


/**
 * Sets the value of the "rank" attribute of this Category_t.
 *
 * @param c the Category_t structure.
 *
 * @param rank unsigned int value of the "rank" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_setRank(Category_t * c, unsigned int rank);


/**
 * Unsets the value of the "rank" attribute of this Category_t.
 *
 * @param c the Category_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_unsetRank(Category_t * c);


/**
 * Returns the value of the "probability" element of this Category_t.
 *
 * @param c the Category_t structure whose probability is sought.
 *
 * @return the value of the "probability" element of this Category_t as a
 * UncertValue*.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
const UncertValue_t*
Category_getProbability(const Category_t * c);


/**
 * Returns the value of the "value" element of this Category_t.
 *
 * @param c the Category_t structure whose value is sought.
 *
 * @return the value of the "value" element of this Category_t as a
 * UncertValue*.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
const UncertValue_t*
Category_getValue(const Category_t * c);


/**
 * Predicate returning @c 1 (true) if this Category_t's "probability" element
 * is set.
 *
 * @param c the Category_t structure.
 *
 * @return @c 1 (true) if this Category_t's "probability" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_isSetProbability(const Category_t * c);


/**
 * Predicate returning @c 1 (true) if this Category_t's "value" element is set.
 *
 * @param c the Category_t structure.
 *
 * @return @c 1 (true) if this Category_t's "value" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_isSetValue(const Category_t * c);


/**
 * Sets the value of the "probability" element of this Category_t.
 *
 * @param c the Category_t structure.
 *
 * @param probability UncertValue_t* value of the "probability" element to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_setProbability(Category_t * c, const UncertValue_t* probability);


/**
 * Sets the value of the "value" element of this Category_t.
 *
 * @param c the Category_t structure.
 *
 * @param value UncertValue_t* value of the "value" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_setValue(Category_t * c, const UncertValue_t* value);


/**
 * Creates a new UncertValue_t object, adds it to this Category_t object and
 * returns the UncertValue_t object created.
 *
 * @param c the Category_t structure to which the UncertValue_t should be
 * added.
 *
 * @return a new UncertValue_t object instance.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
UncertValue_t*
Category_createProbability(Category_t* c);


/**
 * Creates a new UncertValue_t object, adds it to this Category_t object and
 * returns the UncertValue_t object created.
 *
 * @param c the Category_t structure to which the UncertValue_t should be
 * added.
 *
 * @return a new UncertValue_t object instance.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
UncertValue_t*
Category_createValue(Category_t* c);


/**
 * Unsets the value of the "probability" element of this Category_t.
 *
 * @param c the Category_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_unsetProbability(Category_t * c);


/**
 * Unsets the value of the "value" element of this Category_t.
 *
 * @param c the Category_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_unsetValue(Category_t * c);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Category_t object have been set.
 *
 * @param c the Category_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * Category_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_hasRequiredAttributes(const Category_t * c);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * Category_t object have been set.
 *
 * @param c the Category_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * Category_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the Category_t object are:
 * @li "value"
 *
 * @memberof Category_t
 */
LIBSBML_EXTERN
int
Category_hasRequiredElements(const Category_t * c);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Category_H__ */


