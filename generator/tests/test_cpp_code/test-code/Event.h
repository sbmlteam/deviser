/**
 * @file Event.h
 * @brief Definition of the Event class.
 * @author DEVISER
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
 * @class Event
 * @sbmlbrief{core} TODO:Definition of the Event class.
 */


#ifndef Event_H__
#define Event_H__


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbml/SBase.h>
#include <sbml/Trigger.h>
#include <sbml/Priority.h>
#include <sbml/Delay.h>
#include <sbml/SBMLListOfEventAssignments.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBML_CPP_NAMESPACE_BEGIN


class LIBSBML_EXTERN Event : public SBase
{
protected:

  /** @cond doxygenLibsbmlInternal */

  bool mUseValuesFromTriggerTime;
  bool mIsSetUseValuesFromTriggerTime;
  Trigger* mTrigger;
  Priority* mPriority;
  Delay* mDelay;
  SBMLListOfEventAssignments mEventAssignments;
  std::string mTimeUnits;

  /** @endcond */

public:

  /**
   * Creates a new Event using the given SBML Level and @ p version values.
   *
   * @param level an unsigned int, the SBML Level to assign to this Event.
   *
   * @param version an unsigned int, the SBML Version to assign to this Event.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Event(unsigned int level = SBML_DEFAULT_LEVEL,
        unsigned int version = SBML_DEFAULT_VERSION);


  /**
   * Creates a new Event using the given SBMLNamespaces object @p sbmlns.
   *
   * @param sbmlns the SBMLNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  Event(SBMLNamespaces *sbmlns);


  /**
   * Copy constructor for Event.
   *
   * @param orig the Event instance to copy.
   */
  Event(const Event& orig);


  /**
   * Assignment operator for Event.
   *
   * @param rhs the Event object whose values are to be used as the basis of
   * the assignment.
   */
  Event& operator=(const Event& rhs);


  /**
   * Creates and returns a deep copy of this Event object.
   *
   * @return a (deep) copy of this Event object.
   */
  virtual Event* clone() const;


  /**
   * Destructor for Event.
   */
  virtual ~Event();


  /**
   * Returns the value of the "useValuesFromTriggerTime" attribute of this
   * Event.
   *
   * @return the value of the "useValuesFromTriggerTime" attribute of this
   * Event as a boolean.
   */
  bool getUseValuesFromTriggerTime() const;


  /**
   * Returns the value of the "timeUnits" attribute of this Event.
   *
   * @return the value of the "timeUnits" attribute of this Event as a string.
   */
  const std::string& getTimeUnits() const;


  /**
   * Predicate returning @c true if this Event's "useValuesFromTriggerTime"
   * attribute is set.
   *
   * @return @c true if this Event's "useValuesFromTriggerTime" attribute has
   * been set, otherwise @c false is returned.
   */
  bool isSetUseValuesFromTriggerTime() const;


  /**
   * Predicate returning @c true if this Event's "timeUnits" attribute is set.
   *
   * @return @c true if this Event's "timeUnits" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTimeUnits() const;


  /**
   * Sets the value of the "useValuesFromTriggerTime" attribute of this Event.
   *
   * @param useValuesFromTriggerTime bool value of the
   * "useValuesFromTriggerTime" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setUseValuesFromTriggerTime(bool useValuesFromTriggerTime);


  /**
   * Sets the value of the "timeUnits" attribute of this Event.
   *
   * @param timeUnits std::string& value of the "timeUnits" attribute to be
   * set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTimeUnits(const std::string& timeUnits);


  /**
   * Unsets the value of the "useValuesFromTriggerTime" attribute of this
   * Event.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetUseValuesFromTriggerTime();


  /**
   * Unsets the value of the "timeUnits" attribute of this Event.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTimeUnits();


  /**
   * Returns the value of the "trigger" element of this Event.
   *
   * @return the value of the "trigger" element of this Event as a Trigger*.
   */
  const Trigger* getTrigger() const;


  /**
   * Returns the value of the "trigger" element of this Event.
   *
   * @return the value of the "trigger" element of this Event as a Trigger*.
   */
  Trigger* getTrigger();


  /**
   * Returns the value of the "priority" element of this Event.
   *
   * @return the value of the "priority" element of this Event as a Priority*.
   */
  const Priority* getPriority() const;


  /**
   * Returns the value of the "priority" element of this Event.
   *
   * @return the value of the "priority" element of this Event as a Priority*.
   */
  Priority* getPriority();


