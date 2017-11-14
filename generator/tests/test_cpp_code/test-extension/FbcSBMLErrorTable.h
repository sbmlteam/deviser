/**
 * @file FbcSBMLErrorTable.h
 * @brief Definition of the FbcSBMLErrorTable class.
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


#ifndef FbcSBMLErrorTable_H__
#define FbcSBMLErrorTable_H__


#include <sbml/packages/fbc/validator/FbcSBMLError.h>


LIBSBML_CPP_NAMESPACE_BEGIN



/** @cond doxygenLibsbmlInternal */

static const packageErrorTableEntry fbcErrorTable[] =
{
  // 2010100
  { FbcUnknown,
    "Unknown error from Fbc",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Unknown error from Fbc",
    { ""
    }
  },

  // 2010101
  { FbcNSUndeclared,
    "The Fbc namespace is not correctly declared.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "To conform to the Flux Balance Constraints Package specification for SBML "
    "Level 3 Version 1, an SBML document must declare "
    "'http://www.sbml.org/sbml/level3/version1/fbc/version2' as the "
    "XMLNamespace to use for elements of this package.",
    { "L3V1 Fbc V1 Section 3.1"
    }
  },

  // 2010102
  { FbcElementNotInNs,
    "Element not in Fbc namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Flux Balance Constraints Package must use the "
    "'http://www.sbml.org/sbml/level3/version1/fbc/version2' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Fbc V1 Section 3.1"
    }
  },

  // 2010301
  { FbcDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2010302
  { FbcIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of a 'fbc:id' must conform to the syntax of the <sbml> data type "
    "'SId'",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020101
  { FbcAttributeRequiredMissing,
    "Required fbc:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the Flux Balance Constraints Package, the "
    "<sbml> object must have the 'fbc:required' attribute.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020102
  { FbcAttributeRequiredMustBeBoolean,
    "The fbc:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'fbc:required' on the <sbml> object must be of data "
    "type 'boolean'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020103
  { FbcAttributeRequiredMustHaveValue,
    "The fbc:required attribute must be 'false'",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'fbc:required' on the <sbml> object must be set to "
    "'false'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020201
  { FbcModelAllowedAttributes,
    "Attributes allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <model> object must have the required attribute 'fbc:strict'. No other "
    "attributes from the SBML Level 3 Flux Balance Constraints namespaces are "
    "permitted on a <model> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020202
  { FbcModelAllowedElements,
    "Elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <model> object may contain one and only one instance of each of the "
    "<listOfObjectives,> <listOfFluxBounds> and <listOfGeneProducts> elements. "
    "No other elements from the SBML Level 3 Flux Balance Constraints "
    "namespaces are permitted on a <model> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020203
  { FbcModelStrictMustBeBoolean,
    "Strict attribute must be Boolean.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:strict' on a <model> must have a value of data type "
    "'boolean'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020204
  { FbcModelEmptyLOElements,
    "No Empty ListOf elements allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfObjectives,> <listOfFluxBounds> and <listOfGeneProducts> "
    "subobjects on a <model> object is optional, but if present, these "
    "container objects must not be empty.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020205
  { FbcModelLOObjectivesAllowedCoreElements,
    "Core elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfObjectives> container object may only contain "
    "<objective> objects.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020206
  { FbcModelLOFluxBoundsAllowedCoreElements,
    "Core elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfFluxBounds> container object may only contain "
    "<fluxBound> objects.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020207
  { FbcModelLOGeneProductsAllowedCoreElements,
    "Core elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfGeneProducts> container object may only contain "
    "<geneProduct> objects.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020208
  { FbcModelLOObjectivesAllowedCoreAttributes,
    "Core attributes allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfObjectives> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfObjectives> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020209
  { FbcModelLOFluxBoundsAllowedCoreAttributes,
    "Core attributes allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfFluxBounds> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfFluxBounds> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020210
  { FbcModelLOGeneProductsAllowedCoreAttributes,
    "Core attributes allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfGeneProducts> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfGeneProducts> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020211
  { FbcModelLOObjectivesAllowedAttributes,
    "Attributes allowed on <listOfObjectives>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfObjectives> object may have the optional attributes "
    "'fbc:activeObjective' and 'fbc:activeObjective'. No other attributes from "
    "the SBML Level 3 Flux Balance Constraints namespaces are permitted on a "
    "<listOfObjectives> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020212
  { FbcModelActiveObjectiveMustBeObjective,
    "ActiveObjective attribute must be Objective.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:activeObjective' of a <model> object must "
    "be the identifier of an existing <objective> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020301
  { FbcSpeciesAllowedAttributes,
    "Attributes allowed on <species>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <species> object may have the optional attributes 'fbc:charge', "
    "'fbc:chemicalFormula', 'fbc:charge' and 'fbc:chemicalFormula'. No other "
    "attributes from the SBML Level 3 Flux Balance Constraints namespaces are "
    "permitted on a <species> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020302
  { FbcSpeciesChargeMustBeInteger,
    "Charge attribute must be Integer.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:charge' on a <species> must have a value of data type "
    "'integer'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020303
  { FbcSpeciesChemicalFormulaMustBeString,
    "ChemicalFormula attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:chemicalFormula' on a <species> must have a value of "
    "data type 'string'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020401
  { FbcReactionAllowedAttributes,
    "Attributes allowed on <reaction>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <reaction> object may have the optional attributes 'fbc:lowerFluxBound' "
    "and 'fbc:upperFluxBound'. No other attributes from the SBML Level 3 Flux "
    "Balance Constraints namespaces are permitted on a <reaction> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020402
  { FbcReactionAllowedElements,
    "Elements allowed on <reaction>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <reaction> object may contain one and only one instance of the "
    "<geneProductAssociation> element. No other elements from the SBML Level 3 "
    "Flux Balance Constraints namespaces are permitted on a <reaction> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020403
  { FbcReactionLowerFluxBoundMustBeParameter,
    "LowerFluxBound attribute must be Parameter.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:lowerFluxBound' of a <reaction> object "
    "must be the identifier of an existing <parameter> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020404
  { FbcReactionUpperFluxBoundMustBeParameter,
    "UpperFluxBound attribute must be Parameter.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:upperFluxBound' of a <reaction> object "
    "must be the identifier of an existing <parameter> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020501
  { FbcFluxBoundAllowedCoreAttributes,
    "Core attributes allowed on <fluxBound>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <fluxBound> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <fluxBound>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020502
  { FbcFluxBoundAllowedCoreElements,
    "Core elements allowed on <fluxBound>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <fluxBound> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <fluxBound>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020503
  { FbcFluxBoundAllowedAttributes,
    "Attributes allowed on <fluxBound>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <fluxBound> object must have the required attributes 'fbc:id', "
    "'fbc:reaction', 'fbc:operation' and 'fbc:value', and may have the optional "
    "attribute 'fbc:name'. No other attributes from the SBML Level 3 Flux "
    "Balance Constraints namespaces are permitted on a <fluxBound> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020504
  { FbcFluxBoundReactionMustBeReaction,
    "The attribute 'reaction' must point to Reaction object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:reaction' of a <fluxBound> object must be "
    "the identifier of an existing <reaction> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020505
  { FbcFluxBoundOperationMustBeFbcOperationEnum,
    "The 'operation' attribute must be FbcOperationEnum.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:operation' of a <fluxBound> object must "
    "conform to the syntax of SBML data type 'FbcOperation' and may only take "
    "on the allowed values of 'FbcOperation' defined in SBML; that is, the "
    "value must be one of the following: 'lessEqual', 'greaterEqual', 'less', "
    "'greater' or 'equal'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020506
  { FbcFluxBoundValueMustBeDouble,
    "The 'value' attribute must be Double.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:value' on a <fluxBound> must have a value of data type "
    "'double'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020507
  { FbcFluxBoundNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:name' on a <fluxBound> must have a value of data type "
    "'string'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020601
  { FbcObjectiveAllowedCoreAttributes,
    "Core attributes allowed on <objective>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <objective> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <objective>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020602
  { FbcObjectiveAllowedCoreElements,
    "Core elements allowed on <objective>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <objective> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <objective>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020603
  { FbcObjectiveAllowedAttributes,
    "Attributes allowed on <objective>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <objective> object must have the required attributes 'fbc:id', "
    "'fbc:type', 'fbc:id' and 'fbc:type', and may have the optional attributes "
    "'fbc:name' and 'fbc:name'. No other attributes from the SBML Level 3 Flux "
    "Balance Constraints namespaces are permitted on an <objective> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020604
  { FbcObjectiveAllowedElements,
    "Elements allowed on <objective>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <objective> object may contain one and only one instance of each of the "
    "<listOfFluxObjectives> and <listOfFluxObjectives> elements. No other "
    "elements from the SBML Level 3 Flux Balance Constraints namespaces are "
    "permitted on an <objective> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020605
  { FbcObjectiveTypeMustBeFbcTypeEnum,
    "The 'type' attribute must be FbcTypeEnum.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:type' of an <objective> object must "
    "conform to the syntax of SBML data type 'FbcType' and may only take on the "
    "allowed values of 'FbcType' defined in SBML; that is, the value must be "
    "one of the following: 'maximize' or 'minimize'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020607
  { FbcObjectiveNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:name' on an <objective> must have a value of data type "
    "'string'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020609
  { FbcObjectiveEmptyLOElements,
    "No Empty ListOf elements allowed on <objective>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfFluxObjectives> and <listOfFluxObjectives> subobjects on an "
    "<objective> object are optional, but if present, these container objects "
    "must not be empty.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020610
  { FbcObjectiveLOFluxObjectivesAllowedCoreElements,
    "Core elements allowed on <listOfFluxObjectives>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfFluxObjectives> container object may only contain "
    "<fluxObjective> objects.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020612
  { FbcObjectiveLOFluxObjectivesAllowedCoreAttributes,
    "Core attributes allowed on <listOfFluxObjectives>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfFluxObjectives> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfFluxObjectives> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020614
  { FbcObjectiveLOObjectivesAllowedAttributes,
    "Attributes allowed on <listOfObjectives>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <listOfObjectives> object may have the optional attributes "
    "'fbc:activeObjective' and 'fbc:activeObjective'. No other attributes from "
    "the SBML Level 3 Flux Balance Constraints namespaces are permitted on an "
    "<listOfObjectives> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020615
  { FbcLOObjectivesActiveObjectiveMustBeObjective,
    "The attribute 'activeObjective' must point to Objective object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:activeObjective' of an <listOfObjectives> "
    "object must be the identifier of an existing <objective> object defined in "
    "the enclosing <model> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020701
  { FbcFluxObjectiveAllowedCoreAttributes,
    "Core attributes allowed on <fluxObjective>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <fluxObjective> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <fluxObjective>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020702
  { FbcFluxObjectiveAllowedCoreElements,
    "Core elements allowed on <fluxObjective>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <fluxObjective> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <fluxObjective>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020703
  { FbcFluxObjectiveAllowedAttributes,
    "Attributes allowed on <fluxObjective>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <fluxObjective> object must have the required attributes 'fbc:reaction', "
    "'fbc:coefficient', 'fbc:reaction' and 'fbc:coefficient', and may have the "
    "optional attributes 'fbc:id', 'fbc:name', 'fbc:id' and 'fbc:name'. No "
    "other attributes from the SBML Level 3 Flux Balance Constraints namespaces "
    "are permitted on a <fluxObjective> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020704
  { FbcFluxObjectiveReactionMustBeReaction,
    "The attribute 'reaction' must point to Reaction object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:reaction' of a <fluxObjective> object must "
    "be the identifier of an existing <reaction> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020705
  { FbcFluxObjectiveCoefficientMustBeDouble,
    "The 'coefficient' attribute must be Double.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:coefficient' on a <fluxObjective> must have a value of "
    "data type 'double'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020708
  { FbcFluxObjectiveNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:name' on a <fluxObjective> must have a value of data "
    "type 'string'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020801
  { FbcGeneProductAllowedCoreAttributes,
    "Core attributes allowed on <geneProduct>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProduct> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <geneProduct>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020802
  { FbcGeneProductAllowedCoreElements,
    "Core elements allowed on <geneProduct>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProduct> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <geneProduct>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020803
  { FbcGeneProductAllowedAttributes,
    "Attributes allowed on <geneProduct>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProduct> object must have the required attributes 'fbc:id' and "
    "'fbc:label', and may have the optional attributes 'fbc:name' and "
    "'fbc:associatedSpecies'. No other attributes from the SBML Level 3 Flux "
    "Balance Constraints namespaces are permitted on a <geneProduct> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020804
  { FbcGeneProductLabelMustBeString,
    "The 'label' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:label' on a <geneProduct> must have a value of data "
    "type 'string'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020805
  { FbcGeneProductNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:name' on a <geneProduct> must have a value of data type "
    "'string'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020806
  { FbcGeneProductAssociatedSpeciesMustBeSpecies,
    "The attribute 'associatedSpecies' must point to Species object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:associatedSpecies' of a <geneProduct> "
    "object must be the identifier of an existing <species> object defined in "
    "the enclosing <model> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020901
  { FbcGeneProductRefAllowedCoreAttributes,
    "Core attributes allowed on <geneProductRef>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProductRef> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <geneProductRef>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020902
  { FbcGeneProductRefAllowedCoreElements,
    "Core elements allowed on <geneProductRef>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProductRef> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <geneProductRef>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020903
  { FbcGeneProductRefAllowedAttributes,
    "Attributes allowed on <geneProductRef>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProductRef> object may have the optional attributes 'fbc:id', "
    "'fbc:name' and 'fbc:geneProduct'. No other attributes from the SBML Level "
    "3 Flux Balance Constraints namespaces are permitted on a <geneProductRef> "
    "object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020904
  { FbcGeneProductRefNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:name' on a <geneProductRef> must have a value of data "
    "type 'string'.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2020905
  { FbcGeneProductRefGeneProductMustBeGeneProduct,
    "The attribute 'geneProduct' must point to GeneProduct object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'fbc:geneProduct' of a <geneProductRef> object "
    "must be the identifier of an existing <geneProduct> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021001
  { FbcFbcAndAllowedCoreAttributes,
    "Core attributes allowed on <and>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <and> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <and>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021002
  { FbcFbcAndAllowedCoreElements,
    "Core elements allowed on <and>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <and> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <and>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021003
  { FbcFbcAndAllowedElements,
    "Elements allowed on <and>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <and> object may contain one and only one instance of the "
    "<listOfAssociations> element. No other elements from the SBML Level 3 Flux "
    "Balance Constraints namespaces are permitted on an <and> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021101
  { FbcFbcOrAllowedCoreAttributes,
    "Core attributes allowed on <or>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <or> object may have the optional SBML Level 3 Core attributes 'metaid' "
    "and 'sboTerm'. No other attributes from the SBML Level 3 Core namespaces "
    "are permitted on an <or>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021102
  { FbcFbcOrAllowedCoreElements,
    "Core elements allowed on <or>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <or> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <or>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021103
  { FbcFbcOrAllowedElements,
    "Elements allowed on <or>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <or> object may contain one and only one instance of the "
    "<listOfAssociations> element. No other elements from the SBML Level 3 Flux "
    "Balance Constraints namespaces are permitted on an <or> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021201
  { FbcAssociationAllowedCoreAttributes,
    "Core attributes allowed on <association>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <association> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <association>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021202
  { FbcAssociationAllowedCoreElements,
    "Core elements allowed on <association>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <association> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <association>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021301
  { FbcGeneProductAssociationAllowedCoreAttributes,
    "Core attributes allowed on <geneProductAssociation>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProductAssociation> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <geneProductAssociation>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021302
  { FbcGeneProductAssociationAllowedCoreElements,
    "Core elements allowed on <geneProductAssociation>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProductAssociation> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <geneProductAssociation>.",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021303
  { FbcGeneProductAssociationAllowedAttributes,
    "Attributes allowed on <geneProductAssociation>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProductAssociation> object may have the optional attributes "
    "'fbc:id' and 'fbc:name'. No other attributes from the SBML Level 3 Flux "
    "Balance Constraints namespaces are permitted on a <geneProductAssociation> "
    "object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021304
  { FbcGeneProductAssociationAllowedElements,
    "Elements allowed on <geneProductAssociation>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geneProductAssociation> object may contain one and only one instance of "
    "the <listOfAssociations> element. No other elements from the SBML Level 3 "
    "Flux Balance Constraints namespaces are permitted on a "
    "<geneProductAssociation> object. ",
    { "L3V1 Fbc V1 Section"
    }
  },

  // 2021305
  { FbcGeneProductAssociationNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'fbc:name' on a <geneProductAssociation> must have a value "
    "of data type 'string'.",
    { "L3V1 Fbc V1 Section"
    }
  },

};

/** @endcond */



LIBSBML_CPP_NAMESPACE_END




#endif /* !FbcSBMLErrorTable_H__ */


