/**
 * @file BetaDistribution.h
 * @brief Definition of the BetaDistribution class.
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
 * @class BetaDistribution
 * @sbmlbrief{distrib} TODO:Definition of the BetaDistribution class.
 */


#ifndef BetaDistribution_H__
#define BetaDistribution_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/packages/distrib/sbml/ContinuousUnivariateDistribution.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/UncertValue.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN BetaDistribution : public ContinuousUnivariateDistribution
{
protected:

  /** @cond doxygenLibsbmlInternal */

  UncertValue* mAlpha;
  UncertValue* mBeta;

  /** @endcond */

public:

  /**
   * Creates a new BetaDistribution using the given SBML Level, Version and
   * &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * BetaDistribution.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * BetaDistribution.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this BetaDistribution.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  BetaDistribution(unsigned int level = DistribExtension::getDefaultLevel(),
                   unsigned int version =
                     DistribExtension::getDefaultVersion(),
                   unsigned int pkgVersion =
                     DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new BetaDistribution using the given DistribPkgNamespaces
   * object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  BetaDistribution(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for BetaDistribution.
   *
   * @param orig the BetaDistribution instance to copy.
   */
  BetaDistribution(const BetaDistribution& orig);


  /**
   * Assignment operator for BetaDistribution.
   *
   * @param rhs the BetaDistribution object whose values are to be used as the
   * basis of the assignment.
   */
  BetaDistribution& operator=(const BetaDistribution& rhs);


  /**
   * Creates and returns a deep copy of this BetaDistribution object.
   *
   * @return a (deep) copy of this BetaDistribution object.
   */
  virtual BetaDistribution* clone() const;


  /**
   * Destructor for BetaDistribution.
   */
  virtual ~BetaDistribution();


  /**
   * Returns the value of the "alpha" element of this BetaDistribution.
   *
   * @return the value of the "alpha" element of this BetaDistribution as a
   * UncertValue*.
   */
  const UncertValue* getAlpha() const;


  /**
   * Returns the value of the "alpha" element of this BetaDistribution.
   *
   * @return the value of the "alpha" element of this BetaDistribution as a
   * UncertValue*.
   */
  UncertValue* getAlpha();


  /**
   * Returns the value of the "beta" element of this BetaDistribution.
   *
   * @return the value of the "beta" element of this BetaDistribution as a
   * UncertValue*.
   */
  const UncertValue* getBeta() const;


  /**
   * Returns the value of the "beta" element of this BetaDistribution.
   *
   * @return the value of the "beta" element of this BetaDistribution as a
   * UncertValue*.
   */
  UncertValue* getBeta();


  /**
   * Predicate returning @c true if this BetaDistribution's "alpha" element is
   * set.
   *
   * @return @c true if this BetaDistribution's "alpha" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetAlpha() const;


  /**
   * Predicate returning @c true if this BetaDistribution's "beta" element is
   * set.
   *
   * @return @c true if this BetaDistribution's "beta" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetBeta() const;


  /**
   * Sets the value of the "alpha" element of this BetaDistribution.
   *
   * @param alpha UncertValue* value of the "alpha" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setAlpha(const UncertValue* alpha);


  /**
   * Sets the value of the "beta" element of this BetaDistribution.
   *
   * @param beta UncertValue* value of the "beta" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBeta(const UncertValue* beta);


  /**
   * Creates a new UncertValue object, adds it to this BetaDistribution object
   * and returns the UncertValue object created.
   *
   * @return a new UncertValue object instance.
   */
  UncertValue* createAlpha();


  /**
   * Creates a new UncertValue object, adds it to this BetaDistribution object
   * and returns the UncertValue object created.
   *
   * @return a new UncertValue object instance.
   */
  UncertValue* createBeta();


  /**
   * Unsets the value of the "alpha" element of this BetaDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetAlpha();


  /**
   * Unsets the value of the "beta" element of this BetaDistribution.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBeta();


  /**
   * Returns the XML element name of this BetaDistribution object.
   *
   * For BetaDistribution, the XML element name is always @c
   * "betaDistribution".
   *
   * @return the name of this element, i.e. @c "betaDistribution".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this BetaDistribution object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_DISTRIB_BETADISTRIBUTION, SBMLDistribTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * BetaDistribution object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * BetaDistribution have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * BetaDistribution object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * BetaDistribution have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the BetaDistribution object are:
   * @li "alpha"
   * @li "beta"
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
   * Gets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Gets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Gets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Gets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Gets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Gets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Predicate returning @c true if this BetaDistribution's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this BetaDistribution's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Sets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Sets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Sets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Sets the value of the "attributeName" attribute of this BetaDistribution.
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
   * Sets the value of the "attributeName" attribute of this BetaDistribution.
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
   * BetaDistribution.
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
   * Creates and returns an new "elementName" object in this BetaDistribution.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this BetaDistribution.
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
   * BetaDistribution.
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
   * Returns the number of "elementName" in this BetaDistribution.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this BetaDistribution.
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
 * Creates a new BetaDistribution_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * BetaDistribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * BetaDistribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this BetaDistribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
BetaDistribution_t *
BetaDistribution_create(unsigned int level,
                        unsigned int version,
                        unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this BetaDistribution_t object.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @return a (deep) copy of this BetaDistribution_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
BetaDistribution_t*
BetaDistribution_clone(const BetaDistribution_t* bd);


/**
 * Frees this BetaDistribution_t object.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
void
BetaDistribution_free(BetaDistribution_t* bd);


/**
 * Returns the value of the "alpha" element of this BetaDistribution_t.
 *
 * @param bd the BetaDistribution_t structure whose alpha is sought.
 *
 * @return the value of the "alpha" element of this BetaDistribution_t as a
 * UncertValue*.
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
const UncertValue_t*
BetaDistribution_getAlpha(const BetaDistribution_t * bd);


/**
 * Returns the value of the "beta" element of this BetaDistribution_t.
 *
 * @param bd the BetaDistribution_t structure whose beta is sought.
 *
 * @return the value of the "beta" element of this BetaDistribution_t as a
 * UncertValue*.
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
const UncertValue_t*
BetaDistribution_getBeta(const BetaDistribution_t * bd);


/**
 * Predicate returning @c 1 (true) if this BetaDistribution_t's "alpha" element
 * is set.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @return @c 1 (true) if this BetaDistribution_t's "alpha" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
int
BetaDistribution_isSetAlpha(const BetaDistribution_t * bd);


/**
 * Predicate returning @c 1 (true) if this BetaDistribution_t's "beta" element
 * is set.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @return @c 1 (true) if this BetaDistribution_t's "beta" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
int
BetaDistribution_isSetBeta(const BetaDistribution_t * bd);


/**
 * Sets the value of the "alpha" element of this BetaDistribution_t.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @param alpha UncertValue_t* value of the "alpha" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
int
BetaDistribution_setAlpha(BetaDistribution_t * bd,
                          const UncertValue_t* alpha);


/**
 * Sets the value of the "beta" element of this BetaDistribution_t.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @param beta UncertValue_t* value of the "beta" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
int
BetaDistribution_setBeta(BetaDistribution_t * bd, const UncertValue_t* beta);


/**
 * Creates a new UncertValue_t object, adds it to this BetaDistribution_t
 * object and returns the UncertValue_t object created.
 *
 * @param bd the BetaDistribution_t structure to which the UncertValue_t should
 * be added.
 *
 * @return a new UncertValue_t object instance.
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
UncertValue_t*
BetaDistribution_createAlpha(BetaDistribution_t* bd);


/**
 * Creates a new UncertValue_t object, adds it to this BetaDistribution_t
 * object and returns the UncertValue_t object created.
 *
 * @param bd the BetaDistribution_t structure to which the UncertValue_t should
 * be added.
 *
 * @return a new UncertValue_t object instance.
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
UncertValue_t*
BetaDistribution_createBeta(BetaDistribution_t* bd);


/**
 * Unsets the value of the "alpha" element of this BetaDistribution_t.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
int
BetaDistribution_unsetAlpha(BetaDistribution_t * bd);


/**
 * Unsets the value of the "beta" element of this BetaDistribution_t.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
int
BetaDistribution_unsetBeta(BetaDistribution_t * bd);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * BetaDistribution_t object have been set.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * BetaDistribution_t have been set, otherwise @c 0 is returned.
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
int
BetaDistribution_hasRequiredAttributes(const BetaDistribution_t * bd);


/**
 * Predicate returning @c 1 if all the required elements for this
 * BetaDistribution_t object have been set.
 *
 * @param bd the BetaDistribution_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this
 * BetaDistribution_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the BetaDistribution_t object are:
 * @li "alpha"
 * @li "beta"
 *
 * @memberof BetaDistribution_t
 */
LIBSBML_EXTERN
int
BetaDistribution_hasRequiredElements(const BetaDistribution_t * bd);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !BetaDistribution_H__ */


