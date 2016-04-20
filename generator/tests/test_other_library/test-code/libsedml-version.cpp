/**
 * @file libsedml-version.cpp
 * @brief Implementation of the libsedml-version class.
 * @author DEVISER
 */



#include "sedml/common/libsedml-version.h"
#include <string.h>


LIBSEDML_CPP_NAMESPACE_BEGIN

LIBSEDML_EXTERN
int 
getLibSEDMLVersion() 
{ 
  return LIBSEDML_VERSION; 
}


LIBSEDML_EXTERN
const char* 
getLibSEDMLDottedVersion() 
{ 
  return LIBSEDML_DOTTED_VERSION;
}


LIBSEDML_EXTERN
const char* 
getLibSEDMLVersionString() 
{ 
  return LIBSEDML_VERSION_STRING;
}

LIBSEDML_CPP_NAMESPACE_END


