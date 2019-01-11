/**
 * @file SedmlEnumerations.h
 * @brief Definition of SedmlEnumerations.
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
 * @class SedmlEnumerations
 * @sbmlbrief{sedml} TODO:Definition of SedmlEnumerations.
 */


#ifndef SedmlEnumerations_H__
#define SedmlEnumerations_H__


#include <sedml/common/extern.h>
#include <sedml/SedTypeCodes.h>


LIBSEDML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * @enum MappingType_t
 * @brief Enumeration of values permitted as the value of "MappingType_t".
 */
typedef enum
{
  SEDML_MAPPINGTYPE_VARIABLE        /*!< The sedml mappingtype is @c "Variable". */
, SEDML_MAPPINGTYPE_PARAMETER       /*!< The sedml mappingtype is @c "Parameter". */
, SEDML_MAPPINGTYPE_INVALID         /*!< Invalid MappingType value. */
} MappingType_t;


/**
 * Returns the string version of the provided #MappingType_t enumeration.
 *
 * @param mt the #MappingType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "Variable",
 * "Parameter",
 * "invalid MappingType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_MAPPINGTYPE_INVALID,
 * MappingType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
MappingType_toString(MappingType_t mt);


/**
 * Returns the #MappingType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #MappingType_t.
 *
 * @return the corresponding #MappingType_t or
 * @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t} if no match is
 * found.
 *
 * @note The matching is case-sensitive: "Variable" will return
 * @sbmlconstant{SEDML_MAPPINGTYPE_VARIABLE, MappingType_t}, but "Variable"
 * will return @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
MappingType_t
MappingType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MappingType_t is valid.
 *
 * @param mt the #MappingType_t enumeration to query.
 *
 * @return @c 1 (true) if the #MappingType_t is
 * @sbmlconstant{SEDML_MAPPINGTYPE_VARIABLE, MappingType_t}, or
 * @sbmlconstant{SEDML_MAPPINGTYPE_PARAMETER, MappingType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_MAPPINGTYPE_INVALID,
 * MappingType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
MappingType_isValid(MappingType_t mt);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MappingType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "Variable",
 * "Parameter", or
 * "invalid MappingType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "Variable" will return @c 1 (true),
 * but "Variable" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
MappingType_isValidString(const char* code);


/**
 * @enum ExperimentType_t
 * @brief Enumeration of values permitted as the value of "ExperimentType_t".
 */
typedef enum
{
  SEDML_EXPERIMENTTYPE_TIMECOURSE        /*!< The sedml experimenttype is @c "TimeCourse". */
, SEDML_EXPERIMENTTYPE_STEADYSTATE       /*!< The sedml experimenttype is @c "SteadyState". */
, SEDML_EXPERIMENTTYPE_INVALID           /*!< Invalid ExperimentType value. */
} ExperimentType_t;


/**
 * Returns the string version of the provided #ExperimentType_t enumeration.
 *
 * @param et the #ExperimentType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "TimeCourse",
 * "SteadyState",
 * "invalid ExperimentType value",
 * or @c NULL if the value is @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID,
 * ExperimentType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
ExperimentType_toString(ExperimentType_t et);


/**
 * Returns the #ExperimentType_t enumeration corresponding to the given string
 * or @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t} if there is
 * no such match.
 *
 * @param code the string to convert to a #ExperimentType_t.
 *
 * @return the corresponding #ExperimentType_t or
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t} if no match is
 * found.
 *
 * @note The matching is case-sensitive: "TimeCourse" will return
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_TIMECOURSE, ExperimentType_t}, but
 * "TimeCourse" will return @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID,
 * ExperimentType_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
ExperimentType_t
ExperimentType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #ExperimentType_t is valid.
 *
 * @param et the #ExperimentType_t enumeration to query.
 *
 * @return @c 1 (true) if the #ExperimentType_t is
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_TIMECOURSE, ExperimentType_t}, or
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_STEADYSTATE, ExperimentType_t};
 * @c 0 (false) otherwise (including
 * @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
ExperimentType_isValid(ExperimentType_t et);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #ExperimentType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "TimeCourse",
 * "SteadyState", or
 * "invalid ExperimentType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "TimeCourse" will return @c 1 (true),
 * but "TimeCourse" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
ExperimentType_isValidString(const char* code);


/**
 * @enum AxisKind_t
 * @brief Enumeration of values permitted as the value of "AxisKind_t".
 */
