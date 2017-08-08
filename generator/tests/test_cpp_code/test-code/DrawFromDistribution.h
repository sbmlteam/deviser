/**
 * @file DrawFromDistribution.h
 * @brief Definition of the DrawFromDistribution class.
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
 * @class DrawFromDistribution
 * @sbmlbrief{distrib} TODO:Definition of the DrawFromDistribution class.
 */


#ifndef DrawFromDistribution_H__
#define DrawFromDistribution_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/Distribution.h>
#include <sbml/packages/distrib/sbml/ListOfDistribInputs.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN DrawFromDistribution : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  ListOfDistribInputs mDistribInputs;
  Distribution* mDistribution;

  /** @endcond */

public:

  /**
   * Creates a new DrawFromDistribution using the given SBML Level, Version and
   * &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * DrawFromDistribution.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * DrawFromDistribution.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this DrawFromDistribution.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  DrawFromDistribution(unsigned int level =
    DistribExtension::getDefaultLevel(),
                       unsigned int version =
                         DistribExtension::getDefaultVersion(),
                       unsigned int pkgVersion =
                         DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new DrawFromDistribution using the given DistribPkgNamespaces
   * object.
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @throws SBMLConstructorException
   * Thrown if the given @p level and @p version combination, or this kind of
   * SBML object, are either invalid or mismatched with respect to the parent
   * SBMLDocument object.
   * @copydetails doc_note_setting_lv
   */
  DrawFromDistribution(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for DrawFromDistribution.
   *
   * @param orig the DrawFromDistribution instance to copy.
   */
  DrawFromDistribution(const DrawFromDistribution& orig);


  /**
   * Assignment operator for DrawFromDistribution.
   *
   * @param rhs the DrawFromDistribution object whose values are to be used as
   * the basis of the assignment.
   */
  DrawFromDistribution& operator=(const DrawFromDistribution& rhs);


  /**
   * Creates and returns a deep copy of this DrawFromDistribution object.
   *
   * @return a (deep) copy of this DrawFromDistribution object.
   */
  virtual DrawFromDistribution* clone() const;


  /**
   * Destructor for DrawFromDistribution.
   */
  virtual ~DrawFromDistribution();


  /**
   * Returns the value of the "distribution" element of this
   * DrawFromDistribution.
   *
   * @return the value of the "distribution" element of this
   * DrawFromDistribution as a Distribution*.
   */
  const Distribution* getDistribution() const;


  /**
   * Returns the value of the "distribution" element of this
   * DrawFromDistribution.
   *
   * @return the value of the "distribution" element of this
   * DrawFromDistribution as a Distribution*.
   */
  Distribution* getDistribution();


  /**
   * Predicate returning @c true if this DrawFromDistribution's "distribution"
   * element is set.
   *
   * @return @c true if this DrawFromDistribution's "distribution" element has
   * been set, otherwise @c false is returned.
   */
  bool isSetDistribution() const;


  /**
   * Sets the value of the "distribution" element of this DrawFromDistribution.
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
   * Creates a new BetaDistribution object, adds it to this
   * DrawFromDistribution object and returns the BetaDistribution object
   * created.
   *
   * @return a new BetaDistribution object instance.
   */
  BetaDistribution* createBetaDistribution();


  /**
   * Creates a new CauchyDistribution object, adds it to this
   * DrawFromDistribution object and returns the CauchyDistribution object
   * created.
   *
   * @return a new CauchyDistribution object instance.
   */
  CauchyDistribution* createCauchyDistribution();


  /**
   * Creates a new LogisticDistribution object, adds it to this
   * DrawFromDistribution object and returns the LogisticDistribution object
   * created.
   *
   * @return a new LogisticDistribution object instance.
   */
  LogisticDistribution* createLogisticDistribution();


  /**
   * Creates a new NormalDistribution object, adds it to this
   * DrawFromDistribution object and returns the NormalDistribution object
   * created.
   *
   * @return a new NormalDistribution object instance.
   */
  NormalDistribution* createNormalDistribution();


  /**
   * Creates a new BinomialDistribution object, adds it to this
   * DrawFromDistribution object and returns the BinomialDistribution object
   * created.
   *
   * @return a new BinomialDistribution object instance.
   */
  BinomialDistribution* createBinomialDistribution();


  /**
   * Creates a new GeometricDistribution object, adds it to this
   * DrawFromDistribution object and returns the GeometricDistribution object
   * created.
   *
   * @return a new GeometricDistribution object instance.
   */
  GeometricDistribution* createGeometricDistribution();


  /**
   * Creates a new BernoulliDistribution object, adds it to this
   * DrawFromDistribution object and returns the BernoulliDistribution object
   * created.
   *
   * @return a new BernoulliDistribution object instance.
   */
  BernoulliDistribution* createBernoulliDistribution();


  /**
   * Creates a new CategoricalDistribution object, adds it to this
   * DrawFromDistribution object and returns the CategoricalDistribution object
   * created.
   *
   * @return a new CategoricalDistribution object instance.
   */
  CategoricalDistribution* createCategoricalDistribution();


  /**
   * Creates a new MultivariateDistribution object, adds it to this
   * DrawFromDistribution object and returns the MultivariateDistribution
   * object created.
   *
   * @return a new MultivariateDistribution object instance.
   */
  MultivariateDistribution* createMultivariateDistribution();


  /**
   * Creates a new ExternalDistribution object, adds it to this
   * DrawFromDistribution object and returns the ExternalDistribution object
   * created.
   *
   * @return a new ExternalDistribution object instance.
   */
  ExternalDistribution* createExternalDistribution();


  /**
   * Unsets the value of the "distribution" element of this
   * DrawFromDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDistribution();


  /**
   * Returns the ListOfDistribInputs from this DrawFromDistribution.
   *
   * @return the ListOfDistribInputs from this DrawFromDistribution.
   */
  const ListOfDistribInputs* getListOfDistribInputs() const;


  /**
   * Returns the ListOfDistribInputs from this DrawFromDistribution.
   *
   * @return the ListOfDistribInputs from this DrawFromDistribution.
   */
  ListOfDistribInputs* getListOfDistribInputs();


  /**
   * Get a DistribInput from the DrawFromDistribution.
   *
   * @param n an unsigned int representing the index of the DistribInput to
   * retrieve.
   *
   * @return the nth DistribInput in the ListOfDistribInputs within this
   * DrawFromDistribution.
   *
   * @see getNumDistribInputs()
   */
  DistribInput* getDistribInput(unsigned int n);


  /**
   * Get a DistribInput from the DrawFromDistribution.
   *
   * @param n an unsigned int representing the index of the DistribInput to
   * retrieve.
   *
   * @return the nth DistribInput in the ListOfDistribInputs within this
   * DrawFromDistribution.
   *
   * @see getNumDistribInputs()
   */
  const DistribInput* getDistribInput(unsigned int n) const;


  /**
   * Get a DistribInput from the DrawFromDistribution based on its identifier.
   *
   * @param sid a string representing the identifier of the DistribInput to
   * retrieve.
   *
   * @return the DistribInput in the ListOfDistribInputs within this
   * DrawFromDistribution with the given id or NULL if no such DistribInput
   * exists.
   *
   * @see getDistribInput(unsigned int n)
   * @see getNumDistribInputs()
   */
  DistribInput* getDistribInput(const std::string& sid);


  /**
   * Get a DistribInput from the DrawFromDistribution based on its identifier.
   *
   * @param sid a string representing the identifier of the DistribInput to
   * retrieve.
   *
   * @return the DistribInput in the ListOfDistribInputs within this
   * DrawFromDistribution with the given id or NULL if no such DistribInput
   * exists.
   *
   * @see getDistribInput(unsigned int n)
   * @see getNumDistribInputs()
   */
  const DistribInput* getDistribInput(const std::string& sid) const;


  /**
   * Adds a copy of the given DistribInput to this DrawFromDistribution.
   *
   * @param di the DistribInput object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createDistribInput()
   */
  int addDistribInput(const DistribInput* di);


  /**
   * Get the number of DistribInput objects in this DrawFromDistribution.
   *
   * @return the number of DistribInput objects in this DrawFromDistribution.
   */
  unsigned int getNumDistribInputs() const;


  /**
   * Creates a new DistribInput object, adds it to this DrawFromDistribution
   * object and returns the DistribInput object created.
   *
   * @return a new DistribInput object instance.
   *
   * @see addDistribInput(const DistribInput* di)
   */
  DistribInput* createDistribInput();


  /**
   * Removes the nth DistribInput from this DrawFromDistribution and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the DistribInput to
   * remove.
   *
   * @return a pointer to the nth DistribInput in this DrawFromDistribution.
   *
   * @see getNumDistribInputs
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  DistribInput* removeDistribInput(unsigned int n);


  /**
   * Removes the DistribInput from this DrawFromDistribution based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the DistribInput to
   * remove.
   *
   * @return the DistribInput in this DrawFromDistribution based on the
   * identifier or NULL if no such DistribInput exists.
   *
   * @note the caller owns the returned object and is responsible for deleting
   * it.
   */
  DistribInput* removeDistribInput(const std::string& sid);


  /**
   * Returns the XML element name of this DrawFromDistribution object.
   *
   * For DrawFromDistribution, the XML element name is always @c
   * "drawFromDistribution".
   *
   * @return the name of this element, i.e. @c "drawFromDistribution".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this DrawFromDistribution object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_DISTRIB_DRAWFROMDISTRIBUTION, SBMLDistribTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * DrawFromDistribution object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * DrawFromDistribution have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the DrawFromDistribution object are:
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * Predicate returning @c true if this DrawFromDistribution's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this DrawFromDistribution's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * DrawFromDistribution.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this DrawFromDistribution.
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
   * DrawFromDistribution.
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
   * Returns the number of "elementName" in this DrawFromDistribution.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this DrawFromDistribution.
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
 * Creates a new DrawFromDistribution_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * DrawFromDistribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * DrawFromDistribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this DrawFromDistribution_t.
 *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination, or this kind of
 * SBML object, are either invalid or mismatched with respect to the parent
 * SBMLDocument object.
 * @copydetails doc_note_setting_lv
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
DrawFromDistribution_t *
DrawFromDistribution_create(
                            unsigned int level =
                              DistribExtension::getDefaultLevel(),
                            unsigned int version =
                              DistribExtension::getDefaultVersion(),
                            unsigned int pkgVersion =
                              DistribExtension::getDefaultPackageVersion());


/**
 * Creates and returns a deep copy of this DrawFromDistribution_t object.
 *
 * @param dfd the DrawFromDistribution_t structure.
 *
 * @return a (deep) copy of this DrawFromDistribution_t object.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
DrawFromDistribution_t*
DrawFromDistribution_clone(const DrawFromDistribution_t* dfd);


/**
 * Frees this DrawFromDistribution_t object.
 *
 * @param dfd the DrawFromDistribution_t structure.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
void
DrawFromDistribution_free(DrawFromDistribution_t* dfd);


/**
 * Returns the value of the "distribution" element of this
 * DrawFromDistribution_t.
 *
 * @param dfd the DrawFromDistribution_t structure whose distribution is
 * sought.
 *
 * @return the value of the "distribution" element of this
 * DrawFromDistribution_t as a Distribution*.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
const Distribution_t*
DrawFromDistribution_getDistribution(const DrawFromDistribution_t * dfd);


/**
 * Predicate returning @c 1 if this DrawFromDistribution_t's "distribution"
 * element is set.
 *
 * @param dfd the DrawFromDistribution_t structure.
 *
 * @return @c 1 if this DrawFromDistribution_t's "distribution" element has
 * been set, otherwise @c 0 is returned.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
int
DrawFromDistribution_isSetDistribution(const DrawFromDistribution_t * dfd);


/**
 * Sets the value of the "distribution" element of this DrawFromDistribution_t.
 *
 * @param dfd the DrawFromDistribution_t structure.
 *
 * @param distribution Distribution_t* value of the "distribution" element to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
int
DrawFromDistribution_setDistribution(DrawFromDistribution_t * dfd,
                                     const Distribution_t* distribution);


/**
 * Creates a new BetaDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the BetaDistribution_t object
 * created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * BetaDistribution_t should be added.
 *
 * @return a new BetaDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
BetaDistribution_t*
DrawFromDistribution_createBetaDistribution(DrawFromDistribution_t* dfd);


/**
 * Creates a new CauchyDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the CauchyDistribution_t object
 * created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * CauchyDistribution_t should be added.
 *
 * @return a new CauchyDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
CauchyDistribution_t*
DrawFromDistribution_createCauchyDistribution(DrawFromDistribution_t* dfd);


/**
 * Creates a new LogisticDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the LogisticDistribution_t object
 * created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * LogisticDistribution_t should be added.
 *
 * @return a new LogisticDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
LogisticDistribution_t*
DrawFromDistribution_createLogisticDistribution(DrawFromDistribution_t* dfd);


/**
 * Creates a new NormalDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the NormalDistribution_t object
 * created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * NormalDistribution_t should be added.
 *
 * @return a new NormalDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
NormalDistribution_t*
DrawFromDistribution_createNormalDistribution(DrawFromDistribution_t* dfd);


/**
 * Creates a new BinomialDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the BinomialDistribution_t object
 * created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * BinomialDistribution_t should be added.
 *
 * @return a new BinomialDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
BinomialDistribution_t*
DrawFromDistribution_createBinomialDistribution(DrawFromDistribution_t* dfd);


/**
 * Creates a new GeometricDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the GeometricDistribution_t object
 * created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * GeometricDistribution_t should be added.
 *
 * @return a new GeometricDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
GeometricDistribution_t*
DrawFromDistribution_createGeometricDistribution(DrawFromDistribution_t* dfd);


/**
 * Creates a new BernoulliDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the BernoulliDistribution_t object
 * created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * BernoulliDistribution_t should be added.
 *
 * @return a new BernoulliDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
BernoulliDistribution_t*
DrawFromDistribution_createBernoulliDistribution(DrawFromDistribution_t* dfd);


/**
 * Creates a new CategoricalDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the CategoricalDistribution_t
 * object created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * CategoricalDistribution_t should be added.
 *
 * @return a new CategoricalDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
CategoricalDistribution_t*
DrawFromDistribution_createCategoricalDistribution(DrawFromDistribution_t*
  dfd);


/**
 * Creates a new MultivariateDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the MultivariateDistribution_t
 * object created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * MultivariateDistribution_t should be added.
 *
 * @return a new MultivariateDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
MultivariateDistribution_t*
DrawFromDistribution_createMultivariateDistribution(DrawFromDistribution_t*
  dfd);


/**
 * Creates a new ExternalDistribution_t object, adds it to this
 * DrawFromDistribution_t object and returns the ExternalDistribution_t object
 * created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the
 * ExternalDistribution_t should be added.
 *
 * @return a new ExternalDistribution_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
ExternalDistribution_t*
DrawFromDistribution_createExternalDistribution(DrawFromDistribution_t* dfd);


/**
 * Unsets the value of the "distribution" element of this
 * DrawFromDistribution_t.
 *
 * @param dfd the DrawFromDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
int
DrawFromDistribution_unsetDistribution(DrawFromDistribution_t * dfd);


/**
 * Returns a ListOf_t* containing DistribInput_t objects from this
 * DrawFromDistribution_t.
 *
 * @param dfd the DrawFromDistribution_t structure whose "ListOfDistribInputs"
 * is sought.
 *
 * @return the "ListOfDistribInputs" from this DrawFromDistribution_t as a
 * ListOf_t *.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
ListOf_t*
DrawFromDistribution_getListOfDistribInputs(DrawFromDistribution_t* dfd);


/**
 * Get a DistribInput_t from the DrawFromDistribution_t.
 *
 * @param dfd the DrawFromDistribution_t structure to search.
 *
 * @param n an unsigned int representing the index of the DistribInput_t to
 * retrieve.
 *
 * @return the nth DistribInput_t in the ListOfDistribInputs within this
 * DrawFromDistribution.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
const DistribInput_t*
DrawFromDistribution_getDistribInput(DrawFromDistribution_t* dfd,
                                     unsigned int n);


/**
 * Get a DistribInput_t from the DrawFromDistribution_t based on its
 * identifier.
 *
 * @param dfd the DrawFromDistribution_t structure to search.
 *
 * @param sid a string representing the identifier of the DistribInput_t to
 * retrieve.
 *
 * @return the DistribInput_t in the ListOfDistribInputs within this
 * DrawFromDistribution with the given id or NULL if no such DistribInput_t
 * exists.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
const DistribInput_t*
DrawFromDistribution_getDistribInputById(DrawFromDistribution_t* dfd,
                                         const char *sid);


/**
 * Adds a copy of the given DistribInput_t to this DrawFromDistribution_t.
 *
 * @param dfd the DrawFromDistribution_t structure to which the DistribInput_t
 * should be added.
 *
 * @param di the DistribInput_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
int
DrawFromDistribution_addDistribInput(DrawFromDistribution_t* dfd,
                                     const DistribInput_t* di);


/**
 * Get the number of DistribInput_t objects in this DrawFromDistribution_t.
 *
 * @param dfd the DrawFromDistribution_t structure to query.
 *
 * @return the number of DistribInput_t objects in this DrawFromDistribution_t.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
unsigned int
DrawFromDistribution_getNumDistribInputs(DrawFromDistribution_t* dfd);


/**
 * Creates a new DistribInput_t object, adds it to this DrawFromDistribution_t
 * object and returns the DistribInput_t object created.
 *
 * @param dfd the DrawFromDistribution_t structure to which the DistribInput_t
 * should be added.
 *
 * @return a new DistribInput_t object instance.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
DistribInput_t*
DrawFromDistribution_createDistribInput(DrawFromDistribution_t* dfd);


/**
 * Removes the nth DistribInput_t from this DrawFromDistribution_t and returns
 * a pointer to it.
 *
 * @param dfd the DrawFromDistribution_t structure to search.
 *
 * @param n an unsigned int representing the index of the DistribInput_t to
 * remove.
 *
 * @return a pointer to the nth DistribInput_t in this DrawFromDistribution_t.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
DistribInput_t*
DrawFromDistribution_removeDistribInput(DrawFromDistribution_t* dfd,
                                        unsigned int n);


/**
 * Removes the DistribInput_t from this DrawFromDistribution_t based on its
 * identifier and returns a pointer to it.
 *
 * @param dfd the DrawFromDistribution_t structure to search.
 *
 * @param sid a string representing the identifier of the DistribInput_t to
 * remove.
 *
 * @return the DistribInput_t in this DrawFromDistribution_t based on the
 * identifier or NULL if no such DistribInput_t exists.
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
DistribInput_t*
DrawFromDistribution_removeDistribInputById(DrawFromDistribution_t* dfd,
                                            const char* sid);


/**
 * Predicate returning @c 1 if all the required elements for this
 * DrawFromDistribution_t object have been set.
 *
 * @param dfd the DrawFromDistribution_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this
 * DrawFromDistribution_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the DrawFromDistribution_t object are:
 *
 * @memberof DrawFromDistribution_t
 */
LIBSBML_EXTERN
int
DrawFromDistribution_hasRequiredElements(const DrawFromDistribution_t * dfd);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !DrawFromDistribution_H__ */


