/**
 * @file Objective.h
 * @brief Definition of the Objective class.
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
 * @class Objective
 * @sbmlbrief{fbc} TODO:Definition of the Objective class.
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
 * @class doc_objective_type
 *
 * @par
 * The attribute "type" on a Objective object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Fbc specification, the following are the
 * allowable values for "type":
 * <ul>
 * <li> @c "maximize", TODO:add description
 *
 * <li> @c "minimize", TODO:add description
 *
 * </ul>
 *
 * @class doc_objective_type
 *
 * @par
 * The attribute "type" on a Objective object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Fbc specification, the following are the
 * allowable values for "type":
 * <ul>
 * <li> @c "maximize", TODO:add description
 *
 * <li> @c "minimize", TODO:add description
 *
 * </ul>
 */


#ifndef Objective_H__
#define Objective_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/packages/fbc/common/fbcfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/packages/fbc/extension/FbcExtension.h>
#include <sbml/packages/fbc/sbml/ListOfFluxObjectives.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Objective : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  FbcType_t mType;
  ListOfFluxObjectives mFluxObjectives;

  /** @endcond */

public:

  /**
   * Creates a new Objective using the given SBML Level, Version and
   * &ldquo;fbc&rdquo; package version.
   *
   * @param level an unsigned int, the SBML Level to assign to this Objective.
   *
   * @param version an unsigned int, the SBML Version to assign to this
   * Objective.
   *
   * @param pkgVersion an unsigned int, the SBML Fbc Version to assign to this
   * Objective.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Objective(unsigned int level = FbcExtension::getDefaultLevel(),
            unsigned int version = FbcExtension::getDefaultVersion(),
            unsigned int pkgVersion =
              FbcExtension::getDefaultPackageVersion());


  /**
   * Creates a new Objective using the given FbcPkgNamespaces object.
   *
   * @copydetails doc_what_are_sbml_package_namespaces
   *
   * @param fbcns the FbcPkgNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Objective(FbcPkgNamespaces *fbcns);


  /**
   * Copy constructor for Objective.
   *
   * @param orig the Objective instance to copy.
   */
  Objective(const Objective& orig);


  /**
   * Assignment operator for Objective.
   *
   * @param rhs the Objective object whose values are to be used as the basis
   * of the assignment.
   */
  Objective& operator=(const Objective& rhs);


  /**
   * Creates and returns a deep copy of this Objective object.
   *
   * @return a (deep) copy of this Objective object.
   */
  virtual Objective* clone() const;


  /**
   * Destructor for Objective.
   */
  virtual ~Objective();


  /**
   * Returns the value of the "id" attribute of this Objective.
   *
   * @return the value of the "id" attribute of this Objective as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "name" attribute of this Objective.
   *
   * @return the value of the "name" attribute of this Objective as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Returns the value of the "type" attribute of this Objective.
   *
   * @return the value of the "type" attribute of this Objective as a
   * FbcType_t.
   *
   * @copydetails doc_objective_type
   * @if clike The value is drawn from the enumeration @ref FbcType_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{OBJECTIVE_TYPE_MAXIMIZE, FbcType_t}
   * @li @sbmlconstant{OBJECTIVE_TYPE_MINIMIZE, FbcType_t}
   * @li @sbmlconstant{OBJECTIVE_TYPE_INVALID, FbcType_t}
   */
  FbcType_t getType() const;


  /**
   * Returns the value of the "type" attribute of this Objective.
   *
   * @return the value of the "type" attribute of this Objective as a string.
   *
   * @copydetails doc_objective_type
   * The possible values returned by this method are:
   * @li @c "maximize"
   * @li @c "minimize"
   * @li @c "invalid FbcType value"
   */
  std::string getTypeAsString() const;


  /**
   * Predicate returning @c true if this Objective's "id" attribute is set.
   *
   * @return @c true if this Objective's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this Objective's "name" attribute is set.
   *
   * @return @c true if this Objective's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Predicate returning @c true if this Objective's "type" attribute is set.
   *
   * @return @c true if this Objective's "type" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_objective_type
   */
  bool isSetType() const;


  /**
   * Sets the value of the "id" attribute of this Objective.
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
   * Sets the value of the "name" attribute of this Objective.
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
   * Sets the value of the "type" attribute of this Objective.
   *
   * @param type @if clike FbcType_t@else int@endif value of the "type"
   * attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_objective_type
   */
  int setType(const FbcType_t type);


  /**
   * Sets the value of the "type" attribute of this Objective.
   *
   * @param type std::string& of the "type" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_objective_type
   */
  int setType(const std::string& type);


  /**
   * Unsets the value of the "id" attribute of this Objective.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "name" attribute of this Objective.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetName();


  /**
   * Unsets the value of the "type" attribute of this Objective.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_objective_type
   */
  int unsetType();


  /**
   * Returns the ListOfFluxObjectives from this Objective.
   *
   * @return the ListOfFluxObjectives from this Objective.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see createFluxObjective()
   * @see getFluxObjective(const std::string& sid)
   * @see getFluxObjective(unsigned int n)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(const std::string& sid)
   * @see removeFluxObjective(unsigned int n)
   */
  const ListOfFluxObjectives* getListOfFluxObjectives() const;


  /**
   * Returns the ListOfFluxObjectives from this Objective.
   *
   * @return the ListOfFluxObjectives from this Objective.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see createFluxObjective()
   * @see getFluxObjective(const std::string& sid)
   * @see getFluxObjective(unsigned int n)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(const std::string& sid)
   * @see removeFluxObjective(unsigned int n)
   */
  ListOfFluxObjectives* getListOfFluxObjectives();


  /**
   * Get a FluxObjective from the Objective.
   *
   * @param n an unsigned int representing the index of the FluxObjective to
   * retrieve.
   *
   * @return the nth FluxObjective in the ListOfFluxObjectives within this
   * Objective.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see createFluxObjective()
   * @see getFluxObjective(const std::string& sid)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(const std::string& sid)
   * @see removeFluxObjective(unsigned int n)
   */
  FluxObjective* getFluxObjective(unsigned int n);


  /**
   * Get a FluxObjective from the Objective.
   *
   * @param n an unsigned int representing the index of the FluxObjective to
   * retrieve.
   *
   * @return the nth FluxObjective in the ListOfFluxObjectives within this
   * Objective.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see createFluxObjective()
   * @see getFluxObjective(const std::string& sid)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(const std::string& sid)
   * @see removeFluxObjective(unsigned int n)
   */
  const FluxObjective* getFluxObjective(unsigned int n) const;


  /**
   * Get a FluxObjective from the Objective based on its identifier.
   *
   * @param sid a string representing the identifier of the FluxObjective to
   * retrieve.
   *
   * @return the FluxObjective in the ListOfFluxObjectives within this
   * Objective with the given @p sid or @c NULL if no such FluxObjective
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see createFluxObjective()
   * @see getFluxObjective(unsigned int n)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(const std::string& sid)
   * @see removeFluxObjective(unsigned int n)
   */
  FluxObjective* getFluxObjective(const std::string& sid);


  /**
   * Get a FluxObjective from the Objective based on its identifier.
   *
   * @param sid a string representing the identifier of the FluxObjective to
   * retrieve.
   *
   * @return the FluxObjective in the ListOfFluxObjectives within this
   * Objective with the given @p sid or @c NULL if no such FluxObjective
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see createFluxObjective()
   * @see getFluxObjective(unsigned int n)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(const std::string& sid)
   * @see removeFluxObjective(unsigned int n)
   */
  const FluxObjective* getFluxObjective(const std::string& sid) const;


  /**
   * Get a FluxObjective from the Objective based on the Reaction to which it
   * refers.
   *
   * @param sid a string representing the "reaction" attribute of the
   * FluxObjective object to retrieve.
   *
   * @return the first FluxObjective in this Objective based on the given
   * reaction attribute or NULL if no such FluxObjective exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const FluxObjective* getFluxObjectiveByReaction(const std::string& sid)
    const;


  /**
   * Get a FluxObjective from the Objective based on the Reaction to which it
   * refers.
   *
   * @param sid a string representing the "reaction" attribute of the
   * FluxObjective object to retrieve.
   *
   * @return the first FluxObjective in this Objective based on the given
   * reaction attribute or NULL if no such FluxObjective exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  FluxObjective* getFluxObjectiveByReaction(const std::string& sid);


  /**
   * Adds a copy of the given FluxObjective to this Objective.
   *
   * @param fo the FluxObjective object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createFluxObjective()
   * @see getFluxObjective(const std::string& sid)
   * @see getFluxObjective(unsigned int n)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(const std::string& sid)
   * @see removeFluxObjective(unsigned int n)
   */
  int addFluxObjective(const FluxObjective* fo);


  /**
   * Get the number of FluxObjective objects in this Objective.
   *
   * @return the number of FluxObjective objects in this Objective.
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see createFluxObjective()
   * @see getFluxObjective(const std::string& sid)
   * @see getFluxObjective(unsigned int n)
   * @see removeFluxObjective(const std::string& sid)
   * @see removeFluxObjective(unsigned int n)
   */
  unsigned int getNumFluxObjectives() const;


  /**
   * Creates a new FluxObjective object, adds it to this Objective object and
   * returns the FluxObjective object created.
   *
   * @return a new FluxObjective object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see getFluxObjective(const std::string& sid)
   * @see getFluxObjective(unsigned int n)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(const std::string& sid)
   * @see removeFluxObjective(unsigned int n)
   */
  FluxObjective* createFluxObjective();


  /**
   * Removes the nth FluxObjective from this Objective and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the FluxObjective to
   * remove.
   *
   * @return a pointer to the nth FluxObjective in this Objective.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see createFluxObjective()
   * @see getFluxObjective(const std::string& sid)
   * @see getFluxObjective(unsigned int n)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(const std::string& sid)
   */
  FluxObjective* removeFluxObjective(unsigned int n);


  /**
   * Removes the FluxObjective from this Objective based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the FluxObjective to
   * remove.
   *
   * @return the FluxObjective in this Objective based on the identifier or
   * NULL if no such FluxObjective exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addFluxObjective(const FluxObjective* object)
   * @see createFluxObjective()
   * @see getFluxObjective(const std::string& sid)
   * @see getFluxObjective(unsigned int n)
   * @see getNumFluxObjectives()
   * @see removeFluxObjective(unsigned int n)
   */
  FluxObjective* removeFluxObjective(const std::string& sid);


  /**
   * Returns the XML element name of this Objective object.
   *
   * For Objective, the XML element name is always @c "objective".
   *
   * @return the name of this element, i.e. @c "objective".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Objective object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{SBML_FBC_OBJECTIVE, SBMLFbcTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * Objective object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * Objective have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Objective object are:
   * @li "id"
   * @li "type"
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
   * Gets the value of the "attributeName" attribute of this Objective.
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
   * Gets the value of the "attributeName" attribute of this Objective.
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
   * Gets the value of the "attributeName" attribute of this Objective.
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
   * Gets the value of the "attributeName" attribute of this Objective.
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
   * Gets the value of the "attributeName" attribute of this Objective.
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
   * Predicate returning @c true if this Objective's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Objective's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Objective.
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
   * Sets the value of the "attributeName" attribute of this Objective.
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
   * Sets the value of the "attributeName" attribute of this Objective.
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
   * Sets the value of the "attributeName" attribute of this Objective.
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
   * Sets the value of the "attributeName" attribute of this Objective.
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
   * Unsets the value of the "attributeName" attribute of this Objective.
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
   * Creates and returns an new "elementName" object in this Objective.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this Objective.
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
   * Objective.
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
   * Returns the number of "elementName" in this Objective.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this Objective.
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
   * Reads the expected attributes into the member data variables
   */
  void readL3V1V1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  void readL3V1V2Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  void writeL3V1V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  void writeL3V1V2Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Objective_t using the given SBML Level, Version and
 * &ldquo;fbc&rdquo; package version.
 *
 * @param level an unsigned int, the SBML Level to assign to this Objective_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this
 * Objective_t.
 *
 * @param pkgVersion an unsigned int, the SBML Fbc Version to assign to this
 * Objective_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
