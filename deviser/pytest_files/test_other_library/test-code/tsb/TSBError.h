/**
 * @file TSBError.h
 * @brief Definition of the TSBError class.
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


#ifndef TSBError_h
#define TSBError_h

#include <tsb/common/extern.h>
#include <xml/XMLError.h>
#include <tsb/TSBNamespaces.h>


LIBTSB_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * @enum TSBErrorCode_t
 * Codes for all TSB-level errors and warnings from the core specification.
 */
typedef enum
{
  TSBUnknown                      = 10000 /*!< Encountered unknown internal libTSB error. */
, TSBNotUTF8                               = 10001 /*!< File does not use UTF-8 encoding. */
, TSBUnrecognizedElement                   = 10002 /*!< Encountered unrecognized element. */
, TSBNotSchemaConformant                   = 10003 /*!< Document does not conform to the TSB XML schema. */
, TSBInvalidMathElement                    = 10201
, TSBMissingTestAnnotationNamespace            = 10401 /*!< Missing declaration of the XML namespace for the annotation. */
, TSBDuplicateTestAnnotationNamespaces         = 10402 /*!< Multiple annotations using the same XML namespace. */
, TSBNamespaceInTestAnnotation             = 10403 /*!< The TSB XML namespace cannot be used in an TestAnnotation object. */
, TSBMultipleTestAnnotations                   = 10404 /*!< Only one TestAnnotation object is permitted under a given TSB object. */
, TSBTestAnnotationNotElement                  = 10405
, TSBNotesNotInXHTMLNamespace              = 10801 /*!< Notes must be placed in the XHTML XML namespace. */
, TSBNotesContainsXMLDecl                  = 10802 /*!< XML declarations are not permitted in Notes objects. */
, TSBNotesContainsDOCTYPE                  = 10803 /*!< XML DOCTYPE elements are not permitted in Notes objects. */
, TSBInvalidNotesContent                   = 10804 /*!< Invalid notes content found. */
, TSBOnlyOneNotesElementAllowed            = 10805 /*!< Only one Notes subobject is permitted on a given TSB object. */
, TsbNSUndeclared      = 10101
, TsbElementNotInNs      = 10102
, TsbDuplicateComponentId      = 10301
, TsbIdSyntaxRule      = 10302
, TSBInvalidMetaidSyntax      = 10303
, InvalidNamespaceOnTSB      = 20101
, AllowedAttributes      = 20102
, TSBEmptyListElement      = 20103
, TsbDocumentAllowedCoreAttributes      = 20201
, TsbDocumentAllowedCoreElements      = 20202
, TsbDocumentAllowedAttributes      = 20203
, TsbDocumentAllowedElements      = 20204
, TsbDocumentLevelMustBeNonNegativeInteger      = 20205
, TsbDocumentVersionMustBeNonNegativeInteger      = 20206
, TsbDocumentLOCommentsAllowedCoreElements      = 20207
, TsbDocumentLOCommentsAllowedCoreAttributes      = 20208
, TsbCommentAllowedCoreAttributes      = 20301
, TsbCommentAllowedCoreElements      = 20302
, TsbCommentAllowedAttributes      = 20303
, TsbCommentContributorMustBeString      = 20304
, TsbCommentNumberMustBeDouble      = 20305
, TsbCommentPointMustBeString      = 20306
, TSBUnknownCoreAttribute                  = 99994 /*!< Encountered an unknown attribute in the TSB Core namespace. */
, TSBCodesUpperBound                   = 99999 /*!< Upper boundary of libTSB-specific diagnostic codes. */
} TSBErrorCode_t;


/**
 * @enum TSBErrorCategory_t
 * Category codes for TSBError diagnostics.
 *
 * Note that these are distinct from XMLError's category codes.  User
 * programs receiving an TSBError object can use this distinction to
 * check whether the error represents a low-level XML problem or an
 * TSB problem.
 *
 * @see #XMLErrorCategory_t
 */
