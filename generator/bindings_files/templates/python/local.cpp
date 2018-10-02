
#include <cstddef>
#include "sbml/SBase.h"

/**
* @return the most specific Swig type for the given SBase object.
*/
struct swig_type_info*
GetDowncastSwigType (SBase* sb)
{
  if (sb == 0) return SWIGTYPE_p_SBase;

  std::string name;

  switch (sb->getTypeCode())
  {
  case SBML_DOCUMENT:
    return SWIGTYPE_p_SBMLDocument;

<insert_derived_types/>
    case SBML_LIST_OF:
      name = sb->getElementName();
      if(name == "listOf")
      {
        return SWIGTYPE_p_ListOf;
      }
<insert_derived_listof_types/>           
    
    return SWIGTYPE_p_ListOf;
    
  default:
    return SWIGTYPE_p_SBase;
  }

  return SWIGTYPE_p_SBase;
}

/* Compatibility bug fix for swig 2.0.7 and Python 3. 
* See http://patch-tracker.debian.org/patch/series/view/swig2.0/2.0.7-3/pyint_fromsize_t.diff
*/
#if (PY_MAJOR_VERSION >= 3)
#define PyInt_FromSize_t(x) PyLong_FromSize_t(x)
#endif
