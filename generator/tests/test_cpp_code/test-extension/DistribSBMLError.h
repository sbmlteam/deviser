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
  DistribUnknown                                              = 1510100
, DistribNSUndeclared                                         = 1510101
, DistribElementNotInNs                                       = 1510102
, DistribDuplicateComponentId                                 = 1510301
, DistribIdSyntaxRule                                         = 1510302
, DistribAttributeRequiredMissing                             = 1520101
, DistribAttributeRequiredMustBeBoolean                       = 1520102
, DistribAttributeRequiredMustHaveValue                       = 1520103
, DistribFunctionDefinitionAllowedElements                    = 1520201
, DistribDrawFromDistributionAllowedCoreAttributes            = 1520401
, DistribDrawFromDistributionAllowedCoreElements              = 1520402
, DistribDrawFromDistributionAllowedElements                  = 1520403
, DistribDrawFromDistributionLODistribInputsAllowedCoreElements= 1520404
, DistribDrawFromDistributionLODistribInputsAllowedCoreAttributes= 1520405
, DistribDistribInputAllowedCoreAttributes                    = 1520501
, DistribDistribInputAllowedCoreElements                      = 1520502
, DistribDistribInputAllowedAttributes                        = 1520503
, DistribDistribInputNameMustBeString                         = 1520504
, DistribDistribInputIndexMustBeNonNegativeInteger            = 1520505
, DistribDistributionAllowedCoreAttributes                    = 1520601
, DistribDistributionAllowedCoreElements                      = 1520602
, DistribUnivariateDistributionAllowedCoreAttributes          = 1520701
, DistribUnivariateDistributionAllowedCoreElements            = 1520702
, DistribMultivariateDistributionAllowedCoreAttributes        = 1520801
, DistribMultivariateDistributionAllowedCoreElements          = 1520802
, DistribContinuousUnivariateDistributionAllowedCoreAttributes= 1520901
, DistribContinuousUnivariateDistributionAllowedCoreElements  = 1520902
, DistribContinuousUnivariateDistributionAllowedElements      = 1520903
, DistribDiscreteUnivariateDistributionAllowedCoreAttributes  = 1521001
, DistribDiscreteUnivariateDistributionAllowedCoreElements    = 1521002
, DistribDiscreteUnivariateDistributionAllowedElements        = 1521003
, DistribCategoricalUnivariateDistributionAllowedCoreAttributes= 1521101
, DistribCategoricalUnivariateDistributionAllowedCoreElements = 1521102
, DistribUncertValueAllowedCoreAttributes                     = 1521201
, DistribUncertValueAllowedCoreElements                       = 1521202
, DistribUncertValueAllowedAttributes                         = 1521203
, DistribUncertValueValueMustBeDouble                         = 1521204
, DistribUncertValueVarMustBeSBase                            = 1521205
, DistribUncertValueUnitsMustBeUnitSId                        = 1521206
, DistribUncertBoundAllowedCoreAttributes                     = 1521301
, DistribUncertBoundAllowedCoreElements                       = 1521302
, DistribUncertBoundAllowedAttributes                         = 1521303
, DistribUncertBoundInclusiveMustBeBoolean                    = 1521304
, DistribExternalDistributionAllowedCoreAttributes            = 1521401
, DistribExternalDistributionAllowedCoreElements              = 1521402
, DistribExternalDistributionAllowedAttributes                = 1521403
, DistribExternalDistributionAllowedElements                  = 1521404
, DistribExternalDistributionDefinitionURLMustBeString        = 1521405
, DistribExternalDistributionLOExternalParametersAllowedCoreElements= 1521406
, DistribExternalDistributionLOExternalParametersAllowedCoreAttributes= 1521407
, DistribExternalParameterAllowedCoreAttributes               = 1521501
, DistribExternalParameterAllowedCoreElements                 = 1521502
, DistribExternalParameterAllowedAttributes                   = 1521503
, DistribExternalParameterAllowedElements                     = 1521504
, DistribExternalParameterDefinitionURLMustBeString           = 1521505
, DistribExternalParameterLOExternalParametersAllowedCoreElements= 1521506
, DistribExternalParameterLOExternalParametersAllowedCoreAttributes= 1521507
, DistribNormalDistributionAllowedCoreAttributes              = 1521601
, DistribNormalDistributionAllowedCoreElements                = 1521602
, DistribNormalDistributionAllowedElements                    = 1521603
, DistribCategoricalDistributionAllowedCoreAttributes         = 1521701
, DistribCategoricalDistributionAllowedCoreElements           = 1521702
, DistribCategoricalDistributionAllowedElements               = 1521703
, DistribCategoricalDistributionEmptyReqdLOElements           = 1521704
, DistribCategoricalDistributionLOCategoriesAllowedCoreElements= 1521705
, DistribCategoricalDistributionLOCategoriesAllowedCoreAttributes= 1521706
, DistribCategoryAllowedCoreAttributes                        = 1521801
, DistribCategoryAllowedCoreElements                          = 1521802
, DistribCategoryAllowedAttributes                            = 1521803
, DistribCategoryAllowedElements                              = 1521804
, DistribCategoryRankMustBeNonNegativeInteger                 = 1521805
, DistribBernoulliDistributionAllowedCoreAttributes           = 1521901
, DistribBernoulliDistributionAllowedCoreElements             = 1521902
, DistribBernoulliDistributionAllowedElements                 = 1521903
, DistribBetaDistributionAllowedCoreAttributes                = 1522001
, DistribBetaDistributionAllowedCoreElements                  = 1522002
, DistribBetaDistributionAllowedElements                      = 1522003
, DistribBinomialDistributionAllowedCoreAttributes            = 1522101
, DistribBinomialDistributionAllowedCoreElements              = 1522102
, DistribBinomialDistributionAllowedElements                  = 1522103
, DistribCauchyDistributionAllowedCoreAttributes              = 1522201
, DistribCauchyDistributionAllowedCoreElements                = 1522202
, DistribCauchyDistributionAllowedElements                    = 1522203
, DistribGeometricDistributionAllowedCoreAttributes           = 1522301
, DistribGeometricDistributionAllowedCoreElements             = 1522302
, DistribGeometricDistributionAllowedElements                 = 1522303
, DistribLogisticDistributionAllowedCoreAttributes            = 1522401
, DistribLogisticDistributionAllowedCoreElements              = 1522402
, DistribLogisticDistributionAllowedElements                  = 1522403
, DistribUncertaintyAllowedCoreAttributes                     = 1522501
, DistribUncertaintyAllowedCoreElements                       = 1522502
, DistribUncertaintyAllowedElements                           = 1522503
, DistribUncertStatisticsAllowedCoreAttributes                = 1522601
, DistribUncertStatisticsAllowedCoreElements                  = 1522602
, DistribUncertStatisticsAllowedElements                      = 1522603
, DistribUncertStatisticsLOExternalParametersAllowedCoreElements= 1522604
, DistribUncertStatisticsLOExternalParametersAllowedCoreAttributes= 1522605
, DistribExponentialDistributionAllowedCoreAttributes         = 1522701
, DistribExponentialDistributionAllowedCoreElements           = 1522702
, DistribExponentialDistributionAllowedElements               = 1522703
} DistribSBMLErrorCode_t;


END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !DistribSBMLError_H__ */


