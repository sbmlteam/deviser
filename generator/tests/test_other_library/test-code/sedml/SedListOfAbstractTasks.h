/**
 * @file SedListOfAbstractTasks.h
 * @brief Definition of the SedListOfAbstractTasks class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedListOfAbstractTasks
 * @sbmlbrief{sedml} TODO:Definition of the SedListOfAbstractTasks class.
 */


#ifndef SedListOfAbstractTasks_H__
#define SedListOfAbstractTasks_H__


#include <sedml/common/extern.h>
#include <sedml/common/sedmlfwd.h>


#ifdef __cplusplus


#include <string>


#include <sedml/SedListOf.h>
#include <sedml/SedAbstractTask.h>
#include <sbml/common/libsbml-namespace.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


class SedTask;
class SedRepeatedTask;
class SedParameterEstimationTask;
class SedSimpleRepeatedTask;

class LIBSEDML_EXTERN SedListOfAbstractTasks : public SedListOf
{
protected:

  /** @cond doxygenLibSEDMLInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SedListOfAbstractTasks using the given SEDML Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SEDML Level to assign to this
   * SedListOfAbstractTasks.
   *
   * @param version an unsigned int, the SEDML Version to assign to this
   * SedListOfAbstractTasks.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfAbstractTasks(unsigned int level = SEDML_DEFAULT_LEVEL,
                         unsigned int version = SEDML_DEFAULT_VERSION);


  /**
   * Creates a new SedListOfAbstractTasks using the given SedNamespaces object
   * @p sedmlns.
   *
   * @param sedmlns the SedNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SedListOfAbstractTasks(SedNamespaces *sedmlns);


  /**
   * Copy constructor for SedListOfAbstractTasks.
   *
   * @param orig the SedListOfAbstractTasks instance to copy.
   */
  SedListOfAbstractTasks(const SedListOfAbstractTasks& orig);


  /**
   * Assignment operator for SedListOfAbstractTasks.
   *
   * @param rhs the SedListOfAbstractTasks object whose values are to be used
   * as the basis of the assignment.
   */
  SedListOfAbstractTasks& operator=(const SedListOfAbstractTasks& rhs);


  /**
   * Creates and returns a deep copy of this SedListOfAbstractTasks object.
   *
   * @return a (deep) copy of this SedListOfAbstractTasks object.
   */
  virtual SedListOfAbstractTasks* clone() const;


  /**
   * Destructor for SedListOfAbstractTasks.
   */
  virtual ~SedListOfAbstractTasks();


  /**
   * Get a SedAbstractTask from the SedListOfAbstractTasks.
   *
   * @param n an unsigned int representing the index of the SedAbstractTask to
   * retrieve.
   *
   * @return the nth SedAbstractTask in this SedListOfAbstractTasks.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAbstractTask* get(unsigned int n);


  /**
   * Get a SedAbstractTask from the SedListOfAbstractTasks.
   *
   * @param n an unsigned int representing the index of the SedAbstractTask to
   * retrieve.
   *
   * @return the nth SedAbstractTask in this SedListOfAbstractTasks.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAbstractTask* get(unsigned int n) const;


  /**
   * Get a SedAbstractTask from the SedListOfAbstractTasks based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractTask to
   * retrieve.
   *
   * @return the SedAbstractTask in this SedListOfAbstractTasks with the given
   * @p sid or @c NULL if no such SedAbstractTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SedAbstractTask* get(const std::string& sid);


  /**
   * Get a SedAbstractTask from the SedListOfAbstractTasks based on its
   * identifier.
   *
   * @param sid a string representing the identifier of the SedAbstractTask to
   * retrieve.
   *
   * @return the SedAbstractTask in this SedListOfAbstractTasks with the given
   * @p sid or @c NULL if no such SedAbstractTask exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SedAbstractTask* get(const std::string& sid) const;


  /**
   * Removes the nth SedAbstractTask from this SedListOfAbstractTasks and
   * returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SedAbstractTask to
   * remove.
   *
   * @return a pointer to the nth SedAbstractTask in this
   * SedListOfAbstractTasks.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   */
  virtual SedAbstractTask* remove(unsigned int n);


  /**
   * Removes the SedAbstractTask from this SedListOfAbstractTasks based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SedAbstractTask to
   * remove.
   *
   * @return the SedAbstractTask in this SedListOfAbstractTasks based on the
   * identifier or NULL if no such SedAbstractTask exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(unsigned int n)
   */
  virtual SedAbstractTask* remove(const std::string& sid);


