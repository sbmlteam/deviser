/**
 * @file SedError.h
 * @brief Definition of the SedError class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML. Please visit http://sed-ml.org for more
 * information about SED-ML. The latest version of libSEDML can be found on
 * github: https://github.com/fbergmann/libSEDML/
 * 

 * Copyright (c) 2013-2019, Frank T. Bergmann
 * All rights reserved.
 * 

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 

 * 1. Redistributions of source code must retain the above copyright notice,
 * this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */


#ifndef SedError_h
#define SedError_h

#include <sedml/common/extern.h>
#include <sbml/xml/XMLError.h>
#include <sedml/SedNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * @enum SedErrorCode_t
 * Codes for all SEDML-level errors and warnings from the core specification.
 */
typedef enum
{
  SedUnknown                      = 10000 /*!< Encountered unknown internal libSEDML error. */
, SedNotUTF8                               = 10001 /*!< File does not use UTF-8 encoding. */
, SedUnrecognizedElement                   = 10002 /*!< Encountered unrecognized element. */
, SedNotSchemaConformant                   = 10003 /*!< Document does not conform to the SEDML XML schema. */
, SedInvalidMathElement                    = 10201
, SedMissingAnnotationNamespace            = 10401 /*!< Missing declaration of the XML namespace for the annotation. */
, SedDuplicateAnnotationNamespaces         = 10402 /*!< Multiple annotations using the same XML namespace. */
, SedNamespaceInAnnotation             = 10403 /*!< The SEDML XML namespace cannot be used in an Annotation object. */
, SedMultipleAnnotations                   = 10404 /*!< Only one Annotation object is permitted under a given SEDML object. */
, SedAnnotationNotElement                  = 10405
, SedNotesNotInXHTMLNamespace              = 10801 /*!< Notes must be placed in the XHTML XML namespace. */
, SedNotesContainsXMLDecl                  = 10802 /*!< XML declarations are not permitted in Notes objects. */
, SedNotesContainsDOCTYPE                  = 10803 /*!< XML DOCTYPE elements are not permitted in Notes objects. */
, SedInvalidNotesContent                   = 10804 /*!< Invalid notes content found. */
, SedOnlyOneNotesElementAllowed            = 10805 /*!< Only one Notes subobject is permitted on a given SEDML object. */
, SedmlNSUndeclared      = 10101
, SedmlElementNotInNs      = 10102
, SedmlDuplicateComponentId      = 10301
, SedmlIdSyntaxRule      = 10302
, SedInvalidMetaidSyntax      = 10303
, InvalidNamespaceOnSed      = 20101
, AllowedAttributes      = 20102
, SedEmptyListElement      = 20103
, SedmlDocumentAllowedCoreAttributes      = 20201
, SedmlDocumentAllowedCoreElements      = 20202
, SedmlDocumentAllowedAttributes      = 20203
, SedmlDocumentAllowedElements      = 20204
, SedmlDocumentLevelMustBeInteger      = 20205
, SedmlDocumentVersionMustBeInteger      = 20206
, SedmlDocumentLODataDescriptionsAllowedCoreElements      = 20207
, SedmlDocumentLOModelsAllowedCoreElements      = 20208
, SedmlDocumentLOSimulationsAllowedCoreElements      = 20209
, SedmlDocumentLOAbstractTasksAllowedCoreElements      = 20210
, SedmlDocumentLODataGeneratorsAllowedCoreElements      = 20211
, SedmlDocumentLOOutputsAllowedCoreElements      = 20212
, SedmlDocumentLODataDescriptionsAllowedCoreAttributes      = 20213
, SedmlDocumentLOModelsAllowedCoreAttributes      = 20214
, SedmlDocumentLOSimulationsAllowedCoreAttributes      = 20215
, SedmlDocumentLOAbstractTasksAllowedCoreAttributes      = 20216
, SedmlDocumentLODataGeneratorsAllowedCoreAttributes      = 20217
, SedmlDocumentLOOutputsAllowedCoreAttributes      = 20218
, SedmlModelAllowedCoreAttributes      = 20301
, SedmlModelAllowedCoreElements      = 20302
, SedmlModelAllowedAttributes      = 20303
, SedmlModelAllowedElements      = 20304
, SedmlModelSourceMustBeString      = 20305
, SedmlModelNameMustBeString      = 20306
, SedmlModelLanguageMustBeString      = 20307
, SedmlModelLOChangesAllowedCoreElements      = 20308
, SedmlModelLOChangesAllowedCoreAttributes      = 20309
, SedmlChangeAllowedCoreAttributes      = 20401
, SedmlChangeAllowedCoreElements      = 20402
, SedmlChangeAllowedAttributes      = 20403
, SedmlChangeTargetMustBeString      = 20404
, SedmlAddXMLAllowedCoreAttributes      = 20501
, SedmlAddXMLAllowedCoreElements      = 20502
, SedmlAddXMLAllowedElements      = 20503
, SedmlChangeAttributeAllowedCoreAttributes      = 20601
, SedmlChangeAttributeAllowedCoreElements      = 20602
, SedmlChangeAttributeAllowedAttributes      = 20603
, SedmlChangeAttributeNewValueMustBeString      = 20604
, SedmlVariableAllowedCoreAttributes      = 20701
, SedmlVariableAllowedCoreElements      = 20702
, SedmlVariableAllowedAttributes      = 20703
, SedmlVariableAllowedElements      = 20704
, SedmlVariableNameMustBeString      = 20705
, SedmlVariableSymbolMustBeString      = 20706
, SedmlVariableTargetMustBeString      = 20707
, SedmlVariableTaskReferenceMustBeTask      = 20708
, SedmlVariableModelReferenceMustBeModel      = 20709
, SedmlVariableLORemainingDimensionsAllowedCoreElements      = 20710
, SedmlVariableLORemainingDimensionsAllowedCoreAttributes      = 20711
, SedmlParameterAllowedCoreAttributes      = 20801
, SedmlParameterAllowedCoreElements      = 20802
, SedmlParameterAllowedAttributes      = 20803
, SedmlParameterValueMustBeDouble      = 20804
, SedmlParameterNameMustBeString      = 20805
, SedmlSimulationAllowedCoreAttributes      = 20901
, SedmlSimulationAllowedCoreElements      = 20902
, SedmlSimulationAllowedAttributes      = 20903
, SedmlSimulationAllowedElements      = 20904
, SedmlSimulationNameMustBeString      = 20905
, SedmlUniformTimeCourseAllowedCoreAttributes      = 21001
, SedmlUniformTimeCourseAllowedCoreElements      = 21002
, SedmlUniformTimeCourseAllowedAttributes      = 21003
, SedmlUniformTimeCourseInitialTimeMustBeDouble      = 21004
, SedmlUniformTimeCourseOutputStartTimeMustBeDouble      = 21005
, SedmlUniformTimeCourseOutputEndTimeMustBeDouble      = 21006
, SedmlUniformTimeCourseNumberOfPointsMustBeInteger      = 21007
, SedmlUniformTimeCourseNumberOfStepsMustBeInteger      = 21008
, SedmlAlgorithmAllowedCoreAttributes      = 21101
, SedmlAlgorithmAllowedCoreElements      = 21102
, SedmlAlgorithmAllowedAttributes      = 21103
, SedmlAlgorithmAllowedElements      = 21104
, SedmlAlgorithmKisaoIDMustBeString      = 21105
, SedmlAlgorithmLOAlgorithmParametersAllowedCoreElements      = 21106
, SedmlAlgorithmLOAlgorithmParametersAllowedCoreAttributes      = 21107
, SedmlAbstractTaskAllowedCoreAttributes      = 21201
, SedmlAbstractTaskAllowedCoreElements      = 21202
, SedmlAbstractTaskAllowedAttributes      = 21203
, SedmlAbstractTaskNameMustBeString      = 21204
, SedmlTaskAllowedCoreAttributes      = 21301
, SedmlTaskAllowedCoreElements      = 21302
, SedmlTaskAllowedAttributes      = 21303
, SedmlTaskModelReferenceMustBeModel      = 21304
, SedmlTaskSimulationReferenceMustBeSimulation      = 21305
, SedmlDataGeneratorAllowedCoreAttributes      = 21401
, SedmlDataGeneratorAllowedCoreElements      = 21402
, SedmlDataGeneratorAllowedAttributes      = 21403
, SedmlDataGeneratorAllowedElements      = 21404
, SedmlDataGeneratorNameMustBeString      = 21405
, SedmlDataGeneratorLOVariablesAllowedCoreElements      = 21406
, SedmlDataGeneratorLOParametersAllowedCoreElements      = 21407
, SedmlDataGeneratorLOVariablesAllowedCoreAttributes      = 21408
, SedmlDataGeneratorLOParametersAllowedCoreAttributes      = 21409
, SedmlOutputAllowedCoreAttributes      = 21501
, SedmlOutputAllowedCoreElements      = 21502
, SedmlOutputAllowedAttributes      = 21503
, SedmlOutputNameMustBeString      = 21504
, SedmlPlotAllowedCoreAttributes      = 21601
, SedmlPlotAllowedCoreElements      = 21602
, SedmlPlotAllowedAttributes      = 21603
, SedmlPlotAllowedElements      = 21604
, SedmlPlotLegendMustBeBoolean      = 21605
, SedmlPlotHeightMustBeDouble      = 21606
, SedmlPlotWidthMustBeDouble      = 21607
, SedmlPlot2DAllowedCoreAttributes      = 21701
, SedmlPlot2DAllowedCoreElements      = 21702
, SedmlPlot2DAllowedElements      = 21703
, SedmlPlot2DLOAbstractCurvesAllowedCoreElements      = 21704
, SedmlPlot2DLOAbstractCurvesAllowedCoreAttributes      = 21705
, SedmlPlot3DAllowedCoreAttributes      = 21801
, SedmlPlot3DAllowedCoreElements      = 21802
, SedmlPlot3DAllowedElements      = 21803
, SedmlPlot3DLOSurfacesAllowedCoreElements      = 21804
, SedmlPlot3DLOSurfacesAllowedCoreAttributes      = 21805
, SedmlAbstractCurveAllowedCoreAttributes      = 21901
, SedmlAbstractCurveAllowedCoreElements      = 21902
, SedmlAbstractCurveAllowedAttributes      = 21903
, SedmlAbstractCurveNameMustBeString      = 21904
, SedmlAbstractCurveLogXMustBeBoolean      = 21905
, SedmlAbstractCurveOrderMustBeInteger      = 21906
, SedmlAbstractCurveStyleMustBeStyle      = 21907
, SedmlAbstractCurveYAxisMustBeString      = 21908
, SedmlAbstractCurveXDataReferenceMustBeDataReference      = 21909
, SedmlCurveAllowedCoreAttributes      = 22001
, SedmlCurveAllowedCoreElements      = 22002
, SedmlCurveAllowedAttributes      = 22003
, SedmlCurveLogYMustBeBoolean      = 22004
, SedmlCurveYDataReferenceMustBeDataGenerator      = 22005
, SedmlCurveTypeMustBeCurveTypeEnum      = 22006
, SedmlCurveXErrorUpperMustBeDataGenerator      = 22007
, SedmlCurveXErrorLowerMustBeDataGenerator      = 22008
, SedmlCurveYErrorUpperMustBeDataGenerator      = 22009
, SedmlCurveYErrorLowerMustBeDataGenerator      = 22010
, SedmlSurfaceAllowedCoreAttributes      = 22101
, SedmlSurfaceAllowedCoreElements      = 22102
, SedmlSurfaceAllowedAttributes      = 22103
, SedmlSurfaceLogZMustBeBoolean      = 22104
, SedmlSurfaceZDataReferenceMustBeDataGenerator      = 22105
, SedmlSurfaceSurfaceTypeMustBeSurfaceTypeEnum      = 22106
, SedmlDataSetAllowedCoreAttributes      = 22201
, SedmlDataSetAllowedCoreElements      = 22202
, SedmlDataSetAllowedAttributes      = 22203
, SedmlDataSetLabelMustBeString      = 22204
, SedmlDataSetDataReferenceMustBeDataGenerator      = 22205
, SedmlDataSetNameMustBeString      = 22206
, SedmlReportAllowedCoreAttributes      = 22301
, SedmlReportAllowedCoreElements      = 22302
, SedmlReportAllowedElements      = 22303
, SedmlReportLODataSetsAllowedCoreElements      = 22304
, SedmlReportLODataSetsAllowedCoreAttributes      = 22305
, SedmlAlgorithmParameterAllowedCoreAttributes      = 22401
, SedmlAlgorithmParameterAllowedCoreElements      = 22402
, SedmlAlgorithmParameterAllowedAttributes      = 22403
, SedmlAlgorithmParameterKisaoIDMustBeString      = 22404
, SedmlAlgorithmParameterValueMustBeString      = 22405
, SedmlRangeAllowedCoreAttributes      = 22501
, SedmlRangeAllowedCoreElements      = 22502
, SedmlRangeAllowedAttributes      = 22503
, SedmlChangeXMLAllowedCoreAttributes      = 22601
, SedmlChangeXMLAllowedCoreElements      = 22602
, SedmlChangeXMLAllowedElements      = 22603
, SedmlRemoveXMLAllowedCoreAttributes      = 22701
, SedmlRemoveXMLAllowedCoreElements      = 22702
, SedmlSetValueAllowedCoreAttributes      = 22801
, SedmlSetValueAllowedCoreElements      = 22802
, SedmlSetValueAllowedAttributes      = 22803
, SedmlSetValueAllowedElements      = 22804
, SedmlSetValueModelReferenceMustBeModel      = 22805
, SedmlSetValueSymbolMustBeString      = 22806
, SedmlSetValueTargetMustBeString      = 22807
, SedmlSetValueRangeMustBeRange      = 22808
, SedmlUniformRangeAllowedCoreAttributes      = 22901
, SedmlUniformRangeAllowedCoreElements      = 22902
, SedmlUniformRangeAllowedAttributes      = 22903
, SedmlUniformRangeStartMustBeDouble      = 22904
, SedmlUniformRangeEndMustBeDouble      = 22905
, SedmlUniformRangeNumberOfPointsMustBeInteger      = 22906
, SedmlUniformRangeTypeMustBeString      = 22907
, SedmlVectorRangeAllowedCoreAttributes      = 23001
, SedmlVectorRangeAllowedCoreElements      = 23002
, SedmlVectorRangeAllowedAttributes      = 23003
, SedmlVectorRangeValueMustBeString      = 23004
, SedmlFunctionalRangeAllowedCoreAttributes      = 23101
, SedmlFunctionalRangeAllowedCoreElements      = 23102
, SedmlFunctionalRangeAllowedAttributes      = 23103
, SedmlFunctionalRangeAllowedElements      = 23104
, SedmlFunctionalRangeRangeMustBeRange      = 23105
, SedmlFunctionalRangeLOVariablesAllowedCoreElements      = 23106
, SedmlFunctionalRangeLOParametersAllowedCoreElements      = 23107
, SedmlFunctionalRangeLOVariablesAllowedCoreAttributes      = 23108
, SedmlFunctionalRangeLOParametersAllowedCoreAttributes      = 23109
, SedmlSubTaskAllowedCoreAttributes      = 23201
, SedmlSubTaskAllowedCoreElements      = 23202
, SedmlSubTaskAllowedAttributes      = 23203
, SedmlSubTaskOrderMustBeInteger      = 23204
, SedmlSubTaskTaskMustBeAbstractTask      = 23205
, SedmlOneStepAllowedCoreAttributes      = 23301
, SedmlOneStepAllowedCoreElements      = 23302
, SedmlOneStepAllowedAttributes      = 23303
, SedmlOneStepStepMustBeDouble      = 23304
, SedmlSteadyStateAllowedCoreAttributes      = 23401
, SedmlSteadyStateAllowedCoreElements      = 23402
, SedmlRepeatedTaskAllowedCoreAttributes      = 23501
, SedmlRepeatedTaskAllowedCoreElements      = 23502
, SedmlRepeatedTaskAllowedAttributes      = 23503
, SedmlRepeatedTaskAllowedElements      = 23504
, SedmlRepeatedTaskRangeIdMustBeRange      = 23505
, SedmlRepeatedTaskResetModelMustBeBoolean      = 23506
, SedmlRepeatedTaskLORangesAllowedCoreElements      = 23507
, SedmlRepeatedTaskLOSetValuesAllowedCoreElements      = 23508
, SedmlRepeatedTaskLOSubTasksAllowedCoreElements      = 23509
, SedmlRepeatedTaskLORangesAllowedCoreAttributes      = 23510
, SedmlRepeatedTaskLOSetValuesAllowedCoreAttributes      = 23511
, SedmlRepeatedTaskLOSubTasksAllowedCoreAttributes      = 23512
, SedmlComputeChangeAllowedCoreAttributes      = 23601
, SedmlComputeChangeAllowedCoreElements      = 23602
, SedmlComputeChangeAllowedElements      = 23603
, SedmlComputeChangeLOVariablesAllowedCoreElements      = 23604
, SedmlComputeChangeLOParametersAllowedCoreElements      = 23605
, SedmlComputeChangeLOVariablesAllowedCoreAttributes      = 23606
, SedmlComputeChangeLOParametersAllowedCoreAttributes      = 23607
, SedmlDataDescriptionAllowedCoreAttributes      = 23701
, SedmlDataDescriptionAllowedCoreElements      = 23702
, SedmlDataDescriptionAllowedAttributes      = 23703
, SedmlDataDescriptionAllowedElements      = 23704
, SedmlDataDescriptionNameMustBeString      = 23705
, SedmlDataDescriptionFormatMustBeString      = 23706
, SedmlDataDescriptionSourceMustBeString      = 23707
, SedmlDataDescriptionLODataSourcesAllowedCoreElements      = 23708
, SedmlDataDescriptionLODataSourcesAllowedCoreAttributes      = 23709
, SedmlDataSourceAllowedCoreAttributes      = 23801
, SedmlDataSourceAllowedCoreElements      = 23802
, SedmlDataSourceAllowedAttributes      = 23803
, SedmlDataSourceAllowedElements      = 23804
, SedmlDataSourceNameMustBeString      = 23805
, SedmlDataSourceIndexSetMustBe      = 23806
, SedmlDataSourceLOSlicesAllowedCoreElements      = 23807
, SedmlDataSourceLOSlicesAllowedCoreAttributes      = 23808
, SedmlSliceAllowedCoreAttributes      = 23901
, SedmlSliceAllowedCoreElements      = 23902
, SedmlSliceAllowedAttributes      = 23903
, SedmlSliceReferenceMustBe      = 23904
, SedmlSliceValueMustBeString      = 23905
, SedmlParameterEstimationTaskAllowedCoreAttributes      = 24001
, SedmlParameterEstimationTaskAllowedCoreElements      = 24002
, SedmlParameterEstimationTaskAllowedElements      = 24003
, SedmlParameterEstimationTaskLOAdjustableParametersAllowedCoreElements      = 24004
, SedmlParameterEstimationTaskLOFitExperimentsAllowedCoreElements      = 24005
, SedmlParameterEstimationTaskLOAdjustableParametersAllowedCoreAttributes      = 24006
, SedmlParameterEstimationTaskLOFitExperimentsAllowedCoreAttributes      = 24007
, SedmlObjectiveAllowedCoreAttributes      = 24101
, SedmlObjectiveAllowedCoreElements      = 24102
, SedmlLeastSquareObjectiveFunctionAllowedCoreAttributes      = 24201
, SedmlLeastSquareObjectiveFunctionAllowedCoreElements      = 24202
, SedmlAdjustableParameterAllowedCoreAttributes      = 24301
, SedmlAdjustableParameterAllowedCoreElements      = 24302
, SedmlAdjustableParameterAllowedAttributes      = 24303
, SedmlAdjustableParameterAllowedElements      = 24304
, SedmlAdjustableParameterModelReferenceMustBeModel      = 24305
, SedmlAdjustableParameterTargetMustBeString      = 24306
, SedmlAdjustableParameterLOExperimentRefsAllowedCoreElements      = 24307
, SedmlAdjustableParameterLOExperimentRefsAllowedCoreAttributes      = 24308
, SedmlExperimentRefAllowedCoreAttributes      = 24401
, SedmlExperimentRefAllowedCoreElements      = 24402
, SedmlExperimentRefAllowedAttributes      = 24403
, SedmlExperimentRefExperimentIdMustBeFitExperiment      = 24404
, SedmlFitExperimentAllowedCoreAttributes      = 24501
, SedmlFitExperimentAllowedCoreElements      = 24502
, SedmlFitExperimentAllowedAttributes      = 24503
, SedmlFitExperimentAllowedElements      = 24504
, SedmlFitExperimentSourceMustBeString      = 24505
, SedmlFitExperimentRepresentsMustBeExperimentTypeEnum      = 24506
, SedmlFitExperimentLOFitMappingsAllowedCoreElements      = 24507
, SedmlFitExperimentLOFitMappingsAllowedCoreAttributes      = 24508
, SedmlFitMappingAllowedCoreAttributes      = 24601
, SedmlFitMappingAllowedCoreElements      = 24602
, SedmlFitMappingAllowedAttributes      = 24603
, SedmlFitMappingAllowedElements      = 24604
, SedmlFitMappingColNumberMustBeInteger      = 24605
, SedmlFitMappingDataGeneratorMustBeDataGenerator      = 24606
, SedmlFitMappingTypeMustBeMappingTypeEnum      = 24607
, SedmlScalingAllowedCoreAttributes      = 24701
, SedmlScalingAllowedCoreElements      = 24702
, SedmlValueScalingAllowedCoreAttributes      = 24801
, SedmlValueScalingAllowedCoreElements      = 24802
, SedmlValueScalingAllowedAttributes      = 24803
, SedmlValueScalingWeightMustBeString      = 24804
, SedmlColumnScalingAllowedCoreAttributes      = 24901
, SedmlColumnScalingAllowedCoreElements      = 24902
, SedmlColumnScalingAllowedAttributes      = 24903
, SedmlColumnScalingColNumberMustBeInteger      = 24904
, SedmlBoundsAllowedCoreAttributes      = 25001
, SedmlBoundsAllowedCoreElements      = 25002
, SedmlBoundsAllowedAttributes      = 25003
, SedmlBoundsStartingValueMustBeDouble      = 25004
, SedmlBoundsLowerBoundMustBeDouble      = 25005
, SedmlBoundsUpperBoundMustBeDouble      = 25006
, SedmlFigureAllowedCoreAttributes      = 25101
, SedmlFigureAllowedCoreElements      = 25102
, SedmlFigureAllowedAttributes      = 25103
, SedmlFigureAllowedElements      = 25104
, SedmlFigureNumRowsMustBeInteger      = 25105
, SedmlFigureNumColumnsMustBeInteger      = 25106
, SedmlFigureLOSubPlotsAllowedCoreElements      = 25107
, SedmlFigureLOSubPlotsAllowedCoreAttributes      = 25108
, SedmlSubPlotAllowedCoreAttributes      = 25201
, SedmlSubPlotAllowedCoreElements      = 25202
, SedmlSubPlotAllowedAttributes      = 25203
, SedmlSubPlotPlotMustBePlot      = 25204
, SedmlSubPlotRowMustBeInteger      = 25205
, SedmlSubPlotColumnMustBeInteger      = 25206
, SedmlSubPlotRowSpanMustBeInteger      = 25207
, SedmlSubPlotColumnSpanMustBeInteger      = 25208
, SedmlAxisAllowedCoreAttributes      = 25301
, SedmlAxisAllowedCoreElements      = 25302
, SedmlAxisAllowedAttributes      = 25303
, SedmlAxisTypeMustBeAxisTypeEnum      = 25304
, SedmlAxisMinMustBeDouble      = 25305
, SedmlAxisMaxMustBeDouble      = 25306
, SedmlAxisGridMustBeBoolean      = 25307
, SedmlAxisStyleMustBeStyle      = 25308
, SedmlStyleAllowedCoreAttributes      = 25401
, SedmlStyleAllowedCoreElements      = 25402
, SedmlStyleAllowedAttributes      = 25403
, SedmlStyleAllowedElements      = 25404
, SedmlStyleBaseStyleMustBeStyle      = 25405
, SedmlLineAllowedCoreAttributes      = 25501
, SedmlLineAllowedCoreElements      = 25502
, SedmlLineAllowedAttributes      = 25503
, SedmlLineStyleMustBeLineTypeEnum      = 25504
, SedmlLineColorMustBeString      = 25505
, SedmlLineThicknessMustBeDouble      = 25506
, SedmlMarkerAllowedCoreAttributes      = 25601
, SedmlMarkerAllowedCoreElements      = 25602
, SedmlMarkerAllowedAttributes      = 25603
, SedmlMarkerSizeMustBeDouble      = 25604
, SedmlMarkerStyleMustBeMarkerTypeEnum      = 25605
, SedmlMarkerFillMustBeString      = 25606
, SedmlMarkerLineColorMustBeString      = 25607
, SedmlMarkerLineThicknessMustBeDouble      = 25608
, SedmlFillAllowedCoreAttributes      = 25701
, SedmlFillAllowedCoreElements      = 25702
, SedmlFillAllowedAttributes      = 25703
, SedmlFillColorMustBeString      = 25704
, SedmlFillSecondColorMustBeString      = 25705
, SedmlDependentVariableAllowedCoreAttributes      = 25801
, SedmlDependentVariableAllowedCoreElements      = 25802
, SedmlDependentVariableAllowedAttributes      = 25803
, SedmlDependentVariableTermMustBeString      = 25804
, SedmlDependentVariableTarget2MustBeString      = 25805
, SedmlDependentVariableSymbol2MustBeString      = 25806
, SedmlRemainingDimensionAllowedCoreAttributes      = 25901
, SedmlRemainingDimensionAllowedCoreElements      = 25902
, SedmlRemainingDimensionAllowedAttributes      = 25903
, SedmlRemainingDimensionTargetMustBe      = 25904
, SedmlRemainingDimensionDimensionTargetMustBe      = 25905
, SedmlDataRangeAllowedCoreAttributes      = 26001
, SedmlDataRangeAllowedCoreElements      = 26002
, SedmlDataRangeAllowedAttributes      = 26003
, SedmlDataRangeSourceRefMustBe      = 26004
, SedmlSimpleRepeatedTaskAllowedCoreAttributes      = 26101
, SedmlSimpleRepeatedTaskAllowedCoreElements      = 26102
, SedmlSimpleRepeatedTaskAllowedAttributes      = 26103
, SedmlSimpleRepeatedTaskResetModelMustBeBoolean      = 26104
, SedmlSimpleRepeatedTaskNumRepeatsMustBeInteger      = 26105
, SedmlShadedAreaAllowedCoreAttributes      = 26201
, SedmlShadedAreaAllowedCoreElements      = 26202
, SedmlShadedAreaAllowedAttributes      = 26203
, SedmlShadedAreaYDataReferenceFromMustBeDataGenerator      = 26204
, SedmlShadedAreaYDataReferenceToMustBeDataGenerator      = 26205
, SedUnknownCoreAttribute                  = 99994 /*!< Encountered an unknown attribute in the SEDML Core namespace. */
, SedCodesUpperBound                   = 99999 /*!< Upper boundary of libSEDML-specific diagnostic codes. */
} SedErrorCode_t;


