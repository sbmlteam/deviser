/**
 * @file DistribSBMLErrorTable.h
 * @brief Definition of the DistribSBMLErrorTable class.
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


#ifndef DistribSBMLErrorTable_H__
#define DistribSBMLErrorTable_H__


#include <sbml/packages/distrib/validator/DistribSBMLError.h>


LIBSBML_CPP_NAMESPACE_BEGIN



/** @cond doxygenLibsbmlInternal */

static const packageErrorTableEntry distribErrorTable[] =
{
  // 5010100
  { DistribUnknown,
    "Unknown error from Distrib",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Unknown error from Distrib",
    { ""
    }
  },

  // 5010101
  { DistribNSUndeclared,
    "The Distrib namespace is not correctly declared.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "To conform to the Distributions Package specification for SBML Level 3 "
    "Version 1, an SBML document must declare "
    "'http://www.sbml.org/sbml/level3/version1/distrib/version1' as the "
    "XMLNamespace to use for elements of this package.",
    { "L3V1 Distrib V1 Section 3.1"
    }
  },

  // 5010102
  { DistribElementNotInNs,
    "Element not in Distrib namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Distributions Package must use the "
    "'http://www.sbml.org/sbml/level3/version1/distrib/version1' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Distrib V1 Section 3.1"
    }
  },

  // 5010301
  { DistribDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5010302
  { DistribIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of a 'distrib:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020101
  { DistribAttributeRequiredMissing,
    "Required distrib:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the Distributions Package, the <sbml> object "
    "must have the 'distrib:required' attribute.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020102
  { DistribAttributeRequiredMustBeBoolean,
    "The distrib:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'distrib:required' on the <sbml> object must be of "
    "data type 'boolean'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020103
  { DistribAttributeRequiredMustHaveValue,
    "The distrib:required attribute must be 'true'",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'distrib:required' on the <sbml> object must be set "
    "to 'true'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020201
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

  // 5020301
  { DistribSBaseAllowedElements,
    "Elements allowed on <sBase>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <sBase> object may contain one and only one instance of the "
    "<uncertainty> element. No other elements from the SBML Level 3 "
    "Distributions namespaces are permitted on a <sBase> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020401
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

  // 5020402
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

  // 5020403
  { DistribDrawFromDistributionAllowedElements,
    "Elements allowed on <drawFromDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <drawFromDistribution> object must contain one and only one instance of "
    "the UncertMLNode element, and may contain one and only one instance of the "
    "<listOfDistribInputs> element. No other elements from the SBML Level 3 "
    "Distributions namespaces are permitted on a <drawFromDistribution> object. "
    "",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020404
  { DistribDrawFromDistributionEmptyLOElements,
    "No Empty ListOf elements allowed on <drawFromDistribution>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfDistribInputs> subobject on a <drawFromDistribution> object is "
    "optional, but if present, this container object must not be empty.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020405
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

  // 5020406
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

  // 5020501
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

  // 5020502
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

  // 5020503
  { DistribDistribInputAllowedAttributes,
    "Attributes allowed on <distribInput>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <distribInput> object must have the required attributes 'distrib:id' and "
    "'distrib:index', and may have the optional attribute 'distrib:name'. No "
    "other attributes from the SBML Level 3 Distributions namespaces are "
    "permitted on a <distribInput> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020504
  { DistribDistribInputIdMustBeString,
    "Id attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:id' on a <distribInput> must have a value of data "
    "type 'string'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020505
  { DistribDistribInputIndexMustBeNonNegativeInteger,
    "Index attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:index' on a <distribInput> must have a value of "
    "data type 'integer'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020506
  { DistribDistribInputNameMustBeString,
    "Name attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:name' on a <distribInput> must have a value of data "
    "type 'string'.",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020601
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

  // 5020602
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

  // 5020603
  { DistribUncertaintyAllowedAttributes,
    "Attributes allowed on <uncertainty>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertainty> object may have the optional attributes 'distrib:id' and "
    "'distrib:name'. No other attributes from the SBML Level 3 Distributions "
    "namespaces are permitted on an <uncertainty> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020604
  { DistribUncertaintyAllowedElements,
    "Elements allowed on <uncertainty>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <uncertainty> object must contain one and only one instance of the "
    "UncertMLNode element. No other elements from the SBML Level 3 "
    "Distributions namespaces are permitted on an <uncertainty> object. ",
    { "L3V1 Distrib V1 Section"
    }
  },

  // 5020605
  { DistribUncertaintyNameMustBeString,
    "Name attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'distrib:name' on an <uncertainty> must have a value of data "
    "type 'string'.",
    { "L3V1 Distrib V1 Section"
    }
  },

};

/** @endcond */



LIBSBML_CPP_NAMESPACE_END




#endif /* !DistribSBMLErrorTable_H__ */


