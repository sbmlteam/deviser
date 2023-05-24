/**
 * @file TSBError.cpp
 * @brief Implementation of the TSBError class.
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
 */



#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <xml/XMLError.h>

#include <tsb/TSBError.h>
#include <tsb/TSBErrorTable.h>


/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBTSB_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibtsbInternal **/
/** 
 * Helper function for TSBError().  Takes an index, TSB level and version,
 * and returns the appropriate field for the severity code out of the
   tsbErrorTable entry.
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
      return tsbErrorTable[index].l1v1_severity;
    }
  }
  else
  {
    return tsbErrorTable[index].l1v1_severity;
  }
}


/*
 * @return the severity as a string for the given @n code.
 */
std::string TSBError::stringForSeverity(unsigned int code) const
{
  /* it should never happen that an error ends up with a severity
   * that is not in the XMLSeverity_t enumeration
   * but just in case:
   */
  if (code < LIBTSB_SEV_SCHEMA_ERROR)
  {
    return XMLError::stringForSeverity(code);
  }
  else
  {
    switch (code)
    {
      case LIBTSB_SEV_SCHEMA_ERROR:
        return "Schema error";
        break;

      case LIBTSB_SEV_GENERAL_WARNING:
        return "General warning";
        break;

      case LIBTSB_SEV_NOT_APPLICABLE:
        return "Not applicable";
        break;

      default:
        return "";
        break;
    }
  }
}

/*
 * Table of strings corresponding to the values from TSBErrorCategory_t.
 * The enumeration starts at a number higher than 0, so each entry is keyed
 * by its enum value.
 *
 * A similar table for severity strings is currently unnecessary because
 * libTSB never returns anything more than the XMLSeverityCode_t values.
 */
static struct tsbCategoryString {
  unsigned int catCode;
  const char * catString;
} tsbCategoryStringTable[] = 
{
  { LIBTSB_CAT_TSB,                   "General TSB conformance"    },
  { LIBTSB_CAT_GENERAL_CONSISTENCY,	"TSB component consistency"  },
  { LIBTSB_CAT_IDENTIFIER_CONSISTENCY,	"TSB identifier consistency" },
  { LIBTSB_CAT_MATHML_CONSISTENCY,     "MathML consistency"          },
  { LIBTSB_CAT_INTERNAL_CONSISTENCY,   "Internal consistency"        }
};

static unsigned int tsbCategoryStringTableSize
  = sizeof(tsbCategoryStringTable)/sizeof(tsbCategoryStringTable[0]);

/*
 * @return the category as a string for the given @n code.
 */
std::string TSBError::stringForCategory(unsigned int code) const
{
  if ( code >= LIBTSB_CAT_TSB )
  {
    for ( unsigned int i = 0; i < tsbCategoryStringTableSize; i++ )
      if ( tsbCategoryStringTable[i].catCode == code )
        return tsbCategoryStringTable[i].catString;
  }

  return XMLError::stringForCategory(code);
}
/** @endcond **/


TSBError::TSBError (  const unsigned int errorId
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
            && mErrorId < TSBCodesUpperBound )
  {
    unsigned int tableSize = sizeof(tsbErrorTable)/sizeof(tsbErrorTable[0]);
    unsigned int index = 0;

    for ( unsigned int i = 0; i < tableSize; i++ )
    {
      if ( mErrorId == tsbErrorTable[i].code )
      {
        index = i;
        break;
      }
    }

    if ( index == 0 && mErrorId != TSBUnknown )
    {
      // The id is in the range of error numbers that are supposed to be in
      // the TSB layer, but it's NOT in our table. This is an internal error.
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
    // internal bookkeeping is done in libTSB 3, and also to provide
    // additional info in the messages.

    mCategory     = tsbErrorTable[index].category;
    mShortMessage = tsbErrorTable[index].shortMessage;

    ostringstream newMsg;
    mSeverity = getSeverityForEntry(index, level, version);

    if (mValidError == false)
      mSeverity = LIBTSB_SEV_WARNING;

    if (mSeverity == LIBTSB_SEV_SCHEMA_ERROR)
    {
      mErrorId  = TSBNotSchemaConformant;
      mSeverity = LIBTSB_SEV_ERROR;
      newMsg << tsbErrorTable[3].message << " "; // FIXME
    }
    else if (mSeverity == LIBTSB_SEV_GENERAL_WARNING)
    {

      mSeverity = LIBTSB_SEV_WARNING;
      newMsg << "[Although TSB Level " << level
             << " Version " << version << " does not explicitly define the "
             << "following as an error, other Levels and/or Versions "
             << "of TSB do.] " << endl;
    }

    // Finish updating the (full) error message.

    if (!((string)tsbErrorTable[index].message).empty()) {
      newMsg << tsbErrorTable[index].message << endl;
    }

    // look for individual references
    // if the code for this error does not yet exist skip

    if (tsbErrorTable[index].reference.ref_l1v1 != NULL)
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
          ref = tsbErrorTable[index].reference.ref_l1v1;
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


   // It's not an error code in the TSB layer, so assume the caller has
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
TSBError::TSBError(const TSBError& orig) :
 XMLError(orig)
{
}


 /*
 * Destroys this TSBError.
 */
TSBError::~TSBError ()
{
}


/** @cond doxygenLibtsbInternal **/
/*
 * clone function
 */
TSBError* 
TSBError::clone() const
{
  return new TSBError(*this);
}
/** @endcond **/


/** @cond doxygenLibtsbInternal **/
/*
 * Outputs this TSBError to stream in the following format (and followed by
 * a newline):
 *
 *   line: (error_id [severity]) message
 */
void
TSBError::print(ostream& s) const
{
    s << "line " << getLine() << ": ("
      << setfill('0') << setw(5) << getErrorId()
      << " [" << getSeverityAsString() << "]) "
      << getMessage() << endl;
}
/** @endcond **/


#endif /* __cplusplus */

LIBTSB_CPP_NAMESPACE_END

