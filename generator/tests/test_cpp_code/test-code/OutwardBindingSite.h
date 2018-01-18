/**
 * @file OutwardBindingSite.h
 * @brief Definition of the OutwardBindingSite class.
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
 * @class OutwardBindingSite
 * @sbmlbrief{multi} TODO:Definition of the OutwardBindingSite class.
 */

/**
 * <!-- ~ ~ ~ ~ ~ Start of common documentation strings ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * The following text is used as common documentation blocks copied multiple
 * times elsewhere in this file. The use of @class is a hack needed because
 * Doxygen's @copydetails command has limited functionality. Symbols
 * beginning with "doc_" are marked as ignored in our Doxygen configuration.
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ -->
 *
 *
 * @class doc_outwardbindingsite_bindingStatus
 *
 * @par
 * The attribute "bindingStatus" on a OutwardBindingSite object is used to
 * TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Multi specification, the following are the
 * allowable values for "bindingStatus":
 * <ul>
 * <li> @c "bound", TODO:add description
 *
 * <li> @c "unbound", TODO:add description
 *
 * <li> @c "either", TODO:add description
 *
 * </ul>
 */


#ifndef OutwardBindingSite_H__
#define OutwardBindingSite_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/multi/common/multifwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/multi/extension/MultiExtension.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN OutwardBindingSite : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  BindingStatus_t mBindingStatus;
  std::string mComponent;

  /** @endcond */

