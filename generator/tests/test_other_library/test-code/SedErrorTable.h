/**
 * @file SedErrorTable.h
 * @brief Definition of the SedErrorTable class.
 * @author DEVISER
 */


#ifndef SedErrorTable_H__
#define SedErrorTable_H__

#include <sedml/SedError.h>


LIBSEDML_CPP_NAMESPACE_BEGIN

/** @cond doxygenLibsedmlInternal */
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


static const sedmlErrorTableEntry sedmlErrorTable[] =
{
  // 10000
  { SedUnknownError, 
    "Encountered unknown internal libSEDML error",
    LIBSEDML_CAT_INTERNAL, 
    LIBSEDML_SEV_FATAL,
    "Unrecognized error encountered by libSEDML",
    {"",
    }
  },

  //10001
  {
    NotUTF8,
    "File does not use UTF-8 encoding",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "An Sed XML file must use UTF-8 as the character encoding. More "
    "precisely, the 'encoding' attribute of the XML declaration at the "
    "beginning of the XML data stream cannot have a value other than "
    "'UTF-8'. An example valid declaration is "
    "'<?xml version=\"1.0\" encoding=\"UTF-8\"?>'.",
    {""
    }
  },

  //10002
  {
    UnrecognizedElement,
    "Encountered unrecognized element",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "An Sed XML document must not contain undefined elements or attributes "
    "in the Sed namespace. Documents containing unknown elements or "
    "attributes placed in the Sed namespace do not conform to the Sed "
    "specification.",  
    {""
    }
  },

  //10003
  {
    NotSchemaConformant,
    "Document does not conform to the Sed XML schema",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "An Sed XML document must conform to the XML Schema for the corresponding "
    "Sed Level, Version and Release. The XML Schema for Sed defines the "
    "basic Sed object structure, the data types used by those objects, and the "
    "order in which the objects may appear in an Sed document.",
    {""
    }
  },

  //10201
  {
    InvalidMathElement,
    "Invalid MathML",
    LIBSEDML_CAT_MATHML_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "All MathML content in Sed must appear within a <math> element, and the "
    "<math> element must be either explicitly or implicitly in the XML "
    "namespace \"http://www.w3.org/1998/Math/MathML\".",
    {""
    }
  },

  //10401
  {
    MissingAnnotationNamespace,
    "Missing declaration of the XML namespace for the annotation",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "Every top-level element within an annotation element must "
    "have a namespace declared.",
    {""
    }
  },

  //10402
  {
    DuplicateAnnotationNamespaces,
    "Multiple annotations using the same XML namespace",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "There cannot be more than one top-level element using a "
    "given namespace inside a given annotation element. ", 
    {""
    }
  },

  //10403
  {
    SedNamespaceInAnnotation,
    "The Sed XML namespace cannot be used in an Annotation object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "Top-level elements within an annotation element cannot use any Sed "
    "namespace, whether explicitly or implicitly (by failing "
    "to declare any namespace).",
    {""
    }
  },

  //10404
  {
    MultipleAnnotations,
    "Only one Annotation object is permitted under a given Sed object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A given Sed object may contain at most one <annotation> element.",
    {""
    }
  },

  //10801
  {
    NotesNotInXHTMLNamespace,
    "Notes must be placed in the XHTML XML namespace",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "The contents of the <notes> element must be explicitly placed in the "
    "XHTML XML namespace.", 
    {""
    }
  },

  //10802
  {
    NotesContainsXMLDecl,
    "XML declarations are not permitted in Notes objects",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML declaration "
    "(i.e., a string of the form \"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\" "
    "or similar).",
    {""
    }
  },

  //10803
  {
    NotesContainsDOCTYPE,
    "XML DOCTYPE elements are not permitted in Notes objects",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML DOCTYPE "
    "declaration (i.e., a string beginning with the characters \"<!DOCTYPE\". ",
    {""
    }
  },

  //10805
  {
    OnlyOneNotesElementAllowed,
    "Only one Notes subobject is permitted on a given Sed object",
    LIBSEDML_CAT_SEDML,
    LIBSEDML_SEV_ERROR,
    "A given Sed object may contain at most one <notes> element. ",
    {""
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  Sed specific errors.
   * ----------------------------------------------------------------------- */

  // 10101
  { SedmlNSUndeclared,
    "The Sedml namespace is not correctly declared.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "To conform to the Package specification for SBML Level~1 Version~1, an "
    "SBML document must declare "
    "'http://www.sbml.org/sbml/level1/version1/sedml/version1' as the "
    "XMLNamespaceto use for elements of this package.",
    { "L3V1 Sedml V1 Section 3.1"
    }
  },

  // 10102
  { SedmlElementNotInNs,
    "Element not in Sedml namespace",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Package must use the "
    "'http://www.sbml.org/sbml/level1/version1/sedml/version1' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Sedml V1 Section 3.1"
    }
  },

  // 10301
  { SedmlDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 10302
  { SedmlIdSyntaxRule,
    "Invalid SId syntax",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of a 'sedml:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20101
  { SedmlAttributeRequiredMissing,
    "Required sedml:required attribute on <sbml>",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "In all SBML documents using the Package, the <sbml> object must have the "
    "'sedml:required' attribute.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20102
  { SedmlAttributeRequiredMustBeBoolean,
    "The sedml:required attribute must be Boolean",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of attribute 'sedml:required' on the <sbml> object must be of "
    "data type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20103
  { SedmlAttributeRequiredMustHaveValue,
    "The sedml:required attribute must be 'false'",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of attribute 'sedml:required' on the <sbml> object must be set "
    "to 'false'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20201
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

  // 20202
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

  // 20203
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

  // 20204
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

  // 20205
  { SedmlSedDocumentLevelMustBeInteger,
    "Level attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:level' on a <sedDocument> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20206
  { SedmlSedDocumentVersionMustBeInteger,
    "Version attribute must be Integer.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:version' on a <sedDocument> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20207
  { SedmlSedDocumentEmptyLOElements,
    "No Empty ListOf elements allowed on <sedDocument>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The <sedListOfModels> subobject on a <sedDocument> object is optional, but "
    "if present, this container object must not be empty.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20208
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

  // 20209
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

  // 20301
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

  // 20302
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

  // 20303
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

  // 20304
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

  // 20305
  { SedmlSedModelSourceMustBeString,
    "Source attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:source' on a <sedModel> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20306
  { SedmlSedModelNameMustBeString,
    "Name attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <sedModel> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20307
  { SedmlSedModelLanguageMustBeString,
    "Language attribute must be String.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:language' on a <sedModel> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20308
  { SedmlSedModelEmptyLOElements,
    "No Empty ListOf elements allowed on <sedModel>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The <sedListOfChanges> subobject on a <sedModel> object is optional, but "
    "if present, this container object must not be empty.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20309
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

  // 20310
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

  // 20401
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

  // 20402
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

  // 20501
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

  // 20502
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

  // 20503
  { SedmlSedAddXMLAllowedElements,
    "Elements allowed on <sedAddXML>.",
    LIBSEDML_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedAddXML> object must contain one and only one instance of the XMLNode "
    "element. No other elements from the SBML Level 3 SEDML namespaces are "
    "permitted on a <sedAddXML> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  Application-specific codes should begin at 100000.
   * ----------------------------------------------------------------------- */

  //99999
  {
    SedCodesUpperBound,
    "Upper boundary of libSEDML-specific diagnostic codes",
    LIBSEDML_CAT_INTERNAL,
    LIBSEDML_SEV_NOT_APPLICABLE,
    LIBSEDML_SEV_NOT_APPLICABLE,
    LIBSEDML_SEV_NOT_APPLICABLE,
    LIBSEDML_SEV_NOT_APPLICABLE,
    LIBSEDML_SEV_NOT_APPLICABLE,
    LIBSEDML_SEV_NOT_APPLICABLE,
    LIBSEDML_SEV_NOT_APPLICABLE,
    LIBSEDML_SEV_NOT_APPLICABLE,
    LIBSEDML_SEV_NOT_APPLICABLE,
    "Application-specific codes should begin at 100000.", 
    {"",
     "",
     "",
     "",
     "",
     "",
     "",
     ""}
    }
};

LIBSEDML_CPP_NAMESPACE_END
/** @endcond */



#endif /* !SedErrorTable_H__ */

