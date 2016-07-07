
#ifndef SBMLTypeCodes_h
#define SBMLTypeCodes_h


#include <sbml/common/libsbml-config.h>
#include <sbml/common/extern.h>

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * @enum  SBMLTypeCode_t
 * @brief The enumeration of possible SBML_Lang core object types.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 *
 */
typedef enum
{
    SBML_UNKNOWN                    =  0
  , SBML_DOCUMENT
<insert_type_codes/>
  , SBML_LIST_OF
} SBMLTypeCode_t;



/**
 * This method takes an SBML_Lang type code and returns a string representing
 * the code.
 *
 * @if clike LibSBML attaches an identifying code to every kind of SBML_Lang
 * object.  These are known as <em>SBML_Lang type codes</em>.  The set of
 * possible type codes is defined in the enumeration #SBMLTypeCode_t.
 * The names of the type codes all begin with the characters @c
 * SBML_. @endif@if java LibSBML attaches an identifying code to every
 * kind of SBML_Lang object.  These are known as <em>SBML_Lang type codes</em>.  In
 * other languages, the set of type codes is stored in an enumeration; in
 * the Java language interface for libSBML, the type codes are defined as
 * static integer constants in the interface class {@link
 * libsbmlConstants}.  The names of the type codes all begin with the
 * characters @c SBML_. @endif@if python LibSBML attaches an identifying
 * code to every kind of SBML_Lang object.  These are known as <em>SBML_Lang type
 * codes</em>.  In the Python language interface for libSBML, the type
 * codes are defined as static integer constants in the interface class
 * @link libsbml@endlink.  The names of the type codes all begin with the
 * characters @c SBML_. @endif@if csharp LibSBML attaches an identifying
 * code to every kind of SBML_Lang object.  These are known as <em>SBML_Lang type
 * codes</em>.  In the C# language interface for libSBML, the type codes
 * are defined as static integer constants in the interface class @link
 * libsbml@endlink.  The names of the type codes all begin with
 * the characters @c SBML_. @endif@~
 *
 * @return a human readable name for the given
 * @if clike #SBMLTypeCode_t value@else SBML_Lang type code@endif.
 *
 * @note The caller does not own the returned string and is therefore not
 * allowed to modify it.
 */
LIBSBML_EXTERN
const char *
SBMLTypeCode_toString (int tc);


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /* SBMLTypeCodes_h */
