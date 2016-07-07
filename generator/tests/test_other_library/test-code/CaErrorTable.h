/**
 * @file CaErrorTable.h
 * @brief Definition of the CaErrorTable class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2016 jointly by the following organizations:
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


#ifndef CaErrorTable_H__
#define CaErrorTable_H__

#include <omex/CaError.h>


LIBCOMBINE_CPP_NAMESPACE_BEGIN

/** @cond doxygenLibomexInternal */
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
} omexErrorTableEntry;


static const omexErrorTableEntry omexErrorTable[] =
{
  // 10000
  { CaUnknownError, 
    "Encountered unknown internal libCombine error",
    LIBCOMBINE_CAT_INTERNAL, 
    LIBCOMBINE_SEV_FATAL,
    "Unrecognized error encountered by libCombine",
    {"",
    }
  },

  //10001
  {
    NotUTF8,
    "File does not use UTF-8 encoding",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "An OMEX XML file must use UTF-8 as the character encoding. More "
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
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "An OMEX XML document must not contain undefined elements or attributes "
    "in the OMEX namespace. Documents containing unknown elements or "
    "attributes placed in the OMEX namespace do not conform to the OMEX "
    "specification.",  
    {""
    }
  },

  //10003
  {
    NotSchemaConformant,
    "Document does not conform to the OMEX XML schema",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "An OMEX XML document must conform to the XML Schema for the corresponding "
    "OMEX Level, Version and Release. The XML Schema for OMEX defines the "
    "basic OMEX object structure, the data types used by those objects, and the "
    "order in which the objects may appear in an OMEX document.",
    {""
    }
  },

  //10201
  {
    InvalidMathElement,
    "Invalid MathML",
    LIBCOMBINE_CAT_MATHML_CONSISTENCY,
    LIBCOMBINE_SEV_ERROR,
    "All MathML content in OMEX must appear within a <math> element, and the "
    "<math> element must be either explicitly or implicitly in the XML "
    "namespace \"http://www.w3.org/1998/Math/MathML\".",
    {""
    }
  },

  //10401
  {
    MissingAnnotationNamespace,
    "Missing declaration of the XML namespace for the annotation",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "Every top-level element within an annotation element must "
    "have a namespace declared.",
    {""
    }
  },

  //10402
  {
    DuplicateAnnotationNamespaces,
    "Multiple annotations using the same XML namespace",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "There cannot be more than one top-level element using a "
    "given namespace inside a given annotation element. ", 
    {""
    }
  },

  //10403
  {
    CaNamespaceInAnnotation,
    "The OMEX XML namespace cannot be used in an Annotation object",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "Top-level elements within an annotation element cannot use any OMEX "
    "namespace, whether explicitly or implicitly (by failing "
    "to declare any namespace).",
    {""
    }
  },

  //10404
  {
    MultipleAnnotations,
    "Only one Annotation object is permitted under a given OMEX object",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "A given OMEX object may contain at most one <annotation> element.",
    {""
    }
  },

  //10801
  {
    NotesNotInXHTMLNamespace,
    "Notes must be placed in the XHTML XML namespace",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "The contents of the <notes> element must be explicitly placed in the "
    "XHTML XML namespace.", 
    {""
    }
  },

  //10802
  {
    NotesContainsXMLDecl,
    "XML declarations are not permitted in Notes objects",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
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
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML DOCTYPE "
    "declaration (i.e., a string beginning with the characters \"<!DOCTYPE\". ",
    {""
    }
  },

  //10804
  {
    InvalidNotesContent,
    "Invalid notes content",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "Invalid contents in a <notes> element. ",
    {""
    }
  },

  //10805
  {
    OnlyOneNotesElementAllowed,
    "Only one Notes subobject is permitted on a given OMEX object",
    LIBCOMBINE_CAT_OMEX,
    LIBCOMBINE_SEV_ERROR,
    "A given OMEX object may contain at most one <notes> element. ",
    {""
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  OMEX specific errors.
   * ----------------------------------------------------------------------- */

  // 10101
  { SedmlNSUndeclared,
    "The Sedml namespace is not correctly declared.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "To conform to the Package specification for SBML Level 1 Version 1, an "
    "SBML document must declare "
    "'http://www.sbml.org/sbml/level1/version1/sedml/version1' as the "
    "XMLNamespace to use for elements of this package.",
    { "L3V1 Sedml V1 Section 3.1"
    }
  },

  // 10102
  { SedmlElementNotInNs,
    "Element not in Sedml namespace",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
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
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 10302
  { SedmlIdSyntaxRule,
    "Invalid SId syntax",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of a 'sedml:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 10303
  { InvalidMetaidSyntax,
    "Invalid SId syntax",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of a 'sedml:metaid' must conform to the syntax of the XML Type "
    "ID",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20101
  { InvalidNamespaceOnSed,
    "Invalid namespace",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Invalid namespace declared.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20102
  { AllowedAttributes,
    "Allowed attributes",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Allowed attributes",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20103
  { EmptyListElement,
    "No empty listOf",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "No empty lists",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20201
  { SedmlSedDocumentAllowedCoreAttributes,
    "Core attributes allowed on <sedDocument>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDocument> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <sedDocument>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20202
  { SedmlSedDocumentAllowedCoreElements,
    "Core elements allowed on <sedDocument>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDocument> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <sedDocument>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20203
  { SedmlSedDocumentAllowedAttributes,
    "Attributes allowed on <sedDocument>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
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
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
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
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:level' on a <sedDocument> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20206
  { SedmlSedDocumentVersionMustBeInteger,
    "Version attribute must be Integer.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:version' on a <sedDocument> must have a value of data "
    "type 'integer'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20207
  { SedmlSedDocumentEmptyLOElements,
    "No Empty ListOf elements allowed on <sedDocument>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The <sedListOfModels> subobject on a <sedDocument> object is optional, but "
    "if present, this container object must not be empty.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20208
  { SedmlSedDocumentLOSedModelsAllowedCoreElements,
    "Core elements allowed on <listOfSedModels>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
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
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedListOfModels> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedListOfModels> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20301
  { SedmlSedModelAllowedCoreAttributes,
    "Core attributes allowed on <sedModel>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedModel> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <sedModel>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20302
  { SedmlSedModelAllowedCoreElements,
    "Core elements allowed on <sedModel>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedModel> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <sedModel>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20303
  { SedmlSedModelAllowedAttributes,
    "Attributes allowed on <sedModel>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
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
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
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
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:source' on a <sedModel> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20306
  { SedmlSedModelNameMustBeString,
    "Name attribute must be String.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <sedModel> must have a value of data type "
    "'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20307
  { SedmlSedModelLanguageMustBeString,
    "Language attribute must be String.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:language' on a <sedModel> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20308
  { SedmlSedModelEmptyLOElements,
    "No Empty ListOf elements allowed on <sedModel>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The <sedListOfChanges> subobject on a <sedModel> object is optional, but "
    "if present, this container object must not be empty.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20309
  { SedmlSedModelLOSedChangesAllowedCoreElements,
    "Core elements allowed on <listOfSedChanges>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
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
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedListOfChanges> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedListOfChanges> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20401
  { SedmlSedChangeAllowedCoreAttributes,
    "Core attributes allowed on <sedChange>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedChange> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <sedChange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20402
  { SedmlSedChangeAllowedCoreElements,
    "Core elements allowed on <sedChange>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedChange> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <sedChange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20501
  { SedmlSedAddXMLAllowedCoreAttributes,
    "Core attributes allowed on <sedAddXML>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedAddXML> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <sedAddXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20502
  { SedmlSedAddXMLAllowedCoreElements,
    "Core elements allowed on <sedAddXML>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedAddXML> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <sedAddXML>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20503
  { SedmlSedAddXMLAllowedElements,
    "Elements allowed on <sedAddXML>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedAddXML> object must contain one and only one instance of the XMLNode "
    "element. No other elements from the SBML Level 3 SEDML namespaces are "
    "permitted on a <sedAddXML> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20601
  { SedmlSedSetValueAllowedCoreAttributes,
    "Core attributes allowed on <sedSetValue>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedSetValue> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <sedSetValue>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20602
  { SedmlSedSetValueAllowedCoreElements,
    "Core elements allowed on <sedSetValue>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedSetValue> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <sedSetValue>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20603
  { SedmlSedSetValueAllowedAttributes,
    "Attributes allowed on <sedSetValue>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedSetValue> object must have the required attribute "
    "'sedml:modelReference', and may have the optional attributes "
    "'sedml:symbol', 'sedml:target' and 'sedml:range'. No other attributes from "
    "the SBML Level 3 SEDML namespaces are permitted on a <sedSetValue> object. "
    "",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20604
  { SedmlSedSetValueAllowedElements,
    "Elements allowed on <sedSetValue>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedSetValue> object may contain one and only one instance of the "
    "ASTNode element. No other elements from the SBML Level 3 SEDML namespaces "
    "are permitted on a <sedSetValue> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20605
  { SedmlSedSetValueModelReferenceMustBeModel,
    "ModelReference attribute must be Model.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:modelReference' of a <sedSetValue> "
    "object must be the identifier of an existing <model> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20606
  { SedmlSedSetValueSymbolMustBeString,
    "Symbol attribute must be String.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:symbol' on a <sedSetValue> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20607
  { SedmlSedSetValueTargetMustBeString,
    "Target attribute must be String.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:target' on a <sedSetValue> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20608
  { SedmlSedSetValueRangeMustBeRange,
    "Range attribute must be Range.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:range' of a <sedSetValue> object must be "
    "the identifier of an existing <range> object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20701
  { SedmlSedDataGeneratorAllowedCoreAttributes,
    "Core attributes allowed on <sedDataGenerator>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDataGenerator> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedDataGenerator>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20702
  { SedmlSedDataGeneratorAllowedCoreElements,
    "Core elements allowed on <sedDataGenerator>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDataGenerator> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <sedDataGenerator>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20703
  { SedmlSedDataGeneratorAllowedAttributes,
    "Attributes allowed on <sedDataGenerator>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDataGenerator> object must have the required attribute 'sedml:id', "
    "and may have the optional attribute 'sedml:name'. No other attributes from "
    "the SBML Level 3 SEDML namespaces are permitted on a <sedDataGenerator> "
    "object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20704
  { SedmlSedDataGeneratorAllowedElements,
    "Elements allowed on <sedDataGenerator>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedDataGenerator> object may contain one and only one instance of each "
    "of the <sedListOfVariables,> <sedListOfParameters> and ASTNode elements. "
    "No other elements from the SBML Level 3 SEDML namespaces are permitted on "
    "a <sedDataGenerator> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20705
  { SedmlSedDataGeneratorNameMustBeString,
    "Name attribute must be String.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <sedDataGenerator> must have a value of "
    "data type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20706
  { SedmlSedDataGeneratorEmptyLOElements,
    "No Empty ListOf elements allowed on <sedDataGenerator>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The <sedListOfVariables> and <sedListOfParameters> subobjects on a "
    "<sedDataGenerator> object are optional, but if present, these container "
    "objects must not be empty.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20707
  { SedmlSedDataGeneratorLOSedVariablesAllowedCoreElements,
    "Core elements allowed on <listOfSedVariables>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <sedListOfVariables> container object may only contain "
    "<sedVariable> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20708
  { SedmlSedDataGeneratorLOSedParametersAllowedCoreElements,
    "Core elements allowed on <listOfSedParameters>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <sedListOfParameters> container object may only contain "
    "<sedParameter> objects.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20709
  { SedmlSedDataGeneratorLOSedVariablesAllowedCoreAttributes,
    "Core attributes allowed on <listOfSedVariables>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedListOfVariables> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedListOfVariables> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20710
  { SedmlSedDataGeneratorLOSedParametersAllowedCoreAttributes,
    "Core attributes allowed on <listOfSedParameters>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedListOfParameters> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedListOfParameters> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20801
  { SedmlSedRepeatedTaskAllowedCoreAttributes,
    "Core attributes allowed on <sedRepeatedTask>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedRepeatedTask> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedRepeatedTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20802
  { SedmlSedRepeatedTaskAllowedCoreElements,
    "Core elements allowed on <sedRepeatedTask>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedRepeatedTask> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <sedRepeatedTask>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20803
  { SedmlSedRepeatedTaskAllowedAttributes,
    "Attributes allowed on <sedRepeatedTask>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedRepeatedTask> object may have the optional attributes "
    "'sedml:rangeId' and 'sedml:resetModel'. No other attributes from the SBML "
    "Level 3 SEDML namespaces are permitted on a <sedRepeatedTask> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20804
  { SedmlSedRepeatedTaskRangeIdMustBeRange,
    "RangeId attribute must be Range.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The value of the attribute 'sedml:rangeId' of a <sedRepeatedTask> object "
    "must be the identifier of an existing <range> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20805
  { SedmlSedRepeatedTaskResetModelMustBeBoolean,
    "ResetModel attribute must be Boolean.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:resetModel' on a <sedRepeatedTask> must have a value "
    "of data type 'boolean'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20901
  { SedmlSedSimulationAllowedCoreAttributes,
    "Core attributes allowed on <sedSimulation>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedSimulation> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedSimulation>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20902
  { SedmlSedSimulationAllowedCoreElements,
    "Core elements allowed on <sedSimulation>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedSimulation> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <sedSimulation>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20903
  { SedmlSedSimulationAllowedAttributes,
    "Attributes allowed on <sedSimulation>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedSimulation> object must have the required attribute 'sedml:id', and "
    "may have the optional attribute 'sedml:name'. No other attributes from the "
    "SBML Level 3 SEDML namespaces are permitted on a <sedSimulation> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20904
  { SedmlSedSimulationAllowedElements,
    "Elements allowed on <sedSimulation>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedSimulation> object may contain one and only one instance of the "
    "SedAlgorithm element. No other elements from the SBML Level 3 SEDML "
    "namespaces are permitted on a <sedSimulation> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 20905
  { SedmlSedSimulationNameMustBeString,
    "Name attribute must be String.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "The attribute 'sedml:name' on a <sedSimulation> must have a value of data "
    "type 'string'.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21001
  { SedmlSedVectorRangeAllowedCoreAttributes,
    "Core attributes allowed on <sedVectorRange>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedVectorRange> object may have the optional SBML Level 3 Core "
    "attributes 'metaid' and 'sboTerm'. No other attributes from the SBML Level "
    "3 Core namespaces are permitted on a <sedVectorRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21002
  { SedmlSedVectorRangeAllowedCoreElements,
    "Core elements allowed on <sedVectorRange>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedVectorRange> object may have the optional SBML Level 3 Core "
    "subobjects for notes and annotations. No other elements from the SBML "
    "Level 3 Core namespaces are permitted on a <sedVectorRange>.",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21003
  { SedmlSedVectorRangeAllowedAttributes,
    "Attributes allowed on <sedVectorRange>.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "A <sedVectorRange> object may have the optional attribute 'sedml:value'. "
    "No other attributes from the SBML Level 3 SEDML namespaces are permitted "
    "on a <sedVectorRange> object. ",
    { "L3V1 Sedml V1 Section"
    }
  },

  // 21004
  { SedmlSedVectorRangeValueMustBeString,
    "Value attribute must be String.",
    LIBOMEX_CAT_GENERAL_CONSISTENCY,
    LIBSEDML_SEV_ERROR,
    "FIXME: Encountered an unknown attribute type vector in "
    "ValidationRulesForClass",
    { "L3V1 Sedml V1 Section"
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  Application-specific codes should begin at 100000.
   * ----------------------------------------------------------------------- */

  //99994
  {
    UnknownCoreAttribute,
    "Unknown attribute",
    LIBCOMBINE_CAT_INTERNAL,
    LIBCOMBINE_SEV_ERROR,
    "An unknown attribute has been found.", 
    {""
    }
   },

  //99999
  {
    CaCodesUpperBound,
    "Upper boundary of libCombine-specific diagnostic codes",
    LIBCOMBINE_CAT_INTERNAL,
    LIBCOMBINE_SEV_NOT_APPLICABLE,
    "Application-specific codes should begin at 100000.", 
    {""
    }
   }
};

LIBCOMBINE_CPP_NAMESPACE_END
/** @endcond */



#endif /* !CaErrorTable_H__ */

