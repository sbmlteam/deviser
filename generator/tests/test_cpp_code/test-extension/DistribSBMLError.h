/**
 * @file DistribSBMLError.h
 * @brief Definition of the DistribSBMLError class.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2017 jointly by the following organizations:
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


#ifndef DistribSBMLError_H__
#define DistribSBMLError_H__




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


typedef enum
{
  DistribUnknown                                              = 5010100
, DistribNSUndeclared                                         = 5010101
, DistribElementNotInNs                                       = 5010102
, DistribDuplicateComponentId                                 = 5010301
, DistribIdSyntaxRule                                         = 5010302
, DistribAttributeRequiredMissing                             = 5020101
, DistribAttributeRequiredMustBeBoolean                       = 5020102
, DistribAttributeRequiredMustHaveValue                       = 5020103
, DistribFunctionDefinitionAllowedElements                    = 5020201
, DistribSBaseAllowedElements                                 = 5020301
, DistribDrawFromDistributionAllowedCoreAttributes            = 5020401
, DistribDrawFromDistributionAllowedCoreElements              = 5020402
, DistribDrawFromDistributionAllowedElements                  = 5020403
, DistribDrawFromDistributionEmptyLOElements                  = 5020404
, DistribDrawFromDistributionLODistribInputsAllowedCoreElements= 5020405
, DistribDrawFromDistributionLODistribInputsAllowedCoreAttributes= 5020406
, DistribDistribInputAllowedCoreAttributes                    = 5020501
, DistribDistribInputAllowedCoreElements                      = 5020502
, DistribDistribInputAllowedAttributes                        = 5020503
, DistribDistribInputIdMustBeString                           = 5020504
, DistribDistribInputIndexMustBeNonNegativeInteger            = 5020505
, DistribDistribInputNameMustBeString                         = 5020506
, DistribUncertaintyOldAllowedCoreAttributes                  = 5020601
, DistribUncertaintyOldAllowedCoreElements                    = 5020602
, DistribUncertaintyOldAllowedAttributes                      = 5020603
, DistribUncertaintyOldAllowedElements                        = 5020604
, DistribUncertaintyOldNameMustBeString                       = 5020605
} DistribSBMLErrorCode_t;


END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !DistribSBMLError_H__ */