typedef enum
{
    LIBTSB_CAT_INTERNAL = 1,
    LIBTSB_CAT_SYSTEM = 2,
    LIBTSB_CAT_XML = 3,

    LIBTSB_CAT_TSB = (LIBTSB_CAT_XML + 1)
    /*!< General TSB error  not falling into another category below. */

  , LIBTSB_CAT_GENERAL_CONSISTENCY
    /*!< Category of errors that can occur while validating general TSB
     * constructs. */

  , LIBTSB_CAT_IDENTIFIER_CONSISTENCY
    /*!< Category of errors that can occur while validating symbol
     * identifiers in a model. */

  , LIBTSB_CAT_MATHML_CONSISTENCY
    /*!< Category of errors that can occur while validating MathML formulas
     * in a model.  With respect to the TSB specification, these concern
     * failures in applying the validation rules numbered 102xx in the
     * Level&nbsp;2 Versions&nbsp;2&ndash;4
     * and Level&nbsp;3 Version&nbsp;1 specifications. */

  , LIBTSB_CAT_INTERNAL_CONSISTENCY
    /*!< Category of errors that can occur while validating libTSB's
     * internal representation of TSB constructs. (These are tests
     * performed by libTSB and do not have equivalent TSB validation
     * rules.)  */

} TSBErrorCategory_t;


/**
 * @enum TSBErrorSeverity_t
 * Severity codes for TSBError diagnostics.
 *
 * The only publicly-reported values of this type are the four from #XMLErrorSeverity_t.
 * All other values are used internally only, with translation of those
 * codes done in TSBError.cpp
 *
 * @see XMLErrorSeverity_t
 */
typedef enum
{
  /** @cond doxygenLibtsbInternal **/

  /* The following are used internally in TSBErrorTable, but publicly,
   * we only report one of the 4 XMLError_Severity values.  Translation
   * of the codes is done in TSBError.cpp.
   */
    LIBTSB_SEV_WARNING = 1,
    LIBTSB_SEV_ERROR = 2,
    LIBTSB_SEV_FATAL = 3,

    LIBTSB_SEV_SCHEMA_ERROR    = (LIBTSB_SEV_FATAL + 1)
    /*!< The XML content does not conform to
     * the relevant version of the TSB XML
     * Schema.  The content is not valid TSB. */

  , LIBTSB_SEV_GENERAL_WARNING
    /*!< The XML content is invalid for some
     * levels/versions of TSB, and while it
     * may be valid in others, it is something
     * that is best avoided anyway.  LibTSB
     * will issue warnings in those cases it
     * can recognize. */

  , LIBTSB_SEV_NOT_APPLICABLE
    /*!< This error code is only a placeholder
     * for errors that have relevance to some
     * versions of TSB but not others. */

  /** @endcond **/
} TSBErrorSeverity_t;

END_C_DECLS
LIBTSB_CPP_NAMESPACE_END

#ifdef __cplusplus

LIBTSB_CPP_NAMESPACE_BEGIN

class LIBTSB_EXTERN TSBError : public XMLError
{
public:

