/**
 * @file Arc.h
 * @brief Definition of the Arc class.
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
 * @class Arc
 * @sbmlbrief{sbgnml} TODO:Definition of the Arc class.
 */


#ifndef Arc_H__
#define Arc_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SBase.h>
#include <sbgn/Point.h>
#include <sbgn/SbgnListOfGlyphs.h>
#include <sbgn/SbgnListOfPoints.h>
#include <sbgn/SbgnListOfPorts.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN Arc : public SBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mClazz;
  std::string mSource;
  std::string mTarget;
  SbgnListOfGlyphs mGlyphs;
  Point* mStart;
  SbgnListOfPoints mPoints;
  Point* mEnd;
  SbgnListOfPorts mPorts;

  /** @endcond */

public:

  /**
   * Creates a new Arc using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this Arc.
   *
   * @param version an unsigned int, the SBGN Version to assign to this Arc.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Arc(unsigned int level = SBGN_DEFAULT_LEVEL,
      unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new Arc using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Arc(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for Arc.
   *
   * @param orig the Arc instance to copy.
   */
  Arc(const Arc& orig);


  /**
   * Assignment operator for Arc.
   *
   * @param rhs the Arc object whose values are to be used as the basis of the
   * assignment.
   */
  Arc& operator=(const Arc& rhs);


  /**
   * Creates and returns a deep copy of this Arc object.
   *
   * @return a (deep) copy of this Arc object.
   */
  virtual Arc* clone() const;


  /**
   * Destructor for Arc.
   */
  virtual ~Arc();


  /**
   * Returns the value of the "id" attribute of this Arc.
   *
   * @return the value of the "id" attribute of this Arc as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "class" attribute of this Arc.
   *
   * @return the value of the "class" attribute of this Arc as a string.
   */
  const std::string& getClazz() const;


  /**
   * Returns the value of the "source" attribute of this Arc.
   *
   * @return the value of the "source" attribute of this Arc as a string.
   */
  const std::string& getSource() const;


  /**
   * Returns the value of the "target" attribute of this Arc.
   *
   * @return the value of the "target" attribute of this Arc as a string.
   */
  const std::string& getTarget() const;


  /**
   * Predicate returning @c true if this Arc's "id" attribute is set.
   *
   * @return @c true if this Arc's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this Arc's "class" attribute is set.
   *
   * @return @c true if this Arc's "class" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetClazz() const;


  /**
   * Predicate returning @c true if this Arc's "source" attribute is set.
   *
   * @return @c true if this Arc's "source" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetSource() const;


  /**
   * Predicate returning @c true if this Arc's "target" attribute is set.
   *
   * @return @c true if this Arc's "target" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Sets the value of the "id" attribute of this Arc.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "class" attribute of this Arc.
   *
   * @param clazz std::string& value of the "class" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p clazz = @c NULL or an empty string is
   * equivalent to calling unsetClazz().
   */
  int setClazz(const std::string& clazz);


  /**
   * Sets the value of the "source" attribute of this Arc.
   *
   * @param source std::string& value of the "source" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  int setSource(const std::string& source);


  /**
   * Sets the value of the "target" attribute of this Arc.
   *
   * @param target std::string& value of the "target" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  int setTarget(const std::string& target);


  /**
   * Unsets the value of the "id" attribute of this Arc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "class" attribute of this Arc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetClazz();


  /**
   * Unsets the value of the "source" attribute of this Arc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSource();


  /**
   * Unsets the value of the "target" attribute of this Arc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Returns the value of the "start" element of this Arc.
   *
   * @return the value of the "start" element of this Arc as a Point*.
   */
  const Point* getStart() const;


  /**
   * Returns the value of the "start" element of this Arc.
   *
   * @return the value of the "start" element of this Arc as a Point*.
   */
  Point* getStart();


  /**
   * Returns the value of the "end" element of this Arc.
   *
   * @return the value of the "end" element of this Arc as a Point*.
   */
  const Point* getEnd() const;


  /**
   * Returns the value of the "end" element of this Arc.
   *
   * @return the value of the "end" element of this Arc as a Point*.
   */
  Point* getEnd();


  /**
   * Predicate returning @c true if this Arc's "start" element is set.
   *
   * @return @c true if this Arc's "start" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetStart() const;


  /**
   * Predicate returning @c true if this Arc's "end" element is set.
   *
   * @return @c true if this Arc's "end" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetEnd() const;


  /**
   * Sets the value of the "start" element of this Arc.
   *
   * @param start Point* value of the "start" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStart(const Point* start);


  /**
   * Sets the value of the "end" element of this Arc.
   *
   * @param end Point* value of the "end" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setEnd(const Point* end);


  /**
   * Creates a new Point object, adds it to this Arc object and returns the
   * Point object created.
   *
   * @return a new Point object instance.
   */
  Point* createStart();


  /**
   * Creates a new Point object, adds it to this Arc object and returns the
   * Point object created.
   *
   * @return a new Point object instance.
   */
  Point* createEnd();


  /**
   * Unsets the value of the "start" element of this Arc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStart();


  /**
   * Unsets the value of the "end" element of this Arc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetEnd();


  /**
   * Returns the SbgnListOfGlyphs from this Arc.
   *
   * @return the SbgnListOfGlyphs from this Arc.
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
   * Returns the SbgnListOfGlyphs from this Arc.
   *
   * @return the SbgnListOfGlyphs from this Arc.
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
   * Get a Glyph from the Arc.
   *
   * @param n an unsigned int representing the index of the Glyph to retrieve.
   *
   * @return the nth Glyph in the SbgnListOfGlyphs within this Arc.
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
   * Get a Glyph from the Arc.
   *
   * @param n an unsigned int representing the index of the Glyph to retrieve.
   *
   * @return the nth Glyph in the SbgnListOfGlyphs within this Arc.
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
   * Get a Glyph from the Arc based on its identifier.
   *
   * @param sid a string representing the identifier of the Glyph to retrieve.
   *
   * @return the Glyph in the SbgnListOfGlyphs within this Arc with the given
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
   * Get a Glyph from the Arc based on its identifier.
   *
   * @param sid a string representing the identifier of the Glyph to retrieve.
   *
   * @return the Glyph in the SbgnListOfGlyphs within this Arc with the given
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
   * Adds a copy of the given Glyph to this Arc.
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
   * Get the number of Glyph objects in this Arc.
   *
   * @return the number of Glyph objects in this Arc.
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
   * Creates a new Glyph object, adds it to this Arc object and returns the
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
   * Removes the nth Glyph from this Arc and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Glyph to remove.
   *
   * @return a pointer to the nth Glyph in this Arc.
   *
   * @copydetails doc_returned_owned_pointer
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
   * Removes the Glyph from this Arc based on its identifier and returns a
   * pointer to it.
   *
   * @param sid a string representing the identifier of the Glyph to remove.
   *
   * @return the Glyph in this Arc based on the identifier or NULL if no such
   * Glyph exists.
   *
   * @copydetails doc_returned_owned_pointer
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
   * Returns the SbgnListOfPoints from this Arc.
   *
   * @return the SbgnListOfPoints from this Arc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const Point* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  const SbgnListOfPoints* getListOfNexts() const;


  /**
   * Returns the SbgnListOfPoints from this Arc.
   *
   * @return the SbgnListOfPoints from this Arc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const Point* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  SbgnListOfPoints* getListOfNexts();


  /**
   * Get a Point from the Arc.
   *
   * @param n an unsigned int representing the index of the Point to retrieve.
   *
   * @return the nth Point in the SbgnListOfPoints within this Arc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const Point* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  Point* getNext(unsigned int n);


  /**
   * Get a Point from the Arc.
   *
   * @param n an unsigned int representing the index of the Point to retrieve.
   *
   * @return the nth Point in the SbgnListOfPoints within this Arc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const Point* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  const Point* getNext(unsigned int n) const;


  /**
   * Adds a copy of the given Point to this Arc.
   *
   * @param p the Point object to add.
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
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  int addNext(const Point* p);


  /**
   * Get the number of Point objects in this Arc.
   *
   * @return the number of Point objects in this Arc.
   *
   * @see addNext(const Point* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  unsigned int getNumNexts() const;


  /**
   * Creates a new Point object, adds it to this Arc object and returns the
   * Point object created.
   *
   * @return a new Point object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const Point* object)
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  Point* createNext();


  /**
   * Removes the nth Point from this Arc and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Point to remove.
   *
   * @return a pointer to the nth Point in this Arc.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addNext(const Point* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   */
  Point* removeNext(unsigned int n);


  /**
   * Returns the SbgnListOfPorts from this Arc.
   *
   * @return the SbgnListOfPorts from this Arc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const Port* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  const SbgnListOfPorts* getListOfPorts() const;


  /**
   * Returns the SbgnListOfPorts from this Arc.
   *
   * @return the SbgnListOfPorts from this Arc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const Port* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  SbgnListOfPorts* getListOfPorts();


  /**
   * Get a Port from the Arc.
   *
   * @param n an unsigned int representing the index of the Port to retrieve.
   *
   * @return the nth Port in the SbgnListOfPorts within this Arc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const Port* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  Port* getPort(unsigned int n);


  /**
   * Get a Port from the Arc.
   *
   * @param n an unsigned int representing the index of the Port to retrieve.
   *
   * @return the nth Port in the SbgnListOfPorts within this Arc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const Port* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  const Port* getPort(unsigned int n) const;


  /**
   * Get a Port from the Arc based on its identifier.
   *
   * @param sid a string representing the identifier of the Port to retrieve.
   *
   * @return the Port in the SbgnListOfPorts within this Arc with the given @p
   * sid or @c NULL if no such Port exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const Port* object)
   * @see createPort()
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  Port* getPort(const std::string& sid);


  /**
   * Get a Port from the Arc based on its identifier.
   *
   * @param sid a string representing the identifier of the Port to retrieve.
   *
   * @return the Port in the SbgnListOfPorts within this Arc with the given @p
   * sid or @c NULL if no such Port exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const Port* object)
   * @see createPort()
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  const Port* getPort(const std::string& sid) const;


  /**
   * Adds a copy of the given Port to this Arc.
   *
   * @param p the Port object to add.
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
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  int addPort(const Port* p);


  /**
   * Get the number of Port objects in this Arc.
   *
   * @return the number of Port objects in this Arc.
   *
   * @see addPort(const Port* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  unsigned int getNumPorts() const;


  /**
   * Creates a new Port object, adds it to this Arc object and returns the Port
   * object created.
   *
   * @return a new Port object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const Port* object)
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  Port* createPort();


  /**
   * Removes the nth Port from this Arc and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the Port to remove.
   *
   * @return a pointer to the nth Port in this Arc.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addPort(const Port* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   */
  Port* removePort(unsigned int n);


  /**
   * Removes the Port from this Arc based on its identifier and returns a
   * pointer to it.
   *
   * @param sid a string representing the identifier of the Port to remove.
   *
   * @return the Port in this Arc based on the identifier or NULL if no such
   * Port exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addPort(const Port* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(unsigned int n)
   */
  Port* removePort(const std::string& sid);


  /**
   * Returns the XML element name of this Arc object.
   *
   * For Arc, the XML element name is always @c "arc".
   *
   * @return the name of this element, i.e. @c "arc".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this Arc object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_ARC, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this Arc
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this Arc
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Arc object are:
   * @li "id"
   * @li "class"
   * @li "source"
   * @li "target"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this Arc
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this Arc
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the Arc object are:
   * @li "start"
   * @li "end"
   */
  virtual bool hasRequiredElements() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

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
   * Gets the value of the "attributeName" attribute of this Arc.
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
   * Gets the value of the "attributeName" attribute of this Arc.
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
   * Gets the value of the "attributeName" attribute of this Arc.
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
   * Gets the value of the "attributeName" attribute of this Arc.
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
   * Gets the value of the "attributeName" attribute of this Arc.
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
   * Predicate returning @c true if this Arc's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Arc's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Arc.
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
   * Sets the value of the "attributeName" attribute of this Arc.
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
   * Sets the value of the "attributeName" attribute of this Arc.
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
   * Sets the value of the "attributeName" attribute of this Arc.
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
   * Sets the value of the "attributeName" attribute of this Arc.
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
   * Unsets the value of the "attributeName" attribute of this Arc.
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
   * Creates and returns an new "elementName" object in this Arc.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this Arc.
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
   * Arc.
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
   * Returns the number of "elementName" in this Arc.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this Arc.
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


