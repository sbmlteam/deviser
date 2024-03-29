#ifndef LIBSBML_COMMON_H
#define LIBSBML_COMMON_H 1


#include <sbml/common/libsbml-config.h>


#include <stdio.h>


#if STDC_HEADERS
#  include <errno.h>
#  include <float.h>
#  include <stdarg.h>
#  include <stdlib.h>
#  include <string.h>
#endif

#if HAVE_MATH_H
#  include <math.h>
#endif

#if HAVE_IEEFP_H
#  include <ieeefp.h>
#endif

#ifndef errno
  extern int errno;
#endif


/**
 * Default format used by libSBML when writing out floating-point numbers
 * into the XML produced by libSBML.  This is used by
 * StringBuffer_appendReal.
 */
#define LIBSBML_FLOAT_FORMAT "%.15g"

#define LIBSBML_DOUBLE_PRECISION 15

static const int SBML_INT_MAX = 2147483647;
static const int SBML_INT_MIN = -2147483647 - 1;

/*
 * Sometimes the line/column numbers reported by the underlying parsers are
 * simply invalid.  This especially occurs in error situations when the
 * error is severe.  Typically you're not supposed to call the parsers'
 * getline()/getcolumn() functions in those situations, but it's hard to
 * avoid because of the flow of control in our code.  The problem is, in
 * some cases, calling the parser's getline()/getcolumn() functions results
 * in a segmentation fault.  (Case in point: this was happening using
 * Xerces 2.8 on 32-bit systems.)  We need to communicate that a
 * line/column number value is actually invalid or meaningless.
 *
 * Doing that presents a new problem: our line/column number values are
 * unsigned integers, which thus only allows 2 states to be
 * communicated. (Explanation: you could use 0 to communicate an invalid
 * state and let all other values indicate a valid state.  If we had signed
 * integers, we could communicate 3 state values, using negative, 0, and
 * positive values for the different states.)  Unfortunately we can't use 0
 * because that value is already being used to communicate a different
 * meaning between users of XMLError objects.
 *
 * The following is a bit of a hack, but not completely unrealistic: we use
 * the largest possible value of the data type used to represent
 * line/column numbers.  The probability that an error in an file will
 * involve these specific numbers is vanishingly small.  Thus, we can say
 * that if user code encounters these values as line/column numbers, they
 * should assume they are actually meaningless and no valid line/column
 * number could be provided by the parser.
 */

#define LIBSBML_UNKNOWN_LINE	SBML_INT_MAX
#define LIBSBML_UNKNOWN_COLUMN	SBML_INT_MAX


#include <sbml/common/extern.h>
#include <sbml/util/util.h>
#include <sbml/common/SBMLOperationReturnValues.h>

#endif  /* LIBSBML_COMMON_H */
