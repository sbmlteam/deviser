/**
 * @file SedError.h
 * @brief Definition of the SedError class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2016, Frank T. Bergmann
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
 */


#ifndef SedError_h
#define SedError_h

#include <sedml/common/extern.h>
#include <sbml/xml/XMLError.h>
#include <sedml/SedNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * @enum SedErrorCode_t
 * Codes for all SEDML-level errors and warnings from the core specification.
 */
typedef enum
{
  SedmlUnknown                      = 10000 /*!< Encountered unknown internal libSEDML error. */
, SedNotUTF8                               = 10001 /*!< File does not use UTF-8 encoding. */
, SedUnrecognizedElement                   = 10002 /*!< Encountered unrecognized element. */
, SedNotSchemaConformant                   = 10003 /*!< Document does not conform to the SEDML XML schema. */
, SedInvalidMathElement                    = 10201
, SedMissingAnnotationNamespace            = 10401 /*!< Missing declaration of the XML namespace for the annotation. */
, SedDuplicateAnnotationNamespaces         = 10402 /*!< Multiple annotations using the same XML namespace. */
, SedNamespaceInAnnotation             = 10403 /*!< The SEDML XML namespace cannot be used in an Annotation object. */
, SedMultipleAnnotations                   = 10404 /*!< Only one Annotation object is permitted under a given SEDML object. */
, SedAnnotationNotElement                  = 10405
, SedNotesNotInXHTMLNamespace              = 10801 /*!< Notes must be placed in the XHTML XML namespace. */
, SedNotesContainsXMLDecl                  = 10802 /*!< XML declarations are not permitted in Notes objects. */
, SedNotesContainsDOCTYPE                  = 10803 /*!< XML DOCTYPE elements are not permitted in Notes objects. */
, SedInvalidNotesContent                   = 10804 /*!< Invalid notes content found. */
, SedOnlyOneNotesElementAllowed            = 10805 /*!< Only one Notes subobject is permitted on a given SEDML object. */
, SedmlNSUndeclared      = 10101
, SedmlElementNotInNs      = 10102
, SedmlDuplicateComponentId      = 10301
, SedmlIdSyntaxRule      = 10302
, SedInvalidMetaidSyntax      = 10303
, InvalidNamespaceOnSed      = 20101
, AllowedAttributes      = 20102
, SedEmptyListElement      = 20103
, SedmlSedDocumentAllowedCoreAttributes      = 20201
, SedmlSedDocumentAllowedCoreElements      = 20202
, SedmlSedDocumentAllowedAttributes      = 20203
, SedmlSedDocumentAllowedElements      = 20204
, SedmlSedDocumentLevelMustBeInteger      = 20205
, SedmlSedDocumentVersionMustBeInteger      = 20206
, SedmlSedDocumentEmptyLOElements      = 20207
, SedmlSedDocumentLOModelsAllowedCoreElements      = 20208
, SedmlSedDocumentLOModelsAllowedCoreAttributes      = 20209
, SedmlSedModelAllowedCoreAttributes      = 20301
, SedmlSedModelAllowedCoreElements      = 20302
, SedmlSedModelAllowedAttributes      = 20303
, SedmlSedModelAllowedElements      = 20304
, SedmlSedModelSourceMustBeString      = 20305
, SedmlSedModelNameMustBeString      = 20306
, SedmlSedModelLanguageMustBeString      = 20307
, SedmlSedModelEmptyLOElements      = 20308
, SedmlSedModelLOChangesAllowedCoreElements      = 20309
, SedmlSedModelLOChangesAllowedCoreAttributes      = 20310
, SedmlSedChangeAllowedCoreAttributes      = 20401
, SedmlSedChangeAllowedCoreElements      = 20402
, SedmlSedAddXMLAllowedCoreAttributes      = 20501
, SedmlSedAddXMLAllowedCoreElements      = 20502
, SedmlSedAddXMLAllowedElements      = 20503
, SedmlSedSetValueAllowedCoreAttributes      = 20601
, SedmlSedSetValueAllowedCoreElements      = 20602
, SedmlSedSetValueAllowedAttributes      = 20603
, SedmlSedSetValueAllowedElements      = 20604
, SedmlSedSetValueModelReferenceMustBeModel      = 20605
, SedmlSedSetValueSymbolMustBeString      = 20606
, SedmlSedSetValueTargetMustBeString      = 20607
, SedmlSedSetValueRangeMustBeRange      = 20608
, SedmlSedDataGeneratorAllowedCoreAttributes      = 20701
, SedmlSedDataGeneratorAllowedCoreElements      = 20702
, SedmlSedDataGeneratorAllowedAttributes      = 20703
, SedmlSedDataGeneratorAllowedElements      = 20704
, SedmlSedDataGeneratorNameMustBeString      = 20705
, SedmlSedDataGeneratorEmptyLOElements      = 20706
, SedmlSedDataGeneratorLOVariablesAllowedCoreElements      = 20707
, SedmlSedDataGeneratorLOParametersAllowedCoreElements      = 20708
, SedmlSedDataGeneratorLOVariablesAllowedCoreAttributes      = 20709
, SedmlSedDataGeneratorLOParametersAllowedCoreAttributes      = 20710
, SedmlSedRepeatedTaskAllowedCoreAttributes      = 20801
, SedmlSedRepeatedTaskAllowedCoreElements      = 20802
, SedmlSedRepeatedTaskAllowedAttributes      = 20803
, SedmlSedRepeatedTaskRangeIdMustBeRange      = 20804
, SedmlSedRepeatedTaskResetModelMustBeBoolean      = 20805
, SedmlSedSimulationAllowedCoreAttributes      = 20901
, SedmlSedSimulationAllowedCoreElements      = 20902
, SedmlSedSimulationAllowedAttributes      = 20903
, SedmlSedSimulationAllowedElements      = 20904
, SedmlSedSimulationNameMustBeString      = 20905
, SedmlSedVectorRangeAllowedCoreAttributes      = 21001
, SedmlSedVectorRangeAllowedCoreElements      = 21002
, SedmlSedVectorRangeAllowedAttributes      = 21003
, SedmlSedVectorRangeValueMustBeString      = 21004
, SedUnknownCoreAttribute                  = 99994 /*!< Encountered an unknown attribute in the SEDML Core namespace. */
, SedCodesUpperBound                   = 99999 /*!< Upper boundary of libSEDML-specific diagnostic codes. */
} SedErrorCode_t;


