/**
 * @file QualSBMLErrorTable.h
 * @brief Definition of the QualSBMLErrorTable class.
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
    "To conform to the Qualitative Models Package specification for SBML "
    "Level~3 Version~1, an SBML document must declare the use of the following "
    "XML Namespace: 'http://www.sbml.org/sbml/level3/version1/qual/version1'.",
    { "L3V1 Qual V1 Section 3.1"
    }
  },

  // 3010102
  { QualElementNotInNs,
    "Element not in Qual namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Qualitative Models Package must be declared either implicitly or "
    "explicitly to be in the XML namespace "
    "'http://www.sbml.org/sbml/level3/version1/qual/version1'.",
    { "L3V1 Qual V1 Section 3.1"
    }
  },

  // 3010301
  { QualDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3010302
  { QualIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of a 'qual:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020101
  { QualAttributeRequiredMissing,
    "Required qual:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the Qualitative Models Package, the <sbml> "
    "object must have the 'qual:required' attribute.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020102
  { QualAttributeRequiredMustBeBoolean,
    "The qual:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'qual:required' on the <sbml> object must be of "
    "data type 'boolean'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020103
  { QualAttributeRequiredMustHaveValue,
    "The qual:required attribute must be 'FIX ME'",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'qual:required' on the <sbml> object must be set to "
    "'false'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020201
  { QualModelAllowedElements,
    "Elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <model> object may contain one and only one instance of each of the "
    "<listOfQualitativeSpecies> and <listOfTransitions> elements. No other "
    "elements from the SBML Level 3 Qualitative Models namespaces are permitted "
    "on a <model> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020202
  { QualModelEmptyLOElements,
    "No Empty ListOf elements allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfQualitativeSpecies> and <listOfTransitions> subobjects on a "
    "<model> object is optional, but if present, these container objects must "
    "not be empty.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020203
  { QualModelLOQualitativeSpeciesAllowedElements,
    "Core elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a ListOfQualitativeSpecies container object may only contain "
    "<qualitativeSpecies> objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020204
  { QualModelLOTransitionsAllowedElements,
    "Core elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a ListOfTransitions container object may only contain "
    "<transition> objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020205
  { QualModelLOQualitativeSpeciesAllowedCoreAttributes,
    "Core attributes allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfQualitativeSpecies> object may have the optional SBML Level~3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfQualitativeSpecies> "
    "object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020206
  { QualModelLOTransitionsAllowedCoreAttributes,
    "Core attributes allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfTransitions> object may have the optional SBML Level~3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfTransitions> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020301
  { QualQualitativeSpeciesAllowedCoreAttributes,
    "Core attributes allowed on <qualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <qualitativeSpecies> object may have the optional SBML Level~3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <qualitativeSpecies>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020302
  { QualQualitativeSpeciesAllowedCoreElements,
    "Core elements allowed on <qualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <qualitativeSpecies> object may have the optional SBML Level~3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <qualitativeSpecies>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020303
  { QualQualitativeSpeciesAllowedAttributes,
    "Attributes allowed on <qualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <qualitativeSpecies> object must have the required attributes 'qual:id', "
    "'qual:compartment' and 'qual:constant', and may have the optional "
    "attributes 'qual:name', 'qual:initialLevel' and 'qual:maxLevel'. No other "
    "attributes from the SBML Level 3 Qualitative Models namespaces are "
    "permitted on a <qualitativeSpecies> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020304
  { QualQualitativeSpeciesCompartmentMustBeCompartment,
    "Attributes allowed on <qualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'qual:compartment' of a <qualitativeSpecies> "
    "object must be the identifier of an existing <compartment> object defined "
    "in the enclosing <model> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020305
  { QualQualitativeSpeciesConstantMustBeBoolean,
    "Attributes allowed on <qualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:constant' on a <qualitativeSpecies> must have a value "
    "of data type 'boolean'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020306
  { QualQualitativeSpeciesNameMustBeString,
    "Attributes allowed on <qualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:name' on a <qualitativeSpecies> must have a value of "
    "data type 'string'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020307
  { QualQualitativeSpeciesInitialLevelMustBeUnInteger,
    "Attributes allowed on <qualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:initialLevel' on a <qualitativeSpecies> must have a "
    "value of data type 'integer'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020308
  { QualQualitativeSpeciesMaxLevelMustBeUnInteger,
    "Attributes allowed on <qualitativeSpecies>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:maxLevel' on a <qualitativeSpecies> must have a value "
    "of data type 'integer'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020401
  { QualTransitionAllowedCoreAttributes,
    "Core attributes allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <transition> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <transition>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020402
  { QualTransitionAllowedCoreElements,
    "Core elements allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <transition> object may have the optional SBML Level~3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <transition>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020403
  { QualTransitionAllowedAttributes,
    "Attributes allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <transition> object may have the optional attributes 'qual:id' and "
    "'qual:name'. No other attributes from the SBML Level 3 Qualitative Models "
    "namespaces are permitted on a <transition> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020404
  { QualTransitionAllowedElements,
    "Elements allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <transition> object must contain one and only one instance of the "
    "<listOfFunctionTerms> element, and may contain one and only one instance "
    "of each of the <listOfInputs> and <listOfOutputs> elements. No other "
    "elements from the SBML Level 3 Qualitative Models namespaces are permitted "
    "on a <transition> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020405
  { QualTransitionNameMustBeString,
    "Attributes allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:name' on a <transition> must have a value of data type "
    "'string'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020406
  { QualTransitionEmptyLOElements,
    "No Empty ListOf elements allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfInputs> and <listOfOutputs> subobjects on a <transition> object "
    "are optional, but if present, these container objects must not be empty.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020407
  { QualTransitionLOInputsAllowedElements,
    "Core elements allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfInputs> container object may only contain <input> "
    "objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020408
  { QualTransitionLOOutputsAllowedElements,
    "Core elements allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfOutputs> container object may only contain <output> "
    "objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020409
  { QualTransitionEmptyReqdLOElements,
    "No Empty ListOf elements allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfFunctionTerms> subobject on a <transition> object must not be "
    "empty.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020410
  { QualTransitionLOFunctionTermsAllowedElements,
    "Core elements allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfFunctionTerms> container object may only contain "
    "<functionTerm> objects.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020411
  { QualTransitionLOInputsAllowedCoreAttributes,
    "Core attributes allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfInputs> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfInputs> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020412
  { QualTransitionLOOutputsAllowedCoreAttributes,
    "Core attributes allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfOutputs> object may have the optional SBML Level~3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfOutputs> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020413
  { QualTransitionLOFunctionTermsAllowedCoreAttributes,
    "Core attributes allowed on <transition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfFunctionTerms> object may have the optional SBML Level~3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfFunctionTerms> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020501
  { QualInputAllowedCoreAttributes,
    "Core attributes allowed on <input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <input> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <input>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020502
  { QualInputAllowedCoreElements,
    "Core elements allowed on <input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <input> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <input>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020503
  { QualInputAllowedAttributes,
    "Attributes allowed on <input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <input> object must have the required attribute "
    "'qual:qualitativeSpecies', and may have the optional attributes 'qual:id', "
    "'qual:name', 'qual:sign', 'qual:transitionEffect' and "
    "'qual:thresholdLevel'. No other attributes from the SBML Level 3 "
    "Qualitative Models namespaces are permitted on an <input> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020504
  { QualInputQualitativeSpeciesMustBeQualitativeSpecies,
    "Attributes allowed on <input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'qual:qualitativeSpecies' of an <input> object "
    "must be the identifier of an existing <qualitativeSpecies> object defined "
    "in the enclosing <model> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020505
  { QualInputNameMustBeString,
    "Attributes allowed on <input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:name' on an <input> must have a value of data type "
    "'string'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020506
  { QualInputSignMustBeSignEnum,
    "Attributes allowed on <input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'qual:sign' of an <input> object must conform "
    "to the syntax of SBML data type 'sign' and may only take on the allowed "
    "values of 'sign' defined in SBML; that is the value must be one of the "
    "following: 'positive', 'negative', 'dual' or 'unknown'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020507
  { QualInputTransitionEffectMustBeTransitionInputEffectEnum,
    "Attributes allowed on <input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'qual:transitionEffect' of an <input> object "
    "must conform to the syntax of SBML data type 'transitionInputEffect' and "
    "may only take on the allowed values of 'transitionInputEffect' defined in "
    "SBML; that is the value must be one of the following: 'none' or "
    "'consumption'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020508
  { QualInputThresholdLevelMustBeUnInteger,
    "Attributes allowed on <input>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:thresholdLevel' on an <input> must have a value of "
    "data type 'integer'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020601
  { QualOutputAllowedCoreAttributes,
    "Core attributes allowed on <output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <output> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <output>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020602
  { QualOutputAllowedCoreElements,
    "Core elements allowed on <output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <output> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <output>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020603
  { QualOutputAllowedAttributes,
    "Attributes allowed on <output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <output> object must have the required attributes "
    "'qual:qualitativeSpecies' and 'qual:transitionEffect', and may have the "
    "optional attributes 'qual:id', 'qual:name' and 'qual:outputLevel'. No "
    "other attributes from the SBML Level 3 Qualitative Models namespaces are "
    "permitted on an <output> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020604
  { QualOutputQualitativeSpeciesMustBeQualitativeSpecies,
    "Attributes allowed on <output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'qual:qualitativeSpecies' of an <output> object "
    "must be the identifier of an existing <qualitativeSpecies> object defined "
    "in the enclosing <model> object.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020605
  { QualOutputTransitionEffectMustBeTransitionOutputEffectEnum,
    "Attributes allowed on <output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'qual:transitionEffect' of an <output> object "
    "must conform to the syntax of SBML data type 'transitionOutputEffect' and "
    "may only take on the allowed values of 'transitionOutputEffect' defined in "
    "SBML; that is the value must be one of the following: 'production' or "
    "'assignmentLevel'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020606
  { QualOutputNameMustBeString,
    "Attributes allowed on <output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:name' on an <output> must have a value of data type "
    "'string'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020607
  { QualOutputOutputLevelMustBeInteger,
    "Attributes allowed on <output>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:outputLevel' on an <output> must have a value of data "
    "type 'integer'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020701
  { QualDefaultTermAllowedCoreAttributes,
    "Core attributes allowed on <defaultTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <defaultTerm> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <defaultTerm>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020702
  { QualDefaultTermAllowedCoreElements,
    "Core elements allowed on <defaultTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <defaultTerm> object may have the optional SBML Level~3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <defaultTerm>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020703
  { QualDefaultTermAllowedAttributes,
    "Attributes allowed on <defaultTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <defaultTerm> object must have the required attribute "
    "'qual:resultLevel'. No other attributes from the SBML Level 3 Qualitative "
    "Models namespaces are permitted on a <defaultTerm> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020704
  { QualDefaultTermResultLevelMustBeUnInteger,
    "Attributes allowed on <defaultTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:resultLevel' on a <defaultTerm> must have a value of "
    "data type 'integer'.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020801
  { QualFunctionTermAllowedCoreAttributes,
    "Core attributes allowed on <functionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <functionTerm> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <functionTerm>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020802
  { QualFunctionTermAllowedCoreElements,
    "Core elements allowed on <functionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <functionTerm> object may have the optional SBML Level~3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <functionTerm>.",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020803
  { QualFunctionTermAllowedAttributes,
    "Attributes allowed on <functionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <functionTerm> object must have the required attribute "
    "'qual:resultLevel'. No other attributes from the SBML Level 3 Qualitative "
    "Models namespaces are permitted on a <functionTerm> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020804
  { QualFunctionTermAllowedElements,
    "Elements allowed on <functionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <functionTerm> object must contain one and only one instance of the "
    "ASTNode element. No other elements from the SBML Level 3 Qualitative "
    "Models namespaces are permitted on a <functionTerm> object. ",
    { "L3V1 Qual V1 Section"
    }
  },

  // 3020805
  { QualFunctionTermResultLevelMustBeUnInteger,
    "Attributes allowed on <functionTerm>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'qual:resultLevel' on a <functionTerm> must have a value of "
    "data type 'integer'.",
    { "L3V1 Qual V1 Section"
    }
  },

};

/** @endcond */



LIBSBML_CPP_NAMESPACE_END




#endif /* !QualSBMLErrorTable_H__ */


