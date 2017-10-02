/**
 * @file Distribution.h
 * @brief Definition of the Distribution class.
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
 * @class Distribution
 * @sbmlbrief{distrib} TODO:Definition of the Distribution class.
 */


#ifndef Distribution_H__
#define Distribution_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class BetaDistribution;
class CauchyDistribution;
class ExponentialDistribution;
class LogisticDistribution;
class NormalDistribution;
class BinomialDistribution;
class GeometricDistribution;
class BernoulliDistribution;
class CategoricalDistribution;
class MultivariateDistribution;
class ExternalDistribution;

class LIBSBML_EXTERN Distribution : public SBase
{

public:

  /**
   * Creates a new Distribution using the given SBML Level, Version and
   * &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * Distribution.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Distribution.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this Distribution.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Distribution(unsigned int level = DistribExtension::getDefaultLevel(),
               unsigned int version = DistribExtension::getDefaultVersion(),
               unsigned int pkgVersion =
                 DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new Distribution using the given DistribPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Distribution(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for Distribution.
   *
   * @param orig the Distribution instance to copy.
   */
  Distribution(const Distribution& orig);


  /**
   * Assignment operator for Distribution.
   *
   * @param rhs the Distribution object whose values are to be used as the
   * basis of the assignment.
   */
  Distribution& operator=(const Distribution& rhs);


  /**
   * Creates and returns a deep copy of this Distribution object.
   *
   * @return a (deep) copy of this Distribution object.
   */
  virtual Distribution* clone() const;


  /**
   * Destructor for Distribution.
   */
  virtual ~Distribution();


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * BetaDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * BetaDistribution, @c false otherwise
   */
  virtual bool isBetaDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * CauchyDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * CauchyDistribution, @c false otherwise
   */
  virtual bool isCauchyDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * ExponentialDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * ExponentialDistribution, @c false otherwise
   */
  virtual bool isExponentialDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * LogisticDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * LogisticDistribution, @c false otherwise
   */
  virtual bool isLogisticDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * NormalDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * NormalDistribution, @c false otherwise
   */
  virtual bool isNormalDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * BinomialDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * BinomialDistribution, @c false otherwise
   */
  virtual bool isBinomialDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * GeometricDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * GeometricDistribution, @c false otherwise
   */
  virtual bool isGeometricDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * BernoulliDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * BernoulliDistribution, @c false otherwise
   */
  virtual bool isBernoulliDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * CategoricalDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * CategoricalDistribution, @c false otherwise
   */
  virtual bool isCategoricalDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * MultivariateDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * MultivariateDistribution, @c false otherwise
   */
  virtual bool isMultivariateDistribution() const;


  /**
   * Predicate returning @c true if this abstract "Distribution" is of type
   * ExternalDistribution
   *
   * @return @c true if this abstract "Distribution" is of type
   * ExternalDistribution, @c false otherwise
   */
  virtual bool isExternalDistribution() const;


  /**
   * Returns the XML element name of this Distribution object.
   *
   * For Distribution, the XML element name is always @c "distribution".
   *
   * @return the name of this element, i.e. @c "distribution".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Distribution object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_DISTRIB_DISTRIBUTION, SBMLDistribTypeCode_t}.
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
   * Enables/disables the given package with this element
   */
  virtual void enablePackageInternal(const std::string& pkgURI,
                                     const std::string& pkgPrefix,
                                     bool flag);

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Distribution.
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
   * Gets the value of the "attributeName" attribute of this Distribution.
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
   * Gets the value of the "attributeName" attribute of this Distribution.
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
   * Gets the value of the "attributeName" attribute of this Distribution.
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
   * Gets the value of the "attributeName" attribute of this Distribution.
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
   * Gets the value of the "attributeName" attribute of this Distribution.
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
   * Predicate returning @c true if this Distribution's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Distribution's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Distribution.
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
   * Sets the value of the "attributeName" attribute of this Distribution.
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
   * Sets the value of the "attributeName" attribute of this Distribution.
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
   * Sets the value of the "attributeName" attribute of this Distribution.
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
   * Sets the value of the "attributeName" attribute of this Distribution.
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
   * Sets the value of the "attributeName" attribute of this Distribution.
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
   * Unsets the value of the "attributeName" attribute of this Distribution.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


protected:

};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new BetaDistribution (Distribution_t) using the given SBML Level,
 * Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createBetaDistribution(unsigned int level,
                                    unsigned int version,
                                    unsigned int pkgVersion);


