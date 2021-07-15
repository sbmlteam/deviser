
#include <sbml/common/common.h>
#include <sbml/SBMLTypeCodes.h>

LIBSBML_CPP_NAMESPACE_BEGIN

static
const char* SBML_TYPE_CODE_STRINGS[] =
{
    "(Unknown SBML_Lang Type)"
<insert_type_strings/>
  , "ListOf"
};


LIBSBML_EXTERN
const char *
SBMLTypeCode_toString (int tc)
{
  int max = SBML_LIST_OF;

  if (tc < SBML_UNKNOWN + 1 || tc > max)
  {
    tc = SBML_UNKNOWN;
  }

  return SBML_TYPE_CODE_STRINGS[tc];
}

LIBSBML_CPP_NAMESPACE_END

