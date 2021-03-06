/**
 * @file RenderSBMLError.h
 * @brief Definition of the RenderSBMLError class.
 * @author SBMLTeam
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


#ifndef RenderSBMLError_H__
#define RenderSBMLError_H__




LIBSBML_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * @enum RenderSBMLErrorCode_t
 * Codes for all SBML-level errors and warnings from the 'render' package.
 *
 * These are distinguished from other SBML error codes by having a number
 * between 1300000 and 1399999.
 *
 * @copydetails doc_sbml_error_code_ranges
 */
typedef enum
{
  RenderUnknown                                               = 1310100
, RenderNSUndeclared                                          = 1310101
, RenderElementNotInNs                                        = 1310102
, RenderDuplicateComponentId                                  = 1310301
, RenderIdSyntaxRule                                          = 1310302
, RenderAttributeRequiredMissing                              = 1320101
, RenderAttributeRequiredMustBeBoolean                        = 1320102
, RenderAttributeRequiredMustHaveValue                        = 1320103
, RenderGraphicalObjectAllowedAttributes                      = 1320201
, RenderGraphicalObjectObjectRoleMustBeString                 = 1320202
, RenderLayoutAllowedElements                                 = 1320301
, RenderLayoutEmptyLOElements                                 = 1320302
, RenderLayoutLOLocalRenderInformationAllowedCoreElements     = 1320303
, RenderLayoutLOLocalRenderInformationAllowedCoreAttributes   = 1320304
, RenderLayoutLOLocalRenderInformationAllowedAttributes       = 1320305
, RenderLayoutVersionMajorMustBeNonNegativeInteger            = 1320306
, RenderLayoutVersionMinorMustBeNonNegativeInteger            = 1320307
, RenderLayoutDefaultValuesMustBeString                       = 1320308
, RenderListOfLayoutsAllowedElements                          = 1320401
, RenderListOfLayoutsEmptyLOElements                          = 1320402
, RenderListOfLayoutsLOGlobalRenderInformationAllowedCoreElements= 1320403
, RenderListOfLayoutsLOGlobalRenderInformationAllowedCoreAttributes= 1320404
, RenderListOfLayoutsLOGlobalRenderInformationAllowedAttributes= 1320405
, RenderListOfLayoutsVersionMajorMustBeNonNegativeInteger     = 1320406
, RenderListOfLayoutsVersionMinorMustBeNonNegativeInteger     = 1320407
, RenderListOfLayoutsDefaultValuesMustBeString                = 1320408
, RenderColorDefinitionAllowedCoreAttributes                  = 1320501
, RenderColorDefinitionAllowedCoreElements                    = 1320502
, RenderColorDefinitionAllowedAttributes                      = 1320503
, RenderColorDefinitionValueMustBeString                      = 1320504
, RenderColorDefinitionNameMustBeString                       = 1320505
, RenderEllipseAllowedCoreAttributes                          = 1320601
, RenderEllipseAllowedCoreElements                            = 1320602
, RenderEllipseAllowedAttributes                              = 1320603
, RenderEllipseCxMustBeString                                 = 1320604
, RenderEllipseCyMustBeString                                 = 1320605
, RenderEllipseRxMustBeString                                 = 1320606
, RenderEllipseRatioMustBeDouble                              = 1320607
, RenderEllipseCzMustBeString                                 = 1320608
, RenderEllipseRyMustBeString                                 = 1320609
, RenderGlobalRenderInformationAllowedCoreAttributes          = 1320701
, RenderGlobalRenderInformationAllowedCoreElements            = 1320702
, RenderGlobalRenderInformationAllowedElements                = 1320703
, RenderGlobalRenderInformationEmptyLOElements                = 1320704
, RenderGlobalRenderInformationLOGlobalStylesAllowedCoreElements= 1320705
, RenderGlobalRenderInformationLOGlobalStylesAllowedCoreAttributes= 1320706
, RenderGlobalStyleAllowedCoreAttributes                      = 1320801
, RenderGlobalStyleAllowedCoreElements                        = 1320802
, RenderGradientBaseAllowedCoreAttributes                     = 1320901
, RenderGradientBaseAllowedCoreElements                       = 1320902
, RenderGradientBaseAllowedAttributes                         = 1320903
, RenderGradientBaseAllowedElements                           = 1320904
, RenderGradientBaseNameMustBeString                          = 1320905
, RenderGradientBaseSpreadMethodMustBeGradientSpreadMethodEnum= 1320906
, RenderGradientStopAllowedCoreAttributes                     = 1321001
, RenderGradientStopAllowedCoreElements                       = 1321002
, RenderGradientStopAllowedAttributes                         = 1321003
, RenderGradientStopStopColorMustBeString                     = 1321004
, RenderGradientStopOffsetMustBeString                        = 1321005
, RenderRenderGroupAllowedCoreAttributes                      = 1321101
, RenderRenderGroupAllowedCoreElements                        = 1321102
, RenderRenderGroupAllowedAttributes                          = 1321103
, RenderRenderGroupAllowedElements                            = 1321104
, RenderRenderGroupStartHeadMustBeLineEnding                  = 1321105
, RenderRenderGroupEndHeadMustBeLineEnding                    = 1321106
, RenderRenderGroupFontFamilyMustBeString                     = 1321107
, RenderRenderGroupFontWeightMustBeFontWeightEnum             = 1321108
, RenderRenderGroupFontStyleMustBeFontStyleEnum               = 1321109
, RenderRenderGroupTextAnchorMustBeHTextAnchorEnum            = 1321110
, RenderRenderGroupVtextAnchorMustBeVTextAnchorEnum           = 1321111
, RenderRenderGroupFontSizeMustBeString                       = 1321112
, RenderImageAllowedCoreAttributes                            = 1321201
, RenderImageAllowedCoreElements                              = 1321202
, RenderImageAllowedAttributes                                = 1321203
, RenderImageHrefMustBeString                                 = 1321204
, RenderImageXMustBeString                                    = 1321205
, RenderImageYMustBeString                                    = 1321206
, RenderImageWidthMustBeString                                = 1321207
, RenderImageHeightMustBeString                               = 1321208
, RenderImageZMustBeString                                    = 1321209
, RenderLineEndingAllowedCoreAttributes                       = 1321301
, RenderLineEndingAllowedCoreElements                         = 1321302
, RenderLineEndingAllowedAttributes                           = 1321303
, RenderLineEndingAllowedElements                             = 1321304
, RenderLineEndingEnableRotationalMappingMustBeBoolean        = 1321305
, RenderLinearGradientAllowedCoreAttributes                   = 1321401
, RenderLinearGradientAllowedCoreElements                     = 1321402
, RenderLinearGradientAllowedAttributes                       = 1321403
, RenderLinearGradientX1MustBeString                          = 1321404
, RenderLinearGradientY1MustBeString                          = 1321405
, RenderLinearGradientZ1MustBeString                          = 1321406
, RenderLinearGradientX2MustBeString                          = 1321407
, RenderLinearGradientY2MustBeString                          = 1321408
, RenderLinearGradientZ2MustBeString                          = 1321409
, RenderLocalRenderInformationAllowedCoreAttributes           = 1321501
, RenderLocalRenderInformationAllowedCoreElements             = 1321502
, RenderLocalRenderInformationAllowedElements                 = 1321503
, RenderLocalRenderInformationEmptyLOElements                 = 1321504
, RenderLocalRenderInformationLOLocalStylesAllowedCoreElements= 1321505
, RenderLocalRenderInformationLOLocalStylesAllowedCoreAttributes= 1321506
, RenderLocalStyleAllowedCoreAttributes                       = 1321601
, RenderLocalStyleAllowedCoreElements                         = 1321602
, RenderLocalStyleAllowedAttributes                           = 1321603
, RenderLocalStyleIdListMustBeString                          = 1321604
, RenderPolygonAllowedCoreAttributes                          = 1321701
, RenderPolygonAllowedCoreElements                            = 1321702
, RenderPolygonAllowedElements                                = 1321703
, RenderPolygonEmptyLOElements                                = 1321704
, RenderPolygonLOCurveElementsAllowedCoreElements             = 1321705
, RenderPolygonLOCurveElementsAllowedCoreAttributes           = 1321706
, RenderRadialGradientAllowedCoreAttributes                   = 1321801
, RenderRadialGradientAllowedCoreElements                     = 1321802
, RenderRadialGradientAllowedAttributes                       = 1321803
, RenderRadialGradientCxMustBeString                          = 1321804
, RenderRadialGradientCyMustBeString                          = 1321805
, RenderRadialGradientCzMustBeString                          = 1321806
, RenderRadialGradientRMustBeString                           = 1321807
, RenderRadialGradientFxMustBeString                          = 1321808
, RenderRadialGradientFyMustBeString                          = 1321809
, RenderRadialGradientFzMustBeString                          = 1321810
, RenderRectangleAllowedCoreAttributes                        = 1321901
, RenderRectangleAllowedCoreElements                          = 1321902
, RenderRectangleAllowedAttributes                            = 1321903
, RenderRectangleXMustBeString                                = 1321904
, RenderRectangleYMustBeString                                = 1321905
, RenderRectangleWidthMustBeString                            = 1321906
, RenderRectangleHeightMustBeString                           = 1321907
, RenderRectangleRatioMustBeDouble                            = 1321908
, RenderRectangleZMustBeString                                = 1321909
, RenderRectangleRXMustBeString                               = 1321910
, RenderRectangleRYMustBeString                               = 1321911
, RenderRenderCubicBezierAllowedCoreAttributes                = 1322001
, RenderRenderCubicBezierAllowedCoreElements                  = 1322002
, RenderRenderCubicBezierAllowedAttributes                    = 1322003
, RenderRenderCubicBezierBasePoint1_xMustBeString             = 1322004
, RenderRenderCubicBezierBasePoint1_yMustBeString             = 1322005
, RenderRenderCubicBezierBasePoint2_xMustBeString             = 1322006
, RenderRenderCubicBezierBasePoint2_yMustBeString             = 1322007
, RenderRenderCubicBezierBasePoint1_zMustBeString             = 1322008
, RenderRenderCubicBezierBasePoint2_zMustBeString             = 1322009
, RenderRenderCurveAllowedCoreAttributes                      = 1322101
, RenderRenderCurveAllowedCoreElements                        = 1322102
, RenderRenderCurveAllowedAttributes                          = 1322103
, RenderRenderCurveAllowedElements                            = 1322104
, RenderRenderCurveStartHeadMustBeLineEnding                  = 1322105
, RenderRenderCurveEndHeadMustBeLineEnding                    = 1322106
, RenderRenderCurveEmptyLOElements                            = 1322107
, RenderRenderCurveLOCurveElementsAllowedCoreElements         = 1322108
, RenderRenderCurveLOCurveElementsAllowedCoreAttributes       = 1322109
, RenderRenderPointAllowedCoreAttributes                      = 1322201
, RenderRenderPointAllowedCoreElements                        = 1322202
, RenderRenderPointAllowedAttributes                          = 1322203
, RenderRenderPointXMustBeString                              = 1322204
, RenderRenderPointYMustBeString                              = 1322205
, RenderRenderPointZMustBeString                              = 1322206
, RenderTextAllowedCoreAttributes                             = 1322301
, RenderTextAllowedCoreElements                               = 1322302
, RenderTextAllowedAttributes                                 = 1322303
, RenderTextXMustBeString                                     = 1322304
, RenderTextYMustBeString                                     = 1322305
, RenderTextFontFamilyMustBeString                            = 1322306
, RenderTextFontWeightMustBeFontWeightEnum                    = 1322307
, RenderTextFontStyleMustBeFontStyleEnum                      = 1322308
, RenderTextTextAnchorMustBeHTextAnchorEnum                   = 1322309
, RenderTextVtextAnchorMustBeVTextAnchorEnum                  = 1322310
, RenderTextZMustBeString                                     = 1322311
, RenderTextFontSizeMustBeString                              = 1322312
, RenderTransformation2DAllowedCoreAttributes                 = 1322401
, RenderTransformation2DAllowedCoreElements                   = 1322402
, RenderTransformationAllowedCoreAttributes                   = 1322501
, RenderTransformationAllowedCoreElements                     = 1322502
, RenderTransformationAllowedAttributes                       = 1322503
, RenderTransformationTransformMustBeString                   = 1322504
, RenderTransformationNameMustBeString                        = 1322505
, RenderGraphicalPrimitive1DAllowedCoreAttributes             = 1322601
, RenderGraphicalPrimitive1DAllowedCoreElements               = 1322602
, RenderGraphicalPrimitive1DAllowedAttributes                 = 1322603
, RenderGraphicalPrimitive1DStrokeMustBeString                = 1322604
, RenderGraphicalPrimitive1DStrokeWidthMustBeString           = 1322605
, RenderGraphicalPrimitive1DStrokeDasharrayMustBeString       = 1322606
, RenderGraphicalPrimitive2DAllowedCoreAttributes             = 1322701
, RenderGraphicalPrimitive2DAllowedCoreElements               = 1322702
, RenderGraphicalPrimitive2DAllowedAttributes                 = 1322703
, RenderGraphicalPrimitive2DFillMustBeString                  = 1322704
, RenderGraphicalPrimitive2DFillRuleMustBeFillRuleEnum        = 1322705
, RenderStyleAllowedCoreAttributes                            = 1322801
, RenderStyleAllowedCoreElements                              = 1322802
, RenderStyleAllowedAttributes                                = 1322803
, RenderStyleAllowedElements                                  = 1322804
, RenderStyleNameMustBeString                                 = 1322805
, RenderStyleRoleListMustBeString                             = 1322806
, RenderStyleTypeListMustBeString                             = 1322807
, RenderRenderInformationBaseAllowedCoreAttributes            = 1322901
, RenderRenderInformationBaseAllowedCoreElements              = 1322902
, RenderRenderInformationBaseAllowedAttributes                = 1322903
, RenderRenderInformationBaseAllowedElements                  = 1322904
, RenderRenderInformationBaseNameMustBeString                 = 1322905
, RenderRenderInformationBaseProgramNameMustBeString          = 1322906
, RenderRenderInformationBaseProgramVersionMustBeString       = 1322907
, RenderRenderInformationBaseReferenceRenderInformationMustBeRenderInformationBase= 1322908
, RenderRenderInformationBaseBackgroundColorMustBeString      = 1322909
, RenderRenderInformationBaseLOElementChildren                = 1322910
, RenderRenderInformationBaseLOColorDefinitionsAllowedCoreElements= 1322911
, RenderRenderInformationBaseLOGradientDefinitionsAllowedCoreElements= 1322912
, RenderRenderInformationBaseLOLineEndingsAllowedCoreElements = 1322913
, RenderRenderInformationBaseLOColorDefinitionsAllowedCoreAttributes= 1322914
, RenderRenderInformationBaseLOGradientDefinitionsAllowedCoreAttributes= 1322915
, RenderRenderInformationBaseLOLineEndingsAllowedCoreAttributes= 1322916
, RenderDefaultValuesAllowedCoreAttributes                    = 1323001
, RenderDefaultValuesAllowedCoreElements                      = 1323002
, RenderDefaultValuesAllowedAttributes                        = 1323003
, RenderDefaultValuesStrokeWidthMustBeDouble                  = 1323004
, RenderDefaultValuesStartHeadMustBeLineEnding                = 1323005
, RenderDefaultValuesFontSizeMustBeString                     = 1323006
} RenderSBMLErrorCode_t;


END_C_DECLS




LIBSBML_CPP_NAMESPACE_END




#endif /* !RenderSBMLError_H__ */


