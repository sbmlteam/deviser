
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

<verbatim>
#include <sbml/xml/XMLError.h>
</verbatim>

#include <sbml/SBMLError.h>
#include <sbml/SBMLErrorTable.h>


/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibsbmlInternal **/
/** 
 * Helper function for SBMLError().  Takes an index, SBML level and version,
 * and returns the appropriate field for the severity code out of the
   LANGUAGEErrorTable entry.
 */
static const unsigned int
getSeverityForEntry(unsigned int index,
                    unsigned int level,
                    unsigned int version)
{
  if ( level == 1 )
  {
    switch (version)
    {
    case 1:
    default:
      return LANGUAGEErrorTable[index].l1v1_severity;
    }
  }
  else
  {
    return LANGUAGEErrorTable[index].l1v1_severity;
  }
}


/*
 * @return the severity as a string for the given @n code.
 */
std::string SBMLError::stringForSeverity(unsigned int code) const
{
  /* it should never happen that an error ends up with a severity
   * that is not in the XMLSeverity_t enumeration
   * but just in case:
   */
  if (code < LIBSBML_SEV_SCHEMA_ERROR)
  {
    return XMLError::stringForSeverity(code);
  }
  else
  {
    switch (code)
    {
      case LIBSBML_SEV_SCHEMA_ERROR:
        return "Schema error";
        break;

      case LIBSBML_SEV_GENERAL_WARNING:
        return "General warning";
        break;

      case LIBSBML_SEV_NOT_APPLICABLE:
        return "Not applicable";
        break;

      default:
        return "";
        break;
    }
  }
}

/*
 * Table of strings corresponding to the values from SBMLErrorCategory_t.
 * The enumeration starts at a number higher than 0, so each entry is keyed
 * by its enum value.
 *
 * A similar table for severity strings is currently unnecessary because
 * libSBML never returns anything more than the XMLSeverityCode_t values.
 */
static struct sbmlCategoryString {
  unsigned int catCode;
  const char * catString;
} sbmlCategoryStringTable[] = 
{
  { LIBSBML_CAT_SBML,                   "General SBML conformance"    },
  { LIBSBML_CAT_GENERAL_CONSISTENCY,	"SBML component consistency"  },
  { LIBSBML_CAT_IDENTIFIER_CONSISTENCY,	"SBML identifier consistency" },
  { LIBSBML_CAT_MATHML_CONSISTENCY,     "MathML consistency"          },
  { LIBSBML_CAT_INTERNAL_CONSISTENCY,   "Internal consistency"        }
};

static unsigned int sbmlCategoryStringTableSize
  = sizeof(sbmlCategoryStringTable)/sizeof(sbmlCategoryStringTable[0]);

/*
 * @return the category as a string for the given @n code.
 */
std::string SBMLError::stringForCategory(unsigned int code) const
{
  if ( code >= LIBSBML_CAT_SBML )
  {
    for ( unsigned int i = 0; i < sbmlCategoryStringTableSize; i++ )
      if ( sbmlCategoryStringTable[i].catCode == code )
        return sbmlCategoryStringTable[i].catString;
  }

  return XMLError::stringForCategory(code);
}
/** @endcond **/