  /**
   * Returns the value of the "delay" element of this Event.
   *
   * @return the value of the "delay" element of this Event as a Delay*.
   */
  const Delay* getDelay() const;


  /**
   * Returns the value of the "delay" element of this Event.
   *
   * @return the value of the "delay" element of this Event as a Delay*.
   */
  Delay* getDelay();


  /**
   * Predicate returning @c true if this Event's "trigger" element is set.
   *
   * @return @c true if this Event's "trigger" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetTrigger() const;


  /**
   * Predicate returning @c true if this Event's "priority" element is set.
   *
   * @return @c true if this Event's "priority" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetPriority() const;


  /**
   * Predicate returning @c true if this Event's "delay" element is set.
   *
   * @return @c true if this Event's "delay" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetDelay() const;


  /**
   * Sets the value of the "trigger" element of this Event.
   *
   * @param trigger Trigger* value of the "trigger" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTrigger(const Trigger* trigger);


  /**
   * Sets the value of the "priority" element of this Event.
   *
   * @param priority Priority* value of the "priority" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPriority(const Priority* priority);


  /**
   * Sets the value of the "delay" element of this Event.
   *
   * @param delay Delay* value of the "delay" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setDelay(const Delay* delay);


  /**
   * Creates a new Trigger object, adds it to this Event object and returns the
   * Trigger object created.
   *
   * @return a new Trigger object instance.
   */
  Trigger* createTrigger();


  /**
   * Creates a new Priority object, adds it to this Event object and returns
   * the Priority object created.
   *
   * @return a new Priority object instance.
   */
  Priority* createPriority();


  /**
   * Creates a new Delay object, adds it to this Event object and returns the
   * Delay object created.
   *
   * @return a new Delay object instance.
   */
  Delay* createDelay();


  /**
   * Unsets the value of the "trigger" element of this Event.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTrigger();


  /**
   * Unsets the value of the "priority" element of this Event.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPriority();


  /**
   * Unsets the value of the "delay" element of this Event.
   *
   * @copydetails doc_returns_success_code
   * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetDelay();


  /**
   * Returns the SBMLListOfEventAssignments from this Event.
   *
   * @return the SBMLListOfEventAssignments from this Event.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addEventAssignment(const EventAssignment* object)
   * @see createEventAssignment()
   * @see getEventAssignment(const std::string& sid)
   * @see getEventAssignment(unsigned int n)
   * @see getNumEventAssignments()
   * @see removeEventAssignment(const std::string& sid)
   * @see removeEventAssignment(unsigned int n)
   */
  const SBMLListOfEventAssignments* getListOfEventAssignments() const;


  /**
   * Returns the SBMLListOfEventAssignments from this Event.
   *
   * @return the SBMLListOfEventAssignments from this Event.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addEventAssignment(const EventAssignment* object)
   * @see createEventAssignment()
   * @see getEventAssignment(const std::string& sid)
   * @see getEventAssignment(unsigned int n)
   * @see getNumEventAssignments()
   * @see removeEventAssignment(const std::string& sid)
   * @see removeEventAssignment(unsigned int n)
   */
  SBMLListOfEventAssignments* getListOfEventAssignments();


  /**
   * Get an EventAssignment from the Event.
   *
   * @param n an unsigned int representing the index of the EventAssignment to
   * retrieve.
   *
   * @return the nth EventAssignment in the SBMLListOfEventAssignments within
   * this Event.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addEventAssignment(const EventAssignment* object)
   * @see createEventAssignment()
   * @see getEventAssignment(const std::string& sid)
   * @see getNumEventAssignments()
   * @see removeEventAssignment(const std::string& sid)
   * @see removeEventAssignment(unsigned int n)
   */
  EventAssignment* getEventAssignment(unsigned int n);


  /**
   * Get an EventAssignment from the Event.
   *
   * @param n an unsigned int representing the index of the EventAssignment to
   * retrieve.
   *
   * @return the nth EventAssignment in the SBMLListOfEventAssignments within
   * this Event.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addEventAssignment(const EventAssignment* object)
   * @see createEventAssignment()
   * @see getEventAssignment(const std::string& sid)
   * @see getNumEventAssignments()
   * @see removeEventAssignment(const std::string& sid)
   * @see removeEventAssignment(unsigned int n)
   */
  const EventAssignment* getEventAssignment(unsigned int n) const;