/**
 * @enum SedErrorCategory_t
 * Category codes for SedError diagnostics.
 *
 * Note that these are distinct from XMLError's category codes.  User
 * programs receiving an SedError object can use this distinction to
 * check whether the error represents a low-level XML problem or an
 * SEDML problem.
 *
 * @see #XMLErrorCategory_t
 */
typedef enum
{
    LIBSEDML_CAT_INTERNAL = LIBSBML_CAT_INTERNAL,
    LIBSEDML_CAT_SYSTEM = LIBSBML_CAT_SYSTEM,
    LIBSEDML_CAT_XML = LIBSBML_CAT_XML,

    LIBSEDML_CAT_SEDML = (LIBSEDML_CAT_XML + 1)
    /*!< General SEDML error  not falling into another category below. */

  , LIBSEDML_CAT_GENERAL_CONSISTENCY
    /*!< Category of errors that can occur while validating general SEDML
     * constructs. */

  , LIBSEDML_CAT_IDENTIFIER_CONSISTENCY
    /*!< Category of errors that can occur while validating symbol
     * identifiers in a model. */

  , LIBSEDML_CAT_MATHML_CONSISTENCY
    /*!< Category of errors that can occur while validating MathML formulas
     * in a model.  With respect to the SEDML specification, these concern
     * failures in applying the validation rules numbered 102xx in the
     * Level&nbsp;2 Versions&nbsp;2&ndash;4
     * and Level&nbsp;3 Version&nbsp;1 specifications. */

  , LIBSEDML_CAT_INTERNAL_CONSISTENCY
    /*!< Category of errors that can occur while validating libSEDML's
     * internal representation of SEDML constructs. (These are tests
     * performed by libSEDML and do not have equivalent SEDML validation
     * rules.)  */

} SedErrorCategory_t;


