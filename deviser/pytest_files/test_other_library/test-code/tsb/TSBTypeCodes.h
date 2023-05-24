/**
 * @file TSBTypeCodes.h
 * @brief Definition of the TSBTypeCodes class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class TSBTypeCodes
 * @sbmlbrief{} TODO:Definition of the TSBTypeCodes class.
 */



#ifndef TSBTypeCodes_h
#define TSBTypeCodes_h


#include <tsb/common/libtsb-config.h>
#include <tsb/common/extern.h>

LIBTSB_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * @enum  TSBTypeCode_t
 * @brief The enumeration of possible TSB core object types.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 *
 */
typedef enum
{
    TSB_UNKNOWN                    =  0
  , TSB_DOCUMENT
  , TSB_COMMENT
  , TSB_LIST_OF
} TSBTypeCode_t;



/**
 * This method takes an TSB type code and returns a string representing
 * the code.
 *
 * @if clike LibTSB attaches an identifying code to every kind of TSB
 * object.  These are known as <em>TSB type codes</em>.  The set of
 * possible type codes is defined in the enumeration #TSBTypeCode_t.
 * The names of the type codes all begin with the characters @c
 * TSB_. @endif@if java LibTSB attaches an identifying code to every
 * kind of TSB object.  These are known as <em>TSB type codes</em>.  In
 * other languages, the set of type codes is stored in an enumeration; in
 * the Java language interface for libTSB, the type codes are defined as
 * static integer constants in the interface class {@link
 * libtsbConstants}.  The names of the type codes all begin with the
 * characters @c TSB_. @endif@if python LibTSB attaches an identifying
 * code to every kind of TSB object.  These are known as <em>TSB type
 * codes</em>.  In the Python language interface for libTSB, the type
 * codes are defined as static integer constants in the interface class
 * @link libtsb@endlink.  The names of the type codes all begin with the
 * characters @c TSB_. @endif@if csharp LibTSB attaches an identifying
 * code to every kind of TSB object.  These are known as <em>TSB type
 * codes</em>.  In the C# language interface for libTSB, the type codes
 * are defined as static integer constants in the interface class @link
 * libtsb@endlink.  The names of the type codes all begin with
 * the characters @c TSB_. @endif@~
 *
 * @return a human readable name for the given
 * @if clike #TSBTypeCode_t value@else TSB type code@endif.
 *
 * @note The caller does not own the returned string and is therefore not
 * allowed to modify it.
 */
LIBTSB_EXTERN
const char *
TSBTypeCode_toString (int tc);


END_C_DECLS
LIBTSB_CPP_NAMESPACE_END

#endif  /* TSBTypeCodes_h */
