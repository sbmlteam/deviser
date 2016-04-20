/**
 * @file SedErrorTable.h
 * @brief Definition of the SedErrorTable class.
 * @author DEVISER
 */


#ifndef SedErrorTable_H__
#define SedErrorTable_H__


#include <sedml/SedError.h>

typedef struct {
  const char * ref_l1v1;
} referenceEntry;


typedef struct {
  unsigned int code;
  const char * shortMessage;
  unsigned int category;
  unsigned int l1v1_severity;
  const char * message;
  referenceEntry reference;
} sedmlErrorTableEntry;



LIBSEDML_CPP_NAMESPACE_BEGIN



/** @cond doxygenLibSEDMLInternal */

static const sedmlErrorTableEntry sedmlErrorTable[] =
{
  // 110100
  { SedmlUnknown,
    "Unknown error from Sedml",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Unknown error from Sedml",
    { ""
    }
  },

  // 110101
  { SedmlNSUndeclared,
    "The Sedml namespace is not correctly declared.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "To conform to the SEDML Package specification for SBML Level~1 Version~1, "
    "an SBML document must declare "
    "'http://www.sbml.org/sbml/level1/version1/sedml/version1' as the "
    "XMLNamespaceto use for elements of this package.",
    { "L3V1 Sedml V1 Section 3.1"
    }
  },

  // 110102
  { SedmlElementNotInNs,
    "Element not in Sedml namespace",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "SEDML Package must use the "
    "'http://www.sbml.org/sbml/level1/version1/sedml/version1' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Sedml V1 Section 3.1"
    }
  },

  // 110301
  { SedmlDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 110302
  { SedmlIdSyntaxRule,
    "Invalid SId syntax",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of a 'sedml:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120101
  { SedmlAttributeRequiredMissing,
    "Required sedml:required attribute on <sbml>",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "In all SBML documents using the SEDML Package, the <sbml> object must have "
    "the 'sedml:required' attribute.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120102
  { SedmlAttributeRequiredMustBeBoolean,
    "The sedml:required attribute must be Boolean",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of attribute 'sedml:required' on the <sbml> object must be of "
    "data type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120103
  { SedmlAttributeRequiredMustHaveValue,
    "The sedml:required attribute must be 'false'",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of attribute 'sedml:required' on the <sbml> object must be set "
    "to 'false'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120201
  { SedmlSedDocumentAllowedCoreAttributes,
    "Core attributes allowed on <sedDocument>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDocument> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <sedDocument>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120202
  { SedmlSedDocumentAllowedCoreElements,
    "Core elements allowed on <sedDocument>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDocument> object may have the optional SBML Level~3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <sedDocument>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120203
  { SedmlSedDocumentAllowedAttributes,
    "Attributes allowed on <sedDocument>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDocument> object must have the required attributes 'sedml:level' and "
    "'sedml:version'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <sedDocument> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120204
  { SedmlSedDocumentAllowedElements,
    "Elements allowed on <sedDocument>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDocument> object may contain one and only one instance of the "
    "<sedListOfModels> element. No other elements from the SBML Level 3 SEDML "
    "namespaces are permitted on a <sedDocument> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120205
  { SedmlSedDocumentLevelMustBeInteger,
    "Level attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:level' on a <sedDocument> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120206
  { SedmlSedDocumentVersionMustBeInteger,
    "Version attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:version' on a <sedDocument> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120207
  { SedmlSedDocumentEmptyLOElements,
    "No Empty ListOf elements allowed on <sedDocument>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The <sedListOfModels> subobject on a <sedDocument> object is optional, but "
    "if present, this container object must not be empty.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120208
  { SedmlSedDocumentLOSedModelsAllowedCoreElements,
    "Core elements allowed on <listOfSedModels>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <sedListOfModels> container object may only contain "
    "<sedModel> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120209
  { SedmlSedDocumentLOSedModelsAllowedCoreAttributes,
    "Core attributes allowed on <listOfSedModels>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedListOfModels> object may have the optional SBML Level~3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedListOfModels> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120301
  { SedmlSedModelAllowedCoreAttributes,
    "Core attributes allowed on <sedModel>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedModel> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <sedModel>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120302
  { SedmlSedModelAllowedCoreElements,
    "Core elements allowed on <sedModel>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedModel> object may have the optional SBML Level~3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <sedModel>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120303
  { SedmlSedModelAllowedAttributes,
    "Attributes allowed on <sedModel>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedModel> object must have the required attributes 'sedml:id' and "
    "'sedml:source', and may have the optional attributes 'sedml:name' and "
    "'sedml:language'. No other attributes from the SBML Level 3 SEDML "
    "namespaces are permitted on a <sedModel> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120304
  { SedmlSedModelAllowedElements,
    "Elements allowed on <sedModel>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedModel> object may contain one and only one instance of the "
    "<sedListOfChanges> element. No other elements from the SBML Level 3 SEDML "
    "namespaces are permitted on a <sedModel> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120305
  { SedmlSedModelSourceMustBeString,
    "Source attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:source' on a <sedModel> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120306
  { SedmlSedModelNameMustBeString,
    "Name attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <sedModel> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120307
  { SedmlSedModelLanguageMustBeString,
    "Language attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:language' on a <sedModel> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120308
  { SedmlSedModelEmptyLOElements,
    "No Empty ListOf elements allowed on <sedModel>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The <sedListOfChanges> subobject on a <sedModel> object is optional, but "
    "if present, this container object must not be empty.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120309
  { SedmlSedModelLOSedChangesAllowedCoreElements,
    "Core elements allowed on <listOfSedChanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <sedListOfChanges> container object may only contain "
    "<sedChange> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120310
  { SedmlSedModelLOSedChangesAllowedCoreAttributes,
    "Core attributes allowed on <listOfSedChanges>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedListOfChanges> object may have the optional SBML Level~3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedListOfChanges> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120401
  { SedmlSedChangeAllowedCoreAttributes,
    "Core attributes allowed on <sedChange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedChange> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <sedChange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120402
  { SedmlSedChangeAllowedCoreElements,
    "Core elements allowed on <sedChange>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedChange> object may have the optional SBML Level~3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <sedChange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120501
  { SedmlSedAddXMLAllowedCoreAttributes,
    "Core attributes allowed on <sedAddXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedAddXML> object may have the optional SBML Level~3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <sedAddXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120502
  { SedmlSedAddXMLAllowedCoreElements,
    "Core elements allowed on <sedAddXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedAddXML> object may have the optional SBML Level~3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <sedAddXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 120503
  { SedmlSedAddXMLAllowedElements,
    "Elements allowed on <sedAddXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedAddXML> object must contain one and only one instance of the Sed "
    "element. No other elements from the SBML Level 3 SEDML namespaces are "
    "permitted on a <sedAddXML> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

};

/** @endcond */



LIBSEDML_CPP_NAMESPACE_END




#endif /* !SedErrorTable_H__ */