protected:


  /** @cond doxygenlibSBGNInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SbgnBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
    XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Arc_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this Arc_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this Arc_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Arc_t *
Arc_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this Arc_t object.
 *
 * @param a the Arc_t structure.
 *
 * @return a (deep) copy of this Arc_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Arc_t*
Arc_clone(const Arc_t* a);


/**
 * Frees this Arc_t object.
 *
 * @param a the Arc_t structure.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
void
Arc_free(Arc_t* a);


/**
 * Returns the value of the "id" attribute of this Arc_t.
 *
 * @param a the Arc_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this Arc_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
char *
Arc_getId(const Arc_t * a);


/**
 * Returns the value of the "class" attribute of this Arc_t.
 *
 * @param a the Arc_t structure whose class is sought.
 *
 * @return the value of the "class" attribute of this Arc_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
char *
Arc_getClazz(const Arc_t * a);


/**
 * Returns the value of the "source" attribute of this Arc_t.
 *
 * @param a the Arc_t structure whose source is sought.
 *
 * @return the value of the "source" attribute of this Arc_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
char *
Arc_getSource(const Arc_t * a);


/**
 * Returns the value of the "target" attribute of this Arc_t.
 *
 * @param a the Arc_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this Arc_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
char *
Arc_getTarget(const Arc_t * a);


/**
 * Predicate returning @c 1 (true) if this Arc_t's "id" attribute is set.
 *
 * @param a the Arc_t structure.
 *
 * @return @c 1 (true) if this Arc_t's "id" attribute has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_isSetId(const Arc_t * a);


/**
 * Predicate returning @c 1 (true) if this Arc_t's "class" attribute is set.
 *
 * @param a the Arc_t structure.
 *
 * @return @c 1 (true) if this Arc_t's "class" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_isSetClazz(const Arc_t * a);


/**
 * Predicate returning @c 1 (true) if this Arc_t's "source" attribute is set.
 *
 * @param a the Arc_t structure.
 *
 * @return @c 1 (true) if this Arc_t's "source" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_isSetSource(const Arc_t * a);


/**
 * Predicate returning @c 1 (true) if this Arc_t's "target" attribute is set.
 *
 * @param a the Arc_t structure.
 *
 * @return @c 1 (true) if this Arc_t's "target" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_isSetTarget(const Arc_t * a);


/**
 * Sets the value of the "id" attribute of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_setId(Arc_t * a, const char * id);


/**
 * Sets the value of the "class" attribute of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @param clazz const char * value of the "class" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p clazz = @c NULL or an empty string is
 * equivalent to calling Arc_unsetClazz().
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_setClazz(Arc_t * a, const char * clazz);


/**
 * Sets the value of the "source" attribute of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @param source const char * value of the "source" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_setSource(Arc_t * a, const char * source);


/**
 * Sets the value of the "target" attribute of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_setTarget(Arc_t * a, const char * target);


/**
 * Unsets the value of the "id" attribute of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_unsetId(Arc_t * a);


/**
 * Unsets the value of the "class" attribute of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_unsetClazz(Arc_t * a);


/**
 * Unsets the value of the "source" attribute of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_unsetSource(Arc_t * a);


/**
 * Unsets the value of the "target" attribute of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_unsetTarget(Arc_t * a);


/**
 * Returns the value of the "start" element of this Arc_t.
 *
 * @param a the Arc_t structure whose start is sought.
 *
 * @return the value of the "start" element of this Arc_t as a Point*.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
const Point_t*
Arc_getStart(const Arc_t * a);


/**
 * Returns the value of the "end" element of this Arc_t.
 *
 * @param a the Arc_t structure whose end is sought.
 *
 * @return the value of the "end" element of this Arc_t as a Point*.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
const Point_t*
Arc_getEnd(const Arc_t * a);


/**
 * Predicate returning @c 1 (true) if this Arc_t's "start" element is set.
 *
 * @param a the Arc_t structure.
 *
 * @return @c 1 (true) if this Arc_t's "start" element has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_isSetStart(const Arc_t * a);


/**
 * Predicate returning @c 1 (true) if this Arc_t's "end" element is set.
 *
 * @param a the Arc_t structure.
 *
 * @return @c 1 (true) if this Arc_t's "end" element has been set, otherwise
 * @c 0 (false) is returned.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_isSetEnd(const Arc_t * a);


/**
 * Sets the value of the "start" element of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @param start Point_t* value of the "start" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_setStart(Arc_t * a, const Point_t* start);


/**
 * Sets the value of the "end" element of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @param end Point_t* value of the "end" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_setEnd(Arc_t * a, const Point_t* end);


/**
 * Creates a new Point_t object, adds it to this Arc_t object and returns the
 * Point_t object created.
 *
 * @param a the Arc_t structure to which the Point_t should be added.
 *
 * @return a new Point_t object instance.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Point_t*
Arc_createStart(Arc_t* a);


/**
 * Creates a new Point_t object, adds it to this Arc_t object and returns the
 * Point_t object created.
 *
 * @param a the Arc_t structure to which the Point_t should be added.
 *
 * @return a new Point_t object instance.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Point_t*
Arc_createEnd(Arc_t* a);


/**
 * Unsets the value of the "start" element of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_unsetStart(Arc_t * a);


/**
 * Unsets the value of the "end" element of this Arc_t.
 *
 * @param a the Arc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_unsetEnd(Arc_t * a);


/**
 * Returns a ListOf_t * containing Glyph_t objects from this Arc_t.
 *
 * @param a the Arc_t structure whose SbgnListOfGlyphs is sought.
 *
 * @return the SbgnListOfGlyphs from this Arc_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Arc_addGlyph()
 * @see Arc_createGlyph()
 * @see Arc_getGlyphById()
 * @see Arc_getGlyph()
 * @see Arc_getNumGlyphs()
 * @see Arc_removeGlyphById()
 * @see Arc_removeGlyph()
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Arc_getListOfGlyphs(Arc_t* a);


/**
 * Get a Glyph_t from the Arc_t.
 *
 * @param a the Arc_t structure to search.
 *
 * @param n an unsigned int representing the index of the Glyph_t to retrieve.
 *
 * @return the nth Glyph_t in the SbgnListOfGlyphs within this Arc.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_getGlyph(Arc_t* a, unsigned int n);


/**
 * Get a Glyph_t from the Arc_t based on its identifier.
 *
 * @param a the Arc_t structure to search.
 *
 * @param sid a string representing the identifier of the Glyph_t to retrieve.
 *
 * @return the Glyph_t in the SbgnListOfGlyphs within this Arc with the given
 * @p sid or @c NULL if no such Glyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_getGlyphById(Arc_t* a, const char *sid);


/**
 * Adds a copy of the given Glyph_t to this Arc_t.
 *
 * @param a the Arc_t structure to which the Glyph_t should be added.
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
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_addGlyph(Arc_t* a, const Glyph_t* g);


/**
 * Get the number of Glyph_t objects in this Arc_t.
 *
 * @param a the Arc_t structure to query.
 *
 * @return the number of Glyph_t objects in this Arc_t.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
unsigned int
Arc_getNumGlyphs(Arc_t* a);


/**
 * Creates a new Glyph_t object, adds it to this Arc_t object and returns the
 * Glyph_t object created.
 *
 * @param a the Arc_t structure to which the Glyph_t should be added.
 *
 * @return a new Glyph_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_createGlyph(Arc_t* a);


/**
 * Removes the nth Glyph_t from this Arc_t and returns a pointer to it.
 *
 * @param a the Arc_t structure to search.
 *
 * @param n an unsigned int representing the index of the Glyph_t to remove.
 *
 * @return a pointer to the nth Glyph_t in this Arc_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_removeGlyph(Arc_t* a, unsigned int n);


/**
 * Removes the Glyph_t from this Arc_t based on its identifier and returns a
 * pointer to it.
 *
 * @param a the Arc_t structure to search.
 *
 * @param sid a string representing the identifier of the Glyph_t to remove.
 *
 * @return the Glyph_t in this Arc_t based on the identifier or NULL if no such
 * Glyph_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Glyph_t*
Arc_removeGlyphById(Arc_t* a, const char* sid);


/**
 * Returns a ListOf_t * containing Point_t objects from this Arc_t.
 *
 * @param a the Arc_t structure whose SbgnListOfPoints is sought.
 *
 * @return the SbgnListOfPoints from this Arc_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Arc_addNext()
 * @see Arc_createNext()
 * @see Arc_getNextById()
 * @see Arc_getNext()
 * @see Arc_getNumNexts()
 * @see Arc_removeNextById()
 * @see Arc_removeNext()
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Arc_getListOfNexts(Arc_t* a);


/**
 * Get a Point_t from the Arc_t.
 *
 * @param a the Arc_t structure to search.
 *
 * @param n an unsigned int representing the index of the Point_t to retrieve.
 *
 * @return the nth Point_t in the SbgnListOfPoints within this Arc.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Point_t*
Arc_getNext(Arc_t* a, unsigned int n);


/**
 * Adds a copy of the given Point_t to this Arc_t.
 *
 * @param a the Arc_t structure to which the Point_t should be added.
 *
 * @param p the Point_t object to add.
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
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_addNext(Arc_t* a, const Point_t* p);


/**
 * Get the number of Point_t objects in this Arc_t.
 *
 * @param a the Arc_t structure to query.
 *
 * @return the number of Point_t objects in this Arc_t.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
unsigned int
Arc_getNumNexts(Arc_t* a);


/**
 * Creates a new Point_t object, adds it to this Arc_t object and returns the
 * Point_t object created.
 *
 * @param a the Arc_t structure to which the Point_t should be added.
 *
 * @return a new Point_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Point_t*
Arc_createNext(Arc_t* a);


/**
 * Removes the nth Point_t from this Arc_t and returns a pointer to it.
 *
 * @param a the Arc_t structure to search.
 *
 * @param n an unsigned int representing the index of the Point_t to remove.
 *
 * @return a pointer to the nth Point_t in this Arc_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Point_t*
Arc_removeNext(Arc_t* a, unsigned int n);


/**
 * Returns a ListOf_t * containing Port_t objects from this Arc_t.
 *
 * @param a the Arc_t structure whose SbgnListOfPorts is sought.
 *
 * @return the SbgnListOfPorts from this Arc_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Arc_addPort()
 * @see Arc_createPort()
 * @see Arc_getPortById()
 * @see Arc_getPort()
 * @see Arc_getNumPorts()
 * @see Arc_removePortById()
 * @see Arc_removePort()
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
Arc_getListOfPorts(Arc_t* a);


/**
 * Get a Port_t from the Arc_t.
 *
 * @param a the Arc_t structure to search.
 *
 * @param n an unsigned int representing the index of the Port_t to retrieve.
 *
 * @return the nth Port_t in the SbgnListOfPorts within this Arc.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Port_t*
Arc_getPort(Arc_t* a, unsigned int n);


/**
 * Get a Port_t from the Arc_t based on its identifier.
 *
 * @param a the Arc_t structure to search.
 *
 * @param sid a string representing the identifier of the Port_t to retrieve.
 *
 * @return the Port_t in the SbgnListOfPorts within this Arc with the given @p
 * sid or @c NULL if no such Port_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Port_t*
Arc_getPortById(Arc_t* a, const char *sid);


/**
 * Adds a copy of the given Port_t to this Arc_t.
 *
 * @param a the Arc_t structure to which the Port_t should be added.
 *
 * @param p the Port_t object to add.
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
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_addPort(Arc_t* a, const Port_t* p);


/**
 * Get the number of Port_t objects in this Arc_t.
 *
 * @param a the Arc_t structure to query.
 *
 * @return the number of Port_t objects in this Arc_t.
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
unsigned int
Arc_getNumPorts(Arc_t* a);


/**
 * Creates a new Port_t object, adds it to this Arc_t object and returns the
 * Port_t object created.
 *
 * @param a the Arc_t structure to which the Port_t should be added.
 *
 * @return a new Port_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Port_t*
Arc_createPort(Arc_t* a);


/**
 * Removes the nth Port_t from this Arc_t and returns a pointer to it.
 *
 * @param a the Arc_t structure to search.
 *
 * @param n an unsigned int representing the index of the Port_t to remove.
 *
 * @return a pointer to the nth Port_t in this Arc_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Port_t*
Arc_removePort(Arc_t* a, unsigned int n);


/**
 * Removes the Port_t from this Arc_t based on its identifier and returns a
 * pointer to it.
 *
 * @param a the Arc_t structure to search.
 *
 * @param sid a string representing the identifier of the Port_t to remove.
 *
 * @return the Port_t in this Arc_t based on the identifier or NULL if no such
 * Port_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
Port_t*
Arc_removePortById(Arc_t* a, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Arc_t object have been set.
 *
 * @param a the Arc_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * Arc_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the Arc_t object are:
 * @li "id"
 * @li "class"
 * @li "source"
 * @li "target"
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_hasRequiredAttributes(const Arc_t * a);


/**
 * Predicate returning @c 1 (true) if all the required elements for this Arc_t
 * object have been set.
 *
 * @param a the Arc_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this Arc_t
 * have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the Arc_t object are:
 * @li "start"
 * @li "end"
 *
 * @memberof Arc_t
 */
LIBSBGN_EXTERN
int
Arc_hasRequiredElements(const Arc_t * a);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Arc_H__ */