typedef enum
{
  SEDML_AXISKIND_LINEAR        /*!< The sedml axiskind is @c "linear". */
, SEDML_AXISKIND_LOG10         /*!< The sedml axiskind is @c "log10". */
, SEDML_AXISKIND_INVALID       /*!< Invalid AxisKind value. */
} AxisKind_t;


/**
 * Returns the string version of the provided #AxisKind_t enumeration.
 *
 * @param ak the #AxisKind_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "linear",
 * "log10",
 * "invalid AxisKind value",
 * or @c NULL if the value is @sbmlconstant{SEDML_AXISKIND_INVALID, AxisKind_t}
 * or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
AxisKind_toString(AxisKind_t ak);


/**
 * Returns the #AxisKind_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_AXISKIND_INVALID, AxisKind_t} if there is no such match.
 *
 * @param code the string to convert to a #AxisKind_t.
 *
 * @return the corresponding #AxisKind_t or
 * @sbmlconstant{SEDML_AXISKIND_INVALID, AxisKind_t} if no match is found.
 *
 * @note The matching is case-sensitive: "linear" will return
 * @sbmlconstant{SEDML_AXISKIND_LINEAR, AxisKind_t}, but "Linear" will return
 * @sbmlconstant{SEDML_AXISKIND_INVALID, AxisKind_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
AxisKind_t
AxisKind_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #AxisKind_t is valid.
 *
 * @param ak the #AxisKind_t enumeration to query.
 *
 * @return @c 1 (true) if the #AxisKind_t is
 * @sbmlconstant{SEDML_AXISKIND_LINEAR, AxisKind_t}, or
 * @sbmlconstant{SEDML_AXISKIND_LOG10, AxisKind_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_AXISKIND_INVALID,
 * AxisKind_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
AxisKind_isValid(AxisKind_t ak);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #AxisKind_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "linear",
 * "log10", or
 * "invalid AxisKind value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "linear" will return @c 1 (true), but
 * "Linear" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
AxisKind_isValidString(const char* code);


/**
 * @enum LineKind_t
 * @brief Enumeration of values permitted as the value of "LineKind_t".
 */
typedef enum
{
  SEDML_LINEKIND_NONE          /*!< The sedml linekind is @c "none". */
, SEDML_LINEKIND_SOLID         /*!< The sedml linekind is @c "solid". */
, SEDML_LINEKIND_DASH          /*!< The sedml linekind is @c "dash". */
, SEDML_LINEKIND_DOT           /*!< The sedml linekind is @c "dot". */
, SEDML_LINEKIND_DASHDOT       /*!< The sedml linekind is @c "dashDot". */
, SEDML_LINEKIND_INVALID       /*!< Invalid LineKind value. */
} LineKind_t;