public:

  /**
   * Creates a new OutwardBindingSite using the given SBML Level, Version and
   * &ldquo;multi&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * OutwardBindingSite.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * OutwardBindingSite.
   *
   * @param pkgVersion an unsigned int, the SBML Multi Version to assign to
   * this OutwardBindingSite.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  OutwardBindingSite(unsigned int level = MultiExtension::getDefaultLevel(),
                     unsigned int version =
                       MultiExtension::getDefaultVersion(),
                     unsigned int pkgVersion =
                       MultiExtension::getDefaultPackageVersion());


  /**
   * Creates a new OutwardBindingSite using the given MultiPkgNamespaces
   * object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param multins the MultiPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  OutwardBindingSite(MultiPkgNamespaces *multins);


  /**
   * Copy constructor for OutwardBindingSite.
   *
   * @param orig the OutwardBindingSite instance to copy.
   */
  OutwardBindingSite(const OutwardBindingSite& orig);


  /**
   * Assignment operator for OutwardBindingSite.
   *
   * @param rhs the OutwardBindingSite object whose values are to be used as
   * the basis of the assignment.
   */
  OutwardBindingSite& operator=(const OutwardBindingSite& rhs);


  /**
   * Creates and returns a deep copy of this OutwardBindingSite object.
   *
   * @return a (deep) copy of this OutwardBindingSite object.
   */
  virtual OutwardBindingSite* clone() const;


  /**
   * Destructor for OutwardBindingSite.
   */
  virtual ~OutwardBindingSite();


  /**
   * Returns the value of the "id" attribute of this OutwardBindingSite.
   *
   * @return the value of the "id" attribute of this OutwardBindingSite as a
   * string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this OutwardBindingSite.
   *
   * @return the value of the "name" attribute of this OutwardBindingSite as a
   * string.
   */
  virtual const std::string& getName() const;


  /**
   * Returns the value of the "bindingStatus" attribute of this
   * OutwardBindingSite.
   *
   * @return the value of the "bindingStatus" attribute of this
   * OutwardBindingSite as a BindingStatus_t.
   *
   * @copydetails doc_outwardbindingsite_bindingStatus
   * @if clike The value is drawn from the enumeration @ref BindingStatus_t
   * @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{MULTI_BINDING_STATUS_BOUND, BindingStatus_t}
   * @li @sbmlconstant{MULTI_BINDING_STATUS_UNBOUND, BindingStatus_t}
   * @li @sbmlconstant{MULTI_BINDING_STATUS_EITHER, BindingStatus_t}
   * @li @sbmlconstant{OUTWARD_BINDING_SITE_BINDING_STATUS_INVALID,
   * BindingStatus_t}
   */
  BindingStatus_t getBindingStatus() const;


  /**
   * Returns the value of the "bindingStatus" attribute of this
   * OutwardBindingSite.
   *
   * @return the value of the "bindingStatus" attribute of this
   * OutwardBindingSite as a string.
   *
   * @copydetails doc_outwardbindingsite_bindingStatus
   * The possible values returned by this method are:
   * @li @c "bound"
   * @li @c "unbound"
   * @li @c "either"
   * @li @c "invalid OutwardBindingSiteBindingStatus"
   */
  const std::string& getBindingStatusAsString() const;


  /**
   * Returns the value of the "component" attribute of this OutwardBindingSite.
   *
   * @return the value of the "component" attribute of this OutwardBindingSite
   * as a string.
   */
  const std::string& getComponent() const;


  /**
   * Predicate returning @c true if this OutwardBindingSite's "id" attribute is
   * set.
   *
   * @return @c true if this OutwardBindingSite's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this OutwardBindingSite's "name" attribute
   * is set.
   *
   * @return @c true if this OutwardBindingSite's "name" attribute has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Predicate returning @c true if this OutwardBindingSite's "bindingStatus"
   * attribute is set.
   *
   * @return @c true if this OutwardBindingSite's "bindingStatus" attribute has
   * been set, otherwise @c false is returned.
   *
   * @copydetails doc_outwardbindingsite_bindingStatus
   */
  bool isSetBindingStatus() const;


  /**
   * Predicate returning @c true if this OutwardBindingSite's "component"
   * attribute is set.
   *
   * @return @c true if this OutwardBindingSite's "component" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetComponent() const;


  /**
   * Sets the value of the "id" attribute of this OutwardBindingSite.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * Calling this function with @p id = @c NULL or an empty string is
   * equivalent to calling unsetId().
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "name" attribute of this OutwardBindingSite.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p name = @c NULL or an empty string is
   * equivalent to calling unsetName().
   */
  virtual int setName(const std::string& name);


  /**
   * Sets the value of the "bindingStatus" attribute of this
   * OutwardBindingSite.
   *
   * @param bindingStatus @if clike BindingStatus_t@else int@endif value of the
   * "bindingStatus" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_outwardbindingsite_bindingStatus
   */
  int setBindingStatus(const BindingStatus_t bindingStatus);


  /**
   * Sets the value of the "bindingStatus" attribute of this
   * OutwardBindingSite.
   *
   * @param bindingStatus std::string& of the "bindingStatus" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_outwardbindingsite_bindingStatus
   */
  int setBindingStatus(const std::string& bindingStatus);


  /**
   * Sets the value of the "component" attribute of this OutwardBindingSite.
   *
   * @param component std::string& value of the "component" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setComponent(const std::string& component);


  /**
   * Unsets the value of the "id" attribute of this OutwardBindingSite.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "name" attribute of this OutwardBindingSite.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetName();


  /**
   * Unsets the value of the "bindingStatus" attribute of this
   * OutwardBindingSite.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_outwardbindingsite_bindingStatus
   */
  int unsetBindingStatus();


  /**
   * Unsets the value of the "component" attribute of this OutwardBindingSite.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetComponent();


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this OutwardBindingSite object.
   *
   * For OutwardBindingSite, the XML element name is always
   * @c "outwardBindingSite".
   *
   * @return the name of this element, i.e. @c "outwardBindingSite".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this OutwardBindingSite object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_MULTI_OUTWARD_BINDING_SITE, SBMLMultiTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * OutwardBindingSite object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * OutwardBindingSite have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the OutwardBindingSite object are:
   * @li "bindingStatus"
   * @li "component"
   */
  virtual bool hasRequiredAttributes() const;



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
   * Gets the value of the "attributeName" attribute of this
   * OutwardBindingSite.
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
   * OutwardBindingSite.
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
   * OutwardBindingSite.
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
   * OutwardBindingSite.
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
   * OutwardBindingSite.
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
   * Predicate returning @c true if this OutwardBindingSite's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this OutwardBindingSite's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * OutwardBindingSite.
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
   * OutwardBindingSite.
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
   * OutwardBindingSite.
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
   * OutwardBindingSite.
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
   * OutwardBindingSite.
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
   * OutwardBindingSite.
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
 * Creates a new OutwardBindingSite_t using the given SBML Level, Version and
 * &ldquo;multi&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * OutwardBindingSite_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * OutwardBindingSite_t.
 *
 * @param pkgVersion an unsigned int, the SBML Multi Version to assign to this
 * OutwardBindingSite_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
