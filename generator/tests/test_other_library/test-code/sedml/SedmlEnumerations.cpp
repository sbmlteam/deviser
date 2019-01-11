/**
 * @file SedmlEnumerations.cpp
 * @brief Implementation of SedmlEnumerations.
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
 */
#include <string>
#include <sedml/common/SedmlEnumerations.h>


LIBSEDML_CPP_NAMESPACE_BEGIN


static
const char* SEDML_MAPPING_TYPE_STRINGS[] =
{
  "Variable"
, "Parameter"
, "invalid MappingType value"
};


/*
 * Returns the string version of the provided #MappingType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
MappingType_toString(MappingType_t mt)
{
  int min = SEDML_MAPPINGTYPE_VARIABLE;
  int max = SEDML_MAPPINGTYPE_INVALID;

  if (mt < min || mt > max)
  {
    return "(Unknown MappingType value)";
  }

  return SEDML_MAPPING_TYPE_STRINGS[mt - min];
}


/*
 * Returns the #MappingType_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_MAPPINGTYPE_INVALID, MappingType_t} if there is no such
 * match.
 */
LIBSEDML_EXTERN
MappingType_t
MappingType_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_MAPPING_TYPE_STRINGS)/sizeof(SEDML_MAPPING_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_MAPPING_TYPE_STRINGS[i])
    {
      return (MappingType_t)(i);
    }
  }

  return SEDML_MAPPINGTYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MappingType_t is valid.
 */
LIBSEDML_EXTERN
int
MappingType_isValid(MappingType_t mt)
{
  int min = SEDML_MAPPINGTYPE_VARIABLE;
  int max = SEDML_MAPPINGTYPE_INVALID;

  if (mt < min || mt >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MappingType_t.
 */
LIBSEDML_EXTERN
int
MappingType_isValidString(const char* code)
{
  return MappingType_isValid(MappingType_fromString(code));
}


static
const char* SEDML_EXPERIMENT_TYPE_STRINGS[] =
{
  "TimeCourse"
, "SteadyState"
, "invalid ExperimentType value"
};


/*
 * Returns the string version of the provided #ExperimentType_t enumeration.
 */
LIBSEDML_EXTERN
const char*
ExperimentType_toString(ExperimentType_t et)
{
  int min = SEDML_EXPERIMENTTYPE_TIMECOURSE;
  int max = SEDML_EXPERIMENTTYPE_INVALID;

  if (et < min || et > max)
  {
    return "(Unknown ExperimentType value)";
  }

  return SEDML_EXPERIMENT_TYPE_STRINGS[et - min];
}


/*
 * Returns the #ExperimentType_t enumeration corresponding to the given string
 * or @sbmlconstant{SEDML_EXPERIMENTTYPE_INVALID, ExperimentType_t} if there is
 * no such match.
 */
LIBSEDML_EXTERN
ExperimentType_t
ExperimentType_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_EXPERIMENT_TYPE_STRINGS)/sizeof(SEDML_EXPERIMENT_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_EXPERIMENT_TYPE_STRINGS[i])
    {
      return (ExperimentType_t)(i);
    }
  }

  return SEDML_EXPERIMENTTYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #ExperimentType_t is valid.
 */
LIBSEDML_EXTERN
int
ExperimentType_isValid(ExperimentType_t et)
{
  int min = SEDML_EXPERIMENTTYPE_TIMECOURSE;
  int max = SEDML_EXPERIMENTTYPE_INVALID;

  if (et < min || et >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #ExperimentType_t.
 */
LIBSEDML_EXTERN
int
ExperimentType_isValidString(const char* code)
{
  return ExperimentType_isValid(ExperimentType_fromString(code));
}


static
const char* SEDML_AXIS_KIND_STRINGS[] =
{
  "linear"
, "log10"
, "invalid AxisKind value"
};


/*
 * Returns the string version of the provided #AxisKind_t enumeration.
 */
LIBSEDML_EXTERN
const char*
AxisKind_toString(AxisKind_t ak)
{
  int min = SEDML_AXISKIND_LINEAR;
  int max = SEDML_AXISKIND_INVALID;

  if (ak < min || ak > max)
  {
    return "(Unknown AxisKind value)";
  }

  return SEDML_AXIS_KIND_STRINGS[ak - min];
}


/*
 * Returns the #AxisKind_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_AXISKIND_INVALID, AxisKind_t} if there is no such match.
 */
LIBSEDML_EXTERN
AxisKind_t
AxisKind_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_AXIS_KIND_STRINGS)/sizeof(SEDML_AXIS_KIND_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_AXIS_KIND_STRINGS[i])
    {
      return (AxisKind_t)(i);
    }
  }

  return SEDML_AXISKIND_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #AxisKind_t is valid.
 */