/**
 * Creates a new CauchyDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createCauchyDistribution(unsigned int level,
                                      unsigned int version,
                                      unsigned int pkgVersion);


/**
 * Creates a new ExponentialDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createExponentialDistribution(unsigned int level,
                                           unsigned int version,
                                           unsigned int pkgVersion);


/**
 * Creates a new LogisticDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createLogisticDistribution(unsigned int level,
                                        unsigned int version,
                                        unsigned int pkgVersion);


/**
 * Creates a new NormalDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createNormalDistribution(unsigned int level,
                                      unsigned int version,
                                      unsigned int pkgVersion);


/**
 * Creates a new BinomialDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createBinomialDistribution(unsigned int level,
                                        unsigned int version,
                                        unsigned int pkgVersion);


/**
 * Creates a new GeometricDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createGeometricDistribution(unsigned int level,
                                         unsigned int version,
                                         unsigned int pkgVersion);


/**
 * Creates a new BernoulliDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createBernoulliDistribution(unsigned int level,
                                         unsigned int version,
                                         unsigned int pkgVersion);


/**
 * Creates a new CategoricalDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createCategoricalDistribution(unsigned int level,
                                           unsigned int version,
                                           unsigned int pkgVersion);


/**
 * Creates a new MultivariateDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createMultivariateDistribution(unsigned int level,
                                            unsigned int version,
                                            unsigned int pkgVersion);


/**
 * Creates a new ExternalDistribution (Distribution_t) using the given SBML
 * Level, Version and &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Distribution_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Distribution_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this Distribution_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t *
Distribution_createExternalDistribution(unsigned int level,
                                        unsigned int version,
                                        unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Distribution_t object.
 *
 * @param d the Distribution_t structure.
 *
 * @return a (deep) copy of this Distribution_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
Distribution_t*
Distribution_clone(const Distribution_t* d);


/**
 * Frees this Distribution_t object.
 *
 * @param d the Distribution_t structure.
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
void
Distribution_free(Distribution_t* d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * BetaDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type BetaDistribution_t, @c 0
 * otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isBetaDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * CauchyDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type CauchyDistribution_t, @c 0
 * otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isCauchyDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * ExponentialDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type ExponentialDistribution_t,
 * @c 0 otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isExponentialDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * LogisticDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type LogisticDistribution_t, @c 0
 * otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isLogisticDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * NormalDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type NormalDistribution_t, @c 0
 * otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isNormalDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * BinomialDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type BinomialDistribution_t, @c 0
 * otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isBinomialDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * GeometricDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type GeometricDistribution_t, @c 0
 * otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isGeometricDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * BernoulliDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type BernoulliDistribution_t, @c 0
 * otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isBernoulliDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * CategoricalDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type CategoricalDistribution_t,
 * @c 0 otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isCategoricalDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * MultivariateDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type MultivariateDistribution_t,
 * @c 0 otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isMultivariateDistribution(const Distribution_t * d);


/**
 * Predicate returning @c 1 if this Distribution_t is of type
 * ExternalDistribution_t
 *
 * @param d the Distribution_t structure.
 *
 * @return @c 1 if this Distribution_t is of type ExternalDistribution_t, @c 0
 * otherwise
 *
 * @memberof Distribution_t
 */
LIBSBML_EXTERN
int
Distribution_isExternalDistribution(const Distribution_t * d);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Distribution_H__ */