/**
 * @enum SedErrorSeverity_t
 * Severity codes for SedError diagnostics.
 *
 * The only publicly-reported values of this type are the four from #XMLErrorSeverity_t.
 * All other values are used internally only, with translation of those
 * codes done in SedError.cpp
 *
 * @see XMLErrorSeverity_t
 */
typedef enum
{
  /** @cond doxygenLibsedmlInternal **/

  /* The following are used internally in SedErrorTable, but publicly,
   * we only report one of the 4 XMLError_Severity values.  Translation
   * of the codes is done in SedError.cpp.
   */
    LIBSEDML_SEV_WARNING = LIBSBML_SEV_WARNING,
    LIBSEDML_SEV_ERROR = LIBSBML_SEV_ERROR,
    LIBSEDML_SEV_FATAL = LIBSBML_SEV_FATAL,

    LIBSEDML_SEV_SCHEMA_ERROR    = (LIBSEDML_SEV_FATAL + 1)
    /*!< The XML content does not conform to
     * the relevant version of the SEDML XML
     * Schema.  The content is not valid SEDML. */

  , LIBSEDML_SEV_GENERAL_WARNING
    /*!< The XML content is invalid for some
     * levels/versions of SEDML, and while it
     * may be valid in others, it is something
     * that is best avoided anyway.  LibSEDML
     * will issue warnings in those cases it
     * can recognize. */

  , LIBSEDML_SEV_NOT_APPLICABLE
    /*!< This error code is only a placeholder
     * for errors that have relevance to some
     * versions of SEDML but not others. */

  /** @endcond **/
} SedErrorSeverity_t;