/**
 * @enum SedErrorCategory_t
 * Category codes for SedError diagnostics.
 *
 * Note that these are distinct from XMLError's category codes.  User
 * programs receiving an SedError object can use this distinction to
 * check whether the error represents a low-level XML problem or an
 * SEDML problem.
 *
 * @see #XMLErrorCategory_t
 */
typedef enum
{
    LIBSEDML_CAT_INTERNAL = LIBSBML_CAT_INTERNAL,
    LIBSEDML_CAT_SYSTEM = LIBSBML_CAT_SYSTEM,
    LIBSEDML_CAT_XML = LIBSBML_CAT_XML,

    LIBSEDML_CAT_SEDML = (LIBSEDML_CAT_XML + 1)
    /*!< General SEDML error  not falling into another category below. */

  , LIBSEDML_CAT_GENERAL_CONSISTENCY
    /*!< Category of errors that can occur while validating general SEDML
     * constructs. */

  , LIBSEDML_CAT_IDENTIFIER_CONSISTENCY
    /*!< Category of errors that can occur while validating symbol
     * identifiers in a model. */

  , LIBSEDML_CAT_MATHML_CONSISTENCY
    /*!< Category of errors that can occur while validating MathML formulas
     * in a model.  With respect to the SEDML specification, these concern
     * failures in applying the validation rules numbered 102xx in the
     * Level&nbsp;2 Versions&nbsp;2&ndash;4
     * and Level&nbsp;3 Version&nbsp;1 specifications. */

  , LIBSEDML_CAT_INTERNAL_CONSISTENCY
    /*!< Category of errors that can occur while validating libSEDML's
     * internal representation of SEDML constructs. (These are tests
     * performed by libSEDML and do not have equivalent SEDML validation
     * rules.)  */

} SedErrorCategory_t;


/**
 * @enum SedErrorSeverity_t
 * Severity codes for SedError diagnostics.
 *
 * The only publicly-reported values of this type are the four from #XMLErrorSeverity_t.
 * All other values are used internally only, with translation of those
 * codes done in SedError.cpp
 *
 * @see XMLErrorSeverity_t
 */
typedef enum
{
  /** @cond doxygenLibsedmlInternal **/

  /* The following are used internally in SedErrorTable, but publicly,
   * we only report one of the 4 XMLError_Severity values.  Translation
   * of the codes is done in SedError.cpp.
   */
    LIBSEDML_SEV_WARNING = LIBSBML_SEV_WARNING,
    LIBSEDML_SEV_ERROR = LIBSBML_SEV_ERROR,
    LIBSEDML_SEV_FATAL = LIBSBML_SEV_FATAL,

    LIBSEDML_SEV_SCHEMA_ERROR    = (LIBSEDML_SEV_FATAL + 1)
    /*!< The XML content does not conform to
     * the relevant version of the SEDML XML
     * Schema.  The content is not valid SEDML. */

  , LIBSEDML_SEV_GENERAL_WARNING
    /*!< The XML content is invalid for some
     * levels/versions of SEDML, and while it
     * may be valid in others, it is something
     * that is best avoided anyway.  LibSEDML
     * will issue warnings in those cases it
     * can recognize. */

  , LIBSEDML_SEV_NOT_APPLICABLE
    /*!< This error code is only a placeholder
     * for errors that have relevance to some
     * versions of SEDML but not others. */

  /** @endcond **/
} SedErrorSeverity_t;

END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#ifdef __cplusplus

LIBSEDML_CPP_NAMESPACE_BEGIN

class LIBSEDML_EXTERN SedError : public XMLError
{
public:

  /**
   * Creates a new SedError to report that something occurred during SEDML
   * processing.
   *
   * When a libSEDML operation on SEDML content results in a warning, error
   * or other diagnostic, the issue is reported as an SedError object.
   * SedError objects have identification numbers to indicate the nature
   * of the exception.  @if clike These numbers are drawn from
   * the enumeration <a class="el"
   * href="#SedErrorCode_t">
   * SedErrorCode_t</a>.  @endif@if java These numbers are
   * defined as unsigned integer constants in the file
   * "libsedmlConstants.html".  See the <a class="el"
   * href="#SedErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@if python These
   * numbers are defined as unsigned integer constants in the interface
   * class @link libsedml libsedml@endlink.  See the <a class="el"
   * href="#SedErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@~ The argument
   * @p errorId to this constructor @em can be (but does not have to be) a
   * value from this @if clike enumeration. If it @em is a value
   * from <a class="el" href="#SedErrorCode_t">SedErrorCode_t</a>, the
   * SedError class assumes the error is a low-level system or SEDML layer
   * error and <em>prepends</em> a built-in, predefined error message to
   * any string passed in the argument @p details to this constructor.  In
   * addition, all <a class="el"
   * href="#SedErrorCode_t">SedErrorCode_t</a> errors have associated
   * values for the @p severity and @p category codes, and these fields are
   * filled-in as well from the enumerations <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>,
   * respectively. @else set of constants.  If it @em
   * is one of the predefined error identifiers, the SedError class
   * assumes the error is a low-level system or SEDML layer error and
   * <em>prepends</em> a built-in, predefined error message to any string
   * passed in the argument @p details to this constructor.  In addition,
   * all the predefined error identifiers have associated values for the
   * @p severity and @p category codes, and these fields are filled-in using
   * the libSEDML defaults for each different error identifier. @endif@~
   *
   * If the error identifier @p errorId is a number greater than 99999, the
   * SedError class assumes the error was generated from another part of
   * the software and does not do additional filling in of values beyond
   * the default in the constructor itself.  This allows SedError to serve
   * as a base class for other errors, such as for user-defined validation
   * rules (see Validator).  Callers should fill in all the parameters with
   * suitable values if generating errors with codes greater than 99999 to
   * make maximum use of the SedError facilities.
   *
   * @if clike As mentioned above, there are two other
   * enumerations, <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>, used for indicating
   * the severity and category of error for the predefined SedError codes.
   * The values passed in @p severity and @p category override the defaults
   * assigned based on the error code.  If the value of @p errorId is a
   * value from <a class="el" href="#SedErrorCode_t">SedErrorCode_t</a>,
   * callers do not need to fill in @p severity and @p category.
   * Conversely, if @p errorId is not a value from <a class="el"
   * href="#SedErrorCode_t">SedErrorCode_t</a>, callers can use other
   * values (not just those from <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>, but their own
   * special values) for @p severity and
   * @p category. @else As mentioned above,
   * there are additional constants defined for <a class="el"
   * href="#SedErrorSeverity_t">standard severity</a> and <a class="el"
   * href="#SedErrorCategory_t">standard category</a> codes, and every predefined
   * error in libSEDML has an associated value for severity and category taken
   * from these predefined sets.  These constants have symbol names
   * prefixed with <code>LIBSEDML_SEV_</code> and <code>LIBSEDML_CAT_</code>,
   * respectively.  If the value of @p errorId is one of the standard error
   * codes, callers do not need to fill in @p severity and @p category in a
   * call to this constructor.  Conversely, if @p errorId is not an existing
   * SEDML-level error code, callers can use other values for @p severity and
   * @p category. @endif@~
   *
   * Please see the top of the documentation for SedError for a longer
   * discussion of the possible error codes, their meanings, and their
   * applicability to different combinations of Level+Version of SEDML.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level the SEDML Level of the SEDML model
   *
   * @param version the SEDML Version within the Level of the SEDML model
   *
   * @param details a string containing additional details about the error.
   * If the error code in @p errorId is one that is recognized by SedError,
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
  SedError
  (
     const unsigned int errorId  = 0
   , const unsigned int level    = SEDML_DEFAULT_LEVEL
   , const unsigned int version  = SEDML_DEFAULT_VERSION
   , const std::string& details  = ""
   , const unsigned int line     = 0
   , const unsigned int column   = 0
   , const unsigned int severity = LIBSEDML_SEV_ERROR
   , const unsigned int category = LIBSEDML_CAT_SEDML
  );


  /**
   * Copy constructor; creates a copy of this SedError.
   */
  SedError(const SedError& orig);

  /**
   * Destroys this SedError.
   */
  virtual ~SedError();


#ifndef SWIG

  /** @cond doxygenLibsedmlInternal **/

  /**
   * Creates and returns a deep copy of this SedError object.
   *
   * @return the (deep) copy of this SedError object.
   */
  virtual SedError* clone() const;

  /**
   * Outputs this SedError to stream in the following format (and followed
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
  /** @cond doxygenLibsedmlInternal **/

  virtual std::string stringForSeverity(unsigned int code) const;
  virtual std::string stringForCategory(unsigned int code) const;

  /** @endcond **/
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif /* SedError_h */