LIBSEDML_EXTERN
int
AxisKind_isValid(AxisKind_t ak)
{
  int min = SEDML_AXISKIND_LINEAR;
  int max = SEDML_AXISKIND_INVALID;

  if (ak < min || ak >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #AxisKind_t.
 */
LIBSEDML_EXTERN
int
AxisKind_isValidString(const char* code)
{
  return AxisKind_isValid(AxisKind_fromString(code));
}


static
const char* SEDML_LINE_KIND_STRINGS[] =
{
  "none"
, "solid"
, "dash"
, "dot"
, "dashDot"
, "invalid LineKind value"
};


/*
 * Returns the string version of the provided #LineKind_t enumeration.
 */
LIBSEDML_EXTERN
const char*
LineKind_toString(LineKind_t lk)
{
  int min = SEDML_LINEKIND_NONE;
  int max = SEDML_LINEKIND_INVALID;

  if (lk < min || lk > max)
  {
    return "(Unknown LineKind value)";
  }

  return SEDML_LINE_KIND_STRINGS[lk - min];
}


/*
 * Returns the #LineKind_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_LINEKIND_INVALID, LineKind_t} if there is no such match.
 */
LIBSEDML_EXTERN
LineKind_t
LineKind_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_LINE_KIND_STRINGS)/sizeof(SEDML_LINE_KIND_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_LINE_KIND_STRINGS[i])
    {
      return (LineKind_t)(i);
    }
  }

  return SEDML_LINEKIND_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #LineKind_t is valid.
 */
LIBSEDML_EXTERN
int
LineKind_isValid(LineKind_t lk)
{
  int min = SEDML_LINEKIND_NONE;
  int max = SEDML_LINEKIND_INVALID;

  if (lk < min || lk >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #LineKind_t.
 */
LIBSEDML_EXTERN
int
LineKind_isValidString(const char* code)
{
  return LineKind_isValid(LineKind_fromString(code));
}


static
const char* SEDML_MARKER_KIND_STRINGS[] =
{
  "none"
, "square"
, "circle"
, "diamond"
, "xCross"
, "plus"
, "star"
, "triangleUp"
, "triangleDown"
, "triangleLeft"
, "triangleRight"
, "hDash"
, "vDash"
, "invalid MarkerKind value"
};


/*
 * Returns the string version of the provided #MarkerKind_t enumeration.
 */
LIBSEDML_EXTERN
const char*
MarkerKind_toString(MarkerKind_t mk)
{
  int min = SEDML_MARKERKIND_NONE;
  int max = SEDML_MARKERKIND_INVALID;

  if (mk < min || mk > max)
  {
    return "(Unknown MarkerKind value)";
  }

  return SEDML_MARKER_KIND_STRINGS[mk - min];
}


/*
 * Returns the #MarkerKind_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_MARKERKIND_INVALID, MarkerKind_t} if there is no such
 * match.
 */
LIBSEDML_EXTERN
MarkerKind_t
MarkerKind_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_MARKER_KIND_STRINGS)/sizeof(SEDML_MARKER_KIND_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_MARKER_KIND_STRINGS[i])
    {
      return (MarkerKind_t)(i);
    }
  }

  return SEDML_MARKERKIND_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MarkerKind_t is valid.
 */
LIBSEDML_EXTERN
int
MarkerKind_isValid(MarkerKind_t mk)
{
  int min = SEDML_MARKERKIND_NONE;
  int max = SEDML_MARKERKIND_INVALID;

  if (mk < min || mk >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MarkerKind_t.
 */
LIBSEDML_EXTERN
int
MarkerKind_isValidString(const char* code)
{
  return MarkerKind_isValid(MarkerKind_fromString(code));
}


static
const char* SEDML_CURVE_KIND_STRINGS[] =
{
  "points"
, "bar"
, "barStacked"
, "invalid CurveKind value"
};


/*
 * Returns the string version of the provided #CurveKind_t enumeration.
 */
LIBSEDML_EXTERN
const char*
CurveKind_toString(CurveKind_t ck)
{
  int min = SEDML_CURVEKIND_POINTS;
  int max = SEDML_CURVEKIND_INVALID;

  if (ck < min || ck > max)
  {
    return "(Unknown CurveKind value)";
  }

  return SEDML_CURVE_KIND_STRINGS[ck - min];
}


/*
 * Returns the #CurveKind_t enumeration corresponding to the given string or
 * @sbmlconstant{SEDML_CURVEKIND_INVALID, CurveKind_t} if there is no such
 * match.
 */
LIBSEDML_EXTERN
CurveKind_t
CurveKind_fromString(const char* code)
{
  static int size =
    sizeof(SEDML_CURVE_KIND_STRINGS)/sizeof(SEDML_CURVE_KIND_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SEDML_CURVE_KIND_STRINGS[i])
    {
      return (CurveKind_t)(i);
    }
  }

  return SEDML_CURVEKIND_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #CurveKind_t is valid.
 */
LIBSEDML_EXTERN
int
CurveKind_isValid(CurveKind_t ck)
{
  int min = SEDML_CURVEKIND_POINTS;
  int max = SEDML_CURVEKIND_INVALID;

  if (ck < min || ck >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #CurveKind_t.
 */
LIBSEDML_EXTERN
int
CurveKind_isValidString(const char* code)
{
  return CurveKind_isValid(CurveKind_fromString(code));
}




LIBSEDML_CPP_NAMESPACE_END


