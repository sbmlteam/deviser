#ifndef SBMLError_h
#define SBMLError_h

#include <sbml/common/extern.h>
<verbatim>
#include <sbml/xml/XMLError.h>
</verbatim>
#include <sbml/SBMLNamespaces.h>


LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * @enum SBMLErrorCode_t
 * Codes for all SBML_Lang-level errors and warnings from the core specification.
 */
typedef enum
{
  SBMLUnknownError                      = 10000 /*!< Encountered unknown internal libSBML error. */
, NotUTF8                               = 10001 /*!< File does not use UTF-8 encoding. */
, UnrecognizedElement                   = 10002 /*!< Encountered unrecognized element. */
, NotSchemaConformant                   = 10003 /*!< Document does not conform to the SBML_Lang XML schema. */
, InvalidMathElement                    = 10201
, MissingAnnotationNamespace            = 10401 /*!< Missing declaration of the XML namespace for the annotation. */
, DuplicateAnnotationNamespaces         = 10402 /*!< Multiple annotations using the same XML namespace. */
, SBMLNamespaceInAnnotation             = 10403 /*!< The SBML_Lang XML namespace cannot be used in an Annotation object. */
, MultipleAnnotations                   = 10404 /*!< Only one Annotation object is permitted under a given SBML_Lang object. */
, AnnotationNotElement                  = 10405
, NotesNotInXHTMLNamespace              = 10801 /*!< Notes must be placed in the XHTML XML namespace. */
, NotesContainsXMLDecl                  = 10802 /*!< XML declarations are not permitted in Notes objects. */
, NotesContainsDOCTYPE                  = 10803 /*!< XML DOCTYPE elements are not permitted in Notes objects. */
, InvalidNotesContent                   = 10804 /*!< Invalid notes content found. */
, OnlyOneNotesElementAllowed            = 10805 /*!< Only one Notes subobject is permitted on a given SBML_Lang object. */
<add_specific_errors/>
, UnknownCoreAttribute                  = 99994 /*!< Encountered an unknown attribute in the SBML_Lang Core namespace. */
, SBMLCodesUpperBound                   = 99999 /*!< Upper boundary of libSBML-specific diagnostic codes. */
} SBMLErrorCode_t;


/**
 * @enum SBMLErrorCategory_t
 * Category codes for SBMLError diagnostics.
 *
 * Note that these are distinct from XMLError's category codes.  User
 * programs receiving an SBMLError object can use this distinction to
 * check whether the error represents a low-level XML problem or an
 * SBML_Lang problem.
 *
 * @see #XMLErrorCategory_t
 */
typedef enum
{
<sbml>
    LIBREPLACE_CAT_INTERNAL = LIBSBML_CAT_INTERNAL,
    LIBREPLACE_CAT_SYSTEM = LIBSBML_CAT_SYSTEM,
    LIBREPLACE_CAT_XML = LIBSBML_CAT_XML,
</sbml>

    LIBSBML_CAT_SBML = (LIBSBML_CAT_XML + 1)
    /*!< General SBML_Lang error  not falling into another category below. */

  , LIBSBML_CAT_GENERAL_CONSISTENCY
    /*!< Category of errors that can occur while validating general SBML_Lang
     * constructs. */

  , LIBSBML_CAT_IDENTIFIER_CONSISTENCY
    /*!< Category of errors that can occur while validating symbol
     * identifiers in a model. */

  , LIBSBML_CAT_MATHML_CONSISTENCY
    /*!< Category of errors that can occur while validating MathML formulas
     * in a model.  With respect to the SBML_Lang specification, these concern
     * failures in applying the validation rules numbered 102xx in the
     * Level&nbsp;2 Versions&nbsp;2&ndash;4
     * and Level&nbsp;3 Version&nbsp;1 specifications. */

  , LIBSBML_CAT_INTERNAL_CONSISTENCY
    /*!< Category of errors that can occur while validating libSBML's
     * internal representation of SBML_Lang constructs. (These are tests
     * performed by libSBML and do not have equivalent SBML_Lang validation
     * rules.)  */

} SBMLErrorCategory_t;


/**
 * @enum SBMLErrorSeverity_t
 * Severity codes for SBMLError diagnostics.
 *
 * The only publicly-reported values of this type are the four from #XMLErrorSeverity_t.
 * All other values are used internally only, with translation of those
 * codes done in SBMLError.cpp
 *
 * @see XMLErrorSeverity_t
 */
typedef enum
{
  /** @cond doxygenLibsbmlInternal **/

  /* The following are used internally in SBMLErrorTable, but publicly,
   * we only report one of the 4 XMLError_Severity values.  Translation
   * of the codes is done in SBMLError.cpp.
   */
<sbml>
    LIBREPLACE_SEV_WARNING = LIBSBML_SEV_WARNING,
    LIBREPLACE_SEV_ERROR = LIBSBML_SEV_ERROR,
    LIBREPLACE_SEV_FATAL = LIBSBML_SEV_FATAL,
</sbml>

    LIBSBML_SEV_SCHEMA_ERROR    = (LIBSBML_SEV_FATAL + 1)
    /*!< The XML content does not conform to
     * the relevant version of the SBML_Lang XML
     * Schema.  The content is not valid SBML_Lang. */

  , LIBSBML_SEV_GENERAL_WARNING
    /*!< The XML content is invalid for some
     * levels/versions of SBML_Lang, and while it
     * may be valid in others, it is something
     * that is best avoided anyway.  LibSBML
     * will issue warnings in those cases it
     * can recognize. */

  , LIBSBML_SEV_NOT_APPLICABLE
    /*!< This error code is only a placeholder
     * for errors that have relevance to some
     * versions of SBML_Lang but not others. */

  /** @endcond **/
} SBMLErrorSeverity_t;

