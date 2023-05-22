/**
 * @file TSBErrorLog.h
 * @brief Definition of the TSBErrorLog class.
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
 * @class TSBErrorLog
 * @sbmlbrief{} TODO:Definition of the TSBErrorLog class.
 */


#ifndef TSBErrorLog_h
#define TSBErrorLog_h


#include <tsb/common/extern.h>
#include <xml/XMLError.h>
#include <xml/XMLErrorLog.h>
#include <tsb/TSBError.h>


#ifdef __cplusplus

#include <vector>

LIBTSB_CPP_NAMESPACE_BEGIN

class LIBTSB_EXTERN TSBErrorLog : public XMLErrorLog
{
public:

  /**
   * Returns the <i>n</i>th TSBError object in this log.
   *
   * Index @p n is counted from 0.  Callers should first inquire about the
   * number of items in the log by using the
   * @if java XMLErrorLog::getNumErrors()@else getNumErrors()@endif@~ method.
   * Attempts to use an error index number that exceeds the actual number
   * of errors in the log will result in a @c NULL being returned.
   *
   * @param n the index number of the error to retrieve (with 0 being the
   * first error).
   *
   * @return the <i>n</i>th TSBError in this log, or @c NULL if @p n is
   * greater than or equal to
   * @if java XMLErrorLog::getNumErrors()@else getNumErrors()@endif.
   *
   * @see getNumErrors()
   */
  const TSBError* getError (unsigned int n) const;


  /**
   * Returns the <i>n</i>th TSBError object with given severity in this log.
   *
   * Index @p n is counted from 0.  Callers should first inquire about the
   * number of items in the log by using the
   * @if java TSBErrorLog::getNumFailsWithSeverity(long severity)@else getNumFailsWithSeverity()@endif@~ method.
   * Attempts to use an error index number that exceeds the actual number
   * of errors in the log will result in a @c NULL being returned.
   *
   * @param n the index number of the error to retrieve (with 0 being the
   * first error).
   * @param severity the severity of the error to retrieve 
   *
   * @return the <i>n</i>th TSBError in this log, or @c NULL if @p n is
   * greater than or equal to
   * @if java TSBErrorLog::getNumFailsWithSeverity(long severity)@else getNumFailsWithSeverity()@endif.
   *
   * @see getNumFailsWithSeverity(unsigned int severity)
   */
  const TSBError* getErrorWithSeverity(unsigned int n, unsigned int severity) const;


  /**
   * Returns the number of errors that have been logged with the given
   * severity code.
   *
   * @if clike @param severity a value from
   * #TSBErrorSeverity_t @endif@if java @param severity a
   * value from the set of <code>LIBTSB_SEV_</code> constants defined by
   * the interface class <code><a
   * href="libtsbConstants.html">libtsbConstants</a></code> @endif@if python @param severity a
   * value from the set of <code>LIBTSB_SEV_</code> constants defined by
   * the interface class @link libtsb libtsb@endlink. @endif@~
   *
   * @return a count of the number of errors with the given severity code.
   *
   * @see getNumErrors()
   */
  unsigned int getNumFailsWithSeverity(unsigned int severity);


   /**
   * Returns the number of errors that have been logged with the given
   * severity code.
   *
   * @if clike @param severity a value from
   * #TSBErrorSeverity_t @endif@if java @param severity a
   * value from the set of <code>LIBTSB_SEV_</code> constants defined by
   * the interface class <code><a
   * href="libtsbConstants.html">libtsbConstants</a></code> @endif@if python @param severity a
   * value from the set of <code>LIBTSB_SEV_</code> constants defined by
   * the interface class @link libtsb libtsb@endlink. @endif@~
   *
   * @return a count of the number of errors with the given severity code.
   *
   * @see getNumErrors()
   */
  unsigned int getNumFailsWithSeverity(unsigned int severity) const;


  /** @cond doxygenLibtsbInternal */
  
  /**
   * Creates a new, empty TSBErrorLog.
   */
  TSBErrorLog ();


  /**
   * Copy Constructor
   */
  TSBErrorLog (const TSBErrorLog& other);


  /**
   * Assignment operator for TSBErrorLog
   */
  TSBErrorLog& operator=(const TSBErrorLog& other);


  /**
   * Destroys this TSBErrorLog.
   */
  virtual ~TSBErrorLog ();


  /**
   * Convenience function that combines creating an TSBError object and
   * adding it to the log.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level an unsigned int, the TSB Level
   *
   * @param version an unsigned int, the TSB Level's Version
   * 
   * @param details a string containing additional details about the error.
   * If the error code in @p errorId is one that is recognized by TSBError,
   * the given message is @em appended to a predefined message associated
   * with the given code.  If the error code is not recognized, the message
   * is stored as-is as the text of the error.
   * 
   * @param line an unsigned int, the line number at which the error occured.
   * 
   * @param column an unsigned int, the column number at which the error occured.
   * 
   * @param severity an integer indicating severity of the error.
   * 
   * @param category an integer indicating the category to which the error
   * belongs.
   */
  void logError
  (
      const unsigned int errorId  = 0
    , const unsigned int level    = TSB_DEFAULT_LEVEL
    , const unsigned int version  = TSB_DEFAULT_VERSION
    , const std::string& details  = ""
    , const unsigned int line     = 0
    , const unsigned int column   = 0
    , const unsigned int severity = LIBTSB_SEV_ERROR
    , const unsigned int category = LIBTSB_CAT_TSB
  );


  /**
   * Adds the given TSBError to the log.
   *
   * @param error TSBError, the error to be logged.
   */
  void add (const TSBError& error);


  /** @cond doxygenCppOnly */

  /**
   * Adds (copies) the TSBErrors in the given TSBError list to this
   * TSBErrorLog.
   *
   * @param errors list, a list of TSBError to be added to the log.
   */
  void add (const std::list<TSBError>& errors);


  /**
   * Adds (copies) the TSBErrors in the given TSBError vector to this
   * TSBErrorLog.
   *
   * @param errors vector, a vector of TSBError to be added to the log.
   */
  void add (const std::vector<TSBError>& errors);

  /** @endcond */


  /**
   * Removes an error having errorId from the TSBError list.
   *  
   * Only the first item will be removed if there are multiple errors
   * with the given errorId.
   *
   * @param errorId the error identifier of the error to be removed.
   */
  void remove (const unsigned int errorId);


  /**
   * Removes all errors having errorId from the TSBError list.
   *
   * @param errorId the error identifier of the error to be removed.
   */
  void removeAll(const unsigned int errorId);

  /**
   * Returns true if TSBErrorLog contains an errorId
   *
   * @param errorId the error identifier of the error to be found.
   */
  bool contains (const unsigned int errorId) const;


  /** @endcond */
};

LIBTSB_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* TSBErrorLog_h */
