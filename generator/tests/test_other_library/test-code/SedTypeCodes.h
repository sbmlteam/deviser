/**
 * @file SedTypeCodes.h
 * @brief Definition of the SedTypeCodes class.
 * @author DEVISER
 *
 * @class 
 * @sbmlbrief{} TODO:Definition of the SedTypeCodes class.
 */



#ifndef SedTypeCodes_h
#define SedTypeCodes_h


#include <sedml/common/libsedml-config.h>
#include <sedml/common/extern.h>

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * @enum  SedTypeCode_t
 * @brief The enumeration of possible Sed core object types.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 *
 */
typedef enum
{
    SEDML_UNKNOWN                    =  0
  , SEDML_DOCUMENT
  , SEDML_MODEL
  , SEDML_CHANGE
  , SEDML_ADDXML
  , SEDML_TASK_SETVALUE
  , SEDML_DATAGENERATOR
  , SEDML_TASK_REPEATEDTASK
  , SEDML_SIMULATION
  , SEDML_LIST_OF
} SedTypeCode_t;



/**
 * This method takes an Sed type code and returns a string representing
 * the code.
 *
 * @if clike LibSEDML attaches an identifying code to every kind of Sed
 * object.  These are known as <em>Sed type codes</em>.  The set of
 * possible type codes is defined in the enumeration #SedTypeCode_t.
 * The names of the type codes all begin with the characters @c
 * SEDML_. @endif@if java LibSEDML attaches an identifying code to every
 * kind of Sed object.  These are known as <em>Sed type codes</em>.  In
 * other languages, the set of type codes is stored in an enumeration; in
 * the Java language interface for libSEDML, the type codes are defined as
 * static integer constants in the interface class {@link
 * libsedmlConstants}.  The names of the type codes all begin with the
 * characters @c SEDML_. @endif@if python LibSEDML attaches an identifying
 * code to every kind of Sed object.  These are known as <em>Sed type
 * codes</em>.  In the Python language interface for libSEDML, the type
 * codes are defined as static integer constants in the interface class
 * @link libsedml@endlink.  The names of the type codes all begin with the
 * characters @c SEDML_. @endif@if csharp LibSEDML attaches an identifying
 * code to every kind of Sed object.  These are known as <em>Sed type
 * codes</em>.  In the C# language interface for libSEDML, the type codes
 * are defined as static integer constants in the interface class @link
 * libsedml@endlink.  The names of the type codes all begin with
 * the characters @c SEDML_. @endif@~
 *
 * @return a human readable name for the given
 * @if clike #SedTypeCode_t value@else Sed type code@endif.
 *
 * @note The caller does not own the returned string and is therefore not
 * allowed to modify it.
 */
LIBSEDML_EXTERN
const char *
SedTypeCode_toString (int tc);


END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* SedTypeCodes_h */