/**
 * Returns the string version of the provided #LineKind_t enumeration.
 *
 * @param lk the #LineKind_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "none",
 * "solid",
 * "dash",
 * "dot",
 * "dashDot",
 * "invalid LineKind value",
 * or @c NULL if the value is @sbmlconstant{SEDML_LINEKIND_INVALID, LineKind_t}
 * or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
LineKind_toString(LineKind_t lk);


/**
 * Returns the #LineKind_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_LINEKIND_INVALID, LineKind_t} if there is no such match.
 *
 * @param code the string to convert to a #LineKind_t.
 *
 * @return the corresponding #LineKind_t or
 * @sbmlconstant{SEDML_LINEKIND_INVALID, LineKind_t} if no match is found.
 *
 * @note The matching is case-sensitive: "none" will return
 * @sbmlconstant{SEDML_LINEKIND_NONE, LineKind_t}, but "None" will return
 * @sbmlconstant{SEDML_LINEKIND_INVALID, LineKind_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
LineKind_t
LineKind_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #LineKind_t is valid.
 *
 * @param lk the #LineKind_t enumeration to query.
 *
 * @return @c 1 (true) if the #LineKind_t is
 * @sbmlconstant{SEDML_LINEKIND_NONE, LineKind_t},
 * @sbmlconstant{SEDML_LINEKIND_SOLID, LineKind_t},
 * @sbmlconstant{SEDML_LINEKIND_DASH, LineKind_t},
 * @sbmlconstant{SEDML_LINEKIND_DOT, LineKind_t}, or
 * @sbmlconstant{SEDML_LINEKIND_DASHDOT, LineKind_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_LINEKIND_INVALID,
 * LineKind_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
LineKind_isValid(LineKind_t lk);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #LineKind_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "none",
 * "solid",
 * "dash",
 * "dot",
 * "dashDot", or
 * "invalid LineKind value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "none" will return @c 1 (true), but
 * "None" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
LineKind_isValidString(const char* code);


/**
 * @enum MarkerKind_t
 * @brief Enumeration of values permitted as the value of "MarkerKind_t".
 */
typedef enum
{
  SEDML_MARKERKIND_NONE                /*!< The sedml markerkind is @c "none". */
, SEDML_MARKERKIND_SQUARE              /*!< The sedml markerkind is @c "square". */
, SEDML_MARKERKIND_CIRCLE              /*!< The sedml markerkind is @c "circle". */
, SEDML_MARKERKIND_DIAMOND             /*!< The sedml markerkind is @c "diamond". */
, SEDML_MARKERKIND_XCROSS              /*!< The sedml markerkind is @c "xCross". */
, SEDML_MARKERKIND_PLUS                /*!< The sedml markerkind is @c "plus". */
, SEDML_MARKERKIND_STAR                /*!< The sedml markerkind is @c "star". */
, SEDML_MARKERKIND_TRIANGLEUP          /*!< The sedml markerkind is @c "triangleUp". */
, SEDML_MARKERKIND_TRIANGLEDOWN        /*!< The sedml markerkind is @c "triangleDown". */
, SEDML_MARKERKIND_TRIANGLELEFT        /*!< The sedml markerkind is @c "triangleLeft". */
, SEDML_MARKERKIND_TRIANGLERIGHT       /*!< The sedml markerkind is @c "triangleRight". */
, SEDML_MARKERKIND_HDASH               /*!< The sedml markerkind is @c "hDash". */
, SEDML_MARKERKIND_VDASH               /*!< The sedml markerkind is @c "vDash". */
, SEDML_MARKERKIND_INVALID             /*!< Invalid MarkerKind value. */
} MarkerKind_t;


