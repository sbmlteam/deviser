/**
 * @file UncertaintyOld.h
 * @brief Definition of the UncertaintyOld class.
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
 * @class UncertaintyOld
 * @sbmlbrief{distrib} TODO:Definition of the UncertaintyOld class.
 */


#ifndef UncertaintyOld_H__
#define UncertaintyOld_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/distrib/common/distribfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/distrib/extension/DistribExtension.h>
#include <sbml/packages/distrib/sbml/UncertMLNode.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN UncertaintyOld : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  UncertMLNode* mUncertML;

  /** @endcond */

public:

  /**
   * Creates a new UncertaintyOld using the given SBML Level, Version and
   * &ldquo;distrib&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this
   * UncertaintyOld.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * UncertaintyOld.
   *
   * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
   * this UncertaintyOld.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  UncertaintyOld(unsigned int level = DistribExtension::getDefaultLevel(),
                 unsigned int version = DistribExtension::getDefaultVersion(),
                 unsigned int pkgVersion =
                   DistribExtension::getDefaultPackageVersion());


  /**
   * Creates a new UncertaintyOld using the given DistribPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param distribns the DistribPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  UncertaintyOld(DistribPkgNamespaces *distribns);


  /**
   * Copy constructor for UncertaintyOld.
   *
   * @param orig the UncertaintyOld instance to copy.
   */
  UncertaintyOld(const UncertaintyOld& orig);


  /**
   * Assignment operator for UncertaintyOld.
   *
   * @param rhs the UncertaintyOld object whose values are to be used as the
   * basis of the assignment.
   */
  UncertaintyOld& operator=(const UncertaintyOld& rhs);


  /**
   * Creates and returns a deep copy of this UncertaintyOld object.
   *
   * @return a (deep) copy of this UncertaintyOld object.
   */
  virtual UncertaintyOld* clone() const;


  /**
   * Destructor for UncertaintyOld.
   */
  virtual ~UncertaintyOld();


  /**
   * Returns the value of the "id" attribute of this UncertaintyOld.
   *
   * @return the value of the "id" attribute of this UncertaintyOld as a
   * string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this UncertaintyOld.
   *
   * @return the value of the "name" attribute of this UncertaintyOld as a
   * string.
   */
  virtual const std::string& getName() const;


  /**
   * Predicate returning @c true if this UncertaintyOld's "id" attribute is
   * set.
   *
   * @return @c true if this UncertaintyOld's "id" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this UncertaintyOld's "name" attribute is
   * set.
   *
   * @return @c true if this UncertaintyOld's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Sets the value of the "id" attribute of this UncertaintyOld.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "name" attribute of this UncertaintyOld.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * Calling this function with @p name = @c NULL or an empty string is
   * equivalent to calling unsetName().
   */
  virtual int setName(const std::string& name);


  /**
   * Unsets the value of the "id" attribute of this UncertaintyOld.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "name" attribute of this UncertaintyOld.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetName();


  /**
   * Returns the value of the "uncertML" element of this UncertaintyOld.
   *
   * @return the value of the "uncertML" element of this UncertaintyOld as a
   * UncertMLNode*.
   */
  const UncertMLNode* getUncertML() const;


  /**
   * Returns the value of the "uncertML" element of this UncertaintyOld.
   *
   * @return the value of the "uncertML" element of this UncertaintyOld as a
   * UncertMLNode*.
   */
  UncertMLNode* getUncertML();


  /**
   * Predicate returning @c true if this UncertaintyOld's "uncertML" element is
   * set.
   *
   * @return @c true if this UncertaintyOld's "uncertML" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetUncertML() const;


  /**
   * Sets the value of the "uncertML" element of this UncertaintyOld.
   *
   * @param uncertML UncertMLNode* value of the "uncertML" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUncertML(const UncertMLNode* uncertML);


  /**
   * Unsets the value of the "uncertML" element of this UncertaintyOld.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUncertML();


  /**
   * Returns the XML element name of this UncertaintyOld object.
   *
   * For UncertaintyOld, the XML element name is always @c "uncertaintyOld".
   *
   * @return the name of this element, i.e. @c "uncertaintyOld".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this UncertaintyOld object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   *
   * @sbmlconstant{SBML_DISTRIB_UNCERTAINTY, SBMLDistribTypeCode_t}
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * UncertaintyOld object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * UncertaintyOld have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * UncertaintyOld object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * UncertaintyOld have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the UncertaintyOld object are:
   * @li "uncertML"
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
   * Gets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Gets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Predicate returning @c true if this UncertaintyOld's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this UncertaintyOld's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Sets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Unsets the value of the "attributeName" attribute of this UncertaintyOld.
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
   * Creates and returns an new "elementName" object in this UncertaintyOld.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this UncertaintyOld.
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
   * UncertaintyOld.
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
   * Returns the number of "elementName" in this UncertaintyOld.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this UncertaintyOld.
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
   * Reads other XML such as math/notes etc.
   */
  virtual bool readOtherXML(XMLInputStream& stream);

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
 * Creates a new UncertaintyOld_t using the given SBML Level, Version and
 * &ldquo;distrib&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this
 * UncertaintyOld_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * UncertaintyOld_t.
 *
 * @param pkgVersion an unsigned int, the SBML Distrib Version to assign to
 * this UncertaintyOld_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