END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#ifdef __cplusplus

LIBSBML_CPP_NAMESPACE_BEGIN

class LIBSBML_EXTERN SBMLError : public XMLError
{
public:

  /**
   * Creates a new SBMLError to report that something occurred during SBML_Lang
   * processing.
   *
   * When a libSBML operation on SBML_Lang content results in a warning, error
   * or other diagnostic, the issue is reported as an SBMLError object.
   * SBMLError objects have identification numbers to indicate the nature
   * of the exception.  @if clike These numbers are drawn from
   * the enumeration <a class="el"
   * href="#SBMLErrorCode_t">
   * SBMLErrorCode_t</a>.  @endif@if java These numbers are
   * defined as unsigned integer constants in the file
   * "libsbmlConstants.html".  See the <a class="el"
   * href="#SBMLErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@if python These
   * numbers are defined as unsigned integer constants in the interface
   * class @link libsbml libsbml@endlink.  See the <a class="el"
   * href="#SBMLErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@~ The argument
   * @p errorId to this constructor @em can be (but does not have to be) a
   * value from this @if clike enumeration. If it @em is a value
   * from <a class="el" href="#SBMLErrorCode_t">SBMLErrorCode_t</a>, the
   * SBMLError class assumes the error is a low-level system or SBML_Lang layer
   * error and <em>prepends</em> a built-in, predefined error message to
   * any string passed in the argument @p details to this constructor.  In
   * addition, all <a class="el"
   * href="#SBMLErrorCode_t">SBMLErrorCode_t</a> errors have associated
   * values for the @p severity and @p category codes, and these fields are
   * filled-in as well from the enumerations <a class="el"
   * href="#SBMLErrorSeverity_t">SBMLErrorSeverity_t</a> and <a class="el"
   * href="#SBMLErrorCategory_t">SBMLErrorCategory_t</a>,
   * respectively. @else set of constants.  If it @em
   * is one of the predefined error identifiers, the SBMLError class
   * assumes the error is a low-level system or SBML_Lang layer error and
   * <em>prepends</em> a built-in, predefined error message to any string
   * passed in the argument @p details to this constructor.  In addition,
   * all the predefined error identifiers have associated values for the
   * @p severity and @p category codes, and these fields are filled-in using
   * the libSBML defaults for each different error identifier. @endif@~
   *
   * If the error identifier @p errorId is a number greater than 99999, the
   * SBMLError class assumes the error was generated from another part of
   * the software and does not do additional filling in of values beyond
   * the default in the constructor itself.  This allows SBMLError to serve
   * as a base class for other errors, such as for user-defined validation
   * rules (see Validator).  Callers should fill in all the parameters with
   * suitable values if generating errors with codes greater than 99999 to
   * make maximum use of the SBMLError facilities.
   *
   * @if clike As mentioned above, there are two other
   * enumerations, <a class="el"
   * href="#SBMLErrorSeverity_t">SBMLErrorSeverity_t</a> and <a class="el"
   * href="#SBMLErrorCategory_t">SBMLErrorCategory_t</a>, used for indicating
   * the severity and category of error for the predefined SBMLError codes.
   * The values passed in @p severity and @p category override the defaults
   * assigned based on the error code.  If the value of @p errorId is a
   * value from <a class="el" href="#SBMLErrorCode_t">SBMLErrorCode_t</a>,
   * callers do not need to fill in @p severity and @p category.
   * Conversely, if @p errorId is not a value from <a class="el"
   * href="#SBMLErrorCode_t">SBMLErrorCode_t</a>, callers can use other
   * values (not just those from <a class="el"
   * href="#SBMLErrorSeverity_t">SBMLErrorSeverity_t</a> and <a class="el"
   * href="#SBMLErrorCategory_t">SBMLErrorCategory_t</a>, but their own
   * special values) for @p severity and
   * @p category. @else As mentioned above,
   * there are additional constants defined for <a class="el"
   * href="#SBMLErrorSeverity_t">standard severity</a> and <a class="el"
   * href="#SBMLErrorCategory_t">standard category</a> codes, and every predefined
   * error in libSBML has an associated value for severity and category taken
   * from these predefined sets.  These constants have symbol names
   * prefixed with <code>LIBSBML_SEV_</code> and <code>LIBSBML_CAT_</code>,
   * respectively.  If the value of @p errorId is one of the standard error
   * codes, callers do not need to fill in @p severity and @p category in a
   * call to this constructor.  Conversely, if @p errorId is not an existing
   * SBML_Lang-level error code, callers can use other values for @p severity and
   * @p category. @endif@~
   *
   * Please see the top of the documentation for SBMLError for a longer
   * discussion of the possible error codes, their meanings, and their
   * applicability to different combinations of Level+Version of SBML_Lang.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level the SBML_Lang Level of the SBML_Lang model
   *
   * @param version the SBML_Lang Version within the Level of the SBML_Lang model
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
  SBMLError
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
   * Copy constructor; creates a copy of this SBMLError.
   */
  SBMLError(const SBMLError& orig);

  /**
   * Destroys this SBMLError.
   */
  virtual ~SBMLError();


#ifndef SWIG

  /** @cond doxygenLibsbmlInternal **/

  /**
   * Creates and returns a deep copy of this SBMLError object.
   *
   * @return the (deep) copy of this SBMLError object.
   */
  virtual SBMLError* clone() const;

  /**
   * Outputs this SBMLError to stream in the following format (and followed
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
  /** @cond doxygenLibsbmlInternal **/

  virtual std::string stringForSeverity(unsigned int code) const;
  virtual std::string stringForCategory(unsigned int code) const;

  /** @endcond **/
};

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif /* SBMLError_h */
