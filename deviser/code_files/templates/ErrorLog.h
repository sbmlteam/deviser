#ifndef SBMLErrorLog_h
#define SBMLErrorLog_h


#include <sbml/common/extern.h>
<verbatim>
#include <xml/XMLError.h>
#include <xml/XMLErrorLog.h>
</verbatim>
#include <sbml/SBMLError.h>


#ifdef __cplusplus

#include <vector>

LIBSBML_CPP_NAMESPACE_BEGIN

class LIBSBML_EXTERN SBMLErrorLog : public XMLErrorLog
{
public:

  /**
   * Returns the <i>n</i>th SBMLError object in this log.
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
   * @return the <i>n</i>th SBMLError in this log, or @c NULL if @p n is
   * greater than or equal to
   * @if java XMLErrorLog::getNumErrors()@else getNumErrors()@endif.
   *
   * @see getNumErrors()
   */
  const SBMLError* getError (unsigned int n) const;


  /**
   * Returns the <i>n</i>th SBMLError object with given severity in this log.
   *
   * Index @p n is counted from 0.  Callers should first inquire about the
   * number of items in the log by using the
   * @if java SBMLErrorLog::getNumFailsWithSeverity(long severity)@else getNumFailsWithSeverity()@endif@~ method.
   * Attempts to use an error index number that exceeds the actual number
   * of errors in the log will result in a @c NULL being returned.
   *
   * @param n the index number of the error to retrieve (with 0 being the
   * first error).
   * @param severity the severity of the error to retrieve 
   *
   * @return the <i>n</i>th SBMLError in this log, or @c NULL if @p n is
   * greater than or equal to
   * @if java SBMLErrorLog::getNumFailsWithSeverity(long severity)@else getNumFailsWithSeverity()@endif.
   *
   * @see getNumFailsWithSeverity(unsigned int severity)
   */
  const SBMLError* getErrorWithSeverity(unsigned int n, unsigned int severity) const;


  /**
   * Returns the number of errors that have been logged with the given
   * severity code.
   *
   * @if clike @param severity a value from
   * #SBMLErrorSeverity_t @endif@if java @param severity a
   * value from the set of <code>LIBSBML_SEV_</code> constants defined by
   * the interface class <code><a
   * href="libsbmlConstants.html">libsbmlConstants</a></code> @endif@if python @param severity a
   * value from the set of <code>LIBSBML_SEV_</code> constants defined by
   * the interface class @link libsbml libsbml@endlink. @endif@~
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
   * #SBMLErrorSeverity_t @endif@if java @param severity a
   * value from the set of <code>LIBSBML_SEV_</code> constants defined by
   * the interface class <code><a
   * href="libsbmlConstants.html">libsbmlConstants</a></code> @endif@if python @param severity a
   * value from the set of <code>LIBSBML_SEV_</code> constants defined by
   * the interface class @link libsbml libsbml@endlink. @endif@~
   *
   * @return a count of the number of errors with the given severity code.
   *
   * @see getNumErrors()
   */
  unsigned int getNumFailsWithSeverity(unsigned int severity) const;


  /** @cond doxygenLibsbmlInternal */
  
  /**
   * Creates a new, empty SBMLErrorLog.
   */
  SBMLErrorLog ();


  /**
   * Copy Constructor
   */
  SBMLErrorLog (const SBMLErrorLog& other);


  /**
   * Assignment operator for SBMLErrorLog
   */
  SBMLErrorLog& operator=(const SBMLErrorLog& other);


  /**
   * Destroys this SBMLErrorLog.
   */
  virtual ~SBMLErrorLog ();


  /**
   * Convenience function that combines creating an SBMLError object and
   * adding it to the log.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level an unsigned int, the SBML_Lang Level
   *
   * @param version an unsigned int, the SBML_Lang Level's Version
   * 
   * @param details a string containing additional details about the error.
   * If the error code in @p errorId is one that is recognized by SBMLError,
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
    , const unsigned int level    = SBML_DEFAULT_LEVEL
    , const unsigned int version  = SBML_DEFAULT_VERSION
    , const std::string& details  = ""
    , const unsigned int line     = 0
    , const unsigned int column   = 0
    , const unsigned int severity = LIBSBML_SEV_ERROR
    , const unsigned int category = LIBSBML_CAT_SBML
  );


  /**
   * Adds the given SBMLError to the log.
   *
   * @param error SBMLError, the error to be logged.
   */
  void add (const SBMLError& error);


  /** @cond doxygenCppOnly */

  /**
   * Adds (copies) the SBMLErrors in the given SBMLError list to this
   * SBMLErrorLog.
   *
   * @param errors list, a list of SBMLError to be added to the log.
   */
  void add (const std::list<SBMLError>& errors);


  /**
   * Adds (copies) the SBMLErrors in the given SBMLError vector to this
   * SBMLErrorLog.
   *
   * @param errors vector, a vector of SBMLError to be added to the log.
   */
  void add (const std::vector<SBMLError>& errors);

  /** @endcond */


  /**
   * Removes an error having errorId from the SBMLError list.
   *  
   * Only the first item will be removed if there are multiple errors
   * with the given errorId.
   *
   * @param errorId the error identifier of the error to be removed.
   */
  void remove (const unsigned int errorId);


  /**
   * Removes all errors having errorId from the SBMLError list.
   *
   * @param errorId the error identifier of the error to be removed.
   */
  void removeAll(const unsigned int errorId);

  /**
   * Returns true if SBMLErrorLog contains an errorId
   *
   * @param errorId the error identifier of the error to be found.
   */
  bool contains (const unsigned int errorId) const;


  /** @endcond */
};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* SBMLErrorLog_h */
