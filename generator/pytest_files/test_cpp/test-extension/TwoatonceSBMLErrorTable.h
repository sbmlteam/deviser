/**
 * @file TwoatonceSBMLErrorTable.h
 * @brief Definition of the TwoatonceSBMLErrorTable class.
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


#ifndef TwoatonceSBMLErrorTable_H__
#define TwoatonceSBMLErrorTable_H__


#include <sbml/packages/twoatonce/validator/TwoatonceSBMLError.h>


LIBSBML_CPP_NAMESPACE_BEGIN



/** @cond doxygenLibsbmlInternal */

static const packageErrorTableEntry twoatonceErrorTable[] =
{
  // 2010100
  { TwoatonceUnknown,
    "Unknown error from Twoatonce",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Unknown error from Twoatonce",
    { ""
    }
  },

  // 2010101
  { TwoatonceNSUndeclared,
    "The Twoatonce namespace is not correctly declared.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "To conform to the Package testing one version with two namespaces created "
    "at once Package specification for SBML Level 3 Version 2, an SBML document "
    "must declare 'http://www.sbml.org/sbml/level3/version2/twoatonce/version1' "
    "as the XMLNamespace to use for elements of this package.",
    { "L3V1 Twoatonce V1 Section 3.1"
    }
  },

  // 2010102
  { TwoatonceElementNotInNs,
    "Element not in Twoatonce namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Package testing one version with two namespaces created at once Package "
    "must use the 'http://www.sbml.org/sbml/level3/version2/twoatonce/version1' "
    "namespace, declaring so either explicitly or implicitly.",
    { "L3V1 Twoatonce V1 Section 3.1"
    }
  },

  // 2010301
  { TwoatonceDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2010302
  { TwoatonceIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of a 'twoatonce:id' must conform to the syntax of the <sbml> "
    "data type 'SId'",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020101
  { TwoatonceAttributeRequiredMissing,
    "Required twoatonce:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the Package testing one version with two "
    "namespaces created at once Package, the <sbml> object must have the "
    "'twoatonce:required' attribute.",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020102
  { TwoatonceAttributeRequiredMustBeBoolean,
    "The twoatonce:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'twoatonce:required' on the <sbml> object must be "
    "of data type 'boolean'.",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020103
  { TwoatonceAttributeRequiredMustHaveValue,
    "The twoatonce:required attribute must be 'false'",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'twoatonce:required' on the <sbml> object must be "
    "set to 'false'.",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020201
  { TwoatonceSBaseAllowedElements,
    "Elements allowed on <sBase>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A 'SBase' object may contain one and only one instance of each of the "
    "<normalClass> and <classWithRequiredID> elements. No other elements from "
    "the SBML Level 3 Package testing one version with two namespaces created "
    "at once namespaces are permitted on a 'SBase' object. ",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020301
  { TwoatonceNormalClassAllowedCoreAttributes,
    "Core attributes allowed on <normalClass>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <normalClass> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <normalClass>.",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020302
  { TwoatonceNormalClassAllowedCoreElements,
    "Core elements allowed on <normalClass>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <normalClass> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <normalClass>.",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020303
  { TwoatonceNormalClassAllowedAttributes,
    "Attributes allowed on <normalClass>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <normalClass> object must have the required attribute "
    "'twoatonce:attribute'. No other attributes from "
    "the SBML Level 3 Package testing one version with two namespaces created "
    "at once namespaces are permitted on a <normalClass> object. ",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020304
  { TwoatonceNormalClassAttributeMustBeString,
    "The 'attribute' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'twoatonce:attribute' on a <normalClass> must have a value "
    "of data type 'string'.",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020401
  { TwoatonceClassWithRequiredIDAllowedCoreAttributes,
    "Core attributes allowed on <classWithRequiredID>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <classWithRequiredID> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <classWithRequiredID>.",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020402
  { TwoatonceClassWithRequiredIDAllowedCoreElements,
    "Core elements allowed on <classWithRequiredID>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <classWithRequiredID> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <classWithRequiredID>.",
    { "L3V1 Twoatonce V1 Section"
    }
  },

  // 2020403
  { TwoatonceClassWithRequiredIDAllowedAttributes,
    "Attributes allowed on <classWithRequiredID>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <classWithRequiredID> object must have the required attribute "
    "'twoatonce:id' or 'id' in L3V2. No other attributes from the SBML Level 3 Package testing "
    "one version with two namespaces created at once. namespaces are permitted "
    "on a <classWithRequiredID> object. ",
    { "L3V1 Twoatonce V1 Section"
    }
  },

};

/** @endcond */



LIBSBML_CPP_NAMESPACE_END




#endif /* !TwoatonceSBMLErrorTable_H__ */


