/**
 * @file RefsSBMLErrorTable.h
 * @brief Definition of the RefsSBMLErrorTable class.
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


#ifndef RefsSBMLErrorTable_H__
#define RefsSBMLErrorTable_H__


#include <sbml/packages/refs/validator/RefsSBMLError.h>


LIBSBML_CPP_NAMESPACE_BEGIN



/** @cond doxygenLibsbmlInternal */

static const packageErrorTableEntry refsErrorTable[] =
{
  // 110100
  { RefsUnknown,
    "Unknown error from Refs",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Unknown error from Refs",
    { ""
    }
  },

  // 110101
  { RefsNSUndeclared,
    "The Refs namespace is not correctly declared.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "To conform to the SID References Package specification for SBML Level~3 "
    "Version~1, an SBML document must declare "
    "'http://www.sbml.org/sbml/level3/version1/refs/version1' as the "
    "XMLNamespaceto use for elements of this package.",
    { "L3V1 Refs V1 Section 3.1"
    }
  },

  // 110102
  { RefsElementNotInNs,
    "Element not in Refs namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "SID References Package must use the "
    "'http://www.sbml.org/sbml/level3/version1/refs/version1' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Refs V1 Section 3.1"
    }
  },

  // 110301
  { RefsDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Refs V1 Section"
    }
  },

  // 110302
  { RefsIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of a 'refs:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120101
  { RefsAttributeRequiredMissing,
    "Required refs:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the SID References Package, the <sbml> object "
    "must have the 'refs:required' attribute.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120102
  { RefsAttributeRequiredMustBeBoolean,
    "The refs:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'refs:required' on the <sbml> object must be of "
    "data type 'boolean'.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120103
  { RefsAttributeRequiredMustHaveValue,
    "The refs:required attribute must be 'false'",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'refs:required' on the <sbml> object must be set to "
    "'false'.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120201
  { RefsModelAllowedElements,
    "Elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <model> object may contain one and only one instance of each of the "
    "<thingA,> <thingB> and <listOfThingCs> elements. No other elements from "
    "the SBML Level 3 SID References namespaces are permitted on a <model> "
    "object. ",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120202
  { RefsModelEmptyLOElements,
    "No Empty ListOf elements allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfThingCs> subobject on a <model> object is optional, but if "
    "present, this container object must not be empty.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120203
  { RefsModelLOThingCsAllowedCoreElements,
    "Core elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfThingCs> container object may only contain <thingC> "
    "objects.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120204
  { RefsModelLOThingCsAllowedCoreAttributes,
    "Core attributes allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfThingCs> object may have the optional SBML Level~3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfThingCs> object.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120301
  { RefsThingAAllowedCoreAttributes,
    "Core attributes allowed on <thingA>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thingA> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <thingA>.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120302
  { RefsThingAAllowedCoreElements,
    "Core elements allowed on <thingA>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thingA> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <thingA>.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120303
  { RefsThingAAllowedAttributes,
    "Attributes allowed on <thingA>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thingA> object must have the required attribute 'refs:id'. No other "
    "attributes from the SBML Level 3 SID References namespaces are permitted "
    "on a <thingA> object. ",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120401
  { RefsThingBAllowedCoreAttributes,
    "Core attributes allowed on <thingB>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thingB> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <thingB>.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120402
  { RefsThingBAllowedCoreElements,
    "Core elements allowed on <thingB>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thingB> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <thingB>.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120403
  { RefsThingBAllowedAttributes,
    "Attributes allowed on <thingB>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thingB> object must have the required attribute 'refs:id'. No other "
    "attributes from the SBML Level 3 SID References namespaces are permitted "
    "on a <thingB> object. ",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120501
  { RefsThingCAllowedCoreAttributes,
    "Core attributes allowed on <thingC>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thingC> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <thingC>.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120502
  { RefsThingCAllowedCoreElements,
    "Core elements allowed on <thingC>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thingC> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <thingC>.",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120503
  { RefsThingCAllowedAttributes,
    "Attributes allowed on <thingC>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thingC> object must have the required attributes 'refs:thing' and "
    "'refs:id'. No other attributes from the SBML Level 3 SID References "
    "namespaces are permitted on a <thingC> object. ",
    { "L3V1 Refs V1 Section"
    }
  },

  // 120504
  { RefsThingCThingMustBeThingAOrThingB,
    "Attributes allowed on <thingC>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'refs:thing' of a <thingC> object must be the "
    "identifier of an existing <thingA> or <thingB> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Refs V1 Section"
    }
  },

};

/** @endcond */



LIBSBML_CPP_NAMESPACE_END




#endif /* !RefsSBMLErrorTable_H__ */