OutwardBindingSite_t *
OutwardBindingSite_create(unsigned int level,
                          unsigned int version,
                          unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this OutwardBindingSite_t object.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @return a (deep) copy of this OutwardBindingSite_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
OutwardBindingSite_t*
OutwardBindingSite_clone(const OutwardBindingSite_t* obs);


/**
 * Frees this OutwardBindingSite_t object.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
void
OutwardBindingSite_free(OutwardBindingSite_t* obs);


/**
 * Returns the value of the "id" attribute of this OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this OutwardBindingSite_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
char *
OutwardBindingSite_getId(const OutwardBindingSite_t * obs);


/**
 * Returns the value of the "name" attribute of this OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this OutwardBindingSite_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
char *
OutwardBindingSite_getName(const OutwardBindingSite_t * obs);


/**
 * Returns the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure whose bindingStatus is sought.
 *
 * @return the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t as a BindingStatus_t.
 *
 * @copydetails doc_outwardbindingsite_bindingStatus
 * @if clike The value is drawn from the enumeration @ref BindingStatus_t
 * @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{MULTI_BINDING_STATUS_BOUND, BindingStatus_t}
 * @li @sbmlconstant{MULTI_BINDING_STATUS_UNBOUND, BindingStatus_t}
 * @li @sbmlconstant{MULTI_BINDING_STATUS_EITHER, BindingStatus_t}
 * @li @sbmlconstant{OUTWARD_BINDING_SITE_BINDING_STATUS_INVALID,
 * BindingStatus_t}
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
BindingStatus_t
OutwardBindingSite_getBindingStatus(const OutwardBindingSite_t * obs);


/**
 * Returns the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure whose bindingStatus is sought.
 *
 * @return the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t as a const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_outwardbindingsite_bindingStatus
 * The possible values returned by this method are:
 * @li @c "bound"
 * @li @c "unbound"
 * @li @c "either"
 * @li @c "invalid OutwardBindingSiteBindingStatus"
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
const char *
OutwardBindingSite_getBindingStatusAsString(const OutwardBindingSite_t * obs);


/**
 * Returns the value of the "component" attribute of this OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure whose component is sought.
 *
 * @return the value of the "component" attribute of this OutwardBindingSite_t
 * as a pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
char *
OutwardBindingSite_getComponent(const OutwardBindingSite_t * obs);


/**
 * Predicate returning @c 1 (true) if this OutwardBindingSite_t's "id"
 * attribute is set.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @return @c 1 (true) if this OutwardBindingSite_t's "id" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_isSetId(const OutwardBindingSite_t * obs);


/**
 * Predicate returning @c 1 (true) if this OutwardBindingSite_t's "name"
 * attribute is set.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @return @c 1 (true) if this OutwardBindingSite_t's "name" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_isSetName(const OutwardBindingSite_t * obs);


/**
 * Predicate returning @c 1 (true) if this OutwardBindingSite_t's
 * "bindingStatus" attribute is set.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @return @c 1 (true) if this OutwardBindingSite_t's "bindingStatus" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_outwardbindingsite_bindingStatus
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_isSetBindingStatus(const OutwardBindingSite_t * obs);


/**
 * Predicate returning @c 1 (true) if this OutwardBindingSite_t's "component"
 * attribute is set.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @return @c 1 (true) if this OutwardBindingSite_t's "component" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_isSetComponent(const OutwardBindingSite_t * obs);


/**
 * Sets the value of the "id" attribute of this OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling OutwardBindingSite_unsetId().
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setId(OutwardBindingSite_t * obs, const char * id);


/**
 * Sets the value of the "name" attribute of this OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling OutwardBindingSite_unsetName().
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setName(OutwardBindingSite_t * obs, const char * name);


/**
 * Sets the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @param bindingStatus BindingStatus_t value of the "bindingStatus" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_outwardbindingsite_bindingStatus
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setBindingStatus(OutwardBindingSite_t * obs,
                                    BindingStatus_t bindingStatus);


/**
 * Sets the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @param bindingStatus const char * of the "bindingStatus" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_outwardbindingsite_bindingStatus
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setBindingStatusAsString(OutwardBindingSite_t * obs,
                                            const char * bindingStatus);


/**
 * Sets the value of the "component" attribute of this OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @param component const char * value of the "component" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_setComponent(OutwardBindingSite_t * obs,
                                const char * component);


/**
 * Unsets the value of the "id" attribute of this OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_unsetId(OutwardBindingSite_t * obs);


/**
 * Unsets the value of the "name" attribute of this OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_unsetName(OutwardBindingSite_t * obs);


/**
 * Unsets the value of the "bindingStatus" attribute of this
 * OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_outwardbindingsite_bindingStatus
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_unsetBindingStatus(OutwardBindingSite_t * obs);


/**
 * Unsets the value of the "component" attribute of this OutwardBindingSite_t.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_unsetComponent(OutwardBindingSite_t * obs);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * OutwardBindingSite_t object have been set.
 *
 * @param obs the OutwardBindingSite_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * OutwardBindingSite_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the OutwardBindingSite_t object are:
 * @li "bindingStatus"
 * @li "component"
 *
 * @memberof OutwardBindingSite_t
 */
LIBSBML_EXTERN
int
OutwardBindingSite_hasRequiredAttributes(const OutwardBindingSite_t * obs);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !OutwardBindingSite_H__ */


