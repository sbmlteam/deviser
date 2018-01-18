/**
 * @file Uncertainty.h
 * @brief Definition of the Uncertainty class.
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
 * @class Uncertainty
 * @sbmlbrief{distrib} TODO:Definition of the Uncertainty class.
 */


#ifndef Uncertainty_H__
#define Uncertainty_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/UncertStatistics.h>
#include <sbml/packages/distrib/sbml/Distribution.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Uncertainty : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  UncertStatistics* mUncertStatistics;
  Distribution* mDistribution;

  /** @endcond */

public:

  /**
   * Creates a new Uncertainty using the given SBML Level, Version and
   * &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * Uncertainty.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Uncertainty.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this Uncertainty.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Uncertainty(unsigned int level = DistribExtension::getDefaultLevel(),
              unsigned int version = DistribExtension::getDefaultVersion(),
              unsigned int pkgVersion =
                DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new Uncertainty using the given DistribPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Uncertainty(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for Uncertainty.
   *
   * @param orig the Uncertainty instance to copy.
   */
  Uncertainty(const Uncertainty& orig);


  /**
   * Assignment operator for Uncertainty.
   *
   * @param rhs the Uncertainty object whose values are to be used as the basis
   * of the assignment.
   */
  Uncertainty& operator=(const Uncertainty& rhs);


  /**
   * Creates and returns a deep copy of this Uncertainty object.
   *
   * @return a (deep) copy of this Uncertainty object.
   */
  virtual Uncertainty* clone() const;


  /**
   * Destructor for Uncertainty.
   */
  virtual ~Uncertainty();


  /**
   * Returns the value of the "uncertStatistics" element of this Uncertainty.
   *
   * @return the value of the "uncertStatistics" element of this Uncertainty as
   * a UncertStatistics*.
   */
  const UncertStatistics* getUncertStatistics() const;


  /**
   * Returns the value of the "uncertStatistics" element of this Uncertainty.
   *
   * @return the value of the "uncertStatistics" element of this Uncertainty as
   * a UncertStatistics*.
   */
  UncertStatistics* getUncertStatistics();


  /**
   * Returns the value of the "distribution" element of this Uncertainty.
   *
   * @return the value of the "distribution" element of this Uncertainty as a
   * Distribution*.
   */
  const Distribution* getDistribution() const;


  /**
   * Returns the value of the "distribution" element of this Uncertainty.
   *
   * @return the value of the "distribution" element of this Uncertainty as a
   * Distribution*.
   */
  Distribution* getDistribution();


  /**
   * Predicate returning @c true if this Uncertainty's "uncertStatistics"
   * element is set.
   *
   * @return @c true if this Uncertainty's "uncertStatistics" element has been
   * set, otherwise @c false is returned.
   */
  bool isSetUncertStatistics() const;


  /**
   * Predicate returning @c true if this Uncertainty's "distribution" element
   * is set.
   *
   * @return @c true if this Uncertainty's "distribution" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetDistribution() const;


  /**
   * Sets the value of the "uncertStatistics" element of this Uncertainty.
   *
   * @param uncertStatistics UncertStatistics* value of the "uncertStatistics"
   * element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUncertStatistics(const UncertStatistics* uncertStatistics);


  /**
   * Sets the value of the "distribution" element of this Uncertainty.
   *
   * @param distribution Distribution* value of the "distribution" element to
   * be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDistribution(const Distribution* distribution);


  /**
   * Creates a new UncertStatistics object, adds it to this Uncertainty object
   * and returns the UncertStatistics object created.
   *
   * @return a new UncertStatistics object instance.
   */
  UncertStatistics* createUncertStatistics();


  /**
   * Creates a new BetaDistribution object, adds it to this Uncertainty object
   * and returns the BetaDistribution object created.
   *
   * @return a new BetaDistribution object instance.
   */
  BetaDistribution* createBetaDistribution();


  /**
   * Creates a new CauchyDistribution object, adds it to this Uncertainty
   * object and returns the CauchyDistribution object created.
   *
   * @return a new CauchyDistribution object instance.
   */
  CauchyDistribution* createCauchyDistribution();


  /**
   * Creates a new ExponentialDistribution object, adds it to this Uncertainty
   * object and returns the ExponentialDistribution object created.
   *
   * @return a new ExponentialDistribution object instance.
   */
  ExponentialDistribution* createExponentialDistribution();


  /**
   * Creates a new LogisticDistribution object, adds it to this Uncertainty
   * object and returns the LogisticDistribution object created.
   *
   * @return a new LogisticDistribution object instance.
   */
  LogisticDistribution* createLogisticDistribution();


  /**
   * Creates a new NormalDistribution object, adds it to this Uncertainty
   * object and returns the NormalDistribution object created.
   *
   * @return a new NormalDistribution object instance.
   */
  NormalDistribution* createNormalDistribution();


  /**
   * Creates a new BinomialDistribution object, adds it to this Uncertainty
   * object and returns the BinomialDistribution object created.
   *
   * @return a new BinomialDistribution object instance.
   */
  BinomialDistribution* createBinomialDistribution();


  /**
   * Creates a new GeometricDistribution object, adds it to this Uncertainty
   * object and returns the GeometricDistribution object created.
   *
   * @return a new GeometricDistribution object instance.
   */
  GeometricDistribution* createGeometricDistribution();


  /**
   * Creates a new BernoulliDistribution object, adds it to this Uncertainty
   * object and returns the BernoulliDistribution object created.
   *
   * @return a new BernoulliDistribution object instance.
   */
  BernoulliDistribution* createBernoulliDistribution();


  /**
   * Creates a new CategoricalDistribution object, adds it to this Uncertainty
   * object and returns the CategoricalDistribution object created.
   *
   * @return a new CategoricalDistribution object instance.
   */
  CategoricalDistribution* createCategoricalDistribution();


  /**
   * Creates a new MultivariateDistribution object, adds it to this Uncertainty
   * object and returns the MultivariateDistribution object created.
   *
   * @return a new MultivariateDistribution object instance.
   */
  MultivariateDistribution* createMultivariateDistribution();


  /**
   * Creates a new ExternalDistribution object, adds it to this Uncertainty
   * object and returns the ExternalDistribution object created.
   *
   * @return a new ExternalDistribution object instance.
   */
  ExternalDistribution* createExternalDistribution();


  /**
   * Unsets the value of the "uncertStatistics" element of this Uncertainty.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUncertStatistics();


  /**
   * Unsets the value of the "distribution" element of this Uncertainty.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDistribution();


  /**
   * Returns the XML element name of this Uncertainty object.
   *
   * For Uncertainty, the XML element name is always @c "uncertainty".
   *
   * @return the name of this element, i.e. @c "uncertainty".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Uncertainty object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_DISTRIB_UNCERTAINTY, SBMLDistribTypeCode_t}.
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
   * Gets the value of the "attributeName" attribute of this Uncertainty.
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
   * Gets the value of the "attributeName" attribute of this Uncertainty.
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
   * Gets the value of the "attributeName" attribute of this Uncertainty.
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
   * Gets the value of the "attributeName" attribute of this Uncertainty.
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
   * Gets the value of the "attributeName" attribute of this Uncertainty.
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
   * Predicate returning @c true if this Uncertainty's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Uncertainty's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Uncertainty.
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
   * Sets the value of the "attributeName" attribute of this Uncertainty.
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
   * Sets the value of the "attributeName" attribute of this Uncertainty.
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
   * Sets the value of the "attributeName" attribute of this Uncertainty.
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
   * Sets the value of the "attributeName" attribute of this Uncertainty.
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
   * Unsets the value of the "attributeName" attribute of this Uncertainty.
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
   * Creates and returns an new "elementName" object in this Uncertainty.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this Uncertainty.
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
   * Uncertainty.
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
   * Returns the number of "elementName" in this Uncertainty.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this Uncertainty.
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
 * Creates a new Uncertainty_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Uncertainty_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Uncertainty_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Uncertainty_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
Uncertainty_t *
Uncertainty_create(unsigned int level,
                   unsigned int version,
                   unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Uncertainty_t object.
 *
 * @param u the Uncertainty_t structure.
 *
 * @return a (deep) copy of this Uncertainty_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
Uncertainty_t*
Uncertainty_clone(const Uncertainty_t* u);


/**
 * Frees this Uncertainty_t object.
 *
 * @param u the Uncertainty_t structure.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
void
Uncertainty_free(Uncertainty_t* u);


/**
 * Returns the value of the "uncertStatistics" element of this Uncertainty_t.
 *
 * @param u the Uncertainty_t structure whose uncertStatistics is sought.
 *
 * @return the value of the "uncertStatistics" element of this Uncertainty_t as
 * a UncertStatistics*.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
const UncertStatistics_t*
Uncertainty_getUncertStatistics(const Uncertainty_t * u);


/**
 * Returns the value of the "distribution" element of this Uncertainty_t.
 *
 * @param u the Uncertainty_t structure whose distribution is sought.
 *
 * @return the value of the "distribution" element of this Uncertainty_t as a
 * Distribution*.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
const Distribution_t*
Uncertainty_getDistribution(const Uncertainty_t * u);


/**
 * Predicate returning @c 1 (true) if this Uncertainty_t's "uncertStatistics"
 * element is set.
 *
 * @param u the Uncertainty_t structure.
 *
 * @return @c 1 (true) if this Uncertainty_t's "uncertStatistics" element has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
int
Uncertainty_isSetUncertStatistics(const Uncertainty_t * u);


/**
 * Predicate returning @c 1 (true) if this Uncertainty_t's "distribution"
 * element is set.
 *
 * @param u the Uncertainty_t structure.
 *
 * @return @c 1 (true) if this Uncertainty_t's "distribution" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
int
Uncertainty_isSetDistribution(const Uncertainty_t * u);


/**
 * Sets the value of the "uncertStatistics" element of this Uncertainty_t.
 *
 * @param u the Uncertainty_t structure.
 *
 * @param uncertStatistics UncertStatistics_t* value of the "uncertStatistics"
 * element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
int
Uncertainty_setUncertStatistics(Uncertainty_t * u,
                                const UncertStatistics_t* uncertStatistics);


/**
 * Sets the value of the "distribution" element of this Uncertainty_t.
 *
 * @param u the Uncertainty_t structure.
 *
 * @param distribution Distribution_t* value of the "distribution" element to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
int
Uncertainty_setDistribution(Uncertainty_t * u,
                            const Distribution_t* distribution);


/**
 * Creates a new UncertStatistics_t object, adds it to this Uncertainty_t
 * object and returns the UncertStatistics_t object created.
 *
 * @param u the Uncertainty_t structure to which the UncertStatistics_t should
 * be added.
 *
 * @return a new UncertStatistics_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
UncertStatistics_t*
Uncertainty_createUncertStatistics(Uncertainty_t* u);


/**
 * Creates a new BetaDistribution_t object, adds it to this Uncertainty_t
 * object and returns the BetaDistribution_t object created.
 *
 * @param u the Uncertainty_t structure to which the BetaDistribution_t should
 * be added.
 *
 * @return a new BetaDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
BetaDistribution_t*
Uncertainty_createBetaDistribution(Uncertainty_t* u);


/**
 * Creates a new CauchyDistribution_t object, adds it to this Uncertainty_t
 * object and returns the CauchyDistribution_t object created.
 *
 * @param u the Uncertainty_t structure to which the CauchyDistribution_t
 * should be added.
 *
 * @return a new CauchyDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
CauchyDistribution_t*
Uncertainty_createCauchyDistribution(Uncertainty_t* u);


/**
 * Creates a new ExponentialDistribution_t object, adds it to this
 * Uncertainty_t object and returns the ExponentialDistribution_t object
 * created.
 *
 * @param u the Uncertainty_t structure to which the ExponentialDistribution_t
 * should be added.
 *
 * @return a new ExponentialDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
ExponentialDistribution_t*
Uncertainty_createExponentialDistribution(Uncertainty_t* u);


/**
 * Creates a new LogisticDistribution_t object, adds it to this Uncertainty_t
 * object and returns the LogisticDistribution_t object created.
 *
 * @param u the Uncertainty_t structure to which the LogisticDistribution_t
 * should be added.
 *
 * @return a new LogisticDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
LogisticDistribution_t*
Uncertainty_createLogisticDistribution(Uncertainty_t* u);


/**
 * Creates a new NormalDistribution_t object, adds it to this Uncertainty_t
 * object and returns the NormalDistribution_t object created.
 *
 * @param u the Uncertainty_t structure to which the NormalDistribution_t
 * should be added.
 *
 * @return a new NormalDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
NormalDistribution_t*
Uncertainty_createNormalDistribution(Uncertainty_t* u);


/**
 * Creates a new BinomialDistribution_t object, adds it to this Uncertainty_t
 * object and returns the BinomialDistribution_t object created.
 *
 * @param u the Uncertainty_t structure to which the BinomialDistribution_t
 * should be added.
 *
 * @return a new BinomialDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
BinomialDistribution_t*
Uncertainty_createBinomialDistribution(Uncertainty_t* u);


/**
 * Creates a new GeometricDistribution_t object, adds it to this Uncertainty_t
 * object and returns the GeometricDistribution_t object created.
 *
 * @param u the Uncertainty_t structure to which the GeometricDistribution_t
 * should be added.
 *
 * @return a new GeometricDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
GeometricDistribution_t*
Uncertainty_createGeometricDistribution(Uncertainty_t* u);


/**
 * Creates a new BernoulliDistribution_t object, adds it to this Uncertainty_t
 * object and returns the BernoulliDistribution_t object created.
 *
 * @param u the Uncertainty_t structure to which the BernoulliDistribution_t
 * should be added.
 *
 * @return a new BernoulliDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
BernoulliDistribution_t*
Uncertainty_createBernoulliDistribution(Uncertainty_t* u);


/**
 * Creates a new CategoricalDistribution_t object, adds it to this
 * Uncertainty_t object and returns the CategoricalDistribution_t object
 * created.
 *
 * @param u the Uncertainty_t structure to which the CategoricalDistribution_t
 * should be added.
 *
 * @return a new CategoricalDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
CategoricalDistribution_t*
Uncertainty_createCategoricalDistribution(Uncertainty_t* u);


/**
 * Creates a new MultivariateDistribution_t object, adds it to this
 * Uncertainty_t object and returns the MultivariateDistribution_t object
 * created.
 *
 * @param u the Uncertainty_t structure to which the MultivariateDistribution_t
 * should be added.
 *
 * @return a new MultivariateDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
MultivariateDistribution_t*
Uncertainty_createMultivariateDistribution(Uncertainty_t* u);


/**
 * Creates a new ExternalDistribution_t object, adds it to this Uncertainty_t
 * object and returns the ExternalDistribution_t object created.
 *
 * @param u the Uncertainty_t structure to which the ExternalDistribution_t
 * should be added.
 *
 * @return a new ExternalDistribution_t object instance.
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
ExternalDistribution_t*
Uncertainty_createExternalDistribution(Uncertainty_t* u);


/**
 * Unsets the value of the "uncertStatistics" element of this Uncertainty_t.
 *
 * @param u the Uncertainty_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
int
Uncertainty_unsetUncertStatistics(Uncertainty_t * u);


/**
 * Unsets the value of the "distribution" element of this Uncertainty_t.
 *
 * @param u the Uncertainty_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Uncertainty_t
 */
LIBSBML_EXTERN
int
Uncertainty_unsetDistribution(Uncertainty_t * u);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Uncertainty_H__ */


