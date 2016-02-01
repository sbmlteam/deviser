/**
 * @file FooSBMLErrorTable.h
 * @brief Definition of the FooSBMLErrorTable class.
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


#ifndef FooSBMLErrorTable_H__
#define FooSBMLErrorTable_H__


#include <sbml/packages/foo/validator/FooSBMLError.h>


LIBSBML_CPP_NAMESPACE_BEGIN



/** @cond doxygenLibsbmlInternal */

static const packageErrorTableEntry fooErrorTable[] =
{
  // 110100
  { FooUnknown,
    "Unknown error from Foo",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Unknown error from Foo",
    { ""
    }
  },

  // 110101
  { FooNSUndeclared,
    "The Foo namespace is not correctly declared.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "To conform to the Foo Package specification for SBML Level~3 Version~1, an "
    "SBML document must declare the use of the following XML Namespace: "
    "'http://www.sbml.org/sbml/level3/version1/foo/version1'.",
    { "L3V1 Foo V1 Section 3.1"
    }
  },

  // 110102
  { FooElementNotInNs,
    "Element not in Foo namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Foo Package must be declared either implicitly or explicitly to be in the "
    "XML namespace 'http://www.sbml.org/sbml/level3/version1/foo/version1'.",
    { "L3V1 Foo V1 Section 3.1"
    }
  },

  // 110301
  { FooDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Foo V1 Section"
    }
  },

  // 110302
  { FooIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of a 'foo:id' must conform to the syntax of the <sbml> data type "
    "'SId'",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120101
  { FooAttributeRequiredMissing,
    "Required foo:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the Foo Package, the <sbml> object must have "
    "the 'foo:required' attribute.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120102
  { FooAttributeRequiredMustBeBoolean,
    "The foo:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'foo:required' on the <sbml> object must be of data "
    "type 'boolean'.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120103
  { FooAttributeRequiredMustHaveValue,
    "The foo:required attribute must be 'true'",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'foo:required' on the <sbml> object must be set to "
    "'true'.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120201
  { FooModelAllowedElements,
    "Elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <model> object may contain one and only one instance of the "
    "<listOfApples> element. No other elements from the SBML Level 3 Foo "
    "namespaces are permitted on a <model> object. ",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120202
  { FooModelLOElementChildren,
    "No children in ListOf elements allowed on <Model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfApples> subobject on a <model> object is optional, but if "
    "present, this container object must not be empty.The <listOfApples> must "
    "contain at least two instances of the <apple> object.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120203
  { FooModelLOApplesAllowedCoreElements,
    "Core elements allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a ListOfApples container object may only contain <apple> "
    "objects.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120204
  { FooModelLOApplesAllowedCoreAttributes,
    "Core attributes allowed on <model>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfApples> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfApples> object.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120301
  { FooCompartmentAllowedElements,
    "Elements allowed on <compartment>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <compartment> object may contain one and only one instance of the "
    "<listOfPears> element. No other elements from the SBML Level 3 Foo "
    "namespaces are permitted on a <compartment> object. ",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120302
  { FooCompartmentLOPearsAllowedCoreElements,
    "Core elements allowed on <compartment>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a ListOfPears container object may only contain <pear> "
    "objects.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120303
  { FooCompartmentLOPearsAllowedCoreAttributes,
    "Core attributes allowed on <compartment>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfPears> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfPears> object.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120401
  { FooSpeciesAllowedElements,
    "Elements allowed on <species>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <species> object may contain one and only one instance of the "
    "<listOfBananas> element. No other elements from the SBML Level 3 Foo "
    "namespaces are permitted on a <species> object. ",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120402
  { FooSpeciesEmptyLOElements,
    "No Empty ListOf elements allowed on <Species>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfBananas> subobject on a <species> object is optional, but if "
    "present, this container object must not be empty.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120403
  { FooSpeciesLOBananasAllowedCoreElements,
    "Core elements allowed on <species>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a ListOfBananas container object may only contain <banana> "
    "objects.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120404
  { FooSpeciesLOBananasAllowedCoreAttributes,
    "Core attributes allowed on <species>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfBananas> object may have the optional SBML Level~3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfBananas> object.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120501
  { FooAppleAllowedCoreAttributes,
    "Core attributes allowed on <apple>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <apple> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <apple>.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120502
  { FooAppleAllowedCoreElements,
    "Core elements allowed on <apple>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <apple> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <apple>.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120601
  { FooPearAllowedCoreAttributes,
    "Core attributes allowed on <pear>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <pear> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <pear>.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120602
  { FooPearAllowedCoreElements,
    "Core elements allowed on <pear>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <pear> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <pear>.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120701
  { FooBowlAllowedCoreAttributes,
    "Core attributes allowed on <bowl>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <bowl> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <bowl>.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120702
  { FooBowlAllowedCoreElements,
    "Core elements allowed on <bowl>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <bowl> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <bowl>.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120703
  { FooBowlAllowedElements,
    "Elements allowed on <bowl>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <bowl> object may contain one and only one instance of the <listOfPears> "
    "element. No other elements from the SBML Level 3 Foo namespaces are "
    "permitted on a <bowl> object. ",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120704
  { FooBowlLOPearsAllowedCoreElements,
    "Core elements allowed on <listOfPears>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfPears> container object may only contain <pear> "
    "objects.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120705
  { FooBowlLOPearsAllowedCoreAttributes,
    "Core attributes allowed on <listOfPears>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfPears> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfPears> object.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120801
  { FooPlateAllowedCoreAttributes,
    "Core attributes allowed on <plate>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <plate> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <plate>.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120802
  { FooPlateAllowedCoreElements,
    "Core elements allowed on <plate>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <plate> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <plate>.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120803
  { FooPlateAllowedElements,
    "Elements allowed on <plate>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <plate> object must contain one and only one instance of the "
    "<listOfBananas> element, and may contain one and only one instance of the "
    "<listOfApples> element. No other elements from the SBML Level 3 Foo "
    "namespaces are permitted on a <plate> object. ",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120804
  { FooPlateLOElementChildren,
    "Number of children in ListOf elements allowed on <plate>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfApples> subobject on a <plate> object is optional, but if "
    "present, this container object must not be empty.The <listOfApples> must "
    "contain at least two instances of the <apple> object.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120805
  { FooPlateLOApplesAllowedCoreElements,
    "Core elements allowed on <listOfApples>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfApples> container object may only contain <apple> "
    "objects.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120806
  { FooPlateEmptyReqdLOElements,
    "No Empty ListOf elements allowed on <plate>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The <listOfBananas> subobject on a <plate> object must not be empty.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120807
  { FooPlateLOBananasAllowedCoreElements,
    "Core elements allowed on <listOfBananas>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfBananas> container object may only contain <banana> "
    "objects.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120808
  { FooPlateLOApplesAllowedCoreAttributes,
    "Core attributes allowed on <listOfApples>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfApples> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfApples> object.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120809
  { FooPlateLOBananasAllowedCoreAttributes,
    "Core attributes allowed on <listOfBananas>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfBananas> object may have the optional SBML Level~3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfBananas> object.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120901
  { FooBananaAllowedCoreAttributes,
    "Core attributes allowed on <banana>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <banana> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <banana>.",
    { "L3V1 Foo V1 Section"
    }
  },

  // 120902
  { FooBananaAllowedCoreElements,
    "Core elements allowed on <banana>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <banana> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <banana>.",
    { "L3V1 Foo V1 Section"
    }
  },

};

/** @endcond */



LIBSBML_CPP_NAMESPACE_END




#endif /* !FooSBMLErrorTable_H__ */