  /**
   * Get an EventAssignment from the Event based on the element to which it
   * refers.
   *
   * @param sid a string representing the "variable" attribute of the
   * EventAssignment object to retrieve.
   *
   * @return the first EventAssignment in this Event based on the given
   * variable attribute or NULL if no such EventAssignment exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const EventAssignment* getEventAssignmentByVariable(const std::string& sid)
    const;


  /**
   * Get an EventAssignment from the Event based on the element to which it
   * refers.
   *
   * @param sid a string representing the "variable" attribute of the
   * EventAssignment object to retrieve.
   *
   * @return the first EventAssignment in this Event based on the given
   * variable attribute or NULL if no such EventAssignment exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  EventAssignment* getEventAssignmentByVariable(const std::string& sid);


  /**
   * Adds a copy of the given EventAssignment to this Event.
   *
   * @param ea the EventAssignment object to add.
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
   * @see createEventAssignment()
   * @see getEventAssignment(const std::string& sid)
   * @see getEventAssignment(unsigned int n)
   * @see getNumEventAssignments()
   * @see removeEventAssignment(const std::string& sid)
   * @see removeEventAssignment(unsigned int n)
   */
  int addEventAssignment(const EventAssignment* ea);


  /**
   * Get the number of EventAssignment objects in this Event.
   *
   * @return the number of EventAssignment objects in this Event.
   *
   *
   * @see addEventAssignment(const EventAssignment* object)
   * @see createEventAssignment()
   * @see getEventAssignment(const std::string& sid)
   * @see getEventAssignment(unsigned int n)
   * @see removeEventAssignment(const std::string& sid)
   * @see removeEventAssignment(unsigned int n)
   */
  unsigned int getNumEventAssignments() const;


  /**
   * Creates a new EventAssignment object, adds it to this Event object and
   * returns the EventAssignment object created.
   *
   * @return a new EventAssignment object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addEventAssignment(const EventAssignment* object)
   * @see getEventAssignment(const std::string& sid)
   * @see getEventAssignment(unsigned int n)
   * @see getNumEventAssignments()
   * @see removeEventAssignment(const std::string& sid)
   * @see removeEventAssignment(unsigned int n)
   */
  EventAssignment* createEventAssignment();