Objective_t *
Objective_create(unsigned int level,
                 unsigned int version,
                 unsigned int pkgVersion);


/**
 * Creates and returns a deep copy of this Objective_t object.
 *
 * @param o the Objective_t structure.
 *
 * @return a (deep) copy of this Objective_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
Objective_t*
Objective_clone(const Objective_t* o);


/**
 * Frees this Objective_t object.
 *
 * @param o the Objective_t structure.
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
void
Objective_free(Objective_t* o);


/**
 * Returns the value of the "id" attribute of this Objective_t.
 *
 * @param o the Objective_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this Objective_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
char *
Objective_getId(const Objective_t * o);


/**
 * Returns the value of the "name" attribute of this Objective_t.
 *
 * @param o the Objective_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this Objective_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
char *
Objective_getName(const Objective_t * o);


/**
 * Returns the value of the "type" attribute of this Objective_t.
 *
 * @param o the Objective_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this Objective_t as a
 * FbcType_t.
 *
 * @copydetails doc_objective_type
 * @if clike The value is drawn from the enumeration @ref FbcType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{OBJECTIVE_TYPE_MAXIMIZE, FbcType_t}
 * @li @sbmlconstant{OBJECTIVE_TYPE_MINIMIZE, FbcType_t}
 * @li @sbmlconstant{OBJECTIVE_TYPE_INVALID, FbcType_t}
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
FbcType_t
Objective_getType(const Objective_t * o);


/**
 * Returns the value of the "type" attribute of this Objective_t.
 *
 * @param o the Objective_t structure whose type is sought.
 *
 * @return the value of the "type" attribute of this Objective_t as a const
 * char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_objective_type
 * The possible values returned by this method are:
 * @li @c "maximize"
 * @li @c "minimize"
 * @li @c "invalid FbcType value"
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
char *
Objective_getTypeAsString(const Objective_t * o);


/**
 * Predicate returning @c 1 (true) if this Objective_t's "id" attribute is set.
 *
 * @param o the Objective_t structure.
 *
 * @return @c 1 (true) if this Objective_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_isSetId(const Objective_t * o);


/**
 * Predicate returning @c 1 (true) if this Objective_t's "name" attribute is
 * set.
 *
 * @param o the Objective_t structure.
 *
 * @return @c 1 (true) if this Objective_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_isSetName(const Objective_t * o);


/**
 * Predicate returning @c 1 (true) if this Objective_t's "type" attribute is
 * set.
 *
 * @param o the Objective_t structure.
 *
 * @return @c 1 (true) if this Objective_t's "type" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_objective_type
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_isSetType(const Objective_t * o);


/**
 * Sets the value of the "id" attribute of this Objective_t.
 *
 * @param o the Objective_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling Objective_unsetId().
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_setId(Objective_t * o, const char * id);


/**
 * Sets the value of the "name" attribute of this Objective_t.
 *
 * @param o the Objective_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling Objective_unsetName().
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_setName(Objective_t * o, const char * name);


/**
 * Sets the value of the "type" attribute of this Objective_t.
 *
 * @param o the Objective_t structure.
 *
 * @param type FbcType_t value of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_objective_type
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_setType(Objective_t * o, FbcType_t type);


/**
 * Sets the value of the "type" attribute of this Objective_t.
 *
 * @param o the Objective_t structure.
 *
 * @param type const char * of the "type" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_objective_type
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_setTypeAsString(Objective_t * o, const char * type);


/**
 * Unsets the value of the "id" attribute of this Objective_t.
 *
 * @param o the Objective_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_unsetId(Objective_t * o);


/**
 * Unsets the value of the "name" attribute of this Objective_t.
 *
 * @param o the Objective_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_unsetName(Objective_t * o);


/**
 * Unsets the value of the "type" attribute of this Objective_t.
 *
 * @param o the Objective_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_objective_type
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_unsetType(Objective_t * o);


/**
 * Returns a ListOf_t * containing FluxObjective_t objects from this
 * Objective_t.
 *
 * @param o the Objective_t structure whose ListOfFluxObjectives is sought.
 *
 * @return the ListOfFluxObjectives from this Objective_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Objective_addFluxObjective()
 * @see Objective_createFluxObjective()
 * @see Objective_getFluxObjectiveById()
 * @see Objective_getFluxObjective()
 * @see Objective_getNumFluxObjectives()
 * @see Objective_removeFluxObjectiveById()
 * @see Objective_removeFluxObjective()
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
ListOf_t*
Objective_getListOfFluxObjectives(Objective_t* o);


/**
 * Get a FluxObjective_t from the Objective_t.
 *
 * @param o the Objective_t structure to search.
 *
 * @param n an unsigned int representing the index of the FluxObjective_t to
 * retrieve.
 *
 * @return the nth FluxObjective_t in the ListOfFluxObjectives within this
 * Objective.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_getFluxObjective(Objective_t* o, unsigned int n);


/**
 * Get a FluxObjective_t from the Objective_t based on its identifier.
 *
 * @param o the Objective_t structure to search.
 *
 * @param sid a string representing the identifier of the FluxObjective_t to
 * retrieve.
 *
 * @return the FluxObjective_t in the ListOfFluxObjectives within this
 * Objective with the given @p sid or @c NULL if no such FluxObjective_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_getFluxObjectiveById(Objective_t* o, const char *sid);


/**
 * Get a FluxObjective_t from the Objective_t based on the Reaction to which it
 * refers.
 *
 * @param o the Objective_t structure to search.
 *
 * @param sid a string representing the "reaction" attribute of the
 * FluxObjective_t object to retrieve.
 *
 * @return the first FluxObjective_t in this Objective_t based on the given
 * reaction attribute or NULL if no such FluxObjective_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_getFluxObjectiveByReaction(Objective_t* o, const char *sid);


/**
 * Adds a copy of the given FluxObjective_t to this Objective_t.
 *
 * @param o the Objective_t structure to which the FluxObjective_t should be
 * added.
 *
 * @param fo the FluxObjective_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_addFluxObjective(Objective_t* o, const FluxObjective_t* fo);


/**
 * Get the number of FluxObjective_t objects in this Objective_t.
 *
 * @param o the Objective_t structure to query.
 *
 * @return the number of FluxObjective_t objects in this Objective_t.
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
unsigned int
Objective_getNumFluxObjectives(Objective_t* o);


/**
 * Creates a new FluxObjective_t object, adds it to this Objective_t object and
 * returns the FluxObjective_t object created.
 *
 * @param o the Objective_t structure to which the FluxObjective_t should be
 * added.
 *
 * @return a new FluxObjective_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_createFluxObjective(Objective_t* o);


/**
 * Removes the nth FluxObjective_t from this Objective_t and returns a pointer
 * to it.
 *
 * @param o the Objective_t structure to search.
 *
 * @param n an unsigned int representing the index of the FluxObjective_t to
 * remove.
 *
 * @return a pointer to the nth FluxObjective_t in this Objective_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_removeFluxObjective(Objective_t* o, unsigned int n);


/**
 * Removes the FluxObjective_t from this Objective_t based on its identifier
 * and returns a pointer to it.
 *
 * @param o the Objective_t structure to search.
 *
 * @param sid a string representing the identifier of the FluxObjective_t to
 * remove.
 *
 * @return the FluxObjective_t in this Objective_t based on the identifier or
 * NULL if no such FluxObjective_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
FluxObjective_t*
Objective_removeFluxObjectiveById(Objective_t* o, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Objective_t object have been set.
 *
 * @param o the Objective_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * Objective_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the Objective_t object are:
 * @li "id"
 * @li "type"
 *
 * @memberof Objective_t
 */
LIBSBML_EXTERN
int
Objective_hasRequiredAttributes(const Objective_t * o);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Objective_H__ */


