/**
 * @file    libtsb-version.h
 * @brief   Define libTSB version numbers for access from client software.
 *
 */


#ifndef LIBTSB_VERSION_H
#define LIBTSB_VERSION_H 

#include <tsb/common/extern.h>


/**
 * LIBTSB_DOTTED_VERSION:
 *
 * A version string of the form "1.2.3".
 */
#define LIBTSB_DOTTED_VERSION	"@PACKAGE_VERSION@"


/**
 * LIBTSB_VERSION:
 *
 * The version as an integer: version 1.2.3 becomes 10203.  Since the major
 * number comes first, the overall number will always increase when a new
 * libTSB is released, making it easy to use less-than and greater-than
 * comparisons when testing versions numbers.
 */
#define LIBTSB_VERSION		@LIBTSB_VERSION_NUMERIC@


/**
 * LIBTSB_VERSION_STRING:
 *
 * The numeric version as a string: version 1.2.3 becomes "10203".
 */
#define LIBTSB_VERSION_STRING	"@LIBTSB_VERSION_NUMERIC@"


LIBTSB_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * Returns the version number of this copy of libTSB as an integer.
 *
 * @return the libTSB version as an integer; version 1.2.3 becomes 10203.
 */
LIBTSB_EXTERN
int 
getLibTSBVersion();


/**
 * Returns the version number of this copy of libTSB as a string.
 *
 * @return the libTSB version as a string; version 1.2.3 becomes
 * "1.2.3".
 *
 * @see getLibTSBVersionString()
 */
LIBTSB_EXTERN
const char* 
getLibTSBDottedVersion();


/**
 * Returns the version number of this copy of libTSB as a string without
 * periods.
 *
 * @return the libTSB version as a string: version 1.2.3 becomes "10203".
 *
 * @see getLibTSBDottedVersion()
 */
LIBTSB_EXTERN
const char* 
getLibTSBVersionString();


END_C_DECLS
LIBTSB_CPP_NAMESPACE_END

#endif  /* LIBTSB_VERSION_H */
