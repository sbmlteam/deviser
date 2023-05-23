/**
 * @file Map.h
 * @brief Definition of the Map class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
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
 * @class Map
 * @sbmlbrief{sbgnml} TODO:Definition of the Map class.
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
 * @class doc_map_language
 *
 * @par
 * The attribute "language" on a Map object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sbgnml specification, the following are the
 * allowable values for "language":
 * <ul>
 * <li> @c "process description", TODO:add description
 *
 * <li> @c "entity relationship", TODO:add description
 *
 * <li> @c "activity flow", TODO:add description
 *
 * </ul>
 */


#ifndef Map_H__
#define Map_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>
#include <sbgn/common/SbgnEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SBase.h>
#include <sbgn/BBox.h>
#include <sbgn/SbgnListOfGlyphs.h>
#include <sbgn/SbgnListOfArcs.h>
#include <sbgn/SbgnListOfArcGroups.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN Map : public SBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  Language_t mLanguage;
  BBox* mBBox;
  SbgnListOfGlyphs mGlyphs;
  SbgnListOfArcs mArcs;
  SbgnListOfArcGroups mArcGroups;

  /** @endcond */

public:

  /**
   * Creates a new Map using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this Map.
   *
   * @param version an unsigned int, the SBGN Version to assign to this Map.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Map(unsigned int level = SBGN_DEFAULT_LEVEL,
      unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new Map using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Map(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for Map.
   *
   * @param orig the Map instance to copy.
   */
  Map(const Map& orig);


  /**
   * Assignment operator for Map.
   *
   * @param rhs the Map object whose values are to be used as the basis of the
   * assignment.
   */
  Map& operator=(const Map& rhs);


  /**
   * Creates and returns a deep copy of this Map object.
   *
   * @return a (deep) copy of this Map object.
   */
  virtual Map* clone() const;


  /**
   * Destructor for Map.
   */
  virtual ~Map();


  /**
   * Returns the value of the "id" attribute of this Map.
   *
   * @return the value of the "id" attribute of this Map as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "language" attribute of this Map.
   *
   * @return the value of the "language" attribute of this Map as a Language_t.
   *
   * @copydetails doc_map_language
   * @if clike The value is drawn from the enumeration @ref Language_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SBGNML_LANGUAGE_PROCESS_DESCRIPTION, Language_t}
   * @li @sbmlconstant{SBGNML_LANGUAGE_ENTITY_RELATIONSHIP, Language_t}
   * @li @sbmlconstant{SBGNML_LANGUAGE_ACTIVITY_FLOW, Language_t}
   * @li @sbmlconstant{SBGNML_LANGUAGE_INVALID, Language_t}
   */
  Language_t getLanguage() const;


  /**
   * Returns the value of the "language" attribute of this Map.
   *
   * @return the value of the "language" attribute of this Map as a string.
   *
   * @copydetails doc_map_language
   * The possible values returned by this method are:
   * @li @c "process description"
   * @li @c "entity relationship"
   * @li @c "activity flow"
   * @li @c "invalid Language value"
   */
  std::string getLanguageAsString() const;


  /**
   * Predicate returning @c true if this Map's "id" attribute is set.
   *
   * @return @c true if this Map's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this Map's "language" attribute is set.
   *
   * @return @c true if this Map's "language" attribute has been set, otherwise
   * @c false is returned.
   *
   * @copydetails doc_map_language
   */
  bool isSetLanguage() const;


  /**
   * Sets the value of the "id" attribute of this Map.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "language" attribute of this Map.
   *
   * @param language @if clike Language_t@else int@endif value of the
   * "language" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_map_language
   */
  int setLanguage(const Language_t language);


  /**
   * Sets the value of the "language" attribute of this Map.
   *
   * @param language std::string& of the "language" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_map_language
   */
  int setLanguage(const std::string& language);


  /**
   * Unsets the value of the "id" attribute of this Map.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "language" attribute of this Map.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_map_language
   */
  int unsetLanguage();


  /**
   * Returns the value of the "bbox" element of this Map.
   *
   * @return the value of the "bbox" element of this Map as a BBox*.
   */
  const BBox* getBBox() const;


  /**
   * Returns the value of the "bbox" element of this Map.
   *
   * @return the value of the "bbox" element of this Map as a BBox*.
   */
  BBox* getBBox();


  /**
   * Predicate returning @c true if this Map's "bbox" element is set.
   *
   * @return @c true if this Map's "bbox" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetBBox() const;


  /**
   * Sets the value of the "bbox" element of this Map.
   *
   * @param bbox BBox* value of the "bbox" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBBox(const BBox* bbox);


  /**
   * Creates a new BBox object, adds it to this Map object and returns the BBox
   * object created.
   *
   * @return a new BBox object instance.
   */
  BBox* createBBox();


  /**
   * Unsets the value of the "bbox" element of this Map.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBBox();


  /**
   * Returns the SbgnListOfGlyphs from this Map.
   *
   * @return the SbgnListOfGlyphs from this Map.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const Glyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  const SbgnListOfGlyphs* getListOfGlyphs() const;


  /**
   * Returns the SbgnListOfGlyphs from this Map.
   *
   * @return the SbgnListOfGlyphs from this Map.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const Glyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  SbgnListOfGlyphs* getListOfGlyphs();


  /**
   * Get a Glyph from the Map.
   *
   * @param n an unsigned int representing the index of the Glyph to retrieve.
   *
   * @return the nth Glyph in the SbgnListOfGlyphs within this Map or @c NULL
   * if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const Glyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  Glyph* getGlyph(unsigned int n);


  /**
   * Get a Glyph from the Map.
   *
   * @param n an unsigned int representing the index of the Glyph to retrieve.
   *
   * @return the nth Glyph in the SbgnListOfGlyphs within this Map or @c NULL
   * if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const Glyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  const Glyph* getGlyph(unsigned int n) const;


  /**
   * Get a Glyph from the Map based on its identifier.
   *
   * @param sid a string representing the identifier of the Glyph to retrieve.
   *
   * @return the Glyph in the SbgnListOfGlyphs within this Map with the given
   * @p sid or @c NULL if no such Glyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const Glyph* object)
   * @see createGlyph()
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  Glyph* getGlyph(const std::string& sid);


  /**
   * Get a Glyph from the Map based on its identifier.
   *
   * @param sid a string representing the identifier of the Glyph to retrieve.
   *
   * @return the Glyph in the SbgnListOfGlyphs within this Map with the given
   * @p sid or @c NULL if no such Glyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const Glyph* object)
   * @see createGlyph()
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  const Glyph* getGlyph(const std::string& sid) const;


  /**
   * Adds a copy of the given Glyph to this Map.
   *
   * @param g the Glyph object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  int addGlyph(const Glyph* g);


  /**
   * Get the number of Glyph objects in this Map.
   *
   * @return the number of Glyph objects in this Map.
   *
   * @see addGlyph(const Glyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  unsigned int getNumGlyphs() const;


  /**
   * Creates a new Glyph object, adds it to this Map object and returns the
   * Glyph object created.
   *
   * @return a new Glyph object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const Glyph* object)
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  Glyph* createGlyph();


  /**
   * Removes the nth Glyph from this Map and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Glyph to remove.
   *
   * @return a pointer to the nth Glyph in this Map.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addGlyph(const Glyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   */
  Glyph* removeGlyph(unsigned int n);


  /**
   * Removes the Glyph from this Map based on its identifier and returns a
   * pointer to it.
   *
   * @param sid a string representing the identifier of the Glyph to remove.
   *
   * @return the Glyph in this Map based on the identifier or NULL if no such
   * Glyph exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addGlyph(const Glyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(unsigned int n)
   */
  Glyph* removeGlyph(const std::string& sid);


  /**
   * Returns the SbgnListOfArcs from this Map.
   *
   * @return the SbgnListOfArcs from this Map.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const Arc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  const SbgnListOfArcs* getListOfArcs() const;


  /**
   * Returns the SbgnListOfArcs from this Map.
   *
   * @return the SbgnListOfArcs from this Map.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const Arc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  SbgnListOfArcs* getListOfArcs();


  /**
   * Get an Arc from the Map.
   *
   * @param n an unsigned int representing the index of the Arc to retrieve.
   *
   * @return the nth Arc in the SbgnListOfArcs within this Map or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const Arc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  Arc* getArc(unsigned int n);


  /**
   * Get an Arc from the Map.
   *
   * @param n an unsigned int representing the index of the Arc to retrieve.
   *
   * @return the nth Arc in the SbgnListOfArcs within this Map or @c NULL if no
   * such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const Arc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  const Arc* getArc(unsigned int n) const;


  /**
   * Get an Arc from the Map based on its identifier.
   *
   * @param sid a string representing the identifier of the Arc to retrieve.
   *
   * @return the Arc in the SbgnListOfArcs within this Map with the given @p
   * sid or @c NULL if no such Arc exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const Arc* object)
   * @see createArc()
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  Arc* getArc(const std::string& sid);


  /**
   * Get an Arc from the Map based on its identifier.
   *
   * @param sid a string representing the identifier of the Arc to retrieve.
   *
   * @return the Arc in the SbgnListOfArcs within this Map with the given @p
   * sid or @c NULL if no such Arc exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const Arc* object)
   * @see createArc()
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  const Arc* getArc(const std::string& sid) const;


  /**
   * Adds a copy of the given Arc to this Map.
   *
   * @param a the Arc object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  int addArc(const Arc* a);


  /**
   * Get the number of Arc objects in this Map.
   *
   * @return the number of Arc objects in this Map.
   *
   * @see addArc(const Arc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  unsigned int getNumArcs() const;


  /**
   * Creates a new Arc object, adds it to this Map object and returns the Arc
   * object created.
   *
   * @return a new Arc object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const Arc* object)
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  Arc* createArc();


  /**
   * Removes the nth Arc from this Map and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Arc to remove.
   *
   * @return a pointer to the nth Arc in this Map.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addArc(const Arc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   */
  Arc* removeArc(unsigned int n);


  /**
   * Removes the Arc from this Map based on its identifier and returns a
   * pointer to it.
   *
   * @param sid a string representing the identifier of the Arc to remove.
   *
   * @return the Arc in this Map based on the identifier or NULL if no such Arc
   * exists.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addArc(const Arc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(unsigned int n)
   */
  Arc* removeArc(const std::string& sid);


  /**
   * Returns the SbgnListOfArcGroups from this Map.
   *
   * @return the SbgnListOfArcGroups from this Map.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const ArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  const SbgnListOfArcGroups* getListOfArcGroups() const;


  /**
   * Returns the SbgnListOfArcGroups from this Map.
   *
   * @return the SbgnListOfArcGroups from this Map.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const ArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  SbgnListOfArcGroups* getListOfArcGroups();


  /**
   * Get an ArcGroup from the Map.
   *
   * @param n an unsigned int representing the index of the ArcGroup to
   * retrieve.
   *
   * @return the nth ArcGroup in the SbgnListOfArcGroups within this Map or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const ArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  ArcGroup* getArcGroup(unsigned int n);


  /**
   * Get an ArcGroup from the Map.
   *
   * @param n an unsigned int representing the index of the ArcGroup to
   * retrieve.
   *
   * @return the nth ArcGroup in the SbgnListOfArcGroups within this Map or
   * @c NULL if no such object exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const ArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  const ArcGroup* getArcGroup(unsigned int n) const;


  /**
   * Adds a copy of the given ArcGroup to this Map.
   *
   * @param ag the ArcGroup object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  int addArcGroup(const ArcGroup* ag);


  /**
   * Get the number of ArcGroup objects in this Map.
   *
   * @return the number of ArcGroup objects in this Map.
   *
   * @see addArcGroup(const ArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  unsigned int getNumArcGroups() const;


  /**
   * Creates a new ArcGroup object, adds it to this Map object and returns the
   * ArcGroup object created.
   *
   * @return a new ArcGroup object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const ArcGroup* object)
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  ArcGroup* createArcGroup();


  /**
   * Removes the nth ArcGroup from this Map and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the ArcGroup to remove.
   *
   * @return a pointer to the nth ArcGroup in this Map.
   *
   * @copydetails doc_warning_returns_owned_pointer
   *
   * @see addArcGroup(const ArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   */
  ArcGroup* removeArcGroup(unsigned int n);


  /**
   * Returns the XML element name of this Map object.
   *
   * For Map, the XML element name is always @c "map".
   *
   * @return the name of this element, i.e. @c "map".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this Map object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_MAP, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this Map
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this Map
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Map object are:
   * @li "language"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this Map
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this Map
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Map object are:
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(XMLOutputStream& stream) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Accepts the given SbgnVisitor
   */
  virtual bool accept(SbgnVisitor& v) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the parent SbgnDocument
   */
  virtual void setSbgnDocument(SbgnDocument* d);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Predicate returning @c true if this Map's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Map's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this Map.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Creates and returns an new "elementName" object in this Map.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this Map.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SbgnBase* element);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * Map.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SbgnBase* removeChildObject(const std::string& elementName,
                                      const std::string& id);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the number of "elementName" in this Map.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this Map.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SbgnBase* getObject(const std::string& elementName,
                              unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SbgnBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SbgnBase* getElementBySId(const std::string& id);


  /**
   * Returns a List of all child SbgnBase objects, including those nested to an
   * arbitrary depth.
   *
   * @param filter an ElementFilter that may impose restrictions on the objects
   * to be retrieved.
   *
   * @return a List pointer of pointers to all SbgnBase child objects with any
   * restriction imposed.
   */
  virtual List* getAllElements(SbgnElementFilter * filter = NULL);


protected:


  /** @cond doxygenlibSBGNInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SbgnBase* createObject(XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(const XMLAttributes& attributes,
                              const ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(XMLOutputStream& stream) const;

  /** @endcond */


};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Map_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this Map_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this Map_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Map_t *
Map_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this Map_t object.
 *
 * @param m the Map_t structure.
 *
 * @return a (deep) copy of this Map_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Map_t*