  /**
   * Creates a new TSBError to report that something occurred during TSB
   * processing.
   *
   * When a libTSB operation on TSB content results in a warning, error
   * or other diagnostic, the issue is reported as an TSBError object.
   * TSBError objects have identification numbers to indicate the nature
   * of the exception.  @if clike These numbers are drawn from
   * the enumeration <a class="el"
   * href="#TSBErrorCode_t">
   * TSBErrorCode_t</a>.  @endif@if java These numbers are
   * defined as unsigned integer constants in the file
   * "libtsbConstants.html".  See the <a class="el"
   * href="#TSBErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@if python These
   * numbers are defined as unsigned integer constants in the interface
   * class @link libtsb libtsb@endlink.  See the <a class="el"
   * href="#TSBErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@~ The argument
   * @p errorId to this constructor @em can be (but does not have to be) a
   * value from this @if clike enumeration. If it @em is a value
   * from <a class="el" href="#TSBErrorCode_t">TSBErrorCode_t</a>, the
   * TSBError class assumes the error is a low-level system or TSB layer
   * error and <em>prepends</em> a built-in, predefined error message to
   * any string passed in the argument @p details to this constructor.  In
   * addition, all <a class="el"
   * href="#TSBErrorCode_t">TSBErrorCode_t</a> errors have associated
   * values for the @p severity and @p category codes, and these fields are
   * filled-in as well from the enumerations <a class="el"
   * href="#TSBErrorSeverity_t">TSBErrorSeverity_t</a> and <a class="el"
   * href="#TSBErrorCategory_t">TSBErrorCategory_t</a>,
   * respectively. @else set of constants.  If it @em
   * is one of the predefined error identifiers, the TSBError class
   * assumes the error is a low-level system or TSB layer error and
   * <em>prepends</em> a built-in, predefined error message to any string
   * passed in the argument @p details to this constructor.  In addition,
   * all the predefined error identifiers have associated values for the
   * @p severity and @p category codes, and these fields are filled-in using
   * the libTSB defaults for each different error identifier. @endif@~
   *
   * If the error identifier @p errorId is a number greater than 99999, the
   * TSBError class assumes the error was generated from another part of
   * the software and does not do additional filling in of values beyond
   * the default in the constructor itself.  This allows TSBError to serve
   * as a base class for other errors, such as for user-defined validation
   * rules (see Validator).  Callers should fill in all the parameters with
   * suitable values if generating errors with codes greater than 99999 to
   * make maximum use of the TSBError facilities.
   *
   * @if clike As mentioned above, there are two other
   * enumerations, <a class="el"
   * href="#TSBErrorSeverity_t">TSBErrorSeverity_t</a> and <a class="el"
   * href="#TSBErrorCategory_t">TSBErrorCategory_t</a>, used for indicating
   * the severity and category of error for the predefined TSBError codes.
   * The values passed in @p severity and @p category override the defaults
   * assigned based on the error code.  If the value of @p errorId is a
   * value from <a class="el" href="#TSBErrorCode_t">TSBErrorCode_t</a>,
   * callers do not need to fill in @p severity and @p category.
   * Conversely, if @p errorId is not a value from <a class="el"
   * href="#TSBErrorCode_t">TSBErrorCode_t</a>, callers can use other
   * values (not just those from <a class="el"
   * href="#TSBErrorSeverity_t">TSBErrorSeverity_t</a> and <a class="el"
   * href="#TSBErrorCategory_t">TSBErrorCategory_t</a>, but their own
   * special values) for @p severity and
   * @p category. @else As mentioned above,
   * there are additional constants defined for <a class="el"
   * href="#TSBErrorSeverity_t">standard severity</a> and <a class="el"
   * href="#TSBErrorCategory_t">standard category</a> codes, and every predefined
   * error in libTSB has an associated value for severity and category taken
   * from these predefined sets.  These constants have symbol names
   * prefixed with <code>LIBTSB_SEV_</code> and <code>LIBTSB_CAT_</code>,
   * respectively.  If the value of @p errorId is one of the standard error
   * codes, callers do not need to fill in @p severity and @p category in a
   * call to this constructor.  Conversely, if @p errorId is not an existing
   * TSB-level error code, callers can use other values for @p severity and
   * @p category. @endif@~
   *
   * Please see the top of the documentation for TSBError for a longer
   * discussion of the possible error codes, their meanings, and their
   * applicability to different combinations of Level+Version of TSB.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level the TSB Level of the TSB model
   *
   * @param version the TSB Version within the Level of the TSB model
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
  TSBError
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
   * Copy constructor; creates a copy of this TSBError.
   */
  TSBError(const TSBError& orig);

  /**
   * Destroys this TSBError.
   */
  virtual ~TSBError();


#ifndef SWIG

  /** @cond doxygenLibtsbInternal **/

  /**
   * Creates and returns a deep copy of this TSBError object.
   *
   * @return the (deep) copy of this TSBError object.
   */
  virtual TSBError* clone() const;

  /**
   * Outputs this TSBError to stream in the following format (and followed
   * by a newline):
   *
   *   line: (error id) message
   *
   * @param stream the output stream to write to.
   */
  virtual void print(std::ostream& stream) const;

  /** @endcond **/

#endif  /* !SWIG */

protected:
  /** @cond doxygenLibtsbInternal **/

  virtual std::string stringForSeverity(unsigned int code) const;
  virtual std::string stringForCategory(unsigned int code) const;

  /** @endcond **/
};

LIBTSB_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif /* TSBError_h */