/**
 * Returns the string version of the provided #MarkerKind_t enumeration.
 *
 * @param mk the #MarkerKind_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "none",
 * "square",
 * "circle",
 * "diamond",
 * "xCross",
 * "plus",
 * "star",
 * "triangleUp",
 * "triangleDown",
 * "triangleLeft",
 * "triangleRight",
 * "hDash",
 * "vDash",
 * "invalid MarkerKind value",
 * or @c NULL if the value is @sbmlconstant{SEDML_MARKERKIND_INVALID,
 * MarkerKind_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
MarkerKind_toString(MarkerKind_t mk);


/**
 * Returns the #MarkerKind_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_MARKERKIND_INVALID, MarkerKind_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #MarkerKind_t.
 *
 * @return the corresponding #MarkerKind_t or
 * @sbmlconstant{SEDML_MARKERKIND_INVALID, MarkerKind_t} if no match is found.
 *
 * @note The matching is case-sensitive: "none" will return
 * @sbmlconstant{SEDML_MARKERKIND_NONE, MarkerKind_t}, but "None" will return
 * @sbmlconstant{SEDML_MARKERKIND_INVALID, MarkerKind_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
MarkerKind_t
MarkerKind_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MarkerKind_t is valid.
 *
 * @param mk the #MarkerKind_t enumeration to query.
 *
 * @return @c 1 (true) if the #MarkerKind_t is
 * @sbmlconstant{SEDML_MARKERKIND_NONE, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_SQUARE, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_CIRCLE, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_DIAMOND, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_XCROSS, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_PLUS, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_STAR, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_TRIANGLEUP, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_TRIANGLEDOWN, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_TRIANGLELEFT, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_TRIANGLERIGHT, MarkerKind_t},
 * @sbmlconstant{SEDML_MARKERKIND_HDASH, MarkerKind_t}, or
 * @sbmlconstant{SEDML_MARKERKIND_VDASH, MarkerKind_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_MARKERKIND_INVALID,
 * MarkerKind_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
MarkerKind_isValid(MarkerKind_t mk);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MarkerKind_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "none",
 * "square",
 * "circle",
 * "diamond",
 * "xCross",
 * "plus",
 * "star",
 * "triangleUp",
 * "triangleDown",
 * "triangleLeft",
 * "triangleRight",
 * "hDash",
 * "vDash", or
 * "invalid MarkerKind value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "none" will return @c 1 (true), but
 * "None" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
MarkerKind_isValidString(const char* code);


/**
 * @enum CurveKind_t
 * @brief Enumeration of values permitted as the value of "CurveKind_t".
 */
typedef enum
{
  SEDML_CURVEKIND_POINTS           /*!< The sedml curvekind is @c "points". */
, SEDML_CURVEKIND_BAR              /*!< The sedml curvekind is @c "bar". */
, SEDML_CURVEKIND_BARSTACKED       /*!< The sedml curvekind is @c "barStacked". */
, SEDML_CURVEKIND_INVALID          /*!< Invalid CurveKind value. */
} CurveKind_t;


/**
 * Returns the string version of the provided #CurveKind_t enumeration.
 *
 * @param ck the #CurveKind_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "points",
 * "bar",
 * "barStacked",
 * "invalid CurveKind value",
 * or @c NULL if the value is @sbmlconstant{SEDML_CURVEKIND_INVALID,
 * CurveKind_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
const char*
CurveKind_toString(CurveKind_t ck);


/**
 * Returns the #CurveKind_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_CURVEKIND_INVALID, CurveKind_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #CurveKind_t.
 *
 * @return the corresponding #CurveKind_t or
 * @sbmlconstant{SEDML_CURVEKIND_INVALID, CurveKind_t} if no match is found.
 *
 * @note The matching is case-sensitive: "points" will return
 * @sbmlconstant{SEDML_CURVEKIND_POINTS, CurveKind_t}, but "Points" will return
 * @sbmlconstant{SEDML_CURVEKIND_INVALID, CurveKind_t}.
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
CurveKind_t
CurveKind_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #CurveKind_t is valid.
 *
 * @param ck the #CurveKind_t enumeration to query.
 *
 * @return @c 1 (true) if the #CurveKind_t is
 * @sbmlconstant{SEDML_CURVEKIND_POINTS, CurveKind_t},
 * @sbmlconstant{SEDML_CURVEKIND_BAR, CurveKind_t}, or
 * @sbmlconstant{SEDML_CURVEKIND_BARSTACKED, CurveKind_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SEDML_CURVEKIND_INVALID,
 * CurveKind_t}).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
CurveKind_isValid(CurveKind_t ck);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #CurveKind_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "points",
 * "bar",
 * "barStacked", or
 * "invalid CurveKind value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "points" will return @c 1 (true), but
 * "Points" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sedml_t
 * @endif
 */
LIBSEDML_EXTERN
int
CurveKind_isValidString(const char* code);




END_C_DECLS




LIBSEDML_CPP_NAMESPACE_END




#endif /* !SedmlEnumerations_H__ */


