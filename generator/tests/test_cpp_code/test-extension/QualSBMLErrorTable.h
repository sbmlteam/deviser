/**
 * @file QualSBMLErrorTable.h
 * @brief Definition of QualSBMLErrorTable.
 * @author SBMLTeam
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2015 jointly by the following organizations:
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


#ifndef QualSBMLErrorTable_H__
#define QualSBMLErrorTable_H__


#include <sbml/packages/qual/validator/QualSBMLError.h>


LIBSBML_CPP_NAMESPACE_BEGIN



/** @cond doxygenLibsbmlInternal */

static const packageErrorTableEntry qualErrorTable[] =
{
  // 3010100
  { QualUnknown,
    "Unknown error from Qual",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Unknown error from Qual",
    { ""
    }
  },

  // 3010101
  { QualNSUndeclared,
    "The Qual namespace is not correctly declared.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "To conform to the <QualitativeModelsPackage> specification for SBML "
    "Level~3 Version~1, an SBML document must declare the use of the following "
    "XML Namespace: "
    "'http://www>.sbml.org/sbml/level3/version1/qual/version1'.",
    { "L3V1 Qual V1 Section 3.1"
    }
  },

  // 3010102
  { QualElementNotInNs,
    "Element not in Qual namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "<QualitativeModelsPackage> package must be declared either implicitly or "
    "explicitly to be in the XML namespace "
    "'http://www>.sbml.org/sbml/level3/version1/qual/version1'.",
    { "L3V1 Qual V1 Section 3.1"
    }
  },

  // 3010301
  { QualDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification.) TO "
    "DO list scope of ids)",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3010302
  { QualIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of a 'qual:id' must conform to the syntax of the "
    "<class{SBML}> data type <primtype{SId}>",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020101
  { QualAttributeRequiredMissing,
    "Required qual:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the Qualatitive Models Package, the <sbml> object "
    "must have the 'qual:required' attribute.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020102
  { QualAttributeRequiredMustBeBoolean,
    "The qual:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute <token{qual:<-required}> on the <class{SBML}> "
    "object must be of data type Boolean.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020103
  { QualAttributeRequiredMustHaveValue,
    "The qual:required attribute must be 'FIX ME'",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute <token{qual:<-required}> on the <class{SBML}> "
    "object must be set to <val{false}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020201
  { QualModelAllowedElements,
    "Elements allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <Model> object may contain one and only one instance of each of the "
    "<ListOfQualitativeSpecies> and <ListOfTransitions> elements. No other "
    "elements from the SBML Level 3 Qualitative Models namespaces are permitted "
    "on a <Model> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020202
  { QualModelEmptyLOElements,
    "No Empty ListOf elements allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <ListOfQualitativeSpecies> and <ListOfTransitions> subobjects on a "
    "<Model> object is optional, but if present, these container objects must "
    "not be empty.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020203
  { QualModelLOQualitativeSpeciesAllowedElements,
    "Core elements allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a ListOfQualitativeSpecies container object may only contain "
    "<QualitativeSpecies> objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020204
  { QualModelLOTransitionsAllowedElements,
    "Core elements allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a ListOfTransitions container object may only contain "
    "<Transition> objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020205
  { QualModelLOQualitativeSpeciesAllowedCoreAttributes,
    "Core attributes allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <ListOfQualitativeSpecies> object may have the optional SBML Level~3 "
    "Core attributes <token{metaid}> and <token{sboTerm}>. No other attributes "
    "from the SBML Level 3 Core namespaces are permitted on a "
    "<ListOfQualitativeSpecies> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020206
  { QualModelLOTransitionsAllowedCoreAttributes,
    "Core attributes allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <ListOfTransitions> object may have the optional SBML Level~3 Core "
    "attributes <token{metaid}> and <token{sboTerm}>. No other attributes from "
    "the SBML Level 3 Core namespaces are permitted on a <ListOfTransitions> "
    "object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020301
  { QualQualitativeSpeciesAllowedCoreAttributes,
    "Core attributes allowed on <QualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <QualitativeSpecies> object may have the optional SBML Level~3 Core "
    "attributes <token{metaid}> and <token{sboTerm}>. No other attributes from "
    "the SBML Level 3 Core namespaces are permitted on a "
    "<QualitativeSpecies>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020302
  { QualQualitativeSpeciesAllowedCoreElements,
    "Core elements allowed on <QualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <QualitativeSpecies> object may have the optional SBML Level~3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <QualitativeSpecies>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020303
  { QualQualitativeSpeciesAllowedAttributes,
    "Attributes allowed on <QualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <QualitativeSpecies> object must have the required attributes "
    "<token{qual:<-id},> <token{qual:<-compartment}> and "
    "<token{qual:<-constant},> and may have the optional attributes "
    "<token{qual:<-name},> <token{qual:<-initialLevel}> and "
    "<token{qual:<-maxLevel}>. No other attributes from the SBML Level 3 "
    "Qualitative Models namespaces are permitted on a <QualitativeSpecies> "
    "object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020304
  { QualQualitativeSpeciesCompartmentMustBeCompartment,
    "Attributes allowed on <QualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute <token{qual:<-compartment}> of a "
    "<QualitativeSpecies> object must be the identifier of an existing "
    "<Compartment> object defined in the enclosing <Model> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020305
  { QualQualitativeSpeciesConstantMustBeBoolean,
    "Attributes allowed on <QualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-constant}> on a <QualitativeSpecies> must have "
    "a value of data type <token{boolean}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020306
  { QualQualitativeSpeciesNameMustBeString,
    "Attributes allowed on <QualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-name}> on a <QualitativeSpecies> must have a "
    "value of data type <token{string}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020307
  { QualQualitativeSpeciesInitialLevelMustBeUnInteger,
    "Attributes allowed on <QualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-initialLevel}> on a <QualitativeSpecies> must "
    "have a value of data type <token{integer}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020308
  { QualQualitativeSpeciesMaxLevelMustBeUnInteger,
    "Attributes allowed on <QualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-maxLevel}> on a <QualitativeSpecies> must have "
    "a value of data type <token{integer}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020401
  { QualTransitionAllowedCoreAttributes,
    "Core attributes allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <Transition> object may have the optional SBML Level~3 Core attributes "
    "<token{metaid}> and <token{sboTerm}>. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <Transition>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020402
  { QualTransitionAllowedCoreElements,
    "Core elements allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <Transition> object may have the optional SBML Level~3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <Transition>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020403
  { QualTransitionAllowedAttributes,
    "Attributes allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <Transition> object may have the optional attributes <token{qual:<-id}> "
    "and <token{qual:<-name}>. No other attributes from the SBML Level 3 "
    "Qualitative Models namespaces are permitted on a <Transition> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020404
  { QualTransitionAllowedElements,
    "Elements allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <Transition> object must contain one and only one instance of the "
    "<ListOfFunctionTerms> element, and may contain one and only one instance "
    "of each of the <ListOfInputs> and <ListOfOutputs> elements. No other "
    "elements from the SBML Level 3 Qualitative Models namespaces are permitted "
    "on a <Transition> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020405
  { QualTransitionNameMustBeString,
    "Attributes allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-name}> on a <Transition> must have a value of "
    "data type <token{string}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020406
  { QualTransitionEmptyLOElements,
    "No Empty ListOf elements allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <ListOfInputs> and <ListOfOutputs> subobjects on a <Transition> object "
    "is optional, but if present, these container objects must not be empty.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020407
  { QualTransitionLOInputsAllowedElements,
    "Core elements allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <ListOfInputs> container object may only contain <Input> "
    "objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020408
  { QualTransitionLOOutputsAllowedElements,
    "Core elements allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <ListOfOutputs> container object may only contain <Output> "
    "objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020409
  { QualTransitionLOFunctionTermsAllowedElements,
    "Core elements allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <ListOfFunctionTerms> container object may only contain "
    "<FunctionTerm> objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020410
  { QualTransitionLOInputsAllowedCoreAttributes,
    "Core attributes allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <ListOfInputs> object may have the optional SBML Level~3 Core attributes "
    "<token{metaid}> and <token{sboTerm}>. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <ListOfInputs> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020411
  { QualTransitionLOOutputsAllowedCoreAttributes,
    "Core attributes allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <ListOfOutputs> object may have the optional SBML Level~3 Core "
    "attributes <token{metaid}> and <token{sboTerm}>. No other attributes from "
    "the SBML Level 3 Core namespaces are permitted on a <ListOfOutputs> "
    "object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020412
  { QualTransitionLOFunctionTermsAllowedCoreAttributes,
    "Core attributes allowed on <Transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <ListOfFunctionTerms> object may have the optional SBML Level~3 Core "
    "attributes <token{metaid}> and <token{sboTerm}>. No other attributes from "
    "the SBML Level 3 Core namespaces are permitted on a <ListOfFunctionTerms> "
    "object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020501
  { QualInputAllowedCoreAttributes,
    "Core attributes allowed on <Input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <Input> object may have the optional SBML Level~3 Core attributes "
    "<token{metaid}> and <token{sboTerm}>. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on an <Input>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020502
  { QualInputAllowedCoreElements,
    "Core elements allowed on <Input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <Input> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <Input>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020503
  { QualInputAllowedAttributes,
    "Attributes allowed on <Input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <Input> object must have the required attribute "
    "<token{qual:<-qualitativeSpecies},> and may have the optional attributes "
    "<token{qual:<-id},> <token{qual:<-name},> <token{qual:<-sign},> "
    "<token{qual:<-transitionEffect}> and <token{qual:<-thresholdLevel}>. No "
    "other attributes from the SBML Level 3 Qualitative Models namespaces are "
    "permitted on an <Input> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020504
  { QualInputQualitativeSpeciesMustBeQualitativeSpecies,
    "Attributes allowed on <Input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute <token{qual:<-qualitativeSpecies}> of an "
    "<Input> object must be the identifier of an existing <QualitativeSpecies> "
    "object defined in the enclosing <Model> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020505
  { QualInputNameMustBeString,
    "Attributes allowed on <Input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-name}> on an <Input> must have a value of data "
    "type <token{string}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020506
  { QualInputSignMustBeSignEnum,
    "Attributes allowed on <Input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute <token{qual:<-sign}> of an <Input> object must "
    "conform to the syntax of SBML data type <primtype{sign}> and may only take "
    "on the allowed values of <primtype{sign}> defined in SBML; that is the "
    "value must be one of the following "positive", "negative", "dual" or
    "unknown".",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020507
  { QualInputTransitionEffectMustBeTransitionInputEffectEnum,
    "Attributes allowed on <Input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute <token{qual:<-transitionEffect}> of an <Input> "
    "object must conform to the syntax of SBML data type "
    "<primtype{transitionInputEffect}> and may only take on the allowed values "
    "of <primtype{transitionInputEffect}> defined in SBML; that is the value "
    "must be one of the following "none" or "consumption".",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020508
  { QualInputThresholdLevelMustBeUnInteger,
    "Attributes allowed on <Input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-thresholdLevel}> on an <Input> must have a "
    "value of data type <token{integer}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020601
  { QualOutputAllowedCoreAttributes,
    "Core attributes allowed on <Output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <Output> object may have the optional SBML Level~3 Core attributes "
    "<token{metaid}> and <token{sboTerm}>. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on an <Output>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020602
  { QualOutputAllowedCoreElements,
    "Core elements allowed on <Output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <Output> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <Output>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020603
  { QualOutputAllowedAttributes,
    "Attributes allowed on <Output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <Output> object must have the required attributes "
    "<token{qual:<-qualitativeSpecies}> and <token{qual:<-transitionEffect},> "
    "and may have the optional attributes <token{qual:<-id},> "
    "<token{qual:<-name}> and <token{qual:<-outputLevel}>. No other attributes "
    "from the SBML Level 3 Qualitative Models namespaces are permitted on an "
    "<Output> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020604
  { QualOutputQualitativeSpeciesMustBeQualitativeSpecies,
    "Attributes allowed on <Output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute <token{qual:<-qualitativeSpecies}> of an "
    "<Output> object must be the identifier of an existing <QualitativeSpecies> "
    "object defined in the enclosing <Model> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020605
  { QualOutputTransitionEffectMustBeTransitionOutputEffectEnum,
    "Attributes allowed on <Output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute <token{qual:<-transitionEffect}> of an <Output> "
    "object must conform to the syntax of SBML data type "
    "<primtype{transitionOutputEffect}> and may only take on the allowed values "
    "of <primtype{transitionOutputEffect}> defined in SBML; that is the value "
    "must be one of the following "production" or "assignmentLevel".",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020606
  { QualOutputNameMustBeString,
    "Attributes allowed on <Output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-name}> on an <Output> must have a value of "
    "data type <token{string}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020607
  { QualOutputOutputLevelMustBeInteger,
    "Attributes allowed on <Output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-outputLevel}> on an <Output> must have a value "
    "of data type <token{integer}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020701
  { QualDefaultTermAllowedCoreAttributes,
    "Core attributes allowed on <DefaultTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <DefaultTerm> object may have the optional SBML Level~3 Core attributes "
    "<token{metaid}> and <token{sboTerm}>. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <DefaultTerm>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020702
  { QualDefaultTermAllowedCoreElements,
    "Core elements allowed on <DefaultTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <DefaultTerm> object may have the optional SBML Level~3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <DefaultTerm>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020703
  { QualDefaultTermAllowedAttributes,
    "Attributes allowed on <DefaultTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <DefaultTerm> object must have the required attribute "
    "<token{qual:<-resultLevel}>. No other attributes from the SBML Level 3 "
    "Qualitative Models namespaces are permitted on a <DefaultTerm> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020704
  { QualDefaultTermResultLevelMustBeUnInteger,
    "Attributes allowed on <DefaultTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-resultLevel}> on a <DefaultTerm> must have a "
    "value of data type <token{integer}>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020801
  { QualFunctionTermAllowedCoreAttributes,
    "Core attributes allowed on <FunctionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <FunctionTerm> object may have the optional SBML Level~3 Core attributes "
    "<token{metaid}> and <token{sboTerm}>. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <FunctionTerm>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020802
  { QualFunctionTermAllowedCoreElements,
    "Core elements allowed on <FunctionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <FunctionTerm> object may have the optional SBML Level~3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <FunctionTerm>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020803
  { QualFunctionTermAllowedAttributes,
    "Attributes allowed on <FunctionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <FunctionTerm> object must have the required attribute "
    "<token{qual:<-resultLevel}>. No other attributes from the SBML Level 3 "
    "Qualitative Models namespaces are permitted on a <FunctionTerm> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020804
  { QualFunctionTermAllowedElements,
    "Elements allowed on <FunctionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <FunctionTerm> object must contain one and only one instance of the "
    "ASTNode element. No other elements from the SBML Level 3 Qualitative "
    "Models namespaces are permitted on a <FunctionTerm> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020805
  { QualFunctionTermResultLevelMustBeUnInteger,
    "Attributes allowed on <FunctionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute <token{qual:<-resultLevel}> on a <FunctionTerm> must have a "
    "value of data type <token{integer}>.",
    { "L3V1 Qual V1 Section"
    }
  },

};

/** @endcond */



LIBSBML_CPP_NAMESPACE_END




#endif /* !QualSBMLErrorTable_H__ */