  /**
   * Removes the nth EventAssignment from this Event and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the EventAssignment to
   * remove.
   *
   * @return a pointer to the nth EventAssignment in this Event.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addEventAssignment(const EventAssignment* object)
   * @see createEventAssignment()
   * @see getEventAssignment(const std::string& sid)
   * @see getEventAssignment(unsigned int n)
   * @see getNumEventAssignments()
   * @see removeEventAssignment(const std::string& sid)
   */
  EventAssignment* removeEventAssignment(unsigned int n);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this Event object.
   *
   * For Event, the XML element name is always @c "".
   *
   * @return the name of this element, i.e. @c "".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBML type code for this Event object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBML type code for this object:
   * @sbmlconstant{CORE_EVENT, SBMLCoreTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this Event
   * object have been set.
   *
   * @return @c true to indicate that all the required attributes of this Event
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the Event object are:
   * @li "useValuesFromTriggerTime"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenLibsbmlInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

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




  #ifndef SWIG



  /** @cond doxygenLibsbmlInternal */

  /**
   * Gets the value of the "attributeName" attribute of this Event.
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
   * Gets the value of the "attributeName" attribute of this Event.
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
   * Gets the value of the "attributeName" attribute of this Event.
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
   * Gets the value of the "attributeName" attribute of this Event.
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
   * Gets the value of the "attributeName" attribute of this Event.
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
   * Predicate returning @c true if this Event's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this Event's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Sets the value of the "attributeName" attribute of this Event.
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
   * Sets the value of the "attributeName" attribute of this Event.
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
   * Sets the value of the "attributeName" attribute of this Event.
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
   * Sets the value of the "attributeName" attribute of this Event.
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
   * Sets the value of the "attributeName" attribute of this Event.
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
   * Unsets the value of the "attributeName" attribute of this Event.
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
   * Creates and returns an new "elementName" object in this Event.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds a new "elementName" object to this Event.
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
   * Event.
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
   * Returns the number of "elementName" in this Event.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Returns the nth object of "objectName" in this Event.
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


protected:


  /** @cond doxygenLibsbmlInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenLibsbmlInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSBML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new Event_t using the given SBML Level and @ p version values.
 *
 * @param level an unsigned int, the SBML Level to assign to this Event_t.
 *
 * @param version an unsigned int, the SBML Version to assign to this Event_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
Event_t *
Event_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this Event_t object.
 *
 * @param e the Event_t structure.
 *
 * @return a (deep) copy of this Event_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
Event_t*
Event_clone(const Event_t* e);


/**
 * Frees this Event_t object.
 *
 * @param e the Event_t structure.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
void
Event_free(Event_t* e);


/**
 * Returns the value of the "useValuesFromTriggerTime" attribute of this
 * Event_t.
 *
 * @param e the Event_t structure whose useValuesFromTriggerTime is sought.
 *
 * @return the value of the "useValuesFromTriggerTime" attribute of this
 * Event_t as a boolean.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_getUseValuesFromTriggerTime(const Event_t * e);


/**
 * Returns the value of the "timeUnits" attribute of this Event_t.
 *
 * @param e the Event_t structure whose timeUnits is sought.
 *
 * @return the value of the "timeUnits" attribute of this Event_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
char *
Event_getTimeUnits(const Event_t * e);


/**
 * Predicate returning @c 1 (true) if this Event_t's "useValuesFromTriggerTime"
 * attribute is set.
 *
 * @param e the Event_t structure.
 *
 * @return @c 1 (true) if this Event_t's "useValuesFromTriggerTime" attribute
 * has been set, otherwise @c 0 (false) is returned.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_isSetUseValuesFromTriggerTime(const Event_t * e);


/**
 * Predicate returning @c 1 (true) if this Event_t's "timeUnits" attribute is
 * set.
 *
 * @param e the Event_t structure.
 *
 * @return @c 1 (true) if this Event_t's "timeUnits" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_isSetTimeUnits(const Event_t * e);


/**
 * Sets the value of the "useValuesFromTriggerTime" attribute of this Event_t.
 *
 * @param e the Event_t structure.
 *
 * @param useValuesFromTriggerTime int value of the "useValuesFromTriggerTime"
 * attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_setUseValuesFromTriggerTime(Event_t * e, int useValuesFromTriggerTime);


/**
 * Sets the value of the "timeUnits" attribute of this Event_t.
 *
 * @param e the Event_t structure.
 *
 * @param timeUnits const char * value of the "timeUnits" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_setTimeUnits(Event_t * e, const char * timeUnits);


/**
 * Unsets the value of the "useValuesFromTriggerTime" attribute of this
 * Event_t.
 *
 * @param e the Event_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_unsetUseValuesFromTriggerTime(Event_t * e);


/**
 * Unsets the value of the "timeUnits" attribute of this Event_t.
 *
 * @param e the Event_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_unsetTimeUnits(Event_t * e);


/**
 * Returns the value of the "trigger" element of this Event_t.
 *
 * @param e the Event_t structure whose trigger is sought.
 *
 * @return the value of the "trigger" element of this Event_t as a Trigger*.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
const Trigger_t*
Event_getTrigger(const Event_t * e);


/**
 * Returns the value of the "priority" element of this Event_t.
 *
 * @param e the Event_t structure whose priority is sought.
 *
 * @return the value of the "priority" element of this Event_t as a Priority*.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
const Priority_t*
Event_getPriority(const Event_t * e);


/**
 * Returns the value of the "delay" element of this Event_t.
 *
 * @param e the Event_t structure whose delay is sought.
 *
 * @return the value of the "delay" element of this Event_t as a Delay*.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
const Delay_t*
Event_getDelay(const Event_t * e);


/**
 * Predicate returning @c 1 (true) if this Event_t's "trigger" element is set.
 *
 * @param e the Event_t structure.
 *
 * @return @c 1 (true) if this Event_t's "trigger" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_isSetTrigger(const Event_t * e);


/**
 * Predicate returning @c 1 (true) if this Event_t's "priority" element is set.
 *
 * @param e the Event_t structure.
 *
 * @return @c 1 (true) if this Event_t's "priority" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_isSetPriority(const Event_t * e);


/**
 * Predicate returning @c 1 (true) if this Event_t's "delay" element is set.
 *
 * @param e the Event_t structure.
 *
 * @return @c 1 (true) if this Event_t's "delay" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_isSetDelay(const Event_t * e);


/**
 * Sets the value of the "trigger" element of this Event_t.
 *
 * @param e the Event_t structure.
 *
 * @param trigger Trigger_t* value of the "trigger" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_setTrigger(Event_t * e, const Trigger_t* trigger);


/**
 * Sets the value of the "priority" element of this Event_t.
 *
 * @param e the Event_t structure.
 *
 * @param priority Priority_t* value of the "priority" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_setPriority(Event_t * e, const Priority_t* priority);


/**
 * Sets the value of the "delay" element of this Event_t.
 *
 * @param e the Event_t structure.
 *
 * @param delay Delay_t* value of the "delay" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_setDelay(Event_t * e, const Delay_t* delay);


/**
 * Creates a new Trigger_t object, adds it to this Event_t object and returns
 * the Trigger_t object created.
 *
 * @param e the Event_t structure to which the Trigger_t should be added.
 *
 * @return a new Trigger_t object instance.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
Trigger_t*
Event_createTrigger(Event_t* e);


/**
 * Creates a new Priority_t object, adds it to this Event_t object and returns
 * the Priority_t object created.
 *
 * @param e the Event_t structure to which the Priority_t should be added.
 *
 * @return a new Priority_t object instance.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
Priority_t*
Event_createPriority(Event_t* e);


/**
 * Creates a new Delay_t object, adds it to this Event_t object and returns the
 * Delay_t object created.
 *
 * @param e the Event_t structure to which the Delay_t should be added.
 *
 * @return a new Delay_t object instance.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
Delay_t*
Event_createDelay(Event_t* e);


/**
 * Unsets the value of the "trigger" element of this Event_t.
 *
 * @param e the Event_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_unsetTrigger(Event_t * e);


/**
 * Unsets the value of the "priority" element of this Event_t.
 *
 * @param e the Event_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_unsetPriority(Event_t * e);


/**
 * Unsets the value of the "delay" element of this Event_t.
 *
 * @param e the Event_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbmlconstant{LIBSBML_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbmlconstant{LIBSBML_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_unsetDelay(Event_t * e);


/**
 * Returns a ListOf_t * containing EventAssignment_t objects from this Event_t.
 *
 * @param e the Event_t structure whose SBMLListOfEventAssignments is sought.
 *
 * @return the SBMLListOfEventAssignments from this Event_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see Event_addEventAssignment()
 * @see Event_createEventAssignment()
 * @see Event_getEventAssignmentById()
 * @see Event_getEventAssignment()
 * @see Event_getNumEventAssignments()
 * @see Event_removeEventAssignmentById()
 * @see Event_removeEventAssignment()
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
SBMLListOf_t*
Event_getListOfEventAssignments(Event_t* e);


/**
 * Get an EventAssignment_t from the Event_t.
 *
 * @param e the Event_t structure to search.
 *
 * @param n an unsigned int representing the index of the EventAssignment_t to
 * retrieve.
 *
 * @return the nth EventAssignment_t in the SBMLListOfEventAssignments within
 * this Event.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
EventAssignment_t*
Event_getEventAssignment(Event_t* e, unsigned int n);


/**
 * Get an EventAssignment_t from the Event_t based on the element to which it
 * refers.
 *
 * @param e the Event_t structure to search.
 *
 * @param sid a string representing the "variable" attribute of the
 * EventAssignment_t object to retrieve.
 *
 * @return the first EventAssignment_t in this Event_t based on the given
 * variable attribute or NULL if no such EventAssignment_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
EventAssignment_t*
Event_getEventAssignmentByVariable(Event_t* e, const char *sid);


/**
 * Adds a copy of the given EventAssignment_t to this Event_t.
 *
 * @param e the Event_t structure to which the EventAssignment_t should be
 * added.
 *
 * @param ea the EventAssignment_t object to add.
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
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_addEventAssignment(Event_t* e, const EventAssignment_t* ea);


/**
 * Get the number of EventAssignment_t objects in this Event_t.
 *
 * @param e the Event_t structure to query.
 *
 * @return the number of EventAssignment_t objects in this Event_t.
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
unsigned int
Event_getNumEventAssignments(Event_t* e);


/**
 * Creates a new EventAssignment_t object, adds it to this Event_t object and
 * returns the EventAssignment_t object created.
 *
 * @param e the Event_t structure to which the EventAssignment_t should be
 * added.
 *
 * @return a new EventAssignment_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
EventAssignment_t*
Event_createEventAssignment(Event_t* e);


/**
 * Removes the nth EventAssignment_t from this Event_t and returns a pointer to
 * it.
 *
 * @param e the Event_t structure to search.
 *
 * @param n an unsigned int representing the index of the EventAssignment_t to
 * remove.
 *
 * @return a pointer to the nth EventAssignment_t in this Event_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
EventAssignment_t*
Event_removeEventAssignment(Event_t* e, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Event_t object have been set.
 *
 * @param e the Event_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * Event_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the Event_t object are:
 * @li "useValuesFromTriggerTime"
 *
 * @memberof Event_t
 */
LIBSBML_EXTERN
int
Event_hasRequiredAttributes(const Event_t * e);




END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !Event_H__ */


