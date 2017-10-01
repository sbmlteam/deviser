/**
 * @file UncertaintyA.h
 * @brief Definition of the UncertaintyA class.
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
 * @class UncertaintyA
 * @sbmlbrief{distrib} TODO:Definition of the UncertaintyA class.
 */


#ifndef UncertaintyA_H__
#define UncertaintyA_H__


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


class LIBSBML_EXTERN UncertaintyA : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  UncertStatistics* mUncertStatistics;
  Distribution* mDistribution;

  /** @endcond */

public:

  /**
   * Creates a new UncertaintyA using the given SBML Level, Version and
   * &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * UncertaintyA.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * UncertaintyA.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this UncertaintyA.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  UncertaintyA(unsigned int level = DistribExtension::getDefaultLevel(),
               unsigned int version = DistribExtension::getDefaultVersion(),
               unsigned int pkgVersion =
                 DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new UncertaintyA using the given DistribPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  UncertaintyA(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for UncertaintyA.
   *
   * @param orig the UncertaintyA instance to copy.
   */
  UncertaintyA(const UncertaintyA& orig);


  /**
   * Assignment operator for UncertaintyA.
   *
   * @param rhs the UncertaintyA object whose values are to be used as the
   * basis of the assignment.
   */
  UncertaintyA& operator=(const UncertaintyA& rhs);


  /**
   * Creates and returns a deep copy of this UncertaintyA object.
   *
   * @return a (deep) copy of this UncertaintyA object.
   */
  virtual UncertaintyA* clone() const;


  /**
   * Destructor for UncertaintyA.
   */
  virtual ~UncertaintyA();


  /**
   * Returns the value of the "uncertStatistics" element of this UncertaintyA.
   *
   * @return the value of the "uncertStatistics" element of this UncertaintyA
   * as a UncertStatistics*.
   */
  const UncertStatistics* getUncertStatistics() const;


  /**
   * Returns the value of the "uncertStatistics" element of this UncertaintyA.
   *
   * @return the value of the "uncertStatistics" element of this UncertaintyA
   * as a UncertStatistics*.
   */
  UncertStatistics* getUncertStatistics();


  /**
   * Returns the value of the "distribution" element of this UncertaintyA.
   *
   * @return the value of the "distribution" element of this UncertaintyA as a
   * Distribution*.
   */
  const Distribution* getDistribution() const;


  /**
   * Returns the value of the "distribution" element of this UncertaintyA.
   *
   * @return the value of the "distribution" element of this UncertaintyA as a
   * Distribution*.
   */
  Distribution* getDistribution();


  /**
   * Predicate returning @c true if this UncertaintyA's "uncertStatistics"
   * element is set.
   *
   * @return @c true if this UncertaintyA's "uncertStatistics" element has been
   * set, otherwise @c false is returned.
   */
  bool isSetUncertStatistics() const;


  /**
   * Predicate returning @c true if this UncertaintyA's "distribution" element
   * is set.
   *
   * @return @c true if this UncertaintyA's "distribution" element has been
   * set, otherwise @c false is returned.
   */
  bool isSetDistribution() const;


  /**
   * Sets the value of the "uncertStatistics" element of this UncertaintyA.
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
   * Sets the value of the "distribution" element of this UncertaintyA.
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
   * Creates a new UncertStatistics object, adds it to this UncertaintyA object
   * and returns the UncertStatistics object created.
   *
   * @return a new UncertStatistics object instance.
   */
  UncertStatistics* createUncertStatistics();


  /**
   * Creates a new BetaDistribution object, adds it to this UncertaintyA object
   * and returns the BetaDistribution object created.
   *
   * @return a new BetaDistribution object instance.
   */
  BetaDistribution* createBetaDistribution();


  /**
   * Creates a new CauchyDistribution object, adds it to this UncertaintyA
   * object and returns the CauchyDistribution object created.
   *
   * @return a new CauchyDistribution object instance.
   */
  CauchyDistribution* createCauchyDistribution();


  /**
   * Creates a new ChiSquareDistribution object, adds it to this UncertaintyA
   * object and returns the ChiSquareDistribution object created.
   *
   * @return a new ChiSquareDistribution object instance.
   */
  ChiSquareDistribution* createChiSquareDistribution();


  /**
   * Creates a new ExponentialDistribution object, adds it to this UncertaintyA
   * object and returns the ExponentialDistribution object created.
   *
   * @return a new ExponentialDistribution object instance.
   */
  ExponentialDistribution* createExponentialDistribution();


  /**
   * Creates a new FDistribution object, adds it to this UncertaintyA object
   * and returns the FDistribution object created.
   *
   * @return a new FDistribution object instance.
   */
  FDistribution* createFDistribution();


  /**
   * Creates a new GammaDistribution object, adds it to this UncertaintyA
   * object and returns the GammaDistribution object created.
   *
   * @return a new GammaDistribution object instance.
   */
  GammaDistribution* createGammaDistribution();


  /**
   * Creates a new InverseGammaDistribution object, adds it to this
   * UncertaintyA object and returns the InverseGammaDistribution object
   * created.
   *
   * @return a new InverseGammaDistribution object instance.
   */
  InverseGammaDistribution* createInverseGammaDistribution();


  /**
   * Creates a new LaPlaceDistribution object, adds it to this UncertaintyA
   * object and returns the LaPlaceDistribution object created.
   *
   * @return a new LaPlaceDistribution object instance.
   */
  LaPlaceDistribution* createLaPlaceDistribution();


  /**
   * Creates a new LogNormalDistribution object, adds it to this UncertaintyA
   * object and returns the LogNormalDistribution object created.
   *
   * @return a new LogNormalDistribution object instance.
   */
  LogNormalDistribution* createLogNormalDistribution();


  /**
   * Creates a new LogisticDistribution object, adds it to this UncertaintyA
   * object and returns the LogisticDistribution object created.
   *
   * @return a new LogisticDistribution object instance.
   */
  LogisticDistribution* createLogisticDistribution();


  /**
   * Creates a new NormalDistribution object, adds it to this UncertaintyA
   * object and returns the NormalDistribution object created.
   *
   * @return a new NormalDistribution object instance.
   */
  NormalDistribution* createNormalDistribution();


  /**
   * Creates a new ParetoDistribution object, adds it to this UncertaintyA
   * object and returns the ParetoDistribution object created.
   *
   * @return a new ParetoDistribution object instance.
   */
  ParetoDistribution* createParetoDistribution();


  /**
   * Creates a new RayleighDistribution object, adds it to this UncertaintyA
   * object and returns the RayleighDistribution object created.
   *
   * @return a new RayleighDistribution object instance.
   */
  RayleighDistribution* createRayleighDistribution();


  /**
   * Creates a new StudentTDistribution object, adds it to this UncertaintyA
   * object and returns the StudentTDistribution object created.
   *
   * @return a new StudentTDistribution object instance.
   */
  StudentTDistribution* createStudentTDistribution();


  /**
   * Creates a new UniformDistribution object, adds it to this UncertaintyA
   * object and returns the UniformDistribution object created.
   *
   * @return a new UniformDistribution object instance.
   */
  UniformDistribution* createUniformDistribution();


  /**
   * Creates a new WeibullDistribution object, adds it to this UncertaintyA
   * object and returns the WeibullDistribution object created.
   *
   * @return a new WeibullDistribution object instance.
   */
  WeibullDistribution* createWeibullDistribution();


  /**
   * Creates a new BinomialDistribution object, adds it to this UncertaintyA
   * object and returns the BinomialDistribution object created.
   *
   * @return a new BinomialDistribution object instance.
   */
  BinomialDistribution* createBinomialDistribution();


  /**
   * Creates a new GeometricDistribution object, adds it to this UncertaintyA
   * object and returns the GeometricDistribution object created.
   *
   * @return a new GeometricDistribution object instance.
   */
  GeometricDistribution* createGeometricDistribution();


  /**
   * Creates a new HypergeometricDistribution object, adds it to this
   * UncertaintyA object and returns the HypergeometricDistribution object
   * created.
   *
   * @return a new HypergeometricDistribution object instance.
   */
  HypergeometricDistribution* createHypergeometricDistribution();


  /**
   * Creates a new NegativeBinomialDistribution object, adds it to this
   * UncertaintyA object and returns the NegativeBinomialDistribution object
   * created.
   *
   * @return a new NegativeBinomialDistribution object instance.
   */
  NegativeBinomialDistribution* createNegativeBinomialDistribution();


  /**
   * Creates a new PoissonDistribution object, adds it to this UncertaintyA
   * object and returns the PoissonDistribution object created.
   *
   * @return a new PoissonDistribution object instance.
   */
  PoissonDistribution* createPoissonDistribution();


  /**
   * Creates a new BernoulliDistribution object, adds it to this UncertaintyA
   * object and returns the BernoulliDistribution object created.
   *
   * @return a new BernoulliDistribution object instance.
   */
  BernoulliDistribution* createBernoulliDistribution();


  /**
   * Creates a new CategoricalDistribution object, adds it to this UncertaintyA
   * object and returns the CategoricalDistribution object created.
   *
   * @return a new CategoricalDistribution object instance.
   */
  CategoricalDistribution* createCategoricalDistribution();


  /**
   * Creates a new MultivariateDistribution object, adds it to this
   * UncertaintyA object and returns the MultivariateDistribution object
   * created.
   *
   * @return a new MultivariateDistribution object instance.
   */
  MultivariateDistribution* createMultivariateDistribution();


  /**
   * Creates a new ExternalDistribution object, adds it to this UncertaintyA
   * object and returns the ExternalDistribution object created.
   *
   * @return a new ExternalDistribution object instance.
   */
  ExternalDistribution* createExternalDistribution();


  /**
   * Unsets the value of the "uncertStatistics" element of this UncertaintyA.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUncertStatistics();


  /**
   * Unsets the value of the "distribution" element of this UncertaintyA.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDistribution();


  /**
   * Returns the XML element name of this UncertaintyA object.
   *
   * For UncertaintyA, the XML element name is always @c "uncertainty".
   *
   * @return the name of this element, i.e. @c "uncertainty".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this UncertaintyA object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_DISTRIB_UNCERTAINTY, SBMLDistribTypeCode_t}
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
   * Gets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Predicate returning @c true if this UncertaintyA's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this UncertaintyA's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Unsets the value of the "attributeName" attribute of this UncertaintyA.
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
   * Creates and returns an new "elementName" object in this UncertaintyA.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this UncertaintyA.
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
   * UncertaintyA.
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
   * Returns the number of "elementName" in this UncertaintyA.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this UncertaintyA.
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
 * Creates a new UncertaintyA_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * UncertaintyA_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * UncertaintyA_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this UncertaintyA_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
UncertaintyA_t *
UncertaintyA_create(unsigned int level,
                    unsigned int version,
                    unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this UncertaintyA_t object.
 *
 * @param ua the UncertaintyA_t structure.
 *
 * @return a (deep) copy of this UncertaintyA_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
UncertaintyA_t*
UncertaintyA_clone(const UncertaintyA_t* ua);


/**
 * Frees this UncertaintyA_t object.
 *
 * @param ua the UncertaintyA_t structure.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
void
UncertaintyA_free(UncertaintyA_t* ua);


/**
 * Returns the value of the "uncertStatistics" element of this UncertaintyA_t.
 *
 * @param ua the UncertaintyA_t structure whose uncertStatistics is sought.
 *
 * @return the value of the "uncertStatistics" element of this UncertaintyA_t
 * as a UncertStatistics*.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
const UncertStatistics_t*
UncertaintyA_getUncertStatistics(const UncertaintyA_t * ua);


/**
 * Returns the value of the "distribution" element of this UncertaintyA_t.
 *
 * @param ua the UncertaintyA_t structure whose distribution is sought.
 *
 * @return the value of the "distribution" element of this UncertaintyA_t as a
 * Distribution*.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
const Distribution_t*
UncertaintyA_getDistribution(const UncertaintyA_t * ua);


/**
 * Predicate returning @c 1 (true) if this UncertaintyA_t's "uncertStatistics"
 * element is set.
 *
 * @param ua the UncertaintyA_t structure.
 *
 * @return @c 1 (true) if this UncertaintyA_t's "uncertStatistics" element has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
int
UncertaintyA_isSetUncertStatistics(const UncertaintyA_t * ua);


/**
 * Predicate returning @c 1 (true) if this UncertaintyA_t's "distribution"
 * element is set.
 *
 * @param ua the UncertaintyA_t structure.
 *
 * @return @c 1 (true) if this UncertaintyA_t's "distribution" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
int
UncertaintyA_isSetDistribution(const UncertaintyA_t * ua);


/**
 * Sets the value of the "uncertStatistics" element of this UncertaintyA_t.
 *
 * @param ua the UncertaintyA_t structure.
 *
 * @param uncertStatistics UncertStatistics_t* value of the "uncertStatistics"
 * element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
int
UncertaintyA_setUncertStatistics(UncertaintyA_t * ua,
                                 const UncertStatistics_t* uncertStatistics);


/**
 * Sets the value of the "distribution" element of this UncertaintyA_t.
 *
 * @param ua the UncertaintyA_t structure.
 *
 * @param distribution Distribution_t* value of the "distribution" element to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
int
UncertaintyA_setDistribution(UncertaintyA_t * ua,
                             const Distribution_t* distribution);


/**
 * Creates a new UncertStatistics_t object, adds it to this UncertaintyA_t
 * object and returns the UncertStatistics_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the UncertStatistics_t
 * should be added.
 *
 * @return a new UncertStatistics_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
UncertStatistics_t*
UncertaintyA_createUncertStatistics(UncertaintyA_t* ua);


/**
 * Creates a new BetaDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the BetaDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the BetaDistribution_t
 * should be added.
 *
 * @return a new BetaDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
BetaDistribution_t*
UncertaintyA_createBetaDistribution(UncertaintyA_t* ua);


/**
 * Creates a new CauchyDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the CauchyDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the CauchyDistribution_t
 * should be added.
 *
 * @return a new CauchyDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
CauchyDistribution_t*
UncertaintyA_createCauchyDistribution(UncertaintyA_t* ua);


/**
 * Creates a new ChiSquareDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the ChiSquareDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the ChiSquareDistribution_t
 * should be added.
 *
 * @return a new ChiSquareDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
ChiSquareDistribution_t*
UncertaintyA_createChiSquareDistribution(UncertaintyA_t* ua);


/**
 * Creates a new ExponentialDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the ExponentialDistribution_t object
 * created.
 *
 * @param ua the UncertaintyA_t structure to which the
 * ExponentialDistribution_t should be added.
 *
 * @return a new ExponentialDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
ExponentialDistribution_t*
UncertaintyA_createExponentialDistribution(UncertaintyA_t* ua);


/**
 * Creates a new FDistribution_t object, adds it to this UncertaintyA_t object
 * and returns the FDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the FDistribution_t should
 * be added.
 *
 * @return a new FDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
FDistribution_t*
UncertaintyA_createFDistribution(UncertaintyA_t* ua);


/**
 * Creates a new GammaDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the GammaDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the GammaDistribution_t
 * should be added.
 *
 * @return a new GammaDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
GammaDistribution_t*
UncertaintyA_createGammaDistribution(UncertaintyA_t* ua);


/**
 * Creates a new InverseGammaDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the InverseGammaDistribution_t object
 * created.
 *
 * @param ua the UncertaintyA_t structure to which the
 * InverseGammaDistribution_t should be added.
 *
 * @return a new InverseGammaDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
InverseGammaDistribution_t*
UncertaintyA_createInverseGammaDistribution(UncertaintyA_t* ua);


/**
 * Creates a new LaPlaceDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the LaPlaceDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the LaPlaceDistribution_t
 * should be added.
 *
 * @return a new LaPlaceDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
LaPlaceDistribution_t*
UncertaintyA_createLaPlaceDistribution(UncertaintyA_t* ua);


/**
 * Creates a new LogNormalDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the LogNormalDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the LogNormalDistribution_t
 * should be added.
 *
 * @return a new LogNormalDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
LogNormalDistribution_t*
UncertaintyA_createLogNormalDistribution(UncertaintyA_t* ua);


/**
 * Creates a new LogisticDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the LogisticDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the LogisticDistribution_t
 * should be added.
 *
 * @return a new LogisticDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
LogisticDistribution_t*
UncertaintyA_createLogisticDistribution(UncertaintyA_t* ua);


/**
 * Creates a new NormalDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the NormalDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the NormalDistribution_t
 * should be added.
 *
 * @return a new NormalDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
NormalDistribution_t*
UncertaintyA_createNormalDistribution(UncertaintyA_t* ua);


/**
 * Creates a new ParetoDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the ParetoDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the ParetoDistribution_t
 * should be added.
 *
 * @return a new ParetoDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
ParetoDistribution_t*
UncertaintyA_createParetoDistribution(UncertaintyA_t* ua);


/**
 * Creates a new RayleighDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the RayleighDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the RayleighDistribution_t
 * should be added.
 *
 * @return a new RayleighDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
RayleighDistribution_t*
UncertaintyA_createRayleighDistribution(UncertaintyA_t* ua);


/**
 * Creates a new StudentTDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the StudentTDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the StudentTDistribution_t
 * should be added.
 *
 * @return a new StudentTDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
StudentTDistribution_t*
UncertaintyA_createStudentTDistribution(UncertaintyA_t* ua);


/**
 * Creates a new UniformDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the UniformDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the UniformDistribution_t
 * should be added.
 *
 * @return a new UniformDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
UniformDistribution_t*
UncertaintyA_createUniformDistribution(UncertaintyA_t* ua);


/**
 * Creates a new WeibullDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the WeibullDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the WeibullDistribution_t
 * should be added.
 *
 * @return a new WeibullDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
WeibullDistribution_t*
UncertaintyA_createWeibullDistribution(UncertaintyA_t* ua);


/**
 * Creates a new BinomialDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the BinomialDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the BinomialDistribution_t
 * should be added.
 *
 * @return a new BinomialDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
BinomialDistribution_t*
UncertaintyA_createBinomialDistribution(UncertaintyA_t* ua);


/**
 * Creates a new GeometricDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the GeometricDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the GeometricDistribution_t
 * should be added.
 *
 * @return a new GeometricDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
GeometricDistribution_t*
UncertaintyA_createGeometricDistribution(UncertaintyA_t* ua);


/**
 * Creates a new HypergeometricDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the HypergeometricDistribution_t object
 * created.
 *
 * @param ua the UncertaintyA_t structure to which the
 * HypergeometricDistribution_t should be added.
 *
 * @return a new HypergeometricDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
HypergeometricDistribution_t*
UncertaintyA_createHypergeometricDistribution(UncertaintyA_t* ua);


/**
 * Creates a new NegativeBinomialDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the NegativeBinomialDistribution_t object
 * created.
 *
 * @param ua the UncertaintyA_t structure to which the
 * NegativeBinomialDistribution_t should be added.
 *
 * @return a new NegativeBinomialDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
NegativeBinomialDistribution_t*
UncertaintyA_createNegativeBinomialDistribution(UncertaintyA_t* ua);


/**
 * Creates a new PoissonDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the PoissonDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the PoissonDistribution_t
 * should be added.
 *
 * @return a new PoissonDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
PoissonDistribution_t*
UncertaintyA_createPoissonDistribution(UncertaintyA_t* ua);


/**
 * Creates a new BernoulliDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the BernoulliDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the BernoulliDistribution_t
 * should be added.
 *
 * @return a new BernoulliDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
BernoulliDistribution_t*
UncertaintyA_createBernoulliDistribution(UncertaintyA_t* ua);


/**
 * Creates a new CategoricalDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the CategoricalDistribution_t object
 * created.
 *
 * @param ua the UncertaintyA_t structure to which the
 * CategoricalDistribution_t should be added.
 *
 * @return a new CategoricalDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
CategoricalDistribution_t*
UncertaintyA_createCategoricalDistribution(UncertaintyA_t* ua);


/**
 * Creates a new MultivariateDistribution_t object, adds it to this
 * UncertaintyA_t object and returns the MultivariateDistribution_t object
 * created.
 *
 * @param ua the UncertaintyA_t structure to which the
 * MultivariateDistribution_t should be added.
 *
 * @return a new MultivariateDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
MultivariateDistribution_t*
UncertaintyA_createMultivariateDistribution(UncertaintyA_t* ua);


/**
 * Creates a new ExternalDistribution_t object, adds it to this UncertaintyA_t
 * object and returns the ExternalDistribution_t object created.
 *
 * @param ua the UncertaintyA_t structure to which the ExternalDistribution_t
 * should be added.
 *
 * @return a new ExternalDistribution_t object instance.
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
ExternalDistribution_t*
UncertaintyA_createExternalDistribution(UncertaintyA_t* ua);


/**
 * Unsets the value of the "uncertStatistics" element of this UncertaintyA_t.
 *
 * @param ua the UncertaintyA_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
int
UncertaintyA_unsetUncertStatistics(UncertaintyA_t * ua);


/**
 * Unsets the value of the "distribution" element of this UncertaintyA_t.
 *
 * @param ua the UncertaintyA_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof UncertaintyA_t
 */
LIBSBML_EXTERN
int
UncertaintyA_unsetDistribution(UncertaintyA_t * ua);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !UncertaintyA_H__ */


