/**
 * @file tsbfwd.h
 * @brief Definition of tsbfwd.
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
 */


#ifndef tsbfwd_H__
#define tsbfwd_H__


#include <tsb/common/libtsb-namespace.h>

/**
 * Forward declaration of all opaque C types.
 *
 * Declaring all types up-front avoids "redefinition of type Foo" compile
 * errors and allows our combined C/C++ headers to depend minimally upon each
 * other. Put another way, the type definitions below serve the same purpose as
 * "class Foo;" forward declarations in C++ code.
 */

#ifdef __cplusplus
# define CLASS_OR_STRUCT class
#else
# define CLASS_OR_STRUCT struct
#endif /* __cplusplus */


LIBTSB_CPP_NAMESPACE_BEGIN


typedef CLASS_OR_STRUCT TSBDocument        TSBDocument_t;
typedef CLASS_OR_STRUCT TSBComment         TSBComment_t;
typedef CLASS_OR_STRUCT TSBBase            TSBBase_t;
typedef CLASS_OR_STRUCT TSBListOf          TSBListOf_t;
typedef CLASS_OR_STRUCT TSBReader          TSBReader_t;
typedef CLASS_OR_STRUCT TSBWriter          TSBWriter_t;
typedef CLASS_OR_STRUCT TSBNamespaces      TSBNamespaces_t;
typedef CLASS_OR_STRUCT TSBError           TSBError_t;
typedef CLASS_OR_STRUCT List               List_t;
typedef CLASS_OR_STRUCT ListNode           ListNode_t;
typedef CLASS_OR_STRUCT ExpectedAttributes ExpectedAttributes_t;


LIBTSB_CPP_NAMESPACE_END


#undef CLASS_OR_STRUCT


#endif /* !tsbfwd_H__ */


