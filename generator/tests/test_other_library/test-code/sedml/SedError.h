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
, SedmlSedDocumentAllowedCoreAttributes      = 20201
, SedmlSedDocumentAllowedCoreElements      = 20202
, SedmlSedDocumentAllowedAttributes      = 20203
, SedmlSedDocumentAllowedElements      = 20204
, SedmlSedDocumentLevelMustBeInteger      = 20205
, SedmlSedDocumentVersionMustBeInteger      = 20206
, SedmlSedDocumentLOSimulationsAllowedCoreElements      = 20207
, SedmlSedDocumentLOModelsAllowedCoreElements      = 20208
, SedmlSedDocumentLOAbstractTasksAllowedCoreElements      = 20209
, SedmlSedDocumentLODataGeneratorsAllowedCoreElements      = 20210
, SedmlSedDocumentLOOutputsAllowedCoreElements      = 20211
, SedmlSedDocumentLODataDescriptionsAllowedCoreElements      = 20212
, SedmlSedDocumentLOSimulationsAllowedCoreAttributes      = 20213
, SedmlSedDocumentLOModelsAllowedCoreAttributes      = 20214
, SedmlSedDocumentLOAbstractTasksAllowedCoreAttributes      = 20215
, SedmlSedDocumentLODataGeneratorsAllowedCoreAttributes      = 20216
, SedmlSedDocumentLOOutputsAllowedCoreAttributes      = 20217
, SedmlSedDocumentLODataDescriptionsAllowedCoreAttributes      = 20218
, SedmlSedModelAllowedCoreAttributes      = 20301
, SedmlSedModelAllowedCoreElements      = 20302
, SedmlSedModelAllowedAttributes      = 20303
, SedmlSedModelAllowedElements      = 20304
, SedmlSedModelSourceMustBeString      = 20305
, SedmlSedModelNameMustBeString      = 20306
, SedmlSedModelLanguageMustBeString      = 20307
, SedmlSedModelLOChangesAllowedCoreElements      = 20308
, SedmlSedModelLOChangesAllowedCoreAttributes      = 20309
, SedmlSedChangeAllowedCoreAttributes      = 20401
, SedmlSedChangeAllowedCoreElements      = 20402
, SedmlSedChangeAllowedAttributes      = 20403
, SedmlSedChangeTargetMustBeString      = 20404
, SedmlSedAddXMLAllowedCoreAttributes      = 20501
, SedmlSedAddXMLAllowedCoreElements      = 20502
, SedmlSedAddXMLAllowedElements      = 20503
, SedmlSedChangeAttributeAllowedCoreAttributes      = 20601
, SedmlSedChangeAttributeAllowedCoreElements      = 20602
, SedmlSedChangeAttributeAllowedAttributes      = 20603
, SedmlSedChangeAttributeNewValueMustBeString      = 20604
, SedmlSedVariableAllowedCoreAttributes      = 20701
, SedmlSedVariableAllowedCoreElements      = 20702
, SedmlSedVariableAllowedAttributes      = 20703
, SedmlSedVariableAllowedElements      = 20704
, SedmlSedVariableNameMustBeString      = 20705
, SedmlSedVariableSymbolMustBeString      = 20706
, SedmlSedVariableTargetMustBeString      = 20707
, SedmlSedVariableTaskReferenceMustBeTask      = 20708
, SedmlSedVariableModelReferenceMustBeModel      = 20709
, SedmlSedVariableLORemainingDimensionsAllowedCoreElements      = 20710
, SedmlSedVariableLORemainingDimensionsAllowedCoreAttributes      = 20711
, SedmlSedParameterAllowedCoreAttributes      = 20801
, SedmlSedParameterAllowedCoreElements      = 20802
, SedmlSedParameterAllowedAttributes      = 20803
, SedmlSedParameterValueMustBeDouble      = 20804
, SedmlSedParameterNameMustBeString      = 20805
, SedmlSedSimulationAllowedCoreAttributes      = 20901
, SedmlSedSimulationAllowedCoreElements      = 20902
, SedmlSedSimulationAllowedAttributes      = 20903
, SedmlSedSimulationAllowedElements      = 20904
, SedmlSedSimulationNameMustBeString      = 20905
, SedmlSedUniformTimeCourseAllowedCoreAttributes      = 21001
, SedmlSedUniformTimeCourseAllowedCoreElements      = 21002
, SedmlSedUniformTimeCourseAllowedAttributes      = 21003
, SedmlSedUniformTimeCourseInitialTimeMustBeDouble      = 21004
, SedmlSedUniformTimeCourseOutputStartTimeMustBeDouble      = 21005
, SedmlSedUniformTimeCourseOutputEndTimeMustBeDouble      = 21006
, SedmlSedUniformTimeCourseNumberOfPointsMustBeInteger      = 21007
, SedmlSedUniformTimeCourseNumberOfStepsMustBeInteger      = 21008
, SedmlSedAlgorithmAllowedCoreAttributes      = 21101
, SedmlSedAlgorithmAllowedCoreElements      = 21102
, SedmlSedAlgorithmAllowedAttributes      = 21103
, SedmlSedAlgorithmAllowedElements      = 21104
, SedmlSedAlgorithmKisaoIDMustBeString      = 21105
, SedmlSedAlgorithmLOAlgorithmParametersAllowedCoreElements      = 21106
, SedmlSedAlgorithmLOAlgorithmParametersAllowedCoreAttributes      = 21107
, SedmlSedAbstractTaskAllowedCoreAttributes      = 21201
, SedmlSedAbstractTaskAllowedCoreElements      = 21202
, SedmlSedAbstractTaskAllowedAttributes      = 21203
, SedmlSedAbstractTaskNameMustBeString      = 21204
, SedmlSedTaskAllowedCoreAttributes      = 21301
, SedmlSedTaskAllowedCoreElements      = 21302
, SedmlSedTaskAllowedAttributes      = 21303
, SedmlSedTaskModelReferenceMustBeModel      = 21304
, SedmlSedTaskSimulationReferenceMustBeSimulation      = 21305
, SedmlSedDataGeneratorAllowedCoreAttributes      = 21401
, SedmlSedDataGeneratorAllowedCoreElements      = 21402
, SedmlSedDataGeneratorAllowedAttributes      = 21403
, SedmlSedDataGeneratorAllowedElements      = 21404
, SedmlSedDataGeneratorNameMustBeString      = 21405
, SedmlSedDataGeneratorLOVariablesAllowedCoreElements      = 21406
, SedmlSedDataGeneratorLOParametersAllowedCoreElements      = 21407
, SedmlSedDataGeneratorLOVariablesAllowedCoreAttributes      = 21408
, SedmlSedDataGeneratorLOParametersAllowedCoreAttributes      = 21409
, SedmlSedOutputAllowedCoreAttributes      = 21501
, SedmlSedOutputAllowedCoreElements      = 21502
, SedmlSedOutputAllowedAttributes      = 21503
, SedmlSedOutputNameMustBeString      = 21504
, SedmlSedPlotAllowedCoreAttributes      = 21601
, SedmlSedPlotAllowedCoreElements      = 21602
, SedmlSedPlotAllowedAttributes      = 21603
, SedmlSedPlotAllowedElements      = 21604
, SedmlSedPlotLegendMustBeBoolean      = 21605
, SedmlSedPlotHeightMustBeDouble      = 21606
, SedmlSedPlotWidthMustBeDouble      = 21607
, SedmlSedPlot2DAllowedCoreAttributes      = 21701
, SedmlSedPlot2DAllowedCoreElements      = 21702
, SedmlSedPlot2DAllowedElements      = 21703
, SedmlSedPlot2DLOAbstractCurvesAllowedCoreElements      = 21704
, SedmlSedPlot2DLOAbstractCurvesAllowedCoreAttributes      = 21705
, SedmlSedPlot3DAllowedCoreAttributes      = 21801
, SedmlSedPlot3DAllowedCoreElements      = 21802
, SedmlSedPlot3DAllowedElements      = 21803
, SedmlSedPlot3DLOSurfacesAllowedCoreElements      = 21804
, SedmlSedPlot3DLOSurfacesAllowedCoreAttributes      = 21805
, SedmlSedAbstractCurveAllowedCoreAttributes      = 21901
, SedmlSedAbstractCurveAllowedCoreElements      = 21902
, SedmlSedAbstractCurveAllowedAttributes      = 21903
, SedmlSedAbstractCurveNameMustBeString      = 21904
, SedmlSedAbstractCurveLogXMustBeBoolean      = 21905
, SedmlSedAbstractCurveOrderMustBeInteger      = 21906
, SedmlSedAbstractCurveStyleMustBeStyle      = 21907
, SedmlSedAbstractCurveYAxisMustBeString      = 21908
, SedmlSedAbstractCurveXDataReferenceMustBeDataReference      = 21909
, SedmlSedCurveAllowedCoreAttributes      = 22001
, SedmlSedCurveAllowedCoreElements      = 22002
, SedmlSedCurveAllowedAttributes      = 22003
, SedmlSedCurveLogYMustBeBoolean      = 22004
, SedmlSedCurveYDataReferenceMustBeDataGenerator      = 22005
, SedmlSedCurveTypeMustBeCurveKindEnum      = 22006
, SedmlSedCurveXErrorUpperMustBeDataGenerator      = 22007
, SedmlSedCurveXErrorLowerMustBeDataGenerator      = 22008
, SedmlSedCurveYErrorUpperMustBeDataGenerator      = 22009
, SedmlSedCurveYErrorLowerMustBeDataGenerator      = 22010
, SedmlSedSurfaceAllowedCoreAttributes      = 22101
, SedmlSedSurfaceAllowedCoreElements      = 22102
, SedmlSedSurfaceAllowedAttributes      = 22103
, SedmlSedSurfaceLogZMustBeBoolean      = 22104
, SedmlSedSurfaceZDataReferenceMustBeDataGenerator      = 22105
, SedmlSedDataSetAllowedCoreAttributes      = 22201
, SedmlSedDataSetAllowedCoreElements      = 22202
, SedmlSedDataSetAllowedAttributes      = 22203
, SedmlSedDataSetLabelMustBeString      = 22204
, SedmlSedDataSetDataReferenceMustBeDataGenerator      = 22205
, SedmlSedDataSetNameMustBeString      = 22206
, SedmlSedReportAllowedCoreAttributes      = 22301
, SedmlSedReportAllowedCoreElements      = 22302
, SedmlSedReportAllowedElements      = 22303
, SedmlSedReportLODataSetsAllowedCoreElements      = 22304
, SedmlSedReportLODataSetsAllowedCoreAttributes      = 22305
, SedmlSedAlgorithmParameterAllowedCoreAttributes      = 22401
, SedmlSedAlgorithmParameterAllowedCoreElements      = 22402
, SedmlSedAlgorithmParameterAllowedAttributes      = 22403
, SedmlSedAlgorithmParameterKisaoIDMustBeString      = 22404
, SedmlSedAlgorithmParameterValueMustBeString      = 22405
, SedmlSedRangeAllowedCoreAttributes      = 22501
, SedmlSedRangeAllowedCoreElements      = 22502
, SedmlSedRangeAllowedAttributes      = 22503
, SedmlSedChangeXMLAllowedCoreAttributes      = 22601
, SedmlSedChangeXMLAllowedCoreElements      = 22602
, SedmlSedChangeXMLAllowedElements      = 22603
, SedmlSedRemoveXMLAllowedCoreAttributes      = 22701
, SedmlSedRemoveXMLAllowedCoreElements      = 22702
, SedmlSedSetValueAllowedCoreAttributes      = 22801
, SedmlSedSetValueAllowedCoreElements      = 22802
, SedmlSedSetValueAllowedAttributes      = 22803
, SedmlSedSetValueAllowedElements      = 22804
, SedmlSedSetValueModelReferenceMustBeModel      = 22805
, SedmlSedSetValueSymbolMustBeString      = 22806
, SedmlSedSetValueTargetMustBeString      = 22807
, SedmlSedSetValueRangeMustBeRange      = 22808
, SedmlSedUniformRangeAllowedCoreAttributes      = 22901
, SedmlSedUniformRangeAllowedCoreElements      = 22902
, SedmlSedUniformRangeAllowedAttributes      = 22903
, SedmlSedUniformRangeStartMustBeDouble      = 22904
, SedmlSedUniformRangeEndMustBeDouble      = 22905
, SedmlSedUniformRangeNumberOfPointsMustBeInteger      = 22906
, SedmlSedUniformRangeTypeMustBeString      = 22907
, SedmlSedVectorRangeAllowedCoreAttributes      = 23001
, SedmlSedVectorRangeAllowedCoreElements      = 23002
, SedmlSedVectorRangeAllowedAttributes      = 23003
, SedmlSedVectorRangeValueMustBeString      = 23004
, SedmlSedFunctionalRangeAllowedCoreAttributes      = 23101
, SedmlSedFunctionalRangeAllowedCoreElements      = 23102
, SedmlSedFunctionalRangeAllowedAttributes      = 23103
, SedmlSedFunctionalRangeAllowedElements      = 23104
, SedmlSedFunctionalRangeRangeMustBeRange      = 23105
, SedmlSedFunctionalRangeLOVariablesAllowedCoreElements      = 23106
, SedmlSedFunctionalRangeLOParametersAllowedCoreElements      = 23107
, SedmlSedFunctionalRangeLOVariablesAllowedCoreAttributes      = 23108
, SedmlSedFunctionalRangeLOParametersAllowedCoreAttributes      = 23109
, SedmlSedSubTaskAllowedCoreAttributes      = 23201
, SedmlSedSubTaskAllowedCoreElements      = 23202
, SedmlSedSubTaskAllowedAttributes      = 23203
, SedmlSedSubTaskOrderMustBeInteger      = 23204
, SedmlSedSubTaskTaskMustBeAbstractTask      = 23205
, SedmlSedOneStepAllowedCoreAttributes      = 23301
, SedmlSedOneStepAllowedCoreElements      = 23302
, SedmlSedOneStepAllowedAttributes      = 23303
, SedmlSedOneStepStepMustBeDouble      = 23304
, SedmlSedSteadyStateAllowedCoreAttributes      = 23401
, SedmlSedSteadyStateAllowedCoreElements      = 23402
, SedmlSedRepeatedTaskAllowedCoreAttributes      = 23501
, SedmlSedRepeatedTaskAllowedCoreElements      = 23502
, SedmlSedRepeatedTaskAllowedAttributes      = 23503
, SedmlSedRepeatedTaskAllowedElements      = 23504
, SedmlSedRepeatedTaskRangeIdMustBeRange      = 23505
, SedmlSedRepeatedTaskResetModelMustBeBoolean      = 23506
, SedmlSedRepeatedTaskLORangesAllowedCoreElements      = 23507
, SedmlSedRepeatedTaskLOSetValuesAllowedCoreElements      = 23508
, SedmlSedRepeatedTaskLOSubTasksAllowedCoreElements      = 23509
, SedmlSedRepeatedTaskLORangesAllowedCoreAttributes      = 23510
, SedmlSedRepeatedTaskLOSetValuesAllowedCoreAttributes      = 23511
, SedmlSedRepeatedTaskLOSubTasksAllowedCoreAttributes      = 23512
, SedmlSedComputeChangeAllowedCoreAttributes      = 23601
, SedmlSedComputeChangeAllowedCoreElements      = 23602
, SedmlSedComputeChangeAllowedElements      = 23603
, SedmlSedComputeChangeLOVariablesAllowedCoreElements      = 23604
, SedmlSedComputeChangeLOParametersAllowedCoreElements      = 23605
, SedmlSedComputeChangeLOVariablesAllowedCoreAttributes      = 23606
, SedmlSedComputeChangeLOParametersAllowedCoreAttributes      = 23607
, SedmlSedDataDescriptionAllowedCoreAttributes      = 23701
, SedmlSedDataDescriptionAllowedCoreElements      = 23702
, SedmlSedDataDescriptionAllowedAttributes      = 23703
, SedmlSedDataDescriptionAllowedElements      = 23704
, SedmlSedDataDescriptionNameMustBeString      = 23705
, SedmlSedDataDescriptionFormatMustBeString      = 23706
, SedmlSedDataDescriptionSourceMustBeString      = 23707
, SedmlSedDataDescriptionLODataSourcesAllowedCoreElements      = 23708
, SedmlSedDataDescriptionLODataSourcesAllowedCoreAttributes      = 23709
, SedmlSedDataSourceAllowedCoreAttributes      = 23801
, SedmlSedDataSourceAllowedCoreElements      = 23802
, SedmlSedDataSourceAllowedAttributes      = 23803
, SedmlSedDataSourceAllowedElements      = 23804
, SedmlSedDataSourceNameMustBeString      = 23805
, SedmlSedDataSourceIndexSetMustBe      = 23806
, SedmlSedDataSourceLOSlicesAllowedCoreElements      = 23807
, SedmlSedDataSourceLOSlicesAllowedCoreAttributes      = 23808
, SedmlSedSliceAllowedCoreAttributes      = 23901
, SedmlSedSliceAllowedCoreElements      = 23902
, SedmlSedSliceAllowedAttributes      = 23903
, SedmlSedSliceReferenceMustBe      = 23904
, SedmlSedSliceValueMustBeString      = 23905
, SedmlSedParameterEstimationTaskAllowedCoreAttributes      = 24001
, SedmlSedParameterEstimationTaskAllowedCoreElements      = 24002
, SedmlSedParameterEstimationTaskAllowedElements      = 24003
, SedmlSedParameterEstimationTaskLOAdjustableParametersAllowedCoreElements      = 24004
, SedmlSedParameterEstimationTaskLOFitExperimentsAllowedCoreElements      = 24005
, SedmlSedParameterEstimationTaskLOAdjustableParametersAllowedCoreAttributes      = 24006
, SedmlSedParameterEstimationTaskLOFitExperimentsAllowedCoreAttributes      = 24007
, SedmlSedObjectiveAllowedCoreAttributes      = 24101
, SedmlSedObjectiveAllowedCoreElements      = 24102
, SedmlSedLeastSquareObjectiveFunctionAllowedCoreAttributes      = 24201
, SedmlSedLeastSquareObjectiveFunctionAllowedCoreElements      = 24202
, SedmlSedAdjustableParameterAllowedCoreAttributes      = 24301
, SedmlSedAdjustableParameterAllowedCoreElements      = 24302
, SedmlSedAdjustableParameterAllowedAttributes      = 24303
, SedmlSedAdjustableParameterAllowedElements      = 24304
, SedmlSedAdjustableParameterModelReferenceMustBeModel      = 24305
, SedmlSedAdjustableParameterTargetMustBeString      = 24306
, SedmlSedAdjustableParameterLOExperimentRefsAllowedCoreElements      = 24307
, SedmlSedAdjustableParameterLOExperimentRefsAllowedCoreAttributes      = 24308
, SedmlSedExperimentRefAllowedCoreAttributes      = 24401
, SedmlSedExperimentRefAllowedCoreElements      = 24402
, SedmlSedExperimentRefAllowedAttributes      = 24403
, SedmlSedExperimentRefExperimentIdMustBeFitExperiment      = 24404
, SedmlSedFitExperimentAllowedCoreAttributes      = 24501
, SedmlSedFitExperimentAllowedCoreElements      = 24502
, SedmlSedFitExperimentAllowedAttributes      = 24503
, SedmlSedFitExperimentAllowedElements      = 24504
, SedmlSedFitExperimentSourceMustBeString      = 24505
, SedmlSedFitExperimentLOFitMappingsAllowedCoreElements      = 24506
, SedmlSedFitExperimentLOFitMappingsAllowedCoreAttributes      = 24507
, SedmlSedFitMappingAllowedCoreAttributes      = 24601
, SedmlSedFitMappingAllowedCoreElements      = 24602
, SedmlSedFitMappingAllowedAttributes      = 24603
, SedmlSedFitMappingAllowedElements      = 24604
, SedmlSedFitMappingColNumberMustBeInteger      = 24605
, SedmlSedFitMappingDataGeneratorMustBeDataGenerator      = 24606
, SedmlSedFitMappingTypeMustBeMappingTypeEnum      = 24607
, SedmlSedScalingAllowedCoreAttributes      = 24701
, SedmlSedScalingAllowedCoreElements      = 24702
, SedmlSedValueScalingAllowedCoreAttributes      = 24801
, SedmlSedValueScalingAllowedCoreElements      = 24802
, SedmlSedValueScalingAllowedAttributes      = 24803
, SedmlSedValueScalingWeightMustBeString      = 24804
, SedmlSedColumnScalingAllowedCoreAttributes      = 24901
, SedmlSedColumnScalingAllowedCoreElements      = 24902
, SedmlSedColumnScalingAllowedAttributes      = 24903
, SedmlSedColumnScalingColNumberMustBeInteger      = 24904
, SedmlSedBoundsAllowedCoreAttributes      = 25001
, SedmlSedBoundsAllowedCoreElements      = 25002
, SedmlSedBoundsAllowedAttributes      = 25003
, SedmlSedBoundsStartingValueMustBeDouble      = 25004
, SedmlSedBoundsLowerBoundMustBeDouble      = 25005
, SedmlSedBoundsUpperBoundMustBeDouble      = 25006
, SedmlSedFigureAllowedCoreAttributes      = 25101
, SedmlSedFigureAllowedCoreElements      = 25102
, SedmlSedFigureAllowedAttributes      = 25103
, SedmlSedFigureAllowedElements      = 25104
, SedmlSedFigureNumRowsMustBeInteger      = 25105
, SedmlSedFigureNumColumnsMustBeInteger      = 25106
, SedmlSedFigureLOSubPlotsAllowedCoreElements      = 25107
, SedmlSedFigureLOSubPlotsAllowedCoreAttributes      = 25108
, SedmlSedSubPlotAllowedCoreAttributes      = 25201
, SedmlSedSubPlotAllowedCoreElements      = 25202
, SedmlSedSubPlotAllowedAttributes      = 25203
, SedmlSedSubPlotPlotMustBePlot      = 25204
, SedmlSedSubPlotRowMustBeInteger      = 25205
, SedmlSedSubPlotColumnMustBeInteger      = 25206
, SedmlSedSubPlotRowSpanMustBeInteger      = 25207
, SedmlSedSubPlotColumnSpanMustBeInteger      = 25208
, SedmlSedAxisAllowedCoreAttributes      = 25301
, SedmlSedAxisAllowedCoreElements      = 25302
, SedmlSedAxisAllowedAttributes      = 25303
, SedmlSedAxisTypeMustBeAxisKindEnum      = 25304
, SedmlSedAxisMinMustBeDouble      = 25305
, SedmlSedAxisMaxMustBeDouble      = 25306
, SedmlSedAxisGridMustBeBoolean      = 25307
, SedmlSedAxisStyleMustBeStyle      = 25308
, SedmlSedStyleAllowedCoreAttributes      = 25401
, SedmlSedStyleAllowedCoreElements      = 25402
, SedmlSedStyleAllowedAttributes      = 25403
, SedmlSedStyleAllowedElements      = 25404
, SedmlSedStyleBaseStyleMustBeStyle      = 25405
, SedmlSedLineAllowedCoreAttributes      = 25501
, SedmlSedLineAllowedCoreElements      = 25502
, SedmlSedLineAllowedAttributes      = 25503
, SedmlSedLineStyleMustBeLineKindEnum      = 25504
, SedmlSedLineColorMustBeString      = 25505
, SedmlSedLineThicknessMustBeDouble      = 25506
, SedmlSedMarkerAllowedCoreAttributes      = 25601
, SedmlSedMarkerAllowedCoreElements      = 25602
, SedmlSedMarkerAllowedAttributes      = 25603
, SedmlSedMarkerSizeMustBeDouble      = 25604
, SedmlSedMarkerStyleMustBeMarkerKindEnum      = 25605
, SedmlSedMarkerFillMustBeString      = 25606
, SedmlSedMarkerLineColorMustBeString      = 25607
, SedmlSedMarkerLineThicknessMustBeDouble      = 25608
, SedmlSedFillAllowedCoreAttributes      = 25701
, SedmlSedFillAllowedCoreElements      = 25702
, SedmlSedFillAllowedAttributes      = 25703
, SedmlSedFillColorMustBeString      = 25704
, SedmlSedFillSecondColorMustBeString      = 25705
, SedmlSedDependentVariableAllowedCoreAttributes      = 25801
, SedmlSedDependentVariableAllowedCoreElements      = 25802
, SedmlSedDependentVariableAllowedAttributes      = 25803
, SedmlSedDependentVariableTermMustBeString      = 25804
, SedmlSedDependentVariableTarget2MustBeString      = 25805
, SedmlSedDependentVariableSymbol2MustBeString      = 25806
, SedmlSedRemainingDimensionAllowedCoreAttributes      = 25901
, SedmlSedRemainingDimensionAllowedCoreElements      = 25902
, SedmlSedRemainingDimensionAllowedAttributes      = 25903
, SedmlSedRemainingDimensionTargetMustBe      = 25904
, SedmlSedRemainingDimensionDimensionTargetMustBe      = 25905
, SedmlSedDataRangeAllowedCoreAttributes      = 26001
, SedmlSedDataRangeAllowedCoreElements      = 26002
, SedmlSedDataRangeAllowedAttributes      = 26003
, SedmlSedDataRangeSourceRefMustBe      = 26004
, SedmlSedSimpleRepeatedTaskAllowedCoreAttributes      = 26101
, SedmlSedSimpleRepeatedTaskAllowedCoreElements      = 26102
, SedmlSedSimpleRepeatedTaskAllowedAttributes      = 26103
, SedmlSedSimpleRepeatedTaskResetModelMustBeBoolean      = 26104
, SedmlSedSimpleRepeatedTaskNumRepeatsMustBeInteger      = 26105
, SedmlSedShadedAreaAllowedCoreAttributes      = 26201
, SedmlSedShadedAreaAllowedCoreElements      = 26202
, SedmlSedShadedAreaAllowedAttributes      = 26203
, SedmlSedShadedAreaYDataReferenceFromMustBeDataGenerator      = 26204
, SedmlSedShadedAreaYDataReferenceToMustBeDataGenerator      = 26205
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
