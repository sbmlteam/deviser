#include <algorithm>
#include <functional>
#include <string>
#include <list>

<verbatim>
#include <xml/XMLToken.h>
#include <xml/XMLParser.h>
</verbatim>

#include <sbml/SBMLError.h>
#include <sbml/SBMLErrorLog.h>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibsbmlInternal */

/*
 * Creates a new empty SBMLErrorLog.
 */
SBMLErrorLog::SBMLErrorLog ()
{
}

/*
* Copy Constructor
*/
SBMLErrorLog::SBMLErrorLog (const SBMLErrorLog& other)
  : XMLErrorLog(other)
{
}

/*
* Assignment operator
*/
SBMLErrorLog& SBMLErrorLog::operator=(const SBMLErrorLog& other)
{
  XMLErrorLog::operator=(other);
  return *this;
}



/*
 * Used by the Destructor to delete each item in mErrors.
 */
struct Delete : public unary_function<XMLError*, void>
{
  void operator() (XMLError* error) { delete error; }
};


/*
 * Destroys this SBMLErrorLog.
 */
SBMLErrorLog::~SBMLErrorLog ()
{
}


/*
 * See SBMLError for a list of SBML_Lang error codes and XMLError
 * for a list of system and XML-level error codes.
 */
void
SBMLErrorLog::logError ( const unsigned int errorId
                       , const unsigned int level
                       , const unsigned int version
                       , const std::string& details
                       , const unsigned int line
                       , const unsigned int column
                       , const unsigned int severity
                       , const unsigned int category )
{
  add( SBMLError( errorId, level, version, details, line, column,
                  severity, category ));
}


/*
 * Adds the given SBMLError to the log.
 *
 * @param error SBMLError, the error to be logged.
 */
void
SBMLErrorLog::add (const SBMLError& error)
{
  if (error.getSeverity() != LIBSBML_SEV_NOT_APPLICABLE)
    XMLErrorLog::add(error);
}


/*
 * Logs (copies) the SBMLErrors in the given SBMLError list to this
 * SBMLErrorLog.
 *
 * @param errors list, a list of SBMLError to be added to the log.
 */
void
SBMLErrorLog::add (const std::list<SBMLError>& errors)
{
  list<SBMLError>::const_iterator end = errors.end();
  list<SBMLError>::const_iterator iter;

  for (iter = errors.begin(); iter != end; ++iter)
    XMLErrorLog::add( *iter );
}

/*
 * Logs (copies) the SBMLErrors in the given SBMLError vector to this
 * SBMLErrorLog.
 *
 * @param errors vector, a vector of SBMLError to be added to the log.
 */
void
SBMLErrorLog::add (const std::vector<SBMLError>& errors)
{
  vector<SBMLError>::const_iterator end = errors.end();
  vector<SBMLError>::const_iterator iter;

  for (iter = errors.begin(); iter != end; ++iter)
    XMLErrorLog::add( *iter );
}

/*
 * Helper class used by SBMLErrorLog::remove.
 */
class MatchErrorId
{
public:
  MatchErrorId(const unsigned int theId) : idToFind(theId) {};

  bool operator() (XMLError* e) const
  {
    return e->getErrorId() == idToFind;
  };

private:
  unsigned int idToFind;
};


/*
 * Removes an error having errorId from the SBMLError list.
 *
 * Only the first item will be removed if there are multiple errors
 * with the given errorId.
 *
 * @param errorId the error identifier of the error to be removed.
 */
void
SBMLErrorLog::remove (const unsigned int errorId)
{
  vector<XMLError*>::iterator delIter;

  // finds an item with the given errorId (the first item will be found if
  // there are two or more items with the same Id)
  delIter = find_if(mErrors.begin(), mErrors.end(), MatchErrorId(errorId));

  if ( delIter != mErrors.end() )
  {
    // deletes (invoke delete operator for the matched item) and erases (removes
    // the pointer from mErrors) the matched item (if any)
    delete *delIter;
    mErrors.erase(delIter);
  }
}

void
SBMLErrorLog::removeAll (const unsigned int errorId)
{
  vector<XMLError*>::iterator delIter;

  // finds an item with the given errorId (the first item will be found if
  // there are two or more items with the same Id)
  delIter = find_if(mErrors.begin(), mErrors.end(), MatchErrorId(errorId));

  while ( delIter != mErrors.end() )
  {
    // deletes (invoke delete operator for the matched item) and erases (removes
    // the pointer from mErrors) the matched item (if any)
    delete *delIter;
    mErrors.erase(delIter);

    delIter = find_if(mErrors.begin(), mErrors.end(), MatchErrorId(errorId));
  }
}


bool
SBMLErrorLog::contains (const unsigned int errorId) const
{
  vector<XMLError*>::const_iterator iter;

  // finds an item with the given errorId (the first item will be found if
  // there are two or more items with the same Id)
  iter = find_if(mErrors.begin(), mErrors.end(), MatchErrorId(errorId));

  if ( iter != mErrors.end() )
  {
    return true;
  }
  else
  {
    return false;
  }
}


/*
 * Helper class used by
 * SBMLErrorLog::getNumFailsWithSeverity(SBMLErrorSeverity_t).
 */
class MatchSeverity
{
public:
  MatchSeverity(const unsigned int s) : severity(s) {};

  bool operator() (XMLError* e) const
  {
    return e->getSeverity() == severity;
  };

private:
  unsigned int severity;
};

/** @endcond */


unsigned int 
SBMLErrorLog::getNumFailsWithSeverity(unsigned int severity) const
{
  unsigned int n = 0;

#if defined(__SUNPRO_CC)
  // Workaround for Sun cc which is missing:
  count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity), n);
#else
  n = (unsigned int)count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity));
#endif

  return n;
}


/*
 * Returns number of errors that are logged with severity Error
 */
unsigned int
SBMLErrorLog::getNumFailsWithSeverity(unsigned int severity)
{
  unsigned int n = 0;

#if defined(__SUNPRO_CC)
  // Workaround for Sun cc which is missing:
  count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity), n);
#else
  n = (unsigned int)count_if(mErrors.begin(), mErrors.end(), MatchSeverity(severity));
#endif

  return n;
}


/*
 * Returns the nth SBMLError in this log.
 *
 * @param n unsigned int number of the error to retrieve.
 *
 * @return the nth SBMLError in this log.
 */
const SBMLError*
SBMLErrorLog::getError (unsigned int n) const
{
  return static_cast<const SBMLError*>(XMLErrorLog::getError(n));
}


/*
 * Returns the nth SBMLError with severity in this log.
 *
 * @param n unsigned int number of the error to retrieve.
 * @param severity the severity sought
 *
 * @return the nth SBMLError in this log.
 */
const SBMLError*
SBMLErrorLog::getErrorWithSeverity(unsigned int n, unsigned int severity) const
{
  unsigned int count = 0;
  MatchSeverity matcher(severity);
  std::vector<XMLError*>::const_iterator it = mErrors.begin();
  for (; it != mErrors.end(); ++it)
  {
    if (matcher(*it))
    {
      if (count == n) return dynamic_cast<const SBMLError*>(*it);
      ++count;
    }
  }
  return NULL;
}

#endif /* __cplusplus */


/** @cond doxygenIgnored */
/** @endcond */
LIBSBML_CPP_NAMESPACE_END