END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#ifdef __cplusplus

LIBSEDML_CPP_NAMESPACE_BEGIN

class LIBSEDML_EXTERN SedError : public XMLError
{
public:

  /**
   * Creates a new SedError to report that something occurred during SEDML
   * processing.
   *
   * When a libSEDML operation on SEDML content results in a warning, error
   * or other diagnostic, the issue is reported as an SedError object.
   * SedError objects have identification numbers to indicate the nature
   * of the exception.  @if clike These numbers are drawn from
   * the enumeration <a class="el"
   * href="#SedErrorCode_t">
   * SedErrorCode_t</a>.  @endif@if java These numbers are
   * defined as unsigned integer constants in the file
   * "libsedmlConstants.html".  See the <a class="el"
   * href="#SedErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@if python These
   * numbers are defined as unsigned integer constants in the interface
   * class @link libsedml libsedml@endlink.  See the <a class="el"
   * href="#SedErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@~ The argument
   * @p errorId to this constructor @em can be (but does not have to be) a
   * value from this @if clike enumeration. If it @em is a value
   * from <a class="el" href="#SedErrorCode_t">SedErrorCode_t</a>, the
   * SedError class assumes the error is a low-level system or SEDML layer
   * error and <em>prepends</em> a built-in, predefined error message to
   * any string passed in the argument @p details to this constructor.  In
   * addition, all <a class="el"
   * href="#SedErrorCode_t">SedErrorCode_t</a> errors have associated
   * values for the @p severity and @p category codes, and these fields are
   * filled-in as well from the enumerations <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>,
   * respectively. @else set of constants.  If it @em
   * is one of the predefined error identifiers, the SedError class
   * assumes the error is a low-level system or SEDML layer error and
   * <em>prepends</em> a built-in, predefined error message to any string
   * passed in the argument @p details to this constructor.  In addition,
   * all the predefined error identifiers have associated values for the
   * @p severity and @p category codes, and these fields are filled-in using
   * the libSEDML defaults for each different error identifier. @endif@~
   *
   * If the error identifier @p errorId is a number greater than 99999, the
   * SedError class assumes the error was generated from another part of
   * the software and does not do additional filling in of values beyond
   * the default in the constructor itself.  This allows SedError to serve
   * as a base class for other errors, such as for user-defined validation
   * rules (see Validator).  Callers should fill in all the parameters with
   * suitable values if generating errors with codes greater than 99999 to
   * make maximum use of the SedError facilities.
   *
   * @if clike As mentioned above, there are two other
   * enumerations, <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>, used for indicating
   * the severity and category of error for the predefined SedError codes.
   * The values passed in @p severity and @p category override the defaults
   * assigned based on the error code.  If the value of @p errorId is a
   * value from <a class="el" href="#SedErrorCode_t">SedErrorCode_t</a>,
   * callers do not need to fill in @p severity and @p category.
   * Conversely, if @p errorId is not a value from <a class="el"
   * href="#SedErrorCode_t">SedErrorCode_t</a>, callers can use other
   * values (not just those from <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>, but their own
   * special values) for @p severity and
   * @p category. @else As mentioned above,
   * there are additional constants defined for <a class="el"
   * href="#SedErrorSeverity_t">standard severity</a> and <a class="el"
   * href="#SedErrorCategory_t">standard category</a> codes, and every predefined
   * error in libSEDML has an associated value for severity and category taken
   * from these predefined sets.  These constants have symbol names
   * prefixed with <code>LIBSEDML_SEV_</code> and <code>LIBSEDML_CAT_</code>,
   * respectively.  If the value of @p errorId is one of the standard error
   * codes, callers do not need to fill in @p severity and @p category in a
   * call to this constructor.  Conversely, if @p errorId is not an existing
   * SEDML-level error code, callers can use other values for @p severity and
   * @p category. @endif@~
   *
   * Please see the top of the documentation for SedError for a longer
   * discussion of the possible error codes, their meanings, and their
   * applicability to different combinations of Level+Version of SEDML.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level the SEDML Level of the SEDML model
   *
   * @param version the SEDML Version within the Level of the SEDML model
   *
   * @param details a string containing additional details about the error.
   * If the error code in @p errorId is one that is recognized by SedError,
   * the given message is @em appended to a predefined message associated
   * with the given code.  If the error code is not recognized, the message
   * is stored as-is as the text of the error.
   *
   * @param line an unsigned int, the line number at which the error occured.
   *
   * @param column an unsigned int, the column number at which the error occured.
   *
   * @param severity an integer indicating severity of the error.
   *
   * @param category an integer indicating the category to which the error
   * belongs.
   */
  SedError
  (
     const unsigned int errorId  = 0
   , const unsigned int level    = SEDML_DEFAULT_LEVEL
   , const unsigned int version  = SEDML_DEFAULT_VERSION
   , const std::string& details  = ""
   , const unsigned int line     = 0
   , const unsigned int column   = 0
   , const unsigned int severity = LIBSEDML_SEV_ERROR
   , const unsigned int category = LIBSEDML_CAT_SEDML
  );


  /**
   * Copy constructor; creates a copy of this SedError.
   */
  SedError(const SedError& orig);

  /**
   * Destroys this SedError.
   */
  virtual ~SedError();


#ifndef SWIG

  /** @cond doxygenLibsedmlInternal **/

  /**
   * Creates and returns a deep copy of this SedError object.
   *
   * @return the (deep) copy of this SedError object.
   */
  virtual SedError* clone() const;

  /**
   * Outputs this SedError to stream in the following format (and followed
   * by a newline):
   *
   *   line: (error id) message
   *
   * @param stream the output stream to write to.
   */
  virtual void print(std::ostream& stream) const;

  /** @endcond **/

#endif  /* !SWIG */

protected:
  /** @cond doxygenLibsedmlInternal **/

  virtual std::string stringForSeverity(unsigned int code) const;
  virtual std::string stringForCategory(unsigned int code) const;

  /** @endcond **/
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif /* SedError_h */