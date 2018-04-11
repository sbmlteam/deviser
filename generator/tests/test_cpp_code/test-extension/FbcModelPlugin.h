/**
 * @file FbcModelPlugin.h
 * @brief Definition of the FbcModelPlugin class.
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
 * @class FbcModelPlugin
 * @sbmlbrief{fbc} Extension of Model.
 */


#ifndef FbcModelPlugin_H__
#define FbcModelPlugin_H__


#include <sbml/common/extern.h>


#ifdef __cplusplus


#include <sbml/extension/SBasePlugin.h>
#include <sbml/packages/fbc/sbml/ListOfObjectives.h>
#include <sbml/packages/fbc/sbml/Objective.h>
#include <sbml/packages/fbc/sbml/ListOfFluxBounds.h>
#include <sbml/packages/fbc/sbml/FluxBound.h>
#include <sbml/packages/fbc/sbml/ListOfGeneProducts.h>
#include <sbml/packages/fbc/sbml/GeneProduct.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN FbcModelPlugin : public SBasePlugin
{
protected:

  /** @cond doxygenLibsbmlInternal */

  bool mStrict;
  bool mIsSetStrict;
  ListOfObjectives mObjectives;
  ListOfFluxBounds mFluxBounds;
  ListOfGeneProducts mGeneProducts;

  /** @endcond */

public:

  /**
   * Creates a new FbcModelPlugin using the given URI, prefix and package
   * namespace.
   *
   * @param uri a string, representing the URI of the SBML Level&nbsp;3 package
   * implemented by this libSBML package extension.
   *
   * @param prefix a string, the XML namespace prefix being used for this
   * package.
   *
   * @param fbcns a pointer to the namesspaces object (FbcPkgNamespaces) for
   * this package.
   *
   * @copydetails doc_what_are_xmlnamespaces
   *
   * @copydetails doc_what_are_sbmlnamespaces
   */
  FbcModelPlugin(const std::string& uri,
                 const std::string& prefix,
                 FbcPkgNamespaces* fbcns);


  /**
   * Copy constructor for FbcModelPlugin.
   *
   * @param orig the FbcModelPlugin instance to copy.
   */
  FbcModelPlugin(const FbcModelPlugin& orig);


  /**
   * Assignment operator for FbcModelPlugin.
   *
   * @param rhs the FbcModelPlugin object whose values are to be used as the
   * basis of the assignment.
   */
  FbcModelPlugin& operator=(const FbcModelPlugin& rhs);


  /**
   * Creates and returns a deep copy of this FbcModelPlugin object.
   *
   * @return a (deep) copy of this FbcModelPlugin object.
   */
  virtual FbcModelPlugin* clone() const;


  /**
   * Destructor for FbcModelPlugin.
   */
  virtual ~FbcModelPlugin();


  /**
   * Returns the value of the "strict" attribute of this FbcModelPlugin.
   *
   * @return the value of the "strict" attribute of this FbcModelPlugin as a
   * boolean.
   */
  bool getStrict() const;


  /**
   * Predicate returning @c true if this FbcModelPlugin's "strict" attribute is
   * set.
   *
   * @return @c true if this FbcModelPlugin's "strict" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetStrict() const;


  /**
   * Sets the value of the "strict" attribute of this FbcModelPlugin.
   *
   * @param strict bool value of the "strict" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStrict(bool strict);


  /**
   * Unsets the value of the "strict" attribute of this FbcModelPlugin.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStrict();


  /**
   * Returns the ListOfObjectives from this FbcModelPlugin.
   *
   * @return the ListOfObjectives from this FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see getObjective(const std::string& sid)
   * @see getObjective(unsigned int n)
   * @see getNumObjectives()
   * @see removeObjective(const std::string& sid)
   * @see removeObjective(unsigned int n)
   */
  const ListOfObjectives* getListOfObjectives() const;


  /**
   * Returns the ListOfObjectives from this FbcModelPlugin.
   *
   * @return the ListOfObjectives from this FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see getObjective(const std::string& sid)
   * @see getObjective(unsigned int n)
   * @see getNumObjectives()
   * @see removeObjective(const std::string& sid)
   * @see removeObjective(unsigned int n)
   */
  ListOfObjectives* getListOfObjectives();


  /**
   * Get an Objective from the FbcModelPlugin.
   *
   * @param n an unsigned int representing the index of the Objective to
   * retrieve.
   *
   * @return the nth Objective in the ListOfObjectives within this
   * FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see getObjective(const std::string& sid)
   * @see getNumObjectives()
   * @see removeObjective(const std::string& sid)
   * @see removeObjective(unsigned int n)
   */
  Objective* getObjective(unsigned int n);


  /**
   * Get an Objective from the FbcModelPlugin.
   *
   * @param n an unsigned int representing the index of the Objective to
   * retrieve.
   *
   * @return the nth Objective in the ListOfObjectives within this
   * FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see getObjective(const std::string& sid)
   * @see getNumObjectives()
   * @see removeObjective(const std::string& sid)
   * @see removeObjective(unsigned int n)
   */
  const Objective* getObjective(unsigned int n) const;


  /**
   * Get an Objective from the FbcModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the Objective to
   * retrieve.
   *
   * @return the Objective in the ListOfObjectives within this FbcModelPlugin
   * with the given @p sid or @c NULL if no such Objective exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see getObjective(unsigned int n)
   * @see getNumObjectives()
   * @see removeObjective(const std::string& sid)
   * @see removeObjective(unsigned int n)
   */
  Objective* getObjective(const std::string& sid);


  /**
   * Get an Objective from the FbcModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the Objective to
   * retrieve.
   *
   * @return the Objective in the ListOfObjectives within this FbcModelPlugin
   * with the given @p sid or @c NULL if no such Objective exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see getObjective(unsigned int n)
   * @see getNumObjectives()
   * @see removeObjective(const std::string& sid)
   * @see removeObjective(unsigned int n)
   */
  const Objective* getObjective(const std::string& sid) const;


  /**
   * Adds a copy of the given Objective to this FbcModelPlugin.
   *
   * @param o the Objective object to add.
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
   * @see createObjective()
   * @see getObjective(const std::string& sid)
   * @see getObjective(unsigned int n)
   * @see getNumObjectives()
   * @see removeObjective(const std::string& sid)
   * @see removeObjective(unsigned int n)
   */
  int addObjective(const Objective* o);


  /**
   * Get the number of Objective objects in this FbcModelPlugin.
   *
   * @return the number of Objective objects in this FbcModelPlugin.
   *
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see getObjective(const std::string& sid)
   * @see getObjective(unsigned int n)
   * @see removeObjective(const std::string& sid)
   * @see removeObjective(unsigned int n)
   */
  unsigned int getNumObjectives() const;


  /**
   * Creates a new Objective object, adds it to this FbcModelPlugin object and
   * returns the Objective object created.
   *
   * @return a new Objective object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see getObjective(const std::string& sid)
   * @see getObjective(unsigned int n)
   * @see getNumObjectives()
   * @see removeObjective(const std::string& sid)
   * @see removeObjective(unsigned int n)
   */
  Objective* createObjective();


  /**
   * Removes the nth Objective from this FbcModelPlugin and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the Objective to
   * remove.
   *
   * @return a pointer to the nth Objective in this FbcModelPlugin.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see getObjective(const std::string& sid)
   * @see getObjective(unsigned int n)
   * @see getNumObjectives()
   * @see removeObjective(const std::string& sid)
   */
  Objective* removeObjective(unsigned int n);


  /**
   * Removes the Objective from this FbcModelPlugin based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the Objective to
   * remove.
   *
   * @return the Objective in this FbcModelPlugin based on the identifier or
   * NULL if no such Objective exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addObjective(const Objective* object)
   * @see createObjective()
   * @see getObjective(const std::string& sid)
   * @see getObjective(unsigned int n)
   * @see getNumObjectives()
   * @see removeObjective(unsigned int n)
   */
  Objective* removeObjective(const std::string& sid);


  /**
   * Returns the ListOfFluxBounds from this FbcModelPlugin.
   *
   * @return the ListOfFluxBounds from this FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxBound(const FluxBound* object)
   * @see createFluxBound()
   * @see getFluxBound(const std::string& sid)
   * @see getFluxBound(unsigned int n)
   * @see getNumFluxBounds()
   * @see removeFluxBound(const std::string& sid)
   * @see removeFluxBound(unsigned int n)
   */
  const ListOfFluxBounds* getListOfFluxBounds() const;


  /**
   * Returns the ListOfFluxBounds from this FbcModelPlugin.
   *
   * @return the ListOfFluxBounds from this FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxBound(const FluxBound* object)
   * @see createFluxBound()
   * @see getFluxBound(const std::string& sid)
   * @see getFluxBound(unsigned int n)
   * @see getNumFluxBounds()
   * @see removeFluxBound(const std::string& sid)
   * @see removeFluxBound(unsigned int n)
   */
  ListOfFluxBounds* getListOfFluxBounds();


  /**
   * Get a FluxBound from the FbcModelPlugin.
   *
   * @param n an unsigned int representing the index of the FluxBound to
   * retrieve.
   *
   * @return the nth FluxBound in the ListOfFluxBounds within this
   * FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxBound(const FluxBound* object)
   * @see createFluxBound()
   * @see getFluxBound(const std::string& sid)
   * @see getNumFluxBounds()
   * @see removeFluxBound(const std::string& sid)
   * @see removeFluxBound(unsigned int n)
   */
  FluxBound* getFluxBound(unsigned int n);


  /**
   * Get a FluxBound from the FbcModelPlugin.
   *
   * @param n an unsigned int representing the index of the FluxBound to
   * retrieve.
   *
   * @return the nth FluxBound in the ListOfFluxBounds within this
   * FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxBound(const FluxBound* object)
   * @see createFluxBound()
   * @see getFluxBound(const std::string& sid)
   * @see getNumFluxBounds()
   * @see removeFluxBound(const std::string& sid)
   * @see removeFluxBound(unsigned int n)
   */
  const FluxBound* getFluxBound(unsigned int n) const;


  /**
   * Get a FluxBound from the FbcModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the FluxBound to
   * retrieve.
   *
   * @return the FluxBound in the ListOfFluxBounds within this FbcModelPlugin
   * with the given @p sid or @c NULL if no such FluxBound exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxBound(const FluxBound* object)
   * @see createFluxBound()
   * @see getFluxBound(unsigned int n)
   * @see getNumFluxBounds()
   * @see removeFluxBound(const std::string& sid)
   * @see removeFluxBound(unsigned int n)
   */
  FluxBound* getFluxBound(const std::string& sid);


  /**
   * Get a FluxBound from the FbcModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the FluxBound to
   * retrieve.
   *
   * @return the FluxBound in the ListOfFluxBounds within this FbcModelPlugin
   * with the given @p sid or @c NULL if no such FluxBound exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxBound(const FluxBound* object)
   * @see createFluxBound()
   * @see getFluxBound(unsigned int n)
   * @see getNumFluxBounds()
   * @see removeFluxBound(const std::string& sid)
   * @see removeFluxBound(unsigned int n)
   */
  const FluxBound* getFluxBound(const std::string& sid) const;


  /**
   * Get a FluxBound from the FbcModelPlugin based on the Reaction to which it
   * refers.
   *
   * @param sid a string representing the "reaction" attribute of the FluxBound
   * object to retrieve.
   *
   * @return the first FluxBound in this FbcModelPlugin based on the given
   * reaction attribute or NULL if no such FluxBound exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const FluxBound* getFluxBoundByReaction(const std::string& sid) const;


  /**
   * Get a FluxBound from the FbcModelPlugin based on the Reaction to which it
   * refers.
   *
   * @param sid a string representing the "reaction" attribute of the FluxBound
   * object to retrieve.
   *
   * @return the first FluxBound in this FbcModelPlugin based on the given
   * reaction attribute or NULL if no such FluxBound exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  FluxBound* getFluxBoundByReaction(const std::string& sid);


  /**
   * Adds a copy of the given FluxBound to this FbcModelPlugin.
   *
   * @param fb the FluxBound object to add.
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
   * @see createFluxBound()
   * @see getFluxBound(const std::string& sid)
   * @see getFluxBound(unsigned int n)
   * @see getNumFluxBounds()
   * @see removeFluxBound(const std::string& sid)
   * @see removeFluxBound(unsigned int n)
   */
  int addFluxBound(const FluxBound* fb);


  /**
   * Get the number of FluxBound objects in this FbcModelPlugin.
   *
   * @return the number of FluxBound objects in this FbcModelPlugin.
   *
   *
   * @see addFluxBound(const FluxBound* object)
   * @see createFluxBound()
   * @see getFluxBound(const std::string& sid)
   * @see getFluxBound(unsigned int n)
   * @see removeFluxBound(const std::string& sid)
   * @see removeFluxBound(unsigned int n)
   */
  unsigned int getNumFluxBounds() const;


  /**
   * Creates a new FluxBound object, adds it to this FbcModelPlugin object and
   * returns the FluxBound object created.
   *
   * @return a new FluxBound object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addFluxBound(const FluxBound* object)
   * @see getFluxBound(const std::string& sid)
   * @see getFluxBound(unsigned int n)
   * @see getNumFluxBounds()
   * @see removeFluxBound(const std::string& sid)
   * @see removeFluxBound(unsigned int n)
   */
  FluxBound* createFluxBound();


  /**
   * Removes the nth FluxBound from this FbcModelPlugin and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the FluxBound to
   * remove.
   *
   * @return a pointer to the nth FluxBound in this FbcModelPlugin.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addFluxBound(const FluxBound* object)
   * @see createFluxBound()
   * @see getFluxBound(const std::string& sid)
   * @see getFluxBound(unsigned int n)
   * @see getNumFluxBounds()
   * @see removeFluxBound(const std::string& sid)
   */
  FluxBound* removeFluxBound(unsigned int n);


  /**
   * Removes the FluxBound from this FbcModelPlugin based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the FluxBound to
   * remove.
   *
   * @return the FluxBound in this FbcModelPlugin based on the identifier or
   * NULL if no such FluxBound exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addFluxBound(const FluxBound* object)
   * @see createFluxBound()
   * @see getFluxBound(const std::string& sid)
   * @see getFluxBound(unsigned int n)
   * @see getNumFluxBounds()
   * @see removeFluxBound(unsigned int n)
   */
  FluxBound* removeFluxBound(const std::string& sid);


  /**
   * Returns the ListOfGeneProducts from this FbcModelPlugin.
   *
   * @return the ListOfGeneProducts from this FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see createGeneProduct()
   * @see getGeneProduct(const std::string& sid)
   * @see getGeneProduct(unsigned int n)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(const std::string& sid)
   * @see removeGeneProduct(unsigned int n)
   */
  const ListOfGeneProducts* getListOfGeneProducts() const;


  /**
   * Returns the ListOfGeneProducts from this FbcModelPlugin.
   *
   * @return the ListOfGeneProducts from this FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see createGeneProduct()
   * @see getGeneProduct(const std::string& sid)
   * @see getGeneProduct(unsigned int n)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(const std::string& sid)
   * @see removeGeneProduct(unsigned int n)
   */
  ListOfGeneProducts* getListOfGeneProducts();


  /**
   * Get a GeneProduct from the FbcModelPlugin.
   *
   * @param n an unsigned int representing the index of the GeneProduct to
   * retrieve.
   *
   * @return the nth GeneProduct in the ListOfGeneProducts within this
   * FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see createGeneProduct()
   * @see getGeneProduct(const std::string& sid)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(const std::string& sid)
   * @see removeGeneProduct(unsigned int n)
   */
  GeneProduct* getGeneProduct(unsigned int n);


  /**
   * Get a GeneProduct from the FbcModelPlugin.
   *
   * @param n an unsigned int representing the index of the GeneProduct to
   * retrieve.
   *
   * @return the nth GeneProduct in the ListOfGeneProducts within this
   * FbcModelPlugin.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see createGeneProduct()
   * @see getGeneProduct(const std::string& sid)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(const std::string& sid)
   * @see removeGeneProduct(unsigned int n)
   */
  const GeneProduct* getGeneProduct(unsigned int n) const;


  /**
   * Get a GeneProduct from the FbcModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the GeneProduct to
   * retrieve.
   *
   * @return the GeneProduct in the ListOfGeneProducts within this
   * FbcModelPlugin with the given @p sid or @c NULL if no such GeneProduct
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see createGeneProduct()
   * @see getGeneProduct(unsigned int n)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(const std::string& sid)
   * @see removeGeneProduct(unsigned int n)
   */
  GeneProduct* getGeneProduct(const std::string& sid);


  /**
   * Get a GeneProduct from the FbcModelPlugin based on its identifier.
   *
   * @param sid a string representing the identifier of the GeneProduct to
   * retrieve.
   *
   * @return the GeneProduct in the ListOfGeneProducts within this
   * FbcModelPlugin with the given @p sid or @c NULL if no such GeneProduct
   * exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see createGeneProduct()
   * @see getGeneProduct(unsigned int n)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(const std::string& sid)
   * @see removeGeneProduct(unsigned int n)
   */
  const GeneProduct* getGeneProduct(const std::string& sid) const;


  /**
   * Get a GeneProduct from the FbcModelPlugin based on the AssociatedSpecies
   * to which it refers.
   *
   * @param sid a string representing the "associatedSpecies" attribute of the
   * GeneProduct object to retrieve.
   *
   * @return the first GeneProduct in this FbcModelPlugin based on the given
   * associatedSpecies attribute or NULL if no such GeneProduct exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const GeneProduct* getGeneProductByAssociatedSpecies(const std::string& sid)
    const;


  /**
   * Get a GeneProduct from the FbcModelPlugin based on the AssociatedSpecies
   * to which it refers.
   *
   * @param sid a string representing the "associatedSpecies" attribute of the
   * GeneProduct object to retrieve.
   *
   * @return the first GeneProduct in this FbcModelPlugin based on the given
   * associatedSpecies attribute or NULL if no such GeneProduct exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  GeneProduct* getGeneProductByAssociatedSpecies(const std::string& sid);


  /**
   * Adds a copy of the given GeneProduct to this FbcModelPlugin.
   *
   * @param gp the GeneProduct object to add.
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
   * @see createGeneProduct()
   * @see getGeneProduct(const std::string& sid)
   * @see getGeneProduct(unsigned int n)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(const std::string& sid)
   * @see removeGeneProduct(unsigned int n)
   */
  int addGeneProduct(const GeneProduct* gp);


  /**
   * Get the number of GeneProduct objects in this FbcModelPlugin.
   *
   * @return the number of GeneProduct objects in this FbcModelPlugin.
   *
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see createGeneProduct()
   * @see getGeneProduct(const std::string& sid)
   * @see getGeneProduct(unsigned int n)
   * @see removeGeneProduct(const std::string& sid)
   * @see removeGeneProduct(unsigned int n)
   */
  unsigned int getNumGeneProducts() const;


  /**
   * Creates a new GeneProduct object, adds it to this FbcModelPlugin object
   * and returns the GeneProduct object created.
   *
   * @return a new GeneProduct object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see getGeneProduct(const std::string& sid)
   * @see getGeneProduct(unsigned int n)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(const std::string& sid)
   * @see removeGeneProduct(unsigned int n)
   */
  GeneProduct* createGeneProduct();


  /**
   * Removes the nth GeneProduct from this FbcModelPlugin and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the GeneProduct to
   * remove.
   *
   * @return a pointer to the nth GeneProduct in this FbcModelPlugin.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see createGeneProduct()
   * @see getGeneProduct(const std::string& sid)
   * @see getGeneProduct(unsigned int n)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(const std::string& sid)
   */
  GeneProduct* removeGeneProduct(unsigned int n);


  /**
   * Removes the GeneProduct from this FbcModelPlugin based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the GeneProduct to
   * remove.
   *
   * @return the GeneProduct in this FbcModelPlugin based on the identifier or
   * NULL if no such GeneProduct exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addGeneProduct(const GeneProduct* object)
   * @see createGeneProduct()
   * @see getGeneProduct(const std::string& sid)
   * @see getGeneProduct(unsigned int n)
   * @see getNumGeneProducts()
   * @see removeGeneProduct(unsigned int n)
   */
  GeneProduct* removeGeneProduct(const std::string& sid);


  /**
   * Predicate returning @c true if all the required attributes for this
   * FbcModelPlugin object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * FbcModelPlugin have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the FbcModelPlugin object are:
   * @li "strict"
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




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Gets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Predicate returning @c true if this FbcModelPlugin's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this FbcModelPlugin's attribute "attributeName" has
   * been set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Sets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Unsets the value of the "attributeName" attribute of this FbcModelPlugin.
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
   * Creates and returns an new "elementName" object in this FbcModelPlugin.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this FbcModelPlugin.
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
   * FbcModelPlugin.
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
   * Returns the number of "elementName" in this FbcModelPlugin.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this FbcModelPlugin.
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
  virtual void readL3V1V1Attributes(const XMLAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readL3V1V2Attributes(const XMLAttributes& attributes);

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
  virtual void writeL3V1V1Attributes(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeL3V1V2Attributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Returns a ListOf_t * containing Objective_t objects from this
 * FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure whose ListOfObjectives is sought.
 *
 * @return the ListOfObjectives from this FbcModelPlugin_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see FbcModelPlugin_addObjective()
 * @see FbcModelPlugin_createObjective()
 * @see FbcModelPlugin_getObjectiveById()
 * @see FbcModelPlugin_getObjective()
 * @see FbcModelPlugin_getNumObjectives()
 * @see FbcModelPlugin_removeObjectiveById()
 * @see FbcModelPlugin_removeObjective()
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
ListOf_t*
FbcModelPlugin_getListOfObjectives(FbcModelPlugin_t* fmp);


/**
 * Get an Objective_t from the FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the Objective_t to
 * retrieve.
 *
 * @return the nth Objective_t in the ListOfObjectives within this
 * FbcModelPlugin.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_getObjective(FbcModelPlugin_t* fmp, unsigned int n);


/**
 * Get an Objective_t from the FbcModelPlugin_t based on its identifier.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the Objective_t to
 * retrieve.
 *
 * @return the Objective_t in the ListOfObjectives within this FbcModelPlugin
 * with the given @p sid or @c NULL if no such Objective_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_getObjectiveById(FbcModelPlugin_t* fmp, const char *sid);


/**
 * Adds a copy of the given Objective_t to this FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure to which the Objective_t should be
 * added.
 *
 * @param o the Objective_t object to add.
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
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
int
FbcModelPlugin_addObjective(FbcModelPlugin_t* fmp, const Objective_t* o);


/**
 * Get the number of Objective_t objects in this FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure to query.
 *
 * @return the number of Objective_t objects in this FbcModelPlugin_t.
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
unsigned int
FbcModelPlugin_getNumObjectives(FbcModelPlugin_t* fmp);


/**
 * Creates a new Objective_t object, adds it to this FbcModelPlugin_t object
 * and returns the Objective_t object created.
 *
 * @param fmp the FbcModelPlugin_t structure to which the Objective_t should be
 * added.
 *
 * @return a new Objective_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_createObjective(FbcModelPlugin_t* fmp);


/**
 * Removes the nth Objective_t from this FbcModelPlugin_t and returns a pointer
 * to it.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the Objective_t to
 * remove.
 *
 * @return a pointer to the nth Objective_t in this FbcModelPlugin_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_removeObjective(FbcModelPlugin_t* fmp, unsigned int n);


/**
 * Removes the Objective_t from this FbcModelPlugin_t based on its identifier
 * and returns a pointer to it.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the Objective_t to
 * remove.
 *
 * @return the Objective_t in this FbcModelPlugin_t based on the identifier or
 * NULL if no such Objective_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
Objective_t*
FbcModelPlugin_removeObjectiveById(FbcModelPlugin_t* fmp, const char* sid);


/**
 * Returns a ListOf_t * containing FluxBound_t objects from this
 * FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure whose ListOfFluxBounds is sought.
 *
 * @return the ListOfFluxBounds from this FbcModelPlugin_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see FbcModelPlugin_addFluxBound()
 * @see FbcModelPlugin_createFluxBound()
 * @see FbcModelPlugin_getFluxBoundById()
 * @see FbcModelPlugin_getFluxBound()
 * @see FbcModelPlugin_getNumFluxBounds()
 * @see FbcModelPlugin_removeFluxBoundById()
 * @see FbcModelPlugin_removeFluxBound()
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
ListOf_t*
FbcModelPlugin_getListOfFluxBounds(FbcModelPlugin_t* fmp);


/**
 * Get a FluxBound_t from the FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the FluxBound_t to
 * retrieve.
 *
 * @return the nth FluxBound_t in the ListOfFluxBounds within this
 * FbcModelPlugin.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_getFluxBound(FbcModelPlugin_t* fmp, unsigned int n);


/**
 * Get a FluxBound_t from the FbcModelPlugin_t based on its identifier.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the FluxBound_t to
 * retrieve.
 *
 * @return the FluxBound_t in the ListOfFluxBounds within this FbcModelPlugin
 * with the given @p sid or @c NULL if no such FluxBound_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_getFluxBoundById(FbcModelPlugin_t* fmp, const char *sid);


/**
 * Get a FluxBound_t from the FbcModelPlugin_t based on the Reaction to which
 * it refers.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param sid a string representing the "reaction" attribute of the FluxBound_t
 * object to retrieve.
 *
 * @return the first FluxBound_t in this FbcModelPlugin_t based on the given
 * reaction attribute or NULL if no such FluxBound_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_getFluxBoundByReaction(FbcModelPlugin_t* fmp, const char *sid);


/**
 * Adds a copy of the given FluxBound_t to this FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure to which the FluxBound_t should be
 * added.
 *
 * @param fb the FluxBound_t object to add.
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
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
int
FbcModelPlugin_addFluxBound(FbcModelPlugin_t* fmp, const FluxBound_t* fb);


/**
 * Get the number of FluxBound_t objects in this FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure to query.
 *
 * @return the number of FluxBound_t objects in this FbcModelPlugin_t.
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
unsigned int
FbcModelPlugin_getNumFluxBounds(FbcModelPlugin_t* fmp);


/**
 * Creates a new FluxBound_t object, adds it to this FbcModelPlugin_t object
 * and returns the FluxBound_t object created.
 *
 * @param fmp the FbcModelPlugin_t structure to which the FluxBound_t should be
 * added.
 *
 * @return a new FluxBound_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_createFluxBound(FbcModelPlugin_t* fmp);


/**
 * Removes the nth FluxBound_t from this FbcModelPlugin_t and returns a pointer
 * to it.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the FluxBound_t to
 * remove.
 *
 * @return a pointer to the nth FluxBound_t in this FbcModelPlugin_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_removeFluxBound(FbcModelPlugin_t* fmp, unsigned int n);


/**
 * Removes the FluxBound_t from this FbcModelPlugin_t based on its identifier
 * and returns a pointer to it.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the FluxBound_t to
 * remove.
 *
 * @return the FluxBound_t in this FbcModelPlugin_t based on the identifier or
 * NULL if no such FluxBound_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
FluxBound_t*
FbcModelPlugin_removeFluxBoundById(FbcModelPlugin_t* fmp, const char* sid);


/**
 * Returns a ListOf_t * containing GeneProduct_t objects from this
 * FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure whose ListOfGeneProducts is
 * sought.
 *
 * @return the ListOfGeneProducts from this FbcModelPlugin_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see FbcModelPlugin_addGeneProduct()
 * @see FbcModelPlugin_createGeneProduct()
 * @see FbcModelPlugin_getGeneProductById()
 * @see FbcModelPlugin_getGeneProduct()
 * @see FbcModelPlugin_getNumGeneProducts()
 * @see FbcModelPlugin_removeGeneProductById()
 * @see FbcModelPlugin_removeGeneProduct()
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
ListOf_t*
FbcModelPlugin_getListOfGeneProducts(FbcModelPlugin_t* fmp);


/**
 * Get a GeneProduct_t from the FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the GeneProduct_t to
 * retrieve.
 *
 * @return the nth GeneProduct_t in the ListOfGeneProducts within this
 * FbcModelPlugin.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_getGeneProduct(FbcModelPlugin_t* fmp, unsigned int n);


/**
 * Get a GeneProduct_t from the FbcModelPlugin_t based on its identifier.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the GeneProduct_t to
 * retrieve.
 *
 * @return the GeneProduct_t in the ListOfGeneProducts within this
 * FbcModelPlugin with the given @p sid or @c NULL if no such GeneProduct_t
 * exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_getGeneProductById(FbcModelPlugin_t* fmp, const char *sid);


/**
 * Get a GeneProduct_t from the FbcModelPlugin_t based on the AssociatedSpecies
 * to which it refers.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param sid a string representing the "associatedSpecies" attribute of the
 * GeneProduct_t object to retrieve.
 *
 * @return the first GeneProduct_t in this FbcModelPlugin_t based on the given
 * associatedSpecies attribute or NULL if no such GeneProduct_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_getGeneProductByAssociatedSpecies(FbcModelPlugin_t* fmp,
                                                 const char *sid);


/**
 * Adds a copy of the given GeneProduct_t to this FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure to which the GeneProduct_t should
 * be added.
 *
 * @param gp the GeneProduct_t object to add.
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
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
int
FbcModelPlugin_addGeneProduct(FbcModelPlugin_t* fmp, const GeneProduct_t* gp);


/**
 * Get the number of GeneProduct_t objects in this FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure to query.
 *
 * @return the number of GeneProduct_t objects in this FbcModelPlugin_t.
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
unsigned int
FbcModelPlugin_getNumGeneProducts(FbcModelPlugin_t* fmp);


/**
 * Creates a new GeneProduct_t object, adds it to this FbcModelPlugin_t object
 * and returns the GeneProduct_t object created.
 *
 * @param fmp the FbcModelPlugin_t structure to which the GeneProduct_t should
 * be added.
 *
 * @return a new GeneProduct_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_createGeneProduct(FbcModelPlugin_t* fmp);


/**
 * Removes the nth GeneProduct_t from this FbcModelPlugin_t and returns a
 * pointer to it.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param n an unsigned int representing the index of the GeneProduct_t to
 * remove.
 *
 * @return a pointer to the nth GeneProduct_t in this FbcModelPlugin_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_removeGeneProduct(FbcModelPlugin_t* fmp, unsigned int n);


/**
 * Removes the GeneProduct_t from this FbcModelPlugin_t based on its identifier
 * and returns a pointer to it.
 *
 * @param fmp the FbcModelPlugin_t structure to search.
 *
 * @param sid a string representing the identifier of the GeneProduct_t to
 * remove.
 *
 * @return the GeneProduct_t in this FbcModelPlugin_t based on the identifier
 * or NULL if no such GeneProduct_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
GeneProduct_t*
FbcModelPlugin_removeGeneProductById(FbcModelPlugin_t* fmp, const char* sid);


/**
 * Returns the value of the "strict" attribute of this FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure whose strict is sought.
 *
 * @return the value of the "strict" attribute of this FbcModelPlugin_t as a
 * boolean.
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
int
FbcModelPlugin_getStrict(const FbcModelPlugin_t * fmp);


/**
 * Predicate returning @c 1 (true) if this FbcModelPlugin_t's "strict"
 * attribute is set.
 *
 * @param fmp the FbcModelPlugin_t structure.
 *
 * @return @c 1 (true) if this FbcModelPlugin_t's "strict" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
int
FbcModelPlugin_isSetStrict(const FbcModelPlugin_t * fmp);


/**
 * Sets the value of the "strict" attribute of this FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure.
 *
 * @param strict int value of the "strict" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
int
FbcModelPlugin_setStrict(FbcModelPlugin_t * fmp, int strict);


/**
 * Unsets the value of the "strict" attribute of this FbcModelPlugin_t.
 *
 * @param fmp the FbcModelPlugin_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof FbcModelPlugin_t
 */
LIBSBML_EXTERN
int
FbcModelPlugin_unsetStrict(FbcModelPlugin_t * fmp);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !FbcModelPlugin_H__ */


