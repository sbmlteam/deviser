/**
 * @file RefsSBMLError.h
 * @brief Definition of the RefsSBMLError class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
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


#ifndef RefsSBMLError_H__
#define RefsSBMLError_H__




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * @enum RefsSBMLErrorCode_t
 * Codes for all SBML-level errors and warnings from the 'refs' package.
 *
 * These are distinguished from other SBML error codes by having a number
 * between 100000 and 199999.
 *
 * @copydetails doc_sbml_error_code_ranges
 */
typedef enum
{
  RefsUnknown                                                 = 110100
, RefsNSUndeclared                                            = 110101
, RefsElementNotInNs                                          = 110102
, RefsDuplicateComponentId                                    = 110301
, RefsIdSyntaxRule                                            = 110302
, RefsAttributeRequiredMissing                                = 120101
, RefsAttributeRequiredMustBeBoolean                          = 120102
, RefsAttributeRequiredMustHaveValue                          = 120103
, RefsModelAllowedElements                                    = 120201
, RefsModelEmptyLOElements                                    = 120202
, RefsModelLOThingCsAllowedCoreElements                       = 120203
, RefsModelLOThingCsAllowedCoreAttributes                     = 120204
, RefsThingAAllowedCoreAttributes                             = 120301
, RefsThingAAllowedCoreElements                               = 120302
, RefsThingAAllowedAttributes                                 = 120303
, RefsThingBAllowedCoreAttributes                             = 120401
, RefsThingBAllowedCoreElements                               = 120402
, RefsThingBAllowedAttributes                                 = 120403
, RefsThingCAllowedCoreAttributes                             = 120501
, RefsThingCAllowedCoreElements                               = 120502
, RefsThingCAllowedAttributes                                 = 120503
, RefsThingCThingMustBeThingAOrThingB                         = 120504
} RefsSBMLErrorCode_t;


END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !RefsSBMLError_H__ */


