/**
 * @file Event.cpp
 * @brief Implementation of the Event class.
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
 */
#include <sbml/Event.h>
#include <sbml/SBMLListOfEvents.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBML_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new Event using the given SBML Level and @ p version values.
 */
Event::Event(unsigned int level, unsigned int version)
  : SBase(level, version)
  , mUseValuesFromTriggerTime (false)
  , mIsSetUseValuesFromTriggerTime (false)
  , mTrigger (NULL)
  , mPriority (NULL)
  , mDelay (NULL)
  , mEventAssignments (level, version)
  , mTimeUnits ("")
{
  setSBMLNamespacesAndOwn(new SBMLNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new Event using the given SBMLNamespaces object @p sbmlns.
 */
Event::Event(SBMLNamespaces *sbmlns)
  : SBase(sbmlns)
  , mUseValuesFromTriggerTime (false)
  , mIsSetUseValuesFromTriggerTime (false)
  , mTrigger (NULL)
  , mPriority (NULL)
  , mDelay (NULL)
  , mEventAssignments (sbmlns)
  , mTimeUnits ("")
{
  setElementNamespace(sbmlns->getURI());
  connectToChild();
}


/*
 * Copy constructor for Event.
 */
Event::Event(const Event& orig)
  : SBase( orig )
  , mUseValuesFromTriggerTime ( orig.mUseValuesFromTriggerTime )
  , mIsSetUseValuesFromTriggerTime ( orig.mIsSetUseValuesFromTriggerTime )
  , mTrigger ( NULL )
  , mPriority ( NULL )
  , mDelay ( NULL )
  , mEventAssignments ( orig.mEventAssignments )
  , mTimeUnits ( orig.mTimeUnits )
{
  if (orig.mTrigger != NULL)
  {
    mTrigger = orig.mTrigger->clone();
  }

  if (orig.mPriority != NULL)
  {
    mPriority = orig.mPriority->clone();
  }

  if (orig.mDelay != NULL)
  {
    mDelay = orig.mDelay->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for Event.
 */
Event&
Event::operator=(const Event& rhs)
{
  if (&rhs != this)
  {
    SBase::operator=(rhs);
    mUseValuesFromTriggerTime = rhs.mUseValuesFromTriggerTime;
    mIsSetUseValuesFromTriggerTime = rhs.mIsSetUseValuesFromTriggerTime;
    mEventAssignments = rhs.mEventAssignments;
    mTimeUnits = rhs.mTimeUnits;
    delete mTrigger;
    if (rhs.mTrigger != NULL)
    {
      mTrigger = rhs.mTrigger->clone();
    }
    else
    {
      mTrigger = NULL;
    }

    delete mPriority;
    if (rhs.mPriority != NULL)
    {
      mPriority = rhs.mPriority->clone();
    }
    else
    {
      mPriority = NULL;
    }

    delete mDelay;
    if (rhs.mDelay != NULL)
    {
      mDelay = rhs.mDelay->clone();
    }
    else
    {
      mDelay = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this Event object.
 */
Event*
Event::clone() const
{
  return new Event(*this);
}


/*
 * Destructor for Event.
 */
Event::~Event()
{
  delete mTrigger;
  mTrigger = NULL;
  delete mPriority;
  mPriority = NULL;
  delete mDelay;
  mDelay = NULL;
}


/*
 * Returns the value of the "useValuesFromTriggerTime" attribute of this Event.
 */
bool
Event::getUseValuesFromTriggerTime() const
{
  return mUseValuesFromTriggerTime;
}


/*
 * Returns the value of the "timeUnits" attribute of this Event.
 */
const std::string&
Event::getTimeUnits() const
{
  return mTimeUnits;
}


/*
 * Predicate returning @c true if this Event's "useValuesFromTriggerTime"
 * attribute is set.
 */
bool
Event::isSetUseValuesFromTriggerTime() const
{
  return mIsSetUseValuesFromTriggerTime;
}


/*
 * Predicate returning @c true if this Event's "timeUnits" attribute is set.
 */
bool
Event::isSetTimeUnits() const
{
  return (mTimeUnits.empty() == false);
}


/*
 * Sets the value of the "useValuesFromTriggerTime" attribute of this Event.
 */
int
Event::setUseValuesFromTriggerTime(bool useValuesFromTriggerTime)
{
  mUseValuesFromTriggerTime = useValuesFromTriggerTime;
  mIsSetUseValuesFromTriggerTime = true;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "timeUnits" attribute of this Event.
 */
int
Event::setTimeUnits(const std::string& timeUnits)
{
  if (!(SyntaxChecker::isValidInternalUnitSId(timeUnits)))
  {
    return LIBSBML_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTimeUnits = timeUnits;
    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "useValuesFromTriggerTime" attribute of this Event.
 */
int
Event::unsetUseValuesFromTriggerTime()
{
  mUseValuesFromTriggerTime = false;
  mIsSetUseValuesFromTriggerTime = false;

  if (isSetUseValuesFromTriggerTime() == false)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "timeUnits" attribute of this Event.
 */
int
Event::unsetTimeUnits()
{
  mTimeUnits.erase();

  if (mTimeUnits.empty() == true)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBML_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "trigger" element of this Event.
 */
const Trigger*
Event::getTrigger() const
{
  return mTrigger;
}


/*
 * Returns the value of the "trigger" element of this Event.
 */
Trigger*
Event::getTrigger()
{
  return mTrigger;
}


/*
 * Returns the value of the "priority" element of this Event.
 */
const Priority*
Event::getPriority() const
{
  return mPriority;
}


/*
 * Returns the value of the "priority" element of this Event.
 */
Priority*
Event::getPriority()
{
  return mPriority;
}


/*
 * Returns the value of the "delay" element of this Event.
 */
const Delay*
Event::getDelay() const
{
  return mDelay;
}


/*
 * Returns the value of the "delay" element of this Event.
 */
Delay*
Event::getDelay()
{
  return mDelay;
}


/*
 * Predicate returning @c true if this Event's "trigger" element is set.
 */
bool
Event::isSetTrigger() const
{
  return (mTrigger != NULL);
}


/*
 * Predicate returning @c true if this Event's "priority" element is set.
 */
bool
Event::isSetPriority() const
{
  return (mPriority != NULL);
}


/*
 * Predicate returning @c true if this Event's "delay" element is set.
 */
bool
Event::isSetDelay() const
{
  return (mDelay != NULL);
}


/*
 * Sets the value of the "trigger" element of this Event.
 */
int
Event::setTrigger(const Trigger* trigger)
{
  if (mTrigger == trigger)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (trigger == NULL)
  {
    delete mTrigger;
    mTrigger = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mTrigger;
    mTrigger = (trigger != NULL) ? trigger->clone() : NULL;
    if (mTrigger != NULL)
    {
      mTrigger->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "priority" element of this Event.
 */
int
Event::setPriority(const Priority* priority)
{
  if (mPriority == priority)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (priority == NULL)
  {
    delete mPriority;
    mPriority = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mPriority;
    mPriority = (priority != NULL) ? priority->clone() : NULL;
    if (mPriority != NULL)
    {
      mPriority->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "delay" element of this Event.
 */
int
Event::setDelay(const Delay* delay)
{
  if (mDelay == delay)
  {
    return LIBSBML_OPERATION_SUCCESS;
  }
  else if (delay == NULL)
  {
    delete mDelay;
    mDelay = NULL;
    return LIBSBML_OPERATION_SUCCESS;
  }
  else
  {
    delete mDelay;
    mDelay = (delay != NULL) ? delay->clone() : NULL;
    if (mDelay != NULL)
    {
      mDelay->connectToParent(this);
    }

    return LIBSBML_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new Trigger object, adds it to this Event object and returns the
 * Trigger object created.
 */
Trigger*
Event::createTrigger()
{
  if (mTrigger != NULL)
  {
    delete mTrigger;
  }

  mTrigger = new Trigger(getSBMLNamespaces());

  connectToChild();

  return mTrigger;
}


/*
 * Creates a new Priority object, adds it to this Event object and returns the
 * Priority object created.
 */
Priority*
Event::createPriority()
{
  if (mPriority != NULL)
  {
    delete mPriority;
  }

  mPriority = new Priority(getSBMLNamespaces());

  connectToChild();

  return mPriority;
}


/*
 * Creates a new Delay object, adds it to this Event object and returns the
 * Delay object created.
 */
Delay*
Event::createDelay()
{
  if (mDelay != NULL)
  {
    delete mDelay;
  }

  mDelay = new Delay(getSBMLNamespaces());

  connectToChild();

  return mDelay;
}


/*
 * Unsets the value of the "trigger" element of this Event.
 */
int
Event::unsetTrigger()
{
  delete mTrigger;
  mTrigger = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "priority" element of this Event.
 */
int
Event::unsetPriority()
{
  delete mPriority;
  mPriority = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "delay" element of this Event.
 */
int
Event::unsetDelay()
{
  delete mDelay;
  mDelay = NULL;
  return LIBSBML_OPERATION_SUCCESS;
}


/*
 * Returns the SBMLListOfEventAssignments from this Event.
 */
const SBMLListOfEventAssignments*
Event::getSBMLListOfEventAssignments() const
{
  return &mEventAssignments;
}


/*
 * Returns the SBMLListOfEventAssignments from this Event.
 */
SBMLListOfEventAssignments*
Event::getSBMLListOfEventAssignments()
{
  return &mEventAssignments;
}


/*
 * Get an EventAssignment from the Event.
 */
EventAssignment*
Event::getEventAssignment(unsigned int n)
{
  return mEventAssignments.get(n);
}


/*
 * Get an EventAssignment from the Event.
 */
const EventAssignment*
Event::getEventAssignment(unsigned int n) const
{
  return mEventAssignments.get(n);
}


/*
 * Get an EventAssignment from the Event based on the element to which it
 * refers.
 */
const EventAssignment*
Event::getEventAssignmentByVariable(const std::string& sid) const
{
  return mEventAssignments.getByVariable(sid);
}


/*
 * Get an EventAssignment from the Event based on the element to which it
 * refers.
 */
EventAssignment*
Event::getEventAssignmentByVariable(const std::string& sid)
{
  return mEventAssignments.getByVariable(sid);
}


/*
 * Adds a copy of the given EventAssignment to this Event.
 */
int
Event::addEventAssignment(const EventAssignment* ea)
{
  if (ea == NULL)
  {
    return LIBSBML_OPERATION_FAILED;
  }
  else if (ea->hasRequiredAttributes() == false)
  {
    return LIBSBML_INVALID_OBJECT;
  }
  else if (getLevel() != ea->getLevel())
  {
    return LIBSBML_LEVEL_MISMATCH;
  }
  else if (getVersion() != ea->getVersion())
  {
    return LIBSBML_VERSION_MISMATCH;
  }
  else if (matchesRequiredSBMLNamespacesForAddition(static_cast<const
    SBase*>(ea)) == false)
  {
    return LIBSBML_NAMESPACES_MISMATCH;
  }
  else
  {
    return mEventAssignments.append(ea);
  }
}


/*
 * Get the number of EventAssignment objects in this Event.
 */
unsigned int
Event::getNumEventAssignments() const
{
  return mEventAssignments.size();
}


/*
 * Creates a new EventAssignment object, adds it to this Event object and
 * returns the EventAssignment object created.
 */
EventAssignment*
Event::createEventAssignment()
{
  EventAssignment* ea = NULL;

  try
  {
    ea = new EventAssignment(getSBMLNamespaces());
  }
  catch (...)
  {
  }

  if (ea != NULL)
  {
    mEventAssignments.appendAndOwn(ea);
  }

  return ea;
}


/*
 * Removes the nth EventAssignment from this Event and returns a pointer to it.
 */
EventAssignment*
Event::removeEventAssignment(unsigned int n)
{
  return mEventAssignments.remove(n);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
Event::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetTimeUnits() && mTimeUnits == oldid)
  {
    setTimeUnits(newid);
  }
}


/*
 * Returns the XML element name of this Event object.
 */
const std::string&
Event::getElementName() const
{
  static const string name = "";
  return name;
}


/*
 * Returns the libSBML type code for this Event object.
 */
int
Event::getTypeCode() const
{
  return CORE_EVENT;
}


/*
 * Predicate returning @c true if all the required attributes for this Event
 * object have been set.
 */
bool
Event::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetUseValuesFromTriggerTime() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Write any contained elements
 */
void
Event::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeElements(stream);

  if (isSetTrigger() == true)
  {
    mTrigger->write(stream);
  }

  if (isSetPriority() == true)
  {
    mPriority->write(stream);
  }

  if (isSetDelay() == true)
  {
    mDelay->write(stream);
  }

  if (getNumEventAssignments() > 0)
  {
    mEventAssignments.write(stream);
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Accepts the given SBMLVisitor
 */
bool
Event::accept(SBMLVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the parent SBMLDocument
 */
void
Event::setSBMLDocument(SBMLDocument* d)
{
  SBase::setSBMLDocument(d);

  if (mTrigger != NULL)
  {
    mTrigger->setSBMLDocument(d);
  }

  if (mPriority != NULL)
  {
    mPriority->setSBMLDocument(d);
  }

  if (mDelay != NULL)
  {
    mDelay->setSBMLDocument(d);
  }

  mEventAssignments.setSBMLDocument(d);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Connects to child elements
 */
void
Event::connectToChild()
{
  SBase::connectToChild();

  if (mTrigger != NULL)
  {
    mTrigger->connectToParent(this);
  }

  if (mPriority != NULL)
  {
    mPriority->connectToParent(this);
  }

  if (mDelay != NULL)
  {
    mDelay->connectToParent(this);
  }

  mEventAssignments.connectToParent(this);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Updates the namespaces when setLevelVersion is used
 */
void
Event::updateSBMLNamespace(const std::string& package,
                           unsigned int level,
                           unsigned int version)
{
  if (mTrigger != NULL)
  {
    mTrigger->updateSBMLNamespace(package, level, version);
  }

  if (mPriority != NULL)
  {
    mPriority->updateSBMLNamespace(package, level, version);
  }

  if (mDelay != NULL)
  {
    mDelay->updateSBMLNamespace(package, level, version);
  }

  mEventAssignments.updateSBMLNamespace(package, level, version);
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Event.
 */
int
Event::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "useValuesFromTriggerTime")
  {
    value = getUseValuesFromTriggerTime();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Event.
 */
int
Event::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Event.
 */
int
Event::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Event.
 */
int
Event::getAttribute(const std::string& attributeName,
                    unsigned int& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Gets the value of the "attributeName" attribute of this Event.
 */
int
Event::getAttribute(const std::string& attributeName,
                    std::string& value) const
{
  int return_value = SBase::getAttribute(attributeName, value);

  if (return_value == LIBSBML_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "timeUnits")
  {
    value = getTimeUnits();
    return_value = LIBSBML_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Predicate returning @c true if this Event's attribute "attributeName" is
 * set.
 */
bool
Event::isSetAttribute(const std::string& attributeName) const
{
  bool value = SBase::isSetAttribute(attributeName);

  if (attributeName == "useValuesFromTriggerTime")
  {
    value = isSetUseValuesFromTriggerTime();
  }
  else if (attributeName == "timeUnits")
  {
    value = isSetTimeUnits();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Event.
 */
int
Event::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "useValuesFromTriggerTime")
  {
    return_value = setUseValuesFromTriggerTime(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Event.
 */
int
Event::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Event.
 */
int
Event::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Event.
 */
int
Event::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Sets the value of the "attributeName" attribute of this Event.
 */
int
Event::setAttribute(const std::string& attributeName,
                    const std::string& value)
{
  int return_value = SBase::setAttribute(attributeName, value);

  if (attributeName == "timeUnits")
  {
    return_value = setTimeUnits(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Unsets the value of the "attributeName" attribute of this Event.
 */
int
Event::unsetAttribute(const std::string& attributeName)
{
  int value = SBase::unsetAttribute(attributeName);

  if (attributeName == "useValuesFromTriggerTime")
  {
    value = unsetUseValuesFromTriggerTime();
  }
  else if (attributeName == "timeUnits")
  {
    value = unsetTimeUnits();
  }

  return value;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Creates and returns an new "elementName" object in this Event.
 */
SBase*
Event::createChildObject(const std::string& elementName)
{
  SBase* obj = NULL;

  if (elementName == "trigger")
  {
    return createTrigger();
  }
  else if (elementName == "priority")
  {
    return createPriority();
  }
  else if (elementName == "delay")
  {
    return createDelay();
  }
  else if (elementName == "eventAssignment")
  {
    return createEventAssignment();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds a new "elementName" object to this Event.
 */
int
Event::addChildObject(const std::string& elementName, const SBase* element)
{
  if (elementName == "trigger" && element->getTypeCode() == CORE_TRIGGER)
  {
    return setTrigger((const Trigger*)(element));
  }
  else if (elementName == "priority" && element->getTypeCode() ==
    CORE_PRIORITY)
  {
    return setPriority((const Priority*)(element));
  }
  else if (elementName == "delay" && element->getTypeCode() == CORE_DELAY)
  {
    return setDelay((const Delay*)(element));
  }
  else if (elementName == "eventAssignment" && element->getTypeCode() ==
    CORE_EVENTASSIGNMENT)
  {
    return addEventAssignment((const EventAssignment*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * Event.
 */
SBase*
Event::removeChildObject(const std::string& elementName,
                         const std::string& id)
{
  if (elementName == "trigger")
  {
    Trigger * obj = getTrigger();
    if (unsetTrigger() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "priority")
  {
    Priority * obj = getPriority();
    if (unsetPriority() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "delay")
  {
    Delay * obj = getDelay();
    if (unsetDelay() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "eventAssignment")
  {
    for (unsigned int i = 0; i < getNumEventAssignments(); i++)
    {
      if (getEventAssignment(i)->getId() == id)
      {
        return removeEventAssignment(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the number of "elementName" in this Event.
 */
unsigned int
Event::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "trigger")
  {
    if (isSetTrigger())
    {
      return 1;
    }
  }
  else if (elementName == "priority")
  {
    if (isSetPriority())
    {
      return 1;
    }
  }
  else if (elementName == "delay")
  {
    if (isSetDelay())
    {
      return 1;
    }
  }
  else if (elementName == "eventAssignment")
  {
    return getNumEventAssignments();
  }

  return n;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Returns the nth object of "objectName" in this Event.
 */
SBase*
Event::getObject(const std::string& elementName, unsigned int index)
{
  SBase* obj = NULL;

  if (elementName == "trigger")
  {
    return getTrigger();
  }
  else if (elementName == "priority")
  {
    return getPriority();
  }
  else if (elementName == "delay")
  {
    return getDelay();
  }
  else if (elementName == "eventAssignment")
  {
    return getEventAssignment(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SBase*
Event::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SBase* obj = NULL;

  if (mTrigger != NULL)
  {
    if (mTrigger->getId() == id)
    {
      return mTrigger;
    }

    obj = mTrigger->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mPriority != NULL)
  {
    if (mPriority->getId() == id)
    {
      return mPriority;
    }

    obj = mPriority->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mDelay != NULL)
  {
    if (mDelay->getId() == id)
    {
      return mDelay;
    }

    obj = mDelay->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  obj = mEventAssignments.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}



/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SBase*
Event::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "trigger")
  {
    if (isSetTrigger())
    {
      getErrorLog()->logError(CoreEventAllowedElements, getLevel(),
        getVersion());
    }

    delete mTrigger;
    mTrigger = new Trigger(getSBMLNamespaces());
    obj = mTrigger;
  }
  else if (name == "priority")
  {
    if (isSetPriority())
    {
      getErrorLog()->logError(CoreEventAllowedElements, getLevel(),
        getVersion());
    }

    delete mPriority;
    mPriority = new Priority(getSBMLNamespaces());
    obj = mPriority;
  }
  else if (name == "delay")
  {
    if (isSetDelay())
    {
      getErrorLog()->logError(CoreEventAllowedElements, getLevel(),
        getVersion());
    }

    delete mDelay;
    mDelay = new Delay(getSBMLNamespaces());
    obj = mDelay;
  }
  else if (name == "sBMLListOfEventAssignments")
  {
    if (mEventAssignments.size() != 0)
    {
      getErrorLog()->logError(CoreEventAllowedElements, getLevel(),
        getVersion());
    }

    obj = &mEventAssignments;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Adds the expected attributes for this element
 */
void
Event::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SBase::addExpectedAttributes(attributes);

  attributes.add("useValuesFromTriggerTime");

  attributes.add("timeUnits");
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
Event::readAttributes(
                      const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes&
                        attributes,
                      const LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes&
                        expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SBMLErrorLog* log = getErrorLog();

  if (log && getParentSBMLObject() &&
    static_cast<SBMLListOfEvents*>(getParentSBMLObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SBMLUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SBMLUnknownCoreAttribute);
        log->logError(CoreModelLOEventsAllowedCoreAttributes, level, version,
          details);
      }
    }
  }

  SBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SBMLUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SBMLUnknownCoreAttribute);
        log->logError(CoreEventAllowedAttributes, level, version, details);
      }
    }
  }

  // 
  // useValuesFromTriggerTime bool (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetUseValuesFromTriggerTime =
    attributes.readInto("useValuesFromTriggerTime", mUseValuesFromTriggerTime);

  if (mIsSetUseValuesFromTriggerTime == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      log->logError(CoreEventUseValuesFromTriggerTimeMustBeBoolean, level,
        version);
    }
    else
    {
      std::string message = "Core attribute 'useValuesFromTriggerTime' is "
        "missing from the <Event> element.";
      log->logError(CoreEventAllowedAttributes, level, version, message);
    }
  }

  // 
  // timeUnits UnitSIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("timeUnits", mTimeUnits);

  if (assigned == true)
  {
    if (mTimeUnits.empty() == true)
    {
      logEmptyString(mTimeUnits, level, version, "<Event>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mTimeUnits) == false)
    {
      std::string msg = "The timeUnits attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mTimeUnits + "', which does not conform to the syntax.";
      logError(CoreEventTimeUnitsMustBeUnitSId, level, version, msg);
    }
  }
}

/** @endcond */



/** @cond doxygenLibsbmlInternal */

/*
 * Writes the attributes to the stream
 */
void
Event::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SBase::writeAttributes(stream);

  if (isSetUseValuesFromTriggerTime() == true)
  {
    stream.writeAttribute("useValuesFromTriggerTime", getPrefix(),
      mUseValuesFromTriggerTime);
  }

  if (isSetTimeUnits() == true)
  {
    stream.writeAttribute("timeUnits", getPrefix(), mTimeUnits);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new Event_t using the given SBML Level and @ p version values.
 */
LIBSBML_EXTERN
Event_t *
Event_create(unsigned int level, unsigned int version)
{
  return new Event(level, version);
}


/*
 * Creates and returns a deep copy of this Event_t object.
 */
LIBSBML_EXTERN
Event_t*
Event_clone(const Event_t* e)
{
  if (e != NULL)
  {
    return static_cast<Event_t*>(e->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this Event_t object.
 */
LIBSBML_EXTERN
void
Event_free(Event_t* e)
{
  if (e != NULL)
  {
    delete e;
  }
}


/*
 * Returns the value of the "useValuesFromTriggerTime" attribute of this
 * Event_t.
 */
LIBSBML_EXTERN
int
Event_getUseValuesFromTriggerTime(const Event_t * e)
{
  return (e != NULL) ? static_cast<int>(e->getUseValuesFromTriggerTime()) : 0;
}


/*
 * Returns the value of the "timeUnits" attribute of this Event_t.
 */
LIBSBML_EXTERN
char *
Event_getTimeUnits(const Event_t * e)
{
  if (e == NULL)
  {
    return NULL;
  }

  return e->getTimeUnits().empty() ? NULL :
    safe_strdup(e->getTimeUnits().c_str());
}


/*
 * Predicate returning @c 1 (true) if this Event_t's "useValuesFromTriggerTime"
 * attribute is set.
 */
LIBSBML_EXTERN
int
Event_isSetUseValuesFromTriggerTime(const Event_t * e)
{
  return (e != NULL) ? static_cast<int>(e->isSetUseValuesFromTriggerTime()) :
    0;
}


/*
 * Predicate returning @c 1 (true) if this Event_t's "timeUnits" attribute is
 * set.
 */
LIBSBML_EXTERN
int
Event_isSetTimeUnits(const Event_t * e)
{
  return (e != NULL) ? static_cast<int>(e->isSetTimeUnits()) : 0;
}


/*
 * Sets the value of the "useValuesFromTriggerTime" attribute of this Event_t.
 */
LIBSBML_EXTERN
int
Event_setUseValuesFromTriggerTime(Event_t * e, int useValuesFromTriggerTime)
{
  return (e != NULL) ? e->setUseValuesFromTriggerTime(useValuesFromTriggerTime)
    : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "timeUnits" attribute of this Event_t.
 */
LIBSBML_EXTERN
int
Event_setTimeUnits(Event_t * e, const char * timeUnits)
{
  return (e != NULL) ? e->setTimeUnits(timeUnits) : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "useValuesFromTriggerTime" attribute of this
 * Event_t.
 */
LIBSBML_EXTERN
int
Event_unsetUseValuesFromTriggerTime(Event_t * e)
{
  return (e != NULL) ? e->unsetUseValuesFromTriggerTime() :
    LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "timeUnits" attribute of this Event_t.
 */
LIBSBML_EXTERN
int
Event_unsetTimeUnits(Event_t * e)
{
  return (e != NULL) ? e->unsetTimeUnits() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns the value of the "trigger" element of this Event_t.
 */
LIBSBML_EXTERN
const Trigger_t*
Event_getTrigger(const Event_t * e)
{
  if (e == NULL)
  {
    return NULL;
  }

  return (Trigger_t*)(e->getTrigger());
}


/*
 * Returns the value of the "priority" element of this Event_t.
 */
LIBSBML_EXTERN
const Priority_t*
Event_getPriority(const Event_t * e)
{
  if (e == NULL)
  {
    return NULL;
  }

  return (Priority_t*)(e->getPriority());
}


/*
 * Returns the value of the "delay" element of this Event_t.
 */
LIBSBML_EXTERN
const Delay_t*
Event_getDelay(const Event_t * e)
{
  if (e == NULL)
  {
    return NULL;
  }

  return (Delay_t*)(e->getDelay());
}


/*
 * Predicate returning @c 1 (true) if this Event_t's "trigger" element is set.
 */
LIBSBML_EXTERN
int
Event_isSetTrigger(const Event_t * e)
{
  return (e != NULL) ? static_cast<int>(e->isSetTrigger()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Event_t's "priority" element is set.
 */
LIBSBML_EXTERN
int
Event_isSetPriority(const Event_t * e)
{
  return (e != NULL) ? static_cast<int>(e->isSetPriority()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this Event_t's "delay" element is set.
 */
LIBSBML_EXTERN
int
Event_isSetDelay(const Event_t * e)
{
  return (e != NULL) ? static_cast<int>(e->isSetDelay()) : 0;
}


/*
 * Sets the value of the "trigger" element of this Event_t.
 */
LIBSBML_EXTERN
int
Event_setTrigger(Event_t * e, const Trigger_t* trigger)
{
  return (e != NULL) ? e->setTrigger(trigger) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "priority" element of this Event_t.
 */
LIBSBML_EXTERN
int
Event_setPriority(Event_t * e, const Priority_t* priority)
{
  return (e != NULL) ? e->setPriority(priority) : LIBSBML_INVALID_OBJECT;
}


/*
 * Sets the value of the "delay" element of this Event_t.
 */
LIBSBML_EXTERN
int
Event_setDelay(Event_t * e, const Delay_t* delay)
{
  return (e != NULL) ? e->setDelay(delay) : LIBSBML_INVALID_OBJECT;
}


/*
 * Creates a new Trigger_t object, adds it to this Event_t object and returns
 * the Trigger_t object created.
 */
LIBSBML_EXTERN
Trigger_t*
Event_createTrigger(Event_t* e)
{
  if (e == NULL)
  {
    return NULL;
  }

  return (Trigger_t*)(e->createTrigger());
}


/*
 * Creates a new Priority_t object, adds it to this Event_t object and returns
 * the Priority_t object created.
 */
LIBSBML_EXTERN
Priority_t*
Event_createPriority(Event_t* e)
{
  if (e == NULL)
  {
    return NULL;
  }

  return (Priority_t*)(e->createPriority());
}


/*
 * Creates a new Delay_t object, adds it to this Event_t object and returns the
 * Delay_t object created.
 */
LIBSBML_EXTERN
Delay_t*
Event_createDelay(Event_t* e)
{
  if (e == NULL)
  {
    return NULL;
  }

  return (Delay_t*)(e->createDelay());
}


/*
 * Unsets the value of the "trigger" element of this Event_t.
 */
LIBSBML_EXTERN
int
Event_unsetTrigger(Event_t * e)
{
  return (e != NULL) ? e->unsetTrigger() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "priority" element of this Event_t.
 */
LIBSBML_EXTERN
int
Event_unsetPriority(Event_t * e)
{
  return (e != NULL) ? e->unsetPriority() : LIBSBML_INVALID_OBJECT;
}


/*
 * Unsets the value of the "delay" element of this Event_t.
 */
LIBSBML_EXTERN
int
Event_unsetDelay(Event_t * e)
{
  return (e != NULL) ? e->unsetDelay() : LIBSBML_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing EventAssignment_t objects from this Event_t.
 */
LIBSBML_EXTERN
SBMLListOf_t*
Event_getSBMLListOfEventAssignments(Event_t* e)
{
  return (e != NULL) ? e->getSBMLListOfEventAssignments() : NULL;
}


/*
 * Get an EventAssignment_t from the Event_t.
 */
LIBSBML_EXTERN
EventAssignment_t*
Event_getEventAssignment(Event_t* e, unsigned int n)
{
  return (e != NULL) ? e->getEventAssignment(n) : NULL;
}


/*
 * Get an EventAssignment_t from the Event_t based on the element to which it
 * refers.
 */
LIBSBML_EXTERN
EventAssignment_t*
Event_getEventAssignmentByVariable(Event_t* e, const char *sid)
{
  return (e != NULL && sid != NULL) ? e->getEventAssignmentByVariable(sid) :
    NULL;
}


/*
 * Adds a copy of the given EventAssignment_t to this Event_t.
 */
LIBSBML_EXTERN
int
Event_addEventAssignment(Event_t* e, const EventAssignment_t* ea)
{
  return (e != NULL) ? e->addEventAssignment(ea) : LIBSBML_INVALID_OBJECT;
}


/*
 * Get the number of EventAssignment_t objects in this Event_t.
 */
LIBSBML_EXTERN
unsigned int
Event_getNumEventAssignments(Event_t* e)
{
  return (e != NULL) ? e->getNumEventAssignments() : SBML_INT_MAX;
}


/*
 * Creates a new EventAssignment_t object, adds it to this Event_t object and
 * returns the EventAssignment_t object created.
 */
LIBSBML_EXTERN
EventAssignment_t*
Event_createEventAssignment(Event_t* e)
{
  return (e != NULL) ? e->createEventAssignment() : NULL;
}


/*
 * Removes the nth EventAssignment_t from this Event_t and returns a pointer to
 * it.
 */
LIBSBML_EXTERN
EventAssignment_t*
Event_removeEventAssignment(Event_t* e, unsigned int n)
{
  return (e != NULL) ? e->removeEventAssignment(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * Event_t object have been set.
 */
LIBSBML_EXTERN
int
Event_hasRequiredAttributes(const Event_t * e)
{
  return (e != NULL) ? static_cast<int>(e->hasRequiredAttributes()) : 0;
}




LIBSBML_CPP_NAMESPACE_END


