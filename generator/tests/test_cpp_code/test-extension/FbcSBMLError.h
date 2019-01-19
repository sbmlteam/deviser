/**
 * @file FbcSBMLError.h
 * @brief Definition of the FbcSBMLError class.
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


#ifndef FbcSBMLError_H__
#define FbcSBMLError_H__




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * @enum FbcSBMLErrorCode_t
 * Codes for all SBML-level errors and warnings from the 'fbc' package.
 *
 * These are distinguished from other SBML error codes by having a number
 * between 2000000 and 2099999.
 *
 * @copydetails doc_sbml_error_code_ranges
 */
typedef enum
{
  FbcUnknown                                                  = 2010100
, FbcNSUndeclared                                             = 2010101
, FbcElementNotInNs                                           = 2010102
, FbcDuplicateComponentId                                     = 2010301
, FbcIdSyntaxRule                                             = 2010302
, FbcAttributeRequiredMissing                                 = 2020101
, FbcAttributeRequiredMustBeBoolean                           = 2020102
, FbcAttributeRequiredMustHaveValue                           = 2020103
, FbcModelAllowedAttributes                                   = 2020201
, FbcModelAllowedElements                                     = 2020202
, FbcModelStrictMustBeBoolean                                 = 2020203
, FbcModelEmptyLOElements                                     = 2020204
, FbcModelLOObjectivesAllowedCoreElements                     = 2020205
, FbcModelLOFluxBoundsAllowedCoreElements                     = 2020206
, FbcModelLOGeneProductsAllowedCoreElements                   = 2020207
, FbcModelLOObjectivesAllowedCoreAttributes                   = 2020208
, FbcModelLOFluxBoundsAllowedCoreAttributes                   = 2020209
, FbcModelLOGeneProductsAllowedCoreAttributes                 = 2020210
, FbcModelLOObjectivesAllowedAttributes                       = 2020211
, FbcModelActiveObjectiveMustBeObjective                      = 2020212
, FbcSpeciesAllowedAttributes                                 = 2020301
, FbcSpeciesChargeMustBeInteger                               = 2020302
, FbcSpeciesChemicalFormulaMustBeString                       = 2020303
, FbcReactionAllowedAttributes                                = 2020401
, FbcReactionAllowedElements                                  = 2020402
, FbcReactionLowerFluxBoundMustBeParameter                    = 2020403
, FbcReactionUpperFluxBoundMustBeParameter                    = 2020404
, FbcFluxBoundAllowedCoreAttributes                           = 2020501
, FbcFluxBoundAllowedCoreElements                             = 2020502
, FbcFluxBoundAllowedAttributes                               = 2020503
, FbcFluxBoundReactionMustBeReaction                          = 2020504
, FbcFluxBoundOperationMustBeFbcOperationEnum                 = 2020505
, FbcFluxBoundValueMustBeDouble                               = 2020506
, FbcFluxBoundNameMustBeString                                = 2020507
, FbcObjectiveAllowedCoreAttributes                           = 2020601
, FbcObjectiveAllowedCoreElements                             = 2020602
, FbcObjectiveAllowedAttributes                               = 2020603
, FbcObjectiveAllowedElements                                 = 2020604
, FbcObjectiveTypeMustBeFbcTypeEnum                           = 2020605
, FbcObjectiveNameMustBeString                                = 2020607
, FbcObjectiveEmptyLOElements                                 = 2020609
, FbcObjectiveLOFluxObjectivesAllowedCoreElements             = 2020610
, FbcObjectiveLOFluxObjectivesAllowedCoreAttributes           = 2020612
, FbcObjectiveLOObjectivesAllowedAttributes                   = 2020614
, FbcLOObjectivesActiveObjectiveMustBeObjective               = 2020615
, FbcFluxObjectiveAllowedCoreAttributes                       = 2020701
, FbcFluxObjectiveAllowedCoreElements                         = 2020702
, FbcFluxObjectiveAllowedAttributes                           = 2020703
, FbcFluxObjectiveReactionMustBeReaction                      = 2020704
, FbcFluxObjectiveCoefficientMustBeDouble                     = 2020705
, FbcFluxObjectiveNameMustBeString                            = 2020708
, FbcGeneProductAllowedCoreAttributes                         = 2020801
, FbcGeneProductAllowedCoreElements                           = 2020802
, FbcGeneProductAllowedAttributes                             = 2020803
, FbcGeneProductLabelMustBeString                             = 2020804
, FbcGeneProductNameMustBeString                              = 2020805
, FbcGeneProductAssociatedSpeciesMustBeSpecies                = 2020806
, FbcGeneProductRefAllowedCoreAttributes                      = 2020901
, FbcGeneProductRefAllowedCoreElements                        = 2020902
, FbcGeneProductRefAllowedAttributes                          = 2020903
, FbcGeneProductRefNameMustBeString                           = 2020904
, FbcGeneProductRefGeneProductMustBeGeneProduct               = 2020905
, FbcAndAllowedCoreAttributes                                 = 2021001
, FbcAndAllowedCoreElements                                   = 2021002
, FbcAndAllowedElements                                       = 2021003
, FbcOrAllowedCoreAttributes                                  = 2021101
, FbcOrAllowedCoreElements                                    = 2021102
, FbcOrAllowedElements                                        = 2021103
, FbcAssociationAllowedCoreAttributes                         = 2021201
, FbcAssociationAllowedCoreElements                           = 2021202
, FbcGeneProductAssociationAllowedCoreAttributes              = 2021301
, FbcGeneProductAssociationAllowedCoreElements                = 2021302
, FbcGeneProductAssociationAllowedAttributes                  = 2021303
, FbcGeneProductAssociationAllowedElements                    = 2021304
, FbcGeneProductAssociationNameMustBeString                   = 2021305
} FbcSBMLErrorCode_t;


END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !FbcSBMLError_H__ */