SBMLError::SBMLError (  const unsigned int errorId
                      , const unsigned int level
                      , const unsigned int version 
                      , const std::string& details
                      , const unsigned int line
                      , const unsigned int column
                      , const unsigned int severity
                      , const unsigned int category) :
    XMLError((int)errorId, details, line, column, severity, category)
{
  // Check if the given @p id is one we have in our table of error codes.  If
  // it is, fill in the fields of the error object with the appropriate
  // content.  If it's not in the table, take the content as-is.

  if ( /*mErrorId >= 0 &&*/ mErrorId < XMLErrorCodesUpperBound )
  {
    // The error was caught during the XML read and the XMLError
    // constructor will have filled in all the right pieces.
    return;
  }
  else if ( mErrorId > XMLErrorCodesUpperBound
            && mErrorId < SBMLCodesUpperBound )
  {
    unsigned int tableSize = sizeof(LANGUAGEErrorTable)/sizeof(LANGUAGEErrorTable[0]);
    unsigned int index = 0;

    for ( unsigned int i = 0; i < tableSize; i++ )
    {
      if ( mErrorId == LANGUAGEErrorTable[i].code )
      {
        index = i;
        break;
      }
    }

    if ( index == 0 && mErrorId != SBMLUnknownError )
    {
      // The id is in the range of error numbers that are supposed to be in
      // the SBML layer, but it's NOT in our table. This is an internal error.
      // Unfortunately, we don't have an error log or anywhere to report it
      // except the measure of last resort: the standard error output.
    
      //cerr << "Internal error: unknown error code '" << mErrorId
      //     << "' encountered while processing error." << endl;
      //return;
      // Changed this behaviour

      // Now we log the error as an UnKnown Error and mark it as invalid

      mValidError = false;
    }

    // The rest of this block massages the results to account for how some
    // internal bookkeeping is done in libSBML 3, and also to provide
    // additional info in the messages.

    mCategory     = LANGUAGEErrorTable[index].category;
    mShortMessage = LANGUAGEErrorTable[index].shortMessage;

    ostringstream newMsg;
    mSeverity = getSeverityForEntry(index, level, version);

    if (mValidError == false)
      mSeverity = LIBSBML_SEV_WARNING;

    if (mSeverity == LIBSBML_SEV_SCHEMA_ERROR)
    {
      mErrorId  = NotSchemaConformant;
      mSeverity = LIBSBML_SEV_ERROR;
      newMsg << LANGUAGEErrorTable[3].message << " "; // FIXME
    }
    else if (mSeverity == LIBSBML_SEV_GENERAL_WARNING)
    {

      mSeverity = LIBSBML_SEV_WARNING;
      newMsg << "[Although SBML Level " << level
             << " Version " << version << " does not explicitly define the "
             << "following as an error, other Levels and/or Versions "
             << "of SBML do.] " << endl;
    }

    // Finish updating the (full) error message.

    if (!((string)LANGUAGEErrorTable[index].message).empty()) {
      newMsg << LANGUAGEErrorTable[index].message << endl;
    }

    // look for individual references
    // if the code for this error does not yet exist skip

    if (LANGUAGEErrorTable[index].reference.ref_l1v1 != NULL)
    {

      std::string ref;
      switch(level)
      {
      case 1:
      default:
       switch(version)
        {
        case 1:
        default:
          ref = LANGUAGEErrorTable[index].reference.ref_l1v1;
        break;
        }
       break;
      }

      if (!ref.empty())
      {
        newMsg << "Reference: " << ref << endl;
      }
    }
    if (!details.empty())
    {
      newMsg << " " << details;
      if (details[details.size()-1] != '\n') {
        newMsg << endl;
      }
    }      
    mMessage  = newMsg.str();

    // We mucked around with the severity code and (maybe) category code
    // after creating the XMLError object, so we may have to update the
    // corresponding strings.

    mSeverityString = stringForSeverity(mSeverity);
    mCategoryString = stringForCategory(mCategory);

    return;
  }


   // It's not an error code in the SBML layer, so assume the caller has
  // filled in all the relevant additional data.  (If they didn't, the
  // following merely assigns the defaults.)
  mMessage        = details;
  mSeverity       = severity;
  mCategory       = category;
  mSeverityString = stringForSeverity(mSeverity);
  mCategoryString = stringForCategory(mCategory);
}


/*
 * Copy Constructor
 */
SBMLError::SBMLError(const SBMLError& orig) :
 XMLError(orig)
{
}


 /*
 * Destroys this SBMLError.
 */
SBMLError::~SBMLError ()
{
}


/** @cond doxygenLibsbmlInternal **/
/*
 * clone function
 */
SBMLError* 
SBMLError::clone() const
{
  return new SBMLError(*this);
}
/** @endcond **/


/** @cond doxygenLibsbmlInternal **/
/*
 * Outputs this SBMLError to stream in the following format (and followed by
 * a newline):
 *
 *   line: (error_id [severity]) message
 */
void
SBMLError::print(ostream& s) const
{
    s << "line " << getLine() << ": ("
      << setfill('0') << setw(5) << getErrorId()
      << " [" << getSeverityAsString() << "]) "
      << getMessage() << endl;
}
/** @endcond **/


#endif /* __cplusplus */

LIBSBML_CPP_NAMESPACE_END