Map_clone(const Map_t* m);


/**
 * Frees this Map_t object.
 *
 * @param m the Map_t structure.
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
void
Map_free(Map_t* m);


/**
 * Returns the value of the "id" attribute of this Map_t.
 *
 * @param m the Map_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this Map_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
char *
Map_getId(const Map_t * m);


/**
 * Returns the value of the "language" attribute of this Map_t.
 *
 * @param m the Map_t structure whose language is sought.
 *
 * @return the value of the "language" attribute of this Map_t as a Language_t.
 *
 * @copydetails doc_map_language
 * @if clike The value is drawn from the enumeration @ref Language_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SBGNML_LANGUAGE_PROCESS_DESCRIPTION, Language_t}
 * @li @sbmlconstant{SBGNML_LANGUAGE_ENTITY_RELATIONSHIP, Language_t}
 * @li @sbmlconstant{SBGNML_LANGUAGE_ACTIVITY_FLOW, Language_t}
 * @li @sbmlconstant{SBGNML_LANGUAGE_INVALID, Language_t}
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Language_t
Map_getLanguage(const Map_t * m);


/**
 * Returns the value of the "language" attribute of this Map_t.
 *
 * @param m the Map_t structure whose language is sought.
 *
 * @return the value of the "language" attribute of this Map_t as a const char
 * *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_map_language
 * The possible values returned by this method are:
 * @li @c "process description"
 * @li @c "entity relationship"
 * @li @c "activity flow"
 * @li @c "invalid Language value"
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
char *
Map_getLanguageAsString(const Map_t * m);


/**
 * Predicate returning @c 1 (true) if this Map_t's "id" attribute is set.
 *
 * @param m the Map_t structure.
 *
 * @return @c 1 (true) if this Map_t's "id" attribute has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_isSetId(const Map_t * m);


/**
 * Predicate returning @c 1 (true) if this Map_t's "language" attribute is set.
 *
 * @param m the Map_t structure.
 *
 * @return @c 1 (true) if this Map_t's "language" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_map_language
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_isSetLanguage(const Map_t * m);


/**
 * Sets the value of the "id" attribute of this Map_t.
 *
 * @param m the Map_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_setId(Map_t * m, const char * id);


/**
 * Sets the value of the "language" attribute of this Map_t.
 *
 * @param m the Map_t structure.
 *
 * @param language Language_t value of the "language" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_map_language
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_setLanguage(Map_t * m, Language_t language);


/**
 * Sets the value of the "language" attribute of this Map_t.
 *
 * @param m the Map_t structure.
 *
 * @param language const char * of the "language" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_map_language
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_setLanguageAsString(Map_t * m, const char * language);


/**
 * Unsets the value of the "id" attribute of this Map_t.
 *
 * @param m the Map_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_unsetId(Map_t * m);


/**
 * Unsets the value of the "language" attribute of this Map_t.
 *
 * @param m the Map_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_map_language
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_unsetLanguage(Map_t * m);


/**
 * Returns the value of the "bbox" element of this Map_t.
 *
 * @param m the Map_t structure whose bbox is sought.
 *
 * @return the value of the "bbox" element of this Map_t as a BBox*.
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
const BBox_t*
Map_getBBox(const Map_t * m);


/**
 * Predicate returning @c 1 (true) if this Map_t's "bbox" element is set.
 *
 * @param m the Map_t structure.
 *
 * @return @c 1 (true) if this Map_t's "bbox" element has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_isSetBBox(const Map_t * m);


/**
 * Sets the value of the "bbox" element of this Map_t.
 *
 * @param m the Map_t structure.
 *
 * @param bbox BBox_t* value of the "bbox" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_setBBox(Map_t * m, const BBox_t* bbox);


/**
 * Creates a new BBox_t object, adds it to this Map_t object and returns the
 * BBox_t object created.
 *
 * @param m the Map_t structure to which the BBox_t should be added.
 *
 * @return a new BBox_t object instance.
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
BBox_t*
Map_createBBox(Map_t* m);


/**
 * Unsets the value of the "bbox" element of this Map_t.
 *
 * @param m the Map_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_unsetBBox(Map_t * m);


/**
 * Returns a ListOf_t * containing Glyph_t objects from this Map_t.
 *
 * @param m the Map_t structure whose SbgnListOfGlyphs is sought.
 *
 * @return the SbgnListOfGlyphs from this Map_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Map_addGlyph()
 * @see Map_createGlyph()
 * @see Map_getGlyphById()
 * @see Map_getGlyph()
 * @see Map_getNumGlyphs()
 * @see Map_removeGlyphById()
 * @see Map_removeGlyph()
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Map_getListOfGlyphs(Map_t* m);


/**
 * Get a Glyph_t from the Map_t.
 *
 * @param m the Map_t structure to search.
 *
 * @param n an unsigned int representing the index of the Glyph_t to retrieve.
 *
 * @return the nth Glyph_t in the SbgnListOfGlyphs within this Map or @c NULL
 * if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Glyph_t*
Map_getGlyph(Map_t* m, unsigned int n);


/**
 * Get a Glyph_t from the Map_t based on its identifier.
 *
 * @param m the Map_t structure to search.
 *
 * @param sid a string representing the identifier of the Glyph_t to retrieve.
 *
 * @return the Glyph_t in the SbgnListOfGlyphs within this Map with the given
 * @p sid or @c NULL if no such Glyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Glyph_t*
Map_getGlyphById(Map_t* m, const char *sid);


/**
 * Adds a copy of the given Glyph_t to this Map_t.
 *
 * @param m the Map_t structure to which the Glyph_t should be added.
 *
 * @param g the Glyph_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_addGlyph(Map_t* m, const Glyph_t* g);


/**
 * Get the number of Glyph_t objects in this Map_t.
 *
 * @param m the Map_t structure to query.
 *
 * @return the number of Glyph_t objects in this Map_t.
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
unsigned int
Map_getNumGlyphs(Map_t* m);


/**
 * Creates a new Glyph_t object, adds it to this Map_t object and returns the
 * Glyph_t object created.
 *
 * @param m the Map_t structure to which the Glyph_t should be added.
 *
 * @return a new Glyph_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Glyph_t*
Map_createGlyph(Map_t* m);


/**
 * Removes the nth Glyph_t from this Map_t and returns a pointer to it.
 *
 * @param m the Map_t structure to search.
 *
 * @param n an unsigned int representing the index of the Glyph_t to remove.
 *
 * @return a pointer to the nth Glyph_t in this Map_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Glyph_t*
Map_removeGlyph(Map_t* m, unsigned int n);


/**
 * Removes the Glyph_t from this Map_t based on its identifier and returns a
 * pointer to it.
 *
 * @param m the Map_t structure to search.
 *
 * @param sid a string representing the identifier of the Glyph_t to remove.
 *
 * @return the Glyph_t in this Map_t based on the identifier or NULL if no such
 * Glyph_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Glyph_t*
Map_removeGlyphById(Map_t* m, const char* sid);


/**
 * Returns a ListOf_t * containing Arc_t objects from this Map_t.
 *
 * @param m the Map_t structure whose SbgnListOfArcs is sought.
 *
 * @return the SbgnListOfArcs from this Map_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Map_addArc()
 * @see Map_createArc()
 * @see Map_getArcById()
 * @see Map_getArc()
 * @see Map_getNumArcs()
 * @see Map_removeArcById()
 * @see Map_removeArc()
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Map_getListOfArcs(Map_t* m);


/**
 * Get an Arc_t from the Map_t.
 *
 * @param m the Map_t structure to search.
 *
 * @param n an unsigned int representing the index of the Arc_t to retrieve.
 *
 * @return the nth Arc_t in the SbgnListOfArcs within this Map or @c NULL if no
 * such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Arc_t*
Map_getArc(Map_t* m, unsigned int n);


/**
 * Get an Arc_t from the Map_t based on its identifier.
 *
 * @param m the Map_t structure to search.
 *
 * @param sid a string representing the identifier of the Arc_t to retrieve.
 *
 * @return the Arc_t in the SbgnListOfArcs within this Map with the given @p
 * sid or @c NULL if no such Arc_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Arc_t*
Map_getArcById(Map_t* m, const char *sid);


/**
 * Adds a copy of the given Arc_t to this Map_t.
 *
 * @param m the Map_t structure to which the Arc_t should be added.
 *
 * @param a the Arc_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_addArc(Map_t* m, const Arc_t* a);


/**
 * Get the number of Arc_t objects in this Map_t.
 *
 * @param m the Map_t structure to query.
 *
 * @return the number of Arc_t objects in this Map_t.
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
unsigned int
Map_getNumArcs(Map_t* m);


/**
 * Creates a new Arc_t object, adds it to this Map_t object and returns the
 * Arc_t object created.
 *
 * @param m the Map_t structure to which the Arc_t should be added.
 *
 * @return a new Arc_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Arc_t*
Map_createArc(Map_t* m);


/**
 * Removes the nth Arc_t from this Map_t and returns a pointer to it.
 *
 * @param m the Map_t structure to search.
 *
 * @param n an unsigned int representing the index of the Arc_t to remove.
 *
 * @return a pointer to the nth Arc_t in this Map_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Arc_t*
Map_removeArc(Map_t* m, unsigned int n);


/**
 * Removes the Arc_t from this Map_t based on its identifier and returns a
 * pointer to it.
 *
 * @param m the Map_t structure to search.
 *
 * @param sid a string representing the identifier of the Arc_t to remove.
 *
 * @return the Arc_t in this Map_t based on the identifier or NULL if no such
 * Arc_t exists.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
Arc_t*
Map_removeArcById(Map_t* m, const char* sid);


/**
 * Returns a ListOf_t * containing ArcGroup_t objects from this Map_t.
 *
 * @param m the Map_t structure whose SbgnListOfArcGroups is sought.
 *
 * @return the SbgnListOfArcGroups from this Map_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Map_addArcGroup()
 * @see Map_createArcGroup()
 * @see Map_getArcGroupById()
 * @see Map_getArcGroup()
 * @see Map_getNumArcGroups()
 * @see Map_removeArcGroupById()
 * @see Map_removeArcGroup()
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Map_getListOfArcGroups(Map_t* m);


/**
 * Get an ArcGroup_t from the Map_t.
 *
 * @param m the Map_t structure to search.
 *
 * @param n an unsigned int representing the index of the ArcGroup_t to
 * retrieve.
 *
 * @return the nth ArcGroup_t in the SbgnListOfArcGroups within this Map or
 * @c NULL if no such object exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
ArcGroup_t*
Map_getArcGroup(Map_t* m, unsigned int n);


/**
 * Adds a copy of the given ArcGroup_t to this Map_t.
 *
 * @param m the Map_t structure to which the ArcGroup_t should be added.
 *
 * @param ag the ArcGroup_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_addArcGroup(Map_t* m, const ArcGroup_t* ag);


/**
 * Get the number of ArcGroup_t objects in this Map_t.
 *
 * @param m the Map_t structure to query.
 *
 * @return the number of ArcGroup_t objects in this Map_t.
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
unsigned int
Map_getNumArcGroups(Map_t* m);


/**
 * Creates a new ArcGroup_t object, adds it to this Map_t object and returns
 * the ArcGroup_t object created.
 *
 * @param m the Map_t structure to which the ArcGroup_t should be added.
 *
 * @return a new ArcGroup_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
ArcGroup_t*
Map_createArcGroup(Map_t* m);


/**
 * Removes the nth ArcGroup_t from this Map_t and returns a pointer to it.
 *
 * @param m the Map_t structure to search.
 *
 * @param n an unsigned int representing the index of the ArcGroup_t to remove.
 *
 * @return a pointer to the nth ArcGroup_t in this Map_t.
 *
 * @copydetails doc_warning_returns_owned_pointer
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
ArcGroup_t*
Map_removeArcGroup(Map_t* m, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Map_t object have been set.
 *
 * @param m the Map_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * Map_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the Map_t object are:
 * @li "language"
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_hasRequiredAttributes(const Map_t * m);


/**
 * Predicate returning @c 1 (true) if all the required elements for this Map_t
 * object have been set.
 *
 * @param m the Map_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this Map_t
 * have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the Map_t object are:
 *
 * @memberof Map_t
 */
LIBSBGN_EXTERN
int
Map_hasRequiredElements(const Map_t * m);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Map_H__ */


