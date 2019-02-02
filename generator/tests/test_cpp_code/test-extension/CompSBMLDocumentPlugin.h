/**
 * @file CompSBMLDocumentPlugin.h
 * @brief Definition of the CompSBMLDocumentPlugin class.
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
 * @class CompSBMLDocumentPlugin
 * @sbmlbrief{comp} Extension of SBMLDocument.
 */


#ifndef CompSBMLDocumentPlugin_H__
#define CompSBMLDocumentPlugin_H__


#include <sbml/common/extern.h>


#ifdef __cplusplus


#include <sbml/extension/SBMLDocumentPlugin.h>
#include <sbml/packages/comp/extension/CompExtension.h>
#include <sbml/packages/comp/sbml/ListOfExternalModelDefinitions.h>
#include <sbml/packages/comp/sbml/ExternalModelDefinition.h>
#include <sbml/packages/comp/sbml/ListOfModelDefinitions.h>
#include <sbml/packages/comp/sbml/ModelDefinition.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN CompSBMLDocumentPlugin : public SBMLDocumentPlugin
{
protected:

  /** @cond doxygenLibsbmlInternal */

  ListOfExternalModelDefinitions mExternalModelDefinitions;
  ListOfModelDefinitions mModelDefinitions;

  /** @endcond */

public:

  /**
   * Creates a new CompSBMLDocumentPlugin using the given URI, prefix and
   * package namespace.
   *
   * @param uri a string, representing the URI of the SBML Level&nbsp;3 package
   * implemented by this libSBML package extension.
   *
   * @param prefix a string, the XML namespace prefix being used for this
   * package.
   *
   * @param compns a pointer to the namesspaces object (CompPkgNamespaces) for
   * this package.
   *
   * @copydetails doc_what_are_xmlnamespaces
   *
   * @copydetails doc_what_are_sbmlnamespaces
   */
  CompSBMLDocumentPlugin(const std::string& uri,
                         const std::string& prefix,
                         CompPkgNamespaces* compns);


  /**
   * Copy constructor for CompSBMLDocumentPlugin.
   *
   * @param orig the CompSBMLDocumentPlugin instance to copy.
   */
  CompSBMLDocumentPlugin(const CompSBMLDocumentPlugin& orig);


  /**
   * Assignment operator for CompSBMLDocumentPlugin.
   *
   * @param rhs the CompSBMLDocumentPlugin object whose values are to be used
   * as the basis of the assignment.
   */
  CompSBMLDocumentPlugin& operator=(const CompSBMLDocumentPlugin& rhs);


  /**
   * Creates and returns a deep copy of this CompSBMLDocumentPlugin object.
   *
   * @return a (deep) copy of this CompSBMLDocumentPlugin object.
   */
  virtual CompSBMLDocumentPlugin* clone() const;


  /**
   * Destructor for CompSBMLDocumentPlugin.
   */
  virtual ~CompSBMLDocumentPlugin();


  /**
   * Returns the ListOfExternalModelDefinitions from this
   * CompSBMLDocumentPlugin.
   *
   * @return the ListOfExternalModelDefinitions from this
   * CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(const std::string& sid)
   * @see getExternalModelDefinition(unsigned int n)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(const std::string& sid)
   * @see removeExternalModelDefinition(unsigned int n)
   */
  const ListOfExternalModelDefinitions* getListOfExternalModelDefinitions()
    const;


  /**
   * Returns the ListOfExternalModelDefinitions from this
   * CompSBMLDocumentPlugin.
   *
   * @return the ListOfExternalModelDefinitions from this
   * CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(const std::string& sid)
   * @see getExternalModelDefinition(unsigned int n)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(const std::string& sid)
   * @see removeExternalModelDefinition(unsigned int n)
   */
  ListOfExternalModelDefinitions* getListOfExternalModelDefinitions();


  /**
   * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin.
   *
   * @param n an unsigned int representing the index of the
   * ExternalModelDefinition to retrieve.
   *
   * @return the nth ExternalModelDefinition in the
   * ListOfExternalModelDefinitions within this CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(const std::string& sid)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(const std::string& sid)
   * @see removeExternalModelDefinition(unsigned int n)
   */
  ExternalModelDefinition* getExternalModelDefinition(unsigned int n);


  /**
   * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin.
   *
   * @param n an unsigned int representing the index of the
   * ExternalModelDefinition to retrieve.
   *
   * @return the nth ExternalModelDefinition in the
   * ListOfExternalModelDefinitions within this CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(const std::string& sid)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(const std::string& sid)
   * @see removeExternalModelDefinition(unsigned int n)
   */
  const ExternalModelDefinition* getExternalModelDefinition(unsigned int n)
    const;


  /**
   * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin based on
   * its identifier.
   *
   * @param sid a string representing the identifier of the
   * ExternalModelDefinition to retrieve.
   *
   * @return the ExternalModelDefinition in the ListOfExternalModelDefinitions
   * within this CompSBMLDocumentPlugin with the given @p sid or @c NULL if no
   * such ExternalModelDefinition exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(unsigned int n)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(const std::string& sid)
   * @see removeExternalModelDefinition(unsigned int n)
   */
  ExternalModelDefinition* getExternalModelDefinition(const std::string& sid);


  /**
   * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin based on
   * its identifier.
   *
   * @param sid a string representing the identifier of the
   * ExternalModelDefinition to retrieve.
   *
   * @return the ExternalModelDefinition in the ListOfExternalModelDefinitions
   * within this CompSBMLDocumentPlugin with the given @p sid or @c NULL if no
   * such ExternalModelDefinition exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(unsigned int n)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(const std::string& sid)
   * @see removeExternalModelDefinition(unsigned int n)
   */
  const ExternalModelDefinition* getExternalModelDefinition(const std::string&
    sid) const;


  /**
   * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin based on
   * the ModelRef to which it refers.
   *
   * @param sid a string representing the "modelRef" attribute of the
   * ExternalModelDefinition object to retrieve.
   *
   * @return the first ExternalModelDefinition in this CompSBMLDocumentPlugin
   * based on the given modelRef attribute or NULL if no such
   * ExternalModelDefinition exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const ExternalModelDefinition* getExternalModelDefinitionByModelRef(const
    std::string& sid) const;


  /**
   * Get an ExternalModelDefinition from the CompSBMLDocumentPlugin based on
   * the ModelRef to which it refers.
   *
   * @param sid a string representing the "modelRef" attribute of the
   * ExternalModelDefinition object to retrieve.
   *
   * @return the first ExternalModelDefinition in this CompSBMLDocumentPlugin
   * based on the given modelRef attribute or NULL if no such
   * ExternalModelDefinition exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  ExternalModelDefinition* getExternalModelDefinitionByModelRef(const
    std::string& sid);


  /**
   * Adds a copy of the given ExternalModelDefinition to this
   * CompSBMLDocumentPlugin.
   *
   * @param emd the ExternalModelDefinition object to add.
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
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(const std::string& sid)
   * @see getExternalModelDefinition(unsigned int n)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(const std::string& sid)
   * @see removeExternalModelDefinition(unsigned int n)
   */
  int addExternalModelDefinition(const ExternalModelDefinition* emd);


  /**
   * Get the number of ExternalModelDefinition objects in this
   * CompSBMLDocumentPlugin.
   *
   * @return the number of ExternalModelDefinition objects in this
   * CompSBMLDocumentPlugin.
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(const std::string& sid)
   * @see getExternalModelDefinition(unsigned int n)
   * @see removeExternalModelDefinition(const std::string& sid)
   * @see removeExternalModelDefinition(unsigned int n)
   */
  unsigned int getNumExternalModelDefinitions() const;


  /**
   * Creates a new ExternalModelDefinition object, adds it to this
   * CompSBMLDocumentPlugin object and returns the ExternalModelDefinition
   * object created.
   *
   * @return a new ExternalModelDefinition object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see getExternalModelDefinition(const std::string& sid)
   * @see getExternalModelDefinition(unsigned int n)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(const std::string& sid)
   * @see removeExternalModelDefinition(unsigned int n)
   */
  ExternalModelDefinition* createExternalModelDefinition();


  /**
   * Removes the nth ExternalModelDefinition from this CompSBMLDocumentPlugin
   * and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the
   * ExternalModelDefinition to remove.
   *
   * @return a pointer to the nth ExternalModelDefinition in this
   * CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(const std::string& sid)
   * @see getExternalModelDefinition(unsigned int n)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(const std::string& sid)
   */
  ExternalModelDefinition* removeExternalModelDefinition(unsigned int n);


  /**
   * Removes the ExternalModelDefinition from this CompSBMLDocumentPlugin based
   * on its identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the
   * ExternalModelDefinition to remove.
   *
   * @return the ExternalModelDefinition in this CompSBMLDocumentPlugin based
   * on the identifier or NULL if no such ExternalModelDefinition exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addExternalModelDefinition(const ExternalModelDefinition* object)
   * @see createExternalModelDefinition()
   * @see getExternalModelDefinition(const std::string& sid)
   * @see getExternalModelDefinition(unsigned int n)
   * @see getNumExternalModelDefinitions()
   * @see removeExternalModelDefinition(unsigned int n)
   */
  ExternalModelDefinition* removeExternalModelDefinition(const std::string&
    sid);


  /**
   * Returns the ListOfModelDefinitions from this CompSBMLDocumentPlugin.
   *
   * @return the ListOfModelDefinitions from this CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModelDefinition(const ModelDefinition* object)
   * @see createModelDefinition()
   * @see getModelDefinition(const std::string& sid)
   * @see getModelDefinition(unsigned int n)
   * @see getNumModelDefinitions()
   * @see removeModelDefinition(const std::string& sid)
   * @see removeModelDefinition(unsigned int n)
   */
  const ListOfModelDefinitions* getListOfModelDefinitions() const;


  /**
   * Returns the ListOfModelDefinitions from this CompSBMLDocumentPlugin.
   *
   * @return the ListOfModelDefinitions from this CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModelDefinition(const ModelDefinition* object)
   * @see createModelDefinition()
   * @see getModelDefinition(const std::string& sid)
   * @see getModelDefinition(unsigned int n)
   * @see getNumModelDefinitions()
   * @see removeModelDefinition(const std::string& sid)
   * @see removeModelDefinition(unsigned int n)
   */
  ListOfModelDefinitions* getListOfModelDefinitions();


  /**
   * Get a ModelDefinition from the CompSBMLDocumentPlugin.
   *
   * @param n an unsigned int representing the index of the ModelDefinition to
   * retrieve.
   *
   * @return the nth ModelDefinition in the ListOfModelDefinitions within this
   * CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModelDefinition(const ModelDefinition* object)
   * @see createModelDefinition()
   * @see getModelDefinition(const std::string& sid)
   * @see getNumModelDefinitions()
   * @see removeModelDefinition(const std::string& sid)
   * @see removeModelDefinition(unsigned int n)
   */
  ModelDefinition* getModelDefinition(unsigned int n);


  /**
   * Get a ModelDefinition from the CompSBMLDocumentPlugin.
   *
   * @param n an unsigned int representing the index of the ModelDefinition to
   * retrieve.
   *
   * @return the nth ModelDefinition in the ListOfModelDefinitions within this
   * CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModelDefinition(const ModelDefinition* object)
   * @see createModelDefinition()
   * @see getModelDefinition(const std::string& sid)
   * @see getNumModelDefinitions()
   * @see removeModelDefinition(const std::string& sid)
   * @see removeModelDefinition(unsigned int n)
   */
  const ModelDefinition* getModelDefinition(unsigned int n) const;


  /**
   * Adds a copy of the given ModelDefinition to this CompSBMLDocumentPlugin.
   *
   * @param md the ModelDefinition object to add.
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
   * @see createModelDefinition()
   * @see getModelDefinition(const std::string& sid)
   * @see getModelDefinition(unsigned int n)
   * @see getNumModelDefinitions()
   * @see removeModelDefinition(const std::string& sid)
   * @see removeModelDefinition(unsigned int n)
   */
  int addModelDefinition(const ModelDefinition* md);


  /**
   * Get the number of ModelDefinition objects in this CompSBMLDocumentPlugin.
   *
   * @return the number of ModelDefinition objects in this
   * CompSBMLDocumentPlugin.
   *
   * @see addModelDefinition(const ModelDefinition* object)
   * @see createModelDefinition()
   * @see getModelDefinition(const std::string& sid)
   * @see getModelDefinition(unsigned int n)
   * @see removeModelDefinition(const std::string& sid)
   * @see removeModelDefinition(unsigned int n)
   */
  unsigned int getNumModelDefinitions() const;


  /**
   * Creates a new ModelDefinition object, adds it to this
   * CompSBMLDocumentPlugin object and returns the ModelDefinition object
   * created.
   *
   * @return a new ModelDefinition object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addModelDefinition(const ModelDefinition* object)
   * @see getModelDefinition(const std::string& sid)
   * @see getModelDefinition(unsigned int n)
   * @see getNumModelDefinitions()
   * @see removeModelDefinition(const std::string& sid)
   * @see removeModelDefinition(unsigned int n)
   */
  ModelDefinition* createModelDefinition();


  /**
   * Removes the nth ModelDefinition from this CompSBMLDocumentPlugin and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the ModelDefinition to
   * remove.
   *
   * @return a pointer to the nth ModelDefinition in this
   * CompSBMLDocumentPlugin.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addModelDefinition(const ModelDefinition* object)
   * @see createModelDefinition()
   * @see getModelDefinition(const std::string& sid)
   * @see getModelDefinition(unsigned int n)
   * @see getNumModelDefinitions()
   * @see removeModelDefinition(const std::string& sid)
   */
  ModelDefinition* removeModelDefinition(unsigned int n);



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
   * Connects to parent element
   */
  virtual void connectToParent(SBase* base);

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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Predicate indicating whether 'comp' flattening has been implemented for
   * the Comp package.
   */
  virtual bool isCompFlatteningImplemented() const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Calls check consistency for any relevant Comp validators.
   */
  virtual unsigned int checkConsistency();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the Comp attributes in the top-level element.
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */




  #endif /* !SWIG */




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * Predicate returning @c true if this CompSBMLDocumentPlugin's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this CompSBMLDocumentPlugin's attribute "attributeName"
   * has been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this CompSBMLDocumentPlugin.
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
   * CompSBMLDocumentPlugin.
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
   * Returns the number of "elementName" in this CompSBMLDocumentPlugin.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this CompSBMLDocumentPlugin.
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



  /** @cond doxygenLibsbmlInternal */

  /**
   * Append items from model (used in comp flattening)
   *
   * @param model a pointer to a model object.
   *
   */
  int appendFrom(const Model* model);

  /** @endcond */


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
 * Returns a ListOf_t * containing ExternalModelDefinition_t objects from this
 * CompSBMLDocumentPlugin_t.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure whose
 * ListOfExternalModelDefinitions is sought.
 *
 * @return the ListOfExternalModelDefinitions from this
 * CompSBMLDocumentPlugin_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see CompSBMLDocumentPlugin_addExternalModelDefinition()
 * @see CompSBMLDocumentPlugin_createExternalModelDefinition()
 * @see CompSBMLDocumentPlugin_getExternalModelDefinitionById()
 * @see CompSBMLDocumentPlugin_getExternalModelDefinition()
 * @see CompSBMLDocumentPlugin_getNumExternalModelDefinitions()
 * @see CompSBMLDocumentPlugin_removeExternalModelDefinitionById()
 * @see CompSBMLDocumentPlugin_removeExternalModelDefinition()
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ListOf_t*
CompSBMLDocumentPlugin_getListOfExternalModelDefinitions(CompSBMLDocumentPlugin_t*
  csbmldp);


/**
 * Get an ExternalModelDefinition_t from the CompSBMLDocumentPlugin_t.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * ExternalModelDefinition_t to retrieve.
 *
 * @return the nth ExternalModelDefinition_t in the
 * ListOfExternalModelDefinitions within this CompSBMLDocumentPlugin.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_getExternalModelDefinition(
                                                  CompSBMLDocumentPlugin_t*
                                                    csbmldp,
                                                  unsigned int n);


/**
 * Get an ExternalModelDefinition_t from the CompSBMLDocumentPlugin_t based on
 * its identifier.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * ExternalModelDefinition_t to retrieve.
 *
 * @return the ExternalModelDefinition_t in the ListOfExternalModelDefinitions
 * within this CompSBMLDocumentPlugin with the given @p sid or @c NULL if no
 * such ExternalModelDefinition_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_getExternalModelDefinitionById(
                                                      CompSBMLDocumentPlugin_t*
                                                        csbmldp,
                                                      const char *sid);


/**
 * Get an ExternalModelDefinition_t from the CompSBMLDocumentPlugin_t based on
 * the ModelRef to which it refers.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to search.
 *
 * @param sid a string representing the "modelRef" attribute of the
 * ExternalModelDefinition_t object to retrieve.
 *
 * @return the first ExternalModelDefinition_t in this CompSBMLDocumentPlugin_t
 * based on the given modelRef attribute or NULL if no such
 * ExternalModelDefinition_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_getExternalModelDefinitionByModelRef(
                                                            CompSBMLDocumentPlugin_t*
                                                              csbmldp,
                                                            const char *sid);


/**
 * Adds a copy of the given ExternalModelDefinition_t to this
 * CompSBMLDocumentPlugin_t.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to which the
 * ExternalModelDefinition_t should be added.
 *
 * @param emd the ExternalModelDefinition_t object to add.
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
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
int
CompSBMLDocumentPlugin_addExternalModelDefinition(
                                                  CompSBMLDocumentPlugin_t*
                                                    csbmldp,
                                                  const ExternalModelDefinition_t*
                                                    emd);


/**
 * Get the number of ExternalModelDefinition_t objects in this
 * CompSBMLDocumentPlugin_t.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to query.
 *
 * @return the number of ExternalModelDefinition_t objects in this
 * CompSBMLDocumentPlugin_t.
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
unsigned int
CompSBMLDocumentPlugin_getNumExternalModelDefinitions(CompSBMLDocumentPlugin_t*
  csbmldp);


/**
 * Creates a new ExternalModelDefinition_t object, adds it to this
 * CompSBMLDocumentPlugin_t object and returns the ExternalModelDefinition_t
 * object created.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to which the
 * ExternalModelDefinition_t should be added.
 *
 * @return a new ExternalModelDefinition_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_createExternalModelDefinition(CompSBMLDocumentPlugin_t*
  csbmldp);


/**
 * Removes the nth ExternalModelDefinition_t from this CompSBMLDocumentPlugin_t
 * and returns a pointer to it.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the
 * ExternalModelDefinition_t to remove.
 *
 * @return a pointer to the nth ExternalModelDefinition_t in this
 * CompSBMLDocumentPlugin_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_removeExternalModelDefinition(
                                                     CompSBMLDocumentPlugin_t*
                                                       csbmldp,
                                                     unsigned int n);


/**
 * Removes the ExternalModelDefinition_t from this CompSBMLDocumentPlugin_t
 * based on its identifier and returns a pointer to it.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the
 * ExternalModelDefinition_t to remove.
 *
 * @return the ExternalModelDefinition_t in this CompSBMLDocumentPlugin_t based
 * on the identifier or NULL if no such ExternalModelDefinition_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ExternalModelDefinition_t*
CompSBMLDocumentPlugin_removeExternalModelDefinitionById(
                                                         CompSBMLDocumentPlugin_t*
                                                           csbmldp,
                                                         const char* sid);


/**
 * Returns a ListOf_t * containing ModelDefinition_t objects from this
 * CompSBMLDocumentPlugin_t.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure whose
 * ListOfModelDefinitions is sought.
 *
 * @return the ListOfModelDefinitions from this CompSBMLDocumentPlugin_t as a
 * ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see CompSBMLDocumentPlugin_addModelDefinition()
 * @see CompSBMLDocumentPlugin_createModelDefinition()
 * @see CompSBMLDocumentPlugin_getModelDefinitionById()
 * @see CompSBMLDocumentPlugin_getModelDefinition()
 * @see CompSBMLDocumentPlugin_getNumModelDefinitions()
 * @see CompSBMLDocumentPlugin_removeModelDefinitionById()
 * @see CompSBMLDocumentPlugin_removeModelDefinition()
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ListOf_t*
CompSBMLDocumentPlugin_getListOfModelDefinitions(CompSBMLDocumentPlugin_t*
  csbmldp);


/**
 * Get a ModelDefinition_t from the CompSBMLDocumentPlugin_t.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the ModelDefinition_t to
 * retrieve.
 *
 * @return the nth ModelDefinition_t in the ListOfModelDefinitions within this
 * CompSBMLDocumentPlugin.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ModelDefinition_t*
CompSBMLDocumentPlugin_getModelDefinition(CompSBMLDocumentPlugin_t* csbmldp,
                                          unsigned int n);


/**
 * Adds a copy of the given ModelDefinition_t to this CompSBMLDocumentPlugin_t.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to which the
 * ModelDefinition_t should be added.
 *
 * @param md the ModelDefinition_t object to add.
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
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
int
CompSBMLDocumentPlugin_addModelDefinition(CompSBMLDocumentPlugin_t* csbmldp,
                                          const ModelDefinition_t* md);


/**
 * Get the number of ModelDefinition_t objects in this
 * CompSBMLDocumentPlugin_t.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to query.
 *
 * @return the number of ModelDefinition_t objects in this
 * CompSBMLDocumentPlugin_t.
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
unsigned int
CompSBMLDocumentPlugin_getNumModelDefinitions(CompSBMLDocumentPlugin_t*
  csbmldp);


/**
 * Creates a new ModelDefinition_t object, adds it to this
 * CompSBMLDocumentPlugin_t object and returns the ModelDefinition_t object
 * created.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to which the
 * ModelDefinition_t should be added.
 *
 * @return a new ModelDefinition_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ModelDefinition_t*
CompSBMLDocumentPlugin_createModelDefinition(CompSBMLDocumentPlugin_t*
  csbmldp);


/**
 * Removes the nth ModelDefinition_t from this CompSBMLDocumentPlugin_t and
 * returns a pointer to it.
 *
 * @param csbmldp the CompSBMLDocumentPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the ModelDefinition_t to
 * remove.
 *
 * @return a pointer to the nth ModelDefinition_t in this
 * CompSBMLDocumentPlugin_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof CompSBMLDocumentPlugin_t
 */
LIBSBML_EXTERN
ModelDefinition_t*
CompSBMLDocumentPlugin_removeModelDefinition(CompSBMLDocumentPlugin_t* csbmldp,
                                             unsigned int n);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !CompSBMLDocumentPlugin_H__ */


