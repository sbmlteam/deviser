
#ifndef LIBSBML_VERSION_H
#define LIBSBML_VERSION_H 

#include <sbml/common/extern.h>


/**
 * LIBSBML_DOTTED_VERSION:
 *
 * A version string of the form "1.2.3".
 */
#define LIBSBML_DOTTED_VERSION	"@PACKAGE_VERSION@"


/**
 * LIBSBML_VERSION:
 *
 * The version as an integer: version 1.2.3 becomes 10203.  Since the major
 * number comes first, the overall number will always increase when a new
 * libSBML is released, making it easy to use less-than and greater-than
 * comparisons when testing versions numbers.
 */
#define LIBSBML_VERSION		@LIBSBML_VERSION_NUMERIC@


/**
 * LIBSBML_VERSION_STRING:
 *
 * The numeric version as a string: version 1.2.3 becomes "10203".
 */
#define LIBSBML_VERSION_STRING	"@LIBSBML_VERSION_NUMERIC@"


LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * Returns the version number of this copy of libSBML as an integer.
 *
 * @return the libSBML version as an integer; version 1.2.3 becomes 10203.
 */
LIBSBML_EXTERN
int 
getLibSBMLVersion();


/**
 * Returns the version number of this copy of libSBML as a string.
 *
 * @return the libSBML version as a string; version 1.2.3 becomes
 * "1.2.3".
 *
 * @see getLibSBMLVersionString()
 */
LIBSBML_EXTERN
const char* 
getLibSBMLDottedVersion();


/**
 * Returns the version number of this copy of libSBML as a string without
 * periods.
 *
 * @return the libSBML version as a string: version 1.2.3 becomes "10203".
 *
 * @see getLibSBMLDottedVersion()
 */
LIBSBML_EXTERN
const char* 
getLibSBMLVersionString();


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /* LIBSBML_VERSION_H */
