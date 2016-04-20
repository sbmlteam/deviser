/**
 * @file SedTypeCodes.cpp
 * @brief Implementation of the SedTypeCodes class.
 * @author DEVISER
 */



#include <sedml/common/common.h>
#include <sedml/SedTypeCodes.h>

LIBSEDML_CPP_NAMESPACE_BEGIN

static
const char* SEDML_TYPE_CODE_STRINGS[] =
{
    "(Unknown Sed Type)"
  , "SedDocument"
  , "Model"
  , "Change"
  , "AddXML"
  , "SedListOf"
};


LIBSEDML_EXTERN
const char *
SedTypeCode_toString (int tc)
{
  int max = SEDML_LIST_OF;

  if (tc < SEDML_DOCUMENT || tc > max)
  {
    tc = SEDML_UNKNOWN;
  }

  return SEDML_TYPE_CODE_STRINGS[tc];
}

LIBSEDML_CPP_NAMESPACE_END

