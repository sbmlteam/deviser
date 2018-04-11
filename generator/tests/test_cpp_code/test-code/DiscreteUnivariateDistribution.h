/**
 * @file DiscreteUnivariateDistribution.h
 * @brief Definition of the DiscreteUnivariateDistribution class.
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
 * @class DiscreteUnivariateDistribution
 * @sbmlbrief{distrib} TODO:Definition of the DiscreteUnivariateDistribution
 * class.
 */


#ifndef DiscreteUnivariateDistribution_H__
#define DiscreteUnivariateDistribution_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/distrib/sbml/UnivariateDistribution.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/UncertBound.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class BinomialDistribution;
class GeometricDistribution;

class LIBSBML_EXTERN DiscreteUnivariateDistribution : public
  UnivariateDistribution
{
protected:

  /** @cond doxygenLibsbmlInternal */

  UncertBound* mTruncationLowerBound;
  UncertBound* mTruncationUpperBound;

  /** @endcond */

public:

  /**
   * Creates a new DiscreteUnivariateDistribution using the given SBML Level,
   * Version and &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * DiscreteUnivariateDistribution.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * DiscreteUnivariateDistribution.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this DiscreteUnivariateDistribution.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DiscreteUnivariateDistribution(
                                 unsigned int level =
                                   DistribExtension::getDefaultLevel(),
                                 unsigned int version =
                                   DistribExtension::getDefaultVersion(),
                                 unsigned int pkgVersion =
                                   DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new DiscreteUnivariateDistribution using the given
   * DistribPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  DiscreteUnivariateDistribution(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for DiscreteUnivariateDistribution.
   *
   * @param orig the DiscreteUnivariateDistribution instance to copy.
   */
  DiscreteUnivariateDistribution(const DiscreteUnivariateDistribution& orig);


  /**
   * Assignment operator for DiscreteUnivariateDistribution.
   *
   * @param rhs the DiscreteUnivariateDistribution object whose values are to
   * be used as the basis of the assignment.
   */
  DiscreteUnivariateDistribution& operator=(const
    DiscreteUnivariateDistribution& rhs);


  /**
   * Creates and returns a deep copy of this DiscreteUnivariateDistribution
   * object.
   *
   * @return a (deep) copy of this DiscreteUnivariateDistribution object.
   */
  virtual DiscreteUnivariateDistribution* clone() const;


  /**
   * Destructor for DiscreteUnivariateDistribution.
   */
  virtual ~DiscreteUnivariateDistribution();


  /**
   * Returns the value of the "truncationLowerBound" element of this
   * DiscreteUnivariateDistribution.
   *
   * @return the value of the "truncationLowerBound" element of this
   * DiscreteUnivariateDistribution as a UncertBound*.
   */
  const UncertBound* getTruncationLowerBound() const;


  /**
   * Returns the value of the "truncationLowerBound" element of this
   * DiscreteUnivariateDistribution.
   *
   * @return the value of the "truncationLowerBound" element of this
   * DiscreteUnivariateDistribution as a UncertBound*.
   */
  UncertBound* getTruncationLowerBound();


  /**
   * Returns the value of the "truncationUpperBound" element of this
   * DiscreteUnivariateDistribution.
   *
   * @return the value of the "truncationUpperBound" element of this
   * DiscreteUnivariateDistribution as a UncertBound*.
   */
  const UncertBound* getTruncationUpperBound() const;


  /**
   * Returns the value of the "truncationUpperBound" element of this
   * DiscreteUnivariateDistribution.
   *
   * @return the value of the "truncationUpperBound" element of this
   * DiscreteUnivariateDistribution as a UncertBound*.
   */
  UncertBound* getTruncationUpperBound();


  /**
   * Predicate returning @c true if this DiscreteUnivariateDistribution's
   * "truncationLowerBound" element is set.
   *
   * @return @c true if this DiscreteUnivariateDistribution's
   * "truncationLowerBound" element has been set, otherwise @c false is
   * returned.
   */
  bool isSetTruncationLowerBound() const;


  /**
   * Predicate returning @c true if this DiscreteUnivariateDistribution's
   * "truncationUpperBound" element is set.
   *
   * @return @c true if this DiscreteUnivariateDistribution's
   * "truncationUpperBound" element has been set, otherwise @c false is
   * returned.
   */
  bool isSetTruncationUpperBound() const;


  /**
   * Sets the value of the "truncationLowerBound" element of this
   * DiscreteUnivariateDistribution.
   *
   * @param truncationLowerBound UncertBound* value of the
   * "truncationLowerBound" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTruncationLowerBound(const UncertBound* truncationLowerBound);


  /**
   * Sets the value of the "truncationUpperBound" element of this
   * DiscreteUnivariateDistribution.
   *
   * @param truncationUpperBound UncertBound* value of the
   * "truncationUpperBound" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTruncationUpperBound(const UncertBound* truncationUpperBound);


  /**
   * Creates a new UncertBound object, adds it to this
   * DiscreteUnivariateDistribution object and returns the UncertBound object
   * created.
   *
   * @return a new UncertBound object instance.
   */
  UncertBound* createTruncationLowerBound();


  /**
   * Creates a new UncertBound object, adds it to this
   * DiscreteUnivariateDistribution object and returns the UncertBound object
   * created.
   *
   * @return a new UncertBound object instance.
   */
  UncertBound* createTruncationUpperBound();


  /**
   * Unsets the value of the "truncationLowerBound" element of this
   * DiscreteUnivariateDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTruncationLowerBound();


  /**
   * Unsets the value of the "truncationUpperBound" element of this
   * DiscreteUnivariateDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTruncationUpperBound();


  /**
   * Predicate returning @c true if this abstract
   * "DiscreteUnivariateDistribution" is of type BinomialDistribution
   *
   * @return @c true if this abstract "DiscreteUnivariateDistribution" is of
   * type BinomialDistribution, @c false otherwise
   */
  virtual bool isBinomialDistribution() const;


  /**
   * Predicate returning @c true if this abstract
   * "DiscreteUnivariateDistribution" is of type GeometricDistribution
   *
   * @return @c true if this abstract "DiscreteUnivariateDistribution" is of
   * type GeometricDistribution, @c false otherwise
   */
  virtual bool isGeometricDistribution() const;


  /**
   * Returns the XML element name of this DiscreteUnivariateDistribution
   * object.
   *
   * For DiscreteUnivariateDistribution, the XML element name is always
   * @c "discreteUnivariateDistribution".
   *
   * @return the name of this element, i.e.
   * @c "discreteUnivariateDistribution".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this DiscreteUnivariateDistribution
   * object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_DISTRIB_DISCRETEUNIVARIATEDISTRIBUTION,
   * SBMLDistribTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * DiscreteUnivariateDistribution object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * DiscreteUnivariateDistribution have been set, otherwise @c false is
   * returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * DiscreteUnivariateDistribution object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * DiscreteUnivariateDistribution have been set, otherwise @c false is
   * returned.
   *
   *
   * @note The required elements for the DiscreteUnivariateDistribution object
   * are:
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
   * Gets the value of the "attributeName" attribute of this
   * DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
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
   * Predicate returning @c true if this DiscreteUnivariateDistribution's
   * attribute "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this DiscreteUnivariateDistribution's attribute
   * "attributeName" has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
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
   * Unsets the value of the "attributeName" attribute of this
   * DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this DiscreteUnivariateDistribution.
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
   * DiscreteUnivariateDistribution.
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
   * Returns the number of "elementName" in this
   * DiscreteUnivariateDistribution.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this
   * DiscreteUnivariateDistribution.
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


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new DiscreteUnivariateDistribution_t using the given SBML Level,
 * Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * DiscreteUnivariateDistribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * DiscreteUnivariateDistribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this DiscreteUnivariateDistribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
DiscreteUnivariateDistribution_t *
DiscreteUnivariateDistribution_create(unsigned int level,
                                      unsigned int version,
                                      unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this DiscreteUnivariateDistribution_t
 * object.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @return a (deep) copy of this DiscreteUnivariateDistribution_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
DiscreteUnivariateDistribution_t*
DiscreteUnivariateDistribution_clone(const DiscreteUnivariateDistribution_t*
  dud);


/**
 * Frees this DiscreteUnivariateDistribution_t object.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
void
DiscreteUnivariateDistribution_free(DiscreteUnivariateDistribution_t* dud);


/**
 * Returns the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution_t.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure whose
 * truncationLowerBound is sought.
 *
 * @return the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution_t as a UncertBound*.
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
const UncertBound_t*
DiscreteUnivariateDistribution_getTruncationLowerBound(const
  DiscreteUnivariateDistribution_t * dud);


/**
 * Returns the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution_t.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure whose
 * truncationUpperBound is sought.
 *
 * @return the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution_t as a UncertBound*.
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
const UncertBound_t*
DiscreteUnivariateDistribution_getTruncationUpperBound(const
  DiscreteUnivariateDistribution_t * dud);


/**
 * Predicate returning @c 1 (true) if this DiscreteUnivariateDistribution_t's
 * "truncationLowerBound" element is set.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @return @c 1 (true) if this DiscreteUnivariateDistribution_t's
 * "truncationLowerBound" element has been set, otherwise @c 0 (false) is
 * returned.
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_isSetTruncationLowerBound(const
  DiscreteUnivariateDistribution_t * dud);


/**
 * Predicate returning @c 1 (true) if this DiscreteUnivariateDistribution_t's
 * "truncationUpperBound" element is set.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @return @c 1 (true) if this DiscreteUnivariateDistribution_t's
 * "truncationUpperBound" element has been set, otherwise @c 0 (false) is
 * returned.
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_isSetTruncationUpperBound(const
  DiscreteUnivariateDistribution_t * dud);


/**
 * Sets the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution_t.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @param truncationLowerBound UncertBound_t* value of the
 * "truncationLowerBound" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_setTruncationLowerBound(
                                                       DiscreteUnivariateDistribution_t
                                                         * dud,
                                                       const UncertBound_t*
                                                         truncationLowerBound);


/**
 * Sets the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution_t.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @param truncationUpperBound UncertBound_t* value of the
 * "truncationUpperBound" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_setTruncationUpperBound(
                                                       DiscreteUnivariateDistribution_t
                                                         * dud,
                                                       const UncertBound_t*
                                                         truncationUpperBound);


/**
 * Creates a new UncertBound_t object, adds it to this
 * DiscreteUnivariateDistribution_t object and returns the UncertBound_t object
 * created.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure to which the
 * UncertBound_t should be added.
 *
 * @return a new UncertBound_t object instance.
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
UncertBound_t*
DiscreteUnivariateDistribution_createTruncationLowerBound(DiscreteUnivariateDistribution_t*
  dud);


/**
 * Creates a new UncertBound_t object, adds it to this
 * DiscreteUnivariateDistribution_t object and returns the UncertBound_t object
 * created.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure to which the
 * UncertBound_t should be added.
 *
 * @return a new UncertBound_t object instance.
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
UncertBound_t*
DiscreteUnivariateDistribution_createTruncationUpperBound(DiscreteUnivariateDistribution_t*
  dud);


/**
 * Unsets the value of the "truncationLowerBound" element of this
 * DiscreteUnivariateDistribution_t.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_unsetTruncationLowerBound(DiscreteUnivariateDistribution_t
  * dud);


/**
 * Unsets the value of the "truncationUpperBound" element of this
 * DiscreteUnivariateDistribution_t.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_unsetTruncationUpperBound(DiscreteUnivariateDistribution_t
  * dud);


/**
 * Predicate returning @c 1 if this DiscreteUnivariateDistribution_t is of type
 * BinomialDistribution_t
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @return @c 1 if this DiscreteUnivariateDistribution_t is of type
 * BinomialDistribution_t, @c 0 otherwise
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_isBinomialDistribution(const
  DiscreteUnivariateDistribution_t * dud);


/**
 * Predicate returning @c 1 if this DiscreteUnivariateDistribution_t is of type
 * GeometricDistribution_t
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @return @c 1 if this DiscreteUnivariateDistribution_t is of type
 * GeometricDistribution_t, @c 0 otherwise
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_isGeometricDistribution(const
  DiscreteUnivariateDistribution_t * dud);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * DiscreteUnivariateDistribution_t object have been set.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * DiscreteUnivariateDistribution_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_hasRequiredAttributes(const
  DiscreteUnivariateDistribution_t * dud);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * DiscreteUnivariateDistribution_t object have been set.
 *
 * @param dud the DiscreteUnivariateDistribution_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * DiscreteUnivariateDistribution_t have been set, otherwise @c 0 (false) is
 * returned.
 *
 *
 * @note The required elements for the DiscreteUnivariateDistribution_t object
 * are:
 *
 * @memberof DiscreteUnivariateDistribution_t
 */
LIBSBML_EXTERN
int
DiscreteUnivariateDistribution_hasRequiredElements(const
  DiscreteUnivariateDistribution_t * dud);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !DiscreteUnivariateDistribution_H__ */


