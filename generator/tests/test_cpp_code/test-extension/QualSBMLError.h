/**
 * @file: QualSBMLError.h
 * @brief: Definition of QualSBMLError.
 * @author: SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2014 jointly by the following organizations:
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


#ifndef QualSBMLError_H__
#define QualSBMLError_H__




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


typdef enum
{
  QualUnknown                                                 = 3010100
, QualNSUndeclared                                            = 3010101
, QualElementNotInNs                                          = 3010102
, QualDuplicateComponentId                                    = 3010301
, QualAttributeRequiredMissing                                = 3020101
, QualAttributeRequiredMustBeBoolean                          = 3020202
, QualModelAllowedElements                                    = 3020201
, TBC                                                         = 3020202
, QualModelLOQualitativeSpeciesAllowedElements                = 3020203
, QualModelLOTransitionsAllowedElements                       = 3020204
, QualModelLOQualitativeSpeciesAllowedCoreAttributes          = 3020205
, QualModelLOTransitionsAllowedCoreAttributes                 = 3020206
, QualQualitativeSpeciesAllowedCoreAttributes                 = 3020301
, QualQualitativeSpeciesAllowedCoreElements                   = 3020302
, QualQualitativeSpeciesAllowedAttributes                     = 3020303
, QualQualitativeSpeciesCompartmentMustBeCompartment          = 3020304
, QualQualitativeSpeciesConstantMustBeBoolean                 = 3020305
, QualQualitativeSpeciesNameMustBeString                      = 3020306
, QualQualitativeSpeciesInitialLevelMustBeUnInteger           = 3020307
, QualQualitativeSpeciesMaxLevelMustBeUnInteger               = 3020308
, QualTransitionAllowedCoreAttributes                         = 3020401
, QualTransitionAllowedCoreElements                           = 3020402
, QualTransitionAllowedAttributes                             = 3020403
, QualTransitionAllowedElements                               = 3020404
, QualTransitionNameMustBeString                              = 3020405
, QualTransitionEmptyLOElements                               = 3020406
, QualTransitionLOInputsAllowedElements                       = 3020407
, QualTransitionLOOutputsAllowedElements                      = 3020408
, QualTransitionLOFunctionTermsAllowedElements                = 3020409
, QualTransitionLOInputsAllowedCoreAttributes                 = 3020410
, QualTransitionLOOutputsAllowedCoreAttributes                = 3020411
, QualTransitionLOFunctionTermsAllowedCoreAttributes          = 3020412
, QualInputAllowedCoreAttributes                              = 3020501
, QualInputAllowedCoreElements                                = 3020502
, QualInputAllowedAttributes                                  = 3020503
, QualInputQualitativeSpeciesMustBeQualitativeSpecies         = 3020504
, QualInputNameMustBeString                                   = 3020505
, QualInputSignMustBeSignEnum                                 = 3020506
, QualInputTransitionEffectMustBeTransitionInputEffectEnum    = 3020507
, QualInputThresholdLevelMustBeUnInteger                      = 3020508
, QualOutputAllowedCoreAttributes                             = 3020601
, QualOutputAllowedCoreElements                               = 3020602
, QualOutputAllowedAttributes                                 = 3020603
, QualOutputQualitativeSpeciesMustBeQualitativeSpecies        = 3020604
, QualOutputTransitionEffectMustBeTransitionOutputEffectEnum  = 3020605
, QualOutputNameMustBeString                                  = 3020606
, QualOutputOutputLevelMustBeInteger                          = 3020607
, QualDefaultTermAllowedCoreAttributes                        = 3020701
, QualDefaultTermAllowedCoreElements                          = 3020702
, QualDefaultTermAllowedAttributes                            = 3020703
, QualDefaultTermResultLevelMustBeUnInteger                   = 3020704
, QualFunctionTermAllowedCoreAttributes                       = 3020801
, QualFunctionTermAllowedCoreElements                         = 3020802
, QualFunctionTermAllowedAttributes                           = 3020803
, QualFunctionTermAllowedElements                             = 3020804
, QualFunctionTermResultLevelMustBeUnInteger                  = 3020805
} QualSBMLErrorCode_t;


END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !QualSBMLError_H__ */


