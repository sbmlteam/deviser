/**
 * @file Association.h
 * @brief Definition of the Association class.
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
 * @class Association
 * @sbmlbrief{fbc} TODO:Definition of the Association class.
 */


#ifndef Association_H__
#define Association_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/fbc/common/fbcfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/fbc/extension/FbcExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class FbcAnd;
class FbcOr;
class GeneProductRef;

class LIBSBML_EXTERN Association : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new Association using the given SBML Level, Version and
   * &ldquo;fbc&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * Association.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Association.
   *
   * @param pkgVersion an unsigned int, the SBML Fbc Version to assign to this
   * Association.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Association(unsigned int level = FbcExtension::getDefaultLevel(),
              unsigned int version = FbcExtension::getDefaultVersion(),
              unsigned int pkgVersion =
                FbcExtension::getDefaultPackageVersion());


  /**
   * Creates a new Association using the given FbcPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param fbcns the FbcPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Association(FbcPkgNamespaces *fbcns);


  /**
   * Copy constructor for Association.
   *
   * @param orig the Association instance to copy.
   */
  Association(const Association& orig);


  /**
   * Assignment operator for Association.
   *
   * @param rhs the Association object whose values are to be used as the basis
   * of the assignment.
   */
  Association& operator=(const Association& rhs);


  /**
   * Creates and returns a deep copy of this Association object.
   *
   * @return a (deep) copy of this Association object.
   */
  virtual Association* clone() const;


  /**
   * Destructor for Association.
   */
  virtual ~Association();


  /**
   * Predicate returning @c true if this abstract "Association" is of type
   * FbcAnd
   *
   * @return @c true if this abstract "Association" is of type FbcAnd, @c false
   * otherwise
   */
  virtual bool isFbcAnd() const;


  /**
   * Predicate returning @c true if this abstract "Association" is of type
   * FbcOr
   *
   * @return @c true if this abstract "Association" is of type FbcOr, @c false
   * otherwise
   */
  virtual bool isFbcOr() const;


  /**
   * Predicate returning @c true if this abstract "Association" is of type
   * GeneProductRef
   *
   * @return @c true if this abstract "Association" is of type GeneProductRef,
   * @c false otherwise
   */
  virtual bool isGeneProductRef() const;


  /**
   * Returns the XML element name of this Association object.
   *
   * For Association, the XML element name is always @c "association".
   *
   * @return the name of this element, i.e. @c "association".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the XML name of this Association object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBML type code for this Association object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_FBC_ASSOCIATION, SBMLFbcTypeCode_t}.
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
   * Gets the value of the "attributeName" attribute of this Association.
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
   * Gets the value of the "attributeName" attribute of this Association.
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
   * Gets the value of the "attributeName" attribute of this Association.
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
   * Gets the value of the "attributeName" attribute of this Association.
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
   * Gets the value of the "attributeName" attribute of this Association.
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
   * Predicate returning @c true if this Association's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Association's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Association.
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
   * Sets the value of the "attributeName" attribute of this Association.
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
   * Sets the value of the "attributeName" attribute of this Association.
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
   * Sets the value of the "attributeName" attribute of this Association.
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
   * Sets the value of the "attributeName" attribute of this Association.
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
   * Unsets the value of the "attributeName" attribute of this Association.
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
 * Creates a new FbcAnd (Association_t) using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Association_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Association_t.
 *
 * @param pkgVersion an unsigned int, the SBML Fbc Version to assign to this
 * Association_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Association_t
 */
LIBSBML_EXTERN
Association_t *
Association_createFbcAnd(unsigned int level,
                         unsigned int version,
                         unsigned int pkgVersion);


/**
 * Creates a new FbcOr (Association_t) using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Association_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Association_t.
 *
 * @param pkgVersion an unsigned int, the SBML Fbc Version to assign to this
 * Association_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Association_t
 */
LIBSBML_EXTERN
Association_t *
Association_createFbcOr(unsigned int level,
                        unsigned int version,
                        unsigned int pkgVersion);


/**
 * Creates a new GeneProductRef (Association_t) using the given SBML Level,
 * Version and &ldquo;fbc&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * Association_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Association_t.
 *
 * @param pkgVersion an unsigned int, the SBML Fbc Version to assign to this
 * Association_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Association_t
 */
LIBSBML_EXTERN
Association_t *
Association_createGeneProductRef(unsigned int level,
                                 unsigned int version,
                                 unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Association_t object.
 *
 * @param a the Association_t structure.
 *
 * @return a (deep) copy of this Association_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Association_t
 */
LIBSBML_EXTERN
Association_t*
Association_clone(const Association_t* a);


/**
 * Frees this Association_t object.
 *
 * @param a the Association_t structure.
 *
 * @memberof Association_t
 */
LIBSBML_EXTERN
void
Association_free(Association_t* a);


/**
 * Predicate returning @c 1 if this Association_t is of type FbcAnd_t
 *
 * @param a the Association_t structure.
 *
 * @return @c 1 if this Association_t is of type FbcAnd_t, @c 0 otherwise
 *
 * @memberof Association_t
 */
LIBSBML_EXTERN
int
Association_isFbcAnd(const Association_t * a);


/**
 * Predicate returning @c 1 if this Association_t is of type FbcOr_t
 *
 * @param a the Association_t structure.
 *
 * @return @c 1 if this Association_t is of type FbcOr_t, @c 0 otherwise
 *
 * @memberof Association_t
 */
LIBSBML_EXTERN
int
Association_isFbcOr(const Association_t * a);


/**
 * Predicate returning @c 1 if this Association_t is of type GeneProductRef_t
 *
 * @param a the Association_t structure.
 *
 * @return @c 1 if this Association_t is of type GeneProductRef_t, @c 0
 * otherwise
 *
 * @memberof Association_t
 */
LIBSBML_EXTERN
int
Association_isGeneProductRef(const Association_t * a);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Association_H__ */


