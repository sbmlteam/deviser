/**
 * @file TestSBMLErrorTable.h
 * @brief Definition of the TestSBMLErrorTable class.
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


#ifndef TestSBMLErrorTable_H__
#define TestSBMLErrorTable_H__


#include <sbml/packages/test/validator/TestSBMLError.h>


LIBSBML_CPP_NAMESPACE_BEGIN



/** @cond doxygenLibsbmlInternal */

static const packageErrorTableEntry testErrorTable[] =
{
  // 10010100
  { TestUnknown,
    "Unknown error from Test",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Unknown error from Test",
    { ""
    }
  },

  // 10010101
  { TestNSUndeclared,
    "The Test namespace is not correctly declared.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "To conform to the testAttributes Package specification for SBML Level 3 "
    "Version 1, an SBML document must declare "
    "'http://www.sbml.org/sbml/level3/version1/test/version1' as the "
    "XMLNamespace to use for elements of this package.",
    { "L3V1 Test V1 Section 3.1"
    }
  },

  // 10010102
  { TestElementNotInNs,
    "Element not in Test namespace",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "testAttributes Package must use the "
    "'http://www.sbml.org/sbml/level3/version1/test/version1' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Test V1 Section 3.1"
    }
  },

  // 10010301
  { TestDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Test V1 Section"
    }
  },

  // 10010302
  { TestIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of a 'test:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020101
  { TestAttributeRequiredMissing,
    "Required test:required attribute on <sbml>",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "In all SBML documents using the testAttributes Package, the <sbml> object "
    "must have the 'test:required' attribute.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020102
  { TestAttributeRequiredMustBeBoolean,
    "The test:required attribute must be Boolean",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'test:required' on the <sbml> object must be of "
    "data type 'boolean'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020103
  { TestAttributeRequiredMustHaveValue,
    "The test:required attribute must be 'false'",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of attribute 'test:required' on the <sbml> object must be set to "
    "'false'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020201
  { TestSpeciesAllowedAttributes,
    "Attributes allowed on <species>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <species> object may have the optional attributes 'test:charge' and "
    "'test:chemicalFormula'. No other attributes from the SBML Level 3 "
    "testAttributes namespaces are permitted on a <species> object. ",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020202
  { TestSpeciesChargeMustBeInteger,
    "Charge attribute must be Integer.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:charge' on a <species> must have a value of data type "
    "'integer'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020203
  { TestSpeciesChemicalFormulaMustBeString,
    "ChemicalFormula attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:chemicalFormula' on a <species> must have a value of "
    "data type 'string'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020301
  { TestMyTestClassAllowedCoreAttributes,
    "Core attributes allowed on <myTestClass>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <myTestClass> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <myTestClass>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020302
  { TestMyTestClassAllowedCoreElements,
    "Core elements allowed on <myTestClass>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <myTestClass> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <myTestClass>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020303
  { TestMyTestClassAllowedAttributes,
    "Attributes allowed on <myTestClass>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <myTestClass> object may have the optional attributes 'test:id', "
    "'test:name', 'test:num', 'test:numTwo', 'test:numThree', 'test:numOne', "
    "'test:true', 'test:false', 'test:unit', 'test:refOne', 'test:refTwo', "
    "'test:refUnit', 'test:correctId', 'test:idRef', 'test:idrefOne' and "
    "'test:idrefTwo'. No other attributes from the SBML Level 3 testAttributes "
    "namespaces are permitted on a <myTestClass> object. ",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020304
  { TestMyTestClassNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:name' on a <myTestClass> must have a value of data "
    "type 'string'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020305
  { TestMyTestClassNumMustBeNonNegativeInteger,
    "The 'num' attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:num' on a <myTestClass> must have a value of data type "
    "'integer', and must be non negative.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020306
  { TestMyTestClassNum2MustBeNonNegativeInteger,
    "The 'num2' attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:numTwo' on a <myTestClass> must have a value of data "
    "type 'integer', and must be non negative.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020307
  { TestMyTestClassNum3MustBeInteger,
    "The 'num3' attribute must be Integer.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:numThree' on a <myTestClass> must have a value of data "
    "type 'integer'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020308
  { TestMyTestClassNum1MustBeDouble,
    "The 'num1' attribute must be Double.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:numOne' on a <myTestClass> must have a value of data "
    "type 'double'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020309
  { TestMyTestClassTrueMustBeBoolean,
    "The 'true' attribute must be Boolean.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:true' on a <myTestClass> must have a value of data "
    "type 'boolean'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020310
  { TestMyTestClassFalseMustBeBoolean,
    "The 'false' attribute must be Boolean.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:false' on a <myTestClass> must have a value of data "
    "type 'boolean'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020311
  { TestMyTestClassUnitMustBeUnitSId,
    "The 'unit' attribute must be UnitSId.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:unit' on a <myTestClass> must have a "
    "taken from the following: the identifier of a <unitDefinition> object in "
    "the enclosing <model,> or one of the base units in SBML.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020312
  { TestMyTestClassRef1MustBeThing1,
    "The attribute 'ref1' must point to Thing1 object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:refOne' of a <myTestClass> object must be "
    "the identifier of an existing <thing1> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020313
  { TestMyTestClassRef2MustBeThing2,
    "The attribute 'ref2' must point to Thing2 object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:refTwo' of a <myTestClass> object must be "
    "the identifier of an existing <thing2> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020314
  { TestMyTestClassRefUnitMustBeUnitSId,
    "The 'refUnit' attribute must be UnitSId.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:refUnit' on a <myTestClass> must have a "
    "taken from the following: the identifier of a <unitDefinition> object in "
    "the enclosing <model,> or one of the base units in SBML.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020315
  { TestMyTestClassIdRefMustBeSBase,
    "The attribute 'idRef' must point to SBase object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:idRef' of a <myTestClass> object must be "
    "the 'metaid' of an existing 'SBase' object defined in the enclosing "
    "<model> object.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020316
  { TestMyTestClassIdref1MustBeSBase,
    "The attribute 'idref1' must point to SBase object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:idrefOne' of a <myTestClass> object must "
    "be the 'metaid' of an existing 'SBase' object defined in the enclosing "
    "<model> object.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020317
  { TestMyTestClassIdref2MustBeSBase,
    "The attribute 'idref2' must point to SBase object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:idrefTwo' of a <myTestClass> object must "
    "be the 'metaid' of an existing 'SBase' object defined in the enclosing "
    "<model> object.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020401
  { TestUnitAllowedCoreAttributes,
    "Core attributes allowed on <unit>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <unit> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <unit>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020402
  { TestUnitAllowedCoreElements,
    "Core elements allowed on <unit>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <unit> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <unit>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020403
  { TestUnitAllowedAttributes,
    "Attributes allowed on <unit>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <unit> object may have the optional attribute 'test:unit'. No other "
    "attributes from the SBML Level 3 testAttributes namespaces are permitted "
    "on an <unit> object. ",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020404
  { TestUnitUnitMustBeUnitSId,
    "The 'unit' attribute must be UnitSId.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:unit' on an <unit> must have a taken from "
    "the following: the identifier of a <unitDefinition> object in the "
    "enclosing <model,> or one of the base units in SBML.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020501
  { TestMyLoTestAllowedCoreAttributes,
    "Core attributes allowed on <myLoTest>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <myLoTest> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <myLoTest>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020502
  { TestMyLoTestAllowedCoreElements,
    "Core elements allowed on <myLoTest>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <myLoTest> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <myLoTest>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020503
  { TestMyLoTestAllowedAttributes,
    "Attributes allowed on <myLoTest>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <myLoTest> object may have the optional attribute 'test:id'. No other "
    "attributes from the SBML Level 3 testAttributes namespaces are permitted "
    "on a <myLoTest> object. ",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020601
  { TestMyRequiredClassAllowedCoreAttributes,
    "Core attributes allowed on <myRequiredClass>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <myRequiredClass> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <myRequiredClass>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020602
  { TestMyRequiredClassAllowedCoreElements,
    "Core elements allowed on <myRequiredClass>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <myRequiredClass> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <myRequiredClass>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020603
  { TestMyRequiredClassAllowedAttributes,
    "Attributes allowed on <myRequiredClass>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <myRequiredClass> object must have the required attributes 'test:id', "
    "'test:name', 'test:num', 'test:numTwo', 'test:numThree', 'test:numOne', "
    "'test:true', 'test:false', 'test:unit', 'test:refOne', 'test:refTwo', "
    "'test:refUnit', 'test:correctId', 'test:posint', 'test:posintTwo', "
    "'test:posintOne', 'test:metaidTwo', 'test:metaidOne', 'test:numFour', "
    "'test:metaidrefOne' and 'test:notmetaid', and may have the optional "
    "attributes 'test:vectorDouble', 'test:vectorDoubleOne', 'test:vectorInt', "
    "'test:vectorIntOne', 'test:arrayD' and 'test:arrayInt'. No other "
    "attributes from the SBML Level 3 testAttributes namespaces are permitted "
    "on a <myRequiredClass> object. ",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020604
  { TestMyRequiredClassNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:name' on a <myRequiredClass> must have a value of data "
    "type 'string'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020605
  { TestMyRequiredClassNumMustBeNonNegativeInteger,
    "The 'num' attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:num' on a <myRequiredClass> must have a value of data "
    "type 'integer', and must be non negative.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020606
  { TestMyRequiredClassNum2MustBeNonNegativeInteger,
    "The 'num2' attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:numTwo' on a <myRequiredClass> must have a value of "
    "data type 'integer', and must be non negative.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020607
  { TestMyRequiredClassNum3MustBeInteger,
    "The 'num3' attribute must be Integer.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:numThree' on a <myRequiredClass> must have a value of "
    "data type 'integer'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020608
  { TestMyRequiredClassNum1MustBeDouble,
    "The 'num1' attribute must be Double.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:numOne' on a <myRequiredClass> must have a value of "
    "data type 'double'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020609
  { TestMyRequiredClassTrueMustBeBoolean,
    "The 'true' attribute must be Boolean.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:true' on a <myRequiredClass> must have a value of data "
    "type 'boolean'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020610
  { TestMyRequiredClassFalseMustBeBoolean,
    "The 'false' attribute must be Boolean.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:false' on a <myRequiredClass> must have a value of "
    "data type 'boolean'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020611
  { TestMyRequiredClassUnitMustBeUnitSId,
    "The 'unit' attribute must be UnitSId.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:unit' on a <myRequiredClass> must have a "
    "taken from the following: the identifier of a <unitDefinition> object in "
    "the enclosing <model,> or one of the base units in SBML.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020612
  { TestMyRequiredClassRef1MustBeThing1,
    "The attribute 'ref1' must point to Thing1 object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:refOne' of a <myRequiredClass> object "
    "must be the identifier of an existing <thing1> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020613
  { TestMyRequiredClassRef2MustBeThing2,
    "The attribute 'ref2' must point to Thing2 object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:refTwo' of a <myRequiredClass> object "
    "must be the identifier of an existing <thing2> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020614
  { TestMyRequiredClassRefUnitMustBeUnitSId,
    "The 'refUnit' attribute must be UnitSId.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:refUnit' on a <myRequiredClass> must have "
    "a taken from the following: the identifier of a <unitDefinition> object in "
    "the enclosing <model,> or one of the base units in SBML.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020615
  { TestMyRequiredClassPosintMustBeNonNegativeInteger,
    "The 'posint' attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:posint' on a <myRequiredClass> must have a value of "
    "data type 'integer', and must be non negative.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020616
  { TestMyRequiredClassPosint2MustBeNonNegativeInteger,
    "The 'posint2' attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:posintTwo' on a <myRequiredClass> must have a value of "
    "data type 'integer', and must be non negative.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020617
  { TestMyRequiredClassPosint1MustBeNonNegativeInteger,
    "The 'posint1' attribute must be NonNegativeInteger.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:posintOne' on a <myRequiredClass> must have a value of "
    "data type 'integer', and must be non negative.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020618
  { TestMyRequiredClassMetaid2MustBeString,
    "The 'metaid2' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:metaidTwo' on a <myRequiredClass> must have a value of "
    "XML data type 'ID'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020619
  { TestMyRequiredClassMetaid1MustBeString,
    "The 'metaid1' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:metaidOne' on a <myRequiredClass> must have a value of "
    "XML data type 'ID'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020620
  { TestMyRequiredClassNum4MustBeInteger,
    "The 'num4' attribute must be Integer.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:numFour' on a <myRequiredClass> must have a value of "
    "data type 'integer'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020621
  { TestMyRequiredClassMetaidref1MustBeSBase,
    "The attribute 'metaidref1' must point to SBase object.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:metaidrefOne' of a <myRequiredClass> "
    "object must be the 'metaid' of an existing 'SBase' object defined in the "
    "enclosing <model> object.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020622
  { TestMyRequiredClassNotmetaidMustBeString,
    "The 'notmetaid' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The attribute 'test:notmetaid' on a <myRequiredClass> must have a value of "
    "XML data type 'ID'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020623
  { TestMyRequiredClassVectorDoubleMustBeString,
    "The 'vectorDouble' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:vectorDouble' of a <myRequiredClass> "
    "object must be an vector of values of type 'double'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020624
  { TestMyRequiredClassVectorDouble1MustBeString,
    "The 'vectorDouble1' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:vectorDoubleOne' of a <myRequiredClass> "
    "object must be an vector of values of type 'double'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020625
  { TestMyRequiredClassVectorIntMustBeString,
    "The 'vectorInt' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:vectorInt' of a <myRequiredClass> object "
    "must be an vector of values of type 'int'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020626
  { TestMyRequiredClassVectorInt1MustBeString,
    "The 'vectorInt1' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:vectorIntOne' of a <myRequiredClass> "
    "object must be an vector of values of type 'integer'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020627
  { TestMyRequiredClassArrayDMustBeString,
    "The 'arrayD' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:arrayD' of a <myRequiredClass> object "
    "must be an array of values of type 'double'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020628
  { TestMyRequiredClassArrayIntMustBeString,
    "The 'arrayInt' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:arrayInt' of a <myRequiredClass> object "
    "must be an array of values of type 'integer'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020701
  { TestArrayChildAllowedCoreAttributes,
    "Core attributes allowed on <arrayChild>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <arrayChild> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <arrayChild>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020702
  { TestArrayChildAllowedCoreElements,
    "Core elements allowed on <arrayChild>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <arrayChild> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <arrayChild>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020703
  { TestArrayChildAllowedAttributes,
    "Attributes allowed on <arrayChild>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <arrayChild> object may have the optional attribute 'test:number'. No "
    "other attributes from the SBML Level 3 testAttributes namespaces are "
    "permitted on an <arrayChild> object. ",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020704
  { TestArrayChildAllowedElements,
    "Elements allowed on <arrayChild>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <arrayChild> object may contain one and only one instance of the Unit "
    "element. No other elements from the SBML Level 3 testAttributes namespaces "
    "are permitted on an <arrayChild> object. ",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020705
  { TestArrayChildNumberMustBeString,
    "The 'number' attribute must be String.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "The value of the attribute 'test:number' of an <arrayChild> object must be "
    "an array of values of type 'double'.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020801
  { TestContainerAllowedCoreAttributes,
    "Core attributes allowed on <container>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <container> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <container>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020802
  { TestContainerAllowedCoreElements,
    "Core elements allowed on <container>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <container> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <container>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020803
  { TestContainerAllowedElements,
    "Elements allowed on <container>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <container> object may contain one and only one instance of the "
    "<listOfMyLoTests> element. No other elements from the SBML Level 3 "
    "testAttributes namespaces are permitted on a <container> object. ",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020804
  { TestContainerLOMyLoTestsAllowedCoreElements,
    "Core elements allowed on <listOfMyLoTests>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfMyLoTests> container object may only contain "
    "<myLoTest> objects.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020805
  { TestContainerLOMyLoTestsAllowedCoreAttributes,
    "Core attributes allowed on <listOfMyLoTests>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfMyLoTests> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <listOfMyLoTests> object.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020806
  { TestContainerLOMyLoTestsAllowedAttributes,
    "Attributes allowed on <listOfMyLoTests>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <listOfMyLoTests> object may have the optional attribute 'test:id'. No "
    "other attributes from the SBML Level 3 testAttributes namespaces are "
    "permitted on a <listOfMyLoTests> object. ",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020901
  { TestUnit1AllowedCoreAttributes,
    "Core attributes allowed on <unit1>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <unit1> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <unit1>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10020902
  { TestUnit1AllowedCoreElements,
    "Core elements allowed on <unit1>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "An <unit1> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <unit1>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10021001
  { TestThing1AllowedCoreAttributes,
    "Core attributes allowed on <thing1>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thing1> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <thing1>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10021002
  { TestThing1AllowedCoreElements,
    "Core elements allowed on <thing1>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thing1> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <thing1>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10021101
  { TestThing2AllowedCoreAttributes,
    "Core attributes allowed on <thing2>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thing2> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <thing2>.",
    { "L3V1 Test V1 Section"
    }
  },

  // 10021102
  { TestThing2AllowedCoreElements,
    "Core elements allowed on <thing2>.",
    LIBSBML_CAT_GENERAL_CONSISTENCY,
    LIBSBML_SEV_ERROR,
    "A <thing2> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <thing2>.",
    { "L3V1 Test V1 Section"
    }
  },

};

/** @endcond */



LIBSBML_CPP_NAMESPACE_END




#endif /* !TestSBMLErrorTable_H__ */