  /**
   * Adds a copy of the given SedAbstractTask to this SedListOfAbstractTasks.
   *
   * @param sat the SedAbstractTask object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sedmlconstant{LIBSEDML_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sedmlconstant{LIBSEDML_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addAbstractTask(const SedAbstractTask* sat);


  /**
   * Get the number of SedAbstractTask objects in this SedListOfAbstractTasks.
   *
   * @return the number of SedAbstractTask objects in this
   * SedListOfAbstractTasks.
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see createAbstractTask()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumAbstractTasks() const;


  /**
   * Creates a new SedTask object, adds it to this SedListOfAbstractTasks
   * object and returns the SedTask object created.
   *
   * @return a new SedTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedTask* createTask();


  /**
   * Creates a new SedRepeatedTask object, adds it to this
   * SedListOfAbstractTasks object and returns the SedRepeatedTask object
   * created.
   *
   * @return a new SedRepeatedTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedRepeatedTask* createRepeatedTask();


  /**
   * Creates a new SedParameterEstimationTask object, adds it to this
   * SedListOfAbstractTasks object and returns the SedParameterEstimationTask
   * object created.
   *
   * @return a new SedParameterEstimationTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedParameterEstimationTask* createParameterEstimationTask();


  /**
   * Creates a new SedSimpleRepeatedTask object, adds it to this
   * SedListOfAbstractTasks object and returns the SedSimpleRepeatedTask object
   * created.
   *
   * @return a new SedSimpleRepeatedTask object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addAbstractTask(const SedAbstractTask* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumAbstractTasks()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SedSimpleRepeatedTask* createSimpleRepeatedTask();


  /**
   * Returns the XML element name of this SedListOfAbstractTasks object.
   *
   * For SedListOfAbstractTasks, the XML element name is always
   * @c "listOfAbstractTasks".
   *
   * @return the name of this element, i.e. @c "listOfAbstractTasks".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Sets the XML name of this SedListOfAbstractTasks object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSEDML type code for this SedListOfAbstractTasks object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML type code for this object:
   * @sedmlconstant{SEDML_LIST_OF, SEDMLTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSEDML type code for the SEDML objects contained in this
   * SedListOfAbstractTasks object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SEDML typecode for the objects contained in this
   * SedListOfAbstractTasks:
   * @sedmlconstant{SEDML_SEDML_ABSTRACTTASK, SEDMLSedmlTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenLibSEDMLInternal */

  /**
   * Creates a new SedAbstractTask in this SedListOfAbstractTasks
   */
  virtual SedBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
    stream);

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * Writes the namespace for the Sedml package
   */
  virtual void writeXMLNS(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenLibSEDMLInternal */

  /**
   * checks concrete types
   */
  virtual bool isValidTypeForList(SedBase* item);

  /** @endcond */


};



LIBSEDML_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SedAbstractTask_t from the SedListOf_t.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractTask_t to
 * retrieve.
 *
 * @return the nth SedAbstractTask_t in this SedListOf_t.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfAbstractTasks_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfAbstractTasks_getAbstractTask(SedListOf_t* slo, unsigned int n);


/**
 * Get a SedAbstractTask_t from the SedListOf_t based on its identifier.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractTask_t to
 * retrieve.
 *
 * @return the SedAbstractTask_t in this SedListOf_t with the given @p sid or
 * @c NULL if no such SedAbstractTask_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SedListOfAbstractTasks_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfAbstractTasks_getById(SedListOf_t* slo, const char *sid);


/**
 * Removes the nth SedAbstractTask_t from this SedListOf_t and returns a
 * pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SedAbstractTask_t to
 * remove.
 *
 * @return a pointer to the nth SedAbstractTask_t in this SedListOf_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedListOfAbstractTasks_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfAbstractTasks_remove(SedListOf_t* slo, unsigned int n);


/**
 * Removes the SedAbstractTask_t from this SedListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SedListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SedAbstractTask_t to
 * remove.
 *
 * @return the SedAbstractTask_t in this SedListOf_t based on the identifier or
 * NULL if no such SedAbstractTask_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SedListOfAbstractTasks_t
 */
LIBSEDML_EXTERN
SedAbstractTask_t*
SedListOfAbstractTasks_removeById(SedListOf_t* slo, const char* sid);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SedListOfAbstractTasks_H__ */