UncertaintyOld_t *
UncertaintyOld_create(unsigned int level,
                      unsigned int version,
                      unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this UncertaintyOld_t object.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @return a (deep) copy of this UncertaintyOld_t object.
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
UncertaintyOld_t*
UncertaintyOld_clone(const UncertaintyOld_t* uo);


/**
 * Frees this UncertaintyOld_t object.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
void
UncertaintyOld_free(UncertaintyOld_t* uo);


/**
 * Returns the value of the "id" attribute of this UncertaintyOld_t.
 *
 * @param uo the UncertaintyOld_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this UncertaintyOld_t as a
 * pointer to a string.
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
const char *
UncertaintyOld_getId(const UncertaintyOld_t * uo);


/**
 * Returns the value of the "name" attribute of this UncertaintyOld_t.
 *
 * @param uo the UncertaintyOld_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this UncertaintyOld_t as a
 * pointer to a string.
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
const char *
UncertaintyOld_getName(const UncertaintyOld_t * uo);


/**
 * Predicate returning @c 1 (true) if this UncertaintyOld_t's "id" attribute is
 * set.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @return @c 1 (true) if this UncertaintyOld_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_isSetId(const UncertaintyOld_t * uo);


/**
 * Predicate returning @c 1 (true) if this UncertaintyOld_t's "name" attribute
 * is set.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @return @c 1 (true) if this UncertaintyOld_t's "name" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_isSetName(const UncertaintyOld_t * uo);


/**
 * Sets the value of the "id" attribute of this UncertaintyOld_t.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_setId(UncertaintyOld_t * uo, const char * id);


/**
 * Sets the value of the "name" attribute of this UncertaintyOld_t.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling UncertaintyOld_unsetName().
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_setName(UncertaintyOld_t * uo, const char * name);


/**
 * Unsets the value of the "id" attribute of this UncertaintyOld_t.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_unsetId(UncertaintyOld_t * uo);


/**
 * Unsets the value of the "name" attribute of this UncertaintyOld_t.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_unsetName(UncertaintyOld_t * uo);


/**
 * Returns the value of the "uncertML" element of this UncertaintyOld_t.
 *
 * @param uo the UncertaintyOld_t structure whose uncertML is sought.
 *
 * @return the value of the "uncertML" element of this UncertaintyOld_t as a
 * UncertMLNode*.
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
const UncertMLNode_t*
UncertaintyOld_getUncertML(const UncertaintyOld_t * uo);


/**
 * Predicate returning @c 1 (true) if this UncertaintyOld_t's "uncertML"
 * element is set.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @return @c 1 (true) if this UncertaintyOld_t's "uncertML" element has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_isSetUncertML(const UncertaintyOld_t * uo);


/**
 * Sets the value of the "uncertML" element of this UncertaintyOld_t.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @param uncertML UncertMLNode_t* value of the "uncertML" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_setUncertML(UncertaintyOld_t * uo,
                           const UncertMLNode_t* uncertML);


/**
 * Unsets the value of the "uncertML" element of this UncertaintyOld_t.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_unsetUncertML(UncertaintyOld_t * uo);


/**
 * Predicate returning @c 1 if all the required attributes for this
 * UncertaintyOld_t object have been set.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @return @c 1 to indicate that all the required attributes of this
 * UncertaintyOld_t have been set, otherwise @c 0 is returned.
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_hasRequiredAttributes(const UncertaintyOld_t * uo);


/**
 * Predicate returning @c 1 if all the required elements for this
 * UncertaintyOld_t object have been set.
 *
 * @param uo the UncertaintyOld_t structure.
 *
 * @return @c 1 to indicate that all the required elements of this
 * UncertaintyOld_t have been set, otherwise @c 0 is returned.
 *
 *
 * @note The required elements for the UncertaintyOld_t object are:
 * @li "uncertML"
 *
 * @memberof UncertaintyOld_t
 */
LIBSBML_EXTERN
int
UncertaintyOld_hasRequiredElements(const UncertaintyOld_t * uo);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !UncertaintyOld_H__ */


