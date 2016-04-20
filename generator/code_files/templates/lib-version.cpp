
#include "sbml/common/libsbml-version.h"
#include <string.h>


LIBSBML_CPP_NAMESPACE_BEGIN

LIBSBML_EXTERN
int 
getLibSBMLVersion() 
{ 
  return LIBSBML_VERSION; 
}


LIBSBML_EXTERN
const char* 
getLibSBMLDottedVersion() 
{ 
  return LIBSBML_DOTTED_VERSION;
}


LIBSBML_EXTERN
const char* 
getLibSBMLVersionString() 
{ 
  return LIBSBML_VERSION_STRING;
}

LIBSBML_CPP_NAMESPACE_END


