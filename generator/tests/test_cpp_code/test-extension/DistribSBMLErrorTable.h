/**
 * @file DistribSBMLErrorTable.h
 * @brief Definition of the DistribSBMLErrorTable class.
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


#ifndef DistribSBMLErrorTable_H__
#define DistribSBMLErrorTable_H__


#include <sbml/packages/distrib/validator/DistribSBMLError.h>


LIBSBML_CPP_NAMESPACE_BEGIN



/** @cond doxygenLibsbmlInternal */

static const packageErrorTableEntry distribErrorTable[] =
{
  // 1510100
  { DistribUnknown,
    "Unknown error from Distrib",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Unknown error from Distrib",
    { ""
    }
  },

  // 1510101
  { DistribNSUndeclared,
    "The Distrib namespace is not correctly declared.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "To conform to the Distributions Package specification for SBML Level 3 "
    "Version 2, an SBML document must declare "
    "'http://www.sbml.org/sbml/level3/version2/distrib/version1' as the "
    "XMLNamespace to use for elements of this package.",
    { "L3V1 Distrib V1 Section 3.1"
    }
  },

  // 1510102
  { DistribElementNotInNs,
    "Element not in Distrib namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Distributions Package must use the "
    "'http://www.sbml.org/sbml/level3/version2/distrib/version1' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Distrib V1 Section 3.1"
    }
  },

  // 1510301
  { DistribDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1510302
  { DistribIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of a 'distrib:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520101
  { DistribAttributeRequiredMissing,
    "Required distrib:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the Distributions Package, the <sbml> object "
    "must have the 'distrib:required' attribute.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520102
  { DistribAttributeRequiredMustBeBoolean,
    "The distrib:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'distrib:required' on the <sbml> object must be of "
    "data type 'boolean'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520103
  { DistribAttributeRequiredMustHaveValue,
    "The distrib:required attribute must be 'true'",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'distrib:required' on the <sbml> object must be set "
    "to 'true'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520201
  { DistribFunctionDefinitionAllowedElements,
    "Elements allowed on <functionDefinition>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <functionDefinition> object may contain one and only one instance of the "
    "<drawFromDistribution> element. No other elements from the SBML Level 3 "
    "Distributions namespaces are permitted on a <functionDefinition> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520401
  { DistribDrawFromDistributionAllowedCoreAttributes,
    "Core attributes allowed on <drawFromDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <drawFromDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <drawFromDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520402
  { DistribDrawFromDistributionAllowedCoreElements,
    "Core elements allowed on <drawFromDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <drawFromDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <drawFromDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520403
  { DistribDrawFromDistributionAllowedElements,
    "Elements allowed on <drawFromDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <drawFromDistribution> object may contain one and only one instance of "
    "each of the <listOfDistribInputs> and Distribution elements. No other "
    "elements from the SBML Level 3 Distributions namespaces are permitted on a "
    "<drawFromDistribution> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520404
  { DistribDrawFromDistributionLODistribInputsAllowedCoreElements,
    "Core elements allowed on <listOfDistribInputs>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfDistribInputs> container object may only contain "
    "<distribInput> objects.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520405
  { DistribDrawFromDistributionLODistribInputsAllowedCoreAttributes,
    "Core attributes allowed on <listOfDistribInputs>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfDistribInputs> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfDistribInputs> object.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520501
  { DistribDistribInputAllowedCoreAttributes,
    "Core attributes allowed on <distribInput>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <distribInput> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <distribInput>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520502
  { DistribDistribInputAllowedCoreElements,
    "Core elements allowed on <distribInput>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <distribInput> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <distribInput>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520503
  { DistribDistribInputAllowedAttributes,
    "Attributes allowed on <distribInput>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <distribInput> object may have the optional attributes 'distrib:id', "
    "'distrib:name' and 'distrib:index'. No other attributes from the SBML "
    "Level 3 Distributions namespaces are permitted on a <distribInput> object. "
    "",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520504
  { DistribDistribInputNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:name' on a <distribInput> must have a value of data "
    "type 'string'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520505
  { DistribDistribInputIndexMustBeNonNegativeInteger,
    "The 'index' attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:index' on a <distribInput> must have a value of "
    "data type 'integer', and must be non negative.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520601
  { DistribDistributionAllowedCoreAttributes,
    "Core attributes allowed on <distribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <distribution> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <distribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520602
  { DistribDistributionAllowedCoreElements,
    "Core elements allowed on <distribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <distribution> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <distribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520701
  { DistribUnivariateDistributionAllowedCoreAttributes,
    "Core attributes allowed on <univariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <univariateDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <univariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520702
  { DistribUnivariateDistributionAllowedCoreElements,
    "Core elements allowed on <univariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <univariateDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <univariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520801
  { DistribMultivariateDistributionAllowedCoreAttributes,
    "Core attributes allowed on <multivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <multivariateDistribution> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <multivariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520802
  { DistribMultivariateDistributionAllowedCoreElements,
    "Core elements allowed on <multivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <multivariateDistribution> object may have the optional SBML Level 3 "
    "Core subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <multivariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520901
  { DistribContinuousUnivariateDistributionAllowedCoreAttributes,
    "Core attributes allowed on <continuousUnivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <continuousUnivariateDistribution> object may have the optional SBML "
    "Level 3 Core attributes 'metaid' and 'sboTerm'. No other attributes from "
    "the SBML Level 3 Core namespaces are permitted on a "
    "<continuousUnivariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520902
  { DistribContinuousUnivariateDistributionAllowedCoreElements,
    "Core elements allowed on <continuousUnivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <continuousUnivariateDistribution> object may have the optional SBML "
    "Level 3 Core subobjects for notes and annotations. No other elements from "
    "the SBML Level 3 Core namespaces are permitted on a "
    "<continuousUnivariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1520903
  { DistribContinuousUnivariateDistributionAllowedElements,
    "Elements allowed on <continuousUnivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <continuousUnivariateDistribution> object may contain one and only one "
    "instance of each of the UncertBound and UncertBound elements. No other "
    "elements from the SBML Level 3 Distributions namespaces are permitted on a "
    "<continuousUnivariateDistribution> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521001
  { DistribDiscreteUnivariateDistributionAllowedCoreAttributes,
    "Core attributes allowed on <discreteUnivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <discreteUnivariateDistribution> object may have the optional SBML Level "
    "3 Core attributes 'metaid' and 'sboTerm'. No other attributes from the "
    "SBML Level 3 Core namespaces are permitted on a "
    "<discreteUnivariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521002
  { DistribDiscreteUnivariateDistributionAllowedCoreElements,
    "Core elements allowed on <discreteUnivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <discreteUnivariateDistribution> object may have the optional SBML Level "
    "3 Core subobjects for notes and annotations. No other elements from the "
    "SBML Level 3 Core namespaces are permitted on a "
    "<discreteUnivariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521003
  { DistribDiscreteUnivariateDistributionAllowedElements,
    "Elements allowed on <discreteUnivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <discreteUnivariateDistribution> object may contain one and only one "
    "instance of each of the UncertBound and UncertBound elements. No other "
    "elements from the SBML Level 3 Distributions namespaces are permitted on a "
    "<discreteUnivariateDistribution> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521101
  { DistribCategoricalUnivariateDistributionAllowedCoreAttributes,
    "Core attributes allowed on <categoricalUnivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <categoricalUnivariateDistribution> object may have the optional SBML "
    "Level 3 Core attributes 'metaid' and 'sboTerm'. No other attributes from "
    "the SBML Level 3 Core namespaces are permitted on a "
    "<categoricalUnivariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521102
  { DistribCategoricalUnivariateDistributionAllowedCoreElements,
    "Core elements allowed on <categoricalUnivariateDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <categoricalUnivariateDistribution> object may have the optional SBML "
    "Level 3 Core subobjects for notes and annotations. No other elements from "
    "the SBML Level 3 Core namespaces are permitted on a "
    "<categoricalUnivariateDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521201
  { DistribUncertValueAllowedCoreAttributes,
    "Core attributes allowed on <uncertValue>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertValue> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <uncertValue>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521202
  { DistribUncertValueAllowedCoreElements,
    "Core elements allowed on <uncertValue>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertValue> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <uncertValue>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521203
  { DistribUncertValueAllowedAttributes,
    "Attributes allowed on <uncertValue>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertValue> object may have the optional attributes 'distrib:value', "
    "'distrib:var' and 'distrib:units'. No other attributes from the SBML Level "
    "3 Distributions namespaces are permitted on an <uncertValue> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521204
  { DistribUncertValueValueMustBeDouble,
    "The 'value' attribute must be Double.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:value' on an <uncertValue> must have a value of "
    "data type 'double'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521205
  { DistribUncertValueVarMustBeSBase,
    "The attribute 'var' must point to SBase object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'distrib:var' of an <uncertValue> object must "
    "be the identifier of an existing object derived from the 'SBase' class and "
    "defined in the enclosing <model> object.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521206
  { DistribUncertValueUnitsMustBeUnitSId,
    "The 'units' attribute must be UnitSId.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'distrib:units' on an <uncertValue> must have a "
    "taken from the following: the identifier of a <unitDefinition> object in "
    "the enclosing <model,> or one of the base units in SBML.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521301
  { DistribUncertBoundAllowedCoreAttributes,
    "Core attributes allowed on <uncertBound>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertBound> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <uncertBound>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521302
  { DistribUncertBoundAllowedCoreElements,
    "Core elements allowed on <uncertBound>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertBound> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <uncertBound>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521303
  { DistribUncertBoundAllowedAttributes,
    "Attributes allowed on <uncertBound>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertBound> object must have the required attribute "
    "'distrib:inclusive'. No other attributes from the SBML Level 3 "
    "Distributions namespaces are permitted on an <uncertBound> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521304
  { DistribUncertBoundInclusiveMustBeBoolean,
    "The 'inclusive' attribute must be Boolean.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:inclusive' on an <uncertBound> must have a value of "
    "data type 'boolean'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521401
  { DistribExternalDistributionAllowedCoreAttributes,
    "Core attributes allowed on <externalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <externalDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <externalDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521402
  { DistribExternalDistributionAllowedCoreElements,
    "Core elements allowed on <externalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <externalDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <externalDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521403
  { DistribExternalDistributionAllowedAttributes,
    "Attributes allowed on <externalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <externalDistribution> object must have the required attribute "
    "'distrib:definitionURL'. No other attributes from the SBML Level 3 "
    "Distributions namespaces are permitted on an <externalDistribution> "
    "object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521404
  { DistribExternalDistributionAllowedElements,
    "Elements allowed on <externalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <externalDistribution> object may contain one and only one instance of "
    "the <listOfExternalParameters> element. No other elements from the SBML "
    "Level 3 Distributions namespaces are permitted on an "
    "<externalDistribution> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521405
  { DistribExternalDistributionDefinitionURLMustBeString,
    "The 'definitionURL' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:definitionURL' on an <externalDistribution> must "
    "have a value of data type 'string'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521406
  { DistribExternalDistributionLOExternalParametersAllowedCoreElements,
    "Core elements allowed on <listOfExternalParameters>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfExternalParameters> container object may only "
    "contain <externalParameter> objects.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521407
  { DistribExternalDistributionLOExternalParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfExternalParameters>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfExternalParameters> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfExternalParameters> "
    "object.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521501
  { DistribExternalParameterAllowedCoreAttributes,
    "Core attributes allowed on <externalParameter>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <externalParameter> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <externalParameter>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521502
  { DistribExternalParameterAllowedCoreElements,
    "Core elements allowed on <externalParameter>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <externalParameter> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <externalParameter>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521503
  { DistribExternalParameterAllowedAttributes,
    "Attributes allowed on <externalParameter>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <externalParameter> object must have the required attribute "
    "'distrib:definitionURL'. No other attributes from the SBML Level 3 "
    "Distributions namespaces are permitted on an <externalParameter> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521504
  { DistribExternalParameterAllowedElements,
    "Elements allowed on <externalParameter>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <externalParameter> object may contain one and only one instance of the "
    "<listOfExternalParameters> element. No other elements from the SBML Level "
    "3 Distributions namespaces are permitted on an <externalParameter> object. "
    "",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521505
  { DistribExternalParameterDefinitionURLMustBeString,
    "The 'definitionURL' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:definitionURL' on an <externalParameter> must have "
    "a value of data type 'string'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521506
  { DistribExternalParameterLOExternalParametersAllowedCoreElements,
    "Core elements allowed on <listOfExternalParameters>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfExternalParameters> container object may only "
    "contain <externalParameter> objects.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521507
  { DistribExternalParameterLOExternalParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfExternalParameters>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfExternalParameters> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfExternalParameters> "
    "object.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521601
  { DistribNormalDistributionAllowedCoreAttributes,
    "Core attributes allowed on <normalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <normalDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <normalDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521602
  { DistribNormalDistributionAllowedCoreElements,
    "Core elements allowed on <normalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <normalDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <normalDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521603
  { DistribNormalDistributionAllowedElements,
    "Elements allowed on <normalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <normalDistribution> object must contain one and only one instance of "
    "the UncertValue element, and may contain one and only one instance of each "
    "of the UncertValue and UncertValue elements. No other elements from the "
    "SBML Level 3 Distributions namespaces are permitted on a "
    "<normalDistribution> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521701
  { DistribCategoricalDistributionAllowedCoreAttributes,
    "Core attributes allowed on <categoricalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <categoricalDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <categoricalDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521702
  { DistribCategoricalDistributionAllowedCoreElements,
    "Core elements allowed on <categoricalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <categoricalDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <categoricalDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521703
  { DistribCategoricalDistributionAllowedElements,
    "Elements allowed on <categoricalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <categoricalDistribution> object must contain one and only one instance "
    "of the <listOfCategories> element. No other elements from the SBML Level 3 "
    "Distributions namespaces are permitted on a <categoricalDistribution> "
    "object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521704
  { DistribCategoricalDistributionEmptyReqdLOElements,
    "No Empty ListOf elements allowed on <categoricalDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfCategories> subobject on a <categoricalDistribution> object "
    "must not be empty.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521705
  { DistribCategoricalDistributionLOCategoriesAllowedCoreElements,
    "Core elements allowed on <listOfCategories>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfCategories> container object may only contain "
    "<category> objects.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521706
  { DistribCategoricalDistributionLOCategoriesAllowedCoreAttributes,
    "Core attributes allowed on <listOfCategories>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfCategories> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfCategories> object.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521801
  { DistribCategoryAllowedCoreAttributes,
    "Core attributes allowed on <category>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <category> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <category>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521802
  { DistribCategoryAllowedCoreElements,
    "Core elements allowed on <category>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <category> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <category>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521803
  { DistribCategoryAllowedAttributes,
    "Attributes allowed on <category>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <category> object may have the optional attribute 'distrib:rank'. No "
    "other attributes from the SBML Level 3 Distributions namespaces are "
    "permitted on a <category> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521804
  { DistribCategoryAllowedElements,
    "Elements allowed on <category>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <category> object must contain one and only one instance of the "
    "UncertValue element, and may contain one and only one instance of the "
    "UncertValue element. No other elements from the SBML Level 3 Distributions "
    "namespaces are permitted on a <category> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521805
  { DistribCategoryRankMustBeNonNegativeInteger,
    "The 'rank' attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:rank' on a <category> must have a value of data "
    "type 'integer', and must be non negative.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521901
  { DistribBernoulliDistributionAllowedCoreAttributes,
    "Core attributes allowed on <bernoulliDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <bernoulliDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <bernoulliDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521902
  { DistribBernoulliDistributionAllowedCoreElements,
    "Core elements allowed on <bernoulliDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <bernoulliDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <bernoulliDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1521903
  { DistribBernoulliDistributionAllowedElements,
    "Elements allowed on <bernoulliDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <bernoulliDistribution> object must contain one and only one instance of "
    "the UncertValue element. No other elements from the SBML Level 3 "
    "Distributions namespaces are permitted on a <bernoulliDistribution> "
    "object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522001
  { DistribBetaDistributionAllowedCoreAttributes,
    "Core attributes allowed on <betaDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <betaDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <betaDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522002
  { DistribBetaDistributionAllowedCoreElements,
    "Core elements allowed on <betaDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <betaDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <betaDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522003
  { DistribBetaDistributionAllowedElements,
    "Elements allowed on <betaDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <betaDistribution> object must contain one and only one instance of each "
    "of the UncertValue and <uncertValue> elements. No other elements from the "
    "SBML Level 3 Distributions namespaces are permitted on a "
    "<betaDistribution> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522101
  { DistribBinomialDistributionAllowedCoreAttributes,
    "Core attributes allowed on <binomialDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <binomialDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <binomialDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522102
  { DistribBinomialDistributionAllowedCoreElements,
    "Core elements allowed on <binomialDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <binomialDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <binomialDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522103
  { DistribBinomialDistributionAllowedElements,
    "Elements allowed on <binomialDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <binomialDistribution> object must contain one and only one instance of "
    "each of the UncertValue and <uncertValue> elements. No other elements from "
    "the SBML Level 3 Distributions namespaces are permitted on a "
    "<binomialDistribution> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522201
  { DistribCauchyDistributionAllowedCoreAttributes,
    "Core attributes allowed on <cauchyDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <cauchyDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <cauchyDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522202
  { DistribCauchyDistributionAllowedCoreElements,
    "Core elements allowed on <cauchyDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <cauchyDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <cauchyDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522203
  { DistribCauchyDistributionAllowedElements,
    "Elements allowed on <cauchyDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <cauchyDistribution> object must contain one and only one instance of "
    "each of the UncertValue and <uncertValue> elements. No other elements from "
    "the SBML Level 3 Distributions namespaces are permitted on a "
    "<cauchyDistribution> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522301
  { DistribGeometricDistributionAllowedCoreAttributes,
    "Core attributes allowed on <geometricDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geometricDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <geometricDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522302
  { DistribGeometricDistributionAllowedCoreElements,
    "Core elements allowed on <geometricDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geometricDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <geometricDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522303
  { DistribGeometricDistributionAllowedElements,
    "Elements allowed on <geometricDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <geometricDistribution> object must contain one and only one instance of "
    "the UncertValue element. No other elements from the SBML Level 3 "
    "Distributions namespaces are permitted on a <geometricDistribution> "
    "object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522401
  { DistribLogisticDistributionAllowedCoreAttributes,
    "Core attributes allowed on <logisticDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <logisticDistribution> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <logisticDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522402
  { DistribLogisticDistributionAllowedCoreElements,
    "Core elements allowed on <logisticDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <logisticDistribution> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <logisticDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522403
  { DistribLogisticDistributionAllowedElements,
    "Elements allowed on <logisticDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <logisticDistribution> object must contain one and only one instance of "
    "each of the UncertValue and <uncertValue> elements. No other elements from "
    "the SBML Level 3 Distributions namespaces are permitted on a "
    "<logisticDistribution> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522501
  { DistribUncertaintyAllowedCoreAttributes,
    "Core attributes allowed on <uncertainty>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertainty> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <uncertainty>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522502
  { DistribUncertaintyAllowedCoreElements,
    "Core elements allowed on <uncertainty>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertainty> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <uncertainty>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522503
  { DistribUncertaintyAllowedElements,
    "Elements allowed on <uncertainty>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertainty> object may contain one and only one instance of each of "
    "the UncertStatistics and Distribution elements. No other elements from the "
    "SBML Level 3 Distributions namespaces are permitted on an <uncertainty> "
    "object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522601
  { DistribUncertStatisticsAllowedCoreAttributes,
    "Core attributes allowed on <uncertStatistics>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertStatistics> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on an <uncertStatistics>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522602
  { DistribUncertStatisticsAllowedCoreElements,
    "Core elements allowed on <uncertStatistics>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertStatistics> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <uncertStatistics>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522603
  { DistribUncertStatisticsAllowedElements,
    "Elements allowed on <uncertStatistics>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertStatistics> object may contain one and only one instance of each "
    "of the UncertValue and <listOfExternalParameters> elements. No other "
    "elements from the SBML Level 3 Distributions namespaces are permitted on "
    "an <uncertStatistics> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522604
  { DistribUncertStatisticsLOExternalParametersAllowedCoreElements,
    "Core elements allowed on <listOfExternalParameters>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfExternalParameters> container object may only "
    "contain <externalParameter> objects.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522605
  { DistribUncertStatisticsLOExternalParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfExternalParameters>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfExternalParameters> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on a <listOfExternalParameters> "
    "object.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522701
  { DistribExponentialDistributionAllowedCoreAttributes,
    "Core attributes allowed on <exponentialDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <exponentialDistribution> object may have the optional SBML Level 3 "
    "Core attributes 'metaid' and 'sboTerm'. No other attributes from the SBML "
    "Level 3 Core namespaces are permitted on an <exponentialDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522702
  { DistribExponentialDistributionAllowedCoreElements,
    "Core elements allowed on <exponentialDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <exponentialDistribution> object may have the optional SBML Level 3 "
    "Core subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on an <exponentialDistribution>.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 1522703
  { DistribExponentialDistributionAllowedElements,
    "Elements allowed on <exponentialDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <exponentialDistribution> object must contain one and only one instance "
    "of the UncertValue element. No other elements from the SBML Level 3 "
    "Distributions namespaces are permitted on an <exponentialDistribution> "
    "object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

};

/** @endcond */



LIBSBML_CPP_NAMESPACE_END




#endif /* !DistribSBMLErrorTable_H__ */


